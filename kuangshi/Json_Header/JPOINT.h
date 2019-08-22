#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_POINT "POINT" 
class JPOINT : public JObject
{
public:
	JIntObj		bottom;
	JIntObj		left;
	JIntObj		right;
	JIntObj		top;

public:
    JPOINT(JObject *pParent = NULL, const char *szName = JK_POINT):
    JObject(pParent,szName),
	bottom(this, "bottom"),
	left(this, "left"),
	right(this, "right"),
	top(this, "top"){
	};

    ~JPOINT(void){};
};

NS_NETSDK_CFG_END