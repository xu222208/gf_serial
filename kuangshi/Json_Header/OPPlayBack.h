#pragma once
#include "JObject.h"
NS_NETSDK_CFG_BEGIN

#define JK_PlayBackParameter "Parameter"
class PlayBackParameter : public JObject
{
public:
	JIntObj		Channel;
    JStrObj		FileName;
    JStrObj		PlayMode;
    JIntObj		Stream_Type;
    JIntObj		Value;
    JStrObj		TransMode;
    JStrObj		IntelligentPlayBackEvent;
    JIntObj		IntelligentPlayBackSpeed;
    
public:
    PlayBackParameter(JObject *pParent = NULL, const char *szName = JK_PlayBackParameter):
    JObject(pParent,szName),
	Channel(this, "Channel"),
    FileName(this, "FileName"),
    PlayMode(this, "PlayMode"),
    Stream_Type(this, "Stream_Type"),
    Value(this, "Value"),
    TransMode(this, "TransMode"),
    IntelligentPlayBackEvent(this, "IntelligentPlayBackEvent"),
    IntelligentPlayBackSpeed(this, "IntelligentPlayBackSpeed"){
    };
    
    ~PlayBackParameter(void){};
    
    //    F_SUB_COMMON		= 0x00,				F_SUB_LOCALALARM		= 0x01, 	///< 本地报警
    //    F_SUB_NETALARM		= 0x02, 	///< 网络报警	F_SUB_NETABORT		= 0x03, 	///< 断网报警
    //    F_SUB_IPCALARM		= 0x04, 	///< IPC报警	F_SUB_SPEEDALARM		= 0x05, 	///< 超速报警
    //    F_SUB_GSENSORALARM	= 0x06, 	///< SENSOR报警	F_SUB_SERIALALARM		= 0x07, 	///<串口报警
    //    F_SUB_MOTIONDETECT	= 0x08, 	///< 移动侦测	F_SUB_LOSSDETECT		= 0x09, 	///< 视频丢失
    //    F_SUB_BLINDDETECT		= 0x0a, 	///< 视频遮挡	F_SUB_PIRALARM		= 0x0b, 	///< 红外检测
    //    F_SUB_CARDNUMBER		= 0x0c, 	///< 卡号录像	F_SUB_PERIMETER		= 0x0d, 	///< 周界检测
    //    F_SUB_TRIPWIRE		= 0x0e,	///< 单绊线检测	F_SUB_ABANDUM		= 0x0f, 	///< 物品遗留
    //    F_SUB_STOLEN			= 0x10, 	///< 物品被盗	F_SUB_CHANGE			= 0x11, 	///< 场景变换
    //    F_SUB_NR				= 0x1f,
    void SetPlayBackEvent(unsigned int *event, int nCount)
    {
        unsigned int value;
        for(int i = 0; i < nCount; i++)
        {
            value |= (0x1 << event[i]);
        }
    };
    
    void SetPlayBackEvent(const char *szEvent)
    {
    };
};
#define JK_OPPlayBack "OPPlayBack"
class OPPlayBack : public JObject
{
public:
	JStrObj		Action;
	PlayBackParameter		mParameter;
	JStrObj		EndTime;
	JStrObj		StartTime;

public:
	OPPlayBack(JObject *pParent = NULL, const char *szName = JK_OPPlayBack):
	JObject(pParent,szName),
	Action(this, "Action"),
	mParameter(this, JK_PlayBackParameter),
	EndTime(this, "EndTime"),
	StartTime(this, "StartTime"){
        static const char *s_szInitValue =
        "{\r\n\"Name\" : \"OPPlayBack\",\r\n\
        \"SessionID\" : \"0x2c\", \r\n\
        \"OPPlayBack\":	{\r\n\
        \"Action\":	\"Stop\",\r\n\
        \"Parameter\":	{\r\n\
		\"Channel\":	0,\r\n\
		\"FileName\":	\"00_2018-08-06 00:00:00\",\r\n\
       \"PlayMode\":	\"ByTime\",\r\n\
        \"Stream_Type\":	0,\r\n\
        \"Value\":	0,\r\n\
        \"TransMode\":	\"TCP\",\r\n\
        \"IntelligentPlayBackEvent\":	\"ALL\",\r\n\
        \"IntelligentPlayBackSpeed\":	0\r\n\
        },\r\n\
		\"StartTime\":	\"2000-01-01 00:00:00\",\r\n\
        \"EndTime\":	\"2000-01-01 23:59:59\"\r\n\
        }\r\n}";
        this->Parse(s_szInitValue);
	};

    void SetStartTime(int tt[6])
    {
        char szTime[32];
        sprintf(szTime, "%04d-%02d-%02d %02d:%02d:%02d", tt[0], tt[1], tt[2], tt[3], tt[4], tt[5]);
        StartTime = szTime;
    };
    void SetEndTime(int tt[6])
    {
        char szTime[32];
        sprintf(szTime, "%04d-%02d-%02d %02d:%02d:%02d", tt[0], tt[1], tt[2], tt[3], tt[4], tt[5]);
        EndTime = szTime;
    };
	~OPPlayBack(void){};
};

NS_NETSDK_CFG_END

