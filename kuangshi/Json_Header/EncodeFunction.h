#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_EncodeFunction "EncodeFunction" 
class EncodeFunction : public JObject
{
public:
	JBoolObj		CombineStream;
	JBoolObj		DoubleStream;
	JBoolObj		SnapStream;
	JBoolObj		WaterMark;

public:
    EncodeFunction(JObject *pParent = NULL, const char *szName = JK_EncodeFunction):
    JObject(pParent,szName),
	CombineStream(this, "CombineStream"),
	DoubleStream(this, "DoubleStream"),
	SnapStream(this, "SnapStream"),
	WaterMark(this, "WaterMark"){
	};

    ~EncodeFunction(void){};
};

NS_NETSDK_CFG_END