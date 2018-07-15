#include "CMD.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "SysTick_Timer.h"


//当前使用的串口号
USART_TypeDef *currUSART = USART1;
StatusParaStruct currStatus;

//RDD相关命令的处理
void RDDProcess(void)
{  
	
}

//WRT相关命令的处理
void WRTProcess(void)
{

}


extern WM_HWIN CreateMsgBox_Nobt();
extern WM_HWIN CreateMsgBox();
extern void ShowMsg(char* msg);
extern void ShowMsg_NoBt(char* msg);

//SRQ相关命令的处理
void SRQProcess(void)
{
	if (StrCMP(_cmdRecvBuff.CmdName, "CURRSTATUS")) //状态主动上送
	{
		u8 count=0;
		currStatus.DevStatus=NoGetStatus;
		LIST* ls=GetLIST((char*)_cmdRecvBuff.CmdData,&count);
		currStatus.DevStatus=ConvertAsciiTou32(ls[0].item);		
		strcpy(currStatus.StatusDescribe,ls[1].item);		
		switch(currStatus.DevStatus)
		{
			case DeviceIniting: //设备初始化中,屏幕也重启
                __disable_fault_irq(); 
                NVIC_SystemReset();
				break;					
			case DevWorking: //设备正在工作
									
				break;
			case DevScram: //急停中
				ShowMessageBox_NoBut("设备已急停，请弹出【急停按钮】再继续！");
                //CreateMessageBox_NoBtn();
				break;
			case USBInsert: //USB已插入
				//ShowUSBForm();
				break;
			default:
				break;
		}
	}
	
	
//	if (StrCMP(_cmdRecvBuff.CmdName, "USBFunc_Ctr")) //控制板上USB相关功能窗体
//	  {		
//		  CreateUSBFunc_Ctr();
//	  }
//	  else if (StrCMP(_cmdRecvBuff.CmdName, "SysResetForm")) //系统复位窗体
//	  {		
//		  //
//	  }
//	  else if(StrCMP(_cmdRecvBuff.CmdName, "BootStatus")) //引导程序状态上报
//	  {
//		//CreateMsgBox_Nobt();
//		//ShowMsg_NoBt((char*)_cmdRecvBuff.CmdData);
//	  }
//	  else if(StrCMP(_cmdRecvBuff.CmdName, "ShowMsg"))
//	  {
//		CreateMsgBox_Nobt();
//		ShowMsg_NoBt((char*)_cmdRecvBuff.CmdData);
//	  }
//	  else if(StrCMP(_cmdRecvBuff.CmdName, "ShowMsgBox"))
//	  {
//		CreateMsgBox();
//		ShowMsg((char*)_cmdRecvBuff.CmdData);
//	  }
}

//读数据延时，当读取到数据后立即返回
void ReadDataDelay()
{
	  for(u16 i=0;i<100;i++)
		{
			if(_cmdRecvBuff.RecvOK)
			{
				break;
			}
			Delay_ms_Tick(100);
		}
}

//读取设备型号，也用作联机握手。当读取到返回true
bool GetDevMode(char* devModeBuff)
{
	  SendChars_Pack(_rdd,"DEVMODE",NULL);
		ReadDataDelay();
		if(_cmdRecvBuff.RecvOK)
		{
			strcpy(devModeBuff,(char*)_cmdRecvBuff.CmdData);
			return true;
		}
		return false;
}

void GetParameter()
{
  SendChars_Pack(_rdd,"PARAFILE",NULL);
	ReadDataDelay();
  CopyBytes((u8*)&Parameter,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
}

//从下位机读取系统参数
void GetSysParameter()
{
	SendChars_Pack(_rdd,"SYSPARA",NULL);
	ReadDataDelay();
	CopyBytes((u8*)&SysParameter,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
}

//获取下位机当前状态
StatusParaStruct GetCurrStatus(void)
{
	currStatus.DevStatus=NoGetStatus;
	memset(currStatus.StatusDescribe,0,sizeof(currStatus.StatusDescribe));
	SendChars_Pack(_rdd,"CURRSTATUS",NULL);
	ReadDataDelay();
	if(_cmdRecvBuff.RecvOK)
	{			
		u8 count=0;
		LIST* ls=GetLIST((char*)_cmdRecvBuff.CmdData,&count);
		currStatus.DevStatus=ConvertAsciiTou32(ls[0].item);		
		strcpy(currStatus.StatusDescribe,ls[1].item);
	}
	return currStatus;
}

void AxisPTRun(char* axisID,char* fx)
{
  char buff[50]={0};
  LinkThreeStr(buff,axisID,",",fx);
  SendChars_Pack(_wrt,"AxisPTRun",buff);
}

void AxisPTStop(char* axisID)
{
  SendChars_Pack(_wrt,"AxisPTStop",axisID);
}

//在设备上进行注册
void RegisterDevice(char* regNum)
{
	SendChars_Pack(_wrt,"RegisterDevice",regNum);
}

MultiAxisCoordStruct _currCoord;
//获取当前实时坐标
MultiAxisCoordStruct* GetCurrCoord()
{
    SendChars_Pack(_rdd,"CURRCOORD",NULL);
    ReadDataDelay();
    CopyBytes((u8*)&_currCoord,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
    return &_currCoord;
}

