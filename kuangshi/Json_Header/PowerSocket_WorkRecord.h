#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_WorkRecord "PowerSocket.WorkRecord" 
class PowerSocket_WorkRecord : public JObject
{
public:
	JIntObj		TotalEnergy;
	JIntObj		TotalTime;
	JIntObj		EnergyOfThisMon;
	JIntObj		TimeOfThisMon;
	JIntObj		EnergyRecently;
	JIntObj		TimeRecently;
	JIntObj		DeviceType;
	JIntObj		DevicePower;

public:
    PowerSocket_WorkRecord(JObject *pParent = NULL, const char *szName = JK_PowerSocket_WorkRecord):
    JObject(pParent,szName),
	TotalEnergy(this, "TotalEnergy"),
	TotalTime(this, "TotalTime"),
	EnergyOfThisMon(this, "EnergyOfThisMon"),
	TimeOfThisMon(this, "TimeOfThisMon"),
	EnergyRecently(this, "EnergyRecently"),
	TimeRecently(this, "TimeRecently"),
	DeviceType(this, "DeviceType"),
	DevicePower(this, "DevicePower"){
	};

    ~PowerSocket_WorkRecord(void){};
};

NS_NETSDK_CFG_END