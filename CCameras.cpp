//
// Created by HXD on 18-5-4.
//
#include "global.h"
#include "CCameras.h"
#include <boost/filesystem/operations.hpp>
#include <dirent.h>
#include "hikvision/HCCamera.h"
#include "dahua/DHCamera.h"
#include "jvt/JVTCamera.h"
#include "kuangshi/KSCamera.h"
#include  "NETDEV/NetDev.h"

extern string pathcamt;
BOOL CALLBACK fMessageCallback(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void *pUser) {
    switch (lCommand) {
        case COMM_ALARM_FACE: //人脸检测
            break;
        case COMM_UPLOAD_FACESNAP_RESULT: //人脸抓拍
        {
            FaceSnapResult(pAlarmInfo);
        }
            break;
        case COMM_ALARM_FACE_DETECTION: //人脸侦测
            break;
        case COMM_SNAP_MATCH_ALARM: //人脸对比
            break;
        case COMM_ALARM_ACS: {
            AcsAlarmResult(pAlarmer, pAlarmInfo);
        }

            break;
        case COMM_ITS_PLATE_RESULT: {
            LicenseSnapResult(pAlarmer, pAlarmInfo);

            break;
        }
        default:
            char buf[100] = {0};
            sprintf(buf, "Other exception,type:0x%x", lCommand);
            logError(buf);
            break;
    }

    return TRUE;
}


//接收异常消息的回调函数的外部实现g_strSavePictureSrc
void CALLBACK ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser) {
    //获取相机对象指针
    CCameras *pCameras = (CCameras *) pUser;
    string strIP = g_CameraIDAndIP[lUserID];
    //logError(strIP);
    switch (dwType) {
        case EXCEPTION_EXCHANGE:            //用户交互时异常（注册心跳超时，心跳间隔为2分钟）
        {
            logWarn("XXXXXX" + strIP +
                    "Exception exchange(heartbeat timeout, heartbeat interval of 2 minutes)!!!XXXXXXX");
            pCameras->send_camera_state(strIP, false);
        }
            break;
        case EXCEPTION_ALARM:            //报警上传时网络异常
            logWarn("XXXXXXXX" + strIP + "Exception alarm!!!XXXXXXXX");
            //TODO: 关闭报警上传
            break;
        case EXCEPTION_PREVIEW:            //网络预览时异常
            logWarn("XXXXXXXX" + strIP + "Exception preview!!!XXXXXXXX");
            //TODO: 关闭网络预览
            break;
        case EXCEPTION_RECONNECT:            //预览时重连
            logWarn("XXXXXXXX" + strIP + "Exception reconnect!!!XXXXXXXX");
            break;
        case EXCEPTION_RELOGIN:             //用户重登了
            logWarn("XXXXXXXX" + strIP + "User relogin!!XXXXXXXX!");
            break;
        case RELOGIN_SUCCESS:               //用户重登陆成功
        {
            logWarn("XXXXXXXX" + strIP + "User relogin successful!!!XXXXXXXX");
            pCameras->send_camera_state(strIP, true);
        }
            break;
        case RESUME_EXCHANGE:               //用户交互恢复OnSetCameras
            logWarn("XXXXXXXX" + strIP + "User resume exchange!!!XXXXXXXX");
            break;
        case EXCEPTION_ALARMRECONNECT:      //报警重连
            logWarn("XXXXXXXX" + strIP + "Exception alarm reconnect!!!XXXXXXXX");
            break;
        case ALARM_RECONNECTSUCCESS:        //报警重连成功
            logWarn("XXXXXXXX" + strIP + "Alarm reconnect with success!!!XXXXXXXX");
            break;
        default: {
            char buf[100] = {0};            //其它异常信息
            sprintf(buf, "XXXXXXXX%sOther exception:0x%xXXXXXXXX", strIP.c_str(), dwType);
            logError(buf);
            break;
        }

    }
};


CCameras::CCameras(SendQueue *pSendQueue) : m_pSendQueue(pSendQueue) {

    OnInitCameras();
}

CCameras::~CCameras() {

    m_isRun = false;
    m_thread.join();
    m_threadTime.join();
    //注销相机
    OnDestoryCameras();

    if (m_pReceiveCar) {
        delete m_pReceiveCar;
        m_pReceiveCar = nullptr;
    }

}

void CCameras::send_camera_state(string strIP, bool isState) {
    PictureProtocol::CameraStatusList cameraStatusList;
    PictureProtocol::Head head;

    uint64 nID = g_CameraIP[strIP];
    PictureProtocol::CameraStatus *cameraStatus = cameraStatusList.add_camerastatus();
    cameraStatus->set_camera_id(nID);
    cameraStatus->set_status(isState);

    head.set_message_size(cameraStatusList.ByteSize());
    head.set_message_type(PictureProtocol::MessageType::CAMERA_STATUS_MESSAGE);

    //m_pSendQueue->SendMsg(head.SerializeAsString() + cameraStatusList.SerializeAsString());
}

void CCameras::OnDestoryCameras() {
    //释放指针
    for (auto iter = m_CameraMap.begin(); iter != m_CameraMap.end(); iter++) {
        CAMERA_MSG *camera_msg = iter->second;
        void *pCamera = camera_msg->pCamera;

        if (camera_msg->nTag == HIKVISION) {
            //获取海康函数指针
            HCCamera *hCamera = (HCCamera *) pCamera;
            if (hCamera) {
                delete hCamera;
                hCamera = nullptr;
            }
        } else if (camera_msg->nTag == DAHUA) {
            DHCamera *dhCamera = (DHCamera *) pCamera;
            if (dhCamera) {
                delete dhCamera;
                dhCamera = nullptr;
            }
        } else if (camera_msg->nTag == JVT || camera_msg->nTag == BEARHUNTING) {
            JVTCamera *jvtCamera = (JVTCamera *) pCamera;
            if (jvtCamera) {
                delete jvtCamera;
                jvtCamera = nullptr;
            }
        } else if (camera_msg->nTag == KUANGSHI) {
            KSCamera *ksCamera = (KSCamera *) pCamera;
            if (ksCamera) {
                delete ksCamera;
                ksCamera = nullptr;
            }
        }else if(camera_msg->nTag ==NETDEV){
            NetDevCamera *Netdevcamera=(NetDevCamera *)pCamera;
            if(Netdevcamera){
                delete Netdevcamera;
                Netdevcamera= nullptr;
            }

        }

        if (camera_msg) {
            delete camera_msg;
            camera_msg = nullptr;
        }
    }
    //清空map
    m_CameraMap.clear();
    g_CameraIP.clear();
    g_CameraIDAndIP.clear();
}

//设置文件监听线程
void CCameras::listen_file_changed() {
    long latest_modify_time = 0;
  /*  //获取用户主目录
    char *cPath = getenv("HOME");
    string strPath = cPath;

    //创建图片保存文件夹
    string strFacePicture = strPath + "/face_picture";
    //创建logs文件夹*/
    string strFacePicture=pathcamt;
    boost::filesystem::path filePath(strFacePicture);   //初始化

    //查询文件夹是否存在,若不存在，则创建
    if (!boost::filesystem::exists(strFacePicture)) {

        boost::filesystem::create_directories(strFacePicture);
    }

    g_strSavePictureSrc = strFacePicture;
    //读取json文件
    string strPath=strFacePicture;
    strPath += "/cameras.json";
    while (m_isRun) {
        struct stat buf;
        stat(strPath.c_str(), &buf);
        long modify_time = buf.st_mtime; //latest modification time (seconds passed from 01/01/00:00:00 1970 UTC)
        if (latest_modify_time != modify_time) {
            logDebug("File change to reread configuration information!");
            latest_modify_time = modify_time;
            //注销相机
            OnDestoryCameras();
            //查询json文件,加载相机信息
            OnGetJsonMsg(strPath);

            static bool isInitCameras = true;
            if (isInitCameras) {
                //表示加载相机完成,只用初始化加载一次
                isInitCameras = false;
                //获取图片文件
                getFiles();
            }
        }
        sleep(1);
    }
}

void CCameras::listen_dahua_cameras() {
    while (m_isRun) {
        time_t t = time(NULL);
        //检查是否存在超时数据,若存在,则删除
        for (auto iter = g_pUselistBuffer.begin(); iter != g_pUselistBuffer.end(); iter++) {
            logWarn(to_string(iter->first));
            if (iter->second.nTimer < t) {
                string strID = to_string(iter->first);
                logWarn(strID + ":recovery!!!");
                //放回空队列
                g_pListThread->PutBuffer(iter->second.plistBuffer, empty);
                g_pUselistBuffer.erase(iter->first);
                logWarn("delete dahua error picture !!!");
                break;
            }

        }
        //10秒钟轮休一下
        sleep(10);
    }
}

void CCameras::listen_jvt_cameras() {
    while (m_isRun) {
        time_t t = time(NULL);

        //检查是否存在超时数据,若存在,则删除
        for (auto iter = g_pUselistBuffer_JVT.begin(); iter != g_pUselistBuffer_JVT.end(); iter++) {
            logWarn(to_string(iter->first));
            if (iter->second.nTimer < t) {
                string strID = to_string(iter->first);
                logWarn(strID + ":recovery!!!");
                //放回空队列
                g_pListThread->PutBuffer(iter->second.plistBuffer, empty);
                g_pUselistBuffer_JVT.erase(iter->first);
                logWarn("delete bearhunting error picture !!!");
                break;
            }

        }
        //10秒钟轮休一下
        sleep(10);
    }
}

void CCameras::listen_kuangshi_cameras() {
    while (m_isRun) {
        time_t t = time(NULL);
        //检查是否存在超时数据,若存在,则删除
        for (auto iter = g_pUselistBuffer_KS.begin(); iter != g_pUselistBuffer_KS.end(); iter++) {
            logWarn(to_string(iter->first));
            if (iter->second.nTimer < t) {
                string strID = to_string(iter->first);
                logWarn(strID + ":recovery!!!");
                //放回空队列
                g_pListThread->PutBuffer(iter->second.plistBuffer, empty);
                g_pUselistBuffer_KS.erase(iter->first);
                logWarn("delete kuangshi error picture !!!");
                break;
            }

        }
        //10秒钟轮休一下
        sleep(10);
    }
}


void CCameras::listen_NETDEV_cameras(){
    while (m_isRun) {
        time_t t = time(NULL);
        //检查是否存在超时数据,若存在,则删除
        for (auto iter = g_pUselistBuffer_NETDEV.begin(); iter != g_pUselistBuffer_NETDEV.end(); iter++) {
            logWarn(to_string(iter->first));
            if (iter->second.nTimer < t) {
                string strID = to_string(iter->first);
                logWarn(strID + ":recovery!!!");
                //放回空队列
                g_pListThread->PutBuffer(iter->second.plistBuffer, empty);
                g_pUselistBuffer_NETDEV.erase(iter->first);
                logWarn("delete NETDEV error picture !!!");
                break;
            }

        }
        //10秒钟轮休一下
        sleep(10);
    }


}



void CCameras::reconnect_cameras() {

    while (m_isReconnect) {
        for (auto iter = m_listCameraMsg.begin(); iter != m_listCameraMsg.end(); iter++) {
            string strLog = "try again camera init:" + iter->strIP;
            logInfo(strLog);
            FACE_CAMERA_MSG faceCameraMsg;
            faceCameraMsg.nCapType = iter->nCapType;
            faceCameraMsg.nID = iter->nID;
            faceCameraMsg.strIP = iter->strIP;
            faceCameraMsg.strPassword = iter->strPassword;
            faceCameraMsg.strUserName = iter->strUserName;
            faceCameraMsg.nPort = iter->nPort;
            faceCameraMsg.nType = iter->nType;

            void *pCameras = GetCamera(iter->nType, &faceCameraMsg);
            if (pCameras) {
                //相机登录成功
                CAMERA_MSG *camera_msg = new CAMERA_MSG;
                //设置相机标签
                camera_msg->nTag = iter->nType;
                camera_msg->pCamera = pCameras;
                m_CameraMap.insert(make_pair(iter->nID, camera_msg));
                m_listCameraMsg.erase(iter++);
            }
        }

        if (m_listCameraMsg.size() > 0)
            //600秒重连相机一次
            sleep(600);
        else
            //否则退出循环
            m_isReconnect = false;
    }

    //存在人脸抓拍相机
    if (g_isFaceHKCameras)
        //设置相机回调
        SetCallBack(HIKVISION);

    if (g_isFaceDHCameras)
        //设置相机回调
        SetCallBack(DAHUA);

    if (g_isFaceJVTCameras)
        //设置相机回调
        SetCallBack(JVT);
    if (g_isFaceKSCameras)
        //设置相机回调
        SetCallBack(KUANGSHI);
        //设置相机回调
    if(g_isFaceNETDEVCameras)
        SetCallBack(NETDEV);

}

void CCameras::OnInitCameras() {
    //启动文件监听线程
    m_thread = boost::thread(boost::bind(&CCameras::listen_file_changed, this));
}

void CCameras::OnGetJsonMsg(const string strPath) {
    //清空掉线相机消息记录
    if (m_listCameraMsg.size() > 0) {
        //等待线程结束
        m_isReconnect = false;
        m_threadReconnect.join();

        m_listCameraMsg.clear();
    }
    auto document = GetJsonMsg(strPath);

    FACE_CAMERA_MSG face_camera_msg;

    if (document.IsArray()) {
        for (int i = 0; i < document.Size(); ++i) {
            const Value &cur_camera = document[i];

            face_camera_msg.nType = cur_camera["type"].GetInt();
            face_camera_msg.nID = cur_camera["id"].GetInt64();
            //printf("face_camera_msg.nID=%d\n",face_camera_msg.nID);

            auto capType = cur_camera.FindMember("capType");
            if (capType != cur_camera.MemberEnd())
                face_camera_msg.nCapType = cur_camera["capType"].GetInt();
            else
                face_camera_msg.nCapType = FACE_CAP;

            face_camera_msg.strIP = cur_camera["ip"].GetString();
            face_camera_msg.nPort = cur_camera["port"].GetInt();
            face_camera_msg.strUserName = cur_camera["username"].GetString();
            face_camera_msg.strPassword = cur_camera["password"].GetString();

            if (face_camera_msg.nType == HIKVISION)
                g_isFaceHKCameras = true;

            if (face_camera_msg.nType == DAHUA)
                g_isFaceDHCameras = true;
            if(face_camera_msg.nType ==NETDEV)
                g_isFaceNETDEVCameras=true;


            if (face_camera_msg.nCapType == FACE_CAP) {
                if(face_camera_msg.nType==NETDEV)
                    g_isFaceNETDEVCameras=true;
                if (face_camera_msg.nType == JVT || face_camera_msg.nType == BEARHUNTING) {
                    g_isFaceJVTCameras = true;
                }
                if (face_camera_msg.nType == KUANGSHI)
                    g_isFaceKSCameras = true;

                OnSetCameras(&face_camera_msg);
            } else if (face_camera_msg.nCapType == CAR_CAP) {
                g_isCapCameras = true;
                if (face_camera_msg.nType == HIKVISION || face_camera_msg.nType == DAHUA/*||face_camera_msg.nType==NETDEV*/) {
                    //若为海康大华车牌抓拍,调用海康大华接口
                    OnSetCameras(&face_camera_msg);
                    continue;
                }

                //唯一ID标识指定相机
                uint64 nID = face_camera_msg.nID;

                string strLog = "cap car camera init:" + face_camera_msg.strIP;
                logInfo(strLog);

                //IP与ID绑定
                g_CameraIP.insert(make_pair(face_camera_msg.strIP, nID));
            }

        }

        //存在人脸抓拍相机
        if (g_isFaceHKCameras)
            //设置相机回调
            SetCallBack(HIKVISION);

        if (g_isFaceDHCameras)
            //设置相机回调
            SetCallBack(DAHUA);


        if (g_isFaceJVTCameras)
            //设置相机回调
            SetCallBack(JVT);

        if (g_isFaceKSCameras)
            //设置相机回调
            SetCallBack(KUANGSHI);
        if(g_isFaceNETDEVCameras)
            SetCallBack(NETDEV);
        //存在车牌抓拍相机
        if (g_isCapCameras) {
            if (m_pReceiveCar) {
                delete m_pReceiveCar;
                m_pReceiveCar = nullptr;
            }
            m_pReceiveCar = new CReceiveCar;
        }

        PictureProtocol::CameraStatusList cameraStatusList;
        PictureProtocol::Head head;

        //发送登录成功相机状态信息
        for (auto iter = m_CameraMap.begin(); iter != m_CameraMap.end(); iter++) {
            PictureProtocol::CameraStatus *cameraStatus = cameraStatusList.add_camerastatus();
            cameraStatus->set_camera_id(iter->first);
            cameraStatus->set_status(true);
        }

        //发送登录失败相机状态信息
        for (auto iter = m_listCameraMsg.begin(); iter != m_listCameraMsg.end(); iter++) {
            PictureProtocol::CameraStatus *cameraStatus = cameraStatusList.add_camerastatus();
            cameraStatus->set_camera_id(iter->nID);
            cameraStatus->set_status(false);
        }

        head.set_message_size(cameraStatusList.ByteSize());
        head.set_message_type(PictureProtocol::MessageType::CAMERA_STATUS_MESSAGE);

        //m_pSendQueue->SendMsg(head.SerializeAsString() + cameraStatusList.SerializeAsString());

    }

    if (m_listCameraMsg.size() > 0) {
        m_isReconnect = true;
        //启动重连线程
        m_threadReconnect = boost::thread(boost::bind(&CCameras::reconnect_cameras, this));
    }
}

void CCameras::SetCallBack(int nType) {
    switch (nType) {
        case HIKVISION: {
            SetHKCallBack();
        }
            break;
        case DAHUA: {
            SetDHCallBack();
        }
            break;
        case JVT: {
            SetJVTCallBack();
        }
        case KUANGSHI: {
            SetKSCallBack();
        }
            break;
        case NETDEV:{
            SetNETDEVCallBack();
        }
           break;
    }
}

void CCameras::SetHKCallBack() {
    //注册接收异常消息的回调函数
    if (!NET_DVR_SetExceptionCallBack_V30(0, NULL, ExceptionCallBack, this)) {
        char buf[100] = {0};
        sprintf(buf, "NET_DVR_SetExceptionCallBack_V30 error, %d", NET_DVR_GetLastError());
        logError(buf);
        return;
    }


    //设置报警回调函数
    if (!NET_DVR_SetDVRMessageCallBack_V31(fMessageCallback, this)) {
        char buf[100] = {0};
        sprintf(buf, "NET_DVR_SetDVRMessageCallBack_V31 error, %d", NET_DVR_GetLastError());
        logError(buf);
        return;
    }
}

void CCameras::SetDHCallBack() {
    //时间监听线程
    m_threadTime = boost::thread(boost::bind(&CCameras::listen_dahua_cameras, this));
}

void CCameras::SetJVTCallBack() {
    //时间监听线程
    m_threadTime = boost::thread(boost::bind(&CCameras::listen_jvt_cameras, this));
}

void CCameras::SetKSCallBack() {
    //时间监听线程
    m_threadTime = boost::thread(boost::bind(&CCameras::listen_kuangshi_cameras, this));
}

void CCameras::SetNETDEVCallBack()
{
    //时间监听线程
    m_threadTime = boost::thread(boost::bind(&CCameras::listen_NETDEV_cameras, this));
}


void CCameras::OnSetCameras(const FACE_CAMERA_MSG *face_camera_msg) {
    //唯一ID标识指定相机
    uint64 nID = face_camera_msg->nID;

    string strLog = "camera init:" + face_camera_msg->strIP;
    logInfo(strLog);

    //IP与ID绑定
    g_CameraIP.insert(make_pair(face_camera_msg->strIP, nID));

    //登录相机设备
    void *pCameras = GetCamera(face_camera_msg->nType, face_camera_msg);


    if (pCameras) {
        //相机登录成功
        CAMERA_MSG *camera_msg = new CAMERA_MSG;
        //设置相机标签
        camera_msg->nTag = face_camera_msg->nType;
        camera_msg->pCamera = pCameras;
        m_CameraMap.insert(make_pair(nID, camera_msg));


        return;
    }
    //相机未登录成功,保存列表，定时登录
    FACE_CAMERA_MSG faceCameraMsg;
    faceCameraMsg.nCapType = face_camera_msg->nCapType;
    faceCameraMsg.nID = face_camera_msg->nID;
    faceCameraMsg.strIP = face_camera_msg->strIP;
    faceCameraMsg.strPassword = face_camera_msg->strPassword;
    faceCameraMsg.strUserName = face_camera_msg->strUserName;
    faceCameraMsg.nPort = face_camera_msg->nPort;
    faceCameraMsg.nType = face_camera_msg->nType;

    m_listCameraMsg.push_back(faceCameraMsg);

}

void *CCameras::GetCamera(const int nType, const FACE_CAMERA_MSG *face_camera_msg) {
    void *pCamera = nullptr;
    switch (nType) {
        //海康威视
        case HIKVISION: {
            HCCamera *hCamera = new HCCamera(face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                             face_camera_msg->strUserName.c_str(),
                                             face_camera_msg->strPassword.c_str(), face_camera_msg->nCapType);

            //相机登录失败,删除相机
            if (!hCamera->GetCameraInit()) {
                logError("The hikvision camera login failed, please check the configuration!");
                delete hCamera;
                hCamera = nullptr;
                return nullptr;
            }
            pCamera = (void *) hCamera;
        }
            break;
            //大华
        case DAHUA: {
            DHCamera *dhCamera = new DHCamera(this, face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                              face_camera_msg->strUserName.c_str(),
                                              face_camera_msg->strPassword.c_str(), face_camera_msg->nCapType);
            if (!dhCamera->GetCameraInit()) {
                logError("The dahua camera login failed, please check the configuration!");
                delete dhCamera;
                dhCamera = nullptr;
                return nullptr;
            }
            pCamera = (void *) dhCamera;
        }
            break;
            //巨龙创视
        case JVT: {
            JVTCamera *jvtCamera = new JVTCamera(face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                                 face_camera_msg->strUserName.c_str(),
                                                 face_camera_msg->strPassword.c_str());
            if (!jvtCamera->GetCameraInit()) {
                logError("The jvt camera login failed, please check the configuration!");
                delete jvtCamera;
                jvtCamera = nullptr;
                return nullptr;
            }
            pCamera = (void *) jvtCamera;
        }
            break;
            //猎熊座
        case BEARHUNTING: {
            JVTCamera *jvtCamera = new JVTCamera(face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                                 face_camera_msg->strUserName.c_str(),
                                                 face_camera_msg->strPassword.c_str());
            if (!jvtCamera->GetCameraInit()) {
                logError("The bearhunting camera login failed, please check the configuration!");
                delete jvtCamera;
                jvtCamera = nullptr;
                return nullptr;
            }
            pCamera = (void *) jvtCamera;
        }
            break;
        case KUANGSHI: {
            KSCamera *ksCamera = new KSCamera(face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                              face_camera_msg->strUserName.c_str(),
                                              face_camera_msg->strPassword.c_str());
            if (!ksCamera->GetCameraInit()) {
                logError("The kuangshi camera login failed, please check the configuration!");
                delete ksCamera;
                ksCamera = nullptr;
                return nullptr;
            }
            pCamera = (void *) ksCamera;
        }
            break;
        case NETDEV:{
            NetDevCamera *netdevCamera= new NetDevCamera(face_camera_msg->strIP.c_str(), face_camera_msg->nPort,
                                                         face_camera_msg->strUserName.c_str(),
                                                         face_camera_msg->strPassword.c_str());


           if(!(netdevCamera->GetCameraInit()))
            {
                logError("The netdev camera login failed, please check the configuration!");
                delete netdevCamera;
                netdevCamera=nullptr;
                return nullptr;
            }
            pCamera = (void *)netdevCamera;
        }
        break;
        default:
            break;
    }

    return pCamera;
}

void CCameras::getFiles() {
    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir = opendir(g_strSavePictureSrc.c_str())) == NULL) {
        logError("Open dir error...");
        return;
    }

    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            continue;
        else if (ptr->d_type == 8) {
            char cFileName[100] = {0};
            memcpy(cFileName, ptr->d_name, 100);
            const char *sep = "-"; //可按多个字符来分割
            char *p = nullptr;
            p = strtok(cFileName, sep);
            if (atoi(p) == HIKVISION) {
                g_listStrSavePic.push_back(ptr->d_name);
            } else if (atoi(p) == DAHUA) {
                string strFileName = ptr->d_name;
                int nPos = strFileName.find("-bk.jpg");
                if (nPos != -1) {
                    string strNewFileNaem(strFileName.substr(0, nPos));
                    g_listStrSavePic.push_back(strNewFileNaem);
                }
            }

        } else if (ptr->d_type == 10)    ///link file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            continue;
        else if (ptr->d_type == 4)    ///dir
            continue;
    }
    closedir(dir);
}