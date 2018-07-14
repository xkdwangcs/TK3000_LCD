#include "FileOperate.h"
#include "stdlib.h"
#include "stdbool.h"
#include "PublicFunction.h"
#include "MemoryAlloc.h"
#include "bsp_nand_flash.h"

u8 _fileBuff[FLASH_SECTOR_SIZE] __at(FileBuffAddr);
//u8 _tempArray[FLASH_SECTOR_SIZE*4]__at(FileOPTempAddr);	

//��ȫ·�����棬����
char _fullPathBuff[2][50];
//�ɴ��̱�ŵó������ַ���
char* GetDiskStr(u8 diskID)
{
     if(diskID==0)
         return "0:/";
     else if(diskID==1)
         return "1:/";
     else if(diskID==2)
         return "2:/";
}

char _diskStr[3];
//����ȫ·���еõ��̷�,����������̷��򷵻�"0:/"
char* GetDiskStrByFullPath(char* fullPath)
{
   if(fullPath[1]==0x3A && fullPath[2]==0x2F)
   {
      _diskStr[0]=fullPath[0];
      _diskStr[1]=fullPath[1];
      _diskStr[2]=fullPath[2];
      return _diskStr;
   }           
   return "0:/";
}

char _extName[5];
//���ļ����л�ȡ��չ��
char* GetExtName(char* fileName)
{
	u16 leng=strlen(fileName);
	u16 index=0;
	for(index=leng;index>=0;index--)
	{
		if(fileName[index]=='/')//������ҵ���Ŀ¼������ʾ���ļ�
		{
			return NULL;
		}
		if(fileName[index]=='.')
		{
			break;
		}
	}
	index++;
	memset(_extName,0,sizeof(_extName));
	u8 count=leng-index;
	for(u8 i=0;i<count;i++)
	{
		_extName[i]=fileName[i+index];
	}
	return _extName;
}

//�ɶ����ż��ļ�·����ȡ����·��
char* GetFullPath_mdisk(u8 diskID,const char* dirFileName)
{
    char *fpb = _fullPathBuff[diskID];
    memset(fpb,0,sizeof(_fullPathBuff[0]));
    sprintf(fpb,"%s%s",GetDiskStr(diskID),dirFileName);
    return fpb; 
}

FRESULT _res;
//��ʽ��ָ������
void FormatDisk(u8 diskID)
{
  char* diskStr=GetDiskStr(diskID);   
	//FRESULT res = f_mkfs(diskStr,1,_MAX_SS); //0.12
	_res = f_mkfs(diskStr,FM_ANY,0,_fileBuff,sizeof(_fileBuff)); //0.12b
}


char pathBuff[80]={0};
char tpath[80]={0};
//��ָ���Ĵ����ϴ���һ��Ŀ¼�����Ŀ¼�Ѵ���Ҳ�������֧��һ�δ����༶Ŀ¼
//path:���̷���·������������̷�ʱĬ��Ϊ0�Ŵ��̣�Ҳ��������ȫ�ļ�·�����磺1:/AA/BB/CC/test.txt
FRESULT CreateDir_in(char* path)
{
    FRESULT res=FR_OK;
    char* diskStr=GetDiskStrByFullPath(path);    
	memset(pathBuff,0,sizeof(pathBuff));
	memset(tpath,0,sizeof(tpath));
    tpath[0]=diskStr[0];
    tpath[1]=diskStr[1];
    u8 pcount=0;
    LIST* plist=SplitString(path,"/", &pcount);
    for(u8 i=0;i<pcount;i++)
    {   
        if(i==0 && strstr(plist[i].item,":") !=NULL)//������̷����磺0:
            continue;
        if(i==pcount-1 && strstr(plist[i].item,".") !=NULL) //������һ��·������"."�����ʾΪ�ļ�����"ABC.txt"
            break;
        memset(pathBuff,0,sizeof(pathBuff));
        sprintf(pathBuff,"%s%s%s",tpath,"/",plist[i].item); //Ҫ�ۼ�·��          
        res = f_mkdir(pathBuff);
        if(res!=FR_OK && res!=FR_EXIST)
            return res;
        memset(tpath,0,sizeof(tpath));
        strcpy(tpath,pathBuff);
    }
    return res;
}
   
//��ָ���Ĵ����ϴ���һ��Ŀ¼�����Ŀ¼�Ѵ���Ҳ�������֧��һ�δ����༶Ŀ¼
//path:���̷���·������������̷�ʱĬ��Ϊ0�Ŵ��̣�Ҳ��������ȫ�ļ�·�����磺1:/AA/BB/CC/test.txt
void CreateDirOnDisk(char* path)
{
    FATFS fs; 
    char* diskStr=GetDiskStrByFullPath(path);    
	FRESULT res = f_mount(&fs,diskStr,0);
	if (res != FR_OK)
	{
		return;
	}		
	//res = f_mkdir(path);
    res = CreateDir_in(path);
	res = f_mount(NULL, diskStr, 0);
}

//����һ���ļ���fileName:���̷������û���̷���Ĭ��Ϊ0�Ŵ��̡�֧�ֶ༶Ŀ¼���磺1:/AA/BB/CC/test.txt
//���Ŀ¼���������Զ�������isConver:�Ƿ񸴸�ԭ���ļ�,���ش��ļ���״̬
FRESULT CreateFileOnDisk(char* fileName,bool isCover)
{  
    u32 reindex;
    FIL file;
	FATFS fs;
    char* diskStr=GetDiskStrByFullPath(fileName);    

	u8 res = f_mount(&fs,diskStr,0);
	if (res != FR_OK)
	{
		return res;
	}
    res = CreateDir_in(fileName);//��鲢�������·��
    u8 createMode= FA_CREATE_NEW;  //�����Ե��ļ�����ʱ�������´�������д�ļ���ʱ��FR_INVALID_OBJECT����û���ļ�ʱ������������
    if(isCover)
        createMode=FA_CREATE_ALWAYS;  //���ǵ�ʱ�򴴽�ģʽҪѡ������´���һ���ļ���������д�ļ�ʱ�� res=FR_INVALID_OBJECT(09)
	res = f_open(&file,fileName,FA_READ | FA_WRITE | createMode);
    //����Ĳ�����Ҫ�����ļ��򿪵�״̬
	if (res == FR_OK)
	{	
		f_close(&file);			
	}
	f_mount(NULL, diskStr, 0);
	return res;
}

//��ָ���Ĵ�����ɾ���ļ���fileName:���̷������û���̷���Ĭ��Ϊ0�Ŵ��̡��磺1:/AA/test.txt
void DeleteFileOnDisk(char* fileName)
{
    FATFS fs;
	FIL	file;
    char* diskStr=GetDiskStrByFullPath(fileName);     
    u8 res = f_mount(&fs,diskStr,0);
    res = f_unlink(fileName);	  /* Delete a File or Directory */
    res  = f_mount(NULL, diskStr, 0);
}

char fileName[50];
//ɾ��ָ��Ŀ¼�µ������ļ�
void DeleteAllFileOnDir(char* dirPath)
{
    FATFS fs;
    FIL file;
	FILINFO finfo;
	DIR dirs;
	u16 fileIndex=0;
    char* diskStr=GetDiskStrByFullPath(dirPath);
	FRESULT res = f_mount(&fs,diskStr,0);
	res = f_opendir(&dirs, dirPath);    
	while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0]) 
	{
		if (finfo.fattrib & AM_DIR) 
		{ 
			continue;
		} 
		else 
		{  
            memset(fileName,0, sizeof(fileName));
            sprintf(fileName,"%s%s%s",dirPath,"/",finfo.fname);
			res = f_unlink(fileName);	  /* Delete a File or Directory */	
		}
	}
}

//�������ļ���oldName�����̷������û���̷���Ϊ0�Ŵ��̡��磺1:/dir1/abc.txt��newName:1:/dir1/ok.txt
void RenameOnDisk(char* oldName,char* newName)
{
    FATFS fs;
	FIL	file;
    char* diskStr=GetDiskStrByFullPath(oldName); 
    u8 res = f_mount(&fs,diskStr,0);
    res = f_rename(oldName,newName);	 
    res  = f_mount(NULL, diskStr, 0);
}   

//��һ��ָ�����ļ�
FRESULT OpenFile(char* fileName,u8 openMode,FIL* file)
{
    FATFS fs;
    DIR dirs;
    u32 re;
    FRESULT res;
   // char* diskStr=GetDiskStrByFullPath(fileName);
	//FRESULT res = f_mount(&fs,diskStr,0);
	//if (res != FR_OK)
		//return res;
	res = f_open(file,fileName,openMode);
    //if(res!=FR_OK && res!=FR_EXIST)
        //f_mount(NULL, diskStr, 0); 
    return res;
}

//�ر�ָ�����ļ�
FRESULT CloseFile(FIL* file,char* fileName)
{
    FRESULT res = f_close(file);
    //char* diskStr=GetDiskStrByFullPath(fileName);
    //res  = f_mount(NULL, diskStr, 0); 
    return res;
}

//��ȡָ��Ŀ¼�µ������ļ���,�����ļ�������dirPath:Ŀ¼·����fileList:�������ṩ�Ļ��棬��ά����
//rowCount:�ж����У�rowItemCount:ÿ�е�Ԫ�ظ�����fileterExt:���ڹ����ļ�������չ����NULLʱ������
u16 GetFileList_Dir(char* dirPath, char* fileList,u16 rowCount,u16 rowItemCount,char* filterExt)
{
	if(dirPath==NULL || fileList==NULL)
		return 0;
	FATFS fs;
    FIL file;
	FILINFO finfo;
	DIR dirs;
	u16 fileIndex=0;
	u16 ddd=sizeof(*fileList);
	char* diskStr=GetDiskStrByFullPath(dirPath);
	FRESULT res=f_mount(&fs, diskStr, 0);
	res = f_opendir(&dirs, dirPath);
	if(res) return 0;
	while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0]) 
	{
		if (finfo.fattrib & AM_DIR) 
		{ 
			continue;
		} 
		else 
		{  
			if(*finfo.fname=='\0')
				continue;
			if(fileIndex>=rowCount)//����������������������
				break;
			//ִ���˹��˵��⼸�д���󣬽�����USB�򿪳���FR_NO_ENABLE��ԭ�����
			//����Ŀǰ�ò��ϴ˹��ܣ���ʱ����
//			if(filterExt!=NULL) 
//			{				
//				char* extName = GetExtName(finfo.fname);
//				if(!StrCMP_n(extName,filterExt,strlen(extName)))
//					continue;
//			}
			strcpy(fileList+fileIndex*rowItemCount,finfo.fname);
			fileIndex++;		
		}
	}
    res = f_closedir(&dirs);
    res = f_mount(NULL,diskStr, 0);
	return fileIndex;
}

//��ȡָ��Ŀ¼�µ������ļ������޸�ʱ��,�����ļ�������dirPath:Ŀ¼·����fileList:�������ṩ�Ļ���
//rowCount:��������ж����У�fileterExt:���ڹ����ļ�������չ����NULLʱ������
u16 GetFileListDateTime_Dir(char* dirPath, SortFileSturct* fileList,u16 rowCount,char* filterExt)
{
	if(dirPath==NULL || fileList==NULL)
		return 0;
	FATFS fs;
    FIL file;
	FILINFO finfo;
	DIR dirs;
	u16 fileIndex=0;
	u16 ddd=sizeof(*fileList);
	char* diskStr=GetDiskStrByFullPath(dirPath);
	FRESULT res=f_mount(&fs, diskStr, 0);
	res = f_opendir(&dirs, dirPath);
	if(res) return 0;
	while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0]) 
	{
		if (finfo.fattrib & AM_DIR) 
		{ 
			continue;
		} 
		else 
		{  
			if(*finfo.fname=='\0')
				continue;
			if(fileIndex>=rowCount)//����������������������
				break;
			//ִ���˹��˵��⼸�д���󣬽�����USB�򿪳���FR_NO_ENABLE��ԭ�����
			//����Ŀǰ�ò��ϴ˹��ܣ���ʱ����
//			if(filterExt!=NULL) 
//			{				
//				char* extName = GetExtName(finfo.fname);
//				if(!StrCMP_n(extName,filterExt,strlen(extName)))
//					continue;
//			}
			strcpy(fileList[fileIndex].FileName,finfo.fname);
			fileList[fileIndex].DateTime=(int)(finfo.fdate<<16|finfo.ftime);
			fileIndex++;		
		}
	}
    res = f_closedir(&dirs);
    res = f_mount(NULL,diskStr, 0);
	return fileIndex;
}

//��ָ�����ļ���ָ��λ�ÿ�ʼд�����ݡ������ʼλ�ô����ļ���С�����ļ����ʼд��
//fileName:�����̷�����ȫ·��,��:0:/CFG/Parameter.txt��
void WriteBytesToFile(char* fileName,u8* data,u32 startIndex,u32 length)
{
    FIL file;
	FATFS fs;    
	u32 reindex;
    char* diskStr=GetDiskStrByFullPath(fileName);
	FRESULT res = f_mount(&fs,diskStr,0);	                        
    res = f_open(&file,fileName,FA_WRITE);
	if (res == FR_OK)
	{	
        if(startIndex>file.obj.objsize)
            startIndex=file.obj.objsize;
		f_lseek(&file,startIndex);
		res = f_write(&file,data,length,&reindex);
	}
	f_close(&file);
    res  = f_mount(NULL, diskStr, 0);
}

//��ָ�����ļ���ָ��λ�ÿ�ʼ�������ݡ������ʼλ�ô����ļ���С������ִ�ж�����
//fileName:�����̷�����ȫ·��,��:0:/CFG/Parameter.txt��
void ReadBytesFormFile(char* fileName,u8* readBuff,u32 startIndex,u32 readLenght)
{
    FATFS fs;
	FIL	file;
    u32 re;
    char* diskStr=GetDiskStrByFullPath(fileName);
	FRESULT res = f_mount(&fs,diskStr,0);
	res = f_open(&file,fileName,FA_READ);
	if (res == FR_OK)
	{
        if(startIndex<=file.obj.objsize)
        {
			u32 canReadMax=file.obj.objsize-startIndex;//���Զ�����󳤶�
			if(readLenght>canReadMax)
				readLenght=canReadMax;
			f_lseek(&file,startIndex);
            res = f_read(&file,readBuff,readLenght,&re);
        }
	}
	res = f_close(&file);
	res = f_mount(NULL, diskStr, 0);
}

//��ȡ�ļ���С
int GetFileSize(char* fileName)
{
    FATFS fs;
    FIL	file;
    u32 re;
    FRESULT res;
    char* diskStr=GetDiskStrByFullPath(fileName);
	//res = f_mount(&fs,diskStr,0); 
	res = f_open(&file,fileName,FA_READ);
	if (res == FR_OK)
	{
        res = f_close(&file);
        return file.obj.objsize;
    }
    res = f_close(&file);
    return 0;
}

const u32 _fullFileMaxSize=0x64000;
u8 _fullFileBuff[_fullFileMaxSize]__at(FullFileBuffAddr);
//�������ļ�
u8* ReadFullFile(char* fileName,int* fileSize)
{
    FATFS fs;
	FIL	file;
    u32 re;
    FRESULT res;
    char* diskStr=GetDiskStrByFullPath(fileName);
	//res = f_mount(&fs,diskStr,0);//���ܼ��أ������ȡ����� 
	res = f_open(&file,fileName,FA_READ);
	if (res == FR_OK)
	{
		u32 fsize=file.obj.objsize;//�ļ���С
        * fileSize=fsize;
        if(fsize>_fullFileMaxSize)
        {
            res = f_close(&file);
            return NULL;
        }
        memset(_fullFileBuff,0,_fullFileMaxSize);
        res = f_read(&file,_fullFileBuff,fsize,&re);
	}
	res = f_close(&file);
    return _fullFileBuff;
}

//�������ļ�
bool ReadFullFile1(char* fileName,u8* readBuff)
{
    FATFS fs;
	FIL	file;
    u32 re;
    FRESULT res;
    char* diskStr=GetDiskStrByFullPath(fileName);
	//res = f_mount(&fs,diskStr,0);//���ܼ��أ������ȡ����� 
	res = f_open(&file,fileName,FA_READ);
	if (res == FR_OK)
	{
		u32 fsize=file.obj.objsize;//�ļ���С
        //u32 buffSize=sizeof(readBuff);
        /*if(fsize>buffSize)
        {
            res = f_close(&file);
            //res  = f_mount(NULL, diskStr, 0);
            return false;
        }*/
        //memset(readBuff,0,buffSize);
        res = f_read(&file,readBuff,fsize,&re);
	}
	res = f_close(&file);
    //res  = f_mount(NULL, diskStr, 0);
    return true;
}

//ɾ��ָ���ļ�������ݡ�startIndex:��0��ʼ����������ʼɾ����λ�ã�count:Ҫɾ�����ֽڸ���
//void DeleteBytes(FIL* openedFile,u32 startIndex,u32 count)
//{
//       u32 re,res;
//       u32 fileBytes = openedFile->obj.objsize;//FATFS10:openedFile->fsize;//ָ���ļ����ֽڳ���
//       u32 destAddr=startIndex+count;
//       u32 moveBytes=fileBytes-destAddr;
//       if(fileBytes <= startIndex)
//           return;     
//       if(fileBytes>destAddr)
//       {
//		   //��ʼ�ļ��еĶѷ���Ҫ�㹻��Heap_Size��������������Բ��Ե��ļ���6������ʱ�����ٷ���0x00006000
//		   //u8* tempArray=(u8*) malloc(moveBytes);
//		   //u8 tempArray[moveBytes];	
//		   f_lseek(openedFile,destAddr);
//		   res = f_read(openedFile,_tempArray,moveBytes,&re);
//		   f_lseek(openedFile,startIndex);
//           res = f_write(openedFile,_tempArray,moveBytes,&re);
//		   //free(tempArray);		   
//        }
//       else //ֻ��ɾ��ĩβ��
//       {
//		   //�����κ��ƶ���ֻ���ļ���С�ı�
//       }
//       openedFile->obj.objsize=fileBytes-count;
//}

//ɾ��ָ���ļ�������ݡ�startIndex:��0��ʼ����������ʼɾ����λ�ã�count:Ҫɾ�����ֽڸ���
//fileName:�����̷�����ȫ·��,��:0:/DATA/NewFile.dat��
//void DeleteBytesOnFile(char* fileName,u32 startIndex,u32 count)
//{
//	FIL file;
//	FATFS fs;    
//	u32 reindex;
//    char* diskStr=GetDiskStrByFullPath(fileName);
//	FRESULT res = f_mount(&fs,diskStr,0);	                        
//    res = f_open(&file,fileName,FA_READ | FA_WRITE);
//	if (res == FR_OK)
//	{	
//        DeleteBytes(&file,startIndex,count);
//	}
//	f_close(&file);
//    res  = f_mount(NULL, diskStr, 0);
//}

////���ļ��������ݡ�startIndex:��0��ʼ����������ʼ�����λ�ã�count:Ҫ������ֽڸ���
////�ڴ����Ĵ��㷨�򵥡�����Ӧ�ÿ��Լ���д�����������ʹ������
//void InsetBytes(FIL* openedFile,u8* data,u32 startIndex,u32 count)
//{
//       u32 re,res;
//       u32 fileBytes = openedFile->obj.objsize;
//       u32 moveBytes=fileBytes-startIndex;
//       if(startIndex>fileBytes)
//           return; 
//	   //��ʼ�ļ��еĶѷ���Ҫ�㹻��Heap_Size��������������Բ��Ե��ļ���6������ʱ�����ٷ���0x00006000
//	   //u8* tempArray=(u8*) malloc(moveBytes);
//	   //u8 tempArray[moveBytes];
//	   if(startIndex<fileBytes)//�������λ�����м�
//       {
//		   f_lseek(openedFile,startIndex);
//		   res = f_read(openedFile,_tempArray,moveBytes,&re);
//		   f_lseek(openedFile,startIndex + count);
//           res = f_write(openedFile,_tempArray,moveBytes,&re);
//		   f_lseek(openedFile,startIndex);
//           res = f_write(openedFile,data,count,&re);
//		   //free(tempArray);
//	   }
//	   else
//	   {
//		    f_lseek(openedFile,startIndex);
//			res = f_write(openedFile,data,count,&re);
//	   }
//	   openedFile->obj.objsize=fileBytes+count;  
//}

//���ļ��������ݡ�startIndex:��0��ʼ����������ʼ�����λ�ã�count:Ҫ������ֽڸ���
//fileName:�����̷�����ȫ·��,��:0:/DATA/NewFile.dat��
//void InsetBytesOnFile(char* fileName,u8* data,u32 startIndex,u32 count)
//{
//	FIL file;
//	FATFS fs;    
//	u32 reindex;
//    char* diskStr=GetDiskStrByFullPath(fileName);
//	FRESULT res = f_mount(&fs,diskStr,0);	                        
//    res = f_open(&file,fileName,FA_READ | FA_WRITE);
//	if (res == FR_OK)
//	{	
//        InsetBytes(&file,data,startIndex,count);
//	}
//	f_close(&file);
//    res  = f_mount(NULL, diskStr, 0);
//}

//���ļ�β���һ���ı����ݣ��ı�������"/0"��β
//fileName:�����̷�����ȫ·��,��:0:/DATA/NewFile.dat��
void AppendCharsToFile(char* fileName,char* data)
{
    FIL file;
	FATFS fs;    
	u32 reindex;
    char* diskStr=GetDiskStrByFullPath(fileName);
	u8 res = f_mount(&fs,diskStr,0);	                        
    res = f_open(&file,fileName,FA_READ | FA_WRITE);
	u32 length = strlen(data);
	if (res == FR_OK)
	{	
        f_lseek(&file,file.obj.objsize);  //FATFS10:file.fsize
		res = f_write(&file,data,length,&reindex);
		if (res == FR_OK)
		{			
			f_close(&file);
			reindex = 0x00;									
		}
	}
    res  = f_mount(NULL, diskStr, 0);
}

////��ָ���ļ���ĩβ����ֽ����ݡ�count:Ҫ������ֽڸ���
//void AppendBytesToFile(FIL* openedFile,u8* data,u32 count)
//{
//    InsetBytes(openedFile,data, openedFile->obj.objsize,count);
//}


char sourDisk[3];//Դ����
char destDisk[3];//Ŀ�����
char sourFilePath[100];//Դ�ļ�
char destFilePath[100];//Ŀ���ļ�
char copyMsg[50];

//����һ���ļ�
//sourPathFile:Դ�ļ����磺0:/CDATA/abc.txt�� destPathFile��Ŀ���ļ�����: 1:/CDATA/efd.txt��isCoverFile:�Ƿ񸲸������ļ�
bool CopyFile(char* sourPathFile,char* destPathFile,bool isCoverFile)
{
	FATFS fs[2];      
    FIL fsrc, fdst;      
    FRESULT res;         
    UINT br, bw;         
	DIR dirs;
	FILINFO finfo;
	strcpy(sourDisk,GetDiskStrByFullPath(sourPathFile));
	strcpy(destDisk,GetDiskStrByFullPath(destPathFile));
	f_mount(&fs[0], sourDisk, 0);
	if(sourDisk[0]!=destDisk[0])//�������ͬһ������
	{
		f_mount(&fs[1], destDisk, 0);
	} 
    
    res = f_open(&fsrc, sourPathFile, FA_READ);//��Դ�ļ�
	if (res)		return false;
   res= CreateDir_in(destPathFile);//��鲢����Ŀ¼
    u8 createMode= FA_CREATE_NEW;
    if(isCoverFile)
        createMode=FA_CREATE_ALWAYS;  //���ǵ�ʱ�򴴽�ģʽһ��Ҫѡ�����������д�ļ�ʱ�� res=FR_INVALID_OBJECT(09)
    res = f_open(&fdst, destPathFile, FA_WRITE | createMode);
	if(res==FR_OK ||(res==FR_EXIST && isCoverFile))
	{
		//����Դ���ݵ�Ŀ���ļ�
		for (;;) 
		{
			memset(_fileBuff,0,sizeof(_fileBuff));
			res = f_read(&fsrc, _fileBuff, FLASH_SECTOR_SIZE, &br);  
			if (res || br == 0) break;
			res = f_write(&fdst, _fileBuff, br, &bw);          
			if (res || bw < br) break; 
		}
	}
	f_close(&fsrc);
	f_close(&fdst);
    f_mount(NULL, sourDisk, 0);
	if(sourDisk[0]!=destDisk[0])//�������ͬһ������
	{
		f_mount(NULL, destDisk, 0);
	}
	if(res==FR_EXIST && !isCoverFile)//�����ͬ���ļ��Ҳ�����
	{
		return false;
	}
	return true;
}

bool CopyAllFile_Dir(char* sourcDir,char* destDir,bool isCoverFile,OneStrParameterHandler showMSG)
{
    FATFS fs[2];      
    FIL fsrc, fdst;     
    FRESULT res;         
    UINT br, bw;        
	DIR dirs;
	FILINFO finfo;
	
	strcpy(sourDisk,GetDiskStrByFullPath(sourcDir));
	strcpy(destDisk,GetDiskStrByFullPath(destDir));
	res=f_mount(&fs[0], sourDisk, 0);
	if(sourDisk[0]!=destDisk[0])//�������ͬһ������
	{
		res=f_mount(&fs[1], destDisk, 0);
	} 
	
	res = f_opendir(&dirs, sourcDir);//��Դ�ļ���
	if(res) 
	{
		if(showMSG!=NULL) showMSG("��Դ�ļ��д���");
		return false;
	}
    res = CreateDir_in(destDir);//����Ŀ���ļ���
	if(res!=FR_OK && res!=FR_EXIST) 
	{
		if(showMSG!=NULL) showMSG("����Ŀ���ļ��д���");
		return false;
	}
	
	bool isOK=false;
	while ((f_readdir(&dirs, &finfo) == FR_OK) && finfo.fname[0]) 
	{
		if (finfo.fattrib & AM_DIR) 
		{ 
			continue;
		} 
		else 
		{  
			memset(sourFilePath,0,sizeof(sourFilePath));
			sprintf(sourFilePath,"%s%s%s",sourcDir,"/",finfo.fname);
			res = f_open(&fsrc, sourFilePath, FA_READ | FA_OPEN_EXISTING);//��Դ�ļ�
			if (res) continue;
			
			memset(destFilePath,0,sizeof(destFilePath));
			sprintf(destFilePath,"%s%s%s",destDir,"/",finfo.fname);
            u32 createMode= FA_CREATE_NEW;  //�����Ե��ļ�����ʱ�������´�������д�ļ���ʱ��FR_INVALID_OBJECT����û���ļ�ʱ������������
            if(isCoverFile)
               createMode=FA_CREATE_ALWAYS;  //���ǵ�ʱ�򴴽�ģʽҪѡ������´���һ���ļ���������д�ļ�ʱ�� res=FR_INVALID_OBJECT(09)
			res = f_open(&fdst, destFilePath, FA_WRITE | createMode);
			if(res==FR_OK ||(res==FR_EXIST && isCoverFile))
			{
				if(showMSG!=NULL)
                {                    
                    memset(copyMsg,0,sizeof(copyMsg));
                    sprintf(copyMsg,"%s%s","���ڸ��ƣ�",finfo.fname);					
					showMSG(copyMsg);
                }
				//����Դ���ݵ�Ŀ���ļ�
				for (;;) 
				{
					memset(_fileBuff,0,sizeof(_fileBuff));
					res = f_read(&fsrc, _fileBuff, FLASH_SECTOR_SIZE, &br);
					if (res || br == 0) break; // error or eof
					res = f_write(&fdst, _fileBuff, br, &bw);       
					if (res || bw < br) break; // error or disk full
				}
				isOK=true;
			}
			if((res!=FR_OK && res!=FR_EXIST )&& showMSG!=NULL)
			{
				showMSG("��дU���쳣��");
			}
			res = f_close(&fsrc);
			res = f_close(&fdst);
		}
	}
    res = f_closedir(&dirs);
    res = f_mount(NULL, sourDisk, 0);
	if(sourDisk[0]!=destDisk[0])//�������ͬһ������
	{
		res = f_mount(NULL, destDisk, 0);
	} 
	if(isOK)
	{
		if(showMSG!=NULL)
		{
			showMSG("������ϣ��벦��U�̣�");
		}
		return true;
	}
	else
	{
		if(showMSG!=NULL) showMSG("Դ�ļ������ļ���");
	}
	return false;
}

//�жϴ����Ƿ�δ��ʽ��������ǣ����ʽ��
void PDFormatFlash(void)
{
	NAND_Format();
	FormatDisk(FS_NAND); 
	char* fn = "0:/temp.txt";	
	char* diskStr=GetDiskStrByFullPath(fn);   
	bool isFormat=false;
	u32 reindex;
    FIL file;
	FATFS fs;
	u8 res = f_mount(&fs,diskStr,0);
	res = f_open(&file,fn,FA_READ | FA_WRITE | FA_CREATE_NEW);
	if(res==FR_NO_FILESYSTEM || res==FR_INVALID_DRIVE)
	{	
     isFormat=true;					
	}
	else if(res==FR_OK || res==FR_EXIST)
	{
		res = f_close(&file);
	}
	res = f_mount(NULL, diskStr, 0);	
	if(isFormat)
	{
		FormatDisk(FS_NAND); //��ʽ����ĵ�һ����ʾ���������ڶ��ξͿ�����
		//SystemReset();   //������������û��
	}
}

