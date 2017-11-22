#include "chanel.h"

static const char instructs[17][6] = {
    //yada
    {0x01,0x03,0x01,0x00,0x00,0x3E},     //normal  124
    {0x01,0x03,0x01,0x3E,0x00,0x3E},     //normal  124
    {0x01,0x03,0x01,0x7C,0x00,0x1E},     //normal  60
    {0x01,0x03,0x11,0xE1,0X00,0x3F},     //voltageharmonic  126
    {0x01,0x03,0x12,0xE0,0X00,0x3F},     //currentharmonic  126
    //weisheng 
    {0x01,0x03,0x00,0x01,0x00,0x29},     //normal  124
    {0x01,0x03,0x12,0x00,0x00,0x3F},     //normal  124
    {0x01,0x03,0x13,0x03,0x00,0x3C},     //normal  44
    {0x01,0x03,0x20,0x06,0x00,0x02},     //normal  16
    {0x01,0x03,0x20,0x0E,0X00,0x02},     //voltageharmonic  126
    {0x01,0x03,0x21,0x06,0X00,0x02},     //currentharmonic  126
    {0x01,0x03,0x21,0x0E,0x00,0x02},     //harmpowercumn,forward  16
    //taigu
    {0x01,0x03,0x00,0x01,0x00,0x29},     //normal  82
    {0x01,0x03,0x00,0x39,0x00,0x08},     //normal  16
    {0x01,0x03,0x00,0x64,0x00,0x66},     //currentharmonic  204
    {0x01,0x03,0x01,0x2c,0x00,0x66},     //voltageharmonic  204
}; 

int chanel_collectdata(struct chanel_info *ch)
{
    int insnum,insoff;
    int i,j,datalen;

    switch(ch->type)
    {
        case 1:
            insnum = 5;
            insoff = 0;
            printf("this chanel have %d yada elecs!\n",ch->elecnum);
            break;
        case 2:
            insnum = 7;
            insoff = 5;
            printf("this chanel have %d weisheng elecs!\n",ch->elecnum);
            break;
        case 3:
            insnum = 4;
            insoff = 12;
            printf("this chanel have %d taigu elecs!\n",ch->elecnum);
            break;
        default:
            insnum = 0;
            insoff = 0;
            printf("this chanel have %d unkown elecs!\n",ch->elecnum);
            break;
    }

    for(j = 0; j < ch->elecnum; j++)
    {
        for(i = 0; i < insnum; i++)
        {
            usleep(800000);
            sendinstruct(ch,insoff + i,j);
        }
    }
    
    ch->offset = 0;
}

int chanel_getdatalength(struct chanel_info *ch)
{
    int i,j;
    int datalen = 0;

    int insnum,insoff;

    switch(ch->type)
    {
        case 1:
            insnum = 5;
            insoff = 0;
            break;
        case 2:
            insnum = 7;
            insoff = 7;
            break;
        case 3:
            insnum = 4;
            insoff = 12;
            break;
        default:
            insnum = 0;
            insoff = 0;
            break;
    }
    
    for(j = 0; j < ch->elecnum; j++ )
    {
        for(i=0;i<insnum;i++)
        {
            datalen += instructs[insoff+i][5] * 2 + 5;
        }
    }
    
    if(datalen > 0)
        printf("%d datas in this chanel %d!\n",datalen,ch->portnum);
    return datalen;
}

int chanel_getsingleelecdata(struct chanel_info *ch,int index,char elecdatas[])   //get single elec datas
{
    int num = 0;
    int i = 0;
    int offset = 0;
    switch(ch->type)
    {
        case 1:
            num = 585;
            break;
        case 2:
            num = 0;
            break;
        case 3:
            num = 526;
            break;
        default:
            num = 0;
            break;
    }
    
    offset = num * index;
    for(i=0;i<num;i++)
    {
        elecdatas[i] = ch->elecdatas[i + offset];
    }
    return num;
}

int recvdata(struct chanel_info *ch,int num, int index)
{
    int i,re;
    int revnum = 0;
    char revdata[512];
    revnum = serial_rev(ch->fd,revdata,num);
    
    if(revnum != num){
        printf("chanel %d :rev num error!ask num: %d, recieve num : %d\n",ch->portnum,num,revnum);
        return -1;
    } 

    re = bytesfactory_checkcrc16(revdata,revnum-2);
    if(re <0)
    {
        printf("chanel %d :crc check error!\n",ch->portnum);
        return -1;        
    }

    for(i = 0; i < num; i++){
        ch->elecdatas[ch->offset + i] = revdata[i];
    }
    ch->offset += num;
    return 0;
}

int sendinstruct(struct chanel_info *ch,int index,int add)       //send one instruct everytime and get elec data
{
    char sendbuf[256];
    int i,j,flag,sendlen,revnum;

    for(j = 0; j < 3; j++){                               //retry 3 times
        for(i = 0; i < 6; i++){
            sendbuf[i] = instructs[index][i];
        }
        sendbuf[0] = add + 1;                             //elec modbus address
        sendlen    = bytesfactory_addcrc16(sendbuf,6);       //get send data with crc16
        revnum     = sendbuf[5] * 2 + 5; 
        
        if((flag = tcflush(ch->fd,TCIOFLUSH)) == 0){      //refresh cache
            flag = serial_send(ch->fd,sendbuf,sendlen);
            flag = recvdata(ch,revnum,index);
        }
        else{
            flag = -1;
            printf("refresh false!");
        }

        if(flag != -1) break;
        else
        {
            wdt_feed();
            usleep(800000);
            printf("chanel %d :communicate with elec failed , retry %d times\n",ch->portnum,j+1);
        } 
    }
    
    if(flag == -1)
    {
        {
            for(i = 0; i < revnum; i++)
            {
                ch->elecdatas[ch->offset + i] = 0x00;
            }
            ch->offset += revnum;        //failed 3 times,add data offset
        }
    }
    
    return flag;
}
