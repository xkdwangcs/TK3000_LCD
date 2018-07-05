#include "CMD.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "SysTick_Timer.h"


//��ǰʹ�õĴ��ں�
USART_TypeDef *currUSART = USART1;
StatusParaStruct currStatus;

//RDD�������Ĵ���
void RDDProcess(void)
{  
	
}

//WRT�������Ĵ���
void WRTProcess(void)
{

}


extern WM_HWIN CreateMsgBox_Nobt();
extern WM_HWIN CreateMsgBox();
extern void ShowMsg(char* msg);
extern void ShowMsg_NoBt(char* msg);

//SRQ�������Ĵ���
void SRQProcess(void)
{
	if (StrCMP(_cmdRecvBuff.CmdName, "CURRSTATUS")) //״̬��������
	{
		u8 count=0;
		currStatus.DevStatus=NoGetStatus;
		LIST* ls=GetLIST((char*)_cmdRecvBuff.CmdData,&count);
		currStatus.DevStatus=ConvertAsciiTou32(ls[0].item);		
		strcpy(currStatus.StatusDescribe,ls[1].item);		
		switch(currStatus.DevStatus)
		{
			case DeviceIniting: //�豸��ʼ����

				break;					
			case DevWorking: //�豸���ڹ���
									
				break;
			case DevScram: //��ͣ��
				ShowMsgNoButton("�豸�Ѽ�ͣ������󵯳�����ͣ��ť���ټ�����");
				break;
			case USBInsert: //USB�Ѳ���
				ShowUSBForm();
				break;
			default:
				break;
		}
	}
	
	
//	if (StrCMP(_cmdRecvBuff.CmdName, "USBFunc_Ctr")) //���ư���USB��ع��ܴ���
//	  {		
//		  CreateUSBFunc_Ctr();
//	  }
//	  else if (StrCMP(_cmdRecvBuff.CmdName, "SysResetForm")) //ϵͳ��λ����
//	  {		
//		  //
//	  }
//	  else if(StrCMP(_cmdRecvBuff.CmdName, "BootStatus")) //��������״̬�ϱ�
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

void GetParameter()
{
  SendChars_Pack(_rdd,"PARAFILE",NULL);
	ReadDataDelay();
  CopyBytes((u8*)&Parameter,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
}

//����λ����ȡϵͳ����
void GetSysParameter()
{
	SendChars_Pack(_rdd,"SYSPARA",NULL);
	ReadDataDelay();
	CopyBytes((u8*)&SysParameter,0,_cmdRecvBuff.CmdData,_cmdRecvBuff.DataLeng);
}

//��ȡ��λ����ǰ״̬
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

//���豸�Ͻ���ע��
void RegisterDevice(char* regNum)
{
	SendChars_Pack(_wrt,"RegisterDevice",regNum);
}

