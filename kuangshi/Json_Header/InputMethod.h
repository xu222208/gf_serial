#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_InputMethod "InputMethod" 
class InputMethod : public JObject
{
public:
	JBoolObj		NoSupportChinese;

public:
    InputMethod(JObject *pParent = NULL, const char *szName = JK_InputMethod):
    JObject(pParent,szName),
	NoSupportChinese(this, "NoSupportChinese"){
	};

    ~InputMethod(void){};
};

NS_NETSDK_CFG_END