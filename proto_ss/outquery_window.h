/*!
 * Created by carl on 16-10-13.
 *
 * 对 outquery 的处理
 *
 * 消息发送、确认的窗口
 * 一次发送多个，确认多个
 */


#ifndef SS_CLIENT2_CONF_WINDOWS_H
#define SS_CLIENT2_CONF_WINDOWS_H

#include "outquery.h"
#include <atomic>

class outquery_window : public outquery {
private:
    //! 最多能发送的消息 5 个. sends < send_max_size
    static const int send_max_size = 5;
    std::atomic_int sends;
//    int sends = 0;

public:
    outquery_window(int query_max_size);

    //! 获取一个发送消息
    bool get_one(TcpHead::Head &, TcpHead::Data &);

    //! 重置队列的发送数量
    void init() {sends = 0;}

    //! 按 id 删除记录
    void remove_by_id(int id);
};


#endif //SS_CLIENT2_CONF_WINDOWS_H
