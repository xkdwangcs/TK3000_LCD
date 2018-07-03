
#ifndef _W25Q64B_H
#define _W25Q64B_H

#include "stm32f4xx.h"
#include "string.h"
#include "stdbool.h"

/**
W25Q64�����˾��������64Mb�ģ�Ҳ����8M�ֽڣ�
��W25Q64�����8M��������Ϊ128��-Block��ÿ��64K�ֽڣ��ֳ�16��������ÿ������4K�ֽڣ�
�����ǣ�W25Q64--8M  һ����--64K   һ������4K����С������λΪһ������
�ؼ���---����������Ҫ��W25Q64����һ������4K�Ļ�������������SRAMҪ��Ƚϸߣ�Ҫ��оƬ������4K����SRAM���ܺܺõĲ�����(�ţ�Ҫ���ٻ�����)
*/

#define CMD_AAI       0xAD  	/* AAI �������ָ��(FOR SST25VF016B) */
#define CMD_DISWR	  0x04		/* ��ֹд, �˳�AAI״̬ */
#define CMD_EWRSR	  0x50		/* ����д״̬�Ĵ��������� */
#define CMD_WRSR      0x01  	/* д״̬�Ĵ������� */
#define CMD_WREN      0x06		/* дʹ������ */
#define CMD_READ      0x03  	/* ������������ */
#define CMD_RDSR      0x05		/* ��״̬�Ĵ������� */
#define CMD_RDID      0x9F		/* ������ID���� */
#define CMD_SE        0x20		/* ������������ */
#define CMD_BE        0xC7		/* ������������ */
#define DUMMY_BYTE    0xA5		/* ���������Ϊ����ֵ�����ڶ����� */
#define WIP_FLAG      0x01		/* ״̬�Ĵ����е����ڱ�̱�־��WIP) */

//��ʼ��flash
u8 W25Q64B_SPIFlashInit(void);
//�����洢����ȫ������
void W25Q64B_ChipErase(void);
//�����õ�ַ���ڵ�4K�洢�������ݡ� sectorIndex: ������ַ
void W25Q64B_SectorErase_4KByte(u32 sectorIndex);
//��ȡָ��������ַ+ƫ�Ƶ�һ�����ݣ������ǿ������
void W25Q64B_ReadBytes(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count); 
//ͨ��ָ����ַ�����Զ�ȡ��������ڵ����ݣ�������ԭ�����ݣ���ȡ������ָ��������
void W25Q64B_ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount);
//��һ��ָ����������ȡFLASH_SECTOR_SIZE���ȵ�����
//sectionIndex����0��ʼ����������;readDatas��Ҫ��ȡ�������ڴ�ռ�,Ҫȷ���ڴ�ռ���������
void W25Q64B_ReadOneSector(u16 sectionIndex,u8* readDatas);
//��һ��ָ��������д��FLASH_SECTOR_SIZE��������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ�
void W25Q64B_WriteOneSector(u16 sectionIndex,u8* writeDatas);
//��ָ����������ַ��ʼд��ָ�����ȵ����ݣ�����һ��д���������
//sectionIndex����0��ʼ������������writeDatas��Ҫд������ݿ飻dataCount:д������ݳ���
void W25Q64B_WriteBytes(u16 sectionIndex,u8* writeDatas,u32 dataCount);
//Flash����
bool W25Q64B_FlashTest(void);

#endif

