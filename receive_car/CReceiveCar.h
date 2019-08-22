//
// Created by carl on 18-10-16.
//

#ifndef FACEPICTURECLIENT_CRECEIVECAR_H
#define FACEPICTURECLIENT_CRECEIVECAR_H

#include <zmq.h>
#include <boost/thread.hpp>

class CReceiveCar {
public:
    CReceiveCar();

    ~CReceiveCar();

private:
    //初始化接收相机抓拍服务
    bool InitReceiveCar();

    //车牌抓拍监听文件
    void receive_car_file();

    //设置车牌类型
    int setPlateType(int nType);

    //设置车牌颜色
    int setPlateColor(int nColor);

private:
    //设置zmq通信参数
    void *m_pCtx = nullptr;
    void *m_pSock = nullptr;
    //创建车牌监听线程对象
    boost::thread m_thread;
    //线程是否运行
    bool m_isRun = true;
};


#endif //FACEPICTURECLIENT_CRECEIVECAR_H
