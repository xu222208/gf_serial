//
// Created by carllu on 16-10-11.
//

#include "outquery.h"

outquery::outquery(int query_max_size)
        : info_query(query_max_size) {

}


bool outquery::push_back(const string &data_) {
    Mess_point t(new OneMessage());
    t->mess_id = tcp_id.get();
    t->mess_info = data_;
    return info_query::push_back(t);
}


bool outquery::get_first(TcpHead::Head &head_, TcpHead::Data &data_) {
    Mess_point t = get_first_();
    if (t == nullptr)
        return false;

    data_.clear_info();
    data_.set_info(t->mess_info);

    head_.set_message_id(t->mess_id);
    head_.set_message_type(TcpHead::Head::MessageType::Head_MessageType_Normal);
    head_.set_message_size(data_.ByteSize());

    return true;
}


void outquery::remove_by_id(int id) {
    LOCKCB;
    //2018.9.12 alter by hxd
    for (auto p = cb.begin(); p != cb.end(); ++p) {
        if( (*p)->mess_id == id ){
            cb.erase(p);
            break;
        }

    }
//    if( !cb.empty() ) {
//
//        auto p = cb.begin();
//        if( (*p)->mess_id == id )
//            cb.pop_front();
//    }
}