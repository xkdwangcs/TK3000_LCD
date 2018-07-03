#include "CMD.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "SysTick_Timer.h"
#include "Parameter.h"
#include "USBFunc_Ctr.h"

//当前使用的串口号
USART_TypeDef *currUSART = USART1;

//RDD相关命令的处理
void RDDProcess(void)
{  
	//memset(_protocolBuff.CmdBuff,0,CMDBuffLeng);//一般查询指令只有指令名，所以放在此处共用。如果有参数就不能放在此处
	//char* cmdAddr=&_protocolBuff.CmdBuff[PackHeadNum];
//	if (StrCMP(_protocolBuff.CmdName, "DEVMODEL")) //此条命令必备，联机用
//	{		
//		LinkThreeStr(cmdAddr,_protocolBuff.CmdName,"=",Parameter.ProdModel);
//	}
//	else if(StrCMP(_protocolBuff.CmdName, "MPMSG"))//铭牌信息
//	{
//		AppendStrAddSplit(cmdAddr, "MPMSG=ProdName|", Parameter.ProdName);
//		AppendStrAddSplit(cmdAddr, ",ProdModel|", Parameter.ProdModel);
//		AppendStrAddSplit(cmdAddr, ",ProduDate|", Parameter.ProduDate);
//		AppendStrAddSplit(cmdAddr, ",ProdID|", Parameter.ProdID);
//		AppendStrAddSplit(cmdAddr, ",Company|", Parameter.Company);
//		AppendStrAddSplit(cmdAddr, ",URL|", Parameter.URL);
//		AppendStrAddSplit(cmdAddr, ",Tel|", Parameter.Tel);
//		AppendStrAddSplit(cmdAddr, ",CompanyAddr|", Parameter.CompanyAddr);		
//	}
//	else if(StrCMP(_protocolBuff.CmdName, "CTMPMSG"))//控制器铭牌信息
//	{
//		AppendStrAddSplit(cmdAddr, "MPMSG=ProdName|", ControlMPMsg.ProdName);
//		AppendStrAddSplit(cmdAddr, ",ProdModel|", ControlMPMsg.ProdModel);
//		AppendStrAddSplit(cmdAddr, ",ProduDate|", ControlMPMsg.ProduDate);
//		AppendStrAddSplit(cmdAddr, ",ProdID|", ControlMPMsg.ProdID);
//		AppendStrAddSplit(cmdAddr, ",Company|", ControlMPMsg.Company);
//		AppendStrAddSplit(cmdAddr, ",URL|", ControlMPMsg.URL);
//		AppendStrAddSplit(cmdAddr, ",Tel|", ControlMPMsg.Tel);
//		AppendStrAddSplit(cmdAddr, ",CompanyAddr|", ControlMPMsg.CompanyAddr);		
//	}
//	ResponseSendData(_rdd, strlen(cmdAddr));
	return;
}

//WRT命令回复OK
void SendWRTOK(void)
{
	SendChars_Pack(_wrt,_cmdRecvBuff.CmdName,"OK");
}

//WRT相关命令的处理
void WRTProcess(void)
{
	/*if(StrCMP(_protocolBuff.CmdName, "MPMSG"))//设备铭牌信息设置
	{
		u8 count=0;
		Dictionary* dic=ConvertToDic(_protocolBuff.CmdBuff,&count);
		for(u8 i=0;i<count;i++)
		{
			if(StrCMP(dic[i].key,"ProdName"))
				strcpy(Parameter.ProdName,dic[i].value);
			else if(StrCMP(dic[i].key,"ProdModel"))
				strcpy(Parameter.ProdModel,dic[i].value);
			else if(StrCMP(dic[i].key,"ProduDate"))
				strcpy(Parameter.ProduDate,dic[i].value);
			else if(StrCMP(dic[i].key,"ProdID"))
				strcpy(Parameter.ProdID,dic[i].value);
			else if(StrCMP(dic[i].key,"Company"))
				strcpy(Parameter.Company,dic[i].value);
			else if(StrCMP(dic[i].key,"URL"))
				strcpy(Parameter.URL,dic[i].value);
			else if(StrCMP(dic[i].key,"Tel"))
				strcpy(Parameter.Tel,dic[i].value);
			else if(StrCMP(dic[i].key,"CompanyAddr"))
				strcpy(Parameter.CompanyAddr,dic[i].value);
		}
		WriteParameter(NULL);
		SendWRTOK();
	}
	else if(StrCMP(_protocolBuff.CmdName, "CTMPMSG"))//控制器铭牌信息设置
	{
		u8 count=0;
		Dictionary* dic=ConvertToDic(_protocolBuff.CmdBuff,&count);
		for(u8 i=0;i<count;i++)
		{
			if(StrCMP(dic[i].key,"ProdName"))
				strcpy(ControlMPMsg.ProdName,dic[i].value);
			else if(StrCMP(dic[i].key,"ProdModel"))
				strcpy(ControlMPMsg.ProdModel,dic[i].value);
			else if(StrCMP(dic[i].key,"ProduDate"))
				strcpy(ControlMPMsg.ProduDate,dic[i].value);
			else if(StrCMP(dic[i].key,"ProdID"))
				strcpy(ControlMPMsg.ProdID,dic[i].value);
			else if(StrCMP(dic[i].key,"Company"))
				strcpy(ControlMPMsg.Company,dic[i].value);
			else if(StrCMP(dic[i].key,"URL"))
				strcpy(ControlMPMsg.URL,dic[i].value);
			else if(StrCMP(dic[i].key,"Tel"))
				strcpy(ControlMPMsg.Tel,dic[i].value);
			else if(StrCMP(dic[i].key,"CompanyAddr"))
				strcpy(ControlMPMsg.CompanyAddr,dic[i].value);
		}
		ControlMPMsg.IsWrited=true;
		WriteControlMPMsg();
		SendWRTOK();
	}
	else if(StrCMP(_protocolBuff.CmdName, "TIMEJZ"))//时间校准
	{
		char* data=_protocolBuff.CmdBuff;
		u16 leng=strlen(data);
		bool bl=true;
		if(!(leng!=19 || data[4]!='-'|| data[10]!=' ' || data[16]!=':'))
			bl = TimeAdjust(data);		
		SendWRTOK();
	}*/
}

//OUT命令回复OK
void SendOUTOK(char *cmdName)
{
	SendChars_Pack(_out,_cmdRecvBuff.CmdName,"OK");
}

//OUT相关命令的处理
void OUTProcess(void)
{
	
}

extern WM_HWIN CreateMsgBox_Nobt();
extern WM_HWIN CreateMsgBox();
extern void ShowMsg(char* msg);
extern void ShowMsg_NoBt(char* msg);

//SRQ相关命令的处理
void SRQProcess(void)
{
	if (StrCMP(_cmdRecvBuff.CmdName, "USBFunc_Ctr")) //控制板上USB相关功能窗体
  {		
      CreateUSBFunc_Ctr();
  }
  else if (StrCMP(_cmdRecvBuff.CmdName, "SysResetForm")) //系统复位窗体
  {		
      //
  }
  else if(StrCMP(_cmdRecvBuff.CmdName, "BootStatus")) //引导程序状态上报
  {
    //CreateMsgBox_Nobt();
    //ShowMsg_NoBt((char*)_cmdRecvBuff.CmdData);
  }
  else if(StrCMP(_cmdRecvBuff.CmdName, "ShowMsg"))
  {
    CreateMsgBox_Nobt();
    ShowMsg_NoBt((char*)_cmdRecvBuff.CmdData);
  }
  else if(StrCMP(_cmdRecvBuff.CmdName, "ShowMsgBox"))
  {
    CreateMsgBox();
    ShowMsg((char*)_cmdRecvBuff.CmdData);
  }
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
			Delay_ms_Tick(10);
		}
}

void GetParameter()
{
  SendChars_Pack(_rdd,"PARAFILE",NULL);
	ReadDataDelay();
  CopyBytes((u8*)&Parameter,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
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

StatusParaStruct currStatus;
//获取下位机当前状态
StatusParaStruct GetCurrStatus(void)
{
	currStatus.StatusID=0;
	memset(currStatus.StatusDescribe,0,sizeof(currStatus.StatusDescribe));
	SendChars_Pack(_rdd,"CURRSTATUS",NULL);
	ReadDataDelay();
	if(_cmdRecvBuff.RecvOK)
	{			
			u8 count=0;
      LIST* ls=GetLIST((char*)_cmdRecvBuff.CmdData,&count);
		currStatus.StatusID=ConvertAsciiTou32(ls[0].item);		
		strcpy(currStatus.StatusDescribe,ls[1].item);
	}
		return currStatus;
}


