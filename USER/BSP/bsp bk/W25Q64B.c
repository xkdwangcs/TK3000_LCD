#include "W25Q64B.h"
#include <string.h>
#include "SPIFlashBase.h"

#ifdef W25Q64B	

void sf_ReadInfo(void);
static uint8_t sf_SendByte(uint8_t _ucValue);
static void sf_WriteEnable(void);
static void sf_WriteStatus(uint8_t _ucValue);
static void sf_WaitForWriteEnd(void);
static uint8_t sf_NeedErase(uint8_t * _ucpOldBuf, uint8_t *_ucpNewBuf, uint16_t _uiLen);
static uint8_t sf_CmpData(uint32_t _uiSrcAddr, uint8_t *_ucpTar, uint32_t _uiSize);
static uint8_t sf_AutoWritePage(uint8_t *_ucpSrc, uint32_t _uiWrAddr, uint16_t _usWrLen);
static void bsp_CfgSPIForSFlash(void);

u32 _totalSize = FLASH_TOTAL_SIZE;

#define SPIPort					SPI1
//ƬѡGPIO�˿�
#define SF_CS_GPIO			GPIOF
#define SF_CS_PIN				GPIO_Pin_8
//Ƭѡ�����õ�ѡ��
#define SF_CS_LOW()     SF_CS_GPIO->BSRRH = SF_CS_PIN
//Ƭѡ�����ø߲�ѡ��
#define SF_CS_HIGH()    SF_CS_GPIO->BSRRL = SF_CS_PIN

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitSpiFlash
*	����˵��: ��ʼ������FlashӲ���ӿڣ�����STM32��SPIʱ�ӡ�GPIO)
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_InitSFlash(void)
{
    /*
    	������STM32-V5 ��������߷��䣺  ����Flash�ͺ�Ϊ W25Q64BVSSIG (80MHz)
    	PB3/SPI3_SCK
    	PB4/SPI3_MISO
    	PB5/SPI3_MOSI
    	PF8/SF_CS
    	STM32Ӳ��SPI�ӿ� = SPI3
    */
    GPIO_InitTypeDef GPIO_InitStructure;
    /* ʹ��GPIO ʱ�� */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOF, ENABLE);

    /* ���� SCK, MISO �� MOSI Ϊ���ù��� */
    //GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI3);
    //GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI3);
    //GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI3);
    /* ���� SCK, MISO �� MOSI Ϊ���ù��� */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI1);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI1);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* ����Ƭѡ����Ϊ�������ģʽ */
    SF_CS_HIGH();		/* Ƭѡ�øߣ���ѡ�� */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOF, &GPIO_InitStructure);

    /* ����SPIӲ���������ڷ��ʴ���Flash */
    bsp_CfgSPIForSFlash();
    sf_ReadInfo();				/* �Զ�ʶ��оƬ�ͺ� */
    SF_CS_LOW();				/* �����ʽ��ʹ�ܴ���FlashƬѡ */
    sf_SendByte(CMD_DISWR);		/* ���ͽ�ֹд�������,��ʹ�����д���� */
    SF_CS_HIGH();				/* �����ʽ�����ܴ���FlashƬѡ */
    sf_WaitForWriteEnd();		/* �ȴ�����Flash�ڲ�������� */
    sf_WriteStatus(0);			/* �������BLOCK��д���� */
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_CfgSPIForSFlash
*	����˵��: ����STM32�ڲ�SPIӲ���Ĺ���ģʽ���ٶȵȲ��������ڷ���SPI�ӿڵĴ���Flash��
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_CfgSPIForSFlash(void)
{
    SPI_InitTypeDef  SPI_InitStructure;
    // ��SPIʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    // ����SPIӲ������
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;	/* ���ݷ���2��ȫ˫�� */
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		/* STM32��SPI����ģʽ ������ģʽ */
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;	/* ����λ���� �� 8λ */
    //SPI_CPOL��SPI_CPHA���ʹ�þ���ʱ�Ӻ����ݲ��������λ��ϵ��
    //��������: ���߿����Ǹߵ�ƽ,��2�����أ������ز�������)
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;			/* ʱ�������ز������� */
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;		/* ʱ�ӵĵ�2�����ز������� */
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;			/* Ƭѡ���Ʒ�ʽ��������� */

    //���ò�����Ԥ��Ƶϵ��
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	/* ����λ������򣺸�λ�ȴ� */
    SPI_InitStructure.SPI_CRCPolynomial = 7;			/* CRC����ʽ�Ĵ�������λ��Ϊ7�������̲��� */
    SPI_Init(SPIPort, &SPI_InitStructure);
    SPI_Cmd(SPIPort, DISABLE);							/* �Ƚ�ֹSPI  */
    SPI_Cmd(SPIPort, ENABLE);							/* ʹ��SPI  */
}


/*
*********************************************************************************************************
*	�� �� ��: sf_EraseSector
*	����˵��: ����ָ��������
*	��    ��:  _uiSectorAddr : ������ַ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void sf_EraseSector(uint32_t _uiSectorAddr)
{
	sf_WriteEnable();								/* ����дʹ������ */

	/* ������������ */
	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_SE);								/* ���Ͳ������� */
	sf_SendByte((_uiSectorAddr & 0xFF0000) >> 16);	/* ����������ַ�ĸ�8bit */
	sf_SendByte((_uiSectorAddr & 0xFF00) >> 8);		/* ����������ַ�м�8bit */
	sf_SendByte(_uiSectorAddr & 0xFF);				/* ����������ַ��8bit */
	SF_CS_HIGH();									/* ����Ƭѡ */

	sf_WaitForWriteEnd();							/* �ȴ�����Flash�ڲ�д������� */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_EraseChip
*	����˵��: ��������оƬ
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void sf_EraseChip(void)
{
	sf_WriteEnable();								/* ����дʹ������ */

	/* ������������ */
	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_BE);							/* ������Ƭ�������� */
	SF_CS_HIGH();									/* ����Ƭѡ */

	sf_WaitForWriteEnd();							/* �ȴ�����Flash�ڲ�д������� */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_PageWrite
*	����˵��: ��һ��page��д�������ֽڡ��ֽڸ������ܳ���ҳ���С��4K)
*	��    ��:  	_pBuf : ����Դ��������
*				_uiWriteAddr ��Ŀ�������׵�ַ
*				_usSize �����ݸ��������ܳ���ҳ���С
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void sf_PageWrite(uint8_t * _pBuf, uint32_t _uiWriteAddr, uint16_t _usSize)
{
	uint32_t i, j;
		for (j = 0; j < _usSize / 256; j++)
		{
			sf_WriteEnable();								/* ����дʹ������ */
			SF_CS_LOW();									/* ʹ��Ƭѡ */
			sf_SendByte(0x02);								/* ����AAI����(��ַ�Զ����ӱ��) */
			sf_SendByte((_uiWriteAddr & 0xFF0000) >> 16);	/* ����������ַ�ĸ�8bit */
			sf_SendByte((_uiWriteAddr & 0xFF00) >> 8);		/* ����������ַ�м�8bit */
			sf_SendByte(_uiWriteAddr & 0xFF);				/* ����������ַ��8bit */

			for (i = 0; i < 256; i++)
			{
				sf_SendByte(*_pBuf++);					/* �������� */
			}

			SF_CS_HIGH();								/* ��ֹƬѡ */

			sf_WaitForWriteEnd();						/* �ȴ�����Flash�ڲ�д������� */

			_uiWriteAddr += 256;
		}

		/* ����д����״̬ */
		SF_CS_LOW();
		sf_SendByte(CMD_DISWR);
		SF_CS_HIGH();

		sf_WaitForWriteEnd();							/* �ȴ�����Flash�ڲ�д������� */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_ReadBuffer
*	����˵��: ������ȡ�����ֽڡ��ֽڸ������ܳ���оƬ������
*	��    ��:  	_pBuf : ����Դ��������
*				_uiReadAddr ���׵�ַ
*				_usSize �����ݸ���, ���Դ���PAGE_SIZE,���ǲ��ܳ���оƬ������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void sf_ReadBuffer(uint8_t * _pBuf, uint32_t _uiReadAddr, uint32_t _uiSize)
{
	/* �����ȡ�����ݳ���Ϊ0���߳�������Flash��ַ�ռ䣬��ֱ�ӷ��� */
	if ((_uiSize == 0) ||(_uiReadAddr + _uiSize) > _totalSize)
	{
		return;
	}
	/* ������������ */
	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_READ);							/* ���Ͷ����� */
	sf_SendByte((_uiReadAddr & 0xFF0000) >> 16);	/* ����������ַ�ĸ�8bit */
	sf_SendByte((_uiReadAddr & 0xFF00) >> 8);		/* ����������ַ�м�8bit */
	sf_SendByte(_uiReadAddr & 0xFF);				/* ����������ַ��8bit */
	while (_uiSize--)
	{
		*_pBuf++ = sf_SendByte(DUMMY_BYTE);			/* ��һ���ֽڲ��洢��pBuf�������ָ���Լ�1 */
	}
	SF_CS_HIGH();									/* ����Ƭѡ */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_CmpData
*	����˵��: �Ƚ�Flash������.
*	��    ��:  	_ucpTar : ���ݻ�����
*				_uiSrcAddr ��Flash��ַ
*				_uiSize �����ݸ���, ���Դ���PAGE_SIZE,���ǲ��ܳ���оƬ������
*	�� �� ֵ: 0 = ���, 1 = ����
*********************************************************************************************************
*/
static uint8_t sf_CmpData(uint32_t _uiSrcAddr, uint8_t *_ucpTar, uint32_t _uiSize)
{
	uint8_t ucValue;

	/* �����ȡ�����ݳ���Ϊ0���߳�������Flash��ַ�ռ䣬��ֱ�ӷ��� */
	if ((_uiSrcAddr + _uiSize) > _totalSize)
	{
		return 1;
	}

	if (_uiSize == 0)
	{
		return 0;
	}

	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_READ);							/* ���Ͷ����� */
	sf_SendByte((_uiSrcAddr & 0xFF0000) >> 16);		/* ����������ַ�ĸ�8bit */
	sf_SendByte((_uiSrcAddr & 0xFF00) >> 8);		/* ����������ַ�м�8bit */
	sf_SendByte(_uiSrcAddr & 0xFF);					/* ����������ַ��8bit */
	while (_uiSize--)
	{
		/* ��һ���ֽ� */
		ucValue = sf_SendByte(DUMMY_BYTE);
		if (*_ucpTar++ != ucValue)
		{
			SF_CS_HIGH();
			return 1;
		}
	}
	SF_CS_HIGH();
	return 0;
}

/*
*********************************************************************************************************
*	�� �� ��: sf_NeedErase
*	����˵��: �ж�дPAGEǰ�Ƿ���Ҫ�Ȳ�����
*	��    ��:   _ucpOldBuf �� ������
*			   _ucpNewBuf �� ������
*			   _uiLen �����ݸ��������ܳ���ҳ���С
*	�� �� ֵ: 0 : ����Ҫ������ 1 ����Ҫ����
*********************************************************************************************************
*/
static uint8_t sf_NeedErase(uint8_t * _ucpOldBuf, uint8_t *_ucpNewBuf, uint16_t _usLen)
{
	uint16_t i;
	uint8_t ucOld;

	/*
	�㷨��1����old ��, new ����
	      old    new
		  1101   0101
	~     1111
		= 0010   0101

	�㷨��2��: old �󷴵Ľ���� new λ��
		  0010   old
	&	  0101   new
		 =0000

	�㷨��3��: ���Ϊ0,���ʾ�������. �����ʾ��Ҫ����
	*/

	for (i = 0; i < _usLen; i++)
	{
		ucOld = *_ucpOldBuf++;
		ucOld = ~ucOld;

		/* ע������д��: if (ucOld & (*_ucpNewBuf++) != 0) */
		if ((ucOld & (*_ucpNewBuf++)) != 0)
		{
			return 1;
		}
	}
	return 0;
}

/*
*********************************************************************************************************
*	�� �� ��: sf_AutoWritePage
*	����˵��: д1��PAGE��У��,�������ȷ������д���Ρ��������Զ���ɲ���������
*	��    ��:  	_pBuf : ����Դ��������
*				_uiWriteAddr ��Ŀ�������׵�ַ
*				_usSize �����ݸ��������ܳ���ҳ���С
*	�� �� ֵ: 0 : ���� 1 �� �ɹ�
*********************************************************************************************************
*/
static uint8_t sf_AutoWritePage(uint8_t *_ucpSrc, uint32_t _uiWrAddr, uint16_t _usWrLen)
{
	uint16_t i;
	uint16_t j;					/* ������ʱ */
	uint32_t uiFirstAddr;		/* ������ַ */
	uint8_t ucNeedErase;		/* 1��ʾ��Ҫ���� */
	uint8_t cRet;

	/* ����Ϊ0ʱ����������,ֱ����Ϊ�ɹ� */
	if (_usWrLen == 0)
	{
		return 1;
	}

	/* ���ƫ�Ƶ�ַ����оƬ�������˳� */
	if (_uiWrAddr >= _totalSize)
	{
		return 0;
	}

	/* ������ݳ��ȴ����������������˳� */
	if (_usWrLen > FLASH_SECTOR_SIZE)
	{
		return 0;
	}

	/* ���FLASH�е�����û�б仯,��дFLASH */
	sf_ReadBuffer(_flashBuff, _uiWrAddr, _usWrLen);
	if (memcmp(_flashBuff, _ucpSrc, _usWrLen) == 0)
	{
		return 1;
	}

	/* �ж��Ƿ���Ҫ�Ȳ������� */
	/* ����������޸�Ϊ�����ݣ�����λ���� 1->0 ���� 0->0, ���������,���Flash���� */
	ucNeedErase = 0;
	if (sf_NeedErase(_flashBuff, _ucpSrc, _usWrLen))
	{
		ucNeedErase = 1;
	}

	uiFirstAddr = _uiWrAddr & (~(FLASH_SECTOR_SIZE - 1));

	if (_usWrLen == FLASH_SECTOR_SIZE)		/* ������������д */
	{
		for	(i = 0; i < FLASH_SECTOR_SIZE; i++)
		{
			_flashBuff[i] = _ucpSrc[i];
		}
	}
	else						/* ��д�������� */
	{
		/* �Ƚ��������������ݶ��� */
		sf_ReadBuffer(_flashBuff, uiFirstAddr, FLASH_SECTOR_SIZE);

		/* ���������ݸ��� */
		i = _uiWrAddr & (FLASH_SECTOR_SIZE - 1);
		memcpy(&_flashBuff[i], _ucpSrc, _usWrLen);
	}

	/* д��֮�����У�飬�������ȷ����д�����3�� */
	cRet = 0;
	for (i = 0; i < 3; i++)
	{

		/* ����������޸�Ϊ�����ݣ�����λ���� 1->0 ���� 0->0, ���������,���Flash���� */
		if (ucNeedErase == 1)
		{
			sf_EraseSector(uiFirstAddr);		/* ����1������ */
		}

		/* ���һ��PAGE */
		sf_PageWrite(_flashBuff, uiFirstAddr, FLASH_SECTOR_SIZE);

		if (sf_CmpData(_uiWrAddr, _ucpSrc, _usWrLen) == 0)
		{
			cRet = 1;
			break;
		}
		else
		{
			if (sf_CmpData(_uiWrAddr, _ucpSrc, _usWrLen) == 0)
			{
				cRet = 1;
				break;
			}

			/* ʧ�ܺ��ӳ�һ��ʱ�������� */
			for (j = 0; j < 10000; j++);
		}
	}

	return cRet;
}

/*
*********************************************************************************************************
*	�� �� ��: sf_WriteBuffer
*	����˵��: д1��������У��,�������ȷ������д���Ρ��������Զ���ɲ���������
*	��    ��:  	_pBuf : ����Դ��������
*				_uiWrAddr ��Ŀ�������׵�ַ
*				_usSize �����ݸ��������ܳ���ҳ���С
*	�� �� ֵ: 1 : �ɹ��� 0 �� ʧ��
*********************************************************************************************************
*/
uint8_t sf_WriteBuffer(uint8_t* _pBuf, uint32_t _uiWriteAddr, uint16_t _usWriteSize)
{
	uint16_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;
	Addr = _uiWriteAddr % FLASH_SECTOR_SIZE;
	count = FLASH_SECTOR_SIZE - Addr;
	NumOfPage =  _usWriteSize / FLASH_SECTOR_SIZE;
	NumOfSingle = _usWriteSize % FLASH_SECTOR_SIZE;

	if (Addr == 0) /* ��ʼ��ַ��ҳ���׵�ַ  */
	{
		if (NumOfPage == 0) /* ���ݳ���С��ҳ���С */
		{
			if (sf_AutoWritePage(_pBuf, _uiWriteAddr, _usWriteSize) == 0)
			{
				return 0;
			}
		}
		else 	/* ���ݳ��ȴ��ڵ���ҳ���С */
		{
			while (NumOfPage--)
			{
				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, FLASH_SECTOR_SIZE) == 0)
				{
					return 0;
				}
				_uiWriteAddr +=  FLASH_SECTOR_SIZE;
				_pBuf += FLASH_SECTOR_SIZE;
			}
			if (sf_AutoWritePage(_pBuf, _uiWriteAddr, NumOfSingle) == 0)
			{
				return 0;
			}
		}
	}
	else  /* ��ʼ��ַ����ҳ���׵�ַ  */
	{
		if (NumOfPage == 0) /* ���ݳ���С��ҳ���С */
		{
			if (NumOfSingle > count) /* (_usWriteSize + _uiWriteAddr) > SPI_FLASH_PAGESIZE */
			{
				temp = NumOfSingle - count;

				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, count) == 0)
				{
					return 0;
				}

				_uiWriteAddr +=  count;
				_pBuf += count;

				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, temp) == 0)
				{
					return 0;
				}
			}
			else
			{
				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, _usWriteSize) == 0)
				{
					return 0;
				}
			}
		}
		else	/* ���ݳ��ȴ��ڵ���ҳ���С */
		{
			_usWriteSize -= count;
			NumOfPage =  _usWriteSize / FLASH_SECTOR_SIZE;
			NumOfSingle = _usWriteSize % FLASH_SECTOR_SIZE;

			if (sf_AutoWritePage(_pBuf, _uiWriteAddr, count) == 0)
			{
				return 0;
			}

			_uiWriteAddr +=  count;
			_pBuf += count;

			while (NumOfPage--)
			{
				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, FLASH_SECTOR_SIZE) == 0)
				{
					return 0;
				}
				_uiWriteAddr +=  FLASH_SECTOR_SIZE;
				_pBuf += FLASH_SECTOR_SIZE;
			}

			if (NumOfSingle != 0)
			{
				if (sf_AutoWritePage(_pBuf, _uiWriteAddr, NumOfSingle) == 0)
				{
					return 0;
				}
			}
		}
	}
	return 1;	/* �ɹ� */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_ReadID
*	����˵��: ��ȡ����ID
*	��    ��:  ��
*	�� �� ֵ: 32bit������ID (���8bit��0����ЧIDλ��Ϊ24bit��
*********************************************************************************************************
*/
uint32_t sf_ReadID(void)
{
	uint32_t uiID;
	uint8_t id1, id2, id3;

	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_RDID);								/* ���Ͷ�ID���� */
	id1 = sf_SendByte(DUMMY_BYTE);					/* ��ID�ĵ�1���ֽ� */
	id2 = sf_SendByte(DUMMY_BYTE);					/* ��ID�ĵ�2���ֽ� */
	id3 = sf_SendByte(DUMMY_BYTE);					/* ��ID�ĵ�3���ֽ� */
	SF_CS_HIGH();									/* ����Ƭѡ */

	uiID = ((uint32_t)id1 << 16) | ((uint32_t)id2 << 8) | id3;

	return uiID;
}

/*
*********************************************************************************************************
*	�� �� ��: sf_ReadInfo
*	����˵��: ��ȡ����ID,�������������
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void sf_ReadInfo(void)
{
	/* �Զ�ʶ����Flash�ͺ� */
	{
		u32 id = sf_ReadID();	/* оƬID */

//		switch (g_tSF.ChipID)
//		{
//			case SST25VF016B_ID:
//				strcpy(g_tSF.ChipName, "SST25VF016B");
//				g_tSF.TotalSize = 2 * 1024 * 1024;	/* ������ = 2M */
//				g_tSF.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//				break;

//			case MX25L1606E_ID:
//				strcpy(g_tSF.ChipName, "MX25L1606E");
//				g_tSF.TotalSize = 2 * 1024 * 1024;	/* ������ = 2M */
//				g_tSF.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//				break;

//			case W25Q64BV_ID:
//				strcpy(g_tSF.ChipName, "W25Q64BV");
//				g_tSF.TotalSize = 8 * 1024 * 1024;	/* ������ = 8M */
//				g_tSF.PageSize = 4 * 1024;			/* ҳ���С = 4K */
//				break;

//			default:
//				strcpy(g_tSF.ChipName, "Unknow Flash");
//				g_tSF.TotalSize = 2 * 1024 * 1024;
//				g_tSF.PageSize = 4 * 1024;
//				break;
//		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: sf_SendByte
*	����˵��: ����������һ���ֽڣ�ͬʱ��MISO���߲����������ص�����
*	��    ��:  _ucByte : ���͵��ֽ�ֵ
*	�� �� ֵ: ��MISO���߲����������ص�����
*********************************************************************************************************
*/
static uint8_t sf_SendByte(uint8_t _ucValue)
{
	/* �ȴ��ϸ�����δ������� */
	while (SPI_I2S_GetFlagStatus(SPIPort, SPI_I2S_FLAG_TXE) == RESET);

	/* ͨ��SPIӲ������1���ֽ� */
	SPI_I2S_SendData(SPIPort, _ucValue);

	/* �ȴ�����һ���ֽ�������� */
	while (SPI_I2S_GetFlagStatus(SPIPort, SPI_I2S_FLAG_RXNE) == RESET);

	/* ���ش�SPI���߶��������� */
	return SPI_I2S_ReceiveData(SPIPort);
}

/*
*********************************************************************************************************
*	�� �� ��: sf_WriteEnable
*	����˵��: ����������дʹ������
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void sf_WriteEnable(void)
{
	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_WREN);								/* �������� */
	SF_CS_HIGH();									/* ����Ƭѡ */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_WriteStatus
*	����˵��: д״̬�Ĵ���
*	��    ��:  _ucValue : ״̬�Ĵ�����ֵ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void sf_WriteStatus(uint8_t _ucValue)
{
		SF_CS_LOW();									/* ʹ��Ƭѡ */
		sf_SendByte(CMD_WRSR);							/* ������� д״̬�Ĵ��� */
		sf_SendByte(_ucValue);							/* �������ݣ�״̬�Ĵ�����ֵ */
		SF_CS_HIGH();									/* ����Ƭѡ */
}

/*
*********************************************************************************************************
*	�� �� ��: sf_WaitForWriteEnd
*	����˵��: ����ѭ����ѯ�ķ�ʽ�ȴ������ڲ�д�������
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void sf_WaitForWriteEnd(void)
{
	SF_CS_LOW();									/* ʹ��Ƭѡ */
	sf_SendByte(CMD_RDSR);							/* ������� ��״̬�Ĵ��� */
	while((sf_SendByte(DUMMY_BYTE) & WIP_FLAG) == SET);	/* �ж�״̬�Ĵ�����æ��־λ */
	SF_CS_HIGH();									/* ����Ƭѡ */
}



//��ʼ��flash
u8 W25Q64B_SPIFlashInit(void)
{
	bsp_InitSFlash();
	return 0;
}

//�����洢����ȫ������
void W25Q64B_ChipErase(void)
{
	sf_EraseChip();
}

//�����õ�ַ���ڵ�4K�洢�������ݡ� sectorIndex: ������ַ
void W25Q64B_SectorErase_4KByte(u32 sectorIndex)
{
	sf_EraseSector(sectorIndex);
}

//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
void W25Q64B_ReadBytes(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count)
{
	if(count<=0)
		return;
	u32 readAddr=sectorBaseAddr*FLASH_SECTOR_SIZE+startIndex;
	memset(data,0,count);
	sf_ReadBuffer(data, readAddr, count);
}

//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void W25Q64B_ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount)
{
	sf_ReadBuffer(&readData[buffAddr], flashAddr, dataCount);
}

//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void W25Q64B_ReadOneSector(u16 sectionIndex,u8* readDatas)
{
	W25Q64B_ReadBytes(sectionIndex,readDatas,0, FLASH_SECTOR_SIZE);
}

//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void W25Q64B_WriteOneSector(u16 sectionIndex,u8* writeDatas)
{	
	u32 writeAddr=sectionIndex*FLASH_SECTOR_SIZE;
	sf_PageWrite(writeDatas,writeAddr,FLASH_SECTOR_SIZE);
}

//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void W25Q64B_WriteBytes(u16 sectionIndex,u8* writeDatas,u32 dataCount)
{
	if(dataCount<=0)
		return;  
	u32 writeAddr=sectionIndex*FLASH_SECTOR_SIZE;
	sf_WriteBuffer(writeDatas,writeAddr,dataCount);
}

//Flash����
bool W25Q64B_FlashTest_bk(void)
{
	u8 value=0;
	u16 testList[10]={0,1,5,6,0x41,0x42,0x45,0x46,0x50,0x51};
	for(u16 jj=0;jj<10;jj++)
	{
		u16 testSector=testList[jj];
	memset(_testFlashBuff,0,FLASH_SECTOR_SIZE);
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
	W25Q64B_SectorErase_4KByte(testSector);
	W25Q64B_WriteOneSector(testSector,_testFlashBuff);
	memset(_testFlashBuff,0,FLASH_SECTOR_SIZE);
	W25Q64B_ReadOneSector(testSector,_testFlashBuff);
}
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

bool W25Q64B_FlashTest(void)
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
	W25Q64B_WriteOneSector(SPIFlashTestSection,_testFlashBuff);
	memset(_testFlashBuff,0,FLASH_SECTOR_SIZE);
	W25Q64B_ReadOneSector(SPIFlashTestSection,_testFlashBuff);
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