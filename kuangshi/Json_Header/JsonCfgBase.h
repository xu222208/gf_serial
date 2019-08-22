#pragma once
#include "JObject.h"
#include <string>
using namespace std;
NS_NETSDK_CFG_BEGIN

#define CFG_CHN_NAME(x,y) JCFG::GetChnCfgName(x, y).c_str()
namespace JCFG
{
    string GetChnCfgName(const char *szCfgName, int nChnIndex);
}

NS_NETSDK_CFG_END


