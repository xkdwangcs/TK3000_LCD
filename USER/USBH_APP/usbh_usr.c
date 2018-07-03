/**
  ******************************************************************************
  * @file    usbh_usr.c
  * @author  MCD Application Team
  * @version V2.1.0
  * @date    19-March-2012
  * @brief   This file includes the usb host library user callbacks
  ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "usbh_usr.h"
#include "usbh_msc_core.h"
#include "usbh_msc_scsi.h"
#include "usbh_msc_bot.h"
#include "FileOperate.h"
#include "GUI.h"

USB_OTG_CORE_HANDLE   USB_OTG_Core;
USBH_HOST             USB_Host;
bool _isRunOne=false;  //U��������ִ��һ��

//USB�ص�������˳��ִ��
USBH_Usr_cb_TypeDef USR_cb =
{
  USBH_USR_Init,							//��ʼ��
  USBH_USR_DeInit,
  USBH_USR_DeviceAttached,					//��⵽��USB�豸����
  USBH_USR_ResetDevice,						//�����豸
  USBH_USR_DeviceDisconnected,				//��⵽���豸�Ƴ�
  USBH_USR_OverCurrentDetected,
  USBH_USR_DeviceSpeedDetected,				//����豸�ٶȣ�������١�ȫ�١�����
  USBH_USR_Device_DescAvailable,			//�豸��Ϣ
  USBH_USR_DeviceAddressAssigned,	   		//�����ַ�ɹ�
  USBH_USR_Configuration_DescAvailable,	    //��������
  USBH_USR_Manufacturer_String,		  		//������Ϣ���ַ�����
  USBH_USR_Product_String,			  		//��Ʒ��Ϣ���ַ�����
  USBH_USR_SerialNum_String,		   		//�豸����
  USBH_USR_EnumerationDone,			  		//ö�����
  USBH_USR_UserInput,						//�û�����Ӧ�ó���״̬��Ŀ
  USBH_USR_MSC_Application,					//USBӦ�ò���
  USBH_USR_DeviceNotSupported,				//�豸��֧��
  USBH_USR_UnrecoveredError 
};

//���Գ�ʼ��һЩ����
void USBH_USR_Init(void)
{

}

//��⵽U�̲���
void USBH_USR_DeviceAttached(void)
{
	//printf("��⵽USB�豸����!\r\n");
}

//�޷��ָ��Ĵ���!!
void USBH_USR_UnrecoveredError (void)
{
	//printf("�޷��ָ��Ĵ���!!!\r\n\r\n");
}

//��⵽U�̰γ�
void USBH_USR_DeviceDisconnected (void)
{
	//printf("USB�豸�γ�!\r\n");
	//SetUSBHostTaskEnable(false);//�ڴ˿��Թر�USBHost���񣬽�ʡ������Դ
	_isRunOne=false;
}

//��������
void USBH_USR_ResetDevice(void)
{
	/* callback for USB-Reset */
	//printf("USBH_USR_ResetDevice\r\n");
}

//��⵽�ӻ��ٶ�
//DeviceSpeed:�ӻ��ٶ�(0,1,2 / ����)
void USBH_USR_DeviceSpeedDetected(uint8_t DeviceSpeed)
{
	/*if(DeviceSpeed==HPRT0_PRTSPD_HIGH_SPEED)
	{
		printf("����(HS)USB�豸!\r\n");
 	}  
	else if(DeviceSpeed==HPRT0_PRTSPD_FULL_SPEED)
	{
		printf("ȫ��(FS)USB�豸!\r\n"); 
	}
	else if(DeviceSpeed==HPRT0_PRTSPD_LOW_SPEED)
	{
		printf("����(LS)USB�豸!\r\n");  
	}
	else
	{
		printf("�豸����!\r\n");  
	}  */
}

//��⵽�ӻ���������
//DeviceDesc:�豸������ָ��
void USBH_USR_Device_DescAvailable(void *DeviceDesc)
{
//	USBH_DevDesc_TypeDef *hs;
//	hs = DeviceDesc;
//	usb_printf("> VID : %04Xh\r\n" , (uint32_t)(*hs).idVendor);
//	usb_printf("> PID : %04Xh\r\n" , (uint32_t)(*hs).idProduct);
}

//�ӻ���ַ����ɹ�
void USBH_USR_DeviceAddressAssigned(void)
{
  //printf("�ӻ���ַ����ɹ�\r\n");
}


//��������������Ч
void USBH_USR_Configuration_DescAvailable(USBH_CfgDesc_TypeDef * cfgDesc,
                                          USBH_InterfaceDesc_TypeDef *itfDesc,
                                          USBH_EpDesc_TypeDef *epDesc)
{
	/*USBH_InterfaceDesc_TypeDef *id; 
	id = itfDesc;   
	if((*id).bInterfaceClass==0x08)
	{
		//printf("���ƶ��洢���豸!\r\n"); 
	}
    else if((*id).bInterfaceClass==0x03)
	{
		//printf("HID �豸!\r\n"); 
	}*/    
}

//���̣��ַ�������Ϣ
void USBH_USR_Manufacturer_String(void *ManufacturerString)
{
  //printf("Manufacturer : %s\r\n", (char *)ManufacturerString);
}

//��Ʒ��Ϣ���ַ�����
void USBH_USR_Product_String(void *ProductString)
{
	//printf("Product : %s\r\n", (char *)ProductString);
}

//�豸����
void USBH_USR_SerialNum_String(void *SerialNumString)
{
	//printf( "Serial Number : %s\r\n", (char *)SerialNumString); 
}

//�豸USBö�����
void USBH_USR_EnumerationDone(void)
{
//	printf("�豸USBö�����\r\n");	
//	USB_OTG_BSP_mDelay(500);
	//USBH_USR_MSC_Application();
}

//�޷�ʶ���USB�豸
void USBH_USR_DeviceNotSupported(void)
{
	//printf("�޷�ʶ���USB�豸\r\n");
}

//�û�����Ӧ�ó���״̬��Ŀ
USBH_USR_Status USBH_USR_UserInput(void)
{
	return USBH_USR_RESP_OK;
}

//USB�ӿڵ�������
void USBH_USR_OverCurrentDetected (void)
{
	//printf("�˿ڵ�������!!!\r\n");
}

void USBBackReset(u16 keyCode)
{
	//SystemReset();
}

//Ӧ�ò���
int USBH_USR_MSC_Application(void)
{
    if(!_isRunOne)
    {
        _isRunOne=true;
//			PermissionTypeEnum destPer=AdminiPer;//��Ҫ����Ա������Ȩ��
//			if(_currPermission<destPer)
//			{
//				ShowLoginForm(destPer,ShowUSBOprateForm,USBBackReset);
//				return 0;
//			}
//			ShowUSBOprateForm(0);
			
//			bool bl = CopyAllFile_Dir("1:/Pic","0:/Pic",true,NULL);
//			bl = CopyAllFile_Dir("1:/Font","0:/Font",true,NULL);
			
//			u8 buff[50];
//			char* ws = "TestWriteFile";
//			char* fn="0:/ABC.txt";
//			FRESULT res = CreateFileOnDisk(fn,true);
//			WriteBytesToFile(fn,(u8*)ws,0,strlen(ws));
//			ReadBytesFormFile(fn,buff,0,strlen(ws));
			
//			u32 re;
//			FIL file;
//			FATFS fs;    
//			u32 reindex;
//			FRESULT res = f_mount(&fs,"0:/",0);	                        
//			res = f_open(&file,"0:/ABC.txt",FA_READ);
//			u8 buff[5];
//			if (res == FR_OK)
//			{
//				f_lseek(&file,0);
//				res = f_read(&file,buff,5,&re);          
//			}
//			f_close(&file);
//			res  = f_mount(NULL, "0:/", 0); 	 
			//GUI_SetFont(&GUI_Font24_ASCII);	
			GUI_DispStringHCenterAt("Start copy. Wait...",200,80);		
			//bool bl= CopyFile("1:/Font/HWXH21.xbf","0:/Font/HWXH21.xbf",true);
      bool bl= CopyFile("1:/abc.pdf","0:/abc.pdf",true);
			GUI_DispStringHCenterAt("Copy complate,Plese potup USB!",200,110);	
//			char fileList[40][50];//U����Ķ����ļ�
//			GetFileList_Dir("1:/Pic",(char*)fileList,40,50,NULL);
    }
	return 0;
}

//�û�Ҫ�����³�ʼ���豸
void USBH_USR_DeInit(void)
{
	//USBH_USR_ApplicationState = USH_USR_FS_INIT;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

