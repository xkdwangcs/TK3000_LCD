#include "bsp_beep.h"
#include "SysTick_Timer.h"

//#define BEEP_HAVE_POWER		//定义此行表示有源蜂鸣器，直接通过GPIO驱动, 无需PWM

#ifdef	BEEP_HAVE_POWER		//有源蜂鸣器
	//PA8
	#define GPIO_RCC_BEEP   RCC_AHB1Periph_GPIOA
	#define GPIO_PORT_BEEP	GPIOA
	#define GPIO_PIN_BEEP	GPIO_Pin_8

	#define BEEP_ENABLE()	GPIO_PORT_BEEP->BSRRL = GPIO_PIN_BEEP			//使能蜂鸣器鸣叫
	#define BEEP_DISABLE()	GPIO_PORT_BEEP->BSRRH = GPIO_PIN_BEEP			//禁止蜂鸣器鸣叫
#else		//无源蜂鸣器 
	//PA8 ---> TIM1_CH1
	#define BEEP_ENABLE()	bsp_SetTIMOutPWM(GPIOA, GPIO_Pin_8, TIM1, 1, 5000, 5000); //1500表示频率1.5KHz，5000表示50.00%的占空比	
	#define BEEP_DISABLE()	bsp_SetTIMOutPWM(GPIOA, GPIO_Pin_8, TIM1, 1, 1500, 0);//禁止蜂鸣器鸣叫
#endif

//蜂鸣器停止软定时器
int _beepStopTimer=0;

//初始化蜂鸣器硬件
void BEEP_InitHard(void)
{
#ifdef	BEEP_HAVE_POWER		//有源蜂鸣器
	GPIO_InitTypeDef GPIO_InitStructure;
	//打开GPIOF的时钟
	RCC_AHB1PeriphClockCmd(GPIO_RCC_BEEP, ENABLE);
	BEEP_DISABLE();
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//设为输出口
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//设为推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//上下拉电阻不使能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO口最大速度
	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_BEEP;
	GPIO_Init(GPIO_PORT_BEEP, &GPIO_InitStructure);
#endif	
}

void StopBeep(int v)
{
    BEEP_DISABLE();	
}

//蜂鸣器鸣叫
void LCDBeep(u32 timems)
{
    BEEP_DISABLE();	
    DeleteSoftTimer(_beepStopTimer);
    _beepStopTimer=CreateSoftTimer(SingTimer,timems,StopBeep);
    BEEP_ENABLE();			//开始发声    
    StartSoftTimer(_beepStopTimer);
}

