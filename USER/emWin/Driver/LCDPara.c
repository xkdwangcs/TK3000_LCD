#include "LCDPara.h"
//#include "SPIFlashBase.h"
#include "PublicFunction.h"
#include "FileOperate.h"

char* _lcdFileName="0:/CFG/LCDPara.cfg";
bool _isTouchCalibration=false;
//LCD����ʵ��
LcdParaStruct g_tParam;
//�����������������
//u16 _lcdParaSection=FLASH_SECTOR_COUNT+9;
char* _verStr="ver1.00";

//��Flash�ж�ȡLCD���У׼�������ڴ�
void LoadLcdPara(void)
{
	_isTouchCalibration=false;
	//ReadBytesSPIFlash(_lcdParaSection,(u8 *)&g_tParam,0,sizeof(g_tParam));
	if(CreateFileOnDisk(_lcdFileName,false)!=FR_EXIST)//����ļ�ԭ��������
    { 		
				WriteBytesToFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));  
    }
		ReadBytesFormFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));
	//����汾��־���ԣ������ȱʡ����
	if(!StrCMP_n(_verStr,g_tParam.ParaVer,7))
	{
		memset(&g_tParam,0,sizeof(g_tParam));		
		g_tParam.ucBackLight = 200;
		g_tParam.TouchDirection = 0;			//�������У׼����
		_isTouchCalibration=true;
		//SaveLcdPara();						//���²���д��Flash
	}
}

//��LCD���У׼�������浽Flash
void SaveLcdPara(void)
{
		strcpy(g_tParam.ParaVer,_verStr); 
		//WriteBytesSPIFlash(_lcdParaSection,(u8*)&g_tParam,sizeof(g_tParam));
		CreateFileOnDisk(_lcdFileName,false);
		WriteBytesToFile(_lcdFileName,(u8*) &g_tParam,0,sizeof(g_tParam));  
}
