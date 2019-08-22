#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_NetCommon "NetWork.NetCommon" 
class NetWork_NetCommon : public JObject
{
public:
	JStrObj		DeviceID;
	JIntObj		DeviceType;
	JStrObj		DvrMac;
	JIntObj		EncryptType;
	JStrObj		GateWay;
	JStrObj		HostIP;
	JStrObj		HostName;
	JIntObj		HttpPort;
	JStrObj		MAC;
	JIntObj		MaxBps;
	JIntObj		MonMode;
	JStrObj		Password;
	JStrObj		SN;
	JIntObj		SSLPort;
	JStrObj		Submask;
	JIntObj		TCPMaxConn;
	JIntObj		TCPPort;
	JIntObj		TransferPlan;
	JIntObj		UDPPort;
	JBoolObj	UseHSDownLoad;
	JStrObj		Username;
	JStrObj		Version;
	JStrObj		BuildDate;

public:
	NetWork_NetCommon(JObject *pParent = NULL, const char *szName = JK_NetWork_NetCommon):
	JObject(pParent,szName),
	DeviceID(this, "DeviceID"),
	DeviceType(this, "DeviceType"),
	DvrMac(this, "DvrMac"),
	EncryptType(this, "EncryptType"),
	GateWay(this, "GateWay"),
	HostIP(this, "HostIP"),
	HostName(this, "HostName"),
	HttpPort(this, "HttpPort"),
	MAC(this, "MAC"),
	MaxBps(this, "MaxBps"),
	MonMode(this, "MonMode"),
	Password(this, "Password"),
	SN(this, "SN"),
	SSLPort(this, "SSLPort"),
	Submask(this, "Submask"),
	TCPMaxConn(this, "TCPMaxConn"),
	TCPPort(this, "TCPPort"),
	TransferPlan(this, "TransferPlan"),
	UDPPort(this, "UDPPort"),
	UseHSDownLoad(this, "UseHSDownLoad"),
	Username(this, "Username"),
	Version(this, "Version"),
	BuildDate(this, "BuildDate"){
        const char *szInit = "{ \"Name\" : \"NetWork.NetCommon\", \"NetWork.NetCommon\" : { \"DeviceID\" : \"0x00000000\", \"DeviceType\" : 65535, \"DvrMac\" : \"50:7B:9D:C2:04:FA\", \"EncryptType\" : 1, \"GateWay\" : \"0x01200a0a\", \"HostIP\" : \"0x010aa8c0\", \"HostName\" : \"robot_5002\", \"HttpPort\" : 80, \"MAC\" : \"ac:a2:13:0e:50:02\", \"MaxBps\" : 0, \"MonMode\" : 0, \"Password\" : \"QyZfVmgd\", \"SN\" : \"\", \"SSLPort\" : 8443, \"Submask\" : \"0x00f0ffff\", \"TCPMaxConn\" : 10, \"TCPPort\" : 34567, \"TransferPlan\" : 0, \"UDPPort\" : 34562, \"UseHSDownLoad\" : false, \"Username\" : \"admin\", \"Version\" : \"V4.02.R12.E1207810.12002.130302.00000\", \"BuildDate\" : \"2016-12-30 10:53:37\"  }, \"Ret\" : 100, \"SessionID\" : \"0x00000000\" }";
        this->Parse(szInit);
	};

	~NetWork_NetCommon(void){};
};

NS_NETSDK_CFG_END
