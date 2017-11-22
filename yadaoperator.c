#include "yadaoperator.h"

double getmeansquare(char valuebuf[],int offset,int num)  // huo qu ping fang he kai gen hao
{
    int i = 0;
    double sqsum = 0;
    int value16;
    double value;

    for(i=0;i<num;i++)
    {
        value16 = chartoi(valuebuf,offset,2);
        if(value16 > 0){
            value = (double)value16 / 10000;
            sqsum = sqsum + value * value;
        }
        offset = offset + 2;
    }

    if(sqsum > 0)
        return sqrt(sqsum);
    else
        return 0;  
}

int yadaoperator_getdata(char valuebuf[],char savedata[])
{
    double dvalue = 0;
    double buf;
    double athdu,bthdu,cthdu,athdi,bthdi,cthdi;
    double vfa,vfb,vfc,cfa,cfb,cfc;  
       
    athdu = getmeansquare(valuebuf,(V_har_coA2_yada),20);
    bthdu = getmeansquare(valuebuf,(V_har_coB2_yada),20);
    cthdu = getmeansquare(valuebuf,(V_har_coC2_yada),20);
    athdi = getmeansquare(valuebuf,(C_harA2_yada),20);
    bthdi = getmeansquare(valuebuf,(C_harB2_yada),20);
    cthdi = getmeansquare(valuebuf,(C_harC2_yada),20);

    dvalue = getrealvalue(valuebuf,V_A_yada,4,4);
    vfa = dvalue / sqrt(1+ athdu * athdu);
    insertsavedatar(savedata,V_fundA,vfa,4,4);    //A相基波电压
     
    dvalue = getrealvalue(valuebuf,V_B_yada,4,4);
    vfb = dvalue / (sqrt(1+bthdu * bthdu)); 
    insertsavedatar(savedata,V_fundB,vfb,4,4);    //B相基波电压

    dvalue = getrealvalue(valuebuf,V_C_yada,4,4);
    vfc = dvalue / (sqrt(1+cthdu * cthdu)); 
    insertsavedatar(savedata,V_fundC,vfc,4,4);    //C相基波电压

    dvalue = getrealvalue(valuebuf,C_A_yada,4,4);
    cfa = dvalue / (sqrt(1+athdi * athdi)); 
    insertsavedatar(savedata,C_fundA,cfa,4,4);    //A相基波电流

    dvalue = getrealvalue(valuebuf,C_B_yada,4,4);
    cfb = dvalue / (sqrt(1+bthdi * bthdi)); 
    insertsavedatar(savedata,C_fundB,cfb,4,4);    //B相基波电流

    dvalue = getrealvalue(valuebuf,C_C_yada,4,4);
    cfc = dvalue / (sqrt(1+cthdi * cthdi)); 
    insertsavedatar(savedata,C_fundC,cfc,4,4);    //C相基波电流	
    
    insertsavedata(valuebuf,savedata,V_A_yada,V_A,4);  //A相电压
    insertsavedata(valuebuf,savedata,V_B_yada,V_B,4);  //B相电压
    insertsavedata(valuebuf,savedata,V_C_yada,V_C,4);  //C相电压
    insertsavedata(valuebuf,savedata,C_A_yada,C_A,4);  //B相电流
    insertsavedata(valuebuf,savedata,C_B_yada,C_B,4);  //B相电流	
    insertsavedata(valuebuf,savedata,C_C_yada,C_C,4);  //C相电流	
    insertsavedata(valuebuf,savedata,Act_powerA_yada,Act_powerA,4); //A相有功
    insertsavedata(valuebuf,savedata,Act_powerB_yada,Act_powerB,4); //B相有功	
    insertsavedata(valuebuf,savedata,Act_powerC_yada,Act_powerC,4); //C相有功	
    insertsavedata(valuebuf,savedata,Act_powerT_yada,Act_powerT,4); //总有功	
    insertsavedata(valuebuf,savedata,Rea_powerA_yada,Rea_powerA,4); //A相无功	
    insertsavedata(valuebuf,savedata,Rea_powerB_yada,Rea_powerB,4); //B相无功	
    insertsavedata(valuebuf,savedata,Rea_powerC_yada,Rea_powerC,4); //C相无功	
    insertsavedata(valuebuf,savedata,Rea_powerT_yada,Rea_powerT,4); //总无功	
    insertsavedata(valuebuf,savedata,App_powerA_yada,App_powerA,4); //A相视在
    insertsavedata(valuebuf,savedata,App_powerB_yada,App_powerB,4); //B相视在	
    insertsavedata(valuebuf,savedata,App_powerC_yada,App_powerC,4); //C相视在	
    insertsavedata(valuebuf,savedata,App_powerT_yada,App_powerT,4); //总视在	
    insertsavedata(valuebuf,savedata,powerfac_A_yada,powerfac_A,2); //A相PF	
    insertsavedata(valuebuf,savedata,powerfac_B_yada,powerfac_B,2); //B相PF	
    insertsavedata(valuebuf,savedata,powerfac_C_yada,powerfac_C,2); //C相PF	
    insertsavedata(valuebuf,savedata,powerfac_T_yada,powerfac_T,2); //总PF	
    insertsavedata(valuebuf,savedata,frequency_yada,frequency,2);   //频率	

    insertsavedata(valuebuf,savedata,V_har_coA2_yada,V_har_coA2,2); //A相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coA3_yada,V_har_coA3,2); //A相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coA4_yada,V_har_coA4,2); //A相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coA5_yada,V_har_coA5,2); //A相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coA6_yada,V_har_coA6,2); //A相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coA7_yada,V_har_coA7,2); //A相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coA8_yada,V_har_coA8,2); //A相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coA9_yada,V_har_coA9,2); //A相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coA10_yada,V_har_coA10,2); //A相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coA11_yada,V_har_coA11,2); //A相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coA12_yada,V_har_coA12,2); //A相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coA13_yada,V_har_coA13,2); //A相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coA14_yada,V_har_coA14,2); //A相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coA15_yada,V_har_coA15,2); //A相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coA16_yada,V_har_coA16,2); //A相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coA17_yada,V_har_coA17,2); //A相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coA18_yada,V_har_coA18,2); //A相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coA19_yada,V_har_coA19,2); //A相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coA20_yada,V_har_coA20,2); //A相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coA21_yada,V_har_coA21,2); //A相谐波电压含有率（21）	

    insertsavedata(valuebuf,savedata,V_har_coB2_yada,V_har_coB2,2); //B相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coB3_yada,V_har_coB3,2); //B相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coB4_yada,V_har_coB4,2); //B相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coB5_yada,V_har_coB5,2); //B相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coB6_yada,V_har_coB6,2); //B相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coB7_yada,V_har_coB7,2); //B相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coB8_yada,V_har_coB8,2); //B相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coB9_yada,V_har_coB9,2); //B相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coB10_yada,V_har_coB10,2); //B相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coB11_yada,V_har_coB11,2); //B相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coB12_yada,V_har_coB12,2); //B相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coB13_yada,V_har_coB13,2); //B相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coB14_yada,V_har_coB14,2); //B相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coB15_yada,V_har_coB15,2); //B相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coB16_yada,V_har_coB16,2); //B相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coB17_yada,V_har_coB17,2); //B相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coB18_yada,V_har_coB18,2); //B相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coB19_yada,V_har_coB19,2); //B相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coB20_yada,V_har_coB20,2); //B相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coB21_yada,V_har_coB21,2); //B相谐波电压含有率（21）

    insertsavedata(valuebuf,savedata,V_har_coC2_yada,V_har_coC2,2); //C相谐波电压含有率（2）	
    insertsavedata(valuebuf,savedata,V_har_coC3_yada,V_har_coC3,2); //C相谐波电压含有率（3）	
    insertsavedata(valuebuf,savedata,V_har_coC4_yada,V_har_coC4,2); //C相谐波电压含有率（4）	
    insertsavedata(valuebuf,savedata,V_har_coC5_yada,V_har_coC5,2); //C相谐波电压含有率（5）	
    insertsavedata(valuebuf,savedata,V_har_coC6_yada,V_har_coC6,2); //C相谐波电压含有率（6）	
    insertsavedata(valuebuf,savedata,V_har_coC7_yada,V_har_coC7,2); //C相谐波电压含有率（7）	
    insertsavedata(valuebuf,savedata,V_har_coC8_yada,V_har_coC8,2); //C相谐波电压含有率（8）	
    insertsavedata(valuebuf,savedata,V_har_coC9_yada,V_har_coC9,2); //C相谐波电压含有率（9）	
    insertsavedata(valuebuf,savedata,V_har_coC10_yada,V_har_coC10,2); //C相谐波电压含有率（10）	
    insertsavedata(valuebuf,savedata,V_har_coC11_yada,V_har_coC11,2); //C相谐波电压含有率（11）	
    insertsavedata(valuebuf,savedata,V_har_coC12_yada,V_har_coC12,2); //C相谐波电压含有率（12）	
    insertsavedata(valuebuf,savedata,V_har_coC13_yada,V_har_coC13,2); //C相谐波电压含有率（13）	
    insertsavedata(valuebuf,savedata,V_har_coC14_yada,V_har_coC14,2); //C相谐波电压含有率（14）	
    insertsavedata(valuebuf,savedata,V_har_coC15_yada,V_har_coC15,2); //C相谐波电压含有率（15）	
    insertsavedata(valuebuf,savedata,V_har_coC16_yada,V_har_coC16,2); //C相谐波电压含有率（16）	
    insertsavedata(valuebuf,savedata,V_har_coC17_yada,V_har_coC17,2); //C相谐波电压含有率（17）	
    insertsavedata(valuebuf,savedata,V_har_coC18_yada,V_har_coC18,2); //C相谐波电压含有率（18）	
    insertsavedata(valuebuf,savedata,V_har_coC19_yada,V_har_coC19,2); //C相谐波电压含有率（19）	
    insertsavedata(valuebuf,savedata,V_har_coC20_yada,V_har_coC20,2); //C相谐波电压含有率（20）	
    insertsavedata(valuebuf,savedata,V_har_coC21_yada,V_har_coC21,2); //C相谐波电压含有率（21）

    dvalue = getrealvalue(valuebuf,C_harA2_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA2,dvalue,4,4);    //A相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harA3_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA3,dvalue,4,4);    //A相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harA4_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA4,dvalue,4,4);    //A相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harA5_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA5,dvalue,4,4);    //A相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harA6_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA6,dvalue,4,4);    //A相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harA7_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA7,dvalue,4,4);    //A相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harA8_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA8,dvalue,4,4);    //A相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harA9_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA9,dvalue,4,4);    //A相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harA10_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA10,dvalue,4,4);    //A相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harA11_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA11,dvalue,4,4);    //A相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harA12_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA12,dvalue,4,4);    //A相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harA13_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA13,dvalue,4,4);    //A相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harA14_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA14,dvalue,4,4);    //A相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harA15_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA15,dvalue,4,4);    //A相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harA16_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA16,dvalue,4,4);    //A相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harA17_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA17,dvalue,4,4);    //A相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harA18_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA18,dvalue,4,4);    //A相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harA19_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA19,dvalue,4,4);    //A相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harA20_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA20,dvalue,4,4);    //A相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harA21_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harA21,dvalue,4,4);    //A相谐波电流（21）    

    dvalue = getrealvalue(valuebuf,C_harB2_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB2,dvalue,4,4);    //B相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harB3_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB3,dvalue,4,4);    //B相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harB4_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB4,dvalue,4,4);    //B相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harB5_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB5,dvalue,4,4);    //B相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harB6_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB6,dvalue,4,4);    //B相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harB7_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB7,dvalue,4,4);    //B相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harB8_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB8,dvalue,4,4);    //B相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harB9_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB9,dvalue,4,4);    //B相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harB10_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB10,dvalue,4,4);    //B相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harB11_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB11,dvalue,4,4);    //B相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harB12_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB12,dvalue,4,4);    //B相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harB13_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB13,dvalue,4,4);    //B相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harB14_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB14,dvalue,4,4);    //B相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harB15_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB15,dvalue,4,4);    //B相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harB16_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB16,dvalue,4,4);    //B相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harB17_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB17,dvalue,4,4);    //B相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harB18_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB18,dvalue,4,4);    //B相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harB19_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB19,dvalue,4,4);    //B相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harB20_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB20,dvalue,4,4);    //B相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harB21_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harB21,dvalue,4,4);    //B相谐波电流（21）

    dvalue = getrealvalue(valuebuf,C_harC2_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC2,dvalue,4,4);    //C相谐波电流（2）

    dvalue = getrealvalue(valuebuf,C_harC3_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC3,dvalue,4,4);    //C相谐波电流（3） 
   
    dvalue = getrealvalue(valuebuf,C_harC4_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC4,dvalue,4,4);    //C相谐波电流（4）

    dvalue = getrealvalue(valuebuf,C_harC5_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC5,dvalue,4,4);    //C相谐波电流（5）

    dvalue = getrealvalue(valuebuf,C_harC6_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC6,dvalue,4,4);    //C相谐波电流（6）

    dvalue = getrealvalue(valuebuf,C_harC7_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC7,dvalue,4,4);    //C相谐波电流（7）

    dvalue = getrealvalue(valuebuf,C_harC8_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC8,dvalue,4,4);    //C相谐波电流（8）

    dvalue = getrealvalue(valuebuf,C_harC9_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC9,dvalue,4,4);    //C相谐波电流（9）

    dvalue = getrealvalue(valuebuf,C_harC10_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC10,dvalue,4,4);    //C相谐波电流（10）

    dvalue = getrealvalue(valuebuf,C_harC11_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC11,dvalue,4,4);    //C相谐波电流（11）

    dvalue = getrealvalue(valuebuf,C_harC12_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC12,dvalue,4,4);    //C相谐波电流（12）

    dvalue = getrealvalue(valuebuf,C_harC13_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC13,dvalue,4,4);    //C相谐波电流（13）

    dvalue = getrealvalue(valuebuf,C_harC14_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC14,dvalue,4,4);    //C相谐波电流（14）

    dvalue = getrealvalue(valuebuf,C_harC15_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC15,dvalue,4,4);    //C相谐波电流（15）

    dvalue = getrealvalue(valuebuf,C_harC16_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC16,dvalue,4,4);    //C相谐波电流（16）

    dvalue = getrealvalue(valuebuf,C_harC17_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC17,dvalue,4,4);    //C相谐波电流（17）

    dvalue = getrealvalue(valuebuf,C_harC18_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC18,dvalue,4,4);    //C相谐波电流（18）

    dvalue = getrealvalue(valuebuf,C_harC19_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC19,dvalue,4,4);    //C相谐波电流（19）

    dvalue = getrealvalue(valuebuf,C_harC20_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC20,dvalue,4,4);    //C相谐波电流（20）

    dvalue = getrealvalue(valuebuf,C_harC21_yada,2,2);
    dvalue = cfa * dvalue / 100;
    insertsavedatar(savedata,C_harC21,dvalue,4,4);    //C相谐波电流（21）

    insertsavedatar(savedata,V_wav_disA,athdu,2,4);  //A相电压谐波畸变率
    insertsavedatar(savedata,V_wav_disB,bthdu,2,4);  //B相电压谐波畸变率
    insertsavedatar(savedata,V_wav_disC,cthdu,2,4);  //C相电压谐波畸变率
    insertsavedatar(savedata,C_wav_disA,athdi,2,4);  //A相电流谐波畸变率
    insertsavedatar(savedata,C_wav_disB,bthdi,2,4);  //B相电流谐波畸变率
    insertsavedatar(savedata,C_wav_disC,cthdi,2,4);  //C相电流谐波畸变率

    insertsavedata(valuebuf,savedata,P_act_powT_yada,P_act_powT,4);   //总正向有功总电能
    insertsavedata(valuebuf,savedata,P_rea_PowT_yada,P_rea_powT,4);   //总正向无功总电能
    insertsavedata(valuebuf,savedata,R_act_powT_yada,R_act_powT,4);   //总反向有功总电能
    insertsavedata(valuebuf,savedata,R_rea_powT_yada,R_rea_powT,4);   //总反向无功总电能	

    //savedata[V_imdegree] = valuebuf[V_imdegree_yada]; //电压不平衡度	3	1412
    //savedata[C_imdegree] = valuebuf[C_imdegree_yada]; //电流不平衡度	3	1415
}


