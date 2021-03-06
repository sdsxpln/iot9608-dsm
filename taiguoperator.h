#ifndef TAIGUOPERATOR_H
#define TAIDUOPERATOR_H
#include "fileoperator.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define V_A_taigu 3   //A相电压 2
#define V_B_taigu 5   //B相电压 2
#define V_C_taigu 7   //C相电压 2

#define V_ABline_taigu 17   //AB线电压 2
#define V_BCline_taigu 19   //BC线电压 2
#define V_CAline_taigu 21   //CA线电压 2

#define C_A_taigu 37  //A相电流 2
#define C_B_taigu 39  //B相电流 2	
#define C_C_taigu 41  //C相电流 2

#define C_zero_taigu 51     //零线电流 2
#define C_low_taigu  53     //low currunt 2

#define phase_angA_taigu 31 //AB相相角 2
#define phase_angB_taigu 33 //BC相相角 2
#define phase_angC_taigu 35 //CA相相角 2

#define V_wav_disA_taigu 326 //A相电压波形失真度 2
#define V_wav_disB_taigu 328 //B相电压波形失真度 2
#define V_wav_disC_taigu 330 //C相电压波形失真度 2
#define C_wav_disA_taigu 117 //A相电流波形失真度 2
#define C_wav_disB_taigu 119 //B相电流波形失真度 2
#define C_wav_disC_taigu 121 //C相电流波形失真度 2
#define V_imdegree_taigu 15  //电压不平衡度      2
#define C_imdegree_taigu 43  //电流不平衡度      2
	
#define Act_powerA_taigu 55 //A相有功	2	
#define Act_powerB_taigu 57 //B相有功	2	
#define Act_powerC_taigu 59 //C相有功	2	
#define Act_powerT_taigu 61 //总有功	4	
#define Rea_powerA_taigu 65 //A相无功	2	
#define Rea_powerB_taigu 67 //B相无功	2	
#define Rea_powerC_taigu 69 //C相无功	2	
#define Rea_powerT_taigu 71 //总无功	4	
//#define App_powerA_taigu 293 //A相视在	2	
//#define App_powerB_taigu 297 //B相视在	2	
//#define App_powerC_taigu 301 //C相视在	2	
//#define App_powerT_taigu 289 //总视在	2	
#define powerfac_A_taigu 75  //A相PF	2	
#define powerfac_B_taigu 77  //B相PF	2	
#define powerfac_C_taigu 79  //C相PF	2	
#define powerfac_T_taigu 81  //总PF	2	
#define frequency_taigu  83  //频率	2	

#define V_har_coA2_taigu 344 //A相谐波电压含有率（2）	2	
#define V_har_coA3_taigu 346 //A相谐波电压含有率（3）	2	
#define V_har_coA4_taigu 348 //A相谐波电压含有率（4）	2	
#define V_har_coA5_taigu 350 //A相谐波电压含有率（5）	2
#define V_har_coA6_taigu 352 //A相谐波电压含有率（6）	2
#define V_har_coA7_taigu 354 //A相谐波电压含有率（7）	2
#define V_har_coA8_taigu 356 //A相谐波电压含有率（8）	2
#define V_har_coA9_taigu 358 //A相谐波电压含有率（9）	2
#define V_har_coA10_taigu 360 //A相谐波电压含有率（10）	2
#define V_har_coA11_taigu 362 //A相谐波电压含有率（11）	2
#define V_har_coA12_taigu 364 //A相谐波电压含有率（12）	2
#define V_har_coA13_taigu 366 //A相谐波电压含有率（13）	2
#define V_har_coA14_taigu 368 //A相谐波电压含有率（14）	2
#define V_har_coA15_taigu 370 //A相谐波电压含有率（15）	2
#define V_har_coA16_taigu 372 //A相谐波电压含有率（16）	2
#define V_har_coA17_taigu 374 //A相谐波电压含有率（17）	2
#define V_har_coA18_taigu 376 //A相谐波电压含有率（18）	2
#define V_har_coA19_taigu 378 //A相谐波电压含有率（19）	2
#define V_har_coA20_taigu 380 //A相谐波电压含有率（20）	2
#define V_har_coA21_taigu 382 //A相谐波电压含有率（21）	2
#define V_har_coA22_taigu 384 //A相谐波电压含有率（22）	2
#define V_har_coA23_taigu 386 //A相谐波电压含有率（23）	2
#define V_har_coA24_taigu 388 //A相谐波电压含有率（24）	2
#define V_har_coA25_taigu 390 //A相谐波电压含有率（25）	2
#define V_har_coA26_taigu 392 //A相谐波电压含有率（26）	2
#define V_har_coA27_taigu 394 //A相谐波电压含有率（27）	2
#define V_har_coA28_taigu 396 //A相谐波电压含有率（28）	2
#define V_har_coA29_taigu 398 //A相谐波电压含有率（29）	2
#define V_har_coA30_taigu 400 //A相谐波电压含有率（30）	2
#define V_har_coA31_taigu 402 //A相谐波电压含有率（31）	2

#define V_har_coB2_taigu 404 //B相谐波电压含有率（2）	2
#define V_har_coB3_taigu 406 //B相谐波电压含有率（3）	2
#define V_har_coB4_taigu 408 //B相谐波电压含有率（4）	2
#define V_har_coB5_taigu 410 //B相谐波电压含有率（5）	2
#define V_har_coB6_taigu 412 //B相谐波电压含有率（6）	2
#define V_har_coB7_taigu 414 //B相谐波电压含有率（7）	2
#define V_har_coB8_taigu 416 //B相谐波电压含有率（8）	2
#define V_har_coB9_taigu 418 //B相谐波电压含有率（9）	2
#define V_har_coB10_taigu 420 //B相谐波电压含有率（10）	2
#define V_har_coB11_taigu 422 //B相谐波电压含有率（11）	2
#define V_har_coB12_taigu 424 //B相谐波电压含有率（12）	2
#define V_har_coB13_taigu 426 //B相谐波电压含有率（13）	2
#define V_har_coB14_taigu 428 //B相谐波电压含有率（14）	2
#define V_har_coB15_taigu 430 //B相谐波电压含有率（15）	2
#define V_har_coB16_taigu 432 //B相谐波电压含有率（16）	2
#define V_har_coB17_taigu 434 //B相谐波电压含有率（17）	2
#define V_har_coB18_taigu 436 //B相谐波电压含有率（18）	2
#define V_har_coB19_taigu 438 //B相谐波电压含有率（19）	2
#define V_har_coB20_taigu 440 //B相谐波电压含有率（20）	2
#define V_har_coB21_taigu 442 //B相谐波电压含有率（21）	2
#define V_har_coB22_taigu 444 //B相谐波电压含有率（22）	2
#define V_har_coB23_taigu 446 //B相谐波电压含有率（23）	2
#define V_har_coB24_taigu 448 //B相谐波电压含有率（24）	2
#define V_har_coB25_taigu 450 //B相谐波电压含有率（25）	2
#define V_har_coB26_taigu 452 //B相谐波电压含有率（26）	2
#define V_har_coB27_taigu 454 //B相谐波电压含有率（27）	2
#define V_har_coB28_taigu 456 //B相谐波电压含有率（28）	2
#define V_har_coB29_taigu 458 //B相谐波电压含有率（29）	2
#define V_har_coB30_taigu 460 //B相谐波电压含有率（30）	2
#define V_har_coB31_taigu 462 //B相谐波电压含有率（31）	2

#define V_har_coC2_taigu 464 //C相谐波电压含有率（2）	2
#define V_har_coC3_taigu 466 //C相谐波电压含有率（3）	2
#define V_har_coC4_taigu 468 //C相谐波电压含有率（4）	2
#define V_har_coC5_taigu 470 //C相谐波电压含有率（5）	2
#define V_har_coC6_taigu 472 //C相谐波电压含有率（6）	2
#define V_har_coC7_taigu 474 //C相谐波电压含有率（7）	2
#define V_har_coC8_taigu 476 //C相谐波电压含有率（8）	2
#define V_har_coC9_taigu 478 //C相谐波电压含有率（9）	2
#define V_har_coC10_taigu 480 //C相谐波电压含有率（10）	2
#define V_har_coC11_taigu 482 //C相谐波电压含有率（11）	2
#define V_har_coC12_taigu 484 //C相谐波电压含有率（12）	2
#define V_har_coC13_taigu 486 //C相谐波电压含有率（13）	2
#define V_har_coC14_taigu 488 //C相谐波电压含有率（14）	2
#define V_har_coC15_taigu 490 //C相谐波电压含有率（15）	2
#define V_har_coC16_taigu 492 //C相谐波电压含有率（16）	2
#define V_har_coC17_taigu 494 //C相谐波电压含有率（17）	2
#define V_har_coC18_taigu 496 //C相谐波电压含有率（18）	2
#define V_har_coC19_taigu 498 //C相谐波电压含有率（19）	2
#define V_har_coC20_taigu 500 //C相谐波电压含有率（20）	2
#define V_har_coC21_taigu 502 //C相谐波电压含有率（21）	2
#define V_har_coC22_taigu 504 //C相谐波电压含有率（22）	2
#define V_har_coC23_taigu 506 //C相谐波电压含有率（23）	2
#define V_har_coC24_taigu 508 //C相谐波电压含有率（24）	2
#define V_har_coC25_taigu 510 //C相谐波电压含有率（25）	2
#define V_har_coC26_taigu 512 //C相谐波电压含有率（26）	2
#define V_har_coC27_taigu 514 //C相谐波电压含有率（27）	2
#define V_har_coC28_taigu 516 //C相谐波电压含有率（28）	2
#define V_har_coC29_taigu 518 //C相谐波电压含有率（29）	2
#define V_har_coC30_taigu 520 //C相谐波电压含有率（30）	2
#define V_har_coC31_taigu 522 //C相谐波电压含有率（31）	2

#define C_harA2_taigu 135 //A相谐波电流（2）	2
#define C_harA3_taigu 137 //A相谐波电流（3）	2
#define C_harA4_taigu 139 //A相谐波电流（4）	2
#define C_harA5_taigu 141 //A相谐波电流（5）	2
#define C_harA6_taigu 143 //A相谐波电流（6）	2
#define C_harA7_taigu 145 //A相谐波电流（7）	2
#define C_harA8_taigu 147 //A相谐波电流（8）	2
#define C_harA9_taigu 149 //A相谐波电流（9）	2
#define C_harA10_taigu 151 //A相谐波电流（10）	2
#define C_harA11_taigu 153 //A相谐波电流（11）	2
#define C_harA12_taigu 155 //A相谐波电流（12）	2
#define C_harA13_taigu 157 //A相谐波电流（13）	2
#define C_harA14_taigu 159 //A相谐波电流（14）	2
#define C_harA15_taigu 161 //A相谐波电流（15）	2
#define C_harA16_taigu 163 //A相谐波电流（16）	2
#define C_harA17_taigu 165 //A相谐波电流（17）	2
#define C_harA18_taigu 167 //A相谐波电流（18）	2
#define C_harA19_taigu 169 //A相谐波电流（19）	2
#define C_harA20_taigu 171 //A相谐波电流（20）	2
#define C_harA21_taigu 173 //A相谐波电流（21）	2
#define C_harA22_taigu 175 //A相谐波电流（22）	2
#define C_harA23_taigu 177 //A相谐波电流（23）	2
#define C_harA24_taigu 179 //A相谐波电流（24）	2
#define C_harA25_taigu 181 //A相谐波电流（25）	2
#define C_harA26_taigu 183 //A相谐波电流（26）	2
#define C_harA27_taigu 185 //A相谐波电流（27）	2
#define C_harA28_taigu 187 //A相谐波电流（28）	2
#define C_harA29_taigu 189 //A相谐波电流（29）	2
#define C_harA30_taigu 191 //A相谐波电流（30）	2
#define C_harA31_taigu 193 //A相谐波电流（31）	2

#define C_harB2_taigu 195 //B相谐波电流（2）	2
#define C_harB3_taigu 197 //B相谐波电流（3）	2
#define C_harB4_taigu 199 //B相谐波电流（4）	2
#define C_harB5_taigu 201 //B相谐波电流（5）	2
#define C_harB6_taigu 203 //B相谐波电流（6）	2
#define C_harB7_taigu 205 //B相谐波电流（7）	2
#define C_harB8_taigu 207 //B相谐波电流（8）	2
#define C_harB9_taigu 209 //B相谐波电流（9）	2
#define C_harB10_taigu 211 //B相谐波电流（10）	2
#define C_harB11_taigu 213 //B相谐波电流（11）	2
#define C_harB12_taigu 215 //B相谐波电流（12）	2
#define C_harB13_taigu 217 //B相谐波电流（13）	2
#define C_harB14_taigu 219 //B相谐波电流（14）	2
#define C_harB15_taigu 221 //B相谐波电流（15）	2
#define C_harB16_taigu 223 //B相谐波电流（16）	2
#define C_harB17_taigu 225 //B相谐波电流（17）	2
#define C_harB18_taigu 227 //B相谐波电流（18）	2
#define C_harB19_taigu 229 //B相谐波电流（19）	2
#define C_harB20_taigu 231 //B相谐波电流（20）	2
#define C_harB21_taigu 233 //B相谐波电流（21）	2
#define C_harB22_taigu 235 //B相谐波电流（22）	2
#define C_harB23_taigu 237 //B相谐波电流（23）	2
#define C_harB24_taigu 239 //B相谐波电流（24）	2
#define C_harB25_taigu 241 //B相谐波电流（25）	2
#define C_harB26_taigu 243 //B相谐波电流（26）	2
#define C_harB27_taigu 245 //B相谐波电流（27）	2
#define C_harB28_taigu 247 //B相谐波电流（28）	2
#define C_harB29_taigu 249 //B相谐波电流（29）	2
#define C_harB30_taigu 251 //B相谐波电流（30）	2
#define C_harB31_taigu 253 //B相谐波电流（31）	2

#define C_harC2_taigu 255 //C相谐波电流（2）	2
#define C_harC3_taigu 257 //C相谐波电流（3）	2
#define C_harC4_taigu 259 //C相谐波电流（4）	2
#define C_harC5_taigu 261 //C相谐波电流（5）	2
#define C_harC6_taigu 263 //C相谐波电流（6）	2
#define C_harC7_taigu 265 //C相谐波电流（7）	2
#define C_harC8_taigu 267 //C相谐波电流（8）	2
#define C_harC9_taigu 269 //C相谐波电流（9）	2
#define C_harC10_taigu 271 //C相谐波电流（10）	2
#define C_harC11_taigu 273 //C相谐波电流（11）	2
#define C_harC12_taigu 275 //C相谐波电流（12）	2
#define C_harC13_taigu 277 //C相谐波电流（13）	2
#define C_harC14_taigu 279 //C相谐波电流（14）	2
#define C_harC15_taigu 281 //C相谐波电流（15）	2
#define C_harC16_taigu 283 //C相谐波电流（16）	2
#define C_harC17_taigu 285 //C相谐波电流（17）	2
#define C_harC18_taigu 287 //C相谐波电流（18）	2
#define C_harC19_taigu 289 //C相谐波电流（19）	2
#define C_harC20_taigu 291 //C相谐波电流（20）	2
#define C_harC21_taigu 293 //C相谐波电流（21）	2
#define C_harC22_taigu 295 //C相谐波电流（22）	2
#define C_harC23_taigu 297 //C相谐波电流（23）	2
#define C_harC24_taigu 299 //C相谐波电流（24）	2
#define C_harC25_taigu 301 //C相谐波电流（25）	2
#define C_harC26_taigu 303 //C相谐波电流（26）	2
#define C_harC27_taigu 305 //C相谐波电流（27）	2
#define C_harC28_taigu 307 //C相谐波电流（28）	2
#define C_harC29_taigu 309 //C相谐波电流（29）	2
#define C_harC30_taigu 311 //C相谐波电流（30）	2
#define C_harC31_taigu 313 //C相谐波电流（31）	2

#define P_act_powT_taigu 94  //有功总电能	4
#define P_rea_PowT_taigu 102 //无功总电能	4

extern int taiguoperator_getdata(char valuebuf[],char savedata[]);
#endif
