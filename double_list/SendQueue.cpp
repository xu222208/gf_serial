//
// Created by carl on 18-7-10.
//
#include <opencv2/opencv.hpp>
//#include <jpeglib.h>
#include <boost/filesystem.hpp>
#include "SendQueue.h"
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
extern CCameras *pCameras;   //xj  add
extern int lid6,lid1,lid2,lid3,lid7,lid8;
#define psln(x) std::cout << #x " = " << (x) << std::endl

char* itoa(int num,char* str,int radix);

extern "C"{
#include <zmq.h>
#include <zmq_utils.h>
}


extern void * pSock ;
extern  void * pSock2;


using namespace std;
using namespace rapidjson;

#ifdef RECEIVE_SAVE_PICTUREFileReadStream

#include "../receive_picture/ReceivePicture.h"

#endif

#include <string>
extern char tracking[];
extern char err[];

extern char* getTimeofymd();
extern char* getTimeofh_m_s_ms();

extern int gatewayId;
extern int cameraId;
SendQueue::SendQueue(from_server_info *pServerInfo) : m_pServerInfo(pServerInfo) {

    //设置JPG格式图片保存质量lid6
    m_param = vector<int>(2);
    m_param[0] = CV_IMWRITE_JPEG_QUALITY;
    m_param[1] = 80;//default(95) 0-100

    for (int i = 0; i < THREAD_COUNT; i++) {
        boost::thread *thr = new boost::thread(boost::bind(&SendQueue::send_queue, this, i));
        m_listThr.push_back(thr);

        boost::thread *thrCap = new boost::thread(boost::bind(&SendQueue::send_cap_queue, this, i));
        m_listThr.push_back(thrCap);
    }
//    boost::thread *thrzmqserver = new boost::thread(boost::bind(&SendQueue::server_queue, this, 0));  //xj  add
//    m_listThr.push_back(thrzmqserver);

    //若存在本地推送图片，初始化本地推送库
#ifdef RECEIVE_SAVE_PICTURElid6
    if (RECEIVE_PICTURE_Init()) {
        //获取挂载盘路径
        m_strNfsName = RECEIVE_PICTURE_GetNfsPath();
    }
#endif
}

SendQueue::~SendQueue() {
    //设置关闭线程
    OnSetRun(false);

    for (auto iter = m_listThr.begin(); iter != m_listThr.end(); iter++) {
        boost::thread *thr = *iter;
        thr->join();
        delete thr;
        thr = nullptr;
    }

    m_listThr.clear();
#ifdef RECEIVE_SAVE_PICTURE
    //注销图片接收库文件
    RECEIVE_PICTURE_Destroy();
#endif
}

void SendQueue::send_queue(const int nThreadID) {
    while (OnGetRun()) {
        if (g_isFaceHKCameras || g_isFaceDHCameras || g_isFaceJVTCameras || g_isFaceKSCameras||g_isFaceNETDEVCameras||g_isCapCameras)
            OnGetBuffer(nThreadID);
        else
            sleep(10);
    }

}

void SendQueue::send_cap_queue(const int nThreadID) {
    while (OnGetRun()) {
        if (g_isCapCameras)
            OnGetCapBuffer(nThreadID);
        else
            sleep(10);
    }
}

void SendQueue::OnGetBuffer(const int nThreadID) {
    //未登录
    if (!g_isLogin) {
        logError("Failure of user login server!");
        sleep(1);
        return;
    }

    if (!g_pTcpConf->isConnect()) {
        logError("Unconnected server!");
        sleep(1);
        return;
    }

    //人脸抓拍缓冲区读取
    ReadFaceBuff(nThreadID);

}


void writeFileJson()
{
    //根节点
  
}



void SendQueue::OnGetCapBuffer(const int nThreadID) {
    //未登录
    if (!g_isLogin) {
        logError("Failure of user login server!");
        sleep(1);
        return;
    }

    if (!g_pTcpConf->isConnect()) {
        logError("Unconnected server!");
        sleep(1);
        return;
    }

    //车牌抓拍缓冲区读取
    ReadCapBuff(nThreadID);

}

void SendQueue::ReadCapBuff(const int nThreadID) {
    PLIST_BUFFER plistBuffer;
    //获取满队列
    g_pCarListThread->GetBuffer(&plistBuffer, full);
    //先处理实时接收的图片信息，再处理网关曾经保存的图片信息
    if (plistBuffer == nullptr) {
        sleep(1);
        return;
    }

    char temp[100] = {0};
    sprintf(temp, "Thread %d: read cap double list!", nThreadID + 1);
    logDebug(temp);
    logDebug("/**************************************************************************************/");


    int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
    printf("fd2=%d\n",fd2);
    char buf[200]={0};
    strcat(buf,"|");
    strcat(buf,getTimeofymd());
    strcat(buf,"|");
    strcat(buf,getTimeofh_m_s_ms());
    strcat(buf,"|");
    char fileSizeStr[20] = {0};
    sprintf(fileSizeStr,"%d",g_pListThread->nFaceID);
    strcat(buf,fileSizeStr);
    strcat(buf,"|");
    strcat(buf,"CAPTURE PHOTO|read cap double list|gateway_id=");
    char gwId[10]={0};
    sprintf(gwId,"%d",gatewayId);
    strcat(buf,gwId);
    strcat(buf," camera_id=");
    char camId[10]={0};
    sprintf(camId,"%d",cameraId);
    strcat(buf,camId);
    strcat(buf," vendor=jvt|");
    write(fd2,buf,200);
    close(fd2);

    //处理图片
    OnGetCapPicToSend(plistBuffer, nThreadID);
    //移到空队列
    g_pCarListThread->PutBuffer(plistBuffer, empty);
}

void SendQueue::ReadFaceBuff(const int nThreadID) {
    //printf("111111111111111111111111111\n");
    PLIST_BUFFER plistBuffer;
    //获取满队列
    g_pListThread->GetBuffer(&plistBuffer, full);
    //printf("222222222222222\n");
    //先处理实时接收的图片信息，再处理网关曾经保存的图片信息
    if (plistBuffer == nullptr) {
        //printf("33333333333333333\n");
        //若满队列为空,检查网关硬盘是否有保存数据，若存在,将图片信息放入满队列
        if (g_listStrSavePic.size() == 0) {
            sleep(1);
            return;
        }
        //获取空队列,插入图片信息
        g_pListThread->GetBuffer(&plistBuffer, empty);
        if (plistBuffer) {

            //将图片读取到内存中
            if (InsertPicToBuffer(plistBuffer)) {
                //放入满队列
                g_pListThread->PutBuffer(plistBuffer, full);
            } else {
                //若数据读取失败，归还空队列
                g_pListThread->PutBuffer(plistBuffer, empty);
            }

        }
        return;
    }
    printf("=============ReadFaceBuff============\n");
    printf("plistBuffer->camerasPic.nBackgroundPicLen=%d\n",plistBuffer->camerasPic.nBackgroundPicLen);
    printf("plistBuffer->camerasPic.nFacePicLen=%d\n",plistBuffer->camerasPic.nFacePicLen);

    char temp[100] = {0};
    sprintf(temp, "Thread %d: read face double list!", nThreadID + 1);
    logDebug(temp);
    logDebug("/**************************************************************************************/");

    int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
    printf("fd2=%d\n",fd2);
    char buf[200]={0};
    strcat(buf,"|");
    strcat(buf,getTimeofymd());
    strcat(buf,"|");
    strcat(buf,getTimeofh_m_s_ms());
    strcat(buf,"|");
    char fileSizeStr[20] = {0};
    sprintf(fileSizeStr,"%d",g_pListThread->nFaceID);
    strcat(buf,fileSizeStr);
    strcat(buf,"|");
    strcat(buf,"CAPTURE PHOTO|read face double list|gateway_id=");
    char gwId[10]={0};
    sprintf(gwId,"%d",gatewayId);
    strcat(buf,gwId);
    strcat(buf," camera_id=");
    char camId[10]={0};
    sprintf(camId,"%d",cameraId);
    strcat(buf,camId);
    strcat(buf," vendor=jvt|");
    write(fd2,buf,200);
    close(fd2);

    //处理图片
    OnGetPicToSend(plistBuffer, nThreadID);
    //移到空队列
    g_pListThread->PutBuffer(plistBuffer, empty);
}

bool SendQueue::InsertPicToBuffer(const PLIST_BUFFER plistBuffer) {
    if (g_listStrSavePic.size() == 0)
        return false;
    //获取链表头部文件名称
    string strFileName = g_listStrSavePic.front();
    char cFileName[1024] = {0};
    memcpy(cFileName, strFileName.c_str(), strFileName.length());
    const char *sep = "-"; //可按多个字符来分割
    char *p = nullptr;
    p = strtok(cFileName, sep);
    if (atoi(p) == HIKVISION) {
        ReadHKPicToBuffer(plistBuffer, strFileName, p);
    } else if (atoi(p) == DAHUA) {
        ReadDHPicToBuffer(plistBuffer, strFileName, p);
    }

    return true;
}

bool SendQueue::ReadHKPicToBuffer(const PLIST_BUFFER plistBuffer, const string strFileName, char *p) {
    //cameratype-ip-camerastime-programtime-picturelen-facescore-rect
    const char *sep = "-"; //可按多个字符来分割
    //char *p = nullptr;

    plistBuffer->camerasPic.nCamerasType = HIKVISION;
    p = strtok(NULL, sep);
    if (p) {
        //IP地址
        memcpy(plistBuffer->camerasPic.cCameraIP, p, 16);
    }

    p = strtok(NULL, sep);
    if (p) {
        //相机时间
        plistBuffer->camerasPic.tCameraTime = atoll(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //接收时间
        plistBuffer->camerasPic.tProgramTime = atoll(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //图片长度
        plistBuffer->camerasPic.nBackgroundPicLen = atol(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //人脸评分
        plistBuffer->camerasPic.nFaceScore = atoi(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //区域坐标
        plistBuffer->camerasPic.sAlarmRect.fX = atof(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //区域坐标
        plistBuffer->camerasPic.sAlarmRect.fY = atof(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //区域坐标
        plistBuffer->camerasPic.sAlarmRect.fWidth = atof(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        string strLast = p;
        // 查找
        int index = strLast.find(".jpg");
        if (index >= 0) {
            // 子串
            string sub = strLast.substr(0, index);
            //区域坐标
            plistBuffer->camerasPic.sAlarmRect.fHeight = atof(sub.c_str());
        }

    }

    string strTempFileName = g_strSavePictureSrc + "/" + strFileName;
    char cContent[plistBuffer->camerasPic.nBackgroundPicLen] = {0};
    ReadFile(strTempFileName, plistBuffer->camerasPic.nBackgroundPicLen, cContent);

    //检查内存是否符合大小
    g_pListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);
    //拷贝图片内存
    memcpy(plistBuffer->camerasPic.pBackBuffer, cContent, plistBuffer->camerasPic.nBackgroundPicLen);

    //从队列移除
    g_listStrSavePic.pop_front();
    if (!remove(strTempFileName.c_str()) == 0) {
        logError("delete file error!");
        return false;
    }
    return true;
}

bool SendQueue::ReadDHPicToBuffer(const PLIST_BUFFER plistBuffer, const string strFileName, char *p) {
    //type-ip-camerastime-programtime-backlen-facelen-facescore
    const char *sep = "-"; //可按多个字符来分割
    //char *p = nullptr;

    plistBuffer->camerasPic.nCamerasType = DAHUA;
    p = strtok(NULL, sep);
    if (p) {
        //IP地址
        memcpy(plistBuffer->camerasPic.cCameraIP, p, 16);
    }

    p = strtok(NULL, sep);
    if (p) {
        //相机时间
        plistBuffer->camerasPic.tCameraTime = atoll(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //接收时间
        plistBuffer->camerasPic.tProgramTime = atoll(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //背景图片长度
        plistBuffer->camerasPic.nBackgroundPicLen = atol(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //人脸图片长度
        plistBuffer->camerasPic.nFacePicLen = atol(p);
    }

    p = strtok(NULL, sep);
    if (p) {
        //人脸评分
        plistBuffer->camerasPic.nFaceScore = atoi(p);
    }


    string strTempBKFileName = g_strSavePictureSrc + "/" + strFileName + "-bk.jpg";
    string strTempFileName = g_strSavePictureSrc + "/" + strFileName + ".jpg";
    char cBKContent[plistBuffer->camerasPic.nBackgroundPicLen] = {0};
    char cContent[plistBuffer->camerasPic.nFacePicLen] = {0};
    ReadFile(strTempBKFileName, plistBuffer->camerasPic.nBackgroundPicLen, cBKContent);
    ReadFile(strTempFileName, plistBuffer->camerasPic.nFacePicLen, cContent);

    //检查内存是否符合大小
    g_pListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);
    //拷贝图片内存
    memcpy(plistBuffer->camerasPic.pBackBuffer, cBKContent, plistBuffer->camerasPic.nBackgroundPicLen);

    //检查内存是否符合大小
    g_pListThread->CheckBuffer(plistBuffer->camerasPic.nFacePicLen, FACE_PIC_TAG, plistBuffer);
    //拷贝图片内存
    memcpy(plistBuffer->camerasPic.pFaceBuffer, cContent, plistBuffer->camerasPic.nFacePicLen);

    //从队列移除
    g_listStrSavePic.pop_front();
    if (!remove(strTempBKFileName.c_str()) == 0) {
        logError("delete file error!");
        return false;
    }
    if (!remove(strTempFileName.c_str()) == 0) {
        logError("delete file error!");
        return false;
    }
    return true;
}

bool SendQueue::ReadFile(const string strFileName, const int nLength, char *cContent) {
    logDebug("strFileName:" + strFileName);
    //读取保存文件
    FILE *pfile;
    //打开写文件
    pfile = fopen(strFileName.c_str(), "rb+");
    if (!pfile) {
        logError("file open error!");
        return false;
    }
    //读文件
//    fseek(pfile, 0L, SEEK_END);
//    int len = ftell(pfile);
//    char cContent[len] = {0};
//    rewind(pfile);

    if (fread(cContent, 1, nLength, pfile) != nLength) {
        logError("file read error!");
        return false;
    }
    //关闭文件
    fclose(pfile);
    return true;
}

void SendQueue::OnGetCapPicToSend(const PLIST_BUFFER plistBuffer, const int nThreadID) {

    /**************************处理图片********************************************/

    logDebug("Thread" + to_string(nThreadID + 1) + "：Processing pictures!");

    int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
    printf("fd2=%d\n",fd2);
    char buf[200]={0};
    strcat(buf,"|");
    strcat(buf,getTimeofymd());
    strcat(buf,"|");
    strcat(buf,getTimeofh_m_s_ms());
    strcat(buf,"|");
    char fileSizeStr[20] = {0};
    sprintf(fileSizeStr,"%d",g_pListThread->stContent);
    strcat(buf,fileSizeStr);
    strcat(buf,"|");
    strcat(buf,"CAPTURE PHOTO|Processing cap pictures|gateway_id=");
    char gwId[10]={0};
    sprintf(gwId,"%d",gatewayId);
    strcat(buf,gwId);
    strcat(buf," camera_id=");
    char camId[10]={0};
    sprintf(camId,"%d",cameraId);
    strcat(buf,camId);
    strcat(buf," vendor=jvt|");
    write(fd2,buf,200);
    close(fd2);

    logDebug(plistBuffer->camerasPic.cCameraIP);

    //相机ID
    uint64 nID = g_CameraIP[plistBuffer->camerasPic.cCameraIP];
    logDebug(to_string(nID));

    PictureProtocol::SendCarMessage sendCarMessage;
    PictureProtocol::Head head;

    //相机ID
    sendCarMessage.set_camera_id(nID);
    //车牌评分
   //
    sendCarMessage.set_license_score(plistBuffer->camerasPic.nFaceScore);
    sendCarMessage.set_license_score(70);
    //printf("==========car plistBuffer->camerasPic.nFaceScore=%d\n",plistBuffer->camerasPic.nFaceScore);
    //车牌号码
    sendCarMessage.set_license_plate_num(plistBuffer->camerasPic.cLicense_plate_num);
    //车牌颜色
    //cout << to_string(plistBuffer->camerasPic.nLicense_plate_color) << "===="<<'\n';
    sendCarMessage.set_license_plate_color(to_string(plistBuffer->camerasPic.nLicense_plate_color));
    //车牌类型
    //cout <<to_string(plistBuffer->camerasPic.nLicense_plate_type)<<"**************"<<'\n';
    sendCarMessage.set_license_plate_type(to_string(plistBuffer->camerasPic.nLicense_plate_type));
    //车辆颜色
    //cout <<to_string(plistBuffer->camerasPic.nLicense_car_color)<<"#################"<<'\n';//车辆颜色要转换才正确
    sendCarMessage.set_license_car_color(to_string(plistBuffer->camerasPic.nLicense_car_color));
    //清空车牌子图
    sendCarMessage.set_license_plate_pic("", 0);

    int nWidth = 0;
    int nHeight = 0;
    GetCapCarRect(plistBuffer, &nWidth, &nHeight);

    //车牌子图对比图片坐标区域
    PictureProtocol::RectPicture *rectPictureLicense = new PictureProtocol::RectPicture();
    rectPictureLicense->set_x(plistBuffer->camerasPic.sLicense_rect.nLeft);
    rectPictureLicense->set_y(plistBuffer->camerasPic.sLicense_rect.nTop);

    int nLicenseWidth = 0;
    int nLicenseHight = 0;
    if (plistBuffer->camerasPic.nFacePicLen > 0) {

        nLicenseWidth =
                nWidth - plistBuffer->camerasPic.sLicense_rect.nLeft - plistBuffer->camerasPic.sLicense_rect.nRight;
        if (nLicenseWidth < 0)
            nLicenseWidth = 0;
        rectPictureLicense->set_width(nLicenseWidth);

        nLicenseHight =
                nHeight - plistBuffer->camerasPic.sLicense_rect.nTop - plistBuffer->camerasPic.sLicense_rect.nBottom;
        if (nLicenseHight < 0)
            nLicenseHight = 0;

        //车牌子图
        sendCarMessage.set_license_plate_pic(plistBuffer->camerasPic.pFaceBuffer, plistBuffer->camerasPic.nFacePicLen);
    }


    rectPictureLicense->set_height(nLicenseHight);
    sendCarMessage.set_allocated_rect_pic_license(rectPictureLicense);
    //相机抓拍时间
    sendCarMessage.set_camera_time(plistBuffer->camerasPic.tCameraTime);
    //程序推送照片时间
    sendCarMessage.set_program_time(plistBuffer->camerasPic.tProgramTime);
    //图片名称(三张图片名称相同,便于对应查找)
    string strUuid = OnGetUUID() + ".jpg";
    logDebug(strUuid);
    sendCarMessage.set_picture_name(strUuid);
    //背景图片;
    sendCarMessage.set_back_pic(plistBuffer->camerasPic.pBackBuffer, plistBuffer->camerasPic.nBackgroundPicLen);
    //背景图片大小
    PictureProtocol::RectPicture *rectPictureBack = new PictureProtocol::RectPicture();
    rectPictureBack->set_x(0);
    rectPictureBack->set_y(0);
    rectPictureBack->set_width(nWidth);
    rectPictureBack->set_height(nHeight);
    sendCarMessage.set_allocated_rect_pic_license(rectPictureBack);

    head.set_message_size(sendCarMessage.ByteSize());
    head.set_message_type(PictureProtocol::MessageType::SEND_CAR_MESSAGE);

    m_pServerInfo->SendPicture(head.SerializeAsString() + sendCarMessage.SerializeAsString());

    char Msg[1024] = { 0 };
    int size2=sendCarMessage.ByteSize();
    void *buffer=malloc(size2);
    sendCarMessage.SerializeToArray((void *) buffer, size2);;
    printf("size2=%d\n",size2);
    if (zmq_send(pSock2,buffer, size2,   0) < 0)
    {
        printf("serial send1 error\n");
    }
    zmq_recv(pSock2, Msg, sizeof(Msg), 0);
    printf("Msg=%s\n",Msg);
    free(buffer);
    buffer=NULL;

}

void SendQueue::SendMsg(const string strOut) {
    m_pServerInfo->SendPicture(strOut);
}

void SendQueue::GetCapCarRect(const PLIST_BUFFER plistBuffer, int *nWidth, int *nHeight) {
    if (plistBuffer->camerasPic.nBackgroundPicLen > 0) {
        vector<uchar> buffBack;

        //加载buffer
        copy(plistBuffer->camerasPic.pBackBuffer,
             plistBuffer->camerasPic.pBackBuffer + plistBuffer->camerasPic.nBackgroundPicLen,
             back_inserter(buffBack));
        if (buffBack.size() <= 0) {
            logError("Copy buffer error!");
            return;
        }
        //解码
        cv::Mat mat = cv::imdecode(buffBack, CV_LOAD_IMAGE_COLOR);
        IplImage img = IplImage(mat);

        *nWidth = img.width;
        *nHeight = img.height;
        logDebug("back picture width:" + to_string(*nWidth));
        logDebug("back picture height:" + to_string(*nHeight));
    }

}

void SendQueue::OnGetPicToSend(const PLIST_BUFFER plistBuffer, const int nThreadID) {

    /**************************处理图片********************************************/

    logDebug("Thread" + to_string(nThreadID + 1) + "：Processing pictures!");

    int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
    printf("fd2=%d\n",fd2);
    char buf[200]={0};
    strcat(buf,"|");
    strcat(buf,getTimeofymd());
    strcat(buf,"|");
    strcat(buf,getTimeofh_m_s_ms());
    strcat(buf,"|");
    char fileSizeStr[20] = {0};
    sprintf(fileSizeStr,"%d",g_pListThread->nFaceID);
    strcat(buf,fileSizeStr);
    strcat(buf,"|");
    strcat(buf,"PUSH PHOTO|Processing face pictures|gateway_id=");
    char gwId[10]={0};
    sprintf(gwId,"%d",gatewayId);
    strcat(buf,gwId);
    strcat(buf," camera_id=");
    char camId[10]={0};
    sprintf(camId,"%d",cameraId);
    strcat(buf,camId);
    strcat(buf," vendor=jvt|");
    write(fd2,buf,200);
    close(fd2);


    SEND_PICTURE_DATE sendPictureDate = {0};

    if (GetFaceFile(plistBuffer, &sendPictureDate, nThreadID) == -1) {
        logError("Get Face picture error!");

        int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
        printf("fd2=%d\n",fd2);
        char buf[200]={0};
        strcat(buf,"|");
        strcat(buf,getTimeofymd());
        strcat(buf,"|");
        strcat(buf,getTimeofh_m_s_ms());
        strcat(buf,"|");
        char fileSizeStr[20] = {0};
        sprintf(fileSizeStr,"%d",g_pListThread->nFaceID);
        strcat(buf,fileSizeStr);
        strcat(buf,"|");
        strcat(buf,"PUSH PHOTO|Get Face picture error|gateway_id=");
        char gwId[10]={0};
        sprintf(gwId,"%d",gatewayId);
        strcat(buf,gwId);
        strcat(buf," camera_id=");
        char camId[10]={0};
        sprintf(camId,"%d",cameraId);
        strcat(buf,camId);
        strcat(buf," vendor=jvt|");
        write(fd2,buf,200);
        close(fd2);

        return;
    }


    logDebug(plistBuffer->camerasPic.cCameraIP);

    //相机ID
    uint64 nID = g_CameraIP[plistBuffer->camerasPic.cCameraIP];
    logDebug(to_string(nID));

    PictureProtocol::SendFaceMessage sendFaceMessage;
    PictureProtocol::Head head;

    //相机ID
    sendFaceMessage.set_camera_id(nID);
    //人脸评分
    sendFaceMessage.set_face_score(plistBuffer->camerasPic.nFaceScore);

    //背景图片推送
    sendFaceMessage.set_back_pic(plistBuffer->camerasPic.pBackBuffer,
                                 plistBuffer->camerasPic.nBackgroundPicLen);

    sendFaceMessage.set_face_contrast_pic(plistBuffer->camerasPic.pFaceBuffer, sendPictureDate.nFaceLen);

    //sendFaceMessage.set_face_show_pic(plistBuffer->camerasPic.pShowBuffer, sendPictureDate.nShowLen);

    //区域大小
    PictureProtocol::RectPicture *rectPictureBak = new PictureProtocol::RectPicture();
    rectPictureBak->set_x(sendPictureDate.sBackRect.nX);
    rectPictureBak->set_y(sendPictureDate.sBackRect.nY);
    rectPictureBak->set_width(sendPictureDate.sBackRect.nWidth);
    rectPictureBak->set_height(sendPictureDate.sBackRect.nHeight);
    sendFaceMessage.set_allocated_rect_pic_back(rectPictureBak);

    PictureProtocol::RectPicture *rectPictureFace = new PictureProtocol::RectPicture();
    rectPictureFace->set_x(sendPictureDate.sFaceRect.nX);
    rectPictureFace->set_y(sendPictureDate.sFaceRect.nY);
    rectPictureFace->set_width(sendPictureDate.sFaceRect.nWidth);
    rectPictureFace->set_height(sendPictureDate.sFaceRect.nHeight);
    sendFaceMessage.set_allocated_rect_pic_face(rectPictureFace);

//    PictureProtocol::RectPicture *rectPictureShow = new PictureProtocol::RectPicture();
//    rectPictureShow->set_x(sendPictureDate.sShowRect.nX);
//    rectPictureShow->set_y(sendPictureDate.sShowRect.nY);
//    rectPictureShow->set_width(sendPictureDate.sShowRect.nWidth);
//    rectPictureShow->set_height(sendPictureDate.sShowRect.nHeight);
//    sendFaceMessage.set_allocated_rect_pic_show(rectPictureShow);

    sendFaceMessage.set_camera_time(plistBuffer->camerasPic.tCameraTime);
    sendFaceMessage.set_program_time(plistBuffer->camerasPic.tProgramTime);
    sendFaceMessage.set_send_time(time(0));
    string strUuid = OnGetUUID() + ".jpg";
    logDebug(strUuid);
    sendFaceMessage.set_picture_name(strUuid);

    head.set_message_size(sendFaceMessage.ByteSize());
    head.set_message_type(PictureProtocol::MessageType::SEND_FACE_MESSAGE);

    m_pServerInfo->SendPicture(head.SerializeAsString() + sendFaceMessage.SerializeAsString());

    char Msg[1024] = { 0 };
    int size2=sendFaceMessage.ByteSize();
    void *buffer=malloc(size2);
    sendFaceMessage.SerializeToArray((void *) buffer, size2);;
    printf("size2=%d\n",size2);
    if (zmq_send(pSock,buffer, size2,   0) < 0)
    {
        printf("serial send1 error\n");
    }
    zmq_recv(pSock, Msg, sizeof(Msg), 0);
    printf("Msg=%s\n",Msg);
    free(buffer);
    buffer=NULL;



#ifdef RECEIVE_SAVE_PICTURE
    //保存图片，推送mq
    OnGetPicToJSON(plistBuffer, &sendPictureDate, nThreadID, strUuid);
#endif

}

#ifdef RECEIVE_SAVE_PICTURE

void SendQueue::OnGetPicToJSON(const PLIST_BUFFER plistBuffer, const SEND_PICTURE_DATE *pSendPictureDate,
                               const int nThreadID, const string strUuid) {
    //判断挂载盘路径是否存在
    if (m_strNfsName.empty())
        return;

    //获取时间文件夹
    char cTime[100] = {0};
    //设置背景图片名称
    char cFilename[MAX_PATH] = {0};
    char cSendFilename[MAX_PATH] = {0};
    //设置人脸图片名称
    char cFacename[MAX_PATH] = {0};
    char cSendFacename[MAX_PATH] = {0};
    //设置本地挂载路径时间文件夹
    char cNfcFileTimeName[100] = {0};
    char cNfcFaceTimeName[100] = {0};

    time_t tProgramTime = plistBuffer->camerasPic.tProgramTime;
    tm *tm1 = gmtime(&tProgramTime);

    sprintf(cTime, "/%4.4d/%2.2d/%2.2d", tm1->tm_year + 1900, tm1->tm_mon + 1,
            tm1->tm_mday);

    logDebug(cTime);

    sprintf(cNfcFileTimeName, "%s/passerby/BackPic%s", m_strNfsName.c_str(), cTime);
    sprintf(cNfcFaceTimeName, "%s/passerby/FacePic%s", m_strNfsName.c_str(), cTime);


    //检查文件夹是否存在，若没有，创建
    if (!CreateFile(cNfcFileTimeName)) {
        logError("背景图片文件夹创建失败,数据丢弃！");
        return;
    }

    if (!CreateFile(cNfcFaceTimeName)) {
        logError("人脸图片文件夹创建失败,数据丢弃！");
        return;
    }

    //保存文件路径名称
    sprintf(cFilename, "%s/%s", cNfcFileTimeName, strUuid.c_str());
    sprintf(cFacename, "%s/%s", cNfcFaceTimeName, strUuid.c_str());

    //传送文件路径名称
    sprintf(cSendFilename, "passerby/BackPic%s/%s", cTime, strUuid.c_str());
    sprintf(cSendFacename, "passerby/FacePic%s/%s", cTime, strUuid.c_str());

    int nRes = SaveFaceFile(plistBuffer,pSendPictureDate, cFilename, cFacename, nThreadID);

    //保存图片
    if (-1 == nRes) {
        logError("图片保存出错,数据丢弃！");
        return;
    }

    //将参数传递到数组
    SEND_PICTURE_MSG SendPictureMsg;
    memcpy(SendPictureMsg.cCameraIP, plistBuffer->camerasPic.cCameraIP, 16);

    SendPictureMsg.dwFaceScore = plistBuffer->camerasPic.nFaceScore;

    memcpy(SendPictureMsg.cBackPicSrc, cSendFilename, MAX_PATH);
    memcpy(SendPictureMsg.cFacePicSrc, cSendFacename, MAX_PATH);
    //memcpy(SendPictureMsg.cShowFacePicSrc, cShowSendFacename, MAX_PATH);

    SendPictureMsg.tCameraTime = plistBuffer->camerasPic.tCameraTime;
    SendPictureMsg.tProgramTime = plistBuffer->camerasPic.tProgramTime;

    RECEIVE_PICTURE_SendJson(&SendPictureMsg);
}

#endif

int SendQueue::SaveFaceFile(const PLIST_BUFFER plistBuffer, const SEND_PICTURE_DATE *pSendPictureDate,
                            const char *cFilename, const char *cFacename, const int nThreadID) {
    //图片保存文件
    FILE *pfile;
    //打开写文件
    pfile = fopen(cFilename, "wb+");
    //写文件
    fwrite(plistBuffer->camerasPic.pBackBuffer, sizeof(unsigned char), plistBuffer->camerasPic.nBackgroundPicLen,
           pfile);
    //关闭文件
    fclose(pfile);

    char temp[100] = {0};
    sprintf(temp, "线程 %d: 背景图像已保存!", nThreadID);
    logDebug(temp);

    //打开写文件
    pfile = fopen(cFacename, "wb+");
    //写文件
    fwrite(plistBuffer->camerasPic.pFaceBuffer, sizeof(unsigned char), pSendPictureDate->nFaceLen,
           pfile);
    //关闭文件
    fclose(pfile);

    char temp1[100] = {0};
    sprintf(temp1, "线程 %d: 人脸图片已保存!", nThreadID);
    logDebug(temp1);

    return 1;
}

bool SendQueue::CreateFile(const char *pFile) {
    boost::filesystem::path filePath(pFile);   //初始化

    //查询文件夹是否存在,若不存在，则创建
    if (!boost::filesystem::exists(filePath)) {
        try {
            //挂载盘异常处理,若不存在挂载盘,捕获异常
            return boost::filesystem::create_directories(filePath);
        } catch (const std::exception &e) {
            logError(e.what());
            return false;
        }
    }

    return true;
}

void SendQueue::SetPictureRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate) {

    //边界框左上角点的X轴坐标，取值范围[0.001,1]
    float fX = plistBuffer->camerasPic.sAlarmRect.fX;
    int nX = (int) (fX * pSendPictureDate->sBackRect.nWidth);
    int nShowX = nX;//用于展示照片尺寸
    //边界框左上角点的Y轴坐标，取值范围[0.001,1]
    float fY = plistBuffer->camerasPic.sAlarmRect.fY;
    int nY = (int) (fY * pSendPictureDate->sBackRect.nHeight);
    int nShowY = nY;//用于展示照片尺寸
    //边界框的宽度，取值范围[0.001,1]
    float fWidth = plistBuffer->camerasPic.sAlarmRect.fWidth;
    int nWidth = (int) (fWidth * pSendPictureDate->sBackRect.nWidth);
    //边界框的高度，取值范围[0.001,1]
    float fHeight = plistBuffer->camerasPic.sAlarmRect.fHeight;
    int nHeight = (int) (fHeight * pSendPictureDate->sBackRect.nHeight);

    //获取左上角新坐标点
    nX = max((nX - PICTURE_MARGIN_LEFT), 0);
    nY = max((nY - PICTURE_MARGIN_TOP), 0);

    nShowX = max((nShowX - PICTURE_SHOW_MARGIN), 0);
    nShowY = max((nShowY - PICTURE_SHOW_MARGIN), 0);
    //获取右下角坐标点
    int nXR = min((nX + nWidth + PICTURE_MARGIN_LEFT + PICTURE_MARGIN_RIGHT), pSendPictureDate->sBackRect.nWidth);
    int nYR = min((nY + nHeight + PICTURE_MARGIN_TOP + PICTURE_MARGIN_BUTTON), pSendPictureDate->sBackRect.nHeight);

    int nShowXR = min((nShowX + nWidth + PICTURE_SHOW_MARGIN * 2), pSendPictureDate->sBackRect.nWidth);
    int nShowYR = min((nShowY + nHeight + PICTURE_SHOW_MARGIN * 2), pSendPictureDate->sBackRect.nHeight);

    //获取图片新的宽度和高度
    nWidth = nXR - nX;
    nHeight = nYR - nY;

    //设置人脸抓拍子图坐标
    pSendPictureDate->sFaceRect.nX = nX;
    pSendPictureDate->sFaceRect.nY = nY;
    pSendPictureDate->sFaceRect.nWidth = nWidth;
    pSendPictureDate->sFaceRect.nHeight = nHeight;

    nWidth = nShowXR - nShowX;
    nHeight = nShowYR - nShowY;

    //设置展示子图坐标
    pSendPictureDate->sShowRect.nX = nShowX;
    pSendPictureDate->sShowRect.nY = nShowY;
    pSendPictureDate->sShowRect.nWidth = nWidth;
    pSendPictureDate->sShowRect.nHeight = nHeight;
}

int SendQueue::GetFaceFile(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID) {
    if (plistBuffer->camerasPic.nCamerasType == HIKVISION  ||plistBuffer->camerasPic.nCamerasType ==NETDEV) {   //modify
        //检查区域大小
        if (CheckPictureRect(plistBuffer)) {
            //根据报警区域提取图片
            return GetAlarmRect(plistBuffer, pSendPictureDate, nThreadID);
        }

        return CopyAlarmRect(plistBuffer, pSendPictureDate, nThreadID);
    } else {
        // DAHUA JVT BEARHUNTING
//        if (plistBuffer->camerasPic.nCamerasType == DAHUA || plistBuffer->camerasPic.nCamerasType == JVT
//            || plistBuffer->camerasPic.nCamerasType == BEARHUNTING)
        return GetDahuaRect(plistBuffer, pSendPictureDate, nThreadID);
    }

}


int SendQueue::CopyAlarmRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID) {
    vector<uchar> buffBack;
    //加载buffer

    printf("before  modify  plistBuffer->camerasPic.nBackgroundPicLen=%d\n", plistBuffer->camerasPic.nBackgroundPicLen);
    printf("before  modify plistBuffer->nBackBufferSize=%d\n",plistBuffer->nBackBufferSize);
    //plistBuffer->camerasPic.nBackgroundPicLen=plistBuffer->nBackBufferSize;//xj  add  may  be not  correct
    copy(plistBuffer->camerasPic.pBackBuffer,
         plistBuffer->camerasPic.pBackBuffer + plistBuffer->camerasPic.nBackgroundPicLen,
         back_inserter(buffBack));
    if (buffBack.size() <= 0) {
        logError("Copy buffer error!");
        return -1;
    }

    //解码
    cv::Mat mat = cv::imdecode(buffBack, CV_LOAD_IMAGE_COLOR);
    IplImage img = IplImage(mat);
    //获取背景图片分辨率，填入数组
    pSendPictureDate->sBackRect.nX = 0;
    pSendPictureDate->sBackRect.nY = 0;
    pSendPictureDate->sBackRect.nWidth = img.width;
    pSendPictureDate->sBackRect.nHeight = img.height;
    logDebug("back picture width:" + to_string(pSendPictureDate->sBackRect.nWidth));
    logDebug("back picture height:" + to_string(pSendPictureDate->sBackRect.nHeight));

    //将人脸图片加入内存中
    //检查所要拷贝内存大小是否符合要求
    g_pListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, FACE_PIC_TAG, plistBuffer);
    logDebug("plistBuffer  nFaceBufferSize:"+to_string(plistBuffer->nFaceBufferSize));
    logDebug("plistBuffer   nBackgroundPicLen:"+to_string(plistBuffer->nBackBufferSize));
    //拷贝内存
//    memcpy(plistBuffer->camerasPic.pFaceBuffer, plistBuffer->camerasPic.pBackBuffer,
//           plistBuffer->camerasPic.nBackgroundPicLen);//xj  delete


    /*********************************add  begin************/
    vector<uchar> buffFace;
    printf("before  modify plistBuffer->camerasPic.nFacePicLen=%d\n",plistBuffer->camerasPic.nFacePicLen);
//    printf("before  modify plistBuffer->nFaceBufferSize=%d\n",plistBuffer->nFaceBufferSize);
//    plistBuffer->camerasPic.nFacePicLen=plistBuffer->nFaceBufferSize;//xj add ,may be  not  correct


    //加载buffer
    copy(plistBuffer->camerasPic.pFaceBuffer,
         plistBuffer->camerasPic.pFaceBuffer + plistBuffer->camerasPic.nFacePicLen,
         back_inserter(buffFace));




    if (buffFace.size() <= 0) {
        logError("Copy buffer 3 error!");
        return -1;
    }

    //解码
    cv::Mat matFace = cv::imdecode(buffFace, CV_LOAD_IMAGE_COLOR);
    IplImage imgFace = IplImage(matFace);

    pSendPictureDate->sFaceRect.nX = plistBuffer->camerasPic.sAlarmRect_JVT.nX;
    pSendPictureDate->sFaceRect.nY = plistBuffer->camerasPic.sAlarmRect_JVT.nY;
    pSendPictureDate->sFaceRect.nWidth = imgFace.width;
    pSendPictureDate->sFaceRect.nHeight = imgFace.height;
    logDebug("face picture width:" + to_string(pSendPictureDate->sFaceRect.nWidth));
    logDebug("face picture height:" + to_string(pSendPictureDate->sFaceRect.nHeight));
    pSendPictureDate->nFaceLen = plistBuffer->camerasPic.nFacePicLen;

//*****************************add end***********************************//






    //获取背景图片分辨率，填入数组
 /*   pSendPictureDate->sFaceRect.nX = 0;
    pSendPictureDate->sFaceRect.nY = 0;
    pSendPictureDate->sFaceRect.nWidth = img.width;
    pSendPictureDate->sFaceRect.nHeight = img.height;*/   //xj delete



    /*logDebug("face picture nwith:"+to_string(pSendPictureDate->sFaceRect.nWidth ));
    logDebug("face picture  nHeigh:"+to_string(pSendPictureDate->sFaceRect.nHeight));
    */   //xj delete

    //获取图片长度
    //pSendPictureDate->nFaceLen = plistBuffer->camerasPic.nBackgroundPicLen;//xj  delete
    //将展示图片加入内存中
    //检查所要拷贝内存大小是否符合要求
//    g_pListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, SHOW_PIC_TAG, plistBuffer);
//    //拷贝内存
//    memcpy(plistBuffer->camerasPic.pShowBuffer, plistBuffer->camerasPic.pBackBuffer,
//           plistBuffer->camerasPic.nBackgroundPicLen);
//    //获取背景图片分辨率，填入数组
//    pSendPictureDate->sShowRect.nX = 0;
//    pSendPictureDate->sShowRect.nY = 0;
//    pSendPictureDate->sShowRect.nWidth = img.width;
//    pSendPictureDate->sShowRect.nHeight = img.height;
//
//    //获取图片长度
//    pSendPictureDate->nShowLen = plistBuffer->camerasPic.nBackgroundPicLen;
    //释放
    mat.release();
    buffBack.clear();
    return 1;
}




int SendQueue::GetDahuaRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID) {
    vector<uchar> buffBack;
    vector<uchar> buffFace;
    //加载buffer
    copy(plistBuffer->camerasPic.pBackBuffer,
         plistBuffer->camerasPic.pBackBuffer + plistBuffer->camerasPic.nBackgroundPicLen,
         back_inserter(buffBack));
    if (buffBack.size() <= 0) {
        logError("Copy buffer 1 error!");
        return -1;
    }
    //加载buffer
    copy(plistBuffer->camerasPic.pFaceBuffer,
         plistBuffer->camerasPic.pFaceBuffer + plistBuffer->camerasPic.nFacePicLen,
         back_inserter(buffFace));
    if (buffFace.size() <= 0) {
        logError("Copy buffer 2 error!");
        return -1;
    }
    //解码
    cv::Mat mat = cv::imdecode(buffBack, CV_LOAD_IMAGE_COLOR);
    IplImage img = IplImage(mat);
    //获取背景图片分辨率，填入数组
    pSendPictureDate->sBackRect.nX = 0;
    pSendPictureDate->sBackRect.nY = 0;
    pSendPictureDate->sBackRect.nWidth = img.width;
    pSendPictureDate->sBackRect.nHeight = img.height;
    logDebug("back picture width:" + to_string(pSendPictureDate->sBackRect.nWidth));
    logDebug("back picture height:" + to_string(pSendPictureDate->sBackRect.nHeight));

    //解码
    cv::Mat matFace = cv::imdecode(buffFace, CV_LOAD_IMAGE_COLOR);
    IplImage imgFace = IplImage(matFace);

    pSendPictureDate->sFaceRect.nX = plistBuffer->camerasPic.sAlarmRect_JVT.nX;
    pSendPictureDate->sFaceRect.nY = plistBuffer->camerasPic.sAlarmRect_JVT.nY;
    pSendPictureDate->sFaceRect.nWidth = imgFace.width;
    pSendPictureDate->sFaceRect.nHeight = imgFace.height;
    logDebug("face picture width:" + to_string(pSendPictureDate->sFaceRect.nWidth));
    logDebug("face picture height:" + to_string(pSendPictureDate->sFaceRect.nHeight));
    pSendPictureDate->nFaceLen = plistBuffer->camerasPic.nFacePicLen;

    //释放
    mat.release();
    buffBack.clear();
    return 1;
}

int SendQueue::GetAlarmRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID) {
    try {
        //设置图片存储容器
        vector<uchar> buffFace;
        //vector<uchar> buffShow;
        vector<uchar> buffBack;

        //加载buffer
        copy(plistBuffer->camerasPic.pBackBuffer,
             plistBuffer->camerasPic.pBackBuffer + plistBuffer->camerasPic.nBackgroundPicLen,
             back_inserter(buffBack));
        if (buffBack.size() <= 0) {
            logError("Copy buffer error!");
            return -1;
        }
        //解码
        cv::Mat mat = cv::imdecode(buffBack, CV_LOAD_IMAGE_COLOR);
        IplImage img = IplImage(mat);
        //获取背景图片分辨率，填入数组
        pSendPictureDate->sBackRect.nX = 0;
        pSendPictureDate->sBackRect.nY = 0;
        pSendPictureDate->sBackRect.nWidth = img.width;
        pSendPictureDate->sBackRect.nHeight = img.height;
        logDebug("back picture width:" + to_string(pSendPictureDate->sBackRect.nWidth));
        logDebug("back picture height:" + to_string(pSendPictureDate->sBackRect.nHeight));
        //设置子图坐标区域
        SetPictureRect(plistBuffer, pSendPictureDate);

        cv::Mat TempImg;
        cv::Mat imageROI = mat(cv::Rect(pSendPictureDate->sFaceRect.nX, pSendPictureDate->sFaceRect.nY,
                                        pSendPictureDate->sFaceRect.nWidth,
                                        pSendPictureDate->sFaceRect.nHeight));    //设置待裁取ROI
        logDebug("pSendPictureDate->sFaceRect.nX:"+to_string(pSendPictureDate->sFaceRect.nX));
        logDebug("pSendPictureDate->sFaceRect.nY:"+to_string(pSendPictureDate->sFaceRect.nY));
        logDebug("pSendPictureDate->sFaceRect.nWidth:"+to_string(pSendPictureDate->sFaceRect.nWidth));
        logDebug("pSendPictureDate->sFaceRect.nHeight:"+to_string(pSendPictureDate->sFaceRect.nHeight));
        imageROI.convertTo(TempImg, TempImg.type());        //将ROI区域拷贝至dst

        cv::imencode(".jpg", TempImg, buffFace, m_param);
        pSendPictureDate->nFaceLen = buffFace.size();
        unsigned char tempBuff[pSendPictureDate->nFaceLen] = {0};
        int i = 0;
        for (auto m:buffFace) {
            //tempBuff[i] = m;
            memcpy(&tempBuff[i], &m, sizeof(unsigned char));
            i++;
        }

        //检查所要拷贝内存大小是否符合要求
        g_pListThread->CheckBuffer(pSendPictureDate->nFaceLen, FACE_PIC_TAG, plistBuffer);
        //拷贝内存
        memcpy(plistBuffer->camerasPic.pFaceBuffer, tempBuff, pSendPictureDate->nFaceLen);

//        imageROI = mat(cv::Rect(pSendPictureDate->sShowRect.nX, pSendPictureDate->sShowRect.nY,
//                                pSendPictureDate->sShowRect.nWidth, pSendPictureDate->sShowRect.nHeight));    //设置待裁取ROI
//        imageROI.convertTo(TempImg, TempImg.type());        //将ROI区域拷贝至dst
//        cv::imencode(".jpg", TempImg, buffShow, m_param);
//        pSendPictureDate->nShowLen = buffShow.size();
//        unsigned char tempBuff1[pSendPictureDate->nShowLen] = {0};
//        i = 0;
//        for (auto m:buffShow) {
//            memcpy(&tempBuff1[i], &m, sizeof(unsigned char));
//            i++;
//        }
//
//        g_pListThread->CheckBuffer(pSendPictureDate->nShowLen, SHOW_PIC_TAG, plistBuffer);
//
//        memcpy(plistBuffer->camerasPic.pShowBuffer, tempBuff1, pSendPictureDate->nShowLen);

        //释放
        TempImg.release();
        imageROI.release();
        mat.release();

        buffFace.clear();
        //buffShow.clear();
        buffBack.clear();

        return 1;
    } catch (const std::exception &e) {
        logError(e.what());
        return -1;
    }
}

bool SendQueue::CheckPictureRect(const PLIST_BUFFER plistBuffer) {
    const float EPSINON = 0.00001;
    logInfo("plistBuffer->camerasPic.sAlarmRect.fWidth=:"+to_string(plistBuffer->camerasPic.sAlarmRect.fWidth));
    logInfo("plistBuffer->camerasPic.sAlarmRect.fHeight=:"+to_string(plistBuffer->camerasPic.sAlarmRect.fHeight));
    if ((plistBuffer->camerasPic.sAlarmRect.fWidth >= -EPSINON) &&
        (plistBuffer->camerasPic.sAlarmRect.fWidth <= EPSINON) &&
        (plistBuffer->camerasPic.sAlarmRect.fHeight >= -EPSINON) &&
        (plistBuffer->camerasPic.sAlarmRect.fHeight <= EPSINON)) {
        //无报警区域
        return false;
    }
    return true;
}

void
SendQueue::CutPicture(char *Des, char *Src, const int nLeft, const int nTop, const int nWidth, const int nHeight,
                      const int nSrcWid, const int nSrcHei, const int nBit) {
    if ((nLeft + nWidth) > nSrcWid || (nTop + nHeight) > nSrcHei) {
        return;
    }
    char *pDes = Des;
    char *pSrc = Src;

    for (int i = 0; i < nHeight; i++) {
        memcpy(&pDes[i * nWidth * nBit], &pSrc[((i + nTop) * nSrcWid + nLeft) * nBit], nWidth * nBit);
    }
}
