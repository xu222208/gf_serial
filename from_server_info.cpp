//
// Created by carl on 16-11-8.
//

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "from_server_info.h"
#include "global.h"

from_server_info::from_server_info(inquery &inq_, outquery_window &outq_)
        : inq(inq_), outq(outq_) {
    thr = new boost::thread(boost::bind(&from_server_info::run, this));

    head.set_message_size(0);
    head.set_message_type(0);
}

from_server_info::~from_server_info() {
    stop();

    assert(thr);

    thr->join();
    delete thr;
    thr = nullptr;

}


void from_server_info::run() {
    while (!stop_flag) {
        if (inq.empty()) {
            sleep(1);
            continue;
        }

        Mess_point t = inq.get_first_();
        inq.pop_front();
        if (head.ParseFromArray(t->mess_info.c_str(), head.ByteSize())) {
            do_one_message(head, t->mess_info);
        } else {
            logError("error read head!");
        }
    }
}


void from_server_info::stop() {
    stop_flag = true;
}


void from_server_info::do_one_message(const PictureProtocol::Head &head_, const string &data) {
    std::size_t l = head_.message_size();
    if (l + head.ByteSize() > data.size()) {
        logError("error read data size:"+to_string(data.size()));
        return;
    }

    const char *data_p = data.c_str() + head.ByteSize();
    size_t len = head_.message_size();
    switch (head_.message_type()) {
            // 登入返回结果
        case PictureProtocol::MessageType::LOGIN_RESULT: {
            PictureProtocol::LoginResult info;
            if (info.ParseFromArray(data_p, len)) {
                if (info.flag() == PictureProtocol::LoginResult::Flag::LoginResult_Flag_ok) {
                    g_isLogin = true;
                    logDebug("Server login success!");
                } else {
                    g_isLogin = false;
                    logError("Server login failure!");
                    g_pTcpConf->stop();
                }
            } else {
                logError("error LOGIN_RESULT ParseFromArray!");
            }
            break;
        }
        default:
            logError("unkown message type." + to_string(head_.message_type()));
    }
}

void from_server_info::SendPicture(const string strOut) {
    outq.push_back(strOut);
}
