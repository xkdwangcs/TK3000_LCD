#include "SysTick_Timer.h"
#include "bsp_touch.h"
#include "usbh_usr.h" 
#include "usb_bsp.h"

//	ȫ������ʱ�䣬��λ1ms
//	����Ա�ʾ 24.85�죬�����Ĳ�Ʒ��������ʱ�䳬�������������뿼���������
__IO int32_t _iRunTime = 0;
//������ʱ������
volatile u32  _msDelayCount;
volatile u8 _10msCount = 0;
//��ʱ��ʵ��
TimekeeperStruct _timekeeper;

void SysTick_Init(void)
{
	/*
		����systic�ж�����Ϊ1ms��������systick�ж�
    	SystemCoreClock �ǹ̼��ж����ϵͳ�ں�ʱ�ӣ�����STM32F4XX,һ��Ϊ 168MHz
    	SysTick_Config() �������βα�ʾ�ں�ʱ�Ӷ��ٸ����ں󴥷�һ��Systick��ʱ�ж�.
	    SystemCoreClock / 1000  ��ʾ��ʱƵ��Ϊ 1000Hz�� Ҳ���Ƕ�ʱ����Ϊ  1ms
	    SystemCoreClock / 500   ��ʾ��ʱƵ��Ϊ 500Hz��  Ҳ���Ƕ�ʱ����Ϊ  2ms
	    SystemCoreClock / 2000  ��ʾ��ʱƵ��Ϊ 2000Hz�� Ҳ���Ƕ�ʱ����Ϊ  500us
      SystemCoreClock / 100000 10us
      SystemCoreClock / 1000000 1us
    	���ڳ����Ӧ�ã�����һ��ȡ��ʱ����1ms�����ڵ���CPU���ߵ͹���Ӧ�ã��������ö�ʱ����Ϊ 10ms
    */
	SysTick_Config(SystemCoreClock / 1000);
  
//    #ifdef  SysTick_HCLK_Div8   /* SysTickʱ��ԴΪHCLK��8��Ƶ */
//    /* SystemCoreClock/1000/8      1ms 
//      * SystemCoreClock/100000/8    10us
//      * SystemCoreClock/1000000/8   1us        
//      */
//    SysTick_Config(SystemCoreClock/1000/8); 
//    /* ʱ�����ñ������SysTick_Config�����󣬲�Ȼ��������  */
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
//    #else
//    /****************************************
//     *SystemCoreClock/1000      1ms         *
//     *SystemCoreClock/100000    10us        *
//     *SystemCoreClock/1000000   1us         *
//     *****************************************/
//    SysTick_Config(SystemCoreClock / 1000);
//    /* ʱ�����ñ������SysTick_Config�����󣬲�Ȼ��������  */
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);/* ϵͳĬ��SysTickʱ��Դ�����Բ�д */  
//    #endif
}

//1ms����һ�ε�����
void Run1msTask(void)
{
	//���败������ɨ��
	if(g_tTP.Enable == 1)
	{
		TOUCH_Scan();	
	}
	
	if(_currUSBMode==HostMode && _isUSBInset)
		USBH_Process(&USB_OTG_Core, &USB_Host);
}

//10ms����һ�ε�����
void Run10msTask(void)
{
  
}

//��ʱ���ۼӣ�1msһ��
void TimeKeeperISR()
{
    if(_timekeeper.TimerValue>0xEFFFFFFF)//��ֹ�����һ�㲻������ô���
			_timekeeper.TimerValue=0;
		_timekeeper.TimerValue++;
		
		for(u8 i=0;i<SoftTimerCount;i++)
		{
			if(!_timekeeper.SoftTimers[i].IsUse) //���ûʹ��
				continue;
			if(!_timekeeper.SoftTimers[i].IsEnable) //���û�п�ʼ����
				continue;
			_timekeeper.SoftTimers[i].Count++;
			if(_timekeeper.SoftTimers[i].Count==_timekeeper.SoftTimers[i].PreValue)
			{
				if(_timekeeper.SoftTimers[i].TimerType==SingTimer)
				{
					_timekeeper.SoftTimers[i].IsEnable=false;
				}
				_timekeeper.SoftTimers[i].Count=0;
				if(_timekeeper.SoftTimers[i].CallFunc!= NULL)
				{
					_timekeeper.SoftTimers[i].CallFunc(i);
				}
			}
		}
 }

//����˵��: ϵͳ��શ�ʱ���жϷ�����������ļ��������˸ú�����
void SysTick_Handler(void)
{	
	//ȫ������ʱ��ÿ1ms��1
	_iRunTime++;
	_msDelayCount--;
	if (_iRunTime == 0x7FFFFFFF)	//��������� int32_t ���ͣ������Ϊ 0x7FFFFFFF
	{
		_iRunTime = 0;
	}
	Run1msTask();		  //ÿ��1ms����һ�δ˺���
  
	if (++_10msCount >= 10)
	{
		_10msCount = 0;
		Run10msTask();	// ÿ��10ms����һ�δ˺���
	}  
  //��ʱ���ۼ�
  TimeKeeperISR();
}

//��ȡ��ʱ����ǰ�ļ�ʱ������λms
u32 GetTimekeeperValue(void)
{
	return _timekeeper.TimerValue;
}

//��λ��ʱ��
void ResetTimekeeper(void)
{
	_timekeeper.TimerValue=0;
}

//����һ����ʱ������������ɹ��򷵻�0��ʼ�����������򷵻�0xFF
//timerType:��ʱ�����ͣ�perValue:��ʱ��Ԥװֵ������ʱ���ۼƵ���ֵ���������ص���callFunc���ص�����
u8 CreateSoftTimer(SoftTimerType timerType,u32 perValue,OneIntParameterHandler callFunc)
{
	for(u8 timerIndex=0;timerIndex<SoftTimerCount;timerIndex++)
	{
		if(_timekeeper.SoftTimers[timerIndex].IsUse)//�����ʱ������ʹ��
			continue;
		_timekeeper.SoftTimers[timerIndex].TimerType=timerType;
		_timekeeper.SoftTimers[timerIndex].Count=0;
		_timekeeper.SoftTimers[timerIndex].PreValue=perValue;
		_timekeeper.SoftTimers[timerIndex].IsUse=true;
		_timekeeper.SoftTimers[timerIndex].IsEnable=false;
		_timekeeper.SoftTimers[timerIndex].CallFunc=callFunc;
		return timerIndex;
	}
	return 0xFF;
}

//ɾ��һ����ʱ�����ͷŶ�ʱ��
void DeleteSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	StopSoftTimer(timerIndex);
	_timekeeper.SoftTimers[timerIndex].IsUse=false;
}

//��ʼһ����ʱ��
void StartSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	if(_timekeeper.SoftTimers[timerIndex].IsUse && !_timekeeper.SoftTimers[timerIndex].IsEnable)
		_timekeeper.SoftTimers[timerIndex].IsEnable=true;
}

//��λһ����ʱ��
void ResetSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	_timekeeper.SoftTimers[timerIndex].Count=0;
}

//ֹͣ��ʱ��
void StopSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	_timekeeper.SoftTimers[timerIndex].IsEnable=false;
}

//��ʱms
void Delay_ms_Tick(u32 time)
{
  _msDelayCount = time;
  while(_msDelayCount > 0)
	{
		_msDelayCount=_msDelayCount;
		;
	}
}

//��ʱ����
void Delay_s_Tick(float time_s)
{
	u32 time_int = (u32) (time_s * 1000.0);
	Delay_ms_Tick(time_int);	
}

