#include "XNetSDKTest.h"

int TestDevSearch()
{
	printf("%s\r\n", __FUNCTION__);
	char c = 0;
	do 
	{
		XSDK_SearchDevices(4000);
	}
	while((c = getchar()) != 'q');
	return 0;
}

void OnDevSearchResult(int nResult, SXSDK_CONFIG_NET_COMMON *pDevs, int nCount)
{
	printf("OnDevSearchResult[SearchResutl:%d][DeviceCount:%d]\r\n", nResult, nCount);
	for (int i = 0; i < nCount; i++)
	{
		printf("[%d][SN:%s][IP:%d.%d.%d.%d][Port:%d]\r\n", i, pDevs[i].sSn, 
			pDevs[i].HostIP.c[0], pDevs[i].HostIP.c[1], pDevs[i].HostIP.c[2], pDevs[i].HostIP.c[3],
			pDevs[i].TCPPort);
	}
}