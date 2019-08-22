#pragma once
#include "JObject.h"
#include "ExtraFormat.h"
#include "MainFormat.h"
NS_NETSDK_CFG_BEGIN

#define JK_Simplify_Encode "Simplify.Encode" 
class Simplify_Encode : public JObject
{
public:
	ExtraFormat		mExtraFormat;
	MainFormat		mMainFormat;

public:
	Simplify_Encode(JObject *pParent = NULL, const char *szName = JK_Simplify_Encode):
	JObject(pParent,szName),
	mExtraFormat(this, "ExtraFormat"),
	mMainFormat(this, "MainFormat"){
	};

	~Simplify_Encode(void){};
};

NS_NETSDK_CFG_END