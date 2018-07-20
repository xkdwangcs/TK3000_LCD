#include "XBFFont.h"
#include "bsp_nand_flash.h"


char* _xbfLibName14 = "0:/Font/YAHE14.xbf";
char* _xbfLibName18 = "0:/Font/YAHE18.xbf";
char* _xbfLibName24 = "0:/Font/YAHE24.xbf";
char* _xbfLibName32 = "0:/Font/YAHE32.xbf";

GUI_FONT     GUI_FontYAHE14;
GUI_FONT     GUI_FontYAHE18;
GUI_FONT     GUI_FontYAHE24;
GUI_FONT     GUI_FontYAHE32;

GUI_XBF_DATA XBF_Data14;
GUI_XBF_DATA XBF_Data18;
GUI_XBF_DATA XBF_Data24;
GUI_XBF_DATA XBF_Data32;


FRESULT result;
UINT bw;
FIL    Fontfile14;
FIL    Fontfile18;
FIL    Fontfile24;
FIL    Fontfile32;

static	FATFS fontfs;
static	FIL* FontFile14;
static	FIL* FontFile18;
static	FIL* FontFile24;
static	FIL* FontFile32;


static int _cbGetData14(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	FontFile14 = (FIL *)pVoid;
	result =f_lseek(FontFile14, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile14, pBuffer, NumBytes, &bw);
	if (result != FR_OK) return 1; 
	return 0;
}

static int _cbGetData18(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	FontFile18 = (FIL *)pVoid;
	result =f_lseek(FontFile18, Off);
	if (result != FR_OK) return 1;
	result = f_read(FontFile18, pBuffer, NumBytes, &bw);
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

//初始化XBF字体
void IniXBF(void) 
{
	FRESULT result;
	//result = f_mount(&fontfs,"0:/",0);
	
	result = f_open(&Fontfile14, _xbfLibName14, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&GUI_FontYAHE14, &XBF_Data14,GUI_XBF_TYPE_PROP_AA4_EXT,
							_cbGetData14, &Fontfile14); 
	}		
	
	result = f_open(&Fontfile18, _xbfLibName18, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
		GUI_XBF_CreateFont(&GUI_FontYAHE18, &XBF_Data18,GUI_XBF_TYPE_PROP_AA4_EXT,
							_cbGetData18, &Fontfile18); 
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
	
//	f_close(&Fontfile);							
//	result  = f_mount(0, "0:/", 0);		
}
