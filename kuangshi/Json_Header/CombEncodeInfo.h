#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_CombEncodeInfo "CombEncodeInfo" 
class CombEncodeInfo : public JObject
{
public:
	JIntHex		CompressionMask;
	JBoolObj		Enable;
	JBoolObj		HaveAudio;
	JIntHex		ResolutionMask;
	JStrObj		StreamType;

public:
	CombEncodeInfo(JObject *pParent = NULL, const char *szName = JK_CombEncodeInfo):
	JObject(pParent,szName),
	CompressionMask(this, "CompressionMask"),
	Enable(this, "Enable"),
	HaveAudio(this, "HaveAudio"),
	ResolutionMask(this, "ResolutionMask"),
	StreamType(this, "StreamType"){
	};

	~CombEncodeInfo(void){};
};

NS_NETSDK_CFG_END