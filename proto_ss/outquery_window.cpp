//
// Created by carl on 16-10-13.
//

#include "outquery_window.h"


outquery_window::outquery_window(int query_max_size)
        : outquery(query_max_size) {
    sends = 0;
}


bool outquery_window::get_one(TcpHead::Head &head_, TcpHead::Data &data_) {
    LOCKCB;

    if (sends >= send_max_size ) {
#ifdef DEBUG
        cout << "send query send_max_size." << sends <<  endl;
#endif
        return false;
    }

    if( cb.empty() ){
#ifdef DEBUG
        cout << "outquery empty. sends =" << sends <<  endl;
#endif
        return false;
    }

    //! 移动指针到未读的记录
    /*auto p = cb.begin();
    for (auto i = 0; i < sends && p != cb.end(); ++p, ++i) {
    }
    if( p!= cb.end() ) {
        Mess_point t = *p;

        data_.clear_info();
        data_.set_info(t->mess_info);

        head_.set_message_id(t->mess_id);
        head_.set_message_type(TcpHead::Head::MessageType::Head_MessageType_Normal);
        head_.set_message_size(data_.ByteSize());

#ifdef DEBUG_C
        cout << "read from buff. id = " << t->mess_id << endl;
#endif
        sends++;

        return true;
    }*/

    //2018-3-22 alter by hxd
    //! 移动指针到未读的记录
    if(sends < cb.size()){
        auto p = cb[sends];
        Mess_point t = p;
        if(!t){
            return false;
        }

        data_.clear_info();
        data_.set_info(t->mess_info);

        head_.set_message_id(t->mess_id);
        head_.set_message_type(TcpHead::Head::MessageType::Head_MessageType_Normal);
        head_.set_message_size(data_.ByteSize());

#ifdef DEBUG
        cout << "read from buff. id = " << t->mess_id << endl;
        cout << "data ByteSize = " << data_.ByteSize() <<endl;
#endif
        sends++;

        return true;
    }
    return false;
}


void outquery_window::remove_by_id(int id){
    if (sends > 0)
        sends--;
#ifdef DEBUG
    cout << "remove id:" << id << " sends:" << sends << endl;
#endif
    outquery::remove_by_id(id);
}

