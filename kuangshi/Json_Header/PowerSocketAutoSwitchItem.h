#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocketAutoSwitchItem "" 
class PowerSocketAutoSwitchItem : public JObject
{
public:
	JIntObj		TimeStart;
	JIntObj		TimeStop;
	JIntObj		DayStart;
	JIntObj		DayStop;
	JBoolObj		Enable;

public:
    PowerSocketAutoSwitchItem(JObject *pParent = NULL, const char *szName = JK_PowerSocketAutoSwitchItem):
    JObject(pParent,szName),
	TimeStart(this, "TimeStart"),
	TimeStop(this, "TimeStop"),
	DayStart(this, "DayStart"),
	DayStop(this, "DayStop"),
	Enable(this, "Enable"){
	};

    ~PowerSocketAutoSwitchItem(void){};
};

NS_NETSDK_CFG_END