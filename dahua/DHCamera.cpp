//
// Created by carl on 18-9-18.
//

#include "DHCamera.h"
#include "../CCameras.h"
#include <iconv.h>
//存储登录相机IP地址和登录ID
map<LLONG, string> g_HandIDAndIP;
//定义全局队列，用来存储文件信息
//map<int, PLIST_BUFFER> g_pUselistBuffer;
map<int, USELISTTIMER> g_pUselistBuffer;


//#define LOCKCB_FUNC boost::mutex::scoped_lock lock(io_mutex)
//
//boost::mutex io_mutex;

// 通过 CLIENT_Init 设置该回调函数,当设备出现断线时,SDK 通过该函数通知用户
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser) {
    DHCamera *pDHCamera = (DHCamera *) dwUser;
    string strIP = pchDVRIP;
    string strError = to_string(lLoginID) + "ip:" + strIP + "DisConnect!!!";
    logError(strError);
    //设置相机状态
    pDHCamera->send_dhcamera_state(strIP, false);
    return;
}

void CALLBACK AutoConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser) {
    DHCamera *pDHCamera = (DHCamera *) dwUser;
    string strIP = pchDVRIP;
    string strError = to_string(lLoginID) + "ip:" + strIP + "Reconnect success!!!";
    logInfo(strError);
    //设置相机状态
    pDHCamera->send_dhcamera_state(strIP, true);
    return;
}

// nSequence 表示上传的相同图片情况,为 0 时表示是第一次出现,为 2 表示最后一次出现或仅出现一次,为 1表示此次之后还有
// int nState = *(int*) reserved 表示当前回调数据的状态, 为 0 表示当前数据为实时数据,为 1 表示当前回调数据是离线数据,
// 为2时表示离线数据传送结束
// 返回值已废除,无特殊意义
int CALLBACK AnalyzerDataCallBack(LLONG lAnalyzerHandle, DWORD dwAlarmType, void *pAlarmInfo,
                                  BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved) {
    switch (dwAlarmType) {
        // 翻越围栏事件(对应 DEV_EVENT_CROSSFENCEDETECTION_INFO)
        case EVENT_IVS_CROSSFENCEDETECTION: {
        }
            break;
            // 绊线/警戒线入侵(对应 DEV_EVENT_CROSSREGION_INFO)
        case EVENT_IVS_CROSSLINEDETECTION: {
            //主要功能
        }
            break;
        case EVENT_IVS_FACEDETECT: {
            DEV_EVENT_FACEDETECT_INFO *pEventFacedect = {0};
            pEventFacedect = (DEV_EVENT_FACEDETECT_INFO *) pAlarmInfo;

            //保存抓拍场景图片
            if (dwBufSize > 0 && NULL != pBuffer) {
                DH_EVENT_FILE_INFO stuFileInfo = pEventFacedect->stuFileInfo;
                //获取同一组抓拍文件的唯一标识
                int nGroupId = stuFileInfo.nGroupId;
                //  接收图片写入日志
                char buf[100] = {0};
                string strIP = g_HandIDAndIP[lAnalyzerHandle];
                sprintf(buf, "%s:picture receive!", strIP.c_str());
                logInfo(buf);

                auto iter = g_pUselistBuffer.find(nGroupId);
                if (iter != g_pUselistBuffer.end()) {
                    //PLIST_BUFFER plistBuffer = iter->second;
                    USELISTTIMER uselisttimer = iter->second;
                    //获取已存在信息
                    if (uselisttimer.plistBuffer) {
                        int nTempPicLen = uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen;
                        if (nTempPicLen < dwBufSize) {
                            //如果获取到的图片大小大于背景printf("m_lUserID=%d***********\n",m_lUserID);图片，图片调换
                            //将背景图片放入人脸子图中
                            //检查内存是否符合大小
                            uselisttimer.plistBuffer->camerasPic.nFacePicLen = nTempPicLen;
                            g_pListThread->CheckBuffer(nTempPicLen, FACE_PIC_TAG, uselisttimer.plistBuffer);
                            //拷贝图片内存
                            memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pBuffer,
                                   nTempPicLen);
                            //保存背景图片
                            uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = dwBufSize;
                            g_pListThread->CheckBuffer(dwBufSize, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                            //拷贝图片内存
                            memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pBuffer,
                                   dwBufSize);
                        } else {
                            //图片长度
                            uselisttimer.plistBuffer->camerasPic.nFacePicLen = dwBufSize;
                            //检查内存是否符合大小
                            g_pListThread->CheckBuffer(dwBufSize, FACE_PIC_TAG, uselisttimer.plistBuffer);

                            //拷贝图片内存
                            memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pBuffer,
                                   dwBufSize);
                        }

                        //插入缓存队列时间
                        uselisttimer.plistBuffer->camerasPic.tProgramTime = time(0);
                        //放入满队列
                        g_pListThread->PutBuffer(uselisttimer.plistBuffer, full);

                        //清空指定map
                        g_pUselistBuffer.erase(nGroupId);
                        //图片放入缓冲区，写入日志
                        sprintf(buf, "%s:picture inster double list!", strIP.c_str());
                        logInfo(buf);
                    }

                } else {
                    //获取系统时间
                    time_t t = time(NULL);
                    USELISTTIMER uselisttimer;
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
                        SaveFaceFile(uselisttimer.plistBuffer, DAHUA);
                    }

                    if (uselisttimer.plistBuffer) {
                        //获取时间
                        //时间
                        NET_TIME_EX UTC = pEventFacedect->UTC;
                        DVR_TIME dvrTime;
                        dvrTime.nYear = UTC.dwYear;
                        dvrTime.nMonth = UTC.dwMonth;
                        dvrTime.nDay = UTC.dwDay;
                        dvrTime.nHour = UTC.dwHour;
                        dvrTime.nMinute = UTC.dwMinute;
                        dvrTime.nSecond = UTC.dwSecond;
                        uselisttimer.plistBuffer->camerasPic.nCamerasType = DAHUA;
                        //相机时间戳
                        uselisttimer.plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);

                        //图片长度
                        uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = dwBufSize;
                        //检查内存是否符合大小
                        g_pListThread->CheckBuffer(dwBufSize, BAKE_PIC_TAG, uselisttimer.plistBuffer);
                        //拷贝图片内存
                        memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pBuffer,
                               dwBufSize);

                        //清空IP地址
                        memset(uselisttimer.plistBuffer->camerasPic.cCameraIP, 0, 16);

                        //IP地址
                        memcpy(uselisttimer.plistBuffer->camerasPic.cCameraIP, strIP.c_str(), strIP.length());

                        //人脸评分
                        uselisttimer.plistBuffer->camerasPic.nFaceScore = 70;
                        //获取告警区域坐标
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nX = 0;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nY = 0;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nWidth = 0;
                        uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nHeight = 0;
                        logInfo("picture insert first!");

                    }

                    g_pUselistBuffer.insert(make_pair(nGroupId, uselisttimer));
                }
            }
        }
            break;
        case EVENT_IVS_TRAFFICJUNCTION: {
            //车辆抓拍事件
            DEV_EVENT_TRAFFICJUNCTION_INFO *pEventTraffic = {0};
            pEventTraffic = (DEV_EVENT_TRAFFICJUNCTION_INFO *) pAlarmInfo;

            DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO dev_event_traffic_trafficcar_info = pEventTraffic->stTrafficCar;


            if (strcmp(dev_event_traffic_trafficcar_info.szPlateNumber, "") == 0 ||
                pEventTraffic->stuObject.bPicEnble != true) {

                return 1;
            }

            DHCamera *pDHCamera = (DHCamera *) dwUser;
            //  接收图片写入日志
            char buf[100] = {0};
            string strIP = g_HandIDAndIP[lAnalyzerHandle];
            sprintf(buf, "%s:picture receive!", strIP.c_str());
            logInfo(buf);

            //保存抓拍场景图片
            if (dwBufSize > 0 && NULL != pBuffer) {
                PLIST_BUFFER plistBuffer;
                //获取空队列
                g_pCarListThread->GetBuffer(&plistBuffer, empty);
                if (plistBuffer == nullptr) {
                    //若空队列为空,获取满队列地址
                    logDebug("The hk car data is full and the original data is discarded!");
                    //g_pListThread->GetHeadBuffer(&plistBuffer, full);
                    g_pCarListThread->GetBuffer(&plistBuffer, full);

                    SaveFaceFile(plistBuffer, DAHUA);//xj add
                }
                if (plistBuffer) {

                    //获取时间
                    //时间
                    NET_TIME_EX UTC = pEventTraffic->UTC;
                    DVR_TIME dvrTime;
                    dvrTime.nYear = UTC.dwYear;
                    dvrTime.nMonth = UTC.dwMonth;
                    dvrTime.nDay = UTC.dwDay;
                    dvrTime.nHour = UTC.dwHour;
                    dvrTime.nMinute = UTC.dwMinute;
                    dvrTime.nSecond = UTC.dwSecond;

                    //相机抓拍时间
                    plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);

                    cout << "szPlateType:" << dev_event_traffic_trafficcar_info.szPlateType << endl;

                    cout << "szPlateColor:" << dev_event_traffic_trafficcar_info.szPlateColor << endl;

                    //"White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
                    //车辆颜色 保留字段 暂无
                    plistBuffer->camerasPic.nLicense_car_color = pDHCamera->setVehicleColor(
                            dev_event_traffic_trafficcar_info.szVehicleColor);

                    //车牌类型
                    plistBuffer->camerasPic.nLicense_plate_type = pDHCamera->setPlateType(
                            dev_event_traffic_trafficcar_info.szPlateType);
                    //车牌评分
                    plistBuffer->camerasPic.nFaceScore = 80;

                    //程序推送照片时间
                    plistBuffer->camerasPic.tProgramTime = time(NULL);

                    //图片长度
                    plistBuffer->camerasPic.nBackgroundPicLen = dwBufSize;

                    //检查内存是否符合大小
                    g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);

                    //拷贝图片内存
                    memcpy(plistBuffer->camerasPic.pBackBuffer, pBuffer,
                           dwBufSize);

                    //图片长度
                    plistBuffer->camerasPic.nFacePicLen = pEventTraffic->stuObject.stPicInfo.dwFileLenth;

                    //检查内存是否符合大小
                    g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nFacePicLen, FACE_PIC_TAG, plistBuffer);

                    //拷贝图片内存
                    memcpy(plistBuffer->camerasPic.pFaceBuffer, pBuffer + pEventTraffic->stuObject.stPicInfo.dwOffSet,
                           pEventTraffic->stuObject.stPicInfo.dwFileLenth);

                    //IP地址
                    memcpy(plistBuffer->camerasPic.cCameraIP, strIP.c_str(), 16);

                    //车牌
                    memcpy(plistBuffer->camerasPic.cLicense_plate_num, dev_event_traffic_trafficcar_info.szPlateNumber,
                           16);

                    cout << "strNumber:" << plistBuffer->camerasPic.cLicense_plate_num << endl;


                    // 在坐标系8192 * 8192中的车牌的坐标点
                    DH_RECT dRect = pEventTraffic->stuObject.BoundingBox;

                    // 真实物理坐标
                    DH_RECT dstRect = {0};

                    // 计算真实的车牌物理坐标，分为三种情况：
                    dstRect.left = dRect.left * pEventTraffic->stuResolution.snWidth / 8192;
                    dstRect.right = dRect.right * pEventTraffic->stuResolution.snWidth / 8192;

                    // 抓图无OSD叠加；或者设备端对OSD处理过，无需考虑OSD问题
                    dstRect.top = dRect.top * pEventTraffic->stuResolution.snHight / 8192;
                    dstRect.bottom = dRect.bottom * pEventTraffic->stuResolution.snHight / 8192;

//                    int n = dstRect.right - dstRect.left;
//                    int d = dstRect.bottom - dstRect.top;


                    //坐标区域
                    plistBuffer->camerasPic.sLicense_rect.nBottom = dstRect.bottom;
                    plistBuffer->camerasPic.sLicense_rect.nLeft = dstRect.left;
                    plistBuffer->camerasPic.sLicense_rect.nRight = dstRect.right;
                    plistBuffer->camerasPic.sLicense_rect.nTop = dstRect.top;

                    //车牌颜色
                    plistBuffer->camerasPic.nLicense_plate_color = pDHCamera->setPlateColor(
                            dev_event_traffic_trafficcar_info.szPlateColor);;
                    //移到空队列
                    //放入满队列
                    g_pCarListThread->PutBuffer(plistBuffer, full);
                    char buf[100] = {0};
                    //图片放入缓冲区，写入日志
                    sprintf(buf, "%s:picture inster double list!", plistBuffer->camerasPic.cCameraIP);
                    logInfo(buf);
                }
            }

        }
            break;
        default:
            printf("other event type[%d]\n", dwAlarmType);
            break;
    }

    return 1;
}

DHCamera::DHCamera(void *pUser, const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword,
                   const int nTag)
        : m_pCameras((CCameras *) pUser),
          m_lUserID(-1),
          m_lHandle(-1),
          m_strCameraIP(cCameraIP),
          m_nPort(nPort),
          m_cUserName(cUserName),
          m_cPassword(cPassword) {
    //初始化相机
    SetCameraInit(OnInitCamera(cCameraIP, nPort, cUserName, cPassword));

}

DHCamera::~DHCamera() {
    if (m_lUserID == 0)
        return;

    // 停止订阅图片报警
    CLIENT_StopLoadPic(m_lHandle);

    CLIENT_Logout(m_lUserID);
    // 清理 SDK 资源
    CLIENT_Cleanup();
}

void DHCamera::send_dhcamera_state(string strIP, bool isState) {
    m_pCameras->send_camera_state(strIP, isState);
}

bool
DHCamera::OnInitCamera(const char *cDeviceAddress, const WORD wPort, const char *cUserName, const char *cPassword,
                       const int nTag) {
    //初始化
    //Initialize the SDK, set the disconnection callback functions
    CLIENT_Init(DisConnectFunc, (LDWORD) this);

    //Setting disconnection reconnection success of callback functions. If don't call this interface, the SDK will not break reconnection.
    CLIENT_SetAutoReconnect(AutoConnectFunc, (LDWORD) this);

    //设置网络参数
    NET_PARAM stuNetParam = {0};
    stuNetParam.nWaittime = 8000; // unit ms
    CLIENT_SetNetworkParam(&stuNetParam);

    NET_DEVICEINFO_Ex stDevInfo = {0};
    int nError = 0;

    // 登录设备
    m_lUserID = CLIENT_LoginEx2(cDeviceAddress, wPort, cUserName, cPassword,
                                EM_LOGIN_SPEC_CAP_TCP, NULL, &stDevInfo, &nError);
    // 退出设备
    if (0 == m_lUserID) {
        //int nErrorNum = CLIENT_GetLastError() & (0x7fffffff);
        string strIP = cDeviceAddress;
        logError(strIP + ",login error, ErrorNum:" + to_string(nError));
        CLIENT_Logout(m_lUserID);
        // 清理 SDK 资源
        CLIENT_Cleanup();
        return false;
    }

    // 订阅智能图片报警
    LDWORD dwUser = (LDWORD) this;
    int nChannel = 0;
    // 每次设置对应一个通道,并且对应一种类型的事件
    // 如果要设置该通道上传所有类型的事件,可以将参数 dwAlarmType 设置为 EVENT_IVS_ALL
    // 如果需要设置一个通道上传两种事件,那么请调用两次 CLIENT_RealLoadPictureEx,并且传入不同的事件类型
    m_lHandle = CLIENT_RealLoadPictureEx(m_lUserID, nChannel, EVENT_IVS_ALL/*EVENT_IVS_FACEDETECT*/, TRUE,
                                         AnalyzerDataCallBack, dwUser, NULL);
    if (m_lHandle == 0) {
        //int nErrorNum = CLIENT_GetLastError() & (0x7fffffff);
        logError("realLoadPicture error, ErrorNum:" + to_string(nError));
        CLIENT_Logout(m_lUserID);
        // 清理 SDK 资源
        CLIENT_Cleanup();
        return false;
    }

    g_HandIDAndIP.insert(make_pair(m_lHandle, m_strCameraIP));
    return true;
}

int DHCamera::setVehicleColor(const char *strColor) {
    int nColorType = 1;
    //车身颜色	"White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
    if (strcmp(strColor, "White") == 0) {
        nColorType = COLOUR_WHITE;
    } else if (strcmp(strColor, "White") == 0) {
        nColorType = COLOUR_WHITE;
    } else if (strcmp(strColor, "Black") == 0) {
        nColorType = COLOUR_BLACK;
    } else if (strcmp(strColor, "Red") == 0) {
        nColorType = COLOUR_RED;
    } else if (strcmp(strColor, "Yellow") == 0) {
        nColorType = COLOUR_YELLOW;
    } else if (strcmp(strColor, "Gray") == 0) {
        nColorType = COLOUR_ASH;
    } else if (strcmp(strColor, "Blue") == 0) {
        nColorType = COLOUR_BLUE;
    } else if (strcmp(strColor, "Green") == 0) {
        nColorType = COLOUR_GREEN;
    } else {
        nColorType = COLOUR_OTHER;
    }
    return nColorType;
}

int DHCamera::setPlateColor(const char *strColor) {
    int nColorType = 1;
    // 车牌颜色    "Blue","Yellow", "White","Black","YellowbottomBlackText","BluebottomWhiteText",
    // "BlackBottomWhiteText","ShadowGreen","YellowGreen"
    if (strcmp(strColor, "Blue") == 0) {
        nColorType = COLOUR_BLUE;
    } else if (strcmp(strColor, "Yellow") == 0) {
        nColorType = COLOUR_YELLOW;
    } else if (strcmp(strColor, "White") == 0) {
        nColorType = COLOUR_WHITE;
    } else if (strcmp(strColor, "Black") == 0) {
        nColorType = COLOUR_BLACK;
    } else if (strcmp(strColor, "YellowbottomBlackText") == 0) {
        nColorType = COLOUR_YELLOW;
    } else if (strcmp(strColor, "BluebottomWhiteText") == 0) {
        nColorType = COLOUR_BLUE;
    } else if (strcmp(strColor, "BlackBottomWhiteText") == 0) {
        nColorType = COLOUR_BLACK;
    } else if (strcmp(strColor, "ShadowGreen") == 0) {
        nColorType = COLOUR_GREEN;
    } else if (strcmp(strColor, "YellowGreen") == 0) {
        nColorType = COLOUR_OTHER;
    } else {
        nColorType = COLOUR_OTHER;
    }
    return nColorType;
}

int DHCamera::setPlateType(const char *strType) {
    int nColorType = 1;
    //"Unknown" 未知; "Normal" 蓝牌黑牌; "Yellow" 黄牌; "DoubleYellow" 双层黄尾牌
    // "Police" 警牌; "Armed" 武警牌; "Military" 部队号牌; "DoubleMilitary" 部队双层
    if (strcmp(strType, "Unknown") == 0) {
        nColorType = LICENSE_OTHER;
    } else if (strcmp(strType, "Normal") == 0) {
        nColorType = LICENSE_SMALL_CAR;
    } else if (strcmp(strType, "Yellow") == 0) {
        nColorType = LICENSE_LARGE_CAR;
    } else if (strcmp(strType, "DoubleYellow") == 0) {
        nColorType = LICENSE_LARGE_CAR;
    } else if (strcmp(strType, "Police") == 0) {
        nColorType = LICENSE_POLICE_CAR;
    } else if (strcmp(strType, "Armed") == 0) {
        nColorType = LICENSE_ARMED_POLICE;
    } else if (strcmp(strType, "Military") == 0) {
        nColorType = LICENSE_ARMY;
    } else if (strcmp(strType, "DoubleMilitary") == 0) {
        nColorType = LICENSE_ARMY;
    } else {
        nColorType = LICENSE_OTHER;
    }
    return nColorType;
}