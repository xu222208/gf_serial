#include <iostream>
#include "proto_ss/tcp_conf_handle.h"
#include "protoc/SendPictureProtocol.pb.h"
#include "from_server_info.h"
#include "CCameras.h"
#include "double_list/SendQueue.h"
#include <boost/filesystem.hpp>
#define VERSION "0.2.1" // 此处每次发布版本要手动更新
#define NAME "facepics"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>


#include <iostream>
#include <string>
#include<sys/timeb.h>

CCameras *pCameras;   //xj  add
using namespace std;
struct NowDate{char tmp0[16]; //年月日
char tmp1[16]; //时分秒
char tmp2[4]; //毫秒
 };


const int g_OutQuerySize = 512;
bool g_isRun = true;
uint64 g_nID = 0;
string g_strServer = "";
int g_nPort = 0;
string g_strUserName = "";
string g_strPassword = "";
char tracking[]="/var/log/facepics/tracking.log";
char err[]="/var/log/facepics/error.log";
int gatewayId;
int cameraId;

char* getTimeofymd();
char* getTimeofh_m_s_ms();

char* getTimeofymd()
{
    time_t timep;
    time (&timep);
    NowDate date;
    strftime(date.tmp0, sizeof(date.tmp0), "%Y-%m-%d",localtime(&timep) );
    char  *ymd=(char *)malloc(16);
    memcpy(ymd,date.tmp0,16);
    return ymd;
}



#include "global.h"
#include "CCameras.h"
#include <boost/filesystem/operations.hpp>
#include <dirent.h>
#include "hikvision/HCCamera.h"
#include "dahua/DHCamera.h"
#include "jvt/JVTCamera.h"
#include "kuangshi/KSCamera.h"
#include <sys/types.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


extern "C"{
#include <zmq.h>
#include <zmq_utils.h>
}
void * pSock = NULL;
void * pSock2 = NULL;


string pathlogt;
string testgf;
string pathcamt;
string pathgatet;
char* getTimeofh_m_s_ms()
{
    time_t timep;
    time (&timep);
    NowDate date;
    strftime(date.tmp1, sizeof(date.tmp1), "%H:%M:%S",localtime(&timep) );
    struct timeb tb;
    ftime(&tb);
    sprintf(date.tmp2,"%d",tb.millitm);
    char *h_m_s_ms=(char *)malloc(20);
    memcpy(h_m_s_ms,date.tmp1,16);
    strcat(h_m_s_ms,date.tmp2);
    return  h_m_s_ms;
}



//获取登录字符串gateway_id
string GetLoginString() {
    PictureProtocol::Head head;
    PictureProtocol::Login login;
    login.set_id(g_nID);
    login.set_username(g_strUserName);
    login.set_password(g_strPassword);
    login.set_version(1);
    login.set_os("ubtu 16.4");

    head.set_message_size(login.ByteSize());
    head.set_message_type(PictureProtocol::MessageType::LOGIN);

    return (head.SerializeAsString() + login.SerializeAsString());

}

//TCP连接启动线程
void ios_run(outquery_window &outq, inquery &inq) {
    boost::asio::io_service ios;
    boost::asio::ssl::context ctx(boost::asio::ssl::context::tlsv1_client);



    tcp_conf_handle *ptcpConfHandle = new tcp_conf_handle(ios,
                                                          g_strServer.c_str(), g_nPort,
                                                          inq, outq);

    if (g_pTcpConf) {
        delete g_pTcpConf;
        g_pTcpConf = nullptr;
    }

    g_pTcpConf = ptcpConfHandle ;
    //g_pTcpConf = new tcp_conf_handle(ierrorLogos, g_strServer, g_nPort, inq, outerrq);
    ptcpConfHandle->set_login_data(GetLoginString());

//    tcp_conf_handle c(ios,
//                      g_strServer, g_nPort,
//                      inq, outq);

    //c.set_login_data(GetLoginString());

    sleep(1);
    try {
        ios.run();
        ios.stop();
    }
    catch (std::exception &e) {
        logError(e.what());
    }

}


static void show_info(char *argv[]) {
    if (0 == strcmp("-v", argv[1])) {
        printf("%s version: %s (%s, %s)\n", NAME, VERSION, __DATE__, __TIME__);
        return;
    } else if (0 == strcmp("-h", argv[1])) {
        printf("Usage: %s [options]\n", NAME);
        printf("Options:\n");
        printf(" void\tRun %s\n", NAME);
        printf(" -v\tDisplay %s version information\n", NAME);
        printf(" -h\tDisplay help information\n");
        return;
    }
    printf("Usage: %s [-v | -h]\n", NAME);
    return;
}

vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[str.length() + 1] ; //不要忘了
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }

    return res;
}

string  mkdr( char *path) {
    vector<string> vec = split(path, "/");
    vector<string>::iterator iter;
    string tpath = "/";
    for (iter = vec.begin();
         iter != vec.end() - 1;
         ++iter) {
        cout << *iter << endl;
        tpath = tpath + *iter + "/";
        const char *mystr = tpath.c_str();
        mkdir(mystr, 0777);
        printf("mystr=%s\n",mystr);

    }
    return  tpath;
}

string getfile(char *path)
{
    vector<string> vec = split(path, "/");
    vector<string>::iterator iter;
    string tpath = "/";
    for (iter = vec.begin();
         iter != vec.end() - 1;
         ++iter) {
        //cout << *iter << endl;

        tpath = tpath + *iter + "/";
        const char *mystr = tpath.c_str();
        mkdir(mystr, 0777);
        //printf("mystr=%s\n",mystr);

    }
    return (*(vec.end()-1));
}



int main(int argc, char *argv[]) {
    //显示版本号
    if (2 == argc) {
        show_info(argv);
        return 0;
    }
    if ( argc==1)
    {
        char pathlog1[]="/var/log/facepics/facepics.log";
        pathlogt=mkdr(pathlog1);
        testgf=getfile(pathlog1);
        const char *tt=testgf.c_str();

        char pathc1[] = "/usr/local/etc/facepics/cameras.json";
        pathcamt=mkdr(pathc1);

        char pathg1[] = "/usr/local/etc/facepics/gateway.json";
        pathgatet=mkdr(pathg1);
    }

    if(argc>2) {
        printf("argc=%d\n",argc);
        int paran;
        for (paran = 1; paran < argc; paran++) {
            if ((strcmp(argv[paran], "-L") != 0)&&(paran!=argc-1)) {
                continue;
            }
           else if ((paran < argc - 1)&&(strcmp(argv[paran], "-L")==0)) {
                char pathlog1[100]={0};
                strcpy(pathlog1, argv[paran + 1]);

                pathlogt=mkdr(pathlog1);//倒数第二个位置
                testgf=getfile(pathlog1);
                break;
            } else if (paran == argc - 1) {
                char pathlog1[100] = "/var/log/facepics/facepics.log";
                pathlogt=mkdr(pathlog1);
                testgf=getfile(pathlog1);

            }

        }


        for (paran = 1; paran < argc ; paran++) {
            if ((strcmp(argv[paran], "-C") != 0)&&(paran!=argc-1)) {
                continue;
            }
            else if ((paran < argc - 1)&&(strcmp(argv[paran],"-C")==0)) {
                char pathcam1[100]={0};
                strcpy(pathcam1, argv[paran + 1]);
                pathcamt=mkdr(pathcam1);
                break;
            } else if (paran == argc - 1) {
                char pathc1[] = "/usr/local/etc/facepics/cameras.json";
                char pathcam[100]={0};
                strcpy(pathcam, pathc1);
                pathcamt=mkdr(pathcam);
            }
        }



        for (paran = 1; paran < argc; paran++) {
            if ((strcmp(argv[paran], "-G") != 0)&&(paran!=argc-1) ) {
                continue;
            }
            else if ((paran < argc - 1)&&(strcmp(argv[paran],"-G")==0)){
                char pathgate[100]={0};
                strcpy(pathgate, argv[paran + 1]);
                pathgatet=mkdr(pathgate);
                break;
            } else if ((paran == argc - 1)) {
                char pathg1[] = "/usr/local/etc/facepics/gateway.json";
                char pathgate1[100]={0};
                strcpy(pathgate1, pathg1);
                pathgatet=mkdr(pathgate1);
            }
        }
    }





//    if (fork() > 0) // parent process
//        exit(0);err
//    setsid();

//     char path[]="/var/log/facepics";



//     printf("%d\n",mkdir("/var/log/facepics", 0777));//创建文件夹

    g_log = CLog::getInstance();



        //获取用户主目录
//    char *cPath = getenv("HOME");
//    char cPath[100]={0};
//    strcpy(cPath,pathgate);
//    string strPath = cPath;
    string strPath =pathgatet;
    //读取json文件
    //strPath += "/gateway.json";
    strPath += "gateway.json";
    auto document = GetJsonMsg(strPath);
    cout<<"gateway path"<<strPath;

    if (!document.IsObject()) {
        //读取文件失败
        while (true) {
            logError("read gateway.json error ,read again!");
            int fd2=open(err,O_RDWR|O_CREAT|O_APPEND,0777);
            printf("fd2=%d\n",fd2);
            char buf[200]={0};
            strcat(buf,"|");
            strcat(buf,getTimeofymd());
            strcat(buf,"|");
            strcat(buf,getTimeofh_m_s_ms());
            strcat(buf,"|");
            strcat(buf,"NULL|CONN CAM|read gateway.json error ,read again!|gateway_id=NULL camera_id=NULL vendor=jvt|");
            write(fd2,buf,200);
            close(fd2);
            //重新读取文件
            document = GetJsonMsg(strPath);
            if (document.IsObject()) {
                logDebug("read gateway.json ok!");
                int fd2=open(tracking,O_RDWR|O_CREAT|O_APPEND,0777);
                printf("fd2=%d\n",fd2);
                char buf[200]={0};
                strcat(buf,"|");
                strcat(buf,getTimeofymd());
                strcat(buf,"|");
                strcat(buf,getTimeofh_m_s_ms());
                strcat(buf,"|");
                strcat(buf,"NULL|CONN CAM|read gateway.json ok!|gateway_id=NULL camera_id=NULL vendor=jvt|");
                write(fd2,buf,200);
                close(fd2);
                break;
            }
            sleep(2);
        }
    }



    const Value &cur_server = document;
    g_nID = cur_server["id"].GetInt64();
    g_strServer = cur_server["server"].GetString();
    g_nPort = cur_server["port"].GetInt();
    g_strUserName = cur_server["username"].GetString();
    g_strPassword = cur_server["password"].GetString();



    logDebug("************!\n");
    // 进出消息
    outquery_window outq(g_OutQuerySize);
    inquery inq(g_OutQuerySize);

    // 入消息处理，单独线程
    from_server_info inq_op(inq, outq);

    //初始化循环队列
    OnInitQuery();

    //添加发送图片信息发送线程
    SendQueue *pSendQueue = new SendQueue(&inq_op);

    //添加相机类
   // CCameras *pCameras = new CCameras(pSendQueue);//xj  delete
    pCameras = new CCameras(pSendQueue);//xj  add
    //启动传输线
    while (g_isRun) {
        try {
            boost::thread t1 = boost::thread(ios_run, boost::ref(outq), boost::ref(inq));

            ////**********************************************client**********************/
            void * pCtx = NULL;
            void * pCtx2 = NULL;
            //使用tcp协议进行通信，需要连接的目标机器IP地址为192.168.1.2
            //通信使用的网络端口 为7766
            const char * pAddr = "tcp://192.168.63.13:9999";
            const char * pAddr2 = "tcp://192.168.63.13:9998";

            //创建context
            if ((pCtx = zmq_ctx_new()) == NULL)
            {
                return 0;
            }
            if ((pCtx2 = zmq_ctx_new()) == NULL)
            {
                return 0;
            }

            //创建socket
            if ((pSock = zmq_socket(pCtx, ZMQ_REQ)) == NULL)
            {
                zmq_ctx_destroy(pCtx);
                return 0;
            }
            if ((pSock2 = zmq_socket(pCtx2, ZMQ_REQ)) == NULL)
            {
                zmq_ctx_destroy(pCtx2);
                return 0;
            }
            int iSndTimeout = 5000;// millsecond
            //设置接收超时
            if (zmq_setsockopt(pSock, ZMQ_RCVTIMEO, &iSndTimeout, sizeof(iSndTimeout)) < 0)
            {
                zmq_close(pSock);
                zmq_ctx_destroy(pCtx);
                return 0;
            }

            if (zmq_setsockopt(pSock2, ZMQ_RCVTIMEO, &iSndTimeout, sizeof(iSndTimeout)) < 0)
            {
                zmq_close(pSock2);
                zmq_ctx_destroy(pCtx2);
                return 0;
            }

            //连接目标IP192.168.63.13，端口9999
            if (zmq_connect(pSock, pAddr) < 0)
            {
                zmq_close(pSock);
                zmq_ctx_destroy(pCtx);
                return 0;
            }


            if (zmq_connect(pSock2, pAddr2) < 0)
            {
                zmq_close(pSock2);
                zmq_ctx_destroy(pCtx2);
                return 0;
            }
            //循环发送消息
//            while (1)
//            {
//                printf("%%%%%%%%%%%%%%%%%%%%%%%%%\n");
//                static int i = 0;
//                char szMsg[1024] = { 0 };
//                sprintf(szMsg, "hello world : %3d", i++);
//                printf("Enter to send...\n");
//                if (zmq_send(pSock, szMsg, sizeof(szMsg), 0) < 0)
//                {
//                    fprintf(stderr, "send message faild\n");
//                    continue;
//                }
//                printf("send message : [%s] succeed\n", szMsg);
//                zmq_recv(pSock, szMsg, sizeof(szMsg), 0);
//                printf("szMsg=%s\n",szMsg);
//                //getchar();
//                printf("$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//                sleep(1);
//            }

//            return 0;


            //**********************************************************************/
            t1.join();

        }
        catch (std::exception &e) {
            logError(e.what());
        }

    }


    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    if (pCameras) {
        delete pCameras;
        pCameras = nullptr;
    }

    if (pSendQueue) {
        delete pSendQueue;
        pSendQueue = nullptr;
    }

    //删除队列
    OnDeletQuery();
    logInfo("stop");

    return 0;
}