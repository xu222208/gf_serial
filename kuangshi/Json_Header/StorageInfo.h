#pragma once
#include "JObject.h"
#include "Partition.h"
NS_NETSDK_CFG_BEGIN

#define JK_StorageInfo "StorageInfo"
class StorageInfo : public JObject  //磁盘分区
{
public:
	JIntObj		PartNumber;
	JObjArray<Partition>		Partition;
	JIntObj		PlysicalNo;

public:
	StorageInfo(JObject *pParent = NULL, const char *szName = JK_StorageInfo):
	JObject(pParent,szName),
	PartNumber(this, "PartNumber"),
	Partition(this, "Partition"),
	PlysicalNo(this, "PlysicalNo"){
	};

	~StorageInfo(void){};
};

NS_NETSDK_CFG_END