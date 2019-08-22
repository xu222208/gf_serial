#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_Wifi "NetWork.Wifi" 
class NetWork_Wifi : public JObject
{
public:
	JStrObj		Auth;
	JIntObj		Channel;
	JBoolObj		Enable;
	JStrObj		EncrypType;
	JStrObj		GateWay;
	JStrObj		HostIP;
	JIntObj		KeyType;
	JStrObj		Keys;
	JStrObj		NetType;
	JStrObj		SSID;
	JStrObj		Submask;

public:
    NetWork_Wifi(JObject *pParent = NULL, const char *szName = JK_NetWork_Wifi):
    JObject(pParent,szName),
	Auth(this, "Auth"),
	Channel(this, "Channel"),
	Enable(this, "Enable"),
	EncrypType(this, "EncrypType"),
	GateWay(this, "GateWay"),
	HostIP(this, "HostIP"),
	KeyType(this, "KeyType"),
	Keys(this, "Keys"),
	NetType(this, "NetType"),
	SSID(this, "SSID"),
	Submask(this, "Submask"){
	};

    ~NetWork_Wifi(void){};
};

NS_NETSDK_CFG_END