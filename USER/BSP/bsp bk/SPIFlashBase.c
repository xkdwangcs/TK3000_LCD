
#include "SPIFlashBase.h"
#include "PublicFunction.h"
#include "SST25VF032B.h"
#include "W25Q64B.h"	
#include "MemoryAlloc.h"

u8 _flashBuff[FLASH_SECTOR_SIZE] __at(FlashBuffAddr);
u8 _testFlashBuff[FLASH_SECTOR_SIZE] __at(FlashTestBuffAddr);

//��ʼ�� SPI flash
u8 SPIFlashInit(void)
{
	#ifdef W25Q64B
		return W25Q64B_SPIFlashInit();
	#endif
	#ifdef SST25VF032B
		return SST25V_SPIFlashInit();
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//��������оƬ
void SPIFlashChipErase(void)
{
	#ifdef W25Q64B
		W25Q64B_ChipErase();
	#endif
	#ifdef SST25VF032B
		SST25V_ChipErase();
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//�����õ�ַ���ڵ�4K�洢�������ݡ� sectorIndex: ������ַ
void SPIFlashChipErase4K(u32 sectorIndex)
{
	#ifdef W25Q64B
		W25Q64B_SectorErase_4KByte(sectorIndex);
	#endif
	#ifdef SST25VF032B
		SST25V_SectorErase_4KByte(sectorIndex);
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
void ReadBytesSPIFlash(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count)
{
	#ifdef W25Q64B
		W25Q64B_ReadBytes(sectorBaseAddr,data,startIndex,count);
	#endif
	#ifdef SST25VF032B
		SST25V_ReadBytes(sectorBaseAddr,data,startIndex,count);
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount)
{
	#ifdef W25Q64B
		W25Q64B_ReadBytesOffset(flashAddr,readData,buffAddr,dataCount);
	#endif
	#ifdef SST25VF032B
		SST25V_ReadBytesOffset(flashAddr,readData,buffAddr,dataCount);
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void ReadOneSectorSPIFlash(u16 sectionIndex,u8* readDatas)
{
	#ifdef W25Q64B
		W25Q64B_ReadOneSector(sectionIndex,readDatas);
	#endif
	#ifdef SST25VF032B
		SST25V_ReadOneSector(sectionIndex,readDatas);
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void WriteOneSectorSPIFlash(u16 sectionIndex,u8* writeDatas)
{
	#ifdef W25Q64B
		W25Q64B_WriteOneSector(sectionIndex,writeDatas);
	#endif
	#ifdef SST25VF032B
		SST25V_WriteOneSector(sectionIndex,writeDatas);
	#endif
	#ifdef MX25L1606E
	
	#endif
}

//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void WriteBytesSPIFlash(u16 sectionIndex,u8* writeDatas,u32 dataCount)
{
	#ifdef W25Q64B
		W25Q64B_WriteBytes(sectionIndex,writeDatas,dataCount);
	#endif
	#ifdef SST25VF032B
		SST25V_WriteBytes(sectionIndex,writeDatas,dataCount);
	#endif
	#ifdef MX25L1606E
	
	#endif
}
//Flash����
bool SPIFlashTest(void)
{
	#ifdef W25Q64B
		return W25Q64B_FlashTest();
	#endif
	#ifdef SST25VF032B
		return SST25V_FlashTest();
	#endif
	#ifdef MX25L1606E
	
	#endif
}