#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN 

#define JK_OPTimeSetting "OPTimeSetting" 
class OPTimeSetting : public JObject
{
public:
	JStrObj		Name;
	JStrObj		mOPTimeSetting;
	JStrObj		SessionID;

public:
	OPTimeSetting():
	JObject(NULL, ""),
	Name(this, JK_OPTimeSetting),
	mOPTimeSetting(this, "\"2018-07-25 17:20:37\""),
	SessionID(this, "SessionID")
	{
		this->Parse("{ \"Name\" : \"OPTimeSetting\", \"OPTimeSetting\" : \"2018-07-25 17:20:37\", \"SessionID\" : \"0x00000000\" }");
	};

	~OPTimeSetting(void)
	{

	};
};

NS_NETSDK_CFG_END 