#include "chanel.h"
#include <pthread.h>
#include "yadaoperator.h"
#include "taiguoperator.h"

pthread_t ch_thread[8];     //get data thread
struct chanel_info ch[8];   //chanel info

void *chthread_f(void *arg)
{
    int res;
    struct chanel_info *ch = (struct chanel_info *)arg;

    while(1){
        if((res = updatechpara(arg)) < 0)    //check chanel info
            continue;
        if(ch->elecnum > 0)
        {
            chanel_collectdata(arg);         //start one time data collector
            savedata(arg);                   //save elec data in files
        }
        else
        {
            sleep(5);
        }
    }
}

char getchecktype(char buf)
{
    switch(buf)
    {
        case 0x01:
            return 'O';
        case 0x02:
            return 'E';
        default:
            return 'N';
    }
}

int initchpara()    //init chanel parameter
{
    int i;
    for(i=0;i<8;i++)
    {
        ch[i].portnum   = i+ 1;
        ch[i].offset    = 0;
        ch[i].bundbit   = 9600;
        ch[i].checktype = 'N';
        ch[i].stopbit   = 1;
        ch[i].fd = serial_init(ch[i].portnum,ch[i].bundbit,ch[i].checktype,ch[i].stopbit);
    }
    return 0;
}

int updatechpara(struct chanel_info *ch)
{
    int  res;
    int  bundbit,stopbit;
    char checktype;
    char setinfo[F_SETFILE_LENGTH];

    if(res = fgetsetdata(setinfo) != F_SETFILE_LENGTH)
    {
        wdt_feed();
        sleep(1); 
        return -1;
    }
        
    bundbit   = chartoi(setinfo,(ch->portnum -1)*10 +34,2);
    stopbit   = setinfo[(ch->portnum -1)*10 +39];
    checktype = getchecktype(setinfo[(ch->portnum -1)*10 +37]);
    if(ch->bundbit != bundbit || ch->stopbit != stopbit || ch->checktype != checktype)
    {
        if(bundbit != 0 && stopbit !=0)
        {
            close(ch->fd);                         //parameter changed , restart the siral port
            ch->bundbit   = bundbit;
            ch->stopbit   = stopbit;
            ch->checktype = checktype;
            usleep(100000);
            printf("chanel %d: serial number is changed : %d,%d,%c\n",ch->portnum,bundbit,stopbit,checktype);
            ch->fd = serial_init(ch->portnum,ch->bundbit,ch->checktype,ch->stopbit);        
        }

    }
        
    ch->elecnum = chartoi(setinfo,(ch->portnum -1)*10 + 30,2);
    ch->type    = setinfo[(ch->portnum -1)*10+33];
    ch->datalen = chanel_getdatalength(ch);
    return 0;
}

int savedata(struct chanel_info *ch)
{
    char savedata[1420];
    char databuf[800];
    int  i,j,res;
    char filename[3];
    int  worktype;


    for(i =0;i<ch->elecnum;i++)                         
    {
        chanel_getsingleelecdata(ch,i,databuf);
        savedatainit(savedata);          //init save data
        savedata[0] = ch->portnum;
        savedata[1] = i + 1;
        savedata[2] = ':';
        switch(ch->type)
        {
            case 1:
                yadaoperator_getdata(databuf,savedata);
                break;
            case 2:
                break;
            case 3:
               taiguoperator_getdata(databuf,savedata); 
       
                break;
            default:
                break;
        }
        
        filename[0] = ch->portnum + 0x30;
        filename[1] = i+0x31;
        filename[2] = '\0';
        printf("write %d%d into file\n",ch->portnum,i+1); 
        wrfile(filename,savedata);
    }
}

int main(int argc,char* argv[])
{
    int  i; 
    chdir((char *)dirname(argv[0]));   //file path

    initchpara();
    wdt_init(60); 
   
    for(i=0;i<8;i++)
    {
        pthread_create(&ch_thread[i],NULL,chthread_f,&ch[i]);
    }

    while(1)
    {  
        sleep(30);
        wdt_feed();
    }
    
    return 0;
}



