//
// Created by carl on 18-7-10.
//

#ifndef FACEPICTURECLIENT_LISTOPERATION_H
#define FACEPICTURECLIENT_LISTOPERATION_H


#include <boost/thread/mutex.hpp>
#include <opencv2/core/types_c.h>
#include "list.h"

//告警区域坐标
typedef struct tagALARM_RECT {
    float fX;               //边界框左上角点的X轴坐标, 0.001~1
    float fY;               //边界框左上角点的Y轴坐标, 0.001~1
    float fWidth;           //边界框的宽度, 0.001~1
    float fHeight;          //边界框的高度, 0.001~1
} ALARM_RECT;

typedef struct tagALARM_RECT_JVT {
    int nX;               //边界框左上角点的X轴坐标
    int nY;               //边界框左上角点的Y轴坐标
    int nWidth;           //边界框的宽度
    int nHeight;          //边界框的高度
} ALARM_RECT_JVT;
//告警区域坐标
typedef struct tagALARM_CAP_RECT {
    int nLeft;               //距离左边界的宽度
    int nRight;              //距离右边界的宽度
    int nTop;                //距离上边界的宽度
    int nBottom;             //距离下边界的宽度
} ALARM_CAP_RECT;

// 缓冲区状态定义
typedef enum _BUFFER_STATUS {
    empty = 0,
    full,
    reset
} BUFFER_STATUS;

typedef void (*CLENA_FUNCTION)(PLIST_ENTRY, void *);

//相机信息结构体
typedef struct tag_RECEIVE_CAMERAS_PIC {
    int nCamerasType;        //设置相机类型标签
    int nCapType;            //设置相机抓拍标签，1为人脸抓拍，2为车牌抓拍
    char cCameraIP[16];            //相机IP地址
    uint32_t nFaceScore;        //人脸评分
    uint64_t nBackgroundPicLen; //背景图片长度
    uchar *pBackBuffer;     //背景图片
    uint64_t nShowPicLen; //展示子图长度
    uchar *pShowBuffer;     //web展示图片
    uint64_t nFacePicLen; //人脸子图长度
    uchar *pFaceBuffer;     //人脸子图片
    ALARM_RECT sAlarmRect;  //告警区域坐标
    ALARM_RECT_JVT sAlarmRect_JVT;//巨龙告警区域坐标
    time_t tCameraTime;     //获取相机推送照片时间戳
    time_t tProgramTime;       //插入缓存队列时间
    char cLicense_plate_num[50]; //车牌号码
    int nLicense_plate_color; //车牌颜色
    int nLicense_plate_type; //车牌类型
    int nLicense_car_color; //车辆颜色
    ALARM_CAP_RECT sLicense_rect;//车牌区域坐标
} RECEIVE_CAMERAS_PIC, *PRECEIVE_CAMERAS_PIC;

// 缓冲区信息
typedef struct _LIST_BUFFER {
    LIST_ENTRY list;
    BUFFER_STATUS status;
    RECEIVE_CAMERAS_PIC camerasPic;
    uint64_t nBackBufferSize;      // 背景图片缓冲区大小
    uint64_t nFaceBufferSize;      // 人脸子图片缓冲区大小
    uint64_t nShowBufferSize;    //展示子图图片缓冲区大小
} LIST_BUFFER, *PLIST_BUFFER;
//列表信息
typedef struct _OPERAT_LIST {
    LIST_ENTRY root;                      //满、空缓冲区队列
    boost::mutex io_mutex_list;          // 满、空队列使用的信号量
    u_int64_t size;                      // 当前队列大小
    CLENA_FUNCTION Clean;                // 清理函数
    void *pParam;                        // 清理函数的第二个参数
} OPERATE_LIST, *POPERATE_LIST;

class ListOperation {
public:
    ListOperation();

    ~ListOperation();

public:
    // 初始化链表
    void OperateLISTInit(POPERATE_LIST pList, CLENA_FUNCTION, void *);

    // 清理链表
    void OperateLISTRelease(POPERATE_LIST pList);

    // 加锁函数
    void OperateLock(POPERATE_LIST);

    // 解锁函数
    void OperateUnlock(POPERATE_LIST);

    // 首部插入
    void OperateInsert(POPERATE_LIST, PLIST_ENTRY);

    // 尾部移除
    PLIST_ENTRY OperateRemove(POPERATE_LIST);

    //头部移除
    PLIST_ENTRY OperateRemoveHead(POPERATE_LIST pList);
};


#endif //FACEPICTURECLIENT_LISTOPERATION_H
