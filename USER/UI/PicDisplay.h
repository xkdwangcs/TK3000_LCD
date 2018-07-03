#ifndef _BMPDISPLAY_H
#define _BMPDISPLAY_H

#include "stm32f4xx.h"
#include "ff.h"

//用大内存缓存方式,在指定位置显示加载到RAM中的BMP图片
void ShowBMP(char* bmpFileName,u8 mode,u32 x,u32 y,int member,int denom);
//用大内存缓存方式,在指定位置显示加载到RAM中的JPEG图片
void ShowJPEG(char* jpegFileName,u8 mode,u32 x,u32 y,int member,int denom);
// 加载到缓存的方式 显示PNG图片
void ShowPNG(char* pngFilename, u16 x0, u16 y0);
//显示GIF片
void ShowGIF(const char* gifFilename); 

void ShowBMPEx(char* bmpFileName,u8 mode,u32 x0,u32 y0,int member,int denom);
void ShowBMPEx_LeftTop(char* bmpFilename);
void ShowJPEGEx(char* jpegFileName,u8 mode,u32 x0,u32 y0,int member,int denom);
void ShowPNGEx(char* pngFilename, u16 x0, u16 y0);
void ShowGIFEx(const char* gifFilename);

//测试显示图片及字库
void TestPictureFontDisplay(void);
#endif
