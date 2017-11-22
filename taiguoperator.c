#include "taiguoperator.h"

int taiguoperator_getdata(char valuebuf[],char savedata[])
{
    double dvalue = 0;
    double buf;
    double athdu,bthdu,cthdu,athdi,bthdi,cthdi;
    double vfa,vfb,vfc,cfa,cfb,cfc; 
    int    bflag; 
       
    athdu = getrealvalue(valuebuf,V_wav_disA_taigu,2,3);
    bthdu = getrealvalue(valuebuf,V_wav_disB_taigu,2,3);
    cthdu = getrealvalue(valuebuf,V_wav_disC_taigu,2,3);
    athdi = getrealvalue(valuebuf,C_wav_disA_taigu,2,3);
    bthdi = getrealvalue(valuebuf,C_wav_disB_taigu,2,3);
    cthdi = getrealvalue(valuebuf,C_wav_disC_taigu,2,3);

    dvalue = getrealvalue(valuebuf,V_A_taigu,2,2);
    if(dvalue == 0)
    {
        bflag = 0;
        dvalue = getrealvalue(valuebuf,V_ABline_taigu,2,2);
    }
    else
    {
        bflag = 1;
    }

    vfa = dvalue / sqrt(1+ athdu * athdu);
    insertsavedatar(savedata,V_fundA,vfa,4,4);    //A相基波电压
    
    if(bflag == 1) 
    {
        dvalue = getrealvalue(valuebuf,V_B_taigu,2,2);
        vfb = dvalue / (sqrt(1+bthdu * bthdu)); 
        insertsavedatar(savedata,V_fundB,vfb,4,4);    //B相基波电压
    }

    if(bflag == 1)
        dvalue = getrealvalue(valuebuf,V_C_taigu,2,2);
    else
        dvalue = getrealvalue(valuebuf,V_BCline_taigu,2,2);

    vfc = dvalue / (sqrt(1+cthdu * cthdu)); 
    insertsavedatar(savedata,V_fundC,vfc,4,4);    //C相基波电压

    dvalue = getrealvalue(valuebuf,C_A_taigu,2,3);
    cfa = dvalue / (sqrt(1+athdi * athdi)); 
    insertsavedatar(savedata,C_fundA,cfa,4,4);    //A相基波电流

    if(bflag == 1)
    {
        dvalue = getrealvalue(valuebuf,C_B_taigu,2,3);
        cfb = dvalue / (sqrt(1+bthdi * bthdi)); 
        insertsavedatar(savedata,C_fundB,cfb,4,4);    //B相基波电流    
    }

    dvalue = getrealvalue(valuebuf,C_C_taigu,2,3);
    cfc = dvalue / (sqrt(1+cthdi * cthdi)); 
    insertsavedatar(savedata,C_fundC,cfc,4,4);    //C相基波电流	
    
    if(bflag == 1)
    {
        insertsavedata(valuebuf,savedata,V_A_taigu,V_A,2);  //A相电压
        insertsavedata(valuebuf,savedata,V_B_taigu,V_B,2);  //B相电压
        insertsavedata(valuebuf,savedata,V_C_taigu,V_C,2);  //C相电压    
    }   
    else
    {
        insertsavedata(valuebuf,savedata,V_ABline_taigu,V_A,2);  //A相电压
        insertsavedata(valuebuf,savedata,V_BCline_taigu,V_C,2);  //C相电压    
    }

    insertsavedata(valuebuf,savedata,C_A_taigu,C_A,2);  //A相电流
    insertsavedata(valuebuf,savedata,C_B_taigu,C_B,2);  //B相电流	
    insertsavedata(valuebuf,savedata,C_C_taigu,C_C,2);  //C相电流	
    insertsavedata(valuebuf,savedata,Act_powerA_taigu,Act_powerA,2); //A相有功
    insertsavedata(valuebuf,savedata,Act_powerB_taigu,Act_powerB,2); //B相有功	
    insertsavedata(valuebuf,savedata,Act_powerC_taigu,Act_powerC,2); //C相有功	
    insertsavedata(valuebuf,savedata,Act_powerT_taigu,Act_powerT,4); //总有功	
    insertsavedata(valuebuf,savedata,Rea_powerA_taigu,Rea_powerA,2); //A相无功	
    insertsavedata(valuebuf,savedata,Rea_powerB_taigu,Rea_powerB,2); //B相无功	
    insertsavedata(valuebuf,savedata,Rea_powerC_taigu,Rea_powerC,2); //C相无功	
    insertsavedata(valuebuf,savedata,Rea_powerT_taigu,Rea_powerT,4); //总无功	
    
    insertsavedata(valuebuf,savedata,powerfac_A_taigu,powerfac_A,2); //A相PF	
    insertsavedata(valuebuf,savedata,powerfac_B_taigu,powerfac_B,2); //B相PF	
    insertsavedata(valuebuf,savedata,powerfac_C_taigu,powerfac_C,2); //C相PF	
    insertsavedata(valuebuf,savedata,powerfac_T_taigu,powerfac_T,2); //总PF	
    insertsavedata(valuebuf,savedata,frequency_taigu,frequency,2);   //频率	

    insertsavedata(valuebuf,savedata,V_har_coA2_taigu,V_har_coA2,2); //A相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coA3_taigu,V_har_coA3,2); //A相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coA4_taigu,V_har_coA4,2); //A相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coA5_taigu,V_har_coA5,2); //A相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coA6_taigu,V_har_coA6,2); //A相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coA7_taigu,V_har_coA7,2); //A相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coA8_taigu,V_har_coA8,2); //A相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coA9_taigu,V_har_coA9,2); //A相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coA10_taigu,V_har_coA10,2); //A相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coA11_taigu,V_har_coA11,2); //A相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coA12_taigu,V_har_coA12,2); //A相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coA13_taigu,V_har_coA13,2); //A相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coA14_taigu,V_har_coA14,2); //A相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coA15_taigu,V_har_coA15,2); //A相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coA16_taigu,V_har_coA16,2); //A相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coA17_taigu,V_har_coA17,2); //A相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coA18_taigu,V_har_coA18,2); //A相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coA19_taigu,V_har_coA19,2); //A相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coA20_taigu,V_har_coA20,2); //A相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coA21_taigu,V_har_coA21,2); //A相谐波电压含有率（21）
    insertsavedata(valuebuf,savedata,V_har_coA22_taigu,V_har_coA22,2); //A相谐波电压含有率（22）	
    insertsavedata(valuebuf,savedata,V_har_coA23_taigu,V_har_coA23,2); //A相谐波电压含有率（23）	
    insertsavedata(valuebuf,savedata,V_har_coA24_taigu,V_har_coA24,2); //A相谐波电压含有率（24）	
    insertsavedata(valuebuf,savedata,V_har_coA25_taigu,V_har_coA25,2); //A相谐波电压含有率（25）	
    insertsavedata(valuebuf,savedata,V_har_coA26_taigu,V_har_coA26,2); //A相谐波电压含有率（26）	
    insertsavedata(valuebuf,savedata,V_har_coA27_taigu,V_har_coA27,2); //A相谐波电压含有率（27）	
    insertsavedata(valuebuf,savedata,V_har_coA28_taigu,V_har_coA28,2); //A相谐波电压含有率（28）	
    insertsavedata(valuebuf,savedata,V_har_coA29_taigu,V_har_coA29,2); //A相谐波电压含有率（29）	
    insertsavedata(valuebuf,savedata,V_har_coA30_taigu,V_har_coA30,2); //A相谐波电压含有率（30）	
    insertsavedata(valuebuf,savedata,V_har_coA31_taigu,V_har_coA31,2); //A相谐波电压含有率（31）

    insertsavedata(valuebuf,savedata,C_zero_taigu,V_har_coA32,2);  //zero电流
    insertsavedata(valuebuf,savedata,C_low_taigu,V_har_coA33,2);   //low电流		

    insertsavedata(valuebuf,savedata,V_har_coB2_taigu,V_har_coB2,2); //B相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coB3_taigu,V_har_coB3,2); //B相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coB4_taigu,V_har_coB4,2); //B相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coB5_taigu,V_har_coB5,2); //B相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coB6_taigu,V_har_coB6,2); //B相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coB7_taigu,V_har_coB7,2); //B相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coB8_taigu,V_har_coB8,2); //B相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coB9_taigu,V_har_coB9,2); //B相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coB10_taigu,V_har_coB10,2); //B相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coB11_taigu,V_har_coB11,2); //B相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coB12_taigu,V_har_coB12,2); //B相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coB13_taigu,V_har_coB13,2); //B相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coB14_taigu,V_har_coB14,2); //B相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coB15_taigu,V_har_coB15,2); //B相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coB16_taigu,V_har_coB16,2); //B相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coB17_taigu,V_har_coB17,2); //B相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coB18_taigu,V_har_coB18,2); //B相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coB19_taigu,V_har_coB19,2); //B相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coB20_taigu,V_har_coB20,2); //B相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coB21_taigu,V_har_coB21,2); //B相谐波电压含有率（21）
    insertsavedata(valuebuf,savedata,V_har_coB22_taigu,V_har_coB22,2); //B相谐波电压含有率（22）	
    insertsavedata(valuebuf,savedata,V_har_coB23_taigu,V_har_coB23,2); //B相谐波电压含有率（23）	
    insertsavedata(valuebuf,savedata,V_har_coB24_taigu,V_har_coB24,2); //B相谐波电压含有率（24）	
    insertsavedata(valuebuf,savedata,V_har_coB25_taigu,V_har_coB25,2); //B相谐波电压含有率（25）	
    insertsavedata(valuebuf,savedata,V_har_coB26_taigu,V_har_coB26,2); //B相谐波电压含有率（26）	
    insertsavedata(valuebuf,savedata,V_har_coB27_taigu,V_har_coB27,2); //B相谐波电压含有率（27）	
    insertsavedata(valuebuf,savedata,V_har_coB28_taigu,V_har_coB28,2); //B相谐波电压含有率（28）	
    insertsavedata(valuebuf,savedata,V_har_coB29_taigu,V_har_coB29,2); //B相谐波电压含有率（29）	
    insertsavedata(valuebuf,savedata,V_har_coB30_taigu,V_har_coB30,2); //B相谐波电压含有率（30）	
    insertsavedata(valuebuf,savedata,V_har_coB31_taigu,V_har_coB31,2); //B相谐波电压含有率（31）

    insertsavedata(valuebuf,savedata,V_har_coC2_taigu,V_har_coC2,2); //C相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coC3_taigu,V_har_coC3,2); //C相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coC4_taigu,V_har_coC4,2); //C相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coC5_taigu,V_har_coC5,2); //C相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coC6_taigu,V_har_coC6,2); //C相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coC7_taigu,V_har_coC7,2); //C相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coC8_taigu,V_har_coC8,2); //C相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coC9_taigu,V_har_coC9,2); //C相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coC10_taigu,V_har_coC10,2); //C相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coC11_taigu,V_har_coC11,2); //C相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coC12_taigu,V_har_coC12,2); //C相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coC13_taigu,V_har_coC13,2); //C相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coC14_taigu,V_har_coC14,2); //C相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coC15_taigu,V_har_coC15,2); //C相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coC16_taigu,V_har_coC16,2); //C相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coC17_taigu,V_har_coC17,2); //C相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coC18_taigu,V_har_coC18,2); //C相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coC19_taigu,V_har_coC19,2); //C相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coC20_taigu,V_har_coC20,2); //C相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coC21_taigu,V_har_coC21,2); //C相谐波电压含有率（21）
    insertsavedata(valuebuf,savedata,V_har_coC22_taigu,V_har_coC22,2); //C相谐波电压含有率（22）	
    insertsavedata(valuebuf,savedata,V_har_coC23_taigu,V_har_coC23,2); //C相谐波电压含有率（23）	
    insertsavedata(valuebuf,savedata,V_har_coC24_taigu,V_har_coC24,2); //C相谐波电压含有率（24）	
    insertsavedata(valuebuf,savedata,V_har_coC25_taigu,V_har_coC25,2); //C相谐波电压含有率（25）	
    insertsavedata(valuebuf,savedata,V_har_coC26_taigu,V_har_coC26,2); //C相谐波电压含有率（26）	
    insertsavedata(valuebuf,savedata,V_har_coC27_taigu,V_har_coC27,2); //C相谐波电压含有率（27）	
    insertsavedata(valuebuf,savedata,V_har_coC28_taigu,V_har_coC28,2); //C相谐波电压含有率（28）	
    insertsavedata(valuebuf,savedata,V_har_coC29_taigu,V_har_coC29,2); //C相谐波电压含有率（29）	
    insertsavedata(valuebuf,savedata,V_har_coC30_taigu,V_har_coC30,2); //C相谐波电压含有率（30）	
    insertsavedata(valuebuf,savedata,V_har_coC31_taigu,V_har_coC31,2); //C相谐波电压含有率（31）

    dvalue = getrealvalue(valuebuf,C_harA2_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA2,dvalue,4,4);    //A相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harA3_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA3,dvalue,4,4);    //A相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harA4_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA4,dvalue,4,4);    //A相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harA5_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA5,dvalue,4,4);    //A相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harA6_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA6,dvalue,4,4);    //A相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harA7_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA7,dvalue,4,4);    //A相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harA8_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA8,dvalue,4,4);    //A相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harA9_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA9,dvalue,4,4);    //A相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harA10_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA10,dvalue,4,4);    //A相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harA11_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA11,dvalue,4,4);    //A相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harA12_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA12,dvalue,4,4);    //A相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harA13_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA13,dvalue,4,4);    //A相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harA14_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA14,dvalue,4,4);    //A相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harA15_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA15,dvalue,4,4);    //A相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harA16_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA16,dvalue,4,4);    //A相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harA17_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA17,dvalue,4,4);    //A相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harA18_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA18,dvalue,4,4);    //A相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harA19_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA19,dvalue,4,4);    //A相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harA20_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA20,dvalue,4,4);    //A相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harA21_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA21,dvalue,4,4);    //A相谐波电流（21）   

    dvalue = getrealvalue(valuebuf,C_harA22_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA22,dvalue,4,4);    //A相谐波电流（22）

    dvalue = getrealvalue(valuebuf,C_harA23_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA23,dvalue,4,4);    //A相谐波电流（23）

    dvalue = getrealvalue(valuebuf,C_harA24_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA24,dvalue,4,4);    //A相谐波电流（24）

    dvalue = getrealvalue(valuebuf,C_harA25_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA25,dvalue,4,4);    //A相谐波电流（25）

    dvalue = getrealvalue(valuebuf,C_harA26_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA26,dvalue,4,4);    //A相谐波电流（26）

    dvalue = getrealvalue(valuebuf,C_harA27_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA27,dvalue,4,4);    //A相谐波电流（27）

    dvalue = getrealvalue(valuebuf,C_harA28_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA28,dvalue,4,4);    //A相谐波电流（28）

    dvalue = getrealvalue(valuebuf,C_harA29_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA29,dvalue,4,4);    //A相谐波电流（29）

    dvalue = getrealvalue(valuebuf,C_harA30_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA30,dvalue,4,4);    //A相谐波电流（30）

    dvalue = getrealvalue(valuebuf,C_harA31_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA31,dvalue,4,4);    //A相谐波电流（31）
 

    dvalue = getrealvalue(valuebuf,C_harB2_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB2,dvalue,4,4);    //B相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harB3_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB3,dvalue,4,4);    //B相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harB4_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB4,dvalue,4,4);    //B相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harB5_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB5,dvalue,4,4);    //B相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harB6_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB6,dvalue,4,4);    //B相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harB7_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB7,dvalue,4,4);    //B相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harB8_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB8,dvalue,4,4);    //B相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harB9_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB9,dvalue,4,4);    //B相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harB10_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB10,dvalue,4,4);    //B相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harB11_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB11,dvalue,4,4);    //B相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harB12_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB12,dvalue,4,4);    //B相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harB13_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB13,dvalue,4,4);    //B相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harB14_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB14,dvalue,4,4);    //B相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harB15_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB15,dvalue,4,4);    //B相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harB16_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB16,dvalue,4,4);    //B相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harB17_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB17,dvalue,4,4);    //B相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harB18_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB18,dvalue,4,4);    //B相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harB19_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB19,dvalue,4,4);    //B相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harB20_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB20,dvalue,4,4);    //B相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harB21_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB21,dvalue,4,4);    //B相谐波电流（21）

    dvalue = getrealvalue(valuebuf,C_harB22_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB22,dvalue,4,4);    //B相谐波电流（22）

    dvalue = getrealvalue(valuebuf,C_harB23_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB23,dvalue,4,4);    //B相谐波电流（23）

    dvalue = getrealvalue(valuebuf,C_harB24_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB24,dvalue,4,4);    //B相谐波电流（24）

    dvalue = getrealvalue(valuebuf,C_harB25_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB25,dvalue,4,4);    //B相谐波电流（25）

    dvalue = getrealvalue(valuebuf,C_harB26_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB26,dvalue,4,4);    //B相谐波电流（26）

    dvalue = getrealvalue(valuebuf,C_harB27_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB27,dvalue,4,4);    //B相谐波电流（27）

    dvalue = getrealvalue(valuebuf,C_harB28_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB28,dvalue,4,4);    //B相谐波电流（28）

    dvalue = getrealvalue(valuebuf,C_harB29_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB29,dvalue,4,4);    //B相谐波电流（29）

    dvalue = getrealvalue(valuebuf,C_harB30_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB30,dvalue,4,4);    //B相谐波电流（30）

    dvalue = getrealvalue(valuebuf,C_harB31_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB31,dvalue,4,4);    //B相谐波电流（31）


    dvalue = getrealvalue(valuebuf,C_harC2_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC2,dvalue,4,4);    //C相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harC3_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC3,dvalue,4,4);    //C相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harC4_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC4,dvalue,4,4);    //C相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harC5_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC5,dvalue,4,4);    //C相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harC6_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC6,dvalue,4,4);    //C相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harC7_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC7,dvalue,4,4);    //C相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harC8_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC8,dvalue,4,4);    //C相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harC9_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC9,dvalue,4,4);    //C相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harC10_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC10,dvalue,4,4);    //C相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harC11_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC11,dvalue,4,4);    //C相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harC12_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC12,dvalue,4,4);    //C相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harC13_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC13,dvalue,4,4);    //C相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harC14_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC14,dvalue,4,4);    //C相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harC15_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC15,dvalue,4,4);    //C相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harC16_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC16,dvalue,4,4);    //C相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harC17_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC17,dvalue,4,4);    //C相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harC18_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC18,dvalue,4,4);    //C相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harC19_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC19,dvalue,4,4);    //C相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harC20_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC20,dvalue,4,4);    //C相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harC21_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC21,dvalue,4,4);    //C相谐波电流（21）

    dvalue = getrealvalue(valuebuf,C_harC22_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC22,dvalue,4,4);    //C相谐波电流（22）

    dvalue = getrealvalue(valuebuf,C_harC23_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC23,dvalue,4,4);    //C相谐波电流（23）

    dvalue = getrealvalue(valuebuf,C_harC24_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC24,dvalue,4,4);    //C相谐波电流（24）

    dvalue = getrealvalue(valuebuf,C_harC25_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC25,dvalue,4,4);    //C相谐波电流（25）

    dvalue = getrealvalue(valuebuf,C_harC26_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC26,dvalue,4,4);    //C相谐波电流（26）

    dvalue = getrealvalue(valuebuf,C_harC27_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC27,dvalue,4,4);    //C相谐波电流（27）

    dvalue = getrealvalue(valuebuf,C_harC28_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC28,dvalue,4,4);    //C相谐波电流（28）

    dvalue = getrealvalue(valuebuf,C_harC29_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC29,dvalue,4,4);    //C相谐波电流（29）

    dvalue = getrealvalue(valuebuf,C_harC30_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC30,dvalue,4,4);    //C相谐波电流（30）

    dvalue = getrealvalue(valuebuf,C_harC31_taigu,2,1);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC31,dvalue,4,4);    //C相谐波电流（31）


    insertsavedata(valuebuf,savedata,V_wav_disA_taigu,V_wav_disA,2);   //A相电压谐波畸变率
    insertsavedata(valuebuf,savedata,V_wav_disB_taigu,V_wav_disB,2);   //B相电压谐波畸变率
    insertsavedata(valuebuf,savedata,V_wav_disC_taigu,V_wav_disC,2);   //C相电压谐波畸变率
    insertsavedata(valuebuf,savedata,C_wav_disA_taigu,C_wav_disA,2);   //A相电流谐波畸变率
    insertsavedata(valuebuf,savedata,C_wav_disB_taigu,C_wav_disB,2);   //B相电流谐波畸变率
    insertsavedata(valuebuf,savedata,C_wav_disC_taigu,C_wav_disC,2);   //C相电流谐波畸变率

    insertsavedata(valuebuf,savedata,P_act_powT_taigu,P_act_powT,4);   //总正向有功总电能
    insertsavedata(valuebuf,savedata,P_rea_PowT_taigu,P_rea_powT,4);   //总正向无功总电能

    insertsavedata(valuebuf,savedata,V_imdegree_taigu,V_imdegree,2);   //电压不平衡度
    insertsavedata(valuebuf,savedata,C_imdegree_taigu,C_imdegree,2);   //电流不平衡度
}
