#include "XNetSDKTest.h"

int CALLBACK Test_FaceImageCallBack(XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo, int nDataInfoSize, void *pUserData)
{

	if (EXSDK_DATA_FORMATE_FACE_IMAGE == nDataType && pDataInfo)
	{
		SXSDK_IA_FR_REC_S *pInfo = (SXSDK_IA_FR_REC_S *)pDataInfo;

		char szFileName[128] = {0};
		static int s_index = 0;
		sprintf(szFileName, "%d_%d_%d_%d_A.jpg", pInfo->comm.framID, pInfo->comm.picSubType, s_index,pInfo->comm.tagsec);
		ToFile(szFileName, pData, nDataLen);

//		sprintf(szFileName, "%d_%d_%d_%d_B.jpg", pInfo->comm.framID, pInfo->comm.picSubType, s_index,pInfo->index);
//		ToFile(szFileName, pData, nDataLen + 4);
//
//		sprintf(szFileName, "%d_%d_%d_%d_C.jpg", pInfo->comm.framID, pInfo->comm.picSubType, s_index,pInfo->index);
//		ToFile(szFileName, pData, nDataLen + 4 + nDataInfoSize);
		s_index++;

		printf("FacePicture__B__%x_%d_%d[DataLen=%d]\r\n", hMedia, pInfo->comm.picSubType, pInfo->comm.framID, nDataLen);
	}
	else if (EXSDK_DATA_MEDIA_ON_PLAY_STATE == nDataType)
	{
		printf("EXSDK_DATA_MEDIA_ON_PLAY_STATE[%d][%d]\r\n", hMedia, nDataLen);
	}
	else if (ESXSDK_MEDIA_START_FACE_IMAGE == nDataType)
	{
		printf("ESXSDK_MEDIA_START_FACE_IMAGE[%d][%d]\r\n", hMedia, nDataLen);
	}
	else 
	{
		printf("Media[hMedia:%ld][Len:%d][Type:%d]\r\n", hMedia, nDataLen, nDataType);
	}
	return 0;
}


int TestMediaFaceImage()
{
	printf("%s\r\n", __FUNCTION__);
	XSDK_HANDLE hPlayer = 0;
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

				SXMediaFaceImageReq param = {0};
				param.nChannel = 0;
				param.nImgTypeMsk = 3;
				strcpy(param.szIntelType, "Face");
				param.pMediaCallback = Test_FaceImageCallBack;
				param.pUserData = (void *)0x23456;
				hPlayer = XSDK_MediaGetFaceImage(g_hDevice, &param);
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