//
// Created by carl on 16-10-18.
//

#include "send_buff.h"
#include <iostream>
#include <cstring>

send_buff::send_buff() {
    buff = new char[buffsize_block];
    buffsize = buffsize_block;
}


send_buff::~send_buff() {
    if (buff != nullptr) {
#ifdef DEBUG
        std::cout << "~send_buff" << std::endl;
#endif
        delete[]buff;
    }
}


std::size_t send_buff::get_buffsize() {
    return buffsize;
}


std::size_t send_buff::get_data_size() {
    return data_len;
}

char *send_buff::get_new_buff(size_t l) {
    if ((data_len + l) >= buffsize) {
#ifdef DEBUG
        std::cout << "renew send buff" << std::endl;
#endif
        std::size_t t_buffsize = buffsize;
        std::size_t b = (data_len + l) / buffsize_block + 1;
        buffsize = b * buffsize_block;
        char *buff_2 = new char[buffsize];
        memcpy(buff_2, buff, t_buffsize);
        if(buff){
            delete[]buff;
            buff = nullptr;
        }

        buff = buff_2;
    }

    size_t t = data_len;
    data_len += l;

#ifdef DEBUG
    cout << "buffer原始长度: " << t << endl;
#endif
    return buff + t;
}

const char *send_buff::get_buff() {
    return buff;
}

void send_buff::del_front(std::size_t l) {

    if (l > data_len) {
        clog << mylog::level::error << "send_buff::del_front l=" << l << " data_len=" << data_len << endl;
#ifdef DEBUG
        cout << "error: " << "send_buff::del_front l=" << l << " data_len=" << data_len << endl;
#endif
        data_len = 0;
    } else if (l == data_len) {
        data_len = 0;
    } else {
        size_t k = data_len - l;
        memcpy(buff, buff + l, k);
        data_len = k;
    }
#ifdef DEBUG
    cout << "l = " << l << "\t" << " data_len = " << data_len << endl;
#endif
}


void send_buff::init() {
    data_len = 0;
}