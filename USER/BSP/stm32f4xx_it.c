/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.6.1
  * @date    21-October-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "COM.h"
#include "Protocol.h"


/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

void USART1_IRQHandler(void)
{
	u16 i=0;
	if(USART_GetITStatus(COMName1, USART_IT_IDLE) != RESET)  // �����ж�
	{		
		DMA_Cmd(RecvDMAStream1, DISABLE);       // �ر�DMA ����ֹ����	
		//��SR���DR,��USART_IT_IDLE��־  
		i = COMName1->SR; 
		i = COMName1->DR;  	
		//USART_ClearFlag(COMName1, USART_IT_IDLE);//�˺����Ĺ��ܸ����������һ����
		USART_ClearITPendingBit(COMName1, USART_IT_IDLE); //����жϱ�־λ�����ݱ�־λ��ִ����Ӧ���жϺ�����     		
		DMA_ClearFlag(RecvDMAStream1,RecvDMAFlag1);
		DMA_Cmd(RecvDMAStream1, ENABLE); 
		DisPackage();		
	} 
}

//����1��DMA�����ж�
void DMA2_Stream7_IRQHandler(void)
{    
	//if (DMA_GetITStatus(SendDMAStream1,SendDMAFlag1) != RESET)   //������䲻��
    if (DMA_GetITStatus(SendDMAStream1,DMA_IT_TCIF7) != RESET)
	{
		DMA_ClearFlag(SendDMAStream1,SendDMAFlag1);
		DMA_Cmd(SendDMAStream1, DISABLE);	
		
		if(_waitSendCount>0)
		{
			StartSendToDMA_COM1();
		}
		else
		{
			_isSendOK=true;
		}
	}
}     

void TIM6_DAC_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) == SET)
	{
		TIM_Cmd(TIM6, DISABLE);
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);	
		TIM_Cmd(TIM6, ENABLE);
	}
}

//������ʱ������ʱ������Timekeeper��ʵ�����жϺ���
//void TIM7_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM7, TIM_IT_Update) == SET)
//	{	
//		TIM_ClearFlag(TIM7, TIM_FLAG_Update);
//	}
//}


//void RTC_IRQHandler(void)
//{
//	if (RTC_GetITStatus(RTC_IT_SEC) == SET)
//	{
//		/* Clear the RTC Second interrupt */
//		RTC_ClearITPendingBit(RTC_IT_SEC);
//		/* Wait until last write operation on RTC registers has finished */
//		RTC_WaitForLastTask();    
//		/* Reset RTC Counter when Time is 23:59:59 */
//		if (RTC_GetCounter() == 0x00015180)
//		{
//			RTC_SetCounter(0x0);
//			/* Wait until last write operation on RTC registers has finished */
//			RTC_WaitForLastTask();
//		}
//	}
//}


/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

//#include "main.h"

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
    if(CoreDebug->DHCSR & 1)
    {
		//����ִ��
//		*(__IO uint8_t *) (DeviceIniBadTagAddr)=1;
//		SystemReset();
		
//		if(!_isDeviceInitOk)
//		{
//			WorkData.DeviceIniBadTag=true;
//			WriteWorkData();
//			SystemReset();
//		}
       __breakpoint(0);
    }
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
        
    }
}
                                                                            
/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//void SysTick_Handler(void)
//{
//  //TimingDelay_Decrement();
//}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
