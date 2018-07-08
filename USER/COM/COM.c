#include "stm32f4xx.h"
#include "COM.h"
#include "MemoryAlloc.h"

u8 _DMASendBuff[_comBuffLeng] ;//__at(ComSendBuffAddr);//DMA���ͻ���,��CCMRAM���ƺ����У����������ж�
u8 _DMARecvBuff[_comBuffLeng] ;//__at(ComRecvBuffAddr);//DMA���ջ���
DMA_InitTypeDef DMA_InitStructureSend_COM1;
u16 _sendStartIndex=0;//������ʼλ�õ�ַ
u16 _waitSendCount=0;//�ȴ����͵ĸ���
bool _isSendOK=true;//һ�η����Ƿ����

//�ж����ã���nvic.c���Ѷ��壬�˴���Ϊ�淶
void USART1_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);

	//�����ж����ȼ�����
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	//ʹ�ܴ���1���ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//DMA�����ж����ã�����1 TX
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream7_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure);  

	//DMA��������ж����ã�ʹ��DMA1_Channel5  
	/*NVIC_InitStructure.NVIC_IRQChannel = RecvDMAIRQ1;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure); */ 
}

void USART1_Configuration(void)
{
	//��1������GPIO��USART������ʱ�ӡ�ʹ�ܴ���1ʹ�õ�GPIOʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	//ʹ�ܴ���1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);	
	//��2������USART1��GPIO����Ϊ���츴��ģʽ��IO������
	GPIO_InitTypeDef GPIO_InitStructure;
	//����1 TX�ܽ�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//��3������USARTR1��GPIO����Ϊ��������ģʽ������1 RX�ܽ�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//���ڲ�������
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;                                    //���ò�����Ϊ115200
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     //��������λΪ8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;                          //����ֹͣλΪ1λ
	USART_InitStructure.USART_Parity = USART_Parity_No;                             //����żУ��
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //û��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 //���������
	USART_Init(COMName1, &USART_InitStructure);
}

void USART1_DMA_Configuration(void)
{         
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE); 							  // ����DMA2ʱ��    
    
	//DMA����ͨ����DMA2_ͨ��4_������7
	DMA_Cmd(SendDMAStream1, DISABLE);                                                 // ��DMAͨ��,�˾���Բ���
	DMA_DeInit(SendDMAStream1);                                                       // �ָ�ȱʡֵ
	DMA_InitStructureSend_COM1.DMA_Channel = SendDMAChannel1;       			          
	DMA_InitStructureSend_COM1.DMA_PeripheralBaseAddr = (u32)(&COMName1->DR);         // ���ô��ڷ������ݼĴ���
	DMA_InitStructureSend_COM1.DMA_Memory0BaseAddr = (u32)_DMASendBuff;          	  // ���÷��ͻ������׵�ַ
	DMA_InitStructureSend_COM1.DMA_DIR = DMA_DIR_MemoryToPeripheral;                  // ��������λĿ�꣬�ڴ滺���� -> ����Ĵ���
	DMA_InitStructureSend_COM1.DMA_BufferSize = _comBuffLeng;                	  	  // ��Ҫ���͵��ֽ�����������ʵ��������Ϊ0����Ϊ��ʵ��Ҫ���͵�ʱ�򣬻��������ô�ֵ
	DMA_InitStructureSend_COM1.DMA_PeripheralInc = DMA_PeripheralInc_Disable;         // �����ַ�������ӵ�����������������DMA�Զ�ʵ�ֵ�
	DMA_InitStructureSend_COM1.DMA_MemoryInc = DMA_MemoryInc_Enable;                  // �ڴ滺������ַ���ӵ���
	DMA_InitStructureSend_COM1.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  // �������ݿ��8λ��1���ֽ�
	DMA_InitStructureSend_COM1.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;          // �ڴ����ݿ��8λ��1���ֽ�
	DMA_InitStructureSend_COM1.DMA_Mode = DMA_Mode_Normal;							  // ѭ������ģʽ
	DMA_InitStructureSend_COM1.DMA_Priority = DMA_Priority_VeryHigh;                  // ���ȼ�����
    DMA_InitStructureSend_COM1.DMA_FIFOMode = DMA_FIFOMode_Disable;                   // ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ    
    DMA_InitStructureSend_COM1.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;        // ָ����FIFO��ֵˮƽ    
    DMA_InitStructureSend_COM1.DMA_MemoryBurst = DMA_MemoryBurst_Single;              // ָ����Burstת�������ڴ洫��     
    DMA_InitStructureSend_COM1.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;      // ָ����Burstת��������Χת��        
	DMA_Init(SendDMAStream1, &DMA_InitStructureSend_COM1);               		      // д������
    //DMA_ClearFlag(SendDMAFlag1);                                 				      // ���DMA���б�־,�˾���Բ���
	DMA_ITConfig(SendDMAStream1, DMA_IT_TC, ENABLE);         					      // ��������DMAͨ���ж�
    
    //DMA����ͨ����DMA2_ͨ��4_������2 
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_Channel = RecvDMAChannel1;  
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&COMName1->DR);		// ���ô��ڽ������ݼĴ���
	DMA_InitStructure.DMA_Memory0BaseAddr =  (u32)_DMARecvBuff;        		// ���ý��ջ������׵�ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;                 // ��������Ϊ����Դ������Ĵ��� -> �ڴ滺����
	DMA_InitStructure.DMA_BufferSize = _comBuffLeng;                  		// ��Ҫ�����ܽ��յ����ֽ���
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // �����ַ�������ӵ�����������������DMA�Զ�ʵ�ֵ�
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // �ڴ滺������ַ���ӵ���
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // �������ݿ��8λ��1���ֽ�
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;         // �ڴ����ݿ��8λ��1���ֽ�
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // ѭ������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // ���ȼ�����  
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;                  // ָ�����FIFOģʽ��ֱ��ģʽ������ָ������ �� ��ʹ��FIFOģʽ
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;       // ָ����FIFO��ֵˮƽ 
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;             // ָ����Burstת�������ڴ洫��   
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;     // ָ����Burstת��������Χת��  
	DMA_Init(RecvDMAStream1, &DMA_InitStructure);               		    // д������
    //DMA_ClearFlag(RecvDMAFlag1);                                 		    // ���DMA���б�־
	DMA_Cmd(RecvDMAStream1, ENABLE);                            		    // ��������DMAͨ�����ȴ���������		
}

void InitUSART_COM1(void)
{
	USART1_Configuration();
	USART1_NVIC_Configuration();
	USART1_DMA_Configuration();

	//һ��ģʽ��DMA���ͣ������жϽ���
	//	USART_DMACmd(COMName1,USART_DMAReq_Tx,ENABLE); 		//��������DMA����
	//	USART_ITConfig(COMName1, USART_IT_RXNE, ENABLE); 	//ʹ���жϷ�ʽ���ա�ʹ�ܴ��ڽ����ж�
	//	USART_Cmd(COMName1, ENABLE);						//��������

	//����ģʽ��DMA���ͣ�DMA����
	//DMA_ITConfig(RecvDMAStream1, DMA_IT_TC, ENABLE);      //DMA��������ж�
	USART_ITConfig(COMName1, USART_IT_IDLE, ENABLE);        //��������1����IDEL �ж�
	USART_DMACmd(COMName1, USART_DMAReq_Tx, ENABLE);        //��������DMA����
	USART_DMACmd(COMName1, USART_DMAReq_Rx, ENABLE);        //��������DMA����
	USART_Cmd(COMName1, ENABLE);											//��������
}

void StartSendToDMA_COM1(void)
{
	_isSendOK=false;
	DMA_InitStructureSend_COM1.DMA_Memory0BaseAddr = (u32)&_DMASendBuff[_sendStartIndex];  // ���÷��ͻ������׵�ַ
	DMA_Init(SendDMAStream1, &DMA_InitStructureSend_COM1);             	// д������
	DMA_SetCurrDataCounter(SendDMAStream1,_waitSendCount); 						//����Ҫ���͵��ֽ���	
	_sendStartIndex=_sendStartIndex+_waitSendCount;
	_waitSendCount=0;		
	DMA_Cmd(SendDMAStream1, ENABLE); //��ʼDMA����
}      

void SendBytes_COM1(u8* datas, u16 count)
{
	if((_sendStartIndex+_waitSendCount+count)> _comBuffLeng-1)
	{	
		while(!_isSendOK)//�ȴ�������һ���з������
		{   
		}
		_sendStartIndex=0;
	}
	u16 currAddrBase=_sendStartIndex+_waitSendCount;//��ǰҪ�����Ļ�ַ
	for(u16 i=0;i<count;i++)
	{
		_DMASendBuff[currAddrBase+i]=datas[i];
	}	
	_waitSendCount=_waitSendCount+count;
	if(_isSendOK)
	{
		StartSendToDMA_COM1();
	}
}
