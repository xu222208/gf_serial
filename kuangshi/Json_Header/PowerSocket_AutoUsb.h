#pragma once
#include "JObject.h"
#include "PowerSocketAutoUsbItem.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_AutoUsb "PowerSocket.AutoUsb" 
class PowerSocket_AutoUsb : public JObject
{
public:
	JObjArray<PowerSocketAutoUsbItem>		AutoUsb;

public:
    PowerSocket_AutoUsb(JObject *pParent = NULL, const char *szName = JK_PowerSocket_AutoUsb):
    JObject(pParent,szName),
	AutoUsb(this, ""){
	};

    ~PowerSocket_AutoUsb(void){};
};

NS_NETSDK_CFG_END