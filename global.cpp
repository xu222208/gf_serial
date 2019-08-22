//
// Created by hxd on 18-5-7.
//
#include "global.h"
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <iconv.h>

//用户登录标签
bool g_isLogin = false;
//存储登录相机IP地址和登录ID
map<int, string> g_CameraIDAndIP;
//存储ip地址和ID
map<string, uint64> g_CameraIP;
//获取存储图片文件名称
list<string> g_listStrSavePic;
//循环队列类
ListThread *g_pListThread = nullptr;
//车牌循环队列类
ListThread *g_pCarListThread = nullptr;
//tcp通信
tcp_conf_handle *g_pTcpConf = nullptr;

//设置文件保存路径
string g_strSavePictureSrc = "";

//设置车牌抓拍相机
bool g_isCapCameras = false;
//是否有海康人脸抓拍相机
bool g_isFaceHKCameras = false;
//是否有大华人脸抓拍相机
bool g_isFaceDHCameras = false;
//是否有巨龙人脸抓拍机
bool g_isFaceJVTCameras = false;
//是否有旷世人脸抓拍机
bool g_isFaceKSCameras = false;
//是否宇视人脸抓拍
bool g_isFaceNETDEVCameras=false;

//将时间转换为时间戳
time_t strTime2unix(DVR_TIME struAbsTime) {
    struct tm tm;
    memset(&tm, 0, sizeof(tm));

    tm.tm_year = struAbsTime.nYear;
    tm.tm_mon = struAbsTime.nMonth;
    tm.tm_mday = struAbsTime.nDay;
    tm.tm_hour = struAbsTime.nHour;
    tm.tm_min = struAbsTime.nMinute;
    tm.tm_sec = struAbsTime.nSecond;


    tm.tm_year -= 1900;
    tm.tm_mon--;

    return mktime(&tm);
}

//初始化队列
void OnInitQuery() {
    g_pListThread = new ListThread;
    g_pListThread->ResetBuffer(1024 * 2048, 1024 * 50, 20);

    g_pCarListThread = new ListThread;
    g_pCarListThread->ResetBuffer(1024 * 100, 1024 * 50, 20);
}

//删除队列
void OnDeletQuery() {
    if (g_pListThread) {
        delete g_pListThread;
        g_pListThread = nullptr;
    }

    if (g_pCarListThread) {
        delete g_pCarListThread;
        g_pCarListThread = nullptr;
    }
}

//获取json数据
Document GetJsonMsg(const string strPath) {
    FILE *fp = fopen(strPath.c_str(), "r");
    if (!fp) {
        //若文件不存在
        return NULL;
    }
    char cReadFile[7000] = {0};
    FileReadStream readStream(fp, cReadFile, sizeof(cReadFile));
    Document document;
    try {
        document.ParseStream<0>(readStream);

        if (document.HasParseError()) {
            printf("GetParseError %d\n", document.GetParseError());
        }
    } catch (const std::exception &e) {
        logDebug("Json format error!");
    }

    fclose(fp);
    return document;
}

string OnGetUUID() {
    //设置uuid
    boost::uuids::uuid uu;
    boost::uuids::random_generator rgen;
    //获取UUID
    uu = rgen();
    //存储uuid
    return boost::lexical_cast<string>(uu);
}

int SaveHKFaceFile(const PLIST_BUFFER plistBuffer, char *clistFileName) {
    char cFileName[1024] = {0};
    char ctempListFileName[1024] = {0};
    //文件名表示为 type-ip-camerastime-programtime-picturelen-facescore-rect
    // (1-192.168.1.2-12345678-12345678-15874-85-0-0-51-156)
    sprintf(ctempListFileName, "%d-%s-%ld-%ld-%ld-%d-%0.3lf-%0.3lf-%0.3lf-%0.3lf.jpg",
            HIKVISION, plistBuffer->camerasPic.cCameraIP,
            plistBuffer->camerasPic.tCameraTime, plistBuffer->camerasPic.tProgramTime,
            plistBuffer->camerasPic.nBackgroundPicLen, plistBuffer->camerasPic.nFaceScore,
            plistBuffer->camerasPic.sAlarmRect.fX, plistBuffer->camerasPic.sAlarmRect.fY,
            plistBuffer->camerasPic.sAlarmRect.fWidth, plistBuffer->camerasPic.sAlarmRect.fHeight);

    memcpy(clistFileName, ctempListFileName, 1024);
    sprintf(cFileName, "%s/%s", g_strSavePictureSrc.c_str(), clistFileName);
    //图片保存文件
    FILE *pfile;
    //打开写文件
    pfile = fopen(cFileName, "wb+");
    //写文件
    fwrite(plistBuffer->camerasPic.pBackBuffer, sizeof(unsigned char),
           plistBuffer->camerasPic.nBackgroundPicLen,
           pfile);
    //关闭文件
    fclose(pfile);
}

int SaveDHFaceFile(const PLIST_BUFFER plistBuffer, char *clistFileName) {
    char cFileNameBK[1024] = {0};
    char cFileName[1024] = {0};
    char ctempListFileName[1024] = {0};
    //文件名表示为 type-ip-camerastime-programtime-backlen-facelen-facescore
    //(2-192.168.63.5-12345678-12345678-120460-35490-70) 人脸图
    //(2-192.168.63.5-12345678-12345678-120460-35490-70-bk) 背景图
    sprintf(ctempListFileName, "%d-%s-%ld-%ld-%ld-%ld-%d", DAHUA, plistBuffer->camerasPic.cCameraIP,
            plistBuffer->camerasPic.tCameraTime, plistBuffer->camerasPic.tProgramTime,
            plistBuffer->camerasPic.nBackgroundPicLen, plistBuffer->camerasPic.nFacePicLen,
            plistBuffer->camerasPic.nFaceScore);

    memcpy(clistFileName, ctempListFileName, 1024);
    sprintf(cFileNameBK, "%s/%s-bk.jpg", g_strSavePictureSrc.c_str(), clistFileName);
    sprintf(cFileName, "%s/%s.jpg", g_strSavePictureSrc.c_str(), clistFileName);
    //背景图片保存
    FILE *pfile;
    //打开写文件
    pfile = fopen(cFileNameBK, "wb+");
    //写文件
    fwrite(plistBuffer->camerasPic.pBackBuffer, sizeof(unsigned char),
           plistBuffer->camerasPic.nBackgroundPicLen,
           pfile);
    //关闭文件
    fclose(pfile);

    //人脸图片保存
    //打开写文件
    pfile = fopen(cFileName, "wb+");
    //写文件
    fwrite(plistBuffer->camerasPic.pFaceBuffer, sizeof(unsigned char),
           plistBuffer->camerasPic.nFacePicLen,
           pfile);
    //关闭文件
    fclose(pfile);
}

int SaveFaceFile(const PLIST_BUFFER plistBuffer, int nCamerasType) {
    //最多保存8000张图片
    if (g_listStrSavePic.size() == 8000) {
        return 0;
    }

    char clistFileName[1024] = {0};

    if (nCamerasType == HIKVISION) {
        SaveHKFaceFile(plistBuffer, clistFileName);
    } else if (nCamerasType == DAHUA) {
        SaveDHFaceFile(plistBuffer, clistFileName);
    }


    g_listStrSavePic.push_back(clistFileName);
    return 1;
}

//代码转换:从一种编码转为另一种编码
int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    iconv_t cd;
    int rc;
    char **pin = &inbuf;
    char **pout = &outbuf;
    cd = iconv_open(to_charset, from_charset);
    if (cd == 0) return -1;
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == -1) return -1;
    iconv_close(cd);
    return 0;
}

//GB2312码转为UNICODE码
int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    char cUtf8[10] = "utf-8";
    char cGb2312[10] = "gb2312";
    return code_convert(cGb2312, cUtf8, inbuf, inlen, outbuf, outlen);
}


/////////////////////////////////////////////////////////
//
//功能：十进制转十六进制
//
//输入：int dec                     待转换的十进制数据
//      int length                  转换后的十六进制数据长度
//
//输出：unsigned char *hex          转换后的十六进制数据
//
//返回：0    success

//////////////////////////////////////////////////////////
int DectoHex(int dec, unsigned char *hex, int length)
{
    int i;
    for (i = length - 1; i >= 0; i--)
    {
        hex[i] = (dec % 256) & 0xFF;
        dec /= 256;
    }
    return 0;
}