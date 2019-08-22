#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_TipShow "TipShow" 
class TipShow : public JObject
{
public:
	JBoolObj		NoBeepTipShow;
	JBoolObj		NoEmailTipShow;
	JBoolObj		NoFTPTipShow;

public:
    TipShow(JObject *pParent = NULL, const char *szName = JK_TipShow):
    JObject(pParent,szName),
	NoBeepTipShow(this, "NoBeepTipShow"),
	NoEmailTipShow(this, "NoEmailTipShow"),
	NoFTPTipShow(this, "NoFTPTipShow"){
	};

    ~TipShow(void){};
};

NS_NETSDK_CFG_END