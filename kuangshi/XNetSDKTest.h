// XNetSDKTest.h : 定义控制台应用程序的入口点。
//
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <time.h>
#include "XNetSDK.h"
#include "TestFuns.h"

using namespace std;

extern XSDK_HANDLE g_hDevice;

// 测试设备配置
int TestDevConfig();
void OnDevConfig(int nMsgId, int nResult, const char *szCfgName, const char *szResult, int nResultLen, int nSeq);

// 测试设备云台功能
int TestDevPTZ();

// 测试录像查询
int TestDevFindFile();
void OnDevFindFile(int nResult, SXSDKQueryRecordRes *pFiles, int nCount, int nSeq);

// 设备设备报警回调
int TestDevAlarmCallback();
void OnDevAlarmCallback(XSDK_HANDLE hDevice, const char *szAlarm);

// 测试实时视频
int TestMediaRealPlay();

// 设备录像回放
int TestMediaRecordPlay();

// 测试人脸抓图
int TestMediaFaceImage();

// SDK稳定性测试
int TestLibStability();

// 设备搜索
int TestDevSearch();
void OnDevSearchResult(int nResult, SXSDK_CONFIG_NET_COMMON *pDevs, int nCount);