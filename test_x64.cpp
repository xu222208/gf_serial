#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "VideoNetAPI.h"

static int LibIndex = 0;		//????
static int FileIndex = 0;		//?????????	

FILE * g_pFile;

using namespace SDK_JVTFACE;

#if 0
int NpcDevPortMapClient_int(NPC_HANDLE hDevNetPortServer, char *sUMID ,unsigned short usLocalPort)
{
//	NPC_CHAR		sUMID[32];
//	NPC_USHORT		usLocalPort;
	int ret;
	
	NPC_INT 		iTime = 0;
	
	hDevNetPortServer = NPC_F_MPI_MON_DNP_CreateDevNetPortServer(
			(char *)"dev.umeye.com",				//[IN]服务器IP地址或域名 //app.umeye.cn
			8300,						//[IN]服务器端口号
			(char *)"sdktest",					//[IN]认证ID
			(char *)"sdktest"					//[IN]认证密码
			);
	if (!hDevNetPortServer)
	{
		printf("The device network port mapping service was created error.\n");
		return 0;
	}
	printf("The device network port mapping service was created success.\n");

	while(1)
	{
		if(NPC_F_MPI_MON_DNP_CheckSrvConnState(hDevNetPortServer) == 2)
		{
			printf("connect srv success \n");			
			ret = 2;
			break;
		}
		iTime ++;
		usleep(1000*1000);
		
		printf("connect iTime = %d \n",iTime);
		if(iTime > 20)
		{
			printf("connect srv fail \n");
			return 0;
		}
	}


	//ret =NPC_F_MPI_MON_DNP_CheckSrvConnState(hDevNetPortServer);
	if(ret == 2)
	{

	//strcpy(sUMID, "xmggugfg603n");
	//usLocalPort = 23000;
	
		//printf("sUMID = %s\n",sUMID);
		//printf("usLocalPort = %d\n",usLocalPort);
		//添加映射端口
		if ( NPC_F_MPI_MON_DNP_AddPortByChNo(
			hDevNetPortServer,			//[IN]设备网络端口
			sUMID,						//[IN]UMID
			1,
			&usLocalPort,				//[INOUT]本地端口号，如果值为0，则由系统分配端口号
			20000) != 0 )
		{
			printf("添加映射端口失败.\n");
			goto _NPC_CLEAR;
		}
		printf("添加映射端口成功.\n");
		return 1;
	}
	else
	{	
		printf("ret = %d\n",ret);
	}
	
	
//CODE AREA
_NPC_CLEAR:
{
	if ( hDevNetPortServer )
	{
		//销毁设备网络端口映射服务
		NPC_F_MPI_MON_DNP_DestroyDevNetPortServer(
			hDevNetPortServer			//[IN]设备网络端口
			);
		hDevNetPortServer = NULL;

		printf("销毁设备网络端口映射服务完成.\n");
	}
}

return 0;
}


int NpcDevPortMapClient_unint(NPC_HANDLE hDevNetPortServer, unsigned short usLocalPort)
{
	//删除映射端口
			NPC_F_MPI_MON_DNP_DelPort(
				hDevNetPortServer,			//[IN]设备网络端口
				usLocalPort 				//[IN]本地端口号
				);
			printf("删除映射端口成功.\n");

	return 0;
}

#endif


int  BlackAndWhiteListCallBack(long lRealFaceHandle, char *pBuffer,long lbufsize,SDK_FA_BLACKANDWHITELIST_CONFIG *pParm,long dwUser)
{
	SDK_FA_BLACKANDWHITELIST_CONFIG *pConfig = (SDK_FA_BLACKANDWHITELIST_CONFIG *)pParm;

	if(pConfig == NULL)
	{
		return -1;
	}

	if(OUT_INDEX == pConfig->byOutMode)  //
	{
		int nCount = pConfig->byAllNums ;
		for(int i = 0; i < nCount; i++)
		{
			sdk_fileindex_info_t *pInfo = (sdk_fileindex_info_t *)(pBuffer + sizeof(sdk_fileindex_info_t) * i);			
			printf("checksum = %d  enable = %d name = %s findex.fileindex = %d pInfo->findex.libindex = %d ", \
				pInfo->checksum,pInfo->enable,pInfo->name,pInfo->findex.fileindex,pInfo->findex.libindex);
			printf("i = %d\n",i);
			FileIndex = pInfo->findex.fileindex ;
			LibIndex = pInfo->findex.libindex ;

			
		}
	}
	else if(OUT_PICTURE_DEL == pConfig->byOutMode)			
	{

	}
	else if (OUT_PICTURE_DELALL == pConfig->byOutMode)		
	{
	  //????
	}
	else if (IN_PICTURE_ADD == pConfig->byOutMode)			
	{
		//GetResultCode(pConfig->byErrorCode);
		
	}
	else if (IN_PICTURE_ADD_SNAP == pConfig->byOutMode || OUT_PICTURE == pConfig->byOutMode || OUT_PICTURE_COMP == pConfig->byOutMode)	//???????????????  //??????????????е?????
	{
       //????20???head+SDK_FA_BLACKANDWHITELIST_CONFIG+JPG????
	  
		if (pConfig->byErrorCode == WB_OK)
		{	
			char *pFileBuf = new char[lbufsize];
			memcpy(pFileBuf,pBuffer,lbufsize);
			char filename[128] = {0};
			sprintf( filename, "%s",pConfig->byFileName);
			printf("filename = %s\n",filename);
			
			//FILE * m_pFile= fopen(filename,"wb");
			g_pFile = fopen(filename,"wb");	
			if (g_pFile)
			{					
				fwrite(pFileBuf, 1,lbufsize ,g_pFile);
				fclose(g_pFile);
				g_pFile = NULL;
		
				if (pFileBuf != NULL)
				{
					delete pFileBuf;
					pFileBuf = NULL;
				}
			}
			else
			{
				printf("?????????? \n");
			}	
		} 
		else
		{
			//GetResultCode(pConfig->byErrorCode);
			printf("pConfig->byErrorCode = %d",pConfig->byErrorCode);
		}

	}

	return 0;	
}

unsigned int	deviceid;
unsigned int	channelid;
unsigned int	streamid;
unsigned int	wbmode; 		//�ڰ�����
unsigned int	libindex;		//�ڰ�����������
unsigned int	libnumber;		//�ڰ�����������

float			result; 		//�ȶԽ��
unsigned char	SnapTime[32];	////ץ��ʱ��
unsigned char	byRes[64];

unsigned int	guest;			//����ͳ��
unsigned int	Age;			//���� 
unsigned int	Gender; 		//�Ա�
unsigned int	Glasses;		//�۾�	
unsigned int	Mask;			//���
unsigned int	Race;			//����	
unsigned int	Eye;			//�۾�	
unsigned int	Attractive; 	//����ֵ 
unsigned char	ByRes[117]; 	//Ԥ��

int 			facealarm;		//�������� , Ԥ��
float			facecharacter[128];



int  FaceCompareResultCallback(long lRealFaceHandle,char *pBuf, long nDataLen, long dwUser)
{
	SDK_FACECOMPARE_RESULT *pstResulAlarm = (SDK_FACECOMPARE_RESULT *)pBuf;
	
	printf("%s(%d)------------------------------------:%s\n",__FILE__,__LINE__,__func__);
	printf("channelid = %u:\n",pstResulAlarm->channelid);
	printf("picnameComp = %s:\n",pstResulAlarm->picnameComp);
	printf("picnameSnap = %s:\n",pstResulAlarm->picnameSnap);
	
	printf("deviceid = %u:\n",pstResulAlarm->deviceid);
	printf("libindex = %u:\n",pstResulAlarm->libindex);
	printf("libnumber = %u:\n",pstResulAlarm->libnumber);
	printf("SnapTime = %s:\n",pstResulAlarm->SnapTime);
	printf("streamid = %d:\n",pstResulAlarm->streamid);
	printf("wbmode = %u:\n",pstResulAlarm->wbmode);
	printf("result = %f:\n",pstResulAlarm->result);
	printf("guest = %u:\n",pstResulAlarm->guest);
	printf("Age = %d:\n",pstResulAlarm->Age);

	printf("%s(%d)------------------------------------:%s\n",__FILE__,__LINE__,__func__);

	return 0;	
}


int  PictureDataCallback(long lRealFaceHandle,char *pBuf, long nDataLen, SDK_FA_PICTURE_HEAD *pHead, SDK_FACE_ATTR *pAttr, long dwUser)
{
	printf("%s(%d)--:%s\n",__FILE__,__LINE__,__func__);
	char *pFileBuf = new char[nDataLen];
	memcpy(pFileBuf,pBuf,nDataLen);
	SDK_FA_PICTURE_HEAD *picHead = (SDK_FA_PICTURE_HEAD *)pHead;
	SDK_FACE_ATTR *picAttr = (SDK_FACE_ATTR *)pAttr;
	char filename[128] = {0};
	printf("%s(%d)--:%s picHead->filename=%s\n",__FILE__,__LINE__,__func__,picHead->filename);

	printf("ATTR: stDevUUID = %s ", picAttr->stDevUUID);
	printf("ATTR: stOsd = %s ", picAttr->stOsd);

	
	printf("ATTR: (%d,%d) --> (%d,%d) ", picAttr->stFacePosition.left, picAttr->stFacePosition.top, picAttr->stFacePosition.right, 
								picAttr->stFacePosition.bottom);
	
	sprintf( filename, "%s", picHead->filename);

	FILE * m_pFile= fopen(filename,"wb");
	
	if (m_pFile)
	{
				
		printf("#######receive pic sucess:%s\n",filename);
	}
	else
	{
		printf("#######receive pic error:\n");
	}

	if (m_pFile)
	{
		fwrite(pFileBuf , 1,nDataLen,m_pFile);
		fclose(m_pFile);
		m_pFile = NULL;
	}

	if (pFileBuf != NULL)
	{
		delete pFileBuf;
		pFileBuf = NULL;
	}

	return 0;

}




int  NetDataCallBack( long lRealHandle, long dwDataType, unsigned char *pBuffer,long lbufsize,long dwUser)
{	
	printf("lbufsize:%ld\n",lbufsize);
	
	BOOL bResult = TRUE;
	try
	{	
		//fwrite(pBuffer,1,lbufsize,g_pFile);
	}
	catch (...)
	{
		
	}

	// it must return TRUE if decode successfully,or the SDK will consider the decode is failed
	return bResult;

}
int  RealDataCallBack_V2(long lRealHandle, const PACKET_INFO_EX *pFrame, long dwUser)
{
	printf("%s(%d)--:%s\n",__FILE__,__LINE__,__func__);
	printf("time:%04d-%02d-%02d %02d:%02d:%02d\n",pFrame->nYear,pFrame->nMonth,pFrame->nDay,pFrame->nHour,pFrame->nMinute,pFrame->nSecond);
	BOOL bResult = TRUE;
	try
	{	
		fwrite(pFrame->pPacketBuffer,1,pFrame->dwPacketSize,g_pFile);
	}
	catch (...)
	{

	}

	// it must return TRUE if decode successfully,or the SDK will consider the decode is failed
	return bResult;
}
void  Demo_Talk_DataCallBack(LONG lTalkHandle, char *pDataBuf, long dwBufSize, char byAudioFlag, long dwUser)
{
	try
	{
		printf("come TalkDataCallBack :%ld\n",dwBufSize);

		if(g_pFile)
		{
			//printf("come in fwrite");
			fwrite(pDataBuf,1,dwBufSize,g_pFile);
		}
		else
		{
			printf("###################################fWrite wrong!!!!!\n");
		}
		
	}
	catch (...)
	{
		
	}
	// it must return TRUE if decode successfully,or the SDK will consider the decode is failed
	return ;
}

void SubDisConnectCallBack(long lLoginID, SubConnType type, long nChannel, long dwUser)
{
	printf("###################################SubDisConnect!!!!! type = %d\n",type);

}

int g_LoginID=0;
void DevicCallBack(long lLoginID, char *pBuf,
				   unsigned long dwBufLen, long dwUser, int type)
{
	printf("###################one devic is comeing!");
		VIDEONET_ACTIVEREG_INFO *info=(VIDEONET_ACTIVEREG_INFO *)pBuf;
		printf("das device : %s",info->deviceSarialID);
		g_LoginID=lLoginID;

}

//#define SearchDevice
//#define SearchDeviceV2
//#define  DAS
//#define Talk
//#define RealPlay
//#define find
//#define Config
//#define PLAYBACK_BYNAME
//#define PLAYBACK_BYNAME_V2
//#define PlayBack_BYTIME
//#define PlayBack_BYTIME_V2
#define FaceImageSnap
//#define FaceCompareResult
//#define FaceWriteAndBlackList
//#define NPC

pthread_t id;

void* START_ROUTINE(LPVOID lpThreadParameter)
{
	
	VIDEONET_CLIENTINFO playstru;

	playstru.nChannel = 0;
	playstru.nStream = 0;
	playstru.nMode = 0;
	long nPlayHandle = VideoNet_RealPlay(g_LoginID,&playstru );
	printf("nPlayHandle=%ld\n",nPlayHandle);
	sleep(1000);
	return NULL;		
}
void* Jvt_SearchDevice(void *arr)
{

	SDK_CONFIG_NET_COMMON_V2 m_Device[100];
	int nRetLength = 0;
	cout<<"start"<<endl;
	bool bRet= VideoNet_SearchDevice((char*)m_Device,sizeof(SDK_CONFIG_NET_COMMON_V2)*1,&nRetLength,5000);
	if(bRet)
	{	
		printf("m_Device->HostIP.l = %d\n",m_Device[0].HostIP.l);
		printf("m_Device->sMac = %s\n",m_Device[0].sMac);		
		printf("VideoNet_SearchDevice ok number is [%d]\n",nRetLength/(int)sizeof(SDK_CONFIG_NET_COMMON_V2));
		pthread_join(id, NULL);
	}
	return NULL;
}

static int s_flag = 0;
void pfNetComFun(SDK_CONFIG_NET_COMMON_V2 *pNetCom, unsigned long userData)
{
	printf("data============[%d]\n",s_flag);
}


#if 0
void Net_R2eConnect(long lLoginID, char *pchDVRIP, long nDVRPort, unsigned long dwUser)//????????
{
	printf("Net_ReConnect!!!!\n");
}

int P2ictureDataCallback(long lRealFaceHandle,char *pBuf, long nDataLen, SDK_FA_PICTURE_HEAD *pHead, long dwUser)
{
	
	printf("------------------------------------------%s(%d)--:%s\n",__FILE__,__LINE__,__func__);
	return 0;
}


long connect_test()
{
	int s32Err = 0;
	int u32Ret = 0;
	bool bRet = true;
	long lRealFacePicHandle = 0;
	long lRet = 0;
	long lLoginId;

	VIDEONET_DEVICEINFO OutDev;	
	memset(&OutDev,0,sizeof(OutDev));
	int nError = 0;		
	//36123
	printf("VideoNet_Login\n");
	lLoginId = VideoNet_Login((char*)"192.168.55.37", 36123, (char*)"admin",(char*)"admin",(LPVIDEONET_DEVICEINFO)(&OutDev),&nError);		
	printf("g_LoginID=%d,nError:%d\n",lLoginId,nError);
#if 0	
	/*lLoginId = VideoNet_Login((char *)m_stNetInfo.s8aIp, m_stNetInfo.u32Port, (char *)m_stNetInfo.s8aUserName, (char*)m_stNetInfo.s8aPasswd,\
		NULL, (int *)&s32Err);*/
	if (*lLoginId <= 0)
	{
	/*	trace("VideoNet_Login is err m_stNetInfo.u8aIp=%s u32Port=%d %s %s!!!\n", m_stNetInfo.s8aIp,\
			m_stNetInfo.u32Port, m_stNetInfo.s8aUserName, m_stNetInfo.s8aPasswd);*/
		lRet = VideoNet_GetLastError();
	}
	else
	{
	//	trace("VideoNet_Login is sucess m_stNetInfo.u8aIp=%s!!!\n", m_stNetInfo.s8aIp);
		lRealFacePicHandle = VideoNet_StartReceiveFaceImageFile(*lLoginId, 0);
		if (lRealFacePicHandle > 0)
		{
		//	trace("\033[34m""VideoNet_StartReceiveFaceImageFile is sucess!!!!\n""\033[0m");
			bRet = VideoNet_SetFaceImageDataCallBack(lRealFacePicHandle, P2ictureDataCallback, 0);
			if (!bRet)
			{					
			//	trace("\033[34m""VideoNet_SetFaceImageDataCallBack is err\n""\033[0m");
				lRet = VideoNet_GetLastError();
			}
			else
			{
				trace("\033[34m""VideoNet_SetFaceImageDataCallBack is sucess\n""\033[0m");
			}
		}
		else
		{
			lRet = VideoNet_GetLastError();
			trace("VideoNet_StartReceiveFaceImageFile is failed %ld!!!\n", *lLoginId);
		}
	}
#endif
 return lLoginId;
}

int main(void)
{

	long lRet = VideoNet_Init(NULL, 1);


	int i = 0;
	while (1)
	{
		long lLoginId = 0;	
	
/*	
		if ( 0 > lRet)
		{
			lRet = VideoNet_GetLastError();
			printf("VideoNet_GetLastError is err lRet=%ld!!!\n", lRet);
		}
		else
		{
			printf("VideoNet_GetLastError is sucess!!!\n");
		}
*/	

		lLoginId = connect_test();
		printf("lLoginId is = %d !!!\n",lLoginId);
		sleep(10);

		if(lLoginId>0)
		{
			VideoNet_Logout(lLoginId);
			printf("Logout success!!! lLoginId = %d\n",lLoginId);
			//lLoginId = 0;
		}

		sleep(5);
		
		i++;
		if (i > 20)
			break;
		printf("_________________\n");
	}
	
	VideoNet_Cleanup();
	cout<<"VideoNet_Cleanup"<<endl; 


		
	sleep(12);
	return 0;
}

#endif

#if 1
int  main(void)
{	
	g_pFile=NULL;
	VideoNet_Init(NULL,1);
	printf("VideoNet_Init\n");

#ifdef SearchDevice
	int count = 0;

	while(1)
	{	
		sleep(1);

		count++;
		printf("count = %d\n",count);
		
		if(count == 15)
		{
			break;
		}
		
		pthread_create(&id, NULL,Jvt_SearchDevice, NULL);
		if(ret)
		{
			printf("Create pthread error\n");
		}		
	}
#endif



#ifdef SearchDeviceV2
		VideoNet_SearchDevice_V2(pfNetComFun,0, 5000);
#endif


#if 1

#ifdef DAS
	cout<<"start das"<<endl;
	bool ret =VideoNet_StartActiveRigister(9400,DevicCallBack,1);
	cout<<"end das"<<endl;
	if(ret>0)
	{
		cout<<"********sleep 2 minit************ "<<endl;
		sleep(5);
	}	
	else
	{
		printf("Call VideoNet_StartActiveRigister**********wrong￡?");
	}
#else
	VIDEONET_DEVICEINFO OutDev;	
	memset(&OutDev,0,sizeof(OutDev));
	int nError = 0;		
//	36123
#ifdef NPC
	printf("VideoNet_Login_P2P\n");
	unsigned short usLocalPort = 23000;
	g_LoginID = VideoNet_Login_P2P((char*)"127.0.0.1", usLocalPort, (char*)"admin",(char*)"admin",(LPVIDEONET_DEVICEINFO)(&OutDev),&nError);	
#else
	printf("VideoNet_Login\n");
	g_LoginID = VideoNet_Login((char*)"128.128.10.28", 36123, (char*)"admin",(char*)"admin",(LPVIDEONET_DEVICEINFO)(&OutDev),&nError);	
#endif
	printf("g_LoginID=%d,nError:%d\n",g_LoginID,nError);
	
	/*if(g_LoginID)
	{
		SDK_ChannelNameConfigAll ChannelName;
		memset(&ChannelName, 0, sizeof(SDK_ChannelNameConfigAll));
		memcpy(ChannelName[0],"������", sizeof("������"));
		int nRet = VideoNet_SetDevConfig(g_LoginID, E_SDK_CONFIG_CHANNEL_NAME, -1, (char*)&ChannelName, sizeof(SDK_ChannelNameConfigAll), 3000);
		if(nRet)
		{
			printf("���óɹ���\n");
		}
	}*/
	//pthread_t handle;
	//pthread_create(&handle,NULL,START_ROUTINE,NULL);
	
#ifdef ADDUSER	
	USER_INFO userInfo;	
	strcpy(userInfo.Groupname,"admin");	
	strcpy(userInfo.memo,"");
	strcpy(userInfo.name,"12345");
	strcpy(userInfo.passWord,"");

	userInfo.reserved=false;
	userInfo.rigthNum=5;
	strcpy(userInfo.rights[0],"ShutDown");
	strcpy(userInfo.rights[1],"ChannelTitle");
	strcpy(userInfo.rights[2],"RecordConfig");
	strcpy(userInfo.rights[3],"Replay_01");
	strcpy(userInfo.rights[4],"Monitor_01");
	userInfo.shareable=true;
	long lRet2 = VideoNet_SetDevConfig(g_LoginID, E_SDK_CONFIG_ADD_USER, -1, (char*)&userInfo, sizeof(userInfo), 10000);
	if(lRet2 >0)
	{
	   printf("add user ok\n");
	}else
	{
	   printf("add user err\n");
	}
#endif
	
#endif

#ifdef Find

	VIDEONET_FINDINFO findInfo;
	findInfo.nChannelN0=0;
	findInfo.nFileType=0;			//�ļ�����, ��SDK_File_Type
	
	time_t t = time(NULL);
	tm * tt= localtime(&t);
	
	findInfo.startTime.dwYear = tt->tm_year+1900;
	findInfo.startTime.dwMonth = tt->tm_mon+1;
	findInfo.startTime.dwDay = tt->tm_mday;
	findInfo.startTime.dwHour = 0;
	findInfo.startTime.dwMinute = 0;
	findInfo.startTime.dwSecond = 0;

	findInfo.endTime.dwYear = tt->tm_year+1900;
	findInfo.endTime.dwMonth = tt->tm_mon+1;
	findInfo.endTime.dwDay = tt->tm_mday;
	findInfo.endTime.dwHour = 23;
	findInfo.endTime.dwMinute = 59;
	findInfo.endTime.dwSecond = 59;
	
	VIDEONET_FILE_DATA *pData = new VIDEONET_FILE_DATA[64];
	int nFindCount = 0;
	
	long lRet= VideoNet_FindFile(g_LoginID, &findInfo, pData, 64, &nFindCount, 3000);
	if(lRet>0&&nFindCount>0)
	{
	   	printf("search success,playback file num=%d\n", nFindCount);
#ifdef PLAYBACK_BYNAME
	 	lRet = VideoNet_PlayBackByName(g_LoginID, &pData[0], NULL,NetDataCallBack, NULL);
		if(lRet>0)
		{
			sleep(10);
			printf("Play success\n");
		}else
		{
			printf("Play failed,lRet=%ld\n",lRet);
		}
#else

#ifdef PLAYBACK_BYNAME_V2
		lRet = VideoNet_PlayBackByName_V2(g_LoginID, &pData[0], NULL,RealDataCallBack_V2, NULL);
		if(lRet>0)
		{
			sleep(10);
			printf("Play success\n");
		}else
		{
			printf("Play failed,lRet=%ld\n",lRet);
		}
#endif
#endif


	//??·?
					VIDEONET_FINDINFO info;
				 	memset(&info, 0, sizeof(info));
				 	info.nChannelN0=0;
				 	info.nFileType=0;
				 	info.startTime.dwYear = tt->tm_year+1900;
				 	info.startTime.dwMonth = tt->tm_mon+1;
				 	info.startTime.dwDay = tt->tm_mday;
				 	info.startTime.dwHour = 0;
				 	info.startTime.dwMinute = 0;
				 	info.startTime.dwSecond = 0;
				 
				 	info.endTime.dwYear = tt->tm_year+1900;
				 	info.endTime.dwMonth = tt->tm_mon+1;
				 	info.endTime.dwDay = tt->tm_mday;
				 	info.endTime.dwHour = 23;
				 	info.endTime.dwMinute = 59;
				 	info.endTime.dwSecond = 59;
				 	g_pFile = fopen("testPlayBack", "wb+");
					long ret=0;
				 
#ifdef PlayBack_BYTIME
				 	ret=VideoNet_PlayBackByTime(g_LoginID,&info,NULL,NetDataCallBack,1);
					if(ret)
				 	{
				 		printf("######playBackByTime#########\n");
				 		sleep(10);	

				 	}
				 	else
				 	{
				 		printf("#############playbackWrong#####:%ld\n",ret);
				 	}
#else
#ifdef PlayBack_BYTIME_V2
					ret=VideoNet_PlayBackByTime_V2(g_LoginID,&info,RealDataCallBack_V2,1,NULL,NULL);
					if(ret)
				 	{
				 		printf("######playBackByTime#########\n");
				 		sleep(10);	

				 	}
				 	else
				 	{
				 		printf("#############playbackWrong#####:%ld\n",ret);
				 	}
	
				 	
#endif
#endif	
	
	}	

#endif	
	
 	if(g_LoginID>0)
 	{
		 		printf("**************login ok***************\n");	
				//???2
#ifdef Talk
 		g_pFile = fopen("TestTalk", "wb+");			
 		long lHandle = VideoNet_StartVoiceCom_MR(g_LoginID, Demo_Talk_DataCallBack, 0);
 		if ( lHandle <= 0 )
 		{
 			printf("start talk wrong");
 		}
 		else
 		{						
 			printf("start talk ok\n");			
 			sleep(6);
 			if(VideoNet_StopVoiceCom(lHandle))
 			{
 				printf("stop talk ok\n");
 			}
 			else
 			{
 				printf("stop wrong!");
 			}			
 		}
#endif
		//êμê±?àêó

		//í???????
#ifdef Config
 		ulong dwRetLen = 0;
 		int nWaitTime = 10000;
	#if 1	
		/*
 		SDK_CONFIG_NET_COMMON NetWorkCfg;
 		BOOL bReboot = FALSE;
 		BOOL bSuccess = VideoNet_GetDevConfig(g_LoginID,E_SDK_CONFIG_SYSNET,0,
 			(char *)&NetWorkCfg,sizeof(SDK_CONFIG_NET_COMMON),&dwRetLen,nWaitTime);
 		if (bSuccess && dwRetLen == sizeof (SDK_CONFIG_NET_COMMON))
 		{
 			printf("TCPPort:%d\n",NetWorkCfg.SSLPort);	
 			printf("HttpPort:%d\n",NetWorkCfg.HttpPort);	
 			NetWorkCfg.SSLPort=34567;
 			bSuccess = VideoNet_SetDevConfig(g_LoginID,E_SDK_CONFIG_SYSNET,0,
 				(char *)&NetWorkCfg,sizeof(SDK_CONFIG_NET_COMMON),nWaitTime);
 			if (bSuccess)
 			{
 				printf("setconfig ok\n");
 			}
 			else
 			{
 				printf("setconfig wrong\n");
 			}
 
 		}
 		else
 		{
 			int len=sizeof (SDK_CONFIG_NET_COMMON);
 			printf("GetConfig Wrong:%d,RetLen:%ld  !=  %d\n",bSuccess,dwRetLen,len);
 		}
		*/
	 	dwRetLen = 0;
 		nWaitTime = 10000;
 		SDK_CONFIG_NORMAL NormalConfig = {0};
 		BOOL bSuccess = VideoNet_GetDevConfig(g_LoginID, E_SDK_CONFIG_SYSNORMAL ,0, 
 			(char *)&NormalConfig ,sizeof(SDK_CONFIG_NORMAL), &dwRetLen,nWaitTime);
 		if ( bSuccess && dwRetLen == sizeof(SDK_CONFIG_NORMAL))
 		{
 		//	printf("############language: %d#############\n",NormalConfig.iLanguage);
 			printf("############sMachineName: %s#############\n",NormalConfig.sMachineName);
 		//	printf("############iVideoStartOutPut: %d#############\n",NormalConfig.iVideoStartOutPut);
			/*
 			NormalConfig.iLanguage=2;
			sprintf(NormalConfig.sMachineName,"%s","IPC");
 			BOOL bSuccess = VideoNet_SetDevConfig(g_LoginID,E_SDK_CONFIG_SYSNORMAL,0,(char *)&NormalConfig,sizeof(SDK_CONFIG_NORMAL),nWaitTime);
 			if ( bSuccess == VIDEONET_OPT_REBOOT )
 			{
 				printf("####need reboot####\n");
 			}
 			else if(bSuccess>0)
 			{
 				printf("#####setconfig ok####\n");
 			}
 			else
 			{
 				printf("#####setconfig wrong####\n");
 			}
			*/
 		}
	#else
		SDK_SMART_ALARM Algorithm;
 		BOOL bReboot = FALSE;
 		BOOL bSuccess = VideoNet_GetDevConfig(g_LoginID,E_SDK_CFG_SMARTFACE_ALARM,0,
 			(char *)&Algorithm,sizeof(SDK_SMART_ALARM),&dwRetLen,nWaitTime);
 		if (bSuccess && dwRetLen == sizeof (SDK_SMART_ALARM))
 		{
 			printf("aBEnable:%d\n",Algorithm.aBEnable);			
 
 		}
 		else
 		{
 			int len=sizeof (SDK_SMART_ALARM);
 			printf("GetConfig Wrong:%d,RetLen:%ld  !=  %d\n",bSuccess,dwRetLen,len);
 		}
	
	#endif	
#endif

#ifdef RealPlay
		VIDEONET_CLIENTINFO playstru;

		playstru.nChannel = 0;
		playstru.nStream = 0;
		playstru.nMode = 0;
		long m_iPlayhandle = VideoNet_RealPlay(g_LoginID, &playstru);	
		if(m_iPlayhandle == 0 )
		{
			printf("start RealPlay wrong!\n");
		}
		else
		{
			g_pFile = fopen("TestRealPlay.h264", "wb+");
			VideoNet_SetRealDataCallBack_V2(m_iPlayhandle, RealDataCallBack_V2, 0);
			printf("start RealPlay ok!");
			sleep(10);
			if(VideoNet_StopRealPlay(m_iPlayhandle))
			{
				printf("stop realPlay ok\n");
			}
			else
			{
				printf("stop realPlay Wrong\n");
			}

		}
#endif

#ifdef FaceImageSnap
	
		//long m_lRealFacePicHandle =  VideoNet_StartReceiveFaceImageFile(g_LoginID,0);
		long m_lRealFacePicHandle =  VideoNet_StartReceiveFaceImageFileEx(g_LoginID,0,1);
		if(m_lRealFacePicHandle > 0 )
		{
			VideoNet_SetFaceImageDataCallBack(m_lRealFacePicHandle,PictureDataCallback, 0); 	
			printf("start FaceImageData ok!\n");
		
			//sleep(120);

			//if(VideoNet_SetKeepLifeTime(g_LoginID,20,40)!=1)
			//{
			//	printf("VideoNet_SetKeepLifeTime ERROR!\n");
			//}
		
			if(VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 0) != 1)
			{
				printf("VideoNet_SetSubDisconnectCallBack ERROR!\n");
			}
			
			while(1)
			{
				sleep(1);
			}
			
			if (m_lRealFacePicHandle > 0)
			{
				VideoNet_StopReceiveFaceImageFile(m_lRealFacePicHandle);
				int rett = 	VideoNet_DelFaceImageDataCallBack(m_lRealFacePicHandle,PictureDataCallback, 0);
				printf("rett = %d\n",rett);
				m_lRealFacePicHandle = -1;
			}
	
		}
		else
		{
			printf("start ReceiveFaceImageFile wrong!\n");
			
		}
	
#endif

#ifdef FaceWriteAndBlackList
	   
		long m_lFaceBlackAndWhiteList =  VideoNet_StartSendBlackAndWhiteList(g_LoginID,0);
		if(m_lFaceBlackAndWhiteList > 0 )
		{
		
			VideoNet_SetBlackAndWhiteListCallBack(m_lFaceBlackAndWhiteList,BlackAndWhiteListCallBack, 0);	
			
			VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,OUT_INDEX,1,0,0,NULL);
			printf("start FaceWriteAndBlackList ok!\n");
			//sleep(20);
			/*
			while(1)
			{
				sleep(1);
			}
		
			if(VideoNet_SetKeepLifeTime(g_LoginID,20,40)!=1)
			{
				printf("VideoNet_SetKeepLifeTime ERROR!\n");
			}
		*/	
			if(VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 0) != 1)
			{
				printf("VideoNet_SetSubDisconnectCallBack ERROR!\n");
			}
			
			while(1)
			{
				sleep(1);
			}
			
			if (m_lFaceBlackAndWhiteList > 0)
			{
			// g_pFilePath ??????·???????
			//	VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,OUT_INDEX,1,0,0,NULL); //
			//	VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,OUT_PICTURE,1,LibIndex,FileIndex,g_pFilePath);////??????????????е?????
			//	VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,IN_PICTURE_ADD_SNAP,1,0,0,pFilePath);////???????????????
				/*
				int bRet =	VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,IN_PICTURE_ADD,1,0,0,pFilePath); //?????????????????????			
				if (bRet)
				{
					printf("????????? \n");
				}
				else
				{
				
					printf("??????? \n");
				}
				*/
			//	VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList,OUT_PICTURE_DEL,1,LibIndex,FileIndex,pFilePath); ////??????е?????
				
			}
			
			if (m_lFaceBlackAndWhiteList > 0)
			{
				VideoNet_StopSendBlackAndWhiteList(m_lFaceBlackAndWhiteList);
				VideoNet_DeleteBlackAndWhiteListCallBack(m_lFaceBlackAndWhiteList,BlackAndWhiteListCallBack, 0);
				m_lFaceBlackAndWhiteList = -1;
			}
	
			printf("start FaceWriteAndBlackList OK!\n");
	
		}
		else
		{
			printf("start FaceWriteAndBlackList wrong!\n");
		}
	
#endif


#ifdef FaceCompareResult
		SDK_COMPINFO_FLAG stFlag;
		stFlag.iAlarmEn = 1;
		stFlag.iCaptureEn = 1;
		stFlag.iFeatureEn = 1;
		stFlag.iLibPicEn = 1;
		long m_lRealFaceCompareHandle =  VideoNet_StartReceiveFaceCompareResultEx(g_LoginID,0, &stFlag);
		if(m_lRealFaceCompareHandle > 0 )
		{
		
			VideoNet_SetFaceCompareResultCallBack(m_lRealFaceCompareHandle,FaceCompareResultCallback, 0, "/mnt/hgfs/JVTSDK_Linux/JVTSDK_Linux/bin/x64");	
			printf("start etFaceCompareResultCallBack ok!\n");
			
			if(VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 0) != 1)
			{
				printf("VideoNet_SetSubDisconnectCallBack ERROR!\n");
			}

			sleep(60*10);
			
			if (m_lRealFaceCompareHandle > 0)
			{
				VideoNet_StopReceiveFaceCompareResult(m_lRealFaceCompareHandle);
				VideoNet_DelFaceCompareResultCallBack(m_lRealFaceCompareHandle,FaceCompareResultCallback, 0);
				m_lRealFaceCompareHandle = -1;
			}
	
		printf("start FaceCompareResultCallback OK!\n");
	
		}
		else
		{
			printf("start FaceCompareResultCallback m_lRealFaceCompareHandle = %ld\n",m_lRealFaceCompareHandle);
			printf("start FaceCompareResultCallback wrong!\n");
			
		}
	
#endif
	


 	}
 	else
 	{
 		printf("**************login wrong************\n");	
 	}

#ifdef DAS
	cout<<"VideoNet_StopActiveRigister1"<<endl;
	VideoNet_StopActiveRigister();
	cout<<"VideoNet_StopActiveRigister"<<endl;
#endif

#endif
	if(g_LoginID>0)
	{
		VideoNet_Logout(g_LoginID);
		printf("Logout success!!!\n");
	}
	VideoNet_Cleanup();
	cout<<"VideoNet_Cleanup"<<endl;
#ifdef NPC
	NpcDevPortMapClient_unint(hDevNetPortServer,usLocalPort);
	NPC_F_MPI_MON_DNP_DestroyDevNetPortServer(hDevNetPortServer);

#endif
	if(g_pFile)
	{
		fclose(g_pFile);
		g_pFile = NULL;
	}
	printf("**************OVER************\n");
	return 0;
}

#endif