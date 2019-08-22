#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_SupportExtRecord "SupportExtRecord" 
class SupportExtRecord : public JObject
{
public:
	JStrObj		AbilityPram;

public:
	SupportExtRecord(JObject *pParent = NULL, const char *szName = JK_SupportExtRecord):
	JObject(pParent,szName),
	AbilityPram(this, "AbilityPram"){
	};

	~SupportExtRecord(void){};
};

NS_NETSDK_CFG_END