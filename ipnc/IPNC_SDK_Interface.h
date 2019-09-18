#ifndef IPNC_SDK_INTERFACE_H_
#define IPNC_SDK_INTERFACE_H_


#define S_OK    (0L)
#define S_FALSE  (1L)

#define NET_IPC_NOERROR 					0	
#define NET_IPC_PASSWORD_ERROR 				1	
#define NET_IPC_PARAM_ERROR					2	
#define NET_IPC_MALLOC_MEMORY_FAIL				3	
#define NET_IPC_NETWORK_CONNECT_FAIL 			4	
#define NET_IPC_INIT_RESOURCE_FAIL				5	
#define NET_IPC_VERSIONNOMATCH				6	

#define MAX_RESERVE_LEN					128

#define ITC_MSG_TYPE_REMOTE_485_TOUCHUAN_REQ		(61)

typedef unsigned char byte;

typedef enum DEVICE_STATUS
{
	DEVICE_STATUS_UNKNOWN = 0, 
	DEVICE_STATUS_IS_ONLINE,   
	DEVICE_STATUS_IS_OFFLINE,  
	DEVICE_STATUS_MAX,
} DEVICE_STATUS_E;

typedef enum SNAP_MODE_NEW 
{
	SNAP_MODE_NEW_AUTO = 1, 
	SNAP_MODE_NEW_MANUAL =2,  
	SNAP_MODE_NEW_COIL_TRIGGER = 4,  
	SNAP_MODE_NEW_PHONE = 8, 
	SNAP_MODE_NEW_MAX, 
} SNAP_MODE_NEW_E;

typedef enum PLATE_COLOR {
	PLATE_COLOR_UNKNOWN	= 0, 
	PLATE_COLOR_BLUE,
	PLATE_COLOR_YELLOW,     
	PLATE_COLOR_WHITE,
	PLATE_COLOR_BLACK, 
	PLATE_COLOR_GREEN,
} PLATE_COLOR_E;

typedef enum PLATE_TYPE {
	PLATE_TYPE_UNKNOWN	= 0, 
	PLATE_TYPE_BLUE,
	PLATE_TYPE_BLACK,     
	PLATE_TYPE_YELLOW,
	PLATE_TYPE_YELLOW2, 

	PLATE_TYPE_POLICE,
	PLATE_TYPE_ARMPOL,
	PLATE_TYPE_INDIVI,     
	PLATE_TYPE_ARMY,
	PLATE_TYPE_ARMY2, 
	PLATE_TYPE_EMBASSY,

	PLATE_TYPE_HONGKONG,
	PLATE_TYPE_TRACTOR,     
	PLATE_TYPE_MACAU,
	PLATE_TYPE_CHANGNEI, 

	PLATE_TYPE_NEW_ENERGY = 17, 
} PLATE_TYPE_E;

typedef struct{
	int year;
	int mon;
	int day;
	int hour;
	int min;
	int sec;
	int msec;
} SnapTimeStamp;

typedef struct{
	int x;
	int y;
	int w;
	int h;      
} SnapRect;

typedef struct
{
	int isDetectPlate;	
	int snapMode;		
	int plateColor;		
	int plateType;		
	SnapTimeStamp snapTime;
	SnapRect snapRect;
	char plateNo[32];	
	char deviceIp[32];	
	char byRes[128];		
}IPNC_SNAP_INFO, *LPIPNC_SNAP_INFO;

typedef struct {
	int 			flag;
	char			entrance_plate_no[24];
	char			exit_plate_no[24];
	int 			card_attr;
	SnapTimeStamp 	entrance_time_stamp;
	SnapTimeStamp 	exit_time_stamp;
	char			valid_start_time[64];
	char			valid_end_time[64];
	int 			charge_money;
	int 			remain_money;
	char 			entranceIp[32];
	char 			exitIp[32];
	int			get_flag;
	int 			process_flag;
	int 			ignore_mode;
	int 			ignore_len;
	int 			plate_type;
	char			reserve[MAX_RESERVE_LEN - 20];
} IPNC_OFFLINE_RECORD;

typedef struct {
	IPNC_OFFLINE_RECORD record;
	char 		filePath[256];
	int		isGetSucc;
} IPNC_OFFLINE_INFO, *LPIPNC_OFFLINE_INFO;


typedef struct LED_AreaInfo_S
{        
	byte fontColor;        //字体颜色:  0:红色  1:绿色  2:黄色
	byte areaNo;           //区域编号   范围： 0 - 3
	byte fontsize;         //字体大小   16: 16号  32:32号
	byte showMode;         //显示类型   0:文本显示，1:时钟显示        
	short areaY;           //区域Y坐标  范围： 0 - 63
	short areaH;           //区域高     范围： 0 - 63
	short areaW;           //区域宽     范围： 0 - 127
	short unitTimes;       //时间单位（秒）默认30秒
	byte stuntIn;          //进入特技   0:立即显示 1:自右向左滚动 2:自动换行显示  3:向上滚动进入    
	byte StuntOut;         //退出特技 
	byte showSpeed;        //滚动速度   范围：0 - 11
	char AreaContent[32];  //显示的内容  不超过32个字节
} LED_AreaInfo_S;



typedef void (*SNAP_DATA_CAllBACK)(char *pSnapBuffer,int dwBufSize,  char *pPlateJpeg, int plateJpegLen, void *pUser);

typedef void (*DEVICE_STATUS_CAllBACK)(char *pDeviceIp, int port, int deviceStatus, void *pUser);

typedef void (*PROCESS_TCP_CAllBACK)(char *pRecvDataBuffer, int dwBufSize, char *pPlateJpeg, int plateJpegLen, void *pUser);

typedef void (*GET_SAVE_JPEG_CAllBACK)(char *pRecvDataBuffer,int dwBufSize, char *pPlateJpeg, int plateJpegLen, void *pUser);

typedef void (*GET_485_MSG_CAllBACK)(char *pDeviceIp, char *pRecvDataBuffer,int dwBufSize, void *pUser);

//函数功能：IPNC SDK 初始化
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_Init();

//函数功能：IPNC SDK 注销
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_Cleanup();

//函数功能：设备连接
//输入参数：pDeviceIp：设备IP； strUserName：登录用户名；strPassword：登录密码
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_ConnectDevice(char *pDeviceIp, char * strUserName, char * strPassword);

//函数功能：断开设备连接
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_DisconnectDevice(char *pDeviceIp); 

//函数功能：手动抓拍
//输入参数：pDeviceIp：设备IP 
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_ManualSnap(char *pDeviceIp);

//函数功能：设备校时
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_DeviceCheckTime(char *pDeviceIp);

//函数功能：设备重启
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_DeviceReboot(char *pDeviceIp);

//函数功能：远程开闸
//输入参数：pDeviceIp：设备IP
//输入参数：enable：0，表示关闭道闸；1，表示开启道闸
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_DeviceOpenBarrier(char *pDeviceIp);

//函数功能：注册抓拍数据(抓拍图片+抓拍结果)回调
//输入参数：pSnapCallBack:回调函数指针
//输入参数：pUser:用户环境变量
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_RegisterSnapCallBack(SNAP_DATA_CAllBACK pSnapCallBack, void *pUser);

//函数功能：注销抓拍数据回调
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_UnregisterSnapCallBack();

//函数功能：解析抓拍数据
//输入参数：pSnapDataBuffer：抓拍缓冲区
//输入参数：bufSize：抓拍缓冲区大小
//输出参数：pSnapInfo：抓拍结果信息
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_PraseSnapData(char *pSnapDataBuffer,int bufSize, LPIPNC_SNAP_INFO pSnapInfo);

//函数功能：注册设备状态回调
//输入参数：pDeviceStatusCallBack 回调函数指针
//输入参数：pUser:用户环境变量
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_RegisterDeviceStatusCallBack(DEVICE_STATUS_CAllBACK pDeviceStatusCallBack, void *pUser);

//函数功能：注销设备状态回调
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_UnregisterDeviceStatusCallBack();

//函数功能：获取 SDK 错误码
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_GetLastError();

//使能SDK自动校时,针对sdk中连接的所有设备
//输入参数：enable：使能标记 0，禁止；1，启用
//输入参数：autoCheckTimeInterval：校时时间间隔 单位秒
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_EnableAutoCheckTime(int enable, int autoCheckTimeInterval);

//函数功能：设备搜索
//输出参数：pDeviceNum：搜索到的设备数目
//输出参数：pDeviceIpList：搜索到的设备IP列表
//输入参数：timeout：搜索超时
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_SDK_API_DeviceSearch(int *pDeviceNum, char *pDeviceIpList, int timeout);


//========================================标准语音板 =======================================

//函数功能：标准语音板 播报语音“车场满位”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundFullSet(char *pDeviceIp);

//函数功能：标准语音板 播报语音“一路顺风”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundNoTimeOut(char *pDeviceIp);

//函数功能：标准语音板 播报语音“此卡无效”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundInvalidCard(char *pDeviceIp);

//函数功能：//标准语音板 播报语音“此卡已出场”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundNoOut(char *pDeviceIp);

//函数功能：标准语音板 播报语音“此卡已入场”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundNoIn(char *pDeviceIp);

//函数功能：标准语音板 播报语音“月卡过期”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundYKNoDay(char *pDeviceIp);

//函数功能：标准语音板 播报语音“欢迎光临”
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_SetWelcomeInfo(char *pDeviceIp);

//函数功能：标准语音板 播报语音 根据指定内容播报
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundSpeech(char *pDeviceIp, int command, char *pAudioBuffer, int audioBufferLen);

//函数功能：标准语音板 播报月卡出入  车牌及剩余有效天数
//输入参数：pDeviceIp：设备IP
//输入参数：pPlateNo：车牌号码
//输入参数：remainDays：剩余天数
//输入参数：inOutFlag：进出标记 0, 表示入口 1，表示出口
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundYKOutInAndCar(char *pDeviceIp, char *pPlateNo, int remainDays, int inOutFlag);

//函数功能：标准语音板 临时车入口播报车牌
//输入参数：pDeviceIp：设备IP
//输入参数：pPlateNo：车牌号码
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundLSKCarNoAndDays(char *pDeviceIp, char *pPlateNo);

//函数功能：标准语音板 临时车出口播报车牌、停车时间以及收费金额
//输入参数：pDeviceIp：设备IP
//输入参数：pPlateNo：车牌号码
//输入参数：parkingTime：停车时间
//输入参数：offerMoney：交费金额
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_PlaySoundLSKCarTimeMoney(char *pDeviceIp, char *pPlateNo, int parkingTime, int offerMoney);

//函数功能：标准语音板 加载剩余车位信息
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_LoadPlateRemain(char *pDeviceIp, LED_AreaInfo_S *pAreaInfo_01, 
	LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：标准语音板 加载动态信息
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_LoadAutoInfo(char *pDeviceIp, LED_AreaInfo_S *pAreaInfo_01, 
	LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：标准语音板 加载广告信息
//输入参数：pDeviceIp：设备IP
//输入参数：programStayTime：广告停留时间
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_LoadProgram(char *pDeviceIp, int programStayTime, LED_AreaInfo_S *pAreaInfo_01, 
	LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：标准语音板 清除广告信息
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_ClearProgram(const char *pDeviceIp);

//函数功能：标准语音板 初始化显示屏(该接口慎用)
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_InitLED(const char *pDeviceIp);

//函数功能：标准语音板 测试显示屏
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_TestScreen(const char *pDeviceIp);


 //========================================万能语音板 =======================================


//函数功能：万能语音板 语音播报
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_Speek(const char *pDeviceIp, char *pSpeekBuffer);


//函数功能：万能语音板 音量设置
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_SetVolume(const char *pDeviceIp, int volume);

//函数功能：万能语音板 加载车位
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_LoadPlateRemain(const char *pDeviceIp, LED_AreaInfo_S *pAreaInfo_01, 
	LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：万能语音板 加载动态信息
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_LoadAutoInfo(const char *pDeviceIp, LED_AreaInfo_S *pAreaInfo_01, 
	LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：万能语音板 加载广告
//输入参数：pDeviceIp：设备IP
//输入参数：programStayTime：广告停留时间
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_LoadProgram(const char *pDeviceIp, int programStayTime, 
	LED_AreaInfo_S *pAreaInfo_01, LED_AreaInfo_S *pAreaInfo_02, LED_AreaInfo_S *pAreaInfo_03, LED_AreaInfo_S *pAreaInfo_04);

//函数功能：万能语音板 清空广告
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_ClearProgram(const char *pDeviceIp);

//函数功能：万能语音板 测试显示屏
//输入参数：pDeviceIp：设备IP
//函数返回：成功返回 S_OK，失败返回 S_FALSE
unsigned long long IPNC_NET_API_UniversalSpeech_TestScreen(const char *pDeviceIp);

#endif
