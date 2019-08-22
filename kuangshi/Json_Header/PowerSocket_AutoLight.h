#pragma once
#include "JObject.h"
#include "PowerSocketAutoLightItem.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_AutoLight "PowerSocket.AutoLight" 
class PowerSocket_AutoLight : public JObject
{
public:
	JObjArray<PowerSocketAutoLightItem>		AutoLight;

public:
    PowerSocket_AutoLight(JObject *pParent = NULL, const char *szName = JK_PowerSocket_AutoLight):
    JObject(pParent,szName),
	AutoLight(this, ""){
	};

    ~PowerSocket_AutoLight(void){};
};

NS_NETSDK_CFG_END