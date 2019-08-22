//
// Created by carl on 18-12-14.
//

#include <regex>
#include "JVTCamera.h"
#include "VideoNetAPI.h"
#include "../global.h"

using namespace SDK_JVTFACE;

//存储登录相机IP地址和登录ID
map<long, string> g_JVTHandIDAndIP;
//定义全局队列，用来存储文件信息
map<int, JVT_USELISTTIMER> g_pUselistBuffer_JVT;

void SubDisConnectCallBack(long lLoginID, SubConnType type, long nChannel, long dwUser) {
    logError("bearhunting camera subDisConnect,type = " + to_string(type));
    //断线重连
    JVTCamera *pJVTCamera = (JVTCamera *) dwUser;
    pJVTCamera->reconnCamera();
}

int
PictureDataCallback(long lRealFaceHandle, char *pBuf, long nDataLen, SDK_FA_PICTURE_HEAD *pHead, SDK_FACE_ATTR *pAttr,
                    long dwUser) {

    SDK_FA_PICTURE_HEAD *picHead = (SDK_FA_PICTURE_HEAD *) pHead;
    SDK_FACE_ATTR *picAttr = (SDK_FACE_ATTR *) pAttr;
    //保存抓拍场景图片
    if (nDataLen > 0 && NULL != pBuf) {
        //获取同一组抓拍文件的唯一标识
        int nGroupId = picAttr->nFaceID;
        //  接收图片写入日志
        char buf[100] = {0};
        string strIP = g_JVTHandIDAndIP[lRealFaceHandle];
        sprintf(buf, "%s:picture receive!", strIP.c_str());
        logInfo(buf);

        auto iter = g_pUselistBuffer_JVT.find(nGroupId);
        if (iter != g_pUselistBuffer_JVT.end()) {
            //PLIST_BUFFER plistBuffer = iter->second;
            JVT_USELISTTIMER uselisttimer = iter->second;
            //获取已存在信息
            if (uselisttimer.plistBuffer) {
                int nTempPicLen = uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen;
                //获取场景图标识（0：小图；1场景图）
                if (picAttr->byIsScenePic == 0) {
                    //图片长度
                    uselisttimer.plistBuffer->camerasPic.nFacePicLen = nDataLen;
                    //检查内存是否符合大小
                     g_pListThread->CheckBuffer(nDataLen + 1, FACE_PIC_TAG, uselisttimer.plistBuffer);
                    //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pBuf, nDataLen);
                } else if (picAttr->byIsScenePic == 1) {
                    //图片长度
                    uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = nDataLen;
                    //检查内存是否符合大小
                    g_pListThread->CheckBuffer(nDataLen + 1, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                    //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pBuf, nDataLen);
                }

                //插入NETDEV_GetLastError缓存队列时间
                uselisttimer.plistBuffer->camerasPic.tProgramTime = time(0);
                //放入满队列
                g_pListThread->PutBuffer(uselisttimer.plistBuffer, full);

                //清空指定map
                g_pUselistBuffer_JVT.erase(nGroupId);
                //图片放入缓冲区，写入日志//
                sprintf(buf, "%s:picture inster double list!", strIP.c_str());
                logInfo(buf);
            }

        } else {
            //获取系统时间
            time_t t = time(NULL);
            JVT_USELISTTIMER uselisttimer;
            //若10秒还未收到数据,删除队列
            uselisttimer.nTimer = t + 10;

            //PLIST_BUFFER plistBuffer;
            g_pListThread->GetBuffer(&uselisttimer.plistBuffer, empty);
            if (uselisttimer.plistBuffer == nullptr) {
                //若空队列为空,获取满队列头地址
                logDebug("The dh data is full and the original data is discarded!");
                //g_pListThread->GetHeadBuffer(&plistBuffer, full);
                g_pListThread->GetBuffer(&uselisttimer.plistBuffer, full);
                //获取内存图片并保存
                //SaveFaceFile(uselisttimer.plistBuffer, DAHUA);
            }

            if (uselisttimer.plistBuffer) {
                //获取时间
                //时间 2018-12-15 12:47:42
                string strTime = picAttr->stFaceTime;
                char cYear[5] = {0};
                char cMonth[3] = {0};
                char cDay[3] = {0};
                char cHour[3] = {0};
                char cMinute[3] = {0};
                char cSecond[3] = {0};
                memcpy(cYear, &picAttr->stFaceTime[0], 4);
                memcpy(cMonth, &picAttr->stFaceTime[5], 2);
                memcpy(cDay, &picAttr->stFaceTime[8], 2);
                memcpy(cHour, &picAttr->stFaceTime[11], 2);
                memcpy(cMinute, &picAttr->stFaceTime[14], 2);
                memcpy(cSecond, &picAttr->stFaceTime[17], 2);
                DVR_TIME dvrTime;
                dvrTime.nYear = atoi(cYear);
                dvrTime.nMonth = atoi(cMonth);
                dvrTime.nDay = atoi(cDay);
                dvrTime.nHour = atoi(cHour);
                dvrTime.nMinute = atoi(cMinute);
                dvrTime.nSecond = atoi(cSecond);

                uselisttimer.plistBuffer->camerasPic.nCamerasType = JVT;
                //相机时间戳
                uselisttimer.plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);

                //获取场景图标识（0：小图；1场景图）
                if (picAttr->byIsScenePic == 0) {
                    //图片长度mlpUserData
                    uselisttimer.plistBuffer->camerasPic.nFacePicLen = nDataLen;
                    //检查内存是否符合大小
                    g_pListThread->CheckBuffer(nDataLen + 1, FACE_PIC_TAG, uselisttimer.plistBuffer);
                   //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pBuf, nDataLen);
                } else if (picAttr->byIsScenePic == 1) {
                    //图片长度
                    uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = nDataLen;
                    //检查内存是否符合大小
                    g_pListThread->CheckBuffer(nDataLen + 1, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                    //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pBuf, nDataLen);
                }

                //清空IP地址
                memset(uselisttimer.plistBuffer->camerasPic.cCameraIP, 0, 16);

                //IP地址
                memcpy(uselisttimer.plistBuffer->camerasPic.cCameraIP, strIP.c_str(), strIP.length());

                //人脸评分
                uselisttimer.plistBuffer->camerasPic.nFaceScore = 70;
                //获取告警NETDEV_GetLastError区域坐标
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nX = picAttr->stFacePicSize.X;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nY = picAttr->stFacePicSize.Y;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nWidth = picAttr->stFacePicSize.nWidth;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nHeight = picAttr->stFacePicSize.nHeight;
                logInfo("picture insert first!");

            }

            g_pUselistBuffer_JVT.insert(make_pair(nGroupId, uselisttimer));
        }

    }

    return 0;
}

JVTCamera::JVTCamera(const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword)
        : m_lUserID(-1),
          m_lHandle(-1),
          m_strCameraIP(cCameraIP),
          m_nPort(nPort),
          m_cUserName(cUserName),
          m_cPassword(cPassword) {
    SetCameraInit(OnInitCamera(cCameraIP, nPort, cUserName, cPassword));
}

JVTCamera::~JVTCamera() {
    Ondestroy();
}

void JVTCamera::Ondestroy() {
    if (m_lHandle > 0) {
        //停止接收图片信息
        VideoNet_StopReceiveFaceImageFile(m_lHandle);
        //删除回调函数
        int rett = VideoNet_DelFaceImageDataCallBack(m_lHandle, PictureDataCallback, 0);
    }

    if (m_lUserID > 0) {
        //退出登录
        VideoNet_Logout(m_lUserID);
    }

    //清理资源
    VideoNet_Cleanup();
}

void JVTCamera::reconnCamera() {
    m_isFirstLog = false;
    bool isRun = true;
    //清空资源
    Ondestroy();
    while (isRun) {
        //断线重连,10秒钟一次
        if (OnInitCamera(m_strCameraIP.c_str(), m_nPort, m_cUserName, m_cPassword)) {
            isRun = false;
        }
        sleep(10);
    }
}

bool
JVTCamera::OnInitCamera(const char *cDeviceAddress, const unsigned short wPort, const char *cUserName,
                        const char *cPassword) {
    // 初始化
    VideoNet_Init(NULL, 1);

//    if(VideoNet_SetKeepLifeTime(g_LoginID,20,40)!=1)
//    {
//        printf("VideoNet_SetKeepLifeTime ERROR!\n");
//    }

    //设置子连接断开回调
    if (VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, (long) this) != 1) {
        logError("VideoNet_SetSubDisconnectCallBack ERROR!");
        //清理资源
        VideoNet_Cleanup();
        return false;
    }
    //---------------------------------------
    // 注册设备
    //登录参数，包括设备地址、登录用户、密码等
    VIDEONET_DEVICEINFO OutDev;
    memset(&OutDev, 0, sizeof(OutDev));
    int nError = 0;
    char cAddress[20] = {0};
    char cName[50] = {0};
    char cPasswordNew[50] = {0};

    memcpy(cAddress, cDeviceAddress, 20);
    memcpy(cName, cUserName, 50);
    memcpy(cPasswordNew, cPassword, 50);
    m_lUserID = VideoNet_Login(cAddress, wPort, cName, cPasswordNew,
                               (LPVIDEONET_DEVICEINFO) (&OutDev), &nError);
    logInfo("jvt id  m_lUserID="+to_string(m_lUserID));

    if (nError != 0) {
        logError("JVT camera login error:" + to_string(nError));
        //清理资源
        VideoNet_Cleanup();
        return false;
    }

    //开始抓拍图片传送请求
    m_lHandle = VideoNet_StartReceiveFaceImageFileEx(m_lUserID, 0, 1);
    if (m_lHandle <= 0) {
        logError("start ReceiveFaceImageFile wrong!");
        //退出登录
        VideoNet_Logout(m_lUserID);
        //清理资源
        VideoNet_Cleanup();
        return false;
    }

    //抓拍图片回调
    if (!VideoNet_SetFaceImageDataCallBack(m_lHandle, PictureDataCallback, 12)) {
        logError("VideoNet_SetFaceImageDataCallBack wrong!");
        //停止接收图片信息
        VideoNet_StopReceiveFaceImageFile(m_lHandle);
        //退出登录
        VideoNet_Logout(m_lUserID);
        //清理资源
        VideoNet_Cleanup();
        return false;
    }

    if (m_isFirstLog) {
        //将登录信息保存
        g_JVTHandIDAndIP.insert(make_pair(m_lHandle, m_strCameraIP));
    }


    logInfo("bearhunting Camera init success！");
    return true;
}