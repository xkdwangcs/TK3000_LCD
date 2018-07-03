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
W25Q64�����˾��������64Mb�ģ�Ҳ����8M�ֽڣ�
��W25Q64�����8M��������Ϊ128��-Block��ÿ��64K�ֽڣ��ֳ�16��������ÿ������4K�ֽڣ�
�����ǣ�W25Q64--8M  һ����--64K   һ������4K����С������λΪһ������
�ؼ���---����������Ҫ��W25Q64����һ������4K�Ļ�������������SRAMҪ��Ƚϸߣ�Ҫ��оƬ������4K����SRAM���ܺܺõĲ�����(�ţ�Ҫ���ٻ�����)
*/	 
#ifdef W25Q64B
	#define FLASH_TOTAL_SIZE									8 * 1024 * 1024		//������ 8M 
	#define FLASH_SECTOR_SIZE	                4096 				//һ���������ֽ���
	#define FLASH_SECTOR_COUNT	              	2038 				//��������,ԭ����1024��������������10����������ΪFATFS,�洢���޸ĵĲ���
	#define FLASH_BLOCK_SIZE	                65536				//���ֽ��� 64K
	#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE
#endif

#ifdef SST25VF032B	
	#define FLASH_TOTAL_SIZE									4 * 1024 * 1024		//������ 4M 	 
	#define FLASH_SECTOR_SIZE	                4096 				//һ���������ֽ���
	#define FLASH_SECTOR_COUNT	                1014 				//��������,ԭ����1024��������������10����������ΪFATFS,�洢���޸ĵĲ���
	#define FLASH_BLOCK_SIZE	                65536				//���ֽ���
	#define FLASH_PAGES_PER_SECTOR	FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE
#endif
	 
#define SPIFlashTestSection  					FLASH_SECTOR_COUNT+1 //SPIFlash ���������ţ���Ԥ��������һ�� 	 

extern u8 _flashBuff[FLASH_SECTOR_SIZE];
extern u8 _testFlashBuff[FLASH_SECTOR_SIZE];

//��ʼ�� SPI flash
u8 SPIFlashInit(void);
//��������оƬ
void SPIFlashChipErase(void);
//�����õ�ַ���ڵ�4K�洢�������ݡ� sectorIndex: ������ַ
void SPIFlashChipErase4K(u32 sectorIndex);	 
//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
void ReadBytesSPIFlash(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count); 
//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount);
//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void ReadOneSectorSPIFlash(u16 sectionIndex,u8* readDatas);
//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void WriteOneSectorSPIFlash(u16 sectionIndex,u8* writeDatas);
//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void WriteBytesSPIFlash(u16 sectionIndex,u8* writeDatas,u32 dataCount);
//Flash����
bool SPIFlashTest(void);

#ifdef __cplusplus
}
#endif

#endif
