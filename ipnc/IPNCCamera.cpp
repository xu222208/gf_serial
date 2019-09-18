#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

#define bool int   
#define false 0   
#define true 1

#include "IPNC_SDK_Interface.h"
#include "IPNCCamera.h"
#include <time.h>
#define JPEG_BUFFER_TAIL_LEN            (128)

#define JPG_EXTEND_DATA		     (108)

enum PLAYER_STATUS
{
	PLAYER_STATUS_UNKNOWN = 0,
	PLAYER_STATUS_IS_ONLINE,
	PLAYER_STATUS_IS_OFFLINE,
	PLAYER_STATUS_MAX,
};


#define USER_DEBUG_OUTPUT
#ifdef USER_DEBUG_OUTPUT
        #define DBG_OUTPUT(fmt, args...) \
        do{fprintf(stderr,"main debug: %s[%d] [%s]",__FUNCTION__, __LINE__, __FILE__ ); \
                fprintf(stderr,fmt, ##args); fprintf(stderr,"\n");}while(0) 
#else
        #define DBG_OUTPUT(fmt, args...) do{}while(0)
#endif

#define APP_NAME "client_adpt"

static bool s_exitApplication = false;

static bool s_isDeviceOnline = false;

static void signal_kill_handler(int signum)
{
        DBG_OUTPUT("signal_kill_handler:signum[%d]\n", signum);
        signum = signum;
        s_exitApplication = true;
}

static void signal_terminate_handler(int signum)
{
        DBG_OUTPUT("signal_terminate_handler, signum is %d\n", signum);
        signum = signum;
        s_exitApplication = true;
}

static void signal_killall_handler(int signum)
{
        DBG_OUTPUT("signal_killall_handler, signum is %d\n", signum);
        signum = signum;
        s_exitApplication = true;
}

static void signal_child_handler(int signum)
{
        DBG_OUTPUT("signal_child_handler, signum is %d\n", signum);
        signum = signum;
}

static void signal_abort_handler(int signum)
{
        DBG_OUTPUT("signal_abort_handler, signum is %d\n", signum);
        signum = signum;
}

static void signal_alarm_handler(int signum)
{
        DBG_OUTPUT("signal_alarm_handler, signum is %d\n", signum);
        signum = signum;
}

static void set_signal_handler(int signum, void func(int))
{
        struct sigaction sigAction;
        sigAction.sa_flags = 0;
        sigemptyset(&sigAction.sa_mask);
        sigaddset(&sigAction.sa_mask, SIGINT);
        sigAction.sa_handler = func;
        sigaction(signum, &sigAction, NULL);
}

void SigactionProcess()
{
        struct sigaction sigAction;
        sigAction.sa_flags = 0;
        sigemptyset(&sigAction.sa_mask);
        sigaddset(&sigAction.sa_mask, SIGINT);
        sigAction.sa_handler = signal_kill_handler;
        sigaction(SIGINT, &sigAction, NULL);
        
        set_signal_handler(SIGTERM, signal_terminate_handler);
        set_signal_handler(SIGKILL, signal_killall_handler);
        set_signal_handler(SIGCHLD, signal_child_handler);
        set_signal_handler(SIGABRT, signal_abort_handler);
        set_signal_handler(SIGALRM, signal_alarm_handler);
}

void GetPlateColor(int index, char *pPlateColor, int plateColorLen)
{
	if (pPlateColor && (plateColorLen > 0) && (index >= 0))
	{
		switch(index) 
		{
			case 0:
				strncpy(pPlateColor, "未知色",  plateColorLen);
				break;
			case 1:
				strncpy(pPlateColor, "蓝色",  plateColorLen);
				break;
			case 2:
				strncpy(pPlateColor, "黄色",  plateColorLen);
				break;
			case 3:
				strncpy(pPlateColor, "白色",  plateColorLen);
				break;
			case 4:
				strncpy(pPlateColor, "黑色",  plateColorLen);
				break;
			case 5:
				strncpy(pPlateColor, "绿色",  plateColorLen);
				break;
			default:
				strncpy(pPlateColor, "未知色",  plateColorLen);
				break;
		}
	}
}

void GetPlateType(int index, char *pPlateType, int plateTypeLen)
{
	if (pPlateType && (plateTypeLen > 0) && index >= 0)
	{
		switch(index) 
		{
			case 0:
				strncpy(pPlateType, "未知车牌类型",  plateTypeLen);
				break;

			case 1:
				strncpy(pPlateType, "蓝牌",  plateTypeLen);
				break;

			case 2:
				strncpy(pPlateType, "黑牌",  plateTypeLen);
				break;

			case 3:
				strncpy(pPlateType, "单排黄牌",  plateTypeLen);
				break;

			case 4:
				strncpy(pPlateType, "双排黄牌",  plateTypeLen);
				break;

			case 5:
				strncpy(pPlateType, "警车车牌",  plateTypeLen);
				break;

			case 6:
				strncpy(pPlateType, "武警车牌",  plateTypeLen);
				break;

			case 7:
				strncpy(pPlateType, "个性化车牌",  plateTypeLen);
				break;

			case 8:
				strncpy(pPlateType, "单排军车",  plateTypeLen);
				break;

			case 9:
				strncpy(pPlateType, "双排军车",  plateTypeLen);
				break;

			case 10:
				strncpy(pPlateType, "使馆牌",  plateTypeLen);
				break;

			case 11:
				strncpy(pPlateType, "香港牌",  plateTypeLen);
				break;

			case 12:
				strncpy(pPlateType, "拖拉机",  plateTypeLen);
				break;

			case 13:
				strncpy(pPlateType, "澳门牌",  plateTypeLen);
				break;

			default:
				strncpy(pPlateType, "未知车牌类型",  plateTypeLen);
				break;
		}
	}
}

void GetsnapMode(int index, char *pSnapMode, int snapModeLen)
{
	if (pSnapMode && (snapModeLen >= 0) &&(index >= 0))
	{
		if (index & 1)
		{
			strncpy(pSnapMode, "算法抓拍", snapModeLen);
		}
		else if (index & 2)
		{
			strncpy(pSnapMode, "手动抓拍", snapModeLen);
		}
		else if (index & 4)
		{
			strncpy(pSnapMode, "外部触发", snapModeLen);
		}		
		else if (index & 8)
		{
			strncpy(pSnapMode, "无牌车摇一摇抓拍", snapModeLen);
		}
	}
}

void FormatTimeIntoStr_BySnapResult(char *pTimeBuffer, int bufferLen, IPNC_SNAP_INFO *pSnapResult)
{
	if (pSnapResult && pTimeBuffer && bufferLen >= 21)
	{
		sprintf(pTimeBuffer, "%04d_%02d%02d_%02d%02d_%02d_%03d_snap",
			pSnapResult->snapTime.year,  pSnapResult->snapTime.mon, 
			pSnapResult->snapTime.day, pSnapResult->snapTime.hour,
			pSnapResult->snapTime.min, pSnapResult->snapTime.sec, 
			pSnapResult->snapTime.msec);
	}
}

bool GetFullScencePicPath_BySnapResult(char *pFilePath, int filePathLen, IPNC_SNAP_INFO *pSnapResult)
{
	if ((filePathLen > 0) && (pFilePath != NULL) && (pSnapResult != NULL))
	{
		char currSnapTime[256] = {0};

		FormatTimeIntoStr_BySnapResult(currSnapTime, sizeof(currSnapTime), pSnapResult);

		sprintf(pFilePath, "%s_fullScence.jpg", currSnapTime);
	}

	return true;
}

bool GetPlatePicPath_BySnapResult(char *pFilePath, int filePathLen, IPNC_SNAP_INFO *pSnapResult)
{
	if ((filePathLen > 0) && (pFilePath != NULL) && (pSnapResult != NULL))
	{
		char currSnapTime[256] = {0};

		FormatTimeIntoStr_BySnapResult(currSnapTime, sizeof(currSnapTime), pSnapResult);

		sprintf(pFilePath, "%s_plate.jpg", currSnapTime);
	}

	return true;
}

bool SaveDataToJpeg_FullScence(char *pRecvDataBuffer, int dwRecvBufSize, char *pPicFileName)
{
	if ((pRecvDataBuffer) && (dwRecvBufSize > 0) && (pPicFileName))
	{
		DBG_OUTPUT("save full scence jpeg path: %s\n", pPicFileName);

		FILE *fp = fopen(pPicFileName, "wb");

		fwrite((char *)pRecvDataBuffer, dwRecvBufSize, 1, fp);

		fclose(fp);

		return true;
	}

	DBG_OUTPUT("save jpeg fail\n");

	return false;
}

bool SaveDataToJpeg_Plate(char *pRecvDataBuffer, int dwRecvBufSize, char *pPicFileName)
{
	if ((pRecvDataBuffer) && (dwRecvBufSize > 0) && (pPicFileName))
	{
		DBG_OUTPUT("save jpeg plate path: %s\n", pPicFileName);

		FILE *fp = fopen(pPicFileName, "wb");

		fwrite((char *)pRecvDataBuffer, dwRecvBufSize, 1, fp);

		fclose(fp);

		return true;
	}

	DBG_OUTPUT("save jpeg fail\n");

	return false;
}

static void SnapDataCallBack(char *pRecvDataBuffer,int dwRecvBufSize, char *pPlateJpeg, int plateJpegLen, void *pUser)
{
	pUser = pUser;

	DBG_OUTPUT("receive snap jpeg data len %d\n", dwRecvBufSize);

	IPNC_SNAP_INFO snapResult;

	memset(&snapResult, 0x0, sizeof(snapResult));

	IPNC_NET_SDK_API_PraseSnapData(pRecvDataBuffer, dwRecvBufSize, &snapResult);

	char snapMode[32] = { 0 };
	GetsnapMode(snapResult.snapMode, snapMode, sizeof(snapMode));

	if (strlen(snapResult.plateNo) > 0)
	{
		char plateColor[32] = { 0 };
		GetPlateColor(snapResult.plateColor, plateColor, sizeof(plateColor));

		char plateType[32] = { 0 };
		GetPlateType(snapResult.plateType, plateType, sizeof(plateType));

		DBG_OUTPUT("[设备IP：%s] 接收抓拍图片，车牌：%s，抓拍模式：%s，车牌颜色：%s，车牌类型：%s 车牌坐标：x %d y %d w %d h %d\n", 
			snapResult.deviceIp, snapResult.plateNo, snapMode, 
			plateColor, plateType, 
			snapResult.snapRect.x, snapResult.snapRect.y, 
			snapResult.snapRect.w, snapResult.snapRect.h);

		char plateFilePath[256] = { 0 };

		GetPlatePicPath_BySnapResult(plateFilePath, sizeof(plateFilePath), &snapResult);

		SaveDataToJpeg_Plate(pPlateJpeg, plateJpegLen, plateFilePath);
	}
	else
	{
		DBG_OUTPUT("[设备IP：%s] 接收抓拍图片，车牌：未知车牌 抓拍模式：%s\n", snapResult.deviceIp, snapMode);
	}

	char fullScenceFilePath[256] = { 0 };

	GetFullScencePicPath_BySnapResult(fullScenceFilePath, sizeof(fullScenceFilePath), &snapResult);

	SaveDataToJpeg_FullScence(pRecvDataBuffer, dwRecvBufSize - sizeof(snapResult), fullScenceFilePath);



	PLIST_BUFFER plistBuffer;
	//获取空队列
	g_pCarListThread->GetBuffer(&plistBuffer, empty);
	if (plistBuffer == nullptr) {
		//若空队列为空,获取满队列地址
		logDebug("The hk car data is full and the original data is discarded!");
		//g_pListThread->GetHeadBuffer(&plistBuffer, full);
		g_pCarListThread->GetBuffer(&plistBuffer, full);

		//获取内存图片并保存
		SaveFaceFile(plistBuffer, IPNC);

	}
	if (plistBuffer){
		plistBuffer->camerasPic.nCamerasType= IPNC;
		struct tm  timeptr;
		timeptr.tm_year=snapResult.snapTime.year;
		timeptr.tm_mon=snapResult.snapTime.mon;
		timeptr.tm_mday=snapResult.snapTime.day;
		timeptr.tm_hour=snapResult.snapTime.hour;
		timeptr.tm_min=snapResult.snapTime.min;
		timeptr.tm_sec=snapResult.snapTime.sec;
		time_t tt=mktime(&timeptr);
		char str[32];
		sprintf(str, "%d", tt);
		memcpy(&plistBuffer->camerasPic.tCameraTime,str, 32);
		//车辆颜色 保留字段 暂无
		//plistBuffer->camerasPic.nLicense_car_color=??????;
//		plistBuffer->camerasPic.nLicense_plate_type=plateType;
//		printf(" plistBuffer->camerasPic.nLicense_plate_type =%d\n", plistBuffer->camerasPic.nLicense_plate_type);
//		//车牌颜色
//		plistBuffer->camerasPic.nLicense_plate_color=plateColor;
//		int tcol;
//		tcol=plistBuffer->camerasPic.nLicense_plate_color;
		//if(strcmp(plateType,))


	}


}

static void DeviceStatusCallBack(char *pDeviceIp, int port, int deviceStatus, void *pUser)
{
	pUser = pUser;

	DBG_OUTPUT("device ip %s port %d deviceStatus %d\n\n", pDeviceIp, port, deviceStatus);

	if (deviceStatus == PLAYER_STATUS_IS_ONLINE)
	{
		if (!s_isDeviceOnline)
		{
			DBG_OUTPUT("[设备IP：%s] 在线\n", pDeviceIp);
		}

		s_isDeviceOnline = true;
	}
	else
	{
		if (s_isDeviceOnline)
		{
			DBG_OUTPUT("[设备IP：%s] 离线 \n", pDeviceIp);
		}

		s_isDeviceOnline = false;
	}
}

int main(int argc, char **argv)
{
	DBG_OUTPUT("======================= NetSdk Demo start ===============================\n");

	argc = argc;

	argv = argv;

	DBG_OUTPUT("main thread input param %d, %s\n", argc, argv[0]);
  
    	SigactionProcess();

	IPNC_NET_SDK_API_Init();

	IPNC_NET_SDK_API_RegisterSnapCallBack(SnapDataCallBack, NULL);

	IPNC_NET_SDK_API_RegisterDeviceStatusCallBack(DeviceStatusCallBack, NULL);

	char deviceIpList[256] = { 0 };

	int dviceNum = 0;

	IPNC_NET_SDK_API_DeviceSearch(&dviceNum, deviceIpList, 2000);

	DBG_OUTPUT("DeviceSearch dviceNum %d, %s\n", dviceNum, deviceIpList);
	
	char currDeviceIp[32] = "192.168.1.250";

	IPNC_NET_SDK_API_ConnectDevice(currDeviceIp, (char *)"admin", (char *)"123456");	

    	while (!s_exitApplication) 
	{
         	usleep(500 * 1000 * 6);

		if (s_isDeviceOnline)
		{
			//IPNC_NET_SDK_API_ManualSnap(currDeviceIp);

			//IPNC_NET_SDK_API_DeviceOpenBarrier(currDeviceIp);
		}
		else
		{
			DBG_OUTPUT("[设备IP：%s] 离线\n", currDeviceIp);
		}
    	}

	IPNC_NET_SDK_API_DisconnectDevice(currDeviceIp);

	IPNC_NET_SDK_API_UnregisterSnapCallBack();

	IPNC_NET_SDK_API_UnregisterDeviceStatusCallBack();

	IPNC_NET_SDK_API_Cleanup();

       DBG_OUTPUT("main thread exit\n");

       return 0;
}

