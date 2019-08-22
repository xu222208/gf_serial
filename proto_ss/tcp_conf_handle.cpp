//
// Created by carl on 10/4/16.
//

#include "tcp_conf_handle.h"


tcp_conf_handle::tcp_conf_handle(boost::asio::io_service &io_service_,
                                 const char host_[50], int port_,
                                 inquery &inq_, outquery_window &outq_)
        : io_service(io_service_),
          port(port_),
          inq(inq_),
          outq(outq_),
          reconnect_run_dead(io_service_, boost::posix_time::seconds(first_connect_time)),
          ping_run_dead(io_service_, boost::posix_time::seconds(loop_ping_time)),
          send_run_dead(io_service_, boost::posix_time::milliseconds(loop_send_time)) {
    host = host_;

    init_sock();
    if (read_buff == nullptr) {
        read_buff = new char[TcpHead::Head::HeadInfo::Head_HeadInfo_Tcp_size_max];
        if (read_buff == nullptr) {
            cerr << "error new char tcp_conf_handle::tcp_conf_handle" << endl;
            exit(1);
        }
    }
    init_head();
    reconnect_run_dead.async_wait(
            boost::bind(&tcp_conf_handle::loop_reconnect, this, boost::asio::placeholders::error));
    ping_run_dead.async_wait(boost::bind(&tcp_conf_handle::ping_run, this, boost::asio::placeholders::error));
    send_run_dead.async_wait(boost::bind(&tcp_conf_handle::send_run, this, boost::asio::placeholders::error));
}


tcp_conf_handle::~tcp_conf_handle() {
    stop();
    sleep(1);       // 等待消息结束

    if (socket_ != nullptr) {
        delete socket_;
        delete ctx_;
    }

    if (read_buff != nullptr) {
        delete read_buff;
        read_buff = nullptr;
    }
}


void tcp_conf_handle::init_head() {
    head.set_message_size(0);
    head.set_message_type(0);
    head.set_message_id(0);
    head_length = head.ByteSize();
}


void tcp_conf_handle::send(const string &info) {
    boost::asio::async_write(*socket_,
                             boost::asio::buffer(info.c_str(), info.length()),
                             boost::bind(&tcp_conf_handle::handle_write, this,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
}


void tcp_conf_handle::handle_write(const boost::system::error_code &error,
                                   size_t bytes_transferred) {
    if (error.value() == 0) {
        // 延后 ping
        ping_run_dead_change_expires();

        need_send_bytes -= bytes_transferred;

        s_buff.del_front(bytes_transferred);
#ifdef DEBUG
        cout << "write: " << bytes_transferred << "\t"
             << "need_send_bytes: " << need_send_bytes
             << endl;
#endif
        // 发送剩余数据
        send_data();

    } else {
#ifdef DEBUG
        std::cout << "Write failed: " << error.message()
                  << " bytes_transferred: " << bytes_transferred
                  << std::endl;
#endif
        set_disconnect();
    }
}


void tcp_conf_handle::set_disconnect() {
    need_send_bytes = 0;
    head_flag = true;
    connect = Disconnect;
    wait_conf_times = 0;
    //还原接收计数器
    m_nReciveCount = 1;
    set_wait_conf(false);
}


void tcp_conf_handle::set_connwcttwithconf() {
#ifdef DEBUG
    cout << "tcp_conf_handle::set_connwcttwithconf." << endl;
#endif
    connect = ConnectWithConf;

    //! 发送队列重置
    outq.init();

    //! login 消息放在第一个
    push_fornt_login_data();

    // 重置发送队列
    need_send_bytes = 0;
    // 接收到确认回复，　重置计数器
    wait_conf_times = 0;
}


bool tcp_conf_handle::isConnect() {
    return connect == ConnectWithConf;
}


void tcp_conf_handle::handle_connect(const boost::system::error_code &error) {
    if (!error) {
#ifdef DEBUG
        cout << "connected." << endl;
#endif
        connect = StartConnect;
        // 启动读取头
//        start_read_head();
        socket_->async_handshake(boost::asio::ssl::stream_base::client,
                                 boost::bind(&tcp_conf_handle::handle_handshake, this,
                                             boost::asio::placeholders::error));
    } else {
        connect = Disconnect;
#ifdef DEBUG
        cout << "connect fail." << endl;
#endif
    }
}


void tcp_conf_handle::write_0(const TcpHead::Head &head, const google::protobuf::Message &info) {
    if (!run_flag)
        return;
    LOCKCB_BUFF;
//    char *p = s_buff.get_new_buff(head.ByteSize());
//    head.SerializeToArray(p, head.ByteSize());
//    p = s_buff.get_new_buff(info.ByteSize());
//    info.SerializeToArray(p, info.ByteSize());
    size_t nHead = head.ByteSize();
    size_t nInfo = info.ByteSize();
    char *p = s_buff.get_new_buff(nHead + nInfo);
    head.SerializeToArray(p, nHead);
    info.SerializeToArray(p + nHead, nInfo);

#ifdef DEBUG
    cout << "write_0 head:" << nHead << endl;
    cout << "write_0 info:" << nInfo << endl;
    cout << "write_0." << endl;
#endif
    send_data();

}


void tcp_conf_handle::send_data() {
    if (!run_flag)
        return;
    //表示发送数据完毕，设置标签，开始计数
    if (m_isSendDate && s_buff.get_data_size() == 0) {
        wait_conf_times = 0;
        set_wait_conf(true);
    }

    if (s_buff.get_data_size() > 0) {
        need_send_bytes = s_buff.get_data_size();
#ifdef DEBUG
        cout << "send !!!  size: " << s_buff.get_data_size() << endl;
        send_t.restart();
#endif

#ifdef DEBUG
        //        auto p = s_buff.get_buff();
        //        auto l = s_buff.get_data_size();
        //        char buff[16];
        //        for (auto i = 0; i < l; ++i) {
        //            sprintf(buff, "%02x ", *(p + i));
        //            cout << buff;
        //        }
        //        cout << endl;
#endif
        boost::asio::async_write(*socket_,
                                 boost::asio::buffer(s_buff.get_buff(), s_buff.get_data_size()),
                                 boost::bind(&tcp_conf_handle::handle_write, this,
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }
}

void tcp_conf_handle::handle_read(const boost::system::error_code &error, size_t bytes_transferred) {
    if (!error) {
        // 延后 ping
        ping_run_dead_change_expires();

        if (head_flag) {
            if (bytes_transferred == 0)
                return;

            try {
                if (head.ParseFromArray(read_buff, bytes_transferred)) {
                    int l = head.message_size();
                    boost::asio::async_read(*socket_, boost::asio::buffer(read_buff, l),
                                            boost::bind(&tcp_conf_handle::handle_read, this,
                                                        boost::asio::placeholders::error,
                                                        boost::asio::placeholders::bytes_transferred));
                    head_flag = false;
                } else {
#ifdef DEBUG
                    cout << "error handle_read head.ParseFromArray" << endl;
#endif
/*
                    //carl
                    set_disconnect();
                    stop();
*/
                    return;
                }
            }
            catch (const std::exception &e) {
#ifdef DEBUG
                cout << "error handle_read:  " << e.what() << endl;
#endif
                clog << mylog::info << e.what() << endl;
                set_disconnect();
                return;
            }
        }//---- endof head
        else {
#ifdef DEBUG
            cout << "recive from server. type: " << head.message_type() << " size:" << head.message_size() << endl;
#endif
            do_one_message();

            // 读出头内容
            start_read_head();
        }
    }

}


::google::protobuf::Message *tcp_conf_handle::newinfoclass(u_int type) {
    switch (type) {
        case TcpHead::Head::MessageType::Head_MessageType_Normal : {
            return new TcpHead::Data();
        };

        case TcpHead::Head::MessageType::Head_MessageType_connect_conf : {
            return new TcpHead::Connect_conf();
        };

        case TcpHead::Head::MessageType::Head_MessageType_Conf_message : {
            return new TcpHead::Conf();
        };

        default:
            return nullptr;
    }
}


void tcp_conf_handle::loop_reconnect(const boost::system::error_code &error) {
    if (run_flag) {

#ifdef DEBUG
        cout << "dida" << endl;
#endif

        // 重连
        reconnect();

        // 继续转圈
        reconnect_run_dead.expires_from_now(boost::posix_time::seconds(loop_run_time));
        reconnect_run_dead.async_wait(
                boost::bind(&tcp_conf_handle::loop_reconnect, this, boost::asio::placeholders::error));
    } else       // 停 socket
        return;

}


void tcp_conf_handle::start_read_head() {
    // 读出头内容
    head_flag = true;
    boost::asio::async_read(*socket_, boost::asio::buffer(read_buff, head_length),
                            boost::bind(&tcp_conf_handle::handle_read, this,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}


void tcp_conf_handle::init_sock() {
    if (socket_ != nullptr) {
        delete socket_;
        delete ctx_;
    }

    ctx_ = new boost::asio::ssl::context(boost::asio::ssl::context::tlsv1_client);
    socket_ = new boost::asio::ssl::stream<boost::asio::ip::tcp::socket>(io_service, *ctx_);
}

void tcp_conf_handle::reconnect() {
    if (isConnect())
        return;

#ifdef DEBUG
    cout << "start reconnect" << endl;
#endif
    need_send_bytes = 0;
    head_flag = true;
    connect = Disconnect;
    wait_conf_times = 0;

    clog << mylog::info << "reconnect" << endl;

    boost::system::error_code ec;
    socket_->shutdown(ec);

    char str_port[32];
    sprintf(str_port, "%d", port);
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query(host, str_port);
    boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

    // 启动连接过程
    connect = StartConnect;

    // 发送缓冲区清空
    s_buff.init();

    //socket_.lowest_layer().close();
    //socket_.async_shutdown(handle_async_shutdown);
    //boost::asio::ssl::stream::lowest_layer();
    //boost::asio::ssl::stream::async_shutdown();

    init_sock();


    socket_->set_verify_mode(boost::asio::ssl::verify_none);
    boost::asio::async_connect(socket_->lowest_layer(), iterator,
                               boost::bind(&tcp_conf_handle::handle_connect, this,
                                           boost::asio::placeholders::error));
}


void tcp_conf_handle::handle_handshake(const boost::system::error_code &error) {
    if (!error) {
        boost::asio::async_read(*socket_,
                                boost::asio::buffer(read_buff, head_length),
                                boost::bind(&tcp_conf_handle::handle_read, this,
                                            boost::asio::placeholders::error,
                                            boost::asio::placeholders::bytes_transferred));
        //! 已经连接上
        set_connwcttwithconf();
    } else {
#ifdef DEBUG
        std::cout << "Handshake failed: " << error.message() << "\n";
#endif
        clog << mylog::info << "Handshake failed: " << error.message() << endl;
        set_disconnect();
        stop();
    }
}


void tcp_conf_handle::stop() {

    if (run_flag) {
        run_flag = false;

        boost::system::error_code ec;
        // 关 socket
        socket_->shutdown(ec);
        // 停定时器任务
        ping_run_dead.cancel(ec);
        reconnect_run_dead.cancel(ec);
        send_run_dead.cancel(ec);
    }
}


bool tcp_conf_handle::do_one_message() {

    switch (head.message_type()) {
        case TcpHead::Head::MessageType::Head_MessageType_Conf_message : {
            TcpHead::Conf t;
            if (t.ParseFromArray(read_buff, head.message_size())) {
                int nMessageId = t.message_id();
#ifdef DEBUG
                cout << "recive conf id: " << nMessageId << endl;
                cout << "ReciveCount: " << m_nReciveCount << endl;
#endif

                recive_conf(nMessageId);
                if (m_isSendDate) {
                    // 接收到确认回复，　重置计数器
                    wait_conf_times = 0;
                    if (m_nReciveCount == m_nSendCount) {
                        m_nReciveCount = 1;
                        //数据接收成功，设置等待应答标签
                        set_wait_conf(false);
                        m_isSendDate = false;
                    } else {
                        m_nReciveCount++;
                    }
                }

                return true;
            }
            break;
        }

        case TcpHead::Head::MessageType::Head_MessageType_connect_conf : {
            TcpHead::Connect_conf t;
            if (t.ParseFromArray(read_buff, head.message_size())) {
                set_connwcttwithconf();
                return true;
            }
            break;
        }

        case TcpHead::Head::MessageType::Head_MessageType_Normal : {
            TcpHead::Data t;
            if (t.ParseFromArray(read_buff, head.message_size())) {
                Mess_point mes(new OneMessage);
                if (mes->update(head, t)) {      //数据写入 mes
                    inq.push_back(mes);
                }

                //发回返回消息
                TcpHead::Head head_;
                TcpHead::Conf conf_;
                conf_.set_message_id(head.message_id());
                head_.set_message_size(conf_.ByteSize());
                head_.set_message_id(0);
                head_.set_message_type(TcpHead::Head::MessageType::Head_MessageType_Conf_message);
#ifdef DEBUG
                cout << "Head_MessageType_Normal" << endl;
#endif
                write_0(head_, conf_);

                return true;
            } else {
                clog << mylog::info << "error recive data" << endl;
                //cout << "error recive data" << endl;
            }

            break;
        }

        case TcpHead::Head::MessageType::Head_MessageType_PingPong : {
            TcpHead::PingPong t;
            if (t.ParseFromArray(read_buff, head.message_size())) {
                if (t.ping_type() == TcpHead::PingPong::PingType::PingPong_PingType_Ping) {
                    send_pong();
                } else {   //! pong
                    recive_pong();
                }

                return true;
            }
            break;
        }

        default:
#ifdef DEBUG
            cout << "unknow message type: " << head.message_type() << endl;
#endif
            return false;
    }

    return false;
}


void tcp_conf_handle::send_ping() {
    TcpHead::PingPong pp;
    pp.set_ping_type(TcpHead::PingPong::PingType::PingPong_PingType_Ping);

    TcpHead::Head h;
    h.set_message_id(0);
    h.set_message_type(TcpHead::Head::MessageType::Head_MessageType_PingPong);
    h.set_message_size(pp.ByteSize());

#ifdef DEBUG
    cout << "send_ping" << endl;
#endif
    write_0(h, pp);
}


void tcp_conf_handle::recive_pong() {
#ifdef DEBUG
    cout << "pong" << endl;
#endif
    ping_run_dead_change_expires();
}


void tcp_conf_handle::send_pong() {
    TcpHead::PingPong pp;
    pp.set_ping_type(TcpHead::PingPong::PingType::PingPong_PingType_Pong);

    TcpHead::Head h;
    h.set_message_id(0);
    h.set_message_type(TcpHead::Head::MessageType::Head_MessageType_PingPong);
    h.set_message_size(pp.ByteSize());

#ifdef DEBUG
    cout << "send_pong" << endl;
#endif
    write_0(h, pp);
}


void tcp_conf_handle::ping_run(const boost::system::error_code &error) {        // error_code 的用处，取消任务的通知
    if (run_flag && isConnect() && !error) {
#ifdef DEBUG
        cout << "ping" << endl;
#endif
        send_ping();

        // 继续转圈
        ping_run_dead.expires_from_now(boost::posix_time::seconds(loop_ping_time));
        ping_run_dead.async_wait(boost::bind(&tcp_conf_handle::ping_run, this, boost::asio::placeholders::error));
    }
    return;
}


void tcp_conf_handle::ping_run_dead_change_expires() {
    if (run_flag) {
#ifdef DEBUG
        cout << "延后 ping." << endl;
#endif
        ping_run_dead.expires_from_now(boost::posix_time::seconds(loop_ping_time));
        ping_run_dead.async_wait(boost::bind(&tcp_conf_handle::ping_run, this, boost::asio::placeholders::error));
    }
}


void tcp_conf_handle::send_run(const boost::system::error_code &error) {
    if (run_flag) {
        if (!error && isConnect() && !is_waith_conf() && need_send_bytes == 0) {
            if (!outq.empty()) {
#ifdef DEBUG
                cout << "send loop" << endl;
#endif
                //send_one_data();
                m_isSendDate = true;
                send_more_data();
            }
        }

        //　已连接，并且等待回复. 等待的次数超过限制，重连 socket
        if (isConnect() && is_waith_conf()) {
            if (++wait_conf_times >= wait_conf_times_max) {
#ifdef DEBUG
                cout << "wait_conf_times_max.!!!" << endl;
#endif
                set_disconnect();
            }
        }

        // 继续转圈
        send_run_dead.expires_from_now(boost::posix_time::milliseconds(loop_send_time));
        send_run_dead.async_wait(boost::bind(&tcp_conf_handle::send_run, this, boost::asio::placeholders::error));
        return;
    }
}


void tcp_conf_handle::send_one_data() {
    TcpHead::Head head;
    TcpHead::Data data;
    m_nSendCount = 0;
    if (outq.get_one(head, data)) {
        write_0(head, data);
        ++m_nSendCount;
    }
}


void tcp_conf_handle::send_more_data() {
    struct one {
        TcpHead::Head head;
        TcpHead::Data data;
    };

    list<one> more_data;
    one node;
    //清空发送数据个数
    m_nSendCount = 0;
    int send_buff_size = 0;

    //限制传送个数，最多不超过5个
    while (outq.get_one(node.head, node.data)) {
        more_data.push_back(node);
        send_buff_size += (node.head.ByteSize() + node.data.ByteSize());
        ++m_nSendCount;
    }

#ifdef DEBUG
    cout << "SendCount:" << m_nSendCount << endl;
    cout << "send_buff_size:" << send_buff_size << endl;
#endif

//    for (auto p = more_data.begin(); p != more_data.end(); ++p) {
//        send_buff_size += (p->head.ByteSize() + p->data.ByteSize());
//    }


    if (send_buff_size > 0) {
        LOCKCB_BUFF;
        char *sendbuff = s_buff.get_new_buff(send_buff_size);
        int l = 0;
        for (auto p = more_data.begin(); p != more_data.end(); ++p) {
            p->head.SerializeToArray(sendbuff + l, p->head.ByteSize());
            l += p->head.ByteSize();
            p->data.SerializeToArray(sendbuff + l, p->data.ByteSize());
            l += p->data.ByteSize();
        }

        send_data();
    }


    /*
    need_send_bytes = l;

    boost::asio::async_write(socket_,
                             boost::asio::buffer(sendbuff, l),
                             boost::bind(&tcp_conf_handle::handle_write, this,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
*/
}


void tcp_conf_handle::recive_conf(int id) {
#ifdef DEBUG
    cout << "recive_conf elapsed: " << send_t.elapsed() << "s" << endl;
#endif
    outq.remove_by_id(id);
}


void tcp_conf_handle::set_login_data(const string &login_info) {
    login_data = login_info;
}


void tcp_conf_handle::push_fornt_login_data() {
    if (!run_flag) {
#ifdef DEBUG
        cout << "!run_flag" << endl;
#endif
        return;
    }

    if (login_data.empty()) {
#ifdef DEBUG
        cout << "!login_data.empty" << endl;
#endif
        return;
    }

#ifdef DEBUG
    cout << "login_data in" << endl;
#endif

    Mess_point t = outq.get_first_();
    if ((t == nullptr) || (t != nullptr && t->mess_id != login_tcp_id)) {       // 没有预制消息
        Mess_point t(new OneMessage);
        t->mess_id = login_tcp_id;
        t->mess_info = login_data;
        outq.push_fornt(t);
    }
}
