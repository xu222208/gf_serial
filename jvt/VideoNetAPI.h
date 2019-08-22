#ifndef _JVT_VIDEO_NET_API_H
#define _JVT_VIDEO_NET_API_H
#include <stdio.h>
namespace SDK_JVTFACE{
#define Bool int
#define WORD	unsigned short
#define DWORD	unsigned int
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define LONG	long
#define UINT	unsigned int
#define LPVOID	void*
#ifndef DBG
#define DBG(fmt, args...) do { \
	 fprintf(stdout, "\033[m""[-DBG-] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	 \
 } while(0)
#endif

#ifndef SUCCESS_TRACE
#define SUCCESS_TRACE(fmt, args...) do { \
	 fprintf(stdout, "\033[1;32m""[SUCCESS_TRACE!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifndef WARNING_TRACE
#define WARNING_TRACE(fmt, args...) do { \
	 fprintf(stdout, "\033[1;33m""[WARNING_TRACE!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifndef BLUE_TRACE
#define BLUE_TRACE(fmt, args...) do { \
	 fprintf(stdout, "\033[1;34m""[TRACE!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifndef MAGENTA_TRACE
#define MAGENTA_TRACE(fmt, args...) do { \
	 fprintf(stdout, "\033[1;35m""[TRACE!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifndef CYAN_TRACE
#define CYAN_TRACE(fmt, args...) do { \
	 fprintf(stdout, "\033[1;36m""[TRACE!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifndef ERR
#define ERR(fmt, args...) do { \
	 fprintf(stderr, "\033[1;31m""[ERR!] [%s:%5d] " fmt, (char *)__FILE__,__LINE__,## args);	\
 } while(0)
#endif

#ifdef __cplusplus 
extern "C" {
#endif


enum SDK_RET_CODE
{
	VIDEONET_NOERROR				    = 0,				//没有错误
	VIDEONET_SUCCESS					= 1,				//返回成功
	VIDEONET_SDK_NOTVALID				= -10000,			//非法请求
	VIDEONET_NO_INIT					= -10001,			//SDK未经初始化
	VIDEONET_ILLEGAL_PARAM				= -10002,			//用户参数不合法
	VIDEONET_INVALID_HANDLE				= -10003,			//句柄无效
	VIDEONET_SDK_UNINIT_ERROR			= -10004,			//SDK清理出错
	VIDEONET_SDK_TIMEOUT				= -10005,			//等待超时
	VIDEONET_SDK_MEMORY_ERROR			= -10006,			//内存错误，创建内存失败
	VIDEONET_SDK_NET_ERROR				= -10007,			//网络错误
	VIDEONET_SDK_OPEN_FILE_ERROR		= -10008,			//打开文件失败
	VIDEONET_SDK_UNKNOWNERROR			= -10009,			//未知错误
	VIDEONET_DEV_VER_NOMATCH			= -11000,			//收到数据不正确，可能版本不匹配
	VIDEONET_SDK_NOTSUPPORT				= -11001,			//版本不支持
	VIDEONET_SDK_FILE_FORAMAT_ERROR		= -11002,			//文件格式 错误

	VIDEONET_ANAS_EXIST					= -11130,			//NAS地址已存在
	VIDEONET_ANAS_ALIVE					= -11131,			//路径被使用，无法操作
	VIDEONET_ANAS_FULL					= -11132,			//NAS已达到支持的最大值


	VIDEONET_OPEN_CHANNEL_ERROR			= -11200,			//打开通道失败,可能检测到设备已经不在线
	VIDEONET_CLOSE_CHANNEL_ERROR		= -11201,			//关闭通道失败
	VIDEONET_SUB_CONNECT_ERROR			= -11202,			//建立媒体子连接失败,网络出错或者设备可能不在线
	VIDEONET_SUB_CONNECT_SEND_ERROR		= -11203,			//媒体子连接通讯失败,可能检测到设备已经不在线
	VIDEONET_NOTSUPPORT					= -11205,			//版本不支持
	VIDEONET_NOTVALID					= -11206,           //请求非法,主连接可能已断开
	VIDEONET_TCPCONNET_REACHED_MAX		= -11207,			//Tcp视频链接达到最大，不允许新的Tcp视频链接
	VIDEONET_OPENEDPREVIEW				= -11208,			//该通道已经打开预览(通道的打开关闭需要一一对应,打开几次需要关闭几次;不一致会打开提示该错误;预防客户端开发逻辑上的不合理设计增加该错误值)

	/// 用户管理部分错误码
	VIDEONET_NOPOWER					= -11300,			//无权限
	VIDEONET_PASSWORD_NOT_VALID			= -11301,			//账号密码不对
	VIDEONET_LOGIN_USER_NOEXIST			= -11302,			//用户不存在
	VIDEONET_USER_LOCKED				= -11303,			//该用户被锁定
	VIDEONET_USER_IN_BLACKLIST			= -11304,			//该用户不允许访问(在黑名单中)
	VIDEONET_USER_HAS_USED				= -11305,			//该用户已登陆
	VIDEONET_USER_NOT_LOGIN				= -11306,			//该用户没有登陆
	VIDEONET_CONNECT_DEVICE_ERROR		= -11307,			//可能设备不存在
	VIDEONET_ACCOUNT_INPUT_NOT_VALID	= -11308,			//用户管理输入不合法
	VIDEONET_ACCOUNT_OVERLAP			= -11309,			//索引重复
	VIDEONET_ACCOUNT_OBJECT_NONE		= -11310,			//不存在对象, 用于查询时
	VIDEONET_ACCOUNT_OBJECT_NOT_VALID	= -11311,			//不存在对象
	VIDEONET_ACCOUNT_OBJECT_IN_USE		= -11312,			//对象正在使用
	VIDEONET_ACCOUNT_SUBSET_OVERLAP		= -11313,			//子集超范围 (如组的权限超过权限表，用户权限超出组的权限范围等等)
	VIDEONET_ACCOUNT_PWD_NOT_VALID		= -11314,			//密码不正确
	VIDEONET_ACCOUNT_PWD_NOT_MATCH		= -11315,			//密码不匹配
	VIDEONET_ACCOUNT_RESERVED			= -11316,			//保留帐号
	VIDEONET_ACCOUNT_SYS_MAINTAIN		= -11317,			//系统维护中，不可登陆
	VIDEONET_EE_DVR_PASSWORD_NOT_VALID2	= -11318,			//账号密码不对


	/// 配置管理相关错误码
	VIDEONET_OPT_RESTART				= -11400,			//保存配置后需要重启应用程序
	VIDEONET_OPT_REBOOT					= -11401,			//需要重启系统
	VIDEONET_OPT_FILE_ERROR				= -11402,			//写文件出错
	VIDEONET_OPT_CAPS_ERROR				= -11403,			//配置特性不支持
	VIDEONET_OPT_VALIDATE_ERROR			= -11404,			//配置校验失败
	VIDEONET_OPT_CONFIG_NOT_EXIST		= -11405,			//请求或者设置的配置不存在
	
	//
	VIDEONET_CTRL_PAUSE_ERROR			= -11500,			//暂停失败
	VIDEONET_SDK_NOTFOUND				= -11501,			//查找失败，没有找到对应文件
	VIDEONET_CFG_NOT_ENABLE				= -11502,           //配置未启用

	VIDEONET_DECORD_FAIL				= -11503,           //解码失败

	//DNS协议解析返回错误码
	VIDEONET_SOCKET_ERROR				= -11600,			//创建套节字失败
	VIDEONET_SOCKET_CONNECT				= -11601,			//连接套节字失败
	VIDEONET_SOCKET_DOMAIN				= -11602,			//域名解析失败
	VIDEONET_SOCKET_SEND				= -11603,			//发送数据失败
	VIDEONET_NO_CONNECT_FRONT			= -11614,			//前端设备未连接或者连接的前端设备分辨率未知
	VIDEONET_LOGIN_FULL					= -11615,			//登录句柄已达到最大值，无法再登录
	VIDEONET_ARSP_USER_NOEXIST			= -11619,			//用户不存在 
	VIDEONET_ARSP_PASSWORD_ERROR		= -11620,			//账号密码不对
	VIDEONET_ARSP_QUERY_ERROR			= -11621,			//查询失败 
	//升级错误码
	VIDEONET_NOENOUGH_MEMORY			= -11804,			//内存不足
	VIDEONET_INVALID_FORMAT				= -11805,			//升级文件格式不对
	VIDEONET_UPDATE_PART_FAIL			= -11806,			//某个分区升级失败
	VIDEONET_INVALID_HARDWARE			= -11807,			//硬件型号不匹配
	VIDEONET_INVALID_VENDOR				= -11808,			//客户信息不匹配
	VIDEONET_INVALID_COMPALIBLE			= -11809,			//升级程序的兼容版本号比设备现有的小，不允许设备升级回老程序
	VIDEONET_INVALID_VERSION			= -11810,			//非法的版本
	VIDEONET_INVALID_WIFI_DRIVE			= -11811,			//升级程序里wifi驱动和设备当前在使用的wifi网卡不匹配
	VIDEONET_INVALID_CUR_FLASH			= -11812,			//升级程序不支持设备使用的Flash
};

typedef enum _SDK_CONFIG_TYPE
{
	E_SDK_CONFIG_NOTHING = 0,
	E_SDK_CONFIG_USER,					//用户信息，包含了权限列表，用户列表和组列表   对应结构体USER_MANAGE_INFO
	E_SDK_CONFIG_ADD_USER,				//增加用户---对应结构体USER_INFO
	E_SDK_CONFIG_MODIFY_USER,			//修改用户---对应结构体CONF_MODIFYUSER
	E_SDK_CONFIG_DELETE_USER,			//对应结构体USER_INFO
	E_SDK_CONFIG_ADD_GROUP,				//增加组---对应结构体USER_GROUP_INFO
	E_SDK_CONFIG_MODIFY_GROUP,			//修改组---对应结构体CONF_MODIFYGROUP
	E_SDK_COFIG_DELETE_GROUP,			//对应结构体---USER_GROUP_INFO
	E_SDK_CONFIG_MODIFY_PSW,			//修改密码---对应结构体_CONF_MODIFY_PSW
	E_SDK_CONFIG_ABILITY_SYSFUNC = 9,	//支持的网络功能---对应结构体SDK_SystemFunction
	E_SDK_CONFIG_ABILTY_ENCODE = 10,	//首先获得编码能力---对应结构体CONFIG_EncodeAbility
	E_SDK_CONFIG_ABILITY_PTZPRO,		//云台协议---对应结构体SDK_PTZPROTOCOLFUNC
	E_SDK_COMFIG_ABILITY_COMMPRO,		//串口协议---对应结构体SDK_COMMFUNC
	E_SDK_CONFIG_ABILITY_MOTION_FUNC,	//动态检测块---对应结构体SDK_MotionDetectFunction
	E_SDK_CONFIG_ABILITY_BLIND_FUNC,	//视频遮挡块---对应结构体SDK_BlindDetectFunction
	E_SDK_CONFIG_ABILITY_DDNS_SERVER,	//DDNS服务支持类型---对应结构体SDK_DDNSServiceFunction
	E_SDK_CONFIG_ABILITY_TALK,			//对讲编码类型---对应结构体SDK_DDNSServiceFunction
	E_SDK_CONFIG_SYSINFO = 17,			//系统信息---对应结构体VIDEONET_DEVICEINFO
	E_SDK_CONFIG_SYSNORMAL,				//普通配置---对应结构体SDK_CONFIG_NORMAL
	E_SDK_CONFIG_SYSENCODE,				//编码配置---对应结构体SDK_EncodeConfigAll
	E_SDK_CONFIG_SYSNET = 20,			//网络设置---对应结构体SDK_CONFIG_NET_COMMON
	E_SDK_CONFIG_PTZ,					//云台页面---对应结构体SDK_STR_PTZCONFIG_ALL
	E_SDK_CONFIG_COMM,					//串口页面---对应结构体SDK_CommConfigAll
	E_SDK_CONFIG_RECORD,				//录像设置界面---对应结构体SDK_RECORDCONFIG
	E_SDK_CONFIG_MOTION,				//动态检测页面---对应结构体SDK_MOTIONCONFIG
	E_SDK_CONFIG_SHELTER,				//视频遮挡---对应结构体SDK_BLINDDETECTCONFIG
	E_SDK_CONFIG_VIDEO_LOSS,  			//视频丢失---对应结构体SDK_VIDEOLOSSCONFIG
	E_SDK_CONFIG_ALARM_IN,				//报警输入---对应结构体SDK_ALARM_INPUTCONFIG
	E_SDK_CONFIG_ALARM_OUT,				//报警输出---对应结构体SDK_AlarmOutConfigAll
	E_SDK_CONFIG_DISK_MANAGER,			//硬盘管理界面---对应结构体SDK_StorageDeviceControl
	E_SDK_CONFIG_OUT_MODE = 30,			//输出模式界面---对应结构体SDK_VideoWidgetConfigAll
	E_SDK_CONFIG_CHANNEL_NAME,			//通道名称---对应结构体SDK_ChannelNameConfigAll
	E_SDK_CONFIG_AUTO,					//自动维护界面配置---对应结构体SDK_AutoMaintainConfig
	E_SDK_CONFIG_DEFAULT,     			//恢复默认界面配置---对应结构体SDK_SetDefaultConfigTypes
	E_SDK_CONFIG_DISK_INFO,				//硬盘信息---对应结构体SDK_StorageDeviceInformationAll
	E_SDK_CONFIG_LOG_INFO,				//查询日志---对应结构体SDK_LogList
	E_SDK_CONFIG_NET_IPFILTER,			//黑名单配置---对应结构体SDK_NetIPFilterConfig
	E_SDK_CONFIG_NET_DHCP,				//DHCP配置---对应结构体SDK_NetDHCPConfigAll
	E_SDK_CONFIG_NET_DDNS,				//DDNS信息---对应结构体SDK_NetDDNSConfigALL
	E_SDK_CONFIG_NET_EMAIL,				//EMAIL---对应结构体SDK_NetEmailConfig
	E_SDK_CONFIG_NET_MULTICAST = 40,	//组播---对应结构体SDK_NetMultiCastConfig
	E_SDK_CONFIG_NET_NTP,				//NTP---对应结构体SDK_NetNTPConfig
	E_SDK_CONFIG_NET_PPPOE,				//PPPOE---对应结构体SDK_NetPPPoEConfig
	E_SDK_CONFIG_NET_DNS,				//DNS---对应结构体SDK_NetDNSConfig
	E_SDK_CONFIG_NET_FTPSERVER,			//FTP---对应结构体SDK_FtpServerConfig
	E_SDK_CONFIG_SYS_TIME,				//系统时间---对应结构体SDK_SYSTEM_TIME(接口VIDEONET_SetSystemDateTime也可以实现)
	E_SDK_CONFIG_CLEAR_LOG,				//清除日志(接口VIDEONET_ControlDVR)											
	E_SDK_REBOOT_DEV,					//重启启动设备(接口VIDEONET_ControlDVR)												
	E_SDK_CONFIG_ABILITY_LANG,			//支持语言---对应结构体SDK_MultiLangFunction
	E_SDK_CONFIG_VIDEO_FORMAT,																	
	E_SDK_CONFIG_COMBINEENCODE = 50,	//组合编码---对应结构体SDK_CombineEncodeConfigAll
	E_SDK_CONFIG_EXPORT,				//配置导出														
	E_SDK_CONFIG_IMPORT,				//配置导入
	E_SDK_LOG_EXPORT,					//日志导出														
	E_SDK_CONFIG_COMBINEENCODEMODE, 	//组合编码模式---对应结构体SDK_CombEncodeModeAll
	E_SDK_WORK_STATE,					//运行状态---SDK_DVR_WORKSTATE(接口VIDEONET_GetDVRWorkState也可以获取)															
	E_SDK_ABILITY_LANGLIST, 			//实际支持的语言集---对应结构体SDK_MultiLangFunction									
	E_SDK_CONFIG_SNAP_STORAGE = 58,			//抓图设置---对应结构体SDK_SnapshotConfig
	E_SDK_CONFIG_NET_3G, 				//3G拨号---对应结构体SDK_Net3GConfig
	E_SDK_CONFIG_NET_MOBILE = 60, 		//手机监控---对应结构体SDK_NetMoblieConfig
	E_SDK_CONFIG_UPGRADEINFO, 			//获取升级信息/参数/文件名---对应结构体SDK_UpgradeInfo
	E_SDK_CONFIG_NET_DECODER,			//解码器地址设置V1(弃用)---对应结构体SDK_NetDecoderConfigAll
	E_SDK_ABILITY_VSTD, 				//实际支持的视频制式---对应结构体SDK_MultiVstd
	E_SDK_CONFIG_ABILITY_VSTD,			//支持视频制式---对应结构体SDK_MultiVstd
	E_SDK_CONFIG_NET_UPNP, 				//UPUN设置---对应结构体SDK_NetUPNPConfig
	E_SDK_CONFIG_NET_WIFI,				//WIFI---对应结构体SDK_NetWifiConfig
	E_SDK_CONFIG_SYSENCODE_SIMPLIIFY = 68, 	//简化的编码配置---对应结构SDK_EncodeConfigAll_SIMPLIIFY
	E_SDK_CONFIG_NET_ALARM = 70,		//网络告警---对应结构体SDK_NETALARMCONFIG_ALL																		
	E_SDK_VIDEO_PREVIEW = 77,				//
	E_SDK_CONFIG_NET_DECODER_V2,		//解码器地址设置V2(弃用)---对应结构体SDK_NetDecorderConfigAll_V2
	E_SDK_CONFIG_NET_DECODER_V3,		//解码器地址设置V3---对应结构体SDK_NetDecorderConfigAll_V3
	E_SDK_CONFIG_ABILITY_SERIALNO = 80,	//序列号---对应结构体SDK_AbilitySerialNo(经测试不是设备序列号(暂弃用),序列号可以从登陆接口获取到)
	E_SDK_CONFIG_NET_RTSP,    			//RTSP---对应结构体SDK_NetRTSPConfig
	E_SDK_CATCHPIC = 83,               	//抓图												
	E_SDK_VIDEOCOLOR,             		//视频颜色设置---对应结构体SDK_VideoColorConfigAll
	E_SDK_CONFIG_COMM485,				//串口485协议配置---对应结构体SDK_STR_RS485CONFIG_ALL
	E_SDK_COMFIG_ABILITY_COMMPRO485, 	//串口485协议---对应结构体SDK_COMMFUNC
	E_SDK_CONFIG_SYS_TIME_NORTC,		//设置系统时间noRtc---对应结构体SDK_SYSTEM_TIME
	E_SDK_CONFIG_REMOTECHANNEL,   		//远程通道---弃用
	E_SDK_CONFIG_OPENTRANSCOMCHANNEL , 	//打开透明串口---对应结构体TransComChannel
	E_SDK_CONFIG_CLOSETRANSCOMCHANNEL = 90,//关闭透明串口
	E_SDK_CONFIG_SERIALWIRTE,  			//写入透明串口信息
	E_SDK_CONFIG_SERIALREAD,   			//读取透明串口信息
	E_SDK_CONFIG_CHANNELTILE_DOT,		//点阵信息-修改IPC通道名需要点阵信息---对应结构体SDK_TitleDot
	E_SDK_CONFIG_CAMERA,           		//摄象机参数---对应结构体SDK_CameraParam
	E_SDK_CONFIG_ABILITY_CAMERA,    	//曝光能力级---对应结构体SDK_CameraAbility
	E_SDK_CONFIG_BUGINFO,    			//命令调试													
	E_SDK_CONFIG_STORAGENOTEXIST,		//硬盘不存在---对应结构体SDK_VIDEOLOSSCONFIG
	E_SDK_CONFIG_STORAGELOWSPACE, 		//硬盘容量不足---对应结构体SDK_StorageLowSpaceConfig								
	E_SDK_CONFIG_STORAGEFAILURE, 		//硬盘出错---对应结构体SDK_StorageFailConfig
	E_SDK_CFG_NETIPCONFLICT = 100,   	//IP冲突---对应结构体SDK_VIDEOLOSSCONFIG
	E_SDK_CFG_NETABORT,  				//网络异常---对应结构体SDK_VIDEOLOSSCONFIG
	E_SDK_CONFIG_CHNSTATUS, 			//通道状态---对应结构体SDK_NetDecorderChnStatusAll
	E_SDK_CONFIG_CHNMODE,  				//通道模式---对应结构体SDK_NetDecorderChnModeConfig
	E_SDK_CONFIG_NET_DAS,    			//主动注册---对应结构体SDK_DASSerInfo
	E_SDK_CONFIG_CAR_INPUT_EXCHANGE,    //外部信息输入与车辆状态的对应关系---对应结构体SDK_CarStatusExchangeAll			
	E_SDK_CONFIG_NET_ORDER = 107,       //网络优先级---对应结构体SDK_NetOrderConfig
	E_SDK_CONFIG_ABILITY_NETORDER , 	//网络优先级设置能力---对应结构体SDK_NetOrderFunction
	E_SDK_CONFIG_CARPLATE,				//车牌号配置---对应结构体SDK_CarPlates
	E_SDK_CONFIG_LOCALSDK_NET_PLATFORM = 110, //网络平台信息设置---对应结构体SDK_LocalSdkNetPlatformConfig
	E_SDK_CONFIG_VIDEO_ANALYZE = 112, 		//视频分析(智能DVR)---对应结构体SDK_ANALYSECONFIG
	E_SDK_CONFIG_BUGINFOSAVE = 115,     		//命令调试(保存)									 
	E_SDK_CONFIG_MEDIA_WATERMARK,		//水印设置---对应结构体SDK_WaterMarkConfigAll
	E_SDK_CONFIG_ENCODE_STATICPARAM,	//编码器静态参数---对应结构体SDK_EncodeStaticParamAll
	E_SDK_CONFIG_LOSS_SHOW_STR,		    //视频丢失显示字符串
	E_SDK_CONFIG_DIGMANAGER_SHOW,	    //通道管理显示配置---对应结构体SDK_DigManagerShowStatus
	E_SDK_CONFIG_ABILITY_ANALYZEABILITY = 120,//智能分析能力---对应结构体SDK_ANALYZEABILITY
	E_SDK_CONFIG_VIDEOOUT_PRIORITY,   //显示HDMI VGA优先级别配置
	E_SDK_CONFIG_STORAGE_POSITION = 124,    // 录像存储设备类型---对应结构体SDK_RecordStorageType
	E_SDK_CFG_VPN,					//VPN---对应结构体SDK_VPNConfig
	E_SDK_CFG_VIDEOOUT,				//VGA视频分辨率---对应结构体SDK_VGAresolution
	E_SDK_CFG_ABILITY_VGARESOLUTION,//支持的VGA分辨率列表---对应结构体SDK_VGAResolutionAbility
	E_SDK_CFG_NET_LOCALSEARCH,      //搜索设备，设备端的局域网设备---对应结构体SDK_NetDevList
	E_SDK_CFG_NETPLAT_KAINENG = 130,//客户配置---对应结构体SDK_CONFIG_KAINENG_INFO
	E_SDK_CFG_ENCODE_STATICPARAM_V2,//DVR编码器静态参数---对应结构体SDK_EncodeStaticParamV2
	E_SDK_ABILITY_ENC_STATICPARAM,	//静态编码能力集---对应结构体SDK_EncStaticParamAbility (掩码)
	E_SDK_CFG_SPVMN_PLATFORM = 137,       //28181协议配置---对应结构体SDK_ASB_NET_VSP_CONFIG	
	E_SDK_CFG_OSD_INFO,             //屏幕提示信息---对应结构体SDK_OSDInfoConfigAll
	E_SDK_CFG_DIGITAL_REAL = 141,			//真正支持的通道模式---对应结构体SDK_VideoChannelManage
	E_SDK_ABILITY_PTZCONTROL,		//PTZ控制能力集---对应结构体SDK_PTZControlAbility
	E_SDK_CFG_XMHEARTBEAT,			//对应结构体SDK_XMHeartbeatConfig
	E_SDK_CFG_PARAM_EX = 145,				//摄像头扩展参数---对应结构体SDK_CameraParamEx
	E_SDK_WIFI_STATUS = 148,				//Wifi连接信息---对应结构体SDK_WifiStatusInfo
	E_SDK_3G_STATUS,  				//3G连接信息---对应结构体SDK_WirelessStatusInfo
	E_SDK_DAS_STATUS = 150, 		//主动注册状态---对应结构体SDK_DASStatusInfo 
	E_SDK_ABILITY_DECODE_DELEY,		//解码策略能力---对应结构体SDK_DecodeDeleyTimePrame
	E_SDK_CFG_DECODE_PARAM,     	//解码最大延时---对应结构体SDK_DecodeParam
	E_SDK_CFG_VIDEOCOLOR_CUSTOM,    //SDK_VIDEOCOLOR_PARAM_CUSTOM
	E_SDK_ABILITY_ONVIF_SUB_PROTOCOL,//onvif子协议---对应结构体SDK_AbilityMask   
	E_SDK_CONFIG_EXPORT_V2,      	//导出设备默认配置，即出厂的配置
	E_SDK_CFG_IPC_ALARM = 157,			//IPC网络报警---对应结构体SDK_IPCAlarmConfigAll
	E_SDK_CFG_IPC_IP = 161,           	//控制DVR去修改设备IP---对应结构体SDK_IPSetCfg
	E_SDK_CFG_TIME_ZONE = 165,			//时区配置---对应结构体SDK_TimeZone
	E_SDK_CFG_NETBJTHY,       		//客户配置---对应结构体SDK_MonitorPlatformConfig
	E_SDK_ABILITY_MAX_PRE_RECORD,   //最大可设置预录时间1~30---对应结构体SDK_AbilityMask
	E_SDK_CFG_DIG_TIME_SYN,			//数字通道时间同步配置(决定前端同步方式)---对应结构体SDK_TimeSynParam
	E_SDK_CONFIG_OSDINFO_DOT,		//3行OSD
	E_SDK_CFG_NET_POS = 170,		//POS机配置---对应结构体SDK_NetPosConfigAll
	E_SDK_CFG_CUSTOMIZE_OEMINFO,	//定制OEM客户版本信息---对应结构体SDK_CustomizeOEMInfo
	E_SDK_CFG_DIGITAL_ENCODE, 		//数字通道精简版编码配置---对应结构体SDK_EncodeConfigAll_SIMPLIIFY
	E_SDK_CFG_DIGITAL_ABILITY, 		//数字通道的编码能力---对应结构体SDK_DigitDevInfo
	E_SDK_CFG_ENCODECH_DISPLAY,		//IE端编码配置显示的前端通道号---对应结构体SDK_EncodeChDisplay
	E_SDK_CFG_RESUME_PTZ_STATE,		//开机云台状态---对应结构体SDK_ResumePtzState
	E_SDK_CFG_LAST_SPLIT_STATE,   	//最近一次的画面分割模式，用于重启后恢复之前的分割模式
	E_SDK_CFG_SYSTEM_TIMING_WORK,   //设备定时开关机时间配置。隐藏在自动维护页面里，要用超级密码登陆才能看到界面
	E_SDK_ABILITY_AHD_ENCODE_L = 179, 	//AHDL能力集---对应结构体SDK_AHDEncodeLMask
	E_SDK_CFG_SPEEDALARM = 180,		//速度报警---对应结构体SDK_SpeedAlarmConfigAll
	E_SDK_CFG_CORRESPONDENT_INFO,	//用户自定义配置---对应结构体SDK_CorrespondentOwnInfo
	E_SDK_SET_OSDINFO,				//OSD信息设置---对应结构体SDK_OSDInfo,(此项功能只支持模拟通道)
	E_SDK_SET_OSDINFO_V2,			//OSD信息叠加，不保存配置---对应结构体SDK_OSDInfoConfigAll，(此项功能只支持模拟通道)
	E_SDK_ABILITY_SUPPORT_EXTSTREAM,//支持辅码流录像---对应结构体SDK_AbilityMask
	E_SDK_CFG_EXT_RECORD,			//辅码流配置---对应结构体SDK_RECORDCONFIG_ALL/SDK_RECORDCONFIG
	E_SDK_CFG_APP_DOWN_LINK,		//用于用户定制下载链接---对应结构体SDK_AppDownloadLink
	E_SDK_CFG_TRANS_COMM_DATA = 188, 		//串口数据主动上传到UDP或TCP服务器，其中TCP服务器可以支持双向通信---对应结构体SDK_NetTransCommData
	E_SDK_CFG_GSENSORALARM = 193,			//GSENSOR报警
	E_SDK_CFG_SYSTEMTIME=212,			//设置时间的命令 ,当局域网连接的时候,连接的时候,发送对时命令 --Json接口 "Name":"System.Time"
	E_SDK_OPERATION_SET_LOGO = 225,	    //视频上叠加厂家的LOGO---对应结构体SDK_SetLogo
	E_SDK_CFG_IPV6_ADDRESS = 231,			//ipv6------对应的结构体SDK_IPAddressV6
	E_SDK_CFG_DDNS_IPMSG,         	//DDNS外网IP地址
	E_SDK_CFG_ONLINE_UPGRADE,		//在线升级相关配置-----对应的结构体SDK_OnlineUpgradeCfg
	E_SDK_CFG_CONS_SENSOR_ALARM,    //家用产品433报警联动项配置-----对应的SDK_ConsSensorAlarmCfg
	E_SDK_OPEARTION_SPLIT_CONTROL = 235,  //画面分割模式-----对应的结构体SDK_SplitControl
	E_SDK_CFG_RECORD_ENABLE = 237,       	//是否准备好开始录像和抓图，现在用于日本客户通过串口控制开启和关闭录像功能
	E_SDK_CFG_NAS,					//nas配置		//SDK_NAS_LIST
	E_SDK_OPERATION_UTC_TIME_SETTING = 244,	//设置UTC时间---对应结构体SDK_SYSTEM_TIME
	E_SDK_CFG_SPVMN_PLATFORM_SIP = 246,			//28181协议配置sip板卡ip-------SDK_SIP_NET_IP_CONFIG
	E_SDK_CFG_PTZCTRLMODE = 248,					//模拟通道云台控制的控制方式选择-----SDK_PTZControlModeAll
	E_SDK_CFG_ENCODE_SmartH264,				//SmartH264+配置------SDK_SmartH264ParamAll
	E_SDK_CFG_WIFI_INFO = 250,					//无线WIFI信息--SDK_WifiInfo
	E_SDK_CFG_NET_RTMP,						//RTMP协议--SDK_NetRTMPConfig
	E_SDK_CFG_SNAP_SCHEDULE,				//定时抓图配置--SDK_SnapConfigAll
	E_SDK_OPERATION_SET_LANGUAGE,			//设置一种语言
	E_SDK_CFG_PTZPRESET,					//预置点配置--SDK_PtzPreset
	E_SDK_CFG_PTZTOUR = 255,						//巡航配置--SDK_PtzTour
	E_SDK_CFG_BREVIARY = 259,						//缩略图配置
	E_SDK_CFG_SERIALPORT_ALARM = 260,				//串口报警配置--SDK_SerialPortAlarm
	E_SDK_OPEARTION_SET_LEARN_CODE,			//支持串口报警设置才能设置学码--SDK_AMIRLearnCode
	E_SDK_OPERATION_TIME_SETTING_NEW_WAY = 264,	//设置系统时间（想关掉时间同步的程序可以用这个命令，并禁用之前的时间设置命令）
	E_SDK_OPERATION_UTC_TIME_SETTING_NEW_WAY,//设置UTC时间（用于其他协议设置UTC时间）
	E_SDK_CFG_DDNSADDRINFO,					//DDNS状态信息
	E_SDK_CFG_INTEL_ENCODE = 269,					//智能编码--SDK_IntelEnCodeCfgAll
	E_SDK_CFG_PLATE_DETECT_WHITE_LIST = 270,		//车牌识别白名单--SDK_PlateDetectWhiteList
	E_SDK_OPERATION_PLATE_DETECT_LIFT,		//车牌侦测抬杆--SDK_PlateDetectLiftBar
	E_SDK_CFG_ALARM_PLATE_DETECT,			//车牌侦测报警--SDK_PlateDetectAll
	E_SDK_CFG_ALARM_FACE_DETECT,			//人脸识别报警--SDK_FaceDetectAll
	E_SDK_CFG_NET_IPADAPTIVE = 274,				//ip自适应网关功能使能配置--SDK_IPAdaptiveCfg
	E_SDK_CFG_OEM_GETINFO,					//客户定制获取系统信息--SDK_OemGetInfo
	E_SDK_CFG_433_ALARM_DEV,				//客户定制433报警配置--SDK_ConsumerAlarm433DevList
	E_SDK_CFG_NET_ONVIF_PWD_CHECKOUT,		//onvif 密码校验--SDK_IpcOnvifPwdCheckout
	E_SDK_CFG_BALL_CAMERA_TRACK_DETECT,		//球机跟踪识别配置--SDK_BallCameraTrackDetectParamAll
	E_SDK_CFG_CAMERA_SPECIAL_NIGHT = 279,			//夜晚情景特殊模式--SDK_CameraSpecialNightCtrl

	E_SDK_CFG_SMARTDETECTION_CODEC = 294,			//智能编码		by  20170911
	E_SDK_CFG_SMARTDETECTION_DETECT,		//智能检测		by  20170911
	E_SDK_CFG_SMARTDETECTION_CONTROL,		//智能控制		by  20170911
	E_SDK_CFG_SMARTDETECTION_LUMINANCE,		//亮度侦测		by  20170908
	E_SDK_CFG_SMARTDETECTION_MOVE,			//移动侦测		by  20170908
	E_SDK_CFG_SMARTDETECTION_OCCLUSION,		//遮挡侦测		by  20170908
	E_SDK_CFG_SMARTDETECTION_CROSSLINE = 300,		//虚拟警戒线	by  20170908
	E_SDK_CFG_SMARTDETECTION_CROSSAREA,		//区域入侵		by  20170908
	E_SDK_CFG_SMARTDETECTION_COLOR,			//颜色			by  20170908
	E_SDK_CFG_SMARTDETECTION_SOUND,			//声音			by  20170908
	E_SDK_CFG_SMARTDETECTION_LOSEOBJ,		//物品预留		by  20170908
	

	E_SDK_CFG_CALIBRATION_GET_CAMERA_PARAMETER,			//获取摄像机是否已经标定	
	E_SDK_CFG_CALIBRATION_SET_SUBCAMERA_CONNECTINFO,	//设置从机登录信息
	E_SDK_CFG_CALIBRATION_SET_POINTS,					//设置标定坐标(增、删，3D)
	E_SDK_CFG_CALIBRATION_ACTION,						//设置标定（开始、完成）
	E_SDK_CFG_CALIBRATION_MODE,							//标定模式
	E_SDK_CFG_CALIBRATION_ZOOMTIMES = 310,					//变倍系数
	E_SDK_CFG_CALIBRATION_PTZINFO,						//PTZ参数

	E_SDK_CFG_FACECOMPARE_RESULT_ALARM, 	//对比结果报警	 SDK_FA_FACECOMPARE_RESULT_ALARM					
	E_SDK_CFG_SMARTFACE_COMMON_PARAMETER,	//人脸识别参数	  SDK_FA_SMART_FACE				
	E_SDK_CFG_SMARTFACE_AREADETECTION,		//人脸识别侦测区域	SDK_FA_VI_DECTECT			
	E_SDK_CFG_SMARTFACE_VERSION,			//识别算法版本号	SDK_FA_ALGORITHM_Version			
	E_SDK_CFG_SMARTFACE_ALARM,				//人脸报警参数	SDK_SMART_ALARM				
	
}SDK_CONFIG_TYPE;

//云台操作类型
enum PTZ_ControlType
{
	TILT_UP = 0,					//上
	TILT_DOWN,						//下
	PAN_LEFT,						//左
	PAN_RIGHT,						//右
	PAN_LEFTTOP,					//左上
	PAN_LEFTDOWN,					//左下
	PAN_RIGTHTOP,					//右上
	PAN_RIGTHDOWN,					//右下
	ZOOM_OUT_1,						//变倍小//ZOOM_OUT/ZOOM_IN在VS2010与系统定义的冲突了
	ZOOM_IN_1,						//变倍大
	FOCUS_FAR,						//焦点后调
	FOCUS_NEAR,						//焦点前调
	IRIS_OPEN,						//光圈扩大
	IRIS_CLOSE,						//光圈缩小13

	EXTPTZ_OPERATION_ALARM,			//报警功能 
	EXTPTZ_LAMP_ON,					//灯光开
	EXTPTZ_LAMP_OFF,				//灯光关
	EXTPTZ_POINT_SET_CONTROL,		//设置预置点 
	EXTPTZ_POINT_DEL_CONTROL,		//清除预置点 
	EXTPTZ_POINT_MOVE_CONTROL,		//转预置点
	EXTPTZ_STARTPANCRUISE,			//开始水平旋转		20	
	EXTPTZ_STOPPANCRUISE,			//停止水平旋转	
	EXTPTZ_SETLEFTBORDER,			//设置左边界		
	EXTPTZ_SETRIGHTBORDER,			//设置右边界	
	EXTPTZ_STARTLINESCAN,			//自动扫描开始 
	EXTPTZ_CLOSELINESCAN,			//自动扫描开停止 
	EXTPTZ_ADDTOLOOP,				//加入预置点到巡航	p1巡航线路	p2预置点值	
	EXTPTZ_DELFROMLOOP,				//删除巡航中预置点	p1巡航线路	p2预置点值	
	EXTPTZ_POINT_LOOP_CONTROL,		//开始巡航 28
	EXTPTZ_POINT_STOP_LOOP_CONTROL,	//停止巡航
	EXTPTZ_CLOSELOOP,				//清除巡航	p1巡航线路		
	EXTPTZ_FASTGOTO,				//快速定位	
	EXTPTZ_AUXIOPEN,				//辅助开关，关闭在子命令中//param1 参见SDK_PtzAuxStatus，param2传入具体数值
	EXTPTZ_OPERATION_MENU,			//球机菜单操作，其中包括开，关，确定等等
	EXTPTZ_REVERSECOMM,				//镜头翻转
	EXTPTZ_OPERATION_RESET,			//云台复位

	EXTPTZ_TOTAL,
};
/// 云台辅助功能
enum SDK_PtzAuxStatus
{
	EXTPTZ_AUX_ON,	// 开
	EXTPTZ_AUX_OFF,	// 关
	EXTPTZ_AUX_NR,		
};

#define PAN_AUTO		29	/* 云台以SS的速度左右自动扫描 */
//#define EXTPTZ_FASTGOTO	30	//三维定位


#define NET_MAX_CHANNUM 			64			//最大通道个数
#define NET_DECORDR_CH              64          //最大解码通道个数
#define NET_MAX_USER_NUM			60			//最多用户数
#define NET_MAX_RIGTH_NUM			200			//最多权限数
#define NET_MAX_GROUP_NUM			50			//最多组数
#define NET_MAX_USER_LENGTH			32			//用户名密码最大长度
#define NET_MAX_COMBINE_NUM			2			//最大组合编码通道数
#define NET_MAX_DECORDR_CH          64          //最大解码通道个数	

#define NET_MAX_DDNS_TYPE			5			//支持的DDNS种类
#define NET_MAX_SYSFUNC				20			//最多系统功能个数
#define NET_MAX_PTZ_PROTOCOL_LENGTH 32			//云台协议名称最大长度
#define NET_N_WEEKS					7			//星期数
#define	NET_N_TSECT					6			//时间段数
#define NET_MD_REGION_ROW			32			//动态检测区域行数
#define NET_COVERNUM				8			 //覆盖区域数
#define NET_MAX_FILTERIP_NUM		64			//IP地址最大过滤数
#define NET_NAME_PASSWORD_LEN		64			//用户名密码最大长度
#define NET_MAX_PATH_LENGTH	        260			//路径长度
#define NET_N_MIN_TSECT				2
#define NET_MAX_RETURNED_LOGLIST	128			//最多日志条数
#define NET_MAX_MAC_LEN             32          //MAC地址字符最大长度
#define NET_IW_ENCODING_TOKEN_MAX   128
#define NET_MAX_AP_NUMBER           32          //SID最大数量，暂定10
#define NET_MAX_INFO_LEN		    128
#define NET_MAX_USERNAME_LENGTH		128
#define NET_MAX_SERIALNO_LENGTH		128         //最大解码通道个数
#define NET_CHANNEL_NAME_MAX_LEN    64			//通道名称最大长度
#define NET_MAX_LINE_PER_OSD_AREA   12			//编码中一个OSD区域最多可以显示的字符行数

//DDNS参数
#define DDNS_MAX_DDNS_NAMELEN       64  		//主机名长度
#define DDNS_MAX_DDNS_PWDLEN        32   		//密码长度
#define DDNS_MAX_DDNS_IPSIZE        64   		//IP地址长度
#define DDNS_MAX_DDNS_IDSIZE        32   		//设备标识长度
#define DDNS_MAX_SERIALINFO_SIZE    16 			//序列号以及用户名长度

#define  NET_MAX_MSK_SIZE           128			//掩码数组的大小


//摄象机参数
#define CAMERAPARA_MAXNUM           16    		//曝光能力中目前最大长度
//短信最大数量
#define NET_MAX_RECIVE_MSG_PHONE_COUNT 3		///<最大发生短信数量

//VGA分辨率
#define VGA_MAXNUM        32       				//分辨率 种类
#define VGA_NAME_LENGTH   10					//分辨率 长度	

//显示的设备列表(设备端搜索)
#define DEV_LIST_SHOW  256

//IP SIZE
#define IP_SIZE  16
//#define  MAX_HVR_CHNCAP 16
//DDNS服务器设备的信息

//通道模式
#define MAX_HVR_CHNCAP_CHN		32

#define  NET_NAME_TOKEN_LEN 128

#define  NET_NAME_URL_LEN 128
#define  NET_NAME_ID_LEN 64
#define  NET_MAX_POS_FUNC_KEYWORDS 4 //POS功能中最多支持的关键字个数
#define  NET_MAX_TITLE_DOT_BUF_LEN	 64*24*24
//硬盘信息
#define NET_FSLEN 8	//从IConstraint::FS_LEN拷过来

//地址大小和pin码大小
#define  NAME_TOKEN_LEN 128
#define  NAME_URL_LEN 128

typedef struct _DDNS_INFO
{
	char ID[64];    						//设备标识
	char Alias[DDNS_MAX_DDNS_NAMELEN];
	char IP[DDNS_MAX_DDNS_IPSIZE];   		//外网IP
	char LanIP[DDNS_MAX_DDNS_IPSIZE];		//内网IP
	int WebPort; 							//Web端口,默认为80
	int MediaPort; 							//媒体端口,默认为34567
	int MobilePort;  						//手机监控端口，默认为34599
	int UPNPWebPort;  						//UPNP启动下Web端口,UPNP不开启为0
	int UPNPMediaPort; 						//UPNP启动下媒体端口,UPNP不开启为0
	int UPNPMobilePort; 					//UPNP启动下手机监控端口,UPNP不开启为0
	int ChannelNum; 						//通道数
	int Status; 							//状态
	char Username[DDNS_MAX_DDNS_NAMELEN]; 	//用户名
	char Password[DDNS_MAX_DDNS_PWDLEN]; 	//密码
}DDNS_INFO,*pDDNS_INFO;

//DDNS信息查询模式
typedef struct _SearchMode
{
	int  nType;        								//查询类型，见SearchModeType
	char szSerIP[DDNS_MAX_DDNS_IPSIZE];				//服务器地址
	int nSerPort;           						//服务器端口号
	char szSerialInfo[DDNS_MAX_SERIALINFO_SIZE];  	//如果是按序列号，则为序列号，如果是用户名，则为用户名
	char szPassWord[DDNS_MAX_DDNS_PWDLEN]; 			//按用户名登陆时候的密码

}SearchMode;

//DDNS信息查询类型
enum SearchModeType
{
	DDNS_SERIAL = 0,//按序列号
	DDNS_USERNAME,  //按用户名
};
//实时预览扩展接口增加的参数：预览类型
typedef enum _VIDEONET_RealPlayType
{
	NET_RType_Realplay = 0,		//实时预览
	NET_RType_Main_Realplay2,	//实时监视-主码流，等同于NET_RType_Realplay
	NET_RType_Main_Realplay3,
	NET_RType_Sub_Realplay_1,	//实时监视-从码流1
	NET_RType_Sub_Realplay_2,	//实时监视-从码流2
	NET_RType_Sub_Realplay_3,	//实时监视-从码流3

	NET_RType_Multiplay_1,		//多画面预览－1画面
	NET_RType_Multiplay_4,		//多画面预览－4画面
	NET_RType_Multiplay_6,		//多画面预览－6画面
	NET_RType_Multiplay_8,		//多画面预览－8画面
	NET_RType_Multiplay_9,		//多画面预览－9画面
	NET_RType_Multiplay_12,		//多画面预览－12画面
	NET_RType_Multiplay_16,		//多画面预览－16画面
} NET_RealPlayType;

/// 组合编码模式
enum NetCombinType
{
	NET_COMBIN_NONE,
	NET_COMBIN_1,
	NET_COMBIN_2,
	NET_COMBIN_3,
	NET_COMBIN_4,
	NET_COMBIN_5,
	NET_COMBIN_6,
	NET_COMBIN_7,
	NET_COMBIN_8,
	NET_COMBIN_9,
	NET_COMBIN_10,
	NET_COMBIN_11,
	NET_COMBIN_12,
	NET_COMBIN_13,
	NET_COMBIN_14,
	NET_COMBIN_15,
	NET_COMBIN_16,
	NET_COMBIN_1_4,
	NET_COMBIN_5_8,
	NET_COMBIN_9_12,
	NET_COMBIN_13_16,
	NET_COMBIN_1_8,
	NET_COMBIN_9_16,
	NET_COMBIN_1_9,
	NET_COMBIN_8_16,
	NET_COMBIN_1_16
};

//这些结构体和枚举是提供给外部使用，所有可能会和设备那边定义了2次,所以都在前面加了SDK_
enum SDK_CAPTURE_SIZE_t {
	SDK_CAPTURE_SIZE_D1,		///< 720*576(PAL)	720*480(NTSC)   800*480
	SDK_CAPTURE_SIZE_HD1,		///< 352*576(PAL)	352*480(NTSC)
	SDK_CAPTURE_SIZE_BCIF,		///< 720*288(PAL)	720*240(NTSC)
	SDK_CAPTURE_SIZE_CIF,		///< 352*288(PAL)	352*240(NTSC)
	SDK_CAPTURE_SIZE_QCIF,		///< 176*144(PAL)	176*120(NTSC)
	SDK_CAPTURE_SIZE_VGA,		///< 640*480(PAL)	640*480(NTSC)
	SDK_CAPTURE_SIZE_QVGA,		///< 320*240(PAL)	320*240(NTSC)
	SDK_CAPTURE_SIZE_SVCD,		///< 480*480(PAL)	480*480(NTSC)
	SDK_CAPTURE_SIZE_QQVGA,		///< 160*128(PAL)	160*128(NTSC)
	SDK_CAPTURE_SIZE_ND1 = 9,   ///< 240*192
	SDK_CAPTURE_SIZE_650TVL,    ///< 926*576
	SDK_CAPTURE_SIZE_720P,      ///< 1280*720
	SDK_CAPTURE_SIZE_1_3M,      ///< 1280*960
	SDK_CAPTURE_SIZE_UXGA ,     ///< 1600*1200
	SDK_CAPTURE_SIZE_1080P,     ///< 1920*1080
	SDK_CAPTURE_SIZE_WUXGA,     ///< 1920*1200
	SDK_CAPTURE_SIZE_2_5M,      ///< 1872*1408
	SDK_CAPTURE_SIZE_3M,        ///< 2048*1536
	SDK_CAPTURE_SIZE_5M,        ///< 3744*1408
	SDK_CAPTURE_SIZE_NR =19,
	SDK_CAPTURE_SIZE_1080N = 19,///< 960*1080
	SDK_CAPTURE_SIZE_4M,        ///< 2592*1520
	SDK_CAPTURE_SIZE_6M,		///< 3072×2048
	SDK_CAPTURE_SIZE_8M,		///< 3264×2448
	SDK_CAPTURE_SIZE_12M,		///< 4000*3000
	SDK_CAPTURE_SIZE_4K,		///< 4096 * 2160通用/3840*2160海思
	SDK_CAPTURE_SIZE_EXT_V2_NR =25,
	SDK_CAPTURE_SIZE_720N = 25,  	///< 640*720
	SDK_CAPTURE_SIZE_WSVGA,			///< 1024*576
	SDK_CAPTURE_SIZE_NHD,			///< Wifi IPC 640*360
	SDK_CAPTURE_SIZE_3M_N,			///< 1024*1536
	SDK_CAPTURE_SIZE_4M_N,			///< 1296*1520
	SDK_CAPTURE_SIZE_5M_N,			///< 1872*1408
	SDK_CAPTURE_SIZE_4K_N,			///< 2048 * 2160通用/1920*2160海思
	SDK_CAPTURE_SIZE_EXT_V3_NR,
};

/// 捕获码流控制模式类型
enum SDK_capture_brc_t {
	SDK_CAPTURE_BRC_CBR,			///< 固定码流。
	SDK_CAPTURE_BRC_VBR,			///< 可变码流。
	SDK_CAPTURE_BRC_MBR,			///< 混合码流。
	SDK_CAPTURE_BRC_NR				///< 枚举的码流控制模式数目。
};

/// 捕获压缩格式类型
enum SDK_CAPTURE_COMP_t {
	SDK_CAPTURE_COMP_DIVX_MPEG4,	///< DIVX MPEG4。
	SDK_CAPTURE_COMP_MS_MPEG4,		///< MS MPEG4。
	SDK_CAPTURE_COMP_MPEG2,			///< MPEG2。
	SDK_CAPTURE_COMP_MPEG1,			///< MPEG1。
	SDK_CAPTURE_COMP_H263,			///< H.263
	SDK_CAPTURE_COMP_MJPG,			///< MJPG
	SDK_CAPTURE_COMP_FCC_MPEG4,		///< FCC MPEG4
	SDK_CAPTURE_COMP_H264,			///< H.264
	SDK_CAPTURE_COMP_H265,			///< H.265
	SDK_CAPTURE_COMPRESS_H265_S,	///< H.265+
	SDK_CAPTURE_COMP_NR				///< 枚举的压缩标准数目。
};

/// 捕获通道类型
enum SDK_CAPTURE_CHANNEL_t {
	SDK_CHL_MAIN_T = 0,		///< 主通道	－	主码流1 
	SDK_CHL_2END_T = 1,		///< 辅通道	－	出辅码流2 
	SDK_CHL_3IRD_T = 2,		///< 辅通道	－	出辅码流3 
	SDK_CHL_4RTH_T = 3,		///< 辅通道	－	出辅码流4 
	SDK_CHL_JPEG_T = 4,		///< 辅通道	－	出JPEG抓图 
	SDK_CHL_FUNCTION_NUM
};
/// 音频编码类型
enum SDK_AudioEncodeTypes
{
	SDK_AUDIO_ENCODE_NONE = 0,
	SDK_AUDIO_ENCODE_G729_8KBIT,
	SDK_AUDIO_ENCODE_G726_16KBIT,
	SDK_AUDIO_ENCODE_G726_24KBIT,
	SDK_AUDIO_ENCODE_G726_32KBIT,
	SDK_AUDIO_ENCODE_G726_40KBIT,
	SDK_AUDIO_ENCODE_PCM_8TO16BIT,
	SDK_AUDIO_ENCODE_PCM_ALAW,
	SDK_AUDIO_ENCODE_PCM_ULAW,
	SDK_AUDIO_ENCODE_ADPCM8K16BIT,
	SDK_AUDIO_ENCODE_ADPCM16K16BIT,
	SDK_AUDIO_ENCODE_G711_ALAW,
	SDK_AUDIO_ENCODE_MPEG2_LAYER1,
	SDK_AUDIO_ENCODE_AMR8K16BIT,
	SDK_AUDIO_ENCODE_G711_ULAW,
	SDK_AUDIO_ENCODE_IMA_ADPCM_8K16BIT,
	SDK_AUDIO_ENCODE_TYPES_NR,
};

/// 报警事件码
enum SDK_EventCodeTypes
{
	SDK_EVENT_CODE_INIT = 0,
	SDK_EVENT_CODE_LOCAL_ALARM = 1,		//本地报警(外部报警)
	SDK_EVENT_CODE_NET_ALARM,			//网络报警
	SDK_EVENT_CODE_MANUAL_ALARM,		//手动报警
	SDK_EVENT_CODE_VIDEO_MOTION,		//动态检测
	SDK_EVENT_CODE_VIDEO_LOSS,			//视频丢失
	SDK_EVENT_CODE_VIDEO_BLIND,			//视频遮挡
	SDK_EVENT_CODE_VIDEO_TITLE,		
	SDK_EVENT_CODE_VIDEO_SPLIT,
	SDK_EVENT_CODE_VIDEO_TOUR,
	SDK_EVENT_CODE_STORAGE_NOT_EXIST,	//存储设备不存在
	SDK_EVENT_CODE_STORAGE_FAILURE,		//存储设备访问失败
	SDK_EVENT_CODE_LOW_SPACE,			//存储设备容量过低
	SDK_EVENT_CODE_NET_ABORT,
	SDK_EVENT_CODE_COMM,
	SDK_EVENT_CODE_STORAGE_READ_ERROR,	//存储设备读错误
	SDK_EVENT_CODE_STORAGE_WRITE_ERROR,	//存储设备写错误
	SDK_EVENT_CODE_NET_IPCONFLICT,		//ip冲突
	SDK_EVENT_CODE_ALARM_EMERGENCY,
	SDK_EVENT_CODE_DEC_CONNECT,	
	SDK_EVENT_CODE_UPGRADE,
	SDK_EVENT_CODE_BACK_UP,
	SDK_EVENT_CODE_SHUT_DOWN,
	SDK_EVENT_CODE_REBOOT,
	SDK_EVENT_CODE_NEWFILE,
	SDK_EVENT_CODE_VideoAnalyze,
	SDK_EVENT_CODE_IPC_ALARM,
	SDK_EVENT_CODE_SPEED_ALARM,
	SDK_EVENT_CODE_GSENSOR_AlARM,
	SDK_EVENT_CODE_LOGIN_FAILED,		//登录失败
	SDK_EVENT_CODE_SERIAL_ALARM,
	SDK_EVENT_CODE_NR,
};
//! 编码配置的类型
enum SDK_ENCODE_TYPE_BY_RECORD
{
	SDK_ENCODE_TYPE_TIM = 0,
	SDK_ENCODE_TYPE_MTD = 1,
	SDK_ENCODE_TYPE_ALM = 2,
	SDK_ENCODE_TYPE_NUM = 3,
	SDK_ENCODE_TYPE_SNAP_TIMER = 0,
	SDK_ENCODE_TYPE_SNAP_TRIGGER = 1,
};
#define SDK_EXTRATYPES 3 //辅码流类型

//网络传输策略
enum SDK_TransferPolicy
{
	SDK_TRANSFER_POLICY_AUTO,			///< 自适应
	SDK_TRANSFER_POLICY_QUALITY,		///< 质量优先
	SDK_TRANSFER_POLICY_FLUENCY,		///< 流量优先
	SDK_TRANSFER_POLICY_TRANSMISSION,	///< 网传优先
	SDK_TRANSFER_POLICY_NR,
};

/// 网络传输协议类型
enum SDK_NetTransProtocolType
{
	SDK_NET_TRANS_PRO_TCP = 0,
	SDK_NET_TRANS_PRO_UDP = 1,
};

typedef struct {
	int left;
	int top;
	int right;
	int bottom;
}sdkRect;

/// 音频输入格式，语音对讲用
typedef struct SDK_AudioInFormatConfig
{
	int iBitRate;	   ///< 码流大小，kbps为单位，比如192kbps，128kbps
	int iSampleRate;   ///< 采样率，Hz为单位，比如44100Hz
	int iSampleBit;    ///< 采样的位深
	int iEncodeType;   ///< 编码方式，参照AudioEncodeTypes定义
}SDK_AudioInFormatConfig;

//语音对讲格式
typedef enum __TALK_CODING_TYPE
{
	TALK_DEFAULT = 0,
	TALK_PCM = 1,		//PCM
	TALK_G711a,			//G711a
	TALK_AMR,			//AMR
	TALK_G711u,			//G711u
	TALK_G726,			//G726
}TALK_CODING_TYPE;
//语音对讲
typedef struct VIDEONET_TALKDECODE_INFO
{
	TALK_CODING_TYPE		encodeType;		//编码类型
	int						nAudioBit;		//用实际的值表示，如8位 则填值为8
	unsigned int			dwSampleRate;	//采样率，如16k 则填值为16000
	char					reserved[64];
}VIDEONET_TALKDECODE_INFO;


/// 系统时间结构
typedef struct SDK_SYSTEM_TIME{
	int  year;		///< 年。   
	int  month;		///< 月，January = 1, February = 2, and so on.   
	int  day;		///< 日。   
	int  wday;		///< 星期，Sunday = 0, Monday = 1, and so on   
	int  hour;		///< 时。   
	int  minute;	///< 分。   
	int  second;	///< 秒。   
	int  isdst;		///< 夏令时标识。   
}SDK_SYSTEM_TIME;

//录像设置相关结构体
typedef struct SDK_TIMESECTION
{
	//!使能
	int enable;
	//!开始时间:小时
	int startHour;
	//!开始时间:分钟
	int	startMinute;
	//!开始时间:秒钟
	int	startSecond;
	//!结束时间:小时
	int	endHour;
	//!结束时间:分钟
	int	endMinute;
	//!结束时间:秒钟
	int	endSecond;
}SDK_TIMESECTION;

typedef struct{
	int dwYear;		//年
	int dwMonth;	//月
	int dwDay;		//日
	int dwHour;		//时
	int dwMinute;	//分
    int dwSecond;	//秒
}VIDEONET_TIME,*LPVIDEONET_TIME;

//时间结构
typedef struct _NEW_NET_TIME
{
	unsigned int second		:6;		//	秒	1-60		
	unsigned int minute		:6;		//	分	1-60		
	unsigned int hour		:5;		//	时	1-24		
	unsigned int day		:5;		//	日	1-31		
	unsigned int month		:4;		//	月	1-12		
	unsigned int year		:6;		//	年	2000-2063	
}NEW_NET_TIME, *LPNET_TIME;
///< 夏令时结构
typedef struct DSTPoint
{
	int	iYear;
	int	iMonth;
	int	iWeek;		///<周1:first  to2 3 4 -1:last one   0:表示使用按日计算的方法[-1,4]
	int	iWeekDay;	///<weekday from sunday=0	[0, 6]
	int Hour;
	int Minute;
}DSTPoint;

typedef struct SDK_VIDEO_FORMAT
{
	int		iCompression;			//  压缩模式(视频格式) 参照enum SDK_CAPTURE_COMP_t 	
	int		iResolution;			//  分辨率 参照枚举SDK_CAPTURE_SIZE_t
	int		iBitRateControl;		//  码流控制 参照枚举SDK_capture_brc_t
	int		iQuality;				//  码流的画质 档次1-6		
	int		nFPS;					//  帧率值，NTSC/PAL不区分,负数表示多秒一帧		
	int		nBitRate;				//  0-4096k,该列表主要由客户端保存，设备只接收实际的码流值而不是下标。
	int		iGOP;					//  描述两个I帧之间的间隔时间，2-12 
} SDK_VIDEO_FORMAT;

typedef struct  SDK_AUDIO_FORMAT
{
	int		nBitRate;				//  码流kbps	
	int		nFrequency;				//  采样频率	
	int		nMaxVolume;				//  最大音量阈值
}SDK_AUDIO_FORMAT;

// 媒体格式
typedef struct SDK_MEDIA_FORMAT
{
	SDK_VIDEO_FORMAT vfFormat;		//  视频格式定义 			
	SDK_AUDIO_FORMAT afFormat;		//  音频格式定义 
	bool	bVideoEnable;			//  开启视频编码 
	bool	bAudioEnable;			//  开启音频编码 	
} SDK_MEDIA_FORMAT;

typedef union {	//IP addr
	unsigned char	c[4];
	unsigned short	s[2];
	unsigned int 	l;
}CONFIG_IPAddress;

///////////////////用户帐号管理相关结构体/////////////////////////////////
typedef struct _OPR_RIGHT
{
	char name[NET_MAX_USER_LENGTH];
}OPR_RIGHT;

typedef struct _USER_INFO
{
	int			rigthNum;
	char		rights[NET_MAX_RIGTH_NUM][NET_MAX_USER_LENGTH];
	char		Groupname[NET_MAX_USER_LENGTH];
	char		memo[NET_MAX_USER_LENGTH];
	char		name[NET_MAX_USER_LENGTH];
	char		passWord[NET_MAX_USER_LENGTH];
	bool		reserved;		//是否保留
	bool		shareable;		//本用户是否允许复用 1-复用，0-不复用
}USER_INFO;

typedef struct _USER_GROUP_INFO
{
	int			rigthNum;
	char		memo[NET_MAX_USER_LENGTH]; 
	char		name[NET_MAX_USER_LENGTH];
	char		rights[NET_MAX_RIGTH_NUM][NET_MAX_USER_LENGTH];	//权限列表
}USER_GROUP_INFO;

//用户信息配置结构
typedef struct _USER_MANAGE_INFO
{
	int					rigthNum;
	OPR_RIGHT			rightList[NET_MAX_RIGTH_NUM];
	int					groupNum;
	USER_GROUP_INFO		groupList[NET_MAX_GROUP_NUM];
	int					userNum;
	USER_INFO			userList[NET_MAX_USER_NUM];
}USER_MANAGE_INFO;

//修改用户
typedef struct _CONF_MODIFYUSER
{
	char UserName[NET_MAX_USER_LENGTH];
	USER_INFO User;
}CONF_MODIFYUSER;

//修改组
typedef struct _CONF_MODIFYGROUP
{
	char GroupName[NET_MAX_USER_LENGTH];
	USER_GROUP_INFO Group;
}CONF_MODIFYGROUP;


/// 修改用户密码请求
struct _CONF_MODIFY_PSW
{
	char sUserName[NET_MAX_USER_LENGTH];
	char Password[NET_MAX_USER_LENGTH];
    char NewPassword[NET_MAX_USER_LENGTH];
};

//普通配置页结构体
typedef struct _SDK_CONFIG_NORMAL
{
	SDK_SYSTEM_TIME sysTime;		//系统时间

	int  iLocalNo;				///< 本机编号:[0, 998] */
	int  iOverWrite;			///< 硬盘满时处理 "OverWrite（iOverWrite=1）", "StopRecord（iOverWrite=0）" */		
	char cIranCalendarEnable;	///< 是否启用伊朗日历，1表示启用，0表示不启用
	char cFontSize;				///< 矢量字体大小
	char reserved[2];
	char sMachineName[64];		///< 机器名
	int  iVideoStartOutPut;		///< 输出模式 */
	int  iAutoLogout;			///< 本地菜单自动注销(分钟)	[0, 120]

	int  iVideoFormat;			///< 视频制式:“PAL”:0, “NTSC”:1, “SECAM” */
	int  iLanguage;				///< 语言选择:“English”, “SimpChinese”, “TradChinese”, “Italian”, “Spanish”, “Japanese”, “Russian”, “French”, “German” */	
	int  iDateFormat;			///< 日期格式:“YYMMDD”, “MMDDYY”, “DDMMYY” */
	int  iDateSeparator;		///< 日期分割符:“.”, “-”, “/” */
	int  iTimeFormat;			///< 时间格式:“12”, “24” */
	int  iDSTRule;				///< 夏令时规则 
	int  iWorkDay;				///< 工作日
	DSTPoint dDSTStart;
	DSTPoint dDSTEnd;
}SDK_CONFIG_NORMAL;


//以下编码配置相关
// 编码设置
typedef struct SDK_CONFIG_ENCODE
{
	SDK_MEDIA_FORMAT dstMainFmt[SDK_ENCODE_TYPE_NUM];	//  主码流格式 	
	SDK_MEDIA_FORMAT dstExtraFmt[SDK_EXTRATYPES];		//  辅码流格式 
	SDK_MEDIA_FORMAT dstSnapFmt[SDK_ENCODE_TYPE_NUM];	//  抓图格式 
}SDK_CONFIG_ENCODE;

typedef struct  SDK_EncodeConfigAll
{
	SDK_CONFIG_ENCODE vEncodeConfigAll[NET_MAX_CHANNUM];
}SDK_EncodeConfigAll;


// 简化版本编码配置
/// 媒体格式
typedef struct SDK_MEDIA_FORMAT_SIMPLIIFY
{
	SDK_VIDEO_FORMAT vfFormat;		//  视频格式定义 			
	bool	bVideoEnable;			//  开启视频编码 
	bool	bAudioEnable;			//  开启音频编码 	
}SDK_MEDIA_FORMAT_SIMPLIIFY;

/// 编码设置
typedef struct SDK_CONFIG_ENCODE_SIMPLIIFY
{
	SDK_MEDIA_FORMAT dstMainFmt;	//  主码流格式 	
	SDK_MEDIA_FORMAT dstExtraFmt;	//  辅码流格式 
}SDK_CONFIG_ENCODE_SIMPLIIFY;

/// 全通道编码配置
typedef struct SDK_EncodeConfigAll_SIMPLIIFY
{
	SDK_CONFIG_ENCODE_SIMPLIIFY vEncodeConfigAll[NET_MAX_CHANNUM];
}SDK_EncodeConfigAll_SIMPLIIFY;


typedef struct  SDK_CombineEncodeConfigAll
{
	SDK_CONFIG_ENCODE vEncodeConfigAll[NET_MAX_COMBINE_NUM];
}SDK_CombineEncodeConfigAll;

/// 组合编码模式
typedef struct SDK_CombEncodeParam
{
	int iEncodeMode;	 //见CombineEncodeMode
}SDK_CombEncodeParam;

typedef struct SDK_CombEncodeModeAll
{
	SDK_CombEncodeParam vEncodeParam[NET_MAX_COMBINE_NUM];
}SDK_CombEncodeModeAll;

//!视频物件结构
typedef struct  SDK_VIDEO_WIDGET
{
	unsigned int rgbaFrontground;	///< 物件的前景MakeRGB，和透明度	
	unsigned int rgbaBackground;	///< 物件的后景MakeRGB，和透明度	
	sdkRect	rcRelativePos;			///< 物件边距与整长的比例*8191
	bool	bPreviewBlend;			///< 预览叠加,是否显示，1：显示 0：隐藏
	bool	bEncodeBlend;			///< 编码叠加
}SDK_VIDEO_WIDGET;

//!视频物件设置
typedef struct SDK_CONFIG_VIDEOWIDGET
{
	SDK_VIDEO_WIDGET	dstCovers[NET_COVERNUM];
	SDK_VIDEO_WIDGET	ChannelTitle; //通道名称
	SDK_VIDEO_WIDGET	TimeTitle;	  //设备时间
	struct 
	{
		char strName[NET_NAME_PASSWORD_LEN];
		long long iSerialNo;	
	}ChannelName;			///< 通道名称
	int		iCoverNum;		///< 当前该通道有几个叠加的区域 */
}SDK_CONFIG_VIDEOWIDGET;

/// 视频物件(输出模式对话框)
typedef struct SDK_VideoWidgetConfigAll
{
	SDK_CONFIG_VIDEOWIDGET vVideoWidegetConfigAll[NET_MAX_CHANNUM];
}SDK_VideoWidgetConfigAll;

//视频颜色
typedef struct SDK_VIDEOCOLOR_PARAM
{
	int	nBrightness;		///< 亮度	0-100
	int	nContrast;			///< 对比度	0-100
	int	nSaturation;		///< 饱和度	0-100
	int	nHue;				///< 色度	0-100
	int	mGain;				///< 增益	0-100 第７位置1表示自动增益		
	int	mWhitebalance;		///< 自动白电平控制，bit7置位表示开启自动控制.0x0,0x1,0x2分别代表低,中,高等级
	int nAcutance;          ///< 锐度   0-15
}SDK_VIDEOCOLOR_PARAM;
///< 视频颜色设置
typedef struct SDK_VIDEOCOLOR
{
	SDK_TIMESECTION			tsTimeSection;		/// 时间段
	SDK_VIDEOCOLOR_PARAM	dstColor;			/// 颜色定义
	int					iEnable;
}SDK_VIDEOCOLOR;

typedef struct SDK_CONFIG_VIDEOCOLOR
{
	SDK_VIDEOCOLOR dstVideoColor[NET_N_MIN_TSECT];
}SDK_CONFIG_VIDEOCOLOR;

typedef struct SDK_VideoColorConfigAll
{
	SDK_CONFIG_VIDEOCOLOR vVideoColorAll[NET_MAX_CHANNUM];
}SDK_VideoColorConfigAll;


/// 所有通道名称标题
typedef struct SDK_ChannelNameConfigAll
{
	char channelTitle[NET_MAX_CHANNUM][NET_NAME_PASSWORD_LEN];
}SDK_ChannelNameConfigAll;

//输出模式
typedef struct SDK_GUISetConfig
{
	int iWindowAlpha;			///< 窗口透明度	[128, 255]
	bool bTimeTitleEn;			///< 时间标题显示使能
	bool bChannelTitleEn;		///< 通道标题显示使能	
	bool bAlarmStatus;			///< 报警状态
	bool bRecordStatus;			///< 录像状态显示使能
	bool bChanStateRecEn;		///< 录像标志显示使能
	bool bChanStateVlsEn;		///< 视频丢失标志显示使能
	bool bChanStateLckEn;		///< 通道锁定标志显示使能	
	bool bChanStateMtdEn;		///< 动态检测标志显示使能
	bool bBitRateEn;			///< 码流显示使能
	bool bRemoteEnable;			///< 遥控器使能
	bool bDeflick;				///< 抗抖动
}SDK_GUISetConfig;


////!普通网络设置
typedef struct SDK_CONFIG_NET_COMMON
{
	//!主机名
	char HostName[NET_NAME_PASSWORD_LEN];
	//!主机IP
	CONFIG_IPAddress HostIP;
	//!子网掩码
	CONFIG_IPAddress Submask;
	//!网关IP
	CONFIG_IPAddress Gateway;
	//!HTTP服务端口
	int HttpPort;
	//!TCP侦听端口
	int TCPPort;	
	//!SSL侦听端口
	int SSLPort;
	//!UDP侦听端口
	int UDPPort;
	//!最大连接数
	int MaxConn;
	//!监视协议 {"TCP","UDP","MCAST",…}
	int MonMode;
	//!限定码流值
	int MaxBps;
	//!传输策略
	//char TransferPlan[NET_NAME_PASSWORD_LEN];
	int TransferPlan;

	//!是否启用高速录像下载测率
	bool bUseHSDownLoad;

	//!MAC地址
	char sMac[NET_MAX_MAC_LEN];
}SDK_CONFIG_NET_COMMON;

 typedef enum SDK_DevType
 {
 	SDK_DEV_TYPE_IPC,
 	SDK_DEV_TYPE_DVR,
	SDK_DEV_TYPE_HVR,
	SDK_DEV_TYPE_POEIPC,
	SDK_DEV_TYPE_NVR,
	SDK_DEV_TYPE_RTSPIPC,
 	SDK_DEV_TYPE_NR
 }SDK_DevType;


////!普通网络设置 --
typedef struct SDK_CONFIG_NET_COMMON_V2
{
	//!主机名
	char HostName[NET_NAME_PASSWORD_LEN];
	//!主机IP
	CONFIG_IPAddress HostIP;
	//!子网掩码
	CONFIG_IPAddress Submask;
	//!网关IP
	CONFIG_IPAddress Gateway;
	char pLocalLinkAddr[32];	//本地链路地址
	char pAddr[64];				//ipv6地址
	char pGateway[64];
	//!HTTP服务端口
	int HttpPort;
	//!TCP侦听端口
	int TCPPort;	
	//!SSL侦听端口
	int SSLPort;
	//!UDP侦听端口
	int UDPPort;
	//!最大连接数
	int MaxConn;
	//!监视协议 {"TCP","UDP","MCAST",…}
	int MonMode;
	//!限定码流值
	int MaxBps;
	//!传输策略
	//char TransferPlan[NET_NAME_PASSWORD_LEN];
	int  TransferPlan;						///传输策略
	bool bUseHSDownLoad;					///是否启用高速录像下载测率
	char sMac[NET_MAX_MAC_LEN];				///MAC地址
	char sSn[NET_MAX_MAC_LEN]; 				///序列号(大华和中维设备搜索中用到，用来保存修改IP所需数据)
	int  DeviceType;   						///设备类型,手机区分是插座还是普通设备
	int ChannelNum;			///通道数
	int	Device_Type;		///设备类型，见enum SDK_DevType
	char OtherFunction[49]; ///用来保存修改其它厂家IP所需信息 
	char Manufacturer;  ///设备生产商，见枚举SDK_Manufacturer
	char Resume[6];			///保留

}SDK_CONFIG_NET_COMMON_V2;

////!跨网段设置IP需 --
typedef struct SDK_CONFIG_NET_COMMON_V3
{
    char HostName[NET_NAME_PASSWORD_LEN];	///主机名 
    CONFIG_IPAddress HostIP;				///主机IP
    CONFIG_IPAddress Submask;				///子网掩码
    CONFIG_IPAddress Gateway;				///网关IP  
    int  HttpPort;							///HTTP服务端口   
    int  TCPPort;							///TCP侦听端口   
    int  SSLPort;							///SSL侦听端口
    int  UDPPort;							///UDP侦听端口  
    int  MaxConn;							///最大连接数
    int  MonMode;							///监视协议 {"TCP","UDP","MCAST",?}
    int  MaxBps;								///限定码流值
    //char TransferPlan[NET_NAME_PASSWORD_LEN];
    int  TransferPlan;						///传输策略
    bool bUseHSDownLoad; 					///是否启用高速录像下载测率
    char sMac[NET_MAX_MAC_LEN];				///MAC地址
    char UserName[NET_NAME_PASSWORD_LEN];	///设备用户名
    char Password[NET_NAME_PASSWORD_LEN];	///设备密码
    char LocalMac[NET_MAX_MAC_LEN];
    int  nPasswordType;
	char Resume[92];						///保留
}SDK_CONFIG_NET_COMMON_V3;

//DHCP
#define SDK_MAX_ETH_NUM 4
typedef struct SDK_NetDHCPConfig
{
    bool bEnable;
    char ifName[32];
}SDK_NetDHCPConfig;
/// 所有网卡的DHCP配置
typedef struct SDK_NetDHCPConfigAll
{
    SDK_NetDHCPConfig vNetDHCPConfig[SDK_MAX_ETH_NUM];
}SDK_NetDHCPConfigAll;

///< DNS设置
typedef struct SDK_NetDNSConfig
{
    CONFIG_IPAddress		PrimaryDNS;
    CONFIG_IPAddress		SecondaryDNS;
}SDK_NetDNSConfig;
///< 服务器结构定义
typedef struct SDK_RemoteServerConfig
{
    char ServerName[NET_NAME_PASSWORD_LEN];		///< 服务名
    CONFIG_IPAddress ip;						///< IP地址
    int Port;									///< 端口号
    char UserName[NET_NAME_PASSWORD_LEN];		///< 用户名
    char Password[NET_NAME_PASSWORD_LEN];		///< 密码
    bool Anonymity;								///< 是否匿名登录
}SDK_RemoteServerConfig;
///< IP权限设置
typedef struct SDK_NetIPFilterConfig
{
    bool Enable;											///< 是否开启
    CONFIG_IPAddress BannedList[NET_MAX_FILTERIP_NUM];		///< 黑名单列表
    CONFIG_IPAddress TrustList[NET_MAX_FILTERIP_NUM];		///< 白名单列表
}SDK_NetIPFilterConfig;

///< 组播设置
typedef struct SDK_NetMultiCastConfig
{
    bool Enable;						///< 是否开启
    SDK_RemoteServerConfig Server;		///< 组播服务器
}SDK_NetMultiCastConfig;

///< pppoe设置
typedef struct SDK_NetPPPoEConfig
{
    bool Enable;						///< 是否开启
    SDK_RemoteServerConfig Server;		///< PPPOE服务器
    CONFIG_IPAddress addr;				///< 拨号后获得的IP地址
}SDK_NetPPPoEConfig;

///< DDNS设置
typedef struct SDK_NetDDNSConfig
{
    bool Enable;							///< 是否开启
    bool Online;							///< 是否在线
    char DDNSKey[NET_NAME_PASSWORD_LEN];	///< DDNS类型名称, 目前有: JUFENG
    char HostName[NET_NAME_PASSWORD_LEN];	///< 主机名
    SDK_RemoteServerConfig Server;			///< DDNS服务器
    
}SDK_NetDDNSConfig;

///< DDNS设置
typedef struct SDK_NetDDNSConfigALL
{
    SDK_NetDDNSConfig ddnsConfig[NET_MAX_DDNS_TYPE];
}SDK_NetDDNSConfigALL;

///< FTP设置
typedef struct SDK_FtpServerConfig{
    bool bEnable;        					///< 服务器使能
    SDK_RemoteServerConfig Server;			///< FTP服务器
    char cRemoteDir[NET_MAX_PATH_LENGTH];	///< 远程目录
    int  iMaxFileLen;						///< 文件最大长度
}SDK_FtpServerConfig;

///< NTP设置
typedef struct SDK_NetNTPConfig
{
    ///< 是否开启
    bool Enable;
    ///< PPPOE服务器
    SDK_RemoteServerConfig Server;
    ///< 更新周期
    int  UpdatePeriod;
    ///< 时区
    int  TimeZone;
}SDK_NetNTPConfig;
#define  NET_MAX_EMAIL_TITLE_LEN 64
#define  NET_MAX_EMAIL_RECIEVERS  5
#define  NET_EMAIL_ADDR_LEN  64

///< EMAIL设置
typedef struct SDK_NetEmailConfig
{
    ///< 是否开启
    bool Enable;
    ///< smtp 服务器地址使用字符串形式填充
    ///< 可以填ip,也可以填域名
    SDK_RemoteServerConfig Server;
    bool bUseSSL;
    ///< 发送地址
    char SendAddr[NET_EMAIL_ADDR_LEN];
    ///< 接收人地址
    char Recievers[NET_MAX_EMAIL_RECIEVERS][NET_EMAIL_ADDR_LEN];
    ///< 邮件主题
    char Title[NET_MAX_EMAIL_TITLE_LEN];
    ///< email有效时间
    SDK_TIMESECTION Schedule[NET_N_MIN_TSECT];
}SDK_NetEmailConfig;

///< 解码器地址设置
typedef struct SDK_NetDecoderConfig
{
    bool Enable;							///< 是否开启
    char UserName[NET_NAME_PASSWORD_LEN];	///< DDNS类型名称, 目前有: JUFENG
    char PassWord[NET_NAME_PASSWORD_LEN];	///< 主机名
    char Address[NET_NAME_PASSWORD_LEN];
    int  Protocol;
    int  Port;								///< 解码器连接端口
    int  Channel;							///< 解码器连接通道号
    int  Interval;                       	///< 轮巡的间隔时间(s)
}SDK_NetDecoderConfig;

/// 所有通道的解码器地址设置
typedef struct SDK_NetDecoderConfigAll
{
    SDK_NetDecoderConfig vNetDecoderConfig[NET_MAX_DECORDR_CH];
}SDK_NetDecoderConfigAll;


/// 解码器地址设置V2版本
typedef struct SDK_NetDecoderConfig_V2
{
    int nTotalNum;            //有效的数组个数，最大为NET_MAX_CHANNUM
    SDK_NetDecoderConfig vNetDecoderConfig[NET_MAX_CHANNUM];
}SDK_NetDecoderConfig_V2;

/// 所有通道的解码器地址设置V2版本
typedef struct SDK_NetDecoderConfigAll_V2
{
    SDK_NetDecoderConfig_V2 vNetDecoderArray[NET_MAX_DECORDR_CH];
}SDK_NetDecoderConfigAll_V2;


/// 捕获通道类型
enum SDK_CaptureChannelTypes 
{
	SDK_CAPTURE_CHN_MAIN = 0,		///< 主通道	－	主码流1 
	SDK_CAPTURE_CHN_2END = 1,		///< 辅通道	－	出辅码流2 
	SDK_CAPTURE_CHN_3IRD = 2,		///< 辅通道	－	出辅码流3 
	SDK_CAPTURE_CHN_4RTH = 3,		///< 辅通道	－	出辅码流4 
	SDK_CAPTURE_CHN_JPEG = 4,		///< 辅通道	－	出JPEG抓图 
	SDK_CAPTURE_CHN_NR,
};

///< 解码器地址设置
typedef struct SDK_NetDecorderConfigV3
{
    bool Enable;							///< 是否开启
    char UserName[NET_NAME_PASSWORD_LEN];	///< DDNS类型名称, 目前有: JUFENG
    char PassWord[NET_NAME_PASSWORD_LEN];	///< 主机名
    char Address[NET_NAME_URL_LEN];
    int  Protocol;							///见enum SDK_TransferProtocol_V2
    int  Port;								///< 解码器连接端口
    int  Channel;							///< 解码器连接通道号
    int  Interval;                       	///< 轮巡的间隔时间(s),0:表示永久
    char ConfName[NET_NAME_PASSWORD_LEN];	///<配置名称
    int  DevType;							///<设备类型
    int  StreamType;						///<连接的码流类型 见enum SDK_CaptureChannelTypes
	char MainRtspUrl[NET_NAME_URL_LEN];		///<rtsp协议时表示前端设备的主码流地址
	char SubRtspUrl[NET_NAME_URL_LEN];		///<rtsp协议时表示前端设备的辅码流地址
}SDK_NetDecorderConfigV3;

/*解码器连接类型*/
enum SDK_DecorderConnType
{
    SDK_CONN_SINGLE = 0, 	/*单连接*/
    SDK_CONN_MULTI = 1,		/*多连接轮巡*/
    SDK_CONN_TYPE_NR,
};

/*数字通道的配置*/
typedef struct SDK_NetDigitChnConfig
{
    bool Enable;									/*数字通道是否开启*/
    int  ConnType;									/*连接类型，取DecoderConnectType的值*/
    int  TourIntv;									/*多连接时轮巡间隔*/
    unsigned int SingleConnId;						/*单连接时的连接配置ID, 从1开始，0表示无效*/
    bool EnCheckTime;								/*开启对时*/
    SDK_NetDecorderConfigV3 NetDecorderConf[32]; 	/*网络设备通道配置表*/
    int  nNetDeorde; 								/* 有多少个 */
	bool EnSynchResolution;							//同步分辨率使能开关,0表示打开，1表示关闭
}SDK_NetDigitChnConfig;

/*所有数字通道的配置*/
typedef struct SDK_NetDecorderConfigAll_V3
{
    SDK_NetDigitChnConfig DigitChnConf[NET_MAX_DECORDR_CH];
}SDK_NetDecorderConfigAll_V3;

typedef struct SDK_HVR_CHNCAP
{
    int nD1Chn;					// 支持的D1路数
    int n960HChn;				// 支持的960H路数
    int n720PChn;				// 支持的720P路数
    int n1080PChn;				// 支持的1080P路数
    int nCIFChn;				//支持的CIF通道数
    int nHD1Chn;				//支持的HD1通道数
    unsigned char nPlayChn; 	//支持回放路数
    unsigned char nDigiTalChn; 	//支持最大数字通道路数
    unsigned char n960PChn; 	//支持的960P通道数
    unsigned char n3MChn; 		//支持的3M通道数
    unsigned char n5MChn; 		//支持的5M通道数
    unsigned char nWUXGAChn; 	//支持的WUXGA通道数
    unsigned char n1080NChn;	//支持1080N通道数
    unsigned char n4MChn;		//支持4M通道数
    //unsigned char nResChar[2]; //冗余
}SDK_HVR_CHNCAP, *SDK_PHVR_CHNCAP;

typedef struct SDK_HVR_CHNCAPV2
{
    unsigned char nD1Chn;		// 支持的D1路数
    unsigned char n960HChn;		// 支持的960H路数
    unsigned char n720PChn;		// 支持的720P路数
    unsigned char n1080PChn;	// 支持的1080P路数
    unsigned char nCIFChn;		//支持的CIF通道数
    unsigned char nHD1Chn;		//支持的HD1通道数
    unsigned char nPlayChn; 	//支持回放路数
    unsigned char nDigiTalChn; 	//支持最大数字通道路数
    unsigned char n960PChn; 	//支持的960P通道数
    unsigned char n3MChn; 		//支持的3M通道数
    unsigned char n5MChn; 		//支持的5M通道数
    unsigned char nWUXGAChn; 	//支持的WUXGA通道数
    unsigned char n1080NChn;	//支持1080N通道数
    unsigned char n4MChn;		//支持4M通道数
    unsigned char n720NChn;		//支持720N通道数
	unsigned char nWSVGAChn;	//支持WSVGA(1024*576)通道数
	unsigned char n4KChn;		//支持的4K通道数
	unsigned char n3M_NChn;		//支持的3M_N通道数
	unsigned char n4M_NChn;		//支持的4M_N通道数
	unsigned char n5M_NChn;		//支持的5M_N通道数
	unsigned char n4K_NChn;		//支持的4K_N通道数
	unsigned char nRes[11];
}SDK_HVR_CHNCAPV2, *SDK_PHVR_CHNCAPV2;

typedef struct SDK_CAPTURE_HVRCAP  	//改用CAPTURE_HVRCAPV2，为了兼容老的保留
{
    SDK_HVR_CHNCAP DigitalCap;		// 支持的数字通道信息
    SDK_HVR_CHNCAP AnalogCap;		// 支持的模拟通道信息
}SDK_CAPTURE_HVRCAP, *SDK_PCAPTURE_HVRCAP;

typedef struct SDK_CAPTURE_HVRCAPV2
{
    SDK_HVR_CHNCAPV2 DigitalCap;	// 支持的数字通道信息
    SDK_HVR_CHNCAPV2 AnalogCap;		// 支持的模拟通道信息
}SDK_CAPTURE_HVRCAPV2, *SDK_PCAPTURE_HVRCAPV2;

typedef struct SDK_CAPTURE_TOTAL_HVRCAP //改用CAPTURE_TOTAL_HVRCAPV2，为了兼容老的保留
{
    int		nHVRCap;									// 实际支持的模式
    SDK_CAPTURE_HVRCAP	HVRCap[MAX_HVR_CHNCAP_CHN];		// 所有模式的汇总
}SDK_CAPTURE_TOTAL_HVRCAP, *SDK_PCAPTURE_TOTAL_HVRCAP;

typedef struct SDK_CAPTURE_TOTAL_HVRCAPV2
{
    int		nHVRCap;									// 实际支持的模式
    SDK_CAPTURE_HVRCAPV2	HVRCap[MAX_HVR_CHNCAP_CHN];	// 所有模式的汇总
}SDK_CAPTURE_TOTAL_HVRCAPV2, *SDK_PCAPTURE_TOTAL_HVRCAPV2;

//通道模式配置
typedef struct SDK_NetDecorderChnModeConfig
{
    SDK_CAPTURE_TOTAL_HVRCAPV2 	HVRTotalCap;
    int HVRCurCapMode;
}SDK_NetDecorderChnModeConfig;


/*数字通道状态*/
typedef struct SDK_NetDecorderChnStatus
{
    char ChnName[NET_NAME_PASSWORD_LEN];
    char pMaxResName[50];
    char pCurResName[50];
    char pStatus[50];
}SDK_NetDecorderChnStatus;

/*所有数字通道状态*/
typedef struct SDK_NetDecorderChnStatusAll
{
    SDK_NetDecorderChnStatus ChnStatusAll[NET_MAX_DECORDR_CH];
}SDK_NetDecorderChnStatusAll;

//文字编码格式
enum SDK_WordEncode
{
    SDK_WORD_ENCODE_GB2312,  //汉字编码GB2312
    SDK_WORD_ENCODE_UNICODE, //万国码 Unicode
    SDK_WORD_ENCODE_UTF8,    //UTF-8
};

#define SDK_MAX_POS_FUNC_KEYWORDS 4

//RTSP
typedef struct SDK_NetRTSPConfig
{
    bool bServer;
    bool bClient;
    SDK_RemoteServerConfig Server;		///< 服务器模式
    SDK_RemoteServerConfig Client;		///< 客户端模式
}SDK_NetRTSPConfig;

///< UPNP设置
typedef struct SDK_NetUPNPConfig
{
    bool bEnable;				///< 使能标志
    bool bState;				///< 状态, 1: OK 0: NOK
    int  iHTTPPort;				///< HTTP连接映射后的端口
    int  iMediaPort;			///< 媒体连接映射后的端口
    int  iMobliePort;			///< 手机监控映射后的端口
}SDK_NetUPNPConfig;

///< WIFI设置
typedef struct SDK_NetWifiConfig
{
    bool bEnable;
    char sSSID[36];            	///< SSID Number
    int  nChannel;             	///< channel
    char sNetType[32];         	///< Timer, Adhoc
    char sEncrypType[32];      	///< NONE, WEP, TKIP, AES
    char sAuth[32];            	///< OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
    int  nKeyType;             	///< 0:Hex 1:ASCII
    char sKeys[NET_IW_ENCODING_TOKEN_MAX];
    CONFIG_IPAddress HostIP;	///< host ip
    CONFIG_IPAddress Submask;	///< netmask
    CONFIG_IPAddress Gateway;	///< gateway
}SDK_NetWifiConfig;

enum SDK_RSSI_SINGNAL
{
    SDK_RSSI_NO_SIGNAL,    //<= -90db
    SDK_RSSI_VERY_LOW,     //<= -81db
    SDK_RSSI_LOW,          //<= -71db
    SDK_RSSI_GOOD,         //<= -67db
    SDK_RSSI_VERY_GOOD,    //<= -57db
    SDK_RSSI_EXCELLENT     //<= -57db
};

typedef struct SDK_NetWifiDevice
{
    char sSSID[36];            //SSID Number
    int  nRSSI;                //SEE SDK_RSSI_SINGNAL
    int  nChannel;
    char sNetType[32];         //Timer, Adhoc
    char sEncrypType[32];      //NONE, WEP, TKIP, AES
    char sAuth[32];            //OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
}SDK_NetWifiDevice;

typedef struct SDK_NetWifiDeviceAll
{
    int nDevNumber;
    SDK_NetWifiDevice vNetWifiDeviceAll[NET_MAX_AP_NUMBER];
}SDK_NetWifiDeviceAll;

/// 编码信息
typedef struct SDK_EncodeInfo
{
    bool bEnable;						///< 使能项
    bool bHaveAudio;					///< 是否支持音频
    int  iStreamType;					///< 码流类型，capture_channel_t
    unsigned int uiCompression;			///< capture_comp_t的掩码
    unsigned int uiResolution;			///< SDK_CAPTURE_SIZE_t的掩码
}SDK_EncodeInfo;

/// 编码能力
typedef struct CONFIG_EncodeAbility
{
    unsigned int iMaxEncodePower;							///< 支持的最大编码能力
    int iChannelMaxSetSync;									///< 每个通道分辨率是否需要同步 0-不同步, 1 -同步
    unsigned int nMaxPowerPerChannel[NET_MAX_CHANNUM];		///< 每个通道支持的最高编码能力
    unsigned int ImageSizePerChannel[NET_MAX_CHANNUM];		///< 每个通道支持的图像分辨率
    unsigned int ExImageSizePerChannel[NET_MAX_CHANNUM];	///< 每个通道支持的辅码流图像分辨率
	unsigned int CompressionMask[NET_MAX_CHANNUM];			///< 编码模式capture_comp_t掩码
	unsigned int ThridImageSize[NET_MAX_CHANNUM];			///< CHL_3IRD_T码流支持的图像分辨率
	unsigned int FourthImageSize[NET_MAX_CHANNUM];			///< CHL_4RTH_T码流支持的图像分辨率
    SDK_EncodeInfo vEncodeInfo[SDK_CHL_FUNCTION_NUM];		///< 编码信息,暂时最大就4中码流
    SDK_EncodeInfo vCombEncInfo[SDK_CHL_FUNCTION_NUM];		///< 组合编码信息,暂时最大就4中码流
    int	iMaxBps;											///< 最高码流Kbps
    unsigned int ExImageSizePerChannelEx[NET_MAX_CHANNUM][SDK_CAPTURE_SIZE_EXT_V3_NR];	///< 每个通道支持的辅码流图像分辨率
}CONFIG_EncodeAbility;

// 串口协议
enum SDK_CommProtocol
{
    SDK_CONSOLE = 0,
    SDK_KEYBOARD,
    SDK_COM_TYPES,
};
/// 串口协议
typedef struct SDK_COMMFUNC
{
    //每个协议最多由32个字符组成
    int nProNum;
    char vCommProtocol[100][32];
}SDK_COMMFUNC;

/// 云台协议
typedef struct SDK_PTZPROTOCOLFUNC
{
    //每个协议最多由32个字符组成
    int nProNum;
    char vPTZProtocol[100][NET_MAX_PTZ_PROTOCOL_LENGTH];
}SDK_PTZPROTOCOLFUNC;

/// 区域遮挡能力集
typedef struct SDK_BlindDetectFunction
{
    int iBlindConverNum;	///< 区域遮挡块数
}SDK_BlindDetectFunction;

/// 动检区域能力集
typedef struct SDK_MotionDetectFunction
{
    int iGridRow;
    int iGridColumn;
}SDK_MotionDetectFunction;

/// 支持的DDNS类型
typedef struct SDK_DDNSServiceFunction
{
    int  nTypeNum;
    char vDDNSType[NET_MAX_DDNS_TYPE][64];
}SDK_DDNSServiceFunction;

/// 支持语言
typedef struct SDK_MultiLangFunction
{
    //每个协议最多由64个字符组成
    int nLangNum;
    char vLanguageName[128][64];
}SDK_MultiLangFunction;

/// 支持的视频制式
typedef struct SDK_MultiVstd
{
    //每个协议最多由3个字符组成
    int nVstdNum;
    char vVstdName[3][64];
}SDK_MultiVstd;

/// 编码功能
enum SDK_EncodeFunctionTypes
{
    SDK_ENCODE_FUNCTION_TYPE_DOUBLE_STREAM,		///< 双码流功能
    SDK_ENCODE_FUNCTION_TYPE_COMBINE_STREAM,	///< 组合编码功能
    SDK_ENCODE_FUNCTION_TYPE_SNAP_STREAM,		///< 抓图功能
    SDK_ENCODE_FUNCTION_TYPE_WATER_MARK,		///< 水印功能
    SDK_ENCODE_FUNCTION_TYPE_IFRAME_RANGE,		///< I帧间隔
    SDK_ENCODE_FUNCTION_TYPE_LOW_BITRATE,   	///< 低码流
	SDK_ENCODE_FUNCTION_TYPE_SmartH264,			///< H264+
	SDK_ENCODE_FUNCTION_TYPE_INTELLIGENT_ENCODE,///< 智能编码
    SDK_ENCODE_FUNCTION_TYPE_NR,
};

/// 报警功能
enum SDK_AlarmFucntionTypes
{
    SDK_ALARM_FUNCTION_TYPE_MOTION_DETECT,		///< 动态检测
    SDK_ALARM_FUNCTION_TYPE_BLIND_DETECT,		///< 视屏遮挡
    SDK_ALARM_FUNCTION_TYPE_LOSS_DETECT,		///< 视屏丢失
    SDK_ALARM_FUNCTION_TYPE_LOCAL_ALARM,		///< 本地报警
    SDK_ALARM_FUNCTION_TYPE_NET_ALARM,			///< 网络报警
    SDK_ALARM_FUNCTION_TYPE_IP_CONFLICT,		///< IP地址冲突
    SDK_ALARM_FUNCTION_TYPE_NET_ABORT,			///< 网络异常
    SDK_ALARM_FUNCTION_TYPE_STORAGE_NOTEXIST,	///< 存储设备不存在
    SDK_ALARM_FUNCTION_TYPE_STORAGE_LOWSPACE,	///< 存储设备容量不足
    SDK_ALARM_FUNCTION_TYPE_STORAGE_FAILURE,	///< 存储设备访问失败
    SDK_ALARM_FUNCTION_TYPE_VIDEOANALYSE,		///< 视频分析
    SDK_ALARM_FUNCTION_TYPE_NET_ABORT_EXTEND,	///< 网络异常扩展
    SDK_ALARM_FUNCTION_TYPE_IPC_ALARM,			///< IPC报警
    SDK_ALARM_FUNCTION_TYPE_NR
};

/// 网络服务功能
enum SDK_NetServerTypes
{
    SDK_NET_SERVER_TYPES_IPFILTER,			///< 白黑名单
    SDK_NET_SERVER_TYPES_DHCP,				///< DHCP功能
    SDK_NET_SERVER_TYPES_DDNS,				///< DDNS功能
    SDK_NET_SERVER_TYPES_EMAIL,				///< Email功能
    SDK_NET_SERVER_TYPES_MULTICAST,			///< 多播功能
    SDK_NET_SERVER_TYPES_NTP,				///< NTP功能
    SDK_NET_SERVER_TYPES_PPPOE,
    SDK_NET_SERVER_TYPES_DNS,
    SDK_NET_SERVER_TYPES_3G = 9,            	///< 3G拨号
    SDK_NET_SERVER_TYPES_MOBILE=10,     	///< 手机监控
    SDK_NET_SERVER_TYPES_UPNP,				///< UPNP
    SDK_NET_SERVER_TYPES_FTP,				///< FTP
    SDK_NET_SERVER_TYPES_WIFI,          	///< WIFI
    SDK_NET_SERVER_TYPES_RTSP = 19,     			///< RTSP
    SDK_NET_SERVER_TYPES_PHONEMSG=20,     	///< 手机信息发送配置
    SDK_NET_SERVER_TYPES_PHONEMULTIMEDIAMSG,///< 手机信息发送配置
    SDK_NET_SERVER_TYPES_DAS = 22,          		///< 主动注册
    SDK_NET_SERVER_TYPES_LOCALSDK_PLATFORM, ///< 网络平台信息设置
    SDK_NET_SERVER_TYPES_NET_KEYBOARD,		///< 网络键盘配置
    SDK_NET_SERVER_TYPES_SPVMN = 28,				///< 28181协议配置
    SDK_NET_SERVER_TYPE_PROTOCOL_MAC = 31,		///< 支持MAC协议
    SDK_NET_SERVER_TYPE_XMHEARTBEAT, 		///< 心跳
    SDK_NET_SERVER_TYPES_DATALINK,			///< DataLink客户网络服务中执行程序使能配置
    SDK_NET_SERVER_TYPES_WIFI_MODE = 44,			///< 是否支持wifi模式相关配置
	SDK_NET_SERVER_TYPES_IPV6,				///< 支持ipv6
	SDK_NET_SERVER_TYPES_SPVMN_SIP = 48,			///< 28181配置显示SIP 板卡地址
	SDK_NET_SERVER_TYPES_RTMP,				///< RTMP协议
	SDK_NET_SERVER_TYPES_IPADAPTIVE,		///< IP自适应网络能力
	SDK_NET_SERVER_TYPES_ONVIF_PWD_CHECKOUT,///< ONVIF密码校验
    SDK_NET_SERVER_TYPES_NR,
};

/// 预览功能
enum SDK_PreviewTypes
{
    SDK_PREVIEW_TYPES_TOUR,		///< 轮巡
    SDK_PREVIEW_TYPES_TALK,		///< GUI界面配置
    SDK_PREVIEW_TYPES_NR
};

///串口类型
enum SDK_CommTypes
{
    SDK_COMM_TYPES_RS485,		///<485串口
    SDK_COMM_TYPES_RS232,		///<232串口
    SDK_COMM_TYPES_NR
};

//输入法限制
enum SDK_InPutMethod
{
    SDK_NO_SUPPORT_CHINESE,		//不支持中文输入
    SDK_NO_SUPPORT_NR
};

//报警中标签显示
enum SDK_TipShow
{
    SDK_NO_BEEP_TIP_SHOW,  		//蜂鸣提示
    SDK_NO_FTP_TIP_SHOW,  		//FTP提示
    SDK_NO_EMAIL_TIP_SHOW,  	//EMAIL提示
	SDK_NO_DISK_MANAGER_SHOW, //不显示硬盘管理页面的分区和类型修改等按钮
    SDK_NO_TIP_SHOW_NR
};

///车载功能
enum SDK_MobileCar
{
    SDK_MOBILEDVR_STATUS_EXCHANGE,			//车辆状态
    SDK_MOBILEDVR_DELAY_SET,	  			//延时设置
    SDK_MOBILEDVR_CARPLATE_SET,
    SDK_MOBILEDVR_GPS_TIMING,	  			//GPS校时
    SDK_MOBILEDVR_DVR_BOOT_TYPE_SET,
    SDK_MOBILEDVR_NR
};

///其他功能
enum SDK_OtherFunction
{
    SDK_OTHER_DOWNLOADPAUSE,				//录像下载暂停功能
    SDK_OTHER_USB_SUPPORT_RECORD,			//USB支持录像功能
    SDK_OTHER_SD_SUPPORT_RECORD,			//SD支持录像功能
    SDK_OTHER_ONVIF_CLIENT_SUPPORT,			//是否支持ONVIF客户端
    SDK_OTHER_NET_LOCALSEARCH_SUPPORT,		//是否支持远程搜索
    SDK_OTHER_MAXPLAYBACK_SUPPORT, 			//是否支持最大回放通道数显示
    SDK_OTHER_NVR_SUPPORT = 6, 					//是否是专业NVR
    SDK_OTHER_SHOW_OSD_INFO = 9,            	//支持显示3行OSD信息
    SDK_OTHER_HIDE_DIGITAL, 				//通道模式屏蔽功能
    SDK_OTHER_ACUTANCE_HORIZONTAL,			//锐度
    SDK_OTHER_ACUTANCE_VERTIAL,
    SDK_OTHER_BROAD_TRENDS,					//宽动态功能
    SDK_OTHER_NO_TALK,						//对讲能力
    SDK_OTHER_ALTER_DIGITAL_NAME,			//修改数字通道名称
    SDK_OTHER_SHOW_CONNECT_STATUS,      	//支持显示wifi 3G 主动注册等的连接状态
    SDK_OTHER_SUPPORT_ECACT_SEEK,			//支持回放精准定位
    SDK_OTHER_UPLOAD_TITLEANDSTATE,			//通道标题和数字通道状态上传能力集
    SDK_OTHER_NO_HDD_RECORD,				//无硬盘录像
    SDK_OTHER_MUSICFILE_PLAY,				//播放音频文件
    SDK_OTHER_SUPPORT_SET_DIG_IP,			//设置前端ip能力
    SDK_OTHER_VERSION_PRODUCT_TYPE,			//支持在版本信息里显示设备型号
    SDK_OTHER_SUPPORT_CAMERA_IMG_STYLE,		//支持摄像机图像风格
    SDK_OTHER_SUPPORT_TITLE_ABILITY,		//支持修改onvif标题
    SDK_OTHER_SUPPORT_DIMEN_CODE,			//支持二维码
	SDK_OTHER_STORAGE_NAS_SUPPORT,			//是否支持NAS存储功能
    SDK_OTHER_SHOWFALSE_CHECKTIME,			//屏蔽解码器时间同步功能
    SDK_OTHER_SUPPORT_TIME_ZONE, 			//时区配置
    SDK_OTHER_SHOW_ALARM_LEVEL_REGION,		//显示数字通道报警功能的灵敏度和区域设置
    SDK_OTHER_SUPPORT_POS,					//支持POS
    SDK_OTHER_HDD_LOWSPACE_USE_MB,			//硬盘空间不足报警下限用MB
    SDK_OTHER_SUPPORT_CUSTOMIZE_OEMINFO,	//定制OEM客户版本信息
    SDK_OTHER_DIGITAL_ENCODE,				//数字通道编码配置
    SDK_OTHER_RESUME_PTZ_STATE,				//开机恢复云台状态
    SDK_OTHER_SUPPORT_SNAP_CFG,				//支持抓图配置
    SDK_OTHER_ABNORMITY_SEND_EMAIL,			//存储设备存在及存储异常及存储空间不足发邮件
    SDK_OTHER_SUPPORT_DIGITAL_PRE,			//支持数字通道预录
    SDK_OTHER_SUPPORT_WRITE_LOG, 			//报警页面添加是否写日志勾选框
    SDK_OTHER_SUPPORT_CHANGE_ONVIF_PORT,	//支持修改onvif端口
    SDK_OTHER_SUPPORT_COMM_DATA_UPLOAD,  	//支持串口数据上传到指定服务器
    SDK_OTHER_SUPPORT_TEXT_PASSWORD = 41,		//记录明文密码
    SDK_OTHER_SUPPORT_MODIFY_FRONT_CFG = 44,		//支持修改前端配置
	SDK_OTHER_SUPPORT_SPLIT_CONTROL = 55,		//支持CMS客户端画面分割
	SDK_OTHER_RTSP_CLIENT_SUPPORT,			//数字通道是否支持通过RTSP连接前端设备
	SDK_OTHER_LOW_LUX_MODE,					//微光模式
	SDK_OTHER_SUPPORT_Switch_Resolution,	//修改前端数字通道分辨率
	SDK_OTHER_LOW_MOTION,					//运动相机慢动作
	SDK_OTHER_SUPPORT_CORRIDOR_MODE,        //支持走廊模式
	SDK_OTHER_WIFINVR_SUPPORT,				//是否是WIFINVR
	SDK_OTHER_SUPPORT_SNAP_SCHEDULE,		//是否支持定时抓图
	SDK_OTHER_SUPPORT_BREVIARY,				//是否支持缩略图
	SDK_OTHER_SUPPORT_INTELLIGENT_PLAYBACK =66, //是否支持智能快放
	SDK_OTHER_SUPPORT_DEVICE_INFO = 68,			//是否支持新设备信息
	SDK_OTHER_SUPPORT_BALL_CAMERA_TRACK_DETECT,//支持球机跟踪识别
	SDK_OTHER_SPECIAL_NIGHT_CONTROAL,		//夜晚特殊情景控制
	SDK_OTHER_SUPPORT_SET_HARDWARE_ABILITY,	//支持设置设备硬件能力集
	SDK_OTHER_SUPPORT_SAFETY_EMAIL,			//支持安全邮箱重置密码功能
	SDK_OTHER_NR
};

///支持的系统功能
typedef struct SDK_SystemFunction
{
    bool vEncodeFunction[SDK_ENCODE_FUNCTION_TYPE_NR];	///< 编码功能SDK_EncodeFunctionTypes
    bool vAlarmFunction[SDK_ALARM_FUNCTION_TYPE_NR];	///< 报警功能AlarmFucntionTypes
    bool vNetServerFunction[SDK_NET_SERVER_TYPES_NR];	///< 网络服务功能NetServerTypes
    bool vPreviewFunction[SDK_PREVIEW_TYPES_NR];		///< 预览功能PreviewTypes
    bool vCommFunction[SDK_COMM_TYPES_NR];				///< 串口类型SDK_CommTypes
    bool vInputMethodFunction[SDK_NO_SUPPORT_NR];  		///< 输入法限制SDK_InPutMethod>
    bool vTipShowFunction[SDK_NO_TIP_SHOW_NR];          ///< 报警标签显示SDK_TipShow>
    bool vMobileCarFunction[SDK_MOBILEDVR_NR];			///< 车载功能
    bool vOtherFunction[SDK_OTHER_NR];					///< 其他功能OtherFunction
}SDK_SystemFunction;

typedef struct SDK_COMMATTRI
{
    int	iDataBits;	// 数据位取值为5,6,7,8
    int	iStopBits;	// 停止位
    int	iParity;	// 校验位
    int	iBaudRate;	// 实际波特率
}SDK_COMMATTRI;

// 串口配置
typedef struct SDK_CONFIG_COMM_X
{
    char iProtocolName[32];		// 串口协议:“Console”
    int iPortNo;				// 端口号
    SDK_COMMATTRI aCommAttri;	// 串口属性
}SDK_CONFIG_COMM_X;

typedef struct SDK_CommConfigAll
{
    SDK_CONFIG_COMM_X vCommConfig[SDK_COM_TYPES];
}SDK_CommConfigAll;

// 云台设置
typedef struct SDK_STR_CONFIG_PTZ
{
    char sProtocolName[NET_MAX_PTZ_PROTOCOL_LENGTH];	// 协议名称
    int	ideviceNo;										// 云台设备地址编号
    int	iNumberInMatrixs;								// 在矩阵中的统一编号
    int iPortNo;										// 串口端口号	[1, 4]
    SDK_COMMATTRI dstComm;								// 串口属性
}SDK_STR_CONFIG_PTZ;

//所有通道云台协议
typedef struct SDK_STR_PTZCONFIG_ALL
{
    SDK_STR_CONFIG_PTZ ptzAll[NET_MAX_CHANNUM];
}SDK_STR_PTZCONFIG_ALL;

//RS485
typedef struct SDK_STR_RS485CONFIG_ALL
{
    SDK_STR_CONFIG_PTZ ptzAll[NET_MAX_CHANNUM];
}SDK_STR_RS485CONFIG_ALL;


typedef struct SDK_CONFIG_WORKSHEET
{
    SDK_TIMESECTION	tsSchedule[NET_N_WEEKS][NET_N_TSECT];	/*!< 时间段 */
}SDK_CONFIG_WORKSHEET;

/// 录像模式种类
enum SDK_RecordModeTypes
{
    SDK_RECORD_MODE_CLOSED,		///< 关闭录像
    SDK_RECORD_MODE_MANUAL,		///< 手动录像
    SDK_RECORD_MODE_CONFIG,		///< 按配置录像
    SDK_RECORD_MODE_NR,
};

///< 录像设置
typedef struct SDK_RECORDCONFIG
{
    int iPreRecord;										///< 预录时间，为零时表示关闭
    bool bRedundancy;									///< 冗余开关
    //bool bSnapShot;									///< 快照开关
    int iPacketLength;									///< 录像打包长度（分钟）[1, 255]
    int iRecordMode;									///< 录像模式，0 关闭，1 禁止 2 配置
    SDK_CONFIG_WORKSHEET wcWorkSheet;					///< 录像时间段
    unsigned int typeMask[NET_N_WEEKS][NET_N_TSECT];	///< 录像类型掩码
}SDK_RECORDCONFIG;

//录像设置结构体
typedef struct SDK_RECORDCONFIG_ALL
{
    SDK_RECORDCONFIG vRecordConfigAll[NET_MAX_CHANNUM];
}SDK_RECORDCONFIG_ALL;

///< 图片设置
typedef struct SDK_SnapshotConfig
{
    int iPreSnap;										///< 预抓图片数
    bool bRedundancy;									///< 冗余开关
    int iSnapMode;										///< 录像模式，见RecordModeTypes
    SDK_CONFIG_WORKSHEET wcWorkSheet;					///< 录像时间段
    unsigned int typeMask[NET_N_WEEKS][NET_N_TSECT];	///< 录像类型掩码，见enum RecordTypes
}SDK_SnapshotConfig;

typedef struct SDK_SnapshotConfigAll
{
    SDK_SnapshotConfig vSnapshotConfigAll[NET_MAX_CHANNUM];
}SDK_SnapshotConfigAll;

//  云台联动结构
typedef struct SDK_PtzLinkConfig
{
    int iType;		// 联动的类型--对应结构体PtzLinkTypes
    int iValue;		// 联动的类型对应的值
}SDK_PtzLinkConfig;

#define CHANNELNAME_MAX_LEN 64  //通道名称最大长度

//由于要兼容多通道设备，所以需要修改结构体类型
typedef struct SDK_EventHandler
{
	char	dwRecord[NET_MAX_MSK_SIZE];				// 录象掩码 
    int		iRecordLatch;							// 录像延时：10?300 sec
	char	dwTour[NET_MAX_MSK_SIZE];				// 轮巡掩码 	
	char	dwSnapShot[NET_MAX_MSK_SIZE];			// 抓图掩码 
	char	dwAlarmOut[NET_MAX_MSK_SIZE];			// 报警输出通道掩码 
	char	dwMatrix[NET_MAX_MSK_SIZE];				// 矩阵掩码 
    int		iEventLatch;							// 联动开始延时时间，s为单位
    int		iAOLatch;								// 报警输出延时：10?300 sec
    SDK_PtzLinkConfig PtzLink[NET_MAX_CHANNUM];		// 云台联动项
    SDK_CONFIG_WORKSHEET schedule;					// 录像时间段
    
    bool	bRecordEn;				// 录像使能
    bool	bTourEn;				// 轮巡使能
    bool	bSnapEn;				// 抓图使能
    bool	bAlarmOutEn;			// 报警使能
    bool	bPtzEn;
    
    // 云台联动使能
    bool	bTip;					// 屏幕提示使能
    bool	bMail;					// 发送邮件
    bool	bMessage;				// 发送消息到报警中心
    bool	bBeep;					// 蜂鸣
    bool	bVoice;					// 语音提示
    bool	bFTP;					// 启动FTP传输
    bool	bMatrixEn;				// 矩阵使能
    bool	bLog;					// 日志使能
    bool	bMessagetoNet;			// 消息上传给网络使能
    
    bool    bShowInfo;              // 是否在GUI上和编码里显示报警信息
    char    dwShowInfoMask[NET_MAX_MSK_SIZE];	// 要联动显示报警信息的通道掩码
    char    pAlarmInfo[CHANNELNAME_MAX_LEN];	//要显示的报警信息
    
    bool    bShortMsg;              //发送短信
    bool    bMultimediaMsg;         //发送彩信
}SDK_EventHandler;

///< 动态检测设置
typedef struct SDK_MOTIONCONFIG
{
    bool bEnable;								// 动态检测开启
    int iLevel;									// 灵敏度
    unsigned int mRegion[NET_MD_REGION_ROW];	// 区域，每一行使用一个二进制串
    SDK_EventHandler hEvent;					// 动态检测联动
}SDK_MOTIONCONFIG;

/// 全通道动态检测配置
typedef struct SDK_MOTIONCONFIG_ALL
{
    SDK_MOTIONCONFIG vMotionDetectAll[NET_MAX_CHANNUM];
}SDK_MOTIONCONFIG_ALL;

///< 遮挡检测配置
typedef struct SDK_BLINDDETECTCONFIG
{
    bool	bEnable;			///< 遮挡检测开启
    int		iLevel;				///< 灵敏度：1?6
    SDK_EventHandler hEvent;	///< 遮挡检测联动
}SDK_BLINDDETECTCONFIG;

/// 全通道遮挡检测配置
typedef struct SDK_BLINDDETECTCONFIG_ALL
{
    SDK_BLINDDETECTCONFIG vBlindDetectAll[NET_MAX_CHANNUM];
}SDK_BLINDDETECTCONFIG_ALL;

///< 基本事件结构
typedef struct SDK_VIDEOLOSSCONFIG
{
    bool bEnable;				///< 使能
    SDK_EventHandler hEvent;	///< 处理参数
}SDK_VIDEOLOSSCONFIG;

/// 所有通道的基本时间结构
typedef struct SDK_VIDEOLOSSCONFIG_ALL
{
    SDK_VIDEOLOSSCONFIG vGenericEventConfig[NET_MAX_CHANNUM];
}SDK_VIDEOLOSSCONFIG_ALL;

///< 报警输入配置
typedef struct SDK_ALARM_INPUTCONFIG
{
    bool	bEnable;			///< 报警输入开关
    int		iSensorType;		///< 传感器类型常开 or 常闭
    SDK_EventHandler hEvent;	///< 报警联动
}SDK_ALARM_INPUTCONFIG;

///< 所有通道的报警输入配置
typedef struct SDK_ALARM_INPUTCONFIG_ALL
{
    SDK_ALARM_INPUTCONFIG vAlarmConfigAll[NET_MAX_CHANNUM];
}SDK_ALARM_INPUTCONFIG_ALL;

///< 网路报警
typedef struct SDK_NETALARMCONFIG
{
    bool bEnable;				///< 使能
    SDK_EventHandler hEvent;	///< 处理参数
}SDK_NETALARMCONFIG;

/// 所有通道的网路报警结构
typedef struct SDK_NETALARMCONFIG_ALL
{
    SDK_NETALARMCONFIG vNetAlarmConfig[NET_MAX_CHANNUM];
}SDK_NETALARMCONFIG_ALL;

///< 本地报警输出配置
typedef struct SDK_AlarmOutConfig
{
    int nAlarmOutType;		///< 报警输出类型: 配置,手动,关闭
    int nAlarmOutStatus;    ///< 报警状态: 0:打开 1;闭合
}SDK_AlarmOutConfig;

//< 硬盘容量不足事件剩余容量类型
enum SDK_StorageLowSpaceType
{
    SDK_PERSENT = 0,
    SDK_MB,
    SDK_GB,
};

///< 硬盘容量不足事件结构
typedef struct SDK_StorageLowSpaceConfig
{
    bool bEnable;
    int iLowerLimit;			///< 硬盘剩余容量下限, 百分数
    SDK_EventHandler hEvent;	///< 处理参数
    bool bRecordTimeEnable;
    int iRecordTime;			///<录像天数
    int iLowerLimitSpace;		///< 硬盘剩余容量MB或者GB为单位
    int EnableType;				///< 0为用百分比，1为用MB，见枚举StorageLowSpaceType
}SDK_StorageLowSpaceConfig;

///< 所有通道的报警输出配置
typedef struct SDK_AlarmOutConfigAll
{
    SDK_AlarmOutConfig vAlarmOutConfigAll[NET_MAX_CHANNUM];
}SDK_AlarmOutConfigAll;

/// 所有通道的解码器地址设置V2版本
typedef struct SDK_AbilitySerialNo
{
    char serialNo[NET_MAX_SERIALNO_LENGTH];
    char productType[NET_MAX_SERIALNO_LENGTH];
}SDK_AbilitySerialNo;

///< 驱动器信息结构
typedef struct SDK_DriverInformation
{
    int		iDriverType;				///< 驱动器类型
    bool	bIsCurrent;					///< 是否为当前工作盘
    unsigned int	uiTotalSpace;		///< 总容量，MB为单位
    unsigned int	uiRemainSpace;		///< 剩余容量，MB为单位
    int		iStatus;					///< 错误标志，文件系统初始化时被设置
    int		iLogicSerialNo;				///< 逻辑序号
    SDK_SYSTEM_TIME  tmStartTimeNew;	///< 新录像时间段的开始时间
    SDK_SYSTEM_TIME	 tmEndTimeNew;		///< 新录像时间段的结束时间
    SDK_SYSTEM_TIME	 tmStartTimeOld;	///< 老录像时间段的开始时间
    SDK_SYSTEM_TIME	 tmEndTimeOld;		///< 老录像时间段的结束时间
	char		fsType[NET_FSLEN];		///<文件类型
}SDK_DriverInformation;
enum
{
    SDK_MAX_DRIVER_PER_DISK = 4,		///< 每个磁盘最多的分区数
    SDK_MAX_DISK_PER_MACHINE = 8,		///< 最多支持8块硬盘
};
//硬盘管理
typedef struct SDK_STORAGEDISK
{
    int		iPhysicalNo;
    int		iPartNumber;		// 分区数
    SDK_DriverInformation diPartitions[SDK_MAX_DRIVER_PER_DISK];
}SDK_STORAGEDISK;

typedef struct SDK_StorageDeviceInformationAll
{
    int iDiskNumber;
    SDK_STORAGEDISK vStorageDeviceInfoAll[SDK_MAX_DISK_PER_MACHINE];
}SDK_StorageDeviceInformationAll;

/// 存储设备控制类型
enum SDK_StorageDeviceControlTypes
{
    SDK_STORAGE_DEVICE_CONTROL_SETTYPE,		///< 设置类型
    SDK_STORAGE_DEVICE_CONTROL_RECOVER,		///< 恢复错误
    SDK_STORAGE_DEVICE_CONTROL_PARTITIONS,	///< 分区操作
    SDK_STORAGE_DEVICE_CONTROL_CLEAR,		///< 清除操作
 	SDK_STORAGE_DEVICE_CONTROL_NR,
};

/// 清除磁盘数据类型
enum SDK_StorageDeviceClearTypes
{
    SDK_STORAGE_DEVICE_CLEAR_DATA,			///< 清除录像数据
    SDK_STORAGE_DEVICE_CLEAR_PARTITIONS,	///< 清除分区
    SDK_STORAGE_DEVICE_CLEAR_NR,
};

/// 驱动器类型
enum SDK_FileSystemDriverTypes
{
	SDK_DRIVER_READ_WRITE	= 0,	///< 读写驱动器
	SDK_DRIVER_READ_ONLY	= 1,	///< 只读驱动器
	SDK_DRIVER_EVENTS		= 2,	///< 事件驱动器
	SDK_DRIVER_REDUNDANT	= 3,	///< 冗余驱动器
	SDK_DRIVER_SNAPSHOT		= 4,	///< 快照驱动器
	SDK_DRIVER_TYPE_NR		= 5,	///< 驱动器类型个数
	SDK_DRIVER_UNUSED		= 0xff,	///< 没有使用的驱动器结构
};

/// 存储设备控制
typedef struct SDK_StorageDeviceControl
{
    int iAction;	///< 见enum SDK_StorageDeviceControlTypes
    int iSerialNo;	///< 磁盘序列号
    int iPartNo;    ///< 分区号
    int iType;		///< enum SDK_StorageDeviceClearTypes或者SDK_FileSystemDriverTypes
    int iPartSize[4/*MAX_DRIVER_PER_DISK*/];	///< 各个分区的大小
}SDK_StorageDeviceControl;

/// 设备类型
typedef enum SDK_DeviceType
{
    SDK_DEVICE_TYPE_DVR,	///< 普通DVR设备
    SDK_DEVICE_TYPE_NVS,	///< NVS设备
    SDK_DEVICE_TYPE_IPC,	///< IPC设备
    SDK_DEVICE_TYPE_NR
}SDK_DeviceType;

/// 设备信息
typedef struct _VIDEONET_DEVICEINFO
{
    char sSoftWareVersion[64];	///< 软件版本信息
    char sHardWareVersion[64];	///< 硬件版本信息
    char sEncryptVersion[64];	///< 加密版本信息
    SDK_SYSTEM_TIME tmBuildTime;///< 软件创建时间
    char sSerialNumber[64];		///< 设备序列号
    int byChanNum;				///< 视频输入通道数
    int iVideoOutChannel;		///< 视频输出通道数
    int byAlarmInPortNum;		///< 报警输入通道数
    int byAlarmOutPortNum;		///< 报警输出通道数
    int iTalkInChannel;			///< 对讲输入通道数
    int iTalkOutChannel;		///< 对讲输出通道数
    int iExtraChannel;			///< 扩展通道数
    int iAudioInChannel;		///< 音频输入通道数
    int iCombineSwitch;			///< 组合编码通道分割模式是否支持切换
    int iDigChannel;			///<数字通道数
    unsigned int uiDeviceRunTime;///<系统运行时间
    SDK_DeviceType deviceTye;	///设备类型
    char sHardWare[64];			///<设备型号
    char uUpdataTime[20];		///<更新日期 例如 2018-09-03 16:26:56
    unsigned int uUpdataType;	///<更新内容
	char sDeviceModel[16];       //设备型号(底层库从加密里获得，sHardWare针对多个设备用同一个程序这种情况区分不了) 
	int nLanguage;//国家的语言ID,0英语 1中文 2中文繁体 3韩语 4德语 5葡萄牙语 6俄语
}VIDEONET_DEVICEINFO,*LPVIDEONET_DEVICEINFO;

//主动服务回调数据
typedef struct VIDEONET_ACTIVEREG_INFO
{
    char deviceSarialID[64];		//设备序列号，如果大于64位则赋值0
    VIDEONET_DEVICEINFO deviceInfo;	//设备信息
    char IP[IP_SIZE];   			//外网IP
}VIDEONET_ACTIVEREG_INFO;
///< 自动维护设置
typedef struct SDK_AutoMaintainConfig
{
    int iAutoRebootDay;				///< 自动重启设置日期
    int iAutoRebootHour;			///< 重启整点时间	[0, 23]
    int iAutoDeleteFilesDays;		///< 自动删除文件时间[0, 30]
}SDK_AutoMaintainConfig;

/// 默认配置种类
enum SDK_DefaultConfigKinds
{
    SDK_DEFAULT_CFG_GENERAL,		// 普通配置
    SDK_DEFAULT_CFG_ENCODE,			// 编码配置
    SDK_DEFAULT_CFG_RECORD,			// 录像配置
    SDK_DEFAULT_CFG_NET_SERVICE,	// 网络服务
    SDK_DEFAULT_CFG_NET_COMMON,		// 通用网络
    SDK_DEFAULT_CFG_ALARM,			// 报警
    SDK_DEFAULT_CFG_PTZCOMM,		// 云台，串口
    SDK_DEFAULT_CFG_USERMANAGER,	// 用户管理
    SDK_DEFAULT_CFG_PREVIEW,		// 预览配置
    SDK_DEFAULT_CFG_CAMERA_PARAM,   // 网络摄像头配置
    SDK_DEFAULT_CFG_END,
};

/// 恢复的默认配置种类
typedef struct SDK_SetDefaultConfigTypes
{
    bool vSetDefaultKinds[SDK_DEFAULT_CFG_END];
	bool vDefaultFactory;			//恢复出厂设置配置
}SDK_SetDefaultConfigTypes;


typedef struct VIDEONET_CLIENTINFO{
    int nChannel;	//通道号
    int nStream;	//0表示主码流，为1表示子码流
    int nMode;		//0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-音视频分开(TCP)
    int nComType;	//只对组合编码通道有效, 组合编码通道的拼图模式,默认传0,定义时请初始化
    void* hWnd;
    
    VIDEONET_CLIENTINFO()
    {
        hWnd=0;
    }
    
}*LPVIDEONET_CLIENTINFO;


enum SDK_File_Type
{
    SDK_RECORD_ALL = 0,
    SDK_RECORD_ALARM = 1, //外部报警录像
    SDK_RECORD_DETECT,	  //视频侦测录像
    SDK_RECORD_REGULAR,	  //普通录像
    SDK_RECORD_MANUAL,	  //手动录像
    SDK_RECORD_KEY,		  //关键录像
    SDK_PIC_ALL = 10,
    SDK_PIC_ALARM,		  //外部报警图片
    SDK_PIC_DETECT,		  //视频侦测图片
    SDK_PIC_REGULAR,      //普通图片
    SDK_PIC_MANUAL,       //手动图片
    SDK_PIC_IDXIMG,		  //索引图片
    SDK_TYPE_NUM
};

//查询录像条件
typedef struct VIDEONET_FINDINFO
{
    int nChannelN0;			//通道号
    int nFileType;			//文件类型, 见SDK_File_Type
    VIDEONET_TIME startTime;//开始时间
    VIDEONET_TIME endTime;	//结束时间
    char szFileName[32];	//文件名，为空的话，系统处理，有值，系统采用
    void *hWnd;				
    int  StreamType;		//查询的码流类型,主码流:0,辅码流:1
    VIDEONET_FINDINFO()
    {
        hWnd=NULL;
        StreamType =0;
    }
}VIDEONET_FINDINFO;

//录像文件返回结构体
typedef struct VIDEONET_FILE_DATA
{
    int ch;						//通道号
    int size;					//文件大小
    char sFileName[108];		//文件名
    SDK_SYSTEM_TIME stBeginTime;//文件开始时间
    SDK_SYSTEM_TIME stEndTime;	//文件结束时间
    void *hWnd;					//窗口句柄
    int StreamType;				//码流类型是回放主码流（0）还是辅助码流（1）
    VIDEONET_FILE_DATA()
    {
        hWnd=NULL;
        StreamType =0;
    };
}VIDEONET_FILE_DATA;

//回放动作
enum SDK_PlayBackAction
{
    SDK_PLAY_BACK_PAUSE,		/*<! 暂停回放 */
    SDK_PLAY_BACK_CONTINUE,		/*<! 继续回放 */
    SDK_PLAY_BACK_SEEK,			/*<! 回放定位，时间s为单位 */
    SDK_PLAY_BACK_FAST,	        /*<! 加速回放 */
    SDK_PLAY_BACK_SLOW,	        /*<! 减速回放 */
    SDK_PLAY_BACK_SEEK_PERCENT, /*<! 回放定位百分比 */
	SDK_PLAY_SET_TYPE,			/*<! 回放智能定位*/
};

//按时间段查询
typedef struct SDK_SearchByTime
{
    int nHighChannel;			///< 33~64录像通道号掩码
    int nLowChannel;			///< 1~32录像通道号掩码
    int nFileType;              ///< 文件类型, 见SDK_File_Type
    SDK_SYSTEM_TIME stBeginTime;///< 查询开始时间
    SDK_SYSTEM_TIME stEndTime;	///< 查询结束时间
    int    iSync;               ///< 是否需要同步
    unsigned int	nHighStreamType;///< 33~64录像的码流类型,二进制位为0代表主码流，1代表辅码流
    unsigned int nLowStreamType;///< 1~32录像的码流类型,二进制位为0代表主码流，1代表辅码流
}SDK_SearchByTime;

//每个通道的录像信息
typedef struct SDK_SearchByTimeInfo
{
    int iChannel;			    ///< 录像通道号
    ///< 录像记录用720个字节的5760位来表示一天中的1440分钟
    ///< 0000:无录像 0001:F_COMMON 0002:F_ALERT 0003:F_DYNAMIC 0004:F_CARD 0005:F_HAND
    unsigned char cRecordBitMap[720];
}SDK_SearchByTimeInfo;

typedef struct SDK_SearchByTimeResult
{
    int nInfoNum;										 ///< 通道的录像记录信息个数
    SDK_SearchByTimeInfo ByTimeInfo[NET_MAX_CHANNUM];    ///< 通道的录像记录信息
}SDK_SearchByTimeResult;

//报警信息
typedef struct SDK_ALARM_INFO
{
    int nChannel;
    int iEvent; //报警事件码:见枚举SDK_EventCodeTypes
    int iStatus;//0:报警开始，1:报警结束
    SDK_SYSTEM_TIME SysTime;
	char pExtInfo[128]; //附加信息，发送者和接收者对各种报警类型进行格式约定
}SDK_AlarmInfo;

/// 日志查询条件
typedef struct SDK_LogSearchCondition
{
    int nType;						///< 日志类型
    int iLogPosition;				///< 从上次查询的结束时的日志指针
    SDK_SYSTEM_TIME stBeginTime;	///< 查询日志开始时间
    SDK_SYSTEM_TIME stEndTime;		///< 查询日志结束时间
}SDK_LogSearchCondition;


typedef struct SDK_LogItem
{
    char sType[24];				///< 日志类型
    char sUser[32];				///< 日志用户
    char sData[68];				///< 日志数据
    SDK_SYSTEM_TIME stLogTime;	///< 日志时间
    int  iLogPosition;			///< 从上次查询的结束时的日志指针
}SDK_LogItem;

//日志返回信息
typedef struct SDK_LogList
{
    int iNumLog;
    SDK_LogItem Logs[NET_MAX_RETURNED_LOGLIST];
}SDK_LogList;

/// 语音对讲格式
typedef struct SDK_AudioInFormatConfigAll
{
    SDK_AudioInFormatConfig vAudioInFormatConfig[SDK_AUDIO_ENCODE_TYPES_NR];
}SDK_AudioInFormatConfigAll;

/// 告警状态
typedef struct SDK_DVR_ALARMSTATE
{
	char iVideoMotion[NET_MAX_MSK_SIZE];	///< 移动侦测状态,用掩码表示通道号,byte0代表通道一,以此类推 1: 有告警 0: 无告警
	char iVideoBlind[NET_MAX_MSK_SIZE];		///< 视频遮挡状态,用掩码表示通道号,byte0代表通道一,以此类推 1: 有告警 0: 无告警
	char iVideoLoss[NET_MAX_MSK_SIZE];		///< 视频丢失状态,用掩码表示通道号,byte0代表通道一,以此类推 1: 有告警 0: 无告警
	char iAlarmIn[NET_MAX_MSK_SIZE];		///< 告警输入状态,用掩码表示通道号,byte0代表通道一,以此类推 1: 有告警 0: 无告警
	char iAlarmOut[NET_MAX_MSK_SIZE];		///< 告警输出状态,用掩码表示通道号,byte0代表通道一,以此类推 1: 有告警 0: 无告警
}SDK_DVR_ALARMSTATE;

// 通道状态
typedef struct SDK_DVR_CHANNELSTATE
{
    bool bRecord; ///< 是否正在录像
    int iBitrate;	///< 当前码率
}SDK_DVR_CHANNELSTATE;

// DVR工作状态
typedef struct SDK_DVR_WORKSTATE
{
    SDK_DVR_CHANNELSTATE vChnState[NET_MAX_CHANNUM];
    SDK_DVR_ALARMSTATE vAlarmState;
}SDK_DVR_WORKSTATE;


/// 按键值, 不能随便更改
enum SDK_NetKeyBoardValue
{
    SDK_NET_KEY_0, SDK_NET_KEY_1, SDK_NET_KEY_2, SDK_NET_KEY_3, SDK_NET_KEY_4, SDK_NET_KEY_5, SDK_NET_KEY_6, SDK_NET_KEY_7, SDK_NET_KEY_8, SDK_NET_KEY_9,
    SDK_NET_KEY_10, SDK_NET_KEY_11, SDK_NET_KEY_12, SDK_NET_KEY_13, SDK_NET_KEY_14, SDK_NET_KEY_15, SDK_NET_KEY_16, SDK_NET_KEY_10PLUS,SDK_NET_KEY_DIGIT,
    SDK_NET_KEY_UP = 20,     // 上或者云台向上
    SDK_NET_KEY_DOWN,        // 下或者云台向下
    SDK_NET_KEY_LEFT,        // 左或者云台向左
    SDK_NET_KEY_RIGHT,       // 右或者云台向右
    SDK_NET_KEY_SHIFT,
    SDK_NET_KEY_PGUP,        // 上一页
    SDK_NET_KEY_PGDN,        // 下一页
    SDK_NET_KEY_RET,         // 确认
    SDK_NET_KEY_ESC,         // 取消或退出
    SDK_NET_KEY_FUNC,        // 切换输入法
    SDK_NET_KEY_PLAY,        // 播放/暂停
    SDK_NET_KEY_BACK,        // 倒放
    SDK_NET_KEY_STOP,        // 停止
    SDK_NET_KEY_FAST,        // 快放
    SDK_NET_KEY_SLOW,        // 慢放
    SDK_NET_KEY_NEXT,        // 下一个文件
    SDK_NET_KEY_PREV,        // 上一个文件
	SDK_NET_KEY_PAUSE,		 // 暂停
	SDK_NET_KEY_FUNC_A,		 // 功能键A
	SDK_NET_KEY_FUNC_B,	     // 功能键B(在消费类产品上，A和B的功能会根据设备的不同而有不同的表现)
    SDK_NET_KEY_REC = 40,    // 录像设置
    SDK_NET_KEY_SEARCH,      // 录像查询
    SDK_NET_KEY_INFO,        // 系统信息
    SDK_NET_KEY_ALARM,       // 告警输出
    SDK_NET_KEY_ADDR,        // 遥控器地址设置
    SDK_NET_KEY_BACKUP,      // 备份
    SDK_NET_KEY_SPLIT,       // 画面分割模式切换，每按一次切换到下一个风格模式
    SDK_NET_KEY_SPLIT1,      // 单画面
    SDK_NET_KEY_SPLIT4,      // 四画面
    SDK_NET_KEY_SPLIT8,      // 八画面
    SDK_NET_KEY_SPLIT9,      // 九画面
    SDK_NET_KEY_SPLIT16,     // 16画面
    SDK_NET_KEY_SHUT,        // 关机
    SDK_NET_KEY_MENU,        // 菜单
    SDK_NET_KEY_SPLIT25,	 // 25画面
    SDK_NET_KEY_SPLIT36,     // 36画面
    SDK_NET_KEY_PTZ = 60,    // 进入云台控制模式
    SDK_NET_KEY_TELE,        // 变倍减
    SDK_NET_KEY_WIDE,        // 变倍加
    SDK_NET_KEY_IRIS_SMALL,  // 光圈增
    SDK_NET_KEY_IRIS_LARGE,  // 光圈减
    SDK_NET_KEY_FOCUS_NEAR,  // 聚焦远
    SDK_NET_KEY_FOCUS_FAR,   // 聚焦近
    SDK_NET_KEY_BRUSH,       // 雨刷
    SDK_NET_KEY_LIGHT,       // 灯光
    SDK_NET_KEY_SPRESET,     // 设置预置点
    SDK_NET_KEY_GPRESET,     // 转至预置点
    SDK_NET_KEY_DPRESET,     // 清除预置点
    SDK_NET_KEY_PATTERN,     // 模式
    SDK_NET_KEY_AUTOSCAN,    // 自动扫描开始结束
    SDK_NET_KEY_AUTOTOUR,    // 自动巡航
    SDK_NET_KEY_AUTOPAN,     // 线扫开始/结束
};


// 升级信息获取
typedef struct SDK_UpgradeInfo
{
    char szSerial[64];
    char szHardware[64];
    char szVendor[64];
    unsigned int uiLogoArea[2];
	char szLogoPartType[64];
}SDK_UpgradeInfo;

/// 网络报警
typedef struct SDK_NetAlarmInfo
{
    int iEvent;   //目前未使用
    int iState;   //每bit表示一个通道,bit0:第一通道,0-无报警 1-有报警, 依次类推
}SDK_NetAlarmInfo;

typedef enum SERIAL_TYPE
{
    RS232 = 0,
    RS485 = 1,
}SERIAL_TYPE;


enum MEDIA_PACK_TYPE
{
    FILE_HEAD =	0,	    		// 文件头
    VIDEO_I_FRAME = 1,			// 视频I帧
    VIDEO_B_FRAME =	2,			// 视频B帧
    VIDEO_P_FRAME = 3,			// 视频P帧
    VIDEO_BP_FRAME = 4,			// 视频BP帧
    VIDEO_BBP_FRAME	= 5,		// 视频B帧B帧P帧
    VIDEO_J_FRAME = 6,			// 图片帧
    AUDIO_PACKET = 10,			// 音频包
};

typedef struct
{
    int		       nPacketType;			// 包类型,见MEDIA_PACK_TYPE
    char*	       pPacketBuffer;		// 缓存区地址
    unsigned int   dwPacketSize;		// 包的大小
    
    // 绝对时标
    int		       nYear;				// 时标:年
    int		       nMonth;				// 时标:月
    int		       nDay;				// 时标:日
    int		       nHour;				// 时标:时
    int		       nMinute;				// 时标:分
    int		       nSecond;				// 时标:秒
    unsigned int   dwTimeStamp;			// 相对时标低位，单位为毫秒
    unsigned int   dwTimeStampHigh;    	//相对时标高位，单位为毫秒
    unsigned int   dwFrameNum;          //帧序号
    unsigned int   dwFrameRate;         //帧率
    unsigned short uWidth;              //图像宽度
    unsigned short uHeight;             //图像高度
    unsigned int   Reserved[6];     	//保留
} PACKET_INFO_EX;

typedef struct __TransComChannel//透明串口
{
    SERIAL_TYPE TransComType;	//SERIAL_TYPE
    unsigned int baudrate;
    unsigned int databits;
    unsigned int stopbits;
    unsigned int parity;
} TransComChannel;
typedef enum SDK_State_Type
{
    DEV_STATE_DDNS=0,
}SDK_State_Type;

//摄象机参数.....

//曝光配置
typedef struct SDK_ExposureCfg
{
    int  level;    			//曝光等级
    unsigned int leastTime;	//自动曝光时间下限或手动曝光时间，单位微秒
    unsigned int mostTime; 	//自动曝光时间上限，单位微秒
}SDK_ExposureCfg;

//增益配置
typedef struct SDK_GainCfg
{
    int gain;    //自动增益上限(自动增益启用)或固定增益值
    int autoGain;//自动增益是否启用，0:不开启  1:开启
}SDK_GainCfg;

//网络摄像机配置
typedef struct SDK_CameraParam
{
    unsigned int whiteBalance;      //白平衡
    unsigned int dayNightColor;     //日夜模式，取值有彩色、自动切换和黑白
    int elecLevel;             		//参考电平值
    unsigned int apertureMode;      //自动光圈模式
    unsigned int BLCMode;           //背光补偿模式
    SDK_ExposureCfg exposureConfig;	//曝光配置
    SDK_GainCfg     gainConfig;    	//增益配置
    
    unsigned int PictureFlip;		//图片上下翻转
    unsigned int PictureMirror;		//图片左右翻转(镜像)
    unsigned int RejectFlicker;		//日光灯防闪功能
    unsigned int EsShutter;			//电子慢快门功能
    
    int ircut_mode;		//IR-CUT切换 0 = 红外灯同步切换 1 = 自动切换
    
    int dnc_thr;		//日夜转换阈值
    int ae_sensitivity;	//ae灵敏度配置
    
    int Day_nfLevel;	//noise filter 等级，0-5,0不滤波，1-5 值越大滤波效果越明显
    int Night_nfLevel;
    int Ircut_swap;		//ircut 正常序= 0        反序= 1
	int high_light;     //强光抑制功能 0~255,默认是16
}SDK_CameraParam;

//所有摄象机配置
typedef struct SDK_AllCameraParam
{
    SDK_CameraParam vCameraParamAll[NET_MAX_CHANNUM];   //所有的通道
}SDK_AllCameraParam;

//曝光能力级
typedef struct SDK_CameraAbility
{
    int  count;      						//支持曝光速度数量
    unsigned int speeds[CAMERAPARA_MAXNUM]; //曝光速度
    int  status;     						//工作状态  >= 0 正常    < 0 异常
    int  elecLevel;  						//参考电平值
    int  luminance;  						//平均亮度
    char pVersion[64];						//xm 2a版本
	char isFishLens; //是否是鱼眼镜头，如果是，则需要app和PC端做图像校正
	char resv1[3];   //保留，如果增加char型的成员先用这里的
	char reserve[28];//保留，如果增加int型的成员用这里
}SDK_CameraAbility;

//本地播放控制
enum SDK_LoalPlayAction
{
    SDK_Local_PLAY_PAUSE,		/*<! 暂停播放 */
    SDK_Local_PLAY_CONTINUE,	/*<! 继续正常播放 */
    SDK_Local_PLAY_FAST,	    /*<! 加速播放 */
    SDK_Local_PLAY_SLOW,	    /*<! 减速播放 */
    
};

typedef struct SDK_DASSerInfo
{
    bool enable;
    char serAddr[NET_NAME_PASSWORD_LEN];
    int  port;
    char userName[NET_NAME_PASSWORD_LEN];
    char passwd[NET_NAME_PASSWORD_LEN];
    char devID[NET_NAME_PASSWORD_LEN];
}SDK_DASSerInfo;
typedef enum UploadDataType  //上传数据类型
{
    VEHICLE=0,				//车载信息
    SDK_RECORD_STATE,		//录像状态
    SDK_DIGITCHN_STATE,		//数字通道连接状态
    SDK_TITLE_INFO,			//通道标题
	SDK_FUNCTION_STATE,		//功能状态例如运动相机录像，延时拍等
	SDK_ELECT_STATE,		//电量
	SDK_MUSICBOX_STATE,		//wifi音乐盒
	SDK_ADD_433DEV_RESULT,	//433报警配对数据
}UploadDataType;

//外部输入类型
enum SDK_IO_INPUT_TYPE
{
    SDK_LOCAL_ALARM_INPUT,//本地报警输入
    SDK_RS232_INPUT,      //通过232串口输入
    SDK_RS485_INPUT,      //通过485串口输入
};

enum SDK_network_media {
    SDK_NM_WIRED = 0,  	//有线网卡
    SDK_NM_WLAN,       	//Wifi
    SDK_NM_3G,         	//3G网卡
    SDK_NM_NR,    		//种类数
};
//网络连接优先级
typedef struct SDK_tagNetLinkOrder
{
    int netType;  //取值是network_media类型的
    int netOrder; //数字越小，优先级越高,0是最高优先级
}SDK_NetLinkOrder;
//网络优先级
typedef struct SDK_NetOrderConfig
{
    bool         bEnable;        			//是否设置网络优先级
    int          netCount;       			//网络类型数目
    SDK_NetLinkOrder pNetOrder[SDK_NM_NR];	//网络优先级
    SDK_NetLinkOrder pReserve[7-SDK_NM_NR];	//给新的网络类型预留
}SDK_NetOrderConfig;
///网络优先级能力
typedef struct SDK_NetOrderFunction
{
    bool bNetOrder;
}SDK_NetOrderFunction;

enum NET_ISP
{
    ISP_AUTO, 		//自动选择
    ISP_TELCOM, 	//电信
    ISP_UNIONCOM, 	//联通
    ISP_CNC,		//网通
    ISP_MOBILE,		//移动，铁通
    ISP_USER,		//自定义
};
//网络平台信息设置
typedef struct SDK_LocalSdkNetPlatformConfig
{
    int Enable;
    int nISP;                          ///参见NET_ISP
    char sServerName[32];
    char ID[32];
    char sUserName[32];
    char sPassword[32];
    CONFIG_IPAddress HostIP;		///< host ip
    int port;
}SDK_LOCALSDK_NET_PLATFORM_CONFIG;

enum  SDK_DigManagerShowStatus
{
    SDK_DM_SHOW_NONE,
    SDK_DM_SHOW_ALL,
};


//数字通道显示状态
typedef struct SDK_DigitalManagerShow
{
    int  nDigitalManagerShowSta;
}SDK_DigitalManagerShow;

typedef enum SubConnType
{
    conn_realTimePlay=1,
    conn_talk,
    conn_playback,
   	conn_facepicture,
	conn_faceCompareResult,
	conn_faceBlackAndWhitelList, 
	conn_push
}SubConnType;
//*** */向设备注册
enum SocketStyle
{
	TCPSOCKET=0,
	UDPSOCKET,	
    SOCKETNR
};

/// 数字水印配置
typedef struct SDK_WaterMarkConfig
{
    bool	bEnable;		//  开启水印
    char  sKey[8];
    char sUserData[16];
}SDK_WaterMarkConfig;

typedef struct SDK_WaterMarkConfigAll
{
    SDK_WaterMarkConfig vWaterMarkConfigAll[NET_MAX_CHANNUM];
}SDK_WaterMarkConfigAll;

///编码器静态参数
typedef struct SDK_EncodeStaticParam
{
    int profile;
    int level;
    int reserved1[4];
}SDK_EncodeStaticParam;


typedef struct SDK_EncodeStaticParamAll
{
    SDK_EncodeStaticParam	EncodeStaticParamAll[NET_MAX_CHANNUM];
}SDK_EncodeStaticParamAll;


/// 录像存储设备类型，以下类型的一种或者多种
typedef struct SDK_RecordStorageType
{
    bool SATA_as;
    bool USB_as;
    bool SD_as;
    bool DVD_as;
}SDK_RecordStorageType;

//当前VGA分辨率
typedef struct SDK_VGAresolution
{
    int nHeight;
    int nWidth;
}SDK_VGAresolution;
//支持VGA分辨率列表
typedef struct SDK_VGAResolutionAbility
{
    int vVGANum;
    char vVGAList[VGA_MAXNUM][VGA_NAME_LENGTH];
}SDK_VGAResolutionAbility;

//设备列表(设备搜索的)
typedef struct SDK_NetDevList
{
    int vNetDevNum;
    SDK_CONFIG_NET_COMMON_V2 vNetDevList[DEV_LIST_SHOW];
}SDK_NetDevList;


/***设备信息***/
//闲置布防类型枚举
typedef enum SDK_GuardType
{
    SDK_FORBID = 0,      //禁止
    SDK_TEN_MIN,         //十分钟
    SDK_THIRTY_MIN,      //三十分钟
    SDK_SIXTY_MIN,       //六十分钟
    SDK_MAX,
}SDK_GUARDTYEP;

//搜索设备协议
typedef enum SDK_TransferProtocol_V2
{
    SDK_TRANSFER_PROTOCOL_NETIP,
    SDK_TRANSFER_PROTOCOL_ONVIF,
    SDK_TRANSFER_PROTOCOL_MAC,
	SDK_TRANSFER_PROTOCOL_NAT,
	SDK_TRANSFER_PROTOCOL_DAHUA,
	SDK_TRANSFER_PROTOCOL_RTSP,
	SDK_TRANSFER_PROTOCOL_NETIPV6,
    SDK_TRANSFER_PROTOCOL_NR_V2,
    SDK_TRANSFER_PROTOCOL_ONVIF_DEFAULT = 128,
    SDK_TRANSFER_PROTOCOL_ONVIF_NR_V2
}SDK_TransferProtocol_V2;

typedef struct SDK_EncodeStaticParamV2
{
    int profile; //当前静态编码
    int reserved1[4]; //保留字段
}SDK_EncodeStaticParamV2;

/*
 ==	DVR静态编码能力集，现在3种
 ==	0 不支持 1 支持baseline 2 支持main profile 4 支持high profile
 ==  掩码操作
 */
typedef struct SDK_EncStaticParamAbility
{
    unsigned int encStaticParam;
}SDK_EncStaticParamAbility;

//28181协议配置
typedef struct SDK_ASB_NET_VSP_CONFIG
{
    bool	bCsEnable;								//使能标记
    char	szCsIP[64];								//服务器地址
    short	sCsPort;								//服务器端口
    short	sUdpPort;								//本地绑定udp端口
    char	szServerNo[64];							//服务器序列号
    char 	szServerDn[64];							//服务器所在的域名称
    char	szDeviceNO[64];							//设备序列号
    char 	szConnPass[64];							//设备接入密码
    int		iHsIntervalTime;						//心跳间隔时间,单位是秒
    int		iRsAgedTime;							//重新发送注册时间间隔，单位为秒
    char	Camreaid[NET_MAX_CHANNUM][64];			//设备中摄像头ID
    int		CamreaLevel[NET_MAX_CHANNUM];			//报警等级
    char	Alarmid[NET_MAX_CHANNUM][64];			//设备中摄像头ID
    int		AlarmLevel[NET_MAX_CHANNUM];			//报警等级
    unsigned int	uiAlarmStateGpinEnable;			//外部报警使能
    unsigned int	uiAlarmStateLoseEnable;			//视频丢失告警使能
    unsigned int	uiAlarmStateMotionEnable;		//视频动态侦测告警使能
    unsigned int	uiAlarmStateBlindEnable;		//屏幕遮挡告警使能
    unsigned int	uiAlarmStatePerformanceEnable;	//系统异常告警使能
    unsigned int	uiAlarmStateConnectEnable;		//用户连接告警使能
}SDK_ASB_NET_VSP_CONFIG;

//屏幕提示信息
typedef struct  SDK_OSDInfoConfig
{
    SDK_VIDEO_WIDGET OSDInfoWidget;
    char ppInfo[NET_MAX_LINE_PER_OSD_AREA][NET_CHANNEL_NAME_MAX_LEN];
}SDK_OSDInfoConfig ;

typedef enum SDK_wordEncType
{
    SDK_wordEnc_GB2312,			//汉字编码GB2312
    SDK_wordEnc_Unicode,		//万国码 Unicode
    SDK_wordEnc_UTF8,			//UTF-8
    SDK_wordEnc_NR,	
}SDK_wordEncType;

//所有通道的屏幕提示信息
typedef struct  SDK_OSDInfoConfigAll
{
    SDK_OSDInfoConfig   vOSDInfoAll[NET_MAX_CHANNUM];
    int strEnc;//编码格式,默认为UTF-8,不做任何处理；主要用于客户特殊需求，枚举参见SDK_wordEncType
}SDK_OSDInfoConfigAll;
//
typedef struct SDK_VideoChannelManage
{
    int		nHVRCap;
    int		curMode;
    bool bhide[MAX_HVR_CHNCAP_CHN];
    SDK_CAPTURE_HVRCAPV2	HVRCap[MAX_HVR_CHNCAP_CHN];
}SDK_VideoChannelManage ;

//PTZ控制能力集
typedef struct SDK_PTZControlAbility
{
    unsigned int nPTZPosition;
}SDK_PTZControlAbility;

typedef struct SDK_PositionPoint
{
    int iPointStart_x;
    int iPointStart_y;
    int iPointEnd_x;
    int iPointEnd_y;
}SDK_PositionPoint;

typedef struct SDK_XMHeartbeatConfig
{
    bool bEnable;								///< 是否开启
    int iInterval;								///< 保活间隔时间
    char ServerName[NET_NAME_PASSWORD_LEN];		///< 服务名
    int Port;									///< 端口号
    char UserName[NET_NAME_PASSWORD_LEN];		///< 用户名
    char Password[NET_NAME_PASSWORD_LEN];		///< 密码
    char resume[24];
}SDK_XMHeartbeatConfig;

typedef enum SDK_IMG_TYPE
{
    SDK_IMG_TYPE_DEFAULT,
    SDK_IMG_TYPE_1,
    SDK_IMG_TYPE_2,
    SDK_IMG_TYPE_NR,
}SDK_IMG_TYPE;
//网络摄像头扩展参数
typedef struct SDK_CameraParamEx
{
    SDK_GainCfg broadTrends;		//宽动态
    int style;						//enum SDK_IMG_TYPE
    unsigned int exposureTime;		//实际生效的曝光时间
	int  Dis ;						//电子防抖设置  0:关闭 1:开启**/
	int Ldc; 						//镜头畸变校正  0:关闭 1:开启**/
	int AeMeansure; 				//测光模式校正  0:平均测光 1:中央测光**/
	int LowLuxMode; 				//微光模式 mode：0 关闭 1开启 ==only imx291
	int corridor_mode;				//1:走廊模式  0:普通模式
	int lightRestrainLevel;			// 强光抑制功能0~255，默认16
	int res[56];	//冗余 
}SDK_CameraParamEx;

// 摄像头所有扩展参数
typedef struct SDK_CameraParamExAll
{
    SDK_CameraParamEx vCameraParamExAll[NET_MAX_CHANNUM];
}SDK_CameraParamExAll;

//wifi状态
typedef struct SDK_WifiStatusInfo
{
    int  connectStatus;  //wifi连接状态  如枚举SDK_INFO_NET_LINK_STATUS所述
    int  strength;       //信号强度
    char rev[24];
}SDK_WifiStatusInfo;

//主动注册状态
typedef struct SDK_DASStatusInfo
{
    int  connectStatus;  //DAS连接状态  如枚举SDK_INFO_NET_LINK_STATUS所述
    char rev[28];
}SDK_DASStatusInfo;

typedef struct SDK_RecordStorageInfo
{
    unsigned int bStart;			//是否录像标志位
    SDK_SYSTEM_TIME beginTime;		//录像开始时间
    SDK_SYSTEM_TIME endTime;		//录像结束时间
    unsigned int  storageCapacity;	//硬盘总容量
    unsigned int  useCapacity;		//使用容量
    int res[16];					//冗余
}SDK_RecordStorageInfo;
/// 解码延时等级
typedef enum SDK_DecodeDeleyTypes
{
    SDK_DecodeDeley_0 = 0,
    SDK_DecodeDeley_1,
    SDK_DecodeDeley_2,
    SDK_DecodeDeley_3,
    SDK_DecodeDeley_4,
    SDK_DecodeDeley_5,
    SDK_DecodeDeley_6,
    SDK_DecodeDeley_TYPE_NR,
}SDK_DecodeDeleyTypes;

typedef struct SDK_DecodeDeleyTimePrame
{
    unsigned int  DecodeDeleyTime[SDK_DecodeDeley_TYPE_NR];
}SDK_DecodeDeleyTimePrame;

// 数字通道
typedef struct SDK_DecodeParam
{
    int iMaxDeleyTime[NET_MAX_CHANNUM];	// 最大的解码延时
}SDK_DecodeParam;

typedef struct SDK_RecordStateInfo
{
    int nchannel;
    int RecordState;
}SDK_RecordStateInfo;

//定制视频颜色结构
typedef struct SDK_VIDEOCOLOR_PARAM_EX
{
    int		BrightnessRef;		///< 亮度ref1，取值0-100。
    int		ContrastRef;		///< 对比度ref1，取值0-100。
    int  		ContrastThRef;	///< 对比度阀值ref1，取值0-100。
    int		ContrastSlopeRef;	///< 对比度斜率ref1，取值0-100。
    int 		DarkBlfRef;
    int		DarkNfRef;
    int		DarkEcPthRef;
    int		DarkEcMthRef;
    int		DarkDcRef;
    int		CbGain;				///high low middle
    int		CrGain;				///higg low middle
    int		reserved;			///保留
}SDK_VIDEOCOLOR_PARAM_EX;

typedef struct SDK_VIDEOCOLOR_PARAM_CUSTOM
{
    SDK_VIDEOCOLOR_PARAM_EX	VideoColor[3];
    int		Saturation;		///< 饱和度，取值0-100。
    int		Gain;			///< 增益，取值0-100。bit7置位表示自动增益，其他位被忽略。
    int		Acutance;		///< 锐度，取值0-100
    int		AeWight;		//背光补偿
}SDK_VIDEOCOLOR_PARAM_CUSTOM;

typedef enum SDK_FileControlType
{
    SDK_FILE_DEL,			//删除文件
    SDK_FILE_DIR_DEL,		//删除文件夹
    SDK_FILE_DIR_CLEAR,		//清空文件夹
	SDK_RUNTIME_CLEAR,		//清除运行时间
    SDK_FILE_NR,
}SDK_FileControlType;

typedef struct SDK_NetFileControl
{
    int iAction;			//enum FileControlType
    char strfile[256];
}SDK_NetFileControl;

typedef enum SDK_DecChnStateType
{
    SDK_DEC_STA_NONE, 			//无用
    SDK_DEC_STA_NOCONFIG,		//未配置
    SDK_DEC_STA_NOLOGIN,		//未登陆
    SDK_DEC_STA_NOCONNECT,		//未连接
    SDK_DEC_STA_CONNECTED,		//已连接
    SDK_DEC_STA_LOGIN_FAILED,	//登录失败
	SDK_DEC_STA_OFFLINE,		//前端设备不在线
}SDK_DecChnStateType;

typedef struct SDK_DigitStateInfo
{
    int nchannel;
    int DigitState; //SDK_DecChnStateType
}SDK_DigitStateInfo;

typedef struct SDK_TitleNameInfo
{
    int nchannel;
    char titleName[256];
}SDK_TitleNameInfo;

typedef struct SDK_Add433DevResult
{
	int nchannel;
	int n433DevChn;
	int AddRet;
	char DevID[8];
}SDK_Add433DevResult;
typedef struct SDK_AbilityMask
{
    unsigned int AbilityPram;
}SDK_AbilityMask;

typedef enum SDK_Music_Play_Action
{
    SDK_MUSIC_ACTION_PLAY,
    SDK_MUSIC_ACTION_STOP,
    SDK_MUSIC_ACTION_PAUSE,
    SDK_MUSIC_ACTION_CONTINUE
}SDK_Music_Play_Action;

typedef struct SDK_LocalMusicControl
{
    int iAction;            //参考SDK_Music_Play_Action
    char sFileName[20];
}SDK_LocalMusicControl;

/// 音频文件列表信息
typedef struct SDK_MusicFileList
{
    int iNumFiles;		///< 文件数量
    char sFileName[8][20];
}SDK_MusicFileList;

//单个IPC
typedef struct SDK_ALARM_IPCCONFIG
{
    bool	bEnable;			///< 报警输入开关
    int		iSensorType;		///< 传感器类型常开 or 常闭
    SDK_EventHandler hEvent;	///< 报警联动
}SDK_ALARM_IPCCONFIG;
///< 所有数字通道的报警配置
typedef struct SDK_IPCAlarmConfigAll
{
    SDK_ALARM_IPCCONFIG vAlarmConfigAll[NET_DECORDR_CH];
}SDK_IPCAlarmConfigAll;

typedef struct SDK_LOGIN_CFG//修改前端ip登录用
{
    char sUserName[NET_MAX_USER_LENGTH];		///< 登陆名字
    char sPassword[NET_MAX_USER_LENGTH];		///< 登陆密码
    int iEncryptType;			///< 密码加密方式 固定值 1
}SDK_LOGIN_CFG;

typedef struct SDK_IPSetCfg
{
    int ch;
    int devtype;
    SDK_CONFIG_NET_COMMON netcfg;
    SDK_LOGIN_CFG loginPram;
}SDK_IPSetCfg;

#define SDK_LONG_PATH_LEN 256	// 远程路径(挂载源)
#define SDK_SHORT_PATH_LEN 64	// 本地挂载点
#define SDK_FS_TYPE_LEN 8	//文件系统类型(eg: ext3)名字长度上限
#define SDK_USERNAME_LEN 32
#define SDK_PASSWD_LEN 32
#define SDK_MAX_NAS_NUM 8	//最多支持NAS个数
#define SDK_MAX_DEV_NUM 16	// 支持本地设备个数
#define SDK_MAX_PART_NUM 4	// 单个硬盘支持的分区数量上限
struct SDK_NAS_INFO	// NAS信息
{
	char mountSrc[SDK_LONG_PATH_LEN];	// 远程路径(挂载源)
	char fsType[SDK_FS_TYPE_LEN];
	char mountOn[SDK_SHORT_PATH_LEN];	// 本地挂载点
	char username[SDK_USERNAME_LEN];
	char password[SDK_PASSWD_LEN];
	unsigned int DirType;	//如枚举IStorageDirectory::DIR_TYPE描述
};

typedef struct SDK_NAS_LIST	// NAS(samba, nfs)列表
{
	unsigned int  count;
	SDK_NAS_INFO nasInfo[SDK_MAX_NAS_NUM];
}SDK_NAS_LIST;

//二维
typedef struct SDK_DimenCode
{
    int size;
    unsigned char code[3920];// 177*177/32*4=3920，局部变量
}SDK_DimenCode;

typedef struct SDK_DimenCodeAll
{
    SDK_DimenCode sn;
    SDK_DimenCode appIOS;
    SDK_DimenCode appAndroid;
    SDK_DimenCode otherInfo;  //客户自定义信息
}SDK_DimenCodeAll;

typedef struct SDK_TimeZone
{
    int minuteswest; 	//跟UTC时间的差值，单位分钟，可以为负
    int FistFlag;		//用于保证第一次使用的时候时间不变
}SDK_TimeZone;


typedef enum SDK_TimeSynTypes
{
    SDK_TST_OFF = 0,
    SDK_TST_TIME_UTC,
    SDK_TST_TIME_LOCAL,
    SDK_TST_TIME_ALL,
    SDK_TST_NR,
}SDK_TimeSynTypes;

// 数字通道时间同步
typedef struct SDK_TimeSynParam
{
    int iTimeModel[NET_MAX_CHANNUM]; //参考SDK_TimeSynTypes
}SDK_TimeSynParam;

typedef struct SDK_IFrameRange
{
	int main_min;
	int main_max;
	int sub_min;
	int sub_max;
}SDK_IFrameRange;

typedef struct SDK_DigitDevInfo
{
    bool enable; 					//配置是否可用，本地设备使用
    int nCapture;					//模拟通道数
    int nAudio;						//音频通道数
    int videoFormat;				//视频制式
    CONFIG_EncodeAbility ability;	//编码能力
	SDK_IFrameRange iGOPRange;	//主辅码流的I帧间隔范围
}SDK_DigitDevInfo;

typedef struct SDK_EncodeChDisplay
{
    char displayChanelMask[NET_MAX_MSK_SIZE];	//IE显示的编码配置通道号掩码
}SDK_EncodeChDisplay;

//点间巡航
typedef struct SDK_TourState
{
    bool bRunning;
    int  lineID;   //点间巡航线路编号
}SDK_TourState;

//巡迹
typedef struct SDK_PatternState
{
    bool bRunning;
    int  lineID;  //巡迹线路编号 (未使用)
}SDK_PatternState;

//线扫
typedef struct SDK_ScanState
{
    bool bRunning;
    int  lineID;  //线扫线路编号 (未使用)
}SDK_ScanState;

//水平旋转
typedef struct SDK_PanonState
{
    bool bRunning;
    int  lineID;  //水平旋转线路编号 (未使用)
}SDK_PanonState;

//开机转到指定预置点
typedef struct SDK_PresetState
{
    bool bEnable;
    int  iPresetID;
}SDK_PresetState;

//断电前位置
typedef struct SDK_PoweroffState
{
    bool bEnable;
    int  iPresetID;
}SDK_PoweroffState;

//一个通道的云台操作状态
typedef struct SDK_PtzState
{
    SDK_TourState    tourState;
    SDK_PatternState patternState;
    SDK_ScanState    scanState;
    SDK_PanonState   panonState;
    SDK_PresetState  presetState;
    SDK_PoweroffState poweroffState;
}SDK_PtzState;

//重启后恢复之前的云台操作状态
typedef struct SDK_ResumePtzState
{
    bool     bEnable;                    //是否启用设备重启后恢复云台状态功能
    SDK_PtzState ptzStateAll[NET_MAX_CHANNUM];
}SDK_ResumePtzState;

typedef struct SDK_OSDInfo
{
    int index;//设置通道标题和时间标题之外的区域，取值0和1
    int nX;//范围0-1000
    int nY;//范围0-1000
    int nChannel;//要设置的通道
    char pOSDStr[1024];//要叠加的字符串
}SDK_OSDInfo;

typedef struct SDK_UserMap
{
    int size;
    USER_INFO UserCfg[64];
}SDK_UserMap;

//wifi模式相关配置，用于行车记录仪自动切换AP模式
typedef struct SDK_NetWifiMode
{
    int autoSwitchAPMode; //取值  1:自动切换成AP模式(家用模式)  0:不自动切换
    int reserve[7];
}SDK_NetWifiMode;

typedef struct SDK_TitleDot
{
	int width;
	int height;
	char pDotBuf[NET_MAX_TITLE_DOT_BUF_LEN];
}SDK_TitleDot;

typedef struct SDK_Authority
{
    int Level;
	int Ability;
}SDK_Authority;

typedef struct SDK_Arm
{
    int Guard;
}SDK_Arm;

typedef struct SDK_AlarmInfo_V2
{
    char Descrip[64];
    char SerialID[64];
    char Type[32];
    char iEvent[20];
    char iStatus[20];
    SDK_SYSTEM_TIME SysTime;
}SDK_AlarmInfo_V2;

/// 用户登陆方式
typedef enum SDK_LoginType
{
    VIDEONET_LOGIN_TYPE_WEB,			///< WEB登陆(默认)
    VIDEONET_LOGIN_TYPE_LOCALUPGRADE,	///< 升级工具(局域网升级)登陆
    VIDEONET_LOGIN_TYPE_CLOUDUPGRADE,	///< 云升级登陆
    VIDEONET_LOGIN_TYPE_PCCLIENT,		///< PC客户端登陆
    VIDEONET_LOGIN_TYPE_MOBILE,			///< 移动终端（IPhone）登陆
	VIDEONET_LOGIN_TYPE_FUTRUE_HOME,	///未来家庭客户端登陆
	VIDEONET_LOGIN_TYPE_XM030,			///xmeye客户端登陆
    VIDEONET_LOGIN_TYPE_NR,				///< 登陆类型
}SDK_LoginType;

typedef enum
{
    SDK_LocalAlarm = (int)0x00001,
    SDK_MotionDetect = (int)0x00002,
}SDK_AlarmRecType;


//是否叠加OSD logo
typedef struct SDK_SetLogo
{
	int Enable;
	int	reserve[8];
}SDK_SetLogo;
typedef enum SDK_EncMode
{
	WIFI_ENC_OPEN = 0,
	WIFI_ENC_AES = 1,
	WIFI_ENC_TKIP = 2,
	WIFI_ENC_WEP =3
}SDK_EncMode;

//ipv6
typedef struct SDK_IPAddressV6
{
	bool bEnable;				//是否启用ipv6
	char pLocalLinkAddr[32];	//本地链路地址
	char pAddr[64];				//ipv6地址
	char pGateway[64];			//网关
	int	iPrefix;  				//ipv6前缀长度
} SDK_IPAddressV6;

typedef struct SDK_OnlineUpgradeCfg
{
	char cEnable; 				//是否启用在线升级功能
	char pServerAddr[63];
	int  serverPort;
	char cAutoCheck;		//是否开启自动检测
	char cAutoUpgradeImp;		//只自动升级重要更新
	char cIgnoreAllVersion;		//忽略所有版本的页面提示
	char cIgnoreCurVersion;		//忽略当前版本的页面提示，发现更新的版本后也只提示一次
	unsigned int IgnoreCurTime;	//忽略掉的当前版本的时间，与 bIgnoreCurVersion联用
	char cJustImpVersion;		//只有重要版本提示
	char rev[3];
} SDK_OnlineUpgradeCfg;

///<硬盘出错事件结构
typedef struct SDK_StorageFailConfig
{
	bool 	bEnable;
	SDK_EventHandler hEvent;	///< 处理参数
	bool	bRebootEnable;		//系统重启全能:hutianhao
	int		bRebooted;			//是否出错重启过;0:未出错重启过;非0:出错重启过
	int		NoBitRateCnt;		//无码流设备自动重启次数
}SDK_StorageFailConfig;

//CMS客户端端发来的画面分割条件
typedef struct SDK_SplitControl
{
	int iSplitChannel;//分割通道
	int iSplitWinType;//分割类型(如:四通道)
	char rev[8];
}SDK_SplitControl;

typedef enum _SDK_EXCEPTION_TYPE
{
	SDK_EXCEPTION_DISCONNECTED,//设备断线
	SDK_EXCEPTION_RECCONNECTED,//设备恢复重连
}SDK_EXCEPTION_TYPE;

//重连设备的相关信息
typedef struct SDK_ReconInfo
{
	LPVIDEONET_DEVICEINFO deviceInfo; //重新登录后的设备信息（切换模式了设备通道等信息可能会变（例如通道模式变化了）,所以重连成功后要返回出来）
	void* pWnd;			//重连视频时通道对应的窗口句柄
	int nType;			//见枚举SDK_EXCEPTION_TYPE
}SDK_ReconInfo;

//子连接重连设备的相关信息
typedef struct SDK_SubConnectInfo
{
	long lRealHandle;	//预览视频子连接断开后重连视频成功的播放句柄
	bool bSubOnline;	//预览视频子连接是否重连上,true代表子连接重连上了
	void* pWnd;			//预览视频子连接断开后重连视频时通道对应的窗口句柄；bSubOnline为trie时调用VIDEONET_RealPlay时传入窗口句柄时pWnd才有值，否则都为NULL
}SDK_SubConnectInfo;

//sip 设备板卡地址
typedef struct SDK_SIP_NET_IP_CONFIG
{
	char	SIPDevIP[64]; 

}SDK_SIP_NET_IP_CONFIG;
typedef struct SDK_registersercfg
{
	bool enable;
	char serAddr[NET_NAME_PASSWORD_LEN];//PAG配置
	int  port;
	int  factorycode;//厂商代码
	char userName[NET_NAME_PASSWORD_LEN];
	char passwd[NET_NAME_PASSWORD_LEN];
	char puid[NET_NAME_PASSWORD_LEN];//设备id
	char mainid[NET_NAME_PASSWORD_LEN];//域id
	int TaskID;//存储相关
	int TaskName;//存储相关
	char MainRecordPath[256];//主用地址
	char BakRecordPath[256];//备用地址
	int FileMode;//文件打包格式   0：按时长，1：按大小
	int FileLength;//文件值10，FileMode为0表示10分钟，为1时表示10M
	int VideoTransMode;//实时传输视频的模式【实时视频发流模式】(0-UDP ,1-TCP)
	char Reserved[NET_NAME_PASSWORD_LEN];
}SDK_GbEyesCfg;

//AHDL通道掩码，该通道为AHDL置1
typedef struct SDK_AHDEncodeLMask
{
	char AHDLMask[NET_MAX_MSK_SIZE];
}SDK_AHDEncodeLMask;

typedef struct SDK_PortService
{
	BOOL Enable;		///< 是否开启
	int port;
}SDK_PortService;

/// 默认响应包格式
typedef struct SDK_DefaultResponse
{
	unsigned int uiSessionId;		///< 会话ID
	int iRet;				///< 返回值
	char sName[64];		///< 配置名称
}SDK_DefaultResponse;

typedef enum SDK_CloudRecType
{
	SDK_TimeRec = (int)0x00001,
	SDK_AlarmRec = (int)0x00002,
}SDK_CloudRecType;

//云台配置的控制方式设置
typedef enum SDK_PTZ_CTRL_TYPE
{
	PTZ_CTRL_COAX = 0,//通过同轴线
	PTZ_CTRL_RS485,   //通过485线
	PTZ_CTRL_BOTH,    //同轴线和485线都发送控制命令
}SDK_PTZ_CTRL_TYPE;

typedef struct SDK_PTZControlMode
{
	int ctrlMode;			//云台控制的方式【PTZ_CTRL_TYPE 三个枚举值】
} SDK_PTZControlMode;

typedef struct SDK_PTZControlModeAll
{
	SDK_PTZControlMode CtrlModeAll[NET_MAX_CHANNUM];
}SDK_PTZControlModeAll;

typedef struct SDK_SmartH264Param
{
	bool SmartH264;
}SDK_SmartH264Param;

typedef struct SDK_SmartH264ParamAll
{
	 SDK_SmartH264Param SmartH264All[NET_MAX_CHANNUM];
}SDK_SmartH264ParamAll;

typedef struct SDK_WifiInfo
{
	char ssid[32];			//无线SSID信息
	char wifiVersion[32];	//无线模块的版本信息
	int advance;			//性能增强模式
}SDK_WifiInfo;

typedef struct SDK_NetRTMPConfig
{
	bool bEnable;			//是否开启
	char Directory[NET_MAX_PATH_LENGTH];	//RTMP的地址
}SDK_NetRTMPConfig;

///< 按间隔抓图
struct SDK_IntervalSnapMode
{
	int iFTPTime;
	int iEmailTime;
	int iStorageTime;
};
///< 按定时抓图
struct SDK_TriggerSnapMode
{
	SDK_SYSTEM_TIME TriggerTime;
	bool bFTP;
	bool bEmail;
	bool bStorage;
};
///< 抓图计划
struct SDK_SnapSchedule
{
	int iSnapType;			// 0:间隔抓图；1:定时抓图 2:关闭
	int iTriggerNum;		//定时抓图的个数
	SDK_IntervalSnapMode intervalMode;
	SDK_TriggerSnapMode vTriggerMode[256];
};

//所有通道的计划抓图配置
struct SDK_SnapConfigAll
{
	SDK_SnapSchedule vSnapScheduleAll[NET_MAX_CHANNUM];
};
//预置点数据配置
struct SDK_PtzPreset
{
	int nPresetId[256];
};
//所有通道的预置点数据配置
struct SDK_PtzPresetAll
{
	SDK_PtzPreset nPresetAll[NET_MAX_CHANNUM];
};

//预置点的数据配置
struct SDK_PtzTour_Preset
{
	int nPresetId;		//预置点Id
	int nPresetTime;	//间隔时间
};
//巡航路线的数据配置
struct SDK_PtzTour 
{
	int nTourId;		//线路Id
	SDK_PtzTour_Preset nTourNum[20];	//对应的所有预置点和时间间隔
};
//所有巡航的数据配置
struct SDK_PtzTours
{
	SDK_PtzTour nPtzTours[20];
};
//所有通道巡航的数据配置
struct SDK_PtzTourAll
{
	SDK_PtzTours vPtzTour[NET_MAX_CHANNUM];
};

///网络获取缩略图
typedef struct SDK_NetBreviaryPic
{
	int iChannel;  //通道号
	int iNumJpg; //请求获取的图片数
	SDK_SYSTEM_TIME startTime;
	SDK_SYSTEM_TIME endTime;
}SDK_NetBreviaryPic;

//智能回放定位的类型,掩码例如:1010—>IPC报警类型=1,断网报警=0,网络报警=1,本地报警=0
enum SDK_PLAY_BACK_SETTYPE
{
	F_SUB_COMMON,
	F_SUB_LOCALALARM, 	///< 本地报警
	F_SUB_NETALARM, 	///< 网络报警
	F_SUB_NETABORT, 	///< 断网报警
	F_SUB_IPCALARM, 	///< IPC报警
	F_SUB_SPEEDALARM, 	///< 超速报警
	F_SUB_GSENSORALARM, ///< SENSOR报警
	F_SUB_SERIALALARM, 	///< 串口报警
	F_SUB_MOTIONDETECT, ///< 移动侦测
	F_SUB_LOSSDETECT, 	///< 视频丢失
	F_SUB_BLINDDETECT, 	///< 视频遮挡
	F_SUB_PIRALARM, 	///< 红外检测
	F_SUB_CARDNUMBER, 	///< 卡号录像
	F_SUB_PERIMETER, 	///< 周界检测
	F_SUB_TRIPWIRE,		///< 单绊线检测
	F_SUB_ABANDUM, 		///< 物品遗留
	F_SUB_STOLEN, 		///< 物品被盗
	F_SUB_CHANGE, 		///< 场景变换
	F_SUB_NR,
};

//DDNS实时状态
typedef struct SDK_NetDDNSInConfig
{
	char IP[32];
	int state;      //state 0 表示未连接 1表示连接成功
	char resv[8];
}SDK_NetDDNSInConfig;

typedef struct SDK_IntelEnCodeCfg
{
	bool bEnable;			//接口使能销毁标志
	int highQP;				//高邋背景邋QP值
	int lowQP;				//前景邋QP值
	int highFPS;			//背景fps
	int lowFPS;				//前景fps
	int Channel;			//编码码流类型：0主，1辅
}SDK_IntelEnCodeCfg;

//智能编码
typedef struct SDK_IntelEnCodeCfgAll
{
	SDK_IntelEnCodeCfg vEncodeCfg[NET_MAX_CHANNUM];
}SDK_IntelEnCodeCfgAll;

//报警回调类型
enum {
	ALARM_TYPE = 1,
	PUSH_TYPE,
};

//ipc onvif搜索时自动修改ip为局域网ip
typedef struct SDK_IPAdaptiveCfg
{
	bool bIPAdaptive;	//IP自适应配置
}SDK_IPAdaptiveCfg;

//查询日历条件
typedef struct SDK_SearchCalendar
{
	int year;
	int month;
	int nFileType;			//文件类型, 见SDK_File_Type
}SDK_SearchCalendar;

//一个月内哪些天有符合要求的录像或图片
typedef struct SDK_SearchCalendarMask
{
	int mask;		//每位代表一天从低位开始，1:有录像, 0:无录像
}SDK_SearchCalendarMask;

typedef struct SDK_HardDiskInfo{
	bool	bIsCurrent;					///< 是否为当前工作盘
	unsigned int	uiTotalSpace;		///< 总容量，MB为单位
	unsigned int	uiRemainSpace;		///< 剩余容量，MB为单位
}SDK_HardDiskInfo;

typedef struct SDK_OemGetInfo
{
	int iConnectNum;					//连接数
	int iDisk;							//硬盘个数
	SDK_HardDiskInfo cHardDisk[SDK_MAX_DISK_PER_MACHINE];//硬盘剩余容量
	char cRecordState[NET_MAX_CHANNUM];	//录像状态
	char cVersion[64];					//版本信息
}SDK_OemGetInfo;

typedef enum {
	DEV_TYPE3_DOOR_CONTACT = 0,		//门磁
	DEV_TYPE3_INFRA = 1,			//红外
	DEV_TYPE3_SHOCK = 2,			//震动
	DEV_TYPE3_BROKEN_GLASS = 3,		//破碎
	DEV_TYPE3_SMOKE_SENSOR = 4,		//烟感
	DEV_TYPE3_GAS_SENSOR = 5,		//气感
	DEV_TYPE3_WATER_SENSOR = 6,		//漏水
	DEV_TYPE3_REMOTE_CONTROL = 7,	//遥控器
	DEV_TYPE3_ENVIRO_SENSOR = 8,	//温度
	DEV_TYPE3_NR,					//其他
}SDK_DEVICE_TYPE3;
typedef enum {
	DEFENCE_TYPE_24HOUR_STEAL = 0,	//24小时窃盗防区
	DEFENCE_TYPE_STOP,				//傍路
	DEFENCE_TYPE_FIRE,				//24小时火警防区
	DEFENCE_TYPE_SILENT,			//24小时无声劫盗防区
	DEFENCE_TYPE_VOICE,				//24小时有声劫盗防区
	DEFENCE_TYPE_INTIME_STEAL,		//延时窃盗防区
	DEFENCE_TYPE_DELAYED_STEAL,		//即时窃盗防区
	DEFENCE_TYPE_NR,
}SDK_DEFENCE_TYPE;

enum SDK_ConsumerProCmd 
{
	CONSUMER_PRO_ADD_DEV = 0,			///< 添加报警设备
	CONSUMER_PRO_STOP_ADD_DEV = 1,		///< 停止添加报警设备
	CONSUMER_PRO_DEL_DEV = 2,			///< 删除已经添加的报警设备
	CONSUMER_PRO_CHANGE_DEV_NAME = 3,	///< 修改已经添加设备的名称
	CONSUMER_PRO_INQUIRY_STATUS = 4,	///< 获取传感器的电量和状态
	CONSUMER_PRO_GET_DEV_LIST = 5,		///< 获取设备列表
	CONSUMER_PRO_CHANGE_DEV_STATUS = 6,	///< 修改传感器的状态 open or close
	CONSUMER_PRO_GET_DEVLIST_STATUS = 7,///< 获取已经在线的设备列表
	CONSUMER_PRO_CHANGE_MODE = 8,		///< 切换场景模式
	CONSUMER_PRO_GET_MODE_CFG = 9,		///< 获取对应模式的状态
	CONSUMER_PRO_GET_MODE_LIST = 10,	///< 获取模式列表
	CONSUMER_PRO_CHANGE_MODE_NAME = 11,	///< 修改模式名字
	CONSUMER_PRO_GET_LINK_STATE = 12,	///< 判断设备是否在线
	CONSUMER_PRO_NR						///< 命令个数
};

typedef struct SDK_ConsumerProOpr
{
	int  cmd;		//如枚举SDK_ConsumerProCmd
	char pArg1[20]; //设备的类型--SDK_DEVICE_TYPE3
	char pArg2[32]; //设备名称
	int  Channel;	//对应的设备通道
	int  nDefenceType;//防区类型
	char res[4];
}SDK_ConsumerProOpr;


//=================================================================================

//时间: 天
typedef struct SDK_DAY_TIME_S
{
	DWORD			week : 5;							//星期
	DWORD			millisec : 10;						//毫秒: 0 ~ 999
	DWORD			second : 6;							//秒:	0 ~ 59
	DWORD			minute : 6;							//分:   0 ~ 59
	DWORD			hour : 5;							//时:	0 ~ 23
}SDK_DAY_TIME; 


//时间: 时间段 
typedef struct SDK_SEG_TIME_S
{
	BYTE			bEnable;							//是否检测
	BYTE			byTask;								//任务
	BYTE			byRes[2];							//备用
	SDK_DAY_TIME		stBgnTime;							//开始时间
	SDK_DAY_TIME		stEndTime;							//结束时间
}SDK_SEG_TIME; 

//计划时间: 周计划时间
typedef struct SDK_SCHWEEK_TIME_S
{
	SDK_SEG_TIME		stSegTime[7][4];					//0: 星期天，1: 周一，2: 周二
}SDK_SCHWEEK_TIME;

//区域
typedef struct SDK_AREA_RECT_S
{
	short			x;									//X坐标
	short			y;									//Y坐标
	short			w;									//宽度
	short			h;									//高度
}SDK_AREA_RECT;


//====================================================================================
//=========================================================================
typedef struct SDK_FA_PICTURE_HEAD_S		
{
	WORD 	headflag;		//包头标志 0x4A50
	BYTE	tag;			//固定值0x01
	BYTE	frametype;		//帧类型 0x4A 表示图片
	BYTE	frameinfo;		//暂时保留
	BYTE	version;		//暂时保留
	WORD	messageid;		//消息ID
	WORD	width;			//暂时保留
	WORD	height;			//暂时保留
	unsigned int   ndatasize;		//暂时保留
	unsigned int   deviceid;		//用户用来区分设备ID
	unsigned int   channelid;		//用户用来区分通道ID
	unsigned int   streamid;		//用户用来区分图片流ID
	BYTE	picnumber[64];	//暂时保留
	BYTE	filename[64];	//图片name
	unsigned int   featureEn;
	unsigned int   nFeatureLen;
	unsigned int   nDevKeyId; 	//设备ID
	BYTE	res[84]; 		//扩展使用
	unsigned int   headend;		//结束标志
} __attribute__((packed, aligned(1))) SDK_FA_PICTURE_HEAD, *P_SDK_FA_PICTURE_HEAD;

#define FACE_ATTRIBUTE_FUN 1

/*人脸属性检测*/
typedef struct _FACE_ATTRIBUTE_S
{
	char byAge;      	//年龄 
	char byGender;	//性别
	char byGlasses; 	//眼镜  
	char byMask; 	//面具
	char byRace;		//种族  
	char byEye;		//眼睛 
	char byMouth;	//嘴巴
	char byBeard;	//胡子  
	char byEmotion;	//表情 
	char byAttractive; //魅力
	char bySmile;      //笑脸
	char byRes[21];
}FACE_ATTRIBUTE_S;

//人脸图片尺寸
typedef struct _FACEPIC_SIZE_S
{
	int X;
	int Y;
	int nWidth;
	int nHeight;
}FACEPIC_SIZE_S;

//人脸坐标
typedef struct _FACE_POSITION_S
{
	int left;
	int top;
	int right;
	int bottom;
}FACE_POSITION_S;


//图片属性3072字节
typedef struct _SDK_FACE_ATTR_S
{
	int nvisits;		//来访次数 用于比对机
	int nPicType;		//图片类型
	int nFaceQuality;	//质量分数
	int	nPicLen;		//图片大小
	int nPicID;			//图片计数
	int	nFaceID;		//人脸ID
	int nFaceOrHead;	//人脸和人头区分(1人头，2人脸)
	int  byIsScenePic;	//场景图标识（0：小图；1场景图） 
	FACE_ATTRIBUTE_S stFaceAttribute;//人脸属性
	FACEPIC_SIZE_S  stFacePicSize;	 //用于人脸抠图，原图不用
	FACE_POSITION_S stFacePosition; //人脸坐标位置
	char stFaceTime[32];			//抓拍时间
	char stDevUUID[32];				//设备UUID,用HK ID
	char stOsd[64];					//OSD信息
	char stContent[160];			//用于存放车牌或者wifi探针信息
	
	int  nFeatureType;				//特征值类型:0 float, 1 char ,2 int
	int  nFeatureLen;				//结合nFeatureType类型，特征值数组长度
	union{
		float	fFeature[512];
		char	cFeature[2048];
		int		nFeature[512];
	}facefeature;
	
	char sRes[632];					//预留

}SDK_FACE_ATTR;




//黑白名单
typedef struct SDK_FA_BLACKANDWHITELIST_CONFIG_S
{
	int					 byOutMode;			// 1 库文件索引; 2 图片
	int					 byWbMode;			// 1 黑名单; 2白名单
	int				 	 byAllNums;			// 实际库数目
	int				 	 byLibIndex;		//库索引
	int					 byFileIndex;		//文件索引
	int					 byDataSize;		//文件大小
	char				 byFileName[64];	//图片名
	int					 byErrorCode;		//错误码，参照XM_WB_ERROR_CODE
	int					 bySex;				//1--男 2--女
	int					 byDataType;		//特征值类型  0 float,1 char ,2 int
	unsigned char		 byRes[28];
}SDK_FA_BLACKANDWHITELIST_CONFIG;


//人脸识别参数
typedef struct  SDK_FA_SMART_FACE_S
{
	int 		nEnable;
	int 		nquality;
	BYTE 		nExposureMode;		//人脸曝光模式
	BYTE		nSnapMode;			//抓拍模式
	BYTE 		nTrackmode;			//人脸跟踪  		 0:关闭 1:过滤跟踪 2:非过滤跟踪
	BYTE        nFtpEnable;			//FTP上传开关	0:关闭 1:开启
	int 		nFaceSize;			//人脸识别最小尺寸(30~300)
	BYTE		nFaceBLC;
	BYTE		nPicMode;			//图片上传格式(0人脸；1原图；2人脸及原图)
	BYTE 		nParamCheckFlag;
	BYTE		byFaceAreaExpand;	//人脸周边区域扩展系数
	BYTE		byPicPrefixEnable;	//人脸图片自定义前缀使能
	char		szPicPrefix[16];	//人脸图片自定义前缀
	int			nTrackFrameNum;		//快速抓拍帧数-----快速抓拍
	BYTE		bySnapNum;			//最大抓拍次数-----离开后抓拍模式
	BYTE		byIntervalTime;		//间隔时间-----间隔抓拍，秒为单位
	BYTE		byFacePicQual;		//人脸图片编码质量
	BYTE		byFramePicQual;		//原图编码质量
	int			nIntervalFrame;		//间隔帧数---间隔抓拍，帧为单位
	BYTE 		byAttributeEnable; //人脸属性开关
	BYTE 		byIntervalSnapNum; //抓拍次数------间隔抓拍模式
	WORD 		wMaxFaceSize; //人脸识别最大像素
	int 		nGateIntervalFrame; //间隔帧数----闸机模式
	BYTE 		byRes[16]; //保留字节
}SDK_FA_SMART_FACE;



typedef struct  SDK_FA_SNAP_FACE_CONFIG_S   
{
	SDK_SCHWEEK_TIME	aTime;			//布防时间
	SDK_FA_SMART_FACE   sSmartFace;  
}SDK_FA_SNAP_FACE_CONFIG;


typedef struct SDK_FA_VI_DECTECT_S
{
	unsigned int		dwSize;			
	int					bEnable;
	SDK_AREA_RECT		stFaceMaskArea;
	BYTE				byRes[32];
}SDK_FA_VI_DECTECT;

typedef struct SDK_FA_ALGORITHM_Version_S
{
	char 		BaseVersion[64];	
	char 		ModeVersion[64];	
	BYTE				byRes[32];
}SDK_FA_ALGORITHM_Version;


//人脸报警   384字节
typedef struct SDK_SMART_ALARM_S
{
	BYTE			aEnable;		//报警开关
	BYTE			aBEnable;		//黑名单报警开关
	BYTE			aWEnable;		//白名单报警开关
	BYTE			aIoEnable;		//IO输出使能
	short			aIoTime;		//IO输出时间
	BYTE			aIoType;		//IO输出类型
	BYTE			aSimilarity;	//相似度 (0-100)
	SDK_SCHWEEK_TIME	aTime;			//布防时间
	BYTE		 	byRes[40];		
}SDK_SMART_ALARM;

//=========================================================================


//协议对黑白名单操作
typedef enum _WBLIST_ACTION_TYPE
{
	OUT_INDEX = 1,			//导出文件索引
	OUT_PICTURE,			//导出黑白名单库中单张图片
	OUT_PICTURE_COMP,		//比对后导出响应库图片
	OUT_PICTURE_DEL,		//删除库中单张图片
	OUT_PICTURE_DELALL,		//删除黑白名单所有库
	IN_PICTURE_ADD,			//通过导入图片添加一张黑白名单
	IN_PICTURE_ADD_SNAP,	//通过抓拍添加黑白名单
	IN_PICTURE_GET_FEATURE,	//通过导入一张图片获取特征值
	IN_INDEX_GET_FEATURE,   //通过库索引获取特征值
	OUT_WBLIST_EN
}WBLIST_ACTION_TYPE;


//黑白名单文件索引表信息结构体
typedef struct _index_info_s {
	int libindex;		//库编号
	int fileindex;		//图片索引编号	
}index_info_t;


typedef struct sdk_fileindex_info_s {
	index_info_t findex;
	int enable;					//是否使用
	char name[64];	//图片名字  //32=>64
	int checksum;				//检验码
}sdk_fileindex_info_t;


typedef struct SDK_FA_ImprotFaceImageInfoCallback_s
{
	unsigned int uiSessionId;		///< 会话ID
	int iRet;				///< 返回值
	char sName[64];		///< 配置名称
	char sFileName[64];		///< 之前导入的图片名称
}SDK_FA_ImprotFaceImageInfoCallback;


//错误码
typedef enum _XM_WB_ERROR_CODE
{
	WB_OK = 1,					//成功
	WB_FAILE = -1,				//失败
	WB_COLLECT_ERROR = -2,		//提取特征值失败
	WB_FILEINDEX_ERROR = -3,	//文件名字编号重复
	WB_LIB_FULL = -4,			//库满
	WB_ADD_TIME_OUT = -5,		//添加超时
	WB_PARA_ERROR	= -6,		//参数错误
	WB_FILE_BIG		= -7,		//文件太大
	WB_SPACE_ERROR	= -8,		//存储空间不足
	WB_FILE_OPEN_ERROR	= -9,	//文件打开失败
	WB_NO_DBFILE	= -10,		//没有数据库
	WB_FILE_ERROR	= -11,		//图片读取失败
	WB_DBFILE_BAD	= -12,		//数据库文件损坏
	WB_PIC_QUALITY_ERROR = -13, //图片质量差
	WB_FILE_WHSIZE_ERROR = -14,  // 图片尺寸错误，宽高不能为奇数
	WB_FILE_FACE_ERROR	 = -15,  //检测人脸失败（没检测到人脸或者检测到多人脸）	
	WB_PIC_FORMAT_ERROR = -16,   //图片格式错误 	
	WB_FACE_AREA_FAIL	=	-17, //人脸区域错误 	
	WB_FACE_HAND_ERROR	=	-18, //算法创建句柄错误 	
	WB_FACE_BUSY		=   -19, //设备忙 	
	WB_FILE_WRITE_ERROR	= 	-20,	//文件写入失败
}XM_WB_ERROR_CODE;



typedef enum _XM_WB_WBLIST_RESULT_S
{
	WBLIST_OK = 100,
	WBLIST_FAILE = 160, 			//失败
	WBLIST_COLLECT_ERROR = 161, 	//提取特征值失败
	WBLIST_FILEINDEX_ERROR = 162,	//文件名字编号重复
	WBLIST_LIB_FULL = 163,			//库满
	WBLIST_ADD_TIME_OUT = 164,		//添加超时
	WBLIST_PARA_ERROR	= 165,		//参数错误
	WBLIST_FILE_BIG 	= 166,		//文件太大
	WBLIST_SPACE_ERROR	= 167,		//存储空间不足
	WBLIST_FILE_OPEN_ERROR	= 168,		//文件打开失败
	WBLIST_NO_DATABASE = 169,		//没有数据库
	WBLIST_FILE_READ_ERROR = 170,	//图片读取失败
	WBLIST_DATABASE_ERROR = 171,	//数据库损坏
	WBLIST_PIC_QUALITY_ERROR = 172, //图片质量差

}XM_WB_WBLIST_RESULT;

// add by barney 20180919
typedef struct _sdk_compinfo_flag
{
	int 			iCaptureEn; // 设置相机发送抓拍图使能
	int 			iLibPicEn; // 设置相机发送底库图使能
	int 			iAlarmEn; // 设置相机发送报警事件使能（预留）
	int 			iFeatureEn; // 设置相机发送人脸特征值使能
}SDK_COMPINFO_FLAG;


//比对结果
typedef struct SDK_FACECOMPARE_RESULT_S		
{
	unsigned int	deviceid;
	unsigned int	channelid;
	unsigned int	streamid;
	unsigned int	wbmode; 		//黑白名单
	unsigned int	libindex;		//黑白名单库索引
	unsigned int	libnumber;		//黑白名单库里编号
	char	picnameComp[64];	//实时比对图片名字
	char	*pCompImgData;			// 图片数据指针
	int		iCompImgSize;		// 图片数据长度
	char	picnameSnap[64];	//实时抓拍图片名字
	char	*pSnapImgData;			// 图片数据指针
	int		iSnapImgSize;		// 图片数据长度

	float			result; 		//比对结果
	unsigned char	SnapTime[32];	////抓拍时间
	unsigned char	byRes[64];

	unsigned int	guest;			//客流统计
	unsigned int	Age;			//年龄 
	unsigned int	Gender; 		//性别
	unsigned int	Glasses;		//眼镜	
	unsigned int	Mask;			//面具
	unsigned int	Race;			//种族	
	unsigned int	Eye;			//眼睛	
	unsigned int	Attractive; 	//魅力值 	
	unsigned int	Beard;			// 胡须
	unsigned int	Emotion;		// 表情
	unsigned char	ByRes[117]; 	//预留

	int 			facealarm;		//人脸报警 , 预留
	float			facecharacter[128];
}SDK_FACECOMPARE_RESULT;  


//==========================================================================




// 数据上传通道回调函数原型
typedef void (*fUploadDataCallBack) (long lLoginID, long UploadType, char *pBuffer, unsigned long dwBufSize, unsigned long dwUser);

// 透明串口回调函数原形
typedef void (*fTransComCallBack) (long lLoginID, long lTransComType, char *pBuffer, unsigned long dwBufSize, unsigned long dwUser);
//服务器断开回调原形
typedef void (*fDisConnect)(long lLoginID, char *pchDVRIP, long nDVRPort, unsigned long dwUser);
//原始数据回调原形
typedef int(*fRealDataCallBack) (long lRealHandle, long dwDataType, unsigned char *pBuffer,long lbufsize,long dwUser);
typedef int(*fRealDataCallBack_V2) (long lRealHandle, const PACKET_INFO_EX *pFrame, long dwUser);

// 回放录像进度回调原形
typedef void(*fDownLoadPosCallBack) (long lPlayHandle, long lTotalSize, long lDownLoadSize, long dwUser);

//消息（报警,主动注册）回调原形
/*
	1.报警,pBuf说明--ntype = ALARM_TYPE
	SDK_AlarmInfo alarmInfo;
	memcpy ( &alarmInfo, pBuf, dwBufLen );
	2.主动注册,pBuf说明,
	VIDEONET_ACTIVEREG_INFO activeInfo;
	memcpy ( &activeInfo, pBuf, dwBufLen );
	3.图片推送,pBuf说明--nType=PUSH_TYPE
	SDK_PushRetData PushDetect;
	memcpy(&PushDetect, pBuf, sizeof(SDK_PushRetData));
	
*/
typedef bool (*fMessCallBack)(long lLoginID, char *pBuf, unsigned long dwBufLen, long dwUser, int nType);

//升级设备程序回调原形
/*
	nSendSize = -1 说明升级完成  
	nSendSize = -2 说明升级出错
	nTotalSize = -1时, nSendSize:1-99返回升级进度 
	nTotalSize =0时,nSendSize = VIDEONET_NOENOUGH_MEMORY-VIDEONET_INVALID_WIFI_DRIVE 升级错误具体码
	其他就是发送进度
	云升级增加了这一步:nTotalSize=-2时，nSendSize:0 - 100=下载进度,没有发送进度
*/
typedef void(*fUpgradeCallBack) (long lLoginID, long lUpgradechannel,
                                             int nTotalSize, int nSendSize, long dwUser);


// 语音对讲的音频数据回调函数原形
typedef void (*pfAudioDataCallBack)(long lVoiceHandle, char *pDataBuf,
                                                long dwBufSize, char byAudioFlag, long dwUser);


//本地播放结束回调原形
typedef void (*fLocalPlayFileCallBack)(long lPlayHand, long nUser);

//信息帧回调设置
typedef void (*InfoFramCallBack)(long lPlayHand, long nType, char *pBuf,long nSize, long nUser);

//子连接断线回调
typedef void (*fSubDisConnectCallBack)(long lLoginID, SubConnType type, long nChannel, long dwUser);

typedef void (* fPlayDrawCallBack)(long lPlayHand,void* hDc,long nUser);

/*
lSubFaceHandle：数据提供者句柄
pBuffer：图片数据缓存
lbufsize；图片数据长度
pPictureHead；图片信息结构体指针
dwUser；用户数据
*/
typedef int(*fFaceImageDataCallBack) (long lSubFaceHandle, char *pBuffer,long lbufsize,SDK_FA_PICTURE_HEAD *pPictureHead, SDK_FACE_ATTR* pPictureAttr, long dwUser);

typedef int(*fFaceCompaeResultCallBack) (long lSubFaceHandle, char *pBuffer,long lbufsize,long dwUser);

typedef int(*fFaceBlackAndWhiteListCallBack) (long lSubFaceHandle, char *pBuffer,long lbufsize,SDK_FA_BLACKANDWHITELIST_CONFIG *pConfig,long dwUser);


/*
	描述:SDK初始化
	参数:
		cbDisConnect[out]:断线回调函数
		dwUser[in]:回调函数参数
	返回值:
		=1: 成功
		<=0:失败
*/
long VideoNet_Init(fDisConnect cbDisConnect, unsigned long dwUser);

/*
	描述:SDK退出清理
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_Cleanup();

/*
	描述:获取错误信息
	返回值:
		错误码	
*/
long VideoNet_GetLastError();

/*
	描述:设置登录设备超时时间和尝试次数
	参数:	
		nWaitTime[in]:单位ms不设置时默认5000ms,
		nTryTimes[in]:次数,不设置时默认3次
*/

bool VideoNet_SetConnectTime(long nWaitTime, long nTryTimes);


/*
	描述:登陆设备
	参数:
		sDVRIP[in]:		  ip
		wDVRPort[in]:	  端口
		sUserName[in]:    用户名
		sPassword[in]:    密码
		lpDeviceInfo[out]:返回设备信息
		error[out]:		  返回登陆错误码
		socketType[in]:	  登陆方式
	返回值:
		>0:	   成功,从1开始到n,每次登录一台设备返回值+1
		=0:	   失败
*/
long VideoNet_Login(char *sDVRIP, unsigned short wDVRPort, char *sUserName, char *sPassword,
                                             LPVIDEONET_DEVICEINFO lpDeviceInfo,int *error,int socketType=0);
/*
	描述:P2P方式登陆设备
	参数:
		puuid[in]:		  设备序列号
		wDVRPort[in]:	  端口,这里不是要链接的设备的端口，而是本地需要映射出去的端口号,如果填0系统会自动分配
		sUserName[in]:    用户名
		sPassword[in]:    密码
		lpDeviceInfo[out]:返回设备信息
		error[out]:		  返回登陆错误码
		socketType[in]:	  登陆方式
	返回值:
		>0:	   成功,从1开始到n,每次登录一台设备返回值+1
		=0:	   失败
*/
long VideoNet_Login_P2P(char *puuid, unsigned short wDVRPort, char *sUserName, char *sPassword,
                                            LPVIDEONET_DEVICEINFO lpDeviceInfo,int *error,int socketType=0);

/*
	描述:向设备注销，登出设备
	参数:
		lLoginID[in]:登陆句柄
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_Logout(long lLoginID);

/*
	描述:设置接收DVR信息回调, 例如报警信息,以ID号区分
	参数:
		cbAlarmcallback[out]:回调函数
		lUser[in]:			 回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SetDVRMessCallBack(fMessCallBack cbAlarmcallback, unsigned long lUser);

/*
	描述:建立报警上传通道
	参数:
		lLoginID[in]:登陆句柄
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_SetupAlarmChan(long lLoginID);

/*
	描述:关闭报警上报
	参数:
		lLoginID[in]:登陆句柄
	返回值:
		=1:成功
		=0:失败
*/
bool VideoNet_CloseAlarmChan(long lLoginID);

/*
	描述:远程获取配置参数
	参数:
		lLoginID[in]:	     登陆句柄
		dwCommand[in]:		 控制命令,见enum SDK_CONFIG_TYPE
		nChannelNO[in]:		 -1代表全通道,0-n代表单个通道
		lpOutBuffer[out]:	 接收缓冲
		dwOutBufferSize[in]: 接收缓冲大小
		lpBytesReturned[out]:返回的数据大小
		waittime[in]:		 等待时间 
	返回值:
		=1:成功
		<0:失败
*/
long VideoNet_GetDevConfig(long lLoginID, unsigned long dwCommand, int nChannelNO, char * lpOutBuffer, unsigned long dwOutBufferSize, unsigned long* lpBytesReturned,int waittime=1000);

/*
	描述:远程设置配置参数
	参数:
		lLoginID[in]:	     登陆句柄
		dwCommand[in]:		 控制命令,见enum SDK_CONFIG_TYPE
		nChannelNO[in]:		 -1代表全通道,0-n代表单个通道
		lpInBuffer[out]:	 输入缓冲
		dwInBufferSize[in]:  输入缓冲大小
		waittime[in]:		 等待时间 
	返回值:
		=1:成功
		<0:失败
*/
long VideoNet_SetDevConfig(long lLoginID, unsigned long dwCommand, int nChannelNO, char * lpInBuffer, unsigned long dwInBufferSize, int waittime=1000);

/*
	描述:跨网段设置设备配置，目前只支持对网络配置进行设置 
	参数:
		dwCommand[in]:	   E_SDK_CONFIG_SYSNET
		nChannelNO[in]:	   1临时保存,其他为永久保存
		lpInBuffer[in]:	   SDK_CONFIG_NET_COMMON_V3结构体地址
		dwInBufferSize[in]:sizeof(SDK_CONFIG_NET_COMMON_V3)
		waittime[in]:	   等待时间
	返回值:
		=0:成功
		<0:失败
*/
long VideoNet_SetConfigOverNet(unsigned long dwCommand, int nChannelNO, char * lpInBuffer, unsigned long dwInBufferSize, int waittime=1000);

/*
	描述:日志查询
	参数:
		lLoginID[in]:登陆句柄
		pFindParam[in]:查询条件
		pRetBuffer[out]:日志返回信息
		lBufSize[in]:接收日志信息大小
		waittime:等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_FindDVRLog(long lLoginID, SDK_LogSearchCondition *pFindParam, SDK_LogList *pRetBuffer, long lBufSize, int waittime=2000);

/*
	描述:打开实时预览
	参数:
		lLoginID[in]:	 登陆句柄
		lpClientInfo[in]:播放信息
	返回值:
		>0或<0:成功，预览播放句柄
		=0:失败,经常出现的错误码分析例如-11202见文档
*/
long VideoNet_RealPlay(long lLoginID, LPVIDEONET_CLIENTINFO lpClientInfo);

/*
	描述:停止实时预览
	参数:
		lRealHandle[in]: 预览播放句柄
		lpClientInfo[in]:播放信息
	返回值:
		>0或<0:成功
		=0:失败
*/
bool VideoNet_StopRealPlay(long lRealHandle,void*hWnd=NULL);

/*
	描述:控制实时预览
	参数:
		lRealHandle[in]:预览播放句柄
		bPause[in]:	    暂停或继续 1-暂停 0-继续
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_PauseRealPlay(long lRealHandle, bool bPause);

/*
	描述:设置数据回调
	参数:
		lRealHandle[in]:预览播放句柄
		cbRealData[out]:实时数据回调
		dwUser[in]:		回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SetRealDataCallBack(long lRealHandle,fRealDataCallBack cbRealData, long dwUser);

/*
	描述:数据经过码流分析过，带有帧的具体信息,其他与VIDEONET_SetRealDataCallBack相同
*/
bool VideoNet_SetRealDataCallBack_V2(long lRealHandle,fRealDataCallBack_V2 cbRealData, long dwUser);

/*
	描述:清除回调函数,该函数需要在VIDEONET_StopRealPlay前调用
	参数:
		lRealHandle[in]:预览播放句柄
		cbRealData[in]: 实时回调函数
		dwUser[in]:	    实时回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_DelRealDataCallBack(long lRealHandle,fRealDataCallBack cbRealData, long dwUser);

/*
	描述:清除回调函数V2版本
	参数:
		lRealHandle[in]:预览播放句柄
		cbRealData[in]: 实时回调函数V2版本
		dwUser[in]:	    实时回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_DelRealDataCallBack_V2(long lRealHandle,fRealDataCallBack_V2 cbRealData, long dwUser);

/*
	描述:按文件名查询录像
	参数:
		lLoginID[in]:登陆句柄
		lpFindInfo[in]:查询条件
		lpFileData[out]:查询结果
		lMaxCount[in]:查询的最大录像数量
		findcount[out]:查询到的录像数量
		waittime[in]:等待时间
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_FindFile(long lLoginID, VIDEONET_FINDINFO* lpFindInfo, VIDEONET_FILE_DATA *lpFileData, int lMaxCount, int *findcount, int waittime=5000);

/*
	描述:按时间查询录像文件
	参数:
		lLoginID[in]:登陆句柄
		lpFindInfo[in]:查询条件
		lpFileData[out]:查询结果
		waittime[in]:等待时间
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_FindFileByTime(long lLoginID, SDK_SearchByTime* lpFindInfo, SDK_SearchByTimeResult *lpFileData, int waittime=10000);

/*
	描述:按文件名回放录像
	参数:
		lLoginID[in]:	   登陆句柄
		sPlayBackFile[in]: 回放的文件参数
		cbDownLoadPos[out]:进度回调，用户通知用户设备是否已经将数据发送完毕，回调中的lDownLoadSize=-1代表数据发送完毕
						   客户如果想实时显示进度，应该从码流里面获取时间来计算网络部分不分析码流，如果以当前接收数据大小/总大小来计算进度的话不是很准，应该以当前时间，根据开始时间和结束时间来计算进度
		fDownLoadDataCallBack[out]:回放数据回调
		dwDataUser[in]:			   数据回调参数
	返回值:
		>0或<0:成功
		=0:	   失败
*/
long VideoNet_PlayBackByName(long lLoginID, VIDEONET_FILE_DATA *sPlayBackFile, fDownLoadPosCallBack cbDownLoadPos, fRealDataCallBack fDownLoadDataCallBack, long dwDataUser);

/*
	描述:按文件名回放录像
	参数:
		lLoginID[in]:	   登陆句柄
		sPlayBackFile[in]: 回放的文件参数
		cbDownLoadPos[out]:进度回调，用户通知用户设备是否已经将数据发送完毕，回调中的lDownLoadSize=-1代表数据发送完毕
						   客户如果想实时显示进度，应该从码流里面获取时间来计算网络部分不分析码流，如果以当前接收数据大小/总大小来计算进度的话不是很准，应该以当前时间，根据开始时间和结束时间来计算进度
		fDownLoadDataCallBack[out]:回放数据回调,数据经过码流分析
		dwDataUser[in]:			   数据回调参数
	返回值:
		>0或<0:成功
		=0:	   失败
*/
long VideoNet_PlayBackByName_V2(long lLoginID, VIDEONET_FILE_DATA *sPlayBackFile, fDownLoadPosCallBack cbDownLoadPos, fRealDataCallBack_V2 fDownLoadDataCallBack, long dwDataUser);

/*
	描述:按时间回放录像
	参数:
		lLoginID[in]:      登陆句柄
		lpFindInfo[in]:    查询录像条件
		cbDownLoadPos[out]:进度回调，用户通知用户设备是否已经将数据发送完毕，回调中的lDownLoadSize=-1代表数据发送完毕
		fDownLoadDataCallBack[out]:回放数据回调
		dwDataUser[in]:			   数据回调参数
	返回值:
		>0或<0:成功
		=0:	   失败
*/
long VideoNet_PlayBackByTime(long lLoginID, VIDEONET_FINDINFO* lpFindInfo, fDownLoadPosCallBack cbDownLoadPos, fRealDataCallBack fDownLoadDataCallBack, long dwDataUser);

/*
	描述:按时间回放录像Ex,进度回调和数据回调用不同的回调参数,其他与VIDEONET_PlayBackByTime相同
	
*/
long VideoNet_PlayBackByTimeEx(long lLoginID, VIDEONET_FINDINFO* lpFindInfo,fRealDataCallBack fDownLoadDataCallBack, long dwDataUser,
											fDownLoadPosCallBack cbDownLoadPos, long dwPosUser);
/*
	描述:fDownLoadDataCallBack数据回调出来的数据的码流分析过，其他与VIDEONET_PlayBackByTimeEx相同
*/
long VideoNet_PlayBackByTime_V2(long lLoginID, VIDEONET_FINDINFO* lpFindInfo,fRealDataCallBack_V2 fDownLoadDataCallBack, long dwDataUser,
											fDownLoadPosCallBack cbDownLoadPos, long dwPosUser);

/*
	描述:停止录像回放
	参数:
		lPlayHandle[in]:回放句柄
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_StopPlayBack(long lPlayHandle);

/*
	描述:回放控制
	参数:
		lPlayHandle[in]:回放句柄
		lControlCode[in]:控制命令,见enum SDK_PlayBackAction
		lCtrlValue[in]:控制值
		itype[in]:类型--仅智能回放定位才有效,各类型的掩码--见enum SDK_PLAY_BACK_SETTYPE
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_PlayBackControl(long lPlayHandle, long lControlCode,long lCtrlValue, int itype=0);

/*
	描述:按文件名下载,用户可以不使用回调，自己通过VIDEONET_GetDownloadPos获取进度
	参数:
		lLoginID[in]:	    登陆句柄
		sPlayBackFile[in]:  下载的录像信息
		sSavedFileName[in]: 保存的文件路径
		cbDownLoadPos[out]:下载进度回调
		dwDataUser[in]:    回调函数参数
		fDownLoadDataCallBack[out]:数据回调
	返回值:
		<0或>0:成功
		=0:	   失败
*/
long VideoNet_GetFileByName(long lLoginID,VIDEONET_FILE_DATA *sPlayBackFile,char *sSavedFileName,
                                                     fDownLoadPosCallBack cbDownLoadPos=NULL, long dwDataUser=0,fRealDataCallBack fDownLoadDataCallBack=NULL);

/*
	描述:按文件名下载V2版本,数据回调是经过码流分析过,其他与VIDEONET_GetFileByName相同
*/
long VideoNet_GetFileByName_V2(long lLoginID,VIDEONET_FILE_DATA *sPlayBackFile,char *sSavedFileName,
													 fDownLoadPosCallBack cbDownLoadPos=NULL, long dwDataUser=0,fRealDataCallBack_V2 fDownLoadDataCallBack_V2=NULL);

/*
	描述:按时间下载V2版本
	参数:
		lLoginID[in]:			  登陆句柄
		lpFindInfo[in]:           录像查询条件
		sSavedFileDIR[in]:		  录像文件保存路径
		bMerge[in]:				  文件是否合并
		cbDownLoadPos[out]:		  进度回调,用户通知用户设备是否已经将数据发送完毕，回调中的lDownLoadSize=-1代表数据发送完毕
		dwDataUser[in]:			  回调函数参数
		fDownLoadDataCallBack[in]:数据回调
	返回值:
		>0或<0:成功
		=0:失败
*/
long VideoNet_GetFileByTime(long lLoginID, VIDEONET_FINDINFO* lpFindInfo, char *sSavedFileDIR, bool bMerge = 0,
                                                     fDownLoadPosCallBack cbDownLoadPos=NULL, long dwDataUser=0,fRealDataCallBack fDownLoadDataCallBack=NULL);

/*
	描述:数据回调出来的数据的码流分析过,其他与VIDEONET_GetFileByTime相同
*/
long VideoNet_GetFileByTime_V2(long lLoginID, VIDEONET_FINDINFO* lpFindInfo, char *sSavedFileDIR, bool bMerge
														,fDownLoadPosCallBack cbDownLoadPos=NULL,long dwDataUser=0,fRealDataCallBack_V2 fDownLoadDataCallBack_V2=NULL);

/*
	描述:停止下载文件
	参数:
		lFileHandle[in]:下载文件句柄
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_StopGetFile(long lFileHandle);


/*
	描述:下载控制
	参数:
		lPlayHandle[in]: 下载句柄
		lControlCode[in]:控制命令,见enum SDK_PlayBackAction
		bDown[in]:		 是否位下载，默认为1
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_GetFileControl(long lPlayHandle, long lControlCode, bool bDown=1);

/*
	描述:获取下载进度
	参数:
		lFileHandle[in]:下载句柄
	返回值:
		>=0:下载进度
		<0:	失败
*/
int VideoNet_GetDownloadPos(long lFileHandle);

/* 
	描述:本地升级
	参数:
		lLoginID[in]: 登陆句柄
		sFileName[in]:升级文件路径
		nType[in]:	  升级类型,1-开始升级 0-终止升级
		cbUpgrade[in]:升级进度回调
		dwUser[in]:	  回调函数参数
	返回值:
		>0或<0: 成功
		=0:		失败
*/
long VideoNet_Upgrade(long lLoginID, char *sFileName, int nType=0, fUpgradeCallBack cbUpgrade=NULL, long dwUser=0);

/*
	描述:得到升级状态
	参数:
		lUpgradeHandle[in]:升级句柄
	返回值:
		1:成功
		2:正在升级
		3:失败
*/
int VideoNet_GetUpgradeState(long lUpgradeHandle);

/* 
	描述:云台控制
	参数:
		lLoginID[in]:	登陆句柄
		nChannelNo[in]:	通道号
		lPTZCommand[in]:控制命令，见enum PTZ_ControlType
		bStop[in]:		是否是停止，0为打开，1为停止
		lSpeed[in]:		速度
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_PTZControl(long lLoginID,int nChannelNo, long lPTZCommand, bool bStop = 0, long lSpeed=4);

/*
	描述:1、设置，删除，转到预置点时：lParam1为预置点值
		 2、加入预置点到巡航，删除巡航中预置点时：lParam1为巡航线路值，lParam2为预置点值,lParam3为时间间隔
		 3、开始巡航，停止巡航，清除巡航线路时：lParam1为巡航线路值
		 4、云台方向设置时：lParam1为水平步长，lParam2为垂直步长
		 5、左边界设置，右边界设置，自动扫线功能：
	参数:
		lLoginID[in]:	登陆句柄
		nChannelNo[in]:	通道号
		lPTZCommand[in]:控制命令，见enum PTZ_ControlType
		lParam1[in]:	参数1
		lParam2[in]:	参数2
		lParam3[in]:	参数3
		bStop[in]:		是否是停止，0为打开，1为停止
	返回值:
		true: 成功
		false:失败
 */
bool VideoNet_PTZControlEx(long lLoginID,int nChannelNo, long lPTZCommand,
                                                    long lParam1, long lParam2, long lParam3, bool bStop=0);

/*
	描述:设备控制 
	参数:
		lLoginID[in]:登陆句柄
		type[in]:	 控制类型,0 重启设备，1 清除日志 2 关机 3.恢复记录日志 4.停止记录日志
		waittime[in]:等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_ControlDVR(long lLoginID, int type, int waittime=2000);
	
/*
	描述:搜索局域网内的设备 
	参数:
		szBuf[out]:		接收缓冲
		nBufLen[in]:	接收缓冲大小,sizeof(SDK_CONFIG_NET_COMMON_V2)*n
		pRetLen[in]:	返回的大小
		nSearchTime[in]:等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SearchDevice(char* szBuf, int nBufLen, int* pRetLen, int nSearchTime);

bool VideoNet_SearchDevice_IPV6(char* szBuf, int nBufLen, int* pRetLen, int nSearchTime, int ntype);

typedef  void (*pfSearchDeviceCallBack)(SDK_CONFIG_NET_COMMON_V2  *pNetCom , unsigned long userData);
//
/*
	描述:搜索局域网内的设备,搜索局域网内的设备V2版本
	参数:
		pfNetCom[out]:	回调函数
		userData[in]:	回调参数
		nSearchTime[in]:等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SearchDevice_V2(pfSearchDeviceCallBack pfNetCom,unsigned long userData, int nSearchTime);

/*
	描述:开始对讲
	参数:
		lLoginID[in]:  登陆句柄
		pVcb[out]:	   接收对讲数据回调	
		dwDataUser[in]:回调函数参数
	返回值:
		>0或<0: 成功
		=0:		失败
*/
long VideoNet_StartVoiceCom_MR(long lLoginID, pfAudioDataCallBack pVcb, long dwDataUser);

/*
	描述:发送对讲数据
	参数:
		lVoiceHandle[in]:对讲句柄
		pSendBuf[in]:	 对讲数据
		lBufSize[in]:	 对讲数据大小
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_VoiceComSendData(long lVoiceHandle, char *pSendBuf, long lBufSize);

/*
	描述:停止对讲
	参数:
		lVoiceHandle[in]:对讲句柄
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_StopVoiceCom(long lVoiceHandle);

/*	
	描述:设置对讲音频编码方式，用户可以不设置，默认为G711A编码
	参数:
		lLoginID[in]:  登陆句柄
		pTalkMode[in]: 通道号,-1代表全通道，0-n代表单个通道
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SetTalkMode(long lLoginID, SDK_AudioInFormatConfig* pTalkMode);

/*	
	描述:设置录像模式
	参数:
		lLoginID[in]:  登陆句柄
		nChannelNo[in]: 通道号,-1代表全通道，0-n代表单个通道
		lRecordType[in]:录像模式,见enum SDK_RecordModeTypes
	返回值:
		true: 成功
		false:失败
*/ 
bool VideoNet_StartDVRRecord(long lLoginID, int nChannelNo ,long lRecordType);

/*	
	描述:关闭录像
	参数:
		lLoginID[in]:  登陆句柄
		nChannelNo[in]: 通道号,-1代表全通道，0-n代表单个通道
	返回值:
		true: 成功
		false:失败
*/ 
bool VideoNet_StopDVRRecord(long lLoginID, int nChannelNo);

/*	
	描述:设置设备系统时间
	参数:
		lLoginID[in]:登陆句柄
		pSysTime[in]:时间
		nType[in]:系统时间类型(true-新的系统时间)
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SetSystemDateTime(long lLoginID, SDK_SYSTEM_TIME *pSysTime, bool nType=0);

/*	
	描述:得到设备的工作状态
	参数:
		lLoginID[in]:   登陆句柄
		pWorkState[out]:设备的工作状态
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_GetDVRWorkState(long lLoginID, SDK_DVR_WORKSTATE *pWorkState);

/*	
	描述:对硬盘进行分区,格式化等等操作
	参数:
		lLoginID[in]:   登陆句柄
		pStorageCtl[in]:操作参数
	返回值:
		=1: 成功
		<=0:失败
*/
int VideoNet_StorageManage(long lLoginID, SDK_StorageDeviceControl *pStorageCtl);

/*
	描述:发送网络报警信息
	参数:
		lLoginID[in]:  登陆句柄
		pAlarmInfo[in]:网络报警参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SendNetAlarmMsg(long lLoginID, SDK_NetAlarmInfo *pAlarmInfo);

/*
	描述:设备端抓图,即抓设备端发过来的即时的一张图片的内存buf
		1.需要设备配置里面有抓图配置选项该接口才有效
		2.如果满足1，默认抓出来的分辨率是D1，如果想抓跟视频分辨率一样的图片，就需要修改编码设置里的抓图分辨率，
		  如果编码设置没有抓图分辨率选项，则需要定制支持该项的程序
    参数:
		lLoginID[in]: 登陆句柄
		nChannel[in]: 通道号
		sFileName[in]:保存路径
		nType[in]:图片类型默认为jpg, 0:jpg 1:YUV
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_CatchPic(long lLoginID, int nChannel, char *sFileName, int nType=0);

/*
	描述:设备端抓图,即抓设备端发过来的即时的一张图片的内存buf，外部生成文件
		1.需要设备配置里面有抓图配置选项该接口才有效
		2.如果满足1，默认抓出来的分辨率是D1，如果想抓跟视频分辨率一样的图片，就需要修改编码设置里的抓图分辨率，
		  如果编码设置没有抓图分辨率选项，则需要定制支持该项的程序
    参数:
		lLoginID[in]:登陆句柄
		nChannel[in]:通道号
		pBuffer[out]:接收缓冲
		nBufLen[in]:接收缓冲的大小
		pPicLen[in]:实际返回的大小
		nType[in]:图片类型默认为jpg, 0:jpg 1:YUV
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_CatchPicInBuffer(long lLoginID, int nChannel, char *pBuffer, int nBufLen, int *pPicLen, int nType=0);

/*
	描述:通过串口向设备写数据
	参数:
		lLoginID[in]:登陆句柄
		nType[in]:	 串口类型
		pBuffer[in]: 数据
		nBufLen[in]: 数据长度
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SerialWrite(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen);

/*
	描述:通过串口从设备读数据
	参数:
		lLoginID[in]: 登陆句柄
		nType[in]:	  串口类型
		pBuffer[out]: 接收数据
		nBufLen[in]:  接收数据长度
		pReadLen[out]:收到的数据长度
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SerialRead(long lLoginID, SERIAL_TYPE nType, char *pBuffer, int nBufLen, int *pReadLen);

/*
	描述:强制I帧
	参数:
		lLoginID[in]:登陆句柄
		nChannel[in]:通道号
		nStream[in]: 码流类型,0表示主码流，为1表示子码流
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_MakeKeyFrame(long lLoginID, int nChannel, int nStream);

/*
	描述:创建透明串口通道
	参数:
		lLoginID[in]:	 登陆句柄
		TransInfo[in]:	 透明串口参数
		cbTransCom[out]: 设备数据回调
		lUser[in]:		 回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_OpenTransComChannel(long lLoginID, TransComChannel *TransInfo, fTransComCallBack cbTransCom, unsigned long lUser);

/*
	描述:关闭透明串口通道
	参数:
		lLoginID[in]:	 登陆句柄
		nType[in]:		 透明串口类型
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_CloseTransComChannel(long lLoginID, SERIAL_TYPE nType);
//获取状态信息
bool VideoNet_GetDeviceState(long lLoginID, SDK_State_Type type, char *pState);

/*
	描述:获取本地ui图片
	参数:
		lLoginID[in]:	 登陆句柄
		saveFileName[in]:图片保存路径
		type[in]:		 保存图片类型,1:为全图片 2:活动区域图片
*/
bool VideoNet_CatchPicUI(long lLoginID,char *saveFileName,int type=1);
/*
	描述:设置本地ip,socket通信套接字绑定的ip
	参数:
		szIP[in]:ip
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SetLocalBindAddress(char*szIP);

/*
	描述:开启上报数据,包括车载信息经纬度/录像状态/数字通道连接状态/通道标题
	参数:
		lLoginID[in]:登陆句柄
		upLoadType[in]:上报数据类型
		callBack[out]:上报数据回调
		lUser[in]:回调函数参数
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_StartUploadData(long lLoginID,UploadDataType upLoadType,fUploadDataCallBack callBack,long lUser);

/*
	描述:停止上报数据
	参数:
		lLoginID[in]:登陆句柄
		upLoadType[in]:上报数据类型
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_StopUploadData(long lLoginID,UploadDataType upLoadType);

/*
	描述:开始主动注册
	参数:
		nPort[in]:监听端口号,0<=nPort<=65535
		cbFunc[out]: 注册上线回调函数
		dwDataUser[in]:回调函数参数
	返回值:
		true:成功
		false:失败
*/
bool VideoNet_StartActiveRigister(int nPort, fMessCallBack cbFunc, unsigned long dwDataUser);

/*
	描述:关闭主动注册
	返回值:
		true:成功
		false:失败
*/
bool VideoNet_StopActiveRigister();

/*
	描述:检测子连接异常断开
	参数:
		callBack[out]:子连接断开回调
		userData[in]: 回调函数参数
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_SetSubDisconnectCallBack(fSubDisConnectCallBack callBack,DWORD userData);

/*
	描述:设置保活时间,perKeeplifeTime(心跳间隔):默认10秒,detectDisconTime(断线检测时间):默认60秒
	参数:
		lLoginID[in]:	     登陆句柄
		perKeeplifeTime[in]: 保活时间
		detectDisconTime[in]:断线检测时间
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_SetKeepLifeTime(long lLoginID,unsigned int perKeeplifeTime,unsigned int detectDisconTime);

/*
	描述:MAC是否得到加密
	参数:
		pMac[in]:MAC地址
	返回值:
		true: 加密
		false:没有加密
*/
bool VideoNet_CheckEncrypt(char *pMac);

/*
	描述:设备搜索到的设备，与设备在同一个局域网的设备,设备去搜索，然后返回结果(VIDEONET_SearchDevice这个接口是sdk本身去搜索,两者返回的结果是一致的)
	参数:
		lLoginID[in]:		 登陆句柄
		pDevlist[out]:		 设备列表
		transferProtocol[in]:传输协议,见enum SDK_TransferProtocol_V2
		waittime[in]:		 等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SearchDeviceEX(long lLoginID,SDK_NetDevList *pDevlist,SDK_TransferProtocol_V2 transferProtocol=SDK_TRANSFER_PROTOCOL_NETIP,int waittime=15000);

/*
	描述:云台快速定位,使用前判断是否支持
	参数:
		lLoginID[in]:		登陆句柄
		nChannel[in]:		通道号
		pPositionPoint[in]:位置
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_PTZPostion(long lLoginID,int nChannel,SDK_PositionPoint *pPositionPoint);

/*
	描述:查询硬盘录像信息
	参数:
		lLoginID[in]:   登陆句柄
		lpFindInfo[in]: 查询条件
		lpFileData[out]:查找到的录像数据，外部开内存
		waittime[in]:	查询超时时间
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_RecordInfo(long lLoginID, SDK_SearchByTime* lpFindInfo, SDK_RecordStorageInfo *lpRecordData, int waittime=15000);

/*
	描述:控制设备上文件
	参数:
		lLoginID[in]:	   登陆句柄
		lpFileControl[in]:需要控制的文件和控制命令
		waittime[in]:      等待时间
	返回值:
		true: 成功
		false:失败
 */
bool VideoNet_ControlFile(long lLoginID,SDK_NetFileControl *lpFileControl,int waittime = 15000);

/*
	描述:查询录像设备里面音频文件，最大8个
	参数:
		lLoginID[in]:	登陆句柄
		lpFileList[out]:查找到的音频数据
		waittime[in]:	等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_FindAudioFile(long lLoginID, SDK_MusicFileList* lpFileList, int waittime=5000);

/*
	描述:控制播放设备上音频文件
	参数:
		lLoginID[in]:	   登陆句柄
		lpMusicControl[in]:需要播放的文件和控制命令
		waittime[in]:      等待时间
	返回值:
		true: 成功
		false:失败
 */
bool VideoNet_ControlAudio(long lLoginID, SDK_LocalMusicControl *lpMusicControl, int waittime=2000);

/*
	描述:既可以获取也可以配置设备参数
	参数:
		lLoginID[in]:		 登陆句柄
		nCmdReq[in]:		 请求命令
		szCmd[in]:			 json名称
		lpOutBuffer[out]:	 接收json缓冲
		dwOutBufferSize[in]: 接收缓冲大小(字节)
		lpBytesReturned[out]:接收到的json大小
		nTimeout[in]:		 等待时间
		pInParam[in]:		 配置时使用的json字符串
		nInParamLen[in]:	 配置时json大小(字节)
	返回值:
		=0:成功
		<0:失败
*/
long VideoNet_CmdGeneral(long lLoginID, int nCmdReq, const char *szCmd, void *lpOutBuffer, unsigned long dwOutBufferSize, unsigned long* lpBytesReturned, int nTimeout, char *pInParam=0, int nInParamLen=0, int nCmdRes=-1);

typedef void (*IDownProcess)(int nProcess,int userData);
typedef void (*IDownData)(unsigned char* data, unsigned int length, int nUserData);

typedef int (*MpsDevAuth)(char *buffer,int size);	//鉴权
typedef int (*MpsDevDataRecv)(char *buffer,int size,int clientID);	//数据由客户端发给设备


/*
	描述:得到配置的json格式
	参数:
		lLoginID[in]:	     登陆句柄
		dwCommand[in]:	     json名
		nChannelNO[in]:		 通道号,-1:得到全通道配置,0-n:得到单个通道的配置,从0开始
		lpOutBuffer[out]:	 接收json缓冲
		dwOutBufferSize[in]: 接收缓冲大小
		lpBytesReturned[out]:得到的缓冲大小(字节)
		waittime[in]:		 等待时间
	返回值:
		=1:成功
		<0:失败
*/
long VideoNet_GetDevConfig_Json(long lLoginID, const char* dwCommand, int nChannelNO,char * lpOutBuffer,unsigned long dwOutBufferSize,unsigned long* lpBytesReturned,int waittime=1000);
/*
	描述:设置配置的json格式
	参数:
		lLoginID[in]:	     登陆句柄
		dwCommand[in]:	     json名
		nChannelNO[in]:		 通道号,-1:得到全通道配置,0-n:得到单个通道的配置,从0开始
		lpOutBuffer[in]:	 设置的json字符串
		waittime[in]:		 等待时间
	返回值:
		=1:成功
		<0:失败
*/
long VideoNet_SetDevConfig_Json(long lLoginID,const char* dwCommand, int nChannelNO, char * lpInBuffer,int waittime=1000);
/*
	描述：获取该时间段上的图片
	参数：
		lLoginID[int]:登录句柄
		pNetBreviaryPic:请求获取的信息
		pBuffer:返回的图片数据
*/
bool VideoNet_GetNetPic(long lLoginID, SDK_NetBreviaryPic* pNetBreviaryPic, char* pBuffer, int nBufLen, int *pPicLen);
/*
	描述:建立图片上传通道
	参数:
		lLoginID[in]:登陆句柄
		nChannelNo[in]:通道号
		nPicType[in]:需要关注的图片类型--见枚举SDK_INTEL_PUSH_TYPE
		nType[in]:推送得到的图片类型--见枚举SDK_INTEL_PUSH_IMG_TYPE
	返回值:
		=1:成功
		=0:失败
*/
long VideoNet_SetupPushChan(long lLoginID, int nChannel, int nPicType, int nType);

/*
	描述:关闭图片上报
	参数:
		lLoginID[in]:登陆句柄
		nChannelNo[in]:通道号
	返回值:
		=1:成功
		=0:失败
*/
bool VideoNet_ClosePushChan(long lLoginID, int nChannelNo);

/*
	描述:日历查询
	参数:
		lLoginID[in]:登陆句柄
		pFindParam[in]:查询条件
		pRetBuffer[out]:日历返回信息
		lBufSize[out]:日历返回大小
		waittime:等待时间
	返回值:
		true: 成功
		false:失败
*/
bool VideoNet_SearchCalendar(long lLoginID, SDK_SearchCalendar *pFindParam, SDK_SearchCalendarMask *pRetBuffer, int waittime=2000);

/*
	描述:特殊命令操作--见枚举SDK_ConsumerProCmd
	参数:
	lLoginID[in]:	     登陆句柄
	lpOutBuffer[out]:	 操作数据--SDK_ConsumerProOpr
	lpBytesReturned[out]:返回的数据
	waittime[in]:		 等待时间 
	返回值:
	=1:成功
	<0:失败
*/
long VideoNet_ConsumerCmd(long lLoginID, SDK_ConsumerProOpr* lpOutBuffer, int* lpBytesReturned,int waittime=1000);

/*
	描述:GPIO控制
	参数:
	lLoginID[in]:		 登陆句柄
	返回值:
	=0:成功
	<0:失败
*/
long VideoNet_GPIOControl(long lLoginID, int iSecond);

//人脸图片
long VideoNet_StartReceiveFaceImageFile(long lLoginID,int nChannel);
long VideoNet_StartReceiveFaceImageFileEx(long lLoginID,int nChannel, int enable);
bool VideoNet_StopReceiveFaceImageFile(long lSubHandle);
bool VideoNet_SetFaceImageDataCallBack(long lSubHandle,fFaceImageDataCallBack cbFacePictureData, long dwUser);
bool VideoNet_DelFaceImageDataCallBack(long lSubHandle,fFaceImageDataCallBack cbFacePictureData, long dwUser);

//比对结果
long VideoNet_StartReceiveFaceCompareResult(long lLoginID,int nChannel); 
long VideoNet_StartReceiveFaceCompareResultEx(long lLoginID,int nChannel, SDK_COMPINFO_FLAG *pstCompinfoFlag); 
bool VideoNet_StopReceiveFaceCompareResult(long lSubHandle);
bool VideoNet_SetFaceCompareResultCallBack(long lSubHandle,fFaceCompaeResultCallBack cbFacePictureData, long dwUser, char *pImgPath = NULL);
bool VideoNet_DelFaceCompareResultCallBack(long lSubHandle,fFaceCompaeResultCallBack cbFacePictureData, long dwUser);


//黑白名单
long VideoNet_StartSendBlackAndWhiteList(long lLoginID,int nChannel);
bool VideoNet_StopSendBlackAndWhiteList(long lSubHandle);
bool VideoNet_SetBlackAndWhiteListCallBack(long lSubHandle,fFaceBlackAndWhiteListCallBack cbFacePictureData, long dwUser);
bool VideoNet_DeleteBlackAndWhiteListCallBack(long lSubHandle,fFaceBlackAndWhiteListCallBack cbFacePictureData, long dwUser);
bool VideoNet_OperationBlackAndWhiteListData(long lSubHandle,WBLIST_ACTION_TYPE ActionType,int nWBType,int nlibraryIndex,int nFileIndex,char *pFile);

//P2P FOR HTTP
//成功返回发送的字节数，失败返回-1
long VideoNet_SendForHttp_P2P( char *puuid, char *pDataBuf, int iDateLen );
// 成功返回接收的字节数，失败返回-1
long VideoNet_RecvForHttp_P2P( char *puuid, char **pDataBuf, int *iBufSize,int timeout);

typedef void (*OnFoundDevCB)(char * uuid,int state);

int VideoNet_InitQuerythread();

int VideoNet_StartQueryUUID(char *puuid[],int num,OnFoundDevCB findDevCB);
typedef void (*OnP2PLogData)(char *plog);
int VideoNet_GetP2PLogData();

}
#ifdef __cplusplus 
}
#endif

#endif

