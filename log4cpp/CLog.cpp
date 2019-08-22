//
// Created by carl on 18-5-18.
//

#include "CLog.h"
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/Priority.hh>
#include <boost/filesystem/operations.hpp>
#include "RollingFileAppender.hh"

using namespace std;

extern string pathlogt;
extern string testgf;

CLog *CLog::plog_ = NULL;


//获取log指针
CLog *CLog::getInstance() {
    if (plog_ == NULL) {
        plog_ = new CLog;
    }
    return plog_;
}


//销毁
void CLog::destory() {
    log4cpp::Category::shutdown();
    if (plog_) {
        plog_->category_root.info("log destroy");
        plog_->category_root.shutdown();
        delete plog_;
    }
}

//构造函数
CLog::CLog() :
        category_root(log4cpp::Category::getRoot()) {
//    char *cPath = getenv("HOME");
//    string strPath = cPath;testgf
//    strPath += "/logs";

    string strPath = pathlogt;

    cout <<"strPath="<<strPath<<'\n';
         //创建logs文件夹
    boost::filesystem::path filePath(strPath);   //初始化

    //查询文件夹是否存在,若不存在，则创建
    if (!boost::filesystem::exists(filePath)) {

        boost::filesystem::create_directories(filePath);
    }

    //自定义输出格式
    log4cpp::PatternLayout *pattern_os_appender = new log4cpp::PatternLayout;
    pattern_os_appender->setConversionPattern("%d: %p %c %x:%m%n");

    log4cpp::PatternLayout *pattern_file_appender = new log4cpp::PatternLayout;
    pattern_file_appender->setConversionPattern("%d: %p %c %x:%m%n");

    //输出到输出流中（输出到控制台上）
    log4cpp::OstreamAppender *os_appender = new log4cpp::OstreamAppender("osAppender", &std::cout);
    os_appender->setLayout(pattern_os_appender);


    //获取文件日志输出 （ 日志文件名:log/Picture.log)
    //strPath += "/";    //xj delete
//    std::string szIniFilePreffix = std::string(strPath)
//            .append("Picture");
    std::string szIniFilePreffix = std::string(strPath)
            .append("");

    cout<<"szIniFilePreffix="<<szIniFilePreffix<<'\n';
    //分割日志大小
    //log4cpp::RollingFileAppender* rollfileAppender =
    //  new log4cpp::RollingFileAppender( "rollfileAppender",std::string(szIniFilePreffix).append("_rollappend.log"),(10*1024*1024),50);
    //rollfileAppender->setLayout(pLayout);

    log4cpp::RollingFileAppender* rollfileAppender =
      new log4cpp::RollingFileAppender( "rollfileAppender",std::string(szIniFilePreffix).append(testgf),(10*1024*1024),10);
    rollfileAppender->setLayout(pattern_file_appender);
    cout<<"szIniFilePreffix.append(testgf)="<<szIniFilePreffix.append(testgf)<<'\n';

    category_root.addAppender(os_appender);

    //category_root.addAppender(backupAppender);
    category_root.addAppender(rollfileAppender);


    //设置默认优先级 DEBUG 之后的都不输出
    category_root.setPriority(log4cpp::Priority::DEBUG);
    category_root.info("Picturelog created!");

}

CLog::~CLog() {
    destory();
}

//设置优先级
void CLog::setPriority(Priority priority) {
    switch (priority) {
        case (ERROR):
            category_root.setPriority(log4cpp::Priority::ERROR);
            break;

        case (WARN):
            category_root.setPriority(log4cpp::Priority::WARN);
            break;

        case (INFO):
            category_root.setPriority(log4cpp::Priority::INFO);
            break;

        case (DEBUG):
            category_root.setPriority(log4cpp::Priority::DEBUG);
            break;

        default:
            category_root.setPriority(log4cpp::Priority::DEBUG);
            break;
    }
}

void CLog::error(const char *msg) {
    category_root.error(msg);
}

void CLog::warn(const char *msg) {
    category_root.warn(msg);
}

void CLog::info(const char *msg) {
    category_root.info(msg);
}

void CLog::debug(const char *msg) {
    category_root.debug(msg);
}

CLog *g_log = nullptr;
