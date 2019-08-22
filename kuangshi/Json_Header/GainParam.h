#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_GainParam "GainParam" 
class GainParam : public JObject
{
public:
	JIntObj		AutoGain;
	JIntObj		Gain;

public:
	GainParam(JObject *pParent = NULL, const char *szName = JK_GainParam):
	JObject(pParent,szName),
	AutoGain(this, "AutoGain"),
	Gain(this, "Gain"){
	};

	~GainParam(void){};
};

NS_NETSDK_CFG_END