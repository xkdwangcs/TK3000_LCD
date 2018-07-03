/*
*********************************************************************************************************
*
*	模块名称 : 外部SRAM驱动模块
*	文件名称 : bsp_fsmc_sram.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*	修改记录 :
*		版本号  日期       作者    说明
*		v1.0    2012-10-12 armfly  ST固件库版本 V2.1.0
*
*	Copyright (C), 2012-2013, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef _BSP_FSMC_SRAM_H
#define _BSP_FSMC_SRAM_H

#include "stm32f4xx_it.h"

#define EXT_SRAM_ADDR  	((uint32_t)0x68000000)
#define EXT_SRAM_SIZE	(2 * 1024 * 1024)

void bsp_InitExtSRAM(void);
uint8_t bsp_TestExtSRAM(void);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
