//
// Created by carl on 18-12-14.
//

#ifndef FACEPICTURECLIENT_JVTCAMERA_H
#define FACEPICTURECLIENT_JVTCAMERA_H

#include "../global.h"

using namespace std;

typedef struct tagJVT_USELISTTIMER {
    int64 nTimer;
    PLIST_BUFFER plistBuffer;
} JVT_USELISTTIMER;

extern map<int, JVT_USELISTTIMER> g_pUselistBuffer_JVT;

class JVTCamera {
public:
    JVTCamera(const char *cCameraIP,const int nPort,const char *cUserName,const char *cPassword);

    ~JVTCamera();

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
    bool OnInitCamera(const char *cDeviceAddress,const unsigned short wPort,const char *cUserName,const char *cPassword);//xj  delete
    //清空资源
    void Ondestroy();
private:
    long m_lUserID;
    long m_lHandle;
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
};


#endif //FACEPICTURECLIENT_JVTCAMERA_H
