#include "SysTick_Timer.h"
#include "bsp_touch.h"
#include "usbh_usr.h" 
#include "usb_bsp.h"

//	全局运行时间，单位1ms
//	最长可以表示 24.85天，如果你的产品连续运行时间超过这个数，则必须考虑溢出问题
__IO int32_t _iRunTime = 0;
//毫秒延时计数器
volatile u32  _msDelayCount;
volatile u8 _10msCount = 0;
//软定时器实例
TimekeeperStruct _timekeeper;

void SysTick_Init(void)
{
	/*
		配置systic中断周期为1ms，并启动systick中断
    	SystemCoreClock 是固件中定义的系统内核时钟，对于STM32F4XX,一般为 168MHz
    	SysTick_Config() 函数的形参表示内核时钟多少个周期后触发一次Systick定时中断.
	    SystemCoreClock / 1000  表示定时频率为 1000Hz， 也就是定时周期为  1ms
	    SystemCoreClock / 500   表示定时频率为 500Hz，  也就是定时周期为  2ms
	    SystemCoreClock / 2000  表示定时频率为 2000Hz， 也就是定时周期为  500us
      SystemCoreClock / 100000 10us
      SystemCoreClock / 1000000 1us
    	对于常规的应用，我们一般取定时周期1ms。对于低速CPU或者低功耗应用，可以设置定时周期为 10ms
    */
	SysTick_Config(SystemCoreClock / 1000);
  
//    #ifdef  SysTick_HCLK_Div8   /* SysTick时钟源为HCLK的8分频 */
//    /* SystemCoreClock/1000/8      1ms 
//      * SystemCoreClock/100000/8    10us
//      * SystemCoreClock/1000000/8   1us        
//      */
//    SysTick_Config(SystemCoreClock/1000/8); 
//    /* 时钟配置必须放在SysTick_Config函数后，不然不起作用  */
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
//    #else
//    /****************************************
//     *SystemCoreClock/1000      1ms         *
//     *SystemCoreClock/100000    10us        *
//     *SystemCoreClock/1000000   1us         *
//     *****************************************/
//    SysTick_Config(SystemCoreClock / 1000);
//    /* 时钟配置必须放在SysTick_Config函数后，不然不起作用  */
//    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);/* 系统默认SysTick时钟源，可以不写 */  
//    #endif
}

//1ms调用一次的任务
void Run1msTask(void)
{
	//电阻触摸屏，扫描
	if(g_tTP.Enable == 1)
	{
		TOUCH_Scan();	
	}
	
	if(_currUSBMode==HostMode && _isUSBInset)
		USBH_Process(&USB_OTG_Core, &USB_Host);
}

//10ms调用一次的任务
void Run10msTask(void)
{
  
}

//软定时器累加，1ms一次
void TimeKeeperISR()
{
    if(_timekeeper.TimerValue>0xEFFFFFFF)//防止溢出，一般不会有这么大的
			_timekeeper.TimerValue=0;
		_timekeeper.TimerValue++;
		
		for(u8 i=0;i<SoftTimerCount;i++)
		{
			if(!_timekeeper.SoftTimers[i].IsUse) //如果没使用
				continue;
			if(!_timekeeper.SoftTimers[i].IsEnable) //如果没有开始运行
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

//功能说明: 系统嘀嗒定时器中断服务程序。启动文件中引用了该函数。
void SysTick_Handler(void)
{	
	//全局运行时间每1ms增1
	_iRunTime++;
	_msDelayCount--;
	if (_iRunTime == 0x7FFFFFFF)	//这个变量是 int32_t 类型，最大数为 0x7FFFFFFF
	{
		_iRunTime = 0;
	}
	Run1msTask();		  //每隔1ms调用一次此函数
  
	if (++_10msCount >= 10)
	{
		_10msCount = 0;
		Run10msTask();	// 每隔10ms调用一次此函数
	}  
  //软定时器累加
  TimeKeeperISR();
}

//获取计时器当前的计时数，单位ms
u32 GetTimekeeperValue(void)
{
	return _timekeeper.TimerValue;
}

//复位计时器
void ResetTimekeeper(void)
{
	_timekeeper.TimerValue=0;
}

//创建一个软定时器。如果创建成功则返回0开始的索引，否则返回0xFF
//timerType:定时器类型，perValue:定时器预装值，当计时器累计到此值，将引发回调。callFunc：回调函数
u8 CreateSoftTimer(SoftTimerType timerType,u32 perValue,OneIntParameterHandler callFunc)
{
	for(u8 timerIndex=0;timerIndex<SoftTimerCount;timerIndex++)
	{
		if(_timekeeper.SoftTimers[timerIndex].IsUse)//如果定时器正在使用
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

//删除一个定时器，释放定时器
void DeleteSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	StopSoftTimer(timerIndex);
	_timekeeper.SoftTimers[timerIndex].IsUse=false;
}

//开始一个定时器
void StartSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	if(_timekeeper.SoftTimers[timerIndex].IsUse && !_timekeeper.SoftTimers[timerIndex].IsEnable)
		_timekeeper.SoftTimers[timerIndex].IsEnable=true;
}

//复位一个定时器
void ResetSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	_timekeeper.SoftTimers[timerIndex].Count=0;
}

//停止计时器
void StopSoftTimer(u8 timerIndex)
{
	if(timerIndex<0 || timerIndex>=SoftTimerCount)
		return;
	_timekeeper.SoftTimers[timerIndex].IsEnable=false;
}

//延时ms
void Delay_ms_Tick(u32 time)
{
  _msDelayCount = time;
  while(_msDelayCount > 0)
	{
		_msDelayCount=_msDelayCount;
		;
	}
}

//延时，秒
void Delay_s_Tick(float time_s)
{
	u32 time_int = (u32) (time_s * 1000.0);
	Delay_ms_Tick(time_int);	
}

