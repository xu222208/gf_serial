#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_Sensitive "PowerSocket.Sensitive" 
class PowerSocket_Sensitive : public JObject
{
public:
	JIntObj		Sensitive;

public:
    PowerSocket_Sensitive(JObject *pParent = NULL, const char *szName = JK_PowerSocket_Sensitive):
    JObject(pParent,szName),
	Sensitive(this, "Sensitive"){
	};

    ~PowerSocket_Sensitive(void){};
};

NS_NETSDK_CFG_END