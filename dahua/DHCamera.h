//
// Created by carl on 18-9-18.
//

#ifndef FACEPICTURECLIENT_DHCAMERA_H
#define FACEPICTURECLIENT_DHCAMERA_H

#include "dhnetsdk.h"
#include "../global.h"

class CCameras;

typedef struct tagUSELISTTIMER {
    int64 nTimer;
    PLIST_BUFFER plistBuffer;
} USELISTTIMER;

extern map<int, USELISTTIMER> g_pUselistBuffer;

class DHCamera {
public:
    DHCamera(void *pUser, const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword,
             const int nTag = FACE_CAP);

    ~DHCamera();

    //获取初始化状态
    bool GetCameraInit() {
        return m_isInit;
    }

    //发送相机状态
    void send_dhcamera_state(string strIP, bool isState);

    //设置车辆颜色
    int setVehicleColor(const char *strColor);

    //设置车牌颜色
    int setPlateColor(const char *strColor);

    //设置车牌类型
    int setPlateType(const char *strType);

private:
    // 初始化相机
    bool OnInitCamera(const char *cDeviceAddress, const WORD wPort, const char *cUserName, const char *cPassword,
                      const int nTag = FACE_CAP);

    //设置初始化标签
    void SetCameraInit(bool isInit) {
        m_isInit = isInit;
    }

private:
    LLONG m_lUserID;
    LLONG m_lHandle;
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
    CCameras *m_pCameras = nullptr;
};


#endif //FACEPICTURECLIENT_DHCAMERA_H
