// XNetSDKTest.cpp : 定义控制台应用程序的入口点。
//
#include "XNetSDKTest.h"
XSDK_HANDLE g_hDevice = 0;

int CALLBACK Main_MessageCallBack(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char *szString, void *pObject, int nSeq, void *pUserData)
{
	switch(nMsgId)
	{
		case ESXSDK_DEV_FIND_FILE:
		{
			OnDevFindFile(nParam1, (SXSDKQueryRecordRes *)pObject, nParam2, nSeq);
		}
			break;
		case ESXSDK_DEV_LOGIN:
		{
			printf("ESXSDK_DEV_LOGIN_Ret[%d]\r\n", nParam1);
			if (nParam1 == EXSDK_ER_UserOrPassword)
			{
				XSDK_DevLogout(hDevice);
			}

			if (nParam1 < 0)
			{
				printf("ESXSDK_DEV_LOGIN__Error\r\n");
			}
		}
			break;
		case ESXSDK_ON_DEV_STATE:
		{
			printf("ESXSDK_ON_DEV_STATE[%s]\r\n", nParam1 == 6 ? "ESTATE_DEV_Logined" : "ESTATE_DEV_NetDisConnect");
		}
			break;
		case ESXSDK_DEV_GENERAL_COMMAND:	// 通用交互返回
		case ESXSDK_DEV_GET_SYS_CONFIG:		// 设备系统配置获取
		case ESXSDK_DEV_SET_SYS_CONFIG:		// 设备系统配置设置
		case ESXSDK_DEV_GET_CHN_CONFIG:		// 设备通道配置获取
		case ESXSDK_DEV_SET_CHN_CONFIG:		// 设备通道配置设置
		{
			OnDevConfig(nMsgId, nParam1, szString, (const char *)pObject, nParam2, nSeq);
		}
			break;
		case ESXSDK_ON_SEARCH_DEVICES:
		{
			OnDevSearchResult(nParam1, (SXSDK_CONFIG_NET_COMMON *)pObject, nParam2);
		}
			break;
		case EXCMD_ALARM_REQ:
		{
			OnDevAlarmCallback(hDevice, szString);
		}
			break;
		default:
			printf("[Dev:%ld][MSG:%d][Ret:%d][Param2:%d][Param3:%d][szParam:%s][Seq:%d]\r\n", hDevice, nMsgId, nParam1, nParam2, nParam3, szString == NULL ? "" : szString, nSeq);
			break;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	SXSDKInitParam initParam = {0};
	initParam.nLogLevel = 3;
	initParam.pMsgCallBack = Main_MessageCallBack;
	initParam.pUserData = (void *)0x123456;
	XSDK_Init(&initParam);

	const char *szDevIP = "192.168.63.166";
	//int nDevPort = 34567;
    int nDevPort = 3000;
	const char *szUser = "admin";
	const char *szPwd = "px68018888";
	if (argc > 4)
	{
		szDevIP = argv[1];
		nDevPort = atoi(argv[2]);
		szUser = argv[3];
		szPwd = argv[4];
	}

	SXSDKLoginParam devParam = {0};
	strcpy(devParam.sDevId, szDevIP);
	devParam.nDevPort = nDevPort;
	strcpy(devParam.sUserName, szUser);
	strcpy(devParam.sPassword, szPwd);
	g_hDevice = XSDK_DevLogin(&devParam, 4000, 0);

	//// 测试设备配置
	//TestDevConfig();

	//// 测试设备云台功能
	//TestDevPTZ();

	//// 测试录像查询
	//TestDevFindFile();

	//// 设备设备报警回调
	//TestDevAlarmCallback();

	//// 测试实时视频
	//TestMediaRealPlay();

	//// 设备录像回放
	//TestMediaRecordPlay();

	//// 测试人脸抓图
	TestMediaFaceImage();

	//// SDK稳定性测试
	//TestLibStability();

	//// 设备搜索
	//TestDevSearch();

	XSDK_DevLogout(g_hDevice);
	XSDK_UnInit();
	return 0;
}

