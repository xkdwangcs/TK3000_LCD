#ifndef PARAMETER_H_
#define PARAMETER_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"
#include "PublicFunction.h"
#include "Handlers.h"
#include "Protocol.h"
  
  #define InPortNum 24  //����˿����� 
#define OutPortNum 16 //����˿�����   
#define FixPortNum 6  	//�ض�����˿ڵ���Ŀ	 	
#define MotorPortNum 6    	//Ӳ�����ܽ�������������
	
extern Dictionary _yesNoDic[2];

  typedef struct
{
	float X;
	float Y;
	float Z;
} CoordStruct;//����ṹ

typedef enum
{
	ZFX = 0, 	//����1,������
	FFX = !ZFX	//����2,������
} DirectEnum;//����ö��

typedef enum
{
	LEFT_LIMIT = 0, 
	RIGHT_LIMIT, 
	LEFT_RIGHT_LIMIT,
	NO_LIMIT,
} LimitModeEnum;//��λģʽ��Ӧ��Ҫ�ŵ�������
  
typedef enum
{
	NoLogined=0,    //δ��½��δ�����κ�Ȩ�����͵�����
	UserPer,        //�û�Ȩ��	
	AdminiPer,      //����ԱȨ��
	DevicePer,		//�豸����ԱȨ��
	SuperPer,       //����Ȩ��
}PermissionTypeEnum;//Ȩ�޵ȼ����ͣ�Ŀǰֻ������������Ȩ�޵ȼ���δ���û���

	//��˿�����ṹ
	typedef struct
	{
		float length;			//��˿����
		float TimeDLimit;		//��λ��s������˿��ʱ�����ޣ������жϸ���
		float TimeULimit;		//��λ��s������˿��ʱ�����ޣ������жϻ���
	} ScrewParaStruct;

	//ȡ�ϲ���
	typedef struct
	{
		CoordStruct Coord;				//ȡ������
		float heigth;							//ȡ�ϸ߶�
		float getScrewSpeed;			//ȡ���ٶ�
		float getDelayTime;				//�����ʱ��ȡ����ʱ
	} GetScrewParaStruct;

	//���ϴ���ʽ
	typedef enum
	{
		IGNORE = 0,  //����ģʽ
		WAIT  		//�ȴ�ģʽ
	} FaultModeEnum;

	//������ģʽ
	typedef enum
	{
		Keep = 0,  //����ģʽ
		Twinkle  	//��˸ģʽ
	} AlarmLampModeEnum;

	typedef enum
	{
		QFQQ=0,		//ǰ��ǰȡ
		QFHQ,		//ǰ�ź�ȡ
	}GJQFModeEnum; //����ȡ��ģʽ

	typedef enum
	{
		DoublePlatform,//˫ƽ̨
		SinglePlatform,//��ƽ̨  
		CustomMovePlat,//�Զ��嶯����ƽ̨��������˿
	}ProdTypeEnum;//��Ʒ����	
	
	typedef enum
	{
		MotorDown,	//�����ѹ����˿
		QGDown,		//������ѹ����˿
		THDown,		//������ѹ����˿
	}LockScrewTypeEnum;//����˿ģʽö��
	
	typedef enum
	{
		SuckScrew,	//����˿
		BlowScrew,	//����˿
		OutScrew,	//�Զ�����˿
	}GetScrewTypeEnum;//ȡ��˿ģʽö��

	typedef struct
	{
		/********�ͻ�������Ϣ**********/
		char ProdName[32];                          //��Ʒ����
		char ProdModel[16];                         //��Ʒ�ͺ�
        char ProdID[16];		                    //��Ʒ���к�        
		char ProduDate[16];                   		//��������	
		char Tel[16];								//��ϵ�绰
		char URL[32];								//��˾��ַ
		char Company[32];							//������λ
		char CompanyAddr[80];                       //������λ��ַ
		/***********************************/		
		
		/**************�豸����*************/
		u8 DeviceAddr;								//������ַ
		u32 Baud;									//�豸������   
		CommChannelEnum	CommChannel;				//����ͨ��ͨ��
		float PulseK[MotorPortNum];					//���嵱��
		float AxisLength[MotorPortNum];				//�г̳���							
		float RunSpeed[MotorPortNum];				//���������ٶ� mm/s
		float AccSpeed[MotorPortNum];				//���ٶ� mm/s
		float DecSpeed[MotorPortNum];				//���ٶ� mm/s	
		LimitModeEnum LimitMode[MotorPortNum];		//��λģʽ
		float OffsetZeroPoint[MotorPortNum];		//ƫ�����,���ԭ��ƫ������λ���ľ���		
		float LinkageSafeSmooth;					//����ʱ�İ�ȫƽ���� %
		LockScrewTypeEnum LockScrewType;			//����˿ģʽ
		GetScrewTypeEnum GetScrewType;				//ȡ��˿ģʽ
		bool BakByte;//IsUseFSGG;					//�Ƿ����ø������,Ԥ�����ֽڣ�����ʱ������д�����ļ�
		bool IsShowDebugMsg;						//�Ƿ���ʾ������Ϣ
		/***********************************/		
		
		float WorkHeight;							//�����߶�(��ȫ�߶�)
		float ScrewLockSpeed;						//����˿ʱ���ٶ� %
		float ResetSpeed;							//��λ�ٶ�,mm/s
		ScrewParaStruct ScrewPara;					//��˿����
		GetScrewParaStruct GetScrewPara;		    //ȡ��˿��ز���
		u32 AutoResetNum;							//�Զ���λ�Ĵ���(N�θ�λ)
		float StartWorkDelay; 					    //ʹ�á��ż�����ʱ����������ʱ
		FaultModeEnum FaultMode;		    		//���ϴ���ģʽ
		bool IsGetScrew;							//�Ƿ�ȡ��
		bool IsScrewCheck;							//�Ƿ���ռ��(��˿�������)
		bool IsWorkpieceCheck;		        		//�����Ƿ���
		bool IsFJQD;			    				//�ż��Ƿ�����
		GJQFModeEnum QFMode;				        //ȡ�Ź�������ģʽ
		AlarmLampModeEnum AlarmLampMode;		    //������ģʽ---����or��˸
		float AlarmBuzzerTime;						//����������ʱ�䳤�����ã���λ��s
		float GainWorkpieceDelayTiem;				//ȡ������ʱ,s
		char AdminiPass[10];						//����Ա���룬���޸ĵ�
		char UserPass[10];							//�û�����
		float ZKTQLength;							//�����ǰ�����ľ���,��λΪmm
		float DPTQLength;							//������ǰ�����ľ���,��λΪmm
		float PTSpeed;								//�㶯�ٶȰٷֱ� %
		
		float WorkSpeedPercent;                     //�����ٶȰٷֱ� %
		ProdTypeEnum ProdType;                      //��ǰϵͳ������  
        char WorkFileName[32];                      //��ǰ�������ļ���	
		bool IsFGBJ;								//��⵽���ߺ��Ƿ񱨾�
		bool IsFYBJ;								//��⵽�������Ƿ񱨾�
		float Y1MoveCoord;							//Y1�������꣬�����ļ������
		float Y2MoveCoord;							//Y2�������꣬�����ļ������
		float NLDelay;								//Ť����ʱ��s
		u16 ScrewTimeDown;							//����˿����ʱ������,ms
		u16 ScrewTimeUP;							//����˿����ʱ������,ms		
		float LockQGDelay;							//�������״���ʱ
		float PushDelay;							//���Ͽ�����ʱ
		float BlowDelay;							//���Ͽ�����ʱ
    char ParaVer[7];							//�����汾�������Զ���������������������ʱ��д         
	} ParameterStruct;		//�����ṹ��

  
extern  ParameterStruct Parameter;
#ifdef __cplusplus
}
#endif

#endif 
