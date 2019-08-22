#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_ChannelTitle "ChannelTitle" 
class ChannelTitle : public JObject
{
public:
	JStrObj		Name;
	JStrObj		SerialNo;

public:
    ChannelTitle(JObject *pParent = NULL, const char *szName = JK_ChannelTitle):
    JObject(pParent,szName),
	Name(this, "Name"),
	SerialNo(this, "SerialNo"){
	};

    ~ChannelTitle(void){};
};

NS_NETSDK_CFG_END