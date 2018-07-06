#include "XBFFont.h"
#include "bsp_nand_flash.h"


char* _xbfLibName16 = "0:/Font/YAHE16.xbf";
char* _xbfLibName24 = "0:/Font/YAHE24.xbf";
char* _xbfLibName32 = "0:/Font/YAHE32.xbf";
char* _xbfLibName36 = "0:/Font/YAHE36.xbf";
char* _xbfLibName40 = "0:/Font/YAHE40.xbf";

GUI_FONT     GUI_FontYAHE16;
GUI_FONT     GUI_FontYAHE24;
GUI_FONT     GUI_FontYAHE32;
GUI_FONT     GUI_FontYAHE36;
GUI_FONT     GUI_FontYAHE40;

GUI_XBF_DATA XBF_Data16;
GUI_XBF_DATA XBF_Data24;
GUI_XBF_DATA XBF_Data32;
GUI_XBF_DATA XBF_Data36;
GUI_XBF_DATA XBF_Data40;


FRESULT result;
UINT bw;
FIL    Fontfile16;
FIL    Fontfile24;
FIL    Fontfile32;
FIL    Fontfile36;
FIL    Fontfile40;

static	FATFS fontfs;
static	FIL* FontFile16;
static	FIL* FontFile24;
static	FIL* FontFile32;
static	FIL* FontFile36;
static	FIL* FontFile40;


static int _cbGetData16(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	FontFile16 = (FIL *)pVoid;
	result =f_lseek(FontFile16, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile16, pBuffer, NumBytes, &bw);
	if (result != FR_OK) return 1; 
	return 0;
}

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
	FontFile32 = (FIL *)pVoid;
	result =f_lseek(FontFile32, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile32, pBuffer, NumBytes, &bw);
	if (result != FR_OK) return 1; 	
	return 0;
}

static int _cbGetData36(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	FontFile36 = (FIL *)pVoid;
	result =f_lseek(FontFile36, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile36, pBuffer, NumBytes, &bw);
	if (result != FR_OK) return 1; 	
	return 0;
}

static int _cbGetData40(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	FontFile40 = (FIL *)pVoid;
	result =f_lseek(FontFile40, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile40, pBuffer, NumBytes, &bw);
	if (result != FR_OK) return 1; 	
	return 0;
}


//使用XBF字体
//这两个函数要放入调用文件中（如MainTask.c）？
void UseXBF(void) 
{
	FRESULT result;
	result = f_mount(&fontfs,"0:/",0);
	
	result = f_open(&Fontfile16, _xbfLibName16, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&GUI_FontYAHE16, &XBF_Data16,GUI_XBF_TYPE_PROP_AA4_EXT,
							_cbGetData16, &Fontfile16); 
	}		
	
	result = f_open(&Fontfile24, _xbfLibName24, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&GUI_FontYAHE24, &XBF_Data24,GUI_XBF_TYPE_PROP_AA4_EXT,
							_cbGetData24, &Fontfile24); 
	}		
	
	//result = f_mount(&fontfs32,"0:/",0);
	result = f_open(&Fontfile32, _xbfLibName32, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		GUI_XBF_CreateFont(&GUI_FontYAHE32,&XBF_Data32,GUI_XBF_TYPE_PROP_AA4_EXT, 
						 _cbGetData32,&Fontfile32); 
	}	
	
	result = f_open(&Fontfile36, _xbfLibName36, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		GUI_XBF_CreateFont(&GUI_FontYAHE36,&XBF_Data36,GUI_XBF_TYPE_PROP_AA4_EXT, 
						 _cbGetData36,&Fontfile36); 
	}	
	
	result = f_open(&Fontfile40, _xbfLibName40, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		GUI_XBF_CreateFont(&GUI_FontYAHE40,&XBF_Data40,GUI_XBF_TYPE_PROP_AA4_EXT, 
						 _cbGetData40,&Fontfile40); 
	}	
	
//	f_close(&Fontfile);							
//	result  = f_mount(0, "0:/", 0);		
}
