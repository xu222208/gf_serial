#pragma once
#include "JObject.h"
#include "EncodeInfo.h"
#include "CombEncodeInfo.h"
NS_NETSDK_CFG_BEGIN

#define JK_EncodeCapability "EncodeCapability" 
class EncodeCapability : public JObject
{
public:
	JIntObj		ChannelMaxSetSync;
	JObjArray<CombEncodeInfo>		CombEncodeInfo;
	JIntHex		Compression;
	JObjArray<EncodeInfo>		EncodeInfo;
	JObjArray<JIntHex>		ExImageSizePerChannel;
	JObjArray<JObjArray<JIntHex> >		ExImageSizePerChannelEx;
	JObjArray<JIntHex>		ImageSizePerChannel;
	JIntObj		MaxBitrate;
	JIntObj		MaxEncodePower;
	JObjArray<JIntHex>		MaxEncodePowerPerChannel;

public:
	EncodeCapability(JObject *pParent = NULL, const char *szName = JK_EncodeCapability):
	JObject(pParent,szName),
	ChannelMaxSetSync(this, "ChannelMaxSetSync"),
	CombEncodeInfo(this, "CombEncodeInfo"),
	Compression(this, "Compression"),
	EncodeInfo(this, "EncodeInfo"),
	ExImageSizePerChannel(this, "ExImageSizePerChannel"),
	ExImageSizePerChannelEx(this, "ExImageSizePerChannelEx"),
	ImageSizePerChannel(this, "ImageSizePerChannel"),
	MaxBitrate(this, "MaxBitrate"),
	MaxEncodePower(this, "MaxEncodePower"),
	MaxEncodePowerPerChannel(this, "MaxEncodePowerPerChannel"){
	};

	~EncodeCapability(void){};
};

NS_NETSDK_CFG_END