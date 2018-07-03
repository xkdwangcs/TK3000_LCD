#ifndef SST25V_H_
#define SST25V_H_

#ifdef __cplusplus
 extern "C" {
#endif 

#include "stm32f4xx.h"
#include "string.h"
#include "stdbool.h"

/**
 4KbytesΪһ��Sector
 16������Ϊ1��Block
 SST25VF032B����Ϊ4M�ֽ�,����64��Block(��),1024��Sector��������
 */
#ifdef SST25VF032B	
	 
	#define SST25_ReadData                      0x03
	#define SST25_FastReadData                  0x0B
	#define SST25_4KByte_BlockERASE             0x20
	#define SST25_32KByte_BlockErase            0x52
	#define SST25_64KByte_BlockErase            0xD8
	#define SST25_ChipErase                     0xC7

	#define SST25_ByteProgram                   0x02
	#define SST25_AAI_WordProgram               0xAD

	#define SST25_ReadStatusReg                 0x05
	#define SST25_EnableWriteStatusReg          0x50
	#define SST25_WriteStatusReg                0x01
	#define SST25_WriteEnable                   0x06
	#define SST25_WriteDisable                  0x04
	#define SST25_ManufactDeviceID              0x90
	#define SST25_JedecDeviceID                 0x9F
	#define SST25_EBSY                          0x70
	#define SST25_DBSY                          0x80  
	#define SST25_Dummy_Byte                    0xFF  //���ֽ�

	#define SPI_FLASH_CS_LOW()                  GPIO_ResetBits(GPIOC, GPIO_Pin_4)
	#define SPI_FLASH_CS_HIGH()                 GPIO_SetBits(GPIOC, GPIO_Pin_4)  
	#define SST25_CS_LOW()                      SPI_FLASH_CS_LOW()
	#define SST25_CS_HIGH()                     SPI_FLASH_CS_HIGH()
#endif

//��ʼ��flash
u8 SST25V_SPIFlashInit(void);
//�����洢����ȫ������
void SST25V_ChipErase(void);
//�����õ�ַ���ڵ�4K�洢�������ݡ� sectorIndex: ������ַ
void SST25V_SectorErase_4KByte(u32 sectorIndex);
//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
void SST25V_ReadBytes(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count); 
//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void SST25V_ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount);
//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void SST25V_ReadOneSector(u16 sectionIndex,u8* readDatas);
//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void SST25V_WriteOneSector(u16 sectionIndex,u8* writeDatas);
//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void SST25V_WriteBytes(u16 sectionIndex,u8* writeDatas,u32 dataCount);
//Flash����
bool SST25V_FlashTest(void);

#ifdef __cplusplus
}
#endif

#endif
