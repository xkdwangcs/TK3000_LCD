#ifndef FILEOPERATE_H_
#define FILEOPERATE_H_

#ifdef __cplusplus
 extern "C" {
#endif 

#include <stm32f4xx.h>
#include "string.h"
//#include "SPIFlashBase.h"
#include "stdbool.h"
#include "FATFS/src/ff.h"
#include "FATFS/src/integer.h"
#include "FATFS/src/diskio.h"
//#include "RTC_F4xx.h"
#include "Handlers.h"
	 
typedef struct
{
	char FileName[50];	//�ļ�����	
	int DateTime;	    //�޸����ڼ�ʱ��
} SortFileSturct;       //Ҫ������ļ��ṹ��

//extern u8 _tempArray[FLASH_SECTOR_SIZE*4]; //������չ�ڴ����

void GetFileListTask(void);	 
//�ɴ��̱�ŵó������ַ���
char* GetDiskStr(u8 diskID);
//����ȫ·���еõ��̷�,����������̷��򷵻�"0:/"
char* GetDiskStrByFullPath(char* fullPath);    
//���ļ����л�ȡ��չ��
char* GetExtName(char* fileName);	 
//��ʽ��ָ������
void FormatDisk(u8 diskID);
//��ָ���Ĵ����ϴ���һ��Ŀ¼�����Ŀ¼�Ѵ���Ҳ�������֧��һ�δ����༶Ŀ¼
//path:���̷���·������������̷�ʱĬ��Ϊ0�Ŵ��̣�Ҳ��������ȫ�ļ�·�����磺1:/AA/BB/CC/test.txt
FRESULT CreateDir_in(char* path);
//��ָ���Ĵ����ϴ���һ��Ŀ¼�����Ŀ¼�Ѵ���Ҳ�������֧��һ�δ����༶Ŀ¼
//path:���̷���·������������̷�ʱĬ��Ϊ0�Ŵ���
void CreateDirOnDisk(char* path);
//����һ���ļ���fileName:���̷������û���̷���Ĭ��Ϊ0�Ŵ��̡�֧�ֶ༶Ŀ¼���磺1:/AA/BB/CC/test.txt
//���Ŀ¼���������Զ�������isConver:�Ƿ񸴸�ԭ���ļ�
FRESULT CreateFileOnDisk(char* fileName,bool isConver);
//��ָ���Ĵ�����ɾ���ļ���fileName:���̷������û���̷���Ĭ��Ϊ0�Ŵ��̡��磺1:/AA/test.txt
void DeleteFileOnDisk(char* fileName);
//ɾ��ָ��Ŀ¼�µ������ļ�
void DeleteAllFileOnDir(char* dirPath);
//�������ļ���oldName�����̷������û���̷���Ĭ��Ϊ0�Ŵ��̡��磺1:/dir1/abc.txt��newName:1:/dir1/ok.txt
void RenameOnDisk(char* oldName,char* newName);
//��ȡָ��Ŀ¼�µ������ļ���,�����ļ�������dirPath:Ŀ¼·����fileList:�������ṩ�Ļ��棬��ά�ַ�����
//rowCount:�ж����У�rowItemCount:ÿ�е�Ԫ�ظ�����fileterExt:���ڹ����ļ�������չ����NULLʱ������
u16 GetFileList_Dir(char* dirPath, char* fileList,u16 rowCount,u16 rowItemCount,char* filterExt);
//��ȡָ��Ŀ¼�µ������ļ������޸�ʱ��,�����ļ�������dirPath:Ŀ¼·����fileList:�������ṩ�Ļ���
//rowCount:��������ж����У�fileterExt:���ڹ����ļ�������չ����NULLʱ������
u16 GetFileListDateTime_Dir(char* dirPath, SortFileSturct* fileList,u16 rowCount,char* filterExt);
//��һ��ָ�����ļ�
FRESULT OpenFile(char* fileName,u8 openMode,FIL* fs);
//�ر�ָ�����ļ�
FRESULT CloseFile(FIL* file,char* fileName);


//��ָ�����ļ���ָ��λ�ÿ�ʼд�����ݡ������ʼλ�ô����ļ���С�����ļ����ʼд��
//fileName:�����̷�����ȫ·��,��:0:/CFG/Parameter.txt
void WriteBytesToFile(char* fileName,u8* data,u32 startIndex,u32 length);
//��ָ�����ļ���ָ��λ�ÿ�ʼ�������ݡ������ʼλ�ô����ļ���С������ִ�ж�����
//fileName:�����̷�����ȫ·��,��:0:/CFG/Parameter.txt��
void ReadBytesFormFile(char* fileName,u8* readBuff,u32 startIndex,u32 readLenght);
////ɾ��ָ���ļ�������ݡ�startIndex:��0��ʼ����������ʼɾ����λ�ã�count:Ҫɾ�����ֽڸ���
//void DeleteBytes(FIL* openedFile,u32 startIndex,u32 count);
////ɾ��ָ���ļ�������ݡ�startIndex:��0��ʼ����������ʼɾ����λ�ã�count:Ҫɾ�����ֽڸ���
////fileName:�����̷�����ȫ·��,��:0:/DATA/NewFile.dat��
//void DeleteBytesOnFile(char* fileName,u32 startIndex,u32 count);
//���ļ��������ݡ�startIndex:��0��ʼ����������ʼ�����λ�ã�count:Ҫ������ֽڸ���
//void InsetBytes(FIL* openedFile,u8* data,u32 startIndex,u32 count);
////���ļ��������ݡ�startIndex:��0��ʼ����������ʼ�����λ�ã�count:Ҫ������ֽڸ���
//void InsetBytesOnFile(char* filePath,u8* data,u32 startIndex,u32 count);

//���ļ�β���һ���ı����ݣ��ı�������"/0"��β
void AppendCharsToFile(char* fileName,char* data);
//��ָ���ļ���ĩβ����ֽ����ݡ�count:Ҫ������ֽڸ���
//void AppendBytesToFile(FIL* openedFile,u8* data,u32 count);
//����һ���ļ�
//sourPathFile:Դ�ļ����磺0:/CDATA/abc.txt�� destPathFile��Ŀ���ļ�����: 1:/CDATA/efd.txt��isCoverFile:�Ƿ񸲸������ļ�
bool CopyFile(char* sourPathFile,char* destPathFile,bool isCoverFile);
//��һ��Ŀ¼�µ������ļ����Ƶ�Ŀ��Ŀ¼�����Ŀ��Ŀ¼���������Զ����������Կ���̸��ơ�
//sourcDir:ԴĿ¼���磺0:/CDATA�� destDir��Ŀ��Ŀ¼����: 1:/CDATA��isCoverFile:�Ƿ񸲸������ļ�
bool CopyAllFile_Dir(char* sourcDir,char* destDir,bool isCoverFile,OneStrParameterHandler showMSG);
//�жϴ����Ƿ�δ��ʽ��������ǣ����ʽ��
void PDFormatFlash(void);

//��ȡ�ļ���С
int GetFileSize(char* fileName);
//�������ļ�
u8* ReadFullFile(char* fileName,int* fileSize);

//�������ļ�
bool ReadFullFile1(char* fileName,u8* readBuff);

#ifdef __cplusplus
}
#endif

#endif
