//
// Created by HXD on 18-5-4.
//

//
// Created by carl on 18-7-10.
//
#include <opencv2/opencv.hpp>
//#include <jpeglib.h>
#include <boost/filesystem.hpp>
#include "../double_list/SendQueue.h"
#include <string.h>
#include <tcp_conf_handle.h>
#include "../rapidjson/rapidjson.h"
//#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"
#include "../rapidjson/filewritestream.h"
#include "../double_list/ListThread.h"
#include "../log4cpp/CLog.h"
#include <sys/types.h>

#include <sys/wait.h>

#include <errno.h>

#include <unistd.h>

//#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include <istream> //基本输入流
#include <ostream> //基本输出流
#include <fstream> //文件输入／输出

#include <cstdio>
#include <iostream>
#include <string>
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"

//#include "../rapidjson/FileStream.h"
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/stringbuffer.h"


#include "../global.h"
#include "../CCameras.h"
#include <boost/filesystem/operations.hpp>
#include <dirent.h>
#include "../hikvision/HCCamera.h"
#include "../dahua/DHCamera.h"
#include "../jvt/JVTCamera.h"
#include "../kuangshi/KSCamera.h"
#include  "../NETDEV/NetDev.h"
#include <string>
#include "stdlib.h"
#include "stdio.h"
#include "global.h"
#include "CCameras.h"
#include <boost/filesystem/operations.hpp>
#include <dirent.h>
#include "hikvision/HCCamera.h"
#include "dahua/DHCamera.h"
#include "jvt/JVTCamera.h"
#include "kuangshi/KSCamera.h"
#include  "NETDEV/NetDev.h"

#include <opencv2/opencv.hpp>
//#include <jpeglib.h>
#include <boost/filesystem.hpp>
#include <string.h>
#include <tcp_conf_handle.h>
#include "../rapidjson/rapidjson.h"
//#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"
#include "../rapidjson/filewritestream.h"
#include "../double_list/ListThread.h"
#include "../log4cpp/CLog.h"
#include <sys/types.h>

#include <sys/wait.h>

#include <errno.h>

#include <unistd.h>

//#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include <istream> //基本输入流
#include <ostream> //基本输出流
#include <fstream> //文件输入／输出

#include <cstdio>
#include <iostream>
#include <string>
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"

//#include "../rapidjson/FileStream.h"
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/stringbuffer.h"
#define psln(x) std::cout << #x " = " << (x) << std::endl

extern LPVOID netdev_UserID;
void *s;
int lid6=0,lid1=0,lid2=0,lid3=0,lid7=0,lid8=0;
char* itoa(int num,char* str,int radix);
extern char NetDeverrIp[60];
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
                    "Excharception exchange(heartbeat timeout, heartbeat interval of 2 minutes)!!!XXXXXXX");
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
}


CCameras::CCameras(SendQueue *pSendQueue) : m_pSendQueue(pSendQueue) {

    OnInitCameras();
    //server_queue();
    th_server_queue();
}

CCameras::~CCameras() {

    m_isRun = false;
    m_thread.join();
    m_threadTime.join();
    m_thread_sq.join();//xj  add
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




void CCameras::reconnect_idele_cameras(char *buffer) {
    Document document;
    document.SetObject();//xj  add
    document.Parse(buffer);
    int   f=document.HasMember("data");
    FACE_CAMERA_MSG face_camera_msg;

   if(f==1)
   {
    Value &names_json=document["data"];
    if (names_json.IsArray()) {
        //NETDEV_Reboot(netdev_UserID);
        for (int i = 0; i < names_json.Size(); ++i) {
            const Value &cur_camera = names_json[i];
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
            printf("face_camera_msg.nType=%d\n",face_camera_msg.nType);
            if(face_camera_msg.nType==NETDEV) {
                NetDevCamera *NETD=new NetDevCamera(face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(NETD->GetCameraInit()==FALSE)
                {
                    lid8=face_camera_msg.nID;

                    printf("lid8=%d\n",lid8);
                    char testbuf1[20]={0};
                    itoa(lid8,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                    lid8=0;
                    printf("reboot failue\n");

                }

            }
            if(face_camera_msg.nType==HIKVISION) {
                HCCamera *HCC=new HCCamera(face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                                    face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(HCC->GetCameraInit()==FALSE)
                {
                    lid1=face_camera_msg.nID;

                    printf("lid1=%d\n",lid1);
                    char testbuf1[20]={0};
                    itoa(lid1,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                    lid1=0;
                    printf("reboot failue\n");

                }
            }

            if(face_camera_msg.nType==DAHUA) {
                DHCamera *DAHUA=new DHCamera(NULL,face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                           face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(DAHUA->GetCameraInit()==FALSE)
                {
                    lid2=face_camera_msg.nID;

                    printf("lid2=%d\n",lid2);
                    char testbuf1[20]={0};
                    itoa(lid2,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                    lid2=0;
                    printf("reboot failue\n");

                }
            }
            if(face_camera_msg.nType==JVT) {
                JVTCamera *JVTC=new JVTCamera(face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                             face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(JVTC->GetCameraInit()==FALSE)
                {
                    lid3=face_camera_msg.nID;

                    printf("lid3=%d\n",lid3);
                    char testbuf1[20]={0};
                    itoa(lid3,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                    lid3=0;
                    printf("reboot failue\n");

                }
            }

            if(face_camera_msg.nType==KUANGSHI) {
                KSCamera *KSC=new KSCamera(face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                              face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(KSC->GetCameraInit()==FALSE)
                {
                    lid7=face_camera_msg.nID;

                    printf("lid7=%d\n",lid7);
                    char testbuf1[20]={0};
                    itoa(lid7,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                    lid7=0;
                    printf("reboot failue\n");

                }
            }

            if(face_camera_msg.nType==BEARHUNTING) {
                JVTCamera *BEAR=new JVTCamera(face_camera_msg.strIP.c_str(), face_camera_msg.nPort,
                                           face_camera_msg.strUserName.c_str(), face_camera_msg.strPassword.c_str());
                if(BEAR->GetCameraInit()==FALSE)
                {
                    lid6=face_camera_msg.nID;

                    //printf("lid6=%d\n",lid6);
                    char *testbuf1="500";
//                    char testbuf1[20]={0};
//                    itoa(lid6,testbuf1,10);
                    zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);

                    lid6=0;
                    printf("reboot failue\n");

                }
            }

        }
     }


    }


}





void CCameras::reconnect_cameras()
{

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
        //设置相机回CCameras调
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

char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//索引表
    unsigned unum;//存放要转换的整数的绝对值,转换的整数可能是负数
    int i=0,j,k;//i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。

    //获取要转换的整数的绝对值
    if(radix==10&&num<0)//要转换成十进制数并且是负数
    {
        unum=(unsigned)-num;//将num的绝对值赋给unum
        str[i++]='-';//在字符串最前面设置为'-'号，并且索引加1
    }
    else unum=(unsigned)num;//若是num为正，直接赋值给unum

    //转换部分，注意转换后是逆序的
    do
    {
        str[i++]=index[unum%(unsigned)radix];//取unum的最后一位，并设置为str对应位，指示索引加1
        unum/=radix;//unum去掉最后一位

    }while(unum);//直至unum为0退出循环

    str[i]='\0';//在字符串最后添加'\0'字符，c语言字符串以'\0'结束。

    //将顺序调整过来
    if(str[0]=='-') k=1;//如果是负数，符号不用调整，从符号后面开始调整
    else k=0;//不是负数，全部都要调整

    char temp;//临时变量，交换两个值时用到
    for(j=k;j<=(i-1)/2;j++)//头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp=str[j];//头部赋值给临时变量
        str[j]=str[i-1+k-j];//尾部赋值给头部
        str[i-1+k-j]=temp;//将临时变量的值(其实就是之前的头部值)赋给尾部
    }

    return str;//返回转换后的字符串
}


void CCameras::server_queue(){

    void *context = zmq_ctx_new();
    s = zmq_socket(context, ZMQ_REP);
    int64_t affinity;
    affinity = 1;
    int rc = zmq_setsockopt (s, ZMQ_USE_FD, &affinity, sizeof (affinity));
    assert (rc);
    int rc2 = zmq_bind(s, "tcp://*:5556");
    assert (rc2 == 0);

    while (1)
    {

        char buffer[1024*1024]={0};
        zmq_recv(s, (void *)buffer, sizeof(buffer) - 1, 0);
        Document d1;
        d1.SetObject();//xj  add
        d1.Parse(buffer);
        if(d1.HasMember("operate")==0)
        {
            printf("d1.HasMember operate is 0,exit from program\n");
            char *testbuf1="send again";
            zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
            sleep(3);

            break;
        }
        Value& st = d1["operate"];
        printf("st.GetInt()=%d\n",st.GetInt());


        const Value &cur_server = d1;
        int operate = cur_server["operate"].GetInt64();
        if(operate==1)
        {

            Document d;
            d.SetObject();
            string filename = "/home/xujun/test3.json";
            ifstream json_file;
            json_file.open(filename.c_str());
            string json;
            if (!json_file.is_open()) {
                cout << "Error opening file" << endl;
                d= GetJsonMsg("/home/xujun/test3.json");
                d.SetObject();
            }
            else {
                getline(json_file, json);
                d.SetObject();//xj
                d.Parse<0>(json.c_str());
            }


            rapidjson::Document::AllocatorType& allocator = d.GetAllocator();
            rapidjson::Value info_array(rapidjson::kArrayType);
            rapidjson::Value  info_object(rapidjson::kObjectType);
            info_object.SetObject();

            Value &sk3=d1["data"]["id"];
            info_object.AddMember("id",sk3.GetInt(),allocator);

            Value &sk4= d1["data"]["type"];
            info_object.AddMember("type",sk4.GetInt(),allocator);

            sk4= d1["data"]["captype"];
            info_object.AddMember("captype",sk4.GetInt(),allocator);

            rapidjson::Value&  sk5=d1["data"]["ip"];
            string cc=sk5.GetString();
            rapidjson::Value p_value(rapidjson::kStringType);
            p_value.SetString(cc.c_str(), (int)cc.size(), d.GetAllocator());
            info_object.AddMember("ip", p_value, d.GetAllocator());

            sk3=d1["data"]["port"];
            info_object.AddMember("port",sk3.GetInt(),allocator);

            sk3=d1["data"]["active"];
            info_object.AddMember("active",sk3.GetBool(),allocator);


            rapidjson::Value&  sk9=d1["data"]["model"];
            string cc9=sk9.GetString();
            rapidjson::Value p_value9(rapidjson::kStringType);
            p_value9.SetString(cc9.c_str(), (int)cc9.size(), d.GetAllocator());
            info_object.AddMember("model", p_value9, d.GetAllocator());


            rapidjson::Value&  sk8=d1["data"]["position"];
            string cc8=sk8.GetString();
            rapidjson::Value p_value8(rapidjson::kStringType);
            p_value8.SetString(cc8.c_str(), (int)cc8.size(), d.GetAllocator());
            info_object.AddMember("position", p_value8, d.GetAllocator());

            rapidjson::Value&  sk12=d1["data"]["username"];
            string cc12=sk12.GetString();
            rapidjson::Value p_value12(rapidjson::kStringType);
            p_value12.SetString(cc12.c_str(), (int)cc12.size(), d.GetAllocator());
            info_object.AddMember("username", p_value12, d.GetAllocator());


            rapidjson::Value&  sk10=d1["data"]["password"];
            string cc10=sk10.GetString();
            rapidjson::Value p_value10(rapidjson::kStringType);
            p_value10.SetString(cc10.c_str(), (int)cc10.size(), d.GetAllocator());
            info_object.AddMember("password", p_value10, d.GetAllocator());



            Value &sk7= d1["data"]["status"];
            info_object.AddMember("status",sk7.GetBool(),allocator);


            rapidjson::Value&  sk11=d1["data"]["url"];
            string cc11=sk11.GetString();
            rapidjson::Value p_value11(rapidjson::kStringType);
            p_value11.SetString(cc11.c_str(), (int)cc11.size(), d.GetAllocator());
            info_object.AddMember("url", p_value11, d.GetAllocator());


            int   f=d.HasMember("Info");
            if(f!=1) {

                info_array.PushBack(info_object, d.GetAllocator());

                d.AddMember("Info", info_array, d.GetAllocator());

            } else{

                Value &node2= d["Info"];


                node2.PushBack(info_object, d.GetAllocator());

            }

            StringBuffer buffer2;
            Writer<StringBuffer> writer2(buffer2);
            d.Accept(writer2);

            psln(buffer2.GetString());
            std::string strPath = "/home/xujun/test3.json";
            FILE* myFile = fopen(strPath.c_str(), "w");  //windows平台要使用wb
            if (myFile) {

                fputs(buffer2.GetString(), myFile);
                fclose(myFile);

            }
            char* testbuf1="200";
            zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
            printf("add ok\n");

        }
        else if( operate==2)
        {
            Document jsonDoc= GetJsonMsg("/home/xujun/test3.json");
            rapidjson::Value &names_json = jsonDoc["Info"];
            for (rapidjson::Value::ValueIterator iter = names_json.Begin(); iter != names_json.End();) {
                std::int32_t id = (*iter)["id"].GetInt();
                if (id ==d1["data"]["id"]) {
                    iter = names_json.Erase(iter);
                    printf("remove id varry\n");
                } else
                    ++iter;
            }
            rapidjson::StringBuffer buffer3;
            Writer<StringBuffer> writer3(buffer3);
            jsonDoc.Accept(writer3);
            //printf("%s\n", str.c_str());
            printf("%s\n", buffer3.GetString());
            std::string strPath = "/home/xujun/test3.json";
            FILE *myFile = fopen(strPath.c_str(), "w");  //windows平台要使用wb
            if (myFile) {
                fputs(buffer3.GetString(), myFile);
                fclose(myFile);
            }
            char* testbuf1="200";
            zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
            printf("delete ok\n");

        }
        else if(operate==3) {

            Document jsonDoc = GetJsonMsg("/home/xujun/test3.json");
            rapidjson::Value &names_json = jsonDoc["Info"];
            for (rapidjson::Value::ValueIterator iter = names_json.Begin(); iter != names_json.End();) {
                std::int32_t id = (*iter)["id"].GetInt();
                if (id == d1["data"]["id"]) {
                    iter = names_json.Erase(iter);
                    printf("remove id varry\n");
                } else
                    ++iter;
            }
            rapidjson::StringBuffer buffer3;
            Writer<StringBuffer> writer3(buffer3);
            jsonDoc.Accept(writer3);
            //printf("%s\n", str.c_str());
            printf("%s\n", buffer3.GetString());
            std::string strPath = "/home/xujun/test3.json";
            FILE *myFile = fopen(strPath.c_str(), "w");  //windows平台要使用wb
            if (myFile) {
                fputs(buffer3.GetString(), myFile);
                fclose(myFile);
            }

            Document d;
            d.SetObject();
            string filename = "/home/xujun/test3.json";
            ifstream json_file;
            json_file.open(filename.c_str());
            string json;
            if (!json_file.is_open()) {
                cout << "Error opening file" << endl;
                d = GetJsonMsg("/home/xujun/test3.json");
                d.SetObject();

            } else {
                getline(json_file, json);
                d.SetObject();//xj
                d.Parse<0>(json.c_str());
            }

            rapidjson::Document::AllocatorType &allocator = d.GetAllocator();
            rapidjson::Value info_array(rapidjson::kArrayType);
            rapidjson::Value info_object(rapidjson::kObjectType);
            info_object.SetObject();//?????


            Value &sk3=d1["data"]["id"];
            info_object.AddMember("id",sk3.GetInt(),allocator);

            Value &sk4= d1["data"]["type"];
            info_object.AddMember("type",sk4.GetInt(),allocator);

            sk4= d1["data"]["captype"];
            info_object.AddMember("captype",sk4.GetInt(),allocator);

            rapidjson::Value&  sk5=d1["data"]["ip"];
            string cc=sk5.GetString();
            rapidjson::Value p_value(rapidjson::kStringType);
            p_value.SetString(cc.c_str(), (int)cc.size(), d.GetAllocator());
            info_object.AddMember("ip", p_value, d.GetAllocator());

            sk3=d1["data"]["port"];
            info_object.AddMember("port",sk3.GetInt(),allocator);

            sk3=d1["data"]["active"];
            info_object.AddMember("active",sk3.GetBool(),allocator);


            rapidjson::Value&  sk9=d1["data"]["model"];
            string cc9=sk9.GetString();
            rapidjson::Value p_value9(rapidjson::kStringType);
            p_value9.SetString(cc9.c_str(), (int)cc9.size(), d.GetAllocator());
            info_object.AddMember("model", p_value9, d.GetAllocator());


            rapidjson::Value&  sk8=d1["data"]["position"];
            string cc8=sk8.GetString();
            rapidjson::Value p_value8(rapidjson::kStringType);
            p_value8.SetString(cc8.c_str(), (int)cc8.size(), d.GetAllocator());
            info_object.AddMember("position", p_value8, d.GetAllocator());

            rapidjson::Value&  sk12=d1["data"]["username"];
            string cc12=sk12.GetString();
            rapidjson::Value p_value12(rapidjson::kStringType);
            p_value12.SetString(cc12.c_str(), (int)cc12.size(), d.GetAllocator());
            info_object.AddMember("username", p_value12, d.GetAllocator());


            rapidjson::Value&  sk10=d1["data"]["password"];
            string cc10=sk10.GetString();
            rapidjson::Value p_value10(rapidjson::kStringType);
            p_value10.SetString(cc10.c_str(), (int)cc10.size(), d.GetAllocator());
            info_object.AddMember("password", p_value10, d.GetAllocator());



            Value &sk7= d1["data"]["status"];
            info_object.AddMember("status",sk7.GetBool(),allocator);


            rapidjson::Value&  sk11=d1["data"]["url"];
            string cc11=sk11.GetString();
            rapidjson::Value p_value11(rapidjson::kStringType);
            p_value11.SetString(cc11.c_str(), (int)cc11.size(), d.GetAllocator());
            info_object.AddMember("url", p_value11, d.GetAllocator());




            int f = d.HasMember("Info");
            if (f != 1) {

                info_array.PushBack(info_object, d.GetAllocator());

                d.AddMember("Info", info_array, d.GetAllocator());

            } else {

                Value &node2 = d["Info"];


                node2.PushBack(info_object, d.GetAllocator());

            }

            StringBuffer buffer2;
            Writer<StringBuffer> writer2(buffer2);
            d.Accept(writer2);
            psln(buffer2.GetString());

            strPath = "/home/xujun/test3.json";
            myFile = fopen(strPath.c_str(), "w");  //windows平台要使用wb
            if (myFile) {
                fputs(buffer2.GetString(), myFile);
                fclose(myFile);

            }
            char *testbuf1 = "200";
            zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
            printf("add ok\n");



        }
        else if(operate==4)
        {
            reconnect_idele_cameras(buffer);
            if(NetDeverrIp!=0)
            {
                char *testbuf1 = "500";
                printf("aaaaaaaaaaaaaaaaaa\n");
                //zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                zmq_send(s, testbuf1, 3, 0);
                printf("11111111111111\n");
                printf("reboot failure\n");
            } else {
                char *testbuf1 = "200";
                zmq_send(s, testbuf1, strlen(testbuf1) + 1, 0);
                printf("reboot ok\n");
            }

        }

    }

    zmq_close(s);
    zmq_ctx_destroy(context);



}




void CCameras::th_server_queue()
{
    m_thread_sq=boost::thread(boost::bind(&CCameras::server_queue,this));
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