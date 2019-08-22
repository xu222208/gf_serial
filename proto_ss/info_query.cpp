//
// Created by carllu on 16-10-10.
//

#include "info_query.h"


info_query::info_query(int query_max_size)
        : max_query_size(query_max_size), cb(query_max_size) {

}


bool info_query::push_back(const Mess_point &t) {

    LOCKCB;
    //! 重要信息, 队列已满,丢弃最前面一个.
    if (t->mess_id < 0 && cb.size() == max_query_size) {
#ifdef DEBUG
        cout << "insert login message. max_query_size." << endl;
#endif
        cb.pop_front();
    }

    if (cb.size() == max_query_size) {
#ifdef DEBUG
        cout << "error max_query_size." << endl;
#endif
        return false;
    }

    cb.push_back(t);
    return true;
}


Mess_point info_query::get_first_() {
    LOCKCB;
    if (cb.empty())
        return nullptr;

    cb.front();
    return cb.front();
}


void info_query::pop_front() {
    LOCKCB;
    if (!cb.empty())
        cb.pop_front();
}


bool info_query::empty() {
    LOCKCB;
    return cb.empty();
}


void info_query::push_fornt(const Mess_point &t) {
    LOCKCB;
    cb.push_front(t);
}
