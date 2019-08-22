#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_BanLed "PowerSocket.BanLed" 
class PowerSocket_BanLed : public JObject
{
public:
	JIntObj		Banstatus;

public:
    PowerSocket_BanLed(JObject *pParent = NULL, const char *szName = JK_PowerSocket_BanLed):
    JObject(pParent,szName),
	Banstatus(this, "Banstatus"){
	};

    ~PowerSocket_BanLed(void){};
};

NS_NETSDK_CFG_END