/*!
 * Created by carllu on 16-10-11.
 * 收到消息的队列
 *
*/

#ifndef SS_CLIENT2_INQUERY_H
#define SS_CLIENT2_INQUERY_H

#include "info_query.h"
class inquery : public info_query {
public:
    inquery(int query_max_size);
};


#endif //SS_CLIENT2_INQUERY_H
