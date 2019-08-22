#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_BroadTrends "BroadTrends" 
class BroadTrends : public JObject
{
public:
	JIntObj		AutoGain;
	JIntObj		Gain;

public:
    BroadTrends(JObject *pParent = NULL, const char *szName = JK_BroadTrends):
    JObject(pParent,szName),
	AutoGain(this, "AutoGain"),
	Gain(this, "Gain"){
	};

    ~BroadTrends(void){};
};

NS_NETSDK_CFG_END