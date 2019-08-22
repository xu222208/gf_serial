#pragma once
#include "JObject.h"
#include "CFG_AUX.h"
#include "JPOINT.h"
NS_NETSDK_CFG_BEGIN

#define JK_Parameter "Parameter" 
class Parameter : public JObject
{
public:
	AUX			mAUX;
	JIntObj		Channel;
	JStrObj		MenuOpts;
	JPOINT		mPOINT;
	JStrObj		Pattern;
	JIntObj		Preset;
	JIntObj		Step;
	JIntObj		Tour;

public:
    Parameter(JObject *pParent = NULL, const char *szName = JK_Parameter):
    JObject(pParent,szName),
	mAUX(this, "AUX"),
	Channel(this, "Channel"),
	MenuOpts(this, "MenuOpts"),
	mPOINT(this, "POINT"),
	Pattern(this, "Pattern"),
	Preset(this, "Preset"),
	Step(this, "Step"),
	Tour(this, "Tour"){
	};

    ~Parameter(void){};
};

NS_NETSDK_CFG_END
