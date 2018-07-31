#include "bsp_beep.h"
#include "SysTick_Timer.h"

//#define BEEP_HAVE_POWER		//������б�ʾ��Դ��������ֱ��ͨ��GPIO����, ����PWM

#ifdef	BEEP_HAVE_POWER		//��Դ������
	//PA8
	#define GPIO_RCC_BEEP   RCC_AHB1Periph_GPIOA
	#define GPIO_PORT_BEEP	GPIOA
	#define GPIO_PIN_BEEP	GPIO_Pin_8

	#define BEEP_ENABLE()	GPIO_PORT_BEEP->BSRRL = GPIO_PIN_BEEP			//ʹ�ܷ���������
	#define BEEP_DISABLE()	GPIO_PORT_BEEP->BSRRH = GPIO_PIN_BEEP			//��ֹ����������
#else		//��Դ������ 
	//PA8 ---> TIM1_CH1
	#define BEEP_ENABLE()	bsp_SetTIMOutPWM(GPIOA, GPIO_Pin_8, TIM1, 1, 5000, 5000); //1500��ʾƵ��1.5KHz��5000��ʾ50.00%��ռ�ձ�	
	#define BEEP_DISABLE()	bsp_SetTIMOutPWM(GPIOA, GPIO_Pin_8, TIM1, 1, 1500, 0);//��ֹ����������
#endif

//������ֹͣ��ʱ��
int _beepStopTimer=0;

//��ʼ��������Ӳ��
void BEEP_InitHard(void)
{
#ifdef	BEEP_HAVE_POWER		//��Դ������
	GPIO_InitTypeDef GPIO_InitStructure;
	//��GPIOF��ʱ��
	RCC_AHB1PeriphClockCmd(GPIO_RCC_BEEP, ENABLE);
	BEEP_DISABLE();
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;		//��Ϊ�����
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//��Ϊ����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	//���������費ʹ��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO������ٶ�
	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_BEEP;
	GPIO_Init(GPIO_PORT_BEEP, &GPIO_InitStructure);
#endif	
}

void StopBeep(int v)
{
    BEEP_DISABLE();	
}

//����������
void LCDBeep(u32 timems)
{
    BEEP_DISABLE();	
    DeleteSoftTimer(_beepStopTimer);
    _beepStopTimer=CreateSoftTimer(SingTimer,timems,StopBeep);
    BEEP_ENABLE();			//��ʼ����    
    StartSoftTimer(_beepStopTimer);
}

