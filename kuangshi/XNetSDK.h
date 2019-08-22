#pragma once
#ifndef _XNetSDK_H_
#define _XNetSDK_H_

#ifdef WIN32
#ifdef XNETSDK_EXPORTS
#define XSDK_API __declspec(dllexport)
#define CALLBACK __stdcall
#else
#define XSDK_API __declspec(dllimport)
#define CALLBACK __stdcall
#endif
#else
#define XSDK_API
#define CALLBACK
#endif

#include "XNetSDKDefine.h"

#define XSDK_HANDLE int
typedef int (CALLBACK *PXSDK_MessageCallBack) (XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char *szString, void *pObject, int nSeq, void *pUserData);

////////////////////////////About XSDK////////////////////////////
typedef struct SXSDKInitParam
{
	int nLogLevel;
	PXSDK_MessageCallBack pMsgCallBack;
	void *pUserData;
}SXSDKInitParam;

////////////////////////////About Device////////////////////////////
typedef int (CALLBACK *PXSDK_MediaCallBack) (XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo, int nDataInfoSize, void *pUserData);
typedef struct SXMediaRealPlayReq
{
	int nChannel;
	int nStreamType;
	int nRequestType;		// 0：原始码流回调 1：按帧回调(见枚举：EXSDK_DATA_FORMATE)
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaRealPlayReq;

typedef struct SXMediaFaceImageReq
{
	int nChannel;
	int nImgTypeMsk;		// 3
	char szIntelType[64];   // Face
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaFaceImageReq;

typedef struct SXMediaRecordReq
{
	int nChannel;
	int nStreamType;
	char sBeginTime[32];
	char sEndTime[32];
	char sFileType[64];		// 暂时无用
	int nRequestType;		// 0：原始码流回调 1：按帧回调
	char sIntelligentPlayBackEvent[64];
	int nIntelligentPlayBackSpeed;
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaRecordReq;

// SDK 初始化&反初始化
XSDK_API int CALLBACK XSDK_Init(SXSDKInitParam *pParam);
XSDK_API void CALLBACK XSDK_UnInit();

// 设备登录、登出
// MsgId:ESXSDK_DEV_LOGIN
XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLogin(SXSDKLoginParam *pParam, int nTimeout, int nSeq);
XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLoginSyn(SXSDKLoginParam *pParam, int nTimeout);
XSDK_API void CALLBACK XSDK_DevLogout(XSDK_HANDLE hDevice);

// 设备系统&通道配置相关
//ESXSDK_DEV_GET_SYS_CONFIG  = 12007,		// 设备系统配置获取
XSDK_API int CALLBACK XSDK_DevGetSysConfig(XSDK_HANDLE hDevice, const char *szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);
//ESXSDK_DEV_GET_CHN_CONFIG  = 12009,		// 设备通道配置获取
XSDK_API int CALLBACK XSDK_DevGetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);
// ESXSDK_DEV_SET_SYS_CONFIG  = 12008,		// 设备系统配置设置
XSDK_API int CALLBACK XSDK_DevSetSysConfig(XSDK_HANDLE hDevice, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);
// ESXSDK_DEV_SET_CHN_CONFIG  = 12010,		// 设备通道配置设置
XSDK_API int CALLBACK XSDK_DevSetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

// 开启或关闭设备报警回调
// 结果在PXSDK_MessageCallBack函数中回调
// MsgId:EXCMD_ALARM_REQ = 1504
// szString:报警消息(Json格式)
XSDK_API int CALLBACK XSDK_DevSetAlarmListener(XSDK_HANDLE hDevice, int bListener);

// ESXSDK_ON_SEARCH_DEVICES   = 13001,		// 局域网设备搜索
// param2:返回个数
XSDK_API int CALLBACK XSDK_SearchDevices(int nTimeout);

// 云台控制
XSDK_API int CALLBACK XSDK_DevPtzControl(XSDK_HANDLE hDevice, int nChannel, const char *szPTZCommand, int nStep, bool bStop);

// ESXSDK_DEV_FIND_FILE  = 12011,		// 设备录像查询
// 注意函数一次最多返回64条（）
XSDK_API int CALLBACK XSDK_DevFindFile(XSDK_HANDLE hDevice, SXSDKQueryRecordReq *pParam, int nTimeout, int nSeq);

// 时间同步
// 时间格式：2018-07-25 17:20:37; == NULL或""时，默认为当前系统时间
// 返回MsgID:ESXSDK_DEV_SET_SYS_CONFIG  = 12008,		// 设备系统配置设置
// 返回nParam3:EXCMD_SYSMANAGER_RSP
XSDK_API int CALLBACK XSDK_DevSynTime(XSDK_HANDLE hDevice, const char *szTime = "", int nSeq = 0);

// 实时媒体播放
// MsgId:ESXSDK_MEDIA_START_REAL_PLAY
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRealPlay(XSDK_HANDLE hDevice, SXMediaRealPlayReq *pParam, int nSeq = 0, int nTimeout = 0);

// 录像回放
// MsgId:ESXSDK_MEDIA_START_RECORD_PLAY
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordPlay(XSDK_HANDLE hDevice,  SXMediaRecordReq *pParam, int nSeq, int nTimeout = 0);

// 录像下载
// MsgId:ESXSDK_MEDIA_DOWN_RECORD_FILE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordDownload(XSDK_HANDLE hDevice,  SXMediaRecordReq *pParam, int nSeq, int nTimeout = 0);

// 录像回放/下载控制->暂停/继续
XSDK_API int CALLBACK XSDK_MediaPause(XSDK_HANDLE hMedia, bool bPause);

// 录像回放跳转
// szTime:YYYY-MM-DD HH:mm:SS
XSDK_API int CALLBACK XSDK_MediaSeekToTime(XSDK_HANDLE hMedia, const char *szTime);

// 回放速度控制
// -1~-4:慢放1~4档
// 1~4：快放1~4档
// 0:恢复
XSDK_API int CALLBACK XSDK_MediaSetSpeed(XSDK_HANDLE hMedia, int nSpeed);

// 人脸识别图片回调
// MsgId:ESXSDK_MEDIA_START_FACE_IMAGE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaGetFaceImage(XSDK_HANDLE hDevice, SXMediaFaceImageReq *pParam, int nSeq = 0, int nTimeout = 0);

// 实时预览/录像回放/下载--停止
XSDK_API void CALLBACK XSDK_MediaStop(XSDK_HANDLE nMediaId);

#endif //_XNetSDK_H_
