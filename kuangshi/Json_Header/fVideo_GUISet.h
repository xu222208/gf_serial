#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_fVideo_GUISet "fVideo.GUISet" 
class fVideo_GUISet : public JObject
{
public:
	JBoolObj		AlarmStateEnable;
	JBoolObj		CarInfo;
	JBoolObj		ChanStateBitRateEnable;
	JBoolObj		ChanStateLckEnable;
	JBoolObj		ChanStateMtdEnable;
	JBoolObj		ChanStateRecEnable;
	JBoolObj		ChanStateVlsEnable;
	JBoolObj		ChannelTitleEnable;
	JBoolObj		Deflick;
	JBoolObj		GPSInfo;
	JBoolObj		RecordStateEnable;
	JBoolObj		RemoteEnable;
	JBoolObj		TimeTitleEnable;
	JIntObj		WindowAlpha;

public:
	fVideo_GUISet(JObject *pParent = NULL, const char *szName = JK_fVideo_GUISet):
	JObject(pParent,szName),
	AlarmStateEnable(this, "AlarmStateEnable"),
	CarInfo(this, "CarInfo"),
	ChanStateBitRateEnable(this, "ChanStateBitRateEnable"),
	ChanStateLckEnable(this, "ChanStateLckEnable"),
	ChanStateMtdEnable(this, "ChanStateMtdEnable"),
	ChanStateRecEnable(this, "ChanStateRecEnable"),
	ChanStateVlsEnable(this, "ChanStateVlsEnable"),
	ChannelTitleEnable(this, "ChannelTitleEnable"),
	Deflick(this, "Deflick"),
	GPSInfo(this, "GPSInfo"),
	RecordStateEnable(this, "RecordStateEnable"),
	RemoteEnable(this, "RemoteEnable"),
	TimeTitleEnable(this, "TimeTitleEnable"),
	WindowAlpha(this, "WindowAlpha"){
	};

	~fVideo_GUISet(void){};
};

NS_NETSDK_CFG_END