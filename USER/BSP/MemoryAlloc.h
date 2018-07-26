#ifndef __MEMORYALLOC_H
#define __MEMORYALLOC_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include "stm32f4xx.h"
#include "absacc.h"
#include "string.h"
#include "PublicFunction.h"
#include "COM.h"
#include "bsp_nand_flash.h"

#define FLASH_SECTOR_SIZE 4096	 
	 
	 
/*************BKPSRAM****************/	 
//使用的备份寄存器（最大4K）
#define FirmwareUpdateTagAddr BKPSRAM_BASE //固件下载、升级标志的地址，放在备份寄存器的第1个
#define PermissionAddr BKPSRAM_BASE+1 //热启动时权限保存地址，在第2个
//#define FormatDiskAddr_OneSYS BKPSRAM_BASE+2 //由引导第一次下载固件后要格式化磁盘，在第3个
#define InportEventCancelTag BKPSRAM_BASE+3 //输入口事件是否取消保存地址，在第4个
#define OutputStateAddrBase BKPSRAM_BASE+32 //前32byte备用，输出口状态从此地址开始存放,一共使用OutPortNum个字节		 
/*************BKPSRAM END****************/


/***************CCMRAM******************/
#define CCMBaseAddr 	    0x10000000 	//CCM内存的起始地址
#define CCMSize				0x10000 	//CCM内存大小：64KB	 

//#define FlashBuffAddr   				CCMBaseAddr 
//#define FlashTestBuffAddr   		FlashBuffAddr+sizeof(s_usLUT)
#define FileBuffAddr    				CCMBaseAddr //FlashTestBuffAddr+sizeof(s_ucTempBuf) 
#define DicBuffAddr						FileBuffAddr+ FLASH_SECTOR_SIZE //字典结构缓存地址
#define ComSendBuffAddr					DicBuffAddr+sizeof(_dic)				//串口发送缓存地址
#define ComRecvBuffAddr					ComSendBuffAddr+_comBuffLeng			//串口接收缓存地址
#define picBuffAddr						ComRecvBuffAddr+_comBuffLeng			//emWin刷图片缓存
/***************CCMRAM END*****************/	 

#ifdef __cplusplus
}
#endif

#endif