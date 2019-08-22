#include "XNetSDKTest.h"
#include "SystemInfo.h"
#include "SystemFunction.h"
USE_NS_NETSDK_CFG

int TestDevConfig()
{
	printf("%s\r\n", __FUNCTION__);
	char c = 0;
	while((c = getchar()) != 'q')
	{
		switch(c)
		{
		case 'a':
			{
				// 获取设备能力级
				XSDK_DevGetSysConfig(g_hDevice, JK_SystemFunction, 1234, 4000, JK_SystemFunction_MsgId);
			}
			break;
		case 'b':
			{
			}
			break;
		case 'c':
			{
				// 获取设备基本信息（版本信息等）
				XSDK_DevGetSysConfig(g_hDevice, JK_SystemInfo, 123, 4000, JK_SystemInfo_MsgId);
			}
			break;
		case 'd':
			{
			}
			break;
		}
	}
	return 0;
}

void OnDevConfig(int nMsgId, int nResult, const char *szCfgName, const char *szResult, int nResultLen, int nSeq)
{
	if (nResult < 0)
	{
		printf("OnDevConfig:[MsgId:%d; Result:%d]\r\n", nMsgId, nResult);
		return;
	}

	if((ESXSDK_DEV_GET_SYS_CONFIG == nMsgId ||ESXSDK_DEV_GET_CHN_CONFIG == nMsgId) && szCfgName && szResult && nResultLen > 0)
	{
		if (strcmp(szCfgName, JK_SystemInfo) == 0)
		{
			SystemInfo cfg;
			cfg.Parse(szResult);
			printf("SystemInfo:[SerialNo:%s; BuildTime:%s; ]\r\n", cfg.SerialNo.Value(), cfg.BuildTime.Value());
		}
		else if (strcmp(szCfgName, JK_SystemFunction) == 0)
		{
			SystemFunction cfg;
			cfg.Parse(szResult);
			printf("SystemFunction:[CombineStream:%d; ]\r\n", cfg.mEncodeFunction.CombineStream.Value());
		}
	}
}
