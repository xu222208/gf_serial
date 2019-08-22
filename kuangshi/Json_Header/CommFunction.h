#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_CommFunction "CommFunction" 
class CommFunction : public JObject
{
public:
	JBoolObj		CommRS232;
	JBoolObj		CommRS485;

public:
    CommFunction(JObject *pParent = NULL, const char *szName = JK_CommFunction):
    JObject(pParent,szName),
	CommRS232(this, "CommRS232"),
	CommRS485(this, "CommRS485"){
	};

    ~CommFunction(void){};
};

NS_NETSDK_CFG_END