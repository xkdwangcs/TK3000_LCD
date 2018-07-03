#ifndef __MEMORYALLOC_H
#define __MEMORYALLOC_H

#ifdef __cplusplus
 extern "C" {
#endif 

/******************
* IS61LV25616
********************/
//��IS61LV25616/IS62WV25616,��ַ�߷�ΧΪA0~A17 
//��IS61LV51216/IS62WV51216,��ַ�߷�ΧΪA0~A18
	 
#include "stm32f4xx.h"
#include "absacc.h"
#include "string.h"
//#include "SPIFlashBase.h"
#include "PublicFunction.h"
#include "COM.h"
#include "bsp_nand_flash.h"
//#include "SRAM_SFMC.h"
//#include "MotionProcFile.h"
//#include "CoordFile.h"
//#include "MatrixCoordEdit.h"
//#include "Controls.h"
//#include "SCurve_Table.h"
		 
#define FLASH_SECTOR_SIZE 4096	 
	 
	 
/*************BKPSRAM****************/	 
//ʹ�õı��ݼĴ��������4K��
#define FirmwareUpdateTagAddr BKPSRAM_BASE //�̼����ء�������־�ĵ�ַ�����ڱ��ݼĴ����ĵ�1��
#define PermissionAddr BKPSRAM_BASE+1 //������ʱȨ�ޱ����ַ���ڵ�2��
//#define FormatDiskAddr_OneSYS BKPSRAM_BASE+2 //��������һ�����ع̼���Ҫ��ʽ�����̣��ڵ�3��
#define InportEventCancelTag BKPSRAM_BASE+3 //������¼��Ƿ�ȡ�������ַ���ڵ�4��
#define OutputStateAddrBase BKPSRAM_BASE+32 //ǰ32byte���ã������״̬�Ӵ˵�ַ��ʼ���,һ��ʹ��OutPortNum���ֽ�		 
/*************BKPSRAM END****************/


/***************CCMRAM******************/
#define CCMBaseAddr 	0x10000000 	//CCM�ڴ����ʼ��ַ
#define CCMSize				0x10000 	//CCM�ڴ��С��64KB	 

//#define FlashBuffAddr   				CCMBaseAddr 
//#define FlashTestBuffAddr   		FlashBuffAddr+sizeof(s_usLUT)
#define FileBuffAddr    				CCMBaseAddr //FlashTestBuffAddr+sizeof(s_ucTempBuf) 
#define DicBuffAddr							FileBuffAddr+ FLASH_SECTOR_SIZE //�ֵ�ṹ�����ַ
#define ComSendBuffAddr					DicBuffAddr+sizeof(_dic)				//���ڷ��ͻ����ַ
#define ComRecvBuffAddr					ComSendBuffAddr+_comBuffLeng			//���ڽ��ջ����ַ
#define picBuffAddr							ComRecvBuffAddr+_comBuffLeng			//emWinˢͼƬ����
/***************CCMRAM END*****************/	 


/*****************ExtRAM****************/
//#define WorkParaAddr 		ExtSRAM_ADDR 								//����������ʼ��ַ
//#define DefaultParaAddr 	WorkParaAddr+sizeof(Parameter) 				//Ĭ�ϲ�����ʼ��ַ
//#define LeftCoordAddr 		DefaultParaAddr+ sizeof(Parameter)  		//��ƽ̨�����б���ʼ��ַ
//#define RightCoordAddr 		LeftCoordAddr+ sizeof(_coordListLeft)  		//��ƽ̨�����б���ʼ��ַ
//#define CoordFileAttriAddr  RightCoordAddr+sizeof(_coordListLeft) 		//�����ļ������б���ʼ��ַ
//#define LcdSendBuffAddr 	CoordFileAttriAddr+ sizeof(_fileList)		//��ʾ�����ͻ�����ʼ��ַ
////#define LcdRecvBuffAddr 	LcdSendBuffAddr+sizeof(_DMASendBuff_COM3)	//��ʾ�����ջ�����ʼ��ַ,�㶯ԭ����ղ��ܷ���չ�ڴ�
//#define LcdSendCMDBuffAddr 	LcdSendBuffAddr+sizeof(_DMASendBuff_COM3)	//��ʾ�������������ʼ��ַ
//#define DrawCircleBuffAddr 	LcdSendCMDBuffAddr+sizeof(_lcdSendCmdBuf)	//������ͼ���б����ַ
//#define MatrixCoordAddr		DrawCircleBuffAddr+sizeof(_drawPoints)		//����������껺��
//#define FileOPTempAddr		MatrixCoordAddr+sizeof(_matrixCoordList)	//�ļ�����ɾ��������ʱ����
//#define MotionCurveBuff		FileOPTempAddr+sizeof(_tempArray)			//�˶����ƼӼ��ٻ���
/**************ExtRAM END***************/	

#ifdef __cplusplus
}
#endif

#endif