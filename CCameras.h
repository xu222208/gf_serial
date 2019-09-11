//
// Created by hxd on 18-5-4.
//

#ifndef TESTPICTURE_CCAMERAS_H
#define TESTPICTURE_CCAMERAS_H

#include <thread>
#include "receive_car/CReceiveCar.h"
#include "double_list/SendQueue.h"

//相机信息结构体
typedef struct tag_FACE_CAMERA_MSG {

    int nType; //相机类型
    int nCapType;//相机抓拍类型标签
    uint64_t nID; //相机ID 唯一标识
    string strIP; //相机IP地址
    int nPort; //相机端口号
    string strUserName; //用户名
    string strPassword; //密码

} FACE_CAMERA_MSG;

//相机信息结构体
typedef struct tag_CAMERA_MSG {
    //相机类型标签
    int nTag;
    //相机类
    void *pCamera;
} CAMERA_MSG;


class CCameras {
public:
    CCameras(SendQueue *pSendQueue);

    ~CCameras();

    //销毁相机
    void OnDestoryCameras();

    //查询数据库并加载相机
    void OnGetJsonMsg(const string strPath);

    //发送相机状态
    void send_camera_state(string strIP, bool isState);

    void server_queue();


    void reconnect_idele_cameras(char  *buffer);
private:
    //初始化所有相机
    void OnInitCameras();

    //启动相机
    void OnSetCameras(const FACE_CAMERA_MSG *face_camera_msg);

    //设置相机回调
    void SetCallBack(int nType);

    //设置海康相机回调
    void SetHKCallBack();

    //设置大华相机回调
    void SetDHCallBack();

    //设置巨龙相机回调
    void SetJVTCallBack();

    //设置旷世相机回调
    void SetKSCallBack();

    //宇视相机回调
    void SetNETDEVCallBack();

    //文件监听线程
    void listen_file_changed();

    //大华相机时间监听线程
    void listen_dahua_cameras();

    //巨龙相机时间监听线程
    void listen_jvt_cameras();

    //旷世相机时间监听线程
    void listen_kuangshi_cameras();

    //宇视相机时间监听线程
    void listen_NETDEV_cameras();
    //获取相机类型标签
    void *GetCamera(const int nType, const FACE_CAMERA_MSG *face_camera_msg);

    //获取图片保存目录下的所有文件
    void getFiles();

    //相机重连线程
    void reconnect_cameras();




private:
    //存储相机信息，根据id查找相机信息
    map<uint64_t, CAMERA_MSG *> m_CameraMap;
    list<FACE_CAMERA_MSG> m_listCameraMsg;

    //创建文件监听线程对象
    boost::thread m_thread;
    boost::thread m_thread_sq;
    void th_server_queue();
    //创建掉线重连线程
    boost::thread m_threadReconnect;
    //设置重连线程标签
    bool m_isReconnect = true;


    //创建时间监听线程对象
    boost::thread m_threadTime;
    bool m_isRun = true;
    CReceiveCar *m_pReceiveCar = nullptr;//定义车牌抓拍接收线程对象
    //记录发送队列指针
    SendQueue *m_pSendQueue = nullptr;

};


#endif //TESTPICTURE_CCAMERAS_H
