/*
*********************************************************************************************************
*
*	ģ������ : STM32F429�ڲ�LCD��������
*	�ļ����� : bsp_tft_429.c
*	��    �� : V1.0
*	˵    �� : STM32F429 �ڲ�LCD�ӿڵ�Ӳ�����ó���
*	�޸ļ�¼ :
*		�汾��  ����       ����    ˵��
*		V1.0    2014-05-05 armfly ���� STM32F429 �ڲ�LCD�ӿڣ� ����ST�����Ӹ��ģ���Ҫ�������ǰ���㶨�壬ֱ��
*							      �� LTDC_Layer1 �� LTDC_Layer2, ����2���ṹ��ָ��
*		V1.1	2015-11-19 armfly 
*						1. ��ͼ�����滻ΪDMA2DӲ����������߻�ͼЧ��
*						2. ͳһ�����������ú������Զ�ʶ���������
*
*	Copyright (C), 2015-2020, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp_tft_429.h"
#include "bsp_tft_lcd.h"
#include "bsp_touch.h"
#include "bsp_fmc_sdram.h"
#include "fonts.h"
#include "string.h"

typedef uint32_t LCD_COLOR;

#define LCD429_FRAME_BUFFER       EXT_SDRAM_ADDR

/* ƫ�Ƶ�ַ���㹫ʽ::
   Maximum width x Maximum Length x Maximum Pixel size (ARGB8888) in bytes
   => 640 x 480 x 4 =  1228800 or 0x12C000 */
#define BUFFER_OFFSET          (uint32_t)(g_LcdHeight * g_LcdWidth * 2)

uint32_t s_CurrentFrameBuffer;
uint8_t s_CurrentLayer;

static void LCD429_AF_GPIOConfig(void);
static void LCD429_ConfigLTDC(void);

void LCD429_LayerInit(void);

//static void LCD429_SetDispWin(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth);
//static void LCD429_QuitWinMode(void);
void LCD429_SetPixelFormat(uint32_t PixelFormat);

static void _DMA_Copy(void * pSrc, void * pDst, int xSize, int ySize, int OffLineSrc, int OffLineDst);

/*
*********************************************************************************************************
*	�� �� ��: LCD429_InitHard
*	����˵��: ��ʼ��LCD
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_InitHard(void)
{
	LCD429_ConfigLTDC();			/* ����429 CPU�ڲ�LTDC */

	LCD429_SetLayer(LCD_LAYER_1);	/* �л���ǰ���� */
	LCD429_SetPixelFormat(LTDC_Pixelformat_RGB565);
	LCD429_ClrScr(CL_BLACK);		/* ��������ʾȫ�� */	
	LTDC_LayerCmd(LTDC_Layer1, ENABLE);
	

	LTDC_LayerCmd(LTDC_Layer2, ENABLE);	/* ���õ���˫�������� ˫�������Ժ����� */
	LCD429_SetLayer(LCD_LAYER_2);	/* �л��������� */
	LCD429_SetPixelFormat(LTDC_Pixelformat_RGB565);
	
	/* Enable The LCD */
	LTDC_Cmd(ENABLE);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_ConfigLTDC
*	����˵��: ����LTDC
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD429_ConfigLTDC(void)
{
	LTDC_InitTypeDef       LTDC_InitStruct;
	LTDC_Layer_TypeDef     LTDC_Layerx;
	uint16_t Width, Height, HSYNC_W, HBP, HFP, VSYNC_W, VBP, VFP;

	/* Enable the LTDC Clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC, ENABLE);

	/* Enable the DMA2D Clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2D, ENABLE);

	/* Configure the LCD Control pins */
	LCD429_AF_GPIOConfig();

	/* Configure the FMC Parallel interface : SDRAM is used as Frame Buffer for LCD */
	//SDRAM_Init();
	bsp_InitExtSDRAM();

	/* �����źż��� */	
	LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;	/* HSYNC �͵�ƽ��Ч */
	/* Initialize the vertical synchronization polarity as active low */
	LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;	/* VSYNC �͵�ƽ��Ч */
	/* Initialize the data enable polarity as active low */
	LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;	/* DE �͵�ƽ��Ч */
	/* Initialize the pixel clock polarity as input pixel clock */
	LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC;
	//LTDC_InitStruct.LTDC_PCPolarity = LTDC_GCR_PCPOL;		// inverted input pixel clock.

	/* Configure R,G,B component values for LCD background color */
	LTDC_InitStruct.LTDC_BackgroundRedValue = 0;
	LTDC_InitStruct.LTDC_BackgroundGreenValue = 0;
	LTDC_InitStruct.LTDC_BackgroundBlueValue = 0;
	
	/* ���� PLLSAI ����LCD */
	/* Enable Pixel Clock */

	/* ����ʱ�� PLLSAI_VCO Input   = HSE_VALUE / PLL_M = 8M / 4 = 2 Mhz */
	/* ���ʱ�� PLLSAI_VCO Output  = PLLSAI_VCO Input * PLLSAI_N =   2 * 429 = 858 Mhz */
	/* PLLLCDCLK = PLLSAI_VCO Output / PLLSAI_R = 858 / 4 = 214.5 Mhz */
	/* LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 214.5 / 8 = 24 Mhz */

	/*

		RCC->PLLSAICFGR = (PLLSAIN << 6) | (PLLSAIQ << 24) | (PLLSAIR << 28);


		This register is used to configure the PLLSAI clock outputs according to the formulas:
		
		f(VCO clock) = f(PLLSAI clock input) �� (PLLSAIN / PLLM)
		
		f(PLLSAI1 clock output) = f(VCO clock) / PLLSAIQ
		f(PLL LCD clock output) = f(VCO clock) / PLLSAIR				
	*/
	
	/* ֧��6����� */
	switch (g_LcdType)
	{
		case LCD_35_480X320:	/* 3.5�� 480 * 320 */	
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
		
			Width = 480;
			Height = 272;
			HSYNC_W = 10;
			HBP = 20;
			HFP = 20;
			VSYNC_W = 20;
			VBP = 20;
			VFP = 20;
			break;
		
		case LCD_43_480X272:		/* 4.3�� 480 * 272 */
			RCC_PLLSAIConfig(429, 2,  6);		/* Ƶ�ʸ��˺�ᶶ�� */
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);		

			Width = 480;
			Height = 272;

			HSYNC_W = 40;
			HBP = 2;
			HFP = 2;
			VSYNC_W = 9;
			VBP = 2;
			VFP = 2;
			break;
		
		case LCD_50_480X272:		/* 5.0�� 480 * 272 */
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
		
			Width = 480;
			Height = 272;
		
			HSYNC_W = 40;
			HBP = 2;
			HFP = 2;
			VSYNC_W = 9;
			VBP = 2;
			VFP = 2;			
			break;
		
		case LCD_50_800X480:		/* 5.0�� 800 * 480 */
			RCC_PLLSAIConfig(429, 2,  6);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);

			Width = 800;
			Height = 480;

			HSYNC_W = 96;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 10;
			HFP = 10;
			VSYNC_W = 2;
			VBP = 10;
			VFP = 10;			
			break;
		
		case LCD_70_800X480:		/* 7.0�� 800 * 480 */
			RCC_PLLSAIConfig(429, 2,  6);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
			
			Width = 800;
			Height = 480;

			HSYNC_W = 90;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 10;
			HFP = 10;
		
			VSYNC_W = 10;
			VBP = 10;
			VFP = 10;				   
			break;
		
		case LCD_70_1024X600:		/* 7.0�� 1024 * 600 */
			LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;	/* HSYNC �͵�ƽ��Ч */
			/* Initialize the vertical synchronization polarity as active low */
			LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;	/* VSYNC �͵�ƽ��Ч */
			/* Initialize the data enable polarity as active low */
			LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;	/* DE �͵�ƽ��Ч */
			/* Initialize the pixel clock polarity as input pixel clock */
			LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IIPC;
		
			/* IPS 7�� 1024*600��  ����ʱ��Ƶ�ʷ�Χ : 57 -- 65 --- 70.5MHz 
		
				PLLSAI_VCO Input   = HSE_VALUE / PLL_M = 8M / 4 = 2 Mhz
				PLLSAI_VCO Output  = PLLSAI_VCO Input * PLLSAI_N =   2 * 429 = 858 Mhz
				PLLLCDCLK = PLLSAI_VCO Output / PLLSAI_R = 858 / 4 = 214.5 Mhz
				LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 214.5 / 4 = 53.625 Mhz 	

				(429, 2, 4); RCC_PLLSAIDivR_Div4 ʵ������ʱ�� = 53.7M
			*/
			RCC_PLLSAIConfig(429, 2, 6);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
		
			Width = 1024;
			Height = 600;

			HSYNC_W = 2;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 157;
			HFP = 160;
		
			VSYNC_W = 2;
			VBP = 20;
			VFP = 12;			
			break;
		
		default:
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);

			Width = 800;
			Height = 480;

			HSYNC_W = 80;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 10;
			HFP = 10;
			VSYNC_W = 10;
			VBP = 10;
			VFP = 10;			
			break;
	}
	
	/* Initialize the LCD pixel width and pixel height */
	g_LcdWidth  = Width;		/* ��ʾ���ֱ���-��� */
	g_LcdHeight = Height;		/* ��ʾ���ֱ���-�߶� */
	
	/* Enable PLLSAI Clock */
	RCC_PLLSAICmd(ENABLE);
	
	/* Wait for PLLSAI activation */
	while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET);

	/* Timing configuration */
	/* Configure horizontal synchronization width */
	LTDC_InitStruct.LTDC_HorizontalSync = HSYNC_W;
	/* Configure vertical synchronization height */
	LTDC_InitStruct.LTDC_VerticalSync = VSYNC_W;
	/* Configure accumulated horizontal back porch */
	LTDC_InitStruct.LTDC_AccumulatedHBP = LTDC_InitStruct.LTDC_HorizontalSync + HBP;
	/* Configure accumulated vertical back porch */
	LTDC_InitStruct.LTDC_AccumulatedVBP = LTDC_InitStruct.LTDC_VerticalSync + VBP;
	/* Configure accumulated active width */
	LTDC_InitStruct.LTDC_AccumulatedActiveW = Width + LTDC_InitStruct.LTDC_AccumulatedHBP;
	/* Configure accumulated active height */
	LTDC_InitStruct.LTDC_AccumulatedActiveH = Height + LTDC_InitStruct.LTDC_AccumulatedVBP;
	/* Configure total width */
	LTDC_InitStruct.LTDC_TotalWidth = LTDC_InitStruct.LTDC_AccumulatedActiveW + HFP;
	/* Configure total height */
	LTDC_InitStruct.LTDC_TotalHeigh = LTDC_InitStruct.LTDC_AccumulatedActiveH + VFP;

	LTDC_Init(&LTDC_InitStruct);

	//LCD429_LayerInit();  չ���˺���
	{
		LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct;

		LTDC_Layer_InitStruct.LTDC_HorizontalStart = HSYNC_W + HBP + 1;
		LTDC_Layer_InitStruct.LTDC_HorizontalStop = (Width + LTDC_Layer_InitStruct.LTDC_HorizontalStart - 1);
		LTDC_Layer_InitStruct.LTDC_VerticalStart = VSYNC_W + VBP + 1; 
		LTDC_Layer_InitStruct.LTDC_VerticalStop = (Height + LTDC_Layer_InitStruct.LTDC_VerticalStart - 1);

		/* Pixel Format configuration*/
		LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_RGB565;
		/* Alpha constant (255 totally opaque) */
		LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 255;
		/* Default Color configuration (configure A,R,G,B component values) */
		LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 0;
		LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 0;
		LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 0;
		LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
		/* Configure blending factors */
		LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_CA;
		LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_CA;

		/* the length of one line of pixels in bytes + 3 then :
		Line Lenth = Active high width x number of bytes per pixel + 3
		Active high width         = LCD429_PIXEL_WIDTH
		number of bytes per pixel = 2    (pixel_format : RGB565)
		*/
		LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((Width * 2) + 3);
		/* the pitch is the increment from the start of one line of pixels to the
		start of the next line in bytes, then :
		Pitch = Active high width x number of bytes per pixel
		*/
		LTDC_Layer_InitStruct.LTDC_CFBPitch = (Height * 2);

		/* Configure the number of lines */
		LTDC_Layer_InitStruct.LTDC_CFBLineNumber = 	Width;	/*���˴���Ҫ��д���ֵ?  */
		
		/* Start Address configuration : the LCD Frame buffer is defined on SDRAM */
		LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD429_FRAME_BUFFER;

		LTDC_LayerInit(LTDC_Layer1, &LTDC_Layer_InitStruct);

		/* Configure Layer2 */
		/* Start Address configuration : the LCD Frame buffer is defined on SDRAM w/ Offset */
		LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD429_FRAME_BUFFER + BUFFER_OFFSET;

		/* Configure blending factors */
		LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;
		LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA;

		LTDC_LayerInit(LTDC_Layer2, &LTDC_Layer_InitStruct);

		LTDC_ReloadConfig(LTDC_IMReload);

		/* Enable foreground & background Layers */
		LTDC_LayerCmd(LTDC_Layer1, ENABLE);
		LTDC_LayerCmd(LTDC_Layer2, ENABLE);
		LTDC_ReloadConfig(LTDC_IMReload);
		
		//LCD429_SetFont(&LCD429_DEFAULT_FONT);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_AF_GPIOConfig
*	����˵��: ����GPIO���� LTDC.
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void LCD429_AF_GPIOConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* Enable GPIOI, GPIOJ, GPIOK AHB Clocks */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI | RCC_AHB1Periph_GPIOJ | \
	             RCC_AHB1Periph_GPIOK,  ENABLE);

	/* GPIOs Configuration */
	/*
	+------------------------+-----------------------+----------------------------+
	+                       LCD pins assignment                                   +
	+------------------------+-----------------------+----------------------------+
	|  LCD429_TFT R0 <-> PI.15  |  LCD429_TFT G0 <-> PJ.07 |  LCD429_TFT B0 <-> PJ.12      |
	|  LCD429_TFT R1 <-> PJ.00  |  LCD429_TFT G1 <-> PJ.08 |  LCD429_TFT B1 <-> PJ.13      |
	|  LCD429_TFT R2 <-> PJ.01  |  LCD429_TFT G2 <-> PJ.09 |  LCD429_TFT B2 <-> PJ.14      |
	|  LCD429_TFT R3 <-> PJ.02  |  LCD429_TFT G3 <-> PJ.10 |  LCD429_TFT B3 <-> PJ.15      |
	|  LCD429_TFT R4 <-> PJ.03  |  LCD429_TFT G4 <-> PJ.11 |  LCD429_TFT B4 <-> PK.03      |
	|  LCD429_TFT R5 <-> PJ.04  |  LCD429_TFT G5 <-> PK.00 |  LCD429_TFT B5 <-> PK.04      |
	|  LCD429_TFT R6 <-> PJ.05  |  LCD429_TFT G6 <-> PK.01 |  LCD429_TFT B6 <-> PK.05      |
	|  LCD429_TFT R7 <-> PJ.06  |  LCD429_TFT G7 <-> PK.02 |  LCD429_TFT B7 <-> PK.06      |
	-------------------------------------------------------------------------------
	|  LCD429_TFT HSYNC <-> PI.12  | LCDTFT VSYNC <->  PI.13 |
	|  LCD429_TFT CLK   <-> PI.14  | LCD429_TFT DE   <->  PK.07 |
	-----------------------------------------------------
	*/

	/* GPIOI configuration */
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource12, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource13, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource14, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource15, GPIO_AF_LTDC);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

	//GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOI, &GPIO_InitStruct);
	
	/* GPIOJ configuration */
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource0, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource1, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource2, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource3, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource4, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource5, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource6, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource7, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource8, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource9, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource10, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource11, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource12, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource13, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource14, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOJ, GPIO_PinSource15, GPIO_AF_LTDC);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | \
	                 GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | \
	                 GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | \
	                 GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

	GPIO_Init(GPIOJ, &GPIO_InitStruct);

	/* GPIOI configuration */
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource0, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource1, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource2, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource3, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource4, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource5, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource6, GPIO_AF_LTDC);
	GPIO_PinAFConfig(GPIOK, GPIO_PinSource7, GPIO_AF_LTDC);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | \
	                 GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;

	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOK, &GPIO_InitStruct);
}


/*
*********************************************************************************************************
*	�� �� ��: LCD429_GetChipDescribe
*	����˵��: ��ȡLCD����оƬ���������ţ�������ʾ
*	��    ��: char *_str : �������ַ�������˻�����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_GetChipDescribe(char *_str)
{
	strcpy(_str, "STM32F429");
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_SetLayer
*	����˵��: �л��㡣ֻ�Ǹ��ĳ���������Ա��ں���Ĵ��������ؼĴ�����Ӳ��֧��2�㡣
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_SetLayer(uint8_t _ucLayer)
{
	if (_ucLayer == LCD_LAYER_1)
	{
		s_CurrentFrameBuffer = LCD429_FRAME_BUFFER;
		s_CurrentLayer = LCD_LAYER_1;
	}
	else if (_ucLayer == LCD_LAYER_2)
	{
		s_CurrentFrameBuffer = LCD429_FRAME_BUFFER + BUFFER_OFFSET;
		s_CurrentLayer = LCD_LAYER_2;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_SetTransparency
*	����˵��: ���õ�ǰ���͸������
*	��    ��: ͸���ȣ� ֵ�� 0x00 - 0xFF
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_SetTransparency(uint8_t transparency)
{
	if (s_CurrentLayer == LCD_LAYER_1)
	{
		LTDC_LayerAlpha(LTDC_Layer1, transparency);
	}
	else
	{
		LTDC_LayerAlpha(LTDC_Layer2, transparency);
	}
	LTDC_ReloadConfig(LTDC_IMReload);	/* ����ˢ�� */
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_SetPixelFormat
*	����˵��: ���õ�ǰ������ظ�ʽ
*	��    ��: ���ظ�ʽ:
*                      LTDC_Pixelformat_ARGB8888
*                      LTDC_Pixelformat_RGB888
*                      LTDC_Pixelformat_RGB565
*                      LTDC_Pixelformat_ARGB1555
*                      LTDC_Pixelformat_ARGB4444
*                      LTDC_Pixelformat_L8
*                      LTDC_Pixelformat_AL44
*                      LTDC_Pixelformat_AL88
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_SetPixelFormat(uint32_t PixelFormat)
{
	if (s_CurrentLayer == LCD_LAYER_1)
	{
		LTDC_LayerPixelFormat(LTDC_Layer1, PixelFormat);
	}
	else
	{
		LTDC_LayerPixelFormat(LTDC_Layer2, PixelFormat);
	}
	LTDC_ReloadConfig(LTDC_IMReload);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_SetDispWin
*	����˵��: ������ʾ���ڣ����봰����ʾģʽ��
*	��    ��:  
*		_usX : ˮƽ����
*		_usY : ��ֱ����
*		_usHeight: ���ڸ߶�
*		_usWidth : ���ڿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_SetDispWin(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth)
{
	if (s_CurrentLayer == LCD_LAYER_1)
	{ 
		/* reconfigure the layer1 position */
		LTDC_LayerPosition(LTDC_Layer1, _usX, _usY);
		LTDC_ReloadConfig(LTDC_IMReload);
	
		/* reconfigure the layer1 size */
		LTDC_LayerSize(LTDC_Layer1, _usWidth, _usHeight);
		LTDC_ReloadConfig(LTDC_IMReload);
	}
	else
	{   
		/* reconfigure the layer2 position */
		LTDC_LayerPosition(LTDC_Layer2, _usX, _usY);
		LTDC_ReloadConfig(LTDC_IMReload); 
		
		/* reconfigure the layer2 size */
		LTDC_LayerSize(LTDC_Layer2, _usWidth, _usHeight);
		LTDC_ReloadConfig(LTDC_IMReload);
	}	
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_QuitWinMode
*	����˵��: �˳�������ʾģʽ����Ϊȫ����ʾģʽ
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_QuitWinMode(void)
{
	LCD429_SetDispWin(0, 0, g_LcdHeight, g_LcdWidth);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DispOn
*	����˵��: ����ʾ
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DispOn(void)
{
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DispOff
*	����˵��: �ر���ʾ
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DispOff(void)
{
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_ClrScr
*	����˵��: �����������ɫֵ����
*	��    ��: _usColor : ����ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_ClrScr(uint16_t _usColor)
{
#if 1
	LCD429_FillRect(0, 0, g_LcdHeight, g_LcdWidth, _usColor);
#else
	uint16_t *index ;
	uint32_t i;

	index = (uint16_t *)s_CurrentFrameBuffer;

	for (i = 0; i < g_LcdHeight * g_LcdWidth; i++)
	{
		*index++ = _usColor;
	}
#endif	
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_PutPixel
*	����˵��: ��1������
*	��    ��:
*			_usX,_usY : ��������
*			_usColor  : ������ɫ ( RGB = 565 ��ʽ)
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_PutPixel(uint16_t _usX, uint16_t _usY, uint16_t _usColor)
{
	uint16_t *p;
	uint32_t index = 0;
	
	p = (uint16_t *)s_CurrentFrameBuffer;
		
	if (g_LcdDirection == 0)		/* ���� */
	{
		index = (uint32_t)_usY * g_LcdWidth + _usX;
	}
	else if (g_LcdDirection == 1)	/* ����180��*/
	{
		index = (uint32_t)(g_LcdHeight - _usY - 1) * g_LcdWidth + (g_LcdWidth - _usX - 1);
	}
	else if (g_LcdDirection == 2)	/* ���� */
	{
		index = (uint32_t)(g_LcdWidth - _usX - 1) * g_LcdHeight + _usY;
	}
	else if (g_LcdDirection == 3)	/* ����180�� */
	{
		index = (uint32_t)_usX * g_LcdHeight + g_LcdHeight - _usY - 1;
	}	
	
	if (index < g_LcdHeight * g_LcdWidth)
	{
		p[index] = _usColor;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_GetPixel
*	����˵��: ��ȡ1������
*	��    ��:
*			_usX,_usY : ��������
*			_usColor  : ������ɫ
*	�� �� ֵ: RGB��ɫֵ
*********************************************************************************************************
*/
uint16_t LCD429_GetPixel(uint16_t _usX, uint16_t _usY)
{
	uint16_t usRGB;
	uint16_t *p;
	uint32_t index = 0;
	
	p = (uint16_t *)s_CurrentFrameBuffer;

	if (g_LcdDirection == 0)		/* ���� */
	{
		index = (uint32_t)_usY * g_LcdWidth + _usX;
	}
	else if (g_LcdDirection == 1)	/* ����180��*/
	{
		index = (uint32_t)(g_LcdHeight - _usY - 1) * g_LcdWidth + (g_LcdWidth - _usX - 1);
	}
	else if (g_LcdDirection == 2)	/* ���� */
	{
		index = (uint32_t)(g_LcdWidth - _usX - 1) * g_LcdHeight + _usY;
	}
	else if (g_LcdDirection == 3)	/* ����180�� */
	{
		index = (uint32_t)_usX * g_LcdHeight + g_LcdHeight - _usY - 1;
	}
	
	usRGB = p[index];

	return usRGB;
}


/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawLine
*	����˵��: ���� Bresenham �㷨����2��仭һ��ֱ�ߡ�
*	��    ��:
*			_usX1, _usY1 : ��ʼ������
*			_usX2, _usY2 : ��ֹ��Y����
*			_usColor     : ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor)
{
	int32_t dx , dy ;
	int32_t tx , ty ;
	int32_t inc1 , inc2 ;
	int32_t d , iTag ;
	int32_t x , y ;

	/* ���� Bresenham �㷨����2��仭һ��ֱ�� */

	LCD429_PutPixel(_usX1 , _usY1 , _usColor);

	/* ��������غϣ���������Ķ�����*/
	if ( _usX1 == _usX2 && _usY1 == _usY2 )
	{
		return;
	}

	iTag = 0 ;
	/* dx = abs ( _usX2 - _usX1 ); */
	if (_usX2 >= _usX1)
	{
		dx = _usX2 - _usX1;
	}
	else
	{
		dx = _usX1 - _usX2;
	}

	/* dy = abs ( _usY2 - _usY1 ); */
	if (_usY2 >= _usY1)
	{
		dy = _usY2 - _usY1;
	}
	else
	{
		dy = _usY1 - _usY2;
	}

	if ( dx < dy )   /*���dyΪ�Ƴ������򽻻��ݺ����ꡣ*/
	{
		uint16_t temp;

		iTag = 1 ;
		temp = _usX1; _usX1 = _usY1; _usY1 = temp;
		temp = _usX2; _usX2 = _usY2; _usY2 = temp;
		temp = dx; dx = dy; dy = temp;
	}
	tx = _usX2 > _usX1 ? 1 : -1 ;    /* ȷ������1���Ǽ�1 */
	ty = _usY2 > _usY1 ? 1 : -1 ;
	x = _usX1 ;
	y = _usY1 ;
	inc1 = 2 * dy ;
	inc2 = 2 * ( dy - dx );
	d = inc1 - dx ;
	while ( x != _usX2 )     /* ѭ������ */
	{
		if ( d < 0 )
		{
			d += inc1 ;
		}
		else
		{
			y += ty ;
			d += inc2 ;
		}
		if ( iTag )
		{
			LCD429_PutPixel ( y , x , _usColor) ;
		}
		else
		{
			LCD429_PutPixel ( x , y , _usColor) ;
		}
		x += tx ;
	}	
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawHLine
*	����˵��: ����һ��ˮƽ��. ʹ��STM32F429 DMA2DӲ������.
*	��    ��:
*			_usX1, _usY1 : ��ʼ������
*			_usLen       : �ߵĳ���
*			_usColor     : ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawHLine(uint16_t _usX, uint16_t _usY, uint16_t _usLen , uint16_t _usColor)
{
#if 0
	LCD429_FillRect(_usX, _usY, 1, _usLen, _usColor);
#else	
	uint16_t i;
	
	for (i = 0; i < _usLen; i++)
	{	
		LCD429_PutPixel(_usX + i , _usY , _usColor);
	}
#endif	
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawVLine
*	����˵��: ����һ����ֱ�ߡ� ʹ��STM32F429 DMA2DӲ������.
*	��    ��:
*			_usX, _usY : ��ʼ������
*			_usLen       : �ߵĳ���
*			_usColor     : ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawVLine(uint16_t _usX , uint16_t _usY , uint16_t _usLen , uint16_t _usColor)
{
#if 0
	LCD429_FillRect(_usX, _usY, _usLen, 1, _usColor);
#else	
	uint16_t i;
	
	for (i = 0; i < _usLen; i++)
	{	
		LCD429_PutPixel(_usX, _usY + i, _usColor);
	}
#endif	
}
/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawPoints
*	����˵��: ���� Bresenham �㷨������һ��㣬������Щ�����������������ڲ�����ʾ��
*	��    ��:
*			x, y     : ��������
*			_usColor : ��ɫ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawPoints(uint16_t *x, uint16_t *y, uint16_t _usSize, uint16_t _usColor)
{
	uint16_t i;

	for (i = 0 ; i < _usSize - 1; i++)
	{
		LCD429_DrawLine(x[i], y[i], x[i + 1], y[i + 1], _usColor);
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawRect
*	����˵��: ����ˮƽ���õľ��Ρ�
*	��    ��:
*			_usX,_usY: �������Ͻǵ�����
*			_usHeight : ���εĸ߶�
*			_usWidth  : ���εĿ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawRect(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
	/*
	 ---------------->---
	|(_usX��_usY)        |
	V                    V  _usHeight
	|                    |
	 ---------------->---
		  _usWidth
	*/
	LCD429_DrawHLine(_usX, _usY, _usWidth, _usColor);
	LCD429_DrawVLine(_usX +_usWidth - 1, _usY, _usHeight, _usColor);
	LCD429_DrawHLine(_usX, _usY + _usHeight - 1, _usWidth, _usColor);
	LCD429_DrawVLine(_usX, _usY, _usHeight, _usColor);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_FillRect
*	����˵��: ��һ����ɫֵ���һ�����Ρ�ʹ��STM32F429�ڲ�DMA2DӲ�����ơ�
*	��    ��:
*			_usX,_usY: �������Ͻǵ�����
*			_usHeight : ���εĸ߶�
*			_usWidth  : ���εĿ��
*			_usColor  : ��ɫ����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_FillRect(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t _usColor)
{
#if 1	/* ���⺯��չ�������ִ��Ч�� */
	uint32_t  Xaddress = 0;
	uint16_t  OutputOffset = 0;
	uint16_t  NumberOfLine = 0;
	uint16_t  PixelPerLine = 0;	

	/* ������ʾ�������ò�ͬ�Ĳ��� */
	if (g_LcdDirection == 0)		/* ���� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdWidth * _usY + _usX);	
		OutputOffset = g_LcdWidth - _usWidth;
		NumberOfLine = _usHeight;
		PixelPerLine = _usWidth;
	}
	else if (g_LcdDirection == 1)	/* ����180��*/
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdWidth * (g_LcdHeight - _usHeight - _usY) + g_LcdWidth - _usX - _usWidth);	
		OutputOffset = g_LcdWidth - _usWidth;
		NumberOfLine = _usHeight;
		PixelPerLine = _usWidth;
	}
	else if (g_LcdDirection == 2)	/* ���� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdHeight * (g_LcdWidth - _usX -  _usWidth) + _usY);	
		OutputOffset = g_LcdHeight - _usHeight;
		NumberOfLine = _usWidth;
		PixelPerLine = _usHeight;
	}
	else if (g_LcdDirection == 3)	/* ����180�� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdHeight * _usX + g_LcdHeight - _usHeight - _usY);	
		OutputOffset = g_LcdHeight - _usHeight;
		NumberOfLine = _usWidth;
		PixelPerLine = _usHeight;		
	}	

	/* �����λ DMA2D */
	RCC->AHB1RSTR |= RCC_AHB1Periph_DMA2D;
	RCC->AHB1RSTR &= ~RCC_AHB1Periph_DMA2D; 
	
	/* ����DMA2D����ģʽΪ R2M (�Ĵ������洢���� */
	DMA2D->CR &= (uint32_t)0xFFFCE0FC;
	DMA2D->CR |= DMA2D_R2M;

	/* �����������ɫģʽΪ RGB565 */
	DMA2D->OPFCCR &= ~(uint32_t)DMA2D_OPFCCR_CM;
	DMA2D->OPFCCR |= (DMA2D_RGB565);

	/* ������ɫֵ */   
	DMA2D->OCOLR |= _usColor;

	/* Configures the output memory address */
	DMA2D->OMAR = Xaddress;

	/* Configure  the line Offset */
	DMA2D->OOR &= ~(uint32_t)DMA2D_OOR_LO;
	DMA2D->OOR |= OutputOffset;

	/* Configure the number of line and pixel per line */
	DMA2D->NLR &= ~(DMA2D_NLR_NL | DMA2D_NLR_PL);
	DMA2D->NLR |= (NumberOfLine | (PixelPerLine << 16));
  
	/* Start Transfer */ 
    DMA2D->CR |= (uint32_t)DMA2D_CR_START;

	/* Wait for CTC Flag activation */
	while ((DMA2D->ISR & DMA2D_FLAG_TC)  == 0);
#endif

#if 0	/* ʹ�ÿ⺯�� -- ������� */
	/* ʹ��DMA2DӲ�������� */
	DMA2D_InitTypeDef      DMA2D_InitStruct;
	uint32_t  Xaddress = 0;
	uint16_t  OutputOffset;
	uint16_t  NumberOfLine;
	uint16_t  PixelPerLine;	
		
	if (g_LcdDirection == 0)		/* ���� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdWidth * _usY + _usX);	
		OutputOffset = g_LcdWidth - _usWidth;
		NumberOfLine = _usHeight;
		PixelPerLine = _usWidth;
	}
	else if (g_LcdDirection == 1)	/* ����180��*/
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdWidth * (g_LcdHeight - _usHeight - _usY) + g_LcdWidth - _usX - _usWidth);	
		OutputOffset = g_LcdWidth - _usWidth;
		NumberOfLine = _usHeight;
		PixelPerLine = _usWidth;
	}
	else if (g_LcdDirection == 2)	/* ���� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdHeight * (g_LcdWidth - _usX -  _usWidth) + _usY);	
		OutputOffset = g_LcdHeight - _usHeight;
		NumberOfLine = _usWidth;
		PixelPerLine = _usHeight;
	}
	else if (g_LcdDirection == 3)	/* ����180�� */
	{
		Xaddress = s_CurrentFrameBuffer + 2 * (g_LcdHeight * _usX + g_LcdHeight - _usHeight - _usY);	
		OutputOffset = g_LcdHeight - _usHeight;
		NumberOfLine = _usWidth;
		PixelPerLine = _usHeight;		
	}	

	/* ���� DMA2D */
	DMA2D_DeInit();		/* ��λ DMA2D */
	DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;       /* ����ģʽ: �Ĵ������洢�� */
	DMA2D_InitStruct.DMA2D_CMode = DMA2D_RGB565;   /* ��ɫģʽ�� RGB565 */   
	
	DMA2D_InitStruct.DMA2D_OutputRed = RGB565_R2(_usColor);		/* ��ɫ������5bit����λΪ0 */           
	DMA2D_InitStruct.DMA2D_OutputGreen = RGB565_G2(_usColor);	/* ��ɫ������6bit����λΪ0 */
	DMA2D_InitStruct.DMA2D_OutputBlue = RGB565_B2(_usColor); 	/* ��ɫ������5bit����λΪ0 */    
	
	DMA2D_InitStruct.DMA2D_OutputAlpha = 0x0F;    				/* ͸�������� ����565��ʽ�������� */              
	DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;      	/* Ŀ���ڴ��ַ */          
	DMA2D_InitStruct.DMA2D_OutputOffset = OutputOffset; 	/* ÿ�м���Դ����ص�ַ��ֵ  */               
	DMA2D_InitStruct.DMA2D_NumberOfLine = NumberOfLine;     /* һ���м��� */        
	DMA2D_InitStruct.DMA2D_PixelPerLine = PixelPerLine;		/* ÿ�м������� */
	DMA2D_Init(&DMA2D_InitStruct); 

	/* Start Transfer */ 
	DMA2D_StartTransfer();

	/* Wait for CTC Flag activation */
	while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
	{
	}
#endif	
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawCircle
*	����˵��: ����һ��Բ���ʿ�Ϊ1������
*	��    ��:
*			_usX,_usY  : Բ�ĵ�����
*			_usRadius  : Բ�İ뾶
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawCircle(uint16_t _usX, uint16_t _usY, uint16_t _usRadius, uint16_t _usColor)
{
	int32_t  D;			/* Decision Variable */
	uint32_t  CurX;		/* ��ǰ X ֵ */
	uint32_t  CurY;		/* ��ǰ Y ֵ */

	D = 3 - (_usRadius << 1);
	CurX = 0;
	CurY = _usRadius;

	while (CurX <= CurY)
	{
		LCD429_PutPixel(_usX + CurX, _usY + CurY, _usColor);
		LCD429_PutPixel(_usX + CurX, _usY - CurY, _usColor);
		LCD429_PutPixel(_usX - CurX, _usY + CurY, _usColor);
		LCD429_PutPixel(_usX - CurX, _usY - CurY, _usColor);
		LCD429_PutPixel(_usX + CurY, _usY + CurX, _usColor);
		LCD429_PutPixel(_usX + CurY, _usY - CurX, _usColor);
		LCD429_PutPixel(_usX - CurY, _usY + CurX, _usColor);
		LCD429_PutPixel(_usX - CurY, _usY - CurX, _usColor);

		if (D < 0)
		{
			D += (CurX << 2) + 6;
		}
		else
		{
			D += ((CurX - CurY) << 2) + 10;
			CurY--;
		}
		CurX++;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_DrawBMP
*	����˵��: ��LCD����ʾһ��BMPλͼ��λͼ����ɨ����򣺴����ң����ϵ���
*	��    ��:  
*			_usX, _usY : ͼƬ������
*			_usHeight  ��ͼƬ�߶�
*			_usWidth   ��ͼƬ���
*			_ptr       ��ͼƬ����ָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_DrawBMP(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t *_ptr)
{
	uint16_t i, k, y;
	const uint16_t *p;

	p = _ptr;
	y = _usY;
	for (i = 0; i < _usHeight; i++)
	{
		for (k = 0; k < _usWidth; k++)
		{
			LCD429_PutPixel(_usX + k, y, *p++);
		}
		
		y++;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_SetDirection
*	����˵��: ������ʾ����ʾ���򣨺��� ������
*	��    ��: ��ʾ������� 0 ��������, 1=����180�ȷ�ת, 2=����, 3=����180�ȷ�ת
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_SetDirection(uint8_t _dir)
{
	uint16_t temp;
	
	if (_dir == 0 || _dir == 1)		/* ������ ����180�� */
	{
		if (g_LcdWidth < g_LcdHeight)
		{
			temp = g_LcdWidth;
			g_LcdWidth = g_LcdHeight;
			g_LcdHeight = temp;			
		}
	}
	else if (_dir == 2 || _dir == 3)	/* ����, ����180��*/
	{
		if (g_LcdWidth > g_LcdHeight)
		{
			temp = g_LcdWidth;
			g_LcdWidth = g_LcdHeight;
			g_LcdHeight = temp;			
		}
	}
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_BeginDraw
*	����˵��: ˫����������ģʽ����ʼ��ͼ������ǰ��ʾ�������������������Ƶ�����һ����������
*			 ����� LCD429_EndDraw�����ɶ�ʹ�á� ʵ��Ч�������á�
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_BeginDraw(void)
{
	uint16_t *src;
	uint16_t *dst;
		
	if (s_CurrentFrameBuffer == LCD429_FRAME_BUFFER)
	{
		src = (uint16_t *)LCD429_FRAME_BUFFER;
		dst =  (uint16_t *)(LCD429_FRAME_BUFFER + BUFFER_OFFSET);
		
		s_CurrentFrameBuffer = LCD429_FRAME_BUFFER + BUFFER_OFFSET;
	}
	else
	{
		src = (uint16_t *)(LCD429_FRAME_BUFFER + BUFFER_OFFSET);
		dst = (uint16_t *)LCD429_FRAME_BUFFER;
		
		s_CurrentFrameBuffer = LCD429_FRAME_BUFFER;
	}
	
	_DMA_Copy(src, dst, g_LcdHeight, g_LcdWidth, 0, 0);
}

/*
*********************************************************************************************************
*	�� �� ��: LCD429_EndDraw
*	����˵��: APP�����˻�������ͼ�������л�Ӳ����ʾ��
*			 ����� LCD429_BeginDraw�����ɶ�ʹ�á�
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void LCD429_EndDraw(void)
{
	LTDC_LayerAddress(LTDC_Layer1, s_CurrentFrameBuffer);
}

/*
*********************************************************************************************************
*	�� �� ��: _GetBufferSize
*	����˵��: ��
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
uint32_t _GetBufferSize(uint8_t LayerIndex)
{
	return g_LcdWidth * g_LcdHeight;
}

/*
*********************************************************************************************************
*	�� �� ��: _DMA_Copy
*	����˵��: ����ͼ��
*	��    ��: 
*			 pSrc : Դ�ڴ��ַ
*			 pDst : Ŀ���ڴ��ַ
*			 xSize : ����x�ߴ�
*			 ySize : ����y�ߴ�
*			 OffLineSrc : Դͼ����ƫ��
*			 OffLineDst : Ŀ��ͼ����ƫ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void _DMA_Copy(void * pSrc, void * pDst, int xSize, int ySize, int OffLineSrc, int OffLineDst) 
{
	DMA2D->CR      = 0x00000000UL | (1 << 9);  	// Control Register (Memory to memory and TCIE)
	DMA2D->FGMAR   = (uint32_t)pSrc;            // Foreground Memory Address Register (Source address)
	DMA2D->OMAR    = (uint32_t)pDst;        	// Output Memory Address Register (Destination address)
	DMA2D->FGOR    = OffLineSrc;           		// Foreground Offset Register (Source line offset)
	DMA2D->OOR     = OffLineDst;            	// Output Offset Register (Destination line offset)
	DMA2D->FGPFCCR = LTDC_Pixelformat_RGB565;           	// Foreground PFC Control Register (Defines the input pixel format)
	DMA2D->NLR     = (uint32_t)(xSize << 16) | (uint16_t)ySize; // Number of Line Register (Size configuration of area to be transfered)
	DMA2D->CR     |= 1;                               // Start operation
	//
	// Wait until transfer is done
	//
	while (DMA2D->CR & DMA2D_CR_START)
	{
		//__WFI();                                        // Sleep until next interrupt
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*********************************************************************************************************
*	                                 ����ĺ�����emWin������
*********************************************************************************************************
*/
/*
*********************************************************************************************************
*	�� �� ��: LCD_ConfigLTDC
*	����˵��: ����LTDC
*	��    ��: ��
*	�� �� ֵ: ��
*   ��    ��:
*       LCD_TFT ͬ��ʱ�����ã������Թٷ�����һ����ͼ���Լ����ࣩ��
*       ----------------------------------------------------------------------------
*    
*                                                 Total Width
*                             <--------------------------------------------------->
*                       Hsync width HBP             Active Width                HFP
*                             <---><--><--------------------------------------><-->
*                         ____    ____|_______________________________________|____ 
*                             |___|   |                                       |    |
*                                     |                                       |    |
*                         __|         |                                       |    |
*            /|\    /|\  |            |                                       |    |
*             | VSYNC|   |            |                                       |    |
*             |Width\|/  |__          |                                       |    |
*             |     /|\     |         |                                       |    |
*             |  VBP |      |         |                                       |    |
*             |     \|/_____|_________|_______________________________________|    |
*             |     /|\     |         | / / / / / / / / / / / / / / / / / / / |    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*    Total    |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*    Heigh    |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |Active|      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |Heigh |      |         |/ / / / / / Active Display Area / / / /|    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |      |      |         |/ / / / / / / / / / / / / / / / / / / /|    |
*             |     \|/_____|_________|_______________________________________|    |
*             |     /|\     |                                                      |
*             |  VFP |      |                                                      |
*            \|/    \|/_____|______________________________________________________|
*            
*     
*     ÿ��LCD�豸�����Լ���ͬ��ʱ��ֵ��
*     Horizontal Synchronization (Hsync) 
*     Horizontal Back Porch (HBP)       
*     Active Width                      
*     Horizontal Front Porch (HFP)     
*   
*     Vertical Synchronization (Vsync)  
*     Vertical Back Porch (VBP)         
*     Active Heigh                       
*     Vertical Front Porch (VFP)         
*     
*     LCD_TFT ����ˮƽ�ʹ�ֱ����ʼ�Լ�����λ�� :
*     ----------------------------------------------------------------
*   
*     HorizontalStart = (Offset_X + Hsync + HBP);
*     HorizontalStop  = (Offset_X + Hsync + HBP + Window_Width - 1); 
*     VarticalStart   = (Offset_Y + Vsync + VBP);
*     VerticalStop    = (Offset_Y + Vsync + VBP + Window_Heigh - 1);
*
*********************************************************************************************************
*/
__IO uint16_t Width, Height, HSYNC_W, VSYNC_W, HBP, HFP, VBP, VFP;
void LCD_ConfigLTDC(void)
{
	LTDC_InitTypeDef       LTDC_InitStruct;
	LTDC_Layer_TypeDef     LTDC_Layerx;

	/* ʹ��LTDC */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC, ENABLE);

	/* ʹ��DMA2D */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2D, ENABLE);

	/* ����LCD���� */
	LCD429_AF_GPIOConfig();

	/* �����źż��� */	
	LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;	/* HSYNC �͵�ƽ��Ч */
	LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;	/* VSYNC �͵�ƽ��Ч */
	LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;	/* DE �͵�ƽ��Ч */
	LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC;

	/* ����ɫ */
	LTDC_InitStruct.LTDC_BackgroundRedValue = 0;
	LTDC_InitStruct.LTDC_BackgroundGreenValue = 0;
	LTDC_InitStruct.LTDC_BackgroundBlueValue = 0;
	
	/* 
	   LTDCʱ������˵����
	     ����RCC_PLLSAIConfig�ĵ�һ��������PLLSAI_N��������������PLLSAI_R��
	     ����RCC_LTDCCLKDivConfig�Ĳ�����RCC_PLLSAIDivR��
	   
	   �����һ�����ӣ�PLLSAI_N = 400�� PLLSAI_R = 4  RCC_PLLSAIDivR = 2:
	     ���ȣ�����ʱ�� PLLSAI_VCO Input = HSE_VALUE / PLL_M = 8M / 8 = 1MHz 
	       ���ʱ�� PLLSAI_VCO Output  = PLLSAI_VCO Input * PLLSAI_N = 1 * 400 = 400 1MHz 
	       PLLLCDCLK = PLLSAI_VCO Output / PLLSAI_R = 400 / 4 = 100 1MHz 
	     ��ã�LTDC ʱ�� = PLLLCDCLK / RCC_PLLSAIDivR = 100 / 2 = 50 1MHz 
	 */
				
	/* ֧��6����� */
	switch (g_LcdType)
	{
		case LCD_35_480X320:	/* 3.5�� 480 * 320 */	
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
		
			Width = 480;
			Height = 272;
			HSYNC_W = 10;
			HBP = 20;
			HFP = 20;
			VSYNC_W = 20;
			VBP = 20;
			VFP = 20;
			break;
		
		case LCD_43_480X272:		/* 4.3�� 480 * 272  ѡ��LTDC���20MHz��������ɫ��ȶ�����ѡ�����ʱ��Ƶ�� */
			RCC_PLLSAIConfig(280, 2,  7);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div2);

			Width = 480;
			Height = 272;

			HSYNC_W = 40;
			HBP = 2;
			HFP = 2;
			VSYNC_W = 9;
			VBP = 2;
			VFP = 2;
			break;
		
		case LCD_50_480X272:		/* 5.0�� 480 * 272 */
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
		
			Width = 480;
			Height = 272;
		
			HSYNC_W = 40;
			HBP = 2;
			HFP = 2;
			VSYNC_W = 9;
			VBP = 2;
			VFP = 2;			
			break;
		
		case LCD_50_800X480:		/* 5.0�� 800 * 480��24λ����32λɫѡ��LTDC���15MHz��16λ����8λ30MHz */
			RCC_PLLSAIConfig(420, 2,  7);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);

			Width = 800;
			Height = 480;

			HSYNC_W = 96;	
			HBP = 10;
			HFP = 10;
			VSYNC_W = 2;
			VBP = 10;
			VFP = 10;			
			break;
		
		case LCD_70_800X480:		/* 7.0�� 800 * 480��24λ����32λɫѡ��LTDC���15MHz��16λ����8λ30MHz*/
			RCC_PLLSAIConfig(420, 2,  7);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div2);
			
			#if 0
				RCC_PLLSAIConfig(400, 2,  2);
				RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
			#endif
			Width = 800;
			Height = 480;

			HSYNC_W = 90;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 10;
			HFP = 10;
		
			VSYNC_W = 10;
			VBP = 10;
			VFP = 10;	
			break;
		
		case LCD_70_1024X600:		/* 7.0�� 1024 * 600 */
			LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;	/* HSYNC �͵�ƽ��Ч */
			LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;	/* VSYNC �͵�ƽ��Ч */
			LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;	/* DE �͵�ƽ��Ч */
			LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IIPC;
		
			/* IPS 7�� 1024*600��  ����ʱ��Ƶ�ʷ�Χ : 57 -- 65 --- 70.5MHz 
		
				PLLSAI_VCO Input   = HSE_VALUE / PLL_M = 8M / 4 = 2 Mhz
				PLLSAI_VCO Output  = PLLSAI_VCO Input * PLLSAI_N =   2 * 429 = 858 Mhz
				PLLLCDCLK = PLLSAI_VCO Output / PLLSAI_R = 858 / 4 = 214.5 Mhz
				LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDivR = 214.5 / 4 = 53.625 Mhz 	

				(429, 2, 4); RCC_PLLSAIDivR_Div4 ʵ������ʱ�� = 53.7M
			*/
			RCC_PLLSAIConfig(429, 2, 6);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div4);
		
			Width = 1024;
			Height = 600;

			HSYNC_W = 2;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 157;
			HFP = 160;
		
			VSYNC_W = 2;
			VBP = 20;
			VFP = 12;			
			break;
		
		default:
			RCC_PLLSAIConfig(429, 2,  4);
			RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);

			Width = 800;
			Height = 480;

			HSYNC_W = 80;	/* =10ʱ����ʾ��λ��20ʱ���������Ե�,80ʱȫ��OK */
			HBP = 10;
			HFP = 10;
			VSYNC_W = 10;
			VBP = 10;
			VFP = 10;			
			break;
	}
	
	g_LcdWidth  = Width;		/* ��ʾ���ֱ���-��� */
	g_LcdHeight = Height;		/* ��ʾ���ֱ���-�߶� */
	
	/* ʹ�� PLLSAI */
	RCC_PLLSAICmd(ENABLE);
	/* �ȴ���� */
	while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET);
	
	/* ����LTDC��ͬ��ʱ�� */
	LTDC_InitStruct.LTDC_HorizontalSync = HSYNC_W;
	LTDC_InitStruct.LTDC_VerticalSync = VSYNC_W;
	LTDC_InitStruct.LTDC_AccumulatedHBP = LTDC_InitStruct.LTDC_HorizontalSync + HBP;
	LTDC_InitStruct.LTDC_AccumulatedVBP = LTDC_InitStruct.LTDC_VerticalSync + VBP;
	LTDC_InitStruct.LTDC_AccumulatedActiveW = Width + LTDC_InitStruct.LTDC_AccumulatedHBP;
	LTDC_InitStruct.LTDC_AccumulatedActiveH = Height + LTDC_InitStruct.LTDC_AccumulatedVBP;
	LTDC_InitStruct.LTDC_TotalWidth = LTDC_InitStruct.LTDC_AccumulatedActiveW + HFP;
	LTDC_InitStruct.LTDC_TotalHeigh = LTDC_InitStruct.LTDC_AccumulatedActiveH + VFP;

	LTDC_Init(&LTDC_InitStruct);
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
