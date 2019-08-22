//
// Created by hxd on 4/7/19.
//

#ifndef COLLECTION_FACE_KSCAMERA_H
#define COLLECTION_FACE_KSCAMERA_H
#include "../global.h"
#include "XNetSDK.h"

using namespace std;

typedef struct tagKS_USELISTTIMER {
    int64 nTimer;
    PLIST_BUFFER plistBuffer;
} KS_USELISTTIMER;

extern map<int, tagKS_USELISTTIMER> g_pUselistBuffer_KS;

class KSCamera {
public:
    KSCamera(const char *cCameraIP,const int nPort,const char *cUserName,const char *cPassword);

    ~KSCamera();

    //获取初始化状态
    bool GetCameraInit() {
        return m_isInit;
    }

    //定义断线重连相机
    void reconnCamera();
private:
    //设置初始化标签
    void SetCameraInit(bool isInit) {
        m_isInit = isInit;
    }
    // 初始化相机
    bool OnInitCamera(const char *cDeviceAddress,const unsigned short wPort,const char *cUserName,const char *cPassword);
    //清空资源
    void Ondestroy();
private:
    XSDK_HANDLE m_hPlayer = 0;
    //相机IP
    string m_strCameraIP;
    //端口号
    const int m_nPort;
    //用户名
    const char *m_cUserName;
    //密码
    const char *m_cPassword;
    //设定是否初始化成功标签
    bool m_isInit = true;
    bool m_isFirstLog = true;
    XSDK_HANDLE m_hDevice = 0;
};


#endif //COLLECTION_FACE_KSCAMERA_H
