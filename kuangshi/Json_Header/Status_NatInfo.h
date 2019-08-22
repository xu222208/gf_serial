#pragma once
#include "JsonCfgBase.h"

#define JK_Status_NatInfo "Status.NatInfo" 
class Status_NatInfo : public JObject   //网络状态头文件
{
public:
	JStrObj		NaInfoCode;
	JStrObj		NatStatus;

public:
	Status_NatInfo(JObject *pParent = NULL, const char *szName = JK_Status_NatInfo):
	JObject(pParent,szName),
	NaInfoCode(this, "NaInfoCode"),
	NatStatus(this, "NatStatus"){
	};

	~Status_NatInfo(void){};
};