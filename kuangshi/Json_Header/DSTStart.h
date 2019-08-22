#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_DSTStart "DSTStart" 
class DSTStart : public JObject
{
public:
	JIntObj		Day;
	JIntObj		Hour;
	JIntObj		Minute;
	JIntObj		Month;
	JIntObj		Week;
	JIntObj		Year;

public:
	DSTStart(JObject *pParent = NULL, const char *szName = JK_DSTStart):
	JObject(pParent,szName),
	Day(this, "Day"),
	Hour(this, "Hour"),
	Minute(this, "Minute"),
	Month(this, "Month"),
	Week(this, "Week"),
	Year(this, "Year"){
	};

	~DSTStart(void){};
};

NS_NETSDK_CFG_END