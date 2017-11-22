#ifndef CHANEL_H
#define CHANEL_H
#include "serial.h"
#include "bytesfactory.h"

struct chanel_info{
    int  portnum;
    int  datalen;     
    int  elecnum;     //the number of elecs
    int  type;        //the type of elec : 1,yada;2,weisheng
    int  fd;          //the serial file number of this chanel
    int  offset;      //when data collector is running , elecdatas offset 
    int  bundbit;
    char checktype;   //ji ou jiao yan
    int  stopbit;
    char ids[32];     //the elec modbus address
    char elecdatas[8192];
};

extern int chanel_init(struct chanel_info *ch);
extern int chanel_collectdata(struct chanel_info *ch);
extern int chanel_getdatalength(struct chanel_info *ch);
extern int chanel_getsingleelecdata(struct chanel_info *ch,int index,char elecdatas[]);

#endif
