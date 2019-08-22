#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetServerFunction "NetServerFunction" 
class NetServerFunction : public JObject
{
public:
	JBoolObj		MACProtocol;
	JBoolObj		MonitorPlatform;
	JBoolObj		NATProtocol;
	JBoolObj		Net3G;
	JBoolObj		NetARSP;
	JBoolObj		NetAlarmCenter;
	JBoolObj		NetAnJuP2P;
	JBoolObj		NetBaiduCloud;
	JBoolObj		NetBjlThy;
	JBoolObj		NetDAS;
	JBoolObj		NetDDNS;
	JBoolObj		NetDHCP;
	JBoolObj		NetDNS;
	JBoolObj		NetEmail;
	JBoolObj		NetFTP;
	JBoolObj		NetGodEyeAlarm;
	JBoolObj		NetIPFilter;
	JBoolObj		NetKaiCong;
	JBoolObj		NetKeyboard;
	JBoolObj		NetLocalSdkPlatform;
	JBoolObj		NetMobile;
	JBoolObj		NetMobileWatch;
	JBoolObj		NetMutliCast;
	JBoolObj		NetNTP;
	JBoolObj		NetNat;
	JBoolObj		NetOpenVPN;
	JBoolObj		NetPMS;
	JBoolObj		NetPPPoE;
	JBoolObj		NetPhoneMultimediaMsg;
	JBoolObj		NetPhoneShortMsg;
	JBoolObj		NetPlatMega;
	JBoolObj		NetPlatShiSou;
	JBoolObj		NetPlatVVEye;
	JBoolObj		NetPlatXingWang;
	JBoolObj		NetRTSP;
	JBoolObj		NetSPVMN;
	JBoolObj		NetTUTKIOTC;
	JBoolObj		NetUPNP;
	JBoolObj		NetVPN;
	JBoolObj		NetWifi;
	JBoolObj		PlatFormGBeyes;
	JBoolObj		XMHeartBeat;

public:
    NetServerFunction(JObject *pParent = NULL, const char *szName = JK_NetServerFunction):
    JObject(pParent,szName),
	MACProtocol(this, "MACProtocol"),
	MonitorPlatform(this, "MonitorPlatform"),
	NATProtocol(this, "NATProtocol"),
	Net3G(this, "Net3G"),
	NetARSP(this, "NetARSP"),
	NetAlarmCenter(this, "NetAlarmCenter"),
	NetAnJuP2P(this, "NetAnJuP2P"),
	NetBaiduCloud(this, "NetBaiduCloud"),
	NetBjlThy(this, "NetBjlThy"),
	NetDAS(this, "NetDAS"),
	NetDDNS(this, "NetDDNS"),
	NetDHCP(this, "NetDHCP"),
	NetDNS(this, "NetDNS"),
	NetEmail(this, "NetEmail"),
	NetFTP(this, "NetFTP"),
	NetGodEyeAlarm(this, "NetGodEyeAlarm"),
	NetIPFilter(this, "NetIPFilter"),
	NetKaiCong(this, "NetKaiCong"),
	NetKeyboard(this, "NetKeyboard"),
	NetLocalSdkPlatform(this, "NetLocalSdkPlatform"),
	NetMobile(this, "NetMobile"),
	NetMobileWatch(this, "NetMobileWatch"),
	NetMutliCast(this, "NetMutliCast"),
	NetNTP(this, "NetNTP"),
	NetNat(this, "NetNat"),
	NetOpenVPN(this, "NetOpenVPN"),
	NetPMS(this, "NetPMS"),
	NetPPPoE(this, "NetPPPoE"),
	NetPhoneMultimediaMsg(this, "NetPhoneMultimediaMsg"),
	NetPhoneShortMsg(this, "NetPhoneShortMsg"),
	NetPlatMega(this, "NetPlatMega"),
	NetPlatShiSou(this, "NetPlatShiSou"),
	NetPlatVVEye(this, "NetPlatVVEye"),
	NetPlatXingWang(this, "NetPlatXingWang"),
	NetRTSP(this, "NetRTSP"),
	NetSPVMN(this, "NetSPVMN"),
	NetTUTKIOTC(this, "NetTUTKIOTC"),
	NetUPNP(this, "NetUPNP"),
	NetVPN(this, "NetVPN"),
	NetWifi(this, "NetWifi"),
	PlatFormGBeyes(this, "PlatFormGBeyes"),
	XMHeartBeat(this, "XMHeartBeat"){
	};

    ~NetServerFunction(void){};
};

NS_NETSDK_CFG_END