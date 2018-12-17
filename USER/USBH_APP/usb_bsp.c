#include "usb_bsp.h"
#include "usb_hcd_int.h"
#include "usbh_core.h"
#include "usbh_usr.h"
#include "usbd_core.h"

USBModeEnum _currUSBMode=HostMode;//DirverMode;//
bool _isUSBInset=false;//U盘是否已经插入

#define TIM_MSEC_DELAY                     0x01
#define TIM_USEC_DELAY                     0x02
__IO uint32_t BSP_delay = 0;

static void BSP_SetTime(uint8_t Unit);
static void BSP_Delay(uint32_t nTime,uint8_t Unit);
static void USB_OTG_BSP_TimeInit ( void );

/* Private function prototypes -----------------------------------------------*/
extern uint32_t USBD_OTG_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);

void USB_OTG_BSP_Init(USB_OTG_CORE_HANDLE *pdev)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA , ENABLE);  
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11 | GPIO_Pin_12;   
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOA, &GPIO_InitStructure);  
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource11,GPIO_AF_OTG1_FS) ; 
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource12,GPIO_AF_OTG1_FS) ;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_OTG_FS, ENABLE) ;  
  USB_OTG_BSP_TimeInit();   
	
//  GPIO_InitTypeDef GPIO_InitStructure;
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//  GPIO_Init(GPIOB, &GPIO_InitStructure); 
//  GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_OTG2_FS) ;
//  GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_OTG2_FS) ;
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_OTG_HS, ENABLE) ;
//  /* Intialize Timer for delay function */
//  USB_OTG_BSP_TimeInit();    
}

void USB_OTG_BSP_EnableInterrupt(USB_OTG_CORE_HANDLE *pdev)
{
  NVIC_InitTypeDef NVIC_InitStructure;   
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
  NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);  
}

void USB_OTG_BSP_DriveVBUS(USB_OTG_CORE_HANDLE *pdev, uint8_t state)
{
	
}

void  USB_OTG_BSP_ConfigVBUS(USB_OTG_CORE_HANDLE *pdev)
{
	
}

void SystemReset(void)
{    
	__disable_fault_irq(); 
	NVIC_SystemReset();
}

//USBHost最后的状态
u8 _usbOTGState=0;
void OTG_FS_IRQHandler(void)
{
	if(_currUSBMode==HostMode)
	{
	   USBH_OTG_ISR_Handler(&USB_OTG_Core);
	   u8 currState= USB_OTG_Core.host.ConnSts;
	   if(currState==_usbOTGState)
		   return;
	   _usbOTGState=currState;
	   if(currState==1)  //检测到插入了U盘
	   {
			 _isUSBInset=true;
		   //SetUSBHostTaskEnable(true);
	   }
	   else  //拨出了U盘
	   {
			 _isUSBInset=false;
			 SystemReset();
			 
		   //SetUSBHostTaskEnable(false);//不能在此关闭，否则不能多次连
//		   if(_currPermission<AdminiPer)
//			   SystemReset();
//		   ShowMainForm(0);       
	   }
	}
	else if(_currUSBMode==DirverMode)
	{
		USBD_OTG_ISR_Handler (&USB_OTG_dev);
	}
}

//void USB_OTG_BSP_uDelay (const uint32_t usec)
//{  
//    Delay_ms_OS(usec/1000);
//}   

//void USB_OTG_BSP_mDelay (const uint32_t msec)
//{ 
//    Delay_ms_OS(msec);  
//}  

/**
  * @brief  USB_OTG_BSP_TimeInit
  *         Initializes delay unit using Timer2
  * @param  None
  * @retval None
  */
static void USB_OTG_BSP_TimeInit ( void )
{  
  NVIC_InitTypeDef NVIC_InitStructure;  
  /* Set the Vector Table base address at 0x08000000 */
  //NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x00);  
  /* Configure the Priority Group to 2 bits */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);  
  /* Enable the TIM7 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //???????,????????????????
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
  NVIC_Init(&NVIC_InitStructure);  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);  
}

void USB_OTG_BSP_uDelay (const uint32_t usec)
{  
    //Delay_us(usec);   //???????
    //Delay_ms_OS(usec/1000);
    BSP_Delay(usec,TIM_USEC_DELAY); 
}   

void USB_OTG_BSP_mDelay (const uint32_t msec)
{ 
    //Delay_ms(msec); //???????
    //Delay_ms_OS(msec);
    BSP_Delay(msec,TIM_MSEC_DELAY);   
}  

void USB_OTG_BSP_TimerIRQ (void)
{     
  if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
    if (BSP_delay > 0x00)
    { 
      BSP_delay--;
    }
    else
    {
      TIM_Cmd(TIM7,DISABLE);
    }
  }
} 

static void BSP_Delay(uint32_t nTime, uint8_t unit)
{  
  BSP_delay = nTime;
  BSP_SetTime(unit);  
  while(BSP_delay != 0);
  TIM_Cmd(TIM7,DISABLE);
}

static void BSP_SetTime(uint8_t unit)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  
  TIM_Cmd(TIM7,DISABLE);
  TIM_ITConfig(TIM7, TIM_IT_Update, DISABLE); 
  
  
  if(unit == TIM_USEC_DELAY)
  {  
    TIM_TimeBaseStructure.TIM_Period = 11;
  }
  else if(unit == TIM_MSEC_DELAY)
  {
    TIM_TimeBaseStructure.TIM_Period = 11999;
  }
  TIM_TimeBaseStructure.TIM_Prescaler = 5;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  
  TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);
  TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
  
  TIM_ARRPreloadConfig(TIM7, ENABLE);
  
  /* TIM IT enable */
  TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
  
  /* TIM7 enable counter */ 
  TIM_Cmd(TIM7, ENABLE);  
} 

void TIM7_IRQHandler(void)
{
  USB_OTG_BSP_TimerIRQ();
}
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
