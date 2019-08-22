//
// Created by carl on 18-9-30.
//

#ifndef FACEPICTURE_RECEIVEPICTURE_H
#define FACEPICTURE_RECEIVEPICTURE_H

#define __stdcall
#define RECEIVE_PICTURE

#include <string>

using namespace std;

#define MAX_PATH 255

////发送信息结构体
typedef struct Tag_SEND_PICTURE_MSG {
    //相机ID
    char cCameraIP[16];
    //人脸评分
    int dwFaceScore;
    //背景图片路径
    char cBackPicSrc[MAX_PATH];
    //人脸图片路径
    char cFacePicSrc[MAX_PATH];
    //人脸展示图片路径
    char cShowFacePicSrc[MAX_PATH];
    //相机图片推送时间
    time_t tCameraTime;
    //图片处理时间
    time_t tProgramTime;
} SEND_PICTURE_MSG;

//初始化接口
RECEIVE_PICTURE bool __stdcall RECEIVE_PICTURE_Init();
//注销接口
RECEIVE_PICTURE void __stdcall RECEIVE_PICTURE_Destroy();
//获取挂载盘路径
RECEIVE_PICTURE string __stdcall RECEIVE_PICTURE_GetNfsPath();
//推送MQ信息
RECEIVE_PICTURE void __stdcall RECEIVE_PICTURE_SendJson(const SEND_PICTURE_MSG *SendPictureMsg);
#endif //FACEPICTURE_RECEIVEPICTURE_H
