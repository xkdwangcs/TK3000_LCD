#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "stm32f4xx.h"


/* 供外部调用的函数声明 */
void BEEP_InitHard(void);
//蜂鸣器鸣叫
void LCDBeep(u32 timems);

#endif
