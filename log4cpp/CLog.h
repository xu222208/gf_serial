//
// Created by carl on 18-5-18.
//

#ifndef TESTPICTURE_CLOG_H
#define TESTPICTURE_CLOG_H

#include<log4cpp/Category.hh>
#include "DailyRollingFileAppender.hh"
#include<iostream>
#include <string>

//日志优先级
enum Priority {
    ERROR,
    WARN,
    INFO,
    DEBUG
};

//*****************************************************
//注意：
//文件名 __FILE__ ,函数名 __func__ ，行号__LINE__ 是编译器实现的
//
//前两个变量是string类型，且__LINE__是整形，所以需要转为string类型
//******************************************************

//整数类型文件行号 ->转换为string类型
inline std::string int2string(int line) {
    std::ostringstream oss;
    oss << line;
    return oss.str();
}



//定义一个在日志后添加 文件名 函数名 行号 的宏定义
#define suffix(msg)  std::string(msg).append(" ##")\
        .append(__FILE__).append(":").append(__func__)\
        .append(":").append(int2string(__LINE__))\
        .append("##").c_str()

class CLog {

public:
    static CLog *getInstance();

    void setPriority(Priority priority);

    void error(const char* msg);

    void warn(const char* msg);

    void info(const char* msg);

    void debug(const char* msg);

private:
    CLog();  //单例模式：构造函数私有化
    ~CLog();
    static void destory();
private:
    static CLog *plog_;
    //定义主体类跟分类
    log4cpp::Category &category_root;
};

//定义日志类对象
extern CLog *g_log;



////外部函数调用开放接口
#define logError(msg) g_log->error(suffix(msg))
#define logWarn(msg) g_log->warn(suffix(msg))
#define logInfo(msg) g_log->info(suffix(msg))
#define logDebug(msg) g_log->debug(suffix(msg))


#endif //TESTPICTURE_CLOG_H
