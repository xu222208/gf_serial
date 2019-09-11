//
// Created by carl on 18-7-10.
//

#ifndef FACEPICTURECLIENT_SENDQUEUE_H
#define FACEPICTURECLIENT_SENDQUEUE_H

#include <boost/thread/thread.hpp>
#include "../global.h"
#include "../from_server_info.h"
//人脸边框宽度
#define PICTURE_MARGIN_TOP    120
#define PICTURE_MARGIN_LEFT   40
#define PICTURE_MARGIN_RIGHT  40
#define PICTURE_MARGIN_BUTTON 30
//展示边框宽度
#define PICTURE_SHOW_MARGIN 32

#define THREAD_COUNT 1

//图片坐标区域
typedef struct tagPICTURE_RECT {
    int nX;       //图片左上角X轴坐标
    int nY;       //图片右上角Y轴坐标
    int nWidth;   //图片宽度
    int nHeight;  //图片高度
} PICTURE_RECT;

//记录发送图片数据
typedef struct tagSEND_PICTURE_DATE {
    PICTURE_RECT sBackRect; //背景图坐标区域
    PICTURE_RECT sFaceRect; //人脸子图坐标区域
    PICTURE_RECT sShowRect; //展示子图坐标区域
    int nFaceLen;           //人脸子图图片长度
    int nShowLen;           //展示子图图片长度
} SEND_PICTURE_DATE;

class SendQueue {
public:
    SendQueue(from_server_info *pServerInfo);

    ~SendQueue();
    void SendMsg(const string strOut);
private:
    //获取线程运行状态
    bool OnGetRun() { return m_isRun; };

    //设置现在运行状态
    void OnSetRun(bool isRun) { m_isRun = isRun; };

    //设置线程发送队列
    void send_queue(const int nThreadID);

    //设置车牌抓拍发送队列
    void send_cap_queue(const int nThreadID);

    //zmq server
    //void server_queue(const int nThreadID);//xj
    //处理图片并发送
    void OnGetPicToSend(const PLIST_BUFFER plistBuffer, const int nThreadID);

    //处理车牌抓拍图片并发送
    void OnGetCapPicToSend(const PLIST_BUFFER plistBuffer, const int nThreadID);

    //获取车牌抓拍图片大小
    void GetCapCarRect(const PLIST_BUFFER plistBuffer, int *nWidth, int *nHeight);

#ifdef RECEIVE_SAVE_PICTURE
    //保存图片，发送mq
    void OnGetPicToJSON(const PLIST_BUFFER plistBuffer, const SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID,
                        const string strUuid);
#endif

    //获取缓冲区数据
    void OnGetBuffer(const int nThreadID);

    void OnGetCapBuffer(const int nThreadID);

    //获取子图和长度
    int GetFaceFile(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID);

    //获取报警区域图片
    int GetAlarmRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID);

    //获取大华报警区域
    int GetDahuaRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID);

    //复制报警区域图片
    int CopyAlarmRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate, const int nThreadID);

    //检查区域大小
    bool CheckPictureRect(const PLIST_BUFFER plistBuffer);

    //裁剪图片
    void CutPicture(char *Des, char *Src, const int nLeft, const int nTop, const int nWidth, const int nHeight,
                    const int nSrcWid, const int nSrcHei, const int nBit);

    //设置子图图片区域
    void SetPictureRect(const PLIST_BUFFER plistBuffer, SEND_PICTURE_DATE *pSendPictureDate);

    //将读取的图片插入缓冲队列
    bool InsertPicToBuffer(const PLIST_BUFFER plistBuffer);

    //读取海康图片插入缓冲队列
    bool ReadHKPicToBuffer(const PLIST_BUFFER plistBuffer, const string strFileName, char *p);

    //读取大华图片插入缓冲队列
    bool ReadDHPicToBuffer(const PLIST_BUFFER plistBuffer, const string strFileName, char *p);

    //读取文件
    bool ReadFile(const string strFileName, const int nLength, char *cContent);

    //检查制定文件夹是否存在，若不存在，创建
    bool CreateFile(const char *pFile);

    //保存图片
    int SaveFaceFile(const PLIST_BUFFER plistBuffer, const SEND_PICTURE_DATE *pSendPictureDate, const char *cFilename,
                     const char *cFacename, const int nThreadID);

    //获取人脸抓拍队列
    void ReadFaceBuff(const int nThreadID);

    //获取车牌抓拍队列
    void ReadCapBuff(const int nThreadID);

private:
    //发送线程,发送循环列表信息
    list<boost::thread *> m_listThr;
    //设置线程启动表情
    bool m_isRun = true;
    //定义接收发送指针
    from_server_info *m_pServerInfo;

    //编码jpg图片质量
    vector<int> m_param;
    //记录挂载盘路径
    string m_strNfsName = "";
};


#endif //FACEPICTURECLIENT_SENDQUEUE_H
