#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_Camera_ClearFog "Camera.ClearFog" 
class Camera_ClearFog : public JObject
{
public:
	JBoolObj    enable;
	JIntObj		level;

public:
    Camera_ClearFog(JObject *pParent = NULL, const char *szName = JK_Camera_ClearFog):
    JObject(pParent,szName),
	enable (this, "enable"),
	level (this, "level"){
	};

    ~Camera_ClearFog(void){};
};

NS_NETSDK_CFG_END