#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PreviewFunction "PreviewFunction" 
class PreviewFunction : public JObject
{
public:
	JBoolObj		GUISet;
	JBoolObj		Tour;

public:
    PreviewFunction(JObject *pParent = NULL, const char *szName = JK_PreviewFunction):
    JObject(pParent,szName),
	GUISet(this, "GUISet"),
	Tour(this, "Tour"){
	};

    ~PreviewFunction(void){};
};

NS_NETSDK_CFG_END