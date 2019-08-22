//
// Created by jdl on 18-4-28.
//

#include <cstdio>
#include <fstream>
#include <cstring>
#include "HCCamera.h"
#include "../tinyxml/tinyxml.h"
#include "HCNetSDK.h"
//#include <jemalloc/jemalloc.h>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <opencv2/opencv.hpp>

//获取时间
#define GET_YEAR(_time_)      (((_time_)>>26) + 2000)
#define GET_MONTH(_time_)     (((_time_)>>22) & 15)
#define GET_DAY(_time_)       (((_time_)>>17) & 31)
#define GET_HOUR(_time_)      (((_time_)>>12) & 31)
#define GET_MINUTE(_time_)    (((_time_)>>6)  & 63)
#define GET_SECOND(_time_)    (((_time_)>>0)  & 63)

bool LicenseSnapResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo) {

    NET_DVR_PLATE_RESULT strucPlateResult={0};
    memcpy(&strucPlateResult,pAlarmInfo,sizeof(strucPlateResult));
    printf("车牌号：%s\n",strucPlateResult.struPlateInfo.sLicense);

#if 0
    printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    NET_ITS_PLATE_RESULT struITSPlateResult = {0};
    memcpy(&struITSPlateResult, pAlarmInfo, sizeof(struITSPlateResult));

    string strIP = pAlarmer->sDeviceIP;

    //车牌信息
    char cLicens[16] = {0};

    //截取车牌信息，去除车牌颜色标识
    strncpy(cLicens, struITSPlateResult.struPlateInfo.sLicense + 2, 14);

    if (strlen(cLicens) == 4) {

        strcpy(cLicens, "无车牌");
        //logDebug(strIP + ":抓拍到无车牌图片,数据丢弃!");
        return true;
    }
  printf("qqqqqqqqqqqqqqqq\n");
    //获取车牌类型
    //车型识别：0- 未知，1- 客车(大型)，2- 货车(大型)，3- 轿车(小型)，4- 面包车，5- 小货车，6- 行人，7- 二轮车，8- 三轮车，
    // 9- SUV/MPV，10- 中型客车，11- 机动车，12- 非机动车，13- 小型轿车，14- 微型轿车，15- 皮卡车
    int nVehicleType = struITSPlateResult.byVehicleType;

    int nBkTag = -1;
    int nLicenseTag = -1;


    for (int i = 0; i < struITSPlateResult.dwPicNum; i++) {
        printf("");

        if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) &&
            (struITSPlateResult.struPicInfo[i].byType == 1) ||
            (struITSPlateResult.struPicInfo[i].byType == 2)) {

            //背景图片响应
            nBkTag = i;
            //获取时间

        }

        if ((struITSPlateResult.struPicInfo[i].dwDataLen != 0) &&
            (struITSPlateResult.struPicInfo[i].byType == 0)) {
            nLicenseTag = i;
        }
    }
     printf("qqqqqqqqqqqqqqqq\n");
    if (nBkTag != -1 && nLicenseTag != -1) {
        printf("eeeeeeeeeeeeeeeeeeeeee\n");

        logInfo(strIP + ":图像接收!");
        char cTempLicens[16] = {0};
        g2u(cLicens, 16, cTempLicens, 16);
        logInfo(cTempLicens);

        PLIST_BUFFER plistBuffer;
        //获取空队列
        g_pCarListThread->GetBuffer(&plistBuffer, empty);
        if (plistBuffer == nullptr) {
            //若空队列为空,获取满队列地址
            logDebug("The hk car data is full and the original data is discarded!");
            //g_pListThread->GetHeadBuffer(&plistBuffer, full);
            g_pCarListThread->GetBuffer(&plistBuffer, full);

        }
        printf("wwwwwwwwwwwwww\n");
        if (plistBuffer) {
            //相机抓拍时间
//            plistBuffer->camerasPic.tCameraTime = cur_car_picture["cameraTime"].GetInt64();
//
//            //车辆颜色 保留字段 暂无
//            plistBuffer->camerasPic.nLicense_car_color = cur_car_picture["carColor"].GetInt();
//
//            //车牌类型
//            plistBuffer->camerasPic.nLicense_plate_type = setPlateType(cur_car_picture["carType"].GetInt());
//
//            //车牌评分
//            plistBuffer->camerasPic.nFaceScore = cur_car_picture["confidenceScore"].GetInt();
//
//            //程序推送照片时间
//            plistBuffer->camerasPic.tProgramTime = cur_car_picture["createTime"].GetInt64();
//
//            //图片长度
//            plistBuffer->camerasPic.nBackgroundPicLen = cur_car_picture["imageFileBackPicLen"].GetInt();
//
//            //检查内存是否符合大小
//            g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);
//
//            //图片进行base64解码
//            CBase64 base64;
//            base64.Decode(cur_car_picture["imageFileBackPic"].GetString(),
//                          plistBuffer->camerasPic.pBackBuffer,
//                          &plistBuffer->camerasPic.nBackgroundPicLen);
//
//
//            //图片长度
//            plistBuffer->camerasPic.nFacePicLen = cur_car_picture["imageFragmentFileLen"].GetInt();
//
//            //检查内存是否符合大小
//            g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nFacePicLen, FACE_PIC_TAG, plistBuffer);
//
//            CBase64 base64;
//            //图片进行base64解码
//            base64.Decode(cur_car_picture["imageFragmentFile"].GetString(),
//                          plistBuffer->camerasPic.pFaceBuffer,
//                          &plistBuffer->camerasPic.nFacePicLen);
//
//
//            //IP地址
//            memcpy(plistBuffer->camerasPic.cCameraIP, strIP.c_str(), 16);
//
//            //车牌
//            memcpy(plistBuffer->camerasPic.cLicense_plate_num, cTempLicens, 16);
//
//            //车牌区域
//            NET_VCA_RECT net_vca_rect = struITSPlateResult.struPicInfo[nBkTag].struPlateRect;
            //int nX = int(g_nWidth * net_vca_rect.fX) * 2.3/2.5;
            //int nY = int(g_nHeight * net_vca_rect.fY) * 1.5;

//            int nX = int(g_nWidth * net_vca_rect.fX) * 0.92;
//            int nY = int(g_nHeight * net_vca_rect.fY) * 0.6;
//
//            //获取车牌横纵坐标
//            receive_pic->nX = nX;
//            receive_pic->nY = nY;

            //坐标区域
//            plistBuffer->camerasPic.sLicense_rect.nBottom = cur_car_rect["bottom"].GetInt();
//            plistBuffer->camerasPic.sLicense_rect.nLeft = cur_car_rect["left"].GetInt();
//            plistBuffer->camerasPic.sLicense_rect.nRight = cur_car_rect["right"].GetInt();
//            plistBuffer->camerasPic.sLicense_rect.nTop = cur_car_rect["top"].GetInt();
//
//            //车牌颜色
//            plistBuffer->camerasPic.nLicense_plate_color = setPlateColor(cur_car_picture["typeColor"].GetInt());
            //移到空队列
            g_pCarListThread->PutBuffer(plistBuffer, empty);
        }
        return true;


//
//        //车牌类型
//        receive_pic->nVehicleType = nVehicleType;
//
//        //获取相机绝对时间
//        memcpy(receive_pic->byAbsTime, (char *) struITSPlateResult.struPicInfo[nBkTag].byAbsTime, 32);
//
//        receive_pic->nBackgroundPicLen = struITSPlateResult.struPicInfo[nBkTag].dwDataLen;
//        //拷贝背景图片内存
//        receive_pic->pBuffer = (BYTE *) malloc(struITSPlateResult.struPicInfo[nBkTag].dwDataLen);
//        memcpy(receive_pic->pBuffer, struITSPlateResult.struPicInfo[nBkTag].pBuffer,
//               struITSPlateResult.struPicInfo[nBkTag].dwDataLen);
//
//        receive_pic->nBackgroundLPicLen = struITSPlateResult.struPicInfo[nLicenseTag].dwDataLen;
//        //拷贝车牌图片内存
//        receive_pic->pLicenseBuffer = (BYTE *) malloc(struITSPlateResult.struPicInfo[nLicenseTag].dwDataLen);
//        memcpy(receive_pic->pLicenseBuffer, struITSPlateResult.struPicInfo[nLicenseTag].pBuffer,
//               struITSPlateResult.struPicInfo[nLicenseTag].dwDataLen);
//
//        g_ReceiveQuery->OnPushBack(receive_pic);
//        logInfo(strIP + ":图像插入缓存队列!");

    }

    return false;

#endif

}

bool FaceSnapResult(const char *pAlarmInfo) {

    NET_VCA_FACESNAP_RESULT struFaceSnap = {0};
    memcpy(&struFaceSnap, pAlarmInfo, sizeof(NET_VCA_FACESNAP_RESULT));

    //背景图的图片数据
    if (struFaceSnap.dwBackgroundPicLen > 0 && struFaceSnap.pBuffer2 != NULL &&
        struFaceSnap.dwFaceScore >= MIN_FACE_SCORE) {


        //  接收图片写入日志
        char buf[100] = {0};
        sprintf(buf, "%s:picture receive!", struFaceSnap.struDevInfo.struDevIP.sIpV4);
        logInfo(buf);

        //获取时间
        NET_DVR_TIME struAbsTime = {0};

        struAbsTime.dwYear = GET_YEAR(struFaceSnap.dwAbsTime);
        struAbsTime.dwMonth = GET_MONTH(struFaceSnap.dwAbsTime);
        struAbsTime.dwDay = GET_DAY(struFaceSnap.dwAbsTime);
        struAbsTime.dwHour = GET_HOUR(struFaceSnap.dwAbsTime);
        struAbsTime.dwMinute = GET_MINUTE(struFaceSnap.dwAbsTime);
        struAbsTime.dwSecond = GET_SECOND(struFaceSnap.dwAbsTime);

        DVR_TIME dvrTime;
        memcpy(&dvrTime, &struAbsTime, sizeof(NET_DVR_TIME));

        //报警目标信息
        NET_VCA_TARGET_INFO struTargetInfo;
        struTargetInfo = struFaceSnap.struTargetInfo;

        //目标边界框
        NET_VCA_RECT sNetRect1 = struTargetInfo.struRect;

        PLIST_BUFFER plistBuffer;
        //获取空队列
        g_pListThread->GetBuffer(&plistBuffer, empty);
        if (plistBuffer == nullptr) {
            //若空队列为空,获取满队列地址
            logDebug("The hk face data is full and the original data is discarded!");
            //g_pListThread->GetHeadBuffer(&plistBuffer, full);
            g_pListThread->GetBuffer(&plistBuffer, full);
            //获取内存图片并保存
            SaveFaceFile(plistBuffer, HIKVISION);
        }
        if (plistBuffer) {
            plistBuffer->camerasPic.nCamerasType = HIKVISION;
            //相机时间戳
            plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);
            //图片长度
            plistBuffer->camerasPic.nBackgroundPicLen = struFaceSnap.dwBackgroundPicLen;
            //检查内存是否符合大小
            g_pListThread->CheckBuffer(struFaceSnap.dwBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);
            //拷贝图片内存
            memcpy(plistBuffer->camerasPic.pBackBuffer, struFaceSnap.pBuffer2, struFaceSnap.dwBackgroundPicLen);

            //IP地址
            memcpy(plistBuffer->camerasPic.cCameraIP, struFaceSnap.struDevInfo.struDevIP.sIpV4, 16);

            //人脸评分
            plistBuffer->camerasPic.nFaceScore = struFaceSnap.dwFaceScore;
            //获取告警区域坐标
            plistBuffer->camerasPic.sAlarmRect.fX = sNetRect1.fX;
            plistBuffer->camerasPic.sAlarmRect.fY = sNetRect1.fY;
            plistBuffer->camerasPic.sAlarmRect.fWidth = sNetRect1.fWidth;
            plistBuffer->camerasPic.sAlarmRect.fHeight = sNetRect1.fHeight;

            //插入缓存队列时间
            plistBuffer->camerasPic.tProgramTime = time(0);

            //放入满队列
            g_pListThread->PutBuffer(plistBuffer, full);
            //图片放入缓冲区，写入日志
            sprintf(buf, "%s:picture inster double list!", struFaceSnap.struDevInfo.struDevIP.sIpV4);
            logInfo(buf);

        }
        return true;

    }

    return false;
}

bool AcsAlarmResult(const NET_DVR_ALARMER *pAlarmer, const char *pAlarmInfo) {
    printf("ppppppppppppppppppp\n");
    NET_DVR_ACS_ALARM_INFO net_dvr_acs_alarm_info = {0};
    memcpy(&net_dvr_acs_alarm_info, pAlarmInfo, sizeof(NET_DVR_ACS_ALARM_INFO));

    //保存抓拍场景图片
    if (net_dvr_acs_alarm_info.dwPicDataLen > 0 && net_dvr_acs_alarm_info.pPicData != NULL) {
        //  接收图片写入日志
        char buf[100] = {0};
        sprintf(buf, "%s:picture receive!", pAlarmer->sDeviceIP);
        logInfo(buf);

        //获取时间
        DVR_TIME dvrTime;
        memcpy(&dvrTime, &net_dvr_acs_alarm_info.struTime, sizeof(NET_DVR_TIME));

        PLIST_BUFFER plistBuffer;
        //获取空队列
        g_pListThread->GetBuffer(&plistBuffer, empty);
        if (plistBuffer == nullptr) {
            //若空队列为空,获取满队列头地址
            logDebug("The hk acs data is full and the original data is discarded!");
            //g_pListThread->GetHeadBuffer(&plistBuffer, full);
            g_pListThread->GetBuffer(&plistBuffer, full);
            //获取内存图片并保存
            SaveFaceFile(plistBuffer, HIKVISION);
        }
        if (plistBuffer) {
            plistBuffer->camerasPic.nCamerasType = HIKVISION;
            //相机时间戳
            plistBuffer->camerasPic.tCameraTime = strTime2unix(dvrTime);

            //图片长度
            plistBuffer->camerasPic.nBackgroundPicLen = net_dvr_acs_alarm_info.dwPicDataLen;
            //检查内存是否符合大小
            g_pListThread->CheckBuffer(net_dvr_acs_alarm_info.dwPicDataLen, BAKE_PIC_TAG, plistBuffer);
            //拷贝图片内存
            memcpy(plistBuffer->camerasPic.pBackBuffer, net_dvr_acs_alarm_info.pPicData,
                   net_dvr_acs_alarm_info.dwPicDataLen);

            //IP地址
            memcpy(plistBuffer->camerasPic.cCameraIP, pAlarmer->sDeviceIP, 16);

            //人脸评分
            plistBuffer->camerasPic.nFaceScore = 70;
            //获取告警区域坐标
            plistBuffer->camerasPic.sAlarmRect.fX = 0;
            plistBuffer->camerasPic.sAlarmRect.fY = 0;
            plistBuffer->camerasPic.sAlarmRect.fWidth = 0;
            plistBuffer->camerasPic.sAlarmRect.fHeight = 0;

            //插入缓存队列时间
            plistBuffer->camerasPic.tProgramTime = time(0);
            //放入满队列
            g_pListThread->PutBuffer(plistBuffer, full);
            //图片放入缓冲区，写入日志
            sprintf(buf, "%s:picture inster double list!", pAlarmer->sDeviceIP);
            logInfo(buf);

        }
        return true;
    }
    return false;
}

HCCamera::HCCamera(const char *cCameraIP, const int nPort, const char *cUserName, const char *cPassword, const int nTag)
        : m_lUserID(-1),
          m_lHandle(-1),
          m_strCameraIP(cCameraIP),
          m_nPort(nPort),
          m_cUserName(cUserName),
          m_cPassword(cPassword) {
    printf("llllllllllllllllllll");

    SetCameraInit(OnInitCamera(cCameraIP, nPort, cUserName, cPassword, nTag));
}


HCCamera::~HCCamera() {

    if (m_lUserID < 0) {
        return;
    }
    //撤销布防上传通道
    if (!NET_DVR_CloseAlarmChan_V30(m_lHandle)) {
        char buf[100] = {0};
        sprintf(buf, "NET_DVR_CloseAlarmChan_V30 error, %d", NET_DVR_GetLastError());
        logError(buf);

        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return;
    }
    logDebug("Close alarm chan!");
    //注销用户
    NET_DVR_Logout(m_lUserID);
    logDebug("Log out!");
    //释放SDK资源
    NET_DVR_Cleanup();
    logDebug("Clean up SDK!");
}

bool
HCCamera::OnInitCamera(const char *cDeviceAddress, const WORD wPort, const char *cUserName, const char *cPassword,
                       const int nTag) {


    // 初始化
    NET_DVR_Init();
    ///设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);


    //---------------------------------------
    // 注册设备

    //登录参数，包括设备地址、登录用户、密码等
    NET_DVR_USER_LOGIN_INFO struLoginInfo = {0};
    struLoginInfo.bUseAsynLogin = 0; //同步登录方式
    strcpy(struLoginInfo.sDeviceAddress, cDeviceAddress); //设备IP地址
    struLoginInfo.wPort = wPort; //设备服务端口
    strcpy(struLoginInfo.sUserName, cUserName); //设备登录用户名
    strcpy(struLoginInfo.sPassword, cPassword); //设备登录密码

    //设备信息, 输出参数
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0};

    m_lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
    if (m_lUserID < 0) {
        char buf[100] = {0};
        sprintf(buf, "NET_DVR_Login_V40 errm_strCameraIPor, %d", NET_DVR_GetLastError());
        logError(buf);

        NET_DVR_Cleanup();
        return false;
    }

    if (nTag == FACE_CAP) {
        //获取门禁能力集
        bool isAcsAbility = GetAbility(ACS_ABILITY, "AcsAbility");
        if (isAcsAbility) {
            //表示有门禁配置参数，该相机为门禁设备
            //配置门禁参数
            if (!SetEntranceGuardCfg()) {
                logError("Entrance guard set error!");
                return false;
            }
        }

        //获取人脸抓拍能力集
        bool isFaceSnapc = GetAbility(DEVICE_ABILITY_INFO, "VcaChanAbility", "Face", "FaceSnap");


        if (isFaceSnapc) {
            //获取人脸抓拍配置信息
            GetDVRFaceSnapConfig();
        }
    } else if (nTag == CAR_CAP) {
        //车牌抓拍
        //设置网络抓拍
        printf("=================\n");
        OnContinuousShoot();
    }


    //启用布防
    if (!OnSetupAlarmChan()) {
        return false;
    }
    //将登录信息保存
    g_CameraIDAndIP.insert(make_pair(m_lUserID, m_strCameraIP));

    logInfo("Camera init success！");

    DWORD t=NET_DVR_GetSDKBuildVersion();
    printf("version =%x\n",t);
    return true;
}

bool HCCamera::OnContinuousShoot() {

    //---------------------------------------
    //网络触发抓拍

    NET_DVR_SNAPCFG struSnapCfg;
    memset(&struSnapCfg, 0, sizeof(NET_DVR_SNAPCFG));

    //结构体大小
    struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);

    //线圈抓拍次数，0-不抓拍，非0-连拍次数，目前最大5次
    struSnapCfg.bySnapTimes = 3;

    //抓拍等待时间，单位ms，取值范围[0,60000]
    struSnapCfg.wSnapWaitTime = 1000;

    //连拍间隔时间，单位ms，取值范围[67,60000]
    struSnapCfg.wIntervalTime[0] = 1000;
    struSnapCfg.wIntervalTime[1] = 1000;

    //触发IO关联的车道号，取值范围[0,9]
    struSnapCfg.byRelatedDriveWay = 0;

    //网络触发连拍
    if (!NET_DVR_ContinuousShoot(m_lUserID, &struSnapCfg)) {

        char buf[100] = {0};
        sprintf(buf, "网络触发连拍:NET_DVR_ContinuousShoot error, %d", NET_DVR_GetLastError());
        logError(buf);

        return 0;
    }


    logDebug("网络触发连拍成功!");

}

bool HCCamera::SetEntranceGuardCfg() {
    //配置触发抓拍参数
    NET_DVR_SNAPCFG struSnapCfg = {0};
    struSnapCfg.dwSize = sizeof(NET_DVR_SNAPCFG);
    struSnapCfg.bySnapTimes = 1;//抓拍次数:0-不抓拍,非 0-连拍次数,目前最大 5 次
    struSnapCfg.wIntervalTime[0] = 0;//连拍间隔时间,单位 ms,取值范围[67,60000]
    struSnapCfg.struJpegPara.wPicSize = 163;//图片分辨率:0-CIF(352*288/352*240) 163-480*640
    if (!NET_DVR_ContinuousShoot(m_lUserID, &struSnapCfg)) {
        logError("NET_DVR_ContinuousShoot error:" + to_string(NET_DVR_GetLastError()));
        NET_DVR_CloseAlarmChan_V30(m_lHandle);
        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return false;
    }

    //---------------------------------------
    //事件及卡号联动参数设置
    NET_DVR_EVENT_CARD_LINKAGE_COND struEventCardLinkageCond = {0};
    struEventCardLinkageCond.dwSize = sizeof(NET_DVR_EVENT_CARD_LINKAGE_COND);
    struEventCardLinkageCond.dwEventID = 1;//事件 ID,从 1 开始,设置不同的事件/卡号联动配置时依次递增即可
    NET_DVR_EVENT_CARD_LINKAGE_CFG_V50 struEventCardLinkageCfgV50 = {0};
    struEventCardLinkageCfgV50.dwSize = sizeof(NET_DVR_EVENT_CARD_LINKAGE_CFG_V50);
    struEventCardLinkageCfgV50.byProMode = 0;//联动方式:0-事件,1-卡号
    struEventCardLinkageCfgV50.byCapturePic = 1;//是否联动抓拍:0-不联动抓拍,1-联动抓拍
    //事件源 ID,0xffffffff 表示联动全部,其他取值:当主类型为设备事件时无效;当主类型是为门事件时,为门编号;
    //当主类型为读卡器事件时,为读卡器 ID;当主类型为报警输入事件时,为防区报警输入 ID 或事件报警输入 ID
    struEventCardLinkageCfgV50.dwEventSourceID = 0xffffffff;

    //联动事件主类型:0-设备事件,1-报警输入事件,2-门事件,3-读卡器事件
    struEventCardLinkageCfgV50.uLinkageInfo.struEventLinkage.wMainEventType = 2;
    //联动事件次类型:10-正常开门(门磁),这里以开门联动抓拍为例
    struEventCardLinkageCfgV50.uLinkageInfo.struEventLinkage.wSubEventType = 10;
    DWORD dwStatus = 0;
    if (!NET_DVR_SetDeviceConfig(m_lUserID, NET_DVR_SET_EVENT_CARD_LINKAGE_CFG_V50,
                                 1, &struEventCardLinkageCond, sizeof(struEventCardLinkageCond), &dwStatus,
                                 &struEventCardLinkageCfgV50, sizeof(struEventCardLinkageCfgV50))) {
        logError("NET_DVR_SET_EVENT_CARD_LINKAGE_CFG_V50 error:" + to_string(NET_DVR_GetLastError()));
        return false;
    }

    //---------------------------------------
    //门禁主机参数设置
    NET_DVR_ACS_CFG struAcsCfg = {0};
    struAcsCfg.dwSize = sizeof(NET_DVR_ACS_CFG);
    struAcsCfg.byUploadCapPic = 1;//联动抓拍是否上传图片:0-不上传,1-上传
    BOOL bRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_ACS_CFG, 0, &struAcsCfg, sizeof(struAcsCfg));
    if (!bRet) {
        logError("NET_DVR_SET_ACS_CFG error:" + to_string(NET_DVR_GetLastError()));
        return false;
    }
    return true;
}

bool HCCamera::GetAbility(const DWORD dwAbilityType, const char *cAbility, const char *cElem, const char *cElem1) {

    try {

        char cInBuf[1024] = {0};

        switch (dwAbilityType) {
            case DEVICE_ABILITY_INFO: {
                if (cElem1 == nullptr) {
                    sprintf(cInBuf, "<EventAbility version='2.0'><channelNO>%d</channelNO></EventAbility >", 1);
                } else {
                    sprintf(cInBuf, "<VcaChanAbility version='2.0'><channelNO>%d</channelNO></VcaChanAbility >", 1);
                }
            }
                break;
            case ACS_ABILITY: {
                const char *cAbility = R"(<AcsAbility version="2.0"></AcsAbility>)";
                memcpy(cInBuf, cAbility, strlen(cAbility));
            }
                break;
            default:
                break;
        }


        char *cOutBuf = new char[XML_BUF];
        TiXmlDocument tiXmlDocument;
        string strChildText = "";
        TiXmlElement *ele;
        TiXmlElement *eleSecond;
        TiXmlElement *eleThird;

        //获取设备能力集
        if (!NET_DVR_GetDeviceAbility(m_lUserID, dwAbilityType, cInBuf, (DWORD) strlen(cInBuf), cOutBuf,
                                      XML_BUF)) {
            DWORD dError = NET_DVR_GetLastError();
            logError("NET_DVR_GetDeviceAbility error:" + to_string(dError));
            goto XML_ERROR;
        }


        tiXmlDocument.Parse(cOutBuf);
        if (cOutBuf != nullptr) {
            ele = tiXmlDocument.FirstChildElement(cAbility);
            if (!ele) {
                goto XML_ERROR;
            }
        }

        if (cElem != nullptr) {
            eleSecond = ele->FirstChildElement(cElem);
            if (!eleSecond) {
                goto XML_ERROR;
            }
        }

        if (cElem1 != nullptr) {
            eleThird = eleSecond->FirstChildElement(cElem1);
            if (!eleThird) {
                goto XML_ERROR;
            }
        }

        //删除指针
        if (cOutBuf) {
            delete[] cOutBuf;
            cOutBuf = nullptr;
        }
        return true;
        XML_ERROR:
        //删除指针
        if (cOutBuf) {
            delete[] cOutBuf;
            cOutBuf = nullptr;
        }
        return false;
    } catch (const std::exception &e) {
        logError(e.what());
        return false;
    }


}

void HCCamera::GetDVRFaceSnapConfig() {
    NET_VCA_FACESNAPCFG sNetFaceSnapcfg;

    DWORD dwReturned = 0;
    //获取设备的配置信息
    if (!NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_FACESNAPCFG, 1, &sNetFaceSnapcfg, sizeof(NET_VCA_FACESNAPCFG),
                              &dwReturned)) {
        logError("NET_DVR_GetDVRConfig error," + to_string(NET_DVR_GetLastError()));
        return;
    }


//    //单个目标人脸的抓拍次数，取值范围：0~10，上传评分最高的一张
//    BYTE bySnapTime = sNetFaceSnapcfg.bySnapTime;
//
//    //抓拍间隔，单位：帧
//    BYTE bySnapInterval = sNetFaceSnapcfg.bySnapInterval;
//
//    //抓拍阈值，取值范围：0-100
//    BYTE bySnapThreshold = sNetFaceSnapcfg.bySnapThreshold;
//
//    //目标生成速度，取值范围：[1, 5]
//    BYTE byGenerateRate = sNetFaceSnapcfg.byGenerateRate;
//
//    //目标检测灵敏度，取值范围：[1, 5]
//    BYTE bySensitive = sNetFaceSnapcfg.bySensitive;
//
//    //参考亮度，取值范围：[0,100]
//    BYTE byReferenceBright = sNetFaceSnapcfg.byReferenceBright;
//
//    //比对报警模式：0-目标消失后报警，1-实时报警
//    BYTE byMatchType = sNetFaceSnapcfg.byMatchType;
//
//    //实时比对阈值，取值范围：0~100
//    BYTE byMatchThreshold = sNetFaceSnapcfg.byMatchThreshold;

    //图片规格结构（图片分辨率和图片质量）

    /*wPicSize
    图片尺寸：0-CIF(352*288/352*240)，1-QCIF(176*144/176*120)，2-4CIF(704*576/704*480)或D1(720*576/720*486)，
     3-UXGA(1600*1200)， 4-SVGA(800*600)，5-HD720P(1280*720)，6-VGA(640*480)，7-XVGA(1280*960)，8-HD900P(1600*900)，
     9-HD1080P(1920*1080)，10-2560*1920， 11-1600*304，12-2048*1536，13-2448*2048，14-2448*1200，15-2448*800，
     16-XGA(1024*768)，17-SXGA(1280*1024)，18-WD1(960*576/960*480), 19-1080I(1920*1080)，20-576*576，21-1536*1536，
     22-1920*1920，23-320*240，24-720*720，25-1024*768，26-1280*1280，27-1600*600， 28-2048*768，29-160*120，
     75-336*256，78-384*256，79-384*216，80-320*256，82-320*192，83-512*384，127-480*272，128-512*272，
     161-288*320，162-144*176，163-480*640，164-240*320，165-120*160，166-576*720，167-720*1280，168-576*960，180-180*240,
     181-360*480, 182-540*720, 183-720*960, 184-960*1280, 185-1080*1440, 500-384*288, 0xff-Auto(使用当前码流分辨率)
    wPicQuality
    图片质量系数：0-最好，1-较好，2-一般*/

    NET_DVR_JPEGPARA struPictureParam = sNetFaceSnapcfg.struPictureParam;
    WORD wPicSize = struPictureParam.wPicSize;

    //人脸抓拍规则
    for (int i = 0; i < MAX_RULE_NUM; i++) {
        NET_VCA_SINGLE_FACESNAPCFG struRule = sNetFaceSnapcfg.struRule[i];
        //是否激活规则：0- 否，1- 是
        BYTE byActive = struRule.byActive;

        //人脸自动ROI开关使能：0- 关闭，1- 开启
        BYTE byAutoROIEnable = struRule.byAutoROIEnable;

        //尺寸过滤器参数结构体
        /*byActive
        是否激活尺寸过滤器，0-否 ，非0-是
        byMode
        过滤器模式，具体定义如下：
        enum _VCA_SIZE_FILTER_MODE_{
          IMAGE_PIX_MODE,
          REAL_WORLD_MODE,
          DEFAULT_MODE
        }SIZE_FILTER_MODE
        IMAGE_PIX_MODE
        根据像素大小设置
        REAL_WORLD_MODE
        根据实际大小设置
        DEFAULT_MODE
        默认模式(目前ATM支持)
        byRes
        保留，置为0
        struMiniRect
        最小目标框，全0表示不设置（瞳距）。实际模式时取值范围为0~50，单位为m。
        struMaxRect
        最大目标框，全0表示不设置*/
        NET_VCA_SIZE_FILTER struSizeFilter = struRule.struSizeFilter;

        //多边形结构体
        /*dwPointNum
        有效点（大于等于3），若是3点在一条线上认为是无效区域，线交叉认为是无效区域
        struPos
        多边形边界点，最大值为10*/
        NET_VCA_POLYGON struVcaPolygon = struRule.struVcaPolygon;
    }


    //人脸曝光最短持续时间，单位：秒，范围：1~3600，默认：60
    WORD wFaceExposureMinDuration = sNetFaceSnapcfg.wFaceExposureMinDuration;

    //人脸曝光使能：1- 关闭，2- 开启，0- 自动（根据人脸判断）
    BYTE byFaceExposureMode = sNetFaceSnapcfg.byFaceExposureMode;

    //背景图上传使能：0- 默认值（开启），1- 禁止
    BYTE byBackgroundPic = sNetFaceSnapcfg.byBackgroundPic;

    //有效人脸最短持续时间，单位：秒
    DWORD dwValidFaceTime = sNetFaceSnapcfg.dwValidFaceTime;

    //人脸抓拍统计数据上传间隔时间，单位：秒，默认为900秒
    DWORD dwUploadInterval = sNetFaceSnapcfg.dwUploadInterval;

    //人脸停留时间过滤，取值范围：0~100，单位：秒，默认为5秒，0秒表示不过滤
    DWORD dwFaceFilteringTime = sNetFaceSnapcfg.dwFaceFilteringTime;

    //设置人脸抓拍配置信息
    SetDVRFaceSnapConfig(sNetFaceSnapcfg);
}

bool HCCamera::SetDVRFaceSnapConfig(NET_VCA_FACESNAPCFG sNetFaceSnapcfg) {
    //获取结构体大小
    DWORD dwSize = sNetFaceSnapcfg.dwSize;

    //单个目标人脸的抓拍次数，取值范围：0~10，上传评分最高的一张
    sNetFaceSnapcfg.bySnapTime = 1;

    //抓拍间隔，单位：帧
    sNetFaceSnapcfg.bySnapInterval = 1;

    //抓拍阈值，取值范围：0-100
//    sNetFaceSnapcfg.bySnapThreshold = 80;

    //目标生成速度，取值范围：[1, 5]
    sNetFaceSnapcfg.byGenerateRate = 3;

    //目标检测灵敏度，取值范围：[1, 5]
    sNetFaceSnapcfg.bySensitive = 3;

    //参考亮度，取值范围：[0,100]
    sNetFaceSnapcfg.byReferenceBright = 50;

    //比对报警模式：0-目标消失后报警，1-实时报警
    sNetFaceSnapcfg.byMatchType = 1;

    //实时比对阈值，取值范围：0~100
    sNetFaceSnapcfg.byMatchThreshold = 0;

    //图片规格结构（图片分辨率和图片质量）

    /*wPicSize
    图片尺寸：0-CIF(352*288/352*240)，1-QCIF(176*144/176*120)，2-4CIF(704*576/704*480)或D1(720*576/720*486)，
     3-UXGA(1600*1200)， 4-SVGA(800*600)，5-HD720P(1280*720)，6-VGA(640*480)，7-XVGA(1280*960)，8-HD900P(1600*900)，
     9-HD1080P(1920*1080)，10-2560*1920， 11-1600*304，12-2048*1536，13-2448*2048，14-2448*1200，15-2448*800，
     16-XGA(1024*768)，17-SXGA(1280*1024)，18-WD1(960*576/960*480), 19-1080I(1920*1080)，20-576*576，21-1536*1536，
     22-1920*1920，23-320*240，24-720*720，25-1024*768，26-1280*1280，27-1600*600， 28-2048*768，29-160*120，
     75-336*256，78-384*256，79-384*216，80-320*256，82-320*192，83-512*384，127-480*272，128-512*272，
     161-288*320，162-144*176，163-480*640，164-240*320，165-120*160，166-576*720，167-720*1280，168-576*960，180-180*240,
     181-360*480, 182-540*720, 183-720*960, 184-960*1280, 185-1080*1440, 500-384*288, 0xff-Auto(使用当前码流分辨率)
    wPicQuality
    图片质量系数：0-最好，1-较好，2-一般*/
    // 	NET_DVR_JPEGPARA  struPictureParam;
    // 	sNetFaceSnapcfg.struPictureParam = struPictureParam;

    //人脸抓拍规则
    // 	for (int i = 0; i<MAX_RULE_NUM; i++)
    // 	{
    // 		NET_VCA_SINGLE_FACESNAPCFG struRule;
    //
    // 		//是否激活规则：0- 否，1- 是
    // 		struRule.byActive = 1;
    //
    // 		//人脸自动ROI开关使能：0- 关闭，1- 开启
    // 		struRule.byAutoROIEnable = 1;
    //
    // 		//尺寸过滤器参数结构体
    // 		/*byActive
    //       是否激活尺寸过滤器，0-否 ，非0-是
    //            byMode
    //            过滤器模式，具体定义如下：
    //            enum _VCA_SIZE_FILTER_MODE_{
    //                IMAGE_PIX_MODE,
    //                REAL_WORLD_MODE,
    //                DEFAULT_MODE
    //            }SIZE_FILTER_MODE
    //            IMAGE_PIX_MODE
    //                    根据像素大小设置
    //            REAL_WORLD_MODE
    //                    根据实际大小设置
    //            DEFAULT_MODE
    //            默认模式(目前ATM支持)
    //            byRes
    //            保留，置为0
    //                    struMiniRect
    //            最小目标框，全0表示不设置（瞳距）。实际模式时取值范围为0~50，单位为m。
    //            struMaxRect
    //            最大目标框，全0表示不设置*/
    // 		NET_VCA_POLYGON struVcaPolygon;
    // 		struRule.struVcaPolygon = struVcaPolygon;
    // 	}


    //人脸曝光最短持续时间，单位：秒，范围：1~3600，默认：60
    sNetFaceSnapcfg.wFaceExposureMinDuration = 60;

    //人脸曝光使能：1- 关闭，2- 开启，0- 自动（根据人脸判断）
    sNetFaceSnapcfg.byFaceExposureMode = 0;

    //背景图上传使能：0- 默认值（开启），1- 禁止
    sNetFaceSnapcfg.byBackgroundPic = 0;

    //有效人脸最短持续时间，单位：秒
    sNetFaceSnapcfg.dwValidFaceTime = 0;

    //人脸抓拍统计数据上传间隔时间，单位：秒，默认为900秒
    sNetFaceSnapcfg.dwUploadInterval = 0;

    //人脸停留时间过滤，取值范围：0~100，单位：秒，默认为5秒，0秒表示不过滤
    sNetFaceSnapcfg.dwFaceFilteringTime = 0;

    //设置设备的配置信息
    if (!NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_FACESNAPCFG, 1, &sNetFaceSnapcfg, dwSize)) {
        logError("NET_DVR_SetDVRConfig error," + to_string(NET_DVR_GetLastError()));
        return false;
    }
    return true;
}

void HCCamera::GetDVRFaceDetect() {
    // 	NET_DVR_CHANNEL_GROUP sNetChannelGroup;
    // 	NET_DVR_DETECT_FACE sNetDetectFace;
    //
    // 	DWORD dwReturned = 0;
    // 	//????????×???????
    // 	if (!NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_FACE_DETECT, 1, &sNetChannelGroup, sizeof(NET_DVR_CHANNEL_GROUP),
    // 		&sNetDetectFace, sizeof(NET_DVR_DETECT_FACE))
    // 	{
    // 		printf("NET_DVR_GetDVRConfig error, %d\n", NET_DVR_GetLastError());
    // 		return;
    // 	}
}

bool HCCamera::OnSetupAlarmChan() {
    //启用布防
    NET_DVR_SETUPALARM_PARAM struAlarmParam = {0};
    struAlarmParam.dwSize = sizeof(struAlarmParam);
    //struAlarmParam.byFaceAlarmDetection = 1; //人脸侦测抓图,上传COMM_ALARM_FACE_DETECTION类型报警信息
    struAlarmParam.byFaceAlarmDetection = 0; //人脸抓拍报警，上传COMM_UPLOAD_FACESNAP_RESULT类型报警信息

    //其他报警布防参数不需要设置，不支持

    m_lHandle = NET_DVR_SetupAlarmChan_V41(m_lUserID, &struAlarmParam);
    if (m_lHandle < 0) {

        char buf[100] = {0};
        sprintf(buf, "NET_DVR_SetupAlarmChan_V41 error, %d", NET_DVR_GetLastError());
        logError(buf);

        NET_DVR_Logout(m_lUserID);
        NET_DVR_Cleanup();
        return false;
    }

    logDebug("Setup alarm chan success!");
    return true;
}


void HCCamera::FacedetectAlarm(char *pAlarmInfo) {
    NET_DVR_FACEDETECT_ALARM struFaceDetectAlarm = {0};
    memcpy(&struFaceDetectAlarm, pAlarmInfo, sizeof(NET_DVR_FACEDETECT_ALARM));

    //绝对时标
    NET_DVR_TIME struAbsTime = {0};
    struAbsTime.dwYear = GET_YEAR(struFaceDetectAlarm.dwAbsTime);
    struAbsTime.dwMonth = GET_MONTH(struFaceDetectAlarm.dwAbsTime);
    struAbsTime.dwDay = GET_DAY(struFaceDetectAlarm.dwAbsTime);
    struAbsTime.dwHour = GET_HOUR(struFaceDetectAlarm.dwAbsTime);
    struAbsTime.dwMinute = GET_MINUTE(struFaceDetectAlarm.dwAbsTime);
    struAbsTime.dwSecond = GET_SECOND(struFaceDetectAlarm.dwAbsTime);
}


void HCCamera::FaceDetereconnCameraction(char *pAlarmInfo) {
    NET_DVR_FACE_DETECTION struFaceDetection = {0};
    memcpy(&struFaceDetection, pAlarmInfo, sizeof(NET_DVR_FACE_DETECTION));

    //绝对时标
    NET_DVR_TIME struAbsTime1 = {0};
    struAbsTime1.dwYear = GET_YEAR(struFaceDetection.dwAbsTime);
    struAbsTime1.dwMonth = GET_MONTH(struFaceDetection.dwAbsTime);
    struAbsTime1.dwDay = GET_DAY(struFaceDetection.dwAbsTime);
    struAbsTime1.dwHour = GET_HOUR(struFaceDetection.dwAbsTime);
    struAbsTime1.dwMinute = GET_MINUTE(struFaceDetection.dwAbsTime);
    struAbsTime1.dwSecond = GET_SECOND(struFaceDetection.dwAbsTime);

    //±??°?????€??????0±í?????????????ó??0±í????????
    DWORD dwBackgroundPicLen = struFaceDetection.dwBackgroundPicLen;

    //?°???è±???????°ü??IP????????????????
    NET_VCA_DEV_INFO struDevInfo = struFaceDetection.struDevInfo;

    //????×??????ò???é?????????à?????ó????±??°??)??·?±???
    for (int i = 0; i < MAX_FACE_PIC_NUM; i++) {
        NET_VCA_RECT struFacePic = struFaceDetection.struFacePic[i];
    }

    //×???????
    BYTE byFacePicNum = struFaceDetection.byFacePicNum;

    //??NET_VCA_DEV_INFO????byIvmsChannel?????à??????±í???ü?ó???????????§????byIvmsChannel????????????????×??ó??255???????§??°?±???????wDevInfoIvmsChannelEx
    WORD wDevInfoIvmsChannelEx = struFaceDetection.wDevInfoIvmsChannelEx;

    //±??°????????????
    BYTE *pBackgroundPicpBuffer = struFaceDetection.pBackgroundPicpBuffer;

    //±???×???????????
    if (dwBackgroundPicLen > 0 && struFaceDetection.pBackgroundPicpBuffer != NULL) {
//        char cFilename[256] = { 0 };
//        //WCHAR wcFilename[256] = { 0 };
//
//        HANDLE hFile;
//        DWORD dwReturn;
//
//        char chTime[128];
//        sprintf(chTime, "%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d", struAbsTime1.dwYear, struAbsTime1.dwMonth, struAbsTime1.dwDay, struAbsTime1.dwHour, struAbsTime1.dwMinute, struAbsTime1.dwSecond);
//
//        sprintf(cFilename, "FacePic[%s][%s].jpg", struDevInfo.struDevIP.sIpV4, chTime);
//
//        memset(wcFilename, 0, sizeof(wcFilename));
//        MultiByteToWideChar(CP_ACP, 0, cFilename, (int)strlen(cFilename) + 1, wcFilename, sizeof(wcFilename) / sizeof(wcFilename[0]));
//
//        hFile = CreateFile(wcFilename, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//        if (hFile == INVALID_HANDLE_VALUE)
//        {
//            return;
//        }
//        WriteFile(hFile, struFaceDetection.pBackgroundPicpBuffer, dwBackgroundPicLen, &dwReturn, NULL);
//        CloseHandle(hFile);
//        hFile = INVALID_HANDLE_VALUE;
    }
}