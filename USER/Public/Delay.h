#ifndef __SYSTICK_H
#define __SYSTICK_H
#ifdef __cplusplus
 extern "C" {
#endif 
#include "stm32f4xx.h"
#include "stdbool.h"	 
//��ʹ��SysTick��ֱ��ʹ������ʱ��SysTickҪռ���ж���Դ�ұ�ϵͳ����ʱ���Ȳ��Ǻܸ�
//extern vu32 TimingDelay;
//void Init_SysTick(void);
//void Delay_10us(u32 ntimes);
//void Delay_ms_tick(vu32 nTime);


//��ʱ��us
void Delay_us(u16 us);
//��ʱms
void Delay_ms(u16 t);
//��ʱ��
void Delay_s(float time_s);
     
#ifdef __cplusplus
}
#endif
#endif
