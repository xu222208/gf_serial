//
// Created by carl on 16-10-12.
//

#include "one_message.h"
#include "info_query.h"

one_message::one_message() {
    init();
}


void one_message::init() {
    mess_id = 0;
    mess_info.clear();
}


bool one_message::update(const TcpHead::Head &head_, const TcpHead::Data &data_) {
    if (head_.IsInitialized() && data_.IsInitialized()) {
        mess_id = head_.message_id();
        mess_info = data_.info();
/*
#ifdef DEBUG_C
        for(auto i=0; i<mess_info.size(); i++){
            cout << (int) *(mess_info.c_str()+i) << " ";
        }
        cout << endl;
#endif
*/
        return true;
    }
    return false;
}


void one_message::get(TcpHead::Head &head_, TcpHead::Data &data_){
    data_.set_info(mess_info);

    head_.set_message_id(mess_id);
    head_.set_message_type(TcpHead::Head_MessageType_Normal);
    head_.set_message_size(data_.ByteSize());
}