#include "PicDisplay.h"
#include "GUI.h"
#include "Delay.h"
#include "bsp_tft_lcd.h"
#include "XBFFont.h"
#include "MemoryAlloc.h"

static FIL _picFile; 
//行显示模式缓存。实际的测试需要是图像宽度的4倍即可，切记(也就是保证每个像素如果是32位数据的情况)
static char _picBuffer[800*4] __at(picBuffAddr);
char* _disk="0:/"; //默认盘符（SPI Flash），也可以根据文件名得出盘符

//从文件读取图片数据
static int GetPicData(void* p, const U8** ppData, unsigned NumBytesReq, U32 Off) 
{
	static int readaddress=0;
	FIL * phFile;
	UINT NumBytesRead;	
	phFile = (FIL *)p;	
	if (NumBytesReq > sizeof(_picBuffer)) 
	{
		NumBytesReq = sizeof(_picBuffer);
	}
	//移动指针到应该读取的位置
	if(Off == 1) 
		readaddress = 0;
	else 
		readaddress=Off;
	f_lseek(phFile,readaddress); 	
	//读取数据到缓冲区中
	f_read(phFile,_picBuffer,NumBytesReq,&NumBytesRead);
	*ppData = (u8*)_picBuffer;
	return NumBytesRead;//返回读取到的字节数
}

/*************************************************************/
//在指定位置显示加载到RAM中的BMP图片
//BMPFileName:图片在SD卡或者其他存储设备中的路径(需文件系统支持！)
//mode:显示模式
//		0 在指定位置显示，由参数x,y确定显示位置
//		1 在LCD中间显示图片，当选择此模式的时候参数x,y无效。
//x:图片左上角在LCD中的x轴位置(当参数mode为1时，此参数无效)
//y:图片左上角在LCD中的y轴位置(当参数mode为1时，此参数无效)
//member:  缩放比例的分子项
//denom:缩放比例的分母项
//返回值:0 显示正常,其他 失败
void ShowBMP(char* bmpFileName,u8 mode,u32 x,u32 y,int member,int denom)
{
	FATFS fs;
	FRESULT result;
	u32 br;
	int XSize, YSize;
	float Xflag,Yflag;
	GUI_HMEM hMem;
	char* picBuffer;
	
	//result = f_mount(&fs,_disk,0);
	result = f_open(&_picFile, bmpFileName, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result != FR_OK)
	{
		return;
	}
	u32 picSize=_picFile.obj.objsize;
	// 申请一块内存空间 并且将其清零 
  hMem = GUI_ALLOC_AllocZero(picSize);//(1024*1024);
	/* 将申请到内存的句柄转换成指针类型 */
	picBuffer = GUI_ALLOC_h2p(hMem);
	/* 读取图片到缓冲中 */
	result = f_read(&_picFile, picBuffer, picSize, &br);
  if (result == FR_OK)
  {	
		switch(mode)
		{
			case 0:	//在指定位置显示图片
				if((member == 1) && (denom == 1)) //无需缩放，直接绘制
				{
					GUI_BMP_Draw(picBuffer,x,y);	//在指定位置显示BMP图片
				}
				else //否则图片需要缩放
				{
					GUI_BMP_DrawScaled(picBuffer,x,y,member,denom);
				}
				break;
			case 1:	//在LCD中间显示图片
				XSize = GUI_BMP_GetXSize(picBuffer);	//获取图片的X轴大小
				YSize = GUI_BMP_GetYSize(picBuffer);	//获取图片的Y轴大小
				if((member == 1) && (denom == 1)) //无需缩放，直接绘制
				{
					//在LCD中间显示图片
					GUI_BMP_Draw(picBuffer,(g_LcdWidth-XSize)/2-1,(g_LcdHeight-YSize)/2-1);
				}
				else //否则图片需要缩放
				{
					Xflag = (float)XSize*((float)member/(float)denom);
					Yflag = (float)YSize*((float)member/(float)denom);
					XSize = (g_LcdWidth-(int)Xflag)/2-1;
					YSize = (g_LcdHeight-(int)Yflag)/2-1;
					GUI_BMP_DrawScaled(picBuffer,XSize,YSize,member,denom);
				}
				break;
		}
	}
	GUI_ALLOC_Free(hMem);							//释放内存
	f_close(&_picFile);								//关闭BMPFile文件
	//result  = f_mount(0, _disk, 0);		
}

//在指定位置显示无需加载到RAM中的BMP图片(需文件系统支持！对于小RAM，推荐使用此方法！)
//BMPFileName:图片在SD卡或者其他存储设备中的路径
//mode:显示模式
//		0 在指定位置显示，有参数x,y确定显示位置
//		1 在LCD中间显示图片，当选择此模式的时候参数x,y无效。
//x:图片左上角在LCD中的x轴位置(当参数mode为1时，此参数无效)
//y:图片左上角在LCD中的y轴位置(当参数mode为1时，此参数无效)
//member:  缩放比例的分子项
//denom:缩放比例的分母项
void ShowBMPEx(char* bmpFileName,u8 mode,u32 x0,u32 y0,int member,int denom)
{
	//FATFS fs;
	FRESULT result;
	int XSize,YSize;
	float Xflag,Yflag;	
	//result = f_mount(&fs,_disk,0);
	result = f_open(&_picFile,(const TCHAR*)bmpFileName,FA_READ);	//打开文件
	//文件打开错误
	if(result != FR_OK) 	
		return;		
	switch(mode)
	{
		case 0:	//在指定位置显示图片
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				GUI_BMP_DrawEx(GetPicData,&_picFile,x0,y0);//在指定位置显示BMP图片
			}
			else //否则图片需要缩放
			{
				GUI_BMP_DrawScaledEx(GetPicData,&_picFile,x0,y0,member,denom);
			}
			break;
		case 1:	//在LCD中间显示图片
			XSize = GUI_BMP_GetXSizeEx(GetPicData,&_picFile);	//获取图片的X轴大小
			YSize = GUI_BMP_GetYSizeEx(GetPicData,&_picFile);	//获取图片的Y轴大小
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				//在LCD中间显示图片
				GUI_BMP_DrawEx(GetPicData,&_picFile,(g_LcdWidth-XSize)/2-1,(g_LcdHeight-YSize)/2-1);
			}
			else //否则图片需要缩放
			{
				Xflag = (float)XSize*((float)member/(float)denom);
				Yflag = (float)YSize*((float)member/(float)denom);
				XSize = (g_LcdHeight-(int)Xflag)/2-1;
				YSize = (g_LcdWidth-(int)Yflag)/2-1;
				GUI_BMP_DrawScaledEx(GetPicData,&_picFile,XSize,YSize,member,denom);
			}
			break;
	}
	result  = f_close(&_picFile);		//关闭BMPFile文件
	//result  = f_mount(0, _disk, 0);
}

//左上角开始画图，无缩放
void ShowBMPEx_LeftTop(char * bmpFilename) 
{	
	ShowBMPEx(bmpFilename,0,0,0,1,1);
}

/***************************************************************************/

//在指定位置显示加载到RAM中的JPEG图片
//JPEGFileName:图片在SD卡或者其他存储设备中的路径(需文件系统支持！)
//mode:显示模式
//		0 在指定位置显示，有参数x,y确定显示位置
//		1 在LCD中间显示图片，当选择此模式的时候参数x,y无效。
//x:图片左上角在LCD中的x轴位置(当参数mode为1时，此参数无效)
//y:图片左上角在LCD中的y轴位置(当参数mode为1时，此参数无效)
//member:  缩放比例的分子项
//denom:缩放比例的分母项
void ShowJPEG(char* jpegFileName,u8 mode,u32 x,u32 y,int member,int denom)
{
	FATFS fs;
	FRESULT result;
	u32 br;
	int XSize, YSize;
	float Xflag,Yflag;
	GUI_HMEM hMem;
	char* picBuffer;
	GUI_JPEG_INFO JpegInfo;
	
	//result = f_mount(&fs,_disk,0);
	result = f_open(&_picFile, jpegFileName, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result != FR_OK)
	{
		return;
	}
	u32 picSize=_picFile.obj.objsize;
	// 申请一块内存空间 并且将其清零 
    hMem = GUI_ALLOC_AllocZero(picSize);//(1024*512);
	// 将申请到内存的句柄转换成指针类型 
	picBuffer = GUI_ALLOC_h2p(hMem);
	// 读取图片到缓冲中
	result = f_read(&_picFile, picBuffer, picSize, &br);
	
	GUI_JPEG_GetInfo(picBuffer,picSize,&JpegInfo); //获取JEGP图片信息
	XSize = JpegInfo.XSize;	//获取JPEG图片的X轴大小
	YSize = JpegInfo.YSize;	//获取JPEG图片的Y轴大小
	switch(mode)
	{
		case 0:	//在指定位置显示图片
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				GUI_JPEG_Draw(picBuffer,picSize,x,y);	//在指定位置显示JPEG图片
			}
			else //否则图片需要缩放
			{
				GUI_JPEG_DrawScaled(picBuffer,picSize,x,y,member,denom);
			}
			break;
		case 1:	//在LCD中间显示图片
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				//在LCD中间显示图片
				GUI_JPEG_Draw(picBuffer,picSize,(g_LcdWidth-XSize)/2-1,(g_LcdHeight-YSize)/2-1);
			}
			else //否则图片需要缩放
			{
				Xflag = (float)XSize*((float)member/(float)denom);
				Yflag = (float)YSize*((float)member/(float)denom);
				XSize = (g_LcdWidth-(int)Xflag)/2-1;
				YSize = (g_LcdHeight-(int)Yflag)/2-1;
				GUI_JPEG_DrawScaled(picBuffer,picSize,XSize,YSize,member,denom);
			}
			break;
	}
	GUI_ALLOC_Free(hMem);							//释放内存
	result  = f_close(&_picFile);		//关闭文件
	//result  = f_mount(0, _disk, 0);
}


//在指定位置显示无需加载到RAM中的BMP图片(需文件系统支持！对于小RAM，推荐使用此方法！)
//JPEGFileName:图片在SD卡或者其他存储设备中的路径
//mode:显示模式
//		0 在指定位置显示，有参数x,y确定显示位置
//		1 在LCD中间显示图片，当选择此模式的时候参数x,y无效。
//x:图片左上角在LCD中的x轴位置(当参数mode为1时，此参数无效)
//y:图片左上角在LCD中的y轴位置(当参数mode为1时，此参数无效)
//member:  缩放比例的分子项
//denom:缩放比例的分母项
void ShowJPEGEx(char* jpegFileName,u8 mode,u32 x0,u32 y0,int member,int denom)
{
	FATFS fs;
	FRESULT result;
	int XSize,YSize;
	float Xflag,Yflag;
	GUI_JPEG_INFO JpegInfo;
	
	//result = f_mount(&fs,_disk,0);
	result = f_open(&_picFile,(const TCHAR*)jpegFileName,FA_READ);	//打开文件
	//文件打开错误
	if(result != FR_OK) 
		return;	
	GUI_JPEG_GetInfoEx(GetPicData,&_picFile,&JpegInfo);
	XSize = JpegInfo.XSize;	//JPEG图片X大小
	YSize = JpegInfo.YSize;	//JPEG图片Y大小
	int v=0;
	switch(mode)
	{
		case 0:	//在指定位置显示图片
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				v = GUI_JPEG_DrawEx(GetPicData,&_picFile,x0,y0);//在指定位置显示BMP图片
			}
			else //否则图片需要缩放
			{
				v = GUI_JPEG_DrawScaledEx(GetPicData,&_picFile,x0,y0,member,denom);
			}
			break;
		case 1:	//在LCD中间显示图片
			if((member == 1) && (denom == 1)) //无需缩放，直接绘制
			{
				//在LCD中间显示图片
				v = GUI_JPEG_DrawEx(GetPicData,&_picFile,(g_LcdWidth-XSize)/2-1,(g_LcdHeight-YSize)/2-1);
			}
			else //否则图片需要缩放
			{
				Xflag = (float)XSize*((float)member/(float)denom);
				Yflag = (float)YSize*((float)member/(float)denom);
				XSize = (g_LcdWidth-(int)Xflag)/2-1;
				YSize = (g_LcdHeight-(int)Yflag)/2-1;
				GUI_JPEG_DrawScaledEx(GetPicData,&_picFile,XSize,YSize,member,denom);			
			}
			break;
	}
	result  = f_close(&_picFile);		//关闭文件
	//result  = f_mount(0, _disk, 0);
}	

/****************************************************************/

//加载到缓存的方式 显示PNG图片
void ShowPNG(char* pngFilename, u16 x0, u16 y0) 
{
		FATFS fs;
		FRESULT result;
		u32 re;
		GUI_HMEM hMem;
		char* picBuff;
		
		//result = f_mount(&fs,_disk,0);	
		result = f_open(&_picFile, pngFilename, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
		if (result != FR_OK)
		{
			return;
		}
		//申请一块内存空间 并且将其清零
		u32 picSize=_picFile.obj.objsize;
		hMem = GUI_ALLOC_AllocZero(picSize); //安富莱的是500000
		//将申请到内存的句柄转换成指针类型
		picBuff = GUI_ALLOC_h2p(hMem);
		//加载图标到动态内存
		result = f_read(&_picFile, picBuff, picSize, &re);
  	if (result == FR_OK)
  	{
			//显示PNG图标
			GUI_PNG_Draw(picBuff, picSize, x0, y0);
		}
		GUI_ALLOC_Free(hMem);
		f_close(&_picFile);
		//result  = f_mount(0, _disk, 0);
}

//行显示PNG图片时，获取数据的回调函数
int GetPNGPicData(void * p, const U8 ** ppData, unsigned NumBytesReq, U32 Off) 
{
	static int fileAddress = 0;
	FIL* file;
	UINT NumBytesRead;
	FRESULT result;
	U8* pData;
	pData  = (u8*)*ppData;
	file = (FIL*)p;
	if(Off == 1)
		fileAddress = 0;
	else fileAddress = Off;
	result =f_lseek(file, fileAddress);	
	result = f_read(file, pData, NumBytesReq, &NumBytesRead);
	return NumBytesRead;
}

//显示PNG图片
void ShowPNGEx(char* pngFilename, u16 x0, u16 y0) 
{	
	FATFS fs;
	FRESULT result;
	int v=0;
	//result = f_mount(&fs,_disk,0);	
	result = f_open(&_picFile, pngFilename, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result != FR_OK)
	{
		return;
	}	
	v = GUI_PNG_DrawEx(GetPNGPicData, &_picFile, x0, y0);
	result  = f_close(&_picFile);
	//result  = f_mount(0, _disk, 0);
}

/*****************************************************/

//显示GIF片
void ShowGIF(const char* gifFilename) 
{
	FATFS fs;
	FRESULT result;
	GUI_HMEM hMem;
	char* picBuff;
	uint8_t i = 0;
	u32 re;
	GUI_GIF_INFO InfoGif1;
	GUI_GIF_IMAGE_INFO InfoGif2;
	
	//result = f_mount(&fs,_disk,0);		
	result = f_open(&_picFile, gifFilename, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result != FR_OK)
	{
		return;
	}
	u32 picSize=_picFile.obj.objsize;
	// 申请一块内存空间 并且将其清零
    hMem = GUI_ALLOC_AllocZero(picSize);//(1024*1024);
	//将申请到内存的句柄转换成指针类型
	picBuff = GUI_ALLOC_h2p(hMem);
	result = f_read(&_picFile, picBuff,picSize, &re);
  	if (result != FR_OK)
  	{
		return;
  	}	
   GUI_GIF_GetInfo(picBuff, picSize, &InfoGif1);   
   while(1)
   {
		if(i < InfoGif1.NumImages)
	    {
	        GUI_GIF_GetImageInfo(picBuff, picSize, &InfoGif2, i);
	        GUI_GIF_DrawSub(picBuff, picSize,
			                (LCD_GetXSize() - InfoGif1.xSize)/2,
											(LCD_GetYSize() - InfoGif1.ySize)/2, 
			                i++);
			
            /* 可以选择放大显示 */			
// 			GUI_GIF_DrawSubScaled(_acBuffer2, 
// 			                      file.fsize, 
// 			                      (LCD_GetXSize() - InfoGif1.xSize*3)/2,
// 							      				(LCD_GetYSize() - InfoGif1.ySize*3)/2, 
// 			                      i++,
// 			                      3, 1);			
				GUI_X_Delay(InfoGif2.Delay*10);					  
	    }
	    else
	    {
	        i = 0;
	    }
	}
		GUI_ALLOC_Free(hMem);
		f_close(&_picFile);
		//result  = f_mount(0, _disk, 0);
}

//GIF图片显示
void ShowGIFEx(const char* gifFilename) 
{	
	uint8_t i;
	FATFS fs;
	FRESULT result;
	GUI_GIF_INFO InfoGif1;
	GUI_GIF_IMAGE_INFO InfoGif2;
	result = f_mount(&fs,_disk,0);	
	result = f_open(&_picFile, gifFilename, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result != FR_OK)
	{
		return;
	}
	GUI_GIF_GetInfoEx(GetPicData, &_picFile,&InfoGif1);

	while(1)
	{
		if(i < InfoGif1.NumImages)
	    {	
	        GUI_GIF_GetImageInfoEx(GetPicData, &_picFile, &InfoGif2, i );
	        GUI_GIF_DrawSubEx(GetPicData, &_picFile, 
			                  (LCD_GetXSize() - InfoGif1.xSize)/2,
												(LCD_GetYSize() - InfoGif1.ySize)/2, 
			                  i++);			
					GUI_X_Delay(InfoGif2.Delay*10);					 
	    }
	    else
	    {
	        i = 0;
	    }
	}
		result  = f_close(&_picFile);
		result  = f_mount(0, _disk, 0);
}

void TestPictureFontDisplay(void)
{
	GUI_SetBkColor(GUI_BLUE);
	GUI_SetColor(GUI_RED);
	//GUI_SetFont(&GUI_Font24_ASCII);
	//XBF字库的使用
//	UseXBF();
	GUI_UC_SetEncodeUTF8();
	GUI_SetFont(&GUI_FontYAHE32);	
	GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
	//GUI_Clear();
	
	while(1)
	{
//		ShowGIF("0:/Pic/4.gif");
//		GUI_Delay(1000);
//		GUI_Clear();	
		

		ShowBMPEx_LeftTop("0:/Pic/1.bmp");
		GUI_DispStringHCenterAt("OK,Very good!",200,50);
		GUI_Delay(1000);
		GUI_Clear();	
		
		ShowJPEG("0:/Pic/001.jpg",0,0,0,1,1);
		GUI_Delay(1000);
		GUI_Clear();	
		
		ShowJPEGEx("0:/Pic/001.jpg",0,0,0,1,1);
		GUI_Delay(1000);
		GUI_Clear();
		
		char* bmpFileName="0:/Pic/1.bmp";
		GUI_DispStringHCenterAt("在指定位置显示一张无需加载的BMP图片",200,50);
		ShowBMPEx(bmpFileName,0,10,	78,	1,1);
		GUI_Delay(1000);
		GUI_Clear();	
			
		ShowBMPEx(bmpFileName,1,0,	0,	1,2);
        GUI_DispStringHCenterAt("在LCD中间显示一张缩小1/2的无需加载的BMP图片",400,50);
		GUI_Delay(1000);
		GUI_Clear();
			
            GUI_DispStringHCenterAt("放在图片显示之前不行",400,50);
		ShowBMPEx(bmpFileName,1,0,	0,	4,3);
		GUI_Delay(1000);
		GUI_Clear();		
				
		ShowJPEGEx("0:/Pic/001.jpg",1,0,0,2,1);
        GUI_DispStringHCenterAt("在LCD中间显示一张扩大2倍的无需加载的JPEG图片",240,50);
		GUI_Delay(1000);
		GUI_Clear();
			
		ShowJPEGEx("0:/Pic/002.jpg",1,0,0,1,2);
        GUI_DispStringHCenterAt("在LCD中间显示一张缩小1/2的无需加载的JPEG图片",240,10);
		GUI_Delay(1000);
		GUI_Clear();        
    
        ShowJPEGEx("0:/Pic/003.jpg",1,0,0,1,1);
        GUI_DispStringHCenterAt("在LCD中间显示一张缩小1/4的无需加载的JPEG图片",240,20);
		GUI_Delay(1000);
		GUI_Clear();
		
		ShowJPEGEx("0:/Pic/Welcome.jpg",1,0,0,1,1);
		GUI_Delay(1000);
		GUI_Clear();
		
		ShowPNG("0:/Pic/1.png",0,0);
		GUI_Delay(1000);
		GUI_Clear();
		
		ShowPNGEx("0:/Pic/1.png",0,100);
		GUI_Delay(1000);
		GUI_Clear();
	}
}
