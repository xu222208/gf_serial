#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_MobileDVR "MobileDVR" 
class MobileDVR : public JObject
{
public:
	JBoolObj		CarPlateSet;
	JBoolObj		DVRBootType;
	JBoolObj		DelaySet;
	JBoolObj		GpsTiming;
	JBoolObj		StatusExchange;

public:
    MobileDVR(JObject *pParent = NULL, const char *szName = JK_MobileDVR):
    JObject(pParent,szName),
	CarPlateSet(this, "CarPlateSet"),
	DVRBootType(this, "DVRBootType"),
	DelaySet(this, "DelaySet"),
	GpsTiming(this, "GpsTiming"),
	StatusExchange(this, "StatusExchange"){
	};

    ~MobileDVR(void){};
};

NS_NETSDK_CFG_END