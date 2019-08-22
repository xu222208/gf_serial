//
// Created by hxd on 4/7/19.
//

#include "KSCamera.h"

//存储登录相机IP地址和登录ID
map<XSDK_HANDLE, string> g_KSHandIDAndIP;
//定义全局队列，用来存储文件信息
map<int, KS_USELISTTIMER> g_pUselistBuffer_KS;

int CALLBACK
Main_MessageCallBack(XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char *szString,
                     void *pObject, int nSeq, void *pUserData) {
    switch (nMsgId) {
        case ESXSDK_DEV_LOGIN: {
            logInfo("ESXSDK_DEV_LOGIN_Ret:" + to_string(nParam1));
            if (nParam1 == EXSDK_ER_UserOrPassword) {
                XSDK_DevLogout(hDevice);
            }

            if (nParam1 < 0) {
                logError("ESXSDK_DEV_LOGIN__Error");
            }
        }
            break;
        case ESXSDK_ON_DEV_STATE: {
            char buf[64];
            sprintf(buf, "%s:%s", "ESXSDK_ON_DEV_STATE",
                    (nParam1 == 6 ? "ESTATE_DEV_Logined" : "ESTATE_DEV_NetDisConnect"));
            //设备状态
            logError(buf);
        }
            break;
        case ESXSDK_DEV_GENERAL_COMMAND:    // 通用交互返回
        case ESXSDK_DEV_GET_SYS_CONFIG:        // 设备系统配置获取
        case ESXSDK_DEV_SET_SYS_CONFIG:        // 设备系统配置设置
        case ESXSDK_DEV_GET_CHN_CONFIG:        // 设备通道配置获取
        case ESXSDK_DEV_SET_CHN_CONFIG:        // 设备通道配置设置
        {
            //OnDevConfig(nMsgId, nParam1, szString, (const char *) pObject, nParam2, nSeq);
        }
            break;
        case ESXSDK_ON_SEARCH_DEVICES: {
            //OnDevSearchResult(nParam1, (SXSDK_CONFIG_NET_COMMON *) pObject, nParam2);
        }
            break;
        case EXCMD_ALARM_REQ: {
            //OnDevAlarmCallback(hDevice, szString);
        }
            break;
        default:
            char buf[100];
            sprintf(buf, "Dev:%d MSG:%d Ret:%d Param2:%d Param3:%d szParam:%s Seq:%d", hDevice, nMsgId, nParam1,
                    nParam2, nParam3, szString == NULL ? "" : szString, nSeq);
            break;
    }
    return 0;
}

int CALLBACK
FaceImageCallBack(XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo,
                  int nDataInfoSize, void *pUserData) {

    if (EXSDK_DATA_FORMATE_FACE_IMAGE == nDataType && pDataInfo) {
        //保存抓拍场景图片
        if (nDataLen > 0 && NULL != pData) {
            SXSDK_IA_FR_REC_S *pInfo = (SXSDK_IA_FR_REC_S *) pDataInfo;
            //获取同一组抓拍文件的唯一标识
            int nGroupId = pInfo->comm.framID;
            //  接收图片写入日志
            char buf[100] = {0};
            string strIP = g_KSHandIDAndIP[hMedia];
            sprintf(buf, "%s:picture receive!", strIP.c_str());
            logInfo(buf);
            auto iter = g_pUselistBuffer_KS.find(nGroupId);
            if (iter != g_pUselistBuffer_KS.end()) {
                //PLIST_BUFFER plistBuffer = iter->second;
                KS_USELISTTIMER uselisttimer = iter->second;
                //获取已存在信息
                if (uselisttimer.plistBuffer) {
                    int nTempPicLen = uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen;
                    //获取场景图标识（0:大图  1:小图）
                    if (pInfo->comm.picSubType == 1) {
                        //图片长度
                        uselisttimer.plistBuffer->camerasPic.nFacePicLen = nDataLen;
                        //检查内存是否符合大小
                        g_pListThread->CheckBuffer(nDataLen + 1, FACE_PIC_TAG, uselisttimer.plistBuffer);
                        //拷贝图片内存
                        memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pData, nDataLen);

                        //获取告警区域坐标
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nX = pInfo->info.stRect.leftX;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nY = pInfo->info.stRect.topY;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nWidth = pInfo->info.stRect.width;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nHeight = pInfo->info.stRect.height;
                    } else if (pInfo->comm.picSubType == 0) {
                        //图片长度
                        uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = nDataLen;
                        //检查内存是否符合大小
                        g_pListThread->CheckBuffer(nDataLen + 1, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                        //拷贝图片内存
                        memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pData, nDataLen);
                    }


                    //插入缓存队列时间
                    uselisttimer.plistBuffer->camerasPic.tProgramTime = time(0);
                    //放入满队列
                    g_pListThread->PutBuffer(uselisttimer.plistBuffer, full);

                    //清空指定map
                    g_pUselistBuffer_KS.erase(nGroupId);
                    //图片放入缓冲区，写入日志
                    sprintf(buf, "%s:picture inster double list!", strIP.c_str());
                    logInfo(buf);
                }

            } else {
                //获取系统时间m_lUserID
                time_t t = time(NULL);
                KS_USELISTTIMER uselisttimer;
                //若10秒还未收到数据,删除队列
                uselisttimer.nTimer = t + 10;

                //PLIST_BUFFER plistBuffer;
                g_pListThread->GetBuffer(&uselisttimer.plistBuffer, empty);
                if (uselisttimer.plistBuffer == nullptr) {
                    //若空队列为空,获取满队列头地址
                    logInfo("The kuangshi data is full and the original data is discarded!");
                    //g_pListThread->GetHeadBuffer(&plistBuffer, full);
                    g_pListThread->GetBuffer(&uselisttimer.plistBuffer, full);
                    //获取内存图片并保存
                    //SaveFaceFile(uselisttimer.plistBuffer, DAHUA);
                }

                if (uselisttimer.plistBuffer) {
                    uselisttimer.plistBuffer->camerasPic.nCamerasType = DAHUA;
                    //相机时间戳
                    uselisttimer.plistBuffer->camerasPic.tCameraTime = pInfo->comm.tagsec;

                    //获取场景图标识（0：大图；1小图）
                    if (pInfo->comm.picSubType == 1) {
                        //图片长度
                        uselisttimer.plistBuffer->camerasPic.nFacePicLen = nDataLen;
                        //检查内存是否符合大小
                        g_pListThread->CheckBuffer(nDataLen + 1, FACE_PIC_TAG, uselisttimer.plistBuffer);
                        //拷贝图片内存
                        memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pData, nDataLen);

                        //获取告警区域坐标
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nX = pInfo->info.stRect.leftX;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nY = pInfo->info.stRect.topY;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nWidth = pInfo->info.stRect.width;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nHeight = pInfo->info.stRect.height;
                    } else if (pInfo->comm.picSubType == 0) {
                        //图片长度
                        uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = nDataLen;
                        //检查内存是否符合大小
                        g_pListThread->CheckBuffer(nDataLen + 1, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                        //拷贝图片内存
                        memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pData, nDataLen);
                    }

                    //清空IP地址
                    memset(uselisttimer.plistBuffer->camerasPic.cCameraIP, 0, 16);

                    //IP地址
                    memcpy(uselisttimer.plistBuffer->camerasPic.cCameraIP, strIP.c_str(), strIP.length());

                    //人脸评分
                    uselisttimer.plistBuffer->camerasPic.nFaceScore = 70;

                    logInfo("picture insert first!");
                }

                g_pUselistBuffer_KS.insert(make_pair(nGroupId, uselisttimer));
            }
        }
    } else if (EXSDK_DATA_MEDIA_ON_PLAY_STATE == nDataType) {
        logInfo("EXSDK_DATA_MEDIA_ON_PLAY_STATE:" + to_string(hMedia) + " Len:" + to_string(nDataLen));
    } else if (ESXSDK_MEDIA_START_FACE_IMAGE == nDataType) {
        logInfo("ESXSDK_MEDIA_START_FACE_IMAGE:" + to_string(hMedia) + " Len:" + to_string(nDataLen));
    } else {
        logInfo("Media hMedia:" + to_string(hMedia) + " Len:" + to_string(nDataLen) + " Type:" + to_string(nDataType));
    }
    return 0;
}

KSCamera::KSCamera(const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword) :
        m_strCameraIP(cCameraIP),
        m_nPort(nPort),
        m_cUserName(cUserName),
        m_cPassword(cPassword) {
    SetCameraInit(OnInitCamera(cCameraIP, nPort, cUserName, cPassword));
}

KSCamera::~KSCamera() {
    Ondestroy();
}

void KSCamera::Ondestroy() {
    //关闭人脸抓拍功能
    if (m_hPlayer) {
        XSDK_MediaStop(m_hPlayer);
        m_hPlayer = 0;
    }
    //退出登录
    XSDK_DevLogout(m_hDevice);
    //注销回调
    XSDK_UnInit();
}

bool
KSCamera::OnInitCamera(const char *cDeviceAddress, const unsigned short wPort, const char *cUserName,
                       const char *cPassword) {

    //初始化相机
    SXSDKInitParam initParam = {0};
    initParam.nLogLevel = 3;
    initParam.pMsgCallBack = Main_MessageCallBack;
    initParam.pUserData = (void *) 0x123456;
    if (XSDK_Init(&initParam) != EXSDK_ER_OK) {
        logError("XSDK_Init ERROR!");
        return false;
    }

    //登录相机
    SXSDKLoginParam devParam = {0};
    strcpy(devParam.sDevId, cDeviceAddress);
    devParam.nDevPort = wPort;
    strcpy(devParam.sUserName, cUserName);
    strcpy(devParam.sPassword, cPassword);
    m_hDevice = XSDK_DevLogin(&devParam, 4000, 0);

    //启动人脸抓拍功能
    if (m_hPlayer) {
        XSDK_MediaStop(m_hPlayer);
        m_hPlayer = 0;
    }

    SXMediaFaceImageReq param = {0};
    param.nChannel = 0;
    param.nImgTypeMsk = 3;
    strcpy(param.szIntelType, "Face");
    param.pMediaCallback = FaceImageCallBack;
    param.pUserData = (void *) 0x23456;
    m_hPlayer = XSDK_MediaGetFaceImage(m_hDevice, &param);

    if (m_isFirstLog) {
        //将登录信息保存
        g_KSHandIDAndIP.insert(make_pair(m_hPlayer, m_strCameraIP));
    }
    logInfo("kuangshi Camera init success！");
    return true;
}