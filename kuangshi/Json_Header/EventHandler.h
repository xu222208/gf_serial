#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_EventHandler "EventHandler" 
class EventHandler : public JObject
{
public:
	JStrObj		AlarmInfo;
	JBoolObj		AlarmOutEnable;
	JIntObj		AlarmOutLatch;
    JIntHex    AlarmOutMask;
	JBoolObj		BeepEnable;
	JIntObj		EventLatch;
	JBoolObj		FTPEnable;
	JBoolObj		LogEnable;
	JBoolObj		MailEnable;
	JBoolObj		MatrixEnable;
	JIntHex		MatrixMask;
	JBoolObj		MessageEnable;
	JBoolObj		MsgtoNetEnable;
	JBoolObj		MultimediaMsgEnable;
	JBoolObj		PtzEnable;
	//JObjArray		PtzLink;
	JBoolObj		RecordEnable;
	JIntObj		RecordLatch;
	JIntHex		RecordMask;
	JBoolObj		ShortMsgEnable;
	JBoolObj		ShowInfo;
	JIntHex		ShowInfoMask;
	JBoolObj		SnapEnable;
	JIntHex		SnapShotMask;
	JObjArray<JObjArray<JStrObj> >	TimeSection;
	JBoolObj		TipEnable;
	JBoolObj		TourEnable;
	JIntHex		TourMask;
	JBoolObj		VoiceEnable;

public:
	EventHandler(JObject *pParent = NULL, const char *szName = JK_EventHandler):
	JObject(pParent,szName),
	AlarmInfo(this, "AlarmInfo"),
	AlarmOutEnable(this, "AlarmOutEnable"),
	AlarmOutLatch(this, "AlarmOutLatch"),
	AlarmOutMask(this, "AlarmOutMask"),
	BeepEnable(this, "BeepEnable"),
	EventLatch(this, "EventLatch"),
	FTPEnable(this, "FTPEnable"),
	LogEnable(this, "LogEnable"),
	MailEnable(this, "MailEnable"),
	MatrixEnable(this, "MatrixEnable"),
	MatrixMask(this, "MatrixMask"),
	MessageEnable(this, "MessageEnable"),
	MsgtoNetEnable(this, "MsgtoNetEnable"),
	MultimediaMsgEnable(this, "MultimediaMsgEnable"),
	PtzEnable(this, "PtzEnable"),
	//PtzLink(this, "PtzLink"),
	RecordEnable(this, "RecordEnable"),
	RecordLatch(this, "RecordLatch"),
	RecordMask(this, "RecordMask"),
	ShortMsgEnable(this, "ShortMsgEnable"),
	ShowInfo(this, "ShowInfo"),
	ShowInfoMask(this, "ShowInfoMask"),
	SnapEnable(this, "SnapEnable"),
	SnapShotMask(this, "SnapShotMask"),
	TimeSection(this, "TimeSection"),
	TipEnable(this, "TipEnable"),
	TourEnable(this, "TourEnable"),
	TourMask(this, "TourMask"),
	VoiceEnable(this, "VoiceEnable"){
	};

	~EventHandler(void){};
};

NS_NETSDK_CFG_END