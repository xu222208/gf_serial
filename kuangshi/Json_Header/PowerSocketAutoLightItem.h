#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocketAutoLightItem "" 
class PowerSocketAutoLightItem : public JObject
{
public:
	JIntObj		DayStop;
	JBoolObj		Enable;
	JIntObj		TimeStop;
	JIntObj		TimeStart;
	JIntObj		DayStart;

public:
    PowerSocketAutoLightItem(JObject *pParent = NULL, const char *szName = JK_PowerSocketAutoLightItem):
    JObject(pParent,szName),
	DayStop(this, "DayStop"),
	Enable(this, "Enable"),
	TimeStop(this, "TimeStop"),
	TimeStart(this, "TimeStart"),
	DayStart(this, "DayStart"){
	};

    ~PowerSocketAutoLightItem(void){};
};

NS_NETSDK_CFG_END