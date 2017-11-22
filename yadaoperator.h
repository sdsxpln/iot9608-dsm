#ifndef YADAOPERATOR_H
#define YADAOPERATOR_H
#include "fileoperator.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define V_A_yada 228 //A相电压 4
#define V_B_yada 232 //B相电压 4
#define V_C_yada 236 //C相电压 4
#define C_A_yada 240 //A相电流 4
#define C_B_yada 244 //B相电流 4	
#define C_C_yada 248 //C相电流 4	
#define Act_powerA_yada 261 //A相有功	4	
#define Act_powerB_yada 265 //B相有功	4	
#define Act_powerC_yada 269 //C相有功	4	
#define Act_powerT_yada 252 //总有功	4	
#define Rea_powerA_yada 277 //A相无功	4	
#define Rea_powerB_yada 281 //B相无功	4	
#define Rea_powerC_yada 285 //C相无功	4	
#define Rea_powerT_yada 273 //总无功	4	
#define App_powerA_yada 293 //A相视在	4	
#define App_powerB_yada 297 //B相视在	4	
#define App_powerC_yada 301 //C相视在	4	
#define App_powerT_yada 289 //总视在	4	
#define powerfac_A_yada 307 //A相PF	2	
#define powerfac_B_yada 309 //B相PF	2	
#define powerfac_C_yada 311 //C相PF	2	
#define powerfac_T_yada 305 //总PF	2	
#define frequency_yada 319  //频率	2	

#define V_har_coA2_yada 328 //A相谐波电压含有率（2）	2	
#define V_har_coA3_yada 330 //A相谐波电压含有率（3）	2	
#define V_har_coA4_yada 332 //A相谐波电压含有率（4）	2	
#define V_har_coA5_yada 334 //A相谐波电压含有率（5）	2
#define V_har_coA6_yada 336 //A相谐波电压含有率（6）	2
#define V_har_coA7_yada 338 //A相谐波电压含有率（7）	2
#define V_har_coA8_yada 340 //A相谐波电压含有率（8）	2
#define V_har_coA9_yada 342 //A相谐波电压含有率（9）	2
#define V_har_coA10_yada 344 //A相谐波电压含有率（10）	2
#define V_har_coA11_yada 346 //A相谐波电压含有率（11）	2
#define V_har_coA12_yada 348 //A相谐波电压含有率（12）	2
#define V_har_coA13_yada 350 //A相谐波电压含有率（13）	2
#define V_har_coA14_yada 352 //A相谐波电压含有率（14）	2
#define V_har_coA15_yada 354 //A相谐波电压含有率（15）	2
#define V_har_coA16_yada 356 //A相谐波电压含有率（16）	2
#define V_har_coA17_yada 358 //A相谐波电压含有率（17）	2
#define V_har_coA18_yada 360 //A相谐波电压含有率（18）	2
#define V_har_coA19_yada 362 //A相谐波电压含有率（19）	2
#define V_har_coA20_yada 364 //A相谐波电压含有率（20）	2
#define V_har_coA21_yada 366 //A相谐波电压含有率（21）	2

#define V_har_coB2_yada 370 //B相谐波电压含有率（2）	2
#define V_har_coB3_yada 372 //B相谐波电压含有率（3）	2
#define V_har_coB4_yada 374 //B相谐波电压含有率（4）	2
#define V_har_coB5_yada 376 //B相谐波电压含有率（5）	2
#define V_har_coB6_yada 378 //B相谐波电压含有率（6）	2
#define V_har_coB7_yada 380 //B相谐波电压含有率（7）	2
#define V_har_coB8_yada 382 //B相谐波电压含有率（8）	2
#define V_har_coB9_yada 384 //B相谐波电压含有率（9）	2
#define V_har_coB10_yada 386 //B相谐波电压含有率（10）	2
#define V_har_coB11_yada 388 //B相谐波电压含有率（11）	2
#define V_har_coB12_yada 390 //B相谐波电压含有率（12）	2
#define V_har_coB13_yada 392 //B相谐波电压含有率（13）	2
#define V_har_coB14_yada 394 //B相谐波电压含有率（14）	2
#define V_har_coB15_yada 396 //B相谐波电压含有率（15）	2
#define V_har_coB16_yada 398 //B相谐波电压含有率（16）	2
#define V_har_coB17_yada 400 //B相谐波电压含有率（17）	2
#define V_har_coB18_yada 402 //B相谐波电压含有率（18）	2
#define V_har_coB19_yada 404 //B相谐波电压含有率（19）	2
#define V_har_coB20_yada 406 //B相谐波电压含有率（20）	2
#define V_har_coB21_yada 408 //B相谐波电压含有率（21）	2

#define V_har_coC2_yada 412 //C相谐波电压含有率（2）	2
#define V_har_coC3_yada 414 //C相谐波电压含有率（3）	2
#define V_har_coC4_yada 416 //C相谐波电压含有率（4）	2
#define V_har_coC5_yada 418 //C相谐波电压含有率（5）	2
#define V_har_coC6_yada 420 //C相谐波电压含有率（6）	2
#define V_har_coC7_yada 422 //C相谐波电压含有率（7）	2
#define V_har_coC8_yada 424 //C相谐波电压含有率（8）	2
#define V_har_coC9_yada 426 //C相谐波电压含有率（9）	2
#define V_har_coC10_yada 428 //C相谐波电压含有率（10）	2
#define V_har_coC11_yada 430 //C相谐波电压含有率（11）	2
#define V_har_coC12_yada 432 //C相谐波电压含有率（12）	2
#define V_har_coC13_yada 434 //C相谐波电压含有率（13）	2
#define V_har_coC14_yada 436 //C相谐波电压含有率（14）	2
#define V_har_coC15_yada 438 //C相谐波电压含有率（15）	2
#define V_har_coC16_yada 440 //C相谐波电压含有率（16）	2
#define V_har_coC17_yada 442 //C相谐波电压含有率（17）	2
#define V_har_coC18_yada 444 //C相谐波电压含有率（18）	2
#define V_har_coC19_yada 446 //C相谐波电压含有率（19）	2
#define V_har_coC20_yada 448 //C相谐波电压含有率（20）	2
#define V_har_coC21_yada 450 //C相谐波电压含有率（21）	2

#define C_harA2_yada 459 //A相谐波电流（2）	2
#define C_harA3_yada 461 //A相谐波电流（3）	2
#define C_harA4_yada 463 //A相谐波电流（4）	2
#define C_harA5_yada 465 //A相谐波电流（5）	2
#define C_harA6_yada 467 //A相谐波电流（6）	2
#define C_harA7_yada 469 //A相谐波电流（7）	2
#define C_harA8_yada 471 //A相谐波电流（8）	2
#define C_harA9_yada 473 //A相谐波电流（9）	2
#define C_harA10_yada 475 //A相谐波电流（10）	2
#define C_harA11_yada 477 //A相谐波电流（11）	2
#define C_harA12_yada 479 //A相谐波电流（12）	2
#define C_harA13_yada 481 //A相谐波电流（13）	2
#define C_harA14_yada 483 //A相谐波电流（14）	2
#define C_harA15_yada 485 //A相谐波电流（15）	2
#define C_harA16_yada 487 //A相谐波电流（16）	2
#define C_harA17_yada 489 //A相谐波电流（17）	2
#define C_harA18_yada 491 //A相谐波电流（18）	2
#define C_harA19_yada 493 //A相谐波电流（19）	2
#define C_harA20_yada 495 //A相谐波电流（20）	2
#define C_harA21_yada 497 //A相谐波电流（21）	2

#define C_harB2_yada 501 //B相谐波电流（2）	2
#define C_harB3_yada 503 //B相谐波电流（3）	2
#define C_harB4_yada 505 //B相谐波电流（4）	2
#define C_harB5_yada 507 //B相谐波电流（5）	2
#define C_harB6_yada 509 //B相谐波电流（6）	2
#define C_harB7_yada 511 //B相谐波电流（7）	2
#define C_harB8_yada 513 //B相谐波电流（8）	2
#define C_harB9_yada 515 //B相谐波电流（9）	2
#define C_harB10_yada 517 //B相谐波电流（10）	2
#define C_harB11_yada 519 //B相谐波电流（11）	2
#define C_harB12_yada 521 //B相谐波电流（12）	2
#define C_harB13_yada 523 //B相谐波电流（13）	2
#define C_harB14_yada 525 //B相谐波电流（14）	2
#define C_harB15_yada 527 //B相谐波电流（15）	2
#define C_harB16_yada 529 //B相谐波电流（16）	2
#define C_harB17_yada 531 //B相谐波电流（17）	2
#define C_harB18_yada 533 //B相谐波电流（18）	2
#define C_harB19_yada 535 //B相谐波电流（19）	2
#define C_harB20_yada 537 //B相谐波电流（20）	2
#define C_harB21_yada 539 //B相谐波电流（21）	2

#define C_harC2_yada 543 //C相谐波电流（2）	2
#define C_harC3_yada 545 //C相谐波电流（3）	2
#define C_harC4_yada 547 //C相谐波电流（4）	2
#define C_harC5_yada 549 //C相谐波电流（5）	2
#define C_harC6_yada 551 //C相谐波电流（6）	2
#define C_harC7_yada 553 //C相谐波电流（7）	2
#define C_harC8_yada 555 //C相谐波电流（8）	2
#define C_harC9_yada 557 //C相谐波电流（9）	2
#define C_harC10_yada 559 //C相谐波电流（10）	2
#define C_harC11_yada 561 //C相谐波电流（11）	2
#define C_harC12_yada 563 //C相谐波电流（12）	2
#define C_harC13_yada 565 //C相谐波电流（13）	2
#define C_harC14_yada 567 //C相谐波电流（14）	2
#define C_harC15_yada 569 //C相谐波电流（15）	2
#define C_harC16_yada 571 //C相谐波电流（16）	2
#define C_harC17_yada 573 //C相谐波电流（17）	2
#define C_harC18_yada 575 //C相谐波电流（18）	2
#define C_harC19_yada 577 //C相谐波电流（19）	2
#define C_harC20_yada 579 //C相谐波电流（20）	2
#define C_harC21_yada 581 //C相谐波电流（21）	2

#define P_act_powT_yada 23 //总正向有功总电能	4
#define P_rea_PowT_yada 63 //总正向无功总电能	4
#define R_act_powT_yada 43 //总反向有功总电能	4
#define R_rea_powT_yada 83 //总反向无功总电能	4

extern int yadaoperator_getdata(char valuebuf[],char savedata[]);
#endif

