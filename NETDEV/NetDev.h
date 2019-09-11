#ifndef COLLECTION_FACE_NETDEV_CAMERA_H
#define COLLECTION_FACE_NETDEV_CAMERA_H
#include "../global.h"

using namespace std;

typedef struct tagNetDev_USELISTTIMER {
    int64 nTimer;
    PLIST_BUFFER plistBuffer;
} NETDEV_USELISTTIMER;

extern map<int, tagNetDev_USELISTTIMER> g_pUselistBuffer_NETDEV;

class NetDevCamera {
public:
    NetDevCamera(const char *cCameraIP,const int nPort,const char *cUserName,const char *cPassword);

    ~NetDevCamera();


    bool OnInitCamera(const char *cDeviceAddress, const unsigned short wPort, const char *cUserName,
                                    const char *cPassword);
    void Ondestroy();
    void reconnCamera();
    //获取初始化状态
    bool GetCameraInit() {
        return m_isInit;
    }
    bool lNetDev_Logout(LPVOID netdev_UserID);

private:
    //设置初始化标签
    void SetCameraInit(bool isInit) {
        m_isInit = isInit;
    }
private:
    LPVOID m_lUserID;
    LPVOID m_lHandle;
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




#endif
