#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPPowerSocketGet "OPPowerSocketGet" 
class OPPowerSocketGet : public JObject
{
public:
	JIntObj		Switch;
	JIntObj		AutoSwitch;
	JIntObj		Light;
	JIntObj		UsbPower;
	JIntObj		AutoLight;
	JIntObj		AutoUsbPower;
	JIntObj		SensorSwitch;
	JIntObj		SensorLight;
	JIntObj		SensorUsbPower;

public:
    OPPowerSocketGet(JObject *pParent = NULL, const char *szName = JK_OPPowerSocketGet):
    JObject(pParent,szName),
	Switch(this, "Switch"),
	AutoSwitch(this, "AutoSwitch"),
	Light(this, "Light"),
	UsbPower(this, "UsbPower"),
	AutoLight(this, "AutoLight"),
	AutoUsbPower(this, "AutoUsbPower"),
	SensorSwitch(this, "SensorSwitch"),
	SensorLight(this, "SensorLight"),
	SensorUsbPower(this, "SensorUsbPower"){
	};

    ~OPPowerSocketGet(void){};
};

NS_NETSDK_CFG_END