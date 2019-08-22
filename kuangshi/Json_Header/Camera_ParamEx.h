#pragma once
#include "JObject.h"
#include "BroadTrends.h"
NS_NETSDK_CFG_BEGIN

#define JK_Camera_ParamEx "Camera.ParamEx"
class Camera_ParamEx : public JObject //
{
public:
	JIntObj		AeMeansure;//测光
	BroadTrends		mBroadTrends;
	JIntObj		Dis;
	JStrObj		ExposureTime;
	JIntObj		Ldc;
	JIntObj		LowLuxMode; //微光模式
	JStrObj		Style;

public:
    Camera_ParamEx(JObject *pParent = NULL, const char *szName = JK_Camera_ParamEx):
    JObject(pParent,szName),
	AeMeansure(this, "AeMeansure"),
	mBroadTrends(this, "BroadTrends"),
	Dis(this, "Dis"),
	ExposureTime(this, "ExposureTime"),
	Ldc(this, "Ldc"),
	LowLuxMode(this, "LowLuxMode"),
	Style(this, "Style"){
	};

    ~Camera_ParamEx(void){};
};

NS_NETSDK_CFG_END