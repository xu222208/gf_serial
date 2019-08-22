#pragma once
#include "JsonCfgBase.h"

#define JK_Record "Record"
class RecordCfg : public JObject   //SDK_RECORDCONFIG  录像设置
{
public:
    JObjArray<JObjArray<JIntHex> > Mask;
	JIntObj		PacketLength;
	JIntObj		PreRecord;
	JStrObj		RecordMode;
	JBoolObj	Redundancy;
	JObjArray<JObjArray<JStrObj> >	TimeSection;

public:
	RecordCfg(JObject *pParent = NULL, const char *szName = JK_Record):
	JObject(pParent,szName),
	Mask(this, "Mask"),
	PacketLength(this, "PacketLength"),
	PreRecord(this, "PreRecord"),
	RecordMode(this, "RecordMode"),
	Redundancy(this, "Redundancy"),
	TimeSection(this, "TimeSection"){
	};

	~RecordCfg(void){};
};