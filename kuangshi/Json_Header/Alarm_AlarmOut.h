#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_Alarm_AlarmOut "Alarm.AlarmOut"
class Alarm_AlarmOut : public JObject  
{
public:
	JStrObj		AlarmOutStatus;
	JStrObj		AlarmOutType;

public:
	Alarm_AlarmOut(JObject *pParent = NULL, const char *szName = JK_Alarm_AlarmOut):
	JObject(pParent,szName),
	AlarmOutStatus(this, "AlarmOutStatus"),
	AlarmOutType(this, "AlarmOutType"){
	};

	~Alarm_AlarmOut(void){};
};

NS_NETSDK_CFG_END