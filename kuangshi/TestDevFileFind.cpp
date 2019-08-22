#include "XNetSDKTest.h"

void OnDevFindFile(int nResult, SXSDKQueryRecordRes *pFiles, int nCount, int nSeq)
{
	if (nResult <= 0)
	{
		printf("ESXSDK_DEV_FIND_FILE[%d]\r\n", nResult);
		return;
	}

	SXSDKQueryRecordRes *pFile = NULL;
	for (int i = 0; i < nCount; i++)
	{
		pFile = &pFiles[i];
		printf("File[%d][%s~%s][%d][%s][%s]\r\n", i, pFile->sBeginTime, pFile->sEndTime, pFile->nFileLength, pFile->sFileType, pFile->sFileSubType);
	}
}

int TestDevFindFile()
{
	printf("%s\r\n", __FUNCTION__);
	int nSeq = 0;
	char c = 0;
	printf("q-->To exit.\r\n", __FUNCTION__);
	while((c = getchar()) != 'q')
	{
		SXSDKQueryRecordReq param = {0};
		strcpy(param.sFileType, EMFileType_recod);
		strcpy(param.sFileSubType, EMFileSubType_ALL);
		param.nChannel = 0;
		param.nStreamType = 0;
#if 1
		time_t tNow = time(NULL);
		struct tm tmNow = *localtime(&tNow);
		sprintf(param.sBeginTime, "%04d-%02d-%02d 00:00:00", tmNow.tm_year + 1900, tmNow.tm_mon + 1, tmNow.tm_mday);
		sprintf(param.sEndTime, "%04d-%02d-%02d 23:59:59", tmNow.tm_year + 1900, tmNow.tm_mon + 1, tmNow.tm_mday);
#else
		strcpy(param.sBeginTime, "2018-08-04 00:00:00");
		strcpy(param.sEndTime, "2018-08-04 23:59:59");
#endif

		//注意函数一次最多返回64条
		XSDK_DevFindFile(g_hDevice, &param, 4000, nSeq++);
	}
	return 0;
}