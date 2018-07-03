#ifndef __LCDPARAM_H
#define __LCDPARAM_H

#include "stm32f4xx.h"
#include "stdbool.h"


//LCD相关参数的结构体
typedef struct
{      
    u8 ucBackLight;				//LCD背光亮度
    u8 TouchDirection;			//屏幕方向 0-3  0表示横屏，1表示横屏180° 2表示竖屏 3表示竖屏180°
    u8 XYChange;				//X, Y 是否交换， 1表示i切换，0表示不切换
	
    u16 usAdcX1;				//左上角
    u16 usAdcY1;
    u16 usAdcX2;				//右下角
    u16 usAdcY2;
    u16 usAdcX3;				//左下角
    u16 usAdcY3;
    u16 usAdcX4;				//右上角
    u16 usAdcY4;

	//校准时，屏幕坐标
    u16 usLcdX1;		
    u16 usLcdY1;
    u16 usLcdX2;
    u16 usLcdY2;
    u16 usLcdX3;
    u16 usLcdY3;
    u16 usLcdX4;
    u16 usLcdY4;	
	
	char ParaVer[7];			//参数版本，用于自动升级参数扇区 
	
} LcdParaStruct;

extern bool _isTouchCalibration;
//LCD参数实例
extern LcdParaStruct g_tParam;

//从Flash中读取LCD相关校准参数到内存
void LoadLcdPara(void);
//将LCD相关校准参数保存到Flash
void SaveLcdPara(void);

#endif
