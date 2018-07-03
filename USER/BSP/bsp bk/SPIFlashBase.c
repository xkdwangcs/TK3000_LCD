
#include "SPIFlashBase.h"
#include "PublicFunction.h"
#include "SST25VF032B.h"
#include "W25Q64B.h"	
#include "MemoryAlloc.h"

u8 _flashBuff[FLASH_SECTOR_SIZE] __at(FlashBuffAddr);
u8 _testFlashBuff[FLASH_SECTOR_SIZE] __at(FlashTestBuffAddr);

//初始化 SPI flash
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

//擦除整块芯片
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

//擦除该地址所在的4K存储器的数据。 sectorIndex: 扇区地址
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

//读取指定扇区基址+偏移的一段数据，可以是跨多扇区
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

//通过指定地址，可以读取多个扇区内的数据，不覆盖原有数据，读取到缓存指定的索引
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

//从一块指定的扇区读取FLASH_SECTOR_SIZE长度的数据
//sectionIndex：从0开始的扇区索引;readDatas：要读取的数据内存空间,要确保内存空间是连续的
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

//向一块指定的扇区写入FLASH_SECTOR_SIZE长度数据
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块
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

//向指定的扇区基址开始写入指定长度的数据，可以一次写多个扇区。
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块；dataCount:写入的数据长度
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
//Flash测试
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