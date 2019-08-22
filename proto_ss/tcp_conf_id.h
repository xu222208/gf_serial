/*!
 * Created by carl on 16-10-12.
 *
 * tcp conf 的序列号生成,
 * [TcpHead::Head::HeadInfo::Head_HeadInfo_Tcp_id_start, TcpHead::Head::HeadInfo::Head_HeadInfo_Tcp_id_max]*/

#ifndef SS_CLIENT2_TCP_CONF_ID_H
#define SS_CLIENT2_TCP_CONF_ID_H

#include "tcp_with_conf.pb.h"
#include <iostream>
#include <atomic>

using namespace std;

class tcp_conf_id {
private:
    std::atomic_int id;

public:
    tcp_conf_id() {
        init();
    }

    void init() {
        id = TcpHead::Head::HeadInfo::Head_HeadInfo_Tcp_id_start;
    };

    int get(){
        if( id > TcpHead::Head::HeadInfo::Head_HeadInfo_Tcp_id_max )
            init();
        return id++;
    }
};


#endif //SS_CLIENT2_TCP_CONF_ID_H
