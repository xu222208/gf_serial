
#include "../global.h"
#include "NetDEVSDK.h"
#include "NetDev.h"

using namespace std;
//存储登录相机IP地址和登录ID
//map<LPVOID, string> g_NETDEVandIDAndIP;
//定义全局队列，用来存储文件信息
map<int, NETDEV_USELISTTIMER> g_pUselistBuffer_NETDEV;

LPVOID netdev_UserID;

char  NetDeverrIp[60]={0};
void cbFaceSnapshotCallBack(LPVOID lpUserID, LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S pstFaceSnapShotData,LPVOID lpUserData);
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetFaceSnapshotCallBack(IN LPVOID lpUserID,
                                                                    IN NETDEV_FaceSnapshotCallBack_PF cbFaceSnapshotCallBack,
                                                                    IN LPVOID lpUserData);



void cbFaceSnapshotCallBack(LPVOID lpUserID, LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S pstFaceSnapShotData,LPVOID lpUserData)
{
    logInfo("cbFaceSnapshotCallBack   enter\n");
    LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S  pic_pstFaceSnapShotData=(LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S)pstFaceSnapShotData;
    if(pic_pstFaceSnapShotData->udwPicBuffLen>0&&NULL!=pic_pstFaceSnapShotData->pcPicBuff) {
        int nGroupId = pic_pstFaceSnapShotData->udwFaceId;
        char buf[100] = {0};
        //string strIP = g_NETDEVandIDAndIP[lpUserID];
        string strIP=pstFaceSnapShotData->szIPAddr;
        sprintf(buf, "%s:picture receive!", strIP.c_str());
        logInfo(buf);
        //printf("pic_pstFaceSnapShotData->enImgType =%d\n",pic_pstFaceSnapShotData->enImgType) ;
        auto iter = g_pUselistBuffer_NETDEV.find(nGroupId);
        if (iter != g_pUselistBuffer_NETDEV.end()) {
            NETDEV_USELISTTIMER uselisttimer = iter->second;
            //获取已存在信息
            if (uselisttimer.plistBuffer) {
                //int nTempPicLen = uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen;
                //人脸
                if (pic_pstFaceSnapShotData->enImgType == 2) {
                    logInfo("face snap shot");
                    uselisttimer.plistBuffer->camerasPic.nFacePicLen = pic_pstFaceSnapShotData->udwPicBuffLen;
                    g_pListThread->CheckBuffer(pic_pstFaceSnapShotData->udwPicBuffLen + 1, FACE_PIC_TAG,
                                               uselisttimer.plistBuffer);
                    memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pic_pstFaceSnapShotData->pcPicBuff,
                           pic_pstFaceSnapShotData->udwPicBuffLen);
                } else if (pic_pstFaceSnapShotData->enImgType == 1)   //全景
                {
                    logInfo("full view");
                    //图片长度
                    uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = pic_pstFaceSnapShotData->udwPicBuffLen;
                    //检查内存是否符合大小
                    g_pListThread->CheckBuffer(pic_pstFaceSnapShotData->udwPicBuffLen + 1, BAKE_PIC_TAG,
                                               uselisttimer.plistBuffer);
                    //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pic_pstFaceSnapShotData->pcPicBuff,
                           pic_pstFaceSnapShotData->udwPicBuffLen);
                }

                //插入NETDEV_GetLastError缓存队列时间
                uselisttimer.plistBuffer->camerasPic.tProgramTime = time(0);
                //放入满队列
                g_pListThread->PutBuffer(uselisttimer.plistBuffer, full);
                g_pUselistBuffer_NETDEV.erase(nGroupId);

                sprintf(buf, "%s:picture inster double list!", strIP.c_str());
                logInfo(buf);

            }


        } else {
            //获取系统时间
            time_t t = time(NULL);
            NETDEV_USELISTTIMER uselisttimer;
            //若10秒还未收到数据,删除队列

            uselisttimer.nTimer = t + 10;
            //PLIST_BUFFER plistBuffer;cbFaceSnapshotCallBack
            g_pListThread->GetBuffer(&uselisttimer.plistBuffer, empty);
            if (uselisttimer.plistBuffer == nullptr) {
                //若空队列为空,获取满队列头地址AutoConnectFunc
                logDebug("The dh data is full and the original data is d(pstReportInfo->stEventInfo.pstEventRes->dwResTypeiscarded!");
                //g_pListThread->GetHeadBuffer(&plistBufferrIper, full);
                g_pListThread->GetBuffer(&uselisttimer.plistBuffer, full);
                //获取内存图片并保存
                //SaveFaceFile(uselisttimer.plistBuffer, DAHUA);
            }
            if (uselisttimer.plistBuffer) {
                string strTime = pic_pstFaceSnapShotData->szPassTime;
                char cYear[4] = {0};
                char cMonth[2] = {0};
                char cDay[2] = {0};
                char cHour[2] = {0};
                char cMinute[2] = {0};
                char cSecond[2] = {0};
                //char cMilsecond[3]={0};
                memcpy(cYear, &pic_pstFaceSnapShotData->szPassTime[0], 4);
                memcpy(cMonth, &pic_pstFaceSnapShotData->szPassTime[4], 2);
                memcpy(cDay, &pic_pstFaceSnapShotData->szPassTime[6], 2);
                memcpy(cHour, &pic_pstFaceSnapShotData->szPassTime[8], 2);
                memcpy(cMinute, &pic_pstFaceSnapShotData->szPassTime[10], 2);
                memcpy(cSecond, &pic_pstFaceSnapShotData->szPassTime[12], 2);
                //memcpy(cMilsecond, &pic_pstFaceSnapShotData->szPassTime[14], 3);
                DVR_TIME dvrTime;
                dvrTime.nYear = atoi(cYear);
                dvrTime.nMonth = atoi(cMonth);
                dvrTime.nDay = atoi(cDay);
                dvrTime.nHour = atoi(cHour);
                dvrTime.nMinute = atoi(cMinute);
                dvrTime.nSecond = atoi(cSecond);
                uselisttimer.plistBuffer->camerasPic.nCamerasType = NETDEV;
                uselisttimer.plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);
                //获取场景图标识（1：全景；2人脸）NETDEV_Cleanup
                //人脸
                if (pic_pstFaceSnapShotData->enImgType == 2) {
                    uselisttimer.plistBuffer->camerasPic.nFacePicLen = pic_pstFaceSnapShotData->udwPicBuffLen;
                    g_pListThread->CheckBuffer(pic_pstFaceSnapShotData->udwPicBuffLen + 1, FACE_PIC_TAG,
                                               uselisttimer.plistBuffer);
                    memcpy(uselisttimer.plistBuffer->camerasPic.pFaceBuffer, pic_pstFaceSnapShotData->pcPicBuff,
                           pic_pstFaceSnapShotData->udwPicBuffLen);
                } else if (pic_pstFaceSnapShotData->enImgType == 1)   //背景
                {
                    //图片长度
                    uselisttimer.plistBuffer->camerasPic.nBackgroundPicLen = pic_pstFaceSnapShotData->udwPicBuffLen;
                    //检查内存是否符合大小
                    g_pListThread->CheckBuffer(pic_pstFaceSnapShotData->udwPicBuffLen + 1, BAKE_PIC_TAG,
                                               uselisttimer.plistBuffer);
                    //拷贝图片内存
                    memcpy(uselisttimer.plistBuffer->camerasPic.pBackBuffer, pic_pstFaceSnapShotData->pcPicBuff,
                           pic_pstFaceSnapShotData->udwPicBuffLen);

                }
                //清空IP地址
                memset(uselisttimer.plistBuffer->camerasPic.cCameraIP, 0, 16);
                //IP地址
                memcpy(uselisttimer.plistBuffer->camerasPic.cCameraIP, strIP.c_str(), strIP.length());
                //人脸评分
                uselisttimer.plistBuffer->camerasPic.nFaceScore = 70;

                //获取告警NETDEV_GetLastError区域坐标
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nX = pic_pstFaceSnapShotData->stFacePos.dwTopLeftX;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nY = pic_pstFaceSnapShotData->stFacePos.dwTopLeftY;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nWidth =  pic_pstFaceSnapShotData->stFacePos.dwBottomRightX;
                uselisttimer.plistBuffer->camerasPic.sAlarmRect_JVT.nHeight = pic_pstFaceSnapShotData->stFacePos.dwBottomRightY;
            }

            g_pUselistBuffer_NETDEV.insert(make_pair(nGroupId, uselisttimer));
        }
    }

}





void NetDevCamera::Ondestroy() {
    if ((LPVOID)m_lHandle > 0) {
        //停止接收图片信息
        //NETDEV_StopRealPlay(m_lHandle);
    }

    if ((LPVOID)m_lUserID > 0) {
        //退出登录
        NETDEV_Logout(m_lUserID);
    }
    printf("NETDEV_Cleanup\n");
    //清理资源
    NETDEV_Cleanup();
}



NetDevCamera::~NetDevCamera() {
    Ondestroy();
}



NetDevCamera::NetDevCamera(const char *cCameraIP,const int nPort,const char *cUserName,const char *cPassword)
        : //m_lUserID(-1),
         // m_lHandle(-1),
          m_strCameraIP(cCameraIP),
          m_nPort(nPort),
          m_cUserName(cUserName),
          m_cPassword(cPassword)
          {

        SetCameraInit(OnInitCamera(cCameraIP, nPort, cUserName, cPassword));
}





void NetDevCamera::reconnCamera() {
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


void      cbAlarmMessCallBack(  LPVOID lpUserID,
                                INT32 dwChannelID,
                                 NETDEV_ALARM_INFO_S stAlarmInfo,
                                LPVOID lpBuf,
                                 INT32 dwBufLen,
                                LPVOID lpUserData)
{
    if(stAlarmInfo.dwAlarmType==NETDEV_ALARM_NET_OFF)
    {
        logInfo("cbAlarmMessCallBack");
        //断线重连
        NetDevCamera *pNetDevCamera= (NetDevCamera *) lpUserData;
        pNetDevCamera->reconnCamera();
    }
}

#if  1
bool NetDevCamera::OnInitCamera(const char *cDeviceAddress, const unsigned short wPort, const char *cUserName,
                                const char *cPassword)
{
    logInfo("=======OnInitCamera:start=======\n");

    BOOL isSuccess = NETDEV_Init();
    if (!isSuccess)
    {
        printf("NETDEV_Init Failed errcode(%d)\n",NETDEV_GetLastError());
        memcpy(NetDeverrIp,cDeviceAddress,strlen(cDeviceAddress));
        return false;
    }

    char pszDevIP[128];
    INT16 wDevPort = 0;
    char pszUserName[128];
    char pszPassword[128];

    memset(pszDevIP, 0, 128);
    memset(pszUserName, 0, 128);
    memset(pszPassword, 0, 128);




    memcpy(pszDevIP,cDeviceAddress,128);

    wDevPort=wPort;


    memcpy(pszUserName,cUserName,128);


    memcpy(pszPassword,cPassword,128);


    //printf("You Input Login Info Is (%s:%d:%s:%s)\n", pszDevIP, wDevPort, pszUserName, pszPassword);

    NETDEV_DEVICE_INFO_S stDevInfo;
    memset(&stDevInfo, 0, sizeof(stDevInfo));

    isSuccess = NETDEV_SetFaceSnapshotCallBack(NULL, cbFaceSnapshotCallBack, NULL);
    if (!isSuccess)
    {
        printf("NETDEV_SetFaceSnapshotCallBack Failed errcode(%d)\n",NETDEV_GetLastError());
        return false;
    }


    LPVOID pUserID = NETDEV_Login(pszDevIP, wDevPort, pszUserName, pszPassword, &stDevInfo);
    if(pUserID != NULL)
    {
        m_lUserID=pUserID;//add
        netdev_UserID=m_lUserID;//add
        logInfo("Login Success\n");
    }
    else
    {
        printf("NETDEV_Login Failed errcode(%d)\n",NETDEV_GetLastError());
        return false;
    }
    if(NETDEV_SetAlarmCallBack(m_lUserID,cbAlarmMessCallBack,this)!=TRUE)
    {
        //清理资源
        NETDEV_Cleanup();
        return false;
    }


    logInfo("=======main:end=======\n");
    return true;
}

bool NetDevCamera::lNetDev_Logout(LPVOID netdev_UserID)
{
    NETDEV_Logout(netdev_UserID);
}

#endif