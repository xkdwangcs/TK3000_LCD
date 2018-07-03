#include "Protocol.h"
#include "CMD.h"
#include "COM.h"
#include "Parameter.h"

char *_cmdERR = "CMDERR";
char *_crcERR = "CRCERR";
char *_tailERR = "TAILERR";
char *_funcERR = "FUNCERR";

u8 _head = 0xAB;
u8 _tail = 0xBA;
u8 _destAddr = 0x01;
u8 _sourAddr = 0x08;
u16 _poly = 0x1021; //crc���ɶ���ʽ
u8 _dataOverBytes=33; //����������ֽ���

//������ջ���
ProtocolBuffStruct _cmdRecvBuff;
//����ͻ���
ProtocolBuffStruct _cmdSendBuff;
u16 _recvStartIndex=0;

//��ȡ���ζ����е���ʵ��ַ
u16 GetAddrReal(u16 addr)
{
	if(addr<_comBuffLeng)
		return addr;
	return addr-_comBuffLeng;
}

//����CRC16
u16 CRC16ByPoly(u8 *data, u16 startIndex, u16 length)
{
	u16 crc = 0;
	u16 i = 0;
	u8 bt, b1, b2;
	while (length-- > 0)
	{
		bt = data[startIndex++];
		for (i = 0; i < 8; i++)
		{
			b1 = (crc & 0x8000) != 0;
			b2 = (bt & 0x80) != 0;
			if (b1 != b2)
				crc = (u16) ((crc << 1) ^ _poly);
			else
				crc <<= 1;
			bt <<= 1;
		}
	}
	return crc;
}

//AB LEN1 LEN2 ADDR1 ADDR2 PNUM PID FUN1 FUN2 FUN3 CNAME1..CNAME20 data1....dataN CRC1 CRC2 BA
//�����������ð��İ���
//�����д��ļ��Ĵ��䣬Ҫʵ�ְַ�
u16 Package(char* func,char* cmdName,u8* cmdData,u16 dataLeng)
{
	u16 length = dataLeng + _dataOverBytes;
	memset((u8*)&_cmdSendBuff,0,sizeof(_cmdSendBuff));
	_cmdSendBuff.Head = _head;
	_cmdSendBuff.Length = length;
	_cmdSendBuff.DestAddr= _destAddr;
	_cmdSendBuff.SourAddr = _sourAddr;
	_cmdSendBuff.PackNum=0x00;
	_cmdSendBuff.PackID=0x00;
	strcpy(_cmdSendBuff.FunCode,func);
  strcpy(_cmdSendBuff.CmdName,cmdName);
  CopyBytes((u8*)&_cmdSendBuff.CmdData,0,cmdData,dataLeng);
	u16 crc16 = CRC16ByPoly((u8*)&_cmdSendBuff, 1, length - 4);
	_cmdSendBuff.CmdData[dataLeng] = crc16 / 256;
	_cmdSendBuff.CmdData[dataLeng + 1] = crc16 % 256;
	_cmdSendBuff.CmdData[dataLeng + 2] = _tail;
  _cmdSendBuff.DataLeng=dataLeng;
	return length;
}

void DisPackage(void)
{
	u16 packLeng = 0;
	u16 tailAddr=0;
	_recvStartIndex=0;
  _cmdRecvBuff.RecvOK=false;
  for(int i=0;i<5;i++)
  {
      u16 num=0;
      bool isHavePack=false;
      while(num<_comBuffLeng)
      {
        num++;
        if (_DMARecvBuff[_recvStartIndex] == _head)
        {
          packLeng = (u16) (_DMARecvBuff[GetAddrReal(_recvStartIndex+2)] << 8 | _DMARecvBuff[GetAddrReal(_recvStartIndex+1)]);
          tailAddr=GetAddrReal(_recvStartIndex+packLeng - 1);
          if (_DMARecvBuff[tailAddr] == _tail) //��β��ȷ
          {
            isHavePack=true;
            break;
          }
//          else
//          {
//            SendCharsPack(_srq,_tailERR);
//          }
        }
        _DMARecvBuff[_recvStartIndex]=0;
        _recvStartIndex=GetAddrReal(_recvStartIndex+1);
      }
      if(!isHavePack)//�������Ч��
        return;
      memset((u8*)&_cmdRecvBuff,0,sizeof(_cmdRecvBuff));
      u8* cmdRecvP=(u8*)&_cmdRecvBuff;
      for(u16 i=0;i<packLeng;i++)
      {
        u16 addr=GetAddrReal(_recvStartIndex+i);
        *cmdRecvP=_DMARecvBuff[addr];
        cmdRecvP++;
        _DMARecvBuff[addr]=0;
      }
      u16 cmdDataLeng=packLeng-_dataOverBytes;
      cmdRecvP=(u8*)&_cmdRecvBuff;
      u16 recCRC = (u16) (cmdRecvP[packLeng - 3] << 8 | cmdRecvP[packLeng - 2]);
      u16 calcCRC = CRC16ByPoly(cmdRecvP, 1, packLeng - 4);
//      if (recCRC != calcCRC)
//      {
//        SendCharsPack(_srq,_crcERR);
//      }
      cmdRecvP[packLeng - 3]=0;
      cmdRecvP[packLeng - 2]=0;
      cmdRecvP[packLeng - 1]=0;
      _cmdRecvBuff.DataLeng=cmdDataLeng;
      _recvStartIndex= GetAddrReal(_recvStartIndex+packLeng);
      _cmdRecvBuff.RecvOK=true;
      CMDAnalysis();
      //��̽�����Ƿ������ݰ�
      isHavePack=false;
      for(u16 i=0;i<3;i++)//���3���ֽڶ�Ϊ0����Ϊ����Ч����
      {
        if(_DMARecvBuff[_recvStartIndex+i]!=0)
        {			
          isHavePack=true;
          break;
        }
      }
      if(!isHavePack)
        return;
    }
	}

//�������,recvPack�����յ���commChannel����ǰ���յ�ͨ��ͨ��
void CMDAnalysis(void)
{
	u16 packLeng = 0;
	if(strncmp(_cmdRecvBuff.FunCode, _rdd, 3) == 0)
	{
		RDDProcess();
	}
	else if(strncmp(_cmdRecvBuff.FunCode, _wrt, 3) == 0)
	{
		WRTProcess();
	}
	else if(strncmp(_cmdRecvBuff.FunCode, _srq, 3) == 0)
	{
		SRQProcess();
	}
	else
	{
		//packLeng = PackageChars(_oneSendPackBuff_COM1,_recPacket.func, _funcERR);
		//SendBytes_COM1( _oneSendPackBuff_COM1, packLeng);
	}
}

//��ΪӦ������ݷ���
void ResponseSendData(char* func, u16 cmdDataLeng)
{
//	if(Parameter.CommChannel==RS232)
//	{
//		u16 leng=Package(_protocolBuff.CmdBuff,func,cmdDataLeng);
//		SendBytes_COM1((u8*)_protocolBuff.CmdBuff,leng);
//	}
//	else if(_currCommChannelEnum==WIFI)
//	{
//		SendCharsPack_WIFI(func,cmdData);
//	}
}

//��ָ���Ĵ��ڷ�������������
void SendBytes_Pack(char* func,char* cmdName, u8* cmdData,u16 cmdLeng)
{
	u16 leng=Package(func,cmdName,cmdData,cmdLeng);
	SendBytes_COM1((u8*)&_cmdSendBuff,leng);
}

//��ָ���Ĵ��ڷ�������������
void SendChars_Pack(char* func,char* cmdName, char* cmdData)
{
	u16 leng=Package(func,cmdName,(u8*)cmdData,strlen(cmdData));
	SendBytes_COM1((u8*)&_cmdSendBuff,leng);
}


