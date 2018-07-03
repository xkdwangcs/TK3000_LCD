#include "CMD.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "SysTick_Timer.h"
#include "Parameter.h"
#include "USBFunc_Ctr.h"

//��ǰʹ�õĴ��ں�
USART_TypeDef *currUSART = USART1;

//RDD�������Ĵ���
void RDDProcess(void)
{  
	//memset(_protocolBuff.CmdBuff,0,CMDBuffLeng);//һ���ѯָ��ֻ��ָ���������Է��ڴ˴����á�����в����Ͳ��ܷ��ڴ˴�
	//char* cmdAddr=&_protocolBuff.CmdBuff[PackHeadNum];
//	if (StrCMP(_protocolBuff.CmdName, "DEVMODEL")) //��������ر���������
//	{		
//		LinkThreeStr(cmdAddr,_protocolBuff.CmdName,"=",Parameter.ProdModel);
//	}
//	else if(StrCMP(_protocolBuff.CmdName, "MPMSG"))//������Ϣ
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
//	else if(StrCMP(_protocolBuff.CmdName, "CTMPMSG"))//������������Ϣ
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

//WRT����ظ�OK
void SendWRTOK(void)
{
	SendChars_Pack(_wrt,_cmdRecvBuff.CmdName,"OK");
}

//WRT�������Ĵ���
void WRTProcess(void)
{
	/*if(StrCMP(_protocolBuff.CmdName, "MPMSG"))//�豸������Ϣ����
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
	else if(StrCMP(_protocolBuff.CmdName, "CTMPMSG"))//������������Ϣ����
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
	else if(StrCMP(_protocolBuff.CmdName, "TIMEJZ"))//ʱ��У׼
	{
		char* data=_protocolBuff.CmdBuff;
		u16 leng=strlen(data);
		bool bl=true;
		if(!(leng!=19 || data[4]!='-'|| data[10]!=' ' || data[16]!=':'))
			bl = TimeAdjust(data);		
		SendWRTOK();
	}*/
}

//OUT����ظ�OK
void SendOUTOK(char *cmdName)
{
	SendChars_Pack(_out,_cmdRecvBuff.CmdName,"OK");
}

//OUT�������Ĵ���
void OUTProcess(void)
{
	
}

extern WM_HWIN CreateMsgBox_Nobt();
extern WM_HWIN CreateMsgBox();
extern void ShowMsg(char* msg);
extern void ShowMsg_NoBt(char* msg);

//SRQ�������Ĵ���
void SRQProcess(void)
{
	if (StrCMP(_cmdRecvBuff.CmdName, "USBFunc_Ctr")) //���ư���USB��ع��ܴ���
  {		
      CreateUSBFunc_Ctr();
  }
  else if (StrCMP(_cmdRecvBuff.CmdName, "SysResetForm")) //ϵͳ��λ����
  {		
      //
  }
  else if(StrCMP(_cmdRecvBuff.CmdName, "BootStatus")) //��������״̬�ϱ�
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

//��������ʱ������ȡ�����ݺ���������
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

//��ȡ�豸�ͺţ�Ҳ�����������֡�����ȡ������true
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
//��ȡ��λ����ǰ״̬
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


