#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_EncodeInfo "EncodeInfo" 
class EncodeInfo : public JObject
{
public:
	JIntHex		CompressionMask;
	JBoolObj		Enable;
	JBoolObj		HaveAudio;
	JIntHex		ResolutionMask;
	JStrObj		StreamType;

public:
	EncodeInfo(JObject *pParent = NULL, const char *szName = JK_EncodeInfo):
	JObject(pParent,szName),
	CompressionMask(this, "CompressionMask"),
	Enable(this, "Enable"),
	HaveAudio(this, "HaveAudio"),
	ResolutionMask(this, "ResolutionMask"),
	StreamType(this, "StreamType"){
	};

	~EncodeInfo(void){};
};

NS_NETSDK_CFG_END