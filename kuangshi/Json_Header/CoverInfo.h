#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_CoverInfo ""
class CoverInfo : public JObject
{
public:
	JIntHex		BackColor;
	JBoolObj		EncodeBlend;
	JIntHex		FrontColor;
	JBoolObj		PreviewBlend;
	JObjArray<JObjArray<JStrObj> >		RelativePos;

public:
    CoverInfo(JObject *pParent = NULL, const char *szName = JK_CoverInfo):
    JObject(pParent,szName),
	BackColor(this, "BackColor"),
	EncodeBlend(this, "EncodeBlend"),
	FrontColor(this, "FrontColor"),
	PreviewBlend(this, "PreviewBlend"),
	RelativePos(this, "RelativePos"){
	};

    ~CoverInfo(void){};
};

NS_NETSDK_CFG_END