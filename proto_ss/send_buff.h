/*!
 *
   send_buff buf

   int i = 10;
   char *p = buf.get_buff(i);
   memset(p, 'a', i);
   buf.del_front(i);
 */
#ifndef SS_CLIENT2_SEND_BUFF_H
#define SS_CLIENT2_SEND_BUFF_H

#include "logcpp.h"
#include <iostream>
using namespace std;

class send_buff {
private:
    const static int buffsize_block = 1024*2500;
    //! 缓冲区大小
    std::size_t buffsize = 0;
    char * buff = nullptr;
    //! 有效数据, 写入的时候添加, 读出之后减少
    std::size_t data_len = 0;

    syslog_stream clog;

public:
    send_buff();
    ~send_buff();
    std::size_t get_buffsize();
    std::size_t get_data_size();

    //! 请求写入, 返回指针. date_len += l
    char * get_new_buff(std::size_t l);
    //! 写出数据, 减掉前面的数据
    void del_front(std::size_t l);
    const char * get_buff();

    // 初始化计数器
    void init();
};


#endif //SS_CLIENT2_SEND_BUFF_H
