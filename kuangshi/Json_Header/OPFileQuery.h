#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPFileQuery "OPFileQuery" 

// MSGID:EXCMD_FILESEARCH_REQ(1440)
class OPFileQuery : public JObject
{
public:
	JStrObj		BeginTime;
	JIntObj		Channel;
	JStrObj		DriverTypeMask;
	JStrObj		EndTime;
	JStrObj		SubType;
	JIntHex		StreamType;
	JStrObj		Type;

public:
	OPFileQuery(JObject *pParent = NULL, const char *szName = JK_OPFileQuery):
	JObject(pParent,szName),
	BeginTime(this, "BeginTime"),
	Channel(this, "Channel"),
	DriverTypeMask(this, "DriverTypeMask"),
	EndTime(this, "EndTime"),
	SubType(this, "Event"),
	StreamType(this, "StreamType"),
	Type(this, "Type")
	{
		this->Parse("{ \"Name\" : \"OPFileQuery\", \"OPFileQuery\" : { \"BeginTime\" : \"2018-07-24 00:00:00\", \"Channel\" : 0, \"DriverTypeMask\" : \"0x0000FFFF\", \"EndTime\" : \"2018-07-24 23:59:59\", \"Event\" : \"*\", \"StreamType\" : \"0x00000000\", \"Type\" : \"h264\" }, \"SessionID\" : \"0x4d5\" }");
	};

	~OPFileQuery(void){};
};

NS_NETSDK_CFG_END