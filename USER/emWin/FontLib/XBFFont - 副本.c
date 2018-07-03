#include "XBFFont.h"
#include "bsp_nand_flash.h"

char* _xbfLibName = "0:/Font/XYQFont.bin";
/* 雅黑16点阵定义 */
#define   XBF_Font16BaseAdd    0x00000000
GUI_XBF_DATA XBF_Data16;
GUI_FONT     XBF_Font16;
void         *Fontfile16;

/* 雅黑24点阵定义 */
#define   XBF_Font24BaseAdd    0x0020A507
GUI_XBF_DATA XBF_Data24;
GUI_FONT     XBF_Font24;
void         *Fontfile24;

/* 雅黑32点阵定义 */
#define   XBF_Font32BaseAdd    0x006CB629
GUI_XBF_DATA XBF_Data32;
GUI_FONT     XBF_Font32;
void         *Fontfile32;

/* 雅黑36点阵定义 */
#define   XBF_Font36BaseAdd    0x00F69C43
GUI_XBF_DATA XBF_Data36;
GUI_FONT     XBF_Font36;
void         *Fontfile36;

/* 雅黑40点阵定义 */
#define   XBF_Font40BaseAdd    0x01A00477
GUI_XBF_DATA XBF_Data40;
GUI_FONT     XBF_Font40;
void         *Fontfile40;

GUI_FONT     XBF_Font;
GUI_XBF_DATA XBF_Data;
FIL          Fontfile;
FRESULT result;
UINT bw;
static	FATFS fontfs;
static	FIL* FontFile;


static int _cbGetData16(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{	
	/* 读取点阵数据 */
	//sf_ReadBuffer(pBuffer, XBF_Font16BaseAdd + Off, NumBytes);
//	NAND_Read(XBF_Font16BaseAdd + Off,pBuffer, NumBytes);
//	return 0;
		/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, XBF_Font16BaseAdd + Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}	
	return 0;
}

static int _cbGetData24(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{	
	/* 读取点阵数据 */
	//sf_ReadBuffer(pBuffer, XBF_Font24BaseAdd + Off, NumBytes);
//	NAND_Read(XBF_Font24BaseAdd + Off,pBuffer, NumBytes);
//	return 0;
	
		/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, XBF_Font24BaseAdd + Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}	
	return 0;
}

static int _cbGetData32(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{	
	/* 读取点阵数据 */
	//sf_ReadBuffer(pBuffer, XBF_Font32BaseAdd + Off, NumBytes);
//	NAND_Read(XBF_Font32BaseAdd + Off,pBuffer, NumBytes);
//	return 0;
	
		/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, XBF_Font32BaseAdd + Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}	
	return 0;
}

static int _cbGetData36(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{	
	/* 读取点阵数据 */
	//sf_ReadBuffer(pBuffer, XBF_Font36BaseAdd + Off, NumBytes);
//	NAND_Read(XBF_Font36BaseAdd + Off,pBuffer, NumBytes);
//	return 0;
	
		/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, XBF_Font36BaseAdd + Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}	
	return 0;
}

static int _cbGetData40(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{	
	/* 读取点阵数据 */
	//sf_ReadBuffer(pBuffer, XBF_Font40BaseAdd + Off, NumBytes);
//	NAND_Read(XBF_Font40BaseAdd + Off,pBuffer, NumBytes);
//	return 0;
	
		/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, XBF_Font40BaseAdd + Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
	if (result != FR_OK) 
	{
		return 1; 
	}	
	return 0;
}

/*
*********************************************************************************************************
*	函 数 名: GUI_SetXBF
*	功能说明: 创建XBF字体
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void GUI_SetXBF(void) 
{

	/* 创建16点阵字体 */
	GUI_XBF_CreateFont(&XBF_Font16,        /* GUI_FONT类型变量     */
					 &XBF_Data16,          /* GUI_XBF_DATA类型变量 */
					 //GUI_XBF_TYPE_PROP,    /* 字体类型             */
						GUI_XBF_TYPE_PROP_AA4_EXT,
					 _cbGetData16,         /* 回调函数             */
					 &Fontfile16);         /* 回调函数参数         */
	
	/* 创建24点阵字体 */
	GUI_XBF_CreateFont(&XBF_Font24,        /* GUI_FONT类型变量     */
					 &XBF_Data24,          /* GUI_XBF_DATA类型变量 */
					 GUI_XBF_TYPE_PROP_AA4_EXT,           
					 _cbGetData24,         /* 回调函数             */
					 &Fontfile24);         /* 回调函数参数         */
	
	/* 创建32点阵字体 */
	GUI_XBF_CreateFont(&XBF_Font32,        /* GUI_FONT类型变量     */
					 &XBF_Data32,          /* GUI_XBF_DATA类型变量 */
					 GUI_XBF_TYPE_PROP_AA4_EXT,    /* 字体类型             */
					 _cbGetData32,         /* 回调函数             */
					 &Fontfile32);         /* 回调函数参数         */
					 
					 	/* 创建36点阵字体 */
	GUI_XBF_CreateFont(&XBF_Font36,        /* GUI_FONT类型变量     */
					 &XBF_Data36,          /* GUI_XBF_DATA类型变量 */
					 GUI_XBF_TYPE_PROP_AA4_EXT,    /* 字体类型             */
					 _cbGetData36,         /* 回调函数             */
					 &Fontfile36);         /* 回调函数参数         */
					 
					 	/* 创建40点阵字体 */
	GUI_XBF_CreateFont(&XBF_Font40,        /* GUI_FONT类型变量     */
					 &XBF_Data40,          /* GUI_XBF_DATA类型变量 */
					 GUI_XBF_TYPE_PROP_AA4_EXT,    /* 字体类型             */
					 _cbGetData40,         /* 回调函数             */
					 &Fontfile40);         /* 回调函数参数         */
}

static int _cbGetData(U32 Off, U16 NumBytes, void * pVoid, void * pBuffer)
{
	/* 文件句柄 */
	FontFile = (FIL *)pVoid;
	/*
	* 指向数据地址
	*/
	result =f_lseek(FontFile, Off);
	if (result != FR_OK) 
	{
		return 1;
	}
	/*
	* 读取数据到buffer
	*/
	result = f_read(FontFile, pBuffer, NumBytes, &bw);
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
	result = f_mount(&fontfs,"0:/",0);
	result = f_open(&Fontfile, _xbfLibName, FA_OPEN_EXISTING | FA_READ | FA_OPEN_ALWAYS);
	if (result == FR_OK)
	{
		/* 创建XBF字体 */
//		GUI_XBF_CreateFont(&XBF_Font,       
//						 &XBF_Data,        
//						 GUI_XBF_TYPE_PROP_AA4_EXT, 
//						 _cbGetData,      
//						 &Fontfile); 
		
		GUI_SetXBF();
	}		
//	f_close(&Fontfile);							
//	result  = f_mount(0, "0:/", 0);		
}
