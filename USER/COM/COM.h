#ifndef _COM_H
#define _COM_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include "stm32f4xx.h"
#include "stdbool.h"

#define _comBuffLeng 2048 	//���ͻ�������ֽ���,64�ֽڶ����ԣ�ֻҪ���������ĳ��ȼ��ɡ��������Ч�ʻ��Щ
	 
extern u8 _DMASendBuff[_comBuffLeng];//DMA���ͻ���
extern u8 _DMARecvBuff[_comBuffLeng];//DMA���ջ���
extern u16 _sendStartIndex;//������ʼλ�õ�ַ
extern u16 _waitSendCount;//�ȴ����͵ĸ���
extern bool _isSendOK;	 //һ�η����Ƿ����
	 
#define COMName1				 USART1
#define SendDMAChannel1          DMA_Channel_4
#define SendDMAStream1           DMA2_Stream7
#define SendDMAFlag1             DMA_FLAG_TCIF7      
#define SendDMAIRQ1              DMA2_Stream7_IRQn 

#define RecvDMAChannel1          DMA_Channel_4
#define RecvDMAStream1           DMA2_Stream2
#define RecvDMAFlag1     	        DMA_FLAG_TCIF2
#define RecvDMAIRQ1      	        DMA2_Stream2_IRQn

//����DMA����
void StartSendToDMA_COM1(void);
//��ʼ����1
void InitUSART_COM1(void);
//��ָ���Ĵ��ڷ���һ���ֽ�����
void SendBytes_COM1(u8* data,u16 count);

#ifdef __cplusplus
}
#endif

#endif
