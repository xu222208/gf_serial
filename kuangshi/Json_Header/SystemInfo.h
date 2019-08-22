#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_SystemInfo "SystemInfo"
#define JK_SystemInfo_MsgId 1020
class SystemInfo : public JObject 
{
public:
	JIntObj		AlarmInChannel;
	JIntObj		AlarmOutChannel;
	JIntObj		AudioInChannel;
	JStrObj		BuildTime;
	JIntObj		CombineSwitch;
	JIntHex		DeviceRunTime;
	JIntObj		DigChannel;
	JStrObj		EncryptVersion;
	JIntObj		ExtraChannel;
	JStrObj		HardWare;
	JStrObj		HardWareVersion;
	JStrObj		SerialNo;
	JStrObj		SoftWareVersion;
	JIntObj		TalkInChannel;
	JIntObj		TalkOutChannel;
	JStrObj		UpdataTime;
	JIntHex		UpdataType;
	JIntObj		VideoInChannel;
	JIntObj		VideoOutChannel;

public:
	SystemInfo(JObject *pParent = NULL, const char *szName = JK_SystemInfo):
	JObject(pParent,szName),
	AlarmInChannel(this, "AlarmInChannel"),
	AlarmOutChannel(this, "AlarmOutChannel"),
	AudioInChannel(this, "AudioInChannel"),
	BuildTime(this, "BuildTime"),
	CombineSwitch(this, "CombineSwitch"),
	DeviceRunTime(this, "DeviceRunTime"),
	DigChannel(this, "DigChannel"),
	EncryptVersion(this, "EncryptVersion"),
	ExtraChannel(this, "ExtraChannel"),
	HardWare(this, "HardWare"),
	HardWareVersion(this, "HardWareVersion"),
	SerialNo(this, "SerialNo"),
	SoftWareVersion(this, "SoftWareVersion"),
	TalkInChannel(this, "TalkInChannel"),
	TalkOutChannel(this, "TalkOutChannel"),
	UpdataTime(this, "UpdataTime"),
	UpdataType(this, "UpdataType"),
	VideoInChannel(this, "VideoInChannel"),
	VideoOutChannel(this, "VideoOutChannel"){
		this->Parse("{ \"Name\" : \"SystemInfo\", \"Ret\" : 100, \"SessionID\" : \"0x2c\", \"SystemInfo\" : { \"AlarmInChannel\" : 2," "\"AlarmOutChannel\" : 1, \"AudioInChannel\" : 1, \"BuildTime\" : \"2017-04-12 19:13:16\", \"CombineSwitch\" : 0," "\"DeviceRunTime\" : \"0x00001D66\", \"DigChannel\" : 0, \"EncryptVersion\" : \"Unknown\", \"ExtraChannel\" : 0, \"HardWare\" :" "\"HI3518E_53H13_S39\", \"HardWareVersion\" : \"Unknown\", \"SerialNo\" : \"558aa5ddab9c31cb\", \"SoftWareVersion\" :" "\"V4.02.R12.D4806531.10002.142100.00000\", \"TalkInChannel\" : 1, \"TalkOutChannel\" : 1, \"UpdataTime\" : \"\", \"UpdataType\" :" "\"0x00000000\", \"VideoInChannel\" : 1, \"VideoOutChannel\" : 1, \"DeviceType\" : 0 } }");
	};

	~SystemInfo(void){};
};

NS_NETSDK_CFG_END