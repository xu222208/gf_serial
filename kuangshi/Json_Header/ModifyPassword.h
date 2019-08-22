#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_ModifyPassword "ModifyPassword"
class ModifyPassword : public JObject   //修改密码相关
{
public:
	JStrObj		EncryptType;
	JStrObj		NewPassWord;
	JStrObj		PassWord;
	JStrObj		SessionID;
	JStrObj		UserName;

public:
	ModifyPassword(JObject *pParent = NULL, const char *szName = JK_ModifyPassword):
	JObject(pParent,szName),
	EncryptType(this, "EncryptType"),
	NewPassWord(this, "NewPassWord"),
	PassWord(this, "PassWord"),
	SessionID(this, "SessionID"),
	UserName(this, "UserName"){
	};

	~ModifyPassword(void){};
};

NS_NETSDK_CFG_END