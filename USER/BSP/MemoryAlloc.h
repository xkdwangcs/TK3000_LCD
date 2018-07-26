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
//ʹ�õı��ݼĴ��������4K��
#define FirmwareUpdateTagAddr BKPSRAM_BASE //�̼����ء�������־�ĵ�ַ�����ڱ��ݼĴ����ĵ�1��
#define PermissionAddr BKPSRAM_BASE+1 //������ʱȨ�ޱ����ַ���ڵ�2��
//#define FormatDiskAddr_OneSYS BKPSRAM_BASE+2 //��������һ�����ع̼���Ҫ��ʽ�����̣��ڵ�3��
#define InportEventCancelTag BKPSRAM_BASE+3 //������¼��Ƿ�ȡ�������ַ���ڵ�4��
#define OutputStateAddrBase BKPSRAM_BASE+32 //ǰ32byte���ã������״̬�Ӵ˵�ַ��ʼ���,һ��ʹ��OutPortNum���ֽ�		 
/*************BKPSRAM END****************/


/***************CCMRAM******************/
#define CCMBaseAddr 	    0x10000000 	//CCM�ڴ����ʼ��ַ
#define CCMSize				0x10000 	//CCM�ڴ��С��64KB	 

//#define FlashBuffAddr   				CCMBaseAddr 
//#define FlashTestBuffAddr   		FlashBuffAddr+sizeof(s_usLUT)
#define FileBuffAddr    				CCMBaseAddr //FlashTestBuffAddr+sizeof(s_ucTempBuf) 
#define DicBuffAddr						FileBuffAddr+ FLASH_SECTOR_SIZE //�ֵ�ṹ�����ַ
#define ComSendBuffAddr					DicBuffAddr+sizeof(_dic)				//���ڷ��ͻ����ַ
#define ComRecvBuffAddr					ComSendBuffAddr+_comBuffLeng			//���ڽ��ջ����ַ
#define picBuffAddr						ComRecvBuffAddr+_comBuffLeng			//emWinˢͼƬ����
/***************CCMRAM END*****************/	 

#ifdef __cplusplus
}
#endif

#endif