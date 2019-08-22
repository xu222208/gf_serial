#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_DelaySwitch "PowerSocket.DelaySwitch" 
class PowerSocket_DelaySwitch : public JObject
{
public:
	JIntObj		PeriodOn;
	JIntObj		PeriodOff;
	JIntObj		Mode;
	JIntObj		Enable;

public:
    PowerSocket_DelaySwitch(JObject *pParent = NULL, const char *szName = JK_PowerSocket_DelaySwitch):
    JObject(pParent,szName),
	PeriodOn(this, "PeriodOn"),
	PeriodOff(this, "PeriodOff"),
	Mode(this, "Mode"),
	Enable(this, "Enable"){
	};

    ~PowerSocket_DelaySwitch(void){};
};

NS_NETSDK_CFG_END