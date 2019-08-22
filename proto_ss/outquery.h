/*!
 * Created by carllu on 16-10-11.
 * 消息发出的队列
*/

#ifndef SS_CLIENT2_OUTQUERY_H
#define SS_CLIENT2_OUTQUERY_H

#include "info_query.h"
#include "tcp_conf_id.h"
#include "tcp_with_conf.pb.h"

class outquery : public info_query {
private:
    tcp_conf_id tcp_id;

public:
    outquery(int query_max_size);

    //! 数据流添加到队列里，并记录序列号
    bool push_back(const string &);

    //! 获得第一个数据，如果没有返回 false
    bool get_first(TcpHead::Head &, TcpHead::Data &);

    //! 按 id 删除记录
    virtual void remove_by_id(int id);
};


#endif //SS_CLIENT2_OUTQUERY_H
