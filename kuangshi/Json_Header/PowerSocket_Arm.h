#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_Arm "PowerSocket.Arm" 
class PowerSocket_Arm : public JObject
{
public:
	JIntObj		Guard;

public:
    PowerSocket_Arm(JObject *pParent = NULL, const char *szName = JK_PowerSocket_Arm):
    JObject(pParent,szName),
	Guard(this, "Guard"){
	};

    ~PowerSocket_Arm(void){};
};

NS_NETSDK_CFG_END