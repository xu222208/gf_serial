#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_ChannelTitleAttribute "ChannelTitleAttribute" 
class ChannelTitleAttribute : public JObject
{
public:
	JStrObj		BackColor;
	JBoolObj		EncodeBlend;
	JStrObj		FrontColor;
	JBoolObj		PreviewBlend;
	JObjArray<JIntObj>		RelativePos;

public:
    ChannelTitleAttribute(JObject *pParent = NULL, const char *szName = JK_ChannelTitleAttribute):
    JObject(pParent,szName),
	BackColor(this, "BackColor"),
	EncodeBlend(this, "EncodeBlend"),
	FrontColor(this, "FrontColor"),
	PreviewBlend(this, "PreviewBlend"),
	RelativePos(this, "RelativePos"){
	};

    ~ChannelTitleAttribute(void){};
};

NS_NETSDK_CFG_END