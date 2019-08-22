//
// Created by hxd on 18-4-28.
//

#ifndef TESTPICTURE_HCCAMERA_H
#define TESTPICTURE_HCCAMERA_H

//人脸评分
#define MIN_FACE_SCORE        70

#include "HCNetSDK.h"
#include "GeneralDef.h"
#include "../global.h"

using namespace std;

enum {
    Pic_Size_GIF,
    Pic_Size_QCIF,
    Pic_Size_CIF,
    Pic_Size_UXGA,
    Pic_Size_SVGA,
    Pic_Size_HD720P,
    Pic_Size_VGA,
    Pic_Size_XVGA,
    Pic_Size_HD900P,
    Pic_Size_HD1080P,
    Pic_Size_HD1920P,
    Pic_Size_HD304P,
    Pic_Size_HD1536P,
    Pic_Size_HD2048P,
    Pic_Size_HD1200P,
    Pic_Size_HD800P
};

//抓拍图片获取
extern bool FaceSnapResult(const char *pAlarmInfo);

extern bool AcsAlarmResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo);

//抓拍图片获取
extern bool LicenseSnapResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo);

class HCCamera {
public:
    HCCamera(const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword,
             const int nTag = FACE_CAP);

    ~HCCamera();

    //人脸检测报警
    void FacedetectAlarm(char *pAlarmInfo);

    //人脸侦测报警信息
    void FaceDetereconnCameraction(char *pAlarmInfo);

    //获取初始化状态
    bool GetCameraInit() {
        return m_isInit;
    }

private:
    // 初始化相机
    bool OnInitCamera(const char *cDeviceAddress, const WORD wPort, const char *cUserName, const char *cPassword,
                      const int nTag);

    //启用布防
    bool OnSetupAlarmChan();

    //获取人脸抓拍配置信息
    void GetDVRFaceSnapConfig();

    //设置人脸抓拍配置信息
    bool SetDVRFaceSnapConfig(NET_VCA_FACESNAPCFG sNetFaceSnapcfg);

    //获取人脸检查报警信息
    void GetDVRFaceDetect();

    //获取能力集
    bool GetAbility(const DWORD dwAbilityType, const char *cAbility, const char *cElem = nullptr,
                    const char *cElem1 = nullptr);

    //设置初始化标签
    void SetCameraInit(bool isInit) {
        m_isInit = isInit;
    }

    //设置门禁参数
    bool SetEntranceGuardCfg();

    //设置网络抓拍
    bool OnContinuousShoot();

private:
    LONG m_lUserID;
    LONG m_lHandle;
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
};


#endif //TESTPICTURE_HCCAMERA_H
