//
// Created by hxd on 18-4-28.
//

#ifndef TESTPICTURE_HCCAMERA_H
#define TESTPICTURE_HCCAMERA_H

//��������
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

//ץ��ͼƬ��ȡ
extern bool FaceSnapResult(const char *pAlarmInfo);

extern bool AcsAlarmResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo);

//ץ��ͼƬ��ȡ
extern bool LicenseSnapResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo);

class HCCamera {
public:
    HCCamera(const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword,
             const int nTag = FACE_CAP);

    ~HCCamera();

    //������ⱨ��
    void FacedetectAlarm(char *pAlarmInfo);

    //������ⱨ����Ϣ
    void FaceDetereconnCameraction(char *pAlarmInfo);

    //��ȡ��ʼ��״̬
    bool GetCameraInit() {
        return m_isInit;
    }



private:
   //  ��ʼ�����
    bool OnInitCamera(const char *cDeviceAddress, const WORD wPort, const char *cUserName, const char *cPassword,
                      const int nTag);

    //���ò���
    bool OnSetupAlarmChan();

    //��ȡ����ץ��������Ϣ
    void GetDVRFaceSnapConfig();

    //��������ץ��������Ϣ
    bool SetDVRFaceSnapConfig(NET_VCA_FACESNAPCFG sNetFaceSnapcfg);

    //��ȡ������鱨����Ϣ
    void GetDVRFaceDetect();

    //��ȡ������
    bool GetAbility(const DWORD dwAbilityType, const char *cAbility, const char *cElem = nullptr,
                    const char *cElem1 = nullptr);

    //���ó�ʼ����ǩ
    void SetCameraInit(bool isInit) {
        m_isInit = isInit;
    }

    //�����Ž�����
    bool SetEntranceGuardCfg();

    //��������ץ��
    bool OnContinuousShoot();

private:
    LONG m_lUserID;
    LONG m_lHandle;
    //���IP
    string m_strCameraIP;
    //�˿ں�
    const int m_nPort;
    //�û���
    const char *m_cUserName;
    //����
    const char *m_cPassword;
    //�趨�Ƿ��ʼ���ɹ���ǩ
    bool m_isInit = true;
};


#endif //TESTPICTURE_HCCAMERA_H
