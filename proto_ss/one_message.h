//
// Created by carl on 16-10-12.
//

#ifndef SS_CLIENT2_ONE_MESSAGE_H
#define SS_CLIENT2_ONE_MESSAGE_H

#include <string>
#include "tcp_with_conf.pb.h"
using namespace std;

class one_message {
public:
    int32_t mess_id;
    string mess_info;

    void init();
    one_message();
    //! 接收到的信息，写入结构
    bool update(const TcpHead::Head &, const TcpHead::Data &);
    //! 结果返回给结构
    void get(TcpHead::Head &, TcpHead::Data &);
};


#endif //SS_CLIENT2_ONE_MESSAGE_H
