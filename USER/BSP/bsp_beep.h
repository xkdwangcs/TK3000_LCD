#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "stm32f4xx.h"


/* ���ⲿ���õĺ������� */
void BEEP_InitHard(void);
//����������
void LCDBeep(u32 timems);

#endif
