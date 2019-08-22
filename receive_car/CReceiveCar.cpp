//
// Created by carl on 18-10-16.
//

#include "CReceiveCar.h"
#include "../CBase64.h"
#include "../log4cpp/CLog.h"
#include "../global.h"

CReceiveCar::CReceiveCar() {
    if (!InitReceiveCar()) {
        logError("start receive car serveres error and restart!!!");
    }
}

CReceiveCar::~CReceiveCar() {
    //退出线程
    m_isRun = false;
    m_thread.join();
    //是否接口
    if (m_pSock)
        zmq_close(m_pSock);

    if (m_pCtx)
        zmq_ctx_destroy(m_pCtx);

}

bool CReceiveCar::InitReceiveCar() {
    //const char *pAddr = "tcp://*:7766";
    const char *pAddr = "tcp://127.0.0.1:7766";

    //创建context，zmq的socket 需要在context上进行创建
    if ((m_pCtx = zmq_ctx_new()) == nullptr) {
        logError("zmq_ctx_new error");
        return false;
    }
    //创建zmq socket ，socket目前有6中属性 ，这里使用dealer方式
    //具体使用方式请参考zmq官方文档（zmq手册）
    if ((m_pSock = zmq_socket(m_pCtx, ZMQ_DEALER)) == nullptr) {
        zmq_ctx_destroy(m_pCtx);
        logError("zmq_socket error");
        return false;
    }
    int iRcvTimeout = 5000;// millsecond
    //设置zmq的接收超时时间为5秒
    if (zmq_setsockopt(m_pSock, ZMQ_RCVTIMEO, &iRcvTimeout, sizeof(iRcvTimeout)) < 0) {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        logError("zmq_setsockopt error");
        return false;
    }
    //绑定地址 tcp://*:7766
    //也就是使用tcp协议进行通信，使用网络端口 7766
    if (zmq_bind(m_pSock, pAddr) < 0) {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        logError("zmq_bind error");
        return false;
    }

    //启动接收线程
    m_thread = boost::thread(boost::bind(&CReceiveCar::receive_car_file, this));
    return true;
}

void CReceiveCar::receive_car_file() {
    while (m_isRun) {
        int nLength = 1024000;
        char szMsg[nLength] = {0};
        errno = 0;

        //循环等待接收到来的消息，当超过10秒没有接到消息时，
        //zmq_recv函数返回错误信息 ，并使用zmq_strerror函数进行错误定位
        int nRecv = zmq_recv(m_pSock, szMsg, nLength, 0);

        if (nRecv <= 0) {
            continue;
        }
        logDebug("车牌接收字节:" + to_string(nRecv));
        Document document;
        try {
            document.Parse(szMsg, nRecv);

            if (document.HasParseError()) {
                logError("GetParseError " + to_string(document.GetParseError()));
                continue;
            }
        } catch (const std::exception &e) {
            logError("Json format error!");
            continue;
        }

        PLIST_BUFFER plistBuffer;
        //获取空队列
        g_pCarListThread->GetBuffer(&plistBuffer, empty);
        if (plistBuffer == nullptr) {
            //若空队列为空,获取满队列地址
            logDebug("The car data is full and the original data is discarded!");
            //g_pListThread->GetHeadBuffer(&plistBuffer, full);
            g_pCarListThread->GetBuffer(&plistBuffer, full);
            //获取内存图片并保存
            SaveFaceFile(plistBuffer, ANSPO_CAR);
        }
        if (plistBuffer) {
            if (document.IsObject()) {
                const Value &cur_car_picture = document;

//                int nManufacturersType = 0;
//                auto manufacturersType = cur_car_picture.FindMember("manufacturersType");
//                if (manufacturersType != cur_car_picture.MemberEnd())
//                    nManufacturersType = cur_car_picture["manufacturersType"].GetInt();

                auto camereTime = cur_car_picture.FindMember("cameraTime");
                if (camereTime != cur_car_picture.MemberEnd())
                    //相机抓拍时间
                    plistBuffer->camerasPic.tCameraTime = cur_car_picture["cameraTime"].GetInt64();

                auto carColor = cur_car_picture.FindMember("carColor");
                if (carColor != cur_car_picture.MemberEnd())
                    //车辆颜色 保留字段 暂无
                    plistBuffer->camerasPic.nLicense_car_color = cur_car_picture["carColor"].GetInt();

                auto carType = cur_car_picture.FindMember("carType");
                if (carType != cur_car_picture.MemberEnd())
                    //车牌类型
                    plistBuffer->camerasPic.nLicense_plate_type = setPlateType(cur_car_picture["carType"].GetInt());

                auto confidenceScore = cur_car_picture.FindMember("confidenceScore");
                if (confidenceScore != cur_car_picture.MemberEnd())
                    //车牌评分
                    plistBuffer->camerasPic.nFaceScore = cur_car_picture["confidenceScore"].GetInt();

                auto creatime = cur_car_picture.FindMember("createTime");
                if (creatime != cur_car_picture.MemberEnd())
                    //程序推送照片时间
                    plistBuffer->camerasPic.tProgramTime = cur_car_picture["createTime"].GetInt64();

                auto imageFileBack_picLen = cur_car_picture.FindMember("imageFileBackPicLen");
                if (imageFileBack_picLen != cur_car_picture.MemberEnd())
                    //图片长度
                    plistBuffer->camerasPic.nBackgroundPicLen = cur_car_picture["imageFileBackPicLen"].GetInt();

                if (plistBuffer->camerasPic.nBackgroundPicLen > 0) {
                    //检查内存是否符合大小
                    g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nBackgroundPicLen, BAKE_PIC_TAG, plistBuffer);

                    auto imageFileBack_pic = cur_car_picture.FindMember("imageFileBackPic");
                    if (imageFileBack_pic != cur_car_picture.MemberEnd()) {
                        //图片进行base64解码
                        CBase64 base64;
                        base64.Decode(cur_car_picture["imageFileBackPic"].GetString(),
                                      plistBuffer->camerasPic.pBackBuffer,
                                      &plistBuffer->camerasPic.nBackgroundPicLen);
                    }

                }


                auto imageFragmentFileLen = cur_car_picture.FindMember("imageFragmentFileLen");
                if (imageFragmentFileLen != cur_car_picture.MemberEnd())
                    //图片长度
                    plistBuffer->camerasPic.nFacePicLen = cur_car_picture["imageFragmentFileLen"].GetInt();

                if (plistBuffer->camerasPic.nFacePicLen) {
                    //检查内存是否符合大小
                    g_pCarListThread->CheckBuffer(plistBuffer->camerasPic.nFacePicLen, FACE_PIC_TAG, plistBuffer);

                    auto imageFragmentFile = cur_car_picture.FindMember("imageFragmentFile");
                    if (imageFragmentFile != cur_car_picture.MemberEnd()) {
                        CBase64 base64;
                        //图片进行base64解码
                        base64.Decode(cur_car_picture["imageFragmentFile"].GetString(),
                                      plistBuffer->camerasPic.pFaceBuffer,
                                      &plistBuffer->camerasPic.nFacePicLen);
                    }

                }

                auto ipaddr = cur_car_picture.FindMember("ipAddress");
                if (ipaddr != cur_car_picture.MemberEnd())
                    //IP地址
                    memcpy(plistBuffer->camerasPic.cCameraIP, cur_car_picture["ipAddress"].GetString(), 16);

                auto license = cur_car_picture.FindMember("license");
                if (license != cur_car_picture.MemberEnd())
                    //车牌
                    memcpy(plistBuffer->camerasPic.cLicense_plate_num, cur_car_picture["license"].GetString(), 50);

                auto location = cur_car_picture.FindMember("location");
                if (location != cur_car_picture.MemberEnd()) {
                    //坐标区域
                    if (cur_car_picture["location"].IsObject()) {
                        const Value &cur_car_rect = cur_car_picture["location"];
                        auto bottom = cur_car_rect.FindMember("bottom");
                        if (bottom != cur_car_rect.MemberEnd())
                            plistBuffer->camerasPic.sLicense_rect.nBottom = cur_car_rect["bottom"].GetInt();
                        auto left = cur_car_rect.FindMember("left");
                        if (left != cur_car_rect.MemberEnd())
                            plistBuffer->camerasPic.sLicense_rect.nLeft = cur_car_rect["left"].GetInt();
                        auto right = cur_car_rect.FindMember("right");
                        if (right != cur_car_rect.MemberEnd())
                            plistBuffer->camerasPic.sLicense_rect.nRight = cur_car_rect["right"].GetInt();
                        auto top = cur_car_rect.FindMember("top");
                        if (top != cur_car_rect.MemberEnd())
                            plistBuffer->camerasPic.sLicense_rect.nTop = cur_car_rect["top"].GetInt();
                    }
                }

                auto typeColor = cur_car_picture.FindMember("typeColor");
                if (typeColor != cur_car_picture.MemberEnd())
                    //车牌颜色
                    plistBuffer->camerasPic.nLicense_plate_color = setPlateColor(cur_car_picture["typeColor"].GetInt());

            }

            //放入满队列
            g_pCarListThread->PutBuffer(plistBuffer, full);
            char buf[100] = {0};
            //图片放入缓冲区，写入日志
            sprintf(buf, "%s:picture inster double list!", plistBuffer->camerasPic.cCameraIP);
            logInfo(buf);

        }
    }
}

int CReceiveCar::setPlateType(int nType) {
    int nPlateType = 1;
    switch (nType) {
        case 0:
            nPlateType = LICENSE_OTHER;
            break;
        case 1:
            nPlateType = LICENSE_SMALL_CAR;
            break;
        case 2:
            nPlateType = LICENSE_SMALL_CAR;
            break;
        case 3:
            nPlateType = LICENSE_LARGE_CAR;
            break;
        case 4:
            nPlateType = LICENSE_LARGE_CAR;
            break;
        case 5:
            nPlateType = LICENSE_POLICE_CAR;
            break;
        case 6:
            nPlateType = LICENSE_ARMED_POLICE;
            break;
        case 7:
            nPlateType = LICENSE_ARMED_POLICE;
            break;
        case 8:
            nPlateType = LICENSE_ARMY;
            break;
        case 9:
            nPlateType = LICENSE_ARMY;
            break;
        case 11:
            nPlateType = LICENSE_SMALL_CAR;
            break;
        case 12:
            nPlateType = LICENSE_LARGE_CAR;
            break;
        case 13:
            nPlateType = LICENSE_EMBASSY_CAR;
            break;
        case 14:
            nPlateType = LICENSE_CONSULATE_CAR;
            break;
        default:
            nPlateType = LICENSE_OTHER;
            break;
    }

    return nPlateType;
}

int CReceiveCar::setPlateColor(int nColor) {
    int nColorType = 1;
    switch (nColor) {
        case 1:
            nColorType = COLOUR_BLUE;
            break;
        case 2:
            nColorType = COLOUR_YELLOW;
            break;
        case 3:
            nColorType = COLOUR_WHITE;
            break;
        case 4:
            nColorType = COLOUR_BLACK;
            break;
        case 5:
            nColorType = COLOUR_GREEN;
            break;
        case 6:
            nColorType = COLOUR_OTHER;
            break;
        default:
            nColorType = COLOUR_OTHER;
            break;
    }

    return nColorType;
}