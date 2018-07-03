//******************************************************************************
//*File name:           bsp_SST25VF016.c                                       *
//*Descriptions:        SPI�µ�SST25VF016B����������                           *
//*Created date:        2011-03-29                                             *
//*Modified date:       2011-03-29                                             *
//*Version:             1.0                                                    *
//*note:                SST25VFXX д����������ʹ��д״̬��ͬʱ��д������λ����Ҫ
//*                     �ڲ���״̬����������4K,32K,64K��ʽ����������д�����轫Ҫ
//*                     �õ�ַ���ڵ�4K���ݶ�������ŵ�һ�����飬�޸������Ӧ����
//*                     �ݣ�Ȼ������洢���ڵĸ�4K���ݣ�����������д��洢��
//******************************************************************************

#include "SST25VF032B.h"
#include "PublicFunction.h"

#ifdef SST25VF032B	

void SST25V_EnableWriteStatusRegister(void);
void SST25V_WriteStatusRegister(u8 Byte);
void SST25V_WaitForWriteEnd(void);
void SST25V_DBSY(void);
void SST25V_ByteWrite(unsigned char *Byte, u32 WriteAddr);
void SST25V_BufferWrite(char* pBuffer, u32 ReadAddr, u16 NumByteToRead);
void SSTF016B_WriteOneByte(unsigned long W_address, unsigned char byte);


// SST25 ��ʼ��
u8 SST25V_SPIFlashInit(void)
{
	//SPI��ض˿�����
	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure; 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC, ENABLE); //ʹ��GPIOA\GPIOCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); //ʹ��SPI1ʱ��     
	// SCLK  MISO  MOSI
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);   
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_SPI1); //����Ϊ SPI1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_SPI1); //����Ϊ SPI1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_SPI1); //����Ϊ SPI1

	//WPд������д��2017.03.17
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_4);
	
    //CS
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;       
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed =GPIO_Speed_25MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);  
    SPI_FLASH_CS_HIGH();
    
    //SPI��������
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		                //����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		            //����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;		                    //����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	                    //����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		                    //NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;  //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ4�Ͽ�(Ҫע��᲻��д����),256��Ƶд��̫����
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	                //ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;	                        //CRCֵ����Ķ���ʽ
	SPI_Init(SPI1, &SPI_InitStructure);                                 //����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ��� 
	SPI_Cmd(SPI1, ENABLE);                                              //ʹ��SPI����  
	
	SST25_CS_HIGH();
	SST25V_EnableWriteStatusRegister();
	SST25V_WriteStatusRegister(0x02);
	SST25V_DBSY();
    return 0;
}


/******************************************************************************
** ��������: SPI_FLASH_SendByte(u8 byte)
** ��������: ����1���ֽ����ݣ����ؽ��յ�������
** ��ڲ���: byte
** ���ڲ���: byte
** ��    ע: ��
*******************************************************************************/
static u8 SPI_FLASH_SendByte(u8 byte)
{
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
		;
	SPI_I2S_SendData(SPI1, byte);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET)
		;
	return SPI_I2S_ReceiveData(SPI1);
}
/******************************************************************************
** ��������: SPI_FLASH_ReadByte(void)
** ��������: ����SPI����
** ��ڲ���: ��
** ���ڲ���: byte ���ؽ��յ�����
** ��    ע: ��
*******************************************************************************/
static u8 SPI_FLASH_ReadByte(void)
{
	return (SPI_FLASH_SendByte(SST25_Dummy_Byte));
}
/************************************************************************
** ��������: SST25V_ReadStatusRegister(void)
** ��������: SST25VF016B ��ȡ״̬�Ĵ���
** ��ڲ���: ��
** ���ڲ���: ״̬�Ĵ�������
** ע	 ��:
************************************************************************/
u8 SST25V_ReadStatusRegister(void)
{
	u8 StatusRegister = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ReadStatusReg);
	StatusRegister = SPI_FLASH_ReadByte();
	SST25_CS_HIGH();
	return StatusRegister;
}
/************************************************************************
** ��������: SST25V_WriteEnable(void)
** ��������: SST25VF016B дʹ��
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_WriteEnable(void)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_WriteEnable);
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_WriteDisable(void)
** ��������: SST25VF016B ��ֹдʹ��
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_WriteDisable(void)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_WriteDisable);
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_EnableWriteStatusRegister(void)
** ��������: SST25VF016B ʹ��д״̬�Ĵ���
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_EnableWriteStatusRegister(void)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_EnableWriteStatusReg);
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_WriteStatusRegister(u8 Byte)
** ��������: SST25VF016B д״̬�Ĵ���ָ��
** ��ڲ���: u8 Byte :ָ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_WriteStatusRegister(u8 Byte)
{
	SST25V_EnableWriteStatusRegister();
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_WriteStatusReg);
	SPI_FLASH_SendByte(Byte);
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_WaitForWriteEnd(void)
** ��������: SST25VF016B �ȴ�����д��
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_WaitForWriteEnd(void)
{
	u8 FLASH_Status = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ReadStatusReg);
	do
	{
		FLASH_Status = SPI_FLASH_SendByte(SST25_Dummy_Byte);

	}
	while ((FLASH_Status & SST25_WriteStatusReg) == SET);

	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_ByteRead
** ��������: SST25VF016B�Ķ�ȡ1���ֽ�����(����)
** ��ڲ���:
**			 u32 ReadAddr��Ŀ���ַ,
��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
** ���ڲ���: ���ض�ȡ������
** ��    ע:
************************************************************************/
u8 SST25V_ByteRead(u32 ReadAddr)
{
	u8 Temp = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ReadData);
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((ReadAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	Temp = SPI_FLASH_ReadByte();
	SST25_CS_HIGH();
	return Temp;
}
/************************************************************************
** ��������: SST25V_BufferRead
** ��������: SST25VF016B�Ķ�ȡN���ֽ�����(����)
** ��ڲ���:
**			 u32 ReadAddr��Ŀ���ַ,
��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
**           pBuffer:  ������ݵ�����
**           NumByteToRead : ���ݸ���
** ���ڲ���: ���ض�ȡ������
** ��    ע:
************************************************************************/
void SST25V_BufferRead(char* pBuffer, u32 ReadAddr, u16 NumByteToRead)
{
	SST25_CS_LOW();
	//	char * temp_abc = (char *)pBuffer;
	SPI_FLASH_SendByte(SST25_ReadData);
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((ReadAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	while (NumByteToRead--)
	{
		*pBuffer = SPI_FLASH_ReadByte();
		pBuffer++;
	}
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_HighSpeedRead
** ��������: SST25VF016B�Ķ����������ٶ�ȡ1�ֽ�
** ��ڲ���:
**			 u32 ReadAddr��Ŀ���ַ,
**			 u8* pBuffer:���ջ����ָ��
** ���ڲ���:
** ��    ע:
************************************************************************/
u8 SST25V_HighSpeedRead(u32 ReadAddr)
{
	u32 Temp = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_FastReadData);
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((ReadAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	SPI_FLASH_SendByte(SST25_Dummy_Byte);
	Temp = SPI_FLASH_ReadByte();
	SST25_CS_HIGH();
	return Temp;
}
/************************************************************************
** ��������: SST25V_HighSpeedBufferRead
** ��������: SST25VF016B�Ķ����������ٶ�ȡN�ֽ�
** ��ڲ���:
**			 u32 ReadAddr��Ŀ���ַ,
��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
**      	 u16 NumByteToRead:	Ҫ��ȡ�������ֽ���
**			 u8* pBuffer:���ջ����ָ��
** ���ڲ���:
** ��    ע:
************************************************************************/
void SST25V_HighSpeedBufferRead(u8* pBuffer, u32 ReadAddr, u16 NumByteToRead)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_FastReadData);
	SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((ReadAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(ReadAddr & 0xFF);
	SPI_FLASH_SendByte(SST25_Dummy_Byte);

	while (NumByteToRead--)
	{
		*pBuffer = SPI_FLASH_ReadByte();
		pBuffer++;
	}
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_Wait_Busy_AAI(void)
** ��������: SST25VF016B ��ѯAAIæ��
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_Wait_Busy_AAI(void)
{
	while (SST25V_ReadStatusRegister() == 0x43) /* ???? */
		SST25V_ReadStatusRegister();
}
/************************************************************************
** ��������: SST25V_ByteWrite
** ��������: SST25VF016B��д��������д1�����ݵ�ָ����ַ
** ��ڲ���:
**			 u32 WriteAddr��Ŀ���ַ,��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
**			 u8 Byte:��������
** ���ڲ���:
** ע	 ��:
************************************************************************/
void SST25V_ByteWrite(unsigned char *Byte, u32 WriteAddr)
{
	SST25V_WriteEnable();
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ByteProgram);
	SPI_FLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((WriteAddr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(WriteAddr & 0xFF);

	SPI_FLASH_SendByte(*Byte);
	SST25_CS_HIGH();
	SST25V_WaitForWriteEnd();
}
/************************************************************************
** ��������: SST25V_ByteWrite
** ��������: SST25VF016B��д��������д2�����ݵ�ָ����ַ (AAIд) ����ַ��д
**           �� ��һ����д��ַ���Ժ����2��2�����ݵĳ���д
** ��ڲ���:
**			 u32 WriteAddr��Ŀ���ַ,��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
**			 u8 Byte1, u8 Byte2:���͵�2������
** ���ڲ���:
** ע	 ��:
************************************************************************/
void AutoAddressIncrement_WordProgramA(u8 Byte1, u8 Byte2, u32 Addr)
{
	SST25V_WriteEnable();
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_AAI_WordProgram);
	SPI_FLASH_SendByte((Addr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((Addr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(Addr & 0xFF);

	SPI_FLASH_SendByte(Byte1);
	SPI_FLASH_SendByte(Byte2);

	SST25_CS_HIGH();
	SST25V_Wait_Busy_AAI();
	SST25V_WaitForWriteEnd();
}
/************************************************************************
** ��������: SST25V_ByteWrite
** ��������: SST25VF016B��д��������д2�����ݵ�ָ����ַ (AAIд) ������ַ��д
**           �� ��һ����д��ַ���Ժ����2��2�����ݵĳ���д
** ��ڲ���:
**			 u32 WriteAddr��Ŀ���ַ,��Χ 0x0 - SST25_MAX_ADDR��SST25_MAX_ADDR = 0x1FFFFF��
**			 u8 Byte1, u8 Byte2:���͵�2������
**           u8 state :ģʽѡ��AAI�������ݵ����2������֮����Ҫ����һ��WRDI
** ���ڲ���:
** ע	 ��:
************************************************************************/
void AutoAddressIncrement_WordProgramB(u8 state, u8 Byte1, u8 Byte2)
{
	SST25V_WriteEnable();
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_AAI_WordProgram);

	SPI_FLASH_SendByte(Byte1);
	SPI_FLASH_SendByte(Byte2);

	SST25_CS_HIGH();
	SST25V_Wait_Busy_AAI();

	if (state == 1)
	{
		SST25V_WriteDisable();
	}
	SST25V_Wait_Busy_AAI();
}

/************************************************************************
** ��������: SST25V_ReadJedecID(void)
** ��������: SST25VF016B ��ȡ�����̺�������Ϣ
** ��ڲ���: ��
** ���ڲ���: ��Ϣ����
** ע	 ��:
************************************************************************/
u32 SST25V_ReadJedecID(void)
{
	u32 JEDECID = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_JedecDeviceID);
	Temp0 = SPI_FLASH_ReadByte();
	Temp1 = SPI_FLASH_ReadByte();
	Temp2 = SPI_FLASH_ReadByte();
	SST25_CS_HIGH();
	JEDECID = (Temp0 << 16) | (Temp1 << 8) | Temp2;
	return JEDECID;
}
/************************************************************************
** ��������: SST25V_ReadManuID_DeviceID(u32 ReadManu_DeviceID_Addr)
** ��������: SST25VF016B ��ȡ������Ϣ
** ��ڲ���: u32 ReadManu_DeviceID_Addr ������ַ
** ���ڲ���: u16  ����ID
** ע	 ��:
************************************************************************/
u16 SST25V_ReadManuID_DeviceID(u32 ReadManu_DeviceID_Addr)
{
	u16 ManuID_DeviceID = 0;
	u8 ManufacturerID = 0, DeviceID = 0;
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ManufactDeviceID);

	SPI_FLASH_SendByte((ReadManu_DeviceID_Addr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((ReadManu_DeviceID_Addr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(ReadManu_DeviceID_Addr & 0xFF);

	if (ReadManu_DeviceID_Addr == 1)
	{
		DeviceID = SPI_FLASH_ReadByte();
		ManufacturerID = SPI_FLASH_ReadByte();
	}
	else
	{
		ManufacturerID = SPI_FLASH_ReadByte();
		DeviceID = SPI_FLASH_ReadByte();
	}

	ManuID_DeviceID = ((ManufacturerID << 8) | DeviceID);
	SST25_CS_HIGH();

	return ManuID_DeviceID;
}
/************************************************************************
** ��������: SST25V_EBSY()
** ��������: SST25VF016B ����EBSY
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_EBSY(void)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_EBSY);
	SST25_CS_HIGH();
}
/************************************************************************
** ��������: SST25V_EBSY()
** ��������: SST25VF016B ����DBSY
** ��ڲ���: ��
** ���ڲ���: ��
** ע	 ��:
************************************************************************/
void SST25V_DBSY(void)
{
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_DBSY);
	SST25_CS_HIGH();
}



//SST25VF016B �����洢����ȫ������
void SST25V_ChipErase(void)
{
	SST25V_WriteEnable();
	SST25_CS_LOW();
	SPI_FLASH_SendByte(SST25_ChipErase);
	SST25_CS_HIGH();
	SST25V_WaitForWriteEnd();
}

//SST25VF016B �����õ�ַ���ڵ�4K�洢��������
void SST25V_SectorErase_4KByte(u32 sectorIndex)
{
	SST25V_WriteEnable();
	SST25_CS_LOW();
    u32 Addr=sectorIndex*FLASH_SECTOR_SIZE;
	SPI_FLASH_SendByte(SST25_4KByte_BlockERASE);
	SPI_FLASH_SendByte((Addr & 0xFF0000) >> 16);
	SPI_FLASH_SendByte((Addr & 0xFF00) >> 8);
	SPI_FLASH_SendByte(Addr & 0xFF);

	SST25_CS_HIGH();
	SST25V_WaitForWriteEnd();
}

//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
//(CoordFileAttri file,u8* data,u32 startIndex,u32 count)
void SST25V_ReadBytes(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count)
{
	if(count<=0)
		return;
	u32 readAddr=sectorBaseAddr*FLASH_SECTOR_SIZE+startIndex;
	memset(data,0,count);
	SST25V_HighSpeedBufferRead(data, readAddr, count);
	//SST25V_BufferRead((char*)data,readAddr,count);
}

//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����,��Ҫ����FATFS
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void SST25V_ReadOneSector(u16 sectionIndex,u8* readDatas)
{
    SST25V_ReadBytes(sectionIndex,readDatas,0, FLASH_SECTOR_SIZE);
}

//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void SST25V_ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount)
{
    SST25V_HighSpeedBufferRead(&readData[buffAddr], flashAddr, dataCount);
}

//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void SST25V_WriteOneSector(u16 sectionIndex,u8* writeDatas)
{
     //WriteBytes(sectionIndex,writeDatas, FLASH_SECTOR_SIZE);
	SST25V_SectorErase_4KByte(sectionIndex);     //����ָ������
    u32 writeAddr=sectionIndex*FLASH_SECTOR_SIZE;
    for (u32 j = 0; j < FLASH_SECTOR_SIZE; j++)
	{
		SST25V_ByteWrite(&writeDatas[j], writeAddr++);
	}
}

//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void SST25V_WriteBytes(u16 sectionIndex,u8* writeDatas,u32 dataCount)
{
	if(dataCount<=0)
		return;   
	u16 sectorNum=dataCount/FLASH_SECTOR_SIZE;
	for(u8 i=0;i<sectorNum;i++)
	{
		SST25V_WriteOneSector(sectionIndex+i,writeDatas);
		writeDatas+=FLASH_SECTOR_SIZE;
	}
	sectionIndex+=sectorNum;
  	sectorNum=dataCount%FLASH_SECTOR_SIZE;
	if(sectorNum>0)
	{
		SST25V_ReadOneSector(sectionIndex,_flashBuff);
		CopyBytes(_flashBuff,0,writeDatas,sectorNum);
		SST25V_WriteOneSector(sectionIndex,_flashBuff);
	}		
}

//Flash����
bool SST25V_FlashTest(void)
{
	memset(_testFlashBuff,0,FLASH_SECTOR_SIZE);
	u8 value=0;
	for(u32 i=0;i<FLASH_SECTOR_SIZE;i++)
	{
		_testFlashBuff[i]=value;
		if(value==0xFF)
		{
			value=0;
			continue;
		}
		value++;
	}
	SST25V_WriteOneSector(SPIFlashTestSection,_testFlashBuff);
	memset(_testFlashBuff,0,FLASH_SECTOR_SIZE);
	SST25V_ReadOneSector(SPIFlashTestSection,_testFlashBuff);
	value=0;
	for(u32 i=0;i<FLASH_SECTOR_SIZE;i++)
	{		
		if(value!=_testFlashBuff[i])
			return false;
		if(value==0xFF)
		{
			value=0;
			continue;
		}
		value++;
	}
	return true;
}

#endif