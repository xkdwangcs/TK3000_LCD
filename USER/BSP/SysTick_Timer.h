#ifndef __SYSTICK_TIMER_H
#define __SYSTICK_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"
#include "Handlers.h"
#include <stdlib.h> 
	

//һ����ʱ��������������ʱ��
#define SoftTimerCount 10 //��ʱ���������Ŀ
	
typedef enum
{
	SingTimer,	  //���ζ�ʱ��
	LoopTimer,	  //ѭ���Ķ�ζ�ʱ��
}SoftTimerType; //�����ʱ������	
	
typedef struct
{
	volatile SoftTimerType TimerType; 			  //��ʱ������
	volatile bool IsUse; 						          //�Ƿ�ʹ�ö�ʱ��
	volatile bool IsEnable;						        //��ʱ���Ƿ�ʹ��
	volatile u32 Count;  						          //��ǰ��ʱ���еļ�ʱ
	volatile u32 PreValue;						        //��ʱ����Ŀ��ֵ(ms),�������ֵ�������¼�(���ûص�)
	volatile OneIntParameterHandler CallFunc;	//�ص����������صĲ���Ϊ��ʱ������������0��ʼ��	
}SoftTimerStruct;//��ʱ���ṹ�壬��Ա���������� volatile, ����C�������Ż�ʱ���������� 

typedef struct
{
	volatile u32 TimerValue; 				//��ǰ��ʱ����ֵ(ms)
	volatile SoftTimerStruct SoftTimers[SoftTimerCount];	//��ʱ���б���ʱ���������ɵ������Լ�ά��
}TimekeeperStruct;//��ʱ���ṹ��

//��ʼ����ʱ��
void IniTimekeeper(void);
//��ȡ��ʱ����ǰ�ļ�ʱ������λms
u32 GetTimekeeperValue(void);
//��ʼ��ʱ��,��ʼ�����������
//void StartTimekeeper(void);
//��λ��ʱ��
void ResetTimekeeper(void);
//ֹͣ��ʱ��
//void StopTimekeeper(void);

//����һ����ʱ������������ɹ��򷵻�0��ʼ�����������򷵻�0xFF
//timerType:��ʱ�����ͣ�perValue:��ʱ��Ԥװֵ������ʱ���ۼƵ���ֵ���������ص���callFunc���ص�����
u8 CreateSoftTimer(SoftTimerType timerType,u32 perValue,OneIntParameterHandler callFunc);
//ɾ��һ����ʱ�����ͷŶ�ʱ��
void DeleteSoftTimer(u8 timerIndex);
//��ʼһ����ʱ��
void StartSoftTimer(u8 timerIndex);
//��λһ����ʱ��
void ResetSoftTimer(u8 timerIndex);
//ֹͣһ����ʱ��
void StopSoftTimer(u8 timerIndex);

//��ʼϵͳ�δ�ʱ��
void SysTick_Init(void); 
//��ʱms
void Delay_ms_Tick(u32 time);
//��ʱ����
void Delay_s_Tick(float time_s);  
//��ʱus��ݬδʵ��
void Delay_us_Tick(u32 time);
  
#ifdef __cplusplus
}
#endif

#endif