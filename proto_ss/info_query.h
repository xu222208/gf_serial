/*!

 消息进出的队列

Created by carllu on 16-10-10.

*/

#ifndef SS_CLIENT2_INFO_QUERY_H
#define SS_CLIENT2_INFO_QUERY_H

#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/shared_ptr.hpp>
#include <list>
#include <boost/circular_buffer.hpp>
#include "one_message.h"

using namespace std;

typedef one_message OneMessage;
typedef boost::shared_ptr<OneMessage> Mess_point;
class info_query {
protected:
    std::size_t max_query_size = 1024;
    boost::circular_buffer< Mess_point > cb;
#define LOCKCB boost::mutex::scoped_lock lock(mutex_cb)
    boost::mutex mutex_cb;

    boost::object_pool<Mess_point> op;

public:
    info_query(int query_max_size);

    //! 队列满，丢弃数据, 返回 false
    virtual bool push_back(const Mess_point &);
    Mess_point get_first_();

    virtual void pop_front();
    bool empty();

    void push_fornt(const Mess_point &);
};


#endif //SS_CLIENT2_INFO_QUERY_H
