#include "XNetSDKTest.h"

int CALLBACK Test_MediaCallBack(XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo, int nDataInfoSize, void *pUserData)
{
	if (EXSDK_DATA_FORMATE_FRAME == nDataType && nDataInfoSize > 0)
	{
		SXSDK_FRAME_INFO *pFrame = (SXSDK_FRAME_INFO *)pDataInfo;
		printf("Media[hMedia:%ld][Len:%d][Type:%d/%d][%04d-%02d-%02d %02d:%02d:%02d-%03d]\r\n", hMedia, nDataLen, pFrame->nType, pFrame->nSubType, pFrame->nYear, pFrame->nMonth, pFrame->nDay, pFrame->nHour, pFrame->nMinute, pFrame->nSecond, (int)(pFrame->nTimeStamp % 1000));
	}
	else if (EXSDK_DATA_MEDIA_ON_PLAY_STATE == nDataType)
	{
		printf("EXSDK_DATA_MEDIA_ON_PLAY_STATE[%d][%d]\r\n", hMedia, nDataLen);
	}
	else if (ESXSDK_MEDIA_START_REAL_PLAY == nDataType)
	{
		printf("OnRealPlayResult[%d][%s]\r\n", hMedia, nDataLen >= 0 ? "Success" : "Failed");
	}
	else 
	{
		printf("Media[hMedia:%ld][Len:%d][Type:%d]\r\n", hMedia, nDataLen, nDataType);
	}
	return 0;
}

int TestMediaRealPlay()
{
	printf("%s\r\n", __FUNCTION__);

	XSDK_HANDLE hPlayer = 0;
	bool bPause = false;
	int nSpeed = 0;

	char c = 0;
	do
	{
		switch(c)
		{
		case 's':
			{
				if (hPlayer)
				{
					XSDK_MediaStop(hPlayer);
					hPlayer = 0;
				}

				SXMediaRealPlayReq param = {0};
				param.nChannel = 0;
				param.nStreamType = 0;
				param.nRequestType = EXSDK_DATA_FORMATE_FRAME;
				param.pMediaCallback = Test_MediaCallBack;
				hPlayer = XSDK_MediaRealPlay(g_hDevice, &param);
				bPause = false;
				nSpeed = 0;
			}
			break;
		case 't':
			{
				if (hPlayer)
				{
					XSDK_MediaStop(hPlayer);
					hPlayer = 0;
				}
			}
			break;
		}
	}while((c = getchar()) != 'q');

	if (hPlayer)
	{
		XSDK_MediaStop(hPlayer);
		hPlayer = 0;
	}
	return 0;
}