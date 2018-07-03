#include "LCDPara.h"
//#include "SPIFlashBase.h"
#include "PublicFunction.h"
#include "FileOperate.h"

char* _lcdFileName="0:/CFG/LCDPara.cfg";
bool _isTouchCalibration=false;
//LCD参数实例
LcdParaStruct g_tParam;
//触摸参数保存的扇区
//u16 _lcdParaSection=FLASH_SECTOR_COUNT+9;
char* _verStr="ver1.00";

//从Flash中读取LCD相关校准参数到内存
void LoadLcdPara(void)
{
	_isTouchCalibration=false;
	//ReadBytesSPIFlash(_lcdParaSection,(u8 *)&g_tParam,0,sizeof(g_tParam));
	if(CreateFileOnDisk(_lcdFileName,false)!=FR_EXIST)//如果文件原来不存在
    { 		
				WriteBytesToFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));  
    }
		ReadBytesFormFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));
	//如果版本标志不对，则填充缺省参数
	if(!StrCMP_n(_verStr,g_tParam.ParaVer,7))
	{
		memset(&g_tParam,0,sizeof(g_tParam));		
		g_tParam.ucBackLight = 200;
		g_tParam.TouchDirection = 0;			//保存横屏校准参数
		_isTouchCalibration=true;
		//SaveLcdPara();						//将新参数写入Flash
	}
}

//将LCD相关校准参数保存到Flash
void SaveLcdPara(void)
{
		strcpy(g_tParam.ParaVer,_verStr); 
		//WriteBytesSPIFlash(_lcdParaSection,(u8*)&g_tParam,sizeof(g_tParam));
		CreateFileOnDisk(_lcdFileName,false);
		WriteBytesToFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));  
}
