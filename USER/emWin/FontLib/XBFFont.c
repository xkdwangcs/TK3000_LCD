#include "XBFFont.h"
#include "bsp_nand_flash.h"

char* _xbfLibName = "0:/Font/YAHE24.xbf";
char* _xbfLibName32 = "0:/Font/YAHE32.xbf";


GUI_XBF_DATA XBF_Data24;
GUI_FONT     XBF_Font24;

GUI_XBF_DATA XBF_Data32;
GUI_FONT     XBF_Font32;


FRESULT result;
UINT bw;
FIL    Fontfile24;
FIL    Fontfile32;

static	FATFS fontfs24;
static	FIL* FontFile24;

static	FATFS fontfs32;
static	FIL* FontFile32;

static int _cbGetData24(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	/* 文件句柄 */
	FontFile24 = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile24, Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile24, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}
	
	return 0;

}

static int _cbGetData32(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	/* 文件句柄 */
	FontFile32 = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile32, Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile32, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}
	
	return 0;

}


//使用XBF字体
//这两个函数要放入调用文件中（如MainTask.c）？
void UseXBF(void) 
{
	FRESULT result;
	result = f_mount(&fontfs24,"0:/",0);
	result = f_open(&Fontfile24, _xbfLibName, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&XBF_Font24,       
						 &XBF_Data24,        
						 GUI_XBF_TYPE_PROP_AA4_EXT, 
						 _cbGetData24,      
						 &Fontfile24); 

	}		
	
	//result = f_mount(&fontfs32,"0:/",0);
	result = f_open(&Fontfile32, _xbfLibName32, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&XBF_Font32,       
						 &XBF_Data32,        
						 GUI_XBF_TYPE_PROP_AA4_EXT, 
						 _cbGetData32,      
						 &Fontfile32); 

	}		
//	f_close(&Fontfile);							
//	result  = f_mount(0, "0:/", 0);		
}
