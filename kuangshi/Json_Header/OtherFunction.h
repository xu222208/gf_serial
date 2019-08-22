#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_OtherFunction "OtherFunction" 
class OtherFunction : public JObject
{
public:
	JBoolObj		AlterDigitalName;
	JBoolObj		DownLoadPause;
	JBoolObj		HddLowSpaceUseMB;
	JBoolObj		HideDigital;
	JBoolObj		MusicFilePlay;
	JBoolObj		NOHDDRECORD;
	JBoolObj		NotSupportAH;
	JBoolObj		NotSupportAV;
	JBoolObj		NotSupportTalk;
	JBoolObj		SDsupportRecord;
	JBoolObj		ShowAlarmLevelRegion;
	JBoolObj		ShowFalseCheckTime;
	JBoolObj		SupportAbnormitySendMail;
	JBoolObj		SupportBT;
	JBoolObj		SupportC7Platform;
	JBoolObj		SupportCamareStyle;
	JBoolObj		SupportCustomOemInfo;
	JBoolObj		SupportDigitalEncode;
	JBoolObj		SupportDigitalPre;
	JBoolObj		SupportDimenCode;
	JBoolObj		SupportExtRecord;
	JBoolObj		SupportMailTest;
	JBoolObj		SupportMaxPlayback;
	JBoolObj		SupportNVR;
	JBoolObj		SupportNetLocalSearch;
	JBoolObj		SupportOSDInfo;
	JBoolObj		SupportOnvifClient;
	JBoolObj		SupportPOS;
	JBoolObj		SupportPlayBackExactSeek;
	JBoolObj		SupportResumePtzState;
	JBoolObj		SupportSetDigIP;
	JBoolObj		SupportShowConnectStatus;
	JBoolObj		SupportShowProductType;
	JBoolObj		SupportSnapCfg;
	JBoolObj		SupportTimeZone;
	JBoolObj		SupportWriteLog;
	JBoolObj		Supportonviftitle;
	JBoolObj		TitleAndStateUpload;
	JBoolObj		USBsupportRecord;
    JBoolObj        SupportLowLuxMode;
    JBoolObj        SupportSlowMotion;

public:
    OtherFunction(JObject *pParent = NULL, const char *szName = JK_OtherFunction):
    JObject(pParent,szName),
	AlterDigitalName(this, "AlterDigitalName"),
	DownLoadPause(this, "DownLoadPause"),
	HddLowSpaceUseMB(this, "HddLowSpaceUseMB"),
	HideDigital(this, "HideDigital"),
	MusicFilePlay(this, "MusicFilePlay"),
	NOHDDRECORD(this, "NOHDDRECORD"),
	NotSupportAH(this, "NotSupportAH"),
	NotSupportAV(this, "NotSupportAV"),
	NotSupportTalk(this, "NotSupportTalk"),
	SDsupportRecord(this, "SDsupportRecord"),
	ShowAlarmLevelRegion(this, "ShowAlarmLevelRegion"),
	ShowFalseCheckTime(this, "ShowFalseCheckTime"),
	SupportAbnormitySendMail(this, "SupportAbnormitySendMail"),
	SupportBT(this, "SupportBT"),
	SupportC7Platform(this, "SupportC7Platform"),
	SupportCamareStyle(this, "SupportCamareStyle"),
	SupportCustomOemInfo(this, "SupportCustomOemInfo"),
	SupportDigitalEncode(this, "SupportDigitalEncode"),
	SupportDigitalPre(this, "SupportDigitalPre"),
	SupportDimenCode(this, "SupportDimenCode"),
	SupportExtRecord(this, "SupportExtRecord"),
	SupportMailTest(this, "SupportMailTest"),
	SupportMaxPlayback(this, "SupportMaxPlayback"),
	SupportNVR(this, "SupportNVR"),
	SupportNetLocalSearch(this, "SupportNetLocalSearch"),
	SupportOSDInfo(this, "SupportOSDInfo"),
	SupportOnvifClient(this, "SupportOnvifClient"),
	SupportPOS(this, "SupportPOS"),
	SupportPlayBackExactSeek(this, "SupportPlayBackExactSeek"),
	SupportResumePtzState(this, "SupportResumePtzState"),
	SupportSetDigIP(this, "SupportSetDigIP"),
	SupportShowConnectStatus(this, "SupportShowConnectStatus"),
	SupportShowProductType(this, "SupportShowProductType"),
	SupportSnapCfg(this, "SupportSnapCfg"),
	SupportTimeZone(this, "SupportTimeZone"),
	SupportWriteLog(this, "SupportWriteLog"),
	Supportonviftitle(this, "Supportonviftitle"),
	TitleAndStateUpload(this, "TitleAndStateUpload"),
	USBsupportRecord(this, "USBsupportRecord"),
    SupportLowLuxMode(this, "SupportLowLuxMode"),
    SupportSlowMotion(this, "SupportSlowMotion"){
	};

    ~OtherFunction(void){};
};

NS_NETSDK_CFG_END