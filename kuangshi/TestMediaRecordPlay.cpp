#include "XNetSDKTest.h"

int CALLBACK Test_RecordMediaCallBack(XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo, int nDataInfoSize, void *pUserData)
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
	else if (ESXSDK_MEDIA_START_RECORD_PLAY == nDataType)
	{
		printf("OnRecordPlayResult[%d][%s]\r\n", hMedia, nDataLen >= 0 ? "Success" : "Failed");
	}
	else if (ESXSDK_MEDIA_DOWN_RECORD_FILE == nDataType)
	{
		printf("OnRecordDownloadResult[%d][%s]\r\n", hMedia, nDataLen >= 0 ? "Success" : "Failed");
	}
	else 
	{
		printf("Media[hMedia:%ld][Len:%d][Type:%d]\r\n", hMedia, nDataLen, nDataType);
	}
	return 0;
}

int TestMediaRecordPlay()
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

				SXMediaRecordReq param = {0};
				param.nChannel = 0;
				param.nStreamType = 0;
				param.nRequestType = EXSDK_DATA_FORMATE_FRAME;
				param.pMediaCallback = Test_RecordMediaCallBack;
#if 1
				time_t tNow = time(NULL);
				struct tm tmNow = *localtime(&tNow);
				sprintf(param.sBeginTime, "%04d-%02d-%02d 00:00:00", tmNow.tm_year + 1900, tmNow.tm_mon + 1, tmNow.tm_mday);
				sprintf(param.sEndTime, "%04d-%02d-%02d 23:59:59", tmNow.tm_year + 1900, tmNow.tm_mon + 1, tmNow.tm_mday);
#else
				strcpy(param.sBeginTime, "2018-08-04 00:00:00");
				strcpy(param.sEndTime, "2018-08-04 23:59:59");
#endif
				hPlayer = XSDK_MediaRecordPlay(g_hDevice, &param, 0, 4000);
				//hPlayer = XSDK_Lib_MediaRecordDownload(g_hDevice, &param, 0, 4000);
				bPause = false;
				nSpeed = 0;
			}
			break;
		case 't':
			{
				XSDK_MediaStop(hPlayer);
				hPlayer = 0;
			}
			break;
		case 'p':
			{
				bPause = !bPause;
				XSDK_MediaPause(hPlayer, bPause);
			}
			break;
		case 'e':
			{
				XSDK_MediaSetSpeed(hPlayer, nSpeed);
				nSpeed++;
				if (nSpeed == 4)
				{
					nSpeed = -4;
				}
			}
			break;
		case 'k':
			{
				XSDK_MediaSeekToTime(hPlayer, "2018-08-04 13:00:00");
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