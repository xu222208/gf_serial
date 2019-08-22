#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_AlarmFunction "AlarmFunction" 
class AlarmFunction : public JObject
{
public:
	JBoolObj		AlarmConfig;
	JBoolObj		BlindDetect;
	JBoolObj		IPCAlarm;
	JBoolObj		LossDetect;
	JBoolObj		MotionDetect;
	JBoolObj		NetAbort;
	JBoolObj		NetAbortExtend;
	JBoolObj		NetAlarm;
	JBoolObj		NetIpConflict;
	JBoolObj		StorageFailure;
	JBoolObj		StorageLowSpace;
	JBoolObj		StorageNotExist;
	JBoolObj		VideoAnalyze;

public:
    AlarmFunction(JObject *pParent = NULL, const char *szName = JK_AlarmFunction):
    JObject(pParent,szName),
	AlarmConfig(this, "AlarmConfig"),
	BlindDetect(this, "BlindDetect"),
	IPCAlarm(this, "IPCAlarm"),
	LossDetect(this, "LossDetect"),
	MotionDetect(this, "MotionDetect"),
	NetAbort(this, "NetAbort"),
	NetAbortExtend(this, "NetAbortExtend"),
	NetAlarm(this, "NetAlarm"),
	NetIpConflict(this, "NetIpConflict"),
	StorageFailure(this, "StorageFailure"),
	StorageLowSpace(this, "StorageLowSpace"),
	StorageNotExist(this, "StorageNotExist"),
	VideoAnalyze(this, "VideoAnalyze"){
	};

    ~AlarmFunction(void){};
};

NS_NETSDK_CFG_END