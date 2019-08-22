#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PowerSocket_Image "PowerSocket.Image" 
class PowerSocket_Image : public JObject
{
public:
	JIntObj		flip;

public:
    PowerSocket_Image(JObject *pParent = NULL, const char *szName = JK_PowerSocket_Image):
    JObject(pParent,szName),
	flip(this, "flip"){
	};

    ~PowerSocket_Image(void){};
};

NS_NETSDK_CFG_END