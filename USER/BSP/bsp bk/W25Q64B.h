
#ifndef _W25Q64B_H
#define _W25Q64B_H

#include "stm32f4xx.h"
#include "string.h"
#include "stdbool.h"

/**
W25Q64，华邦公司，大容量64Mb的，也就是8M字节，
（W25Q64把这个8M的容量分为128块-Block，每块64K字节，分出16个扇区，每个扇区4K字节）
即就是：W25Q64--8M  一个块--64K   一个扇区4K。最小擦除单位为一个扇区
关键点---这样我们需要给W25Q64开辟一个至少4K的缓存区，这样对SRAM要求比较高，要求芯片必须有4K以上SRAM才能很好的操作。(嗯，要开辟缓存区)
*/

#define CMD_AAI       0xAD  	/* AAI 连续编程指令(FOR SST25VF016B) */
#define CMD_DISWR	  0x04		/* 禁止写, 退出AAI状态 */
#define CMD_EWRSR	  0x50		/* 允许写状态寄存器的命令 */
#define CMD_WRSR      0x01  	/* 写状态寄存器命令 */
#define CMD_WREN      0x06		/* 写使能命令 */
#define CMD_READ      0x03  	/* 读数据区命令 */
#define CMD_RDSR      0x05		/* 读状态寄存器命令 */
#define CMD_RDID      0x9F		/* 读器件ID命令 */
#define CMD_SE        0x20		/* 擦除扇区命令 */
#define CMD_BE        0xC7		/* 批量擦除命令 */
#define DUMMY_BYTE    0xA5		/* 哑命令，可以为任意值，用于读操作 */
#define WIP_FLAG      0x01		/* 状态寄存器中的正在编程标志（WIP) */

//初始化flash
u8 W25Q64B_SPIFlashInit(void);
//擦除存储器的全部数据
void W25Q64B_ChipErase(void);
//擦除该地址所在的4K存储器的数据。 sectorIndex: 扇区地址
void W25Q64B_SectorErase_4KByte(u32 sectorIndex);
//读取指定扇区基址+偏移的一段数据，可以是跨多扇区
void W25Q64B_ReadBytes(u16 sectorBaseAddr,u8* data,u32 startIndex,u32 count); 
//通过指定地址，可以读取多个扇区内的数据，不覆盖原有数据，读取到缓存指定的索引
void W25Q64B_ReadBytesOffset(u32 flashAddr,u8* readData, u32 buffAddr,u32 dataCount);
//从一块指定的扇区读取FLASH_SECTOR_SIZE长度的数据
//sectionIndex：从0开始的扇区索引;readDatas：要读取的数据内存空间,要确保内存空间是连续的
void W25Q64B_ReadOneSector(u16 sectionIndex,u8* readDatas);
//向一块指定的扇区写入FLASH_SECTOR_SIZE长度数据
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块
void W25Q64B_WriteOneSector(u16 sectionIndex,u8* writeDatas);
//向指定的扇区基址开始写入指定长度的数据，可以一次写多个扇区。
//sectionIndex：从0开始的扇区索引；writeDatas：要写入的数据块；dataCount:写入的数据长度
void W25Q64B_WriteBytes(u16 sectionIndex,u8* writeDatas,u32 dataCount);
//Flash测试
bool W25Q64B_FlashTest(void);

#endif

