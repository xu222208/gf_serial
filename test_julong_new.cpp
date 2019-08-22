#include <assert.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "jvt/VideoNetAPI.h"

using namespace std;
using namespace SDK_JVTFACE;

#ifndef ulong
#define ulong unsigned long
#endif
int g_LoginID = 0;
string password;
pthread_t id;
static int s_flag = 0;

FILE *g_pFile = NULL;
int recvok = 0;
char *pListInfo = NULL;
int g_Listcount = 0;
pthread_mutex_t m_listmutex;

typedef enum {
    lanlogin,
    P2Plogin,
    JVTDAS,
} JVTLOGINTYPE;

typedef enum {
    RealPlay,
    PLAYBACK_BYNAME,
    PLAYBACK_BYNAME_V2,
    PLAYBACK_BYTIME,
    PLAYBACK_BYTIME_V2,
    JVTTALK,
    JVTConfig,
    ADDUSER,
    FaceImageSnap,
    FaceCompareResult,
    FaceWriteAndBlackList,
    SearchDevice,
    SearchDeviceV2,
    P2PQUERY,
    GPIOControl,
} JVTFUCTION;

int SystemCmd(const char *szCmd) {
    pid_t pid = 0;
    int ret = 0;
    int nRetry = 20;

    if (NULL == szCmd) {
        return -1;
    }

    while (0 < nRetry--) {
        if (0 > (pid = vfork())) {
            usleep(100 * 1000);
        } else {
            break;
        }
    }

    if (0 > pid) {
        DBG("fork failed retry=%d\n", nRetry);
        ret = -1;
    } else if (0 == pid) {
        int fd;

        for (fd = 3; fd < getdtablesize(); fd++)
            close(fd);

        execl("/bin/sh", "sh", "-c", szCmd, NULL);
        exit(127);
    } else {
        while (0 > waitpid(pid, &ret, 0)) {
            if (EINTR != errno) {
                ret = -1;
                break;
            }
        }
    }

    return ret;
}

int
BlackAndWhiteListCallBack(long lRealFaceHandle, char *pBuffer, long lbufsize, SDK_FA_BLACKANDWHITELIST_CONFIG *pParm,
                          long dwUser) {
    SDK_FA_BLACKANDWHITELIST_CONFIG *pConfig = (SDK_FA_BLACKANDWHITELIST_CONFIG *) pParm;
    if (pConfig == NULL) {
        return -1;
    }
    DBG("BlackAndWhiteListCallBack pConfig->byOutMode = %d\n", pConfig->byOutMode);

    if (OUT_INDEX == pConfig->byOutMode) {
        g_Listcount = pConfig->byAllNums;
        pListInfo = new char[sizeof(sdk_fileindex_info_t) * g_Listcount + 1];
        memset(pListInfo, 0, sizeof(sdk_fileindex_info_t) * g_Listcount + 1);
        pthread_mutex_lock(&m_listmutex);
        memcpy(pListInfo, pBuffer, sizeof(sdk_fileindex_info_t) * g_Listcount);
        for (int i = 0; i < g_Listcount; i++) {
            sdk_fileindex_info_t *pInfo = (sdk_fileindex_info_t *) (pListInfo + sizeof(sdk_fileindex_info_t) * i);
            SUCCESS_TRACE("i = %d,checksum=%d,enable=%d,name=%s,fileindex=%d,libindex=%d\n",
                          i, pInfo->checksum, pInfo->enable, pInfo->name, pInfo->findex.fileindex,
                          pInfo->findex.libindex);
        }
        pthread_mutex_unlock(&m_listmutex);
    } else if (OUT_PICTURE_DEL == pConfig->byOutMode) {

    } else if (OUT_PICTURE_DELALL == pConfig->byOutMode) {
        //????
    } else if (IN_PICTURE_ADD == pConfig->byOutMode) {
        //GetResultCode(pConfig->byErrorCode);

    } else if (IN_PICTURE_ADD_SNAP == pConfig->byOutMode || OUT_PICTURE == pConfig->byOutMode ||
               OUT_PICTURE_COMP == pConfig->byOutMode) {
        if (pConfig->byErrorCode == WB_OK) {
            char *pFileBuf = new char[lbufsize];
            memcpy(pFileBuf, pBuffer, lbufsize);
            if (access("./photo", F_OK) != 0) {
                DBG("固定路径下没有文件，现在创建\n");
                SystemCmd((char *) "mkdir photo");
            }
            char filename[128] = {0};
            sprintf(filename, "photo/%s", pConfig->byFileName);
            DBG("filename = %s\n", filename);

            g_pFile = fopen(filename, "wb");
            if (g_pFile) {
                fwrite(pFileBuf, 1, lbufsize, g_pFile);
                fclose(g_pFile);
                g_pFile = NULL;

                if (pFileBuf != NULL) {
                    delete pFileBuf;
                    pFileBuf = NULL;
                }
            } else {
                ERR("g_pFile=%p,errno=%d\n", g_pFile, errno);
            }
        } else {
            //GetResultCode(pConfig->byErrorCode);
            ERR("pConfig->byErrorCode = %d", pConfig->byErrorCode);
        }

    } else if (IN_PICTURE_GET_FEATURE == pConfig->byOutMode || IN_INDEX_GET_FEATURE == pConfig->byOutMode) {
        char szFeature[512] = {0};
        memcpy((char *) szFeature, pBuffer, lbufsize);

        for (int i = 0; i < 512; i++) {
            printf("%02x ", (BYTE) szFeature[i]);
        }
        printf("\n");
    }
    recvok = 1;
    return 0;
}


int FaceCompareResultCallback(long lRealFaceHandle, char *pBuf, long nDataLen, long dwUser) {
    static int nCount = 0;
    SDK_FACECOMPARE_RESULT *pstResulAlarm = (SDK_FACECOMPARE_RESULT *) pBuf;

//    SUCCESS_TRACE("channelid = %u:\n", pstResulAlarm->channelid);
//    SUCCESS_TRACE("picnameComp = %s:\n", pstResulAlarm->picnameComp);
//    SUCCESS_TRACE("picnameSnap = %s:\n", pstResulAlarm->picnameSnap);
//
//    SUCCESS_TRACE("deviceid = %u:\n", pstResulAlarm->deviceid);
//    SUCCESS_TRACE("libindex = %u:\n", pstResulAlarm->libindex);
//    SUCCESS_TRACE("libnumber = %u:\n", pstResulAlarm->libnumber);
//    SUCCESS_TRACE("SnapTime = %s:\n", pstResulAlarm->SnapTime);
//    SUCCESS_TRACE("streamid = %d:\n", pstResulAlarm->streamid);
//    SUCCESS_TRACE("wbmode = %u:\n", pstResulAlarm->wbmode);
//    SUCCESS_TRACE("result = %f:\n", pstResulAlarm->result);
//    SUCCESS_TRACE("guest = %u:\n", pstResulAlarm->guest);
    cout << "****************************************" << endl;
    string strGender = "男";
    switch (pstResulAlarm->Gender){
        case 1:
            strGender = "男";
            break;
        case 2:
            strGender = "女";
            break;
        default:
            break;
    }

    nCount += pstResulAlarm->guest;
    SUCCESS_TRACE("年龄 = %d:\n", pstResulAlarm->Age);
    SUCCESS_TRACE("性别 = %s:\n", strGender.c_str());
    SUCCESS_TRACE("客流统计 = %d:\n", nCount);

//    SUCCESS_TRACE("facecharacter: \n");
//    for (int i = 0; i < 128; i++) {
//        printf("%f ", pstResulAlarm->facecharacter[i]);
//
//        if (i % 16 == 15)
//            printf("\n");
//    }

    return 0;
}


int
PictureDataCallback(long lRealFaceHandle, char *pBuf, long nDataLen, SDK_FA_PICTURE_HEAD *pHead, SDK_FACE_ATTR *pAttr,
                    long dwUser) {
    char *pFileBuf = new char[nDataLen + 1];
    memcpy(pFileBuf, pBuf, nDataLen + 1);
    SDK_FA_PICTURE_HEAD *picHead = (SDK_FA_PICTURE_HEAD *) pHead;
    SDK_FACE_ATTR *picAttr = (SDK_FACE_ATTR *) pAttr;
    char filename[128] = {0};
    SUCCESS_TRACE("================PictureDataCallback=================\n");
    SUCCESS_TRACE("picHead->filename=%s\n", picHead->filename);
    //SUCCESS_TRACE("dwUser=%ld\n",dwUser);
    SUCCESS_TRACE("count picAttr->nPicID=%d\n", picAttr->nPicID);
    SUCCESS_TRACE("picAttr->nFaceID=%d\n", picAttr->nFaceID);

    string s1;
    s1.push_back(picAttr->stFaceAttribute.byGender);

    cout << "性别:" << s1.c_str() << endl;
    cout << "年龄:" << int(picAttr->stFaceAttribute.byAge) << endl;
    switch (int(picAttr->stFaceAttribute.byGender)) {
        case 1:
        {
            cout << "性别: 男" << endl;

        }
            break;
        case 2:
        {
            cout << "性别: 女" << endl;
        }
            break;
        default:
            break;
    }

    //SUCCESS_TRACE("ATTR: stDevUUID = %s \n", picAttr->stDevUUID);
    //SUCCESS_TRACE("ATTR: stOsd = %s \n", picAttr->stOsd);
    //SUCCESS_TRACE("ATTR: nFaceOrHead = %d \n", picAttr->nFaceOrHead);
    //SUCCESS_TRACE("ATTR: (%d,%d) --> (%d,%d) \n", picAttr->stFacePosition.left, picAttr->stFacePosition.top, picAttr->stFacePosition.right, picAttr->stFacePosition.bottom);
    //SUCCESS_TRACE("picAttr->nFeatureType=%d,picAttr->nFeatureLen=%d\n",picAttr->nFeatureType,picAttr->nFeatureLen);
    /*for(int i = 0;i<picAttr->nFeatureLen;++i)
    {
        printf("%02x ",(BYTE)picAttr->facefeature.cFeature[i]);
    }
    printf("\n");*/
    if (access("./picture", F_OK) != 0) {
        SystemCmd((char *) "mkdir picture");
    }
    sprintf(filename, "picture/%s", picHead->filename);

    FILE *m_pFile = fopen(filename, "wb");

    if (m_pFile) {
        SUCCESS_TRACE("#######receive pic sucess:%s\n", filename);
    } else {
        ERR("#######receive pic error:\n");
    }

    if (m_pFile) {
        fwrite(pFileBuf, 1, nDataLen, m_pFile);
        fclose(m_pFile);
        m_pFile = NULL;
    }

    if (pFileBuf != NULL) {
        delete pFileBuf;
        pFileBuf = NULL;
    }
    return 0;
}

int NetDataCallBack(long lRealHandle, long dwDataType, unsigned char *pBuffer, long lbufsize, long dwUser) {
    DBG("lbufsize:%ld\n", lbufsize);
    BOOL bResult = TRUE;
    try {
        //fwrite(pBuffer,1,lbufsize,g_pFile);
    }
    catch (...) {

    }

    // it must return TRUE if decode successfully,or the SDK will consider the decode is failed
    return bResult;

}

int RealDataCallBack_V2(long lRealHandle, const PACKET_INFO_EX *pFrame, long dwUser) {
    //DBG("time:%04d-%02d-%02d %02d:%02d:%02d\n",pFrame->nYear,pFrame->nMonth,pFrame->nDay,pFrame->nHour,pFrame->nMinute,pFrame->nSecond);
    return 0;
    BOOL bResult = TRUE;
    try {
        fwrite(pFrame->pPacketBuffer, 1, pFrame->dwPacketSize, g_pFile);
    }
    catch (...) {

    }

    // it must return TRUE if decode successfully,or the SDK will consider the decode is failed
    return bResult;
}

void Demo_Talk_DataCallBack(LONG lTalkHandle, char *pDataBuf, long dwBufSize, char byAudioFlag, long dwUser) {
    try {
        DBG("come TalkDataCallBack :%ld\n", dwBufSize);
        if (g_pFile) {
            fwrite(pDataBuf, 1, dwBufSize, g_pFile);
        } else {
            printf("###################################fWrite wrong!!!!!\n");
        }
    }
    catch (...) {

    }
    // it must return TRUE if decode successfully,or the SDK will consider the decode is failed
    return;
}

void SubDisConnectCallBack(long lLoginID, SubConnType type, long nChannel, long dwUser) {
    WARNING_TRACE(
            "###################################SubDisConnect!!!!! type = %d login = %d nCahannel = %d dwUser = %d\n",
            type, lLoginID, nChannel, dwUser);

}

bool DevicCallBack(long lLoginID, char *pBuf,
                   unsigned long dwBufLen, long dwUser, int type) {
    SUCCESS_TRACE("###################one devic is comeing!");
    VIDEONET_ACTIVEREG_INFO *info = (VIDEONET_ACTIVEREG_INFO *) pBuf;
    SUCCESS_TRACE("das device : %s", info->deviceSarialID);
    g_LoginID = lLoginID;

    return true;
}

void pfNetComFun(SDK_CONFIG_NET_COMMON_V2 *pNetCom, unsigned long userData) {
    DBG("data============[%d]\n", s_flag);
}

int StartLogin(JVTLOGINTYPE type, char *uuidip);

void FoundDevCB(char *uuid, int state) {
    SUCCESS_TRACE("uuid=%s,state=%d\n", uuid, state);
    if (strcmp(uuid, "umkse560pi9u") == 0 && state == 1) {
        if (StartLogin(P2Plogin, uuid) == 0)
            ERR("log p2p %s failed\n", uuid);
    }
}

void *Jvt_SearchDevice(void *arr) {

    SDK_CONFIG_NET_COMMON_V2 m_Device[100];
    int nRetLength = 0;
    cout << "start" << endl;
    bool bRet = VideoNet_SearchDevice((char *) m_Device, sizeof(SDK_CONFIG_NET_COMMON_V2) * 1, &nRetLength, 5000);
    if (bRet) {
        DBG("m_Device->HostIP.l = %d\n", m_Device[0].HostIP.l);
        DBG("m_Device->sMac = %s\n", m_Device[0].sMac);
        DBG("VideoNet_SearchDevice ok number is [%d]\n", nRetLength / (int) sizeof(SDK_CONFIG_NET_COMMON_V2));
    }
    return NULL;
}

void StartSearchDevice() {
    int count = 0;

    while (1) {
        sleep(1);

        count++;
        DBG("count = %d\n", count);

        if (count == 15) {
            break;
        }

        if (pthread_create(&id, NULL, Jvt_SearchDevice, NULL) != 0) {
            ERR("pthread_create id failed\n");
            return;
        }
        if (pthread_detach(id) != 0) {
            ERR("pthread detached id failed\n");
            return;
        }
    }
}

void StartDASServer() {
    g_LoginID = -1;

    cout << "start das" << endl;
    bool ret = VideoNet_StartActiveRigister(9400, DevicCallBack, 1);
    cout << "end das" << endl;
    if (ret > 0) {
        cout << "********sleep 2 minit************ " << endl;
    } else {
        ERR("Call VideoNet_StartActiveRigister**********wrong\n");
    }

    while (1) {
        sleep(1);
    }
}

int StartLogin(JVTLOGINTYPE type, char *uuidip) {
    VIDEONET_DEVICEINFO OutDev;
    memset(&OutDev, 0, sizeof(OutDev));
    int nError = 0;
//	36123
    if (type == P2Plogin) {
        DBG("VideoNet_Login_P2P\n");
        //VideoNet_GetP2PLogData();
        g_LoginID = VideoNet_Login_P2P(uuidip, 0, (char *) "admin", (char *) "admin", (LPVIDEONET_DEVICEINFO) (&OutDev),
                                       &nError);
    } else if (type == lanlogin) {
        DBG("VideoNet_Login\n");
        g_LoginID = VideoNet_Login(uuidip, 36123, (char *) "admin", (char *) password.c_str(),
                                   (LPVIDEONET_DEVICEINFO) (&OutDev), &nError);
    }
    DBG("g_LoginID=%d,nError:%d\n", g_LoginID, nError);

    if (VideoNet_SetKeepLifeTime(g_LoginID, 20, 40) != 1) {
        printf("VideoNet_SetKeepLifeTime ERROR!\n");
    }


    if (VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 111) != 1) {
        ERR("VideoNet_SetSubDisconnectCallBack ERROR!\n");
    }

    return g_LoginID;
}

void StartAddUser() {
    USER_INFO userInfo;
    strcpy(userInfo.Groupname, "admin");
    strcpy(userInfo.memo, "");
    strcpy(userInfo.name, "12345");
    strcpy(userInfo.passWord, "");

    userInfo.reserved = false;
    userInfo.rigthNum = 5;
    strcpy(userInfo.rights[0], "ShutDown");
    strcpy(userInfo.rights[1], "ChannelTitle");
    strcpy(userInfo.rights[2], "RecordConfig");
    strcpy(userInfo.rights[3], "Replay_01");
    strcpy(userInfo.rights[4], "Monitor_01");
    userInfo.shareable = true;
    long lRet2 = VideoNet_SetDevConfig(g_LoginID, E_SDK_CONFIG_ADD_USER, -1, (char *) &userInfo, sizeof(userInfo),
                                       10000);
    if (lRet2 > 0) {
        DBG("add user ok\n");
    } else {
        ERR("add user err\n");
    }
}

void StartPlayBack(JVTFUCTION type) {
    VIDEONET_FINDINFO findInfo;
    findInfo.nChannelN0 = 0;
    findInfo.nFileType = 0;            //文件类型, 见SDK_File_Type

    time_t t = time(NULL);
    tm *tt = localtime(&t);

    findInfo.startTime.dwYear = tt->tm_year + 1900;
    findInfo.startTime.dwMonth = tt->tm_mon + 1;
    findInfo.startTime.dwDay = tt->tm_mday;
    findInfo.startTime.dwHour = 0;
    findInfo.startTime.dwMinute = 0;
    findInfo.startTime.dwSecond = 0;

    findInfo.endTime.dwYear = tt->tm_year + 1900;
    findInfo.endTime.dwMonth = tt->tm_mon + 1;
    findInfo.endTime.dwDay = tt->tm_mday;
    findInfo.endTime.dwHour = 23;
    findInfo.endTime.dwMinute = 59;
    findInfo.endTime.dwSecond = 59;

    VIDEONET_FILE_DATA *pData = new VIDEONET_FILE_DATA[64];
    int nFindCount = 0;

    long lRet = VideoNet_FindFile(g_LoginID, &findInfo, pData, 64, &nFindCount, 3000);
    if (lRet > 0 && nFindCount > 0) {
        DBG("search success,playback file num=%d\n", nFindCount);
        if (type == PLAYBACK_BYNAME || type == PLAYBACK_BYNAME_V2) {
            if (type == PLAYBACK_BYNAME)
                lRet = VideoNet_PlayBackByName(g_LoginID, &pData[0], NULL, NetDataCallBack, 12);
            else
                lRet = VideoNet_PlayBackByName_V2(g_LoginID, &pData[0], NULL, RealDataCallBack_V2, 12);
            if (lRet > 0) {
                sleep(10);
                SUCCESS_TRACE("Play success\n");
            } else {
                ERR("Play failed,lRet=%ld\n", lRet);
            }
            return;
        }

        VIDEONET_FINDINFO info;
        memset(&info, 0, sizeof(info));
        info.nChannelN0 = 0;
        info.nFileType = 0;
        info.startTime.dwYear = tt->tm_year + 1900;
        info.startTime.dwMonth = tt->tm_mon + 1;
        info.startTime.dwDay = tt->tm_mday;
        info.startTime.dwHour = 0;
        info.startTime.dwMinute = 0;
        info.startTime.dwSecond = 0;

        info.endTime.dwYear = tt->tm_year + 1900;
        info.endTime.dwMonth = tt->tm_mon + 1;
        info.endTime.dwDay = tt->tm_mday;
        info.endTime.dwHour = 23;
        info.endTime.dwMinute = 59;
        info.endTime.dwSecond = 59;
        g_pFile = fopen("testPlayBack", "wb+");

        if (type == PLAYBACK_BYTIME)
            lRet = VideoNet_PlayBackByTime(g_LoginID, &info, NULL, NetDataCallBack, 1);
        else
            lRet = VideoNet_PlayBackByTime_V2(g_LoginID, &info, RealDataCallBack_V2, 1, NULL, 12);
        if (lRet > 0) {
            sleep(10);
            SUCCESS_TRACE("Play success\n");
        } else {
            ERR("Play failed,lRet=%ld\n", lRet);
        }
        return;
        long ret = VideoNet_PlayBackByTime(g_LoginID, &info, NULL, NetDataCallBack, 1);
        if (ret) {
            DBG("######playBackByTime#########\n");
            sleep(10);

        } else {
            ERR("#############playbackWrong#####:%ld\n", ret);
        }
    }
}

void StartTalk() {
    g_pFile = fopen("TestTalk", "wb+");
    long lHandle = VideoNet_StartVoiceCom_MR(g_LoginID, Demo_Talk_DataCallBack, 0);
    if (lHandle <= 0) {
        ERR("start talk wrong");
    } else {
        ERR("start talk ok\n");
        sleep(6);
        if (VideoNet_StopVoiceCom(lHandle)) {
            DBG("stop talk ok\n");
        } else {
            ERR("stop wrong!");
        }
    }
}

void StartConfig() {
    ulong dwRetLen = 0;
    int nWaitTime = 10000;
    dwRetLen = 0;
    nWaitTime = 10000;
    SDK_CONFIG_NORMAL NormalConfig = {{0}};
    BOOL bSuccess = VideoNet_GetDevConfig(g_LoginID, E_SDK_CONFIG_SYSNORMAL, 0,
                                          (char *) &NormalConfig, sizeof(SDK_CONFIG_NORMAL), &dwRetLen, nWaitTime);
    if (bSuccess && dwRetLen == sizeof(SDK_CONFIG_NORMAL)) {
        SUCCESS_TRACE("############sMachineName: %s#############\n", NormalConfig.sMachineName);
    }
}

void StartRealPlay() {
    VIDEONET_CLIENTINFO playstru;

    playstru.nChannel = 0;
    playstru.nStream = 0;
    playstru.nMode = 0;
    long m_iPlayhandle = VideoNet_RealPlay(g_LoginID, &playstru);
    if (m_iPlayhandle == 0) {
        ERR("start RealPlay wrong!\n");
    } else {
        g_pFile = fopen("TestRealPlay.h264", "wb+");
        VideoNet_SetRealDataCallBack_V2(m_iPlayhandle, RealDataCallBack_V2, 0);
        DBG("start RealPlay ok!\n");
        while (1) {
            SUCCESS_TRACE("start RealPlay ok!\n");
            sleep(1);
        }
        DBG("stop realPlay ok\n");
        if (VideoNet_StopRealPlay(m_iPlayhandle)) {
            SUCCESS_TRACE("stop realPlay ok\n");
        } else {
            ERR("stop realPlay Wrong\n");
        }

    }
}

void StartFaceImageSnap() {
    //long m_lRealFacePicHandle =  VideoNet_StartReceiveFaceImageFile(g_LoginID,0);
    DBG("start FaceImageData\n");
    long m_lRealFacePicHandle = VideoNet_StartReceiveFaceImageFileEx(g_LoginID, 0, 1);
    if (m_lRealFacePicHandle > 0) {
        VideoNet_SetFaceImageDataCallBack(m_lRealFacePicHandle, PictureDataCallback, 12);
        DBG("start FaceImageData ok!\n");

        /*while(1)
        {
            sleep(6);
        }

        if (m_lRealFacePicHandle > 0)
        {
            VideoNet_StopReceiveFaceImageFile(m_lRealFacePicHandle);
            int rett = 	VideoNet_DelFaceImageDataCallBack(m_lRealFacePicHandle,PictureDataCallback, 0);
            DBG("rett = %d\n",rett);
            m_lRealFacePicHandle = -1;
        }*/
    } else {
        ERR("start ReceiveFaceImageFile wrong!\n");

    }
}

void StartFaceWriteAndBlackList(WBLIST_ACTION_TYPE type) {
    pthread_mutex_init(&m_listmutex, NULL);
    long m_lFaceBlackAndWhiteList = VideoNet_StartSendBlackAndWhiteList(g_LoginID, 0);
    if (m_lFaceBlackAndWhiteList > 0) {
        DBG("start FaceWriteAndBlackList ok!\n");
        int count = 0;
        VideoNet_SetBlackAndWhiteListCallBack(m_lFaceBlackAndWhiteList, BlackAndWhiteListCallBack, 0);
        switch (type) {
            case OUT_INDEX: {
                VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList, type, 1, 0, 0, NULL);
                count = 0;
                while (!recvok) {
                    usleep(500 * 1000);
                    if (count++ > 30) {
                        ERR("OUT_INDEX failed!\n");
                        break;
                    }
                }
                recvok = 0;
                if (count <= 30)
                    SUCCESS_TRACE("OUT_INDEX success !\n");
                break;
            }
            case OUT_PICTURE:
            case OUT_PICTURE_DEL:
            case IN_INDEX_GET_FEATURE: {
                VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList, OUT_INDEX, 1, 0, 0, NULL);
                count = 0;
                while (!recvok) {
                    usleep(500 * 1000);
                    if (count++ > 60) {
                        ERR("OUT_INDEX failed!\n");
                        break;
                    }
                }
                recvok = 0;
                if (count <= 60)
                    SUCCESS_TRACE("OUT_INDEX success !\n");
                time_t start, end;
                int recvtime = 0;
                int successtime = 0;
                int failtime = 0;
                double sumtime = 0;
                pthread_mutex_lock(&m_listmutex);
                DBG("g_Listcount=%d\n", g_Listcount);
                for (int i = 0; i < g_Listcount; i++) {
                    sdk_fileindex_info_t *pInfo = (sdk_fileindex_info_t *) (pListInfo +
                                                                            sizeof(sdk_fileindex_info_t) * i);
                    SUCCESS_TRACE("i = %d,checksum=%d,enable=%d,name=%s,fileindex=%d,libindex=%d\n",
                                  i, pInfo->checksum, pInfo->enable, pInfo->name, pInfo->findex.fileindex,
                                  pInfo->findex.libindex);
                    VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList, type, 1, pInfo->findex.libindex,
                                                            pInfo->findex.fileindex, pInfo->name);
                    count = 0;
                    time(&start);
                    while (!recvok) {
                        usleep(500 * 1000);
                        if (count++ > 60) {
                            failtime++;
                            ERR("type=%d, failed! failtime=%d\n", type, failtime);
                            break;
                        }
                    }
                    recvok = 0;
                    if (count <= 60) {
                        successtime++;
                        SUCCESS_TRACE("type=%d, OUT_INDEX success successtime=%d!\n", type, successtime);
                    }
                    time(&end);
                    sumtime += difftime(end, start);
                    recvtime++;
                    BLUE_TRACE("IN_PICTURE_ADD cost %f,recvtime=%d\n", difftime(end, start), recvtime);
                }
                pthread_mutex_unlock(&m_listmutex);
                WARNING_TRACE("every IN_PICTURE_ADD average cost %f,successtime=%d,failtime=%d,sendtime=%d\n",
                              sumtime / recvtime, successtime, failtime, recvtime);
                break;
            }

            case IN_PICTURE_ADD:
            case IN_PICTURE_GET_FEATURE: {
                DIR *dirp;
                struct dirent *dp;
                dirp = opendir("../../../pic"); //打开目录指针
                char path[128] = {0};
                time_t start, end;
                int sendtime = 0;
                int successtime = 0;
                int failtime = 0;
                double sumtime = 0;
                while ((dp = readdir(dirp)) != NULL) {
                    if (strstr(dp->d_name, ".jpg")) {
                        sprintf(path, "../../../pic/%s", dp->d_name);

                        time(&start);
                        VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList, type, 1, 0, 0, path);
                        count = 0;
                        while (!recvok) {
                            usleep(500 * 1000);
                            if (count++ > 60) {
                                failtime++;
                                ERR("IN_PICTURE_ADD failed! failtime=%d\n", failtime);
                                break;
                            }
                        }
                        recvok = 0;
                        if (count <= 60) {
                            successtime++;
                            SUCCESS_TRACE("IN_PICTURE_ADD success successtime=%d!\n", successtime);
                        }
                        time(&end);
                        sumtime += difftime(end, start);
                        sendtime++;
                        BLUE_TRACE("IN_PICTURE_ADD cost %f,sendtime=%d\n", difftime(end, start), sendtime);
                    }
                }
                WARNING_TRACE("every IN_PICTURE_ADD average cost %f,successtime=%d,failtime=%d,sendtime=%d\n",
                              sumtime / sendtime, successtime, failtime, sendtime);
                break;
            }
            case IN_PICTURE_ADD_SNAP: {
                char name[64] = {0};
                int i = 0;
                while (1) {
                    memset(name, 0, sizeof(name));
                    i++;
                    sprintf(name, "%4x_%4x_%4x", i, i, i);
                    VideoNet_OperationBlackAndWhiteListData(m_lFaceBlackAndWhiteList, type, 1, 0, 0, name);
                    count = 0;
                    while (!recvok) {
                        usleep(500 * 1000);
                        if (count++ > 60) {
                            ERR("IN_PICTURE_ADD_SNAP failed!\n");
                            break;
                        }
                    }
                    recvok = 0;
                    if (count <= 60)
                        SUCCESS_TRACE("IN_PICTURE_ADD_SNAP success !\n");
                }

            }
            default:
                break;
        }
        if (VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 0) != 1) {
            ERR("VideoNet_SetSubDisconnectCallBack ERROR!\n");
        }

        if (m_lFaceBlackAndWhiteList > 0) {
            VideoNet_StopSendBlackAndWhiteList(m_lFaceBlackAndWhiteList);
            VideoNet_DeleteBlackAndWhiteListCallBack(m_lFaceBlackAndWhiteList, BlackAndWhiteListCallBack, 0);
            m_lFaceBlackAndWhiteList = -1;
        }

        DBG("start FaceWriteAndBlackList OK!\n");

    } else {
        ERR("start FaceWriteAndBlackList wrong!\n");
    }
}

void StartFaceCompareResult() {
    SDK_COMPINFO_FLAG stFlag;
    stFlag.iAlarmEn = 1;
    stFlag.iCaptureEn = 1;
    stFlag.iFeatureEn = 1;
    stFlag.iLibPicEn = 1;
    long m_lRealFaceCompareHandle = VideoNet_StartReceiveFaceCompareResultEx(g_LoginID, 0, &stFlag);
    if (m_lRealFaceCompareHandle > 0) {

        VideoNet_SetFaceCompareResultCallBack(m_lRealFaceCompareHandle, FaceCompareResultCallback, 0, (char *) "./");
        DBG("start etFaceCompareResultCallBack ok!\n");

        if (VideoNet_SetSubDisconnectCallBack(SubDisConnectCallBack, 0) != 1) {
            ERR("VideoNet_SetSubDisconnectCallBack ERROR!\n");
        }

        while (1) {
            sleep(6);
        }

        if (m_lRealFaceCompareHandle > 0) {
            VideoNet_StopReceiveFaceCompareResult(m_lRealFaceCompareHandle);
            VideoNet_DelFaceCompareResultCallBack(m_lRealFaceCompareHandle, FaceCompareResultCallback, 0);
            m_lRealFaceCompareHandle = -1;
        }

        DBG("start FaceCompareResultCallback OK!\n");

    } else {
        ERR("start FaceCompareResultCallback m_lRealFaceCompareHandle = %ld\n", m_lRealFaceCompareHandle);
        ERR("start FaceCompareResultCallback wrong!\n");
    }
}

void QueryHKUUID() {
    char uuid[4][16] = {"umks97tgh29f", "umksd8gxxr5v", "umksbhtsv6as", "umkse560pi9u"};
    char *puuid[4];
    for (int i = 0; i < 4; ++i) {
        puuid[i] = uuid[i];
    }
    //VideoNet_GetP2PLogData();
    VideoNet_InitQuerythread();
    VideoNet_StartQueryUUID(puuid, 4, FoundDevCB);
    while (1) {
        usleep(500 * 1000);
    }
}

int main(int argc, char *argv[]) {
    JVTLOGINTYPE logintype = lanlogin;
    char uuidip[16] = {0};
    JVTFUCTION function = FaceCompareResult;//FaceImageSnap;
    WBLIST_ACTION_TYPE weblisttype = OUT_INDEX;
    password.clear();
    password = "admin";
    BLUE_TRACE("such as ./demo_x86 logintype password IP function Facelisttype\n\n");
    WARNING_TRACE(
            "logintype=>   0:local login 1:P2P login 2:DAS register,this type no need input these three argument after\n\n");
    WARNING_TRACE("password=>   login password\n\n");
    WARNING_TRACE("IP=>when logintype is local login plesae input IPaddress,P2P login input UUID\n\n");
    WARNING_TRACE("function=>   JVTFUCTION:\n");
    WARNING_TRACE("0:RealPlay. 1:PLAYBACK_BYNAME. 2:PLAYBACK_BYNAME_V2. 3:PLAYBACK_BYTIME. 4:PLAYBACK_BYTIME_V2\n");
    WARNING_TRACE("5:JVTTALK. 6:JVTConfig. 7:ADDUSER. 8:FaceImageSnap. 9:FaceCompareResult\n");
    WARNING_TRACE("10:FaceWriteAndBlackList. 11:SearchDevice. 12:SearchDeviceV2. 13:P2PQUERY.\n\n");
    WARNING_TRACE("Facelisttype=>   WBLIST_ACTION_TYPE:\n");
    WARNING_TRACE("1:OUT_INDEX. 2:OUT_PICTURE. 3:OUT_PICTURE_COMP. 4:OUT_PICTURE_DEL\n");
    WARNING_TRACE("5:OUT_PICTURE_DELALL. 6:IN_PICTURE_ADD. 7:IN_PICTURE_ADD_SNAP.\n");
    WARNING_TRACE("8:IN_PICTURE_GET_FEATURE. 9:IN_INDEX_GET_FEATURE. 10:OUT_WBLIST_EN\n\n");
    if (argc < 6) {
        ERR("any arg is default\n");
    }
    sprintf(uuidip, "192.168.63.188");
    //sprintf(uuidip,"umkse5bbg3q9");
//	if(argc >= 2)
//	{
//		logintype = (JVTLOGINTYPE)atoi(argv[1]);
//	}
//	if(argc >= 3)
//	{
//		password = argv[2];
//	}
//	if(argc >= 4)
//	{
//		memset(uuidip,0,sizeof(uuidip));
//		memcpy(uuidip,argv[3],sizeof(uuidip));
//	}
//	if(argc >= 5)
//	{
//		function = (JVTFUCTION)atoi(argv[4]);
//	}
//	if(argc >= 6)
//	{
//		weblisttype = (WBLIST_ACTION_TYPE)atoi(argv[5]);
//	}

    g_pFile = NULL;
    VideoNet_Init(NULL, 1);
    CYAN_TRACE("VideoNet_Init:logintype=%d,password=%s,uuidip=%s,function=%d,weblisttype=%d\n", logintype,
               password.c_str(), uuidip, function, weblisttype);
    //QueryHKUUID();
    if (logintype == JVTDAS) {
        //一直阻塞在这里
        StartDASServer();
    } else if (StartLogin(logintype, uuidip) == 0) {
        goto CLEANUP;
    }
    DBG("**************login ok***************\n");
    switch (function) {
        case RealPlay: {
            StartRealPlay();
            break;
        }
        case PLAYBACK_BYNAME:
        case PLAYBACK_BYNAME_V2:
        case PLAYBACK_BYTIME:
        case PLAYBACK_BYTIME_V2: {
            StartPlayBack(function);
            break;
        }
        case JVTTALK: {
            StartTalk();
            break;
        }
        case JVTConfig: {
            StartConfig();
            break;
        }
        case ADDUSER: {
            StartAddUser();
            break;
        }
        case FaceImageSnap: {
            StartFaceImageSnap();
            break;
        }
        case FaceCompareResult: {
            StartFaceCompareResult();
            break;
        }
        case FaceWriteAndBlackList: {
            StartFaceWriteAndBlackList(weblisttype);
            break;
        }
        case SearchDevice: {
            StartSearchDevice();
            break;
        }
        case SearchDeviceV2: {
            VideoNet_SearchDevice_V2(pfNetComFun, 0, 5000);
            break;
        }
        case P2PQUERY: {
            QueryHKUUID();
            break;
        }
        case GPIOControl: {
            DBG("case GPIOControl\n");
            VideoNet_GPIOControl(g_LoginID, 9);
            break;
        }
        default:
            break;
    }

    if (logintype == JVTDAS) {
        DBG("VideoNet_StopActiveRigister before\n");
        VideoNet_StopActiveRigister();
        DBG("VideoNet_StopActiveRigister after\n");
    }

    while (1) {
        sleep(5);
    }

    if (g_LoginID > 0) {
        VideoNet_Logout(g_LoginID);
        DBG("Logout success!!!\n");
    }
    CLEANUP:
    VideoNet_Cleanup();
    DBG("VideoNet_Cleanup\n");
    if (g_pFile) {
        fclose(g_pFile);
        g_pFile = NULL;
    }
    DBG("**************OVER************\n");
    return 0;
}
