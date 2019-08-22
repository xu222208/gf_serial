/*!
 * tcp conf asio 的函数部分
 */

#ifndef SS_CLIENT2_TCP_CONF_HANDLE_H
#define SS_CLIENT2_TCP_CONF_HANDLE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/asio/ssl/context.hpp>
#include <boost/smart_ptr.hpp>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "tcp_with_conf.pb.h"
#include "inquery.h"
#include "outquery_window.h"
#include "tcp_conf_id.h"
#include "send_buff.h"
#include "logcpp.h"
#include <boost/timer.hpp>

using namespace std;

class tcp_conf_handle {
private:
    boost::asio::io_service &io_service;
    string host;
    int port;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> *socket_ = nullptr;
    char *read_buff = nullptr;
    bool run_flag = true;
    boost::asio::ssl::context *ctx_ = nullptr;

    void init_sock();

    //! 系统日志
    syslog_stream clog;

    //! 进出队列
    inquery &inq;
    outquery_window &outq;
    //! 等待对端的确认消息
    bool wait_conf = false;

    void set_wait_conf(bool isWaitConf) { wait_conf = isWaitConf; };

    bool is_waith_conf() { return wait_conf; };
    //! 发送定时操作
    static const int loop_send_time = 1000;
    boost::asio::deadline_timer send_run_dead;
    // 已发送的标志
    std::size_t need_send_bytes = 0;

    void send_run(const boost::system::error_code &error);

    //! 一次发送一个数据
    void send_one_data();

    //! 一次发送多条数据
    void send_more_data();

    send_buff s_buff;
    //! 在 send_run 循环里，　wait_conf 的次数
    int wait_conf_times = 0;
    //XXX: 等待确认消息时间 60s
    //const int wait_conf_times_max = 1000 / loop_send_time * 30;     // 30s
    const int wait_conf_times_max = 30;     // 60s

    //! head, 初始化 head, 设置 head_length
    TcpHead::Head head;
    int head_length = 0;

    void init_head();

    //! 定时器运行一个循环
    //! 重连 循环保持程序运行
    // 第一次连接，延迟时间 3s. 之后重连时间 30s
    static const int first_connect_time = 3;
    static const int loop_run_time = 30;
    boost::asio::deadline_timer reconnect_run_dead;

    void loop_reconnect(const boost::system::error_code &error);

    bool head_flag = true;

    void handle_write(const boost::system::error_code &error,
                      size_t bytes_transferred);

    // 启动读取头
    void start_read_head();

    void handle_read(const boost::system::error_code &error,
                     size_t bytes_transferred);

    void handle_connect(const boost::system::error_code &error);

    void handle_handshake(const boost::system::error_code &error);

#ifdef DEBUG
    //! 发送到接收的时间间隔
    boost::timer send_t;
#endif

    //! 重连
    void reconnect();

    //! 连接状态
    enum ConnectStatus {
        Disconnect,                 // socket 没有连接，关闭状态
        StartConnect,               // 已经发起连接
        ConnectWithConf,            // 连接完成，收到确认消息
    };
    ConnectStatus connect = Disconnect;
protected:
    virtual void set_disconnect();

    virtual void set_connwcttwithconf();

public:
    bool isConnect();               // ConnectStatus = ConnectWithConf

private:
    void write_0(const TcpHead::Head &, const google::protobuf::Message &);

    //! 看 s_buff 的数据, 和 need_send_bytes == 0, 发送数据
    void send_data();

public:
    tcp_conf_handle(boost::asio::io_service &io_service_, const char host_[50], int port,
                    inquery &inq, outquery_window &);

    ~tcp_conf_handle();

    //! 发送消息
    void send(const string &);

public:
    //! 停止运行. 停定时器任务
    virtual void stop();

private:
    //! 消息后续格式类生成
    ::google::protobuf::Message *newinfoclass(u_int type);

    // 消息处理
    bool do_one_message();

    void send_ping();

    void recive_pong();

    void send_pong();

    void recive_conf(int id);

    // ping.pong
    static const int loop_ping_time = 2 * 60;
    boost::asio::deadline_timer ping_run_dead;

    void ping_run(const boost::system::error_code &error);

    //! 延后 ping_run_dead 的事件触发
    void ping_run_dead_change_expires();

    //! login 部分
    // 如果设置有 login, 那么在 set_connwcttwithconf(), 调用send_login_data() 发送消息编号是 tcp_id = -1 的login 消息.
    // 连接上服务器端, 先发送 login 消息
private:
    string login_data;
    //! 发送 login
    const static int login_tcp_id = -1;

    void push_fornt_login_data();

    //设置发送接收计数
    int m_nSendCount = 0;
    //接收计数
    int m_nReciveCount = 1;
    //数据发送标签
    bool m_isSendDate = false;
//buff lock
#define LOCKCB_BUFF boost::mutex::scoped_lock lock(io_mutex)

    boost::mutex io_mutex;
public:
    //! 设置 login 的数据块
    void set_login_data(const string &login_info);

};


#endif //SS_CLIENT2_TCP_CONF_HANDLE_H
