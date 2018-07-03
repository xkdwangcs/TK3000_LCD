/*****************
UpdataDate:2016-08-31 22:10 XYQ
******************/

#include "main.h"
#include "usbh_usr.h" 
#include "usb_bsp.h"
#include "MainTask.h"
//#include "SPIFlashBase.h"
#include "bsp_fsmc_sram.h"
#include "FileOperate.h"
#include "usbd_usr.h"
//#include "bsp_beep.h"
#include "bsp_nand_flash.h"
//#include "bsp_nor_flash.h"

void BSPInit(void)
{
    //ʹ��CRC ��Ϊʹ��STemWinǰ����Ҫʹ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
    InitUSART_COM1();
    //bsp_InitSPIBus();	      	// ����SPI����
    SysTick_Init();	        	// ��ʼ��ϵͳ�δ�ʱ��
	//BEEP_InitHard();
		bsp_InitExtSRAM();	
		bool sramIsOK = bsp_TestExtSRAM();
	//SPIFlashInit();  //������FATFS�г�ʼ��	
	//SPIFlashChipErase();
	//FormatDisk(SPI_FLASH); 
	//bool flashIsOK = SPIFlashTest();
	//PDFormatFlash();	
	//bsp_InitNorFlash();
		NAND_Init();
		//PDFormatFlash();	
		LCD_InitHard();	        	// ��ʼ����ʾ��Ӳ��(����GPIO��FSMC,��LCD���ͳ�ʼ��ָ��)
		TOUCH_InitHard();

	if(_currUSBMode==DirverMode)//HostMode;
	{
		usbd_OpenMassStorage();
	}
	else
	{
		USBH_Init(&USB_OTG_Core,USB_OTG_FS_CORE_ID,
			&USB_Host,&USBH_MSC_cb,&USR_cb);           //��ʼ��USBHost
	}
}

int main(void)
{
//	BSPInit();
//	char* data="XYQ OKok!";
//	char* fn="0:/abc1.txt";
//	CreateFileOnDisk(fn,true);
//	WriteBytesToFile(fn,(u8*)data,0,strlen(data));
//	u8 readBuff[50]={0};
//	ReadBytesFormFile(fn,readBuff,0,strlen(data));
//	
//  LCD_ClrScr(CL_BLUE3);	/* ��������ʾȫ�� */
//  FONT_T font;
//  font.FontCode = FC_RA8875_32;
//  font.BackColor = CL_BLUE;		/* ͸��ɫ */
//  font.FrontColor = CL_WHITE;
//  font.Space = 0;
//  LCD_DispStr(g_LcdWidth/2, g_LcdHeight/2, (char*)readBuff, &font);			/* �ڵײ�����ʾһ������ */
//	LCD_DrawRect(10,10,200,500,CL_MAGENTA);
//	LCD_Fill_Rect(50,50,200,500,CL_CYAN);
//	LCD_DrawCircle(240,300,100,CL_GREEN);
//  for( ;; );
		
    BSPInit();
//		char* str="NANDFlash,OK!";
//		char* fn="0:/TestDir/abc.txt";
//		CreateFileOnDisk(fn,true);
//		WriteBytesToFile(fn,(u8*)str,0,strlen(str));
    LCDBeep(1000);
    MainTask();
  
  
  while(true)
  {
		//�ŵ�Tick��
    //USBH_Process(&USB_OTG_Core, &USB_Host);
  }
}

