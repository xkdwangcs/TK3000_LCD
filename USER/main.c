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
    //使能CRC 因为使用STemWin前必须要使能
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
    InitUSART_COM1();
    //bsp_InitSPIBus();	      	// 配置SPI总线
    SysTick_Init();	        	// 初始化系统滴答定时器
	//BEEP_InitHard();
		bsp_InitExtSRAM();	
		bool sramIsOK = bsp_TestExtSRAM();
	//SPIFlashInit();  //可以在FATFS中初始化	
	//SPIFlashChipErase();
	//FormatDisk(SPI_FLASH); 
	//bool flashIsOK = SPIFlashTest();
	//PDFormatFlash();	
	//bsp_InitNorFlash();
		NAND_Init();
		//PDFormatFlash();	
		LCD_InitHard();	        	// 初始化显示器硬件(配置GPIO和FSMC,给LCD发送初始化指令)
		TOUCH_InitHard();

	if(_currUSBMode==DirverMode)//HostMode;
	{
		usbd_OpenMassStorage();
	}
	else
	{
		USBH_Init(&USB_OTG_Core,USB_OTG_FS_CORE_ID,
			&USB_Host,&USBH_MSC_cb,&USR_cb);           //初始化USBHost
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
//  LCD_ClrScr(CL_BLUE3);	/* 清屏，显示全黑 */
//  FONT_T font;
//  font.FontCode = FC_RA8875_32;
//  font.BackColor = CL_BLUE;		/* 透明色 */
//  font.FrontColor = CL_WHITE;
//  font.Space = 0;
//  LCD_DispStr(g_LcdWidth/2, g_LcdHeight/2, (char*)readBuff, &font);			/* 在底部处显示一串汉字 */
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
		//放到Tick中
    //USBH_Process(&USB_OTG_Core, &USB_Host);
  }
}

