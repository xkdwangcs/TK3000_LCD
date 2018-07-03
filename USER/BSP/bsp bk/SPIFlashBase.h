#ifndef __SPIFLASHBASE_H_
#define __SPIFLASHBASE_H_

#ifdef __cplusplus
 extern "C" {
#endif 

#include "stm32f4xx.h"
#include "string.h"
#include "stdbool.h"
//#include "SST25VF032B.h"
//#include "W25Q64B.h"	 
	 
#define W25Q64B
//#define SST25VF032B
//#define MX25L1606E  	
	 

/**
W25Q64，华邦公司，大容量64Mb的，也就是8M字节，
（W25Q64把这个8M的容量分为128块-Block，每块64K字节，分出16个扇区，每个扇区4K字节）
即就是：W25Q64--8M  一个块--64K   一个扇区4K。最小擦除单位为一个扇区
关键点---这样我们需要给W25Q64开辟一个至少4K的缓存区，这样对SRAM要求比较高，要求芯片必须有4K以上SRAM才能很好的操作。(嗯，要开辟缓存区)
*/	 
#ifdef W25Q64B
	#define FLASH_TOTAL_SIZE									8 * 1024 * 1024		//总容量 8M 
	#define FLASH_SECTOR_SIZE	                4096 				//一个扇区的字节数
	#define FLASH_SECTOR_COUNT	              	2038 				//扇区总数,原本有1024个扇区，但后面10个扇区不作为FATFS,存储不修改的参数
	#define FLASH_BLOCK_SIZE	                65536				//块字节数 64K
	#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE
#endif

#ifdef SST25VF032B	
	#define FLASH_TOTAL_SIZE									4 * 1024 * 1024		//总容量 4M 	 
	#define FLASH_SECTOR_SIZE	                4096 				//一个扇区的字节数
	#define FLASH_SECTOR_COUNT	                1014 				//扇区总数,原本有1024个扇区，但后面10个扇区不作为FATFS,存储不修改的参数
	#define FLASH_BLOCK_SIZE	                65536				//块字节数
	#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE
#endif
	 
#define SPIFlashTestSection  					FLASH_SECTOR_COUNT+1 //SPIFlash 测试扇区号，在预留扇区第一个 	 

extern u8 _flashBuff[FLASH_SECTOR_SIZE];
extern u8 _testFlashBuff[FLASH_SECTOR_SIZE];

//初始化 SPI flash
u8 SPIFlashInit(void);
//擦除整块芯片
void SPIFlashChipErase(void);
//擦除该地址所在的4K存储器的数据。 sectorIndex: 扇区地址
void SPIFlashChipErase4K(u32 sectorIndex);	 
//读取指定扇区基址+偏移的一段数据，可以是跨多扇区
void ReadBytesSPIFlash(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count); 
//通过指定地址，可以读取多个扇区内的数据，不覆盖原有数据，读取到缓存指定的索引
void ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount);
//从一块指定的扇区读取FLASH_SECTOR_SIZE长度的数据
//sectionIndex：从0开始的扇区索引;readDatas：要读取的数据内存空间,要确保内存空间是连续的
void ReadOneSectorSPIFlash(u16 sectionIndex,u8* readDatas);
//向一块指定的扇区写入FLASH_SECTOR_SIZE长度数据
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块
void WriteOneSectorSPIFlash(u16 sectionIndex,u8* writeDatas);
//向指定的扇区基址开始写入指定长度的数据，可以一次写多个扇区。
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块；dataCount:写入的数据长度
void WriteBytesSPIFlash(u16 sectionIndex,u8* writeDatas,u32 dataCount);
//Flash测试
bool SPIFlashTest(void);

#ifdef __cplusplus
}
#endif

#endif
