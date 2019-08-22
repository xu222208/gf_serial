#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_UserInfo "" 
class UserInfos : public JObject
{
public:
	JObjArray<JStrObj>		AuthorityList;
	JStrObj		Group;
	JStrObj		Memo;
	JStrObj		Names;
	JBoolObj		NoMD5;
	JStrObj		Password;
	JBoolObj		Reserved;
	JBoolObj		Sharable;

public:
	UserInfos(JObject *pParent = NULL, const char *szName = JK_UserInfo):
	JObject(pParent,szName),
	AuthorityList(this, "AuthorityList"),
	Group(this, "Group"),
	Memo(this, "Memo"),
	Names(this, "Name"),
	NoMD5(this, "NoMD5"),
	Password(this, "Password"),
	Reserved(this, "Reserved"),
	Sharable(this, "Sharable"){
	};

	~UserInfos(void){};
};

NS_NETSDK_CFG_END