/*!
 * Created by carl on 16-11-8.
 *
 * 服务器来的信息处理
*/

#ifndef M22UBUNTU_FROM_SERVER_INFO_H
#define M22UBUNTU_FROM_SERVER_INFO_H

#include <iostream>
#include "protoc/SendPictureProtocol.pb.h"
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include "proto_ss/outquery_window.h"
#include "proto_ss/inquery.h"

using namespace std;


class from_server_info {

public:
    from_server_info(inquery &inq_, outquery_window &outq_);

    ~from_server_info();

    void SendPicture(const string strOut);
private:
    void run();

    void stop();

    void do_one_message(const PictureProtocol::Head &, const string &);

private:
    inquery &inq;
    outquery_window &outq;
    boost::thread *thr = nullptr;
    bool stop_flag = false;
    PictureProtocol::Head head;
};


#endif //M22UBUNTU_FROM_SERVER_INFO_H
