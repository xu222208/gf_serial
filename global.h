//
// Created by hxd on 18-5-7.
//

#ifndef FACEPICTURECLIENT_GLOBAL_H
#define FACEPICTURECLIENT_GLOBAL_H

#include <string.h>
#include <tcp_conf_handle.h>
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "double_list/ListThread.h"
#include "log4cpp/CLog.h"

using namespace rapidjson;
using namespace std;

typedef enum _CAMERA_TAG {
    //海康
            HIKVISION = 1,
    //大华
            DAHUA,
    //巨龙创视
            JVT,
    //安视宝
            ANSPO_CAR,
    //蓝卡
            LAN_KA,
    //猎熊座
            BEARHUNTING,
    //旷世
            KUANGSHI,
    //宇视
           NETDEV
} CAMERA_TAG;

typedef enum _CAP_TYPE {
    FACE_CAP = 1, //人脸抓拍
    CAR_CAP       //车牌抓拍
} CAP_TYPE;

//颜色
typedef enum _COLOUR_TYPE {
    COLOUR_BLACK = 1,//黑 1
    COLOUR_WHITE,//白
    COLOUR_ASH,//灰
    COLOUR_RED,//红
    COLOUR_BLUE,//蓝
    COLOUR_YELLOW,//黄
    COLOUR_ORANGE,//橙
    COLOUR_BROWN,//棕
    COLOUR_GREEN,//绿
    COLOUR_PURPLE,//紫
    COLOUR_BLUE_OR_GREEN,//青
    COLOUR_PINK,//粉
    COLOUR_TRANSPARENT,//透明
    COLOUR_OTHER//其他
} COLOUR_TYPE;

//号牌种类
typedef enum _LICENSE_TYPE {
    LICENSE_LARGE_CAR = 1,//大型汽车号牌 1
    LICENSE_SMALL_CAR,//小型汽车号牌
    LICENSE_EMBASSY_CAR,//使馆汽车号牌
    LICENSE_CONSULATE_CAR,//领馆汽车号牌
    LICENSE_POLICE_CAR = 23,//警用汽车号牌 23
    LICENSE_ARMED_POLICE = 31,//武警号牌 31
    LICENSE_ARMY,//军队号牌
    LICENSE_OTHER//其它号牌
} LICENSE_TYPE;

typedef struct {
    int nYear;        //年
    int nMonth;        //月
    int nDay;        //日
    int nHour;        //时
    int nMinute;        //分
    int nSecond;        //秒
} DVR_TIME;

//存储登录相机IP地址和登录ID
extern map<int, string> g_CameraIDAndIP;
//存储ip地址和ID
extern map<string, uint64> g_CameraIP;

//获取存储图片文件名称
extern list<string> g_listStrSavePic;

//将时间转换为时间戳
extern time_t strTime2unix(DVR_TIME struAbsTime);

//初始化队列
extern void OnInitQuery();

//删除队列
extern void OnDeletQuery();

//当网关掉线时，保存文件信息
extern int SaveFaceFile(const PLIST_BUFFER plistBuffer, int nCamerasType);

//获取json信息
extern Document GetJsonMsg(const string strPath);

//获取UUID
extern string OnGetUUID();

//十进制转十六进制
extern int DectoHex(int dec, unsigned char *hex, int length);

//定义图片信息队列
extern ListThread *g_pListThread;
//车牌循环队列类
extern ListThread *g_pCarListThread;

//tcp通信
extern tcp_conf_handle *g_pTcpConf;
//登录标识
extern bool g_isLogin;
//设置文件保存路径
extern string g_strSavePictureSrc;

//是否有车牌抓拍相机
extern bool g_isCapCameras;
//是否有海康人脸抓拍相机
extern bool g_isFaceHKCameras;
//是否有大华人脸抓拍相机
extern bool g_isFaceDHCameras;
//是否有巨龙人脸抓拍机
extern bool g_isFaceJVTCameras;
//是否有旷世人脸抓拍机
extern bool g_isFaceKSCameras;
//是否宇视人脸抓拍
extern bool g_isFaceNETDEVCameras;

//GB2312码转为UNICODE码
extern int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

#endif //FACEPICTURECLIENT_GLOBAL_H
