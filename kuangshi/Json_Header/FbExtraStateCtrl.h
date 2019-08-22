#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_FbExtraStateCtrl "FbExtraStateCtrl" 
class FbExtraStateCtrl : public JObject
{
public:
	JIntObj		ison;

public:
    FbExtraStateCtrl(JObject *pParent = NULL, const char *szName = JK_FbExtraStateCtrl):
    JObject(pParent,szName),
	ison(this, "ison"){
	};

    ~FbExtraStateCtrl(void){};
};

NS_NETSDK_CFG_END