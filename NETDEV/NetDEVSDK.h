#ifndef _NETDEV_H_
#define _NETDEV_H_

#ifdef  __cplusplus
extern "C"{
#endif

#ifndef STATIC
    #define STATIC                  static
#endif

#ifndef CONST
    #define CONST                   const
#endif

#ifndef EXTERN
    #define EXTERN                  extern
#endif

#ifndef INLINE
    #define INLINE                  __inline
#endif

#ifndef UNION
    #define UNION                   union
#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef INOUT
    #define INOUT
#endif

#ifndef NEWINTERFACE
    #define NEWINTERFACE
#endif

#if defined(WIN32)  /* windows */
#define NETDEV_API                  __declspec(dllexport)
#else
#define NETDEV_API
#endif

/* 函数标准调用约定 Standard function calling convention */
#ifdef i386
    #ifdef LINUX
        #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))__attribute__((visibility ("default")))
        #endif
    #else
        #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))
        #endif
    #endif
#else
    #ifdef WIN32
        #ifndef STDCALL
        #define STDCALL                 __stdcall
        #endif
    #else
        #ifdef LINUX
            #ifndef STDCALL
            #define STDCALL                 __attribute__((stdcall))__attribute__((visibility ("default")))
            #endif
        #else
            #ifndef STDCALL
            #define STDCALL
            #endif
        #endif
    #endif
#endif


#ifndef UCHAR_DEF
#define UCHAR_DEF
    typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
    typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
    typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
    typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
    typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
    typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
    typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
    typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
    typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
    typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
    #ifndef TARGET_OS_IPHONE
        typedef int                 BOOL;
    #else
        #import<objc/objc.h>
    #endif
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
    typedef float                   FLOAT;
#endif
#endif

#ifndef DOUBLE
#ifndef DOUBLE_DEF
#define DOUBLE_DEF
    typedef double                   DOUBLE;
#endif
#endif

#ifndef FALSE
    #define FALSE                   0
#endif

#ifndef TRUE
    #define TRUE                    1
#endif

#ifndef WIN32
    typedef LPVOID                 HWND;
#endif

/************************************************************************/
/*                     模块宏定义                                 */
/************************************************************************/
#ifndef LINUX
    #define NETDEV_WITH_MEDIA           1           /* 包含媒体模块 */
#endif
#define NETDEV_WITH_CLOUD           1           /* 包含云服务模块 */
#define NETDEV_WITH_XW              1           /* 包含电视墙、拼接模块 */
#define NETDEV_WITH_VMS             1           /* 包含VMS模块 */
#define NETDEV_WITH_PTZ             1           /* 包含云台模块 */
#define NETDEV_WITH_SMART           1           /* 包含智能业务模块 */
#define NETDEV_WITH_CONFIG          1           /* 包含配置业务模块 */
#define NETDEV_WITH_BASIC           1           /* 包含基础管理业务模块 */
#define NETDEV_ALARM_RECOVER_BASE   1           /* 告警恢复基数 Alarm recover base */


/********************************** 常用数值宏  Commonly used numerical macros *************** */
#define NETDEV_STREAM_ID_LEN                    32          /* 流ID标识长度  Length of stream ID*/
#define NETDEV_FILE_NAME_LEN                    (256u)      /* 文件名长度  Length of filename */
#define NETDEV_USERNAME_LEN                         (128 + 4)   /* Maximum length of username */
#define NETDEV_PASSWORD_LEN                         128         /* Maximum length of password */
#define NETDEV_DESCRIBE_MAX_LEN                     (512 + 4)   /* 描述最大长度 ：128 * 4，任意字符达到长度128 */
#define NETDEV_DOMAIN_LEN                       64          /* 域名最大长度  Maximum length of domain name */
#define NETDEV_PATH_LEN                         128         /* 路径最大长度:包括文件名称  Maximum length of path, including filename */
#define NETDEV_MAX_URL_LEN                      512         /* URL 的最大长度  Maximum length of URL */

/* 通用长度  Common length */
#define NETDEV_LEN_2                            2
#define NETDEV_LEN_4                            4
#define NETDEV_LEN_6                            6
#define NETDEV_LEN_8                            8
#define NETDEV_LEN_16                           16
#define NETDEV_LEN_32                           32
#define NETDEV_LEN_64                           64
#define NETDEV_LEN_128                          128
#define NETDEV_LEN_132                          132
#define NETDEV_LEN_256                          256
#define NETDEV_LEN_260                          260
#define NETDEV_LEN_480                          480
#define NETDEV_LEN_512                          512
#define NETDEV_LEN_1024                         1024
#define NETDEV_LEN_2000                         2000

#define NETDEV_IPADDR_STR_MAX_LEN              (64u)        /* IP 地址信息字符串长度  Length of IP address string */
#define NETDEV_IPV4_LEN_MAX                     16          /* IPV4地址字符串长度 Length of IPV4 address string */
#define NETDEV_IPV6_LEN_MAX                     128         /* IPV6地址字符串长度 Length of IPV6 address string */
#define NETDEV_NAME_MAX_LEN                    (256u)       /* 通用名称字符串长度  Length of common name string */

#define NETDEV_CODE_STR_MAX_LEN                (256u)       /* 通用CODE 长度  Length of common code */
#define NETDEV_MAX_DATE_STRING_LEN             (64u)        /* 最大日期字符长度 Maximum length of date string "2008-10-02 09:25:33.001 GMT" */
#define NETDEV_MAX_ALARM_IN_NUM                 64          /* 告警输入最大数量  Maximum number of alarm inputs */
#define NETDEV_MAX_ALARM_OUT_NUM                64          /* 告警输出最大数量  Maximum number of alarm outputs */
#define NETDEV_PLAN_SECTION_NUM                 8           /* 一天中的计划时间段  Number of scheduled time sections in a day */
#define NETDEV_PLAN_NUM_AWEEK                   8           /* 一周总共可配置的计划个数,包括周一至周日和假日  Total number of plans allowed in a week, including Monday to Sunday, and holidays */

#define NETDEV_MAX_PRESET_NUM                   256         /* 预置位最大数  Maximum number of presets */
#define NETDEV_MAX_CRUISEPOINT_NUM              32          /* 巡航路径中预置位点最大个数  Maximum number of presets for preset patrol */
#define NETDEV_MAX_CRUISEROUTE_NUM              16          /* 预置位巡航路径最大条数  Maximum number of routes for preset patrol */
#define NETDEV_MIN_PTZ_SPEED_LEVEL              1           /* 云台移动最小速度  Maximum PTZ rotating speed */
#define NETDEV_MAX_PTZ_SPEED_LEVEL              9           /* 云台移动最大速度  MinimumPTZ rotating speed */
#define NETDEV_MAX_VIDEO_EFFECT_VALUE           255         /* 图像参数（亮度 对比度 色度 饱和度）最大值  Maximum values for image parameters (brightness, contrast, hue, saturation) */
#define NETDEV_MIN_VIDEO_EFFECT_VALUE           0           /* 图像参数（亮度 对比度 色度 饱和度）最小值  Minimum values for image parameters (brightness, contrast, hue, saturation) */
#define NETDEV_MAX_VIDEO_EFFECT_GAMMA_VALUE     10          /* 图像参数（伽马值）最大值 Minimum values for image parameters (Gama) */

#define NETDEV_MAX_PRIVACY_MASK_AREA_NUM        8           /* 最大可配置遮盖区域个数  Maximum number of privacy mask areas allowed */
#define NETDEV_OSD_TEXTOVERLAY_NUM              6           /* 通道 OSD 字符叠加数量  Number of OSD text overlays */
#define NETDEV_OSD_TEXT_MAX_LEN                 (64 + 4)    /* 通道 OSD 字符长度  Length of OSD texts */
#define NETDEV_OSD_TYPE_MAX_NUM                 26          /* 通道 OSD 最大类型个数  Maximum number of OSD type */
#define NETDEV_OSD_TIME_FORMAT_MAX_NUM          7           /* 通道 OSD 最大时间格式个数  Maximum number of OSD time format type */
#define NETDEV_OSD_DATE_FORMAT_MAX_NUM          15          /* 通道 OSD 最大日期格式个数  Maximum number of OSD date format type */
#define NETDEV_PULL_ALARM_MAX_NUM               8           /* 拉告警最大告警个数  Maximum number of alarms a user can get */
#define NETDEV_TRACK_CRUISE_MAXNUM              1           /* 支持的轨迹巡航的最大条数  Maximum number of patrol routes allowed  */
#define NETDEV_AUDIO_SOUND_MIN_VALUE            0           /* 音量调节最小值  Minimum volume */
#define NETDEV_AUDIO_SOUND_MAX_VALUE            255         /* 音量调节最大值  Maximum volume */
#define NETDEV_MIC_SOUND_MIN_VALUE              0           /* 麦克风音量调节最小值  Minimum volume */
#define NETDEV_MIC_SOUND_MAX_VALUE              255         /* 麦克风音量调节最大值  Maximum volume */
#define NETDEV_SCREEN_INFO_ROW                  18          /* 屏幕信息行数  Screen Info Row */
#define NETDEV_SCREEN_INFO_COLUMN               22          /* 屏幕信息列数  Screen Info Column */
#define NETDEV_CHANNEL_MAX                      512         /* 最大通道数 Maximum number of channel */
#define NETDEV_RESOLUTION_NUM_MAX               32          /* 分辨率总个数 Maximum number of resolution */
#define NETDEV_MONTH_DAY_MAX                    31          /* 每月天数最大值 Maximum number of days in a month */
#define NETDEV_VIDEO_ENCODE_TYPE_MAX            16          /* 编码格式类型总个数 Maximum number of encode type */
#define NETDEV_PEOPLE_CNT_MAX_NUM               60          /* 客流量统计数组最大值（分报表） Maximum number of people count */
#define NETDEV_WIFISNIFFER_MAC_MAX_NUM          64          /* wifi sniffer MAC地址最大长度  Length of wifi sniffer MAC */
#define NETDEV_WIFISNIFFER_MAC_ARRY_MAX_NUM     128         /* wifi sniffer MAC地址数组最大值 Maximum number of wifi sniffer MAC array */
#define NETDEV_DISK_MAX_NUM                     256         /* 磁盘最大数量 Maximum number of Disk */
#define NETDEV_LOCAL_DISK_MAX_NUM               32          /* 本地磁盘最大数量 local Maximum number of Disk */
#define NETDEV_SD_CARD_DISK_MAX_NUM             16          /* SD卡最大数量 SD Maximum number of Disk */
#define NETDEV_ARRAY_MAX_NUM                    16          /* 阵列最大数量 array Maximum number of Disk */
#define NETDEV_EXTEND_CABINET_DISK_MAX_NUM      32          /* 扩展柜硬盘最大数量 extend cabinet Maximum number of Disk */
#define NETDEV_NAS_MAX_NUM                      16          /* NAS最大数量 NAS Maximum number of Disk */
#define NETDEV_ESATA_MAX_NUM                    4           /* ESATA最大数量 eSATA Maximum number of Disk */
#define NETDEV_DISK_SMART_MAX_NUM               128         /* 硬盘SMART信息最大数量 Maximum number of Disk Smart Info */
#define NETDEV_ENCODE_FORMAT_MAX_NUM            3           /* 最大视频编码格式数 Maximum number of video compression */
#define NETDEV_SMART_ENCODE_MODEL_MAX_NUM       3           /* 最大智能图像扩展编码模式数 Maximum number of smart image encoding mode */
#define NETDEV_GOP_TYPE_MAX_NUM                 4           /* 最大GOP类型数量 Maximum number of GOP type */

#define NETDEV_DEV_OTHER_LEN_MAX                32          /* 其他字段 */
#define NETDEV_DEV_NAME_LEN_MAX                 64          /* 设备名称长度 */

#define NETDEV_DEV_PASSWORD_LEN_MAX             64          /* 设备密码长度 */
#define NETDEV_CLOUD_DEV_USER_NAME_LEN          260         /* 云端设备ID长度 */
#define NETDEV_CLOUD_USER_NAME_LEN              260         /* 云端用户名长度 */
#define NETDEV_CLOUD_DEV_USER_AUTH_LEN          260         /* 云端设备用户权限名称长度 */
#define NETDEV_CLOUD_SHARE_TARGET_NAME_LEN      64          /* 云端设备共享对象名称长度 */
#define NETDEV_CLOUD_SHARE_DESCRIBE_LEN         260         /* 云端设备共享描述长度 */
#define NETDEV_CLOUD_DEV_NAME_LEN               260         /* 云端设备名称长度 */
#define NETDEV_XW_MAX_PANE_NUM                  64          /* 窗口最大分屏数量 */
#define NETDEV_NTP_SERVER_LIST_NUM              5           /* NTP服务列表数量 */

#define NETDEV_TMS_FACE_RECORD_ID_LEN           32          /* 记录ID缓存长度 */
#define NETDEV_TMS_CAMER_ID_LEN                 32          /* 相机ID缓存长度 */
#define NETDEV_TMS_PASSTIME_LEN                 32          /* 通过时间字符串缓存长度 */
#define NETDEV_TMS_FACE_TOLLGATE_ID_LEN         32          /* 卡口编号缓存长度 */
#define NETDEV_TMS_HEAT_MAP_DEVID_LEN           32          /*热度图DevID字段长度*/
#define NETDEV_TMS_HEAT_MAP_RECORD_ID_LEN       16          /*热度图RecordID字段长度*/
#define NETDEV_TMS_HEAT_MAP_COllECT_TIME_LEN    18          /*热度图CollectTime 字段长度*/
#define NETDEV_TMS_PIC_COMMON_NUM               10          /*图片或区域上限个数*/
#define NETDEV_TMS_CAR_PLATE_CAMID_LEN          32          /*车牌识别CamID字段长度*/
#define NETDEV_TMS_CAR_PLATE_RECORDID_LEN       32          /*车牌识别RecordID字段长度*/
#define NETDEV_TMS_CAR_PLATE_TOLLGATE_LEN       32          /*车牌识别TollgateID字段长度*/
#define NETDEV_TMS_CAR_PLATE_PASSTIME_LEN       18          /*车牌识别PassTime字段长度*/
#define NETDEV_TMS_CAR_PLATE_LANEID_LEN         18           /*车牌识别LaneID字段长度*/
#define NETDEV_TMS_CAR_PLATE_CARPLATE_LEN       32          /*车牌识别CarPlate字段长度*/
#define NETDEV_USER_NAME_ENCRYPT_LEN            256         /* 加密后的用户名长度 */
#define NETDEV_PASSWORD_ENCRYPT_LEN             256         /* 加密后的密码长度 */
#define NETDEV_VIDEO_FORMAT_MAX                 32          /* 支持的视频输出制式最大数量 */
#define NETDEV_VIDEO_FORMAT_NAME_LEN            32          /* 支持的视频输出制式名称长度 */
#define NETDEV_TVWALL_NAME_LEN                  260         /* 电视墙名称长度 */
#define NETDEV_FORMAT_SPEC_MAX                  256         /* 特殊输出制式的最大个数量 */
#define NETDEV_LED_SPEC_MAX                     256         /* 特殊模组框的最大个数量 */
#define NETDEV_FORMAT_NAME_LEN                  32          /* 输出制式名称长度 */
#define NETDEV_VIDEO_OUT_MAX                    64          /* 物理输出端口的最大个数量 */
#define NETDEV_SCENE_NAME_LEN                   260         /* 场景名称长度 */
#define NETDEV_TIME_LEN                         16          /* 时间字符串长度 */
#define NETDEV_WND_NAME_LEN                     260         /* 窗口名称长度 */
#define NETDEV_SEQUENCE_SRC_MAX                 128         /* 轮巡时视频源最大个数 */
#define NETDEV_TEXT_LEN                         1024        /* 虚拟LED文字内容长度 */
#define NETDEV_BMAP_NAME_LEN                    256         /* 底图名称长度 */
#define NETDEV_SEQ_RES_WIN_MAX                  288         /* 轮巡资源中窗口的最大个数 */
#define NETDEV_MAX_DAY_NUM                      8           /* 最大天数 */
#define NETDEV_MAX_TIME_SECTION_NUM             8           /* 时间段数量 */

#define NETDEV_ALARM_SOURCE_MAX_LEN                 (64 + 4)    /* 告警资源字符描述长度 */
#define NETDEV_MAX_EVENT_RES_SIZE                   1024        /* 事件上报最大资源数 */

#define NETDEV_VIID_CODE_LEN                        48          /* 视图编码长度 */
#define NETDEV_VIDEO_FORMAT_CAP_NUM                 64          /* 编码制式能力集 */
#define NETDEV_LAYOUT_CAP_NUM                       64          /* 分屏能力集 */

#define NETDEV_DA_POINT_CODE_LEN                    48          /* 代理设备 点位 编码长度 */
#define NETDEV_DA_AREA_CODE_LEN                     48          /* 代理设备 区域 编码长度 */
#define NETDEV_VIRTUAL_MEM_TABLE_MAX                32          /* 虚拟内存表元素最大数量 */
#define NETDEV_EVENT_STORE_TYPE_NUM                 128         /* 时间存储类型数量 */
#define NETDEV_MAX_PANE_NUM                         36          /* DC业务分屏数量最大为36分屏 */
#define NETDEV_OSD_MAX_NUM_EX                       8           /* 通道 OSD 最大数量  Maximum Number of OSD */
#define NETDEV_RSA_MAX_VALUE                        3           /* 表示最多尝试密钥生成次数 */

#define NETDEV_MAX_VIDEO_BRIGHT_EFFECT_VALUE        199             /* 图像参数（亮度）最大值 */
#define NETDEV_MAX_VIDEO_CONTRAST_EFFECT_VALUE      199             /* 图像参数（对比度）最大值 */
#define NETDEV_MAX_VIDEO_SATURATION_EFFECT_VALUE    359             /* 图像参数（饱和度）最大值 */
#define NETDEV_MAX_VIDEO_HUE_EFFECT_VALUE           359             /* 图像参数（色度）最大值 */
#define NETDEV_MAX_VIDEO_GAMMA_EFFECT_VALUE         99              /* 图像参数（伽玛）最大值 */
#define NETDEV_PIXEL_CONVERT_RATIO                  5000            /* 像素转换比例 用于区域设置,如拉框放大区域 */
#define NETDEV_PANES_NUM                            16              /* 单通道最大分屏数 */

#define NETDEV_XW_AUDIO_NUM                         16              /* 音频输出通道最大个数 */
#define NETDEV_IP_ADDRESS_LEN                       64              /* IP地址长度 */

#define NETDEV_TVWALLPLAN_NUM                       4               /* 电视墙预案个数 */
#define NETDEV_PLAN_MAX_TVWALL_NUM                  4               /* 预案下电视墙最大数量 */
#define NETDEV_TVWALL_MAX_WIN_NUM                   81              /* 电视墙最大的窗口数量 */
#define NETDEV_TVWALL_MAX_LAYOUT_NUM                64              /* 电视墙最大的分屏数量,即为子窗口数量 */
#define NETDEV_ALARM_LINK_PRESET_NUM                16              /* 告警预案联动预置位数量  */
#define NETDEV_ALARM_LINK_SWITCHOUT_NUM             16              /* 告警预案联动告警输出通道数量 */
#define NETDEV_ALARM_LINK_MONITOR_NUM               16              /* 告警预案联动实况数量 */
#define NETDEV_ALARM_LINK_TVWALL_NUM                32              /* 告警预案联动电视墙最大数量*/
#define NETDEV_ALARM_LINK_SOUND_LEN                 512             /* 告警预案联动声音信息最大长度 */
#define NETDEV_ALARM_SOURCE_NUM                     1               /* 告警源数量 */
#define NETDEV_ALARM_LINK_NUM                       128             /* 告警预案数量 */

#define NETDEV_TIME_TEMPLATE_NUM                    32              /* 时间模板数量 */
#define NETDEV_DC_SCHEME_RES_CHN_MAX_NUM            256             /* DC轮巡最大资源数 */
#define NETDEV_VIEW_MAX_WIN_NUM                     100             /* 视图最大的窗口数量 */
#define NETDEV_MAX_ROLE_RIGHT_SIZE                  256             /* 用户权限菜单项数量 */
#define NETDEV_MAX_ALARM_TASK_SIZE                  128             /* 告警任务数量 */
#define NETDEV_MAX_QUERY_CHANNEL_NUM                500             /* 单次查询最大通道个数 */
#define NETDEV_MAX_QUERY_DEV_NUM                    500             /* 单次查询最大设备个数 */
#define NETDEV_GRID_AREAS_LEN                       256             /* 宏块值数组长度 */
#define NETDEV_MAX_ORG_ROOT_ID_NUM                  32              /* 组织树根节点最大个数 */
#define NETDEV_VOICE_BROADCAST_CHANNEL_NUM_MAX      128             /* 一个语音广播组支持最大通道个数 */
#define NETDEV_RECORD_LOCK_ID_LEN                   64              /* 录像锁定ID最大长度 */
#define NETDEV_RECORD_LOCK_DESC_LEN                 64              /* 锁定录像段的描述最大长度 */
#define NETDEV_NOTIME                               0               /* 时间无值 */
#define NETDEV_WHITE_BALANCE_MODE_MAX_NUM           16              /* 最多支持的白平衡模式个数 Maximum number of Image white balance mode count */
#define NETDEV_FOCUS_MODE_MAX_NUM                   16              /* 最多支持的对焦模式个数 Maximum number of Image focus mode count */
#define NETDEV_FOCUS_SCENE_MAX_NUM                  16              /* 最多支持的对焦场景个数 Maximum number of Image focus scene count */
#define NETDEV_IMAGE_ROTATION_MODE_MAX_NUM          16              /* 最多支持的图像镜像模式个数 Maximum number of Image rotation mode count */
#define NETDEV_LAMP_CTRL_TYPE_MAX_NUM               16              /* 最多支持的支持的补光灯类型个数 Maximum number of lamp ctrl type count */
#define NETDEV_LAMP_CTRL_MODE_MAX_NUM               16              /* 最多支持的补光灯空控制模式个数 Maximum number of lamp ctrl mode count */
#define NETDEV_EXPOSURE_MODE_MAX_NUM                16              /* 最多支持的曝光模式个数 Maximum number of exposure mode count */
#define NETDEV_IRIS_RANGE_MAX_NUM                   16              /* 最多支持的光圈取值个数  Maximum number of Iris Range count */
#define NETDEV_METERING_MODE_MAX_NUM                16              /* 最多支持的测光控制模式个数  Maximum number of Metering mode count */
#define NETDEV_SHUTTER_TIME_RANGE_MAX_NUM           28              /* 最多支持的快门时间的取值的个数  Maximum number of shutter Time Range count */
#define NETDEV_SLOW_SHUTTER_TIME_RANGE_MAX_NUM      16              /* 最多支持的慢快门时间的取值的个数 Maximum number of slow shutter Time Range count */
#define NETDEV_WIDE_DYNAMIC_MODE_MAX_NUM            16              /* 最多支持的宽动态模式个数 Maximum number of wide dynamic mode count */
#define NETDEV_DAY_NIGHT_MODE_MAX_NUM               16              /* 最多支持的昼夜模式类型个数 Maximum number of slow Day Night Mode count */
#define NETDEV_AUDIO_IN_MAX_NUM                     16              /* 最多支持的音频口输入个数 Maximum number of Audio input count */
#define NETDEV_AUDIO_IN_CHL_MODE_MAX_NUM            8               /* 最多支持的音频输入通道模式个数 Maximum number of Audio input mode count */
#define NETDEV_AUDIO_IN_ENCODE_FORMAT_MAX_NUM       16              /* 最多支持的音频输入编码格式个数 Maximum number of Audio input encode format count */
#define NETDEV_AUDIO_SAMPLING_RATE_MAX_NUM          8               /* 最多支持的音频采样率个数 Maximum number of Audio sampling rate count */
#define NETDEV_SERIAL_IN_MAX_NUM                    16              /* 最多支持的串口输入个数 Maximum number of serial input count */
#define NETDEV_SERIAL_IN_ENCODE_FORMAT_MAX_NUM      16              /* 最多支持的串口输入编码格式个数 Maximum number of serial input encode format count */
#define NETDEV_FACE_FEATURE_SIZE                    512             /* 人脸特征信息 512B */
#define NETDEV_FACE_FEATURE_VERSION_LEN             40              /* 人脸特征模型版本号最大长度 */
#define NETDEV_FACE_FEATURE_LIST_FILE_LEN           256             /* 人脸特征库文件名最大长度 */
#define NETDEV_FACE_FEATURE_FILE_MD5_LEN            16              /* 人脸特征库文件的MD5值长度 */
#define NETDEV_FACE_FEATURE_GALLEY_ID_LEN           20              /* 人脸半结构化特征名单库ID长度 */
#define NETDEV_OBJ_TRACK_MODE_NUM                   8               /* 设备支持的智能跟踪模式数量 */
#define NETDEV_STREAM_MAX_NUM                       3               /* 最大支持的码流数量 */
#define NETDEV_PLAN_DAY_NUM_AWEEK                   7               /* 一周总共可配置的计划天数，包含周一到周日 */
#define NETDEV_PLAN_TIME_SECTION_NUM_ADAY           4               /* 一天可配置的时间段数 Total number of plans allowed in a day*/
#define NETDEV_XW_SERIAL_NUM                        16               /* 串口数量 */
#define NETDEV_DNS_LIST_NUM                         2               /* DNS列表数量 */
#define NETDEV_NETWORK_MACNAME_LEN                  48              /* MAC地址名称长度 */
#define NETDEV_LOG_QUERY_COND_NUM                   48              /* 日志查询条件数量 */
#define NETDEV_FACE_DB_NAME_LEN                     256             /* 人脸库名称长度最大值 */
#define NETDEV_FACE_MEMBER_NAME_LEN                 256             /* 人脸库成员名称长度最大值 */
#define NETDEV_FACE_MEMBER_REGION_LEN               256             /* 人脸库成员所在地区名称最大值 */
#define NETDEV_FACE_MEMBER_CUSTOM_NUM               5               /* 自定义属性列表个数 */
#define NETDEV_FACE_MEMBER_CUSTOM_LEN               255             /* 自定义属性值长度 */
#define NETDEV_FACE_IMAGE_MAX_LEN                   (2*1024*1024)   /* 人脸图片数据的最大长度，2M   2097152字节*/
#define NETDEV_FACE_DB_TITLE_NAME_LEN               508             /* 人脸库自定义属性名称最大长度 */
#define NETDEV_FACE_MONITOR_RULE_NAME_LEN           508             /*人脸布控任务的布控名称最大值 */
#define NETDEV_FACE_MONITOR_RULE_REASON_LEN         508             /*人脸布控的布控原因最大值 */
#define NETDEV_FACE_ALARM_SRC_LEN                   256             /* 抓拍通道名称长度 */
#define NETDEV_FACE_ANALYSIS_SKILL_NUM              16              /* 设备支持的人脸分析能力数量 */
#define NETDEV_FACE_MEMBER_BIRTHDAY_LEN             31              /* 成员出生日期字符串最大长度 */
#define NETDEV_FACE_IDNUMBER_LEN                    128             /*证件号最大范围*/
#define NETDEV_LABEL_ID_MAX_LEN                     32
#define NETDEV_TIME_RANGE_NUM                       8               /* 时间模板时间范围个数(周一到周日再加假日) */
#define NETDEV_TIME_DURATION_NUM                    8               /* 时间模板中一天最多8个片段 */
#define NETDEV_HOLIDAY_INFO_NUM                     32              /* 假日配置数量 */
#define NETDEV_AUDIO_MAX_NUM                        18              /* 音频输出业务数量 */
#define NETDEV_CREATE_CONNECT_NUMBER                1               /* 创建连接数量 */
#define NETDEV_EMERGENCY_BRLL_NAME_LEN              128             /*紧急铃名称最大长度*/
#define NETDEV_EMERGENCY_BRLL_MAX_NUM               120             /*紧急铃信息最大数量*/
#define NETDEV_FISHEYE_STREAM_EXIST                 2285            /* 鱼眼流存在,仅用于上报 */
#define NETDEV_FISHEYE_STREAM_NOT_EXIST             2286            /* 鱼眼流不存在,仅用于上报 */
#define NETDEV_VEHICLE_COMP_IMAGE_MAX_LEN           2097152         /* 车辆布控比对图片的最大长度 2M*/
#define NETDEV_VEHICLE_IMAGE_MAX_LEN                4194304         /* 车辆图片数据最大字节数 4M */

#define NETDEV_RES_CHANGE_INFO_LIST_NUM             64              /* 定义LAPI事件上报信息结构体 */

#define NETDEV_PHOTO_SERVER_MAX_NUM                 4               /* 照片服务器数量上限 Maximum number of Photo Server */

/* BIT位定义 */
#ifndef BIT0
#define BIT0  (0x1 << 0)
#define BIT1  (0x1 << 1)
#define BIT2  (0x1 << 2)
#define BIT3  (0x1 << 3)
#define BIT4  (0x1 << 4)
#define BIT5  (0x1 << 5)
#define BIT6  (0x1 << 6)
#define BIT7  (0x1 << 7)
#define BIT8  (0x1 << 8)
#define BIT9  (0x1 << 9)
#define BIT10 (0x1 << 10)
#define BIT11 (0x1 << 11)
#define BIT12 (0x1 << 12)
#define BIT13 (0x1 << 13)
#define BIT14 (0x1 << 14)
#define BIT15 (0x1 << 15)
#define BIT16 (0x1 << 16)
#define BIT17 (0x1 << 17)
#define BIT18 (0x1 << 18)
#define BIT19 (0x1 << 19)
#define BIT20 (0x1 << 20)
#define BIT21 (0x1 << 21)
#define BIT22 (0x1 << 22)
#define BIT23 (0x1 << 23)
#define BIT24 (0x1 << 24)
#define BIT25 (0x1 << 25)
#define BIT26 (0x1 << 26)
#define BIT27 (0x1 << 27)
#define BIT28 (0x1 << 28)
#define BIT29 (0x1 << 29)
#define BIT30 (0x1 << 30)
#define BIT31 (0x1 << 31)

#define BIT(nr)     (1UL << (nr))
#endif  /* BIT位定义 */


/* BEGIN****************************  Enum ************************************************************/
typedef enum tagNETDEVCommonErrCode
{
    NETDEV_E_FAILED                         = -1,           /* 失败  Failed*/
    NETDEV_E_SUCCEED                        = 0,            /* 成功  Succeeded*/
    NETDEV_E_SVC_FAILED                     = 1,            /* 服务器失败错误码  Common Failed*/
    NETDEV_E_NO_USER                        = 5,            /* 用户不存在 User does not exist*/

    NETDEV_E_NO_RESULT                      = 11,           /* 查无结果 No result */
    NETDEV_E_NOENOUGH_BUF                   = 12,           /* 缓冲区太小: 接收设备数据的缓冲区  Buffer is too small for receiving device data */
    NETDEV_E_SDK_SOCKET_LSN_FAIL            = 13,           /* 创建socket listen失败  Failed to create socket listen */
    NETDEV_E_INIT_MUTEX_FAIL                = 14,           /* 初始化锁失败  Failed to initialize lock */
    NETDEV_E_INIT_SEMA_FAIL                 = 15,           /* 初始化信号量失败  Failed to initialize semaphore */
    NETDEV_E_ALLOC_RESOURCE_ERROR           = 16,           /* SDK资源分配错误  Error occurred during SDK resource allocation */
    NETDEV_E_HAVEDATA                       = 17,           /* 还有数据   Data not all sent */
    NETDEV_E_NEEDMOREDATA                   = 18,           /* 需要更多数据  More data required  */
    NETDEV_E_TRANSFILE_FAIL                 = 19,           /* 文件传输失败  File transmission failed */
    NETDEV_E_DEVICE_TYPE_ERR                = 20,           /* 不支持的设备类型 Device type that are not supported */
    NETDEV_E_NONCE_TIMEOUT                  = 21,           /* nonce过期 Nonce expired */
    NETDEV_E_INNER_ERR                      = 22,           /* 系统内部错误 System internal error */
    NETDEV_E_PUBLICKEYFAIL                  = 23,           /* 公钥匹配失败 Failed to match publickey*/
    NETDEV_E_BINDNOTIFY_FAIL                = 24,           /* 绑定告警失败  Failed to bind alarms*/

    NETDEV_E_SYSCALL_FALIED                 = 100,          /* 系统函数调用失败，请查看errno  Failed to call system function. See errno */
    NETDEV_E_NULL_POINT                     = 101,          /* 空指针  Null pointer */
    NETDEV_E_INVALID_PARAM                  = 102,          /* 无效参数  Invalid parameter */
    NETDEV_E_INVALID_MODULEID               = 103,          /* 无效模块ID  Invalid module ID */
    NETDEV_E_INVALID_HANDLE                 = 104,          /* 无效的句柄 Invalid handle */
    NETDEV_E_NO_MEMORY                      = 105,          /* 内存分配失败 Memory allocation failed */
    NETDEV_E_FILE_NO_EXIST                  = 106,          /* 文件等不存在 File does not exist */
    NETDEV_E_NO_DEV                         = 107,          /* 设备不存在 Device does not exist*/
    NETDEV_E_NO_FIT_LOG                     = 108,          /* 符合条件的日志不存在 Qualified logs do not exist*/
    NETDEV_E_BUSY                           = 109,          /* busy状态 busy status */
    NETDEV_E_TIMER_REG_FAILED               = 110,          /* 注册定时器失败 Register timer failed */
    NETDEV_E_COMMON_FAILED                  = 111,          /* 通用错误 General error */
    NETDEV_E_CMD_NOT_SUPPORT                = 112,          /* 命令不支持 Command does not support */
    NETDEV_E_NOT_SUPPORT                    = 113,          /* 设备不支持该功能 The device does not support this function */
    NETDEV_E_TIMEOUT                        = 114,          /* 超时 Overtime */
    NETDEV_E_MSG_ERR                        = 115,          /* 消息不匹配 Message mismatch */
    NETDEV_E_MODULE_INEXIST                 = 116,          /* 模块不存在 Module does not exist */
    NETDEV_E_SOCKET_RECV_ERR                = 117,          /* 消息接收失败 Message acceptance failure */
    NETDEV_E_DECODE_IE_FAILED               = 118,          /* 获取消息IE失败 Failure to get message IE */
    NETDEV_E_ENCODE_IE_FAILED               = 119,          /* 添加消息IE失败 Failed to add message IE */
    NETDEV_E_SDK_NOINTE_ERROR               = 120,          /* SDK未初始化 SDK uninitialized */
    NETDEV_E_ALREDY_INIT_ERROR              = 121,          /* SDK已经初始化 SDK has been initialized */
    NETDEV_E_DEVICE_FACTURER_ERR            = 122,          /* 不支持的设备厂商 Unsupported equipment manufacturer */
    NETDEV_E_NAME_EXIST                     = 123,          /* 名称已存在 Name already exists */
    NETDEV_E_GET_CFG_FAILED                 = 124,          /* 获取配置信息出错 Error acquiring configuration information */
    NETDEV_E_SET_CFG_FAILED                 = 125,          /* 设置配置信息出错 Error setting configuration information */
    NETDEV_E_CHANNEL_OVER_SPEC              = 126,          /* 通道数超规格 Channel number exceeding specification */
    NETDEV_E_CALL_DRV_COMMON                = 127,          /* 调用驱动通用失败 Call driver universal failure */
    NETDEV_E_TOTAL_QUOTA_FULL               = 128,          /* 可分配的配额空间不足 Insufficient allocatable quota space */
    NETDEV_E_CALL_DB_COMMON                 = 129,          /* 调用数据库通用失败 Failure to invoke database universality */
    NETDEV_E_NEED_MORE_MEMORY               = 130,          /* 内存分配不足 Insufficient memory allocation */
    NETDEV_E_T2U_CONNECT_FAILED             = 131,          /* T2U连接失败 Failure of T2U connection */
    NETDEV_E_FUNC_IS_INITIALIZING           = 132,          /* 功能正在初始化中 Functions are being initialized */

    NETDEV_E_CONNECT_ERROR                  = 200,          /* 创建连接失败  Failed to create connection */
    NETDEV_E_SEND_MSG_ERROR                 = 201,          /* 发送消息失败 Failed to send message */
    NETDEV_E_DECODE_RSP_ERROR               = 202,          /* 解析响应消息失败  Failed to decode response message */
    NETDEV_E_NONSUPPORT                     = 203,          /* 该功能函数未实现  Function not supported */
    NETDEV_E_JSON_ERROR                     = 204,          /* Json 通用错误  Json common error */
    NETDEV_E_NORESULT                       = 205,          /* 查询结果为空 The query result is empty */
    NETDEV_E_SOCKET_RECV_ERROR              = 206,          /* Socket接收消息失败  Socket failed to receive message */
    NETDEV_E_CREATE_THREAD_FAIL             = 207,          /* 创建线程失败  Failed to create thread */
    NETDEV_E_RESCODE_NO_EXIST               = 208,          /* 资源编码不存在  Resource code not exist */
    NETDEV_E_MSG_DATA_INVALID               = 209,          /* 消息内容错误  Incorrect message content */
    NETDEV_E_JSON_NO_IMAGE                  = 210           /* 图片数据为空 Picture data is empty */
}NETDEV_COMMON_ECODE_E;

/* 媒体相关错误码 */
typedef enum tagNETDEVMediaErrCode
{
    NETDEV_E_PLAYER_FAIL                        = 1001,     /* 执行失败 Execution failure */
    NETDEV_E_PLAYER_INVALID_PARAM               = 1002,     /* 输入参数非法 Illegal input parameters */
    NETDEV_E_PLAYER_NO_MEMORY                   = 1003,     /* 系统内存不足 Insufficient system memory */
    NETDEV_E_PLAYER_SOCKET_FAIL                 = 1004,     /* 创建SOCKET失败 Failure to create SOCKET */
    NETDEV_E_PLAYER_RECV_FAIL                   = 1005,     /* 接收失败 Failure to receive */
    NETDEV_E_PLAYER_RECV_ZERO                   = 1006,     /* 接收为零 Receive zero */
    NETDEV_E_PLAYER_NOT_SUPPORT                 = 1007,     /* 功能暂不支持 Function not supported for the time being */
    NETDEV_E_PLAYER_CREATETHREAD_FAILED         = 1008,     /* 创建线程失败 Failed to create thread */
    NETDEV_E_PLAYER_OPENDL_FAILED               = 1009,     /* 加载动态库失败 Failure to load dynamic library */
    NETDEV_E_PLAYER_SYMDL_FAILED                = 1010,     /* 获取动态方法失败 Failure to obtain dynamic methods */
    NETDEV_E_PLAYER_SEND_FAILED                 = 1011,     /* 发送失败 Fail in send */
    NETDEV_E_PLAYER_EACCES                      = 1012,     /* 创建文件权限不足 Insufficient permission to create files */
    NETDEV_E_PLAYER_FILE_NOT_FIND               = 1013,     /* 读文件未找到 Reading file not found */
    NETDEV_E_PLAYER_LOG_CLOSE                   = 1014,     /* 日志关闭 Log closes */

    /*********************** Player 资源相关********************************/
    NETDEV_E_FAIL_TO_INIT_EZPLAYER              = 1257,     /* 初始化播放器失败 Initialization player failed */
    NETDEV_E_FAIL_TO_ALLOC_PORT_RES             = 1258,     /* 分配播放通道资源失败 Failed to allocate playback channel resources */
    NETDEV_E_FAIL_TO_GET_PORT_RES               = 1259,     /* 获得播放通道资源失败 Failed to obtain playback channel resources*/
    NETDEV_E_BUFFER_QUEUE_FULL                  = 1260,     /* 缓存队列已满 Cache queue full */
    NETDEV_E_BUFFER_QUEUE_EMPTY                 = 1261,     /* 缓存队列空 Cache queue empty */
    NETDEV_E_OPEN_FILE_FAILED                   = 1262,     /* 打开文件失败 Fail to open file */
    NETDEV_E_FILE_READ_END                      = 1263,     /* 文件已经读取完毕 The file has been read out */
    NETDEV_E_FILE_DISKSPACE_FULL                = 1264,     /* 磁盘空间满 Disk space is full */
    NETDEV_E_FILE_READ_FAIL                     = 1265,     /* 读取失败 Read failure */
    NETDEV_E_MCM_MIC_NOT_EXIST                  = 1266,     /* 麦克风不存在 Microphone does not exist */
    NETDEV_E_TS_PACKET_IN_THE_ROUGH             = 1267,     /* TS打包未完成 TS packaging not completed */
    NETDEV_E_FILE_RECORD_FINISH                 = 1268,     /* 录像保存完毕 The video has been saved.*/

    NETDEV_E_FAIL_TO_OPEN_STREAM                = 1513,     /* 启动媒体流播放失败 Failed to start media stream playback */
    NETDEV_E_FAIL_TO_CLOSE_STREAM               = 1514,     /* 关闭媒体流播放失败 Failed to shut down media stream playback */
    NETDEV_E_FAIL_TO_RECV_DATA                  = 1515,     /* 网络故障导致接收数据失败 Failure of receiving data due to network failure */
    NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         = 1516,     /* 媒体数据处理失败 Media data processing failure */
    NETDEV_E_NOT_START_PLAY                     = 1517,     /* 播放通道未开始播放操作 Play channel did not start playback operation */
    NETDEV_E_FAIL_TO_INPUT_DATA                 = 1518,     /* 输入媒体流数据失败 Input media streaming data failed */
    NETDEV_E_INPUTDATA_BUFFER_FULL              = 1519,     /* 输入数据缓存满 Input data cached full */
    NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        = 1520,     /* 设置媒体流数据回调函数失败 Failed to set media stream data callback function */
    NETDEV_E_VOICE_RUNNING                      = 1521,     /* 语音业务运行过程中出错 Errors in Voice Service Operation */
    NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             = 1522,     /* 启动语音业务失败 Failure to start voice service */
    NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            = 1523,     /* 关闭语音业务失败 Failed to shut down voice service */
    NETDEV_E_UNKNOWN_STREAM_TYPE                = 1524,     /* 未知媒体流 Unknown media stream */
    NETDEV_E_PACKET_LOSE                        = 1525,     /* 丢包 Packet loss */
    NETDEV_E_NEED_MORE_PACKET                   = 1526,     /* 拼包未完成，需要更多包 Packing is not completed, more packages are needed */
    NETDEV_E_FAIL_TO_CREATE_DECODE              = 1527,     /* 创建解码器失败 Failed to create decoder */
    NETDEV_E_FAIL_TO_DECODE                     = 1528,     /* 解码失败 Decoding failure */
    NETDEV_E_RECV_DATA_NOTENOUGH                = 1529,     /* 接收数据不足 Insufficient data received */
    NETDEV_E_RENDER_RES_FULL                    = 1530,     /* 显示资源满 Display full resources */
    NETDEV_E_RENDER_RES_NOT_EXIST               = 1531,     /* 显示资源不存在 Show that resources do not exist */
    NETDEV_E_CREATE_DEV_FAILED                  = 1532,     /* 资源创建失败 Resource creation failed */
    NETDEV_E_AUDIO_RES_NOT_EXIST                = 1533,     /* 音频资源不存在 Audio resources do not exist */
    NETDEV_E_IHW265D_NEED_MORE_BITS             = 1534,     /* 解码器需要更多数据 Decoder needs more data */
    NETDEV_E_FAIL_TO_CREATE_ENCODE              = 1535,     /* 创建编码器失败 Failure to create encoder */
    NETDEV_E_CAPTURE_RES_EXIST                  = 1536,     /* 采集资源不存在 Collection resources do not exist */
    NETDEV_E_RECORD_STARTED                     = 1537,     /* 录像已打开 The video has been turned on */
    NETDEV_E_NEED_WAIT_DECODEC                  = 1538,     /* 未解码完成，需要等待 Undecoded, need to wait */
    NETDEV_E_MORE_DATA_NEED_PACKET              = 1539,     /* 数据过多，还需要继续打包 There's too much data to pack. */
    NETDEV_E_AAC_LC_DECODE_FAIL                 = 1540,     /* AAC_LC解码失败 AAC_LC decode failure*/
    NETDEV_E_RENDER_SURFACELOST                 = 1541,     /* 显示表面丢失 */
    NETDEV_E_PLAYBACK_FINISH                    = 1542,     /* 回放结束 Playback end*/

    /* 媒体会话业务异常上报错误码 */
    NETDEV_E_SESSION_NET_FAILED                 = 1900,     /* 会话网络错误 Network error */
    NETDEV_E_SESSION_NET_TIMEOUT                = 1901,     /* 会话网络超时 Network timeout */
    NETDEV_E_SESSION_SHAKE_FAILED               = 1902,     /* 会话交互错误 Interaction error */
    NETDEV_E_SESSION_STREAMNUM_FULL             = 1903,     /* 流数已经满 Stream full */
    NETDEV_E_SESSION_STREAM_THIRDSTOP           = 1904,     /* 第三方停止流 Third party stream stopped */
    NETDEV_E_SESSION_FILE_END                   = 1905,     /* 文件结束 File ended */
    NETDEV_E_SESSION_STREAM_DOWNLOAD_OVER       = 1906,     /* 一体机国标流下载完成  Download of National Standard Stream in One Machine */
    NETDEV_E_SESSION_RTMP_CONNECT_FAIL          = 1907,     /* RTMP连接失败 RTMP connection failed */
    NETDEV_E_SESSION_RTMP_INIT_FAIL             = 1908,     /* RTMP初始化失败 RTMP initialization failed */

    NETDEV_E_LIVE_EXISTED                       = 2000,     /* 实况业务已经建立 Live business has been established */
    NETDEV_E_LIVE_INPUT_NOT_READY               = 2001,     /* 媒体流未准备就绪 Media streaming is not ready */
    NETDEV_E_LIVE_OUTPUT_BUSY                   = 2002,     /* 实况业务显示资源忙 Live business display resources busy */
    NETDEV_E_LIVE_CB_NOTEXIST                   = 2003,     /* 实况控制块不存在 Real-time control block does not exist */
    NETDEV_E_LIVE_STREAM_FULL                   = 2004,     /* 实况流资源已满 Real-time flow resources are full */

    NETDEV_E_AUDIO_EXISTED                      = 2100,     /* 语音对讲已存在 Speech intercom already exists */
    NETDEV_E_AUDIO_NO_EXISTED                   = 2101,     /* 语音业务不存在 Voice service does not exist */
    NETDEV_E_AUDIO_RESCODE_INVALID              = 2102,     /* 语音对讲资源编码无效 Invalid encoding of voice intercom resources */
    NETDEV_E_AUDIO_FAILED                       = 2104,     /* 语音对讲失败 Speech intercom failure */

    NETDEV_E_CAPTURE_NO_SUPPORT_FORMAT          = 2200,     /* 抓拍格式不支持 Snapshot format does not support  */
    NETDEV_E_CAPTURE_NO_ENOUGH_CAPACITY         = 2201,     /* 硬盘空间不足 Insufficient hard disk space */
    NETDEV_E_CAPTURE_NO_DECODED_PICTURE         = 2202,     /* 没有解码过的图片可供抓拍 Undecoded pictures can be captured */
    NETDEV_E_CAPTURE_SINGLE_FAILED              = 2203,     /* 单次抓拍操作失败 Single snap operation failed */

    NETDEV_E_OVER_ABILITY                       = 2301,     /* 码流超出能力集 Bit stream excess capability set */

	/* 云媒体业务异常上报  Cloud media view exception report 2793~2809 */
	NETDEV_E_CLOUD_DOWNLOAD_FINISH              = 2793,     /* 下载完成 */
	NETDEV_E_CLOUD_PARSE_DOMAIN_FAIL            = 2794,     /* 解析域名失败 */
	NETDEV_E_CLOUD_CONNECT_FAIL                 = 2795,     /* 连接失败 */
	NETDEV_E_CLOUD_CONNECT_TIMEOUT              = 2796,     /* 连接超时 */
	NETDEV_E_CLOUD_DOWNLOAD_TIMEOUT             = 2797,     /* 下载超时 */
	NETDEV_E_CLOUD_DOWNLOAD_FAIL                = 2798,     /* 下载失败 */
	NETDEV_E_CLOUD_NETWORK_POOR                 = 2799,     /* 网络较差 */
	NETDEV_E_CLOUD_PLAY_FINISH                  = 2800,     /* 播放完成 */
	NETDEV_E_CLOUD_DISK_FULL                    = 2801,     /* 磁盘空间满 */
	NETDEV_E_CLOUD_AUTH_FAIL                    = 2802,     /* 鉴权失败 */
	NETDEV_E_CLOUD_CURRENT_TIME                 = 2803,     /* 当前播放时间，仅用于上报 */
	NETDEV_E_CLOUD_PRIOR_DISK_FULL              = 2804,     /* 磁盘预值满 */
	NETDEV_E_CLOUD_NODE_NOT_EXIST               = 2805,     /* 时间节点不存在 */
	NETDEV_E_CLOUD_NO_CACHE_PATH                = 2806,     /* 未设置缓存路径 */
	NETDEV_E_CLOUD_MSG_SEND_FAIL                = 2807,     /* 消息发送失败 */
	NETDEV_E_CLOUD_TASK_CANCELLED               = 2808,     /* 任务已取消 */
	NETDEV_E_CLOUD_TASK_STREAM_CONTINUE         = 2809,     /* 流继续播放 */

    NETDEV_E_MEDIA_INPUT_NOT_READY              = 10000,    /* 媒体流未准备就绪 Media streaming is not ready */
    NETDEV_E_CCB_STATR_INVALID                  = 10001,    /* 控制块状态不可用 Control block state unavailable */
    NETDEV_E_MEDIA_OUTPUT_BUSY                  = 10002,    /* 实况业务显示资源繁忙 Live business display resource busy */
    NETDEV_E_MEDIA_START_LOCAL_LIVE_ERR         = 10003,    /* 实况媒体流未准备就绪 Live media streams are not ready */
    NETDEV_E_MEDIA_START_LOCAL_REPLAY_ERR       = 10004,    /* 回放媒体流未准备就绪 Playback media streams are not ready */

    NETDEV_E_MEDIA_BW_RECV_NOT_ENOUGH           = 10007,    /* 网络接收带宽不足 Insufficient network reception bandwidth */
    NETDEV_E_MEDIA_BW_SEND_NOT_ENOUGH           = 10008,    /* 网络发送带宽不足 Insufficient network transmission bandwidth */
    NETDEV_E_MEDIA_AUDIO_BROADCAST_TO_LIMIT     = 10009,    /* 语音广播业务已达上限 Voice broadcasting service has reached the upper limit */
    NETDEV_E_MEDIA_AUDIO_CHL_BING_USED          = 10010,    /* 音频通道已被占用 Audio channel has been occupied */

    NETDEV_E_MEDIA_MAX                          = 10399     /* 媒体相关错误码最大值 Maximum Media Related Error Code */
}NETDEV_MEDIA_ECODE_E;

/* 云台模块错误码 */
typedef enum tagNETDEVPtzErrCode
{
    NETDEV_E_SET_PRESET_FAILED                  = 10400,    /* 预置位设置失败 Failure of preset setting */
    NETDEV_E_QUERY_PRESET_FAILED                = 10401,    /* 预置位查询失败 Failure of preset query */
    NETDEV_E_QUERY_TRACK_FAILED                 = 10402,    /* 轨迹查询失败 Trajectory Query Failure */
    NETDEV_E_START_RECORD_TRACK_FAILED          = 10403,    /* 开始录制轨迹失败 Failure to start recording trajectory */
    NETDEV_E_STOP_RECORD_TRACK_FAILED           = 10404,    /* 结束录制轨迹失败 Failure to end recording trajectory */
    NETDEV_E_QUERY_CRUISE_FAILED                = 10405,    /* 巡航线路查询失败 Cruise line query failed */
    NETDEV_E_SET_CRUISE_FAILED                  = 10406,    /* 巡航线路设置失败 Failure to set up cruise routes */
    NETDEV_E_PTZ_COMMAND_FAILED                 = 10407,    /* 云台操作失败 PTZ operation failed */
    NETDEV_E_PRESET_IN_CRUISE                   = 10408,    /* 预置位在巡航线路中使用, 无法删除 Pre-positioning is used in cruise routes and cannot be deleted */
    NETDEV_E_CRUISEPOINT_ER                     = 10409,    /* 设置巡航点不连续 Setting Cruise Points Discontinuous */
    NETDEV_E_TRACK_ISUSED                       = 10410,    /* 轨迹已使用，无法删除 Track is in use and cannot be deleted */
    NETDEV_E_SERIALMODE_MISMATCH                = 10411,    /* 串口模式不匹配 Serial port mode mismatch */
    NETDEV_E_TRACK_NOT_EXIST                    = 10412,    /* 轨迹不存在 Trajectory does not exist */
    NETDEV_E_MODE_CRUISE_FULL                   = 10413,    /* 模式路径轨迹点个数已满 Number of path trajectory points of patterns is full*/
    NETDEV_E_PTZ_ISUSED                         = 10414,    /* 云台使用中 PTZ in use */
    NETDEV_E_PRESET_IN_GUARD                    = 10415,    /* 预置位在守望中使用 Prepositioning in Watch */
    NETDEV_E_CRUISE_PATH_IN_GUARD               = 10416,    /* 巡航路径在守望中使用 Cruise Path Used in Watch */

    NETDEV_E_PTZ_MAX                            = 10799     /* 云台模块错误码最大值 Maximum error code of PTZ module */
}NETDEV_PTZ_ECODE_E;


/* 回放模块错误码 */
typedef enum tagNETDEVVodErrCode
{
    NETDEV_E_VOD_ABEND                          = 10800,    /* 回放异常结束 Playback abnormal end */
    NETDEV_E_VOD_END                            = 10801,    /* 回放结束 Playback end */
    NETDEV_E_VOD_CALL_DRV                       = 10802,    /* 调用驱动接口失败 Failed to call driver interface */
    NETDEV_E_VOD_CB_NOT_FIND                    = 10803,    /* 控制块未找到 Control block not found */
    NETDEV_E_VOD_OVER_ABILITY                   = 10804,    /* 超过回放能力 Exceeding playback capability */
    NETDEV_E_VOD_TAG_OVER_LIMIT                 = 10805,    /* 标签数量超过限制 The number of labels exceeds the limit */
    NETDEV_E_VOD_NO_RECORDING                   = 10806,    /* 无录像内容   No recording */
    NETDEV_E_VOD_SMART_NOT_SUPPORT              = 10807,    /* 国标设备不支持智能回放 GB device does not support smart playback*/
    NETDEV_E_VOD_NO_REPLAYURL                   = 10808,    /* 无法获取回放的url   Cannot get the URL for playback*/

    NETDEV_E_VOD_MAX                            = 10999     /* 回放模块错误码最大值 Maximum error code of playback module */
}NETDEV_VOD_ECODE_E;

/* 存储模块错误码 */
typedef enum tagNETDEVStorErrCode
{
    NETDEV_E_STOR_ABEND                         = 101000,   /* 存储异常结束 Storage exception termination */
    NETDEV_E_ARRAY_NAME_EXITS                   = 11001,    /* 阵列已存在 Array already exists */
    NETDEV_E_NOT_RAID_MODE                      = 11002,    /* 非阵列模式 Non-array mode */
    NETDEV_E_NO_STORE_PLAN                      = 11003,    /* 该通道没有配置过录像计划 The channel is not equipped with a video plan. */
    NETDEV_E_DISK_ZERO_OR_ABNORMAL              = 11022,    /* 无硬盘或硬盘异常 No hard disk or hard disk abnormalities */
    NETDEV_E_SLOT_NOT_NORMAL                    = 11023,    /* 槽位1磁盘状态不正常 Slot 1 disk is out of order*/
    NETDEV_E_SLOT_RECONNECT                     = 11024,    /* 开启人脸后槽位1拔掉又插上，需要重启 After opening the face, slot 1 is pulled out and inserted. It needs to be restarted. */

    NETDEV_E_STOR_MAX                           = 11199     /* 存储模块错误码最大值 Maximum error code of storage module */
}NETDEV_STOR_ECODE_E;

/* 用户模块错误码 */
typedef enum tagNETDEVUserErrCode
{
    NETDEV_E_USER_NOT_ONLINE                    = 101200,   /* 用户不在线 Users are not online */
    NETDEV_E_USER_WRONG_PASSWD                  = 11201,    /* 用户密码错误 User password error */
    NETDEV_E_USER_NO_SUCH_USER                  = 11202,    /* 没有该用户 No user */
    NETDEV_E_USER_NO_AUTH                       = 11203,    /* 用户无权限 User has no privilege */
    NETDEV_E_USER_MAX_NUM                       = 11204,    /* 用户上限-不能再被添加 User cap - cannot be added */
    NETDEV_E_USER_EXIST                         = 11205,    /* 用户已存在 User already exists */
    NETDEV_E_USER_LOGIN_MAX_NUM                 = 11206,    /* 用户登录数已达上限 The number of users logged in has reached the upper limit. */
    NETDEV_E_USER_LOCKED                        = 11207,    /* 用户已被锁定 The user has been locked */
    NETDEV_E_USER_IS_ADMIN                      = 11208,    /* 不允许此操作，用户是系统管理员 This operation is not allowed. The user is the system administrator. */
    NETDEV_E_USER_NOT_VALID_PERIOD              = 11209,    /* 不在有效期内 Not within the validity period */
    NETDEV_E_USER_ROLE_BEYOND_RANGE             = 11210,    /* 用户角色个数超过上限 The number of user roles exceeds the upper limit */
    NETDEV_E_USER_SELOG_IP_LOCKED               = 11211,    /* 用户安全登录锁定 User security logon lock*/
    NETDEV_E_ROLE_EXIST                         = 11212,    /* 角色已存在 Roles already exist */
    NETDEV_E_USER_NOT_VALID_TIME                = 11213,    /* 不在有效时段内 Not in the valid period */
    NETDEV_E_USER_WEAK_PASSWD_LOGIN_FAIL        = 11214,    /* 登录失败,请在本地网络修改成强密码后再次尝试远程登录 Logon failed. Please try remote login again after changing the local network to a strong password. */
    NETDEV_E_USER_IS_TEMPPASSWD                 = 11217,    /* 用户使用临时密码登录 Users log in with temporary passwords */
    NETDEV_E_USER_TEMPPASSWD_LOGIN_FAIL         = 11218,    /* 公网临时密码禁止登陆 Temporary password of public network prohibits landing */
    NETDEV_E_USER_WEAK_PASSWD_MODIFY            = 11219,    /* 强制修改密码 Force password modification */
    NETDEV_E_USER_IP_NO_AUTH                    = 11221,    /* 登录IP无权限 Login IP has no permission */

    NETDEV_E_USER_MAX                           = 11599     /* 用户模块错误码最大值 Maximum error code of user module*/
}NETDEV_USER_ECODE_E;


/* 设备管理模块错误码 */
typedef enum tagNETDEVDevErrCode
{
    NETDEV_E_DEV_NOT_ONLINE                     = 11600,    /* 设备不在线 The device is not online */
    NETDEV_E_DEV_WRONG_PASSWD                   = 11601,    /* 设备密码错误 Device password error */
    NETDEV_E_DEV_REPEAT_DEV                     = 11602,    /* 重复设备 Repetitive equipment */
    NETDEV_E_DEV_NO_SUCH_DEV                    = 11603,    /* 没有该设备 No equipment */
    NETDEV_E_DEV_NO_SUCH_CHL                    = 11604,    /* 没有该通道 No channel */
    NETDEV_E_DEV_MAX_NUM                        = 11605,    /* 一体机设备上限-不能再被添加 VMS equipment upper limit - Can't be added anymore*/
    NETDEV_E_DEV_LOGIN_MAX_NUM                  = 11606,    /* 设备登录数上限 Upper limit of device logon number */
    NETDEV_E_DEV_COMMON_FAILED                  = 11607,    /* 由设备返回的通用错误 Common errors returned by devices */
    NETDEV_E_DEV_NO_SUCH_DEV_OID                = 11608,    /* 不存在设备历史ID No device history ID exists */
    NETDEV_E_DEV_DEL_FORBID                     = 11609,    /* 设备不允许删除 Devices are not allowed to be deleted */
    NETDEV_E_CHL_OFFLINE                        = 11610,    /* 通道不在线 Channel not online */
    NETDEV_E_DEV_TYPE_UNMATCHED                 = 11611,    /* 所添加设备类型不匹配 Mismatch of device type added */
    NETDEV_E_DEV_REPEAT_DEV_NAME                = 11612,    /* 设备名称重复 Duplicate device name */
    NETDEV_E_DEV_CFG_FAILED                     = 11613,    /* 设备配置失败 Device configuration failure */
    NETDEV_E_DEV_NO_RESULT                      = 11614,    /* 查询无结果 Inquiries without results */
    NETDEV_E_DEV_DEC_OFFLINE                    = 11617,    /* 解码设备离线  11615、11616错误码一体机内部已使用，所以新增为11617 Decoding equipment offline 11615, 11616 error code integration machine has been used, so the new 11617 */

    /* 升级相关错误码 */
    NETDEV_E_COMMON_FAIL_STAT                   = 11801,    /* 读取文件（目录）状态失败 Failed to read file (directory) status */
    NETDEV_E_COMMON_FILE_NONEXIST               = 11802,    /* 文件不存在 File does not exist */
    NETDEV_E_COMMON_MKDIR_ERR                   = 11803,    /* 创建目录失败 Failed to create directory */
    NETDEV_E_SUBSCRIBE_FULL                     = 11804,    /* 本用户订阅已满, 设备侧用户订阅已满的错误码不能返回 This user's subscription is full and the error code of the device side user's subscription is full cannot be returned. */
    NETDEV_E_UPGRADE_NOTADMIN                   = 11805,    /* 非admin用户无法升级 Non-admin users cannot upgrade */
    NETDEV_E_UPGRADE_INVALID                    = 11806,    /* 升级 未开始 Upgrade not started */
    NETDEV_E_UPGRADE_INPROCESS                  = 11807,    /* 升级 处理中 Upgrade processing */
    NETDEV_E_UPGRADE_NOMEMORY                   = 11808,    /* 升级 内存空间不够 Insufficient upgrade memory space */
    NETDEV_E_UPGRADE_FILE_OPEN_ERR              = 11809,    /* 升级 打开镜像文件出错 Upgrade error opening mirror file */
    NETDEV_E_UPGRADE_DEVICE_ERR                 = 11810,    /* 升级 FLASH出错 Error upgrading FLASH */
    NETDEV_E_UPGRADE_BUSY                       = 11811,    /* 不能同时加载多个升级进程 Multiple upgrade processes cannot be loaded at the same time */
    NETDEV_E_UPGRADE_FAIL_TIMEOUT               = 11812,    /* 升级超时 Upgrade timeout */
    NETDEV_E_INVALID_CONFIGFILE                 = 11813,    /* 配置文件无效 Invalid configuration file */
    NETDEV_E_STOR_RESOURCE_NOTINIT              = 11814,    /* 存储资源未分配 Unallocated storage resources */

    NETDEV_E_DEV_MAX                            = 11999     /* 设备模块错误码最大值 Maximum error code of equipment module */

}NETDEV_DEV_ECODE_E;

/* 组织管理模块错误码 */
typedef enum tagNETDEVOrgErrCode
{
    NETDEV_E_ORG_MAX_NUM                        = 12000,    /* 组织上限-不能再被添加 Organizational cap - cannot be added */
    NETDEV_E_ORG_MAX_LEVEL                      = 12001,    /* 组织层级上限 Upper limit of organizational hierarchy */
    NETDEV_E_ORG_RESOURCE_EXIST                 = 12002,    /* 组织下有资源-不能被删除 Organizational resources - cannot be deleted */
    NETDEV_E_ORG_EXIST                          = 12003,    /* 同分支下组织已存在 Organizations already exist under the same branch*/
    NETDEV_E_ORG_NO_SUCH_ORG                    = 12004,    /* 组织不存在 Organization does not exist */
    NETDEV_E_ORG_IS_ROOT                        = 12005,    /* 不允许此操作，组织是根组织 This operation is not allowed. The organization is the root organization.*/
    NETDEV_E_ORG_NO_SUCH_PORG                   = 12006,    /* 父组织不存在 Paternal organization does not exist */
    NETDEV_E_ORG_SUB_EXIST                      = 12007,    /* 组织下有组织,不能被删除 Organized, not deleted */

    NETDEV_E_ORG_MAX                            = 12399     /* 组织模块最大错误码值 Maximum error code value of organization module*/
}NETDEV_ORG_ECODE_E;


/* 电视墙管理模块错误码 */
typedef enum tagNETDEVTvwallErrCode
{
    NETDEV_E_TVWALL_DCCHL_CONFLICT              = 12400,    /* 绑定解码通道冲突-该通道已绑定同预案内其他电视墙窗口 Binding Decoding Channel Conflict - This channel is bound to other TV wall windows in the plan */
    NETDEV_E_TVWALL_NOT_FOUND                   = 12401,    /* 对象不存在 Object does not exist */
    NETDEV_E_TVWALL_PLAYING_TASK                = 12402,    /* 正在联动上墙 Linking up the wall */
    NETDEV_E_TVWALL_CMD                         = 12403,    /* 非法请求 Illegal request */
    NETDEV_E_TVWALL_START_SCENE                 = 12404,    /* 正在启用场景 Enabling scenarios */
    NETDEV_E_TVWALL_DATA_OUT_OF_SYNC            = 12405,    /* 设备数据不同步 Equipment data asynchronization */
    NETDEV_E_TVWALL_OUT_OF_DEV_CAP              = 12406,    /* 超出设备能力 Beyond Equipment Capability */
    NETDEV_E_TVWALL_SCENE_OVER_LIMIT            = 12407,    /* 场景数目超过限制 The number of scenes exceeds the limit */
    NETDEV_E_TVWALL_PLAYING_GROUPSCHEME         = 12408,    /* 正在组轮巡 Round trip under way */
    NETDEV_E_TVWALL_NOT_WND                     = 12409,    /* 场景中窗口不存在 Window does not exist in the scene */
    NETDEV_E_TVWALL_COLLIGER_INTER_ERR          = 12410,    /* 拼控器内部错误 Internal errors in the spelling controller */
    NETDEV_E_TVWALL_WND_NUMLIMITED              = 12411,    /* 窗口数量超过限制 The number of windows exceeds the limit */
    NETDEV_E_TVWALL_NUMLIMTED                   = 12412,    /* 电视墙数量超过限制 The number of TV walls exceeds the limit */
    NETDEV_E_TVWALL_LED_NUMLIMTED               = 12413,    /* 虚拟LED数量超过限制 The number of virtual LEDs exceeds the limit */
    NETDEV_E_TVWALL_LED_LINELIMTED              = 12414,    /* 单个虚拟LED行数超出限制 Single virtual LED line number exceeding limit */
    NETDEV_E_TVWALL_BASEPIC_NUMLIMITED          = 12415,    /* 设备能存储的底图数量超出限制 The number of base diagrams that the device can store exceeds the limit */
    NETDEV_E_TVWALL_BASEPIC_SCENELIMITED        = 12416,    /* 单场景能绑定的底图数量超出限制 The number of backgrounds that a single scene can bind exceeds the limit */
    NETDEV_E_TVWALL_DECODE_OUTRANGE             = 12417,    /* 目的位置已超解码能力 Destination position super-decoding capability */
    NETDEV_E_TVWALL_WND_OUTRANGE                = 12418,    /* 开窗面积已超过三倍面积 The area of window opening has exceeded three times the area of window opening.*/
    NETDEV_E_TVWALL_WND_RANGELIMITED            = 12419,    /* 开窗位置/漫游位置超出范围 Window position/roaming position out of range */
    NETDEV_E_TVWALL_WND_LOCKED                  = 12420,    /* 当前窗口已被锁定 The current window has been locked */
    NETDEV_E_TVWALL_LED_NOTEXIST                = 12421,    /* 虚拟LED不存在 Virtual LED does not exist */
    NETDEV_E_TVWALL_SEQ_EXISTD                  = 12422,    /* 轮切已经存在 Rotary cutting already exists */
    NETDEV_E_TVWALL_WND_NOTEXIST                = 12423,    /* 窗口不存在 Window does not exist */
    NETDEV_E_TVWALL_WND_EXIST                   = 12424,    /* 窗口已经存在 The window already exists */
    NETDEV_E_TVWALL_SPILT_NOTEXIST              = 12425,    /* 窗口中的分屏不存在 The split screen in the window does not exist */
    NETDEV_E_TVWALL_WND_NOSPILT                 = 12426,    /* 窗口不能分屏 Windows cannot be split */
    NETDEV_E_TVWALL_CHANNEL_UESED               = 12427,    /* 解码通道被其他电视墙占用 Decoding channel occupied by other TV wall */
    NETDEV_E_TVWALL_WINDEXIST                   = 12428,    /* 电视墙存在窗口 TV Wall Existence Window */
    NETDEV_E_TVWALL_NOTEXIST                    = 12429,    /* 电视墙信息不存在 TV wall information does not exist */
    NETDEV_E_TVWALL_SPLIT_INFOERR               = 12430,    /* 错误的分屏类型 Error splitting type */
    NETDEV_E_TVWALL_CHANNEL_NUMERR              = 12431,    /* 通道数量错误 Error in channel number */
    NETDEV_E_TVWALL_ROLLING_LED_NUMLIMITED      = 12432,    /* 滚动虚拟LED个数超出限制 The number of Rolling virtual LEDs exceeds the limit */
    NETDEV_E_TVWALL_MAX                         = 12799     /* 电视墙模块最大错误码值 Maximum error code value of tv wall module*/
}NETDEV_TVWALL_ECODE_E;


/* 网络相关错误码 */
typedef enum tagNETDEVNetErrCode
{
    NETDEV_E_IPADDR_CONFLICT                    = 12800,    /* IP地址冲突 IP Address Conflict */
    NETDEV_E_UPNP_PORT_DISCARD                  = 12801,    /* 映射的端口已废弃 The mapped port is discarded */
    NETDEV_E_UPNP_PORT_EMPLOY                   = 12802,    /* 端口已占用 Port occupied */
    NETDEV_E_SET_VMP_PORT_FAILED                = 12803,    /* 设置VMP端口失败 Failed to set VMP port */
    NETDEV_E_SET_MEDIA_PORT_FAILED              = 12804,    /* 设置媒体流端口失败 Failed to set media stream port */
    NETDEV_E_SET_RTSP_PORT_FAILED               = 12805,    /* 设置RTSP端口失败 Failed to set RTSP port */
    NETDEV_E_SET_ONVIF_PORT_FAILED              = 12806,    /* 设置ONVIF端口失败 Failed to set ONVIF port */
    NETDEV_E_SET_HTTPS_PORT_FAILED              = 12807,    /* 设置HTTPS端口失败 Failed to set HTTPS port */
    NETDEV_E_SET_HTTP_PORT_FAILED               = 12808,    /* 设置HTTP端口失败 Failed to set HTTP port */
    NETDEV_E_TEST_EMAIL                         = 12809,    /* 发送测试邮件失败 Failed to send test mail */
    NETDEV_E_DDNS_INIT                          = 12810,    /* 初始化默认值 Initialize default values */
    NETDEV_E_DDNS_GOOD                          = 12811,    /* 更新完成 Update completed*/
    NETDEV_E_DDNS_NOCHG                         = 12812,    /* 更新完成,但是ip地址没有变化 The update is complete, but the IP address remains unchanged */
    NETDEV_E_DDNS_BADAUTH                       = 12813,    /* 错误的用户名密码 Error username password */
    NETDEV_E_DDNS_DONATOR                       = 12814,    /* 专用的选项要求类似offline URL的服务费 Special options require service fees similar to offline URLs */
    NETDEV_E_DDNS_NOTFQ                         = 12815,    /* 主机名格式不合格 Host name format is not qualified */
    NETDEV_E_DDNS_NOHOST                        = 12816,    /* 不存在该主机名账户 The hostname account does not exist */
    NETDEV_E_DDNS_NUMHOST                       = 12817,    /* 请求立即更新多于20个主机 More than 20 hosts are requested to update immediately */
    NETDEV_E_DDNS_ABUSE                         = 12818,    /* 主机名由于滥用而被禁用 Host name is disabled due to abuse */
    NETDEV_E_DDNS_BADAGENT                      = 12819,    /* 代理发送错误的HTTP请求格式 The proxy sends the wrong HTTP request format */
    NETDEV_E_DDNS_GOOD_127                      = 12820,    /* 除非客户端想要更新127.0.0.1，否则该信息表明在http请求规格中发生错误 Unless the client wants to update 127.0.0.1, this information indicates an error in the HTTP request specification */
    NETDEV_E_DDNS_DNSERR                        = 12821,    /* DNS错误，请联系Support DNS error, please contact Support*/
    NETDEV_E_DDNS_911                           = 12822,    /* 服务维护正在处理 Service maintenance is being processed */
    NETDEV_E_DDNS_REQ                           = 12823,    /* DDNS请求发送失败 DDNS request failed to send */
    NETDEV_E_DDNS_CHECK_KEY                     = 12824,    /* 校验码错误 Check code error */
    NETDEV_E_DDNS_BAD_NAME_FORMAT               = 12825,    /* 域名格式不合格 Domain name format is not qualified */
    NETDEV_E_DDNS_DOMAIN_CONFLICT               = 12826,    /* 域名冲突 Domain name conflict */
    NETDEV_E_DDNS_CLOSE                         = 12827,    /* 非ddns服务器返回，只用于关闭ddns记录状态 Non-ddns server returns, only for closing DDNS record status */
    NETDEV_E_CREATE_CERT_FAILD                  = 12828,    /* 证书文件生成失败 Certificate file generation failed */
    NETDEV_E_GET_CERT_FAILD                     = 12829,    /* 上传证书文件不合法 It is illegal to upload certificate files */
    NETDEV_E_TEST_EMAIL_CHECKSERVER_INFO        = 12830,    /* 认证服务器用户名或密码错误 Error in username or password of authentication server */
    NETDEV_E_TEST_EMAIL_COMM                    = 12831,    /* 邮件发送失败,请检查网络和邮件配置 Mail delivery failed. Check network and mail configuration */
    NETDEV_E_TEST_EMAIL_TIMEOUT                 = 12832,    /* 邮件发送超时 Mail Delivery Timeout */
    NETDEV_E_CLOUD_REPEAT_USER                  = 12833,    /* 该云端账号已登录 The cloud account is logged in */
    NETDEV_E_CLOUD_DEV_ADD_FAIL                 = 12834,    /* 添加云端设备信息失败 Failed to add cloud device information */
    NETDEV_E_CLOUD_ORG_NULL                     = 12835,    /* 云端组织信息为空 Cloud organizational information is empty */
    NETDEV_E_GET_CLOUD_ORG                      = 12836,    /* 无法获取云端信息，请检查网络配置 Cloud information cannot be obtained. Check network configuration */
    NETDEV_E_NO_SUCH_CLOUD_USER                 = 12837,    /* 云端账号不存在 Cloud account does not exist */

    NETDEV_E_NET_MAX                            = 13199     /* 网络模块最大错误码值 Maximum Error Code Value of Network Module */

}NETDEV_NET_ECODE_E;


/* CFG模块 - XML错误码 */
typedef enum tagNETDEVXMLCfgErrCode
{
    NETDEV_E_CONF_FILE_INVALID                  = 13200,    /* 配置文件不合法 Illegal configuration file */
    NETDEV_E_LOAD_XML_FAIL                      = 13201,    /* 导出XML文件失败 Failed to export XML file */
    NETDEV_E_SAVE_XML_FAIL                      = 13202,    /* 生成XML文件失败 Failed to generate XML file */
    NETDEV_E_XML_ATTR_INEXIST                   = 13203,    /* XML属性信息不存在 XML attribute information does not exist */
    NETDEV_E_XML_SYNC_CFG_FAILED                = 13204,    /* 配置区同步出错,用于系统重启时，同步保存配置 Configuration area synchronization error to save configuration synchronously when system restart */
    NETDEV_E_SIMPLE_RECOVER_CFG_FAILED          = 13205,    /* 简单恢复配置出错 Simple Recovery Configuration Error */
    NETDEV_E_RECOVER_CFG_FAILED                 = 13206,    /* 完全恢复配置出错 Complete Recovery Configuration Error */
    NETDEV_E_CONF_FORBID_WRITE                  = 13207,    /* 禁止写入配置 Disable Writing Configuration */

    NETDEV_E_XML_MAX                            = 13599     /* XML模块最大错误码值 Maximum Error Code Value of XML Module */

}NETDEV_XML_ECODE_E;


/* plan模块错误码 */
typedef enum tagNETDEVPlanErrCode
{
    NETDEV_E_PLAN_TEMPLATE_BUSY                 = 13600,    /* 时间模板正在被使用 Template is being used */
    NETDEV_E_PLAN_TEMPLATE_NOT_EXIST            = 13601,    /* 时间模板节点不存在 Time template node does not exist */
    NETDEV_E_PLAN_INVALID_HOLIDAY_TIME          = 13602,    /* 非法假日时间 Illegal Holiday Time */
    NETDEV_E_PLAN_NO_PLAN                       = 13603,    /* 没有计划 No plan */
    NETDEV_E_PLAN_NOT_IN_PLAN                   = 13604,    /* 不在计划内 Not planned */
    NETDEV_E_PLAN_IN_PLAN                       = 13605,    /* 在计划内 Within the plan */

    NETDEV_E_PLAN_MAX                           = 13699     /* Plan模块最大错误码值 Maximum Error Code Value of Plan Module */

}NETDEV_PLAN_ECODE_E;


/* MT 模块 - 错误码 */
typedef enum tagNETDEVMTErrCode
{
    NETDEV_E_UPDATE_VERSION_FAIL                = 13700,    /* 设备升级，版本号不匹配 Equipment upgrade, version number mismatch */
    NETDEV_E_UPDATE_BOARDTYPE_NOT_MATCH         = 13701,    /* 设备升级，设备类型不匹配 Equipment upgrade, equipment type mismatch */
    NETDEV_E_FILE_CHECK_FAILED                  = 13702,    /* 文件校验出错 Document Check Error */
    NETDEV_E_EXPORT_CFG_FAILED                  = 13703,    /* 导出配置出错 Export configuration error */
    NETDEV_E_IMPORT_CFG_FAILED                  = 13704,    /* 导入配置出错 Import configuration error */
    NETDEV_E_UPDATE_OTHER_REASON                = 13705,    /* 设备升级，可能申请内存或者其他原因失败 Device upgrade, memory application or other reasons may fail */
    NETDEV_E_MAINTAIN_EXPORT_RUNNING            = 13706,    /* 维护信息正在导出 Maintenance information is being exported */

    NETDEV_E_MT_MAX                             = 13799     /* MT模块最大错误码值 Maximum error code value of MT module */

}NETDEV_MT_ECODE_E;

/* LINKAGE 模块 - 错误码 */
typedef enum tagNETDEVLinkageErrCode
{
    NETDEV_E_LINKAGE_GUARD_PRO_ALREADY_EXIT     = 13800,    /* 布防预案已存在 Preventive clothing plan already exists */
    NETDEV_E_LINKAGE_GUARD_PRO_NOT_EXIST        = 13801,    /* 指定的布防预案不存在 The designated deployment plan does not exist */
    NETDEV_E_LINKAGE_LINK_RULE_NOT_EXIST        = 13802,    /* 指定的联动规则不存在 The specified linkage rule does not exist */

    NETDEV_E_LINKAGE_MAX                        = 13899    /* Linkage模块最大错误码值 Maximum Error Code Value of Linkage Module */
}NETDEV_LINKAGE_ECODE_E;

/* alarm模块错误码 */
typedef enum tagNETDEVAlarmErrCode
{
    NETDEV_E_ALARM_RESTRAIN                     = 13900     /* 告警抑制 Alarm suppression */

}NETDEV_ALARM_ECODE_E;

/* 电子地图模块错误码 */
typedef enum tagNETDEVEMaprrCode
{
    NETDEV_E_EMAP_PIC_MAX_NUM                   = 15000,    /* 图片数量达到上限，无法添加 The number of pictures reached the upper limit and could not be added. */
    NETDEV_E_EMAP_DIR_EXIST                     = 15001,    /* 电子地图中根目录已存在 The root directory already exists in the electronic map */

    NETDEV_E_EMAP_MAX                           = 15099     /* 电子地图模块最大错误码值 Maximum Error Code Value of Electronic Map Module */
}NETDEV_EMAP_ECODE_E;

/* 门禁人员模块错误码 */
typedef enum tagNETDEVPASCErrCode
{
    NETDEV_E_PACS_PERSON_NO_EXIST               = 17000,    /* 门禁人员不存在 No entrance guards exist */
    NETDEV_E_PACS_PERSON_EXIST                  = 17001,    /* 门禁人员已存在 Access guards already exist */
    NETDEV_E_PACS_PERSON_CARD_EXIST             = 17002,    /* 门禁卡已存在 Access card already exists */
    NETDEV_E_PACS_PERSON_CARD_NO_EXIST          = 17003,    /* 门禁卡不存在 No access card exists*/
    NETDEV_E_PACS_PERSON_CARD_REACH_LIMIT       = 17004,    /* 门禁卡个数已达上限 The number of access cards has reached the upper limit. */
    NETDEV_E_PACS_MAX                           = 17999     /* PACS模块错误码最大值 Maximum Error Code of PACS Module */
}NETDEV_PACS_ECODE_E;

/* 人脸识别模块错误码 */
typedef enum tagFaceSmartModeErrCode
{
    NETDEV_E_FACE_BD_NO_MEMBER                  = 19000,    /* 人脸库中无成员 No member in face database */
    NETDEV_E_FACE_GUARD_NO_EXIST                = 19001,    /* 布控任务不存在 Control task does not exist */
    NETDEV_E_FACE_ALARM_LOG_NO_EXIST            = 19002,    /* 人脸识别告警记录不存在 There is no alarm record for face recognition */
    NETDEV_E_SMART_GET_FACE_IMAGE_FAIL          = 19003,    /* 获取人脸抓拍图片失败 Failure in capturing face images */
    NETDEV_E_NO_UID_AVAILABLE                   = 19004,    /* 没有可用的Uid No Uid is available */

    NETDEV_E_FACE_LIB_COUNT_MAX                 = 19005,    /* 人脸库数量达到最大值 Maximum number of face databases */
    NETDEV_E_FACE_GUARD_COUNT_MAX               = 19006,    /* 该人脸库布控任务数已达到最大值 The number of control tasks in the face database has reached the maximum. */
    NETDEV_E_FACE_MEMBER_COUNT_MAX              = 19007,    /* 该人脸库人脸成员数已达到最大值 The maximum number of face members has been achieved in this face database. */
    NETDEV_E_FACE_IDENTI_NUM_EXIST              = 19008,    /* 证件号码已存在 Document number already exists */
    NETDEV_E_FACE_FEAT_VERTION_UNMATCH          = 19009,    /* 设备人脸识别算法版本不匹配 Version mismatch of device face recognition algorithm */
    NETDEV_E_VEHICLE_GUARD_NO_EXIST             = 19010,    /* 车辆布控任务不存在 Vehicle control tasks do not exist */
    NETDEV_E_SLAVE_PLATE_IMAGE_GET_FAIL         = 19011,    /* 从机车牌图片获取失败 Failure to obtain license plate image */
    NETDEV_E_VEHICLE_LOG_NO_EXIST               = 19012,    /* 车辆记录不存在 Vehicle records do not exist */
    NETDEV_E_GET_SLAVE_PIC_FAIL                 = 19013,    /* 获取从机图片失败 Failed to get slave picture */
    NETDEV_E_GUARD_DEV_VIID_OFFLINE             = 19014,    /* 布控设备视图库状态离线 Out-of-line status of view Library of distribution control equipment */
    NETDEV_E_GUARD_GUARD_DEV_NOW                = 19015,    /* 布控设备中 In Distribution Control Equipment */
    NETDEV_E_GUARD_GUARD_NOT_ENABLE             = 19020,    /* 该布控任务不使能 This control task is not enabled */
    NETDEV_E_GUARD_GUARD_NOW                    = 19021,    /* 布控中 In charge control */
    NETDEV_E_GUARD_DIFFERENT_IMAGE_PROTOCOL     = 19022,    /* 每个布控任务只能选择相同图片接入协议的设备进行布控 */

    NETDEV_E_SMART_MAX                          = 19999     /* 智能模块错误码最大值 Maximum Error Code of Intelligent Module */
}NETDEV_FACE_SMART_ERR_CODE_E;

/* 视图库布控错误码 */
typedef enum tagMonitorErrCode
{
    NETDEV_E_VIID_DISPOSE_DEV_BUSY                  = 25006,  /* 视图库布控错误，设备忙 View library layout control error, equipment busy */
    NETDEV_E_VIID_DISPOSE_DATABASE_FULL             = 25007,  /* 视图库布控错误,人脸库已达上限 View database layout control error, face database has reached the upper limit */
    NETDEV_E_VIID_DISPOSE_MEMBER_FULL               = 25008,  /* 视图库布控错误,人脸成员已达上限 View database layout control error, face members have reached the upper limit */
    NETDEV_E_VIID_DISPOSE_NO_SMARTBAR               = 25009,  /* 视图库布控错误,设备智能棒不存在 View Library Layout Control Error, Device Smart Bar does not exist */
    NETDEV_E_VIID_DISPOSE_VIID_OFFLINE              = 25010   /* 视图库布控错误,设备视图库未连接 View Library Layout Error, Device View Library Not Connected */
}NETDEV_MONITOR_ERR_CODE_E;

/* 云端业务相关错误码 */
typedef enum tagCloudRemoteErrCode
{
    NETDEV_E_CLOUD_REGISTER_BY_OTHER                = 20000,  /* 不是你的设备 Not your device */

    NETDEV_E_CLOUD_CHL_NOT_EXIST                    = 20001,  /* 通道不存在 Channel does not exist */
    NETDEV_E_CLOUD_SREAMID_NOT_EXIST                = 20002,  /* 流ID不存在 Flow ID does not exist */
    NETDEV_E_CLOUD_BITRATE_UNEXPECTED               = 20003,  /* 请求码率过大 Excessive request rate */
    NETDEV_E_CLOUD_LIVEID_NOT_EXIST                 = 20004,  /* 直播ID不存在 Live ID does not exist */
    NETDEV_E_CLOUD_PROTO_TYPE_ILLEGAL               = 20005,  /* 请求流协议不支持 Request Flow Protocol does not support */
    NETDEV_E_CLOUD_CLIENTID_NOT_EXIST               = 20006,  /* 客户端ID不存在 Client ID does not exist */
    NETDEV_E_CLOUD_REQUESTID_NOT_EXIST              = 20007,  /* RequestID不存在 RequestID does not exist */
    NETDEV_E_CLOUD_VISITOR_TOTAL_UNEXPECTED         = 20008,  /* 当前在线用户过多 Too many current online users */
    NETDEV_E_GET_RTMP_URL_FAIL                      = 20009,  /* 获取RTMP拉流URL失败 Failed to obtain RTMP pull URL */
    NETDEV_E_GET_PUSH_STREAM_STATE_FAIL             = 20010,  /* 获取推流状态失败 Failure to acquire push-flow status*/
    NETDEV_E_START_PULL_STREAM_FAIL                 = 20011,  /* 启动拉流失败 Start-up pull-out failure */
    NETDEV_E_GET_CLOUD_DEV_LIST_FAIL                = 20012,  /* 获取云端设备列表失败 Failed to get the list of cloud devices */
    NETDEV_E_GET_DEV_INFO_FAILED                    = 20013,  /* 获取云端设备信息失败 Failed to obtain cloud device information */
    NETDEV_E_GET_NAT_TYPE_FAIL                      = 20014,  /* 获取NAT类型失败 Failed to get NAT type */
    NETDEV_E_MODIFT_CLOUD_DEV_NAME_FAIL             = 20015,  /* 更新云端设备名失败 Failed to update cloud device name */
    NETDEV_E_DELETE_CLOUD_DEVICE_FAIL               = 20016,  /* 删除云端设备失败 Failed to delete cloud devices */
    NETDEV_E_STOP_PULL_STREAM_FAIL                  = 20017,  /* 停止拉流失败 Stop pulling and lose */
    NETDEV_E_KEEP_ALIVE_PULL_STREAM_FAIL            = 20018,  /* 推流保活失败 Failure of Pushing Flow to Preserve Life */
    NETDEV_E_KEEP_ALIVE_LIST_EMPTY                  = 20019,  /* 保活列表为空 The live list is empty */
    NETDEV_E_GET_LIVE_ID_FAIL                       = 20020,  /* 获取直播ID失败 Failed to get live ID */
    NETDEV_E_CLOUD_INVALID_FORMAT                   = 20021,  /* 格式非法 Illegal format */
    NETDEV_E_CLOUD_NOT_REGISTER                     = 20022,  /* 该设备未注册 The device is not registered */
    NETDEV_E_CLOUD_INVALID_REG_CODE                 = 20023,  /* 注册码不存在 Registration code does not exist */
    NETDEV_E_CLOUD_NOT_SHARE_TO_SELF                = 20024,  /* 不能共享给自己 Can't share with oneself */
    NETDEV_E_ADD_CLOUD_DEVICE_FAIL                  = 20025,  /* 添加云端设备失败 Failed to add cloud devices */

    NETDEV_E_GET_CLOUD_DDNS_FAIL                    = 20026,    /* 获取DDNS信息失败 Failed to obtain DDNS information */
    NETDEV_E_GET_CLOUD_ORG_LIST_FAIL                = 20027,    /* 获取云端组织列表失败 Failed to retrieve cloud organization list */
    NETDEV_E_FIND_SHARE_DEVLIST_ERROR               = 20028,    /* 获取共享设备列表失败 Failed to get shared device list */
    NETDEV_E_START_DEVICE_SHARE_FAIL                = 20029,    /* 启动设备共享失败 Failure to start device sharing */
    NETDEV_E_STOP_DEVICE_SHARE_FAIL                 = 20030,    /* 停止云端设备共享失败 Failure to Stop Cloud Device Sharing */
    NETDEV_E_GET_SHARE_RECORD_INFO_FAIL             = 20031,    /* 获取云端共享记录信息失败 Failed to obtain cloud shared record information */
    NETDEV_E_GET_CLOUD_DEV_POPULATION               = 20032,    /* 获取云账户设备统计信息失败 Failed to obtain cloud account device statistics */
    NETDEV_E_ADD_CLOUD_ORG_FAIL                     = 20033,    /* 增加云端组织失败 Increasing cloud Organizational Failure */
    NETDEV_E_MODIFY_CLOUD_ORG_FAIL                  = 20034,    /* 修改云端组织失败 Failure to modify cloud organization */
    NETDEV_E_DELETE_CLOUD_ORG_FAIL                  = 20035,    /* 删除云端组织失败 Failed to delete cloud organizations */
    NETDEV_E_ADD_DEV_TO_CLOUD_ORG_FAIL              = 20036,    /* 增加设备到云端组织失败 Failure to add devices to cloud organizations */
    NETDEV_E_GET_CLOUD_DEV_CHANNEL_LIST_FAIL        = 20037,     /* 获取云设备通道失败 Failure to access cloud device channel */
    NETDEV_E_GET_CLOUD_VIDEO_TIME_FAIL              = 20038,    /* 获取云端视频时间信息失败 Failed to get cloud video time information */
    NETDEV_E_GET_CLOUD_VIDEO_M3U8_FAIL              = 20039     /* 获取云端视频M3u8信息失败 Failed to get cloud video M3u8 information */

}NETDEV_CLOUD_REMOTE_ERR_CODE_E;

/* 抓图模块错误码 */
typedef enum tagNETDEVSnapshotErrCode
{
    NETDEV_E_SNAPSHOT_PIC_FAILED                    = 27000,     /* 图片存储异常 */
    NETDEV_E_SNAPSHOT_QRY_PIC_FAILED                = 27001,     /* 查询图片异常 */

    NETDEV_E_SNAPSHOT_MAX                           = 27999      /* 抓图模块错误码最大值 */
}NETDEV_SNAPSHOT_ERR_CODE_E;

/* END********************* 错误码  Error codes *********************************************************** */

/* BEGIN:****************** 枚举值  Enumeration value ***************************************************** */
/**
 * @brief 通道状态 枚举定义 Channel status Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVChannelStatus
{
    NETDEV_CHL_STATUS_OFFLINE   = 0,            /* 通道离线  Channel offline */
    NETDEV_CHL_STATUS_ONLINE    = 1,             /* 通道在线  Channel online */
    NETDEV_CHL_STATUS_UNBIND    = 2,             /* 通道空闲  Channel unbind */
    NETDEV_CHL_STATUS_INVALID
}NETDEV_CHANNEL_STATUS_E;

/**
 * @brief 通道类型 枚举定义 Channel type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVChannelType
{
    NETDEV_CHL_TYPE_DIGITAL = 0,            /* 数字通道  Digital Channel */
    NETDEV_CHL_TYPE_ANALOG = 1,             /* 模拟通道  analog Channel */
    NETDEV_CHL_TYPE_INVALID
}NETDEV_CHANNEL_TYPE_E;

/**
 * @brief 通道下接入的设备类型(2018-07-26 目前仅NVR使用) 枚举定义 Channel device type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVChannelCameraType
{
    NETDEV_CHL_CAMERA_TYPE_FIXED        = 0,        /* 固定摄像机  fixed camera */
    NETDEV_CHL_CAMERA_TYPE_PTZ          = 1,        /* 云台摄像机  PTZ camera */
    NETDEV_CHL_CAMERA_TYPE_FISH_EYE     = 2,        /* 鱼眼相机（鱼眼镜头+自身矫正功能）fish-eye camera */
    NETDEV_CHL_CAMERA_TYPE_WIDE_ANGLE   = 3,        /* 超广角相机（包含鱼眼镜头、大视角的镜头的相机  但是不具备自身矫正功能）wide-Angle camera*/
    
    NETDEV_CHL_CAMERA_TYPE_INVALID      = 0xff
}NETDEV_CHANNEL_CAMERA_TYPE_E;

/**
 * @brief 视频制式 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVVideoStandard
{
    NETDEV_VIDEO_STANDARD_PAL       = 0,        /* PAL */
    NETDEV_VIDEO_STANDARD_NTSC      = 1,        /* NTSC */
    NETDEV_VIDEO_STANDARD_INVALID   = 0xFF      /* 无效值  Invalid value */
}NETDEV_VIDEO_STANDARD_E;

/**
 * @brief 摄像机类型 枚举定义 Camera type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVCameraType
{
    NETDEV_CAMERA_TYPE_FIX         = 0,            /* 固定摄像机  Fixed camera */
    NETDEV_CAMERA_TYPE_PTZ         = 1,            /* 云台摄像机  PTZ camera */

    NETDEV_CAMERA_TYPE_INVALID     = 0xFF          /* 无效值  Invalid value */
}NETDEV_CAMERA_TYPE_E;

/**
 * @brief 实况业务流索引 枚举定 义 Live stream index Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN       = 0,    /* 主流  Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX        = 1,    /* 辅流  Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD      = 2,    /* 第三流  Third stream */

    NETDEV_LIVE_STREAM_INDEX_INVALID    = 0xFF  /* 无效值  Invalid value */
}NETDEV_LIVE_STREAM_INDEX_E;

/**
 * @brief IP协议类型 枚举定义  Protocol type Enumeration definition
 * @attention 无 None
 */
typedef enum tagHOSTType
{
    NETDEV_NETWORK_HOSTTYPE_IPV4    = 0,        /* IPv4 */
    NETDEV_NETWORK_HOSTTYPE_IPV6    = 1,        /* IPv6 */
    NETDEV_NETWORK_HOSTTYPE_DNS     = 2         /* DNS */
}NETDEV_HOSTTYPE_E;


/**
 * @brief 媒体传输协议 枚举定义  Media transport protocol Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPUDP     = 0,    /* UDP */
    NETDEV_TRANSPROTOCAL_RTPTCP     = 1     /* TCP */
}NETDEV_PROTOCAL_E;

/**
 * @brief 启流模式 枚举定义  start stream mode Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVStreamMode
{
    NETDEV_STREAM_MODE_ALL      = 0x0000,   /* 音频 + 视频 audio & Video */
    NETDEV_STREAM_MODE_VIDEO    = 0x8000    /* 仅视频 only video */
}NETDEV_STREAM_MODE_E;

/**
 * @brief 媒体文件格式 枚举定义  Media file format Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVMediaFileFormat
{
    NETDEV_MEDIA_FILE_MP4                   = 0,    /* MP4格式的媒体文件(音频+视频)  mp4 media file (Audio + Video) */
    NETDEV_MEDIA_FILE_TS                    = 1,    /* TS格式的媒体文件(音频+视频)   TS media file (Audio + Video) */
    NETDEV_MEDIA_FILE_MP4_ADD_TIME          = 2,    /* MP4格式的媒体文件(音频+视频) ,文件名包含时间戳  MP4 media file with time in file name (Audio + Video) */
    NETDEV_MEDIA_FILE_TS_ADD_TIME           = 3,    /* TS格式的媒体文件(音频+视频) ,文件名包含时间戳  TS media file with time in file name (Audio + Video) */
    NETDEV_MEDIA_FILE_AUDIO_TS              = 4,    /* TS格式的音频文件(仅音频)   TS audio file (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_MP4             = 5,    /* MP4格式的音频文件(仅音频)   MP4 audio file (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_TS_ADD_TIME     = 6,    /* TS格式的音频文件(仅音频),文件名包含时间戳  TS audio file with time in file name (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_MP4_ADD_TIME    = 7,    /* MP4格式的音频文件(仅音频),文件名包含时间戳  MP4 audio file with time in file name (Only audio) */
    NETDEV_MEDIA_FILE_MP4_ADD_RCD_TIME      = 8,    /* MP4格式的媒体文件(音频+视频)，文件名包含开始结束时间  MP4 media file with start and end times in file name (Audio + Video)*/
    NETDEV_MEDIA_FILE_TS_ADD_RCD_TIME       = 9,    /* TS格式的媒体文件(音频+视频)，文件名包含开始结束时间  TS media file with start and end times in file name (Audio + Video)*/
    NETDEV_MEDIA_FILE_AUDIO_MP4_ADD_RCD_TIME= 10,   /* MP4格式的音频文件(仅音频)，文件名包含开始结束时间  MP4 audio file with start and end times in file name (Only audio)*/
    NETDEV_MEDIA_FILE_AUDIO_TS_ADD_RCD_TIME = 11,   /* TS格式的音频文件(仅音频)，文件名包含开始结束时间  TS audio file with start and end times in file name (Only audio)*/
    NETDEV_MEDIA_FILE_VIDEO_MP4_ADD_RCD_TIME= 12,   /* MP4格式的媒体文件(仅视频)  mp4 media file (Only video) */
    NETDEV_MEDIA_FILE_VIDEO_TS_ADD_RCD_TIME = 13,   /* TS格式的媒体文件(仅视频)  ts media file (Only video) */

    NETDEV_MEDIA_FILE_AVI                   = 14,   /* AVI格式的媒体文件(音频+视频)   AVI media file (Audio + Video) */
    NETDEV_MEDIA_FILE_AVI_ADD_TIME          = 15,   /* AVI格式的媒体文件(音频+视频)，文件名包含开始结束时间  AVI media file with start and end times in file name (Audio + Video)*/
    NETDEV_MEDIA_FILE_AUDIO_AVI             = 16,   /* AVI格式的音频文件(仅音频)   AVI audio file (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_AVI_ADD_TIME    = 17,   /* AVI(仅音频),文件名包含时间戳  AVI audio file with time in file name (Only audio)*/
    NETDEV_MEDIA_FILE_AVI_ADD_RCD_TIME      = 18,   /* AVI格式的音频文件(音频+视频)，文件名包含开始结束时间  AVI audio file with start and end times in file name (Audio + Video)*/
    NETDEV_MEDIA_FILE_AUDIO_AVI_ADD_RCD_TIME= 19,   /* AVI格式的音频文件(仅音频)，文件名包含开始结束时间  AVI audio file with start and end times in file name (Only audio)*/
    NETDEV_MEDIA_FILE_VIDEO_AVI_ADD_RCD_TIME= 20,   /* AVI格式的媒体文件(仅视频)  AVI media file (Only video) */

    NETDEV_MEDIA_FILE_INVALID
}NETDEV_MEDIA_FILE_FORMAT_E;

/**
 * @brief 解码视频编码格式 枚举定义  Player Video encoding format Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPlayerVideoCodeType
{
    NETDEV_PLAYER_VIDEO_CODE_MPEG2     = 0,          /* MPEG-2 */
    NETDEV_PLAYER_VIDEO_CODE_MPEG4     = 1,          /* MPEG-4 */
    NETDEV_PLAYER_VIDEO_CODE_H264      = 2,          /* H.264 */
    NETDEV_PLAYER_VIDEO_CODE_MJPEG     = 3,          /* MJPEG */
    NETDEV_PLAYER_VIDEO_CODE_H265      = 4,          /* H.265 */

    NETDEV_PLAYER_VIDEO_CODE_INVALID
}NETDEV_PLAYER_VIDEO_CODE_TYPE_E;

/**
 * @brief 视频编码格式 枚举定义  Video encoding format Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoCodeType
{
    NETDEV_VIDEO_CODE_MJPEG     = 0,          /* MJPEG */
    NETDEV_VIDEO_CODE_H264      = 1,          /* H.264 */
    NETDEV_VIDEO_CODE_H265      = 2,          /* H.265 */
    NETDEV_VIDEO_CODE_INVALID
}NETDEV_VIDEO_CODE_TYPE_E;

/**
 * @brief 视频帧类型 枚举定义  Video frame type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I    = 0,               /* I-frame */
    NETDEV_VIDEO_FRAME_P    = 1,               /* P-frame */
    NETDEV_VIDEO_FRAME_B    = 2                /* B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
* @brief 音频编码格式 Audio encode type
* @attention 无 None
*/
typedef enum tagNetDEVAudioEncodeType
{
    NETDEV_AUDIO_ENCODE_G711U   = 0,          /* 音频符合G.711U律标准 Audio up to G.711U-law standard*/
    NETDEV_AUDIO_ENCODE_MP2     = 1,          /* 音频符合MP2编码标准 Audio up to MP2 standard */
    NETDEV_AUDIO_ENCODE_AAC     = 2,          /* 音频符合AAC编码标准 Audio up to AAC standard*/
    NETDEV_AUDIO_ENCODE_G711A   = 3,          /* 音频符合G.711A律标准 Audio up to G.711A-law standard*/
    NETDEV_AUDIO_ENCODE_PCM     = 4,          /* 音频符合PCM律标准 Audio up to PCM law standard*/
    NETDEV_AUDIO_ENCODE_NULL    = 5           /* 无音频 No audio */
}NETDEV_AUDIO_ENCODE_TYPE_E;

/**
* @brief 解码后音频格式 Wave format info
* @attention 无  None
*/
typedef enum tagNetDEVWaveFormatInfo
{
    NETDEV_WAVE_FORMAT_PCM8M16        = 0,        /* PCM,8K采样率,单声道,16位采样 PCM,8k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM16M16       = 1,        /* PCM,16K采样率,单声道,16位采样 PCM,16k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM441M16      = 2,        /* PCM,44.1K采样率,单声道,16位采样 PCM,44.1k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM11025M16    = 3,        /* PCM,11.025K采样率,单声道,16位采样 PCM,11.025k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_UNKNOWN
}NETDEV_WAVE_FORMAT_INFO_E;

/**
 * @brief 视频显示比例 枚举定义  Video display ratio Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL        = 0,                  /* 图像填充整个播放窗格  Stretch */
    NETDEV_RENDER_SCALE_PROPORTION  = 1,                  /* 图像按比例显示  Scale */

    NETDEV_RENDER_SCALE_INVALID     = 0xFF
}NETDEV_RENDER_SCALE_E;

/**
 * @brief 图片格式 枚举定义 Picture type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPictureFormat
{
    NETDEV_PICTURE_BMP = 0,                  /* 图片格式为bmp格式  Picture format is bmp */
    NETDEV_PICTURE_JPG = 1,                  /* 图片格式为jpg格式  Picture format is jpg */

    NETDEV_PICTURE_INVALID
}NETDEV_PICTURE_FORMAT_E;

/**
 * @brief 视频图像质量 枚举定义  Video image quality Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /* 最高  Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /* 较高  Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /* 中  Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /* 低  Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /* 较低  Lower */
    NETDEV_VQ_L9 = 31,                   /* 最低  Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1         /* 无效  Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
 * @brief 图像分辨率 枚举定义 Image resolution Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPictureSize
{
    NETDEV_PICTURE_SIZE_D1     = 0,           /* D1 */
    NETDEV_PICTURE_SIZE_4CIF   = 1,           /* 4CIF */
    NETDEV_PICTURE_SIZE_2CIF   = 2,           /* 2CIF */
    NETDEV_PICTURE_SIZE_CIF    = 3,           /* CIF */
    NETDEV_PICTURE_SIZE_960H   = 4,           /* 960H */
    NETDEV_PICTURE_SIZE_QCIF   = 5,           /* QCIF */
    NETDEV_PICTURE_SIZE_HALFD1 = 6,           /* HALFD1 */
    NETDEV_PICTURE_SIZE_720    = 7,           /* 720 */
    NETDEV_PICTURE_SIZE_1080   = 8,           /* 1080 */
    NETDEV_PICTURE_SIZE_XGA    = 9,           /* 1024*768 */
    NETDEV_PICTURE_SIZE_SXGA   = 10,          /* 1280*1024 */

    NETDEV_PICTURE_SIZE_INVALID               /* 无效值  Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
 * @brief 云台命令 枚举定义 PTZ commands Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPtzCmdEnum
{
    NETDEV_PTZ_IRISCLOSE_STOP       =0x0101,       /* 光圈关停止  Iris close stop */
    NETDEV_PTZ_IRISCLOSE            =0x0102,       /* 光圈关  Iris close */
    NETDEV_PTZ_IRISOPEN_STOP        =0x0103,       /* 光圈开停止  Iris open stop */
    NETDEV_PTZ_IRISOPEN             =0x0104,       /* 光圈开  Iris open */

    NETDEV_PTZ_FOCUSNEAR_STOP       =0x0201,       /* 近聚集停止  Focus near stop */
    NETDEV_PTZ_FOCUSNEAR            =0x0202,       /* 近聚集  Focus near */
    NETDEV_PTZ_FOCUSFAR_STOP        =0x0203,       /* 远聚集停止  Focus far stop */
    NETDEV_PTZ_FOCUSFAR             =0x0204,       /* 远聚集  Focus far */

    NETDEV_PTZ_ZOOMTELE_STOP        = 0x0301,       /* 放大停止  Zoom in stop */
    NETDEV_PTZ_ZOOMTELE             = 0x0302,       /* 放大  Zoom in */
    NETDEV_PTZ_ZOOMWIDE_STOP        = 0x0303,       /* 缩小停止  Zoom out stop */
    NETDEV_PTZ_ZOOMWIDE             = 0x0304,       /* 缩小  Zoom out */
    NETDEV_PTZ_TILTUP               = 0x0402,       /* 向上  Tilt up */
    NETDEV_PTZ_TILTDOWN             = 0x0404,       /* 向下  Tilt down */
    NETDEV_PTZ_PANRIGHT             = 0x0502,       /* 向右  Pan right */
    NETDEV_PTZ_PANLEFT              = 0x0504,       /* 向左  Pan left */
    NETDEV_PTZ_LEFTUP               = 0x0702,       /* 左上  Move up left */
    NETDEV_PTZ_LEFTDOWN             = 0x0704,       /* 左下  Move down left */
    NETDEV_PTZ_RIGHTUP              = 0x0802,       /* 右上  Move up right */
    NETDEV_PTZ_RIGHTDOWN            = 0x0804,       /* 右下  Move down right */

#if 0
    NETDEV_PTZ_PRESAVE              = 0x0601,       /* 预置位保存  Save preset */
    NETDEV_PTZ_PRECALL              = 0x0602,       /* 预置位调用  Call preset */
    NETDEV_PTZ_PREDEL               = 0x0603,       /* 预置位删除  Delete preset */
#endif

    NETDEV_PTZ_ALLSTOP              = 0x0901,       /* 全停命令字  All-stop command word */
    NETDEV_PTZ_FOCUS_AND_IRIS_STOP  = 0x0907,       /* 聚焦.光圈停止  Focus & Iris-stop command word */
    NETDEV_PTZ_MOVE_STOP            = 0x0908,       /* 移动停止命令字  move stop command word */
    NETDEV_PTZ_ZOOM_STOP            = 0x0909,       /* 变倍停止命令字  zoom stop command word */

    NETDEV_PTZ_TRACKCRUISE          = 0x1001,       /* 开始轨迹巡航  Start route patrol*/
    NETDEV_PTZ_TRACKCRUISESTOP      = 0x1002,       /* 停止轨迹巡航  Stop route patrol*/
    NETDEV_PTZ_TRACKCRUISEREC       = 0x1003,       /* 开始录制轨迹  Start recording route */
    NETDEV_PTZ_TRACKCRUISERECSTOP   = 0x1004,       /* 停止录制轨迹  Stop recording route */
    NETDEV_PTZ_TRACKCRUISEADD       = 0x1005,       /* 添加巡航轨迹  Add patrol route */
    NETDEV_PTZ_TRACKCRUISEDEL       = 0x1006,       /* 删除轨迹巡航  Delete patrol route */

    NETDEV_PTZ_AREAZOOMIN           = 0x1101,       /* 拉框放大  Zoom in area */
    NETDEV_PTZ_AREAZOOMOUT          = 0x1102,       /* 拉框缩小  Zoom out area */
    NETDEV_PTZ_AREAZOOM3D           = 0x1103,       /* 3D定位  3D positioning */

    NETDEV_PTZ_BRUSHON              = 0x0A01,       /* 雨刷开  Wiper on */
    NETDEV_PTZ_BRUSHOFF             = 0x0A02,       /* 雨刷关  Wiper off */

    NETDEV_PTZ_LIGHTON              = 0x0B01,       /* 灯开  Lamp on */
    NETDEV_PTZ_LIGHTOFF             = 0x0B02,       /* 灯关  Lamp off */

    NETDEV_PTZ_HEATON               = 0x0C01,       /* 加热开  Heater on */
    NETDEV_PTZ_HEATOFF              = 0x0C02,       /* 加热关  Heater off */

    NETDEV_PTZ_SNOWREMOINGON        = 0x0E01,       /* 除雪开  Snowremoval on */
    NETDEV_PTZ_SNOWREMOINGOFF       = 0x0E02,       /* 除雪关  Snowremoval off  */

    NETDEV_PTZ_INFRAREDON           = 0x0D01,       /* 红外开  IR on */
    NETDEV_PTZ_INFRAREDOFF          = 0x0D02,       /* 红外关  IR off */

    NETDEV_PTZ_SELF_CHECKING        = 0x1801,       /* 自检:当参数dwSpeed为1时,执行云台自检;当为0时,执行恢复球机云台默认物理参数,此时会重启 */

#if 0
    NETDEV_PTZ_ABSPOSITION          = 0x0902,       /* 设置摄像机绝对角度  Set absolute position of camera */
    NETDEV_PTZ_GUARD                = 0x0903,       /* 回看守位,该命令不在云台模板体现  Return to home position (this command is not implemented on the PTZ template) */
    NETDEV_PTZ_SPEEDSET             = 0x0904,       /* 设置速度  Set speed */

    NETDEV_PTZ_PRESETCRUISE         = 0x1001,       /* 云台按预置位巡航 ,该命令字不在云台模板体现  Preset-based PTZ patrol (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_PRESETCRUISESTOP     = 0x1002,       /* 云台按预置位巡航停止,该命令字不在云台模板体现  Preset-based PTZ patrol stop (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_CRUISEDEL            = 0X1003,       /* 删除线路  Delete route */
    NETDEV_PTZ_CRUISEADDPRESET      = 0x1004,       /* 往线路中添加预置位  Add preset to route */
    NETDEV_PTZ_CRUISEADDSTART       = 0x1005,       /* 开始往线路中添加预置位  Start adding preset to route */
    NETDEV_PTZ_CRUISEADDSTOP        = 0x1006,       /* 结束往线路中添加预置位  Stop adding preset to route */
#endif

    NETDEV_PTZ_INVALID

} NETDEV_PTZ_E;

/**
 * @brief 云台预置位操作命令 枚举定义 PTZ preset operation commands Enumeration Definition
 * @attention 无 None
 */
typedef enum tagNETDEVPtzPresetCmd
{
    NETDEV_PTZ_SET_PRESET   = 0,            /* 设置预置位  Set preset */
    NETDEV_PTZ_CLE_PRESET   = 1,            /* 清除预置位  Clear preset */
    NETDEV_PTZ_GOTO_PRESET  = 2             /* 转到预置位  Go to preset */
}NETDEV_PTZ_PRESETCMD_E;

/**
 * @brief 云台巡航操作命令 枚举定义 PTZ patrol operation commands Enumeration Definition
 * @attention 无 None
 */
typedef enum tagNETDEVPTZCruiseCmd
{
    NETDEV_PTZ_ADD_CRUISE      = 0,         /* 添加巡航路径   Add patrol route */
    NETDEV_PTZ_MODIFY_CRUISE   = 1,         /* 编辑巡航路径  Edit patrol route */
    NETDEV_PTZ_DEL_CRUISE      = 2,         /* 删除巡航路径  Delete patrol route */
    NETDEV_PTZ_RUN_CRUISE      = 3,         /* 开始巡航  Start patrol */
    NETDEV_PTZ_STOP_CRUISE     = 4,          /* 停止巡航  Stop patrol */
    NETDEV_PTZ_GET_CRUISE      = 5         /* 获取巡航路径  */    /* Get patrol route */
}NETDEV_PTZ_CRUISECMD_E;

/**
 * @brief 回放控制命令 枚举定义 Playback control commands Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPlayControl
{
    NETDEV_PLAY_CTRL_PLAY                       = 0,        /* 开始播放  Play */
    NETDEV_PLAY_CTRL_PAUSE                      = 1,        /* 暂停播放  Pause */
    NETDEV_PLAY_CTRL_RESUME                     = 2,        /* 恢复播放  Resume */
    NETDEV_PLAY_CTRL_GETPLAYTIME                = 3,        /* 获取播放进度  Obtain playing time */
    NETDEV_PLAY_CTRL_SETPLAYTIME                = 4,        /* 设置播放进度  Configure playing time */
    NETDEV_PLAY_CTRL_GETPLAYSPEED               = 5,        /* 获取播放速度  Obtain playing speed */
    NETDEV_PLAY_CTRL_SETPLAYSPEED               = 6,        /* 设置播放速度  Configure playing speed */
    NETDEV_PLAY_CTRL_SET_SINGLE_FRAME_SPEED     = 7,        /* 设置单帧播放  Configure single frame playing speed */
    NETDEV_PLAY_CTRL_UPDATE_M3U8URL             = 8         /* 更新M3u8URL  urlUpdate M3u8 url */
}NETDEV_VOD_PLAY_CTRL_E;

/**
 * @brief 回放.下载状态 枚举定义 Playback and download status Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVVodPlayStatus
{
    /** 播放状态  Play status */
    NETDEV_PLAY_STATUS_16_BACKWARD          = 0,            /* 16倍速后退播放  Backward at 16x speed */
    NETDEV_PLAY_STATUS_8_BACKWARD           = 1,            /* 8倍速后退播放  Backward at 8x speed */
    NETDEV_PLAY_STATUS_4_BACKWARD           = 2,            /* 4倍速后退播放  Backward at 4x speed */
    NETDEV_PLAY_STATUS_2_BACKWARD           = 3,            /* 2倍速后退播放  Backward at 2x speed */
    NETDEV_PLAY_STATUS_1_BACKWARD           = 4,            /* 正常速度后退播放  Backward at normal speed */
    NETDEV_PLAY_STATUS_HALF_BACKWARD        = 5,            /* 1/2倍速后退播放  Backward at 1/2 speed */
    NETDEV_PLAY_STATUS_QUARTER_BACKWARD     = 6,            /* 1/4倍速后退播放  Backward at 1/4 speed */
    NETDEV_PLAY_STATUS_QUARTER_FORWARD      = 7,            /* 1/4倍速播放  Play at 1/4 speed */
    NETDEV_PLAY_STATUS_HALF_FORWARD         = 8,            /* 1/2倍速播放  Play at 1/2 speed */
    NETDEV_PLAY_STATUS_1_FORWARD            = 9,            /* 正常速度前进播放  Forward at normal speed */
    NETDEV_PLAY_STATUS_2_FORWARD            = 10,           /* 2倍速前进播放  Forward at 2x speed */
    NETDEV_PLAY_STATUS_4_FORWARD            = 11,           /* 4倍速前进播放  Forward at 4x speed */
    NETDEV_PLAY_STATUS_8_FORWARD            = 12,           /* 8倍速前进播放  Forward at 8x speed */
    NETDEV_PLAY_STATUS_16_FORWARD           = 13,           /* 16倍速前进播放  Forward at 16x speed */
    NETDEV_PLAY_STATUS_2_FORWARD_IFRAME     = 14,           /* 2倍速前进播放(I帧) Forward at 2x speed(I frame) */
    NETDEV_PLAY_STATUS_4_FORWARD_IFRAME     = 15,           /* 4倍速前进播放(I帧) Forward at 4x speed(I frame) */
    NETDEV_PLAY_STATUS_8_FORWARD_IFRAME     = 16,           /* 8倍速前进播放(I帧) Forward at 8x speed(I frame) */
    NETDEV_PLAY_STATUS_16_FORWARD_IFRAME    = 17,           /* 16倍速前进播放(I帧) Forward at 16x speed(I frame) */
    NETDEV_PLAY_STATUS_2_BACKWARD_IFRAME    = 18,           /* 2倍速后退播放(I帧) Backward at 2x speed(I frame) */
    NETDEV_PLAY_STATUS_4_BACKWARD_IFRAME    = 19,           /* 4倍速后退播放(I帧) Backward at 4x speed(I frame) */
    NETDEV_PLAY_STATUS_8_BACKWARD_IFRAME    = 20,           /* 8倍速后退播放(I帧) Backward at 8x speed(I frame) */
    NETDEV_PLAY_STATUS_16_BACKWARD_IFRAME   = 21,           /* 16倍速后退播放(I帧) Backward at 16x speed(I frame) */
    NETDEV_PLAY_STATUS_INTELLIGENT_FORWARD  = 22,           /* 智能播放 Intelligent forward */
    NETDEV_PLAY_STATUS_1_FRAME_FORWD        = 23,           /* 单帧前进播放  Forward at 1 frame speed */
    NETDEV_PLAY_STATUS_1_FRAME_BACK         = 24,           /* 单帧后退播放 Backward at 1 frame speed */

    NETDEV_PLAY_STATUS_40_FORWARD           = 25,           /* 40倍速前进播放 Forward at 40x speed*/

    NETDEV_PLAY_STATUS_32_FORWARD_IFRAME    = 26,           /* 32倍速抽帧前进播放 Forward at 32x speed(I frame)*/
    NETDEV_PLAY_STATUS_32_BACKWARD_IFRAME   = 27,           /* 32倍速抽帧后退播放 Backward at 32x speed(I frame)*/
    NETDEV_PLAY_STATUS_64_FORWARD_IFRAME    = 28,           /* 64倍速抽帧前进播放 Forward at 64x speed(I frame)*/
    NETDEV_PLAY_STATUS_64_BACKWARD_IFRAME   = 29,           /* 64倍速抽帧后退播放 Backward at 64x speed(I frame)*/
    NETDEV_PLAY_STATUS_128_FORWARD_IFRAME   = 30,           /* 128倍速抽帧前进播放 Forward at 128x speed(I frame)*/
    NETDEV_PLAY_STATUS_128_BACKWARD_IFRAME  = 31,           /* 128倍速抽帧后退播放 Backward at 128x speed(I frame)*/
    NETDEV_PLAY_STATUS_256_FORWARD_IFRAME   = 32,           /* 256倍速抽帧前进播放 Forward at 256x speed(I frame)*/
    NETDEV_PLAY_STATUS_256_BACKWARD_IFRAME  = 33,           /* 256倍速抽帧后退播放 Backward at 256x speed(I frame)*/

    NETDEV_PLAY_STATUS_32_FORWARD           = 34,           /* 32倍速前进播放 */
    NETDEV_PLAY_STATUS_32_BACKWARD          = 35,           /* 32倍速后退播放 */

    NETDEV_PLAY_STATUS_INVALID
}NETDEV_VOD_PLAY_STATUS_E;

/**
 * @brief 录像下载速度  Recording download speed
 * @attention 无 None
 */
typedef enum tagNETDEVDownloadSpeed
{
    NETDEV_DOWNLOAD_SPEED_ONE           = 0,            /* 一倍速 */
    NETDEV_DOWNLOAD_SPEED_TWO           = 1,            /* 二倍速 */
    NETDEV_DOWNLOAD_SPEED_FOUR          = 2,            /* 四倍速 */
    NETDEV_DOWNLOAD_SPEED_EIGHT         = 3,            /* 八倍速 */
    NETDEV_DOWNLOAD_SPEED_TWO_IFRAME    = 4,            /* 二倍速I帧 */
    NETDEV_DOWNLOAD_SPEED_FOUR_IFRAME   = 5,            /* 四倍速I帧 */
    NETDEV_DOWNLOAD_SPEED_EIGHT_IFRAME  = 6,            /* 八倍速I帧 */
    NETDEV_DOWNLOAD_SPEED_HALF          = 7,            /* 1/2倍速  1/2x */
    NETDEV_DOWNLOAD_SPEED_FORTY         = 8,            /* 40倍速 40x */

    NETDEV_DOWNLOAD_SPEED_INVALID       = 0xFF          /* 无效值 */
}NETDEV_E_DOWNLOAD_SPEED_E;

/**
 * @brief 录像存储类型 枚举定义 Recording storage type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVStoreType
{
    NETDEV_TYPE_STORE_TYPE_ALL                  = 0,            /* 常规存储  All */

    NETDEV_EVENT_STORE_TYPE_MOTIONDETECTION     = 4,            /* 运动检测事件存储  Motion detection */
    NETDEV_EVENT_STORE_TYPE_DIGITALINPUT        = 5,            /* 数字输入事件存储  Digital input */
    NETDEV_EVENT_STORE_TYPE_VIDEOLOSS           = 7,            /* 视频丢失事件存储  Video loss */

    NETDEV_TYPE_STORE_TYPE_INVALID              = 0xFF          /* 无效值  Invalid value */
}NETDEV_PLAN_STORE_TYPE_E;

/**
* @brief 音频位宽
* @attention 无
*/
typedef enum tagNetDevAudioSampleFormatType
{
    NETDEV_AUDIO_SAMPLE_FMT_NONE = -1,
    NETDEV_AUDIO_SAMPLE_FMT_U8      = 0,            /* 无符号8位整型 */
    NETDEV_AUDIO_SAMPLE_FMT_S16     = 1,            /* 有符号16位整型 */
    NETDEV_AUDIO_SAMPLE_FMT_S32     = 2,            /* 有符号32位整型 */
    NETDEV_AUDIO_SAMPLE_FMT_FLT     = 3,            /* 浮点型 */
    NETDEV_AUDIO_SAMPLE_FMT_DBL     = 4             /* double型 */
}NETDEV_AUDIO_SAMPLE_FORMAT_E;

/**
 * @brief 异常回调的消息类型 枚举定义 Exception callback message types Enumeration definition 
 * @attention 无 None
 */
typedef enum tagNETDEVException
{
    /* 回放业务异常上报  Playback exceptions report 300~399 */
    NETDEV_EXCEPTION_REPORT_VOD_END             = 300,          /* 回放结束  Playback ended*/
    NETDEV_EXCEPTION_REPORT_VOD_ABEND           = 301,          /* 回放异常  Playback exception occured */
    NETDEV_EXCEPTION_REPORT_BACKUP_END          = 302,          /* 备份结束  Backup ended */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_OUT     = 303,          /* 磁盘被拔出  Disk removed */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_FULL    = 304,          /* 磁盘已满  Disk full */
    NETDEV_EXCEPTION_REPORT_BACKUP_ABEND        = 305,          /* 其他原因导致备份失败   Backup failure caused by other reasons */

    NETDEV_EXCEPTION_EXCHANGE                   = 0x8000,       /* 用户交互时异常（用户保活超时）  Exception occurred during user interaction (keep-alive timeout) */
    NETDEV_EXCEPTION_REPORT_ALARM_INTERRUPT     = 0x8001,       /* 告警上报异常结束 保活失败或者长连接断开 Failure to report abnormal termination of life preservation or disconnection of long connection */

    NETDEV_EXCEPTION_REPORT_MAX,                                /* 最大值  Maximum value */
    NETDEV_EXCEPTION_REPORT_NOT_VALID_PERIOD,                   /* 不在有效期内 Not Valid period */
    NETDEV_EXCEPTION_REPORT_NOT_VALID_TIME,                     /* 不在有效时段内 Not Valid Time */

    NETDEV_EXCEPTION_REPORT_INVALID             = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_EXCEPTION_TYPE_E;

/**
 * @brief 告警配置操作 枚举定义  Alarm configuration operation Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmTypeEn
{
    NETDEV_ALARM_MOVE_DETECT                = 1,        /* 运动检测告警  Motion detection alarm */
    NETDEV_ALARM_MOVE_DETECT_RECOVER        = 2,        /* 运动检测告警恢复  Motion detection alarm recover */
    NETDEV_ALARM_VIDEO_LOST                 = 3,        /* 视频丢失告警  Video loss alarm */
    NETDEV_ALARM_VIDEO_LOST_RECOVER         = 4,        /* 视频丢失告警恢复  Video loss alarm recover */
    NETDEV_ALARM_VIDEO_TAMPER_DETECT        = 5,        /* 遮挡侦测告警  Tampering detection alarm */
    NETDEV_ALARM_VIDEO_TAMPER_RECOVER       = 6,        /* 遮挡侦测告警恢复  Tampering detection alarm recover */
    NETDEV_ALARM_INPUT_SWITCH               = 7,        /* 输入开关量告警  boolean input alarm */
    NETDEV_ALARM_INPUT_SWITCH_RECOVER       = 8,        /* 输入开关量告警恢复  Boolean input alarm recover */
    NETDEV_ALARM_TEMPERATURE_HIGH           = 9,        /* 高温告警  High temperature alarm */
    NETDEV_ALARM_TEMPERATURE_LOW            = 10,       /* 低温告警  Low temperature alarm */
    NETDEV_ALARM_TEMPERATURE_RECOVER        = 11,       /* 温度告警恢复  Temperature alarm recover */
    NETDEV_ALARM_AUDIO_DETECT               = 12,       /* 音频异常检测告警  Audio detection alarm */
    NETDEV_ALARM_AUDIO_DETECT_RECOVER       = 13,       /* 音频异常检测告警恢复  Audio detection alarm recover */
    NETDEV_ALARM_SERVER_FAULT               = 18,       /* 服务器故障 */
    NETDEV_ALARM_SERVER_NORMAL              = 19,       /* 服务器故障恢复 */
    

    NETDEV_ALARM_REPORT_DEV_ONLINE          = 201,       /* 设备上线告警 */
    NETDEV_ALARM_REPORT_DEV_OFFLINE         = 202,       /* 设备下线告警 */
    NETDEV_ALARM_REPORT_DEV_REBOOT          = 203,       /* 设备重启  Device restart */
    NETDEV_ALARM_REPORT_DEV_SERVICE_REBOOT  = 204,       /* 服务重启  Service restart */
    NETDEV_ALARM_REPORT_DEV_CHL_ONLINE      = 205,       /* 视频通道: 上线 */
    NETDEV_ALARM_REPORT_DEV_CHL_OFFLINE     = 206,       /* 视频通道: 下线 */
    NETDEV_ALARM_REPORT_DEV_DELETE_CHL      = 207,       /* 视频通道: 删除 */

    NETDEV_ALARM_NET_FAILED                 = 401,      /* 会话网络错误 Network error */
    NETDEV_ALARM_NET_TIMEOUT                = 402,      /* 会话网络超时 Network timeout */
    NETDEV_ALARM_SHAKE_FAILED               = 403,      /* 会话交互错误 Interaction error */
    NETDEV_ALARM_STREAMNUM_FULL             = 404,      /* 流数已经满 Stream full */
    NETDEV_ALARM_STREAM_THIRDSTOP           = 405,      /* 第三方停止流 Third party stream stopped */
    NETDEV_ALARM_FILE_END                   = 406,      /* 文件结束 File ended */
    NETDEV_ALARM_RTMP_CONNECT_FAIL          = 407,      /* RTMP连接失败 */
    NETDEV_ALARM_RTMP_INIT_FAIL             = 408,      /* RTMP初始化失败*/

    NETDEV_ALARM_DISK_ERROR                         = 601,      /* 设备磁盘错误  Disk error */
    NETDEV_ALARM_SYS_DISK_ERROR                     = 602,      /* 系统磁盘错误  Disk error */
    NETDEV_ALARM_DISK_ONLINE                        = 603,      /* 设备磁盘上线 Disk online */
    NETDEV_ALARM_SYS_DISK_ONLINE                    = 604,      /* 系统磁盘上线 Disk online */
    NETDEV_ALARM_DISK_OFFLINE                       = 605,      /* 设备磁盘离线 */
    NETDEV_ALARM_SYS_DISK_OFFLINE                   = 606,      /* 系统磁盘离线 */
    NETDEV_ALARM_DISK_ABNORMAL                      = 607,      /* 磁盘异常 Disk abnormal */
    NETDEV_ALARM_DISK_ABNORMAL_RECOVER              = 608,      /* 磁盘异常恢复 Disk abnormal recover */
    NETDEV_ALARM_DISK_STORAGE_WILL_FULL             = 609,      /* 磁盘存储空间即将满 Disk StorageGoingfull */
    NETDEV_ALARM_DISK_STORAGE_WILL_FULL_RECOVER     = 610,      /* 磁盘存储空间即将满恢复 Disk StorageGoingfull recover */
    NETDEV_ALARM_DISK_STORAGE_IS_FULL               = 611,      /* 设备存储空间满 StorageIsfull */
    NETDEV_ALARM_SYS_DISK_STORAGE_IS_FULL           = 612,      /* 系统存储空间满 StorageIsfull */
    NETDEV_ALARM_DISK_STORAGE_IS_FULL_RECOVER       = 613,      /* 存储空间满恢复 StorageIsfull recover */
    NETDEV_ALARM_DISK_RAID_DISABLED_RECOVER         = 614,      /* 阵列损坏恢复 RAIDDisabled recover */
    NETDEV_ALARM_DISK_RAID_DEGRADED                 = 615,      /* 设备阵列衰退 RAIDDegraded */
    NETDEV_ALARM_SYS_DISK_RAID_DEGRADED             = 616,      /* 系统阵列衰退 RAIDDegraded */
    NETDEV_ALARM_DISK_RAID_DISABLED                 = 617,      /* 设备阵列损坏 RAIDDisabled */
    NETDEV_ALARM_SYS_DISK_RAID_DISABLED             = 618,      /* 系统阵列损坏 RAIDDisabled */
    NETDEV_ALARM_DISK_RAID_DEGRADED_RECOVER         = 619,      /* 阵列衰退恢复 RAIDDegraded recover */
    NETDEV_ALARM_STOR_GO_FULL                       = 620,      /* 设备存储即将满告警 */
    NETDEV_ALARM_SYS_STOR_GO_FULL                   = 621,      /* 系统存储即将满告警 */
    NETDEV_ALARM_ARRAY_NORMAL                       = 622,      /* 设备阵列正常 */
    NETDEV_ALARM_SYS_ARRAY_NORMAL                   = 623,      /* 系统阵列正常 */
    NETDEV_ALARM_DISK_RAID_RECOVERED                = 624,      /* 阵列恢复正常 RAIDDegraded */
    NETDEV_ALARM_STOR_ERR                           = 625,      /* 设备存储错误  Storage error */
    NETDEV_ALARM_SYS_STOR_ERR                       = 626,      /* 系统存储错误  Storage error */
    NETDEV_ALARM_STOR_ERR_RECOVER                   = 627,      /* 存储错误恢复  Storage error recover */
    NETDEV_ALARM_STOR_DISOBEY_PLAN                  = 628,      /* 未按计划存储  Not stored as planned */
    NETDEV_ALARM_STOR_DISOBEY_PLAN_RECOVER          = 629,      /* 未按计划存储恢复  Not stored as planned recover */

    NETDEV_ALARM_BANDWITH_CHANGE                    = 801,      /* 设备出口带宽变更 */
    NETDEV_ALARM_VIDEOENCODER_CHANGE                = 802,      /* 设备码流配置变更告警 */
    NETDEV_ALARM_IP_CONFLICT                        = 803,      /* IP冲突异常告警 IP conflict exception alarm*/
    NETDEV_ALARM_IP_CONFLICT_CLEARED                = 804,      /* IP冲突异常告警恢复IP conflict exception alarm recovery */
    NETDEV_ALARM_NET_OFF                            = 805,      /* 网络断开异常告警 */
    NETDEV_ALARM_NET_RESUME_ON                      = 806,      /* 网络断开恢复告警 */

    NETDEV_ALARM_ILLEGAL_ACCESS                     = 1001,          /* 设备非法访问  Illegal access */
    NETDEV_ALARM_SYS_ILLEGAL_ACCESS                 = 1002,          /* 系统非法访问  Illegal access */
    NETDEV_ALARM_LINE_CROSS                         = 1003,          /* 越界告警  Line cross */
    NETDEV_ALARM_OBJECTS_INSIDE                     = 1004,          /* 区域入侵  Objects inside */
    NETDEV_ALARM_FACE_RECOGNIZE                     = 1005,          /* 人脸识别  Face recognize */
    NETDEV_ALARM_IMAGE_BLURRY                       = 1006,          /* 图像虚焦  Image blurry */
    NETDEV_ALARM_SCENE_CHANGE                       = 1007,          /* 场景变更  Scene change */
    NETDEV_ALARM_SMART_TRACK                        = 1008,          /* 智能跟踪  Smart track */
    NETDEV_ALARM_LOITERING_DETECTOR                 = 1009,          /* 徘徊检测  Loitering Detector */
    NETDEV_ALARM_BANDWIDTH_CHANGE                   = 1010,          /* 带宽变更  Bandwidth change */
    NETDEV_ALARM_ALLTIME_FLAG_END                   = 1011,          /* 无布防告警结束标记  End marker of alarm without arming schedule */
    NETDEV_ALARM_MEDIA_CONFIG_CHANGE                = 1012,          /* 编码参数变更 media configurationchanged */
    NETDEV_ALARM_REMAIN_ARTICLE                     = 1013,          /*物品遗留告警  Remain article*/
    NETDEV_ALARM_PEOPLE_GATHER                      = 1014,          /* 人员聚集告警 People gather alarm*/
    NETDEV_ALARM_ENTER_AREA                         = 1015,          /* 进入区域 Enter area*/
    NETDEV_ALARM_LEAVE_AREA                         = 1016,          /* 离开区域 Leave area*/
    NETDEV_ALARM_ARTICLE_MOVE                       = 1017,          /* 物品搬移 Article move*/
    NETDEV_ALARM_SMART_FACE_MATCH_LIST                  = 1018,       /* 人脸识别黑名单报警 */
    NETDEV_ALARM_SMART_FACE_MATCH_LIST_RECOVER          = 1019,       /* 人脸识别黑名单报警恢复 */
    NETDEV_ALARM_SMART_FACE_MISMATCH_LIST               = 1020,       /* 人脸识别不匹配报警 */
    NETDEV_ALARM_SMART_FACE_MISMATCH_LIST_RECOVER       = 1021,       /* 人脸识别不匹配报警恢复 */
    NETDEV_ALARM_SMART_VEHICLE_MATCH_LIST               = 1022,       /* 车辆识别匹配报警 */
    NETDEV_ALARM_SMART_VEHICLE_MATCH_LIST_RECOVER       = 1023,       /* 车辆识别匹配报警恢复 */
    NETDEV_ALARM_SMART_VEHICLE_MISMATCH_LIST            = 1024,       /* 车辆识别不匹配报警 */
    NETDEV_ALARM_SMART_VEHICLE_MISMATCH_LIST_RECOVER    = 1025,       /* 车辆识别不匹配报警回复 */
    NETDEV_ALARM_IMAGE_BLURRY_RECOVER               = 1026,         /* 图像虚焦告警恢复  Image blurry recover */
    NETDEV_ALARM_SMART_TRACK_RECOVER                = 1027,         /* 智能跟踪告警恢复  Smart track recover */
    NETDEV_ALARM_SMART_READ_ERROR_RATE              = 1028,         /* 底层数据读取错误率Error reding the underlying data */
    NETDEV_ALARM_SMART_SPIN_UP_TIME                 = 1029,         /* 主轴起旋时间  Rotation time of spindle */
    NETDEV_ALARM_SMART_START_STOP_COUNT             = 1030,         /* 启停计数 Rev. Stop counting*/
    NETDEV_ALARM_SMART_REALLOCATED_SECTOR_COUNT     = 1031,         /* 重映射扇区计数  Remap sector count*/
    NETDEV_ALARM_SMART_SEEK_ERROR_RATE              = 1032,         /* 寻道错误率 Trace error rate*/
    NETDEV_ALARM_SMART_POWER_ON_HOURS               = 1033,         /* 通电时间累计，出厂后通电的总时间，一般磁盘寿命三万小时 */
    NETDEV_ALARM_SMART_SPIN_RETRY_COUNT             = 1034,         /* 主轴起旋重试次数 */
    NETDEV_ALARM_SMART_CALIBRATION_RETRY_COUNT      = 1035,         /* 磁头校准重试计数 */
    NETDEV_ALARM_SMART_POWER_CYCLE_COUNT            = 1036,         /* 通电周期计数 */
    NETDEV_ALARM_SMART_POWEROFF_RETRACT_COUNT       = 1037,         /* 断电返回计数 */
    NETDEV_ALARM_SMART_LOAD_CYCLE_COUNT             = 1038,         /* 磁头加载计数 */
    NETDEV_ALARM_SMART_TEMPERATURE_CELSIUS          = 1039,         /* 温度 */
    NETDEV_ALARM_SMART_REALLOCATED_EVENT_COUNT      = 1040,         /* 重映射事件计数 */
    NETDEV_ALARM_SMART_CURRENT_PENDING_SECTOR       = 1041,         /* 当前待映射扇区计数 */
    NETDEV_ALARM_SMART_OFFLINE_UNCORRECTABLE        = 1042,         /* 脱机无法校正的扇区计数 */
    NETDEV_ALARM_SMART_UDMA_CRC_ERROR_COUNT         = 1043,         /* 奇偶校验错误率  */
    NETDEV_ALARM_SMART_MULTI_ZONE_ERROR_RATE        = 1044,         /* 多区域错误率 */
    NETDEV_ALARM_RESOLUTION_CHANGE                  = 1045,         /* 分辨率变更 */
    NETDEV_ALARM_MANUAL                             = 1401,         /* 手动告警 */
    NETDEV_ALARM_ALARMHOST_COMMON                   = 1402,         /* 报警点事件 */
    NETDEV_ALARM_DOORHOST_COMMON                    = 1403,         /* 门禁事件 */
    NETDEV_ALARM_FACE_NOT_MATCH                     = 1411,         /* 人脸对比失败 */
    NETDEV_ALARM_FACE_MATCH_SUCCEED                 = 1412,         /* 人脸对比成功 */

    NETDEV_ALARM_INVALID                            = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_ALARM_TYPE_E;

/**
 * @brief 告警资源类型 枚举定义  Alarm configuration operation Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmSrcTypeEn
{
    NETDEV_ALARM_SRC_LOCAL_HARD_DISK                            = 0,        /*本地硬盘*/
    NETDEV_ALARM_SRC_EX_CABINET_1_STORAGE_DISK                  = 1,        /*拓展柜-1存储盘*/
    NETDEV_ALARM_SRC_EX_CABINET_2_STORAGE_DISK                  = 2,        /*拓展柜-2存储盘*/
    NETDEV_ALARM_SRC_ARRAY_STORAGE_DISK                         = 3,        /*阵列存储盘*/
    NETDEV_ALARM_SRC_NAS_STORAGE_DISK                           = 4,        /*NAS存储盘*/
    NETDEV_ALARM_SRC_SAN_STORAGE_DISK                           = 5,        /*SAN存储盘*/
    NETDEV_ALARM_SRC_ESATA_STORAGE_DISK                         = 6,        /*eSATA存储盘*/
    NETDEV_ALARM_SRC_SD_STORAGE_DISK                            = 7,        /*SD存储盘*/
    NETDEV_ALARM_SRC_VIDEO_CHANNEL                              = 8,        /*视频通道*/
    NETDEV_ALARM_SRC_ALARM_INPUT_CHANNEL                        = 9,        /*报警输入通道*/
    NETDEV_ALARM_SRC_SYSTEM                                     = 10,       /*系统*/

    NETDEV_ALARM_SRC_AUDIO_CHANNEL                              = 11,       /*音频通道*/
    NETDEV_ALARM_SRC_DECODE_CHANNEL                             = 12,       /*解码通道*/
    NETDEV_ALARM_SRC_ALARM_OUTPUT_CHANNEL                       = 13,       /*报警输出通道*/
    NETDEV_ALARM_SRC_ACCESS_CONTROL_CHANNEL                     = 14,       /*门禁通道*/
    NETDEV_ALARM_SRC_ALARM_POINT_CHANNEL                        = 15,       /*报警点通道*/
    NETDEV_ALARM_SRC_EMERGENCY_BELL_CHANNEL                     = 16,       /*紧急铃通道(第三方告警)*/
    NETDEV_ALARM_SRC_DEV                                        = 17,       /*设备类*/

    NETDEV_ALARM_SRC_INVALID                                    = 0xFFFF    /* 无效值  Invalid value */
}NETDEV_ALARM_SRC_TYPE_E;

/**
 * @brief 资源变更子事件类型 枚举定义 Type of resource change subevent
 * @attention 无 None
 */
typedef enum tagNETDEVResChangeSubeventType
{
    NETDEV_RES_CHANGE_SUBEVENT_ADD                                  = 0,             /* 增加 */
    NETDEV_RES_CHANGE_SUBEVENT_DELETE                               = 1,             /* 删除 */
    NETDEV_RES_CHANGE_SUBEVENT_MODIFY                               = 2,             /* 修改 */
    NETDEV_RES_CHANGE_SUBEVENT_UP_LINE                              = 3,             /* 上线 */
    NETDEV_RES_CHANGE_SUBEVENT_OFFLINE                              = 4,             /* 离线 */
    NETDEV_RES_CHANGE_SUBEVENT_EMAP_ALARM_REPORT                    = 5,             /* Emap告警上报 */

    NETDEV_RES_CHANGE_SUBEVENT_INVALID                              = 0xff           /* 无效值  Invalid value */
}NETDEV_RES_CHANGE_SUBEVENT_TYPE_E;
/**
 * @brief 资源变更类型 枚举定义 Type of resource change
 * @attention 无 None
 */
typedef enum tagNETDEVResType
{
    NETDEV_RES_USER_RESOURCE                                 = 0,             /* 用户资源 */
    NETDEV_RES_EQUIPMENT_RESOURCE                            = 1,             /* 设备资源 */
    NETDEV_RES_CHANNEL_RESOURCE                              = 2,             /* 通道资源 */
    NETDEV_RES_USER_PERMISSION_RESOURCES                     = 3,             /* 用户权限资源 */
    NETDEV_RES_ROUND_TOUR_RESOURCES                          = 4,             /* 轮巡资源 */
    NETDEV_RES_HOT_RESOURCES                                 = 5,             /* 热点资源 */
    NETDEV_RES_GEOTHERMAL_RESOURCES                          = 6,             /* 热区资源 */
    NETDEV_RES_ALARM_RESOURCES                               = 7,             /* 告警资源 */
    NETDEV_RES_TIME_TEMPLATE                                 = 8,             /* 时间模板 */
    NETDEV_RES_SYSTEM_PERMISSION_RESOURCES                   = 9,             /* 系统权限资源 */
    NETDEV_RES_DEVICE_PERMISSION_RESOURCES                   = 10,            /* 设备权限资源 */
    NETDEV_RES_ORGANIZE_RESOURCES                            = 11,            /* 组织资源 */
    NETDEV_RES_ALARM_TASK_RESOURCES                          = 12,            /* 报警任务资源 */
    NETDEV_RES_MASTER_SLAVE_RESOURCES                        = 13,            /* 主从资源 */
    NETDEV_RES_TV_WALL_INFO                                  = 14,            /* 电视墙信息 */
    NETDEV_RES_TV_WALL_SCENE_RESOURCES                       = 15,            /* 电视墙场景资源 */
    NETDEV_RES_TV_WALL_WINDOW_RESOURCES                      = 16,            /* 电视墙窗口资源 */
    NETDEV_RES_TV_WALL_VIRTUAL_LED_RESOURCES                 = 17,            /* 电视墙虚拟LED资源 */
    NETDEV_RES_BROADCAST_GROUP_INFOR_CHANGES                 = 18,            /* 广播组信息变更 */
    NETDEV_RES_VIRTUAL_ORGANIZATION_RESOURCES                = 19,            /* 虚拟组织资源 */
    NETDEV_RES_USER_ROLE_RESOURCES                           = 20,            /* 用户角色资源 */
    NETDEV_RES_ROLE_ORGANIZE_SDHOW_TREE_RESOURCES            = 21,            /* 角色组织展示树资源 */
    NETDEV_RES_IMAGE_RESOURCES                               = 22,            /* 图片资源 */
    NETDEV_RES_CRUISE_RESOURCES                              = 23,            /* 巡航资源 */
    NETDEV_RES_RECORD_TRACE_RESOURCES                        = 24,            /* 录制轨迹资源 */
    NETDEV_RES_ACCESS_CONTROL_PERSONNEL_RESOURCES            = 25,            /* 门禁人员资源 */
    NETDEV_RES_ACCESS_CONTROL_CARD_RESOURCES                 = 26,            /* 门禁卡资源 */
    NETDEV_RES_TV_WALL_LIST                                  = 27,            /* 电视墙列表 */
    NETDEV_RES_TV_WALL_SCENE_SWITCHING                       = 28,            /* 电视墙场景切换 */
    NETDEV_RES_FACE_DATABASE_RESOURCES                       = 29,            /* 人脸库资源 */
    NETDEV_RES_FACE_DATABASE_CUSTOM_ATTRIBUTE                = 30,            /* 人脸库自定义属性 */
    NETDEV_RES_FACE_MEMBER_RESOURCES                         = 31,            /* 人脸成员资源 */
    NETDEV_RES_FACE_CONTROL_RESOURCES                        = 32,            /* 人脸布控资源 */
    NETDEV_RES_INTELLIGENT_DETECTION_RESOURCES               = 33,            /* 智能检测资源 */
    NETDEV_RES_INVALID                                       = 0xff           /* 无效值  Invalid value */
}NETDEV_RES_CHANGE_TYPE_E;


/**
 * @brief 日志主类型枚举 枚举定义 Major types of logs Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLogMainType
{
    NETDEV_LOG_MAIN_TYPE_ALL                    = 0,               /* 全部类型的日志  Logs of all types */
    NETDEV_LOG_MAIN_TYPE_ALARM                  = 1,               /* 告警类  Alarms */
    NETDEV_LOG_MAIN_TYPE_EXCEPTION              = 2,               /* 异常类  Exceptions */
    NETDEV_LOG_MAIN_TYPE_OPERATION              = 3,               /* 操作类  Operations */
    NETDEV_LOG_MAIN_TYPE_MESSAGE                = 4,               /* 信息类  Messages */

    NETDEV_LOG_MAIN_TYPE_INVALID                = 0xFFFF            /* 无效值  Invalid value */
}NETDEV_LOG_MAIN_TYPE_E;

/**
 * @brief 日志次类型ID 枚举定义 Minor type IDs of logs Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLogSubType
{
    NETDEV_LOG_ALL_SUB_TYPES                     = 0x0101,          /* 所有信息类日志  All information logs */

    /* 信息类日志  Information logs */
    NETDEV_LOG_MSG_HDD_INFO                     = 300,              /* 硬盘信息  HDD information */
    NETDEV_LOG_MSG_SMART_INFO                   = 301,              /* S.M.A.R.T信息  S.M.A.R.T information */
    NETDEV_LOG_MSG_REC_OVERDUE                  = 302,              /* 过期录像删除  Expired recording deletion */
    NETDEV_LOG_MSG_PIC_REC_OVERDUE              = 303,              /* 过期图片文件删除  Expired image deletion */

    /* 通知类日志  notification logs */
    NETDEV_LOG_NOTICE_IPC_ONLINE                = 310,              /* 设备上线  Device online */
    NETDEV_LOG_NOTICE_IPC_OFFLINE               = 311,              /* 设备下线  Device offline */
    NETDEV_LOG_NOTICE_ARRAY_RECOVER             = 312,              /* 阵列恢复正常  arrayRecover */
    NETDEV_LOG_NOTICE_INIT_ARRARY               = 313,              /* 阵列初始化  initializeArray */
    NETDEV_LOG_NOTICE_REBUILD_ARRARY            = 314,              /* 阵列重建  rebuildArray */
    NETDEV_LOG_NOTICE_POE_PORT_STATUS           = 315,              /* PoE网口状态  poePortStatus */
    NETDEV_LOG_NOTICE_NETWORK_PORT_STATUS       = 316,              /* 交换网口状态 networkPortStatus */
    NETDEV_LOG_NOTICE_DISK_ONLINE               = 317,              /* 磁盘上线  Disk online */

    /* 告警类日志的子类型日志ID  Sub type log ID of alarm logs */
    NETDEV_LOG_ALARM_MOTION_DETECT              = 350,              /* 移动侦测告警  Motion detection alarm */
    NETDEV_LOG_ALARM_MOTION_DETECT_RESUME       = 351,              /* 移动侦测告警恢复  Motion detection alarm recover */
    NETDEV_LOG_ALARM_VIDEO_LOST                 = 352,              /* 视频丢失告警  Video loss alarm */
    NETDEV_LOG_ALARM_VIDEO_LOST_RESUME          = 353,              /* 视频丢失告警恢复  Video loss alarm recover */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_DETECT        = 354,              /* 遮挡侦测告警  Tampering detection alarm */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_RESUME        = 355,              /* 遮挡侦测告警恢复  Tampering detection alarm recover */
    NETDEV_LOG_ALARM_INPUT_SW                   = 356,              /* 输入开关量告警  Boolean input alarm */
    NETDEV_LOG_ALARM_INPUT_SW_RESUME            = 357,              /* 输入开关量告警恢复  Boolean input alarm recover */
    NETDEV_LOG_ALARM_IPC_ONLINE                 = 358,              /* 设备上线  Device online */
    NETDEV_LOG_ALARM_IPC_OFFLINE                = 359,              /* 设备下线  Device offline */
    
    NETDEV_LOG_ALARM_AUDIO_DETECTION_START      = 360,              /* 音频检测开始  Audio detection start */
    NETDEV_LOG_ALARM_AUDIO_DETECTION_END        = 361,              /* 音频检测结束  Audio detection end */
    NETDEV_LOG_ALARM_CROSS_LINE_DETECT          = 362,              /* 越界检测报警  CrossLine detection */
    NETDEV_LOG_ALARM_FACE_DETECT                = 363,              /* 人脸检测报警  Face Detection */
    NETDEV_LOG_ALARM_INTRUSION_DETECT           = 364,              /* 区域入侵报警  Intrusion Detection */
    NETDEV_LOG_ALARM_POS                        = 365,              /* POS报警  POS Alarm */
    NETDEV_LOG_ALARM_IMAGETOOBLURRY_ON          = 366,              /* 虚焦检测开始  Defocus detection started*/
    NETDEV_LOG_ALARM_IMAGETOOBLURRY_OFF         = 367,              /* 虚焦检测结束  Defocus detection ended*/
    NETDEV_LOG_ALARM_GLOBAL_SCENE_CHANGE        = 368,              /* 场景变更检测  Scene change detection*/
    NETDEV_LOG_ALARM_AUTO_TRACK_ON              = 369,              /* 智能跟踪开始  Auto tracking started*/
    NETDEV_LOG_ALARM_AUTO_TRACK_OFF             = 370,              /* 智能跟踪结束  Auto tracking ended*/

    /* 异常类日志的子类型日志ID  Sub type log ID of exception logs */
    NETDEV_LOG_EXCEP_DISK_ONLINE                = 400,              /* 磁盘上线  Disk online */
    NETDEV_LOG_EXCEP_DISK_OFFLINE               = 401,              /* 磁盘下线  Disk offline */
    NETDEV_LOG_EXCEP_DISK_ERR                   = 402,              /* 磁盘异常  Disk exception */
    NETDEV_LOG_EXCEP_STOR_ERR                   = 403,              /* 存储错误  Storage error */
    NETDEV_LOG_EXCEP_STOR_ERR_RECOVER           = 404,              /* 存储错误恢复  Storage error recover */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN          = 405,              /* 未按计划存储  Not stored as planned */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN_RECOVER  = 406,              /* 未按计划存储恢复  Not stored as planned recover */
    NETDEV_LOG_EXCEP_ILLEGAL_ACCESS             = 407,              /* 非法访问  Illegal access */
    NETDEV_LOG_EXCEP_IP_CONFLICT                = 408,              /* IP地址冲突  IP address conflict */
    NETDEV_LOG_EXCEP_NET_BROKEN                 = 409,              /* 网络断开  Network disconnection */
    NETDEV_LOG_EXCEP_PIC_REC_ERR                = 410,              /* 抓图出错,获取图片文件失败  Failed to get captured image */
    NETDEV_LOG_EXCEP_VIDEO_EXCEPTION            = 411,              /* 视频输入异常(只针对模拟通道)  Video input exception (for analog channel only) */
    NETDEV_LOG_EXCEP_VIDEO_MISMATCH             = 412,              /* 视频制式不匹配   Video standards do not match */
    NETDEV_LOG_EXCEP_RESO_MISMATCH              = 413,              /* 编码分辨率和前端分辨率不匹配  Encoding resolution and front-end resolution do not match */
    NETDEV_LOG_EXCEP_TEMP_EXCE                  = 414,              /* 温度异常  Temperature exception */
    NETDEV_LOG_EXCEP_RUNOUT_RECORD_SPACE        = 415,              /* 录像存储空间即将满  runOutOfRecordSpace */
    NETDEV_LOG_EXCEP_RUNOUT_IMAGE_SPACE         = 416,              /* 图片存储空间即将满  runOutOfImageSpace */
    NETDEV_LOG_EXCEP_OUT_RECORD_SPACE           = 417,              /* 录像存储空间满  recordSpaceUsedUp */
    NETDEV_LOG_EXCEP_OUT_IMAGE_SPACE            = 418,              /* 图片存储空间满  imageSpaceUsedUp */
    NETDEV_LOG_EXCEP_ANRIDISASSEMBLY            = 419,              /* 防拆报警  antiDisassembly Alarm */
    NETDEV_LOG_EXCEP_ANRIDISASSEMBLY_RECOVER    = 420,              /* 防拆报警恢复 antiDisassembly AlarmClear*/
    NETDEV_LOG_EXCEP_ARRAY_DAMAGE               = 421,              /* 阵列损坏  arrayDamage */
    NETDEV_LOG_EXCEP_ARRAY_DEGRADE              = 422,              /* 阵列衰退  arrayDegrade */
    NETDEV_LOG_EXCEP_RECORD_SNAPSHOT_ABNOR      = 423,              /* 录像/抓图异常  recordSnapshotAbnormal */
    NETDEV_LOG_EXCEP_NET_BROKEN_RECOVER         = 424,              /* 网络断开恢复  networkDisconnectClear */
    NETDEV_LOG_EXCEP_IP_CONFLICT_RECOVER        = 425,              /* IP地址冲突恢复  ipConflictClear */

    /* 操作类日志的子类型日志ID  Sub type log ID of operation logs */
    /* 业务类  Services */
    NETDEV_LOG_OPSET_LOGIN                      = 450,              /* 用户登录  User login */
    NETDEV_LOG_OPSET_LOGOUT                     = 451,              /* 注销登录  Log out */
    NETDEV_LOG_OPSET_USER_ADD                   = 452,              /* 用户添加  Add user */
    NETDEV_LOG_OPSET_USER_DEL                   = 453,              /* 用户删除  Delete user */
    NETDEV_LOG_OPSET_USER_MODIFY                = 454,              /* 用户修改  Modify user */
    NETDEV_LOG_OPSET_START_REC                  = 455,              /* 开始录像  Start recording */
    NETDEV_LOG_OPSET_STOP_REC                   = 456,              /* 停止录像  Stop recording */
    NETDEV_LOG_OPSETR_PLAY_DOWNLOAD             = 457,              /* 回放/下载  Playback and download */
    NETDEV_LOG_OPSET_DOWNLOAD                   = 458,              /* 下载  Download */
    NETDEV_LOG_OPSET_PTZCTRL                    = 459,              /* 云台控制  PTZ control */
    NETDEV_LOG_OPSET_PREVIEW                    = 460,              /* 实况预览  Live preview */
    NETDEV_LOG_OPSET_REC_TRACK_START            = 461,              /* 轨迹录制开始  Start recording route */
    NETDEV_LOG_OPSET_REC_TRACK_STOP             = 462,              /* 轨迹录制停止  Stop recording route */
    NETDEV_LOG_OPSET_START_TALKBACK             = 463,              /* 开始语音对讲  Start two-way audio */
    NETDEV_LOG_OPSET_STOP_TALKBACK              = 464,              /* 停止语音对讲  Stop two-way audio */
    NETDEV_LOG_OPSET_IPC_ADD                    = 465,              /* 添加IPC  Add IP camera */
    NETDEV_LOG_OPSET_IPC_DEL                    = 466,              /* 删除IPC  Delete IP camera */
    NETDEV_LOG_OPSET_IPC_SET                    = 467,              /* 设置IPC  Modify IP camera */
    NETDEV_LOG_OPSET_IPC_QUICK_ADD              = 468,              /* 快速添加IPC  quickAddIpc*/
    NETDEV_LOG_OPSET_IPC_ADD_BY_NETWORK         = 469,              /* 网段添加IPC  addIpcByNetwork */
    NETDEV_LOG_OPSET_IPC_MOD_IP                 = 470,              /* 修改IPC网络地址  modifyIpcAddr */

    /* 配置类  Configurations */
    NETDEV_LOG_OPSET_DEV_BAS_CFG                = 500,              /* 设备基本信息配置  Basic device information */
    NETDEV_LOG_OPSET_TIME_CFG                   = 501,              /* 设备时间配置  Device time */
    NETDEV_LOG_OPSET_SERIAL_CFG                 = 502,              /* 设备串口配置  Device serial port */
    NETDEV_LOG_OPSET_CHL_BAS_CFG                = 503,              /* 通道基本配置  Basic channel configuration */
    NETDEV_LOG_OPSET_CHL_NAME_CFG               = 504,              /* 通道名称配置  Channel name configuration */
    NETDEV_LOG_OPSET_CHL_ENC_VIDEO              = 505,              /* 视频编码参数配置  Video encoding configuration */
    NETDEV_LOG_OPSET_CHL_DIS_VIDEO              = 506,              /* 通道视频显示参数配置  Video display configuration */
    NETDEV_LOG_OPSET_PTZ_CFG                    = 507,              /* 云台配置  PTZ configuration */
    NETDEV_LOG_OPSET_CRUISE_CFG                 = 508,              /* 巡航线路设置  Patrol route configuration */
    NETDEV_LOG_OPSET_PRESET_CFG                 = 509,              /* 预置位设置  Preset configuration */
    NETDEV_LOG_OPSET_VIDPLAN_CFG                = 510,              /* 录像计划配置  Recording schedule configuration */
    NETDEV_LOG_OPSET_MOTION_CFG                 = 511,              /* 运动检测配置  Motion detection configuration */
    NETDEV_LOG_OPSET_VIDLOSS_CFG                = 512,              /* 视频丢失配置  Video loss configuration */
    NETDEV_LOG_OPSET_COVER_CFG                  = 513,              /* 视频遮挡配置  Tampering detection configuration */
    NETDEV_LOG_OPSET_MASK_CFG                   = 514,              /* 视频遮盖配置  Privacy mask configuration */
    NETDEV_LOG_OPSET_SCREEN_OSD_CFG             = 515,              /* OSD叠加配置  OSD overlay configuration */
    NETDEV_LOG_OPSET_ALARMIN_CFG                = 516,              /* 报警输入配置  Alarm input configuration */
    NETDEV_LOG_OPSET_ALARMOUT_CFG               = 517,              /* 报警输出配置  Alarm output configuration */
    NETDEV_LOG_OPSET_ALARMOUT_OPEN_MAN          = 518,              /* 手动开启报警输出,人机  Manually enable alarm output, GUI */
    NETDEV_LOG_OPSET_ALARMOUT_CLOSE_MAN         = 519,              /* 手动关闭报警输出,人机  Manually disable alarm input, GUI */
    NETDEV_LOG_OPSET_ABNORMAL_CFG               = 520,              /* 异常配置  Exception configuration */
    NETDEV_LOG_OPSET_HDD_CFG                    = 521,              /* 硬盘配置  HDD configuration */
    NETDEV_LOG_OPSET_NET_IP_CFG                 = 522 ,             /* TCP/IP配置  TCP/IP configuration */
    NETDEV_LOG_OPSET_NET_PPPOE_CFG              = 523,              /* PPPOE配置  PPPOE configuration */
    NETDEV_LOG_OPSET_NET_PORT_CFG               = 524,              /* 端口配置  Port configuration */
    NETDEV_LOG_OPSET_NET_DDNS_CFG               = 525,              /* DDNS配置  DDNS configuration */
    NETDEV_LOG_OPSET_AUDIO_DETECT               = 527,              /* 搜索扩展硬盘  searchExtendDisk */
    NETDEV_LOG_OPSET_SEARCH_EX_DISK             = 528,              /* 搜索扩展硬盘  searchExtendDisk */
    NETDEV_LOG_OPSET_ADD_EX_DISK                = 529 ,             /* 添加扩展硬盘  addExtendDisk */
    NETDEV_LOG_OPSET_DEL_EX_DISK                = 530,              /* 删除扩展硬盘  deleteExtendDisk */
    NETDEV_LOG_OPSET_SET_EX_DISK                = 531,              /* 配置扩展硬盘  setExtendDisk */
    NETDEV_LOG_OPSET_LIVE_BY_MULTICAST          = 532,              /* 组播实况  liveViewByMulticast */
    NETDEV_LOG_OPSET_BISC_DEV_INFO              = 533,              /* 设备基本信息配置  setBasicDeviceInfo */
    NETDEV_LOG_OPSET_PREVIEW_CFG                = 534,              /* 本地预览配置  SetPreviewOnNvr */
    NETDEV_LOG_OPSET_SET_EMAIL                  = 535,              /* 邮件配置  setEmail */
    NETDEV_LOG_OPSET_TEST_EMAIL                 = 536,              /* 邮件测试  testEmail */
    NETDEV_LOG_OPSET_SET_IPCONTROL              = 537,              /* IP权限配置  setIPControl */
    NETDEV_LOG_OPSET_PORT_MAP                   = 538 ,             /* 端口映射配置  setPortMap */
    NETDEV_LOG_OPSET_ADD_TAG                    = 539,              /* 添加录像标签  addTag */
    NETDEV_LOG_OPSET_DEL_TAG                    = 540,              /* 删除录像标签  deleteTag */
    NETDEV_LOG_OPSET_MOD_TAG                    = 541,              /* 修改录像标签  modifyTag */
    NETDEV_LOG_OPSET_LOCK_RECORD                = 542,              /* 录像锁定  lockRecord */
    NETDEV_LOG_OPSET_UNLOCK_RECORD              = 543,              /* 录像解锁定  unlockRecord */
    NETDEV_LOG_OPSET_DDNS_UPDATE_SUCCESS        = 545,              /* DDNS更新成功  DDNSUpdateSuccess */
    NETDEV_LOG_OPSET_DDNS_INCORRECT_ID          = 546,              /* DDNS更新失败，错误的用户名密码  DDNSUpdateFailedIncorrectUsernamePassword */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_NAME_NOT_EXIST = 547,              /* DDNS更新失败，域名不存在  DDNSUpdateFailedDomainNameNotExist */
    NETDEV_LOG_OPSET_DDNS_UPDATE_FAIL           = 548,              /* DDNS更新失败  DDNSUpdateFailed */
    NETDEV_LOG_OPSET_HTTP_CFG                   = 549,              /* HTTPS配置  setHttps */
    NETDEV_LOG_OPSET_IP_OFFLINE_ALARM_CFG       = 550,              /* IPC离线报警配置  testDDNSDomain */
    NETDEV_LOG_OPSET_TELNET_CFG                 = 551,              /* Telnet配置  setTelnet */
    NETDEV_LOG_OPSET_TEST_DDNS_DOMAIN           = 552,              /* DDNS域名检测  testDDNSDomain */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_CONFLICT       = 553,              /* DDNS域名冲突  DDNSDomainInvalid */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_INVALID        = 554,              /* DDNS域名不合法  setDDNS */
    NETDEV_LOG_OPSET_DEL_PRESET                 = 555,              /* 删除预置位  deletePreset */
    NETDEV_LOG_OPSET_PTZ_3D_POSITION            = 556,              /* 云台3D定位  ptz3DPosition */
    NETDEV_LOG_OPSET_SNAPSHOT_SCHEDULE_CFG      = 557,              /* 抓图计划配置  setSnapshotSchedule */
    NETDEV_LOG_OPSET_IMAGE_UPLOAD_SCHEDULE_CFG  = 558,              /* 图片上传计划配置  setImageUploadSchedule */
    NETDEV_LOG_OPSET_FTP_CFG                    = 559,              /* FTP服务器配置  setFtpServer */
    NETDEV_LOG_OPSET_TEST_FTP_SERVER            = 560,              /* FTP服务器连接测试  testFtpServer */
    NETDEV_LOG_OPSET_START_MANUAL_SNAPSHOT      = 561,              /* 手动抓图开启  startManualSnapshot */
    NETDEV_LOG_OPSET_CLOSE_MANUAL_SNAPSHOT      = 562,              /* 手动抓图关闭  endManualSnapshot */
    NETDEV_LOG_OPSET_SNAPSHOT_CFG               = 563,              /* 抓图参数配置  setSnapshot */
    NETDEV_LOG_OPSET_ADD_HOLIDAY                = 564,              /* 添加假日  addHoliday */
    NETDEV_LOG_OPSET_DEL_HOLIDAY                = 565,              /* 删除假日  deleteHoliday */
    NETDEV_LOG_OPSET_MOD_HOLIDAY                = 566,              /* 修改假日  modifyHoliday */
    NETDEV_LOG_OPSET_ONOFF_HOLIDAY              = 567,              /* 开启/关闭假日  enableDisableHoliday */
    NETDEV_LOG_OPSET_ALLOCATE_SPACE             = 568,              /* 容量配置  allocateSpace */
    NETDEV_LOG_OPSET_HDD_FULL_POLICY_CFG        = 569,              /* 满策略配置  setHddFullPolicy */
    NETDEV_LOG_OPSET_AUDIO_STREAM_CFG           = 570,              /* 音频流配置  setAudioStream */
    NETDEV_LOG_OPSET_ARRAY_PROPERTY_CFG         = 571,              /* 阵列属性配置  setArrayProperty */
    NETDEV_LOG_OPSET_HOT_SPACE_DISK_CFG         = 572,              /* 热备盘配置  setHotSpaceDisk */
    NETDEV_LOG_OPSET_CREAT_ARRAY                = 573,              /* 手动创建阵列  createArray */
    NETDEV_LOG_OPSET_ONE_CLICK_CREAT_ARRAY      = 574,              /* 一键创建阵列  oneClickCreateArray */
    NETDEV_LOG_OPSET_REBUILD_ARRAY              = 575,              /* 重建阵列  rebuildArray */
    NETDEV_LOG_OPSET_DEL_ARRAY                  = 576,              /* 删除阵列  deleteArray */
    NETDEV_LOG_OPSET_ENABLE_RAID                = 577,              /* 开启RAID模式  enableRaid */
    NETDEV_LOG_OPSET_DISABLE_RAID               = 578,              /* 关闭RAID模式  disableRaid */
    NETDEV_LOG_OPSET_TEST_SMART                 = 579,              /* S.M.A.R.T检测  testSmart */
    NETDEV_LOG_OPSET_SMART_CFG                  = 580,              /* S.M.A.R.T配置  setSmart */
    NETDEV_LOG_OPSET_BAD_SECTOR_DETECT          = 581,              /* 坏道检测  badSectorDetect */
    NETDEV_LOG_OPSET_AUDIO_ALARM_DURATION       = 582,              /* 配置声音报警时长  setAudioAlarmDuration */
    NETDEV_LOG_OPSET_CLR_AUDIO_ALARM            = 583,             /* 清除声音报警  clearAudioAlarm */
    NETDEV_LOG_OPSET_IPC_TIME_SYNC_CFG          = 584,              /* 配置同步摄像机时间  setIpcTimeSync */
    NETDEV_LOG_OPSET_ENABLE_DISK_GROUP          = 585,              /* 开启盘组  enableDiskGroup */
    NETDEV_LOG_OPSET_DISABLE_DISK_GRRUOP        = 586,              /* 关闭盘组  disableDiskGroup */
    NETDEV_LOG_OPSET_ONVIF_AUTH_CFG             = 587,              /* ONVIF认证配置  setOnvifAuth */
    NETDEV_LOG_OPSET_8021X_CFG                  = 588,              /* 配置802.1X  set8021x */
    NETDEV_LOG_OPSET_ARP_PROTECTION_CFG         = 589,              /* 配置ARP防攻击  setArpProtection */
    NETDEV_LOG_OPSET_SMART_BASIC_INFO_CFG       = 590 ,             /* 智能报警基本信息配置  setSmartBasicInfo */
    NETDEV_LOG_OPSET_CROSS_LINE_DETECT_CFG      = 591,              /* 越界检测配置  setCrossLineDetection */
    NETDEV_LOG_OPSET_INSTRUSION_DETECT_CFG      = 592,              /* 区域入侵配置  setIntrusionDetection */
    NETDEV_LOG_OPSET_PEOPLE_COUNT_CFG           = 593,              /* 客流量配置  setPeopleCount */
    NETDEV_LOG_OPSET_FACE_DETECT_CFG            = 594,              /* 人脸检测配置  setFaceDetection */
    NETDEV_LOG_OPSET_FISHEYE_CFG                = 595,              /* 鱼眼配置  setFisheye */
    NETDEV_LOG_OPSET_CUSTOM_PROTOCOL_CFG        = 596,              /* 自定义协议配置  setCustomProtocol */
    NETDEV_LOG_OPSET_BEHAVIOR_SEARCH            = 597,              /* 行为检索  behaviorSearch */
    NETDEV_LOG_OPSET_FACE_SEARCH                = 598,              /* 人脸检索  faceSearch */
    NETDEV_LOG_OPSET_PEOPLE_COUNT               = 599,              /* 客流量统计  peopleCount */
        
    /* 维护类 Maintenance */
    NETDEV_LOG_OPSET_START_DVR                  = 600,              /* 开机  Start up*/
    NETDEV_LOG_OPSET_STOP_DVR                   = 601,              /* 关机  Shut down */
    NETDEV_LOG_OPSET_REBOOT_DVR                 = 602,              /* 重启设备  Restart device */
    NETDEV_LOG_OPSET_UPGRADE                    = 603,              /* 版本升级  Version upgrade */
    NETDEV_LOG_OPSET_LOGFILE_EXPORT             = 604,              /* 导出日志文件  Export log files */
    NETDEV_LOG_OPSET_CFGFILE_EXPORT             = 605,              /* 导出配置文件  Export configuration files */
    NETDEV_LOG_OPSET_CFGFILE_IMPORT             = 606,              /* 导入配置文件  Import configuration files */
    NETDEV_LOG_OPSET_CONF_SIMPLE_INIT           = 607,              /* 简单恢复配置  Export configuration files */
    NETDEV_LOG_OPSET_CONF_ALL_INIT              = 608,               /* 恢复出厂配置  Restore to factory settings */

    NETDEV_LOG_OPSET_VCA_BACKUP                 = 700,              /* 智能备份  vcaBackup */
    NETDEV_LOG_OPSET_3G4G_CFG                   = 701,              /* 3G/4G配置  set3g4g */
    NETDEV_LOG_OPSET_MOUNT_EXTENDED_DISK        = 702,              /* 加载扩展硬盘 Mount extended disk*/
    NETDEV_LOG_OPSET_UNMOUNT_EXTENDED_DISK      = 703,              /* 卸载扩展硬盘 Unmount extended disk*/
    NETDEV_LOG_OPSET_FORCE_USER_OFFLINE         = 704,              /* 强制用户下线 Force user off line*/

    NETDEV_LOG_OPSET_AUTO_FUNCTION              = 709,              /* 自动维护  autoFunction */
    NETDEV_LOG_OPSET_IPC_UPRAGDE                = 710,              /* 摄像机升级  ipcUpgrade */
    NETDEV_LOG_OPSET_RESTORE_IPC_DEFAULTS       = 711,              /* 摄像机恢复默认配置  restoreIpcDefaults */
    NETDEV_LOG_OPSET_ADD_TRANSACTION            = 712,              /* 添加交易配置  addTransaction */
    NETDEV_LOG_OPSET_MOD_TRANSACTION            = 713,              /* 修改交易配置  modifyTransaction */
    NETDEV_LOG_OPSET_DEL_TRANSACTION            = 714,              /* 删除交易配置  deleteTransaction */
    NETDEV_LOG_OPSET_POS_OSD                    = 715,              /* POS显示配置设置  setPosOsd */
    NETDEV_LOG_OPSET_ADD_HOT_SPACE_DEV          = 716,              /* 添加备机  addHotSpaceDevice */
    NETDEV_LOG_OPSET_DEL_HOT_SPACE_DEV          = 717,              /* 删除备机  deleteHotSpaceDevice */
    NETDEV_LOG_OPSET_MOD_HOT_SPACE_DEV          = 718,              /* 修改备机  modifyHotSpaceDevice */
    NETDEV_LOG_OPSET_DEL_WORK_DEV               = 719,              /* 删除工作机  deleteWorkDevice */
    NETDEV_LOG_OPSET_WORKMODE_TO_NORMAL_CFG     = 720,              /* 设置工作机模式  SetWorkModeToNormal */
    NETDEV_LOG_OPSET_WORKMODE_TO_HOTSPACE_CFG   = 721,              /* 设置备机模式  SetWorkModeToHotSpace */
    NETDEV_LOG_OPSET_AUTO_GUARD_CFG             = 723,              /* 守望配置  setAutoGuard */
    NETDEV_LOG_OPSET_MULTICAST_CFG              = 724,              /* 组播配置  SetMulticast */
    NETDEV_LOG_OPSET_DEFOCUS_DETECT_CFG         = 725,              /* 虚焦检测配置 Set defocus detection*/
    NETDEV_LOG_OPSET_SCENECHANGE_CFG            = 726,              /* 场景变更配置 Set scene change detection*/
    NETDEV_LOG_OPSET_AUTO_TRCAK_CFG             = 727,              /* 智能跟踪配置 Set auto tracking*/
    NETDEV_LOG_OPSET_SORT_CAMERA_CFG            = 728,              /* 通道排序 Sort camera*/
    NETDEV_LOG_OPSET_WATER_MARK_CFG             = 729              /* 视频水印配置 Set watermark*/
}NETDEV_LOG_SUB_TYPE_E;

typedef enum tagNETDEVDeviceType
{
    NETDEV_DTYPE_UNKNOWN                        = 0,            /* Unknown type */
    NETDEV_DTYPE_IPC                            = 1,            /* IPC range */
    NETDEV_DTYPE_IPC_FISHEYE                    = 2,            /* 非经济型鱼眼IPC Certain fisheye camera models*/
    NETDEV_DTYPE_IPC_ECONOMIC_FISHEYE           = 3,            /* 经济型鱼眼IPC Certain fisheye camera models*/
    NETDEV_DTYPE_NVR                            = 101,          /* NVR range */
    NETDEV_DTYPE_NVR_BACKUP                     = 102,          /* NVR备份服务器  NVR back up */
    NETDEV_DTYPE_HNVR                           = 103,          /* 混合NVR */
    NETDEV_DTYPE_DC                             = 201,          /* DC range */
    NETDEV_DTYPE_DC_ADU                         = 202,          /* ADU range */
    NETDEV_DTYPE_EC                             = 301,          /* EC range */
    NETDEV_DTYPE_VMS                            = 501,          /* VMS range */
    NETDEV_DTYPE_FG                             = 601,          /* FG range */
    NETDEV_DTYPE_INVALID                        = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_DEVICE_TYPE_E;

/**
 * @brief 参数配置命令字 枚举定义 Parameter configuration command words Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVCfgCmd
{
    NETDEV_GET_DEVICECFG                = 100,              /* 获取设备信息,参见#NETDEV_DEVICE_BASICINFO_S  Get device information, see #NETDEV_DEVICE_BASICINFO_S */
    NETDEV_SET_DEVICECFG                = 101,              /* 保留 Reserved */

    NETDEV_GET_NTPCFG                   = 110,              /* 获取NTP参数,参见#NETDEV_SYSTEM_NTP_INFO_S  Get NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */
    NETDEV_SET_NTPCFG                   = 111,              /* 设置NTP参数,参见#NETDEV_SYSTEM_NTP_INFO_S  Set NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */

    NETDEV_GET_NTPCFG_EX                = 112,              /* 获取NTP参数(扩展，建议使用),参见#NETDEV_SYSTEM_NTP_INFO_LIST_S  Get NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_LIST_S */
    NETDEV_SET_NTPCFG_EX                = 113,              /* 设置NTP参数(扩展，建议使用),参见#NETDEV_SYSTEM_NTP_INFO_LIST_S  Set NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_LIST_S */

    NETDEV_GET_STREAMCFG                = 120,              /* 获取视频编码参数,参见#NETDEV_VIDEO_STREAM_INFO_S  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */
    NETDEV_SET_STREAMCFG                = 121,              /* 设置视频编码参数,参见#NETDEV_VIDEO_STREAM_INFO_S  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */
    NETDEV_GET_STREAMCFG_EX             = 122,              /* 获取视频编码参数(扩展，建议使用),参见#NETDEV_VIDEO_STREAM_INFO_LIST_S  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_LIST_S */
    NETDEV_SET_STREAMCFG_EX             = 123,              /* 设置视频编码参数(扩展，建议使用),参见#NETDEV_VIDEO_STREAM_INFO_LIST_S  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_LIST_S */
    NETDEV_GET_VIDEOMODECFG             = 124,              /* 获取图像采集制式，参见#NETDEV_VIDEO_MODE_INFO_S */
    NETDEV_SET_VIDEOMODECFG             = 125,              /* 设置图像采集制式，参见#NETDEV_VIDEO_MODE_INFO_S */

    NETDEV_GET_OSDCFG                   = 140,              /* 获取OSD配置信息,参见#NETDEV_VIDEO_OSD_CFG_S  Get OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */
    NETDEV_SET_OSDCFG                   = 141,              /* 设置OSD配置信息,参见#NETDEV_VIDEO_OSD_CFG_S  Set OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */
    NETDEV_GET_OSDCFG_EX                = 142,              /* 获取OSD配置列表,参见#NETDEV_CHL_OSD_CFG_LIST_S  Get OSD configuration List, see #NETDEV_CHL_OSD_CFG_LIST_S */
    NETDEV_SET_OSDCFG_EX                = 143,              /* 设置OSD配置列表,参见#NETDEV_CHL_OSD_CFG_LIST_S  Set OSD configuration List, see #NETDEV_CHL_OSD_CFG_LIST_S */
    NETDEV_GET_OSD_CONTENT_CFG          = 144,              /* 获取OSD配置信息(扩展，建议使用),参见#NETDEV_OSD_CONTENT_S  Get OSD configuration information, see #NETDEV_OSD_CONTENT_S */
    NETDEV_SET_OSD_CONTENT_CFG          = 145,              /* 设置OSD配置信息(扩展，建议使用),参见#NETDEV_OSD_CONTENT_S  Set OSD configuration information, see #NETDEV_OSD_CONTENT_S */
    NETDEV_GET_OSD_CONTENT_STYLE_CFG    = 146,              /* 获取OSD内容样式,参见#NETDEV_OSD_CONTENT_STYLE_S  Get OSD content style, see #NETDEV_OSD_CONTENT_STYLE_S */
    NETDEV_SET_OSD_CONTENT_STYLE_CFG    = 147,              /* 设置OSD内容样式,参见#NETDEV_OSD_CONTENT_STYLE_S  Set OSD content style, see #NETDEV_OSD_CONTENT_STYLE_S */

    NETDEV_GET_ALARM_OUTPUTCFG          = 150,              /* 获取开关量输出配置信息,参见#NETDEV_ALARM_OUTPUT_LIST_S  Get boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_SET_ALARM_OUTPUTCFG          = 151,              /* 设置开关量输出配置信息,参见#NETDEV_ALARM_OUTPUT_LIST_S  Set boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_TRIGGER_ALARM_OUTPUT         = 152,              /* 触发开关量,参见#NETDEV_TRIGGER_ALARM_OUTPUT_S        Trigger boolean, see #NETDEV_TRIGGER_ALARM_OUTPUT_S */
    NETDEV_GET_ALARM_INPUTCFG           = 153,              /* 获取开关量输入数量,参见#NETDEV_ALARM_INPUT_LIST_S   Get the number of boolean inputs, see #NETDEV_ALARM_INPUT_LIST_S */
    NETDEV_GET_MANUAL_ALARM_CFG         = 154,              /* 获取手动告警开关量配置信息，参见#NETDEV_OUTPUT_SWITCH_ALARM_STATUS_LIST_S  Get manual alarm boolean configuration information, see #NETDEV_OUTPUT_SWITCH_ALARM_STATUS_LIST_S*/
    NETDEV_SET_MANUAL_ALARM_CFG         = 155,              /* 设置手动告警开关量配置信息，参见#NETDEV_OUTPUT_SWITCH_MANUAL_ALARM_INFO_S  Set manual alarm boolean configuration information, see #NETDEV_OUTPUT_SWITCH_MANUAL_ALARM_INFO_S */
    NETDEV_GET_INPUTSWITCH_LIST_CFG     = 156,              /* 获取所有输入开关量配置，参见#NETDEV_INPUT_SWITCH_INFO_LIST_S  Get all input switch information, see #NETDEV_INPUT_SWITCH_INFO_LIST_S*/

    NETDEV_GET_IMAGECFG                 = 160,              /* 获取图像配置信息,参见#NETDEV_IMAGE_SETTING_S  Get image configuration information, see #NETDEV_IMAGE_SETTING_S */
    NETDEV_SET_IMAGECFG                 = 161,              /* 设置图像配置信息,参见#NETDEV_IMAGE_SETTING_S  Set image configuration information, see #NETDEV_IMAGE_SETTING_S */
    NETDEV_GET_IMAGE_EXPOSURE           = 162,              /* 获取通道的图像曝光参数,参见#NETDEV_IMAGE_EXPOSURE_S  get image Exposure configuration information, see #NETDEV_IMAGE_EXPOSURE_S */
    NETDEV_SET_IMAGE_EXPOSURE           = 163,              /* 设置通道的图像曝光参数,参见#NETDEV_IMAGE_EXPOSURE_S  Set image Exposure configuration information, see #NETDEV_IMAGE_EXPOSURE_S */
    NETDEV_GET_IMAGE_LAMP_CTRLCFG       = 164,              /* 获取补光灯参数,参见#NETDEV_LAMP_CTRL_INFO_S  get channel lampctrl configuration information, see #NETDEV_LAMP_CTRL_INFO_S */
    NETDEV_SET_IMAGE_LAMP_CTRLCFG       = 165,              /* 设置补光灯参数,参见#NETDEV_LAMP_CTRL_INFO_S  set channel lampctrl configuration information, see #NETDEV_LAMP_CTRL_INFO_S */
    NETDEV_GET_IMAGE_WHITE_BALANCE      = 166,              /* 获取图像白平衡参数,参见#NETDEV_LAMP_CTRL_INFO_S  get channel lampctrl configuration information, see #NETDEV_LAMP_CTRL_INFO_S */
    NETDEV_SET_IMAGE_WHITE_BALANCE      = 167,              /* 设置图像白平衡参数,参见#NETDEV_LAMP_CTRL_INFO_S  set channel lampctrl configuration information, see #NETDEV_LAMP_CTRL_INFO_S */
    NETDEV_SET_IMAGE_PARAM_RESET        = 168,              /* 设置图像参数默认值set channel image param reset */

    NETDEV_GET_NETWORKCFG               = 170,              /* 获取网络配置信息,参见#NETDEV_NETWORKCFG_S  Get network configuration information, see #NETDEV_NETWORKCFG_S */
    NETDEV_SET_NETWORKCFG               = 171,              /* 设置网络配置信息,参见#NETDEV_NETWORKCFG_S  Set network configuration information, see #NETDEV_NETWORKCFG_S */

    NETDEV_GET_VPN_CFG                  = 172,              /* 获取VPN客户端指定模式信息 参见#NETDEV_VPN_CLIENT_INFO_S get the VPN client specified mode information, see #NETDEV_VPN_CLIENT_INFO_S*/
    NETDEV_SET_VPN_CFG                  = 173,              /* 设置VPN客户端指定模式信息 参见#NETDEV_VPN_CLIENT_INFO_S set the VPN client specified mode information, see #NETDEV_VPN_CLIENT_INFO_S*/
    NETDEV_SET_DNS_CFG                  = 174,              /*设置DNS地址信息 参见#NETDEV_DNS_INFO_S Set DNS info see #NETDEV_DNS_INFO_S*/
    NETDEV_GET_DNS_CFG                  = 175,              /*获取DNS地址信息 参见#NETDEV_DNS_INFO_S Get DNS info see #NETDEV_DNS_INFO_S*/
    NETDEV_SET_NETWORK_CARDS            = 176,              /*设置设备所有网卡的配置信息 参见#NETDEV_NETWORK_CARD_INFO_S set device networkcards infos see #NETDEV_NETWORK_CARD_INFO_S*/
    NETDEV_GET_NETWORK_CARDS            = 177,              /*获取设备所有网卡的配置信息 参见#NETDEV_NETWORK_CARD_INFO_S get device networkcards infos see #NETDEV_NETWORK_CARD_INFO_S*/

    NETDEV_GET_PRIVACYMASKCFG           = 180,              /* 获取隐私遮盖配置信息,参见#NETDEV_PRIVACY_MASK_CFG_S  Get privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_SET_PRIVACYMASKCFG           = 181,              /* 设置隐私遮盖配置信息,参见#NETDEV_PRIVACY_MASK_CFG_S  Set privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_DELETE_PRIVACYMASKCFG        = 182,              /* 删除隐私遮盖配置信息  Delete privacy mask configuration information */

    NETDEV_GET_TAMPERALARM              = 190,              /* 获取遮挡检测告警信息  参见#NETDEV_TAMPER_ALARM_INFO_S  Get tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */
    NETDEV_SET_TAMPERALARM              = 191,              /* 设置遮挡检测告警信息  参见#NETDEV_TAMPER_ALARM_INFO_S  Set tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */

    NETDEV_GET_MOTIONALARM              = 200,              /* 获取运动检测告警信息 参见#NETDEV_MOTION_ALARM_INFO_S  Get motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */
    NETDEV_SET_MOTIONALARM              = 201,              /* 设置运动检测告警信息 参见#NETDEV_MOTION_ALARM_INFO_S  Set motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */

    NETDEV_GET_CROSSLINEALARM           = 202,              /* 获取越界检测告警信息 参见NETDEV_CROSS_LINE_ALARM_INFO_S Get Cross Line alarm configuration information, see #NETDEV_CROSS_LINE_ALARM_INFO_S*/
    NETDEV_SET_CROSSLINEALARM           = 203,              /* 设置越界检测告警信息 参见NETDEV_CROSS_LINE_ALARM_INFO_S Set Cross Line alarm configuration information, see #NETDEV_CROSS_LINE_ALARM_INFO_S*/

    NETDEV_GET_INTRUSIONALARM           = 204,              /* 获取入侵检测告警信息 参见NETDEV_INTRUSION_ALARM_INFO_S Get intrusion alarm configuration information, see #NETDEV_INTRUSION_ALARM_INFO_S*/
    NETDEV_SET_INTRUSIONALARM           = 205,              /* 设置入侵检测告警信息 参见NETDEV_INTRUSION_ALARM_INFO_S Set intrusion alarm configuration information, see #NETDEV_INTRUSION_ALARM_INFO_S*/

    NETDEV_GET_DISKSINFO                = 210,              /* 获取硬盘信息 参见#NETDEV_GET_DISKS_INFO_S  Get disks information, see #NETDEV_GET_DISKS_INFO_S */
    NETDEV_SET_DISKSINFO                = 211,              /* 设置硬盘信息 保留 */

    NETDEV_GET_FOCUSINFO                = 230,              /* 获取聚焦信息 参见#NETDEV_FOCUS_INFO_S Get focus info, see #NETDEV_FOCUS_INFO_S */
    NETDEV_SET_FOCUSINFO                = 231,              /* 设置聚焦信息 参见#NETDEV_FOCUS_INFO_S Set focus info, see #NETDEV_FOCUS_INFO_S */
    NETDEV_GET_IRCUTFILTERINFO          = 232,              /* 获取昼夜模式信息 参见#NETDEV_IRCUT_FILTER_INFO_S Get IRcut filter info, see #NETDEV_IRCUT_FILTER_INFO_S */
    NETDEV_SET_IRCUTFILTERINFO          = 233,              /* 设置昼夜模式信息 参见#NETDEV_IRCUT_FILTER_INFO_S Set IRcut filter info, see #NETDEV_IRCUT_FILTER_INFO_S */
    NETDEV_GET_DEFOGGINGINFO            = 234,              /* 获取透雾模式信息 参见#NETDEV_DEFOGGING_INFO_S Get defogging info, see #NETDEV_DEFOGGING_INFO_S */
    NETDEV_SET_DEFOGGINGINFO            = 235,              /* 设置透雾模式信息 参见#NETDEV_DEFOGGING_INFO_S Set defogging info, see #NETDEV_DEFOGGING_INFO_S */
    NETDEV_SET_CHL_IMAGE_ENHANCE        = 236,              /* 设置通道的图像增强参数set channel image Enhance */
    NETDEV_GET_CHL_IMAGE_ENHANCE        = 237,              /* 获取通道的图像增强参数get channel image Enhance */

    NETDEV_GET_AUDIOIN_CFG              = 240,              /* 获取音频输入参数配置信息 参见#NETDEV_AUDIO_INPUT_CFG_INFO_S get audio input config info see #NETDEV_AUDIO_INPUT_CFG_INFO_S */
    NETDEV_SET_AUDIOIN_CFG              = 241,              /* 设置音频输入参数配置信息 参见#NETDEV_AUDIO_INPUT_CFG_INFO_S set audio input config info see #NETDEV_AUDIO_INPUT_CFG_INFO_S */

    NETDEV_GET_DST_CFG                  = 260,              /* 获取夏令时配置信息 参见#NETDEV_DST_CFG_S Get defogging info, see #NETDEV_DST_CFG_S */
    NETDEV_SET_DST_CFG                  = 261,              /* 设置夏令时配置信息 参见#NETDEV_DST_CFG_S Set defogging info, see #NETDEV_DST_CFG_S */

    NETDEV_GET_RECORDPLANINFO           = 270,              /* 获取录像计划配置信息 参见#NETDEV_RECORD_PLAN_CFG_INFO_S */
    NETDEV_SET_RECORDPLANINFO           = 271,              /* 设置录像计划配置信息 参见#NETDEV_RECORD_PLAN_CFG_INFO_S */
    NETDEV_SET_SNAPSHOT_CFG             = 272,              /*设置指定通道的抓图参数 参见#NETDEV_VIDEO_SNAPSHOT_S Set snapshot info see #NETDEV_VIDEO_SNAPSHOT_S*/
    NETDEV_GET_SNAPSHOT_CFG             = 273,              /*获取指定通道的抓图参数 参见#NETDEV_VIDEO_SNAPSHOT_S Get snapshot info see #NETDEV_VIDEO_SNAPSHOT_S*/

    NETDEV_GET_MOTIONDETECTION_WEEKPLAN     = 280,              /* 获取移动侦测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get motion detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_MOTIONDETECTION_WEEKPLAN     = 281,              /* 设置移动侦测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set motion detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_CROSSLINEDETECTION_WEEKPLAN  = 282,              /* 获取越界检测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get CrossLine detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_CROSSLINEDETECTION_WEEKPLAN  = 283,              /* 设置越界检测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set CrossLine detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_INTRUSIONDETECTION_WEEKPLAN  = 284,              /* 获取区域入侵布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get Intrusion detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_INTRUSIONDETECTION_WEEKPLAN  = 285,              /* 设置区域入侵布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set Intrusion detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_AUDIODETECTION_WEEKPLAN      = 286,              /* 获取音频检测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get Audio detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_AUDIODETECTION_WEEKPLAN      = 287,              /* 设置音频检测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set Audio detection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_OBJTRACK_WEEKPLAN            = 288,              /* 获取目标跟踪布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get ObjTrack deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_OBJTRACK_WEEKPLAN            = 289,              /* 设置目标跟踪布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set ObjTrack deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_VIDEOLOSS_WEEKPLAN           = 290,              /* 获取视频丢失的布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get VideoLoss deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_VIDEOLOSS_WEEKPLAN           = 291,              /* 设置视频丢失的布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set VideoLoss deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_TAMPERDETECTION_WEEKPLAN     = 292,              /* 获取遮挡检测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get TamperDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_TAMPERDETECTION_WEEKPLAN     = 293,              /* 设置遮挡检测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set TamperDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_INPUTSWITCHES_WEEKPLAN       = 294,              /* 获取输入开关量布防计划,参见#NETDEV_SWITCH_WEEK_PLAN_INFO_S  Get InputSwitches deployment plan, see #NETDEV_SWITCH_WEEK_PLAN_INFO_S */
    NETDEV_SET_INPUTSWITCHES_WEEKPLAN       = 295,              /* 设置输入开关量布防计划,,参见#NETDEV_SWITCH_WEEK_PLAN_INFO_S  Set InputSwitches deployment plan, see #NETDEV_SWITCH_WEEK_PLAN_INFO_S */
    NETDEV_GET_OUTPUTSWITCHES_WEEKPLAN      = 296,              /* 获取输出开关量布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get OutputSwitches deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_OUTPUTSWITCHES_WEEKPLAN      = 297,              /* 设置输出开关量布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set OutputSwitches deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_DEFOCUSDETECTION_WEEKPLAN    = 298,              /* 获取虚焦检测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get DefocusDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_DEFOCUSDETECTION_WEEKPLAN    = 299,              /* 设置虚焦检测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set DefocusDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_SCENECHANGE_WEEKPLAN         = 300,              /* 获取场景变更布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get SceneChange deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_SCENECHANGE_WEEKPLAN         = 301,              /* 设置场景变更布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set SceneChange deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_GET_FACEDETECTION_WEEKPLAN       = 302,              /* 获取人脸检测布防计划,参见#NETDEV_WEEK_PLAN_INFO_S  Get FaceDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */
    NETDEV_SET_FACEDETECTION_WEEKPLAN       = 303,              /* 设置人脸检测布防计划,,参见#NETDEV_WEEK_PLAN_INFO_S  Set FaceDetection deployment plan, see #NETDEV_WEEK_PLAN_INFO_S */

    NETDEV_GET_RECORD_STATUS                = 320,              /* 获取录像状态信息 参见#NETDEV_RECORD_STATUS_LIST_S  Get video status information*/

    NETDEV_GET_AUDIO_DECODE_STATUS              = 330,          /* 获取通道所有随路音频解码状态 参见#NETDEV_AUDIO_DECODE_STATUS_LIST_S */
    NETDEV_SET_AUDIO_DECODE_STATUS              = 331,          /* 设置通道所有随路音频解码状态 参见#NETDEV_AUDIO_DECODE_STATUS_LIST_S */

    NETDEV_GET_VIDEO_LOSS_RULE_INFO             = 400,          /* 获取视频丢失告警的配置信息 参见#NETDEV_VIDEO_LOSS_RULE_INFO_S */
    NETDEV_SET_VIDEO_LOSS_RULE_INFO             = 401,          /* 设置视频丢失告警的配置信息 参见#NETDEV_VIDEO_LOSS_RULE_INFO_S */
    NETDEV_GET_VIDEO_LOSS_LINKAGE_ACTIONS       = 410,          /* 获取视频丢失告警的联动动作 参见#NETDEV_VIDEO_LOSS_LINKAGE_ACTIONS */
    NETDEV_SET_VIDEO_LOSS_LINKAGE_ACTIONS       = 411,          /* 设置视频丢失告警的联动动作 参见#NETDEV_VIDEO_LOSS_LINKAGE_ACTIONS */
    NETDEV_GET_TAMPER_DETECTION_RULE_INFO       = 420,          /* 获取视频输入通道的遮挡检测告警的配置 参见#NETDEV_TAMPER_DETECTION_RULE_INFO_S */
    NETDEV_SET_TAMPER_DETECTION_RULE_INFO       = 421,          /* 设置视频输入通道的遮挡检测告警的配置 参见#NETDEV_TAMPER_DETECTION_RULE_INFO_S */
    NETDEV_GET_TAMPER_DETECTION_LINKAGE_ACTIONS = 430,          /* 获取遮挡检测告警的联动动作 参见#NETDEV_TAMPER_DETECTION_LINKAGE_ACTIONS */
    NETDEV_SET_TAMPER_DETECTION_LINKAGE_ACTIONS = 431,          /* 设置遮挡检测告警的联动动作 参见#NETDEV_TAMPER_DETECTION_LINKAGE_ACTIONS */

    NETDEV_GET_MOTION_DETECTION_AREA_TYPE       = 440,          /* 获取视频输入通道运动检测的区域类型 参见#NETDEV_MOTION_DETECTION_AREA_TYPE_S */
    NETDEV_SET_MOTION_DETECTION_AREA_TYPE       = 441,          /* 设置视频输入通道运动检测的区域类型 参见#NETDEV_MOTION_DETECTION_AREA_TYPE_S */
    NETDEV_GET_MOTION_DETECTION_AREA_GRID_INFO  = 442,          /* 获取视频输入通道运动检测的所有宏块区域信息 参见#NETDEV_MOTION_DETECTION_AREA_GRID_INFO_S */
    NETDEV_SET_MOTION_DETECTION_AREA_GRID_INFO  = 443,          /* 设置视频输入通道运动检测的所有宏块区域信息 参见#NETDEV_MOTION_DETECTION_AREA_GRID_INFO_S */
    NETDEV_GET_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST  = 444,    /* 获取视频输入通道运动检测中的所有矩形区域信息 参见#NETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST_S */
    NETDEV_SET_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST  = 445,    /* 设置视频输入通道运动检测中的所有矩形区域信息 参见#NETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST_S */
    NETDEV_GET_MOTION_DETECTION_LINKAGE_ACTIONS = 450,          /* 获取运动检测告警的联动动作 参见#NETDEV_LINKAGE_ACTION_LIST_S */
    NETDEV_SET_MOTION_DETECTION_LINKAGE_ACTIONS = 451,          /* 设置运动检测告警的联动动作 参见#NETDEV_LINKAGE_ACTION_LIST_S */
    NETDEV_GET_INPUT_SWITCHES_LINKAGE_ACTIONS   = 460,          /* 获取输入开关量告警的联动动作 参见#NETDEV_SWITCH_LINKAGE_ACTION_S */
    NETDEV_SET_INPUT_SWITCHES_LINKAGE_ACTIONS   = 461,          /* 设置输入开关量告警的联动动作 参见#NETDEV_SWITCH_LINKAGE_ACTION_S */

    NETDEV_GET_RAID_STATUS                      = 470,          /* 获取阵列状态 参见#NETDEV_RAID_STATUS_S */
    NETDEV_GET_RAID_STORAGE_CONTAINER_INFO_LIST = 471,          /* 先使用NETDEV_GET_RAID_STATUS命令获取阵列状态，阵列状态使能时，获取存储容器信息列表 参见#NETDEV_HDD_INFO_LIST_S */
    NETDEV_GET_STORAGE_CONTAINER_INFO_LIST      = 472,          /* 先使用NETDEV_GET_RAID_STATUS命令获取阵列状态，阵列状态不使能时，获取存储容器信息列表 参见#NETDEV_STORAGE_CONTAINER_INFO_LIST_S */
    NETDEV_GET_HDD_SMART_INFO                   = 473,          /* 获取指定硬盘的Smart检测信息 参见#NETDEV_HDD_SMART_INFO_S */
    NETDEV_SET_HDD_SMART_INFO                   = 474,          /* 设置指定硬盘的Smart检测信息 参见#NETDEV_HDD_SMART_CHECK_INFO_S */
    NETDEV_GET_PHOTO_SERVER_INFO                = 480,          /* 获取照片接收服务器配置信息 参见#NETDEV_PHOTO_SERVER_CFG_INFO */
    NETDEV_SET_PHOTO_SERVER_INFO                = 481,          /* 设置照片接收服务器配置 参见# NETDEV_PHOTO_SERVER_CFG_INFO */

    NETDEV_CFG_INVALID                  = 0xFFFF                /* 无效值  Invalid value */

}NETDEV_CONFIG_COMMAND_E;


/**
 * @brief 日期格式能力集 枚举定义 OSD date format capabilities enumeration 
 * @attention 无 None
 */
typedef enum tagNETDEVDateOSDFormateCap
{
    NETDEV_OSD_DATE_FORMAT_CAP_MD_YYYY          = 0,        /* M/d/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMDD_YYYY        = 1,        /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMM_YYYY        = 2,        /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYY_MMDD        = 3,        /* yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYYMMDDB        = 4,        /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_CAP_XX_MMDD_YYYY     = 5,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMMMDD_YYYY      = 6,        /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMMMM_YYYY      = 7         /* dd MMMM, yyyy */
}NETDEV_OSD_DATE_FORMAT_CAP_E;

/**
 * @brief OSD时间格式能力集枚举 OSD time format capabilities enumeration
 * @attention 无 None
 */
typedef enum tagNETDEVTimeOSDFormateCap
{
    NETDEV_OSD_TIME_FORMAT_CAP_HHMMSS = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_CAP_HH_MM_SS_PM                  /* hh:mm:ss tt */
}NETDEV_OSD_TIME_FORMAT_CAP_E;

/**
 * @brief 输入开关量运行模式 Boolean input operation mode
 * @attention 无 None
 */
typedef enum tagNETDEVBooleanMode
{
    NETDEV_BOOLEAN_MODE_OPEN   = 1,                         /* 常开  Always open */
    NETDEV_BOOLEAN_MODE_CLOSE  = 2,                         /* 常闭  Always closed */
    NETDEV_BOOLEAN_MODE_INVALID
}NETDEV_BOOLEAN_MODE_E;

/**
 * @brief 开关量状态 Boolean input operation mode
 * @attention 无 None
 */
typedef enum tagNETDEVRelayOutPutState
{
    NETDEV_BOOLEAN_STATUS_ACTIVE    = 0,                /* 触发状态  Triggered */
    NETDEV_BOOLEAN_STATUS_INACTIVE  = 1                 /* 非触发状态 Not triggered */
}NETDEV_RELAYOUTPUT_STATE_E;

/**
 * @brief 控制手动告警开关量状态命令
 * @attention 无 None
 */
typedef enum tagNETDEVOutPutManualAlarmCmd
{
    NETDEV_MANUAL_ALARM_CMD_CLOSE    = 0,                /* 关闭 close */
    NETDEV_MANUAL_ALARM_CMD_TRIGGER  = 1                 /* 触发  Triggered */
}NETDEV_MANUAL_ALARM_CMD_E;

/**
* @brief 媒体数据流格式
* @attention 无
*/
typedef enum tagNETDEVMediaDataFormat
{
    NETDEV_MEDIA_DATA_TS            = 0,            /* TS */
    NETDEV_MEDIA_DATA_RTP_ES        = 3             /* RTP + ES */
}NETDEV_MEDIA_DATA_FORMAT_E;

/**
* @brief 协议类型
* @attention 无
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP  = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP  = 2
}NETDEV_PROTOCOL_TYPE_E;

/**
* @brief 时区 Time Zone
* @attention 无 None
*/
typedef enum tagNETDEVTimeZone
{
    NETDEV_TIME_ZONE_W1200 = 0,              /* W12 */
    NETDEV_TIME_ZONE_W1100 = 1,              /* W11 */
    NETDEV_TIME_ZONE_W1000 = 2,              /* W10 */
    NETDEV_TIME_ZONE_W0900 = 3,              /* W9 */
    NETDEV_TIME_ZONE_W0800 = 4,              /* W8 */
    NETDEV_TIME_ZONE_W0700 = 5,              /* W7 */
    NETDEV_TIME_ZONE_W0600 = 6,              /* W6 */
    NETDEV_TIME_ZONE_W0500 = 7,              /* W5 */
    NETDEV_TIME_ZONE_W0430 = 8,              /* W4:30 */
    NETDEV_TIME_ZONE_W0400 = 9,              /* W4 */
    NETDEV_TIME_ZONE_W0330 = 10,             /* W3:30 */
    NETDEV_TIME_ZONE_W0300 = 11,             /* W3 */
    NETDEV_TIME_ZONE_W0200 = 12,             /* W2 */
    NETDEV_TIME_ZONE_W0100 = 13,             /* W1 */
    NETDEV_TIME_ZONE_0000  = 14,             /* W0 */
    NETDEV_TIME_ZONE_E0100 = 15,             /* E1 */
    NETDEV_TIME_ZONE_E0200 = 16,             /* E2 */
    NETDEV_TIME_ZONE_E0300 = 17,             /* E3 */
    NETDEV_TIME_ZONE_E0330 = 18,             /* E3:30 */
    NETDEV_TIME_ZONE_E0400 = 19,             /* E4 */
    NETDEV_TIME_ZONE_E0430 = 20,             /* E4:30 */
    NETDEV_TIME_ZONE_E0500 = 21,             /* E5 */
    NETDEV_TIME_ZONE_E0530 = 22,             /* E5:30 */
    NETDEV_TIME_ZONE_E0545 = 23,             /* E5:45 */
    NETDEV_TIME_ZONE_E0600 = 24,             /* E6 */
    NETDEV_TIME_ZONE_E0630 = 25,             /* E6:30 */
    NETDEV_TIME_ZONE_E0700 = 26,             /* E7 */
    NETDEV_TIME_ZONE_E0800 = 27,             /* E8 */
    NETDEV_TIME_ZONE_E0900 = 28,             /* E9 */
    NETDEV_TIME_ZONE_E0930 = 29,             /* E9:30 */
    NETDEV_TIME_ZONE_E1000 = 30,             /* E10 */
    NETDEV_TIME_ZONE_E1100 = 31,             /* E11 */
    NETDEV_TIME_ZONE_E1200 = 32,             /* E12 */
    NETDEV_TIME_ZONE_E1300 = 33,             /* E13 */
    NETDEV_TIME_ZONE_W0930 = 34,             /* W9:30 */
    NETDEV_TIME_ZONE_E0830 = 35,             /* E8:30 */
    NETDEV_TIME_ZONE_E0845 = 36,             /* E8:45 */
    NETDEV_TIME_ZONE_E1030 = 37,             /* E10:30 */
    NETDEV_TIME_ZONE_E1245 = 38,             /* E12:45 */
    NETDEV_TIME_ZONE_E1400 = 39,             /* E14 */

    NETDEV_TIME_ZONE_INVALID = 0xFF          /* Invalid value */
}NETDEV_TIME_ZONE_E;

/**
* @brief Week emnu
* @attention 无
*/
typedef enum tagNetDEVDayInWeek
{
    NETDEV_WEEK_MONDAY          = 0,        /* 周一 */
    NETDEV_WEEK_TUESDAY         = 1,        /* 周二 */
    NETDEV_WEEK_WEDNESDAY       = 2,        /* 周三 */
    NETDEV_WEEK_THURSDAY        = 3,        /* 周四 */
    NETDEV_WEEK_FRIDAY          = 4,        /* 周五 */
    NETDEV_WEEK_SATURDAY        = 5,        /* 周六 */
    NETDEV_WEEK_SUNDAY          = 6,        /* 周日 */
    NETDEV_WEEK_HOLIDAY         = 7,        /* 假日 */
    NETDEV_WEEK_INVALID         = 0xff      /* 无效值 Invalid value */
}NETDEV_DAY_IN_WEEK_E;

/**
* @brief 夏令时偏移时间 DST offset time
* @attention 无
*/
typedef enum tagNetDEVDSTOffsetTime
{
    NETDEV_DST_OFFSET_TIME_30MIN                 = 30,          /* 30分钟  30Minutes */
    NETDEV_DST_OFFSET_TIME_60MIN                 = 60,          /* 60分钟  60Minutes */
    NETDEV_DST_OFFSET_TIME_90MIN                 = 90,          /* 90分钟  90Minutes */
    NETDEV_DST_OFFSET_TIME_120MIN                = 120,         /* 120分钟  120Minutes */
    NETDEV_DST_OFFSET_TIME_INVALID               = 0xff         /* 无效值 Invalid value */
}NETDEV_DST_OFFSET_TIME;



/**
 * @brief 磁盘工作状态枚举 Disk work status 
 * @attention 无 None
 */
typedef enum tagNETDEVDiskWorkStatus
{
    NETDEV_DISK_WORK_STATUS_EMPTY       = 0,            /* 空状态 Empty */
    NETDEV_DISK_WORK_STATUS_UNFORMAT    = 1,            /* 未格式化状态 Unformat */
    NETDEV_DISK_WORK_STATUS_FORMATING   = 2,            /* 格式化状态 Formating */
    NETDEV_DISK_WORK_STATUS_RUNNING     = 3,            /* 运行状态 Running */
    NETDEV_DISK_WORK_STATUS_HIBERNATE   = 4,            /* 休眠状态 Hibernate */
    NETDEV_DISK_WORK_STATUS_ABNORMAL    = 5,            /* 异常状态 Abnormal */
    NETDEV_DISK_WORK_STATUS_UNKNOWN     = 6,            /* 未知状态 Unknown */

    NETDEV_DISK_WORK_STATUS_INVALID                     /* 无效值 Invalid value */
}NETDEV_DISK_WORK_STATUS_E;

/**
* @enum tagNETDEVHDDType
* @brief 磁盘类型
* @attention 无 None
*/
typedef enum tagNETDEVHDDType
{
    NETDEV_HDD_TYPE_LOCAL_HDD       = 0,            /* LocalHDD */
    NETDEV_HDD_TYPE_NO1_EXTEND_HDD  = 1,            /* No1ExtendCabinetHDD */
    NETDEV_HDD_TYPE_NO2_EXTEND_HDD  = 2,            /* No2ExtendCabinetHDD */

    NETDEV_HDD_TYPE_INVALID = 0xFF                  /* Invalid value */
}NETDEV_HDD_TYPE_E;

/**
* @enum tagNETDEVHDDWorkMode
* @brief 磁盘工作模式
* @attention 无 None
*/
typedef enum tagNETDEVHDDWorkMode
{
    NETDEV_HDD_WORK_MODE_COMMON     = 0,        /* 普通盘 */
    NETDEV_HDD_WORK_MODE_RAID       = 1,        /* 阵列盘 */
    NETDEV_HDD_WORK_MODE_HOT_BACKUP = 2,        /* 热备盘 */

    NETDEV_HDD_WORK_MODE_INVALID    = 0xFF      /* Invalid value */
}NETDEV_HDD_WORK_MODE_E;

/**
* @enum tagNETDEVHDDStatus
* @brief 磁盘状态
* @attention 无 None
*/
typedef enum tagNETDEVHDDStatus
{
    NETDEV_HDD_STATUS_NO        = 0,            /* 无硬盘 */
    NETDEV_HDD_STATUS_NORMAL    = 1,            /* 正常 */
    NETDEV_HDD_STATUS_ABNORMAL  = 2,            /* 异常 */

    NETDEV_HDD_STATUS_INVALID = 0xFF            /* Invalid value */
}NETDEV_HDD_STATUS_E;

/**
* @enum tagNETDEVStorageContainerStatus
* @brief 存储容器状态
* @attention 无 None
*/
typedef enum tagNETDEVStorageContainerStatus
{
    NETDEV_STORAGE_CONTAINER_STATUS_NO                      = 0,            /* 无硬盘/空闲 */
    NETDEV_STORAGE_CONTAINER_STATUS_UNFORMATTED             = 1,            /* 未格式化 */
    NETDEV_STORAGE_CONTAINER_STATUS_FORMATTING       = 2,            /* 正在格式化 */
    NETDEV_STORAGE_CONTAINER_STATUS_NORMAL           = 3,            /* 硬盘状态良好 */
    NETDEV_STORAGE_CONTAINER_STATUS_SLEEP            = 4,            /* 休眠 */
    NETDEV_STORAGE_CONTAINER_STATUS_ABNORMAL                = 5,            /* 异常 */
    NETDEV_STORAGE_CONTAINER_STATUS_SWITCH           = 6,            /* 切换中 */
    NETDEV_STORAGE_CONTAINER_STATUS_UNINSTALLED      = 7,            /* 已卸载 */

    NETDEV_STORAGE_CONTAINER_STATUS_INVALID                 = 0xFF          /* Invalid value */
}NETDEV_STORAGE_CONTAINER_STATUS_E;

/**
* @enum tagNETDEVStorageContainerProperty
* @brief 存储容器属性
* @attention 无 None
*/
typedef enum tagNETDEVStorageContainerProperty
{
    NETDEV_STORAGE_CONTAINER_PROPERTY_RW                = 0,            /* 读写 */
    NETDEV_STORAGE_CONTAINER_PROPERTY_R                 = 1,            /* 只读 */
    NETDEV_STORAGE_CONTAINER_PROPERTY_REDUNDANT         = 2,            /* 冗余 */

    NETDEV_STORAGE_CONTAINER_PROPERTY_INVALID           = 0xFF          /* Invalid value */
}NETDEV_STORAGE_CONTAINER_PROPERTY_E;

/**
* @enum tagNETDEVStorageContainerUsageType
* @brief 存储容器用途
* @attention 无 None
*/
typedef enum tagNETDEVStorageContainerUsageType
{
    NETDEV_STORAGE_CONTAINER_USAGE_TYPE_RECORD_CAPTURE   = 0,        /* 录像/抓图 */
    NETDEV_STORAGE_CONTAINER_USAGE_TYPE_BACKUP           = 1,        /* 备份 */

    NETDEV_STORAGE_CONTAINER_USAGE_TYPE_INVALID          = 0xFF      /* Invalid value */
}NETDEV_STORAGE_CONTAINER_USAGE_TYPE_E;

/**
* @enum tagNETDEVHDDSmartCheckType
* @brief 硬盘Smart检测类型
* @attention 无 None
*/
typedef enum tagNETDEVHDDSmartCheckType
{
    NETDEV_HDD_SMART_CHECK_TYPE_BRIEF          = 0,        /* 简短型 */
    NETDEV_HDD_SMART_CHECK_TYPE_EXTEND         = 1,        /* 扩展型 */
    NETDEV_HDD_SMART_CHECK_TYPE_TRANSMISSION   = 2,        /* 传输型 */

    NETDEV_HDD_SMART_CHECK_TYPE_INVALID        = 0xFF      /* Invalid value */
}NETDEV_HDD_SMART_CHECK_TYPE_E;

/**
* @enum tagNETDEVHDDHealthAssessmentStatus
* @brief 硬盘健康评估状态
* @attention 无 None
*/
typedef enum tagNETDEVHDDHealthAssessmentStatus
{
    NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_NORMAL           = 0,        /* 健康状态良好 */
    NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_PART_DAMAGE      = 1,        /* 存在坏扇区 */
    NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_FAULT            = 2,        /* 故障 */

    NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_INVALID        = 0xFF      /* Invalid value */
}NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_E;

/**
* @enum tagNETDEVHDDSmartAssessmentStatus
* @brief 硬盘Smart评估状态
* @attention 无 None
*/
typedef enum tagNETDEVHDDSmartAssessmentStatus
{
    NETDEV_HDD_SMART_ASSESSMENT_STATUS_NORMAL       = 0,        /* 良好 */
    NETDEV_HDD_SMART_ASSESSMENT_STATUS_WARNING      = 1,        /* 警告 */
    NETDEV_HDD_SMART_ASSESSMENT_STATUS_FAULT        = 2,        /* 故障 */

    NETDEV_HDD_SMART_ASSESSMENT_STATUS_INVALID      = 0xFF      /* Invalid value */
}NETDEV_HDD_SMART_ASSESSMENT_STATUS_E;

/**
* @enum tagNETDEVHDDSmartCheckStatus
* @brief 硬盘Smart检测状态
* @attention 无 None
*/
typedef enum tagNETDEVHDDSmartCheckStatus
{
    NETDEV_HDD_SMART_CHECK_STATUS_NOT                = 0,        /* 未检测 */
    NETDEV_HDD_SMART_CHECK_STATUS_IN_PORGRESS        = 1,        /* 正在自检 */
    NETDEV_HDD_SMART_CHECK_STATUS_SUCCESS            = 2,        /* 自检成功 */
    NETDEV_HDD_SMART_CHECK_STATUS_RECOGNITION_FAIL   = 3,        /* 硬盘识别失败 */
    NETDEV_HDD_SMART_CHECK_STATUS_FAIL               = 4,        /* SMART自检失败 */
    NETDEV_HDD_SMART_CHECK_STATUS_NOT_SUPPORT        = 5,        /* 硬盘不支持检测 */

    NETDEV_HDD_SMART_CHECK_STATUS_INVALID            = 0xFF      /* Invalid value */
}NETDEV_HDD_SMART_CHECK_STATUS_E;

/**
* @brief 图像播放流畅性 Picture fluency
* @attention 无
*/
typedef enum tagNetDEVPictureFluency
{
    NETDEV_PICTURE_REAL                 = 0,                /* 实时性优先 Real-time first */
    NETDEV_PICTURE_FLUENCY              = 1,                /* 流畅性优先 Fluency first */
    NETDEV_PICTURE_BALANCE_NEW          = 3,                /* 均衡 Balance */
    NETDEV_PICTURE_RTMP_FLUENCY         = 4,                /* RTMP流畅性优先 RTMP fluency first */

    NETDEV_PICTURE_FLUENCY_INVALID      = 0xff              /* 无效值 Invalid value */
}NETDEV_PICTURE_FLUENCY_E;

/**
* @brief 云台看守位操作命令 枚举定义 PTZ home position operation commands Enumeration Definition
* @attention 无 None
*/
typedef enum tagNETDEVPtzHomePositionCmd
{
    NETDEV_PTZ_SET_HOMEPOSITION   = 0,            /* 设置看守位  Set home position */
    NETDEV_PTZ_GOTO_HOMEPOSITION  = 1             /* 转到看守位  Go to home position */
}NETDEV_PTZ_HOMEPOSITIONCMD_E;

/**
* @brief 聚焦状态 PTZ Move status
* @attention 无 None
*/
typedef enum tagNETDEVPTZMoveStatus
{
    NETDEV_PTZ_MOVE_STATUS_IDLE     = 0,             /* 空闲 Free */
    NETDEV_PTZ_MOVE_STATUS_MOVING   = 1,             /* 正在聚焦 Moving */

    NETDEV_PTZ_MOVE_STATUS_INVALID  = 0xff           /* 无效值 Invalid value */
}NETDEV_PTZ_MOVE_STATUS_E;

/**
 * @brief 昼夜模式 IRCut filter mode
 * @attention 无 None
 */
typedef enum  tagNETDEVIrCutFilterMode
{
    NETDEV_IR_CUT_FILTER_ON     = 0,            /* 白天模式 On */
    NETDEV_IR_CUT_FILTER_OFF    = 1,            /* 夜晚模式 Off */
    NETDEV_IR_CUT_FILTER_AUTO   = 2             /* 自动模式 Auto */
}NETDEV_IR_CUT_FILTER_MODE_E;

/**
 * @brief 透雾模式枚举 Defogging mode
 * @attention 无 None
 */
typedef enum  tagNETDEVDefoggingMode
{
    NETDEV_DEFOGGING_ON = 0,            /* 开 On */
    NETDEV_DEFOGGING_OFF                /* 关 Off */
}NETDEV_DEFOGGING_MODE_E;

/**
 * @brief 聚焦模式枚举 Focus mode
 * @attention 无 None
 */
typedef enum tagNETDEVFocusMode
{
    NETDEV_FOCUS_AUTO           = 1,            /* 自动聚焦 Auto */
    NETDEV_FOCUS_MANUAL         = 2             /* 手动聚焦 Manual */
}NETDEV_FOCUS_MODE_E;

/**
 * @brief 最小聚焦距离枚举 Focus near limit
 * @attention 无 None
 */
typedef enum tagNETDEVFocusNearlimit
{
    NETDEV_FOCUS_NEARLIMIT_10       = 1,            /* 10cm */
    NETDEV_FOCUS_NEARLIMIT_100      = 2,            /* 100cm */
    NETDEV_FOCUS_NEARLIMIT_300      = 3,            /* 300cm */
    NETDEV_FOCUS_NEARLIMIT_1000     = 4,            /* 1000cm */

    NETDEV_FOCUS_NEARLIMI_INVALID   = 0xff          /* 无效值  Invalid value */
}NETDEV_FOCUS_NEARLIMIT_E;

/**
* @brief 录像类型 Record Type
* @attention 无
*/
typedef enum tagNETDEVRecordType
{
    NETDEV_RECORD_TYPE_MANUAL  = 0,
    NETDEV_RECORD_TYPE_NORMAL = 1
}NETDEV_RECORD_TYPE_E;


/**
 * @brief 录像查询位置 Video Position
 * @attention 无 None
 */
typedef enum tagNETDEVVideoPosition
{
    NETDEV_POSITION_LOCAL       = 1,            /* 设备自身录像 */
    NETDEV_POSITION_CHANNEL     = 2,            /* 设备下的通道录像 */
    NETDEV_POSITION_INVALID
}NETDEV_VIDEO_POSITION_E;

/**
 * @brief 录像状态 Video Status
 * @attention 无 None
 */
typedef enum tagNETDEVVideoStatus
{
    NETDEV_VIDEO_NONE       = 0,        /* 无录像 No video */
    NETDEV_VIDEO_EVENT      = 1,        /* 事件录像 Event video */
    NETDEV_VIDEO_NORMAL     = 2,        /* 普通录像 Normal video */
    NETDEV_VIDEO_INVALID
}NETDEV_VIDEO_STATUS_E;


/**
* @brief 能力集命令 Device capability commond
* @attention 无
*/
typedef enum tagNETDEVCapabilityCommond
{
    NETDEV_CAP_VIDEO_ENCODE         = 1,            /* 视频编码能力集 参见# NETDEV_VIDEO_STREAM_CAP_S。 Video encoding capability. See # NETDEV_VIDEO_STREAM_CAP_S for reference*/
    NETDEV_CAP_OSD                  = 2,            /* OSD参数能力集 参见# NETDEV_OSD_CAP_S。 OSD parameter capability. See # NETDEV_OSD_CAP_S for reference*/
    NETDEV_CAP_SMART                = 3,            /* 智能能力集 参见# NETDEV_SMART_CAP_S。 Smart capability. See # NETDEV_SMART_CAP_S for reference */
    NETDEV_CAP_VIDEO_ENCODE_EX      = 4,            /* 视频编码能力集（扩展） 参见# NETDEV_VIDEO_STREAM_CAP_EX_S。 Video encoding capability. See # NETDEV_VIDEO_STREAM_CAP_EX_S for reference */
    NETDEV_CAP_IMAGE                = 5,            /* 图像参数能力集 参见#NETDEV_IMAGE_CAP_S。 Image capability See # NETDEV_IMAGE_CAP_S for reference*/
    NETDEV_CAP_AUDIO                = 6,            /* 音频能力集 参见 NETDEV_AUDIO_CAPABILITY_INFO_S */
    NETDEV_CAP_VIDEO_SNAPSHOT       = 7,            /* 视频输入通道的抓图参数能力 参见#NETDEV_VIDEO_SNAP_CAP_S Video snapshot capability. See # NETDEV_VIDEO_SNAP_CAP_S for reference   目前仅IPC支持*/
    NETDEV_CAP_FACE_RECOGNAZE       = 10,           /* 人脸识别能力 目前仅NVR支持, 参见NETDEV_DEV_FACE_CAP_INFO_S */

    NETDEV_CAP_INVALID              = 0Xff
}NETDEV_CAPABILITY_COMMOND_E;

/**
* @brief 编码格式类型
* @attention 无
*/
typedef enum tagNETDEVVideoEncodeType
{
    NETDEV_VIDEO_ENCODE_H264    = 1,
    NETDEV_VIDEO_ENCODE_MPEG4   = 2,
    NETDEV_VIDEO_ENCODE_JPEG    = 3,

    NETDEV_VIDEO_ENCODE_INVALID = 0XFF
}NETDEV_ENCODE_TYPE_E;


/**
* @brief 客流量统计模式类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVTrafficStatisticsType
{
    NETDEV_TRAFFIC_STATISTICS_TYPE_IN   = 0,        /* 统计类型：进入 Statistics type : Enter */
    NETDEV_TRAFFIC_STATISTICS_TYPE_OUT  = 1,        /* 统计类型：离开 Statistics type : Exit */
    NETDEV_TRAFFIC_STATISTICS_TYPE_ALL  = 2,        /* 统计类型：所有 Statistics type : All */
    NETDEV_TRAFFIC_STATISTICS_TYPE_BUTT
}NETDEV_TRAFFIC_STATISTICS_TYPE_E;

/**
* @brief 客流量统计报表类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVFormType
{
    NETDEV_FORM_TYPE_DAY    = 0,            /* 日报表 Form type : Day */
    NETDEV_FORM_TYPE_WEEK   = 1,            /* 周报表 Form type : Week */
    NETDEV_FORM_TYPE_MONTH  = 2,            /* 月报表 Form type : Month */
    NETDEV_FORM_TYPE_YEAR   = 3,            /* 年报表 Form type : Year */
    NETDEV_FORM_TYPE_BUTT
}NETDEV_FORM_TYPE_E;

/**
* @brief 地址类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVAddrType
{
    NETDEV_ADDR_TYPE_IPV4       = 0,             /* IPV4 */
    NETDEV_ADDR_TYPE_IPV6       = 1,             /* IPV6 */
    NETDEV_ADDR_TYPE_DOMAIN     = 2,             /* 域名 */
    NETDEV_ADDR_TYPE_IPV4_IPV6  = 3,             /* IPV4和IPV6都需要 */
    NETDEV_ADDR_TYPE_INVALID    = 0XFFFF         /* 无效值 */
}NETDEV_ADDR_TYPE_E;

/**
* @brief 图像扩展编码模式类型 枚举定义 Enumeration of smart image encoding mode
* @attention 无 None
*/
typedef enum tagNETDEVSmartEncodeMode
{
    NETDEV_SMART_ENCODE_MODE_OFF      = 0,      /* 关闭 Off*/
    NETDEV_SMART_ENCODE_MODE_BASIC    = 1,      /* 基础智能编码模式 Basic mode*/
    NETDEV_SMART_ENCODE_MODE_ADVANCED           /* 高级智能编码模式 Advanced mode*/
}NETDEV_SMART_ENCODE_MODE_E;
/**
* @brief 码率模式类型 枚举定义 Enumeration of bit rate mode
* @attention 无 None
*/
typedef enum tagNETDEVBitRateType
{
    NETDEV_BIT_RATE_TYPE_CBR      = 0,         /* CBR模式 CBR mode*/
    NETDEV_BIT_RATE_TYPE_VBR      = 1          /* VBR模式 VBR mode*/
}NETDEV_BIT_RATE_TYPE_E;

/**
* @brief 主码流类型 枚举定义 Enumeration of main stream type
* @attention 无 None
*/
typedef enum tagNETDEVMainStreamType
{
    NETDEV_MAIN_STREAM_TYPE_TIME     = 0,      /* 定时主码流 Scheduled main stream*/
    NETDEV_MAIN_STREAM_TYPE_EVENT    = 1       /* 事件主码流 Event main stream*/
}NETDEV_MAIN_STREAM_TYPE_E;

/**
* @brief GOP类型 枚举定义 Enumeration of GOP type
* @attention 无 None
*/
typedef enum tagNETDEVGopType
{
    NETDEV_GOP_TYPE_IP       = 0,      /* IP */
    NETDEV_GOP_TYPE_IBP      = 1,      /* IBP */
    NETDEV_GOP_TYPE_IBBP     = 2,      /* IBBP */
    NETDEV_GOP_TYPE_I        = 3       /* I */
}NETDEV_GOP_TYPE_E;

/**
* @brief OSD内容类型 枚举定义 Enumeration of content type
* @attention 无 None
*/
typedef enum tagNETDEVOSDContentType
{
    NETDEV_OSD_CONTENT_TYPE_NOTUSE                      = 0,                    /* 不使用 Not used*/
    NETDEV_OSD_CONTENT_TYPE_CUSTOM                      = 1,                    /* 自定义 Custom*/
    NETDEV_OSD_CONTENT_TYPE_DATE_AND_TIME               = 2,                    /* 时间日期 Time and date*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_CONTROLLER              = 3,                    /* 云台控制者 PTZ controller*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_COORDINATES             = 4,                    /* 云台坐标 PTZ Coordinates*/
    NETDEV_OSD_CONTENT_TYPE_CRUISE                      = 5,                    /* 巡航信息 Patrol*/
    NETDEV_OSD_CONTENT_TYPE_ZOOM                        = 6,                    /* 变倍信息 Zoom*/
    NETDEV_OSD_CONTENT_TYPE_PRESET                      = 7,                    /* 预置位信息  Preset*/
    NETDEV_OSD_CONTENT_TYPE_ALARM_INFO                  = 8,                    /* 报警信息 Alarm */
    NETDEV_OSD_CONTENT_TYPE_ENCODE                      = 9,                    /* 编码信息 Encoding*/
    NETDEV_OSD_CONTENT_TYPE_SERIAL_PORT                 = 10,                   /* 串口OSD Serial Port OSD*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_ORIENTATION             = 11,                   /* 云台方位信息 PZT direction*/
    NETDEV_OSD_CONTENT_TYPE_CHN_NAME                    = 12,                   /* 通道名称 Channel name*/
    NETDEV_OSD_CONTENT_TYPE_DEBUG                       = 13,                   /* 调试OSD  Debug OSD*/
    NETDEV_OSD_CONTENT_TYPE_PEOPLE_COUNTING             = 14,                   /* 人数统计OSD People counting OSD*/
    NETDEV_OSD_CONTENT_TYPE_NETWORK_PORT                = 15,                   /* 网口OSD Network Port OSD*/
    NETDEV_OSD_CONTENT_TYPE_TIME                        = 16,                   /* 时间 Time*/
    NETDEV_OSD_CONTENT_TYPE_DATE                        = 17,                   /* 日期 Date*/
    NETDEV_OSD_CONTENT_TYPE_SMART_CONTENT               = 18,                   /* 超感类OSD Sensing OSD*/
    NETDEV_OSD_CONTENT_TYPE_BATTERY                     = 19,                   /* 电池OSD Battery OSD*/
    NETDEV_OSD_CONTENT_TYPE_SCROLL_OSD                  = 20,                   /* 滚动字幕OSD Scroll text OSD*/
    NETDEV_OSD_CONTENT_TYPE_PICTURE_OVERLAY             = 21,                   /* LOGO OSD */
    NETDEV_OSD_CONTENT_TYPE_MOTOR_VEHICLE_NUM           = 22,                   /* 天网卡口机动车流量 Vehicle flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_NON_MOTOR_VEHICLE_NUM       = 23,                   /* 天网卡口非机动车流量 Non-vehicle flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_PEOPLE_NUM                  = 24,                   /* 天网卡口行人流量 Pedestrian flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_INFOOSD_NUM                 = 25                    /* INFOOSD类型数目 Number of INFOOSDtype*/
}NETDEV_OSD_CONTENT_TYPE_E;

/**
 * @brief 日期格式 枚举定义 Enumeration of date format
 * @attention 无 None
 */
typedef enum tagNETDEVDateOSDFormate
{
    NETDEV_OSD_DATE_FORMAT_YYYY_MMDD                = 0,           /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_MMDD_YYYY                = 1,           /* MM-dd-yyyy */
    NETDEV_OSD_DATE_FORMAT_CHINESE_YYYY_MMDD        = 2,           /* yyyy年MM月dd日 yyyy/MM/dd*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_MMDD_YYYY        = 3,           /* MM月dd日yyyy年 MM/dd/yyyy*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_YYY_MMDD_X       = 4,           /*  yyyy年MM月dd日 星期X。 dddd yyyy MM dd*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_MMDD_YYYY_X      = 5,           /* MM月dd日yyyy年 星期X。 dddd MM dd yyyy*/
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDMM_YYYY        = 100,         /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_MMDD_YYYY        = 101,         /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDMMMM_YYYY      = 102,         /* dd MMMM, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_MMMMDD_YYYY      = 103,         /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDDDMMMM_YYYY  = 104,         /* dddd, dd MMMM, yyyy  */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDDDMMMM_DDYYYY = 105,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_YYYY_MMDD        = 106,         /*  yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_YYYY_MMMMDD      = 107,         /*  yyyy, MMMM dd */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDYY_MMDD      = 108         /*  dddd, yy, MM dd */
}NETDEV_OSD_DATE_FORMAT_E;

/**
 * @brief OSD时间格式枚举 Enumeration of OSD time format
 * @attention 无 None
 */
typedef enum tagNETDEVTimeOSDFormate
{
    NETDEV_OSD_TIME_FORMAT_HHMMSS         = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_T     = 1,                  /* hh:mm:ss t.t. */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_TT    = 2,                  /* hh:mm:ss tt */
    NETDEV_OSD_TIME_FORMAT_TT_HH_MM_SS    = 3,                  /*  tt hh:mm:ss */
    NETDEV_OSD_TIME_FORMAT_PM_HH_MM_SS    = 4,                  /* 下午 hh:mm:ss  P.M. hh:mm:ss*/
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_XX    = 5,                  /* HH:mm:ss.xxx */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_XX_TT = 6                   /* hh:mm:ss.xxx tt */

}NETDEV_OSD_TIME_FORMAT_E;

/**
 * @brief OSD字体形式枚举 Enumeration of OSD font style
 * @attention 无 None
 */
typedef enum tagNETDEVOSDFontStyle
{
    NETDEV_OSD_FONT_STYLE_BACKGROUND    = 0,                  /* 背景 Background*/
    NETDEV_OSD_FONT_STYLE_STROKE        = 1,                  /* 描边 Stroke*/
    NETDEV_OSD_FONT_STYLE_HOLLOW        = 2,                  /* 空心 Hollow*/
    NETDEV_OSD_FONT_STYLE_NORMAL        = 3                   /* 正常 Normal*/
}NETDEV_OSD_FONT_STYLE_E;

/**
 * @brief OSD字体大小枚举 Enumeration of OSD font size
 * @attention 无 None
 */
typedef enum tagNETDEVOSDFontSize
{
    NETDEV_OSD_FONT_SIZE_LARGE      = 0,                  /* 特大 X-large*/
    NETDEV_OSD_FONT_SIZE_BIG        = 1,                  /* 大 Large*/
    NETDEV_OSD_FONT_SIZE_MEDIUM     = 2,                  /* 中 Medium*/
    NETDEV_OSD_FONT_SIZE_SMALL      = 3                   /* 小 Small*/
}NETDEV_OSD_FONT_SIZE_E;

/**
 * @brief OSD字体大小枚举 Enumeration of OSD font size
 * @attention 无 None
 */
typedef enum tagNETDEVOSDMinMargin
{
    NETDEV_OSD_MIN_MARGIN_NONE    = 0,               /* 无 None*/
    NETDEV_OSD_MIN_MARGIN_SINGLE  = 1,               /* 一个字符宽度 One char width*/
    NETDEV_OSD_MIN_MARGIN_DOUBLE  = 2                /* 两个字符宽度 Two char width*/
}NETDEV_OSD_MIN_MARGIN_E;

/**
 * @brief OSD区域内对齐枚举 Enumeration of OSD align
 * @attention 无 None
 */
typedef enum tagNETDEVOSDAlign
{
    NETDEV_OSD_ALIGN_LEFT       = 0,               /* 左对齐 Left*/
    NETDEV_OSD_ALIGN_RIGHT      = 1                /* 右对齐 Right*/
}NETDEV_OSD_ALIGN_E;

/**
*@brief 启流模式类型枚举
*@attention 无
*/
typedef enum tagNETDEVPullStreamMode
{
    NETDEV_STREAM_MODE_SERVER_DISTRIBUTE    = 0,   /* 服务器分配 */
    NETDEV_STREAM_MODE_FORCE_CDN            = 1    /* 强制分发 */
}NETDEV_PULL_STREAM_MODE_E;


/**
*@brief 分发模式类型枚举
*@attention 无
*/
typedef enum tagNETDEVDistributeMode
{
    NETDEV_DISTRIBUTE_MODE_AUTO       = 0,            /* 自动 */
    NETDEV_DISTRIBUTE_MODE_FORCE      = 1             /* 强制 */
}NETDEV_DISTRIBUTE_MODE_E;


/**
*@brief 登录类型枚举
*@attention 无
*/
typedef enum tagNETDEVLoginType
{
    NETDEV_LOGIN_TYPE_LOCAL             = 0,          /* 本地登录 */
    NETDEV_LOGIN_TYPE_DYNAMIC           = 1,          /* 动态密码登录 */
    NETDEV_LOGIN_TYPE_LOCAL_ALL         = 2,          /* 支持第三方设备 */
    NETDEV_LOGIN_TYPE_CLOUD_DEVICE      = 3,          /* 云设备登录 */
    NETDEV_LOGIN_TYPE_CLOUD_DEVICE_SN   = 4           /* 云设备SN登录 */
}NETDEV_LOGIN_TYPE_E;

/**
*@brief 接入协议枚举
*@attention 无
*/
typedef enum tagNETDEVLoginProto
{
    NETDEV_LOGIN_PROTO_ONVIF             = 0,           /* 以ONVIF协议接入 */
    NETDEV_LOGIN_PROTO_PRIVATE           = 1            /* 以私有协议接入 */
}NETDEV_LOGIN_PROTO_E;



/**
* @brief 告警协议 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmProtocol
{
    NETDEV_ALARM_PROTOCOL_ONVIF   = 0X01,                   /* ONVIF */
    NETDEV_ALARM_PROTOCOL_PRIVATE = 0X02,                   /* private */

    NETDEV_ALARM_PROTOCOL_INVALID = 0XFF                    /* 无效值*/
}NETDEV_ALARM_PROTOCOL_E;

/**
* @brief 订阅告警事件类型BIT位定义 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVSubscribeAlarmType
{
    NETDEV_SUBSCRIBE_ALARM_TYPE_COM             = 0X01,     /* 通用告警 */
    NETDEV_SUBSCRIBE_ALARM_TYPE_SMART           = 0X02,     /* 智能告警 */
    NETDEV_SUBSCRIBE_ALARM_TYPE_INTELLIGENTIPC  = 0X04      /* 智能IPC */
}NETDEV_SUBSCRIBE_ALARM_TYPE_E;


/* 回放控制类型 */
typedef enum tagNETDEVCtrlType
{
    NETDEV_CTRL_TYPE_SPEED = 1,                                     /* 回放倍速 */ 
    NETDEV_CTRL_TYPE_INVALID
}NETDEV_XW_CTRL_TYPE_E;

/* 虚拟LED类型 */
typedef enum tagNETDEVLEDType
{
    NETDEV_LED_TYPE_STRING = 0                                   /* 字符型 */
}NETDEV_XW_LED_TYPE_E;

/* 虚拟LED字体 */
typedef enum tagNETDEVLEDFontFormat
{
    NETDEV_LED_FONT_SONG          = 0,                             /* 宋体 */
    NETDEV_LED_FONT_FORMAT_SIMHEI = 1,                             /* 黑体 */
    NETDEV_LED_FONT_FORMAT_KAITI  = 2,                             /* 楷体 */
    NETDEV_LED_FONT_FORMAT_Arial  = 3                              /* Arial */
}NETDEV_XW_LED_FONT_FORMAT_E;
/* 虚拟LED字体大小 */
typedef enum tagNETDEVXWLEDFontSize
{
    NETDEV_LED_FONT_SIZE_48X48      = 0,                            /* 48X48点阵 */
    NETDEV_LED_FONT_SIZE_64X64      = 1,                            /* 64X64点阵 */
    NETDEV_LED_FONT_SIZE_96X96      = 2,                            /* 96X96点阵 */
    NETDEV_LED_FONT_SIZE_128X128    = 3,                            /* 128X128点阵 */
    NETDEV_LED_FONT_SIZE_192X192    = 4,                            /* 192X192点阵 */
    NETDEV_LED_FONT_SIZE_256X256    = 5,                            /* 256X256点阵 */
    NETDEV_LED_FONT_SIZE_512X512    = 6,                            /* 512X512点阵 */
    NETDEV_FONT_SIZE_SELF_ADAPTION  = 7                             /* 自适应 */
}NETDEV_XW_LED_FONT_SIZE_E;

/* 虚拟LED字间距 一个中文占2字符*/
typedef enum tagNETDEVXWLEDFontGap
{
    NETDEV_LED_FONT_GAP_NORMAL         = 0,         /* 正常间距 */
    NETDEV_LED_FONT_GAP_ONE            = 1,         /* 间隔2/4高 */
    NETDEV_LED_FONT_GAP_TWO            = 2,         /* 间隔4/4高 */
    NETDEV_LED_FONT_GAP_THREE          = 3,         /* 间隔6/4高 */
    NETDEV_LED_FONT_GAP_FOUR           = 4,         /* 间隔8/4高 */
    NETDEV_LED_FONT_GAP_FIVE           = 5,         /* 间隔1/4高 */
    NETDEV_LED_FONT_GAP_SIX            = 6,         /* 间隔3/4高 */
    NETDEV_LED_FONT_GAP_SEVEN          = 7,         /* 间隔5/4高 */
    NETDEV_LED_FONT_GAP_EIGHT          = 8,         /* 间隔7/4高 */
    NETDEV_LED_FONT_GAP_NINE           = 9,         /* 间隔10/4高 */
    NETDEV_LED_FONT_GAP_INVALID        = 0xFF       /* 无效值(自适应)  Invalid value */
}NETDEV_XW_LED_FONT_GAP_E;

/* 文字滚动方式 */
typedef enum tagNETDEVLEDScrollingMode
{
    NETDEV_LED_SCROLL_STATIC            = 0,        /* 静止 */
    NETDEV_LED_SCROLL_RIGHT_TO_LEFT     = 1,        /* 从右到左 */
    NETDEV_LED_SCROLL_LEFT_TO_RIGHT     = 2,        /* 从左到右 */
    NETDEV_LED_SCROLL_BOTTOM_TO_TOP     = 3,        /* 从下到上 */
    NETDEV_LED_SCROLL_TOP_TO_BOTTOM     = 4         /* 从上到下 */
}NETDEV_XW_LED_SCROLLING_MODE_E;

/* 文字垂直对齐方式 */
typedef enum tagNETDEVVerticalAlignMode
{
    NETDEV_VERTICAL_ALIGN_TOP           = 0,        /* 上对齐 */
    NETDEV_VERTICAL_ALIGN_MIDDLE        = 1,        /* 居中对齐 */
    NETDEV_VERTICAL_ALIGN_BOTTOM        = 2         /* 下对齐*/
}NETDEV_XW_VERTICAL_ALIGN_MODE_E;

/* 文字水平对齐方式 */
typedef enum tagNETDEVHorizontalAlignMode
{
    NETDEV_HORIZONTAL_ALIGN_LEFT        = 0,        /* 左对齐 */
    NETDEV_HORIZONTAL_ALIGN_MIDDLE      = 1,        /* 居中对齐 */
    NETDEV_HORIZONTAL_ALIGN_RIGHT       = 2         /* 右对齐*/
}NETDEV_XW_HORIZONTAL_ALIGN_MODE_E;

/* 虚拟LED修改可选命令字 */
typedef enum tagNETDEVLedCmd
{
    NETDEV_LED_ENABLE               = 0x0001,                   /* 分屏模式 udwEnable */
    NETDEV_LED_TYPE                 = 0x0002,                   /* 虚拟LED类型 dwType */
    NETDEV_LED_AREA                 = 0x0004,                   /* 虚拟LED的位置信息 stArea */
    NETDEV_LED_BACKGROUND           = 0x0008,                   /* 底色 stBackground */
    NETDEV_LED_FONTINFO             = 0x0010,                   /* 文字信息描述 stFontInfo */
    NETDEV_LED_TEXT                 = 0x0020,                   /* 文字内容 udwTestLineNum szText*/
    NETDEV_LED_ALL                  = 0x00FF                    /* 全部 all*/
} NETDEV_XW_LED_CMD_E;

/* 底图类型 */
typedef enum tagNETDEVBaseType
{
    NETDEV_BASE_TYPE_JPEG = 1                                    /* JPEG类型 */
}NETDEV_XW_BASE_TYPE_E;

/* 传输协议 */
typedef enum tagNETDEVTransportProtocol
{
    NETDEV_TRANSPORT_PROTOCOL_UDP = 0,             /* UDP */
    NETDEV_TRANSPORT_PROTOCOL_TCP,                 /* TCP */
    NETDEV_TRANSPORT_PROTOCOL_RTSP,                /* RTSP */
    NETDEV_TRANSPORT_PROTOCOL_HTTP                 /* HTTP */
}NETDEV_TRANSPORT_PROTOCOL_E;

/**
* @brief 轮巡状态 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVXWSequenceResStatus
{
    NETDEV_XW_SEQUENCE_RES_STATUS_RUNNING   = 0,            /* 运行 */
    NETDEV_XW_SEQUENCE_RES_STATUS_PAUSE     = 1,            /* 暂停 */
    NETDEV_XW_SEQUENCE_RES_STATUS_STOP      = 2,            /* 停止 */

    NETDEV_XW_SEQUENCE_RES_STATUS_INVALID = 0xFF           /* 无效值 */
}NETDEV_XW_SEQUENCE_RES_STATUS_E;

/**
 * @brief 图片类型枚举
 * @attention 无 None
 */
typedef enum  tagNETDEVTMSPersionImageType
{
    NETDEV_TMS_PERSION_IMAGE_TYPE_FULL_VIEW = 1,         /* 全景图 */
    NETDEV_TMS_PERSION_IMAGE_TYPE_FACE = 2,              /* 人脸图 */
    NETDEV_TMS_PERSION_IMAGE_TYPE_INVALID
}NETDEV_TMS_PERSION_IMAGE_TYPE_E;

/**
 * @brief 图片格式枚举
 * @attention 无 None
 */
typedef enum  tagNETDEVTMSPersionImageFormatType
{
    NETDEV_TMS_PERSION_IMAGE_FORMAT_JPG  = 1,            /* JPEG */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_BMP  = 2,            /* BMP */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_PNG  = 3,            /* PNG */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_GIF  = 4,            /* GIF */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_TIFF = 5,            /* TIFF */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_INVALID
}NETDEV_TMS_PERSION_IMAGE_FORMAT_E;

/**
 * @brief 控制方式类型
 * @attention
 */
typedef enum tagNETDEVXWScreenCtrlType
{
    NETDEV_XW_SCREEN_CTRL_TYPE_TCP              = 0,          /* TCP */
    NETDEV_XW_SCREEN_CTRL_TYPE_UDP              = 1,          /* UDP */
    NETDEV_XW_SCREEN_CTRL_TYPE_COM              = 2,          /* 串口 */

    NETDEV_XW_SCREEN_CTRL_TYPE_INVALID          = 0xFF        /* 无效值 */
}NETDEV_XW_SCREEN_CTRL_TYPE_E;

/**
 * @brief 控制协议类型
 * @attention
 */
typedef enum tagNETDEVXWScreenCtrlProtocolType
{
    NETDEV_XW_SCREEN_CTRL_PROT_LCD          = 0,          /* LCD屏私有协议 */
    NETDEV_XW_SCREEN_CTRL_PROT_LED          = 1,          /* LED屏私有协议 */
    NETDEV_XW_SCREEN_CTRL_PROT_MODBUS       = 2,          /* MODBUS */

    NETDEV_XW_SCREEN_CTRL_PROT_INVALID      = 0xFF        /* 无效值 */
}NETDEV_XW_SCREEN_CTRL_PROTOCOL_TYPE_E;

/**
 * @brief 屏幕放大类型
 * @attention
 */
typedef enum tagNETDEVXWScreenZoomdType
{
    NETDEV_XW_SCREEN_ZOOM_TYPE_PANE           = 0,           /*分屏放大*/
    NETDEV_XW_SCREEN_ZOOM_TYPE_WIN            = 1,           /*窗口放大*/

    NETDEV_XW_SCREEN_ZOOM_TYPE_INVALID        = 0xFF         /* 无效值 */
}NETDEV_XW_SCREEN_ZOOM_TYPE_E;

/**
 * @brief 屏幕放大模式
 * @attention
 */
typedef enum tagNETDEVXWScreenZoomdMode
{
    NETDEV_XW_SCREEN_ZOOM_MODE_OFF             = 0,          /*恢复*/
    NETDEV_XW_SCREEN_ZOOM_MODE_ON              = 1,          /*放大*/

    NETDEV_XW_SCREEN_ZOOM_MODE_INVALID         = 0xFF        /* 无效值 */
}NETDEV_XW_SCREEN_ZOOM_MODE_E;

/* 分屏能力 */
typedef enum tagNETDEVPaneCap
{
    NETDEV_PANE_UNSUPPORT   = 0,        /* 不支持 */
    NETDEV_PANE_SAME_WND    = 1,        /* 支持单监视器相同大小&位置的窗口分屏 */
    NETDEV_PANE_ANY_WND     = 2,        /* 支持任意窗口的分屏 */

    NETDEV_PANE_INVALID     = 0xFF      /* 无效值 */
}NETDEV_XW_PANE_CAP_E;

/* 窗口漫游能力 */
typedef enum tagNETDEVRoamingCap
{
    NETDEV_ROAMING_UNSUPPORT    = 0,        /* 不支持 */
    NETDEV_ROAMING_SINGLE_WND   = 1,        /* 支持单分屏窗口漫游 */
    NETDEV_ROAMING_PANE_WND     = 2,        /* 支持多分屏窗口漫游 */

    NETDEV_ROAMING_INVALID      = 0xFF      /* 无效值 */
}NETDEV_XW_ROAMING_CAP_E;

/* 开窗能力 */
typedef enum tagNETDEVWndCap
{
    NETDEV_WINDOWS_UNSUPPORT    = 0,        /* 不支持 */
    NETDEV_WINDOWS_SINGLE_WND   = 1,        /* 支持单监视器相同大小&位置的窗口 */
    NETDEV_WINDOWS_MULTI_WND    = 2,        /* 支持跨多个监视器，满窗口开窗 */
    NETDEV_WINDOWS_ANY_WND      = 3,        /* 任意开窗 */
    NETDEV_WINDOWS_INVALID      =0xff       /* 无效值 */
}NETDEV_XW_WND_CAP_E;

typedef enum tagNETDEVXWSceneModifyType
{
    NETDEV_XW_SCENE_MODIFY_TYPE_NAME        = 0,            /* 修改场景名 modify scene name */
    NETDEV_XW_SCENE_MODIFY_TYPE_SAVE_AS     = 1,            /* 将一个场景的信息保存到另一个场景,场景的数据为当前场景的数据 scene Saved as */

    NETDEV_XW_SCENE_MODIFY_TYPE_INVALID     = 0xff          /* 无效值 */
}NETDEV_XW_SCENE_MODIFY_TYPE_E;

/* 星期几 */
typedef enum tagNETDEVWeekInfo
{
    NETDEV_LAPI_WEEK_MONDAY                  = 1,                  /* 星期一  Monday */
    NETDEV_LAPI_WEEK_TUESDAY                 = 2,                  /* 星期二  Tuesday */
    NETDEV_LAPI_WEEK_WEDNESDAY               = 3,                  /* 星期三  Wednesday */
    NETDEV_LAPI_WEEK_THURSDAY                = 4,                  /* 星期四  Thursday */
    NETDEV_LAPI_WEEK_FRIDAY                  = 5,                  /* 星期五  Friday */
    NETDEV_LAPI_WEEK_SATURDAY                = 6,                  /* 星期六  Saturday */
    NETDEV_LAPI_WEEK_SUNDAY                  = 7,                  /* 星期日  Sunday */
    NETDEV_LAPI_WEEK_HOLIDAY                 = 8,                  /* 假日 Holiday */
    NETDEV_LAPI_WEEK_INVALID                 = 0xff                  /* 无效值 */
}NETDEV_LAPI_WEEK_INFO_E;

/* 场景窗口修改可选命令字 */
typedef enum tagNETDEVWndCommond
{
    NETDEV_WND_PANE_MOD         = 0x0001,       /* 分屏模式 udwPaneMod */
    NETDEV_WND_LAYER            = 0x0002,       /* 图层 udwLayer */
    NETDEV_WND_TRANSPARENCY     = 0x0004,       /* 透明度 udwTransparency */
    NETDEV_WND_AREA             = 0x0008,       /* 位置信息 stArea */
    NETDEV_WND_NAME             = 0x0010,       /* 窗口名称 name */
    NETDEV_WND_STATUS           = 0x0020,       /* 是否锁定 */
    NETDEV_WND_WND_TYPE         = 0x0040,       /* 窗口类型 */
    NETDEV_WND_DC_CHI_ID        = 0x0080,       /* DC通道ID */
    NETDEV_WND_ZOOM_TYPE        = 0x0100,       /* 放大类型 */
    NETDEV_WND_SPLIT_INDEX      = 0x0200,       /* 分屏序号 */
    NETDEV_WND_SCHEME_RES_ID    = 0x0400,       /* 轮巡资源 */
    NETDEV_WND_SEQ_STATUS       = 0x0800,       /* 轮巡状态参见 */
    NETDEV_WND_PANE_INFO_NUM    = 0x1000,       /* 分屏数量 */

    NETDEV_WND_ALL              = 0xFFFF        /* 全部配置 all */
} NETDEV_XW_WND_CMD_E;

/* 窗口放大类型 */
typedef enum tagNETDEVZoomType
{
    NETDEV_XW_ZOOM_TYPE_NO          = 0x00,     /* 没放大 NO enlarge */
    NETDEV_XW_ZOOM_TYPE_SPLIT       = 0x01,     /* 分屏放大 split enlarge */
    NETDEV_XW_ZOOM_TYPE_WND         = 0x02,     /* 窗口放大 window enlarge */
    NETDEV_XW_ZOOM_TYPE_INVALID     = 0xFF      /* 无效值 invalid vule */
}NETDEV_XW_ZOOM_TYPE_E;


/* 编码格式 */
typedef enum tagNETDEVVideoEncoding
{
    NETDEV_VIDEOENCODING_H264 = 0,
    NETDEV_VIDEOENCODING_H265 = 1,
    NETDEV_VIDEOENCODING_MPEG4 = 2,
    NETDEV_VIDEOENCODING_MPEG2 = 3,
    NETDEV_VIDEOENCODING_MJPEG = 4
}NETDEV_XW_VIDEOENCODING_E;

/*加密类型*/
typedef enum tagNetDevAuthModel
{
    NETDEV_AUTH_MODEL_RSA_10       = 0,    /* RSA加密 E公钥是10进制*/
    NETDEV_AUTH_MODEL_PRI          = 1,    /* 通用字符串加密 */
    NETDEV_AUTH_MODEL_RSA_16       = 2     /* RSA加密，E公钥是16进制 */
}NETDEV_AUTH_MODEL_E;

/**
* @brief 传输协议 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVTransProtocol
{
    NETDEV_TRANS_PROTOCOL_TCP = 0,              /* TCP */
    NETDEV_TRANS_PROTOCOL_UDP = 1             /* UDP */
}NETDEV_TRANS_PROTOCOL_E;

/**
 * @brief 解码 类型
 * @attention
 */
typedef enum tagNETDEVDecodeType
{
    NETDEV_DECODE_TYPE_CLIENT = 0,      /* 解码器端作为客户端 主动解码 */
    NETDEV_DECODE_TYPE_SERVER = 1       /* 解码器端作为服务端 被动解码 */
    
}NETDEV_XW_DECODE_TYPE_E;

/* 实况业务类型 */
typedef enum tagNETDEVRealPlayType
{
    NETDEV_TYPE_NORMAL  = 0,        /* 默认普通实况 */
    NETDEV_TYPE_ALARM   = 1,        /* 告警联动实况 */
    NETDEV_TYPE_LOCAL   = 2         /* 本地实况 */
}NETDEV_XW_REALPLAY_TYPE_E;

 /**
 * @brief 音频通道端口枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVAudioPortType
{
    NETDEV_AUDIO_PORT_SINGLE            = 0,                /* 单声道 */
    NETDEV_AUDIO_PORT_DOUBLE            = 1,                /* 双声道 */
    NETDEV_AUDIO_PORT_INVALID           = 0xff               /* 无效值 */
}NETDEV_AUDIO_PORT_TYPE_E;

/**
 * @brief 视频端口枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVVideoPortType
{
    NETDEV_VIDEO_PORT_BNC            = 0,                /* 端口类型 BNC */
    NETDEV_VIDEO_PORT_VGA            = 1,                /* 端口类型 VGA */
    NETDEV_VIDEO_PORT_HDMI           = 2,                /* 端口类型 HDMI */
    NETDEV_VIDEO_PORT_DVI_D          = 3,                /* 端口类型 DVI_D */
    NETDEV_VIDEO_PORT_DVI_I          = 4,                /* 端口类型 DVI_D */
    NETDEV_VIDEO_PORT_DP             = 5,                /* 端口类型 DVI_D */
    NETDEV_VIDEO_PORT_SDI            = 6,                /* 端口类型 DVI_D */
    NETDEV_VIDEO_PORT_INVALID        = 0xff               /* 无效值 */
}NETDEV_VIDEO_PORT_TYPE_E;

/**
* @brief XW支持分屏数 
* @attention XW枚举 None
*/
typedef enum tagNETDEVXWLayoutNum
{
    NETDEV_XW_LAYOUT_TYPE_01             = 100,                /* 1分屏 */
    NETDEV_XW_LAYOUT_TYPE_02             = 200,                /* 2分屏 */
    NETDEV_XW_LAYOUT_TYPE_03             = 300,                /* 3分屏 */
    NETDEV_XW_LAYOUT_TYPE_04             = 400,                /* 4分屏 */
    NETDEV_XW_LAYOUT_TYPE_04_1           = 401,                /* 4分屏1+1+2 */
    NETDEV_XW_LAYOUT_TYPE_05             = 500,                /* 5分屏1+3+1 */
    NETDEV_XW_LAYOUT_TYPE_05_1           = 501,                /* 5分屏1+1+3 */
    NETDEV_XW_LAYOUT_TYPE_05_2           = 502,                /* 5分屏1+3+1 顺序不同于500 */
    NETDEV_XW_LAYOUT_TYPE_05_3           = 503,                /* 5分屏1+1+3 顺序不同于501 */
    NETDEV_XW_LAYOUT_TYPE_05_4           = 504,                /* 5分屏3+1+1*/
    NETDEV_XW_LAYOUT_TYPE_06             = 600,                /* 6分屏1+5 */
    NETDEV_XW_LAYOUT_TYPE_07             = 700,                /* 7分屏1+6 */
    NETDEV_XW_LAYOUT_TYPE_07_1           = 701,                /* 7分屏3+1+3 */
    NETDEV_XW_LAYOUT_TYPE_08             = 800,                /* 8分屏1+7 */
    NETDEV_XW_LAYOUT_TYPE_09             = 900,                /* 9分屏 */
    NETDEV_XW_LAYOUT_TYPE_10             = 1000,               /* 10分屏1+9 */
    NETDEV_XW_LAYOUT_TYPE_10_1           = 1001,               /* 10分屏2+8 */
    NETDEV_XW_LAYOUT_TYPE_13             = 1300,               /* 13分屏1+12 */
    NETDEV_XW_LAYOUT_TYPE_13_1           = 1301,               /* 13分屏1+12 顺序不同1300 */
    NETDEV_XW_LAYOUT_TYPE_16             = 1600,               /* 16分屏 */

    NETDEV_XW_LAYOUT_TYPE_INVALID  = 0xffff
}NETDEV_XW_LAYOUT_NUM_E;

/**
* @brief 分辨率 屏幕输出制式
* @attention DC&&XW公用枚举
*/
typedef enum tagNETDEVVideoFormat
{
    NETDEV_VIDEO_FORMAT_720P24          = 2,            /* 1280x720@24 */
    NETDEV_VIDEO_FORMAT_720P25          = 3,            /* 1280x720@25 */
    NETDEV_VIDEO_FORMAT_720P30          = 4,            /* 1280x720@30 */
    NETDEV_VIDEO_FORMAT_720P50          = 5,            /* 1280x720@50 */
    NETDEV_VIDEO_FORMAT_720P60          = 6,            /* 1280x720@60 */
    NETDEV_VIDEO_FORMAT_1080P24         = 10,           /* 1920x1080@24 */
    NETDEV_VIDEO_FORMAT_1080P25         = 11,           /* 1920x1080@25 */
    NETDEV_VIDEO_FORMAT_1080P30         = 12,           /* 1920x1080@30 */
    NETDEV_VIDEO_FORMAT_1080P50         = 13,           /* 1920x1080@50 */
    NETDEV_VIDEO_FORMAT_1080P60         = 14,           /* 1920x1080@60 */
    NETDEV_VIDEO_FORMAT_XGA60           = 15,           /* 1024x768@60 */
    NETDEV_VIDEO_FORMAT_SXGA60          = 16,           /* 1280x1024@60 */
    NETDEV_VIDEO_FORMAT_UXGA60          = 17,           /* 1600x1200@60 */
    NETDEV_VIDEO_FORMAT_SXGAP60HZ       = 18,           
    NETDEV_VIDEO_FORMAT_WXGAP60HZ       = 19,           /* 1366x768@60 */
    NETDEV_VIDEO_FORMAT_WSXGA60HZ       = 20,           /* 1440x900@60 */
    NETDEV_VIDEO_FORMAT_4K30            = 21,           /* 3840x2160@30 */
    NETDEV_VIDEO_FORMAT_4K60            = 22,           /* 3840x2160@60 */
    NETDEV_VIDEO_FORMAT_MUXGA60HZ       = 23,           /* 1920x1200@60 */
    NETDEV_VIDEO_FORMAT_INVALID         = 0xFF
}NETDEV_VIDEO_FORMAT_E;

/**
* @brief 流类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVStreamType
{
    NETDEV_STREAM_TYPE_RTP_UNICAST = 0,         /* 单播 */
    NETDEV_STREAM_TYPE_RTP_MULTICAST = 1,        /* 组播 */

    NETDEV_STREAM_TYPE_RTP_INVALID         = 0xFF
}NETDEV_STREAM_TYPE_E;

typedef enum tagNETDEVAlarmSnapShotType
{
    NETDEV_ALARM_SNAPSHOT_MOTION_DETECT                     = 0,            /* 移动告警 */
    NETDEV_ALARM_SNAPSHOT_VIDEO_LOST                        = 1,            /* 视频丢失告警 */
    NETDEV_ALARM_SNAPSHOT_AUDIO_DETECTION                   = 2,            /* 声音检测告警 */
    NETDEV_ALARM_SNAPSHOT_INPUT_SWITCH                      = 3,            /* 开关量输入告警 */
    NETDEV_ALARM_SNAPSHOT_IPC_OFFLINE                       = 4,            /* IPC离线 */
    NETDEV_ALARM_SNAPSHOT_TAMPER_DETECT                     = 5,            /* 遮挡检测 */

    NETDEV_ALARM_SNAPSHOT_INVALID                        = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_ALARM_SNAPSHOT_TYPE_E;

/**
* @brief 警前预录时间枚举定义          PreRecordTime Enumeration definition
* @attention 
*/
typedef enum tagNETDEVPreRecordTime
{
    NETDEV_PRE_RECORD_TIME_ZERO =  0,            /* 0秒 */
    NETDEV_PRE_RECORD_TIME_FIVE =  5,            /* 5秒 */
    NETDEV_PRE_RECORD_TIME_TEN =   10,           /* 10秒 */
    NETDEV_PRE_RECORD_TIME_TWENTY =20,           /* 20秒 */
    NETDEV_PRE_RECORD_TIME_THIRTY =30,           /* 30秒 */
    NETDEV_PRE_RECORD_TIME_SIXTY = 60            /* 60秒 */
}NETDEV_PRE_RECORD_TIME_E;

/**
* @brief 警后预录时间枚举定义          PostRecordTime Enumeration definition
* @attention 
*/
typedef enum tagNETDEVPostRecordTime
{
    NETDEV_POST_RECORD_TIME_FIVE =                   5,             /* 5秒 */
    NETDEV_POST_RECORD_TIME_TEN =                    10,            /* 10 秒*/
    NETDEV_POST_RECORD_TIME_THIRTY =                 30,            /* 30 秒*/
    NETDEV_POST_RECORD_TIME_SIXTY =                  60,            /* 60 秒*/
    NETDEV_POST_RECORD_TIME_ONE_HUNDRED_AND_TWENTY = 120,           /* 120 秒*/
    NETDEV_POST_RECORD_TIME_THREE_HUNDRED =          300,           /* 300秒 */
    NETDEV_POST_RECORD_TIME_SIX_HUNDRED =            600            /* 600秒 */
}NETDEV_POST_RECORD_TIME_E;

/**
* @brief 布防计划使能 枚举定义          Defence Plan Enable Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVDefencePlanEnable
{
    NETDEV_DEFENCE_PLAN_DISABLE     = 0,        /* 不使能 */
    NETDEV_DEFENCE_PLAN_ENABLE      =  1        /* 使能 */
}NETDEV_DEFENCE_PLAN_ENABLE_E;

/**
* @brief 告警布防类型枚举定义          Alarm And Defence Type Enumeration definition
* @attention 各类告警布防只支持定时类型，录像/抓图计划全支持，IPC只支持定时，不需要带字段，默认是定时
*/
typedef enum tagNETDEVArmingType
{
    NETDEV_ARMING_TYPE_TIMING                   = 0,        /* 定时 */
    NETDEV_ARMING_TYPE_MOTIONDETEC              = 1,        /* 动检 */
    NETDEV_ARMING_TYPE_ALARM                    = 2,        /* 报警 */
    NETDEV_ARMING_TYPE_MOTIONDETEC_AND_ALARM    = 3,        /* 动检和报警 */
    NETDEV_ARMING_TYPE_MOTIONDETEC_OR_ALARM     = 4,        /* 动检或报警 */
    NETDEV_ARMING_TYPE_NO_PLAN                  = 5,        /* 无计划 */
    NETDEV_ARMING_TYPE_EVENT                    = 10        /* 事件 */
}NETDEV_ARMING_TYPE_E;



/**
*@brief 拉流类型枚举
*@attention 无
*/
typedef enum tagNETDEVStreamProtocol
{
    NETDEV_STREAM_PRO_RTMP         = 1,          /* RTP */
    NETDEV_STREAM_PRO_HLS          = 2,          /* HLS */
    NETDEV_STREAM_PRO_FLV          = 3           /* FLV */
}NETDEV_CLOUD_STREAM_PROTOCAL_E;

/**
*@brief 分发模式类型枚举
*@attention 无
*/
typedef enum tagNETDEVDistributeCloud
{
    NETDEV_DISTRIBUTE_CLOUD_NONE      = 0,            /* 不启用分发 */
    NETDEV_DISTRIBUTE_CLOUD_KS        = 1,            /* 启用金山云分发 */
    NETDEV_DISTRIBUTE_CLOUD_UN        = 2,            /* 启用宇视云分发 */
    NETDEV_DISTRIBUTE_CLOUD_TEN       = 3            /* 启用腾讯云分发 */
}NETDEV_DISTRIBUTE_CLOUD_SRV_E;

/**
*@brief 网络模式类型枚举
*@attention 无
*/
typedef enum tagNETDevNetWorkMode
{
    NETDEV_NETMODE_LAN          = 0,        /* LAN 模式,仅用于本地及端口映射 */
    NETDEV_NETMODE_WAN          = 1,        /* WAN 模式,仅用于单层NAT */
    NETDEV_NETMODE_MULTINAT     = 2,        /* 多层NAT模式,用于打洞穿网 （转发和打洞未区分）*/
    NETDEV_NETMODE_P2P          = 3,        /* 多层NAT模式,用于打洞穿网 */
    NETDEV_NETMODE_TURN         = 4         /* 多层NAT模式,用于转发 */

}NETDEV_NETWORK_MODE_E;


/**
 * @enum tagNETDEVReportType
 * @brief 告警/事件上报类型
 * @attention 无 None
 */
typedef enum tagNETDEVReportType
{
    NETDEV_REPORT_TYPE_ALARM            = 0,                /* 上报类型：告警 */
    NETDEV_REPORT_TYPE_EVENT            = 1,                /* 上报类型：事件 */

    NETDEV_REPORT_TYPE_INVALID          = 0xFF              /* 无效值 */
}NETDEV_REPORT_TYPE_E;


/**
* @enum tagNETDEVAlarmSubType
* @brief 告警子类型
* @attention 无
*/
typedef enum tagNETDEVAlarmSubType
{
    NETDEV_ALARM_SUB_TYPE_NOT_CONFIGURED       = 0,                                         /*未配置报警子类型*/

    NETDEV_DEV_TYPE_BASE                       = (100000UL),                                /* 安防报警基数 */
    NETDEV_DEV_TROUBLE                         = (NETDEV_DEV_TYPE_BASE + 1),                /* 设备故障 */
    NETDEV_DEV_ALARM_EMERGENCY                 = (NETDEV_DEV_TYPE_BASE + 2),                /* 紧急报警 */

    /* 报警设备报警类型定义 */
    NETDEV_ALARM_EVENT_BASE                    = (100200UL),                                /* 报警类型定义起始位置 */
    NETDEV_ALARM_EVENT_FIRE_ALARM              = (NETDEV_ALARM_EVENT_BASE + 1),             /* 火警 */
    NETDEV_ALARM_EVENT_KEYPADFIRE              = (NETDEV_ALARM_EVENT_BASE + 2),             /* 键盘火警报警 */
    NETDEV_ALARM_EVENT_KEYPADEMERGENCY         = (NETDEV_ALARM_EVENT_BASE + 3),             /* 键盘紧急报警 */
    NETDEV_ALARM_EVENT_KEYPADMEDICAL           = (NETDEV_ALARM_EVENT_BASE + 4),             /* 键盘求助报警 */
    NETDEV_ALARM_EVENT_DURESSCODEUSED          = (NETDEV_ALARM_EVENT_BASE + 5),             /* 胁持码操作 */
    NETDEV_ALARM_EVENT_UNAUTHORIZEDENTRY       = (NETDEV_ALARM_EVENT_BASE + 6),             /* 未授权进入 */
    NETDEV_ALARM_EVENT_BURGLARPOINTALARM       = (NETDEV_ALARM_EVENT_BASE + 7),             /* 盗警防区报警 */
    NETDEV_ALARM_EVENT_SUPERVISORY             = (NETDEV_ALARM_EVENT_BASE + 8),             /* 监测故障 */
    NETDEV_ALARM_EVENT_FIRETROUBLE             = (NETDEV_ALARM_EVENT_BASE + 9),             /* 火警故障 */
    NETDEV_ALARM_EVENT_FIREPOINTTROUBLE        = (NETDEV_ALARM_EVENT_BASE + 10),            /* 火警防区故障 */
    NETDEV_ALARM_EVENT_BURGLARPOINTTROUBLE     = (NETDEV_ALARM_EVENT_BASE + 11),            /* 盗警防区故障 */
    NETDEV_ALARM_EVENT_CANCELALARM             = (NETDEV_ALARM_EVENT_BASE + 12),            /* 消警 */
    NETDEV_ALARM_EVENT_DISARM                  = (NETDEV_ALARM_EVENT_BASE + 13),            /* 撤防操作成功 */
    NETDEV_ALARM_EVENT_ARM                     = (NETDEV_ALARM_EVENT_BASE + 14),            /* 布防操作成功 */
    NETDEV_ALARM_EVENT_FORCEDBYPASS            = (NETDEV_ALARM_EVENT_BASE + 15),            /* 强制旁路操作 */
    NETDEV_ALARM_EVENT_BYPASS                  = (NETDEV_ALARM_EVENT_BASE + 16),            /* 防区旁路操作 */
    NETDEV_ALARM_EVENT_POINTRESTORAL           = (NETDEV_ALARM_EVENT_BASE + 17),            /* 防区报警恢复 */
    NETDEV_ALARM_EVENT_FAILTOCLOSE             = (NETDEV_ALARM_EVENT_BASE + 18),            /* 布防操作失败 */
    NETDEV_ALARM_EVENT_FAILTOOPEN              = (NETDEV_ALARM_EVENT_BASE + 19),            /* 撤防操作失败 */
    NETDEV_ALARM_EVENT_HISTORYBUFFERDUMP       = (NETDEV_ALARM_EVENT_BASE + 20),            /* 事件记录满 */
    NETDEV_ALARM_EVENT_TESTMSG                 = (NETDEV_ALARM_EVENT_BASE + 21),            /* 测试用 */
    NETDEV_ALARM_EVENT_ZONETROUBLE             = (NETDEV_ALARM_EVENT_BASE + 22),            /* 防区故障 */
    NETDEV_ALARM_EVENT_ZONETROUBLERESTORE      = (NETDEV_ALARM_EVENT_BASE + 23),            /* 防区故障恢复 */
    NETDEV_ALARM_EVENT_ZONESHORT               = (NETDEV_ALARM_EVENT_BASE + 24),            /* 防区短路 */
    NETDEV_ALARM_EVENT_ZONEOPEN                = (NETDEV_ALARM_EVENT_BASE + 25),            /* 防区开路 */
    NETDEV_ALARM_EVENT_ZONENORMAL              = (NETDEV_ALARM_EVENT_BASE + 26),            /* 防区正常 */
    NETDEV_ALARM_EVENT_MXDEVCLOSE              = (NETDEV_ALARM_EVENT_BASE + 27),            /* MX设备布防 */
    NETDEV_ALARM_EVENT_MXDEVOPEN               = (NETDEV_ALARM_EVENT_BASE + 28),            /* MX设备撤防 */
    NETDEV_ALARM_EVENT_MXDEV1ZONEALARM         = (NETDEV_ALARM_EVENT_BASE + 29),            /* MX设备1防区报警 */
    NETDEV_ALARM_EVENT_MXDEV2ZONEALARM         = (NETDEV_ALARM_EVENT_BASE + 30),            /* MX设备2防区报警 */
    NETDEV_ALARM_EVENT_MXDEV3ZONEALARM         = (NETDEV_ALARM_EVENT_BASE + 31),            /* MX设备3防区报警 */
    NETDEV_ALARM_EVENT_MXDEV1ZONERESTAORE      = (NETDEV_ALARM_EVENT_BASE + 32),            /* MX设备1防区恢复 */
    NETDEV_ALARM_EVENT_MXDEV2ZONERESTAORE      = (NETDEV_ALARM_EVENT_BASE + 33),            /* MX设备2防区恢复 */
    NETDEV_ALARM_EVENT_MXDEV3ZONERESTAORE      = (NETDEV_ALARM_EVENT_BASE + 34),            /* MX设备3防区恢复 */
    NETDEV_ALARM_EVENT_TROUBLE_AC              = (NETDEV_ALARM_EVENT_BASE + 35),            /* 交流电源故障 */
    NETDEV_ALARM_EVENT_TROUBLE_BATTERY         = (NETDEV_ALARM_EVENT_BASE + 36),            /* 备用电源故障 */
    NETDEV_ALARM_EVENT_TROUBLE_SNDREPORT       = (NETDEV_ALARM_EVENT_BASE + 37),            /* 报告发送故障 */
    NETDEV_ALARM_EVENT_TROUBLE_CONTROL         = (NETDEV_ALARM_EVENT_BASE + 38),            /* 控制故障 */
    NETDEV_ALARM_EVENT_TROUBLE_MXBUS           = (NETDEV_ALARM_EVENT_BASE + 39),            /* MPX总线故障 */
    NETDEV_ALARM_EVENT_TROUBLE_RADIOSND        = (NETDEV_ALARM_EVENT_BASE + 40),            /* 无线接收故障 */
    NETDEV_ALARM_EVENT_TROUBLE_ASSISTPOWER     = (NETDEV_ALARM_EVENT_BASE + 41),            /* 辅助电源故障 */
    NETDEV_ALARM_EVENT_TROUBLE_OPTION          = (NETDEV_ALARM_EVENT_BASE + 42),            /* option设备故障 */
    NETDEV_ALARM_EVENT_LINK_BREAK              = (NETDEV_ALARM_EVENT_BASE + 43),            /* 联机断开 */
    NETDEV_ALARM_EVENT_LINK_RESUME             = (NETDEV_ALARM_EVENT_BASE + 44),            /* 联机正常 */
    NETDEV_ALARM_EVENT_VOLTAGE_ALARM           = (NETDEV_ALARM_EVENT_BASE + 45),            /* 直流欠压报警 */
    NETDEV_ALARM_EVENT_EXTERNDEV_TROUBLE       = (NETDEV_ALARM_EVENT_BASE + 46),            /* 扩展设备故障报警 */
    NETDEV_ALARM_EVENT_EXTERNDEV_RESUME        = (NETDEV_ALARM_EVENT_BASE + 47),            /* 扩展设备恢复报警 */
    NETDEV_ALARM_EVENT_POINT_DISARM            = (NETDEV_ALARM_EVENT_BASE + 48),            /* 点位撤防 */
    NETDEV_ALARM_EVENT_POINT_ARM               = (NETDEV_ALARM_EVENT_BASE + 49),            /* 点位布防 */
    NETDEV_ALARM_EVENT_FORCE_OPEN              = (NETDEV_ALARM_EVENT_BASE + 50),            /* 报警主机被强制打开 */
    NETDEV_ALARM_EVENT_BYPASS_FAILED           = (NETDEV_ALARM_EVENT_BASE + 51),            /* 旁路操作失败 */
    NETDEV_ALARM_EVENT_RESET_FAILED            = (NETDEV_ALARM_EVENT_BASE + 52),            /* 复位操作失败 */
    NETDEV_ALARM_EVENT_POINT_FIRETROUBLE       = (NETDEV_ALARM_EVENT_BASE + 53),            /* 点位故障 */
    NETDEV_ALARM_EVENT_POINT_SEPARATE          = (NETDEV_ALARM_EVENT_BASE + 54),            /* 点位隔离 */
    NETDEV_ALARM_EVENT_POINT_ACTION            = (NETDEV_ALARM_EVENT_BASE + 55),            /* 点位动作 */
    NETDEV_ALARM_EVENT_POINT_RESUME            = (NETDEV_ALARM_EVENT_BASE + 56),            /* 点位恢复 */
    NETDEV_ALARM_EVENT_ROB_ACTION              = (NETDEV_ALARM_EVENT_BASE + 57),            /* 劫警 */

    /* 报警事件新增 */
    NETDEV_ALARM_EVENT_MISSED_ARM              = (NETDEV_ALARM_EVENT_BASE + 60),            /* 没有布防 */
    NETDEV_ALARM_EVENT_MISSED_DISARM           = (NETDEV_ALARM_EVENT_BASE + 61),            /* 没有撤防 */
    NETDEV_ALARM_EVENT_AUXILARY_RST            = (NETDEV_ALARM_EVENT_BASE + 62),            /* 辅助报警恢复 */
    NETDEV_ALARM_EVENT_AUXILARY                = (NETDEV_ALARM_EVENT_BASE + 63),            /* 辅助报警 */
    NETDEV_ALARM_EVENT_BURGLARY_RST            = (NETDEV_ALARM_EVENT_BASE + 64),            /* 窃警恢复 */
    NETDEV_ALARM_EVENT_BURGLARY                = (NETDEV_ALARM_EVENT_BASE + 65),            /* 窃警 */
    NETDEV_ALARM_EVENT_BYPASS_RST              = (NETDEV_ALARM_EVENT_BASE + 66),            /* 旁路恢复 */
    NETDEV_ALARM_EVENT_CANCEL                  = (NETDEV_ALARM_EVENT_BASE + 67),            /* 取消 */
    NETDEV_ALARM_EVENT_DUPLICATE               = (NETDEV_ALARM_EVENT_BASE + 68),            /* 重复 */
    NETDEV_ALARM_EVENT_DURESS_RST              = (NETDEV_ALARM_EVENT_BASE + 69),            /* 挟持报警恢复 */
    NETDEV_ALARM_EVENT_DURESS                  = (NETDEV_ALARM_EVENT_BASE + 70),            /* 挟持报警 */
    NETDEV_ALARM_EVENT_FIRE_RST                = (NETDEV_ALARM_EVENT_BASE + 71),            /* 火警恢复 */
    NETDEV_ALARM_EVENT_FIRE_TROUBLE            = (NETDEV_ALARM_EVENT_BASE + 72),            /* 防火探头故障 */
    NETDEV_ALARM_EVENT_FIRE_TRB_RST            = (NETDEV_ALARM_EVENT_BASE + 73),            /* 防火探头故障恢复 */
    NETDEV_ALARM_EVENT_MED_RST                 = (NETDEV_ALARM_EVENT_BASE + 74),            /* 医疗救助复位 */
    NETDEV_ALARM_EVENT_PANIC                   = (NETDEV_ALARM_EVENT_BASE + 75),            /* 紧急报警 */
    NETDEV_ALARM_EVENT_PANIC_RST               = (NETDEV_ALARM_EVENT_BASE + 76),            /* 紧急报警恢复 */
    NETDEV_ALARM_EVENT_RESET                   = (NETDEV_ALARM_EVENT_BASE + 77),            /* 复位 */
    NETDEV_ALARM_EVENT_RELAY_SHORTED           = (NETDEV_ALARM_EVENT_BASE + 78),            /* 继电器短路 */
    NETDEV_ALARM_EVENT_RELAY_RST               = (NETDEV_ALARM_EVENT_BASE + 79),            /* 继电器恢复 */
    NETDEV_ALARM_EVENT_RELAY_TROUBLE           = (NETDEV_ALARM_EVENT_BASE + 80),            /* 继电器故障 */
    NETDEV_ALARM_EVENT_TAMPER                  = (NETDEV_ALARM_EVENT_BASE + 81),            /* 防拆报警 */
    NETDEV_ALARM_EVENT_TAMPER_RST              = (NETDEV_ALARM_EVENT_BASE + 82),            /* 防拆报警恢复 */
    NETDEV_ALARM_EVENT_TROUBLE                 = (NETDEV_ALARM_EVENT_BASE + 83),            /* 故障 */
    NETDEV_ALARM_EVENT_TROUBLE_RST             = (NETDEV_ALARM_EVENT_BASE + 84),            /* 故障恢复 */

    /* 乌审旗对接东方电子DF8900电力综合自动化系统新增 */
    NETDEV_ALARM_EVENT_DFE_REMOTE_CONTROL      = (NETDEV_ALARM_EVENT_BASE + 90),            /* 遥控 */
    NETDEV_ALARM_EVENT_DFE_SYNC                = (NETDEV_ALARM_EVENT_BASE + 91),            /* 同期 */
    NETDEV_ALARM_EVENT_DFE_LIFTING             = (NETDEV_ALARM_EVENT_BASE + 92),            /* 升降 */
    NETDEV_ALARM_EVENT_DFE_SWITCH_NORMAL       = (NETDEV_ALARM_EVENT_BASE + 93),            /* 开关正常变位 */
    NETDEV_ALARM_EVENT_DFE_SWITCH_ACCIDENT     = (NETDEV_ALARM_EVENT_BASE + 94),            /* 开关事故变位 */
    NETDEV_ALARM_EVENT_DFE_KINFE_GATE          = (NETDEV_ALARM_EVENT_BASE + 95),            /* 刀闸正常变位 */

    /* 垦华监狱晨鹰哨位集成箱报警 */
    NETDEV_ALARM_EVENT_ESCAPE                  = (NETDEV_ALARM_EVENT_BASE + 96),            /* 晨鹰哨位事件，犯人逃跑 */
    NETDEV_ALARM_EVENT_ESCAPE_END              = (NETDEV_ALARM_EVENT_BASE + 97),            /* 晨鹰哨位事件，犯人逃跑结束 */
    NETDEV_ALARM_EVENT_VIOLENCE                = (NETDEV_ALARM_EVENT_BASE + 98),            /* 晨鹰哨位事件，犯人暴狱 */
    NETDEV_ALARM_EVENT_VIOLENCE_END            = (NETDEV_ALARM_EVENT_BASE + 99),            /* 晨鹰哨位事件，犯人暴狱结束 */
    NETDEV_ALARM_EVENT_ATTACKED                = (NETDEV_ALARM_EVENT_BASE + 100),           /* 晨鹰哨位事件，目标遭袭 */
    NETDEV_ALARM_EVENT_ATTACKED_END            = (NETDEV_ALARM_EVENT_BASE + 101),           /* 晨鹰哨位事件，目标遭袭结束 */
    NETDEV_ALARM_EVENT_NATURAL_DISASTER        = (NETDEV_ALARM_EVENT_BASE + 102),           /* 晨鹰哨位事件，自然灾害 */
    NETDEV_ALARM_EVENT_NATURAL_DISASTER_END    = (NETDEV_ALARM_EVENT_BASE + 103),           /* 晨鹰哨位事件，自然灾害结束 */
    NETDEV_ALARM_EVENT_ONE_KEY_ALARM           = (NETDEV_ALARM_EVENT_BASE + 104),           /* 晨鹰哨位事件，一键报警 */
    NETDEV_ALARM_EVENT_ONE_KEY_ALARM_END       = (NETDEV_ALARM_EVENT_BASE + 105),           /* 晨鹰哨位事件，一键报警结束 */

    /* 潍北监狱中电瑞达高压电网报警 */
    NETDEV_ALARM_EVENT_CERC_NORMAL             = (NETDEV_ALARM_EVENT_BASE + 106),           /* 中电瑞达事件，高压电网正常 */
    NETDEV_ALARM_EVENT_CERC_TOUCH              = (NETDEV_ALARM_EVENT_BASE + 107),           /* 中电瑞达事件，高压电网触网 */
    NETDEV_ALARM_EVENT_CERC_BREAK              = (NETDEV_ALARM_EVENT_BASE + 108),           /* 中电瑞达事件，高压电网断路 */
    NETDEV_ALARM_EVENT_CERC_SHORT              = (NETDEV_ALARM_EVENT_BASE + 109),           /* 中电瑞达事件，高压电网短路 */
    NETDEV_ALARM_EVENT_CERC_COMMU_ERR          = (NETDEV_ALARM_EVENT_BASE + 110),           /* 中电瑞达事件，高压电网通信错误 */

    /* 潍北监狱艾博信相控阵雷达和红外光栅报警 */
    NETDEV_ALARM_EVENT_HYPERSEE_DDR_ALARM      = (NETDEV_ALARM_EVENT_BASE + 111),           /* 艾博信事件，相控阵雷达报警 */
    NETDEV_ALARM_EVENT_HYPERSEE_DDR_ALARM_RST  = (NETDEV_ALARM_EVENT_BASE + 112),           /* 艾博信事件，相控阵雷达报警恢复 */
    NETDEV_ALARM_EVENT_HYPERSEE_IR_ALARM       = (NETDEV_ALARM_EVENT_BASE + 113),           /* 艾博信事件，红外光栅报警 */
    NETDEV_ALARM_EVENT_HYPERSEE_IR_ALARM_RST   = (NETDEV_ALARM_EVENT_BASE + 114),           /* 艾博信事件，红外光栅报警恢复 */

    /* 潍北监狱中科融通陀螺仪报警 */
    NETDEV_ALARM_EVENT_UBI_ALARM               = (NETDEV_ALARM_EVENT_BASE + 115),           /* 中科融通事件，陀螺仪报警 */

    /* 新疆中泰园区中科华讯美国西南周界震动电缆报警 */
    NETDEV_ALARM_EVENT_HXTECH_CABLE_ALARM      = (NETDEV_ALARM_EVENT_BASE + 116),           /* 华讯周界事件，震动电缆报警 */

    /*精华隆数据*/
    NETDEV_ALARM_EVENT_DEVICE_UNDER_VOLTAGE_RST            = (NETDEV_ALARM_EVENT_BASE + 117),               /* 设备欠压恢复模式 */
    NETDEV_ALARM_EVENT_ZONE_NOT_READY                      = (NETDEV_ALARM_EVENT_BASE + 118),               /* 防区未准备 */
    NETDEV_ALARM_EVENT_ZONE_NOT_READY_RST                  = (NETDEV_ALARM_EVENT_BASE + 119),               /* 防区未准备恢复 */
    NETDEV_ALARM_EVENT_TELEPHONE_CABLE_FAULT               = (NETDEV_ALARM_EVENT_BASE + 120),               /* 电话线故障 */
    NETDEV_ALARM_EVENT_TELEPHONE_CABLE_FAULT_RST           = (NETDEV_ALARM_EVENT_BASE + 121),               /* 电话线故障恢复 */
    NETDEV_ALARM_EVENT_AC_POWER_FAULT                      = (NETDEV_ALARM_EVENT_BASE + 122),               /* 交流电故障 */

    /* 一体机对接艾立安告警 */
    NETDEV_ALARM_EVENT_ZONE_TOUCH                          = (NETDEV_ALARM_EVENT_BASE + 123),    /* 防区触发报警 */
    NETDEV_ALARM_EVENT_ZONE_TOUCH_RESTORE                  = (NETDEV_ALARM_EVENT_BASE + 124),    /* 防区触发恢复 */
    NETDEV_ALARM_EVENT_CAPTIVE                             = (NETDEV_ALARM_EVENT_BASE + 125),    /* 被撬 */
    NETDEV_ALARM_EVENT_CAPTIVE_RST                         = (NETDEV_ALARM_EVENT_BASE + 126),    /* 被撬恢复 */
    NETDEV_ALARM_EVENT_UNDERVOLTAGE                        = (NETDEV_ALARM_EVENT_BASE + 127),    /* 欠压 */
    NETDEV_ALARM_EVENT_UNDERVOLTAGE_RST                    = (NETDEV_ALARM_EVENT_BASE + 128),    /* 欠压恢复 */
    NETDEV_ALARM_EVENT_TROUBLE_BATTERY_RST                 = (NETDEV_ALARM_EVENT_BASE + 129),    /* 备用电池故障恢复 */
    NETDEV_ALARM_EVENT_DEV_POWER_REBOOT                    = (NETDEV_ALARM_EVENT_BASE + 130),    /* 设备上电重启 */
    NETDEV_ALARM_EVENT_TEST_FAILURE                        = (NETDEV_ALARM_EVENT_BASE + 131),    /* 设备测试失败 */
    NETDEV_ALARM_EVENT_OPERATOR_TOUCH_LONG                 = (NETDEV_ALARM_EVENT_BASE + 132),    /* 长按键操作  */
    NETDEV_ALARM_EVENT_REMOTE_ARM                          = (NETDEV_ALARM_EVENT_BASE + 133),    /* 遥控布防  */
    NETDEV_ALARM_EVENT_REMOTE_DISARM                       = (NETDEV_ALARM_EVENT_BASE + 134),    /* 遥控撤防  */
    NETDEV_ALARM_EVENT_REMOTE_STAY_ARM                     = (NETDEV_ALARM_EVENT_BASE + 135),    /* 遥控留守布防  */
    NETDEV_ALARM_EVENT_PWD_ARM                             = (NETDEV_ALARM_EVENT_BASE + 136),    /* 密码布防设备  */
    NETDEV_ALARM_EVENT_PWD_DISARM                          = (NETDEV_ALARM_EVENT_BASE + 137),    /* 密码撤防设备  */
    NETDEV_ALARM_EVENT_PWD_STAY_DEV                        = (NETDEV_ALARM_EVENT_BASE + 138),    /* 密码留守布防设备  */
    NETDEV_ALARM_EVENT_PWD_ARM_PART                        = (NETDEV_ALARM_EVENT_BASE + 139),    /* 密码布防分区  */
    NETDEV_ALARM_EVENT_PWD_DISARM_PART                     = (NETDEV_ALARM_EVENT_BASE + 140),    /* 密码撤防分区  */
    NETDEV_ALARM_EVENT_PWD_STAY_PART                       = (NETDEV_ALARM_EVENT_BASE + 141),    /* 密码留守布防分区  */
    NETDEV_ALARM_EVENT_PWD_ARM_ZONE                        = (NETDEV_ALARM_EVENT_BASE + 142),    /* 密码布防防区  */
    NETDEV_ALARM_EVENT_PWD_DISARM_ZONE                     = (NETDEV_ALARM_EVENT_BASE + 143),    /* 密码撤防防区  */
    NETDEV_ALARM_EVENT_USER_ARM                            = (NETDEV_ALARM_EVENT_BASE + 144),    /* 用户布防设备  */
    NETDEV_ALARM_EVENT_USER_DISARM                         = (NETDEV_ALARM_EVENT_BASE + 145),    /* 用户撤防设备  */
    NETDEV_ALARM_EVENT_USER_STAY_DEV                       = (NETDEV_ALARM_EVENT_BASE + 146),    /* 用户留守布防设备  */
    NETDEV_ALARM_EVENT_USER_CLEAN_ALARM                    = (NETDEV_ALARM_EVENT_BASE + 147),    /* 用户清除报警显示  */
    NETDEV_ALARM_EVENT_PWD_OPEN_DOOR                       = (NETDEV_ALARM_EVENT_BASE + 148),    /* 密码开门  */
    NETDEV_ALARM_EVENT_KEY_OPEN_DOOR                       = (NETDEV_ALARM_EVENT_BASE + 149),    /* 钥匙开门  */
    NETDEV_ALARM_EVENT_REMOTE_OPEN_DOOR                    = (NETDEV_ALARM_EVENT_BASE + 150),    /* 遥控开门  */
    NETDEV_ALARM_EVENT_SWIPE_ARM                           = (NETDEV_ALARM_EVENT_BASE + 151),    /* 刷卡布防  */
    NETDEV_ALARM_EVENT_SWIPE_DISARM                        = (NETDEV_ALARM_EVENT_BASE + 152),    /* 刷卡撤防  */
    NETDEV_ALARM_EVENT_SWIPE_LOCK                          = (NETDEV_ALARM_EVENT_BASE + 153),    /* 刷卡闭锁  */
    NETDEV_ALARM_EVENT_SWIPE_UNLOCK                        = (NETDEV_ALARM_EVENT_BASE + 154),    /* 刷卡开锁  */
    NETDEV_ALARM_EVENT_SWIPE_RECORD                        = (NETDEV_ALARM_EVENT_BASE + 155),    /* 刷卡记录  */
    NETDEV_ALARM_EVENT_SWIPE_ATTENDANCE_IN                 = (NETDEV_ALARM_EVENT_BASE + 156),    /* 刷卡考勤入  */
    NETDEV_ALARM_EVENT_SWIPE_ATTENDANCE_OUT                = (NETDEV_ALARM_EVENT_BASE + 157),    /* 刷卡考勤出  */
    NETDEV_ALARM_EVENT_SWIPE_TURNON_LIGHT                  = (NETDEV_ALARM_EVENT_BASE + 158),    /* 刷卡开灯  */
    NETDEV_ALARM_EVENT_SWIPE_OFF_LIGHT                     = (NETDEV_ALARM_EVENT_BASE + 159),    /* 刷卡关灯  */
    NETDEV_ALARM_EVENT_SWIPE_CARD_NUM                      = (NETDEV_ALARM_EVENT_BASE + 160),    /* 刷卡上报卡物理编号  */
    NETDEV_ALARM_EVENT_MANUAL_OPEN                         = (NETDEV_ALARM_EVENT_BASE + 161),    /* 手动开门/开灯  */
    NETDEV_ALARM_EVENT_ZONE_OPEN_DOOR                      = (NETDEV_ALARM_EVENT_BASE + 162),    /* 防区触发开门  */
    NETDEV_ALARM_EVENT_ZONE_DOOR_LONGTIME                  = (NETDEV_ALARM_EVENT_BASE + 163),    /* 防区长时间未触发布防  */
    NETDEV_ALARM_EVENT_ZONE_ARM                            = (NETDEV_ALARM_EVENT_BASE + 164),    /* 防区触发布防  */
    NETDEV_ALARM_EVENT_ZONE_DISARM                         = (NETDEV_ALARM_EVENT_BASE + 165),    /* 防区触发撤防  */
    NETDEV_ALARM_EVENT_TIMER_ARM                           = (NETDEV_ALARM_EVENT_BASE + 166),    /* 定时布防  */
    NETDEV_ALARM_EVENT_TIMER_DISARM                        = (NETDEV_ALARM_EVENT_BASE + 167),    /* 定时撤防  */
    NETDEV_ALARM_EVENT_CENTRAL_COMM_NORMAL                 = (NETDEV_ALARM_EVENT_BASE + 168),    /* 中心通讯正常  */
    NETDEV_ALARM_EVENT_CENTRAL_HANDSHAKE_FAILED            = (NETDEV_ALARM_EVENT_BASE + 169),    /* 中心握手失败  */
    NETDEV_ALARM_EVENT_CENTRAL_RESPONSE_FAILED             = (NETDEV_ALARM_EVENT_BASE + 170),    /* 中心应答失败  */
    NETDEV_ALARM_EVENT_USER_CONFIRMATION                   = (NETDEV_ALARM_EVENT_BASE + 171),    /* 用户接警确认  */
    NETDEV_ALARM_EVENT_USER_TIMEOUT                        = (NETDEV_ALARM_EVENT_BASE + 172),    /* 用户接警超时  */
    NETDEV_ALARM_EVENT_TELEP_RINGING                       = (NETDEV_ALARM_EVENT_BASE + 173),    /* 电话模块接收到振铃信号  */
    NETDEV_ALARM_EVENT_TELEP_ARM                           = (NETDEV_ALARM_EVENT_BASE + 174),    /* 电话模块接收到远程撤布防一位操作密码  */
    NETDEV_ALARM_EVENT_TELEP_STATUS_OFFLINE                = (NETDEV_ALARM_EVENT_BASE + 175),    /* 电话线掉线  */
    NETDEV_ALARM_EVENT_TELEP_STATUS_ONLINE                 = (NETDEV_ALARM_EVENT_BASE + 176),    /* 电话线在线  */
    NETDEV_ALARM_EVENT_MSG_SEND_SUCC                       = (NETDEV_ALARM_EVENT_BASE + 177),    /* 短信发送成功  */
    NETDEV_ALARM_EVENT_MSG_SEND_FAILED                     = (NETDEV_ALARM_EVENT_BASE + 178),    /* 短信发送失败  */
    NETDEV_ALARM_EVENT_SWITCH_CLOSE                        = (NETDEV_ALARM_EVENT_BASE + 179),    /* 操作开关合上  */
    NETDEV_ALARM_EVENT_SWITCH_OFF                          = (NETDEV_ALARM_EVENT_BASE + 180),    /* 操作开关断开  */
    NETDEV_ALARM_EVENT_TEMPER_CHANGE                       = (NETDEV_ALARM_EVENT_BASE + 181),    /* 温度变化上报  */
    NETDEV_ALARM_EVENT_HUMIDITY_CHANGE                     = (NETDEV_ALARM_EVENT_BASE + 182),    /* 湿度变化上报  */
    NETDEV_ALARM_EVENT_DEVID_WRONG                         = (NETDEV_ALARM_EVENT_BASE + 183),    /* 设备ID错误  */
    NETDEV_ALARM_EVENT_ELEC_HIGH_ARM                       = (NETDEV_ALARM_EVENT_BASE + 184),    /* 单个电子围栏高压布防  */
    NETDEV_ALARM_EVENT_ELEC_LOW_ARM                        = (NETDEV_ALARM_EVENT_BASE + 185),    /* 单个电子围栏低压布防  */
    NETDEV_ALARM_EVENT_ELEC_ALARM_RST                      = (NETDEV_ALARM_EVENT_BASE + 186),    /* 单个电子围栏报警复位  */
    NETDEV_ALARM_EVENT_ELEC_DISARM                         = (NETDEV_ALARM_EVENT_BASE + 187),    /* 单个电子围栏撤防  */
    NETDEV_ALARM_EVENT_ELEC_ARM                            = (NETDEV_ALARM_EVENT_BASE + 188),    /* 单个电子围栏电压值布防  */
    NETDEV_ALARM_EVENT_KEY_ALARM_OVER                      = (NETDEV_ALARM_EVENT_BASE + 189),    /* 键盘所有报警处理完成  */
    NETDEV_ALARM_EVENT_KEY_PROL_TYPE                       = (NETDEV_ALARM_EVENT_BASE + 190),    /* 键盘上报协议类型（主要针对电子围栏）  */
    NETDEV_ALARM_EVENT_MOD_DEV_ADDR                        = (NETDEV_ALARM_EVENT_BASE + 191),    /* 键盘修改设备地址（主要针对电子围栏）  */
    NETDEV_ALARM_EVENT_FORWARD_CMD                         = (NETDEV_ALARM_EVENT_BASE + 192) ,   /* 通讯设备转发中心命令  */

    NETDEV_ALARM_EVENT_BASE_VALUE                          = (110000UL),                                    /* 报警类型定义起始位置 */
    NETDEV_ALARM_EVENT_IMMEDIATELY_DEFEND_ALARM            = (NETDEV_ALARM_EVENT_BASE_VALUE + 1),           /* 即时防区报警 */
    NETDEV_ALARM_EVENT_IMMEDIATELY_DEFEND_ALARM_RST        = (NETDEV_ALARM_EVENT_BASE_VALUE + 2),           /* 即时防区报警恢复 */
    NETDEV_ALARM_EVENT_ALL_DAY_NO_VOICE_ALARM              = (NETDEV_ALARM_EVENT_BASE_VALUE + 3),           /* 24小时无声防区报警 */
    NETDEV_ALARM_EVENT_ALL_DAY_NO_VOICE_ALARM_RST          = (NETDEV_ALARM_EVENT_BASE_VALUE + 4),           /* 24小时无声防区报警恢复 */
    NETDEV_ALARM_EVENT_ALL_DAY_VOICE_ALARM                 = (NETDEV_ALARM_EVENT_BASE_VALUE + 5),           /* 24小时有声防区报警 */
    NETDEV_ALARM_EVENT_ALL_DAY_VOICE_ALARM_RST             = (NETDEV_ALARM_EVENT_BASE_VALUE + 6),           /* 24小时有声防区报警恢复 */
    NETDEV_ALARM_EVENT_BOARD_DEFEND_ALARM                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 7),           /* 周界防区报警 */
    NETDEV_ALARM_EVENT_BOARD_DEFEND_ALARM_RST              = (NETDEV_ALARM_EVENT_BASE_VALUE + 8),           /* 周界防区报警恢复 */
    NETDEV_ALARM_EVENT_INNER_DELAY_DEFEND_ALARM            = (NETDEV_ALARM_EVENT_BASE_VALUE + 9),           /* 内部延时防区报警 */
    NETDEV_ALARM_EVENT_INNER_DELAY_DEFEND_ALARM_RST        = (NETDEV_ALARM_EVENT_BASE_VALUE + 10),          /* 内部延时防区报警恢复 */
    NETDEV_ALARM_EVENT_DELAY_DEFEND_ALARM                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 11),          /* 延时防区报警 */
    NETDEV_ALARM_EVENT_DELAY_DEFEND_ALARM_RST              = (NETDEV_ALARM_EVENT_BASE_VALUE + 12),          /* 延时防区报警恢复 */
    NETDEV_ALARM_EVENT_EXPAND_MODEL_FAULT_ALARM            = (NETDEV_ALARM_EVENT_BASE_VALUE + 13),          /* 拓展模块故障 */
    NETDEV_ALARM_EVENT_EXPAND_MODEL_FAULT_ALARM_RST        = (NETDEV_ALARM_EVENT_BASE_VALUE + 14),          /* 拓展模块故障恢复 */
    NETDEV_ALARM_EVENT_OUTER_DISARMED                      = (NETDEV_ALARM_EVENT_BASE_VALUE + 15),          /* 外出撤防 */
    NETDEV_ALARM_EVENT_OUTER_ARMED                         = (NETDEV_ALARM_EVENT_BASE_VALUE + 16),          /* 外出布防 */
    NETDEV_ALARM_EVENT_KEY_DISARMED                        = (NETDEV_ALARM_EVENT_BASE_VALUE + 17),          /* 钥匙防区撤防 */
    NETDEV_ALARM_EVENT_KEY_ARMED                           = (NETDEV_ALARM_EVENT_BASE_VALUE + 18),          /* 钥匙防区布防 */
    NETDEV_ALARM_EVENT_WIRELESS_NET_WORK_EXCEPTION         = (NETDEV_ALARM_EVENT_BASE_VALUE + 19),          /* 无线网络异常 */
    NETDEV_ALARM_EVENT_WIRELESS_NET_WORK_EXCEPTION_RST     = (NETDEV_ALARM_EVENT_BASE_VALUE + 20),          /* 无线网络异常恢复 */
    NETDEV_ALARM_EVENT_WIRED_NET_WORK_BREAK                = (NETDEV_ALARM_EVENT_BASE_VALUE + 21),          /* 有线网络故障 */
    NETDEV_ALARM_EVENT_WIRED_NET_WORK_BREAK_RST            = (NETDEV_ALARM_EVENT_BASE_VALUE + 22),          /* 有线网络故障恢复 */
    NETDEV_ALARM_EVENT_SOFT_DEFEND_URGENCY_ALARM           = (NETDEV_ALARM_EVENT_BASE_VALUE + 23),          /* 软防区紧急报警 */
    NETDEV_ALARM_EVENT_ARMED_STAY                          = (NETDEV_ALARM_EVENT_BASE_VALUE + 24),          /* 留守布防 */
    NETDEV_ALARM_EVENT_IMMEDIATELY_ARMED                   = (NETDEV_ALARM_EVENT_BASE_VALUE + 25),          /* 即时布防 */

    /* 乌审旗对接昆仑传感（烟感、水浸、继电器报警）报警新增 */
    NETDEV_ALARM_EVENT_SMOKE_ALARM                         = (NETDEV_ALARM_EVENT_BASE_VALUE + 26),          /* 昆仑传感 烟感报警 */
    NETDEV_ALARM_EVENT_SMOKE_ALARM_END                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 27),          /* 昆仑传感 烟感报警停止 */
    NETDEV_ALARM_EVENT_WATER_ALARM                         = (NETDEV_ALARM_EVENT_BASE_VALUE + 28),          /* 昆仑传感 水浸报警 */
    NETDEV_ALARM_EVENT_WATER_ALARM_END                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 29),          /* 昆仑传感 水浸报警停止 */
    NETDEV_ALARM_EVENT_IO_ON                               = (NETDEV_ALARM_EVENT_BASE_VALUE + 30),          /* 昆仑传感.开关量开 */
    NETDEV_ALARM_EVENT_IO_OFF                              = (NETDEV_ALARM_EVENT_BASE_VALUE + 31),          /* 昆仑传感.开关量关 */

    /* 长飞振动光纤新增报警定义值 */
    NETDEV_ALARM_EVENT_TOUNCH_ALARM                        = (NETDEV_ALARM_EVENT_BASE_VALUE + 32),          /* 触碰报警 */
    NETDEV_ALARM_EVENT_INVADE_ALARM                        = (NETDEV_ALARM_EVENT_BASE_VALUE + 33),          /* 入侵报警 */
    NETDEV_ALARM_EVENT_BROKEN_ALARM                        = (NETDEV_ALARM_EVENT_BASE_VALUE + 34),          /* 断裂报警 */
    NETDEV_ALARM_EVENT_HELP                                = (NETDEV_ALARM_EVENT_BASE_VALUE + 36),          /* 紧急求助 */
    NETDEV_ALARM_EVENT_DESTROY                             = (NETDEV_ALARM_EVENT_BASE_VALUE + 37),          /* 破坏报警 */
    NETDEV_ALARM_EVENT_ACS                                 = (NETDEV_ALARM_EVENT_BASE_VALUE + 38),          /* 门禁报警 */
    NETDEV_ALARM_EVENT_OTHERS                              = (NETDEV_ALARM_EVENT_BASE_VALUE + 39),          /* 其它报警 */
    NETDEV_ALARM_EVENT_ZONE_ALARM                          = (NETDEV_ALARM_EVENT_BASE_VALUE + 40),          /* 安标报警模块.防区报警 */
    NETDEV_ALARM_EVENT_ZONE_ALARM_RST                      = (NETDEV_ALARM_EVENT_BASE_VALUE + 41),          /* 安标报警模块.防区恢复 */
    NETDEV_ALARM_EVENT_GATO_ALARM_FENCE                    = (NETDEV_ALARM_EVENT_BASE_VALUE + 42),          /* 围栏报警 */
    NETDEV_ALARM_EVENT_GATO_ALARM_HOST                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 43),          /* 主机报警 */
    NETDEV_ALARM_EVENT_GATO_ALARM_ETCZONE                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 44),          /* 扩展防区报警 */
    NETDEV_ALARM_EVENT_GATO_ALARM_OFFLINE                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 45),          /* 通信掉线 */
    NETDEV_ALARM_EVENT_GATO_ALARM_SWITCH1                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 46),          /* 防区开关量1报警 */
    NETDEV_ALARM_EVENT_GATO_ALARM_SWITCH2                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 47),          /* 防区开关量2报警 */
    NETDEV_ALARM_EVENT_STEAL                               = (NETDEV_ALARM_EVENT_BASE_VALUE + 48),          /* 窃盗报警 */
    NETDEV_ALARM_EVENT_GAS                                 = (NETDEV_ALARM_EVENT_BASE_VALUE + 49),          /* 燃气报警 */
    NETDEV_ALARM_EVENT_SAVE                                = (NETDEV_ALARM_EVENT_BASE_VALUE + 50),          /* 救护报警 */
    NETDEV_ALARM_EVENT_INVADE_TROUBLE                      = (NETDEV_ALARM_EVENT_BASE_VALUE + 51),          /* 入侵加故障报警 */
    NETDEV_ALARM_EVENT_SYS_TROUBLE                         = (NETDEV_ALARM_EVENT_BASE_VALUE + 52),          /* 系统故障 */
    NETDEV_ALARM_EVENT_OPTICAL_FIBER_TROUBLE               = (NETDEV_ALARM_EVENT_BASE_VALUE + 53),          /* 光纤故障 */

    /* 烽火科技报警主机报警子类型 */
    NETDEV_ALARM_EVENT_MOTION_DETECTION                    = (NETDEV_ALARM_EVENT_BASE_VALUE + 62),          /* 运动检测报警 */
    NETDEV_ALARM_EVENT_CALL_REMOVE                         = (NETDEV_ALARM_EVENT_BASE_VALUE + 63),          /* 呼叫解除报警 */
    NETDEV_ALARM_EVENT_NOISE                               = (NETDEV_ALARM_EVENT_BASE_VALUE + 64),          /* 噪音报警 */
    NETDEV_ALARM_EVENT_DELAYED                             = (NETDEV_ALARM_EVENT_BASE_VALUE + 65),          /* 延时报警 */
    NETDEV_ALARM_EVENT_ALARM_INPUT_ONE                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 66),          /* 报警输入1报警 */
    NETDEV_ALARM_EVENT_ALARM_INPUT_TWO                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 67),          /* 报警输入2报警 */
    NETDEV_ALARM_EVENT_ALARM_CALL_EMERGENCY                = (NETDEV_ALARM_EVENT_BASE_VALUE + 68),          /* 紧急呼叫  */
    NETDEV_ALARM_EVENT_ALARM_CALL_CONSULTANT               = (NETDEV_ALARM_EVENT_BASE_VALUE + 69),          /* 咨询呼叫 */
    NETDEV_ALARM_EVENT_DOOR_MAGNET_OPEN                    = (NETDEV_ALARM_EVENT_BASE_VALUE + 70),          /* 门磁打开 */
    NETDEV_ALARM_EVENT_DOOR_MAGNET_CLOSE                   = (NETDEV_ALARM_EVENT_BASE_VALUE + 71),          /* 门磁关闭 */
    NETDEV_ALARM_EVENT_DOOR_LOCK_OPEN                      = (NETDEV_ALARM_EVENT_BASE_VALUE + 72),          /* 门锁打开 */
    NETDEV_ALARM_EVENT_DOOR_LOCK_CLOSE                     = (NETDEV_ALARM_EVENT_BASE_VALUE + 73),          /* 门锁关闭 */

    /*世邦报警柱报警子类型*/
    NETDEV_ALARM_EVENT_ALARM_PORT_ONE             = (NETDEV_ALARM_EVENT_BASE_VALUE + 74),          /* 端口1报警  Port 1 Alarm */
    NETDEV_ALARM_EVENT_ALARM_PORT_TWO             = (NETDEV_ALARM_EVENT_BASE_VALUE + 75),          /* 端口2报警  Port 2 Alarm */
    NETDEV_ALARM_EVENT_ALARM_PORTEX               = (NETDEV_ALARM_EVENT_BASE_VALUE + 76),          /* 扩展端口报警  Expansion Port Alarm */
    NETDEV_ALARM_EVENT_ALARM_TUMULT               = (NETDEV_ALARM_EVENT_BASE_VALUE + 77),          /* 喧哗报警  Tumult Alarm */
    NETDEV_ALARM_EVENT_ALARM_110                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 78),          /* 110报警  110 Alarm */
    NETDEV_ALARM_EVENT_ALARM_119                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 79),          /* 119报警  119 Alarm */
    NETDEV_ALARM_EVENT_ALARM_120                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 80),          /* 120报警  120 Alarm */

    /* 蓝星报警主机报警子类型 */
    NETDEV_ALARM_EVENT_ALARM_FINDERCONNECT_FAILED = (NETDEV_ALARM_EVENT_BASE_VALUE + 81),          /* 探测器通讯失败 */
    NETDEV_ALARM_EVENT_ALARM_OUTAGE               = (NETDEV_ALARM_EVENT_BASE_VALUE + 82),          /* 断电报警 */
    NETDEV_ALARM_EVENT_ALARM_DISASSEMBLE          = (NETDEV_ALARM_EVENT_BASE_VALUE + 83),          /* 拆机报警 */
    NETDEV_ALARM_EVENT_ALARM_CIRCUIT              = (NETDEV_ALARM_EVENT_BASE_VALUE + 84),          /* 断路报警 */
    NETDEV_ALARM_EVENT_ALARM_TOUCHNET             = (NETDEV_ALARM_EVENT_BASE_VALUE + 85),          /* 触网报警 */
    NETDEV_ALARM_EVENT_ALARM_PREVENTCUT           = (NETDEV_ALARM_EVENT_BASE_VALUE + 86),          /* 防剪报警 */
    NETDEV_ALARM_EVENT_ALARM_COCKING              = (NETDEV_ALARM_EVENT_BASE_VALUE + 87),          /* 拉紧报警 */
    NETDEV_ALARM_EVENT_ALARM_SLACK                = (NETDEV_ALARM_EVENT_BASE_VALUE + 88),          /* 松弛报警 */
    NETDEV_ALARM_EVENT_ALARM_ZONE_FORBIDDEN       = (NETDEV_ALARM_EVENT_BASE_VALUE + 89),          /* 防区禁用 */

    /* 建大仁科 */
    NETDEV_ALARM_EVENT_HIGH_TEMP                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 90),           /* 温度超上限报警 */
    NETDEV_ALARM_EVENT_LOW_TEMP                   = (NETDEV_ALARM_EVENT_BASE_VALUE + 91),           /* 温度超下限报警 */
    NETDEV_ALARM_EVENT_HIGH_HUMI                  = (NETDEV_ALARM_EVENT_BASE_VALUE + 92),           /* 湿度超上限报警 */
    NETDEV_ALARM_EVENT_LOW_HUMI                   = (NETDEV_ALARM_EVENT_BASE_VALUE + 93),           /* 湿度超下限报警 */
    NETDEV_ALARM_MONITOR_DEVICE_ONLINE            = (NETDEV_ALARM_EVENT_BASE_VALUE + 94),           /* 监控点设备在线 */
    NETDEV_ALARM_MONITOR_DEVICE_OFFLINE           = (NETDEV_ALARM_EVENT_BASE_VALUE + 95),           /* 监控点设备离线 */

    /* 门禁上报事件类型定义*/
    NETDEV_DOOR_EVENT_BASE                         = (100400UL),                          /* 门禁事件类型定义起始位置 */

    NETDEV_DOOR_EVENT_DISCONNECT                   = (NETDEV_DOOR_EVENT_BASE + 1),        /* 通信中断(门禁主机与门之间) */
    NETDEV_DOOR_EVENT_INFRARED_ALARM               = (NETDEV_DOOR_EVENT_BASE + 2),        /* 红外报警 */
    NETDEV_DOOR_EVENT_ILLICIT_OPEN_DOOR            = (NETDEV_DOOR_EVENT_BASE + 3),        /* 非法开门 */
    NETDEV_DOOR_EVENT_COERCE_ALARM                 = (NETDEV_DOOR_EVENT_BASE + 4),        /* 胁迫报警 */
    NETDEV_DOOR_EVENT_OPEN_TIMEOUT                 = (NETDEV_DOOR_EVENT_BASE + 5),        /* 超时未开门 */
    NETDEV_DOOR_EVENT_CLOSE_TIMEOUT                = (NETDEV_DOOR_EVENT_BASE + 6),        /* 超时未关门 */
    NETDEV_DOOR_EVENT_ANOMALOUS_CARD               = (NETDEV_DOOR_EVENT_BASE + 7),        /* 异常刷卡 */
    NETDEV_DOOR_EVENT_CARD_OPEN_DOOR               = (NETDEV_DOOR_EVENT_BASE + 8),        /* 刷卡开门 */
    NETDEV_DOOR_EVENT_REMOTE_OPEN_DOOR             = (NETDEV_DOOR_EVENT_BASE + 9),        /* 远程开门 */
    NETDEV_DOOR_EVENT_MANUAL_OPEN_DOOR             = (NETDEV_DOOR_EVENT_BASE + 10),       /* 手动开门 */
    NETDEV_DOOR_EVENT_EMERGENCY_START              = (NETDEV_DOOR_EVENT_BASE + 11),       /* 紧急事件开始 */
    NETDEV_DOOR_EVENT_EMERGENCY_STOP               = (NETDEV_DOOR_EVENT_BASE + 12),       /* 紧急事件结束 */
    NETDEV_DOOR_EVENT_OPEN_SUCCESS                 = (NETDEV_DOOR_EVENT_BASE + 13),       /* 开门成功 */
    NETDEV_DOOR_EVENT_OPEN_FAILED                  = (NETDEV_DOOR_EVENT_BASE + 14),       /* 开门失败 */
    NETDEV_DOOR_EVENT_CLOSE                        = (NETDEV_DOOR_EVENT_BASE + 15),       /* 关门事件 */
    NETDEV_DOOR_EVENT_CLOSE_FAILED                 = (NETDEV_DOOR_EVENT_BASE + 16),       /* 关门失败 */
    NETDEV_DOOR_EVENT_CARD_NO_AUTH                 = (NETDEV_DOOR_EVENT_BASE + 17),       /* 卡无权限 */
    NETDEV_DOOR_EVENT_NO_DATE_LIMIT                = (NETDEV_DOOR_EVENT_BASE + 18),       /* 无期限 */
    NETDEV_DOOR_EVENT_CARD_ILLEGAL                 = (NETDEV_DOOR_EVENT_BASE + 19),       /* 卡非法 */
    NETDEV_DOOR_EVENT_FIREPORTECT_ALRAM            = (NETDEV_DOOR_EVENT_BASE + 20),       /* 消防报警 */
    NETDEV_DOOR_EVENT_CANCEL_FIREPORTECT           = (NETDEV_DOOR_EVENT_BASE + 21),       /* 取消消防 */
    NETDEV_DOOR_EVENT_PRYING_RESIST_ALRAM          = (NETDEV_DOOR_EVENT_BASE + 22),       /* 防撬报警 */
    NETDEV_DOOR_EVENT_SUPERPASSWD_OPEN_DOOR        = (NETDEV_DOOR_EVENT_BASE + 23),       /* 超级密码开门 */
    NETDEV_DOOR_EVENT_COERCECODE_IN                = (NETDEV_DOOR_EVENT_BASE + 24),       /* 胁迫码进入 */
    NETDEV_DOOR_EVENT_DOOR_STATUS_OPEN             = (NETDEV_DOOR_EVENT_BASE + 25),       /* 门打开 */
    NETDEV_DOOR_EVENT_DOOR_STATUS_CLOSE            = (NETDEV_DOOR_EVENT_BASE + 26),       /* 门关闭 */
    NETDEV_DOOR_EVENT_DOOR_FORCED_OPEN             = (NETDEV_DOOR_EVENT_BASE + 27),       /* 门强开 */
    NETDEV_DOOR_EVENT_DOOR_KEEP_OPEN               = (NETDEV_DOOR_EVENT_BASE + 28),       /* 门保持打开 */
    NETDEV_DOOR_EVENT_LOCK_FAILURE                 = (NETDEV_DOOR_EVENT_BASE + 29),       /* 锁失效 */
    NETDEV_DOOR_EVENT_LOST_STOLEN_CARD             = (NETDEV_DOOR_EVENT_BASE + 30),       /* 丢失或被盗卡 */

    /* 达实门禁对接新增 */
    NETDEV_DOOR_EVENT_PASSWD_WRONG                 = (NETDEV_DOOR_EVENT_BASE + 31),       /* 密码错误 */
    NETDEV_DOOR_EVENT_ALWAYS_CLOSED                = (NETDEV_DOOR_EVENT_BASE + 32),       /* 常闭未通过 */
    NETDEV_DOOR_EVENT_CARD_PASSWD_ENTER            = (NETDEV_DOOR_EVENT_BASE + 33),       /* 卡加密码进入 */
    NETDEV_DOOR_EVENT_CARD_PASSWD_WRONG            = (NETDEV_DOOR_EVENT_BASE + 34),       /* 卡加密码错误 */
    NETDEV_DOOR_EVENT_MORE_CARD_OPEN               = (NETDEV_DOOR_EVENT_BASE + 35),       /* 多卡开门 */
    NETDEV_DOOR_EVENT_FIRST_CARD_OPEN              = (NETDEV_DOOR_EVENT_BASE + 36),       /* 首卡开门 */
    NETDEV_DOOR_EVENT_CARD_OUT_DATE                = (NETDEV_DOOR_EVENT_BASE + 37),       /* 卡过期限 */
    NETDEV_DOOR_EVENT_CARD_WATCH                   = (NETDEV_DOOR_EVENT_BASE + 38),       /* 巡更卡 */

    /*海康门禁对接新增 */ 
    NETDEV_DOOR_EVENT_REMOTE_CLOSE_DOOR            = (NETDEV_DOOR_EVENT_BASE + 39),       /* 远程关门 */
    NETDEV_DOOR_EVENT_REMOTE_ALWAYS_OPEN           = (NETDEV_DOOR_EVENT_BASE + 40),       /* 远程常开 */
    NETDEV_DOOR_EVENT_REMOTE_ALWAYS_CLOSE          = (NETDEV_DOOR_EVENT_BASE + 41),       /* 远程常关 */
    NETDEV_DOOR_EVENT_LEGAL_CARD_PASS              = (NETDEV_DOOR_EVENT_BASE + 42),       /* 合法卡认证通过 */
    NETDEV_DOOR_EVENT_CARD_AND_PSW_PASS            = (NETDEV_DOOR_EVENT_BASE + 43),       /* 刷卡加密码认证通过 */
    NETDEV_DOOR_EVENT_CARD_AND_PSW_FAIL            = (NETDEV_DOOR_EVENT_BASE + 44),       /* 刷卡加密码认证失败） */
    NETDEV_DOOR_EVENT_CARD_AND_PSW_TIMEOUT         = (NETDEV_DOOR_EVENT_BASE + 45),       /* 数卡加密码认证超时 */
    NETDEV_DOOR_EVENT_CARD_AND_PSW_OVER_TIME       = (NETDEV_DOOR_EVENT_BASE + 46),       /* 刷卡加密码超次 */
    NETDEV_DOOR_EVENT_INVALID_CARD                 = (NETDEV_DOOR_EVENT_BASE + 47),       /* 无此卡号 */
    NETDEV_DOOR_EVENT_DOOR_BUTTON_PRESS            = (NETDEV_DOOR_EVENT_BASE + 48),       /* 开门按钮按下 */
    NETDEV_DOOR_EVENT_DOOR_BUTTON_RELEASE          = (NETDEV_DOOR_EVENT_BASE + 49),       /* 开门按钮松开 */
    NETDEV_DOOR_EVENT_CARD_READER_DESMANTLE_ALARM  = (NETDEV_DOOR_EVENT_BASE + 50),       /* 读卡器防拆报警 */
    NETDEV_DOOR_EVENT_CARD_READER_DESMANTLE_RESUME = (NETDEV_DOOR_EVENT_BASE + 51),       /* 读卡器防拆恢复 */
    NETDEV_DOOR_EVENT_DOOR_MAGNET_OPEN             = (NETDEV_DOOR_EVENT_BASE + 52),       /* 门磁打开（正常开门） */
    NETDEV_DOOR_EVENT_DOOR_MAGNET_CLOSE            = (NETDEV_DOOR_EVENT_BASE + 53),       /* 门磁关闭（正常关门 */
    NETDEV_DOOR_EVENT_DOOR_MAGNET_OPEN_ABNORMAL    = (NETDEV_DOOR_EVENT_BASE + 54),       /* 门磁异常打开（门异常打开） */
    NETDEV_DOOR_EVENT_DOOR_MAGNET_OPEN_TIMEOUT     = (NETDEV_DOOR_EVENT_BASE + 55),       /* 门磁打开超时(门打开超时) */
    NETDEV_DOOR_EVENT_ANTI_SNEAK_FAIL              = (NETDEV_DOOR_EVENT_BASE + 56),       /* 反潜回认证失败 */
    NETDEV_DOOR_EVENT_INTERLOCK_DOOR_NOT_CLOSE     = (NETDEV_DOOR_EVENT_BASE + 57),       /* 互锁门未关闭 */
    NETDEV_DOOR_EVENT_MULTI_VERIFY_SUCCESS         = (NETDEV_DOOR_EVENT_BASE + 58),       /* 多重认证成功 */
    NETDEV_DOOR_EVENT_LEADER_CARD_OPEN_BEGIN       = (NETDEV_DOOR_EVENT_BASE + 59),       /* 首卡开门开始 */
    NETDEV_DOOR_EVENT_LEADER_CARD_OPEN_END         = (NETDEV_DOOR_EVENT_BASE + 60),       /* 首卡开门结束 */
    NETDEV_DOOR_EVENT_ALWAYS_OPEN_BEGIN            = (NETDEV_DOOR_EVENT_BASE + 61),       /* 常开状态开始 */
    NETDEV_DOOR_EVENT_ALWAYS_OPEN_END              = (NETDEV_DOOR_EVENT_BASE + 62),       /* 常开状态结束 */
    NETDEV_DOOR_EVENT_ALWAYS_CLOSE_BEGIN           = (NETDEV_DOOR_EVENT_BASE + 63),       /* 常关状态开始 */
    NETDEV_DOOR_EVENT_ALWAYS_CLOSE_END             = (NETDEV_DOOR_EVENT_BASE + 64),       /* 常关状态结束 */
    NETDEV_DOOR_EVENT_KEYPRESS_OPEN_DOOR           = (NETDEV_DOOR_EVENT_BASE + 65),       /* 按键开门 */

    /* 纽贝尔门禁新协议对接事件定义 */
    NETDEV_DOOR_EVENT_COMMU_INTERRUPT              = (NETDEV_DOOR_EVENT_BASE + 81),       /* 通讯中断 */
    NETDEV_DOOR_EVENT_COMMU_RESTORE                = (NETDEV_DOOR_EVENT_BASE + 82),       /* 通讯恢复 */
    NETDEV_DOOR_EVENT_LEGAL_CREDIT_CARD            = (NETDEV_DOOR_EVENT_BASE + 83),       /* 合法刷卡 */
    NETDEV_DOOR_EVENT_LEGAL_USER_ID                = (NETDEV_DOOR_EVENT_BASE + 84),       /* 合法用户ID */
    NETDEV_DOOR_EVENT_CARD_NO_REG                  = (NETDEV_DOOR_EVENT_BASE + 85),       /* 卡未注册 */
    NETDEV_DOOR_EVENT_CARD_UNAUTH                  = (NETDEV_DOOR_EVENT_BASE + 86),       /* 卡未授权 */
    NETDEV_DOOR_EVENT_CARD_DISABLED                = (NETDEV_DOOR_EVENT_BASE + 87),       /* 卡已停用 */
    NETDEV_DOOR_EVENT_CARD_EXPIRED                 = (NETDEV_DOOR_EVENT_BASE + 88),       /* 卡已过期 */
    NETDEV_DOOR_EVENT_INVALID_TIME                 = (NETDEV_DOOR_EVENT_BASE + 89),       /* 无效时段 */
    NETDEV_DOOR_EVENT_PSW_ERROR                    = (NETDEV_DOOR_EVENT_BASE + 90),       /* 密码错误 */
    NETDEV_DOOR_EVENT_PROHIBITED                   = (NETDEV_DOOR_EVENT_BASE + 91),       /* 禁止通行 */
    NETDEV_DOOR_EVENT_REQ_CENTER_OPEN_DOOR         = (NETDEV_DOOR_EVENT_BASE + 92),       /* 请求中心开门 */
    NETDEV_DOOR_EVENT_LEGAL_CARD_OPEN_DOOR         = (NETDEV_DOOR_EVENT_BASE + 93),       /* 合法卡开门 */
    NETDEV_DOOR_EVENT_SUPER_CARD_OPEN_DOOR         = (NETDEV_DOOR_EVENT_BASE + 94),       /* 超级卡开门 */
    NETDEV_DOOR_EVENT_CENTER_OPEN_DOOR             = (NETDEV_DOOR_EVENT_BASE + 96),       /* 中心开门 */
    NETDEV_DOOR_EVENT_LINK_OPEN_DOOR               = (NETDEV_DOOR_EVENT_BASE + 97),       /* 联动开门 */
    NETDEV_DOOR_EVENT_FORCE_OPEN_DOOR              = (NETDEV_DOOR_EVENT_BASE + 98),       /* 强行开门 */
    NETDEV_DOOR_EVENT_DOOR_IS_OPEN                 = (NETDEV_DOOR_EVENT_BASE + 99),       /* 门被打开 */
    NETDEV_DOOR_EVENT_DOOR_IS_CLOSE                = (NETDEV_DOOR_EVENT_BASE + 100),      /* 门被关闭 */
    NETDEV_DOOR_EVENT_STRESS_ALARM                 = (NETDEV_DOOR_EVENT_BASE + 103),      /* 胁迫报警 */
    NETDEV_DOOR_EVENT_TRAILING_ALARM               = (NETDEV_DOOR_EVENT_BASE + 105),      /* 尾随报警 */
    NETDEV_DOOR_EVENT_DOOR_LOCK                    = (NETDEV_DOOR_EVENT_BASE + 106),      /* 门锁死 */
    NETDEV_DOOR_EVENT_LIFT_DOOR_LOCK               = (NETDEV_DOOR_EVENT_BASE + 107),      /* 门解除锁死 */
    NETDEV_DOOR_EVENT_DOOR_NOT_CLOSE               = (NETDEV_DOOR_EVENT_BASE + 108),      /* 门未关好 */
    NETDEV_DOOR_EVENT_NEED_PSW                     = (NETDEV_DOOR_EVENT_BASE + 109),      /* 需要密码 */
    NETDEV_DOOR_EVENT_NEED_FINGERPRINT             = (NETDEV_DOOR_EVENT_BASE + 110),      /* 需要指纹 */
    NETDEV_DOOR_EVENT_REQ_INTERCOM                 = (NETDEV_DOOR_EVENT_BASE + 111),      /* 请求对讲 */
    NETDEV_DOOR_EVENT_EMERGENCY                    = (NETDEV_DOOR_EVENT_BASE + 112),      /* 紧急事件 */
    NETDEV_DOOR_EVENT_PATROL_LEGAL_CREDIT_CARD     = (NETDEV_DOOR_EVENT_BASE + 113),      /* 巡更合法刷卡 */
    NETDEV_DOOR_EVENT_PATROL_LEGAL_FINGERPRINT     = (NETDEV_DOOR_EVENT_BASE + 114),      /* 巡更合法指纹 */
    NETDEV_DOOR_EVENT_PATROL_CARD_NOT_REG          = (NETDEV_DOOR_EVENT_BASE + 115),      /* 巡更卡未注册 */
    NETDEV_DOOR_EVENT_NOT_PATROL_CARD              = (NETDEV_DOOR_EVENT_BASE + 116),      /* 非巡更员刷卡 */
    NETDEV_DOOR_EVENT_NORMAL_PATROL                = (NETDEV_DOOR_EVENT_BASE + 117),      /* 正常巡更 */
    NETDEV_DOOR_EVENT_ADVANCE_PATROL               = (NETDEV_DOOR_EVENT_BASE + 118),      /* 提前巡更 */
    NETDEV_DOOR_EVENT_TIMEOUT_PATROL               = (NETDEV_DOOR_EVENT_BASE + 119),      /* 超时巡更 */
    NETDEV_DOOR_EVENT_INVALID_PATROL               = (NETDEV_DOOR_EVENT_BASE + 120),      /* 无效巡更 */
    NETDEV_DOOR_EVENT_NOT_PATROL                   = (NETDEV_DOOR_EVENT_BASE + 121),      /* 未巡更 */
    NETDEV_DOOR_EVENT_TH_ALARM                     = (NETDEV_DOOR_EVENT_BASE + 122),      /* 温湿度报警 */
    NETDEV_DOOR_EVENT_TH_RESTORE                   = (NETDEV_DOOR_EVENT_BASE + 123),      /* 温湿度恢复 */
    NETDEV_DOOR_EVENT_TH_RECORD                    = (NETDEV_DOOR_EVENT_BASE + 124),      /* 温湿度记录 */
    NETDEV_DOOR_EVENT_SMOKE_ALARM                  = (NETDEV_DOOR_EVENT_BASE + 125),      /* 烟感报警 */
    NETDEV_DOOR_EVENT_SMOKE_RESTORE                = (NETDEV_DOOR_EVENT_BASE + 126),      /* 烟感恢复 */
    NETDEV_DOOR_EVENT_SMOKE_RECORD                 = (NETDEV_DOOR_EVENT_BASE + 127),      /* 烟感记录 */

    /* 微耕门禁新协议对接事件定义 */
    NETDEV_DOOR_EVENT_PC_CONTROL                   = (NETDEV_DOOR_EVENT_BASE + 128),      /* 刷卡不通过：电脑控制 */
    NETDEV_DOOR_EVENT_LIMITED_CARD_NUM             = (NETDEV_DOOR_EVENT_BASE + 129),      /* 刷卡不通过：受刷卡次数限制 */
    NETDEV_DOOR_EVENT_REASON_UNKNOWN               = (NETDEV_DOOR_EVENT_BASE + 130),      /* 刷卡不通过：原因不明 */
    NETDEV_DOOR_EVENT_CONTROLLER_ON                = (NETDEV_DOOR_EVENT_BASE + 131),      /* 控制器上电 */
    NETDEV_DOOR_EVENT_CONTROLLER_RESERT            = (NETDEV_DOOR_EVENT_BASE + 132),      /* 控制器复位 */
    NETDEV_DOOR_EVENT_DOOR_FORCE_CLOSE             = (NETDEV_DOOR_EVENT_BASE + 133),      /* 强制关门 */
    NETDEV_DOOR_EVENT_DOOR_OFFLINE                 = (NETDEV_DOOR_EVENT_BASE + 134),      /* 门不在线 */
    NETDEV_DOOR_EVENT_FIRE                         = (NETDEV_DOOR_EVENT_BASE + 135),      /* 火警 */
    NETDEV_DOOR_EVENT_CALL_EMERGENCY               = (NETDEV_DOOR_EVENT_BASE + 136),      /* 呼叫紧急报警 */
    NETDEV_DOOR_PERSON_FACE_DOOR                   = (NETDEV_DOOR_EVENT_BASE + 137),      /* 人脸刷门 */
    NETDEV_DOOR_PERSON_INVALE_DOOR                 = (NETDEV_DOOR_EVENT_BASE + 138),      /* 人脸非法刷门 */

    NETDEV_DOOR_EVENT_END                          = (NETDEV_DOOR_EVENT_BASE + 599),      /* 门禁事件类型定义结束位置 */

#define NETDEV_IS_DOOR_EVENT(x)    (NETDEV_DOOR_EVENT_BASE <= (x) && (x) < NETDEV_DOOR_EVENT_END)

}NETDEV_ALARM_SUBTYPE_E;

/**
 * @enum tagNETDEVEventResType
 * @brief 事件资源类型枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVEventResType
{
    NETDEV_EVENT_RES_TYPE_USER              = 0,                /* 用户资源，用户上下线对应登录句柄，其余对应用户编号 */
    NETDEV_EVENT_RES_TYPE_DEVICE            = 1,                /* 设备资源，对应设备编号 */
    NETDEV_EVENT_RES_TYPE_CHANNEL           = 2,                /* 通道资源，对应通道编号 */
    NETDEV_EVENT_RES_TYPE_LOGOUT            = 3,                /* 强制用户退出，对应登录句柄 */
    NETDEV_EVENT_RES_TYPE_SEQUENCE          = 4,                /* 轮巡资源，对应资源ID */
    NETDEV_EVENT_RES_TYPE_EMAP_HOTPOT       = 5,                /* 电子地图热点资源，对应资源ID */
    NETDEV_EVENT_RES_TYPE_EMAP_HOTAREA      = 6,                /* 电子地图热区资源，对应资源ID */
    NETDEV_EVENT_RES_TYPE_EMAP_ALARM        = 7,                /* 电子地图告警资源，对应资源ID */
    NETDEV_EVENT_RES_TYPE_TIMETEMPLATE      = 8,                /* 告警预案模板，对应模板ID */
    NETDEV_EVENT_RES_TYPE_SYSRIGHT          = 9,                /* 系统权限资源，对应用户登录句柄 */
    NETDEV_EVENT_RES_TYPE_DEVRIGHT          = 10,               /* 设备权限资源，对应通道编号 */
    NETDEV_EVENT_RES_TYPE_ORG               = 11,               /* 组织资源，对应组织编号 */
    NETDEV_EVENT_RES_TYPE_ALARM_TASK        = 12,               /* 报警任务资源，对应报警任务编号 */
    NETDEV_EVENT_RES_TYPE_SLAVE             = 13,               /* 主从资源(与服务端保持一致) */
    NETDEV_EVENT_RES_TYPE_TVWALL            = 14,               /* 电视墙资源，对应电视墙ID */
    NETDEV_EVENT_RES_TYPE_TVWALL_SCENE      = 15,               /* 电视墙场景资源，对应电视墙ID */
    NETDEV_EVENT_RES_TYPE_WND               = 16,               /* 电视墙窗口资源，对应窗口ID */
    NETDEV_EVENT_RES_TYPE_VIRTUAL_LED       = 17,               /* 电视墙虚拟LED资源，对应虚拟LED ID */
    NETDEV_EVENT_RES_TYPE_BROADCAST_CHANGE  = 18,               /* 广播组信息变更(值与服务端保持一致) */
    NETDEV_EVENT_RES_TYPE_LOGIC_ORG         = 19,               /* 虚拟组织资源，对应组织编号，删除虚拟组织下通道时使用 */
    NETDEV_EVENT_RES_TYPE_USER_ROLE         = 20,               /* 用户角色资源，对应用户登录句柄*/
    NETDEV_EVENT_RES_TYPE_ROLE_ORG          = 21,               /* 角色组织展示树资源，对应用户登录句柄 */
    NETDEV_EVENT_RES_TYPE_EMAP_PIC          = 22,               /* 图片资源，对应热区编号 */
    NETDEV_EVENT_RES_TYPE_PATROL            = 23,               /* 巡航资源 */
    NETDEV_EVENT_RES_TYPE_RECORD            = 24,               /* 录制轨迹资源 */
    NETDEV_EVENT_RES_TYPE_ACS_PERSON        = 25,               /* 门禁人员资源，对应门禁人员ID */
    NETDEV_EVENT_RES_TYPE_ACS_PERSON_CARD   = 26,               /* 门禁卡资源，对应门禁人员ID */
    NETDEV_EVENT_RES_TYPE_TVWALL_LIST       = 27,               /* 电视墙列表，权限到电视墙 */
    NETDEV_EVENT_RES_TYPE_TVWALL_SCENE_SWITCH = 28,             /* 电视墙场景切换 */

    NETDEV_EVENT_RES_TYPE_FACE_LIB          = 29,               /* 人脸库资源，对应人脸库ID */
    NETDEV_EVENT_RES_TYPE_FACE_CUSTOM       = 30,               /* 人脸库自定义属性，对应属性ID */
    NETDEV_EVENT_RES_TYPE_FACE_MEMBER       = 31,               /* 人脸成员资源，对应人脸库ID */
    NETDEV_EVENT_RES_TYPE_FACE_GUARD        = 32,               /* 人脸布控资源，对应人脸布控ID */
    NETDEV_EVENT_RES_TYPE_SMART_DETECT      = 33,               /* 智能检测资源，对应智能检测类型，人脸识别:0 */
    NETDEV_EVENT_RES_TYPE_MANUAL_STATUS     = 34,               /* 手动录像状态 */
    NETDEV_EVENT_RES_TYPE_VEHICLE_GUARD     = 38,               /* 车牌布控资源，对应车牌布控ID */
    NETDEV_EVENT_RES_TYPE_CDN_CHANNEL       = 39,               /* CDN通道资源变更，不上报对应变更信息，客户端收到事件后主动来查询通道列表 */
    NETDEV_EVENT_RES_TYPE_FACE_MEMBER_SORT  = 40,               /* 人脸成员划归资源，对应人脸库ID */
    NETDEV_EVENT_RES_TYPE_VEHICLE_LIB       = 41,               /* 车辆库资源，对应车辆库ID */
    NETDEV_EVENT_RES_TYPE_VEHICLE_MEMBER_SORT = 42,             /* 车辆成员划归资源，对应车辆库ID */
    NETDEV_EVENT_RES_TYPE_VEHICLE_MEMBER      = 43,             /* 车辆成员资源，对应车辆成员ID */
    NETDEV_EVENT_RES_TYPE_VIEWPLAN_RES      = 44,               /* 视图计划，对应计划ID */
    NETDEV_EVENT_RES_TYPE_SCENESPLAN_RES    = 45,               /* 场景间计划，对应计划ID */
    NETDEV_EVENT_RES_TYPE_ACS_PERMISSION    = 46,               /* 权限资源,  用于授权信息变更*/
    NETDEV_EVENT_RES_TYPE_ACS_GROUP         = 47,               /* 门禁权限组资源，用于门禁权限组（组织）的变更 */
    NETDEV_EVENT_RES_TYPE_TVWALL_AUDIO      = 48,               /* 音频事件 */

    NETDEV_EVENT_RES_TYPE_INVALID           = 0xFF              /* 无效值 */
}NETDEV_EVENT_RES_TYPE_E;

/**
* @enum tagNETDEVRecordSearchType
* @brief 按位查询录像类型枚举，参照最新LAPI接口文档
*/
typedef enum tagNETDEVRecordSearchType
{
    NETDEV_RECORD_SEARCH_TYPE_MANUL                  = 1,               /* 手动录像 */
    NETDEV_RECORD_SEARCH_TYPE_EVENT                  = 2,              /* 通用类告警 */
    NETDEV_RECORD_SEARCH_TYPE_MOTION                 = 4,               /* 运动检测 */
    NETDEV_RECORD_SEARCH_TYPE_ALARMIN                = 8,               /* 输入开关量 */
    NETDEV_RECORD_SEARCH_TYPE_VIDEO_LOSS             = 16,               /* 视频丢失 */
    NETDEV_RECORD_SEARCH_TYPE_AUDIO_DETECT           = 64,               /* 音频检测 */

    NETDEV_RECORD_SEARCH_TYPE_COMMON                 = 128,               /* 计划录像(常规录像) */
    NETDEV_RECORD_SEARCH_TYPE_FACE_DETECT            = 256,              /* 人脸检测 */
    NETDEV_RECORD_SEARCH_TYPE_LINE_DETECT            = 512,              /* 越界检测 */
    NETDEV_RECORD_SEARCH_TYPE_FIELD_DETECT           = 1024,              /* 区域入侵 */


    NETDEV_RECORD_SEARCH_TYPE_INVALID                = 0XFFFFFFFF             /* 无效值 */
}NETDEV_RECORD_SEARCH_TYPE_E;

/* IP地址类型 */
typedef enum tagNETDEVAddressType
{
    NETDEV_ADDRESS_TYPE_IPV4                    = 0,               /* IPV4 */
    NETDEV_ADDRESS_TYPE_IPV6                    = 1,               /* IPV6 */
    NETDEV_ADDRESS_TYPE_DOMAIN                  = 2,               /* 域名 */
    NETDEV_ADDRESS_TYPE_IPV4_IPV6               = 3,               /* IPV4和IPV6 */

    NETDEV_ADDRESS_TYPE_INVALID                 = 0xFF             /* 无效值 */
}NETDEV_ADDRESS_TYPE_E;

/**
* @enum tagNETDEVVehicleMonitorType
* @brief 车辆布控类型 枚举定义 monitor type Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVehicleMonitorType
{
    NETDEV_VEHICLE_MONITOR_TYPE_ROB_E         = 0,           /* 被抢车 */
    NETDEV_VEHICLE_MONITOR_TYPE_STEAL_E       = 1,           /* 被盗车 */
    NETDEV_VEHICLE_MONITOR_TYPE_SUSPICION_E   = 2,           /* 嫌疑车 */
    NETDEV_VEHICLE_MONITOR_TYPE_ILLEGAL_E     = 3,           /* 交通违法车 */
    NETDEV_VEHICLE_MONITOR_TYPE_SUREILLANCE_E = 4,           /* 紧急查控车 */

    NETDEV_VEHICLE_MONITOR_TYPE_ALL_E         = 255,         /* 所有布控车 */

    NETDEV_VEHICLE_MONITOR_TYPE_INVALID = 0xFFFF             /* 无效值  Invalid value */
}NETDEV_VEHICLE_MONITOR_TYPE_E;

/**
* @enum tagNETDEVPlateColor
* @brief 车牌颜色 枚举定义 plate color Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVPlateColor
{
    NETDEV_PLATE_COLOR_BLACK_E = 0,           /* 黑色 */
    NETDEV_PLATE_COLOR_WHITE_E = 1,           /* 白色 */
    NETDEV_PLATE_COLOR_GRAY_E = 2,            /* 灰色 */
    NETDEV_PLATE_COLOR_RED_E = 3,             /* 红色 */
    NETDEV_PLATE_COLOR_BLUE_E = 4,            /* 蓝色 */
    NETDEV_PLATE_COLOR_YELLOW_E = 5,          /* 黄色 */
    NETDEV_PLATE_COLOR_ORANGE_E = 6,          /* 橙色 */
    NETDEV_PLATE_COLOR_BROWN_E = 7,           /* 棕色 */
    NETDEV_PLATE_COLOR_GREEN_E = 8,           /* 绿色 */
    NETDEV_PLATE_COLOR_PURPLE_E = 9,          /* 紫色 */
    NETDEV_PLATE_COLOR_CYAN_E = 10,           /* 青色 */
    NETDEV_PLATE_COLOR_PINK_E = 11,           /* 粉色 */
    NETDEV_PLATE_COLOR_TRANSPARENT_E = 12,    /* 透明 */
    NETDEV_PLATE_COLOR_OTHER_E = 99,          /* 其他 */

    NETDEV_PLATE_COLOR_INVALID = 0xFF         /* 无效值  Invalid value */
}NETDEV_PLATE_COLOR_E;

/**
* @enum tagNETDEVPlateType
* @brief 车牌类型 枚举定义 plate type Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVPlateType
{
    NETDEV_PLATE_TYPE_BIG_CAR_E = 0,                     /* 大型汽车号牌 */
    NETDEV_PLATE_TYPE_MINI_CAR_E = 1,                    /* 小型汽车号牌 */
    NETDEV_PLATE_TYPE_EMBASSY_CAR_E = 2,                 /* 使馆汽车号牌 */
    NETDEV_PLATE_TYPE_CONSULATE_CAR_E = 3,               /* 领馆汽车号牌 */
    NETDEV_PLATE_TYPE_OVERSEAS_CAR_E = 4,                /* 境外汽车号牌 */
    NETDEV_PLATE_TYPE_FOREIGN_CAR_E = 5,                 /* 外籍汽车号牌 */
    NETDEV_PLATE_TYPE_COMMON_MOTORBIKE_E = 6,            /* 普通摩托车号牌 */
    NETDEV_PLATE_TYPE_HANDINESS_MOTORBIKE_E = 7,         /* 轻便摩托车号牌 */
    NETDEV_PLATE_TYPE_EMBASSY_MOTORBIKE_E = 8,           /* 使馆摩托车号牌 */
    NETDEV_PLATE_TYPE_CONSULATE_MOTORBIKE_E = 9,         /* 领馆摩托车号牌 */
    NETDEV_PLATE_TYPE_OVERSEAS_MOTORBIKE_E = 10,         /* 境外摩托车号牌 */
    NETDEV_PLATE_TYPE_FOREIGN_MOTORBIKE_E = 11,          /* 外籍摩托车号牌 */
    NETDEV_PLATE_TYPE_LOW_SPEED_CAR_E = 12,              /* 低速车号牌 */
    NETDEV_PLATE_TYPE_TRACTOR_E = 13,                    /* 拖拉机号牌 */
    NETDEV_PLATE_TYPE_TRAILER_E = 14,                    /* 挂车号牌 */
    NETDEV_PLATE_TYPE_COACH_CAR_E = 15,                  /* 教练汽车号牌 */
    NETDEV_PLATE_TYPE_COACH_MOTORBIKE_E = 16,            /* 教练摩托车号牌 */
    NETDEV_PLATE_TYPE_TEMPORARY_ENTRY_CAR_E = 17,        /* 临时入境汽车号牌 */
    NETDEV_PLATE_TYPE_TEMPORARY_ENTRY_MOTORBIKE_E = 18,  /* 临时入境摩托车号牌 */
    NETDEV_PLATE_TYPE_TEMPORARY_DRIVING_E = 19,          /* 临时行驶车号牌 */
    NETDEV_PLATE_TYPE_POLICE_CAR_E = 20,                 /* 警用汽车号牌 */
    NETDEV_PLATE_TYPE_POLICE_MOTORBIKE_E = 21,           /* 警用摩托车号牌 */
    NETDEV_PLATE_TYPE_AGRICULTURAL_E = 22,               /* 原农机号牌 */
    NETDEV_PLATE_TYPE_HONGKONG_ENTRY_EXIT_E = 23,        /* 香港入出境号牌 */
    NETDEV_PLATE_TYPE_MACAO_ENTRY_EXIT_E = 24,           /* 澳门入出境号牌 */
    NETDEV_PLATE_TYPE_ARMED_POLICE_E = 25,               /* 武警号牌 */
    NETDEV_PLATE_TYPE_ARMY_E = 26,                       /* 军队号牌 */

    NETDEV_PLATE_TYPE_OTHER_E = 99,                      /* 其他号牌 */


    NETDEV_PLATE_TYPE_INVALID = 0xFF                     /* 无效值  Invalid value */
}NETDEV_PLATE_TYPE_E;

/**
* @enum tagNETDEVVehicleColor
* @brief 车辆颜色 枚举定义 plate color Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVehicleColor
{
    NETDEV_VEHICLE_COLOR_BLACK_E          = 0,        /* 黑色 */
    NETDEV_VEHICLE_COLOR_WHITE_E          = 1,        /* 白色 */
    NETDEV_VEHICLE_COLOR_GRAY_E           = 2,        /* 灰色 */
    NETDEV_VEHICLE_COLOR_RED_E            = 3,        /* 红色 */
    NETDEV_VEHICLE_COLOR_BLUE_E           = 4,        /* 蓝色 */
    NETDEV_VEHICLE_COLOR_YELLOW_E         = 5,        /* 黄色 */
    NETDEV_VEHICLE_COLOR_ORANGE_E         = 6,        /* 橙色 */
    NETDEV_VEHICLE_COLOR_BROWN_E          = 7,        /* 棕色 */
    NETDEV_VEHICLE_COLOR_GREEN_E          = 8,        /* 绿色 */
    NETDEV_VEHICLE_COLOR_PURPLE_E         = 9,        /* 紫色 */
    NETDEV_VEHICLE_COLOR_CYAN_E           = 10,       /* 青色 */
    NETDEV_VEHICLE_COLOR_PINK_E           = 11,       /* 粉色 */
    NETDEV_VEHICLE_COLOR_TRANSPARENT_E    = 12,       /* 透明 */
    NETDEV_VEHICLE_COLOR_OTHER_E          = 99,       /* 其他 */

    NETDEV_VEHICLE_COLOR_INVALID        = 0xFF      /* 无效值  Invalid value */
}NETDEV_VEHICLE_COLOR_E;

/**
* @enum tagNETDEVVehicleType
* @brief 车辆类型 枚举定义 plate type Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVehicleType
{
    NETDEV_VEHICLE_TYPE_TRICYCLE_E = 0,           /* 三轮车 */
    NETDEV_VEHICLE_TYPE_MOTOR_BUS_E = 1,          /* 大客车 */

    NETDEV_VEHICLE_TYPE_OTHER_E = 999,            /* 其他 */

    NETDEV_VEHICLE_TYPE_INVALID = 0xFFFF          /* 无效值  Invalid value */
}NETDEV_VEHICLE_TYPE_E;


/**
* @enum tagNETDEVVehicleSpeedUnit
* @brief 车辆速度单位 枚举定义 vehicle speed unit Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVehicleSpeedUnit
{
    NETDEV_VEHICLE_SPEED_UNIT_KPH_E = 0,                /* 公里/每小时 */
    NETDEV_VEHICLE_SPEED_UNIT_MPH_E = 1,                /* 英里/每小时 */

    NETDEV_VEHICLE_SPEED_UNIT_INVALID = 0xFF            /* 无效值  Invalid value */
}NETDEV_VEHICLE_SPEED_UNIT_E;


/**
 * @enum tagNETDEVAlarmType
 * @brief  告警类型 枚举定义 Alarm Type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmTypeLAPI
{
/*               IPC&VMS                                           */
  NETDEV_MOTION_ALARM_ON                        = 0,    /* 运动检测告警 */
  NETDEV_MOTION_ALARM_OFF                       = 1,    /* 运动检测告警恢复 */
  NETDEV_MASK_IMAGE_ALARM_ON                    = 2,    /* 遮挡侦测告警 */
  NETDEV_MASK_IMAGE_ALARM_OFF                   = 3,    /* 遮挡侦测告警恢复 */
  NETDEV_ABNORMAL_AUDIO_ON                      = 4,    /* 音频异常检测告警 */
  NETDEV_ABNORMAL_AUDIO_OFF                     = 5,    /* 音频异常检测告警恢复 */
  NETDEV_LINE_DETECTOR_CROSSED                  = 6,    /* 越界告警 */
  NETDEV_FIELD_DETECTOR_OBJECTS_INSIDE          = 7,    /* 区域入侵 */
  NETDEV_OBJECT_IS_RECOGNIZED                   = 8,    /* 人脸识别 */
  NETDEV_GLOBAL_SCENE_CHANGE                    = 9,    /* 场景变更 */
  NETDEV_IMAGE_TOO_BLURRY_ON                    = 10,   /* 图像虚焦 */
  NETDEV_IMAGE_TOO_BLURRY_OFF                   = 11,   /* 图像虚焦告警恢复 */
  NETDEV_INPUT_ALARM_ON                         = 12,   /* 输入开关量告警 */
  NETDEV_INPUT_ALARM_OFF                        = 13,   /* 输入开关量告警恢复 */

  NETDEV_ENTER_AREA                             = 100,  /* 进入区域 */
  NETDEV_LEAVE_AREA                             = 101,  /* 离开区域 */
  NETDEV_LOITERING                              = 102,  /* 区域徘徊 */
  NETDEV_FENCE_CROSSING                         = 103,  /* 翻越围栏 */
  NETDEV_OBJECT_REMOVED                         = 104,  /* 物品看护 */
  NETDEV_OBJECT_LEFT_BEHIND                     = 105,  /* 物品遗留 */
  NETDEV_PEOPLE_GATHERING                       = 106,  /* 人员聚集 */
  NETDEV_PEOPLE_GATHERING_CLEARED               = 107,  /* 人员聚集恢复 */
  NETDEV_FAST_MOVING                            = 108,  /* 快速移动 */
  NETDEV_PARKING                                = 109,  /* 停车 */
  NETDEV_HEAT_MAP                               = 110,  /* 热度图 */

  NETDEV_DISK_OFFLINE                           = 201,  /* 磁盘下线告警 */
  NETDEV_DISK_ABNORMAL                          = 202,  /* 磁盘错误异常告警 */
  NETDEV_ILLEGAL_LOGIN                          = 203,  /* 非法访问 */
  NETDEV_NETWORK_DISCONNECTED                   = 204,  /* 网络断开异常告警 */
  NETDEV_NETWORK_DISCONNECTED_CLEARED           = 205,  /* 网络断开恢复告警 */
  NETDEV_IP_CONFLICT                            = 206,  /* IP冲突异常告警 */
  NETDEV_IP_CONFLICT_CLEARED                    = 207,  /* IP冲突异常告警恢复 */
  NETDEV_STORAGE_FAILURE                        = 208,  /* 存储错误告警 */
  NETDEV_RUNNING_OUT_OF_RECORDING_SPACE         = 209,  /* 存储即将满告警 */
  NETDEV_RECORDING_SAPCE_USED_UP                = 210,  /* 存储满告警 */
  NETDEV_DEVICE_ONLINE                          = 211,  /* 设备上线告警 */
  NETDEV_DEVICE_OFFLINE                         = 212,  /* 设备下线告警 */
  NETDEV_RAID_DISABLED                          = 213,  /* 阵列损坏告警 */
  NETDEV_DISK_ONLINE                            = 214,  /* 磁盘上线告警 */
  NETDEV_RAID_DEGRADED                          = 215,  /* 阵列衰退告警 */
  NETDEV_RAID_RECOVERED                         = 216,  /* 阵列恢复正常 */
  NETDEV_MANUAL_ALARM                           = 217,  /* 手动告警 */
  NETDEV_VIDEO_LOSS_ALARM_ON                    = 218,  /* 视频丢失告警 */
  NETDEV_VIDEO_LOSS_ALARM_OFF                   = 219,  /* 视频丢失告警恢复 */
  NETDEV_SCHEDULED_RECORDING_FAILURE            = 220,  /* 未按计划存储 */
  NETDEV_SCHEDULED_RECORDING_FAILURE_CLEARED    = 221,  /* 未按计划存储恢复 */
  NETDEV_IPC_ONLINE                             = 222,  /* 上线 */
  NETDEV_IPC_OFFLINE                            = 223,  /* 下线 */
  NETDEV_CHANNEL_DELETED                        = 224,  /* 删除*/
  NETDEV_CONTROL_PANEL_ALARM                    = 225,  /* 告警主机告警 */
  NETDEV_ACCESS_CONTROL_ALARM                   = 226,  /* 门禁主机告警 */

  /* Smart信息 */
  NETDEV_SMART_READ_ERROR_RATE                  = 227,  /* 底层数据读取错误率 */
  NETDEV_SMART_SPIN_UP_TIME                     = 228,  /*  主轴起旋时间  */
  NETDEV_SMART_START_STOP_COUNT                 = 229,  /* 启停计数 */
  NETDEV_SMART_REALLOCATED_SECTOR_COUNT         = 230,  /* 重映射扇区计数  */
  NETDEV_SMART_SEEK_ERROR_RATE                  = 231,  /* 寻道错误率 */
  NETDEV_SMART_POWER_ON_HOURS                   = 232,  /* 通电时间累计，出厂后通电的总时间，一般磁盘寿命三万小时 */
  NETDEV_SMART_SPIN_RETRY_COUNT                 = 233,  /* 主轴起旋重试次数 */
  NETDEV_SMART_CALIBRATION_RETRY_COUNT          = 234,  /* 磁头校准重试计数 */
  NETDEV_SMART_POWER_CYCLE_COUNT                = 235,  /* 通电周期计数 */
  NETDEV_SMART_POWEROFF_RETRACT_COUNT           = 236,  /* 断电返回计数 */
  NETDEV_SMART_LOAD_CYCLE_COUNT                 = 237,  /* 磁头加载计数 */
  NETDEV_SMART_TEMPERATURE_CELSIUS              = 238,  /* 温度 */
  NETDEV_SMART_REALLOCATED_EVENT_COUNT          = 239,  /* 重映射事件计数 */
  NETDEV_SMART_CURRENT_PENDING_SECTOR           = 240,  /* 当前待映射扇区计数 */
  NETDEV_SMART_OFFLINE_UNCORRECTABLE            = 241,  /* 脱机无法校正的扇区计数 */
  NETDEV_SMART_UDMA_CRC_ERROR_COUNT             = 242,  /* 奇偶校验错误率  */
  NETDEV_SMART_MULTI_ZONE_ERROR_RATE            = 243,  /* 多区域错误率 */

  NETDEV_SMART_FACE_NOT_MATCH_ALARM             = 244,  /* 人脸对比失败 */
  NETDEV_SMART_FACE_MATCH_ALARM                 = 245,  /* 人脸对比成功 */

  NETDEV_UNKOWN_TYPE_ALARM                      =0xFF   /* 未知告警类型 */

}NETDEV_ALARM_TYPE_LAPI_E;

/**
* @enum tagNETDEVVideoCodeMode
* @brief 视频编码模式 枚举定义  Video encoding Mode Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVVideoCodeMode
{
    NETDEV_VIDEO_CODE_MODE_CBR = 0,             /* 恒定比特率 */
    NETDEV_VIDEO_CODE_MODE_VBR = 1              /* 可变比特率 */
}NETDEV_VIDEO_CODE_MODE_E;

/**
* @enum tagNETDEVRecordPlanEnable
* @brief NVR 录像计划使能 枚举定义   NVR Record Plan Enable Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVRecordPlanEnable
{
    NETDEV_RECORD_Plan_DISABLE = 0,             /* 不使能 */
    NETDEV_RECORD_Plan_ENABLE = 1               /* 使能 */
}NETDEV_RECORD_Plan_ENABLE_E;

/**
* @enum tagNETDEVRedundantStorage
* @brief NVR 冗余存储计划使能 枚举定义   NVR Redundant Storage Plan Enable Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVRedundantStorage
{
    NETDEV_REDUNDANT_STORAGE_DISABLE = 0,             /* 不使能 */
    NETDEV_REDUNDANT_STORAGE_ENABLE = 1               /* 使能 */
}NETDEV_REDUNDANT_STORAGE_ENABLE_E; 

/**
* @enum tagResolution
* @brief 解码分辨率
* @attention  需要与 player_sdk_func.h中的 PLAYER_DECODE_RESOLUTION_E 一一对应 
*/
typedef enum tagNETDEVMemResolution
{
    NETDEV_MEM_RESOLUTION_CIF       = 0,                        /* CIF */
    NETDEV_MEM_RESOLUTION_2CIF      = 1,                        /* 2CIF */
    NETDEV_MEM_RESOLUTION_D1        = 2,                        /* D1 */
    NETDEV_MEM_RESOLUTION_720P      = 3,                        /* 720P */
    NETDEV_MEM_RESOLUTION_1080P     = 4,                        /* 1080P */
    NETDEV_MEM_RESOLUTION_4M        = 5,                        /* 4M */
    NETDEV_MEM_RESOLUTION_8M        = 6,                        /* 8M */
    NETDEV_MEM_RESOLUTION_12M       = 7,                        /* 12M */
    NETDEV_MEM_RESOLUTION_MAX
}NETDEV_MEM_RESOLUTION_E;

/**
* @enum tagDecodePayload
* @brief 解码分辨率
* @attention 需要与 player_sdk_func.h中的 PLAYER_DECODE_PAYLOAD_E 一一对应 
*/
typedef enum tagNETDEVMemPayload
{
    NETDEV_MEM_PAYLOAD_H264         = 0,                           /* H264 */
    NETDEV_MEM_PAYLOAD_H265         = 1,                           /* H265 */
    NETDEV_MEM_PAYLOAD_INVALID      = 0xff
}NETDEV_MEM_PAYLOAD_E;


/**
 * @enum tagNETDEVPLanStoreType
 * @brief 录像存储类型 枚举定义 Recording storage type Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVPLanStoreType
{
    NETDEV_STORE_TYPE_COMMON                        = 0,                /* 常规存储 */  
    NETDEV_STORE_TYPE_DIGITIALINPUT                 = 1,                /* 开关量输入告警存储 */
    NETDEV_STORE_TYPE_MANUL                         = 2,                /* 手动存储 */
    NETDEV_STORE_TYPE_AUDIODETECT                   = 3,                /* 音频检测告警存储 */
    NETDEV_STORE_TYPE_MOTION                        = 4,                /* 运动检测告警存储 */
    NETDEV_STORE_TYPE_DIGITALINPUT                  = 5,                /* 数字输入事件存储  Digital input */
    NETDEV_STORE_TYPE_FACEDETECT                    = 6,                /* 人脸检测告警存储 */
    NETDEV_STORE_TYPE_VIDEO_LOSS                    = 7,                /* 视频丢失存储 */
    NETDEV_STORE_TYPE_LINEDETECT                    = 8,                /* 越界检测告警存储 */
    NETDEV_STORE_TYPE_FIELDDETECT                   = 9,                /* 区域入侵检测告警存储 */
    NETDEV_STORE_TYPE_FOCUSDETECT                   = 10,               /* 图像虚焦告警存储 */
    NETDEV_STORE_TYPE_SCENECHANGE                   = 11,               /* 场景变更告警存储 */
    NETDEV_STORE_TYPE_ALARM                         = 12,               /* 告警 */
    NETDEV_STORE_TYPE_ALARM_AND_MOTION              = 13,               /* 运动检测 和 告警 */
    NETDEV_STORE_TYPE_ALARM_OR_MOTION               = 14,               /* 运动检测 或 告警 */
    NETDEV_STORE_TYPE_CAMERA_DISCONNECT             = 15,               /* 监控点断线 */
    NETDEV_STORE_TYPE_THIRD_STREAM                  = 16,               /* 第三流存储 */
    NETDEV_STORE_TYPE_EVENT_ALL_ALARM               = 17,               /* 事件类型录像，包涵所有告警类型 */
    NETDEV_STORE_TYPE_EVENT_ALL_TYPE                = 18,               /* 事件类型录像，包涵所有录像类型 */
    NETDEV_PLAN_STORE_TYPE_EVENT_WITHOUT_RESUME     = 19,               /* 没有恢复的事件类型存储 */
    NETDEV_PLAN_STORE_TYPE_MAX                      = 20,               /* 存储类型最大值 */

    NETDEV_STORE_TYPE_INVALID                       = 0xFF              /* 无效值 */
}NETDEV_STORE_TYPE_E;

/**
* @struct tagSysType
* @brief 系统类型。
* @attention 需要与 player_sdk_func.h中的 PLAYER_DECODE_SYSTYPE_E 一一对应 
*/
typedef enum tagNETDEVMenSystem
{
    NETDEV_SYSTEM_WIN7      = 0,                    /* WIN7 */
    NETDEV_SYSTEM_WIN8      = 1,                    /* WIN8 */
    NETDEV_SYSTEM_WIN10     = 2                     /* WIN10 */
}NETDEV_MEM_SYSTEM_E;

/**
* @enum tagNETDEVEventStoreType
* @brief 录像事件存储类型 枚举定义
* @attention 增加枚举时注意更新全局变量gaRecordType
*/
typedef enum tagNETDEVEventStoreType
{
    NETDEV_EVENT_STORE_FIND_TYPE_NORMAL             = 1,      /* 常规存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_MOTIONDETEC        = 2,      /* 运动检测告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_DIGITIALINPUT      = 3,      /* 开关量输入告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_MANUAL             = 4,      /* 手动存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_SIGNALLOSS         = 5,      /* 视频丢失存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_AUDIODETECT        = 6,      /* 音频检测告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_FACEDETECT         = 7,      /* 人脸检测告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_LINEDETECT         = 8,      /* 越界检测告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_FIELDDETECT        = 9,      /* 区域入侵检测告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_FOCUSDETECT        = 10,     /* 图像虚焦告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_SCENECHANGE        = 11,     /* 场景变更告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_SMARTTRACK         = 12,     /* 智能跟踪告警存储 */
    NETDEV_EVENT_STORE_FIND_TYPE_BUTT
}NETDEV_EVENT_STORE_TYPE_E;

/**
* @enum tagNETDEVSmartStoreType
* @brief 录像事件存储类型 枚举定义
* @attention 枚举值不能够和NETDEV_EVENT_STORE_TYPE_E中的枚举重复
*/
typedef enum tagNETDEVSmartStoreType
{
    NETDEV_SMART_STORE_FIND_TYPE_MOTIONSMART      = 100,   /* 运动检测智能数据存储 */
    NETDEV_SMART_STORE_FIND_TYPE_BUTT
}NETDEV_SMART_STORE_TYPE_E;


/**
* @enum tagNETDEVEventFindLogic
* @brief 录像事件告警查询类型与或 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVEventFindLogic
{
    NETDEV_EVENT_FIND_LOGIC_AND = 0,     /* 逻辑与 */
    NETDEV_EVENT_FIND_LOGIC_OR  = 1,     /* 逻辑或 */
    NETDEV_EVENT_FIND_LOGIC_BUTT
}NETDEV_EVENT_FIND_LOGIC_E;



/**
* @enum tagNETDEVTransportModeType
* @brief 传输模式 枚举定义
* @attention 无
*/
typedef enum tagNETDEVTransportModeType
{
    NETDEV_TRANSPROTOCAL_RTP_UNICAST    = 0,
    NETDEV_TRANSPROTOCAL_RTP_MULTICAST  = 1,
    NETDEV_TRANSPROTOCAL_RTP_STORE      = 2

}NETDEV_TRANSPORTMODE_E;

/**
* @enum tagNETDEVAudioFlag
* @brief 音频数据类型 枚举定义 Audio data type Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVAudioFlag
{
    NETDEV_AUDIO_LOCAL_GATHERED = 0,               /* 本地采集的数据  Locally collected data*/
    NETDEV_AUDIO_DEVICE_SEND    = 1                /* 设备发送过来的语音数据  Audio data sent from device */
} NETDEV_AUDIO_FLAG_E;

/**
* @enum tagNETDEVEventTypeMajor
* @brief 事件主类型 枚举定义 Major types of event Enumeration definition
* @attention 无 None
*/
typedef enum tagNETDEVEventTypeMajor
{
    NETDEV_EVENT_TYPE_MAJOR_ALARM      = 0,          /* 告警 事件类型 CORE其他模块向CORE告警模块订阅 */
    NETDEV_EVENT_TYPE_MAJOR_SYS        = 1,          /* 系统相关事件类型 */
    NETDEV_EVENT_TYPE_MAJOR_PERI_WARN  = 2,          /* 驱动外设事件 CORE告警模块单独向驱动订阅 */
    NETDEV_EVENT_TYPE_MAJOR_MEDIA      = 3,          /* 媒体处理相关事件 */
    NETDEV_EVENT_TYPE_MAJOR_BUTT
}NETDEV_EVENT_TYPE_MAJOR_E;

/**
* @enum tagNETDEVDecPaneNum
* @brief DC支持分屏数 
* @attention DC&&XW公用枚举 None
*/
typedef enum tagNETDEVDecPaneNum
{
    NETDEV_DEC_PANE_ONE             = 1,                /* 1分屏 */
    NETDEV_DEC_PANE_TWO             = 2,                /* 2分屏 */
    NETDEV_DEC_PANE_THREE           = 3,                /* 3分屏 */
    NETDEV_DEC_PANE_FOUR            = 4,                /* 4分屏 */
    NETDEV_DEC_PANE_FIVE            = 5,                /* 5分屏 */
    NETDEV_DEC_PANE_SIX             = 6,                /* 6分屏 */
    NETDEV_DEC_PANE_SEVEN           = 7,                /* 7分屏 */
    NETDEV_DEC_PANE_EIGHT           = 8,                /* 8分屏 */
    NETDEV_DEC_PANE_NINE            = 9,                /* 9分屏 */
    NETDEV_DEC_PANE_SIXTEEN         = 16,               /* 16分屏 */
    NETDEV_DEC_PANE_TWENTYFIVE      = 25,               /* 25分屏 */
    NETDEV_DEC_PANE_THIRTYSIX       = 36,               /* 36分屏 */
    NETDEV_DEC_PANE_SIXTYFOUR       = 64,               /* 64分屏 */

    NETDEV_DEC_PANE_INVALID         = 0xffff
}NETDEV_PANE_NUM_E;


/**
 * @enum tagNETDEVOSDTextType
 * @brief 
 * @attention 无 None
 */
typedef enum tagNETDEVOSDTextType
{
    NETDEV_OSD_TEXT_DATAANDTIME = 0,            /* 日期.时间, 如yyyy-MM-dd.HH:mm:ss, 日期格式参见#NETDEV_OSD_DATE_FORMAT_CAP_E, 时间格式参见#NETDEV_OSD_TIME_FORMAT_CAP_E */
    NETDEV_OSD_TEXT_PLAIN
}NETDEV_OSD_TEXT_TYPE_E;


/**
 * @enum tagNETDEVAlarmPortType
 * @brief 告警监听端口类型
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmPortType
{
    NETDEV_ALARM_PORT_TYPE_LOCAL = 0,            /* 本地监听端口 */
    NETDEV_ALARM_PORT_TYPE_NAT = 1               /* 端口映射后的事件端口 */
}NETDEV_ALARM_PORT_TYPE_E;



/**
* @enum tagNETDEVFaceAnalysisSkill
* @brief 人脸质量优先类型 枚举定义
* @attention 无
*/
typedef enum tagNETDEVFaceAnalysisSkill
{
    NETDEV_FACE_ANALYSIS_SKILL_AGE                 = 0,            /* 年龄 */
    NETDEV_FACE_ANALYSIS_SKILL_GENGER              = 1,            /* 性别 */
    NETDEV_FACE_ANALYSIS_SKILL_RACE                = 2,            /* 种族 */
    NETDEV_FACE_ANALYSIS_SKILL_GLASSES             = 3,            /* 眼镜 */
    NETDEV_FACE_ANALYSIS_SKILL_MASK                = 4,            /* 口罩 */
    NETDEV_FACE_ANALYSIS_SKILL_MUSTACHE            = 5,            /* 胡子 */
    NETDEV_FACE_ANALYSIS_SKILL_HAT                 = 6,            /* 帽子 */
    NETDEV_FACE_ANALYSIS_SKILL_HAIRSTYLE           = 7,            /* 发型 */
    NETDEV_FACE_ANALYSIS_SKILL_EXPRESSION          = 8,            /* 表情 */
    NETDEV_FACE_ANALYSIS_SKILL_FACE                = 9             /* 颜值 */
}NETDEV_FACE_ANALYSIS_SKILL_E;

/**
* @enum tagNETDEVFaceRecognitionType
* @brief 人脸识别类型 枚举定义
* @attention 无
*/
typedef enum tagNETDEVFaceRecognitionType
{
    NETDEV_FACE_RECOGNITION_TYPE_FRONT              = 0,            /* 前端人脸识别 */
    NETDEV_FACE_RECOGNITION_TYPE_CENTER             = 1            /* 中心人脸识别 */

}NETDEV_FACE_RECOGNITION_TYPE_E;



/**
* @enum tagNETDEVObjTracktModeType
* @brief 跟踪模式 枚举定义
* @attention 无
*/
typedef enum tagNETDEVObjTracktModeType
{
    NETDEV_OBJ_TRACK_MODE_FULLVIEW  = 1,                /* 全景模式 */
    NETDEV_OBJ_TRACK_MODE_CRUISE    = 2                /* 巡航跟踪 */
}NETDEV_OBJ_TRACK_MODE_E;


/* 升级状态 */
typedef enum tagNETDEVDeviceUpgradeStatus
{
    NETDEV_UPGRADE_STATUS_INITING        = 0,       /* 初始化中 */
    NETDEV_UPGRADE_STATUS_QUERYING       = 1,       /* 查询中 */
    NETDEV_UPGRADE_STATUS_DOWNLOADING    = 2,       /* 下载中 */
    NETDEV_UPGRADE_STATUS_TRANSMITTING   = 3,       /* 传输中 */
    NETDEV_UPGRADE_STATUS_UPGRATING      = 4,       /* 升级中 */
    NETDEV_UPGRADE_STATUS_UPGRATEERROR   = 5,       /* 升级出错 */
    NETDEV_UPGRADE_STATUS_NEWEST         = 6,       /* 已是最新版本 */
    NETDEV_UPGRADE_STATUS_HAVEHIGHTER    = 7,       /* 有更高版本 */
    NETDEV_UPGRADE_STATUS_UPGRADEOVER    = 8,       /* 升级完成 */
    NETDEV_UPGRADE_STATUS_GETSTATUSFAIL  = 9,       /* 获取升级进度失败 */
    NETDEV_UPGRADE_STATUS_NOTMATCH       = 10,      /* 版本不匹配 */
    NETDEV_UPGRADE_STATUS_NOTMUTIPROCESS = 11,      /* 不能同时加载多个升级进程 */
    NETDEV_UPGRADE_STATUS_UPGRADETIMEOUT = 12,      /* 获取升级进度超时*/
    NETDEV_UPGRADE_STATUS_BUTT
}NETDEV_UPGRADE_STATUS_E;

/* 升级状态 */
typedef enum tagNETDEVUpgradeType
{
    NETDEV_UPGRADE_TYPE_CLOUD    = 1,               /* 云升级 */
    NETDEV_UPGRADE_TYPE_UDISK    = 2,               /* U盘升级 */
    NETDEV_UPGRADE_TYPE_LOCAL    = 3,               /* 本地升级 */
    NETDEV_UPGRADE_TYPE_BUTT
}NETDEV_UPGRADE_TYPE_E;



/* 音频编码格式类型枚举 */
typedef enum tagNETDEVAudioEncodeFormatType
{
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_MPEG1           = 0,       /* MPEG1 */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_G711A           = 1,       /* G.711A */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_G711U           = 2,       /* G.711U */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_ADPCM           = 3,       /* ADPCM */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_OGG             = 4,       /* OGG */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_Auto            = 5,       /* Auto */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_AACLC           = 6,       /* AAC-LC */
    NETDEV_AUDIO_ENCODE_FORMAT_TYPE_INVALID         = 0xFF     /* 无效值 */
}NETDEV_AUDIO_ENCODE_FORMAT_TYPE_E;

/* 音频采样率枚举 */
typedef enum tagNETDEVAudioSamplingRate
{
    NETDEV_AUDIO_SAMPLING_RATE_8KHZ             = 0,       /* 8KHz */
    NETDEV_AUDIO_SAMPLING_RATE_16KHZ            = 1,       /* 16KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_22_05KHZ         = 2,       /* 22.05KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_24KHZ            = 3,       /* 24KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_32KHZ            = 4,       /* 32KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_44_1KHZ          = 5,       /* 44.1KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_48KHZ            = 6,       /* 48KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_96KHZ            = 7,       /* 96KHZ */
    NETDEV_AUDIO_SAMPLING_RATE_INVALID          = 0xFF     /* 无效值 */
}NETDEV_AUDIO_SAMPLING_RATE_E;

/* 音频输入模式枚举 */
typedef enum tagNETDEVAudioInChlMode
{
    NETDEV_AUDIO_CHL_MODE_LINE              = 0,        /* LINE */
    NETDEV_AUDIO_CHL_MODE_MIC               = 1,        /*  MIC */
    NETDEV_AUDIO_CHL_MODE_RS485             = 2,        /* RS485数字拾音器 */
    NETDEV_AUDIO_CHL_MODE_INVALID           = 0xFF      /* 无效值 */
}NETDEV_AUDIO_CHL_MODE_E;

/* 音频采集口枚举 */
typedef enum tagNETDEVAudioCollectionPortType
{
    NETDEV_AUDIO_COLLECTION_PORT_TYPE_AUDIO_IN              = 0,        /* 音频输入口 */
    NETDEV_AUDIO_COLLECTION_PORT_TYPE_SERIAL_IN             = 1,        /* 串口 */
    NETDEV_AUDIO_COLLECTION_PORT_TYPE_INVALID               = 0xFF      /* 无效值 */
}NETDEV_AUDIO_COLLECTION_PORT_TYPE_E;


/**
 * @enum tagNETDEVWeekPlanEvent
 * @brief 周计划事件枚举
 * @attention 无 None
 */
typedef enum tagNETDEVWeekPlanEvent
{
    NETDEV_WEEK_PLAN_EVENT_MOTION_DETECT    = 1,               /* 运动检测 */
    NETDEV_WEEK_PLAN_EVENT_AUDIO_DETECT     = 2,               /* 声音检测 */
    NETDEV_WEEK_PLAN_EVENT_TAMPER_DETECT    = 3,               /* 遮挡检测 */
    NETDEV_WEEK_PLAN_EVENT_INPUT_SWITCH     = 4,               /* 开关量输入 */
    NETDEV_WEEK_PLAN_EVENT_OUTPUT_SWITCH    = 5,               /* 开关量输出 */
    NETDEV_WEEK_PLAN_EVENT_CROSS_LINE       = 6,               /* 越界检测 */
    NETDEV_WEEK_PLAN_EVENT_INTROSION_ZONE   = 7,               /* 区域入侵 */
    NETDEV_WEEK_PLAN_EVENT_ACCESS_ZONE      = 8,               /* 进入区域 */
    NETDEV_WEEK_PLAN_EVENT_LEAVE_ZONE       = 9,               /* 离开区域 */
    NETDEV_WEEK_PLAN_EVENT_HOVER_ZONE       = 10,              /* 徘徊检测 */
    NETDEV_WEEK_PLAN_EVENT_CARE_ARTICLE     = 11,              /* 物品搬移 */
    NETDEV_WEEK_PLAN_EVENT_REMAIN_ARTICLE   = 12,              /* 物品遗留 */
    NETDEV_WEEK_PLAN_EVENT_GATHER           = 13,              /* 人员聚集 */
    NETDEV_WEEK_PLAN_EVENT_FASTMOVE         = 14,              /* 快速移动 */
    NETDEV_WEEK_PLAN_EVENT_CAR_STOP         = 15,              /* 停车检测 */
    NETDEV_WEEK_PLAN_EVENT_OUT_FOCUS        = 16,              /* 虚焦检测 */
    NETDEV_WEEK_PLAN_EVENT_SCENCECHANGE     = 17,              /* 场景变更 */
    NETDEV_WEEK_PLAN_EVENT_FACE_DETECT      = 18,              /* 人脸检测 */
    NETDEV_WEEK_PLAN_EVENT_ROAD_DETECT      = 19,              /* 道路监控 */
    NETDEV_WEEK_PLAN_EVENT_PEOPLE_COUNT     = 20,              /* 客流量 */
    NETDEV_WEEK_PLAN_EVENT_HEATMAP          = 21,              /* 热度图 */
    NETDEV_WEEK_PLAN_EVENT_SD_STORAGE       = 22               /* SD卡存储 */
}NETDEV_WEEK_PLAN_EVENT_E;


/**
* @enum tagNetDEVFishEyePtzMode
* @brief 鱼眼设备矫正模式枚举变量
* @attention 无
*/
typedef enum tagNetDEVFishEyePtzMode
{
    NETDEV_FISHEYE_MODE_ORIGINAL            = 0,                /* 原始图像 */
    NETDEV_FISHEYE_MODE_180                 = 1,                /* 2*180度模式 */
    NETDEV_FISHEYE_MODE_360_1PTZ            = 2,                /* 360度+1PTZ模式 */
    NETDEV_FISHEYE_MODE_360_6PTZ            = 3,                /* 360度+6PTZ模式 */
    NETDEV_FISHEYE_MODE_3PTZ                = 4,                /* 鱼眼+3PTZ模式 */
    NETDEV_FISHEYE_MODE_MID_ON_4PTZ         = 5,                /* 鱼眼图像在中间且显示+4PTZ模式 */
    NETDEV_FISHEYE_MODE_MID_OFF_4PTZ        = 6,                /* 鱼眼图像在中间但不显示+4PTZ模式 */
    NETDEV_FISHEYE_MODE_LEFT_4PTZ           = 7,                /* 鱼眼左边+4PTZ模式 */
    NETDEV_FISHEYE_MODE_8PTZ                = 8,                /* 鱼眼+8PTZ模式 */
    NETDEV_FISHEYE_MODE_PANORAMA            = 9,                /* 全景模式 */
    NETDEV_FISHEYE_MODE_PR_3PTZ             = 10,               /* 全景+3PTZ模式 */
    NETDEV_FISHEYE_MODE_PR_4PTZ             = 11,               /* 全景+4PTZ模式 */
    NETDEV_FISHEYE_MODE_PR_8PTZ             = 12,               /* 全景+8PTZ模式 */

    NETDEV_FISHEYE_MODE_INVALID             = 0xFF             /* 非法值 */
}NETDEV_FISHEYE_PTZ_MODE_E;

/**
* @enum tagNETDEVfInstallMode
* @brief 设备安装模式
* @attention 无
*/
typedef enum tagNETDEVfInstallMode
{
    NETDEV_INSTALL_MODE_TOP             = 0,            /* 顶部安装 */
    NETDEV_INSTALL_MODE_BOTTOM          = 1,            /* 底部安装 */
    NETDEV_INSTALL_MODE_SIDE            = 2,            /* 侧面安装 */

    NETDEV_INSTALL_MODE_INVALID         = 0xFF          /* 非法值 */
}NETDEV_INSTALL_MODE_E;

/**
* @enum tagNETDEVfMouseMoveMode
* @brief 鼠标移动模式
* @attention 无
*/
typedef enum tagNETDEVfMouseMoveMode
{
    NETDEV_MOUSE_MOVE                   = 0,            /* 鼠标位移 */
    NETDEV_MOUSE_LEFT_BTN_DOWN          = 1,            /* 左键按下 */
    NETDEV_MOUSE_LEFT_BTN_UP            = 2,            /* 左键弹起 */
    NETDEV_MOUSE_WHEEL                  = 3,            /* 滚轮操作 */

    NETDEV_MOUSE_INVALID                = 0xFF          /* 非法值 */
}NETDEV_MOUSE_MOVE_MODE_E;

/**
 * @enum tagNETDEVFindAlarmTypeEn
 * @brief 告警配置操作 枚举定义  Alarm configuration operation Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVFindAlarmTypeEn
{
    NETDEV_FIND_ALARM_DISK_STORAGE_IS_FULL               = 1,            /* 存储满 */
    NETDEV_FIND_ALARM_DISK_STORAGE_WILL_FULL             = 2,            /* 存储即将满 */
    NETDEV_FIND_ALARM_STOR_ERR                           = 3,            /* 存储错误 */
    NETDEV_FIND_ALARM_STOR_ERR_RECOVER                   = 4,            /* 存储错误恢复 */
    NETDEV_FIND_ALARM_MOVE_DETECT                        = 5,            /* 运动检测告警 */
    NETDEV_FIND_ALARM_MOVE_DETECT_RECOVER                = 6,            /* 运动检测告警恢复 */
    NETDEV_FIND_ALARM_VIDEO_TAMPER_DETECT                = 7,            /* 遮挡侦测告警 */
    NETDEV_FIND_ALARM_VIDEO_TAMPER_RECOVER               = 8,            /* 遮挡侦测告警恢复 */
    NETDEV_FIND_ALARM_INPUT_SWITCH                       = 9,            /* 输入开关量告警 */
    NETDEV_FIND_ALARM_INPUT_SWITCH_RECOVER               = 10,           /* 输入开关量告警恢复*/
    NETDEV_FIND_ALARM_BAND_CHANGE                        = 11,           /* 设备出口带宽变更 */
    NETDEV_FIND_ALARM_IMAGE_BLURRY                       = 12,           /* 图像虚焦 */
    NETDEV_FIND_ALARM_IMAGE_BLURRY_RECOVER               = 13,           /* 阵列损坏 */
    NETDEV_FIND_ALARM_SCENE_CHANGE                       = 14,           /* 阵列衰退 */
    NETDEV_FIND_ALARM_ILLEGAL_ACCESS                     = 15,           /* 阵列恢复正常 */
    NETDEV_FIND_ALARM_REPORT_DEV_ONLINE                  = 16,           /* 设备上线 */
    NETDEV_FIND_ALARM_REPORT_DEV_OFFLINE                 = 17,           /* 设备下线 */
    NETDEV_FIND_ALARM_REPORT_DEV_VIDEO_LOSS              = 18,           /* 视频丢失 */
    NETDEV_FIND_ALARM_REPORT_DEV_VIDEO_LOSS_RECOVER      = 19,           /* 视频丢失恢复 */
    NETDEV_FIND_ALARM_COUNT_PEOPLE                       = 20,           /* 人数统计 */
    NETDEV_FIND_ALARM_HEAT_MAP                           = 21,           /* 热度图 */
    NETDEV_FIND_ALARM_LINE_DETECTOR                      = 22,           /* 伴线告警 */
    NETDEV_FIND_ALARM_CELL_MOTION                        = 23,           /* 智能运动检测 */
    NETDEV_FIND_ALARM_LINE_CROSS                         = 24,           /* 越界告警 */
    NETDEV_FIND_ALARM_OBJECTS_INSIDE                     = 25,           /* 区域入侵 */
    NETDEV_FIND_ALARM_ACCESSZONE                         = 26,           /* 进入区域告警 */
    NETDEV_FIND_ALARM_LEAVE_ZONE                         = 27,           /* 离开区域告警 */
    NETDEV_FIND_ALARM_HOVER_ZONE                         = 28,           /* 区域徘徊告警 */
    NETDEV_FIND_ALARM_OVER_ZONE                          = 29,           /* 翻越围栏告警 */
    NETDEV_FIND_ALARM_CARE_ARTICLE                       = 30,           /* 物品看护告警 */
    NETDEV_FIND_ALARM_REMAIN_ARTICLE                     = 31,           /* 物品遗留告警 */
    NETDEV_FIND_ALARM_FACE_DETECTOR                      = 32,           /* 人脸检测 */
    NETDEV_FIND_ALARM_GATHER                             = 33,           /* 人员聚集告警 */
    NETDEV_FIND_ALARM_GATHER_RECOVER                     = 34,           /* 人员聚集告警恢复 */
    NETDEV_FIND_ALARM_FAST_MOVE                          = 35,           /* 快速移动 */
    NETDEV_FIND_ALARM_ILLEGAL_PARKED                     = 36,           /* 违法停车告警 */

    NETDEV_FIND_ALARM_INVALID                            = 0xFFFF        /* 无效值  Invalid value */
}NETDEV_FIND_ALARM_TYPE_E;


/**
* @enum tagNETDEVWndNameDisplay
* @brief 窗口名称显示属性 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVWndNameDisplay
{
    NETDEV_WND_NAME_HIDE    = 0,        /* 窗口名称隐藏 */
    NETDEV_WND_NAME_SHOW    = 1     /* 窗口名称显示 */
} NETDEV_WND_NAME_DISPLAY_E;

/**
* @enum tagNETDEVOperatedMode
* @brief 操作模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVOperatedMode
{
    NETDEV_SPLIT_SCREEN_RECOVER    = 0,               /* 恢复到分屏显示 */
    NETDEV_SPLIT_SCREEN_ZOOM       = 1                /* 某个分屏放大到全窗口大小 */
} NETDEV_OPERATED_MODE_E;

 /**
 * @enum tagNETDEVNATType
 * @brief NAT类型枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVNATType
{
    NETDEV_STUN_TYPE_UNKNOWN                 = 0,       /* 未识别 */
    NETDEV_STUN_TYPE_FAILURE                 = 1,       /* 失败 */
    NETDEV_STUN_TYPE_OPEN                    = 2,       /* 没有NAT，公共IP，没有防火墙 */
    NETDEV_STUN_TYPE_BLOCKED                 = 3,       /* UDP受阻 */
    NETDEV_STUN_TYPE_CONE_NAT                = 4,       /* 完全NAT */
    NETDEV_STUN_TYPE_RESTRICTED_NAT          = 5,       /* 受限NAT */
    NETDEV_STUN_TYPE_PORT_RESTRICTED_NAT     = 6,       /* 端口受限NAT */
    NETDEV_STUN_TYPE_SYM_NAT                 = 7,       /* 对称NAT */
    NETDEV_STUN_TYPE_SYM_FIREWALL            = 8        /* 没有NAT，公共IP，但是对称的UDP防火墙 */
}NETDEV_NAT_TYPE_E;


/**
* @enum tagNetDevFaceIDLengthType
* @brief 人脸识别特征ID的数据结构长度
* @attention 无
*/
typedef enum tagNetDevFaceIDLengthType
{
    NETDEV_FACE_IDLENGTH_TYPE_0      = 0,            /*  0 */
    NETDEV_FACE_IDLENGTH_TYPE_2      = 2,            /*  2 */
    NETDEV_FACE_IDLENGTH_TYPE_4      = 4,            /*  4 */
    NETDEV_FACE_IDLENGTH_TYPE_8      = 8             /*  8 */

}NETDEV_FACE_IDLENGTH_TYPE_E;

/**
 * @enum tagNETDEVFaceDBType
 * @brief 人脸库类型
 * @attention 无 None
 */
typedef enum tagNETDEVFaceDBType
{
    NETDEV_FACE_DB_TYPE_BLACK       = 0,        /* 黑名单 */
    NETDEV_FACE_DB_TYPE_WHITE       = 1,        /* 白名单 */
    NETDEV_FACE_DB_TYPE_GRAY        = 2,        /* 灰名单 */

    NETDEV_FACER_DB_TYPE_INVALID    = 0xFF      /* 无效值 */
}NETDEV_FACE_DB_TYPE_E;


/**
* @enum tagNETDEVImageRotationMode
* @brief 图像镜像模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVImageRotationMode
{
    NETDEV_IMAGE_ROTATION_MODE_NORMAL       = 0,            /* 正常 */
    NETDEV_IMAGE_ROTATION_MODE_V_FLIPPING   = 1,            /* 垂直翻转 */
    NETDEV_IMAGE_ROTATION_MODE_H_FLIPPING   = 2,            /* 水平翻转 */
    NETDEV_IMAGE_ROTATION_MODE_HV           = 3,            /* 水平+垂直 (顺时针180度) */
    NETDEV_IMAGE_ROTATION_MODE_SPIN90_RIGHT = 4,            /* 右旋90度(顺时针90度) */
    NETDEV_IMAGE_ROTATION_MODE_SPIN90_LEFT  = 5,            /* 左旋90度(顺时针270度) */

    NETDEV_IMAGE_ROTATION_MODE_INVALID      = 0xFF          /* 无效值 */
}NETDEV_IMAGE_ROTATION_MODE_E;

/**
* @enum tagNETDEVExposureMode
* @brief 曝光模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVExposureMode
{
    NETDEV_EXPOSURE_MODE_AUTOMATIC          = 0,               /* 自动曝光 */
    NETDEV_EXPOSURE_MODE_CUSTOM             = 1,               /* 自定义曝光 */
    NETDEV_EXPOSURE_MODE_SHUTTER_PRIORITY   = 2,               /* 快门优先 */
    NETDEV_EXPOSURE_MODE_APERTURE_PRIORITY  = 3,               /* 光圈优先 */
    NETDEV_EXPOSURE_MODE_GAIN_PRIORITY      = 4,               /* 增益优先 */
    NETDEV_EXPOSURE_MODE_INDOOR_50_HZ       = 5,               /* 室内50Hz */
    NETDEV_EXPOSURE_MODE_INDOOR_60_HZ       = 6,               /* 室内60Hz */
    NETDEV_EXPOSURE_MODE_MANUAL_OPERATION   = 7,               /* 手动曝光 */
    NETDEV_EXPOSURE_MODE_LOWER_GHOSTING     = 8,               /* 低拖影 */

    NETDEV_EXPOSURE_MODE_INVALID            = 0xFF              /* 无效值 */
}NETDEV_EXPOSURE_MODE_E;

/**
* @enum tagNETDEVLampType
* @brief 补光灯类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVLampType
{
    NETDEV_LAMP_TYPE_WITHOUT            = 0,        /* 无补光灯*/
    NETDEV_LAMP_TYPE_WHITE              = 1,        /* 白光灯 */
    NETDEV_LAMP_TYPE_INFRARED           = 2,        /* 红外灯 */
    NETDEV_LAMP_TYPE_LASER_DEVICE       = 3,        /* 激光器*/
    NETDEV_LAMP_TYPE_INFRARED_SHIELD    = 4,        /* 红外护罩灯*/

    NETDEV_LAMP_TYPE_INVALID            = 0xFF      /* 无效值 */
}NETDEV_LAMP_TYPE_E;

/**
* @enum tagNETDEVLampCtrlMode
* @brief 补光灯支持的控制模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVLampCtrlMode
{
    NETDEV_LCM_GLOBAL_ATTENTION_AC      = 0,        /* 全局兼顾自动控制*/
    NETDEV_LCM_OVEREXPOSE_INHIBIT_AC    = 1,        /* 过曝抑制自动控制 */
    NETDEV_LCM_PRESET_RCM               = 2,        /* 预置控制-道路模式 */
    NETDEV_LCM_MANUAL_CM                = 3,        /* 手动控制模式*/
    NETDEV_LCM_PRESET_PCM               = 4,        /* 预置控制-园区模式*/
    NETDEV_LCM_PHOTOSENS_AM             = 5,        /* 光敏自动模式*/
    NETDEV_LCM_INDOOR_AM                = 6,        /* 室内自动模式*/
    NETDEV_LCM_MANUAL_FOM               = 7,        /* 手动-强制开启模式*/
    NETDEV_LCM_NIGHT_VIDEO_DET_MODE     = 8,        /* 夜间视频检测模式*/

    NETDEV_LCM_INVALID                  = 0xFF      /* 无效值 */
}NETDEV_LAMP_CTRL_MODE_E;


/**
* @enum tagNETDEVShutterTimeRange
* @brief 快门时间支持的取值 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVShutterTimeRange
{
    NETDEV_SHUTTER_TIME_AUTOMATIC   = 0,            /* 快门时间为自动*/
    NETDEV_SHUTTER_TIME_1           = 1,            /* 1/1 */
    NETDEV_SHUTTER_TIME_1_2         = 2,            /* 1/2 */
    NETDEV_SHUTTER_TIME_1_3         = 3,            /* 1/3 */
    NETDEV_SHUTTER_TIME_1_4         = 4,            /* 1/4 */
    NETDEV_SHUTTER_TIME_1_6         = 6,            /* 1/6 */
    NETDEV_SHUTTER_TIME_1_8         = 8,            /* 1/8 */
    NETDEV_SHUTTER_TIME_1_10        = 10,           /* 1/10*/
    NETDEV_SHUTTER_TIME_1_12        = 12,           /* 1/12*/
    NETDEV_SHUTTER_TIME_1_15        = 15,           /* 1/15*/
    NETDEV_SHUTTER_TIME_1_20        = 20,           /* 1/20*/
    NETDEV_SHUTTER_TIME_1_25        = 25,           /* 1/25*/
    NETDEV_SHUTTER_TIME_1_30        = 30,           /* 1/30*/
    NETDEV_SHUTTER_TIME_1_50        = 50,           /* 1/50*/
    NETDEV_SHUTTER_TIME_1_60        = 60,           /* 1/60*/
    NETDEV_SHUTTER_TIME_1_100       = 100,          /* 1/100*/
    NETDEV_SHUTTER_TIME_1_120       = 120,          /* 1/120*/
    NETDEV_SHUTTER_TIME_1_150       = 150,          /* 1/150*/
    NETDEV_SHUTTER_TIME_1_180       = 180,          /* 1/180*/
    NETDEV_SHUTTER_TIME_1_200       = 200,          /* 1/200*/
    NETDEV_SHUTTER_TIME_1_250       = 250,          /* 1/250*/
    NETDEV_SHUTTER_TIME_1_500       = 500,          /* 1/500*/
    NETDEV_SHUTTER_TIME_1_1000      = 1000,         /* 1/1000*/
    NETDEV_SHUTTER_TIME_1_2000      = 2000,         /* 1/2000*/
    NETDEV_SHUTTER_TIME_1_4000      = 4000,         /* 1/4000*/
    NETDEV_SHUTTER_TIME_1_8000      = 8000,         /* 1/8000*/
    NETDEV_SHUTTER_TIME_1_50000     = 50000,        /* 1/50000*/
    NETDEV_SHUTTER_TIME_1_100000    = 100000,       /* 1/100000*/

    NETDEV_SHUTTER_TIME_INVALID = 0xFF                  /* 无效值 */
}NETDEV_SHUTTER_TIME_RANGE_E;

/**
* @enum tagNETDEVWideDynamicMode
* @brief 测光控制模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVWideDynamicMode
{
    NETDEV_WDM_CLOSED   = 0,    /* 关闭*/
    NETDEV_WDM_OPEN     = 1,    /* 开启*/
    NETDEV_WDM_AUTO     = 2,    /* 自动*/

    NETDEV_WDM_INVALID  = 0xFF  /* 无效值 */
}NETDEV_WIDE_DYNAMIC_MODE_E;

/**
* @enum tagNETDEVMeteringMode
* @brief 测光控制模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVMeteringMode
{
    NETDEV_METER_MODE_CENTRAL_WEIGHT    = 0,        /* 中央权重*/
    NETDEV_METER_MODE_AREA_METER        = 1,        /* 区域测光*/
    NETDEV_METER_MODE_SLIGHT_INHIBIT    = 2,        /* 强光抑制*/
    NETDEV_METER_MODE_VEHICLE_METER     = 3,        /* 车辆测光*/
    NETDEV_METER_MODE_FACE_METER        = 4,        /* 人脸测光*/
    NETDEV_METER_MODE_SPOT_METER        = 5,        /* 点测光*/

    NETDEV_METER_MODE_INVALID           = 0xFF      /* 无效值 */
}NETDEV_METER_MODE_E;

/**
* @enum tagNETDEVLampType
* @brief 昼夜模式类型 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVDayNightMode
{
    NETDEV_DNM_AUTO                     = 0,        /* 自动模式*/
    NETDEV_DNM_DAY_COLOR                = 1,        /* 白天--彩色 */
    NETDEV_DNM_NIGHT_BAW                = 2,        /* 夜晚--黑白 */
    NETDEV_DNM_LINK_COLOR_TO_BLACK      = 3,        /* 联动彩转黑*/

    NETDEV_DNM_INVALID                  = 0xFF      /* 无效值 */
}NETDEV_DAY_NIGHT_MODE_E;

/**
* @enum tagNETDEVFocusModel
* @brief 对焦模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVFocusModel
{
    NETDEV_FOCUS_MODEL_AUTO             = 0,        /* 自动对焦*/
    NETDEV_FOCUS_MODEL_MANUAL           = 1,        /* 手动对焦 */
    NETDEV_FOCUS_MODEL_A_KEY_FOCUS      = 2,        /* 一键对焦：设备在云台进行转动、变倍、调用预置位等操作时触发一次自动聚焦。 */
    NETDEV_FOCUS_MODEL_INFRARED_NIGHT   = 3,        /* 一键对焦（夜间红外）可见光较微弱的低照环境（比如夜间或室内低照等），开启红外灯后使用此对焦模式效果较好。*/
    NETDEV_FOCUS_MODEL_LOCK             = 4,        /* 一键对焦（锁定）只在设备变倍结束后进行一次自动聚焦，其它动作都无法触发对焦。*/
    NETDEV_FOCUS_MODEL_INVALID          = 0xFF      /* 无效值 */
}NETDEV_FOCUS_MODEL_E;

/**
* @enum tagNETDEVFocusScene
* @brief 对焦场景 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVFocusScene
{
    NETDEV_FOCUS_SCENE_ROUTINE          = 0,        /* 常规*/
    NETDEV_FOCUS_SCENE_LONG_OBJDIST     = 1,        /* 超远物距 */
    NETDEV_FOCUS_SCENE_INDOOR_MODEL     = 2,        /* 室内模式 */
    NETDEV_FOCUS_SCENE_INVALID          = 0xFF      /* 无效值 */
}NETDEV_FOCUS_SCENE_E;

/**
* @enum tagNETDEVWhiteBalance
* @brief 白平衡模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVWhiteBalance
{
    NETDEV_WBM_AUTO                         = 0,        /*自动模式*/
    NETDEV_WBM_TRIMMING                     = 1,        /*微调模式*/
    NETDEV_WBM_INDOOR                       = 2,        /*室内模式*/
    NETDEV_WBM_OUTDOOR                      = 3,        /*室外模式*/
    NETDEV_WBM_AUTO_MERCURY_LAMP            = 4,        /*自动水银灯模式*/
    NETDEV_WBM_NIGHT_TRIMMING               = 5,        /*夜间微调模式*/
    NETDEV_WBM_AUTO_NA_LAMP                 = 6,        /*自动钠灯模式*/
    NETDEV_WBM_LOCK                         = 7,        /*锁定模式*/
    NETDEV_WBM_SELF_ADAPT_NIGHT_TRIMMING    = 8,        /*自适应夜间微调模式*/
    NETDEV_WBM_AUTO_SECOND                  = 9,        /*自动模式2*/
    NETDEV_WBM_INVALID                      = 0xFF      /* 无效值 */
}NETDEV_WHITE_BALANCE_MODE_E;

/**
 * @enum tagNETDEVXWComType
 * @brief 串口类型
 * @attention 无 None      目前仅支持使用0 和 4
 */
typedef enum tagNETDEVXWComType
{
    NETDEV_XW_COM_TYPE_RS232                    = 0,               /* 232串口 */
    NETDEV_XW_COM_TYPE_RS422HALFDUPLEX          = 1,               /* 422 目前不支持 */
    NETDEV_XW_COM_TYPE_RS422FULLDUPLEX          = 2,               /* 422 目前不支持 */
    NETDEV_XW_COM_TYPE_RS485HALFDUPLEX          = 3,               /* 485 目前不支持 */
    NETDEV_XW_COM_TYPE_RS485FULLDUPLEX          = 4,
    NETDEV_XW_COM_TYPE_GENERIC                  = 5,               /* 目前不支持 */

    NETDEV_XW_COM_TYPE_INVALID                  = 0xFF             /* 无效值 */
}NETDEV_XW_COM_TYPE_E;

/* 流业务类型 */
typedef enum tagNETDEVVideoType
{
    NETDEV_PLAYBACK_REMOTE  = 0,        /* 远端回放 */
    NETDEV_REALPLAY_REMOTE  = 1,        /* 远端实况 */
    NETDEV_REALPLAY_LOCAL   = 2,        /* 本地实况 */
    NETDEV_SEQUENCE_PANE    = 3,        /* 单分屏轮巡 暂未实现*/
    NETDEV_SEQUENCE_WND     = 4,        /* 窗口轮巡 */
    NETDEV_REALPLAY_ALARM   = 5         /* 告警联动实况 */
}NETDEV_XW_VIDEO_TYPE_E;

typedef enum tagNETDEV_PASSIVEDECODE_CMD
{
    PASSIVE_DEC_PAUSE       = 1,   /* 被动解码暂停(仅文件流有效) */
    PASSIVE_DEC_RESUME      = 2,   /* 恢复被动解码(仅文件流有效) */
    PASSIVE_DEC_FAST        = 3,   /* 快速被动解码(仅文件流有效) */
    PASSIVE_DEC_SLOW        = 4,   /* 慢速被动解码(仅文件流有效) */
    PASSIVE_DEC_NORMAL      = 5,   /* 正常被动解码(仅文件流有效) */
    PASSIVE_DEC_ONEBYONE    = 6,   /* 被动解码单帧播放(保留) */
    PASSIVE_DEC_AUDIO_ON    = 7,   /* 音频开启 */
    PASSIVE_DEC_AUDIO_OFF   = 8,   /* 音频关闭 */
    PASSIVE_DEC_RESETBUFFER = 9    /* 清空缓冲区 */
}NETDEV_PASSIVEDECODE_CMD_E;

/* 轮巡状态 */
typedef enum tagNETDEVXWSequenceStatusType
{
    NETDEV_SEQUENCE_STATUS_RUNNING  = 0,        /* 正常运行 */ 
    NETDEV_SEQUENCE_STATUS_PAUSE    = 1,        /* 暂停 */ 
    NETDEV_SEQUENCE_STATUS_INVALID  = 0xff
}NETDEV_XW_SEQUENCE_STATUS_E;

/* 轮巡控制命令 */
typedef enum tagNETDEVXWSequenceCtrlCmd
{
    NETDEV_SEQUENCE_CTRL_CMD_STOP       = 0,        /* 停止 */ 
    NETDEV_SEQUENCE_CTRL_CMD_START      = 1,        /* 启动 */ 
    NETDEV_SEQUENCE_CTRL_CMD_PAUSE      = 2,        /* 暂停 */ 
    NETDEV_SEQUENCE_CTRL_CMD_RECOVER    = 3,        /* 恢复 */ 
    NETDEV_SEQUENCE_CTRL_CMD_PREVIOUS   = 4,        /* 上一屏 */ 
    NETDEV_SEQUENCE_CTRL_CMD_NEXT       = 5,        /* 下一屏 */ 
    NETDEV_SEQUENCE_CTRL_CMD_INVALID    = 0xff
}NETDEV_XW_SEQUENCE_CTRL_CMD_E;

/**
 * @enum tagNETDEVXWWndStreamStatus
 * @brief 建流状态
 * @attention
 */
typedef enum tagNETDEVXWWndStreamStatus
{
    NETDEV_XW_STREAM_STATUS_NO                  = 0,          /*未建流*/
    NETDEV_XW_STREAM_STATUS_SUCCESS             = 1,          /*建流成功*/
    NETDEV_XW_STREAM_STATUS_STREAMING           = 2,          /*建流中*/
    NETDEV_XW_STREAM_STATUS_RESTREAM            = 3,          /*重建流*/
    NETDEV_XW_STREAM_STATUS_FAILED              = 4,          /*建流失败*/
    NETDEV_XW_STREAM_STATUS_CAP_NOT_ENOUGHT     = 5,          /*解码能力不足*/

    NETDEV_XW_STREAM_STATUS_INVALID             = 0xFF        /* 无效值 */
}NETDEV_XW_WND_STREAM_STATUS_E;

/**
* @enum tagNETDEVXWSequencePlayControlCmd
* @brief 轮巡播放控制 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVXWSequencePlayControlCmd
{
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_STOP       = 0,        /* 停止 */
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_START      = 1,        /* 启动 */
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_PAUSE      = 2,        /* 暂停 */
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_RESUME     = 3,        /* 恢复 */
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_PAGEUP     = 4,        /* 上一屏 */
    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_PAGEDOWN   = 5,        /* 下一屏 */

    NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_INVALID    = 0xFF      /* 无效值 */
}NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_E;

/**
* @enum tagNETDEVXWScenesPlanMode
* @brief 场景轮巡计划模式 枚举定义
* @attention 无 None
*/
typedef enum tagNETDEVXWScenesPlanMode
{
    NETDEV_XW_SCENES_PLAN_MODE_TIMER       = 0,            /* 定时切换 */
    NETDEV_XW_SCENES_PLAN_MODE_TIME_TABLE  = 1,            /* 按时间表切换 24小时计划表 */

    NETDEV_XW_SCENES_PLAN_MODE_INVALID     = 0xFF          /* 无效值 */
}NETDEV_XW_SCENES_PLAN_MODE_E;


/**
* @enum tagNETDEVHDDStorageFullStrategy
* @brief 硬盘存储满之后采用的策略
* @attention 
*/
typedef enum tagNETDEVHDDStorageFullStrategy
{
    NETDEV_HDD_STORAGE_FULL_STRATEGY_COVER      = 0,        /* 满覆盖 */
    NETDEV_HDD_STORAGE_FULL_STRATEGY_STOP       = 1,        /* 满停止 */

    NETDEV_HDD_STORAGE_FULL_STRATEGY_INVALID    = 0XFF      /* 无效值 */
}NETDEV_HDD_STORAGE_FULL_STRATEGY_E;



/**
* @enum tagNETDEVCertificateType
* @brief 证件类型
* @attention 无 None
*/
typedef enum tagNETDEVCertificateType
{
    NETDEV_CERTIFICATE_TYPE_ID                  = 0,        /*0:身份证 */
    NETDEV_CERTIFICATE_TYPE_IC                  = 1,        /* 1:IC卡 */
    NETDEV_CERTIFICATE_TYPE_PASSPORT            = 2,        /* 2:护照 */
    NETDEV_CERTIFICATE_TYPE_DRIVING_LICENSE     = 3,        /* 3:行驶证 */
    NETDEV_CERTIFICATE_TYPE_OTHER               = 99,       /* 99:其他 */
    NETDEV_CERTIFICATE_TYPE_INVALID             = 0xFF      /* 无效值 */
}NETDEV_ID_TYPE_E;

/**
* @enum tagNETDEVPeopleLibType
* @brief 人员库类型
* @attention 无 None
*/
typedef enum tagNETDEVPeopleLibType
{
    NETDEV_PEOPLE_LIB_TYPE_DEFAULT      = 0,        /* 默认无效值 */
    NETDEV_PEOPLE_LIB_TYPE_BLACKLIST    = 1,        /* 黑名单 */
    NETDEV_PEOPLE_LIB_TYPE_STRANGER     = 2,        /* 灰名单/陌生人 */
    NETDEV_PEOPLE_LIB_TYPE_STAFF        = 3,        /* 员工 */
    NETDEV_PEOPLE_LIB_TYPE_VISITOR      = 4,        /* 访客 */
    NETDEV_PEOPLE_LIB_TYPE_INVALID      = 0xFF      /* 无效值 */
}NETDEV_PEOPLE_LIB_TYPE_E;

/**
* @enum tagNETDEVSubType
* @brief 订阅类型
* @attention 无 None
*/
typedef enum tagNETDEVSubType
{
    NETDEV_SUB_TYPE_FACE_COLLECTION = 0,                             /* 人脸采集 */
    NETDEV_SUB_TYPE_PERSON_CHECK    = 1,                             /* 人员核验 */
    NETDEV_SUB_TYPE_TYPE_INVALID    = 0xFF                           /* 无效值 */
}NETDEV_SUB_TYPE_E;

/**
* @enum tagNETDEVSmartAlarmType
* @brief 智能告警类型
* @attention 无
*/
typedef enum tagNETDEVSmartAlarmType
{
    NETDEV_SMART_ALARM_TYPE_FACE_SNAP      = 0,             /* 人脸识别抓图 */
    NETDEV_SMART_ALARM_TYPE_VEHICLE_SNAP   = 1,             /* 车牌识别抓图 */
    NETDEV_SMART_ALARM_TYPE_INVALID        = 0xFF           /* 无效值 */
}NETDEV_SMART_ALARM_TYPE_E;

/**
* @enum tagNETDEVSearchType
* @brief 人脸查找类型
* @attention 无
*/
typedef enum tagNETDEVSearchType
{
    NETDEV_SEARCH_TYPE_FACE        = 0,             /* 人脸检索 */
    NETDEV_SEARCH_TYPE_FACE_COMPARE_SUCCESS = 1,    /* 人脸比对成功  */
    NETDEV_SEARCH_TYPE_FACE_COMPARE_FAIL    = 2,    /* 人脸比对失败  */

    NETDEV_SEARCH_TYPE_INVALID              = 0xff  /* 无效值 */
}NETDEV_SEARCH_TYPE_E;


/**
 * @enum tagNETDEVQueryCondType
 * @brief 查询条件类型
 * @attention 无 None
 */
typedef enum tagNETDEVQueryCondType
{
    NETDEV_QUERYCOND_USERNAME          = 0,                /* 查询条件：用户名称 */
    NETDEV_QUERYCOND_ORGNAME           = 1,                /* 查询条件：组织名称 */
    NETDEV_QUERYCOND_DEVNAME           = 2,                /* 查询条件：设备名称 */
    NETDEV_QUERYCOND_CHNNAME           = 3,                /* 查询条件：通道名称 */
    NETDEV_QUERYCOND_TIME              = 4,                /* 查询条件：时间 */
    NETDEV_QUERYCOND_BUSINESSTYPE      = 5,                /* 查询条件：业务类型 */
    NETDEV_QUERYCOND_OPERATETYPE       = 6,                /* 查询条件：操作类型 */
    NETDEV_QUERYCOND_OPEROBJECT        = 7,                /* 查询条件：操作对象 */
    NETDEV_QUERYCOND_ALARMTYPE         = 8,                /* 查询条件：告警类型 参见枚举NETDEV_ALARM_SUBTYPE_E*/
    NETDEV_QUERYCOND_ALARMSRCNAME      = 9,                /* 查询条件：告警源名称 */
    NETDEV_QUERYCOND_ALARMLEVEL        = 10,               /* 查询条件：告警级别 */
    NETDEV_QUERYCOND_ALARMCHECKED      = 11,               /* 查询条件：告警是否确认 */
    NETDEV_QUERYCOND_ALARMCHECKUSER    = 12,               /* 查询条件：告警确认用户 */
    NETDEV_QUERYCOND_ALARMCHECKTIME    = 13,               /* 查询条件：告警确认时间 */
    NETDEV_QUERYCOND_ALARM_DEVID       = 14,               /* 查询条件：告警设备ID */
    NETDEV_QUERYCOND_ALARM_CHNID       = 15,               /* 查询条件：告警通道ID */
    NETDEV_QUERYCOND_ALARM_SUBTYPE     = 16,               /* 查询条件：告警子类型 */
    NETDEV_QUERYCOND_ALARM_SERVER      = 17,               /* 查询条件：归属服务器 */
    NETDEV_QUERYCOND_DOOR_NUM          = 18,               /* 查询条件：门编号 */
    NETDEV_QUERYCOND_CARD_NUM          = 19,               /* 查询条件：卡号 */
    NETDEV_QUERYCOND_ALARM_GENDER      = 20,               /* 查询条件：性别 */
    NETDEV_QUERYCOND_ALARM_BIRTHDAY    = 21,               /* 查询条件：出生年月 */
    NETDEV_QUERYCOND_MONITOY_REASON    = 22,               /* 查询条件：布控原因 */
    NETDEV_QUERYCOND_PLATE_NUM         = 23,               /* 查询条件：车牌号码 */
    NETDEV_QUERYCOND_VEHICLE_TYPE      = 24,               /* 查询条件：车辆类型 */
    NETDEV_QUERYCOND_PLATE_COLOR       = 25,               /* 查询条件：车牌颜色 */
    NETDEV_QUERYCOND_VEHICLE_COLOR     = 26,               /* 查询条件：车身颜色 */
    NETDEV_QUERYCOND_PERSON_NUMBER     = 27,               /* 查询条件：员工编号*/
    NETDEV_QUERYCOND_PERSON_TYPE       = 28,               /* 查询条件：人员类型*/
    NETDEV_QUERYCOND_DIRECT            = 29,               /* 查询条件：方向*/
    NETDEV_DATABASE_ID                 = 38,               /* 查询条件：库ID */
    NETDEV_QUERY_TYPE_PLATECLASS       = 39,               /* 查询条件：车牌类型 */ 
    NETDEV_QUERYCOND_RANGE             = 40,               /* 查询条件：告警查询范围 0是设备，1是服务器*/
    NETDEV_QUERYCOND_BEGIN_TIME          = 41,             /* 查询条件：访客预约开始时间*/
    NETDEV_QUERYCOND_END_TIME            = 42,             /* 查询条件：访客预约结束时间*/
    NETDEV_QUERYCOND_INTERVIEWEE_NAME    = 43,             /* 查询条件：受访人姓名*/
    NETDEV_QUERYCOND_INTERVIEWEE_STATUS  = 44,             /* 查询条件：受访人状态*/
    NETDEV_QUERYCOND_PARK_NAME         = 45,               /* 查询条件：停车场名称 */
    NETDEV_QUERYCOND_CONFIDENCE_LEVEL  = 46,               /* 查询条件：置信度 */
    NETDEV_QUERYCOND_PARK_TIME         = 47,               /* 查询条件：停车时长 */
    NETDEV_QUERYCOND_CONTRACT_RULE     = 48,               /* 查询条件：包期规则 */
    NETDEV_QUERYCOND_PAYMENT_METHOD    = 49,               /* 查询条件：付款方式 */
    NETDEV_QUERYCOND_PASSING_DIRECTION = 50,               /* 查询条件：过车方向 */
    NETDEV_QUERYCOND_VEHICLE_ATTR      = 51,               /* 查询条件：车辆属性 */
    NETDEV_QUERYCOND_STATISTICS_UNITS  = 52,               /* 查询条件：统计单位 */
    NETDEV_QUERYCOND_EXITENTRANCE_NAME = 53,               /* 查询条件：出入口名称 */
    NETDEV_QUERYCOND_PICTURE_DATA      = 54,               /* 查询条件：图片数据 */
    NETDEV_QUERYCOND_PERSON_NAME       = 55,               /* 查询条件：人员姓名 */
    NETDEV_QUERYCOND_SIMILARITY        = 56,               /* 查询条件：相似度 */
    NETDEV_QUERYCOND_SEARCH_TYPE       = 57,               /* 查询条件：检索类型，参见枚举值NETDEV_SEARCH_TYPE_E */
    NETDEV_QUERYCOND_ID_NUMBER         = 58,               /* 查询条件：证件号 */

    NETDEV_QUERYCOND_INVALID             = 0xFF             /* 无效 */
}NETDEV_QUERYCOND_TYPE_E;

/**
 * @enum tagNETDEVQueryCondLogic
 * @brief 查询条件逻辑类型
 * @attention 无 None
 */
typedef enum tagNETDEVQueryCondLogic
{
    NETDEV_QUERYCOND_LOGIC_EQUAL             = 0,                /* 查询条件逻辑类型：等于 */
    NETDEV_QUERYCOND_LOGIC_GREATER           = 1,                /* 查询条件逻辑类型：大于 */
    NETDEV_QUERYCOND_LOGIC_LESS              = 2,                /* 查询条件逻辑类型：小于 */
    NETDEV_QUERYCOND_LOGIC_NO_LESS           = 3,                /* 查询条件逻辑类型：不小于 */
    NETDEV_QUERYCOND_LOGIC_NO_GREATER        = 4,                /* 查询条件逻辑类型：不大于 */
    NETDEV_QUERYCOND_LOGIC_NO_EQUAL          = 5,                /* 查询条件逻辑类型：不等于 */
    NETDEV_QUERYCOND_LOGIC_DIM_QUERY         = 6,                /* 查询条件逻辑类型：模糊查询 */
    NETDEV_QUERYCOND_LOGIC_CONTAIN           = 7,                /* 查询条件逻辑类型：包括 */
    NETDEV_QUERYCOND_LOGIC_ASC_ORDER         = 8,                /* 查询条件逻辑类型：升序 */
    NETDEV_QUERYCOND_LOGIC_DESC_ORDER        = 9                 /* 查询条件逻辑类型：降序 */
}NETDEV_QUERYCOND_LOGICTYPE_E;

/**
* @enum tagNETDEVFaceMatchAlarmType
* @brief 人脸抓拍匹配告警枚举
* @attention 无
*/
typedef enum tagNETDEVFaceMatchAlarmType
{
    NETDEV_FACE_MATCH_TYPE_SNAPSHOT      = 1,               /* 人脸抓拍 */
    NETDEV_FACE_MATCH_ALARM              = 2,               /* 人脸匹配告警 */
    NETDEV_FACE_NOT_MATCH_ALARM          = 4,               /* 人脸不匹配告警 */

    NETDEV_FACET_MATCH_TYPE_INVALID     = 0xFF              /* 无效值 */
}NETDEV_FACE_MATCH_ALARM_TYPE_E;

/* 录像标签错误码 */
typedef enum tagNETDEVRecodeLabelResult
{
    NETDEV_RECODE_LABEL_SUCCESS     = 0,        /* 成功 */
    NETDEV_RECODE_LABEL_FAIL_MAX    = 1,        /* 标签数量达到达到最大值 */
    NETDEV_RECODE_LABEL_FAIL_OTHER  = 2         /* 其他错误 */
}NETDEV_RECODE_LABEL_RESULT_E;


typedef enum tagNETDEVAccessProtocol
{
    NETDEV_ACCESS_PROTOCOL_ONVIF                = 1,                /* onvif协议 */
    NETDEV_ACCESS_PROTOCOL_UNV                  = 2,                /* 私有协议 */
    NETDEV_ACCESS_PROTOCOL_GB                   = 3,                /* 国标 */

    NETDEV_ACCESS_PROTOCOL_INVALID              = 0xFF              /* 无效值 */
}NETDEV_ACCESS_PROTOCOL_E;

/**
 * @enum tagNETDEVVideoChnFindType
 * @brief 视频通道信息查找类型枚举
 * @attention 无 None
 */
typedef enum tagNETDEVVideoChnFindType
{
    NETDEV_VIDEO_CHN_FIND_TYPE_ALL              = 0,         /* 查找所有 */
    NETDEV_VIDEO_CHN_FIND_TYPE_DEV_ORG_ID       = 1,         /* 按指定组织ID和指定设备ID查找 */
    NETDEV_VIDEO_CHN_FIND_TYPE_DEV_ID           = 2,         /* 按指定设备ID查找 */
    NETDEV_VIDEO_CHN_FIND_TYPE_ORG_ID           = 3,         /* 按指定组织ID查找 */


    NETDEV_VIDEO_CHN_FIND_TYPE_INVALID          = 0XFF       /* 无效值 */
}NETDEV_VIDEO_CHN_FIND_TYPE_E;

/**
 * @enum tagNETDEVOrgFindMode
 * @brief 组织查找模式枚举
 * @attention 无 None
 */
typedef enum tagNETDEVOrgFindMode
{
    NETDEV_ORG_FIND_MODE_ID          = 0,            /* 组织ID */
    NETDEV_ORG_FIND_MODE_TYPE        = 1,            /* 组织类型 */


    NETDEV_ORG_FIND_MODE_INVALID            = 0XFF       /* 无效值 */
}NETDEV_ORG_FIND_MODE_E;

/**
 * @brief 设备子类型
 * @attention 无 None
 */
typedef enum tagNETDEVDeviceSubType
{
    NETDEV_DTYPE_SUB_NVR                = 0,                /* NVR */
    NETDEV_DTYPE_SUB_IPC                = 1,                /* IPC */
    NETDEV_DTYPE_SUB_DC_INNER           = 2,                /* 内置DC */ 
    NETDEV_DTYPE_SUB_DC_EXT             = 3,                /* 外置DC */
    NETDEV_DTYPE_SUB_EC                 = 4,                /* EC */
    NETDEV_DTYPE_SUB_VMS                = 5,                /* 一体机 */ 
    NETDEV_DTYPE_SUB_DA                 = 6,                /* 代理设备 */ 
    NETDEV_DTYPE_SUB_ADU                = 7,                /* ADU拼控设备 */
    NETDEV_DTYPE_SUB_FISHEYE_IPC        = 8,                /* 鱼眼设备 */
    NETDEV_DTYPE_SUB_DECARD             = 9,                /* 解码卡设备 */
    NETDEV_DTYPE_SUB_FACE_IPC           = 10,               /* 人脸识别相机 */
    NETDEV_DTYPE_SUB_ALARMHOST          = 11,               /* 报警主机设备 */
    NETDEV_DTYPE_SUB_ACS                = 12,               /* 门禁主机设备 */

    NETDEV_DTYPE_SUB_UNKNOW             = 0xFF              /* 未知设备 */
}NETDEV_DEVICE_SUB_TYPE_E;


/**
 * @enum tagNETDEVLayoutType
 * @brief 布局类型/分屏模式
 * @attention 无 None
 */
typedef enum tagNETDEVLayoutType
{
    /* Layout=aabb, aa代表分屏数 bb区分相同分屏数下不同的分屏类型 */

    NETDEV_LAYOUT_TYPE_01          =  100, /* 1      */
    NETDEV_LAYOUT_TYPE_02          =  200, /* 2      */
    NETDEV_LAYOUT_TYPE_03          =  300, /* 3      */
    NETDEV_LAYOUT_TYPE_04_1        =  400, /* 4      */
    NETDEV_LAYOUT_TYPE_04_2        =  401, /* 1+1+2  */
    NETDEV_LAYOUT_TYPE_05_1        =  500, /* 1+3+1   */
    NETDEV_LAYOUT_TYPE_05_2        =  501, /* 1+1+3   */
    NETDEV_LAYOUT_TYPE_06          =  600, /* 1+5    */
    NETDEV_LAYOUT_TYPE_07          =  700, /* 1+6    */
    NETDEV_LAYOUT_TYPE_08          =  800, /* 1+7    */
    NETDEV_LAYOUT_TYPE_09          =  900, /* 9      */
    NETDEV_LAYOUT_TYPE_10_1        = 1000, /* 1+9    */
    NETDEV_LAYOUT_TYPE_10_2        = 1001, /* 2+9    */
    NETDEV_LAYOUT_TYPE_13          = 1300, /* 1+12   */
    NETDEV_LAYOUT_TYPE_16          = 1600, /* 16     */
    NETDEV_LAYOUT_TYPE_17          = 1700, /* 1+16   */
    NETDEV_LAYOUT_TYPE_25          = 2500, /* 25     */
    NETDEV_LAYOUT_TYPE_32          = 3200, /* 3+1+28 */
    NETDEV_LAYOUT_TYPE_36          = 3600, /* 36     */
    NETDEV_LAYOUT_TYPE_64          = 6400, /* 64     */
	NETDEV_LAYOUT_TYPE_10001       = 10001,/* 自定义分屏1 */
    NETDEV_LAYOUT_TYPE_10002       = 10002,/* 自定义分屏2 */
    NETDEV_LAYOUT_TYPE_10003       = 10003,/* 自定义分屏3 */
    NETDEV_LAYOUT_TYPE_10004       = 10004,/* 自定义分屏4 */
    NETDEV_LAYOUT_TYPE_10005       = 10005,/* 自定义分屏5 */
    NETDEV_LAYOUT_TYPE_10006       = 10006,/* 自定义分屏6 */
    NETDEV_LAYOUT_TYPE_10007       = 10007,/* 自定义分屏7 */
    NETDEV_LAYOUT_TYPE_10008       = 10008,/* 自定义分屏8 */


    NETDEV_LAYOUT_TYPE_INVALID
}NETDEV_LAYOUT_TYPE_E;


/**
* @enum tagNETDEVDCSeqStatus
* @brief DC轮巡状态
* @attention 无 None
*/
typedef enum tagNETDEVDCSeqStatus
{
    NETDEV_DC_SEQSTATUS_START           = 0,            /* 轮巡执行状态：启动 */
    NETDEV_DC_SEQSTATUS_PAUSE           = 1,            /* 轮巡执行状态：暂停 */
    NETDEV_DC_SEQSTATUS_STOP            = 2,            /* 轮巡执行状态：停止 */

    NETDEV_DC_SEQSTATUS_INVALID         = 0xff          /* 无效值 */
}NETDEV_DC_SEQ_STATUS_E;


/**
 * @enum tagNETDEVDCVideoFormat
 * @brief DC 视频编码格式
 * @attention 无 None
 */
typedef enum tagNETDEVDCVideoFormat
{
    NETDEV_DC_VF_PAL        = 0,
    NETDEV_DC_VF_NTSC       = 1,
    NETDEV_DC_VF_720P24     = 2,
    NETDEV_DC_VF_720P25     = 3,
    NETDEV_DC_VF_720P30     = 4,
    NETDEV_DC_VF_720P50     = 5,
    NETDEV_DC_VF_720P60     = 6,
    NETDEV_DC_VF_1080I48    = 7,
    NETDEV_DC_VF_1080I50    = 8,
    NETDEV_DC_VF_1080I60    = 9,
    NETDEV_DC_VF_1080P24    = 10,
    NETDEV_DC_VF_1080P25    = 11,
    NETDEV_DC_VF_1080P30    = 12,
    NETDEV_DC_VF_1080P50    = 13,
    NETDEV_DC_VF_1080P60    = 14,
    NETDEV_DC_VF_XGA60      = 15,
    NETDEV_DC_VF_SXGA60     = 16,
    NETDEV_DC_VF_UXGA60     = 17,
    NETDEV_DC_VF_SXGAP60HZ  = 18,
    NETDEV_DC_VF_WXGAP60HZ  = 19,
    NETDEV_DC_VF_WSXGA60HZ  = 20,
    NETDEV_DC_VF_4K30       = 21,
    NETDEV_DC_VF_4K60       = 22,
    NETDEV_DC_VF_MUXGA60HZ  = 23,

    NETDEV_DC_VF_QXGA60     = 41,
    NETDEV_DC_VF_WQXGA60    = 42,
    NETDEV_DC_VF_4M60       = 43,
    
    NETDEV_DC_VF_INVALID    = 0xff
}NETDEV_DC_VIDEOFORMAT_E;

/**
 * @enum tagNETDEVAlarmPlanType
 * @brief 告警布防预案类型
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmPlanType
{
    NETDEV_ALARM_PLAN_TYPE_STORE        = 0,            /* 存储计划 */
    NETDEV_ALARM_PLAN_TYPE_BS           = 1,            /* B/S */
    NETDEV_ALARM_PLAN_TYPE_CS           = 2,            /* C/S */

    NETDEV_ALARM_PLAN_TYPE_INVALID      = 0xff          /* 无效值 */
}NETDEV_ALARM_PLAN_TYPE_E;
/**
 * @enum tagNETDEVPaneOperateType
 * @brief 告警布防预案类型
 * @attention 无 None
 */
typedef enum tagNETDEVPaneOperateType
{
    NETDEV_PANE_OPERATE_TYPE_BIND_CHANNEL        = 0,            /* 绑定通道 */
    NETDEV_PANE_OPERATE_TYPE_UNBIND_CHANNEL      = 1,            /* 解绑通道 */

    NETDEV_PANE_OPERATE_TYPE_INVALID             = 0xff          /* 无效值 */
}NETDEV_PANE_OPERATE_TYPE_E;

/**
 * @enum tagNETDEVTimeTemplateType
 * @brief 时间模板类型
 * @attention 无 None
 */
typedef enum tagNETDEVTimeTemplateType
{
    NETDEV_TIMETEMPLATE_TYPE_RECORD     = 0,                /* 录像计划 */
    NETDEV_TIMETEMPLATE_TYPE_ALARM      = 1,                /* 告警计划 */
    /* 2和3CS暂不使用，web端使用 2是用户时间模板， 3是微信小程序使用 */
    NETDEV_TIMETEMPLATE_TYPE_SEQUENCE   = 4,                /* 轮巡 */
    NETDEV_TIMETEMPLATE_TYPE_ACS        = 5,                /* 门禁管理 */
    NETDEV_TIMETEMPLATE_TYPE_INVALID    = 0xFF              /* 无效 */
}NETDEV_TIME_TEMPLATE_TYPE_E;

/**
 * @enum tagNETDEVAlarmLinkType
 * @brief 告警联动类型
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmLinkType
{
    NETDEV_ALARM_LINK_TYPE_STORE        = 0X01,         /* 联动存储 */
    NETDEV_ALARM_LINK_TYPE_PRESET       = 0X02,         /* 联动预置位 */
    NETDEV_ALARM_LINK_TYPE_MONITOR      = 0X04,         /* 联动实况 */
    NETDEV_ALARM_LINK_TYPE_SWITCHOUT    = 0X08,         /* 联动报警输出 */
    NETDEV_ALARM_LINK_TYPE_EMAIL        = 0X10,         /* 联动邮件 */
    NETDEV_ALARM_LINK_TYPE_WALL         = 0X20,         /* 联动上墙 */
    NETDEV_ALARM_LINK_TYPE_BUZZER       = 0X40,         /* 联动一体机设备蜂鸣器 */
    NETDEV_ALARM_LINK_TYPE_LOCALAUDIO   = 0X80,         /* 联动本地声音告警 */

    NETDEV_ALARM_LINK_TYPE_INVALID      = 0xFF          /* 无效 */
}NETDEV_ALARM_LINK_TYPE_E;



/**
 * @enum tagNETDEVEMapHotPotType
 * @brief 电子地图热点/热区类型
 * @attention 无 None
 */
typedef enum tagNETDEVEMapHotPotType
{
    NETDEV_EMAP_TYPE_HOTAREA        = 1,                    /* 热区 */
    NETDEV_EMAP_TYPE_HOTPOT         = 2,                    /* 热点 */

    NETDEV_EMAP_TYPE_INVALID        = 0xFF                  /* 无效值 */
}NETDEV_EMAP_HOTPOT_TYPE_E;

/**
 * @enum tagNETDEVViewResType
 * @brief 视图资源类型
 * @attention 无 None
 */
typedef enum tagNETDEVViewResType
{
    NETDEV_VIEW_TYPE_SCHEME     = 0,                        /* 轮巡 */
    NETDEV_VIEW_TYPE_REALPLAY   = 1,                        /* 实况*/

    NETDEV_VIEW_TYPE_INVALID    = 0xFF                      /* 无效 */
}NETDEV_VIEW_TYPE_E;

/* 一级权限 */
typedef enum tagNETDEVRoleMajorRight
{
    /* 设备权限 */
    NETDEV_MAJOR_DEV_VIDEO_CHANNEL       = 1,               /* 视频通道权限   见NETDEV_MINOR_VIDEO_CHANNEL_E */
    NETDEV_MAJOR_DEV_AUDIO_CHANNEL       = 2,               /* 音频通道权限   见NETDEV_MINOR_AUDIO_CHANNEL_E */
    NETDEV_MAJOR_DEV_ALARM_POINT_CHANNEL = 5,               /* 报警主机权限   见 NETDEV_MINOR_ALARM_POINT_CHANNEL_E */
    NETDEV_MAJOR_DEV_DOOR_CHANNEL        = 6,               /* 门禁通道权限   见 NETDEV_MINOR_DOOR_CHANNEL_E */
    NETDEV_MAJOR_DEV_MAX,

    /* 操作权限 */
    NETDEV_MAJOR_OPER_PREVIEW            = 100,              /* 操作端预览     见NETDEV_MINOR_OPER_PREVIEW_E */
    NETDEV_MAJOR_OPER_ALARM              = 101,              /* 操作端告警     见NETDEV_MINOR_OPER_ALARM_E */
    NETDEV_MAJOR_OPER_EMAP               = 102,              /* 操作端电子地图 见NETDEV_MINOR_OPER_EMAP_E */
    NETDEV_MAJOR_OPER_VOICE              = 103,              /* 操作端语音     见NETDEV_MINOR_OPER_VOICE_E */
    NETDEV_MAJOR_OPER_TVWALL             = 104,              /* 操作端电视墙   见NETDEV_MINOR_OPER_TVWALL_E */
    NETDEV_MAJOR_OPER_MONITOR_SCHEME     = 105,              /* 操作端轮巡预案 见NETDEV_MINOR_OPER_MONITOR_SCHEME_E */
    NETDEV_MAJOR_OPER_SEQUENCE_RESOURCE  = 106,              /* 操作端轮巡资源 见NETDEV_MINOR_OPER_SEQUENCE_RESOURCE_E */
    NETDEV_MAJOR_OPER_INTELLIGENT        = 107,              /* 操作端智能     见NETDEV_MINOR_RIGHT_OPER_INTELLIGENT_E */
    NETDEV_MAJOR_OPER_ALARM_POINT_CONFIG = 108,              /* 操作端报警主机 */
    NETDEV_MAJOR_OPER_DOOR_CONFIG        = 109,              /* 操作端门禁管理 见 NETDEV_MINOR_OPER_DOOR_CONFIG_E */
    NETDEV_MAJOR_OPER_FACE_RECOGNITION   = 110,              /* 操作端人脸识别 见 NETDEV_MINOR_OPER_FACE_RECOGNITION_E */
    NETDEV_MAJOR_OPER_VEHICLE_RECOGNITION =  111,            /* 操作端车牌识别 见 NETDEV_MINOR_OPER_VEHICLE_RECOGNITION_E */
    NETDEV_MAJOR_OPER_MAX,

    /* 管理 */
    NETDEV_MAJOR_MGR_BAS_CONFIG         = 200,              /* 管理端基本配置  见NETDEV_MINOR_MGR_BASE_E */
    NETDEV_MAJOR_MGR_SVC_CONFIG         = 201,              /* 管理端业务配置  见NETDEV_MINOR_MGR_SVC_E */
    NETDEV_MAJOR_MGR_SYS_CONFIG         = 202,              /* 管理端系统配置  见NETDEV_MINOR_MGR_SYS_E */
    NETDEV_MAJOR_MGR_STATISTICS         = 203,              /* 管理端运维统计  见NETDEV_MINOR_MGR_STAT_E */
    NETDEV_MAJOR_MGR_MAX,

    NETDEV_MAJOR_BULT                   = 300
}NETDEV_MAJOR_RIGHT_E;

/* 设备视频通道二级权限 */
typedef enum tagNETDEVDevVChlRight
{
    NETDEV_MINOR_VIDEO_CHANNEL_LIVE         = 1,            /* 实况预览 */
    NETDEV_MINOR_VIDEO_CHANNEL_PLAYBACK     = 2,            /* 录像回放 */
    NETDEV_MINOR_VIDEO_CHANNEL_DOWNLOAD     = 4,            /* 录像下载 */
    NETDEV_MINOR_VIDEO_CHANNEL_PTZ          = 8,            /* 云台控制 */
    NETDEV_MINOR_VIDEO_CHANNEL_CENTER_RECORD = 16,           /* 中心录像 */

    NETDEV_MINOR_VIDEO_CHANNEL_ALL          = 0xff
}NETDEV_MINOR_RIGHT_VIDEO_CHANNEL_E;

/* 设备音频通道二级权限 */
typedef enum tagNETDEVDevAChlRight
{
    NETDEV_MINOR_AUDIO_CHANNEL_TALK         = 1,            /* 语音对讲 */
    NETDEV_MINOR_AUDIO_CHANNEL_BROADCAST    = 2,            /* 语音广播 */
    NETDEV_MINOR_AUDIO_CHANNEL_UNSUPPORT    = 4,            /* 不支持音频 */

    NETDEV_MINOR_AUDIO_CHANNEL_ALL          = 0xff
}NETDEV_MINOR_RIGHT_AUDIO_CHANNEL_E;

/* 操作端预览二级权限 */
typedef enum tagNETDEVOperPreviewRight
{
    NETDEV_MINOR_OPER_PREVIEW_LIVE          = 1,            /* 实况 */
    NETDEV_MINOR_OPER_PREVIEW_PLAYBACK      = 2,            /* 回放 */

    NETDEV_MINOR_OPER_PREVIEW_ALL           = 0xff
}NETDEV_MINOR_RIGHT_OPER_PREVIEW_E;

/* 操作端告警管理二级权限 */
typedef enum tagNETDEVOperAlarmRight
{
    NETDEV_MINOR_OPER_ALARM_CONFIG          = 1,            /* 预案配置 */

    NETDEV_MINOR_OPER_ALARM_ALL             = 0xff
}NETDEV_MINOR_RIGHT_OPER_ALARM_E;

/* 操作端电子地图二级权限 */
typedef enum tagNETDEVOperEmapRight
{
    NETDEV_MINOR_OPER_EMAP_CONFIG           = 1,            /* 配置 */
    NETDEV_MINOR_OPER_EMAP_OPERATE          = 2,            /* 操作 */

    NETDEV_MINOR_OPER_EMAP_ALL              = 0xff
}NETDEV_MINOR_RIGHT_OPER_EMAP_E;

/* 操作端语音二级权限 */
typedef enum tagNETDEVOperVoiceRight
{
    NETDEV_MINOR_OPER_VOICE_TALK            = 1,            /* 语音对讲 */
    NETDEV_MINOR_OPER_VOICE_BROADCAST       = 2,            /* 语音广播 */

    NETDEV_MINOR_OPER_VOICE_ALL             = 0xff
}NETDEV_MINOR_RIGHT_OPER_VOICE_E;

/* 操作端电视墙二级权限 */
typedef enum tagNETDEVOperTvwallRight
{
    NETDEV_MINOR_OPER_TVWALL_CONFIG         = 1,            /* 配置 */
    NETDEV_MINOR_OPER_TVWALL_OPERATE        = 2,            /* 操作 */

    NETDEV_MINOR_OPER_TVWALL_ALL            = 0xff
}NETDEV_MINOR_RIGHT_OPER_TVWALL_E;

/* 操作端轮巡预案二级权限 */
typedef enum tagNETDEVOperMonitorSchemeRight
{
    NETDEV_MINOR_OPER_MONITOR_SCHEME_CONFIG  = 1,           /* 配置 */
    NETDEV_MINOR_OPER_MONITOR_SCHEME_OPERATE = 2,           /* 操作 */

    NETDEV_MINOR_OPER_MONITOR_SCHEME_ALL     = 0xff
}NETDEV_MINOR_RIGHT_OPER_MONITOR_SCHEME_E;

/* 操作端轮巡资源二级权限 */
typedef enum tagNETDEVOperSequenceResourceRight
{
    NETDEV_MINOR_OPER_SEQUENCE_RESOURCE_CONFIG  = 1,        /* 配置 */
    NETDEV_MINOR_OPER_SEQUENCE_RESOURCE_OPERATE = 2,        /* 操作 */

    NETDEV_MINOR_OPER_SEQUENCE_RESOURCE_ALL     = 0xff
}NETDEV_MINOR_RIGHT_OPER_SEQUENCE_RESOURCE_E;

/* 操作端智能二级权限 */
typedef enum tagNETDEVOperIntelligentRight
{
    NETDEV_MINOR_OPER_INTELLIGENT_PASSENGER_RFLOW = 1,      /* 客流量查询 */

    NETDEV_MINOR_OPER_INTELLIGENT_ALL = 0xff
}NETDEV_MINOR_RIGHT_OPER_INTELLIGENT_E;

/* 管理端基础配置二级权限 */
typedef enum tagNETDEVMgrBaseRight
{
    NETDEV_MINOR_MGR_ORG                 = 1,                /* 组织管理 */
    NETDEV_MINOR_MGR_USER                = 2,                /* 用户管理 */
    NETDEV_MINOR_MGR_USER_ROLE           = 4,                /* 角色管理 */
    NETDEV_MINOR_MGR_DEV                 = 8,                /* 设备管理 */
    NETDEV_MINOR_MGR_DEV_CHANNEL         = 16,               /* 通道管理 */
    NETDEV_MINOR_MGR_SERVER              = 32,               /*服务器管理*/
    NETDEV_MINOR_MGR_LOGICORG            = 64,               /* 虚拟组织管理*/
    NETDEV_MINOR_MGR_MGR_RES_RELATION    = 128,               /* 关联资源配置 */
    NETDEV_MINOR_MGR_THIRD_ALARM         = 256,              /* 第三方告警 */
    NETDEV_MINOR_MGR_USER_TEMPLATE       = 512,              /* 用户模板 */

    NETDEV_MINOR_MGR_BASE_ALL           = 0xff
}NETDEV_MINOR_RIGHT_MGR_BASE_E;

/* 管理端业务配置二级权限 */
typedef enum tagNETDEVMgrSvcRight
{
    NETDEV_MINOR_MGR_RECORD_PLAN            = 1,            /* 录像计划 */
    NETDEV_MINOR_MGR_RECORD_PLAN_TEMPLATE   = 2,            /* 录像模板 */
    NETDEV_MINOR_MGR_ALARM_CONFIG           = 4,            /* 告警配置 */
    NETDEV_MINOR_MGR_ALARM_PLAN_TEMPLATE    = 8,            /* 告警模板 */
    NETDEV_MINOR_MGR_ALARM_CONTACTS         = 16,           /* 通讯录 */

    NETDEV_MINOR_MGR_SVC_ALL              = 0xff
}NETDEV_MINOR_RIGHT_MGR_SVC_E;

/* 管理端系统配置二级权限 */
typedef enum tagNETDEVMgrSysRight
{
    NETDEV_MINOR_MGR_SYS_BASIC              = 1,            /* 基本配置 */
    NETDEV_MINOR_MGR_SYS_DISK               = 2,            /* 硬盘配置 */
    NETDEV_MINOR_MGR_SYS_NETWORK            = 4,            /* 网络配置 */
    NETDEV_MINOR_MGR_SYS_MAINTAIN           = 8,            /* 系统维护 */
    NETDEV_MINOR_MGR_SYS_SECURITY           = 16,           /* 安全配置 */
    NETDEV_MINOR_MGR_SYS_ALL                = 0xff
}NETDEV_MINOR_RIGHT_MGR_SYS_E;

/* 管理端运维统计二级权限 */
typedef enum tagNETDEVMgrStatRight
{
    NETDEV_MINOR_MGR_STAT_SERVER_DISK       = 1,            /* 硬盘状态 */
    NETDEV_MINOR_MGR_STAT_SERVER_NETWORK    = 2,            /* 网络状态 */
    NETDEV_MINOR_MGR_STAT_SERVER_USER       = 4,            /* 用户状态 */
    NETDEV_MINOR_MGR_STAT_DEVICE            = 8,            /* 设备状态 */
    NETDEV_MINOR_MGR_STAT_DEVICE_CHANNEL    = 16,           /* 通道状态 */
    NETDEV_MINOR_MGR_STAT_DEVICE_RECORD     = 32,           /* 录像状态 */
    NETDEV_MINOR_MGR_STAT_ALARM_LOG         = 64,           /* 告警日志 */
    NETDEV_MINOR_MGR_STAT_OPER_LOG          = 128,          /* 操作日志 */

    NETDEV_MINOR_MGR_STAT_ALL               = 0xff
}NETDEV_MINOR_RIGHT_MGR_STAT_E;

/* 设备报警点通道二级权限 */
typedef enum tagNETDEVDevAPChlRightE
{
    NETDEV_MINOR_ALARM_POINT_CHANNEL_CONTROL = 1, /* 报警点通道手动控制 */

    NETDEV_MINOR_ALARM_POINT_CHANNEL_ALL     = 0xff
}NETDEV_MINOR_ALARM_POINT_CHANNEL_E;

/* 设备门禁通道二级权限 */
typedef enum tagNETDEVDevDoorChlRightE
{
    NETDEV_MINOR_DOOR_CHANNEL_CONTROL = 1, /* 门禁通道手动控制 */

    NETDEV_MINOR_DOOR_CHANNEL_ALL     = 0xff
}NETDEV_MINOR_DOOR_CHANNEL_E;

/* 操作端门禁管理二级权限 */
typedef enum tagNETDEVOperDoorConfigRightE
{
    NETDEV_MINOR_OPER_DOOR_CONFIG            = 1,    /* 门禁管理 */
    NETDEV_MINOR_OPER_DOOR_ACCESS_RECORD     = 2,    /* 出入记录 */
    NETDEV_MINOR_OPER_DOOR_PEOPLE_MANAGEMENT = 4,    /* 人员管理 */

    NETDEV_MINOR_OPER_DOOR_ALL               = 0xff
}NETDEV_MINOR_OPER_DOOR_CONFIG_E;

/* 操作端人脸识别二级权限 */
typedef enum tagNETDEVOperFaceRecognitionE
{
    NETDEV_MINOR_OPER_REAL_TIME_MONITORING      = 1,    /* 实时监控 */
    NETDEV_MINOR_OPER_DATABASE_MANAGE           = 2,    /* 人脸库管理 */
    NETDEV_MINOR_OPER_DISPATCH_TASK             = 4,    /* 布控任务 */
    NETDEV_MINOR_OPER_HISTORY_RECORD            = 8,    /* 历史记录 */
    NETDEV_MINOR_OPER_SMARTNVR_CONFIG           = 16,   /* 智能NVR配置 */
    NETDEV_MINOR_OPER_PEOPLE_RECORD             = 32,   /* 过人记录 */

    NETDEV_MINOR_OPER_FACE_RECOGNITION_ALL      = 0xff
}NETDEV_MINOR_OPER_FACE_RECOGNITION_E;

/* 操作端车牌识别管理二级权限 */
typedef enum tagNETDEVOperVehicleRecognitionE
{
    NETDEV_MINOR_OPER_VEHICLE_REAL_TIME_MONITORING   = 1,          /* 实时监控 */
    NETDEV_MINOR_OPER_VEHICLE_PASSING_RECORD         = 2,          /* 过车记录 */
    NETDEV_MINOR_OPER_VEHICLE_DISPATCH_TASK          = 4,          /* 布控任务 */
    NETDEV_MINOR_OPER_VEHICLE_HISTORY_RECORD         = 8,          /* 历史告警记录 */

    NETDEV_MINOR_OPER_VEHICLE_RECOGNITION_ALL = 0xff
}NETDEV_MINOR_OPER_VEHICLE_RECOGNITION_E;

/* 热备模式(默认为0) */
typedef enum tagNETDEVVmsHotStandbyModeE
{
    NETDEV_HOTSTANDBY_MODE_DISABLE            = 0,    /* 禁用 */
    NETDEV_HOTSTANDBY_MODE_ACTIVITE           = 1,    /* 激活模式 */
    NETDEV_HOTSTANDBY_MODE_BACKUP             = 2     /* 备份模式 */
}NETDEV_VMS_HOTSTANDBYMODE_E;

/* 主从服务器状态 */
typedef enum tagNETDEVVmsStatusE
{
    NETDEV_VMS_OFFLINE               = 0,      /* 离线 */
    NETDEV_VMS_ONLINE                = 1,      /* 在线 */
    NETDEV_VMS_VERSION_INCONSISTENT  = 2,      /* 版本不一致 */
    NETDEV_VMS_SLAVE_REACH_LIMIT     = 3,      /* 从机达到上限 */
    NETDEV_VMS_SLAVE_UNREGISTER      = 4,      /* 从机未注册 */
    NETDEV_VMS_IN_STANDBY_MODE       = 5       /* 服务器处于备机状态 */
}NETDEV_VMS_STATUS_E;

/* 一体机主从模式 */
typedef enum tagNETDEVVmsModeE
{
    NETDEV_VMS_MASTER      = 0,    /* 主一体机 */
    NETDEV_VMS_SLAVE       = 1     /* 从一体机 */
}NETDEV_VMS_MODE_E;

/* 报警日志数据清除标志,默认为1 */
typedef enum tagNETDEVAlarmLogCleanupFlagE
{
    NETDEV_ALARM_LOG_CLEANUP      = 0,    /* 清除 */
    NETDEV_ALARM_LOG_NOT_CLEANUP  = 1     /* 不清除 */
}NETDEV_ALARM_LOG_CLEANUP_FLAG_E;

/**
 * @enum tagNETDEVPTZCruiseCmd
 * @brief 云台巡航操作命令 枚举定义 PTZ patrol operation commands Enumeration Definition
 * @attention 无 None
 */
typedef enum tagNETDEVPTZTRACKCmd
{
    NETDEV_PTZ_TRACKCRUISE_START     = 0,      /* 开始轨迹巡航  Start route patrol*/
    NETDEV_PTZ_TRACKCRUISE_STOP      = 1,      /* 停止轨迹巡航  Stop route patrol*/
    NETDEV_PTZ_TRACKCRUISE_REC       = 2,      /* 开始录制轨迹  Start recording route */
    NETDEV_PTZ_TRACKCRUISE_RECSTOP   = 3,      /* 停止录制轨迹  Stop recording route */
    NETDEV_PTZ_TRACKCRUISE_ADD       = 4,      /* 添加巡航轨迹  Add patrol route  一体机服务器暂不支持该接口，轨迹巡航ID写死为16 */
    NETDEV_PTZ_TRACKCRUISE_DEL       = 5       /* 删除轨迹巡航  Delete patrol route */
}NETDEV_PTZ_TRACKCMD_E;

typedef enum tagNETDEVPTZGuardMode
{
    NETDEV_PTZ_GUARD_MODE_PRESET    = 0,       /* 预置位模式 */
    NETDEV_PTZ_GUARD_MODE_CRUISE    = 1,       /* 预置位巡航模式 */
    NETDEV_PTZ_GUARD_MODE_TRACK     = 2         /* 轨迹巡航模式 */
}NETDEV_PTZ_GUARD_MODE_E;

/**
 * @enum tagNETDEVPTZTrackStatus
 * @brief 巡航状态 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVPTZTrackStatus
{
    NETDEV_PTZ_TRACK_STATUS_FREE           = 0,                        /* 空闲（未巡航且未录制） */
    NETDEV_PTZ_TRACK_STATUS_RUN            = 1,                        /* 正在巡航*/
    NETDEV_PTZ_TRACK_STATUS_START_RECORD   = 2                         /*正在录制*/
}NETDEV_PTZ_TRACK_STATUS_E;

/**
 * @struct tagNETDEVPTZGuardCmd
 * @brief 云台守望配置命令
 * @attention 无 None
 */
typedef enum tagNETDEVPTZGuardCmd
{
    NETDEV_PTZ_GUARD_CMD_GET = 0,       /* 获取指定通道的云台守望信息 */
    NETDEV_PTZ_GUARD_CMD_SET = 1        /* 设置指定通道的云台守望信息 */
}NETDEV_PTZ_GUARD_CMD_E;


/* 响应状态类型枚举 */
typedef enum tagNETDEVOrgResponseStatus
{
    NETDEV_ORG_RESPONSE_SUCCESS           = 0,            /* 响应成功 */
    NETDEV_ORG_RESPONSE_FAIL              = 1             /* 响应失败 */
}NETDEV_ORG_RESPONSE_STAUTE_E;

/* 组织类型枚举 */
typedef enum tagNETDEVOrgType
{
    NETDEV_ORG_TYPE_GENERAL            = 0,            /* 普通组织 */
    NETDEV_ORG_TYPE_CLOUD              = 1,            /* 云端组织 */
    NETDEV_ORG_TYPE_VIRTUAL            = 2,            /* 逻辑组织 */
    NETDEV_ORG_TYPE_FAVORITES          = 3,            /* 收藏夹 */
    NETDEV_ORG_TYPE_DOMAIN             = 4,            /* 域名组织 */
    NETDEV_ORG_TYPE_DOORGROUP          = 5,            /* 门组 */
    NETDEV_ORG_TYPE_DEPT               = 6,            /* 部门组织 */

    NETDEV_ORG_TYPE_INVALID            = 0XFF          /* 无效值 */
}NETDEV_ORG_TYPE_E;

/* 轮巡计划方式枚举 */
typedef enum tagNETDEVPlansMode
{
    NETDEV_PLANS_MODE_TIMING            = 0,             /* 定时切换 */
    NETDEV_PLANS_MODE_24HOUR            = 1,             /* 24小时计划表 */
    NETDEV_PLANS_MODE_INVALID           = 0XFF           /* 无效值 */
}NETDEV_PLANS_MODE_E;


/**
 * @enum tagNETDEVTimeTemplatePlanType
 * @brief 时间模板计划类型
 */
typedef enum tagNETDEVTimeTemplatePlanType
{
    NETDEV_TIME_TEMPLATE_PLAN_COMMON                        = 0,                /* 常规存储 */  
    NETDEV_TIME_TEMPLATE_PLAN_MOTION                        = 1,                /* 运动检测存储 */
    NETDEV_TIME_TEMPLATE_PLAN_ALARM                         = 2,                /* 告警存储 */
    NETDEV_TIME_TEMPLATE_PLAN_MOTION_AND_ALARM              = 3,                /* 运动检测和告警存储 */
    NETDEV_TIME_TEMPLATE_PLAN_MOTION_OR_ALARM               = 4,                /* 运动检测或告警存储 */
    NETDEV_TIME_TEMPLATE_PLAN_MANUL                         = 5,                /* 手动存储 */
    NETDEV_TIME_TEMPLATE_PLAN_DISCONNECT                    = 6,                /* 断网报警 */
    NETDEV_TIME_TEMPLATE_PLAN_THIRD_STREAM                  = 7,                /* 第三流存储 */
    NETDEV_TIME_TEMPLATE_PLAN_VIDEO_LOSS                    = 8,                /* 视频丢失告警 */
    NETDEV_TIME_TEMPLATE_PLAN_AUDIODETECT                   = 9,                /* 音频检测 */
    NETDEV_TIME_TEMPLATE_PLAN_EVENT_ALL_ALARM               = 10,               /* 事件类型，包涵所有告警类型 */
    NETDEV_TIME_TEMPLATE_PLAN_ALL_RECORD_TYPE               = 11,               /* 所有录像类型 */

    NETDEV_TIME_TEMPLATE_PLAN_INVALID                       = 0xFF              /* 无效值 */
}NETDEV_TIME_TEMPLATE_PLAN_TYPE_E;


/**
 * @brief XW设备窗口漫游能力枚举
 * @attention
 */
typedef enum tagNETDEVTVWallType
{
    NETDEV_TVWALL_TYPE_DECODER = 0,                                 /* 解接器电视墙 */
    NETDEV_TVWALL_TYPE_SPLICER = 1,                                 /* 拼接器电视墙 */
    NETDEV_TVWALL_TYPE_DECARD  = 2                                  /* 解码卡电视墙 */
}NETDEV_TVWALL_TYPE_E;



/**
 * @enum tagNETDEVLeftRightAlignment
 * @brief 左右对齐方式枚举
 * @attention
 */
typedef enum tagNETDEVLeftRightAlignment
{
    NETDEV_FONT_LR_ALIGNMENT_LEFT     = 1,                  /* 左对齐 */
    NETDEV_FONT_LR_ALIGNMENT_MID      = 2,                  /* 居中对齐 */
    NETDEV_FONT_LR_ALIGNMENT_RIGHT    = 3                   /* 右对齐 */
}NETDEV_XW_LEFT_RIGHT_ALIGNMENT_E;

/**
 * @enum tagNETDEVUpDownAlignment
 * @brief 上下对齐方式枚举
 * @attention
 */
typedef enum tagNETDEVUpDownAlignment
{
    NETDEV_FONT_UD_ALIGNMENT_UP      = 1,                   /* 上对齐 */
    NETDEV_FONT_UD_ALIGNMENT_MID     = 2,                   /* 居中对齐 */
    NETDEV_FONT_UD_ALIGNMENT_DOWN    = 3                    /* 下对齐 */
}NETDEV_XW_UP_DOWN_ALIGNMENT_E;



/**
 * @enum tagNETDEVXWVirtualLEDInfo
 * @brief 轮巡状态枚举
 * @attention
 */
typedef enum tagNETDEVSeqStatus
{
    NETDEV_SEQ_STATUS_EMPTY    = 0,                          /* 未轮巡 */
    NETDEV_SEQ_STATUS_RUNNING = 1,                           /* 正在轮巡 */
    NETDEV_SEQ_STATUS_STOP   = 2,                            /* 停止轮巡 */

    NETDEV_SEQ_STATUS_INVALID = 0xFF                         /* 无效状态 */
}NETDEV_SEQ_STATUS_E;

/**
 * @enum tagNETDEVLapiTransProtocal
 * @brief 媒体传输协议 枚举定义  Media transport protocol Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVLapiTransProtocal
{
    NETDEV_LAPI_TRANS_PROTOCAL_TCP     = 0,              /* TCP */
    NETDEV_LAPI_TRANS_PROTOCAL_UDP     = 1               /* UDP */
}NETDEV_LAPI_TRANS_PROTOCAL_E;


 /**
 * @enum tagNETDEVXWVirtualLEDInfo
 * @brief 轮巡状态枚举
 * @attention
 */
typedef enum tagNETDEVTVWallWndType
{
    NETDEV_WINDOWS_TYPE_NORMAL    = 0,                          /* 普通窗口 */
    NETDEV_WINDOWS_TYPE_ALARM = 1,                              /* 告警窗口 */

    NETDEV_WINDOWS_TYPE_INVALID = 0xFF                          /* 无效状态 */
}NETDEV_TVWALL_WND_TPYE_E;


/**
 * @enum tagNETDEVXWPlayBackCond
 * @brief 轮巡操作枚举
 * @attention
 */
typedef enum tagNETDEVXWSeqCmd
{
    NETDEV_XW_SEQ_CMD_STOP = 0,                            /* 停止轮巡业务 */
    NETDEV_XW_SEQ_CMD_START  = 1,                          /* 开启轮巡业务 */
    NETDEV_XW_SEQ_CMD_PAUSE  = 2,                          /* 轮巡暂停 */
    NETDEV_XW_SEQ_CMD_CONTINUE = 3,                        /* 暂停后启动 */

    NETDEV_XW_SEQ_CMD_INVALID = 0xFF                       /* 无效命令 */
}NETDEV_XW_SEQ_CMD_E;

/**
 * @enum tagNETDEVXWSeqResourceType
 * @brief 轮巡资源枚举
 * @attention
 */
typedef enum tagNETDEVXWSeqResourceType
{
    NETDEV_XW_SEQ_RESOURCE_WND = 0,                                /* 窗口资源 */
    NETDEV_XW_SEQ_RESOURCE_GROUP_WND = 1,                          /* 组轮巡资源 */

    NETDEV_XW_SEQ_RESOURCE_INVALID = 0xFF                          /* 无效命令 */
}NETDEV_XW_SEQ_RESOURCE_TYPE_E;

/**
 * @enum tagNETDEVLangType
 * @brief 语言类型枚举
 * @attention
 */
typedef enum tagNETDEVLangType
{
    NETDEV_LANG_TYPE_CHINESE             = 0,                           /* 中文 */
    NETDEV_LANG_TYPE_ENGLISH             = 1,                           /* 英文 */
    NETDEV_LANG_TYPE_TRADITIONAL_CHINESE = 2,                           /* 繁体中文 */
    NETDEV_LANG_TYPE_FRENCH              = 3,                           /* 法语 */
    NETDEV_LANG_TYPE_GERMAN              = 4,                           /* 德语 */
    NETDEV_LANG_TYPE_SPANISH             = 5,                           /* 西班牙语 */
    NETDEV_LANG_TYPE_ITALIAN             = 6,                           /* 意大利语 */
    NETDEV_LANG_TYPE_PORTUGUESE          = 7,                           /* 葡萄牙语 */
    NETDEV_LANG_TYPE_RUSSIAN             = 8,                           /* 俄文 */
    NETDEV_LANG_TYPE_UKRAINIAN           = 9,                           /* 乌克兰语 */
    NETDEV_LANG_TYPE_GRUANIAN            = 10,                          /* 格鲁尼亚语 */
    NETDEV_LANG_TYPE_DUTCH               = 11,                          /* 荷兰语 */
    NETDEV_LANG_TYPE_DANISH              = 12,                          /* 丹麦语 */
    NETDEV_LANG_TYPE_FINNISH             = 13,                          /* 芬兰语 */
    NETDEV_LANG_TYPE_SWEDISH             = 14,                          /* 瑞典语 */
    NETDEV_LANG_TYPE_NORWEGIAN           = 15,                          /* 挪威语 */
    NETDEV_LANG_TYPE_LCELANDIC           = 16,                          /* 冰岛语 */
    NETDEV_LANG_TYPE_POLISH              = 17,                          /* 波兰语 */
    NETDEV_LANG_TYPE_LITHUANIAN          = 18,                          /* 立陶宛语 */
    NETDEV_LANG_TYPE_GREEK               = 19,                          /* 希腊语 */
    NETDEV_LANG_TYPE_CZECH               = 20,                          /* 捷克语 */
    NETDEV_LANG_TYPE_SLOVAK              = 21,                          /* 斯洛伐克语 */
    NETDEV_LANG_TYPE_HUNGARIAN           = 22,                          /* 匈牙利语 */
    NETDEV_LANG_TYPE_ROMAN               = 23,                          /* 罗马语 */
    NETDEV_LANG_TYPE_SERBIAN             = 24,                          /* 塞尔维亚语 */
    NETDEV_LANG_TYPE_CROATIAN            = 25,                          /* 克罗地亚语 */
    NETDEV_LANG_TYPE_SLOVENIAN           = 26,                          /* 斯洛文尼亚语 */
    NETDEV_LANG_TYPE_BULGARIAN           = 27,                          /* 保加利亚语 */
    NETDEV_LANG_TYPE_BELARUSIAN          = 28,                          /* 白俄罗斯语 */
    NETDEV_LANG_TYPE_TURKISH             = 29,                          /* 土耳其语 */
    NETDEV_LANG_TYPE_ARABIC              = 30,                          /* 阿拉伯语 */
    NETDEV_LANG_TYPE_HEBREW              = 31,                          /* 希伯来语 */
    NETDEV_LANG_TYPE_HINDI               = 32,                          /* 印度语 */
    NETDEV_LANG_TYPE_BENGALI             = 33,                          /* 孟加拉语 */
    NETDEV_LANG_TYPE_PERSIAN             = 34,                          /* 波斯语 */
    NETDEV_LANG_TYPE_JAPANESE            = 35,                          /* 日语 */
    NETDEV_LANG_TYPE_KOREAN              = 36,                          /* 韩语 */
    NETDEV_LANG_TYPE_THAI                = 37,                          /* 泰语 */
    NETDEV_LANG_TYPE_MALAYSIAN           = 38,                          /* 马来西亚语 */
    NETDEV_LANG_TYPE_INDONESIAN          = 39,                          /* 印度尼西亚语 */
    NETDEV_LANG_TYPE_FILIPINO            = 40,                          /* 菲律宾语 */
    NETDEV_LANG_TYPE_LAO                 = 41,                          /* 老挝语 */
    NETDEV_LANG_TYPE_VIETNAMESE          = 42,                          /* 越南语 */
    NETDEV_LANG_TYPE_MONGOLIAN           = 43,                          /* 蒙古国语 */
    NETDEV_LANG_TYPE_ALBANIAN            = 44,                          /* 阿尔巴尼亚语 */
    NETDEV_LANG_TYPE_AZERBAIJANI         = 45,                          /* 阿塞拜疆语 */
    NETDEV_LANG_TYPE_GAELIC              = 46,                          /* 盖尔语 */
    NETDEV_LANG_TYPE_ESTONIAN            = 47,                          /* 爱沙尼亚语 */
    NETDEV_LANG_TYPE_BOSNIAN             = 48,                          /* 波斯尼亚语 */
    NETDEV_LANG_TYPE_LOWLAND_SAXON       = 49,                          /* 低地撒克逊语 */
    NETDEV_LANG_TYPE_PERUVIAN            = 50,                          /* 秘鲁语 */
    NETDEV_LANG_TYPE_LATVIAN             = 51,                          /* 拉脱维亚语 */

    NETDEV_LANG_TYPE_INVALID             = 0xFF                         /* 无效命令 */
}NETDEV_LANG_TYPE_E;


/**
 * @enum tagNETDEVRegionType
 * @brief 区域类型枚举
 * @attention
 */
typedef enum tagNETDEVRegionType
{
    NETDEV_REGION_TYPE_ENGINEERING  = 0,                          /* 工程 */
    NETDEV_REGION_TYPE_DISTRIBUTION = 1,                          /* 分销 */
    NETDEV_REGION_TYPE_OVERSEAS     = 2,                          /* 海外 */

    NETDEV_REGION_TYPE_INVALID      = 0xFF                        /* 无效命令 */
}NETDEV_REGION_TYPE_E;

/**
 * @enum tagNETDEVCustomType
 * @brief 定制类型枚举
 * @attention
 */
typedef enum tagNETDEVCustomType
{
    NETDEV_CUSTOM_TYPE_GUARD   = 0,                               /* 白牌 */
    NETDEV_CUSTOM_TYPE_UNV_OLD = 1,                               /* 老版本宇视 */
    NETDEV_CUSTOM_TYPE_UNV_NEW = 2,                               /* 新版本宇视 */
    NETDEV_CUSTOM_TYPE_CUSTOM  = 3,                               /* 定制 */

    NETDEV_CUSTOM_TYPE_INVALID = 0xFF                             /* 无效命令 */
}NETDEV_CUSTOM_TYPE_E;

/**
 * @enum tagNETDEVManualRecordStatus
 * @brief 手动录像状态
 * @attention
 */
typedef enum tagNETDEVManualRecordStatus
{
    NETDEV_MANUAL_RECORD_STATUS_FREE = 0,                            /* 未录像 */
    NETDEV_MANUAL_RECORD_STATUS_RECORDING  = 1,                      /* 录像中 */

    NETDEV_MANUAL_RECORD_STATUS_INVALID = 0xFF                       /* 无效命令 */
}NETDEV_MANUAL_RECORD_STATUS_E;



/**
 * @enum tagNETDEVXWSerialType
 * @brief 串口类型
 * @attention 无 None      
 */
typedef enum tagNETDEVXWSerialType
{
    NETDEV_XW_SERIAL_TYPE_RS232                    = 0,               /* 232串口 */
    NETDEV_XW_SERIAL_TYPE_RS422                    = 1,               /* 422 */
    NETDEV_XW_SERIAL_TYPE_RS485                    = 2,               /* 485 */

    NETDEV_XW_SERIAL_TYPE_INVALID                  = 0xFF             /* 无效值 */
}NETDEV_XW_SERIAL_TYPE_E;

/**
 * @enum tagNETDEVXWSerialMode
 * @brief 串口模式
 * @attention 无 None      
 */
typedef enum tagNETDEVXWSerialMode
{
    NETDEV_XW_SERIAL_MODE_BIG_CONTROL                    = 0,               /* 大屏控制 */

    NETDEV_XW_SERIAL_MODE_INVALID                        = 0xFF             /* 无效值 */
}NETDEV_XW_SERIAL_MODE_E;

/**
 * @enum tagNETDEVXWWorkMode
 * @brief 工作模式
 * @attention 无 None      
 */
typedef enum tagNETDEVXWWorkMode
{
    NETDEV_XW_WORK_MODE_ALL                       = 0,               /* 全双工模式 */
    NETDEV_XW_WORK_MODE_SINGLE                    = 1,               /* 半双工模式 */

    NETDEV_XW_WORK_MODE_INVALID                   = 0xFF             /* 无效值 */
}NETDEV_XW_WORK_MODE_E;


/**
 * @enum tagNETDEVXWParityType
 * @brief 校验位 校验方式
 * @attention 无 None      
 */
typedef enum tagNETDEVXWParityType
{
    NETDEV_XW_PARITY_TYPE_NONE                    = 0,               /* 无 */
    NETDEV_XW_PARITY_TYPE_ODD                     = 1,               /* 奇校验 */
    NETDEV_XW_PARITY_TYPE_EVEN                    = 2,               /* 偶校验 */

    NETDEV_XW_PARITY_TYPE_INVALID                 = 0xFF             /* 无效值 */
}NETDEV_XW_PARITY_TYPE_E;

/**
 * @enum tagNETDEVXWFlowCtrl
 * @brief 流控位
 * @attention 无 None      
 */
typedef enum tagNETDEVXWFlowCtrl
{
    NETDEV_XW_FLOW_CTRL_NONE                        = 0,               /* 无 */
    NETDEV_XW_FLOW_CTRL_SOFTWARE                    = 1,               /* 软件流控 */
    NETDEV_XW_FLOW_CTRL_HARDWARE                    = 2,               /* 硬件流控 */

    NETDEV_XW_FLOW_CTRL_INVALID                     = 0xFF             /* 无效值 */
}NETDEV_XW_FLOW_CTRL_E;



/**
 * @enum tagNETDEVAlarmPointActionType
 * @brief 报警点通道控制命令
 * @attention
 */
typedef enum tagNETDEVAlarmPointActionType
{
    NETDEV_ALARMPOINT_ACTION_TYPE_ARM             = 0,                /* 布防 */
    NETDEV_ALARMPOINT_ACTION_TYPE_DISARM          = 1,                /* 撤防 */
    NETDEV_ALARMPOINT_ACTION_TYPE_BYPASS          = 2,                /* 旁路 */
    NETDEV_ALARMPOINT_ACTION_TYPE_DISBYPASS       = 3,                /* 旁路恢复 */

    NETDEV_ALARMPOINT_ACTION_TYPE_INVALID         = 0xFF              /* 无效值 */
}NETDEV_ALARMPOINT_ACTION_TYPE_E;


/**
 * @enum tagNETDEVAlarmPointActionType
 * @brief 报警点通道控制命令
 * @attention
 */
typedef enum tagNETDEVDoorCtrlActionType
{
    NETDEV_DOORCTRL_ACTION_TYPE_OPEN             = 0,                /* 开门 */
    NETDEV_DOORCTRL_ACTION_TYPE_CLOSE            = 1,                /* 关门 */

    NETDEV_DOORCTRL_ACTION_TYPE_INVALID          = 0xFF              /* 无效值 */
}NETDEV_DOORCTRL_ACTION_TYPE_E;

/**
 * @enum tagNETDEVACSPersonCommondType
 * @brief 门禁人员管理命令(添加和删除使用批量接口)
 * @attention
 */
typedef enum tagNETDEVACSPersonCommondType
{
    NETDEV_ACS_PERSON_COMMOND_TYPE_GET            = 0,                /* 获取 */
    NETDEV_ACS_PERSON_COMMOND_TYPE_MOD            = 1,                /* 修改 */

    NETDEV_ACS_PERSON_COMMOND_TYPE_INVALID        = 0xFF              /* 无效值 */
}NETDEV_ACS_PERSON_COMMOND_TYPE_E;

/**
 * @enum tagNETDEVGenderType
 * @brief 成员性别
 * @attention 无 None
 */
typedef enum tagNETDEVGenderType
{
    NETDEV_GENDER_TYPE_UNKNOW       = 0,        /* 0-未知的性别 */
    NETDEV_GENDER_TYPE_MAN          = 1,        /* 1-男 */
    NETDEV_GENDER_TYPE_WOMAN        = 2,        /* 2-女 */
    NETDEV_GENDER_TYPE_UNEXPLAINED  = 9,        /* 9-未说明的性别 */
    NETDEV_GENDER_TYPE_INVALID      = 0xFF      /* 无效值 */
}NETDEV_GENDER_TYPE_E;

/**
 * @enum tagNETDEVFaceMemberIDType
 * @brief 人脸成员证件类型
 * @attention 无 None
 */
typedef enum tagNETDEVFaceMemberIDType
{
    NETDEV_FACE_MEMBER_ID_TYPE_ID_CARD                 = 0,               /* 身份证 */
    NETDEV_FACE_MEMBER_ID_TYPE_PASSPORT                = 1,               /* 护照 */
    NETDEV_FACE_MEMBER_ID_TYPE_DRIVING                 = 2,               /* 驾照 */
    NETDEV_FACE_MEMBER_ID_TYPE_OTHER                   = 99,              /* 其他 */

    NETDEV_FACE_MEMBER_ID_TYPE_INVALID                 = 0xFF             /* 无效值 */
}NETDEV_FACE_MEMBER_ID_TYPE_E;

/**
 * @enum tagNETDEVACSPersonType
 * @brief 人员类型
 * @attention 无 None
 */
typedef enum tagNETDEVACSPersonType
{
    NETDEV_ACS_PERSON_TYPE_STAFF                      = 0,               /* 员工 */
    NETDEV_ACS_PERSON_TYPE_VISITOR                    = 1,               /* 访客 */
    NETDEV_ACS_PERSON_TYPE_STRANGER                   = 2,               /* 陌生人 */

    NETDEV_ACS_PERSON_TYPE_INVALID                    = 0xFF             /* 无效值 */
}NETDEV_ACS_PERSON_TYPE_E;

/**
 * @enum tagNETDEVACSVisitStaus
 * @brief 访客状态
 * @attention 无 None
 */
typedef enum tagNETDEVACSVisitStaus
{
    NETDEV_ACS_VISIT_STATUS_SCHEDULE                 = 0,               /* 预约 */
    NETDEV_ACS_VISIT_STATUS_VISITING                 = 1,               /* 在访 */
    NETDEV_ACS_VISIT_STATUS_LEAVE                    = 2,               /* 离访 */
    NETDEV_ACS_VISIT_STATUS_SCHEDULE_CANCEL          = 3,               /* 预约取消 */
    NETDEV_ACS_VISIT_STATUS_TIMEOUT                  = 4,               /* 超时 */

    NETDEV_ACS_VISIT_STATUS_INVALID                  = 0xFF             /* 无效值 */
}NETDEV_ACS_VISIT_STATUS_E;


/**
 * @enum tagNETDEVAlarmActionType
 * @brief 输出开关量操作
 * @attention
 */
typedef enum tagNETDEVAlarmActionType
{
    NETDEV_ALARM_ACTION_TYPE_CLOSE            = 0,                /* 关闭告警 */
    NETDEV_ALARM_ACTION_TYPE_OPEN             = 1,                /* 触发告警 */

    NETDEV_ALARM_ACTION_TYPE_INVALID          = 0xFF              /* 无效值 */
}NETDEV_ALARM_ACTION_TYPE_E;

/**
 * @enum tagNETDEVAlarmStatusType
 * @brief 开关量输出告警状态
 * @attention
 */
typedef enum tagNETDEVAlarmStatusType
{
    NETDEV_ALARM_STATUS_TYPE_INACTIVE           = 0,                /* 未告警 */
    NETDEV_ALARM_STATUS_TYPE_ACTIVE             = 1,                /* 告警 */

    NETDEV_ALARM_STATUS_TYPE_INVALID            = 0xFF              /* 无效值 */
}NETDEV_ALARM_STATUS_TYPE_E;

/**
 * @enum tagNETDEVEmergencyBellType
 * @brief 紧急铃类型
 * @attention
 */
typedef enum tagNETDEVEmergencyBellType
{
    NETDEV_EMERGENCY_BELL_TYPE_SEHO    = 0,                          /* 韩国紧急铃 */
    NETDEV_EMERGENCY_BELL_TYPE_HITEC   = 1,                          /* Hitec紧急铃 */

    NETDEV_EMERGENCY_BELL_TYPE_INVALID = 0xFF                        /* 无效铃 查询单个通道不传紧急铃类型时下发此值*/
}NETDEV_EMERGENCY_BELL_TYPE_E; 


/**
 * @enum tagNETDEVMonitorType
 * @brief 布控任务类型
 * @attention 无 None
 */
typedef enum tagNETDEVMonitorType
{
    NETDEV_MONITOR_TYPE_FACE                       = 0,                /* 人脸 */
    NETDEV_MONITOR_TYPE_VEHICLE                    = 1,                /* 车牌 */
    NETDEV_MONITOR_TYPE_INVALID                    = 0xFF              /* 无效值*/
}NETDEV_MONITOR_TYPE_E;


/**
 * @enum tagNETDEVDiskModeType
 * @brief 硬盘模式
 * @attention 无 None
 */
typedef enum tagNETDEVDiskModeType
{
    NETDEV_DISK_MODE_TYPE_OLD            = 0,                /* 旧存储格式硬盘 */
    NETDEV_DISK_MODE_TYPE_NEW            = 1,                /* 新存储格式硬盘 */

    NETDEV_DISK_MODE_TYPE_INVALID        = 0xFF              /* 无效值 */
}NETDEV_DISK_MODE_TYPE_E;


/**
 * @enum tagNETDEVEncodeChnStatus
 * @brief 编码通道状态
 * @attention 无 None
 */
typedef enum tagNETDEVChnStatus
{
    NETDEV_CHN_STATUS_OFFLINE          = 0,                /* 离线 offline */
    NETDEV_CHN_STATUS_ONLINE           = 1,                /* 在线 online */
    NETDEV_CHN_STATUS_VIDEO_LOSE       = 2,                /* 视频丢失 video lose */

    NETDEV_CHN_STATUS_INVALID       = 0xFF
}NETDEV_CHN_STATUS_E;


/**
 * @enum tagNETDEVAlarmInChnStatus
 * @brief 告警输入通道状态
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmRunode
{
    NETDEV_ALARM_RUNMODE_OPEN       = 0,                /* 常开  Always open */
    NETDEV_ALARM_RUNMODE_CLOSE      = 1,                /* 常闭  Always closed */
    NETDEV_ALARM_RUNMODE_INVALID    = 0xFF
}NETDEV_ALARM_RUNMODE_E;

/**
 * @enum tagNETDEVAlarmOutChnStatus
 * @brief 告警输出通道状态
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmOutChnStatus
{
    NETDEV_ALARMOUT_CHN_ACTIVE      = 0,
    NETDEV_ALARMOUT_CHN_INACTIVE    = 1,
    NETDEV_ALARMOUT_CHN_INVALID     = 0xFF
}NETDEV_ALARMOUT_CHN_STATUS_E;

/**
 * @enum tagNETDEVRecordLocation
 * @brief 录像存储类型 枚举定义 Record location Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVRecordLocation
{
    NETDEV_RECORD_LOCATION_ALL                        = 0,                /* 存储位置：所有 */  
    NETDEV_RECORD_LOCATION_VMS                        = 1,                /* 存储位置：VMS */  
    NETDEV_RECORD_LOCATION_NVR                        = 2,                /* 存储位置：NVR */
    NETDEV_RECORD_LOCATION_BACKUP                     = 3,                /* 存储位置：备份 */

    NETDEV_RECORD_LOCATION_INVALID                    = 0xFF              /* 无效值 */
}NETDEV_RECORD_LOCATION_E;

/**
 * @enum tagNETDEVDeviceMainType
 * @brief 设备类型枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVDeviceMainType
{
    NETDEV_DTYPE_MAIN_ENCODE            = 0,                /* 编码设备 */
    NETDEV_DTYPE_MAIN_DECODE            = 1,                /* 解码设备 */
    NETDEV_DTYPE_MAIN_VMS               = 2,                /* 一体机设备 */
    NETDEV_DTYPE_MAIN_DA                = 3,                /* 代理设备 */
    NETDEV_DTYPE_MAIN_CLOUD             = 4,                /* 云端编码设备  */
    NETDEV_DTYPE_MAIN_BAYONET           = 5,                /* 卡口设备 */
    NETDEV_DTYPE_MAIN_ACS               = 6,                /* 门禁主机设备 */
    NETDEV_DTYPE_MAIN_ALARMHOST         = 7,                /* 报警主机设备 */

    NETDEV_DTYPE_MAIN_UNKNOWN           = 0XFF              /* 未知设备 */
}NETDEV_DEVICE_MAIN_TYPE_E;

typedef enum tagNETDEVDeviceStatus
{
    NETDEV_DEV_STATUS_OFFLINE                   = 0,                /* 离线 */
    NETDEV_DEV_STATUS_ONLINE                    = 1,                /* 在线 */
    NETDEV_DEV_STATUS_CONNECTING                = 2,                /* 连接中 */

    NETDEV_DEV_STATUS_INVALID                   = 0XFF              /* 无效值 */
}NETDEV_DEVICE_STATUS_E;

typedef enum tagNETDEVDeviceAccessMode
{
    NETDEV_DEV_ACCESS_MODE_IP_DOMAIN            = 0,                /* IP、域名接入 */ 
    NETDEV_DEV_ACCESS_MODE_P2P                  = 1,                /* P2P接入 */
    NETDEV_DEV_ACCESS_MODE_UNP                  = 2,                /* UNP接入 */

    NETDEV_DEV_ACCESS_MODE_INVALID              = 0XFF              /* 无效值 */
}NETDEV_DEVICE_ACCESS_MODE_E;

typedef enum tagNETDEVChlType
{
    NETDEV_CHN_TYPE_ENCODE              = 0,                /* 编码通道, 通道状态参见NETDEV_CHN_STATUS_E */
    NETDEV_CHN_TYPE_ALARMIN             = 1,                /* 告警输入通道, 通道状态参见NETDEV_ALARM_RUNMODE_E */
    NETDEV_CHN_TYPE_ALARMOUT            = 2,                /* 告警输出通道, 通道状态参见NETDEV_ALARMOUT_CHN_STATUS_E */
    NETDEV_CHN_TYPE_DECODE              = 3,                /* 解码通道 */
    NETDEV_CHN_TYPE_AUDIO               = 4,                /* 音频通道 */
    NETDEV_CHN_TYPE_NIC                 = 5,                /* 网卡通道 */
    NETDEV_CHN_TYPE_ALARMPOINT          = 6,                /* 报警点 */
    NETDEV_CHN_TYPE_DOOR                = 7,                /* 门 */
    NETDEV_CHN_TYPE_ADU_ENCODE          = 8,                /* ADU本地编码通道, 通道状态参见NETDEV_CHN_STATUS_E */
    NETDEV_CHN_TYPE_EMERGENCY           = 9,                /* 紧急铃通道 */

    NETDEV_CHN_TYPE_INVALID             = 0xFF              /* 无效值 */
}NETDEV_CHN_TYPE_E;


/**
 * @enum tagNETDEVAlarmPointStatusType
 * @brief 告警点位状态枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVAlarmPointStatusType
{
    NETDEV_ALARM_POINT_STATUS_TYPE_UNKNOWN     = 0,             /* 未知 */
    NETDEV_ALARM_POINT_STATUS_TYPE_ARM         = 1,             /* 布防 */
    NETDEV_ALARM_POINT_STATUS_TYPE_DISARM      = 2,             /* 撤防 */
    NETDEV_ALARM_POINT_STATUS_TYPE_DISBYPASS   = 3,             /* 非旁路 */
    NETDEV_ALARM_POINT_STATUS_TYPE_BYPASS      = 4,             /* 旁路 */
    NETDEV_ALARM_POINT_STATUS_TYPE_ZONEFAILURE = 5,             /* 防区失效 */

    NETDEV_ALARM_POINT_STATUS_TYPE_INVALID     = 0xFF           /* 无效值 */
}NETDEV_ALARM_POINT_STATUS_TYPE_E;

/**
 * @enum tagNETDEVDoorStatusType
 * @brief 告警点位状态枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVDoorStatusType
{
    NETDEV_DOOR_STATUS_TYPE_UNKNOWN     = 0,             /* 未知 */
    NETDEV_DOOR_STATUS_TYPE_CLOSE       = 1,             /* 关门 */
    NETDEV_DOOR_STATUS_TYPE_OPEN        = 2,             /* 开门 */

    NETDEV_DOOR_STATUS_TYPE_INVALID     = 0xFF           /* 无效值 */
}NETDEV_DOOR_STATUS_TYPE_E;


 /**
 * @enum tagNETDEVVideoSrcType
 * @brief 视频输入类型枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVVideoSrcType
{
    NETDEV_VIDEO_SRC_TYPE_BNC            = 0,                /* BNC输入*/
    NETDEV_VIDEO_SRC_TYPE_VGA            = 1,                /* VGA输入*/
    NETDEV_VIDEO_SRC_TYPE_HDMI           = 2,                /* HDMI输入 */
    NETDEV_VIDEO_SRC_TYPE_DVI_D          = 3,                /* DVI_D输入*/
    NETDEV_VIDEO_SRC_TYPE_DVI_I          = 4,                /* DVI_I输入*/
    NETDEV_VIDEO_SRC_TYPE_DP             = 5,                /* DP输入*/
    NETDEV_VIDEO_SRC_TYPE_SDI            = 6,                /* SDI输入*/
    NETDEV_VIDEO_SRC_TYPE_INVALID      = 0xFF                /* 无效值 */
}NETDEV_VIDEO_SRC_TYPE_E;

/**
 *@enum tagNETDEVTrafficStatisticsFormType
 *@brief 客流量报表类型 枚举定义
 *@attention 无 None
 */
typedef enum tagNETDEVTrafficStatisticsFormType
{
    NETDEV_TRAFFIC_STAT_FORM_BY_MINUTE = 0,                  /* 按分钟*/
    NETDEV_TRAFFIC_STAT_FORM_BY_HOUR = 1,                    /* 按小时*/
    NETDEV_TRAFFIC_STAT_FORM_BY_DAY = 2,                     /* 按天*/
    NETDEV_TRAFFIC_STAT_FORM_BY_MONTH = 3,                   /* 按月*/
    NETDEV_TRAFFIC_STAT_FORM_BY_BUTT
}NETDEV_TRAFFIC_STATIC_FORM_TYPE_E;



/* 车辆事件上报类型 */
typedef enum tagNETDEVVehicleEventType
{
    NETDEV_VEHCILE_EVENT_TYPE_SNAPSHOT        = 0,       /* 车辆抓拍 */
    NETDEV_VEHCILE_EVENT_TYPE_MATCHALARM      = 1,       /* 车辆匹配告警 */
    NETDEV_VEHCILE_EVENT_TYPE_MISMATCHALARM   = 2,       /* 车辆不匹配告警 */
    NETDEV_VEHCILE_EVENT_TYPE_BUTT            = 0xFF     /* 无效值 */
}NETDEV_VEHICLE_EVENT_TYPE_E;

/* 人脸事件上报类型 */
typedef enum tagNETDEVFaceEventType
{
    NETDEV_FACE_EVENT_TYPE_SNAPSHOT       = 0,        /* 人脸抓拍 */
    NETDEV_FACE_EVENT_TYPE_MATCH_ALARM    = 1,        /* 人脸匹配告警 */
    NETDEV_FACE_EVENT_TYPE_MISMATCH_ALARM = 2,        /* 人脸不匹配告警 */
    NETDEV_FACE_EVENT_TYPE_BUTT           = 0xFF      /* 无效值 */
}NETDEV_FACE_EVENT_TYPE_E;

/**
 * @enum tagNETDEVEventActionType
 * @brief 事件动作类型枚举 枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVEventActionType
{
    NETDEV_EVENT_ACTION_TYPE_ADD            = 0,                /* 事件动作类型：增加 */
    NETDEV_EVENT_ACTION_TYPE_DELETE         = 1,                /* 事件动作类型：删除 */
    NETDEV_EVENT_ACTION_TYPE_MODIFY         = 2,                /* 事件动作类型：修改 */
    NETDEV_EVENT_ACTION_TYPE_ONLINE         = 3,                /* 事件动作类型：上线 */
    NETDEV_EVENT_ACTION_TYPE_OFFLINE        = 4,                /* 事件动作类型：离线 */
    NETDEV_EVENT_ACTION_TYPE_EMAP_ALARM     = 5,                /* 事件动作类型：电子地图告警 */

    NETDEV_EVENT_ACTION_TYPE_INVALID        = 0xFF              /* 无效值 */
}NETDEV_EVENT_ACTION_TYPE_E;


/**
 * @enum tagNETDEVProtocal
 * @brief 媒体传输协议 枚举定义  Media transport protocol Enumeration definition
 * @attention 无 None
 */
typedef enum tagNETDEVTransProtocal
{
    NETDEV_TRANS_PROTOCAL_UDP     = 0,            /* UDP */
    NETDEV_TRANS_PROTOCAL_TCP     = 1             /* TCP */
}NETDEV_TRANS_PROTOCAL_E;

/**
 * @enum tagNETDEVSessionType
 * @brief 分屏业务类型 枚举定义 
 * @attention 无 None
 */
typedef enum tagNETDEVSessionType
{
    NETDEV_SESSION_TYPE_FREE             = 0,             /* 空闲 */
    NETDEV_SESSION_TYPE_LIVE_ON_WALL     = 1,             /* 实况上墙 */ 
    NETDEV_SESSION_TYPE_PLAYBACK_ON_WALL = 2,             /* 回放上墙 */ 
    NETDEV_SESSION_TYPE_TURNING_ON_WALL  = 3             /* 轮巡上墙 */ 
}NETDEV_SESSION_TYPE_E;


/* 传输类型 */
typedef enum tagNETDEVTransType
{
    NETDEV_TRANS_TYPE_FORWORD     = 0,                        /* 一体机转发 */
    NETDEV_TRANS_TYPE_STRAIGHT    = 1                         /* 下行设备直连*/
}NETDEV_TRANS_TYPE_E;


/**
 * @enum tagNETDEVCloudConnectMode
 * @brief 云端设备连接模式 
 * @attention 无 None
 */
typedef enum tagNETDEVCloudConnectMode
{
    NETDEV_CLOUD_CONNECT_MODE_ALL       = 0,         /* 本地直连->广域网直连->打洞->转发 */
    NETDEV_CLOUD_CONNECT_MODE_P2P_TURN  = 1,         /* 本地直连->广域网直连->打洞+转发(转发延迟500ms) */
    NETDEV_CLOUD_CONNECT_MODE_P2P       = 2,         /* 直接打洞 */
    NETDEV_CLOUD_CONNECT_MODE_TURN      = 3          /* 直接转发 */
}NETDEV_CLOUD_CONNECT_MODE_E;


/**
*@enum tagNETDEVMyCloudOffErr
*@brief 下线原因类型枚举
*@attention 无
*/
typedef enum tagNETDEVMyCloudOffErr
{
    NETDEV_MYCLOUD_OFF_ERR_OK                 = 0,      /* MyCloud正常 */
    NETDEV_MYCLOUD_OFF_ERR_NOT_REGISTER       = 1,      /* 未在MyCloud网站添加设备 */
    NETDEV_MYCLOUD_OFF_ERR_NET_UNREACHABLE    = 2       /* 网络不可达 */
}NETDEV_MYCLOUD_OFF_ERR_E;

/**
* @brief 通道权限枚举
* @attention 按位表示 若拥有该通道实况和对讲权限和云台控制权限，该字段填3
*/
typedef enum tagNETDEVChnPermission
{
    NETDEV_CHN_PERMISSION_LIVE                  = BIT0,                 /* 实况和语音对讲 */
    NETDEV_CHN_PERMISSION_PTZ                   = BIT1,                 /* 云台控制 */
    NETDEV_CHN_PERMISSION_PLAYBACK              = BIT2,                 /* 回放 */
    NETDEV_CHN_PERMISSION_MANU_RECORD           = BIT3,                 /* 手动录像 */
    NETDEV_CHN_PERMISSION_LOCAL_BACK            = BIT4,                 /* 本地备份 */

    NETDEV_CHN_PERMISSION_INVALID               = 0XFFFFFFFF        /* 无效值 */
}NETDEV_CHN_PERMISSION_TYPE_E;

/**
* @brief 用户级别,仅管理员用户可以修改权限
* @attention 无
*/
typedef enum tagNETDEVUserLevel
{
    NETDEV_USER_LEVEL_ADMINISTRATOR  = 0,           /* 管理员 不可配置*/
    NETDEV_USER_LEVEL_OPERATOR       = 1,           /* 操作员 */
    NETDEV_USER_LEVEL_USER           = 2,           /* 普通用户 */
    NETDEV_USER_LEVEL_Default        = 3            /* 默认用户 不可配置 */
}NETDEV_USER_LEVEL_E;

/**
* @brief 基本权限
* @attention 无 
*/
typedef enum tagNETDEVUserBasePermission
{
    NETDEV_USER_BASE_PER_CONFIG           = BIT0,           /* 配置*/
    NETDEV_USER_BASE_PER_UPGRADE          = BIT1,           /* 升级 */
    NETDEV_USER_BASE_PER_LOG              = BIT2,           /* 日志查看和导出 */
    NETDEV_USER_BASE_PER_REBOOT           = BIT3            /* 重启 */
}NETDEV_USER_BASE_PERMISSION_E;

/**
* @enum tagNETDEVFactoryResetModeType
* @brief 出厂设置恢复模式的枚举定义
 * @attention 无 None
 */
typedef enum tagNETDEVFactoryResetModeType
{
    NETDEV_FACTORY_RESET_SOFT             = 0,              /* 软恢复模式（简单恢复，保留网络配置和用户配置）*/
    NETDEV_FACTORY_RESET_HARD             = 1,              /* 硬恢复模式（完全恢复，恢复到出厂配置）*/

    NETDEV_FACTORY_RESET_INVALID          = 0xFF            /* 无效值 */
}NETDEV_FACTORY_RESET_MODE_TYPE_E;


/**
 * @enum tagNETDEVCloudDeviceType
 * @brief 云端设备类型
 * @attention 无 None
 */
typedef enum tagNETDEVCloudDeviceType
{
    NETDEV_CLOUD_DEV_TYPE_IPC                 = 0,          /* IPC设备 */
    NETDEV_CLOUD_DEV_TYPE_NVR                 = 1,          /* NVR设备 */
    NETDEV_CLOUD_DEV_TYPE_VMS                 = 2,          /* 一体机设备 */
    NETDEV_CLOUD_DEV_TYPE_DVR                 = 3,          /* DVR设备 */
    NETDEV_CLOUD_DEV_TYPE_EC                  = 4,          /* 编码器设备 */
    NETDEV_CLOUD_DEV_TYPE_DC                  = 5,          /* 解码器设备 */
    NETDEV_CLOUD_DEV_TYPE_INVALID            = 0xff         /* 无效值 */
}NETDEV_CLOUD_DEVICE_TYPE;

/**
 * @brief 视频分发协议类型
 * @attention
 */
typedef enum tagNETDEVCDNProt
{
    NETDEV_CDN_PROT_PRIVATE     = 0,       /* 私有 */
    NETDEV_CDN_PROT_RTMP        = 1        /* RTMP协议 */

}NETDEV_CDN_PROT_E;

/**
* @enum tagNETDEVFileType
* @brief 文件信息
* @attention 无 None
*/
typedef enum tagNETDEVFileType
{
    NETDEV_TYPE_FOLDER  = 0,    /* 文件夹 */
    NETDEV_TYPE_FILE    = 1,    /* 文件 */
    NETDEV_TYPE_INVALID = 0xff  /* 文件夹 */
}NETDEV_FILE_TYPE_E;

/**
 * @brief 轮询资源业务类型
 * @attention
 */
typedef enum tagNETDEVSeqResType
{
    NETDEV_TYPE_SEQ_RES_REMOTE = 0,                                      /* 远端实况 */
    NETDEV_TYPE_SEQ_RES_LOCAL  = 1,                                      /* 本地实况 */

    NETDEV_TYPE_SEQ_RES_INVALID                         = 0xff           /* 无效值 */
}NETDEV_SEQ_RES_TYPE_E;

/**
* @struct tagNETDEVFacePassRecordType
* @brief 人脸通行记录类型
* @attention 无 None
*/
typedef enum tagNETDEVFacePassRecordType
{
    NETDEV_FACE_PASS_RECORD_SNAP            = 0,                /* 人脸抓拍 */
    NETDEV_TYPE_FACE_PASS_COM_SUCCESS       = 1,                /* 比对成功告警 */
    NETDEV_TYPE_FACE_PASS_COM_FAIL          = 2,                /* 比对失败告警 */
    NETDEV_TYPE_FACE_PASS_INVALID           = 0xff              /* 无效值 */
}NETDEV_FACE_PASS_RECORD_TYPE_E;

/**
* @enum tagNETDEVPersonResultCode
* @brief 人脸处理结果状态码
* @attention 无 None
*/
typedef enum tagNETDEVPersonResultCode
{
    NETDEV_PERSON_CODE_SUCCESSED                    = 0,           /* 成功 */
    NETDEV_PERSON_CODE_EXEC_FAILED                  = 1,           /* 通用执行失败 */
    NETDEV_PERSON_CODE_INIT_DETECT_FAIL             = 2,           /* 初始化检测失败 */
    NETDEV_PERSON_CODE_FACE_DETECT_FAIL             = 3,           /* 人脸检测失败 */
    NETDEV_PERSON_CODE_IMAGE_NOT_FIND_FACE          = 4,           /* 图片未检测到人脸 */
    NETDEV_PERSON_CODE_JPEG_PARSE_FAIL              = 5,           /* jpeg照片解码失败 */
    NETDEV_PERSON_CODE_IMAGE_MASS_NOT_ENOUGH        = 6,           /* 人脸图片质量分数不满足 */
    NETDEV_PERSON_CODE_IMAGE_ZOOM_FAIL              = 7,           /* 图片缩放失败 */
    NETDEV_PERSON_CODE_NOT_START_SMART              = 8,           /* 未启用智能 */
    NETDEV_PERSON_CODE_IMAGE_NO_GOOD                = 9,           /* 图片不存在或过大/过小 */
    NETDEV_PERSON_CODE_INVALID                      = 0xff         /* 无效值 */
}NETDEV_PERSON_RESULT_CODE_E;

/**
 * @enum tagNETDEVPersonMonitorOptResCode
 * @brief 人脸布控操作结果错误码
 * @attention 仅VMS支持
 */
typedef enum tagNETDEVPersonMonitorOptResCode
{
    NETDEV_PERSON_MONITOR_CODE_INIT_DETECT_FAIL             = 11704,           /* 初始化检测失败 */
    NETDEV_PERSON_MONITOR_CODE_FACE_DETECT_FAIL             = 11705,           /* 人脸检测失败 */
    NETDEV_PERSON_MONITOR_CODE_IMAGE_NOT_FIND_FACE          = 11706,           /* 图片未检测到人脸 */
    NETDEV_PERSON_MONITOR_CODE_JPEG_PARSE_FAIL              = 11707,           /* jpeg照片解码失败 */
    NETDEV_PERSON_MONITOR_CODE_IMAGE_MASS_NOT_ENOUGH        = 11708,           /* 人脸图片质量分数不满足 */
    NETDEV_PERSON_MONITOR_CODE_IMAGE_ZOOM_FAIL              = 11709,           /* 图片缩放失败 */
    NETDEV_PERSON_MONITOR_CODE_NOT_START_SMART              = 11710,           /* 未启用智能 */
    NETDEV_PERSON_MONITOR_CODE_IMAGE_NO_GOOD                = 11711,           /* 图片不存在或过大/过小 */
    NETDEV_PERSON_MONITOR_CODE_CREATE_FACE_LIB_FAIL         = 11712,           /* 创建人脸库失败 */
    NETDEV_PERSON_MONITOR_CODE_CREATE_MONITOR_FAIL          = 11713            /* 创建布控任务失败 */
}NETDEV_PERSON_MONITOR_OPT_RES_CODE_E;

/**
* @enum  tagNETDEVMotionDetectAreaType
* @brief 运动检测区域类型枚举 motion detection area type emnu
* @attention 无
*/
typedef enum tagNETDEVMotionDetectAreaType
{
    NETDEV_MOTION_DETECTION_AREA_TYPE_RECTANGLE         = 0,        /* 矩形区域  rectangle */
    NETDEV_MOTION_DETECTION_AREA_TYPE_MB                = 1,        /* 宏块区域  macro block */
    NETDEV_MOTION_DETECTION_AREA_TYPE_INVALID           = 0xff      /* 无效值 Invalid value */
}NETDEV_MOTION_DETECTION_AREA_TYPE_E;

/**
* @enum tagNETDEVPhotoServerProtocolType
* @brief 照片服务器通信协议类型
* @attention 无 None
*/
typedef enum tagNETDEVPhotoServerProtocolType
{
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO1          = 0,        /* TCP传输: 宇视V1（对应泓鎏） */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO2          = 1,        /* TCP传输: 宇视V2（对应当前tms） */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO3          = 2,        /* TCP传输: 先创 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO4          = 3,        /* FTP传输: 泉视通 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO5          = 4,        /* FTP传输: 通用FTP */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO6          = 5,        /* FTP传输: 正直 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO7          = 6,        /* webserver: 海康协议 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO8          = 7,        /* FTP传输: 中通 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO9          = 8,        /* FTP传输: 泉视通2 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO10          = 9,       /* 银江，照片信息webserver 照片数据FTP传输 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO11          = 10,      /* TCP传输:立元 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO12          = 11,      /* 翔讯，照片信息TCP 照片数据FTP传输 */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO31          = 12,      /* TCP传输: 宇视V2（对应当前tms短连接） */
    NETDEV_PHOTO_SERVER_PRO_TYPE_PRO34          = 13,      /* HTTP传输: 松立 */

    NETDEV_PHOTO_SERVER_PRO_TYPE_INVALID        = 0xFF      /* Invalid value */
}NETDEV_PHOTO_SERVER_PRO_TYPE_E;

/**
* @enum tagNETDEVPhotoServerSubProtocolType
* @brief 照片服务器通信子协议类型
* @attention 无 None
*/
typedef enum tagNETDEVPhotoServerSubProtocolType
{
    NETDEV_PHOTO_SERVER_SUBPRO_TYPE_2011          = 0,        /* 宇视智慧物联2011命令 */
    NETDEV_PHOTO_SERVER_SUBPRO_TYPE_2025          = 1,        /* 宇视智慧物联2025命令 */
    NETDEV_PHOTO_SERVER_SUBPRO_TYPE_6130          = 2,        /* 宇视智慧物联6130命令 */


    NETDEV_PHOTO_SERVER_SUBPRO_TYPE_INVALID        = 0xFF      /* Invalid value */
}NETDEV_PHOTO_SERVER_SUBPRO_TYPE_E;

/* END************* 枚举值  Enumeration value *************************** */

/* BEGIN*********** 结构体  Structure *********************************** */
/**
 * @brief 设备信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /* 设备类型,参见枚举#NETDEV_DEVICE_TYPE_E  Device type, see enumeration #NETDEV_DEVICE_TYPE_E */
    INT16   wAlarmInPortNum;                    /* 报警输入个数  Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /* 报警输出个数  Number of alarm outputs */
    INT32   dwChannelNum;                       /* 通道个数  Number of Channels */
    BYTE    byRes[48];                          /* 保留字段  Reserved */
}NETDEV_DEVICE_INFO_S,*LPNETDEV_DEVICE_INFO_S;

/**
 * @brief 设备基本信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDeviceBasicInfo
{ 
    CHAR szDevModel[NETDEV_LEN_64];                     /* 设备型号  Device model */
    CHAR szSerialNum[NETDEV_LEN_64];                    /* 硬件序列号  Hardware serial number */
    CHAR szFirmwareVersion[NETDEV_LEN_64];              /* 软件版本号  Software version */
    CHAR szMacAddress[NETDEV_LEN_64];                   /* IPv4的Mac地址  MAC address of IPv4 */
    CHAR szDeviceName[NETDEV_LEN_64];                   /* 设备名称  Device name */
    CHAR szManufacturer[NETDEV_LEN_64];                 /* 厂商信息  Manufacturer */

    BYTE byRes[384];                                    /* 保留字段  Reserved */
}NETDEV_DEVICE_BASICINFO_S, *LPNETDEV_DEVICE_BASICINFO_S;

/**
 * @brief 网络配置信息 结构体定义 Network configuration information
 * @attention 无 None
 */
typedef struct tagNETDEVNetworkInterfaces
{
    INT32   dwMTU;                              /* MTU值  MTU value */
    BOOL    bIPv4DHCP;                          /* IPv4的DHCP  DHCP of IPv4 */
    CHAR    szIpv4Address[NETDEV_LEN_32];       /* IPv4的IP地址  IP address of IPv4 */
    CHAR    szIPv4GateWay[NETDEV_LEN_32];       /* IPv4的网关地址  Gateway of IPv4 */
    CHAR    szIPv4SubnetMask[NETDEV_LEN_32];    /* IPv4的子网掩码  Subnet mask of IPv4 */
    BYTE    byRes[480];                         /* 保留字段  Reserved */
}NETDEV_NETWORKCFG_S, *LPNETDEV_NETWORKCFG_S;


/**
 * @brief VPN客户端指定模式信息
 * @attention 无 None
 */
typedef struct tagNETDEVRSAPublicKey{
    CHAR    szRSAPublicKeyE[NETDEV_LEN_256];                /* RSAPublicKeyE */
    CHAR    szRSAPublicKeyN[NETDEV_LEN_256];                /* RSAPublicKeyN */
    BYTE    byRes[128];                                     /* 保留字节 Reserved*/
}NETDEV_RSA_PUBLIC_KEY_S, *LPNETDEV_RSA_PUBLIC_KEY_S;

/**
 * @brief VPN客户端指定模式信息
 * @attention 无 None
 */
typedef struct tagNETDEVVPNClientInfo
{
    UINT32   udwEnabled;                                     /* 是否开启 对应兼容格式的一个开关0: 关闭 1: 开启 Support UNP or not，a switch that corresponds to a compatible format, enable 0:unable  1:enable*/
    UINT32   udwCompatibilityMode;                         /* 对应所设置的兼容模式 0: Unp1.0（unp） 1: Unp2.0 (softvpn). Corresponds to the set compatibility mode.0: Unp1.0（unp） 1: Unp2.0 (softvpn) */
    UINT32   udwAuthEnabled;                                 /* 鉴权是否开启。若为Unp2.0一定鉴权，为开启状态。0：关闭 1：开启 Authentication open or close, if is Unp2.0, must authentication and open. 0:close 1:open  */
    UINT32   udwEncryptEnabled;                              /* 加密是否开启兼容模式, 若当前开启兼容模式为Unp1.0 此字段需为使能关闭。0：关闭 1：开启 */
    UINT32   udwInterface;                                 /* 可选IPC 需要；NVR和VMS不需要。有线网口：0 ,4G 网口：1。范围：[0,1]*/
    CHAR     szLoginName[NETDEV_DOMAIN_LEN];               /* 可选：AuthEnable开启时，带此字段。服务器的用户名，不支持中文名。范围[0-63]*/
    CHAR     szPIN[NETDEV_LEN_256];                        /* 可选：AuthEnable开启时，带此字段服务器的用户密码范围[0,256],只有修改了PIN时才下发该字段，
                                                           其他情况下都不带该字段.不修改接入登录密码时不必携带，修改接入登录密码时必携带，如果配置时，修改密码为空，则下发空字段，获取时默认不携带该字段，如需要获取则使用POST动作。
                                                           获取时返回的密码为：密码根据输入参数的公钥进行RSA加密后再经过Base64编码后的字符串；获取时RSA加密的公私钥对由用户自己生成。修改密码时下发的是RSA加密后再经过Base64编码后密文，公私钥对由服务侧生成*/
    NETDEV_RSA_PUBLIC_KEY_S stRSAPublicKey;                /* 公钥查询使用/LAPI/V1.0/System/Security/RSA。不修改接入登录密码时不必携带，
                                                           修改接入登录密码时必携带，获取时默认不携带该字段；具体请见：#NETDEV_RSA_PUBLIC_KEY_S*/
    UINT32   udwAddressType;
    CHAR     szAddress[NETDEV_IPADDR_STR_MAX_LEN];         /* AddressType：IP地址类型。 0: IPv4 1: IPv6 2:域名 3: IPv4和IPv6都需要.当前仅支持IPv4*/
    UINT32   udwPort;                                      /* 可选;NVR 和VMS需要此字段，对应兼容格式的服务器端口，范围[1-65535]，兼容Unp1.0默认值1701；兼容Unp2.0 默认是5555*/ 
    UINT32   udwUNPSuccessd;                               /* UNP成功连接 标识符 (查询返回表示当前对应UNP有无分配对应ip,掩码,路由)。1 成功，0 失败，获取时携带。*/
    CHAR     szUNPShareIPAddr[NETDEV_IPADDR_STR_MAX_LEN];  /* UNP成功连接 服务器所分配的对应地址 (查询并连接成功才返回,非输入参数)。范围[1-64]，GET方法且UNPSuccessd为1时携带。*/
    CHAR     szUNPShareMask[NETDEV_IPADDR_STR_MAX_LEN];    /* UNP成功连接 服务器所分配的对应掩码(查并连接成功才返回,非输入参数)，GET方法且UNPSuccessd为1时携带。*/ 
    CHAR     szUNPShareWayAddr[NETDEV_IPADDR_STR_MAX_LEN]; /* UNP成功连接 服务器所分配的对应的路由(查询并连接成功才返回,非输入参数)，范围[1-64]，GET方法且UNPSuccessd为1时携带。*/
    BYTE     byRes[128];                                   /* 保留字节  Reserved*/
}NETDEV_VPN_CLIENT_INFO_S, *LPNETDEV_VPN_CLIENT_INFO_S;

/**
 * @brief 地址 结构体定义 Address Structure definition 
 * @attention 无 None
 */
typedef struct tagSysemIPAddr
{
    INT32   eIPType;                            /* 协议类型参见枚举#NETDEV_HOSTTYPE_E  Protocol type, see enumeration #NETDEV_HOSTTYPE_E */
    CHAR    szIPAddr[NETDEV_LEN_132];           /* IP地址  IP address */
}NETDEV_SYSTEM_IPADDR_S, *LPNETDEV_SYSTEM_IPADDR_S;

/**
 * @brief  NTP参数 NTP parameter
 * @attention 无 None
 */
typedef struct tagNETDEVSystemNTPInfo
{
    BOOL bSupportDHCP;                      /* 是否支持DHCP  Support DHCP or not */
    NETDEV_SYSTEM_IPADDR_S stAddr;          /* NTP 信息  NTP information */
}NETDEV_SYSTEM_NTP_INFO_S, *LPNETDEV_SYSTEM_NTP_INFO_S;


typedef struct tagSysemIPAddrInfo
{
    BOOL         bEnabled;                      /*NTP服务器使能 0：不开启  1：开启  NTP Server enable 0:unable  1:enable */
    INT64        ulAddressType;                    /*地址类型 0：IPv4  1：IPv6(暂不支持)  2: 域名（NVR和一体机支持） Address type  0:IPv4  1:IPv6(Temporary does not support)  2:domain name(NVR and AIO support)*/
    CHAR         szIPAddress[NETDEV_LEN_64];     /* NTP服务器IP地址，字符长度范围[0, 64] AddressType 为0时，该节点必选
                                                 The IP address of the NTP server ,character length range [0,64]. When address type is 0,the node must be selected. */
    CHAR         szDomainName[NETDEV_LEN_64];    /*NTP服务器域名，字符长度范围[ [0， 64] AddressType 为2时，该节点必选
                                                 The domain name of the NTP server ,character length range [0,64]. When address type is 2,the node must be selected.*/
    INT64        ulPort;                        /*NTP端口，范围[1-65535]  IPC不支持配置。 NTP Port ,the range of [1-65535]. IPC does not support this configuration. */
    INT64        ulSynchronizeInterval;         /*更新间隔 NVR、VMS支持范围： 5/10/15/30分钟，1/2/3/6/12h，1天，1周。IPC支持范围：30-3600s，以上时间周期，都需要转换为秒为单位的时间值。
                                                 Synchronize Interval: The support range of NVR and VMS is 5/10/15/30 minutes ,1/2/3/6/12 hours ,1 day ,and 1 week.The support range of IPC is 30-3600 seconds.
                                                 All of the above time periods need to be converted to a time value in seconds.*/
    BYTE         byRes[128];                    /*保留字段  Reserved*/
}NETDEV_SYSTEM_IPADDR_INFO_S, *LPNETDEV_SYSTEM_IPADDR_INFO_S;

typedef struct tagNETDEVSystemNTPInfoList
{
    INT64                              ulNum;                                             /*NTP服务器个数  NTP Server Number*/
    NETDEV_SYSTEM_IPADDR_INFO_S        astNTPServerInfoList[NETDEV_NTP_SERVER_LIST_NUM];  /*NTP服务器列表当前只支持一个NTP服务器 The NTP server list currently supports only one NTP server.*/
    BYTE                               byRes[128];                                          /*保留字段   Reserved*/
}NETDEV_SYSTEM_NTP_INFO_LIST_S, *LPNETDEV_SYSTEM_NTP_INFO_LIST_S;


/**
 * @brief 实况预览参数 结构体定义 Live view parameter Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                 /* 通道ID  Channel ID */
    INT32   dwStreamType;                /* 码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                  /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                    /* 播放窗口句柄 Play window handle */ 
    INT32   dwFluency;                   /* 图像播放流畅性优先类型,参见枚举#NETDEV_PICTURE_FLUENCY_E */
    INT32   dwStreamMode;                /* 流模式 参见枚举#NETDEV_STREAM_MODE_E  start stream mode see #NETDEV_STREAM_MODE_E*/
    INT32   dwLiveMode;                  /* 启流模式 参见枚举#NETDEV_PULL_STREAM_MODE_E */
    INT32   dwDisTributeCloud;           /* 分发能力 参见枚举#NETDEV_DISTRIBUTE_CLOUD_SRV_E */
    BOOL    dwallowDistribution;         /* 该通道是否支持分发*/
    INT32   dwTransType;                    /* 传输类型，参见枚举#NETDEV_TRANS_TYPE_E */
    BYTE    byRes[240];                  /* 保留字段  Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
 * @brief 实况影像信息 结构体定义 Live image information Structure definition
 * @attention 伽马参数范围0-10,其它参数取值范围0-255 Gamma parameter range: 0-10, other parameters: 0-255
 */
typedef struct tagNETDEVVideoEffect
{
    INT32 dwContrast;                   /* 对比度  Contrast */
    INT32 dwBrightness;                 /* 亮度  Brightness */
    INT32 dwSaturation;                 /* 饱和度  Saturation */
    INT32 dwHue;                        /* 色调  Hue */
    INT32 dwGamma;                      /* 伽玛值  Gamma */
    BYTE  byRes[16];                    /* 保留字段  Reserved */
}NETDEV_VIDEO_EFFECT_S, *LPNETDEV_VIDEO_EFFECT_S;

/**
 * @brief 设备图像设置 结构体定义    Device image settings Structure definition
 * @attention 参数取值范围：0-255     parameter range: 0-255
 */
typedef struct tagNETDEVImagingSetting
{
    INT32 dwContrast;                   /* 对比度  Contrast */
    INT32 dwBrightness;                 /* 亮度  Brightness */
    INT32 dwSaturation;                 /* 饱和度  Saturation */
    INT32 dwSharpness;                  /* 亮度  Sharpness */
    BYTE  byRes[252];                   /* 保留字段  Reserved */
}NETDEV_IMAGE_SETTING_S, *LPNETDEV_IMAGE_SETTING_S;

/************ 回放业务 Playback services***********************************************/

/**
 * @brief 录像查找 结构体定义 Recording query Structure definition
 *        根据文件类型.时间查找设备录像文件 Query recording files according to file type and time
 * @attention 无 None
 */
typedef struct tagNETDEVFindCond
{
    CHAR    szFileName[NETDEV_LEN_64];      /* 录像文件名  Recording file name */
    INT32   dwChannelID;                    /* 通道号  Channel ID */
    INT32   dwStreamType;                   /* 码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwFileType;                     /* 录像存储类型,参见枚举#NETDEV_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_STORE_TYPE_E */
    INT64   tBeginTime;                     /* 起始时间  Start time */
    INT64   tEndTime;                       /* 结束时间  End time */
    INT32   dwRecordLocation;               /* 录像存储位置 Record Position, 参见枚举#NETDEV_RECORD_LOCATION_E */
    UINT32  udwServerID;                    /* 录像所属服务器ID Video server ID */
    BYTE    byRes[28];                      /* 保留字段  Reserved */
}NETDEV_FILECOND_S, *LPNETDEV_FILECOND_S;

/**
 * @brief 录像查找数据 结构体定义 Recording query data Structure definition
 *        逐个获取查找到的文件信息 Get the information of found files one by one
 * @attention 无 None
 */
typedef struct tagNETDEVFindData
{
    CHAR    szFileName[NETDEV_FILE_NAME_LEN];               /* 录像文件名  Recording file name */
    INT64   tBeginTime;                                     /* 起始时间  Start time */
    INT64   tEndTime;                                       /* 结束时间  End time */
    BYTE    byFileType;                                     /* 录像存储类型  参见枚举#NETDEV_STORE_TYPE_E Recording storage type #NETDEV_STORE_TYPE_E */
    UINT32  udwServerID;                                    /* 录像所属服务器ID */
    BYTE    byRes[167];                                     /* 保留字段  Reserved */
}NETDEV_FINDDATA_S,*LPNETDEV_FINDDATA_S;

/**
 * @brief 按文件名回放录像参数 结构体定义 Parameters of play back recordings by file name Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlayBackInfo
{
    char    szName[NETDEV_LEN_260];         /* 回放的控制块名称  Playback control block name*/
    INT64   tBeginTime;                     /* 回放开始时间  Playback start time */
    INT64   tEndTime;                       /* 回放结束时间  Playback end time */
    INT32   dwLinkMode;                     /* 传输协议,参见枚举#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* 播放窗口句柄  Play window handle */
    INT32   dwFileType;                     /* 录像存储类型,参见枚举#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;                /* 下载速度 参见枚举#NETDEV_E_DOWNLOAD_SPEED_E  Download speed, see enumeration #NETDEV_E_DOWNLOAD_SPEED_E */
    INT32   dwStreamMode;                   /*  启流模式，参见枚举#NETDEV_STREAM_MODE_E  stream mode see #NETDEV_STREAM_MODE_E */
    BYTE    byRes[252];                     /* 保留字段  Reserved */
}NETDEV_PLAYBACKINFO_S, *LPNETDEV_PLAYBACKINFO_S;

/**
 * @brief 图像数据 结构体定义 Image data Structure definition
 *        存放解码后图像数据的指针和长度等信息 Storing pointer and length of decoded picture data
 * @attention 无 None
 */
typedef struct tagNETDEVPictureData
{
    BYTE    *pucData[4];                /* pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针  pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32   dwLineSize[4];              /* ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距  ulLineSize[0]: Y line spacing, ulLineSize[1]: U line spacing, ulLineSize[2]: V line spacing */
    INT32   dwPicHeight;                /* 图片高度  Picture height */
    INT32   dwPicWidth;                 /* 图片宽度  Picture width */
    INT32   dwRenderTimeType;           /* 用于渲染的时间数据类型  Time data type for rendering */
    INT64   tRenderTime;                /* 用于渲染的时间数据  Time data for rendering */
}NETDEV_PICTURE_DATA_S, *LPNETDEV_PICTURE_DATA_S;

/**
* 解码后视频流数据回调函数的指针类型  Type of pointer to callback function for decoded video stream data 
* @param [IN] lpPlayHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pstPictureData    存放解码后视频流数据信息缓冲区指针 Pointer to buffer that stores decoded video stream data
* @param [IN] lpUserParam       用户设置参数,即用户在调用#NDPlayer_SetDecodeVideoDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetDecodeVideoDataCB function
* @return 无. None.
* @note
* -     1.用户应及时处理输出的视频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
* -     1. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
* -     2.视频数据是yv12格式.排列顺序“Y0-Y1-......”,“U0-U1-......”,“V0-V1-......”
* -     2. Video data is in yv12 format in sequence of Y0-Y1-......, U0-U1-......, V0-V1-......
*/
typedef void (STDCALL* NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                             IN const NETDEV_PICTURE_DATA_S *pstPictureData,
                                                             IN LPVOID lpUserParam);

/**
 * @brief 按时间回放录像参数 结构体定义 Parameters of play back by time Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlayBackCondition
{
    INT32   dwChannelID;                /* 回放的通道  Playback channel */
    INT64   tBeginTime;                 /* 回放开始时间  Playback start time */
    INT64   tEndTime;                   /* 回放结束时间  Playback end time */
    INT32   dwLinkMode;                 /* 传输协议，参见枚举#NETDEV_TRANS_PROTOCAL_E */
    LPVOID  hPlayWnd;                   /* 播放窗口句柄  Play window handle */
    INT32   dwFileType;                 /* 录像存储类型，参见枚举#NETDEV_STORE_TYPE_E  */
    INT32   dwDownloadSpeed;            /* 下载速度 参见枚举#NETDEV_E_DOWNLOAD_SPEED_E  Download speed, see enumeration #NETDEV_E_DOWNLOAD_SPEED_E */
    INT32   dwStreamMode;               /* 启流模式，参见枚举#NETDEV_STREAM_MODE_E  stream mode see #NETDEV_STREAM_MODE_E */
    INT32   dwStreamIndex;              /* 存储码流类型, 参见枚举#NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwRecordLocation;           /* 录像存储位置 Record Position, 参见枚举#NETDEV_RECORD_LOCATION_E */
    INT32   dwTransType;                /* 传输类型，参见枚举#NETDEV_TRANS_TYPE_E */
    BOOL    bCloudStorage;              /* 是否开启云存储回放模式 */
    BOOL    bOneFrameEnable;            /* 是否开启单帧解码模式，开启后对解码效率有影响 */
    INT32   dwPlaySpeed;                /* 回放播放速度，参考枚举#NETDEV_VOD_PLAY_STATUS_E  Playback speed, see enumeration #NETDEV_VOD_PLAY_STATUS_E*/
    NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF cbPlayDecodeVideoCALLBACK;       /* 解码后数据回调函数 Decode data callback function */
    INT64   tPlayTime;                  /* 播放时间  Playback time */
    UINT32  udwServerID;                /* 录像所属服务器ID Video server ID */
    BYTE    byRes[212];                 /* 保留字段   */
}NETDEV_PLAYBACKCOND_S, *LPNETDEV_PLAYBACKCOND_S;

/**
 * @brief 云台预置位信息 结构体定义 PTZ preset information Structure definition
 * @attention 无 None
 */
typedef struct tagstNETDEVPtzPreset
{
    INT32   dwPresetID;                                 /* 预置位ID  Preset ID */
    CHAR    szPresetName[NETDEV_LEN_32];                /* 预置位名称  Preset name */
}NETDEV_PTZ_PRESET_S, *LPNETDEV_PTZ_PRESET_S;

/**
 * @brief 所有云台预置位 结构体定义 All PTZ presets Structure definition
 * @attention 无 None
 */
typedef struct tagstNETDEVPtzAllPresets
{
    INT32               dwSize;                             /* 预置位总数  Total number of presets */
    NETDEV_PTZ_PRESET_S astPreset[NETDEV_MAX_PRESET_NUM];   /* 预置位信息结构体  Structure of preset information */
}NETDEV_PTZ_ALLPRESETS_S, *LPNETDEV_PTZ_ALLPRESETS_S;

/**
 * @brief 云台预置位巡航轨迹点信息 结构体定义 PTZ preset patrol point information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCruisePoint
{
    INT32   dwPresetID;     /* 预置位ID  Preset ID */
    INT32   dwStayTime;     /* 停留时间  Stay time */
    INT32   dwSpeed;        /* 转动速度,范围[1-10]  Speed [1-10] */
    INT32   dwID;           /* 巡航动作ID */
}NETDEV_CRUISE_POINT_S, *LPNETDEV_CRUISE_POINT_S;

/**
 * @brief 云台预置位巡航路径详细信息 结构体定义 PTZ preset patrol route information Structure definition 
 * @attention 无 None
 */
typedef struct tagNETDEVCruiseInfo
{
    INT32                   dwCuriseID;                                     /* 轨迹ID  Route ID */
    CHAR                    szCuriseName[NETDEV_LEN_32];                    /* 轨迹名称  Route name */
    INT32                   dwSize;                                         /* 路径包含的轨迹点数量  Number of presets included in the route */
    NETDEV_CRUISE_POINT_S   astCruisePoint[NETDEV_MAX_CRUISEPOINT_NUM];     /* 路径包含的轨迹点信息   Information of presets included in the route */
}NETDEV_CRUISE_INFO_S, *LPNETDEV_CRUISE_INFO_S;

/**
 * @brief 云台预置位巡航路径列表 结构体定义 PTZ preset patrol route list Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCruiseList
{
    INT32                   dwSize;                                         /* 巡航路径数量  Number of patrol routes */
    NETDEV_CRUISE_INFO_S    astCruiseInfo[NETDEV_MAX_CRUISEROUTE_NUM];      /* 巡航路径信息  Information of patrol routes */
}NETDEV_CRUISE_LIST_S, *LPNETDEV_CRUISE_LIST_S;

/**
 * @brief 云台轨迹巡航路径信息 结构体定义 Route information of PTZ route patrol Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPtzTrackinfo
{
    INT32 dwTrackNum;                                               /* 已存在的巡航轨迹的数量  Number of existing patrol routes */
    CHAR  aszTrackName[NETDEV_TRACK_CRUISE_MAXNUM][NETDEV_LEN_64];  /* 轨迹名称  Route name */
}NETDEV_PTZ_TRACK_INFO_S, *LPNETDEV_PTZ_TRACK_INFO_S;

/**
 * @brief 云台轨迹巡航路径信息 结构体定义 Route information of PTZ route patrol Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPtzTrackInfoV30
{
    UINT32 udwTrackID;                                                   /* 巡航轨迹的ID */
    CHAR   szTrackName[NETDEV_LEN_64];                                   /* 轨迹名称  RouteID */
    BYTE   byRes[64];                                                    /* 保留字段 */
}NETDEV_PTZ_TRACK_INFO_V30_S, *LPNETDEV_PTZ_TRACK_INFO_V30_S;

/**
 * @brief 云台轨迹巡航路径信息列表
 * @attention 无 None
 */
typedef struct tagNETDEVPtzTrackListV30
{
    INT32 dwTrackNum;                                                           /* 已存在的巡航轨迹的数量  Number of existing patrol routes */
    NETDEV_PTZ_TRACK_INFO_V30_S astTrackInfo[NETDEV_TRACK_CRUISE_MAXNUM];       /* 轨迹名称  RouteID */
}NETDEV_PTZ_TRACK_LIST_V30_S, *LPNETDEV_PTZ_TRACK_LIST_V30_S;

/**
 * @brief 云台状态 结构体定义 PTZ status Structure definition
 * @attention 绝对水平坐标与角度对应关系：0到1对应0到180度，-1到0对应180到360度  Absolute horizontal coordinates correspond to angles: 0 to 1 correspond to 0 to 180 degrees, and -1 to 0 correspond 180 to 360 degrees 
              绝对竖直坐标与角度对应关系：0到1对应0到90度  Absolute vertical coordinates correspond to angles: 0 to 1 correspond to 0 to 90 degrees 
              绝对聚焦倍数与实际倍数对应关系：0到1对应0到最大倍数  Absolute multiples correspond to the actual multiples: 0 to 1, correspond to 0 to maximum multiples 
 */
typedef struct tagNETDEVPTZStatus
{
    FLOAT                       fPanTiltX;              /* 绝对水平坐标  Absolute horizontal coordinates*/
    FLOAT                       fPanTiltY;              /* 绝对竖直坐标  Absolute vertical coordinates*/
    FLOAT                       fZoomX;                 /* 绝对聚焦倍数  Absolute multiples*/
    NETDEV_PTZ_MOVE_STATUS_E    enPanTiltStatus;        /* 云台状态  PTZ Status*/
    NETDEV_PTZ_MOVE_STATUS_E    enZoomStatus;           /* 聚焦状态  Focus Status*/
}NETDEV_PTZ_STATUS_S, *LPNETDEV_PTZ_STATUS_S;

/**
 * @brief 绝对坐标移动 结构体定义  Absolute coodinates Structure definition
 * @attention  绝对水平坐标与角度对应关系：0到1对应0到180度，-1到0对应180到360度  Absolute horizontal coordinates correspond to angles: 0 to 1 correspond to 0 to 180 degrees, and -1 to 0 correspond 180 to 360 degrees 
               绝对竖直坐标与角度对应关系：0到1对应0到90度  Absolute vertical coordinates correspond to angles: 0 to 1 correspond to 0 to 90 degrees 
               绝对聚焦倍数与实际倍数对应关系：0到1对应0到最大倍数  Absolute multiples correspond to the actual multiples: 0 to 1, correspond to 0 to maximum multiples 
 */
typedef struct tagNETDEVPTZAbsoluteMove
{
    FLOAT                       fPanTiltX;                          /* 绝对水平坐标 Absolute horizontal coordinates*/
    FLOAT                       fPanTiltY;                          /* 绝对竖直坐标 Absolute vertical coordinates*/
    FLOAT                       fZoomX;                             /* 绝对聚焦倍数 Absolute multiples*/
}NETDEV_PTZ_ABSOLUTE_MOVE_S, *LPNETDEV_PTZ_ABSOLUTE_MOVE_S;

/**
 * @brief 矩形区域 结构体定义 Rectangle Area  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVRect
{
    INT32   dwLeft;                               /* x轴左点值[0,10000]  X axis left point value [0,10000] */
    INT32   dwTop;                                /* y轴顶点值[0,10000]  Y axis top point value [0,10000] */
    INT32   dwRight;                              /* x轴右点值[0,10000]  X axis right point value [0,10000] */
    INT32   dwBottom;                             /* y轴底点值[0,10000]  Y axis bottom point value [0,10000] */
}NETDEV_RECT_S, *LPNETDEV_RECT_S;

/**
 * @brief 图像区域信息 结构体定义 Image area information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPtzOperateAreaInfo
{
    INT32   dwBeginPointX;      /* 区域起始点X值[0,10000]  Area start point X value [0,10000] */
    INT32   dwBeginPointY;      /* 区域起始点Y值[0,10000]  Area start point Y value [0,10000] */
    INT32   dwEndPointX;        /* 区域结束点X值[0,10000]  Area end point X value [0,10000] */
    INT32   dwEndPointY;        /* 区域结束点Y值[0,10000]  Area end point Y value [0,10000] */
}NETDEV_PTZ_OPERATEAREA_S, *LPNETDEV_PTZ_OPERATEAREA_S;


/**
 * @brief 云台拉框缩放结构体
 * @attention 无 None
 */
typedef struct tagNETDEVPTZZoomAreaInfo
{
    UINT32      udwMidPointX;      /* 拉框中心横坐标 */
    UINT32      udwMidPointY;      /* 拉框中心纵坐标 */
    UINT32      udwLengthX;        /* 拉框长度 */
    UINT32      udwLengthY;        /* 拉框宽度 */
    UINT32      udwWidth;          /* 实际播放窗口长度 */
    UINT32      udwHeight;         /* 实际播放窗口宽度 */
    BYTE        byRes[64];         /* 保留字段   */
}NETDEV_PTZ_ZOOM_AREA_INFO_S, *LPNETDEV_PTZ_ZOOM_AREA_INFO_S;


/**
 * @brief 云台轨迹巡航状态信息
 * @attention 无 None
 */
typedef struct tagNETDEVPTZTrackStatusInfo
{
    INT32 dwStatus;         /* 通道巡航状态  参见NETDEV_PTZ_TRACK_STATUS_E*/
    INT32 dwPatrolID;       /*录制或者巡航路线序号*/
}NETDEV_PTZ_TRACK_STATUS_INFO_S, *LPNETDEV_PTZ_TRACK_STATUS_INFO_S;

/**
 * @brief 云台守望信息结构体
 * @attention 无 None
 */
typedef struct tagNETDEVPTZGuardInfo
{
    BOOL             bEnabled;                          /* 云台守望使能 */
    UINT32           udwMode;                           /* 云台守望模式，请参考枚举 NETDEV_PTZ_GUARD_MODE_E */
    UINT32           udwParam;                          /* 参数,当Mode为0时，Param表示预置位序号，从1开始; 当Mode为1时，Param表示巡航线路索引，从0开始;当Mode为2时，Param表示轨迹巡航线路索引，从0开始。 */
    UINT32           udwTime;                           /* 守望时间，云台静默此时间后自动守望，单位s */
    BYTE             byRes[32];                         /* 保留字段 */
}NETDEV_PTZ_GUARD_INFO_S, *LPNETDEV_PTZ_GUARD_INFO_S;

/**
 * @enum tagNETDEVPTZDireection
 * @brief 云台方位 
 * @attention 无 None
 */
typedef enum tagNETDEVPTZDirection
{
    NETDEV_PTZ_DIRECTION_EAST           = 0,            /* 东 east */
    NETDEV_PTZ_DIRECTION_SOUTHEAST      = 1,            /* 东南 southeast */
    NETDEV_PTZ_DIRECTION_SOUTH          = 2,            /* 南 south */
    NETDEV_PTZ_DIRECTION_SOUTHWEST      = 3,            /* 西南 southwest */
    NETDEV_PTZ_DIRECTION_WEST           = 4,            /* 西 west */
    NETDEV_PTZ_DIRECTION_NORTHWEST      = 5,            /* 西北 northwest */
    NETDEV_PTZ_DIRECTION_NORTH          = 6,            /* 北 north */
    NETDEV_PTZ_DIRECTION_NORTHEAST      = 7,            /* 东北 northeast  */
    NETDEV_PTZ_DIRECTION_AUTO           = 8,            /* 自动 auto */

    NETDEV_PTZ_DIRECTION_INVALID        = 0xFFFF        /* 无效值 invalid value */
}NETDEV_PTZ_DIRECTION_E;

/**
 * @struct tagNETDEVPTZOrientationInfo
 * @brief 云台方位标定信息 结构体定义
 * @attention  
 */
typedef struct tagNETDEVPTZOrientationInfo
{
    INT32   dwDirection;                /* 云台方位信息 参见枚举NETDEV_PTZ_DIRECTION_E Direction Info see enumeration #NETDEV_PTZ_DIRECTION_E */
    BYTE    byRes[252];                 /* 保留字段  Reserved */

}NETDEV_PTZ_ORIENTATION_INFO_S, *LPNETDEV_PTZ_ORIENTATION_INFO_S;

/**
* @brief 音频参数
* @attention 无
*/
typedef struct tagNETDEVAudioSampleParamType
{
    INT32 dwChannels;                               /* 声道数,单声道为1,立体声为2 */
    INT32 dwSampleRate;                             /* 采样率 */
    NETDEV_AUDIO_SAMPLE_FORMAT_E enSampleFormat;    /* 位宽 */
}NETDEV_AUDIO_SAMPLE_PARAM_S, *LPNETDEV_AUDIO_SAMPLE_PARAM_S;

/**
 * @brief 音频数据 结构体定义 Audio data Structure definition
 *        存放解码后音频数据的指针和长度等信息 Storing pointer and length of decoded picture data
 * @attention 无 None
 */
typedef struct tagNETDEVWaveData
{
    CHAR  *pcData;                      /* 音频数据指针  Audio data pointer */
    INT32 dwDataLen;                    /* 音频数据长度  Audio data length */
    INT32 dwWaveFormat;                 /* 解码后音频格式  Format of decoded audio*/
}NETDEV_WAVE_DATA_S, *LPNETDEV_WAVE_DATA_S;

/**
* @brief 存放拼帧后音频数据的指针和长度等信息的结构体定义
* @attention 无
*/
typedef struct tagNETDEVParseAudioData
{
    BYTE *pucData;                  /* 音频数据指针 Audio data pointer */
    UINT32 udwDataLen;              /* 音频数据长度 Audio data length */
    UINT32 udwAudioCodeFormat;      /* 音频编码格式,参见#NETDEV_AUDIO_ENCODE_TYPE_E */
    UINT32 udwWaveFormat;           /* 音频数据解码后音频格式, 参见#NETDEV_WAVE_FORMAT_INFO_E */
    INT64 tTimeStamp;               /* 时间戳 Time stamp (ms)*/
    BYTE  byRes[8];                 /* 保留字段  Reserved */
}NETDEV_PARSE_AUDIO_DATA_S, *LPNETDEV_PARSE_AUDIO_DATA_S;

/**
 * @brief 视频解析数据 结构体定义 Video analytic data Structure definition
 *        存放拼帧后视频数据的指针和长度等信息 Storing pointer and length of framed video data
 * @attention 无 None
 */
typedef struct tagNETDEVParseVideoData
{
    BYTE   *pucData;             /* 视频数据指针  Pointer to video data */
    INT32  dwDataLen;            /* 视频数据长度  Video data length */
    INT32  dwVideoFrameType;     /* 视频帧类型,参考枚举#NETDEV_VIDEO_FRAME_TYPE_E  Frame type, see enumeration #NETDEV_VIDEO_FRAME_TYPE_E */
    INT32  dwVideoCodeFormat;    /* 视频编码格式,参考枚举#NETDEV_VIDEO_CODE_TYPE_E  Video encoding format, see enumeration #NETDEV_VIDEO_CODE_TYPE_E  */
    INT32  dwHeight;             /* 视频图像高度  Video image height */
    INT32  dwWidth;              /* 视频图像宽度  Video image width */
    INT64  tTimeStamp;           /* 时间戳（毫秒） Time stamp (ms) */
    BYTE  byRes[8];              /* 保留字段  Reserved */
}NETDEV_PARSE_VIDEO_DATA_S, *LPNETDEV_PARSE_VIDEO_DATA_S;


/**
 * @brief 视频通道详细信息 结构体定义  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoChlDetailInfo
{
    INT32                       dwChannelID;                        /* 通道ID  Channel ID */
    BOOL                        bPtzSupported;                      /* 是否支持云台 Whether ptz is supported */
    NETDEV_CHANNEL_STATUS_E     enStatus;                           /* 通道状态  Channel status NETDEV_CHANNEL_STATUS_E*/
    INT32                       dwStreamNum;                        /* 流个数  Number of streams 当enStatus为NETDEV_CHL_STATUS_UNBIND时，此值无效*/
    CHAR                        szChnName[NETDEV_LEN_64];           /* 通道名称 Channel Name */
    BYTE                        byRes[4];                           /* 保留字段  Reserved field*/
}NETDEV_VIDEO_CHL_DETAIL_INFO_S, *LPNETDEV_VIDEO_CHL_DETAIL_INFO_S;

/**
 * @brief 视频通道详细信息 结构体定义  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoChlDetailInfoEx
{
    INT32                       dwChannelID;                        /* 通道ID  Channel ID */
    BOOL                        bPtzSupported;                      /* 是否支持云台 Whether ptz is supported */
    NETDEV_CHANNEL_STATUS_E     enStatus;                           /* 通道状态  Channel status NETDEV_CHANNEL_STATUS_E */
    INT32                       dwStreamNum;                        /* 流个数  Number of streams 当enStatus为NETDEV_CHL_STATUS_UNBIND时，此值无效*/
    NETDEV_CHANNEL_TYPE_E       enChannelType;                      /* 通道类型，(note: 该字段仅对混合NVR有效) */
    NETDEV_VIDEO_STANDARD_E     enVideoFormat;                      /* 视频输入制式，当ChannelType为NETDEV_CHL_TYPE_DIGITAL时，此值无效 (note: 该字段仅对混合NVR有效) */
    NETDEV_HOSTTYPE_E           enAddressType;                      /* IP地址类型 */
    CHAR                        szIPAddr[NETDEV_IPADDR_STR_MAX_LEN];/* IP地址 IP address*/
    INT32                       dwPort;                             /* 端口号 */
    CHAR                        szChnName[NETDEV_LEN_64];           /* 通道名称 Channel Name */
    BOOL                        allowDistribution;                   /* 是否允许流分发*/
    INT32                       dwDeviceType;                       /* 通道接入的设备类型，参见枚举NETDEV_CHANNEL_CAMERA_TYPE_E. Channel device Type see#NETDEV_CHANNEL_CAMERA_TYPE_E */
    CHAR                        szManufacturer[NETDEV_LEN_32];      /* 厂商，范围[0,31] */
    CHAR                        szDeviceModel[NETDEV_LEN_32];       /* 设备型号，范围[0,31]  */
    BYTE                        byRes[24];                          /* 保留字段  Reserved field*/
}NETDEV_VIDEO_CHL_DETAIL_INFO_EX_S, *LPNETDEV_VIDEO_CHL_DETAIL_INFO_EX_S;


/**
* @brief 视频源分辨率信息 Video resolution
* @attention 无
*/
typedef struct tagNETDEVVideoResolution
{
    INT32 dwWidth;
    INT32 dwHeight;
}NETDEV_VIDEO_RESOLUTION_S, *LPNETDEV_VIDEO_RESOLUTION_S;


/**
* @brief 取值范围 Range
* @attention 无
*/
typedef struct tagNETDEVRange
{
    INT32   dwMin;
    INT32   dwMax;
}NETDEV_RANGE_S, *LPNETDEV_RANGE_S;

/**
* @brief 视频编码参数选项 Video encode option
* @attention 无
*/
typedef struct tagNETDEVVideoEncodeOption
{
    INT32                       dwEncodeType;                                       /* 编码格式 NETDEV_VIDEO_CODE_TYPE_E*/
    INT32                       dwResolutionSize;                                   /* 分辨率数量 Resolution size */
    NETDEV_VIDEO_RESOLUTION_S   astResolution[NETDEV_RESOLUTION_NUM_MAX];           /* 分辨率 Resolution */
    NETDEV_RANGE_S              stIFrameInterval;                                   /* I帧间隔 I frame interval */
    NETDEV_RANGE_S              stFrameRate;                                        /* 帧率 Frame rate */
    NETDEV_RANGE_S              stEncodingInterval;                                 /* 编码间隔 Encode interval */
    NETDEV_RANGE_S              stBitRate;                                          /* 码率 Bit rate */
}NETDEV_VIDEO_ENCODE_OPTION_S, *LPNETDEV_VIDEO_ENCODE_OPTION_S;

/**
* @brief 视频码流参数能力集 Video stream Cap
* @attention 无
*/
typedef struct tagNETDEVVideoStreamCap
{
    INT32                           dwStreamType;                                   /* 码流类型 入参 参见 NETDEV_LIVE_STREAM_INDEX_E */
    INT32                           dwEncodeCapSize;                                /* 编码能力集个数 Encode capability size */
    NETDEV_VIDEO_ENCODE_OPTION_S    astEncodeCap[NETDEV_VIDEO_ENCODE_TYPE_MAX];     /* 编码能力 Encode capability */
    NETDEV_RANGE_S                  stQuality;                                      /* 图像质量范围 Quality range */
}NETDEV_VIDEO_STREAM_CAP_S, *LPNETDEV_VIDEO_STREAM_CAP_S;

/**
 * @brief 日志查询条件 结构体定义 Log query condition Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFindLogCond
{
    INT32      dwMainType;         /* 日志类型, 请参考#NETDEV_LOG_MAIN_TYPE_E。 Log type. See #NETDEV_LOG_MAIN_TYPE_E for reference */
    INT32      dwSubType;          /* 日志子类型, 请参考#NETDEV_LOG_SUB_TYPE_E。 Sub type. See #NETDEV_LOG_SUB_TYPE_E for reference */
    INT64      tBeginTime;         /* 起始时间  Start time */
    INT64      tEndTime;           /* 结束时间  End time */
    INT32      dwLimitNum;         /* 每次查询的数量 Number of each query*/
    INT32      dwOffset;           /* 从序号几开始查询，序号从0开始 Start search from No. X. X starts from 0*/
}NETDEV_FIND_LOG_COND_S, *LPNETDEV_FIND_LOG_COND_S;

/**
* @brief 日志信息 结构体定义 Definition of log info structure
* @attention 无
*/
typedef struct tagNETDEVOptLogInfo
{
    INT64       tTime;                                  /* 日志时间 Log time*/
    INT32       dwMainType;                             /* 日志主类型, 请参考 #NETDEV_LOG_MAIN_TYPE_E。 Main Type.See #NETDEV_LOG_MAIN_TYPE_E for reference*/
    INT32       dwSubType;                              /* 日志子类型, 请参考 #NETDEV_LOG_SUB_TYPE_E。 Sub Type.See #NETDEV_LOG_SUB_TYPE_E for reference*/
    INT32       dwChannelID;                            /* 日志来源 Log source*/
    CHAR        szUserName[NETDEV_NAME_MAX_LEN];        /* 用户名 Username*/
    CHAR        szUserAddr[NETDEV_IPADDR_STR_MAX_LEN];  /* 用户IP地址 User IP address*/
    BYTE        bRes[256];                              /* 保留字段 Reserved */
}NETDEV_LOG_INFO_S,*LPNETDEV_LOG_INFO_S;

/***************** 告警业务  Alarm services**************************************************/
/**
 * @brief 告警信息 结构体定义 Alarm information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInfo
{
    INT32   dwAlarmType;                    /* 告警类型,参见枚举#NETDEV_ALARM_TYPE_E  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT64   tAlarmTime;                     /* 告警发生时间  Alarm time */
    INT32   dwChannelID;                    /* 通道号,用于NVR  Channel ID for NVR */
    UINT16  wIndex;                         /* 索引号  Index number,  index number */
    CHAR    *pszName;                       /* 告警源名称,开关量名称 Alarm source name, alarm input/output name */
    INT32   dwTotalBandWidth;               /* 当前带宽总量,单位为MBps  Current total bandwidth (in MBps) */
    INT32   dwUnusedBandwidth;              /* 未使用的带宽,单位为MBps  Bandwidth left (in MBps)*/
    INT32   dwTotalStreamNum;               /* 总路数 Total cameras*/
    INT32   dwFreeStreamNum;                /* 未使用路数 Cameras left */
    INT32   dwMediaMode;                    /* 流类型,参见枚举#NETDEV_MEDIA_MODE_E Stream type. For enumerations, see#NETDEV_MEDIA_MODE_E*/
    INT32   dwReserved;                     /* 异常上报保留参数，用于上报解码层保留参数 */
    BYTE    byRes[6];                       /* 保留字段  Reserved */
}NETDEV_ALARM_INFO_S, *LPNETDEV_ALARM_INFO_S;

/**
 * @brief 告警订阅信息 结构体定义 Alarm subscribe information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmSubscribeInfo
{
    INT32   dwAlarmType;                    /* 订阅的告警类型 参见NETDEV_SUBSCRIBE_ALARM_TYPE_E 多个类型使用或运算 */
    BYTE    byRes[44];                      /* 保留字段  Reserved */
}NETDEV_ALARM_SUB_INFO_S, *LPNETDEV_ALARM_SUB_INFO_S;

/**
 * @brief  拉告警信息 结构体定义 Get alarm information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPullAlarmInfo
{
    NETDEV_ALARM_TYPE_E   enAlarm;         /* 告警类型  Alarm type */
    INT32   dwChancelId;                   /* 通道号,用于NVR  Channel ID for NVR */
}NETDEV_PULLALARM_INFO_S, *LPNETDEV_PULLALARM_INFO_S;

/********************** 客流量统计 Passenger flow statistic **************************/
/**
 * @brief  客流量统计信息 结构体定义 Passenger flow statistic infomation Sturcture definition
 * @attention 无 None
 */
typedef struct tagNETDEVPassengerFlowStatisticData
{
    INT32   dwChannelID;            /* 通道号 Channel ID */
    INT64   tReportTime;            /* 上报时间（unix时间戳） Report time */
    INT32   tInterval;              /* 间隔时间 Interval time */
    INT32   dwEnterNum;             /* 进入人数 Enter num */
    INT32   dwExitNum;              /* 离开人数 Exit num */
    INT32   dwTotalEnterNum;        /* 所有进入人数 Total enter num */
    INT32   dwTotalExitNum;         /* 所有离开人数 Total exit num */
}NETDEV_PASSENGER_FLOW_STATISTIC_DATA_S, *LPNETDEV_PASSENGER_FLOW_STATISTIC_DATA_S;


/**
 * @brief 连接及socket缓存信息
 * @attention
 */
typedef struct tagNETDEVTmsConnectInfo
{ 
    UINT32   udwPktVer;          /* 报文版本 */ 
    UINT32   udwTmsProtoCmd;     /* Tms协议命令码 */
    CHAR     *pcRecvBuf;         /* socket接收数据缓冲 */
    UINT32   udwBufMaxLen;       /* RecvBuf的总长度 */
    UINT32   udwPktTotalLen;     /* 通信协议层面数据包的总长度，包含同步头、同步尾 */
    BOOL     bHdrParsed;         /* 报文头解析完成标志 */
    BYTE     bRes[32];           /* 保留字段 Reserved */
}NETDEV_TMS_CONNECT_INFO_S, *LPNETDEV_TMS_CONNECT_INFO_S;

/**
 * @brief 人员信息
 * @attention
 */
typedef  struct tagNETDEVTMSPersonInfo
{
    UINT32 udwFaceId;                                      /* 人脸ID，可能为0，表示无xml对应元素 */
    CHAR   szCamerID[NETDEV_TMS_CAMER_ID_LEN];             /* 相机编号 */
    CHAR   szRecordID[NETDEV_TMS_FACE_RECORD_ID_LEN];      /* 记录ID号 */
    CHAR   szTollgateID[NETDEV_TMS_FACE_TOLLGATE_ID_LEN];  /* 卡口编号 */
    CHAR   szPassTime[NETDEV_TMS_PASSTIME_LEN];            /* 经过时间 */
    BOOL   bFinishFlag;                                    /* 解析完成标志 */
    BYTE   bRes[128];                                      /* 保留字段 Reserved */

}NETDEV_TMS_PERSION_INFO_S, *LPNETDEV_TMS_PERSION_INFO_S;

/**
 * @brief 人脸位置信息
 * @attention
 */
typedef struct tagNETDEVFacePositionInfo
{
    INT32   dwTopLeftX;           /* 左上角X [0, 10000]  Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /* 左上角Y [0, 10000]  Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /* 右下角X [0, 10000]  Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /* 右下角Y [0, 10000]  Lower right corner y [0, 10000] */
    BYTE     bRes[32];           /* 保留字段 Reserved */
}NETDEV_FACE_POSITION_INFO_S, *LPNETDEV_FACE_POSITION_INFO_S;

/**
 * @brief 人脸小图信息
 * @attention
 */
typedef struct tagNETDEVTMSPersionFaceInfo
{ 
    UINT32 udwFaceId;                                /* 人脸ID */
    NETDEV_FACE_POSITION_INFO_S stFacePos;           /* 人脸坐标---画面坐标归一化：0-10000 ;  矩形左上和右下点："138,315,282,684" */
    BYTE   bRes[64];                                 /* 保留字段 Reserved */

}NETDEV_TMS_PERSION_FACE_INFO_S, *LPNETDEV_TMS_PERSION_FACE_INFO_S;

/**
 * @brief 人脸图片详细参数
 * @attention
 */
typedef struct tagNETDEVTMSPersionPicInfo
{
    UINT32                              udwFaceId;                                  /* 人脸ID(Face节点解析到此)， 不会为0 */
    UINT32                              udwPiclen;                                  /* 报文信息中图片长度 */
    CHAR                                szPassTime[NETDEV_TMS_PASSTIME_LEN];        /* 经过时刻 */
    NETDEV_TMS_PERSION_FACE_INFO_S      stFaceInfo;                                 /* 人脸小图信息 */
    NETDEV_TMS_PERSION_IMAGE_TYPE_E     enImgType;                                  /* 图像类型 */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_E   enImgFormat;                                /* 图像格式 */
    UINT32                              udwImageWidth;                              /* 图像宽度*/
    UINT32 udwImageHeight;                                                          /* 图像高度*/
    UINT32                              udwFaceNum;                                 /* 人脸个数 全景图时有效*/
    BYTE   bRes[252];                                                               /* 保留字段 Reserved*/
}NETDEV_TMS_PERSION_PIC_INFO_S, *LPNETDEV_TMS_PERSION_PIC_INFO_S;

/**
 * @brief 人脸识别解析后信息
 * @attention
 */
typedef struct tagNETDEVTMSFaceParseInfo
{ 
    UINT32                          udwFaceNum;                 /* 人脸个数 */
    UINT32                          udwImageNum;                /* pstTMSPersonPicInfo 的个数 */
    CHAR                            *pcPktPicDataPtr;           /* 人脸图片报文起始指针 */
    NETDEV_TMS_PERSION_INFO_S       stTMSPersonInfo;            /* 人员信息 */
    LPNETDEV_TMS_PERSION_PIC_INFO_S pstTMSPersonPicInfo;        /* 人脸图片详细参数 */
    BYTE                            bRes[64];                   /* 保留字段 Reserved */
}NETDEV_TMS_FACE_PARSE_INFO_S, *LPNETDEV_TMS_FACE_XML_INFO_S;

/**
 * @brief 热度图报文XML解析信息
 * @attention
 */
typedef struct tagNETDEVTMSHeatMapXmlInfo
{
    CHAR  szDevID[NETDEV_TMS_HEAT_MAP_DEVID_LEN];                           /* 设备编号 */
    CHAR  szRecordID[NETDEV_TMS_HEAT_MAP_RECORD_ID_LEN];                    /* 记录ID号 */
    CHAR  szCollectTime[NETDEV_TMS_HEAT_MAP_COllECT_TIME_LEN];              /* 采集时间 */
    INT32 dwColumns;                                                        /* 检测列数 */
    INT32 dwRows;                                                           /* 检测行数 */
    INT32 dwIntervalTime;                                                   /* 检测间隔 单位min*/
    BYTE  bRes[256];                                                        /* 保留字段 Reserved */
}NETDEV_TMS_HEAT_MAP_XML_INFO_S, *LPNETDEV_TMS_HEAT_MAP_XML_INFO_S;

/**
 * @brief 热度图报文区域解析信息
 * @attention
 */
typedef struct tagNETDEVTMSHeatMapPicInfo
{
    UINT32  udwPicSize;                                                     /* 区域大小 */
    CHAR    *pcPicData;                                                     /* 区域数据 */
}NETDEV_TMS_HEAT_MAP_PIC_INFO_S,*LPNETDEV_TMS_HEAT_MAP_PIC_INFO_S;

/**
 * @brief 热度图报文数据信息
 * @attention
 */
typedef struct tagNETDEVTMSHeatMapInfo
{
    UINT32                            udwPicNum;                                /* 区域个数 Picture Number */
    NETDEV_TMS_HEAT_MAP_XML_INFO_S    stTmsXmlInfo;                             /* XML信息 XML Information */
    NETDEV_TMS_HEAT_MAP_PIC_INFO_S    stTmsPicInfo[NETDEV_TMS_PIC_COMMON_NUM];  /* 区域信息 Picture Message */
    CHAR                              szIPAddr[NETDEV_IPV4_LEN_MAX];            /* 设备IP地址 */
}NETDEV_TMS_HEAT_MAP_INFO_S,*LPNETDEV_TMS_HEAT_MAP_INFO_S;

/**
 * @brief 车牌识别报文XML解析信息
 * @attention
 */
typedef struct tagNETDEVTMSCarPlateXmlInfo
{
    CHAR szCamID[NETDEV_TMS_CAR_PLATE_CAMID_LEN];                               /* 卡口相机编号 */
    CHAR szRecordID[NETDEV_TMS_CAR_PLATE_RECORDID_LEN];                         /* 记录ID号 */
    CHAR szTollgateID[NETDEV_TMS_CAR_PLATE_TOLLGATE_LEN];                       /* 卡口编号 */
    CHAR szPassTime[NETDEV_TMS_CAR_PLATE_PASSTIME_LEN];                         /* 经过时刻 */
    CHAR szLaneID[NETDEV_TMS_CAR_PLATE_LANEID_LEN];                             /* 车道编号 */
    CHAR szCarPlate[NETDEV_TMS_CAR_PLATE_CARPLATE_LEN];                         /* 车牌号码 */
    BYTE bRes[512];                                                             /* 保留字段 Reserved */

}NETDEV_TMS_CAR_PLATE_XML_INFO_S, *LPNETDEV_TMS_CAR_PLATE_XML_INFO_S;

/**
 * @brief 车牌识别报文图片解析信息
 * @attention
 */
typedef struct tagNETDEVTMSCarPlatePicInfo
{
    UINT32  udwPicSize;                                                      /* 图片大小 */
    CHAR    *pcPicData;                                                      /* 图片数据 */
}NETDEV_TMS_CAR_PLATE_PIC_INFO_S,*LPNETDEV_TMS_CAR_PLATE_PIC_INFO_S;

/**
 * @brief 车牌识别报文数据信息
 * @attention
 */
typedef struct tagNETDEVTMSCarPlateInfo
{
    UINT32                             udwPicNum;                                   /* 图片个数 Picture Number */
    NETDEV_TMS_CAR_PLATE_XML_INFO_S    stTmsXmlInfo;                                /* XML信息 XML Information */
    NETDEV_TMS_CAR_PLATE_PIC_INFO_S    stTmsPicInfo[NETDEV_TMS_PIC_COMMON_NUM];     /* 图片信息 Picture Message */
    CHAR                               szIPAddr[NETDEV_IPV4_LEN_MAX];               /* 设备IP地址 */
}NETDEV_TMS_CAR_PLATE_INFO_S,*LPNETDEV_TMS_CAR_PLATE_INFO_S;

/**
 * @brief 人脸抓拍信息结构体（上报用）
 * @attention
 */
typedef struct tagNETDEVTMSFaceSnapshotPicInfo
{
    UINT32   udwFaceId;                                      /* 人脸ID */
    CHAR    *pcPicBuff;                                      /* 图片缓存 */
    UINT32   udwPicBuffLen;                                  /* 图片缓存长度 */
    NETDEV_TMS_PERSION_IMAGE_TYPE_E    enImgType;            /* 图像类型，参考枚举NETDEV_TMS_PERSION_IMAGE_TYPE_E */
    NETDEV_TMS_PERSION_IMAGE_FORMAT_E  enImgFormat;          /* 图像格式，参考枚举NETDEV_TMS_PERSION_IMAGE_FORMAT_E */
    NETDEV_FACE_POSITION_INFO_S        stFacePos;            /* 人脸坐标---画面坐标归一化：0-10000 ;  矩形左上和右下点："138,315,282,684" */
    UINT32   udwImageWidth;                                  /* 图像宽度 */
    UINT32   udwImageHeight;                                 /* 图像高度 */
    CHAR     szCamerID[NETDEV_TMS_CAMER_ID_LEN];             /* 相机编号 */
    CHAR     szRecordID[NETDEV_TMS_FACE_RECORD_ID_LEN];      /* 记录ID号 */
    CHAR     szTollgateID[NETDEV_TMS_FACE_TOLLGATE_ID_LEN];  /* 卡口编号 */
    CHAR     szPassTime[NETDEV_TMS_PASSTIME_LEN];            /* 经过时刻,YYYYMMDDHHMMSSMMM，时间按24小时制。第一组MM表示月，第二组MM表示分，第三组MMM表示毫秒 */
    UINT32   udwFaceNum;                                     /* 人脸个数 全景图时有效 */
	CHAR     szIPAddr[NETDEV_IPV4_LEN_MAX];                  /* 设备IP地址 */
    BYTE     bRes[76];                                       /* 保留字段 Reserved */
}NETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S, *LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S;

/**
 * @struct tagNETDEVPhotoServerCfgInfo
 * @brief 照片接收服务器配置信息
 * @attention 无 None
 */
typedef struct tagNETDEVPhotoServerCfgInfo
{
    UINT32                          udwProtocol;                                          /* 通信协议类型 参见：NETDEV_PHOTO_SERVER_PRO_TYPE_E*/
    UINT32                          udwSubProtocol;                                       /* 通信协议子类型 参见：NETDEV_PHOTO_SERVER_SUBPRO_TYPE_E，仅在udwProtocol为1、31时有效*/
    UINT32                          udwPort;                                              /* TMS服务器端口号 [0,65535] */
    CHAR                            szIPV4Address[NETDEV_IPADDR_STR_MAX_LEN];             /* TMS服务器IPv4地址*/
    CHAR                            szTollgateID[NETDEV_LEN_64];                          /* 卡口编号(0, 36]; 可选字段，接口不携带该字段时表示不更新该字段 */
    CHAR                            CameraID[NETDEV_LEN_64];                            /* 相机编号(0, 36];可选字段，接口不携带该字段时表示不更新该字段*/

    BYTE                            byRes[128];                                           /* 保留字节 */
}NETDEV_PHOTO_SERVER_CFG_INFO,* LPNETDEV_PHOTO_SERVER_CFG_INFO;

/**
 * @struct tagNETDEVPhotoServerCfgInfoList
 * @brief 照片接收服务器配置信息列表
 * @attention 无 None
 */
typedef struct tagNETDEVPhotoServerCfgInfoList
{
    UINT32                          udwNum;                                               /* 照片服务器数量 */
    NETDEV_PHOTO_SERVER_CFG_INFO    astPhotoServerList[NETDEV_PHOTO_SERVER_MAX_NUM];      /* 照片服务器配置列表 */

    BYTE                            byRes[512];                                           /* 保留字节 */
}NETDEV_PHOTO_SERVER_CFG_INFO_LIST,* LPNETDEV_PHOTO_SERVER_CFG_INFO_LIST;

/**
 * @brief 延迟开关机参数信息
 * @attention
 */
typedef struct tagNETDEVXWDelaySwitchPower
{
    UINT32            udwOperateType;                    /* 操作方式 0:延迟开机（暂不实现）   1:延迟关机*/
    UINT32            udwDelayTime;                      /* 延迟关机时间 单位:min   范围1~720*/

    BYTE              bRes[128];                         /* 预留字段 */
}NETDEV_XW_DELAY_SWITCH_POWER_S, *LPNETDEV_XW_DELAY_SWITCH_POWER_S;

/**
 * @brief 定时开关机信息
 * @attention
 */
typedef struct tagNETDEVXWTimingSwitchPower
{
    BOOL            bPowerOnEnabled;                     /* 使能（是否开启定时开机功能）0:不使能 1:使能*/
    BOOL            bPowerOffEnabled;                    /* 使能（是否开启定时关机功能）0:不使能 1:使能*/
    CHAR            szPowerOnTime[NETDEV_LEN_16];        /* 开机时间格式：HH:MM:SS（小时:分钟: 秒)*/
    CHAR            szPowerOffTime[NETDEV_LEN_16];       /* 开机时间格式：HH:MM:SS（小时:分钟: 秒)*/

    BYTE            bRes[128];                           /* 预留字段 */
}NETDEV_XW_TIMING_SWITCH_POWER_S, *LPNETDEV_XW_TIMING_SWITCH_POWER_S;

/**
 * @brief 手动开关机参数信息
 * @attention
 */
typedef struct tagNETDEVXWManualSwitchPower
{
    UINT32            udwOperateType;                    /* 操作方式 0:开机   1:关机*/

    BYTE               bRes[128];                        /* 预留字段 */
}NETDEV_XW_MANUAL_SWITCH_POWER_S, *LPNETDEV_XW_MANUAL_SWITCH_POWER_S;

/**
 * @brief 拼接屏控制参数信息
 * @attention
 */
typedef struct tagNETDEVXWScreenCtrlParamInfo
{
    UINT32      udwCtrlType;                              /* 控制方式,参见NETDEV_XW_SCREEN_CTRL_TYPE_S */
    UINT32      udwAddressType;                           /* IP地址类型,参见NETDEV_ADDR_TYPE_E  CtrlType为0或1时，该节点必选*/
    CHAR        szIPV4Address[NETDEV_IPADDR_STR_MAX_LEN];             /* IPV4地址 当控制方式为TCP或者UDP，且IP地址类型为IPv4时，该节点必选*/
    CHAR        szIPV6Address[NETDEV_IPADDR_STR_MAX_LEN];             /* IPV6地址 当控制方式为TCP或者UDP，且IP地址类型为IPv6时，该节点必选*/
    CHAR        szDomainAddress[NETDEV_DOMAIN_LEN];       /* 域名 当控制方式为TCP或者UDP，且IP地址类型为域名时，该节点必选*/
    UINT32      udwPort;                                  /* 端口 当控制方式为TCP或者UDP时，该节点必选*/
    UINT32      udwComID;                                 /* 串口ID 当控制方式为串口时，该节点必选*/
    UINT32      udwProtocolType;                          /* 控制协议类型 参见NETDEV_XW_SCREEN_CTRL_PROTOCOL_TYPE_S*/
    BYTE        bRes[256];                                /* 预留字段 */
}NETDEV_XW_SCREEN_CTRL_PARAM_INFO_S, *LPNETDEV_XW_SCREEN_CTRL_PARAM_INFO_S;


/**
 * @brief 屏幕放大信息
 * @attention
 */
typedef struct tagNETDEVXWScreenZoomInfo
{
    UINT32            uOperatedType;                    /* 屏幕操作类型,参见NETDEV_XW_SCREEN_ZOOM_TYPE_E */
    UINT32            uOperatedMode;                    /* 屏幕操作模式,参见NETDEV_XW_SCREEN_ZOOM_MODE_E */
    UINT32            uSplitScreenIndex;                /* 需要放大到全屏的分屏序号,当uOperatedType＝0 & uOperatedMode=1时有效 */
}NETDEV_XW_SCREEN_ZOOM_INFO_S, *LPNETDEV_XW_SCREEN_ZOOM_INFO_S;

/* 坐标信息 */
typedef struct tagNETDEVXWArea
{
    UINT32  udwX;       /* X轴坐标 */
    UINT32  udwY;       /* Y轴坐标 */
}NETDEV_XW_COORD_S, *LPNETDEV_XW_COORD_S;

/* 相对于电视墙的位置信息 */
typedef struct tagNETDEVXWVirtualLEDArea
{
    NETDEV_XW_COORD_S   stTopLeft;          /* 左上角的坐标点 */
    NETDEV_XW_COORD_S   stBottomRight;      /* 右下角的坐标点 */
}NETDEV_XW_AREA_S, *LPNETDEV_XW_AREA_S;


/* 分辨率信息 */
typedef struct tagNETDEVXWVideoResolution
{
    UINT32  udwWidth;       /* 宽 */
    UINT32  udwHeight;      /* 高 */
}NETDEV_XW_RESOLUTION_S, *LPNETDEV_XW_RESOLUTION_S;


/* "XW"设备电视墙能力集 */
typedef struct tagNETDEVXWTVWallCap
{
    UINT32      udwNumMax;              /* 电视墙最大数量 */
    UINT32      udwSceneMax;            /* 单个电视墙的最大场景数 */
    UINT32      udwRowMax;              /* 单个电视墙的最大行数 */
    UINT32      udwColumnMax;           /* 单个电视墙的最大列数 */
    UINT32      udwScenesPlanMax;       /* 单个电视墙最大场景组计划数 */
    BYTE        byRes[60];              /* 保留字段 */
}NETDEV_XW_TVWALL_CAP_S, *LPNETDEV_XW_TVWALL_CAP_S;

/* "XW"设备电视墙能力集 */
typedef struct tagNETDEVXWFormatList
{
    UINT32      udwSize;                                    /* 支持的视频输出制式数量 */
    UINT32      adwFormatList[NETDEV_VIDEO_FORMAT_MAX];     /* 支持的视频输出制式 NETDEV_VIDEO_FORMAT_E */
    BYTE        byRes[64];                                  /* 保留字段 */
}NETDEV_XW_FORMAT_LIST_S, *LPNETDEV_XW_FORMAT_LIST_S;

/* "XW"设备窗口能力集 */
typedef struct tagNETDEVXWWndCap
{
    UINT32                  udwWndMaxPerScene;      /* 单场景的最大窗口数量 */
    UINT32                  udwAreaMax;             /* 单物理输出口的窗口面积 */
    UINT32                  udwPaneMax;             /* 单窗口的最大分屏数量 */
    NETDEV_XW_RESOLUTION_S  stResolutionMin;        /* 最小窗口的像素 */
    BYTE                    byRes[64];              /* 保留字段 */
}NETDEV_XW_Wnd_CAP_S, *LPNETDEV_XW_Wnd_CAP_S;

/* "XW"设备底图能力集 */
typedef struct tagNETDEVXWBaseMapCap
{
    UINT32                      udwNumMax;              /* "ADU"设备最大底图数量 */
    UINT32                      udwNumMaxPerScene;      /* 单场景最大底图数量 */
    UINT32                      udwBytesMax;            /* 单张底图的最大字节数 */
    NETDEV_XW_RESOLUTION_S      stResolutionMax;        /* 底图最大分辨率 */
    BYTE                        byRes[64];              /* 保留字段 */
}NETDEV_XW_BASEMAP_CAP_S, *LPNETDEV_XW_BASEMAP_CAP_S;

/* "XW"设备虚拟LED能力集 */
typedef struct tagNETDEVXWVirtualLEDCap
{
    UINT32  udwNumMaxPerScene;           /* 单场景最大虚拟LED数量 */
    UINT32  udwRowMax;                   /* 单虚拟LED最大行数 */
    UINT32  udwCharMaxPerRow;            /* 单行文字的最大个数 */
    UINT32  udwRollingNumPerSceneMax;    /* 滚动虚拟LED最大个数 */
    UINT32  udwTextHightMax;             /* 字高最大值 */
    UINT32  udwGapMax;                   /* 自适应间隔最大像素 */
    UINT32  udwCharsMax;                 /* 最大字符个数限制 */
    BYTE    byRes[48];                   /* 保留字段 */
}NETDEV_XW_VIRTUALLED_CAP_S, *LPNETDEV_XW_VIRTUALLED_CAP_S;

/* "XW"设备轮巡能力集 */
typedef struct tagNETDEVXWSequenceCap
{
    UINT32  udwSrcNumMax;                /* 单个轮训最大资源数量 */
    UINT32  udwPaneNumMax;               /* 单分屏轮巡最大数量 */
    UINT32  udwWndNumMax;                /* 单窗口轮巡最大数量 */
    UINT32  udwSceneNumMax;              /* 场景轮巡最大个数 */

    UINT32  udwVideoSourceMax;           /* 单个轮巡资源最大监控点数 */
    UINT32  udwSeqResourceInSceneMax;    /* 单个场景下最大的轮巡资源数 */
    BYTE    byRes[56];                   /* 保留字段 */
}NETDEV_XW_SEQUENCE_CAP_S, *LPNETDEV_XW_SEQUENCE_CAP_S;

/* "XW"支持的分屏 */
typedef struct tagNETDEVXWPaneType
{
    UINT32                          udwSize;                     /* 支持的分屏数量 */
    UINT32                          *pudwPaneType;               /* 支持的分屏类型 NETDEV_XW_LAYOUT_NUM_E */
}NETDEV_XW_PANE_TYPE_S, *LPNETDEV_XW_PANE_TYPE_S;

/**
 * @brief 资源管理类型（显控设备侧管理资源需要此字段）
 * @attention
 */
typedef enum tagNETDEVXWManageType
{
    NETDEV_XW_MANAGE_TYPE_OTHER = 0,                                /* 其它 */
    NETDEV_XW_MANAGE_TYPE_XWARE = 1,                                /* 显控设备侧管理 */

    NETDEV_XW_MANAGE_TYPE_INVALID = 0XFF                            /* 无效值 invalid */
    
}NETDEV_XW_MANAGE_TYPE_E;

/* "XW"设备其他能力集 */
typedef struct tagNETDEVXWSupportCap
{
    UINT32                  udwPane;                      /* 分屏能力 NETDEV_PANE_CAP_E*/
    UINT32                  udwWndRoaming;                /* 窗口漫游能力 NETDEV_ROAMING_CAP_E*/
    UINT32                  udwWnd;                       /* 开窗能力 NETDEV_XW_WND_CAP_E*/        
    BOOL                    bBackToShow;                  /* 回显能力 0:不支持 1:支持 */
    BOOL                    bWndOverlay;                  /* 窗口叠加能力 0:不支持 1:支持 */
    BOOL                    bTopWndSetTransp;             /* 顶层窗口设置透明度 0:不支持 1:支持 */
    UINT32                  udwMaxWinNumPerScreen;        /* 单个物理输出口能支持的最大窗口数量 */
    NETDEV_XW_PANE_TYPE_S   stPaneType;                   /* 支持的分屏 */
    UINT32                  udwMaxEncodeDevicesNum;       /* 接入编码设备的最大数量 */
    UINT32                  udwMaxVideoSourceNum;         /* 接入通道的最大数量 */
    BYTE                    byRes[56];                    /* 保留字段 */
}NETDEV_XW_SUPPORT_CAP_S, *LPNETDEV_XW_SUPPORT_CAP_S;

/* "XW"设备能力集 */
typedef struct tagNETDEVXWCAPINFO
{
    NETDEV_XW_TVWALL_CAP_S          stTVWall;               /* 电视墙能力集 */
    NETDEV_XW_FORMAT_LIST_S         stVideoFormats;         /* 视频输出制式列表 */
    NETDEV_XW_Wnd_CAP_S             stWnd;                  /* 窗口能力集 */
    NETDEV_XW_BASEMAP_CAP_S         stBaseMap;              /* 底图能力集 */
    NETDEV_XW_VIRTUALLED_CAP_S      stVirtualLED;           /* 虚拟LED能力集 */
    NETDEV_XW_SEQUENCE_CAP_S        stSequence;             /* 轮巡能力集 */
    NETDEV_XW_SUPPORT_CAP_S         stSupport;              /* 特性能力集 */
    BOOL                            bIsRSASupported;        /* 是否使用RSA加密 */
    BOOL                            bIsDevMgrSupported;     /* 是否支持管理设备 */
    BOOL                            bIsDecodeInfoSupported; /* 是否支持解码信息 */
    BYTE                            byRes[56];              /* 保留字段 */
}NETDEV_XW_CAP_INFO_S, *LPNETDEV_XW_CAP_INFO_S;


/* 电视墙屏幕配置 */
typedef struct tagNETDEVTVWallScreen
{
    UINT32                          udwRowNum;                          /* 电视墙行单元数量 */
    UINT32                          udwColNum;                          /* 电视墙列单元数量 */
    UINT32                          udwFormat;                          /* 屏幕输出制式 NETDEV_VIDEO_FORMAT_E */
    CHAR                            szFormat[NETDEV_FORMAT_NAME_LEN];   /* 无需配置 屏幕输出制式 */
    NETDEV_XW_RESOLUTION_S          stResolution;                       /* 屏幕像素 */
    BYTE                            byRes[64];                          /* 保留字段 */
}NETDEV_TVWALL_SCREEN_S, *LPNETDEV_TVWALL_SCREEN_S;

/* 特殊输出制式配置 */
typedef struct tagNETDEVTVWallFORMATSPECList
{
    UINT32                          udwScreenID;                        /* 屏幕序号(从1开始) */
    UINT32                          udwFormat;                          /* 屏幕输出制式 NETDEV_VIDEO_FORMAT_E */
    CHAR                            szFormat[NETDEV_FORMAT_NAME_LEN];   /* 无需配置 屏幕输出制式 */
    BYTE                            byRes[32];                          /* 保留字段 */
}NETDEV_TVWALL_FORMAT_SPEC_S, *LPNETDEV_TVWALL_FORMAT_SPEC_S;

/* 特殊模组框配置 */
typedef struct tagNETDEVTVWallLEDSPECList
{
    UINT32                  udwScreenID;        /* 屏幕序号(从1开始) */
    NETDEV_XW_RESOLUTION_S  stResolution;       /* 屏幕像素 */
    BYTE                    byRes[32];          /* 保留字段 */
}NETDEV_TVWALL_LED_SPEC_S, *LPNETDEV_TVWALL_LED_SPEC_S;

/* 物理输出端口配置 */
typedef struct tagNETDEVTVWallVOUTList
{
    UINT32  udwScreenID;        /* 屏幕序号(从1开始) */
    UINT32  udwVideoOutID;      /* 物理输出端口ID */
    BYTE    byRes[32];          /* 保留字段 */
}NETDEV_TVWALL_VIDED_OUT_S, *LPNETDEV_TVWALL_VIDED_OUT_S;

/* "XW"视频输出通道信息 */
typedef struct tagNETDEVXWVideoOutInfo
{
    INT32   dwChannelID;                   /* 通道ID */
    INT32   dwSlotID;                      /* 槽位ID */
    INT32   dwIndex;                       /* 序号 */
    UINT32  udwVideoPortType;               /* 通道类型 NETDEV_VIDEO_PORT_TYPE_E */
}NETDEV_XW_VIDEO_OUT_INFO_S, *LPNETDEV_XW_VIDEO_OUT_INFO_S;

/* 电视墙屏幕配置 */
typedef struct tagNETDEVXWTVWallCfg
{
    UINT32                          udwTVWallID;                                    /* 电视墙ID */
    CHAR                            szName[NETDEV_TVWALL_NAME_LEN];                 /* 电视墙名称 */
    NETDEV_TVWALL_SCREEN_S          stScreenInfo;                                   /* 电视墙屏幕配置 */
    UINT32                          udwFormatSpecNum;                               /* 特殊输出制式数量 */
    NETDEV_TVWALL_FORMAT_SPEC_S     astFormatSpec[NETDEV_FORMAT_SPEC_MAX];          /* 特殊输出制式配置 */
    UINT32                          udwLedSpecNum;                                  /* 特殊模组框数量 */
    NETDEV_TVWALL_LED_SPEC_S        astLedSpec[NETDEV_LED_SPEC_MAX];                /* 特殊模组框配置 */
    UINT32                          udwVideoOutNum;                                 /* 物理输出端口数量 */
    NETDEV_TVWALL_VIDED_OUT_S       astVideoOut[NETDEV_VIDEO_OUT_MAX];              /* 物理输出端口列表 */
    UINT32                          udwTVWallType;                                  /* 电视墙类型 */
    INT32                           dwXWDeviceID;                                   /* -1表示DC设备，>0表示ADU设备ID */
    BYTE                            byRes[248];                                     /* 保留字段 */
}NETDEV_XW_TVWALL_CFG_S, *LPNETDEV_XW_TVWALL_CFG_S;

/* 场景基本信息 */
typedef struct tagNETDEVXWSceneInfoBase
{
    UINT32  udwSceneID;                         /* 场景ID */
    CHAR    szName[NETDEV_SCENE_NAME_LEN];      /* 场景名称 */
    UINT32  udwTVWallID;                        /* 电视墙ID */
    UINT32  udwStatus;                          /* 0表示不启用，1表示启用 */
    BYTE    byRes[24];                          /* 保留字段 */
}NETDEV_XW_SCENE_INFO_BASE_S, *LPNETDEV_XW_SCENE_INFO_BASE_S;

/* 场景修改信息 */
typedef struct tagNETDEVXWSceneModifyInfo
{
    NETDEV_XW_SCENE_INFO_BASE_S     stSceneBaseInfo;             /* 场景信息 */
    INT32                           dwModifyType;                /* 修改类型，参见NETDEV_XW_SCENE_MODIFY_TYPE_E modify type see #NETDEV_XW_SCENE_MODIFY_TYPE_E */
    BYTE                            byRes[128];                  /* 保留字段 */
}NETDEV_XW_SCENE_MODIFY_INFO_S, *LPNETDEV_XW_SCENE_MODIFY_INFO_S;

/* 场景简要信息 */
typedef struct tagNETDEVXWSceneInfoShort
{
    NETDEV_XW_SCENE_INFO_BASE_S     stSceneBase;        /* 场景基本 */
    UINT32                          udwIsCurrent;       /* 是否当前场景 0:非当前场景 1:当前场景 */
    BYTE                            byRes[64];          /* 保留字段 */
}NETDEV_XW_SCENE_INFO_BASIC_S, *LPNETDEV_XW_SCENE_INFO_BASIC_S;


/* 计划内容信息 */
typedef struct tagNETDEVXWCfgTime
{
    CHAR    szBeginTime[NETDEV_TIME_LEN];   /* 起始时间 如果全天填00:00:00 */
    CHAR    szEndTime[NETDEV_TIME_LEN];     /* 结束时间 如果全天填24:00:00 */
    UINT32  udwSceneID;                     /* 场景ID */
}NETDEV_XW_CFG_TIME_S, *LPNETDEV_XW_CFG_TIME_S;

/* 周计划信息 */
typedef struct tagNETDEVXWPlanCfg
{
    UINT32                  udwDayOfWeek;                       /* 周几 NETDEV_WEEK_INFO */
    UINT32                  udwSize;                            /* 时间段数量 */
    NETDEV_XW_CFG_TIME_S    stTime[NETDEV_PLAN_SECTION_NUM];    /* 时间段信息 */
}NETDEV_XW_PLAN_CFG_S, *LPNETDEV_XW_PLAN_CFG_S;

/* 场景计划配置 */
typedef struct tagNETDEVXWScenePlan
{
    UINT32                  udwPlanID;                          /* 计划ID */
    BOOL                    bIsEnabled;                         /* 计划是否启用 */
    NETDEV_XW_PLAN_CFG_S    astConfig[NETDEV_PLAN_NUM_AWEEK];   /* 计划配置信息 */
    BYTE                    byRes[64];                          /* 保留字段 */
}NETDEV_XW_SCENE_PLAN_S, *LPNETDEV_XW_SCENE_PLAN_S;


/**
 * @brief XW窗口分屏信息
 * @attention
 */
typedef struct tagNETDEVXWPaneInfo
{
    UINT32      udwPaneID;              /* 分屏序号 */
    INT32       dwChannelID;            /* 通道ID */
    UINT32      udwStreamIndex;         /* 流索引 */
    UINT32      udwTaskNo;              /* 业务号 */
    UINT32      udwTransProtocal;       /* 传输协议 参见 NETDEV_TRANS_PROTOCAL_E */
    UINT32      udwSessionType;         /* 分屏业务类型 参见 NETDEV_SESSION_TYPE_E */
}NETDEV_XW_PANE_INFO_S, *LPNETDEV_XW_PANE_INFO_S;


/* 场景窗口信息 */
typedef struct tagNETDEVXWSceneWndInfo
{
    UINT32                  udwWndID;                           /* 窗口ID */
    UINT32                  udwModifyCmd;                       /* 修改可选命令字 NETDEV_XW_WND_CMD */
    CHAR                    szWndName[NETDEV_WND_NAME_LEN];     /* 窗口名称 */
    UINT32                  udwPaneMod;                         /* 分屏模式,默认1分屏 NETDEV_XW_LAYOUT_NUM_E */
    UINT32                  udwLayer;                           /* 图层，数字大的在最上层*/
    UINT32                  udwTransparency;                    /* 透明度：默认0 不透明,100 全透明 0-100的其他值表明部分透明*/
    NETDEV_XW_AREA_S        stArea;                             /* 位置信息 */
    UINT32                  udwZoomType;                        /* 放大类型 参见NETDEV_XW_ZOOM_TYPE_E zoom Type see NETDEV_XW_ZOOM_TYPE_E */
    UINT32                  udwSplitIndex;                      /* 分屏序号 当udwZoomType为NETDEV_XW_ZOOM_TYPE_SPLIT时有效 */
    UINT32                  udwSchemeResID;                      /* 轮巡资源ID */
    UINT32                  udwSeqStatus;                        /* 轮巡状态参见NETDEV_SEQ_STATUS_E */
    UINT32                  udwPaneSize;                         /* 分屏数量*/
    NETDEV_XW_PANE_INFO_S   astPaneInfoList[NETDEV_XW_MAX_PANE_NUM];      /* 所有分屏信息*/
    UINT32                  udwWndType;                          /* 窗口类型 参见枚举NETDEV_TVWALL_WND_TPYE*/
    UINT32                  udwDChlID;                           /* DC通道ID */
    UINT32                  udwStatus;                           /* 0表示不锁定，1表示锁定 */
    BYTE                    byRes[244];                              /* 保留字段 */
}NETDEV_XW_SCENE_WND_INFO_S, *LPNETDEV_XW_SCENE_WND_INFO_S;


typedef struct tagNETDEVAuthentication
{
    BOOL                            bIsNeedAuthentication;                 /* 是否需要鉴权 */
    CHAR                            szUserName[NETDEV_USER_NAME_ENCRYPT_LEN];/* 视频源用户名 */
    CHAR                            szPassword[NETDEV_PASSWORD_ENCRYPT_LEN]; /* 视频源密码 */
    NETDEV_AUTH_MODEL_E            enAuthModel;                           /* 保留字段，暂不使用。加密类型 参考枚举#NETDEV_XW_AUTH_MODEL_E */
    BYTE                            byRes[64];                            /* 保留字段 */
}NETDEV_AUTHENTICATION_S, *LPNETDEV_AUTHENTICATION_S;

/* 远端回放的视频源信息 */
typedef struct tagNETDEVXWChannels
{
    UINT32                      udwVideoInID;                       /* 视频源ID */
    CHAR                        szReplayURL[NETDEV_MAX_URL_LEN];    /* 回放URL */
    NETDEV_AUTHENTICATION_S     stAuthentication;                   /* 鉴权信息 */
    UINT32                      udwTransProtocol;                   /* 传输协议 NETDEV_LAPI_TRANS_PROTOCOL_E 本地输入时无需配置*/
    UINT32                      udwMulticast;                       /* 单组播 NETDEV_STREAM_TYPE_E 本地输入时无需配置*/
    INT64                       tBeginTime;                         /* 开始时间 */
    INT64                       tEndTime;                           /* 结束时间 */
    UINT32                      udwManageType;                      /* 资源管理类型，参见枚举NETDEV_XW_MANAGE_TYPE_E  */
    BYTE                        byRes[60];                          /* 保留字段 */
}NETDEV_XW_CHANNELS_S, *LPNETDEV_XW_CHANNELS_S;


/* "XW"设备ID信息 */
typedef struct tagNETDEVXWDisplayerID
{
    UINT32  udwTVWallID;    /* 电视墙ID */
    UINT32  udwWndID;       /* 窗口ID */
    UINT32  udwPaneID;      /* 分屏序号 */
    BYTE    byRes[16];      /* 保留字段 */
}NETDEV_XW_DISPLAYER_ID_S, *LPNETDEV_XW_DISPLAYER_ID_S;

/* 远端实况的视频源基本信息 */
typedef struct tagNETDEVXWVideoSourceBase
{
    UINT32                      udwVideoInID;                       /* 视频源ID */
    CHAR                        szRealplayURL[NETDEV_MAX_URL_LEN];  /* 媒体流URL 本地输入时无需配置*/
    UINT32                      udwStreamID;                        /* 媒体流序号 */
    NETDEV_AUTHENTICATION_S     stAuthentication;                   /* 鉴权信息 */
    UINT32                      udwTransProtocol;                   /* 传输协议 NETDEV_LAPI_TRANS_PROTOCOL_E 本地输入时无需配置*/
    UINT32                      udwMulticast;                       /* 单组播 NETDEV_STREAM_TYPE_E 本地输入时无需配置*/
    UINT32                      udwType;                            /* 实况类型 参考 NETDEV_XW_REALPLAY_TYPE_E */
    UINT32                      udwManageType;                      /* 资源管理类型，参见枚举NETDEV_XW_MANAGE_TYPE_E  */
    BYTE                        byRes[28];                         /* 保留字段 */
}NETDEV_XW_VIDEO_SOURCE_BASE_S, *LPNETDEV_XW_VIDEO_SOURCE_BASE_S;

/* 远端实况的视频源信息 */
typedef struct tagNETDEVXWVideoSource
{
    NETDEV_XW_DISPLAYER_ID_S    stDisplayerID;                      /* 设备ID信息 */
    UINT32                      udwVideoInID;                       /* 视频源ID */
    CHAR                        szRealplayURL[NETDEV_MAX_URL_LEN];  /* 媒体流URL 本地输入时无需配置*/
    UINT32                      udwStreamID;                        /* 媒体流序号 */
    NETDEV_AUTHENTICATION_S     stAuthentication;                   /* 鉴权信息 */
    UINT32                      udwTransProtocol;                   /* 传输协议 NETDEV_LAPI_TRANS_PROTOCOL_E 本地输入时无需配置*/
    UINT32                      udwMulticast;                       /* 单组播 NETDEV_STREAM_TYPE_E 本地输入时无需配置*/
    UINT32                      udwType;                            /* 实况类型 参考 NETDEV_XW_REALPLAY_TYPE_E */
    UINT32                      udwDecodeType;                      /* 解码类型 参考NETDEV_XW_DECODE_TYPE_E */
    UINT32                      udwManageType;                      /* 资源管理类型，参见枚举NETDEV_XW_MANAGE_TYPE_E  */
    BYTE                        byRes[60];                          /* 保留字段 */
}NETDEV_XW_VIDEO_SOURCE_S, *LPNETDEV_XW_VIDEO_SOURCE_S;

/* 回放控制信息 */
typedef struct tagNETDEVXWPlaybackParam
{
    UINT32                          udwTaskNo;                   /* 回放业务号 */
    UINT32                          udwControlType;              /* 回放控制类型 参考 NETDEV_XW_CTRL_TYPE_E */
    UINT32                          udwControlParam;             /* 控制的具体数值，比如快进速度等 */
    BYTE                            byRes[64];                  /* 保留字段 */
}NETDEV_XW_PLAYBACK_PARAM_S, *LPNETDEV_XW_PLAYBACK_PARAM_S;

/* 摄像机业务的视频源信息 */
typedef struct tagNETDEVXWVideoInSource
{
    UINT32                      udwVideoInChlID;            /* 视频源ID */
    UINT32                      udwStreamID;                /* 媒体流序号 */
    CHAR                        szURL[NETDEV_MAX_URL_LEN];  /* 媒体流URL */
    NETDEV_AUTHENTICATION_S     stAuthentication;           /* 鉴权信息 */
    UINT32                      udwSeqIntervalSec;          /* 轮巡间隔，单位：秒 只有是轮巡时才需要配置 */
    UINT32                      udwPreset;                  /* 预置位序号 只有是轮巡时才需要配置 */
    BYTE                        byRes[32];                  /* 保留字段 */
}NETDEV_XW_VIDEO_IN_SOURCE_S, *LPNETDEV_XW_VIDEO_IN_SOURCE_S;

/* 摄像机业务信息 */
typedef struct tagNETDEVXWVideoInChannelInfo
{
    UINT32                          udwWndID;                                   /* 窗口ID */
    UINT32                          udwPaneID;                                  /* 分屏序号 0表示窗口轮巡*/
    UINT32                          udwSourceSize;                              /* 摄像机业务中视频源数量 */
    NETDEV_XW_VIDEO_IN_SOURCE_S     astVideoInSource[NETDEV_SEQUENCE_SRC_MAX];        /* 摄像机业务中视频源信息 */
    BYTE                            byRes[32];                                  /* 保留字段 */
}NETDEV_XW_VIDEO_IN_CHANNEL_INFO_S, *LPNETDEV_XW_VIDEO_IN_CHANNEL_INFO_S;


/* 背景 */
typedef struct tagNETDEVXWBackground
{
    UINT32  udwTransparency;    /* 透明度 0－全透明 默认,100－不透明 */
    UINT32  udwBaseColor;       /* 颜色 RGB方式:0xABCDEF AB表示R 00~FF;CD表示G 00~FF;EF表示B 00~FF;默认：0xFFFFFF（白色）*/
    BYTE    byRes[16];          /* 保留字段 */
}NETDEV_XW_BACKGROUND_S, *LPNETDEV_XW_BACKGROUND_S;

/* 文字信息描述 */
typedef struct tagNETDEVXWFontInfo
{
    UINT32  udwFont;                /* 字体 NETDEV_XW_LED_FONT_FORMAT_E */
    UINT32  udwSize;                /* 字体大小 0到7参照枚举：NETDEV_XW_LED_FONT_SIZE_E,其余取值范围[48,1024]，表示实际像素高度  */
    UINT32  udwReferFontSize;       /* 参考字体大小 当udwSize选择自适应后该字段必选 值范围参照Size字段*/ 
    UINT32  udwGap;                 /* 字间距  参见枚举 NETDEV_XW_LED_FONT_GAP_E */
    UINT32  udwHorizontalAlign;     /* 水平对齐方式 NETDEV_XW_HORIZONTAL_ALIGN_MODE_E */
    UINT32  udwVerticalAlign;       /* 垂直对齐方式 NETDEV_XW_VERTICAL_ALIGN_MODE_E */
    UINT32  udwColor;               /* 颜色 RGB方式:0xABCDEF AB表示R 00~FF;CD表示G 00~FF;EF表示B 00~FF;默认：0xFFFFFF（白色）*/
    UINT32  udwScrollMode;          /* 文字滚动方式 NETDEV_XW_LED_SCROLLING_MODE_E  */
    UINT32  udwScrollRateSec;       /* 滚动速度，单位：秒,有条件选择，当ScrollingMode为非1值时，必选；默认1秒 1x－10x可选，1x最慢 ，当文字滚动类型为2/3/4/5时必选*/
    UINT32  udwReferFontGap;        /* 参考字间距大小,当udwGap选择自适应时该字段有效，取值范围0~1024（实际像素宽度） */
    BYTE   byRes[28];               /* 保留字段 */
}NETDEV_XW_FONT_INFO_S, *LPNETDEV_XW_FONT_INFO_S;/* 虚拟LED信息 */

/**
 * @brief 虚拟LED信息
 * @attention
 */
typedef struct tagNETDEVXWVirtualLEDInfo
{
    UINT32                  udwLEDID;                    /* 虚拟LED的ID */
    UINT32                  udwModifyCmd;                /* 修改可选命令字 NETDEV_XW_LED_CMD_E */
    UINT32                  udwEnable;                   /* 虚拟LED是否启用 0不使能 1使能 */
    UINT32                  udwType;                     /* 虚拟LED类型 NETDEV_XW_LED_TYPE_E */
    NETDEV_XW_AREA_S        stArea;                      /* 虚拟LED的位置信息 */
    NETDEV_XW_BACKGROUND_S  stBackground;                /* 背景 */
    NETDEV_XW_FONT_INFO_S   stFontInfo;                  /* 文字信息描述 */
    CHAR                   szText[NETDEV_TEXT_LEN];     /* 文字内容 */
    BYTE                   byRes[32];                   /* 保留字段 */
}NETDEV_XW_VIRTUAL_LED_INFO_S, *LPNETDEV_XW_VIRTUAL_LED_INFO_S;

/*******************************批量开关窗Begin*****************************/
/**
* @brief 批量开窗场景窗口信息
* @attention
*/
typedef struct tagNETDEVXWSenceBatchWnd
{
    UINT32                          udwReqSeq;              /* 请求数据序号 */
    NETDEV_XW_SCENE_WND_INFO_S      stSenceWndInfo;         /* 窗口信息 */
    BYTE                            byRes[32];              /* 保留字段 */
}NETDEV_XW_SENCE_BATCH_WND_S, *LPNETDEV_XW_SENCE_BATCH_WND_S;

/**
 * @brief 批量开窗窗口信息列表
 * @attention
 */
typedef struct tagNETDEVXWBatchWindowInfoList
{
    UINT32                          udwNum;                       /*窗口数量*/
    LPNETDEV_XW_SENCE_BATCH_WND_S   pstSceneWinInfo;              /*窗口详细信息列表*/
}NETDEV_XW_WND_INFO_LIST_S,*LPNETDEV_XW_WND_INFO_LIST_S;

/**
* @brief 批量开窗场景窗口返回信息
* @attention
*/
typedef struct tagNETDEVXWSenceBatchResultWnd
{
    UINT32  udwReqSeq;      /* 请求数据序号 */
    UINT32  udwResuleCode;  /* 返回错误码 */
    UINT32  udwWinID;       /* 窗口ID */
}NETDEV_XW_BATCH_RESULT_WND_S, *LPNETDEV_XW_BATCH_RESULT_WND_S;

/**
* @brief 批量开窗场景窗口返回信息列表
* @attention
*/
typedef struct tagNETDEVXWSenceBatchResultList
{
    UINT32                              udwSize;            /* 窗口数量 */
    UINT32                              udwLastChange;      /* 摘要字 */
    LPNETDEV_XW_BATCH_RESULT_WND_S      pstResultInfo;      /* 窗口信息,根据窗口数量动态申请内存 */
    BYTE                                byRes[32];          /* 保留字段 */
}NETDEV_XW_BATCH_RESULT_LIST_S, *LPNETDEV_XW_BATCH_RESULT_LIST_S;

/* 轮询资源信息 */
typedef struct tagNETDEVXWSequenceSource
{
    UINT32                          udwInterval;                                /* 轮巡间隔 单位秒 */
    UINT32                          udwPreset;                                 /* 预置位序号 */
    NETDEV_XW_VIDEO_SOURCE_BASE_S   stVideoSourceBase;                          /* 摄像机业务中视频源信息 */
    BYTE                            byRes[32];                                 /* 保留字段 */
}NETDEV_XW_SEQUENCE_SOURCE_S, *LPNETDEV_XW_SEQUENCE_SOURCE_S;

/* 轮询资源列表信息 */
typedef struct tagNETDEVXWSequenceSourceList
{
    UINT32                          udwWndID;                                   /* 窗口ID */
    UINT32                          udwSourceSize;                              /* 摄像机业务中视频源数量 */
    NETDEV_XW_SEQUENCE_SOURCE_S     astSequenceSource[NETDEV_SEQUENCE_SRC_MAX]; /* 摄像机业务中视频源信息 */
    BYTE                            byRes[32];                                  /* 保留字段 */
}NETDEV_XW_SEQUENCE_SOURCE_LIST_S, *LPNETDEV_XW_SEQUENCE_SOURCE_LIST_S;

/* 所有底图信息 */
typedef struct tagNETDEVXWBaseMapInfo
{
    UINT32                      udwID;                              /* 底图ID，整个设备唯一 */
    CHAR                        szName[NETDEV_BMAP_NAME_LEN];       /* 底图名称 */
    UINT32                      udwFormat;                          /* 底图格式 NETDEV_XW_BASE_TYPE_E */
    NETDEV_XW_RESOLUTION_S      stResolution;                       /* 底图分辨率 */
    UINT32                      udwThumbnailData;                   /* 缩略图数据 */
    BYTE                        byRes[300];                         /* 保留字段 */
}NETDEV_XW_BASE_MAP_INFO_S, *LPNETDEV_XW_BASE_MAP_INFO_S;


/* 轮巡资源绑定信息 */
typedef struct tagNETDEVXWSequenceResourceBindBaseInfo
{
    UINT32          udwID;                                  /* 轮巡资源绑定信息ID,添加时可选 */
    UINT32          udwSequenceResID;                       /* 轮巡资源ID */
    UINT32          udwIntervalTime;                        /* 业务的时间间隔，单位：秒 */
    UINT32          udwStatus;                              /* 轮巡状态，参见枚举NETDEV_XW_SEQUENCE_RES_STATUS_E */
    UINT32          udwWndNum;                              /* 窗口数量 */
    UINT32          audwWndIDList[NETDEV_SEQ_RES_WIN_MAX];  /* 窗口ID列表，内存由用户维护，规格由能力集接口获取 */
    BYTE            byRes[256];                             /* 保留字段 */
}NETDEV_XW_SEQUENCE_RES_BIND_INFO_S, *LPNETDEV_XW_SEQUENCE_RES_BIND_INFO_S;

/* 场景详细信息*/
typedef struct tagNETDEVXWSceneInfoDetail
{
    CHAR                                    szName[NETDEV_SCENE_NAME_LEN];      /* 场景名称 */
    UINT32                                  udwTVWallID;                        /* 电视墙ID */
    NETDEV_XW_BASE_MAP_INFO_S               stBaseMapInfo;                      /* 底图信息 */
    UINT32                                  udwVirtualLedNum;                   /* 虚拟LED数量 */
    LPNETDEV_XW_VIRTUAL_LED_INFO_S          pstVirtualLedInfo;                  /* 虚拟LED信息 */
    UINT32                                  udwWndNum;                          /* 窗口数量 */
    LPNETDEV_XW_SCENE_WND_INFO_S            pstWndInfo;                         /* 窗口信息 */
    UINT32                                  udwLiveBindNum;                     /* 绑定实况业务数量 */
    LPNETDEV_XW_VIDEO_SOURCE_S              pstVideoSource;                     /* 绑定实况业务信息 */
    UINT32                                  udwSequenceBindNum;                 /* 绑定轮巡业务数量 */
    LPNETDEV_XW_SEQUENCE_SOURCE_LIST_S      pstSequenceSourceList;              /* 绑定轮巡业务信息 */
    UINT32                                  udwWindowsSequenceBindNum;          /* 绑定窗口组业务数量 */
    LPNETDEV_XW_SEQUENCE_RES_BIND_INFO_S    pstWindowsSequenceBindList;         /* 绑定窗口组轮巡业务的详细信息 */
    UINT32                                  udwLinkedSceneID;                   /* 关联场景ID */
    BYTE                                    byRes[244];                         /* 保留字段 */
}NETDEV_XW_SCENE_INFO_DETAIL_S, *LPNETDEV_XW_SCENE_INFO_DETAIL_S;

/* "XW"编码通道信息 */
typedef struct tagNETDEVXWChannelsNum
{
    UINT32  udwVideoInNum;               /* 视频输入通道数量 */
    UINT32  udwVideoOutNum;              /* 视频输出通道数量 */
    UINT32  udwAudioInNum;               /* 音频输入通道数量 */
    UINT32  udwAudioOutNum;              /* 音频输出通道数量 */
    BYTE    byRes[64];                  /* 保留字段 */
}NETDEV_XW_CHANNELS_NUM_S, *LPNETDEV_XW_CHANNELS_NUM_S;


/* "XW"视频输入通道信息 */
typedef struct tagNETDEVXWVideoInInfo
{
    INT32   dwChannelID;            /* 通道ID */
    INT32   dwIndex;                /* 序号 */
    UINT32  udwVideoPortType;       /* 通道类型 NETDEV_VIDEO_PORT_TYPE_E */
    BYTE    byRes[64];              /* 保留字段 */
}NETDEV_XW_VIDEO_IN_INFO_S, *LPNETDEV_XW_VIDEO_IN_INFO_S;

/* "XW"音频输出通道信息 */
typedef struct tagNETDEVXWAudioOutInfo
{
    INT32   dwChannelID;            /* 通道ID */
    UINT32  udwAudioPortType;       /* 通道类型 NETDEV_AUDIO_PORT_TYPE_E */
    BYTE    byRes[64];              /* 保留字段 */
}NETDEV_XW_AUDIO_OUT_INFO_S, *LPNETDEV_XW_AUDIO_OUT_INFO_S;

/* "XW"音频输入通道信息 */
typedef struct tagNETDEVXWAudioInInfo
{
    INT32   dwChannelID;            /* 通道ID */
    UINT32  udwAudioPortType;       /* 通道类型 NETDEV_AUDIO_PORT_TYPE_E */
    BYTE    byRes[64];              /* 保留字段 */
}NETDEV_XW_AUDIO_IN_INFO_S, *LPNETDEV_XW_AUDIO_IN_INFO_S;

/* "XW"通道信息 */
typedef struct tagNETDEVXWChannelsList
{
    UINT32                          udwVideoInNum;                  /* 视频输入通道数量 需要给出ADU/CDU支持的最大通道数 */
    LPNETDEV_XW_VIDEO_IN_INFO_S     pstVideoIn;                     /* 视频输入通道信息 */
    UINT32                          udwVideoOutNum;                 /* 视频输出通道数量 需要给出ADU/CDU支持的最大通道数*/
    LPNETDEV_XW_VIDEO_OUT_INFO_S    pstVideoOut;                    /* 视频输出通道信息 */
    UINT32                          udwAudioInNum;                  /* 音频输入通道数量 需要给出ADU/CDU支持的最大通道数*/
    LPNETDEV_XW_AUDIO_IN_INFO_S     pstAudioIn;                     /* 音频输入通道信息 */
    UINT32                          udwAudioOutNum;                 /* 音频输出通道数量 需要给出ADU/CDU支持的最大通道数*/
    LPNETDEV_XW_AUDIO_OUT_INFO_S    pstAudioOut;                    /* 音频输出通道信息 */
    BYTE                            byRes[64];                      /* 保留字段 */
}NETDEV_XW_CHANNELS_LIST_S, *LPNETDEV_XW_CHANNELS_LIST_S;

/**
* @brief 被动解码发送控制参数信息   
* @attention 无 None
*/
typedef struct tagNETDEVPassiveDecodeSend
{
    INT32 dwTransType;          /*传输方式 */
    INT32 dwBufSize;            /* 数据大小 */
    CHAR *pszBuffer;            /* 数据内容 */
    BYTE byRes[128];            /* 保留字段 */
}NETDEV_PASSIVE_SEND_S, *LPNETDEV_PASSIVE_SEND_S;

/**
 * @brief 图像扩展编码模式 Smart image encoding mode
 * @attention
 */
typedef struct tagNETDEVSmartEncodeInfo 
{
    UINT32 udwH264SmartEncodeModeNum;                                              /* 支持的H.264图像智能编码模式种类个数 Number of smart image encoding in H.264*/
    UINT32 audwH264SmartEncodeModeList[NETDEV_SMART_ENCODE_MODEL_MAX_NUM];         /* 支持的H.265图像智能编码模式种类列表，参见NETDEV_SMART_ENCODE_MODE_E。 List of smart image encoding in H.265. See NETDEV_SMART_ENCODE_MODE_E for reference*/
    UINT32 udwH265SmartEncodeModeNum;                                              /* 支持的H.264图像智能编码模式种类个数 Number of smart image encoding in H.264*/
    UINT32 audwH265SmartEncodeModeList[NETDEV_SMART_ENCODE_MODEL_MAX_NUM];         /* 支持的H.265图像智能编码模式种类列表，参见NETDEV_SMART_ENCODE_MODE_E。 List of smart image encoding in H.265. See NETDEV_SMART_ENCODE_MODE_E for reference */
}NETDEV_SMART_ENCODE_S,*LPNETDEV_SMART_ENCODE_S;


/**
 * @brief 分辨率具体信息 Resolution details
 * @attention
 */
typedef struct tagNETDEVResolutionCapability
{
    UINT32 udwWidth;                                                                  /* 图像宽度 Image width*/
    UINT32 udwHeight;                                                                 /* 图像高度 Image height*/
    UINT32 udwMinBitRate;                                                             /* 最小码率 Minimum bit rate*/
    UINT32 udwMaxBitRate;                                                             /* 最大码率 Maximum bit rate*/
    UINT32 udwDefaultBitRate;                                                         /* 默认码率 Default bit rate*/
}NETDEV_RESOLUTION_CAPABILITY_S,*LPNETDEV_RESOLUTION_CAPABILITY_S;

/**
 * @brief 码流能力信息 Stream capability
 * @attention
 */
typedef struct tagNETDEVStreamCapability
{
    UINT32 udwstreamID;                                                             /* 码流索引，参见枚举NETDEV_LIVE_STREAM_INDEX_E。 Stream index. For enumeration, seeNETDEV_LIVE_STREAM_INDEX_E */
    UINT32 udwResolutionNum;                                                        /* 支持的分辨率个数 Number of resolution*/
    UINT32 udwFrameRateNum;                                                         /* 支持的帧率个数 Number of frame rate*/
    UINT32 udwMaxFrameRate;                                                         /* 当前码流最大帧率 Number of frame rate*/
    UINT32 udwMaxMJPEGFrameRate;                                                    /* 当前码流MJPEG最大帧率 Maximum MJPEG frame rate of current stream*/
    UINT32 audwFrameRateList[NETDEV_LEN_16];                                        /* 支持的帧率数组 Frame rate array*/
    NETDEV_RESOLUTION_CAPABILITY_S astResolutionCapabilityList[NETDEV_LEN_32];      /* 支持的分辨率列表  List of resolution*/
    NETDEV_SMART_ENCODE_S stSmartEncode;                                            /* 图像扩展编码模式 Smart image encoding mode*/
}NETDEV_STREAM_CAP_S,*LPNETDEV_STREAM_CAPABILITY_S;

/**
 * @brief 视频制式能力 Video mode capability
 * @attention
 */
typedef struct tagNETDEVVideoModeInfo 
{
    UINT32 udwWidth;                                      /* 图像宽度 Image width*/
    UINT32 udwHeight;                                     /* 图像高度 Image height*/
    UINT32 udwFrameRate;                                  /* 图像帧率 Image frame rate*/
}NETDEV_VIDEO_MODE_INFO_S,*LPNETDEV_VIDEO_MODE_INFO_S;

/**
* @enum tagNETDEVRecordStatus
* @brief 录像状态信息
* @attention 
*/
typedef struct tagNETDEVRecordStatus
{
    INT32   dwChannelID;                    /* 通道号  Channel ID */
    INT32   dwRecordType;                   /* 录像类型 0:手动录像1:事件录像2:交易录像3:定时录像4:其他*/
    INT32   dwRecordStatus;                 /* 录像状态 0:正在录像1:未启动存储2:没有硬盘或硬盘坏3:通道不在线*/
    BYTE    byRes[128];                     /* 保留字节 */
}NETDEV_RECORD_STATUS, *LPNETDEV_RECORD_STATUS;

/**
* @enum tagNETDEVRecordStatusList
* @brief 录像状态信息列表
* @attention 
*/
typedef struct tagNETDEVRecordStatusList
{
    UINT32                  udwSize;                                 /* 录像状态数量 */
    NETDEV_RECORD_STATUS    astRecordStatus[NETDEV_CHANNEL_MAX];      /* 录像状态信息 */
}NETDEV_RECORD_STATUS_LIST_S, *LPNETDEV_RECORD_STATUS_LIST_S;

/**
 * @brief 视频输入通道的视频能力集 Encoding parameter capability
 * @attention
 */
typedef struct tagNETDEVVideoCapInfo
{
    BOOL bIsSupportCfg;                                                             /* 是否支持配置,0: 不支持, 1: 支持 Support configuration or not. 0-No, 1-Yes*/
    BOOL bIsSupportSmoothLevel;                                                     /* 是否支持码流平滑,0: 不支持, 1: 支持 Support smoothing or not. 0-No, 1-Yes*/
    BOOL bIsSupportImageFormat;                                                     /* 图像制式是否可配,0: 不支持, 1: 支持 Support configuration of image mode or not. 0-No, 1-Yes*/
    UINT32 udwEncodeFormatNum;                                                      /* 支持的视频编码格式个数 Number of video compression*/
    UINT32 audwEncodeFormatList[NETDEV_ENCODE_FORMAT_MAX_NUM];                      /* 支持的视频编码格式列表，参见NETDEV_VIDEO_CODE_TYPE_E。 Video compression list. See NETDEV_VIDEO_CODE_TYPE_E for reference */
    UINT32 udwMinIFrameInterval;                                                    /* 支持的I帧间隔最小值 Minimum value of I Frame Interval*/
    UINT32 udwMaxIFrameInterval;                                                    /* 支持的I帧间隔最大值 Maximum value of I Frame Interval*/
    UINT32 udwGOPTypeNum;                                                           /* 支持的GOP类型数量 Number of GOP type*/
    UINT32 audwGOPTypeList[NETDEV_GOP_TYPE_MAX_NUM];                                /* 支持的GOP类型列表 List of GOP type*/
    UINT32 udwVideoModeNum;                                                         /* 支持的视频制式个数 Number of video mode*/
    NETDEV_VIDEO_MODE_INFO_S astVideoModeList[NETDEV_LEN_16];                       /* 视频制式能力列表 List of video mode capability*/
    UINT32 udwStreamCapNum;                                                         /* 支持的码流个数 Number of stream*/
    NETDEV_STREAM_CAP_S astStreamCapList[NETDEV_LEN_16];                            /* 支持的码流能力列表 List of stream capability*/
}NETDEV_VIDEO_STREAM_CAP_EX_S,*LPNETDEV_VIDEO_STREAM_CAP_EX_S;

/**
 * @brief 视频编码参数信息 Video encoding parameter
 * @attention
 */
typedef struct tagNETDEVVideoEncodeInfo
{
    BOOL bEnableSVCMode;                        /* SVC配置,0：关闭,1：开启 SVC configuration. 0-Off, 1-On*/
    UINT32 udwEncodeFormat;                     /* 视频编码格式信息，参见枚举NETDEV_VIDEO_CODE_TYPE_E。  Video Compression. For enumeration, seeNETDEV_VIDEO_CODE_TYPE_E*/
    UINT32 udwWidth;                            /* 图像宽度 Image width*/
    UINT32 udwHeight;                           /* 图像高度 Image height*/
    UINT32 udwBitrate;                          /* 码率 Bit rate*/
    UINT32 udwBitrateType;                      /* 码率类型，参见NETDEV_BIT_RATE_TYPE_E。 Bitrate type. See NETDEV_BIT_RATE_TYPE_E for reference */
    UINT32 udwFrameRate;                        /* 帧率 Frame rate*/
    UINT32 udwGopType;                          /* Gop模式,参见NETDEV_GOP_TYPE_E。 GOP mode. See NETDEV_GOP_TYPE_E for reference */
    UINT32 udwIFrameInterval;                   /* I帧间隔，范围根据能力来定 I Frame Interval. The range depends on capability*/
    UINT32 udwImageQuality;                     /* 图像质量，范围[1, 9]，9代表图像质量最高 Image quality, ranges from 1 to 9. 9 means the highest quality*/
    UINT32 udwSmoothLevel;                      /* 码流平滑等级，范围[1,9]，1代表平滑级别最低 Smoothing level, ranges from 1 to 9. 1 means the lowest level*/
    UINT32 udwSmartEncodeMode;                  /* 智能编码模式，参见NETDEV_SMART_ENCODE_MODE_E。 Smart encoding mode. See NETDEV_SMART_ENCODE_MODE_E for reference*/
}NETDEV_VIDEO_ENCODE_INFO_S,*LPNETDEV_VIDEO_ENCODE_INFO_S;

/**
 * @brief 视频流信息(LAPI) Video stream info(LAPI)
 * @attention
 */
typedef struct tagNETDEVVideoStreamInfoLapi 
{
    BOOL bEnabled;                                                                  /* 视频流是否启用编码 Enable encoding for video stream or not*/
    UINT32 udwStreamID;                                                             /* 码流索引，参见枚举NETDEV_LIVE_STREAM_INDEX_E。 Stream index. For enumeration, seeNETDEV_LIVE_STREAM_INDEX_E*/
    UINT32 udwMainStreamType;                                                       /* 主码流类型，参见NETDEV_MAIN_STREAM_TYPE_E。 Main stream. See NETDEV_MAIN_STREAM_TYPE_E for reference */
    NETDEV_VIDEO_ENCODE_INFO_S stVideoEncodeInfo;                                   /* 视频编码参数信息 Video encoding parameter*/
}NETDEV_VIDEO_STREAM_INFO_EX_S,*LPNETDEV_VIDEO_STREAM_INFO_EX_S;

/**
 * @brief 视频流信息列表 Video stream list
 * @attention
 */
typedef struct tagNETDEVVideoStreamInfoList 
{
    UINT32 udwNum;                                                              /* 视频流个数 Number of video stream*/
    NETDEV_VIDEO_STREAM_INFO_EX_S astVideoStreamInfoList[NETDEV_LEN_16];        /* 视频流信息列表 Video stream list*/
}NETDEV_VIDEO_STREAM_INFO_LIST_S,*LPNETDEV_VIDEO_STREAM_INFO_LIST_S;



/*********************** 开关量配置  Boolean configuration***************************** */

/**
 * @brief  告警开关量输入信息 结构体定义  Alarm boolean inputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInputInfo
{
    CHAR  szName[NETDEV_LEN_64];                /* 输入开关量名称   Name of input alarm */
}NETDEV_ALARM_INPUT_INFO_S, *LPNETDEV_ALARM_INPUT_INFO_S;

/**
 * @brief  所有告警开关量输入信息 结构体定义  All Alarm boolean inputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInputInfoList
{
    INT32                        dwSize;                                           /* 输入开关量数量  Number of input alarms */
    NETDEV_ALARM_INPUT_INFO_S    astAlarmInputInfo[NETDEV_MAX_ALARM_IN_NUM];       /* 输入开关量配置信息  Configuration information of input alarms */
}NETDEV_ALARM_INPUT_LIST_S, *LPNETDEV_ALARM_INPUT_LIST_S;

/**
 * @brief  输入开关量告警信息 结构体定义  input switch quantity alert information
 * @attention 无 None
 */
typedef struct tagNETDEVInputSwitchesInfo
{
    INT32                        dwChancelId;                   /* 通道号 Channel ID */
    INT32                        dwInputSwitchIndex;            /* 开关量索引  Input Switch Index*/
    CHAR                         szName[NETDEV_LEN_64];         /* 输入开关量名称   Name of input alarm */
    CHAR                         szGBID[NETDEV_LEN_32];         /* 国标资源编码,仅IPC支持   International Standard Resource Coding, supported by IPC only */
    INT32                        dwRunMode;                     /* 报警类型 1:常开 2：常闭  Alarm Type 1: Open 2: Closed*/
    INT32                        dwEnabled;                     /* 报警使能 0:不使能 1：使能  Alarm Enabling 0: No Enabling 1: Enabling*/
    BYTE                         bRes[128];                     /* 保留字段 Reserved */
}NETDEV_INPUT_SWITCH_INFO_S, *LPNETDEV_INPUT_SWITCH_INFO_S;


/**
 * @brief  输入开关量告警配置信息列表 结构体定义  enter switch quantity alert configuration information list
 * @attention 无 None
 */
typedef struct tagNETDEVInputSwitchesInfoList
{
    INT32                        udwNum;                                /* 输入开关量告警数量   Number of input switches  */
    NETDEV_INPUT_SWITCH_INFO_S   astInputSwitchesInfo[NETDEV_LEN_1024]; /* 输入开关量告警配置信息  input switches configuration information */
}NETDEV_INPUT_SWITCH_INFO_LIST_S, *LPNETDEV_INPUT_SWITCH_INFO_LIST_S;

/**
 * @brief  告警开关量输出信息 结构体定义 Alarm boolean outputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmOutputInfo
{   
    CHAR    szName[NETDEV_LEN_64];                  /* 开关量名称  Boolean name */
    INT32   dwChancelId;                            /* 通道号 Channel ID */
    INT32   enDefaultStatus;                        /* 输出开关量默认状态 参见#NETDEV_BOOLEAN_MODE_E  Default status of boolean output, see enumeration #NETDEV_BOOLEAN_MODE_E */
    INT32   dwDurationSec;                          /* 告警持续时间 单位 S  Alarm duration (s) */
} NETDEV_ALARM_OUTPUT_INFO_S, *LPNETDEV_ALARM_OUTPUT_INFO_S;

/**
 * @brief  所有告警开关量输入信息 结构体定义 All Alarm boolean outputs info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmOutputList
{   
    INT32                       dwSize;                                                 /* 开关量数量   Number of booleans  */
    NETDEV_ALARM_OUTPUT_INFO_S  astAlarmOutputInfo[NETDEV_MAX_ALARM_OUT_NUM];           /* 开关量配置信息  Boolean configuration information */
} NETDEV_ALARM_OUTPUT_LIST_S, *LPNETDEV_ALARM_OUTPUT_LIST_S;

/**
 * @brief  输出开关量的逻辑报警状态(手动告警)
 * @attention 无 None
 */
typedef struct tagNETDEVOutputSwitchesAlarmStatus
{
    INT32   dwBooleanId;                            /* 开关量编号  Boolean ID */
    INT32   dwChannelId;                            /* 通道ID,设备本身为0 */
    INT32   enAlarmStatus;                          /* 输出开关量报警状态 参见#NETDEV_RELAYOUTPUT_STATE_E */
} NETDEV_OUTPUT_SWITCH_ALARM_STATUS_S, *LPNETDEV_OUTPUT_SWITCH_ALARM_STATUS_S;

/**
 * @brief  输出开关量的逻辑报警状态列表(手动告警)
 * @attention 无 None
 */
typedef struct tagNETDEVOutputSwitchesAlarmStatusList
{   
    INT32                                dwSize;                                                       /* 设备报警输出开关量通道数   Number of booleans  */
    NETDEV_OUTPUT_SWITCH_ALARM_STATUS_S  astOutputAlarmStatusInfo[NETDEV_MAX_ALARM_OUT_NUM];           /* 输出开关量报警状态列表 Output switches alarm status list*/
    BYTE                                 bRes[128];                                                    /* 保留字段 Reserved */
} NETDEV_OUTPUT_SWITCH_ALARM_STATUS_LIST_S, *LPNETDEV_OUTPUT_SWITCH_ALARM_STATUS_LIST_S;

/**
 * @brief  触发或清除输出开关量的逻辑报警状态结构体(手动告警)
 * @attention 无 None
 */
typedef struct tagNETDEVOutputSwitchesManualAlarmInfo
{   
    INT32                               dwSize;                                    /* 需要设置的报警输出开关量数量   Number of booleans  */
    INT32                               dwIDList[NETDEV_MAX_ALARM_OUT_NUM];        /* 需要设置的输出开关量编号列表 booleans ID list */
    NETDEV_MANUAL_ALARM_CMD_E           dwAlarmAction;                             /* 执行的命令，参见NETDEV_MANUAL_ALARM_CMD_E*/
    BYTE                                 bRes[128];                                /* 保留字段 Reserved */
} NETDEV_OUTPUT_SWITCH_MANUAL_ALARM_INFO_S, *LPNETDEV_OUTPUT_SWITCH_MANUAL_ALARM_INFO_S;

/**
 * @brief  触发开关量输入告警 结构体定义 Trigger boolean output alarm Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVTriggerAlarmOutput
{   
    CHAR                        szName[NETDEV_LEN_64];          /* 开关量名称  Boolean name */
    NETDEV_RELAYOUTPUT_STATE_E  enOutputState;                  /* 触发状态,参考枚举#NETDEV_RELAYOUTPUT_STATE_E  Trigger status, see enumeration #NETDEV_RELAYOUTPUT_STATE_E */
} NETDEV_TRIGGER_ALARM_OUTPUT_S, *LPNETDEV_TRIGGER_ALARM_OUTPUT_S;


/**
 * @brief 时间段配置 结构体定义 Time Sections Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVTimeSectionInfo
{
    CHAR    szBeginTime[NETDEV_LEN_32];              /* 开始时间  Begin time */
    CHAR    szEndTime[NETDEV_LEN_32];                /* 结束时间  End time */
    UINT32  udwArmingType;                           /* 布防类型0: 定时 1: 动检 2: 报警 3: 动检和报警 4: 动检或报警5: 无计划10: 事件  Distribution Type 0: Timing 1: Motive Inspection 2: Alarm 3: Motive Inspection and Alarm 4: Motive Inspection or Alarm 5: Unplanned 10: Event*/
}NETDEV_TIME_SECTION_INFO_S, *LPNETDEV_TIME_SECTION_INFO_S;

/**
 * @brief 计划（天）配置 结构体定义 Play (Day) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDayPlanInfo
{
    UINT32                      udwID;                                           /*星期索引1：周一;2：周二；3：周三；4：周四；5：周五；6：周六；7：周日；8：假日；  Weekly Index 1: Monday; 2: Tuesday; 3: Wednesday; 4: Thursday; 5: Friday; 6: Saturday; 7: Sunday; 8: Holidays;*/
    UINT32                      udwNum;                                          /*每天时间段个数 NVR最大为8段；IPC最大为4段  The maximum number of NVRs per day is 8; IPC maximum 4 paragraphs*/
    NETDEV_TIME_SECTION_INFO_S  astTimeSection[NETDEV_MAX_TIME_SECTION_NUM];         /* 时间段配置  Time Sections */
}NETDEV_DAY_PLAN_INFO_S, *LPNETDEV_DAY_PLAN_INFO_S;


/**
 * @brief 计划（周）配置 结构体定义 Play (Week) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlanWeekInfo
{
    BOOL                        bEnabled;                                           /*使能,仅IPC支持  Enabling,IPC only*/
    UINT32                      udwNum;                                             /* 计划天数，NVR最大为8(一周七天和假日)IPC最大为7(一周七天)  Planned days, NVR up to 8(7 days a week and holidays) IPC up to 7(7 days a week)*/
    NETDEV_DAY_PLAN_INFO_S      astDayPlanInfo[NETDEV_MAX_DAY_NUM];                 /* 一周内每天的布防计划列表  List of deployment plans for each day of the week*/
    BYTE                        byRes[512];                                         /* 保留字段  Reserved */
}NETDEV_WEEK_PLAN_INFO_S, *LPNETDEV_WEEK_PLAN_INFO_S;

/**
 * @brief 开关量计划（周）配置 结构体定义 Plan (Week) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVSwitchWeekPlanInfo
{
    UINT32                      udwSwitchIndex;                 /* 开关量索引 */
    NETDEV_WEEK_PLAN_INFO_S     astWeekPlanInfo;                /* 周计划配置信息 */
    BYTE                        byRes[128];                     /* 保留字段  Reserved */
}NETDEV_SWITCH_WEEK_PLAN_INFO_S, *LPNETDEV_SWITCH_WEEK_PLAN_INFO_S;

/************************************************ OSD********************************************************/

/**
 * @brief  区域 Area
 * @attention 无 None
 */
typedef struct tagNETDEVAreaScope
{
    INT32  dwLocateX;             /** 顶点x坐标值[0,10000] * Coordinates of top point x [0,10000] */
    INT32  dwLocateY;             /** 顶点y坐标值[0,10000] * Coordinates of top point y [0,10000] */
}NETDEV_AREA_SCOPE_S, *LPNETDEV_AREA_SCOPE_S;

/**
 * @brief OSD时间配置信息 OSD time configuration information
 * @attention 无 None
 */
typedef struct tagNETDEVOsdTime
{
    BOOL                    bEnableFlag;        /** 时间OSD使能, BOOL_TRUE为使能,BOOL_FALSE为非使能 * Enable time OSD, BOOL_TRUE means enable and BOOL_FALSE means disable */
    BOOL                    bWeekEnableFlag;    /** 是否显示星期(预留) * Display week or not (reserved) */
    NETDEV_AREA_SCOPE_S     stAreaScope;        /** 区域坐标 * Area coordinates */
    UINT32                  udwTimeFormat;      /** 时间OSD时间格式,详见NETDEV_OSD_TIME_FORMAT_CAP_E * Time OSD format, see NETDEV_OSD_TIME_FORMAT_E */
    UINT32                  udwDateFormat;      /** 日期OSD时间格式,详见NETDEV_OSD_DATE_FORMAT_CAP_E * Date OSD format, see NETDEV_OSD_TIME_FORMAT_E */
}NETDEV_OSD_TIME_S, *LPNETDEV_OSD_TIME_S;

/**
 * @brief OSD字符叠加信息 OSD text overlay information
 * @attention
 */
typedef struct tagNETDEVOsdTextOverlay
{
    BOOL                    bEnableFlag;                /** OSD字符叠加使能, BOOL_TRUE为使能,BOOL_FALSE为非使能 * Enable OSD text overlay, BOOL_TRUE means enable and BOOL_FALSE means disable */
    NETDEV_AREA_SCOPE_S     stAreaScope;                /** OSD字符叠加区域坐标 * OSD text overlay area coordinates */
    CHAR                    szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /** OSD字符叠加名称字符串 * OSD text overlay name strings */
    BYTE                    byRes[4];                               /* 保留字段  Reserved */
}NETDEV_OSD_TEXT_OVERLAY_S, *LPNETDEV_OSD_TEXT_OVERLAY_S;

/**
 * @brief 通道OSD的基本属性信息 Basic channel OSD information
 * @attention
 */
typedef struct tagNETDEVOsdCfgInfo
{
    NETDEV_OSD_TIME_S         stTimeOSD;        /* 通道的时间OSD信息  Information of channel time OSD */
    NETDEV_OSD_TEXT_OVERLAY_S stNameOSD;        /* 通道的名称OSD信息  Information of channel name OSD */
    INT16                     wTextNum;         /* 字符OSD个数  Text OSD number */
    NETDEV_OSD_TEXT_OVERLAY_S astTextOverlay[NETDEV_OSD_TEXTOVERLAY_NUM];   /* 通道OSD字符叠加信息  Information of channel OSD text overlay */
}NETDEV_VIDEO_OSD_CFG_S, *LPNETDEV_VIDEO_OSD_CFG_S;

/**
 * @brief 区域配置结构体定义 Definition of area configuration structure 
 * @attention
 */
typedef struct tagAreaInfo
{
    INT32   bIsEanbled;           /* 是否启用  Enable or not. */
    INT32   dwTopLeftX;           /* 左上角X [0, 10000]  Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /* 左上角Y [0, 10000]  Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /* 右下角X [0, 10000]  Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /* 右下角Y [0, 10000]  Lower right corner y [0, 10000] */
    INT32   dwIndex;              /* 索引  Index. */
}NETDEV_PRIVACY_MASK_AREA_INFO_S;

/**
 * @brief 隐私遮盖配置信息 Privacy mask configuration information
 * @attention
 */
typedef struct tagPrivacyMaskPara
{
    INT32                                  dwSize;                                     /* 区域个数  Mask area number */ 
    NETDEV_PRIVACY_MASK_AREA_INFO_S        astArea[NETDEV_MAX_PRIVACY_MASK_AREA_NUM];  /* 遮盖区域参数  Mask area parameters */
}NETDEV_PRIVACY_MASK_CFG_S, *LPNETDEV_PRIVACY_MASK_CFG_S;

/**
 * @brief 通道OSD的能力集 OSD Capabilities
 * @attention
 */
typedef struct tagNETDEVOsdCapabilities
{
    BOOL     bIsSupportCfg;                                                     /* 是否支持配置,0：不支持 1：支持 Support configuration or not. 0-No, 1-Ye*/
    BOOL     bIsSupportFontSizeCfg;                                             /* 是否支持OSD大小配置 Support configuration of OSD size or not*/ 
    BOOL     bIsSupportFontColorCfg;                                            /* 是否支持OSD颜色配置 upport configuration of OSD color or not*/ 
    UINT32   udwMaxAreaNum;                                                     /* 支持最大的OSD区域数 Maximum number of OSD area*/ 
    UINT32   udwMaxOSDNum;                                                      /* 支持最大的OSD个数 Maximum number of OSD*/ 
    UINT32   udwMaxPerAreaOSDNum;                                               /* 每个区域支持最大的OSD个数 Maximum number of OSD in each area*/ 
    UINT32   udwSupportedOSDTypeNum;                                            /* 支持的OSD内容类型数量 Number of OSD content type*/ 
    UINT32   udwSupportedTimeFormatNum;                                         /* 支持的时间OSD格式数量 Number of OSD time format*/ 
    UINT32   udwSupportedDateFormatNum;                                         /* 支持的日期OSD格式数量 Number of OSD date format*/ 
    UINT32   aduwSupportedDateFormatList[NETDEV_OSD_DATE_FORMAT_MAX_NUM];       /* 日期OSD格式列表，参见枚举NETDEV_OSD_DATE_FORMAT_E */ 
    UINT32   audwSupportedTimeFormatList[NETDEV_OSD_TIME_FORMAT_MAX_NUM];       /* 时间OSD格式列表，参见枚举NETDEV_OSD_TIME_FORMAT_E */ 
    UINT32   audwSupportedOSDTypeList[NETDEV_OSD_TYPE_MAX_NUM];                 /* 支持配置的OSD内容类型列表，参见枚举NETDEV_OSD_CONTENT_TYPE_E */ 
}NETDEV_OSD_CAP_S, *LPNETDEV_OSD_CAP_S;

/**
 * @brief 通道OSD内容样式 Display Style of channel OSD
 * @attention
 */
typedef struct tagNETDEVOsdContentStyle
{
    UINT32 udwFontStyle;                         /* 字体形式，参见枚举NETDEV_OSD_FONT_STYLE_E。  Font style. For enumeration, seeNETDEV_OSD_FONT_STYLE_E*/
    UINT32 udwFontSize;                          /* 字体大小，参见枚举NETDEV_OSD_FONT_SIZE_E。  Font Size. For enumeration, seeNETDEV_OSD_FONT_SIZE_E*/
    UINT32 udwColor;                             /* 颜色 Color*/
    UINT32 udwDateFormat;                        /* 日期格式，参见枚举NETDEV_OSD_DATE_FORMAT_E。  Date Format. For enumeration, seeNETDEV_OSD_DATE_FORMAT_E */
    UINT32 udwTimeFormat;                        /* 时间格式，参见枚举NETDEV_OSD_TIME_FORMAT_E。  Date Format. For enumeration, seeNETDEV_OSD_DATE_FORMAT_E */
    UINT32 audwFontAlignList[NETDEV_LEN_8];      /* 区域内字体对齐，固定8个区域，IPC支持,参见枚举NETDEV_OSD_ALIGN_E。  Font align in area, 8 areasfixed, IPcamera supported. For enumeration, seeNETDEV_OSD_ALIGN_E */
    UINT32 udwMargin;                            /* 边缘空的字符数，IPC支持，参见枚举NETDEV_OSD_MIN_MARGIN_E。  Number of character with margin, IP camera supported. For enumeration, seeNETDEV_OSD_MIN_MARGIN_E */
}NETDEV_OSD_CONTENT_STYLE_S,*LPNETDEV_OSD_CONTENT_STYLE_S;

/**
 * @brief 内容信息 Content
 * @attention
 */
typedef struct tagNETDEVContentInfo
{

    UINT32 udwContentType;                        /* OSD内容类型,参见枚举NETDEV_OSD_CONTENT_TYPE_E OSD content type. For enumeration, see NETDEV_OSD_CONTENT_TYPE_E*/
    CHAR   szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /* OSD文本信息 OSD text*/
}NETDEV_CONTENT_INFO_S,*LPNETDEV_CONTENT_INFO_S;

/**
 * @brief 通道OSD内容信息 Channel OSD content
 * @attention
 */
typedef struct tagNETDEVOSDContentInfo
{
    BOOL   bEnabled;                                        /* OSD区域使能 Enable OSD area*/
    UINT32 udwOSDID;                                        /* OSD区域序号，范围[0,7] Area No., ranges from 0 to 7.*/
    UINT32 udwAreaOSDNum;                                   /* 当前区域内OSD数目 Number of OSD in current area*/
    UINT32 udwTopLeftX;                                     /* OSD区域横坐标,范围[0,9999] X-axis of OSD area, ranges from 0 to 999*/
    UINT32 udwTopLeftY;                                     /* OSD区域纵坐标,范围[0,9999] Y-axisof OSD area, ranges from 0 to 999*/
    NETDEV_CONTENT_INFO_S astContentInfo[NETDEV_LEN_8];     /* 当前区域内OSD内容信息 OSD content in current area*/
}NETDEV_OSD_CONTENT_INFO_S,*LPNETDEV_OSD_CONTENT_INFO_S;

/**
 * @brief 通道OSD所有内容 All contents of channel OSD
 * @attention
 */
typedef struct tagNETDEVOsdContent
{
    UINT32                    udwNum;                          /* OSD区域数量 Number of OSD area*/
    NETDEV_OSD_CONTENT_INFO_S astContentList[NETDEV_LEN_32];   /* OSD区域内容信息列表 Content list of OSD area

*/
}NETDEV_OSD_CONTENT_S,*LPNETDEV_OSD_CONTENT_S;

/************************************************ 视频分析********************************************************/

/**
 * @brief 遮挡检测分析信息 Tampering detection analysis info
 * @attention 无 None
 */
typedef struct tagNETDEVTamperAlarmInfo
{
    INT32  dwSensitivity;                               /* 灵敏度  Sensitivity */
    BYTE   byRes[256];                                  /* 保留字段  Reserved */
}NETDEV_TAMPER_ALARM_INFO_S, *LPNETDEV_TAMPER_ALARM_INFO_S;

/**
 * @brief 运动检测分析信息 Motion detection analysis info
 * @attention 无 None
 */
typedef struct tagNETDEVMotionAlarmInfo
{
    INT32  dwSensitivity;                                                     /* 灵敏度  Sensitivity */
    INT32  dwObjectSize;                                                      /* 物体大小  Objection Size */
    INT32  dwHistory;                                                         /* 持续时间  History */
    INT16  awScreenInfo[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];   /* 屏幕宏块信息  Screen Info */
    BYTE   byRes[64];                                                         /* 保留字段  Reserved */
}NETDEV_MOTION_ALARM_INFO_S, *LPNETDEV_MOTION_ALARM_INFO_S;

/**
 * @struct tagNETDEVMotionDetectionAreaGridInfo
 * @brief 运动检测宏块区域信息 Motion detection area grid info
 * @attention 无 None
 */
typedef struct tagNETDEVMotionDetectionAreaGridInfo
{
    BOOL    bEnabled;                                                        /* 区域使能标识 */
    UINT32  udwSensitivity;                                                  /* 运动检测灵敏度，值越大越灵敏，范围[1,100]  Sensitivity */
    INT16   awGridInfo[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];  /* 检测区域屏幕宏块信息  Grid Info */
    BYTE    byRes[256];                                                         /* 保留字段  Reserved */
}NETDEV_MOTION_DETECTION_AREA_GRID_INFO_S, *LPNETDEV_MOTION_DETECTION_AREA_GRID_INFO_S;

/**
 * @struct tagNETDEVRectAreaInfo
 * @brief 矩形区域坐标信息 结构体定义 Rectangle Area info  Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVRectAreaInfo
{
    UINT32   udwTopLeftX;                       /* x轴左点值 X axis left point value */
    UINT32   udwTopLeftY;                       /* y轴顶点值 Y axis top point value */
    UINT32   udwBottomRightX;                   /* x轴右点值 X axis right point value */
    UINT32   udwBottomRightY;                   /* y轴底点值 Y axis bottom point value */
}NETDEV_RECT_AREA_INFO_S, *LPNETDEV_RECT_AREA_INFO_S;

/**
 * @struct tagNETDEVMotionDetectionAreaRectangleInfo
 * @brief 运动检测矩形区域信息 Motion detection area rectangle info
 * @attention 无 None
 */
typedef struct tagNETDEVMotionDetectionAreaRectangleInfo
{
    UINT32  udwID;                              /* 矩形区域编号 */
    BOOL    bEnabled;                           /* 区域使能标识 */
    UINT32  udwSensitivity;                     /* 运动检测灵敏度，值越大越灵敏，范围[1,100]  Sensitivity */
    UINT32  udwDuration;                        /* 持续时间，范围[1,100] */
    UINT32  udwTargetSize;                      /* 物体大小，范围[1,100] */
    NETDEV_RECT_AREA_INFO_S   stRectAreaInfo;   /* 矩形区域信息,坐标值范围[0,9999]  rectangle area Info [0,9999] */
    BYTE    byRes[128];                                                         /* 保留字段  Reserved */
}NETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_S, *LPNETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_S;

/**
 * @struct tagNETDEVMotionDetectionAreaRectangleInfoList
 * @brief 运动检测矩形区域信息列表 Motion detection area rectangle info
 * @attention 无 None
 */
typedef struct tagNETDEVMotionDetectionAreaRectangleInfoList
{
    UINT32                                          udwNum;                                 /* 矩形区域个数 */
    NETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_S   astRectangleAreaInfoList[NETDEV_LEN_8]; /* 矩形区域信息列表 */
    BYTE    byRes[128];                                                                     /* 保留字段  Reserved */
}NETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST_S, *LPNETDEV_MOTION_DETECTION_AREA_RECTANGLE_INFO_LIST_S;

/**
* @enum tagNETDEVMotionDetectionAreaType
* @brief 运动检测区域类型信息 motion detection area type
* @attention 
*/
typedef struct tagNETDEVMotionDetectionAreaType
{
    UINT32  udwAreaType;                    /* 区域类型 参见枚举#NETDEV_MOTION_DETECTION_AREA_TYPE_E */
    BYTE    byRes[128];                     /* 保留字节 */
}NETDEV_MOTION_DETECTION_AREA_TYPE_S, *LPNETDEV_MOTION_DETECTION_AREA_TYPE_S;

typedef struct tagNETDEVCrossLinePointInfo
{
    BOOL    bEnable;                /* 是否启用  Supported or not */
    INT32   dwSensitivity;        /* 灵敏度  Sensitivity */
    INT32   dwDirection;          /* 触发方向 trigger Direction */
    INT32   dwTopLeftX;           /* 左上角X [0, 10000]  Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /* 左上角Y [0, 10000]  Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /* 右下角X [0, 10000]  Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /* 右下角Y [0, 10000]  Lower right corner y [0, 10000] */
}NETDEV_CROSS_LINE_POINT_INFO_S, *LPNETDEV_CROSS_LINE_POINT_INFO_S;

/**
* @brief 越界检测分析信息
* @attention 无 None
*/
typedef struct tagNETDEVCrossLineAlarmInfo
{
    BOOL    bEnable;                                                  /* 是否启用  Supported or not */
    NETDEV_CROSS_LINE_POINT_INFO_S stAreaInfo[4];                       /* 区域信息 area info */
    BYTE   byRes[64];                                                   /* 保留字段  Reserved */
}NETDEV_CROSS_LINE_ALARM_INFO_S, *LPNETDEV_CROSS_LINE_ALARM_INFO_S;

/**
* @brief 入侵检测区域点坐标
* @attention 无 None
*/
typedef struct tagNETDEVIntrusionPointInfo
{

    INT32   dwPointX;           /* X [0, 10000]*/
    INT32   dwPointY;           /* Y [0, 10000]*/
}NETDEV_INTRUSION_POINT_INFO_S, *LPNETDEV_INTRUSION_POINT_INFO_S;


/**
* @brief 入侵检测区域信息
* @attention 无 None
*/
typedef struct tagNETDEVIntrusionAreaInfo
{
    BOOL    bEnable;                                            /* 是否启用  Supported or not */
    INT32   dwSensitivity;                                      /* 灵敏度，范围1-100  Sensitivity */
    INT32   dwTimeThreshold;                                    /* 时间阈值 范围1-10*/
    INT32   percentage;                                         /* 比率 范围1-100 */
    INT32   dwPointCount;                                       /* 区域点个数，范围3-6，如果不设置该区域，点个数将忽略，*/
    NETDEV_INTRUSION_POINT_INFO_S   stPointInfo[NETDEV_LEN_6];  /* 区域点坐标信息 */
    BYTE   byRes[64];                                           /* 保留字段  Reserved */

}NETDEV_INTRUSION_AREA_INFO_S, *LPNETDEV_INTRUSION_AREA_INFO_S;

/**
* @brief 入侵检测分析信息
* @attention 无 None
*/
typedef struct tagNETDEVIntrusionAlarmInfo
{
    BOOL    bEnable;                                                  /* 是否启用  Supported or not */
    NETDEV_INTRUSION_AREA_INFO_S stAreaInfo[NETDEV_LEN_4];            /* 区域信息 ，最多支持设置4个区域，每个区域由三到六边形构成 area info */
    BYTE   byRes[64];                                                   /* 保留字段  Reserved */
}NETDEV_INTRUSION_ALARM_INFO_S, *LPNETDEV_INTRUSION_ALARM_INFO_S;

/**
 * @brief 协议信息  Protocol info
 * @attention 无 None
 */
typedef struct tagNETDEVUpnpPortState
{
    NETDEV_PROTOCOL_TYPE_E   eType;                            /* 协议类型参见枚举# NETDEV_PROTOCOL_TYPE_E  Protocol type, see enumeration #NETDEV_PROTOCOL_TYPE_E */
    BOOL                     bEnbale;                          /* 是否支持  Supported or not */
    INT32                    dwPort;                           /* 端口号  Port number */
    BYTE                     byRes[128];                       /* 保留字段  Reserved */
}NETDEV_UPNP_PORT_STATE_S, *LPNETDEV_UPNP_PORT_STATE_S;


/**
 * @brief 协议信息列表  Protocol info list
 * @attention 无 None
 */
typedef struct tagNETDEVUpnpNatState
{
    INT32   dwSize;                                            /* 协议个数  Number of protocols */
    NETDEV_UPNP_PORT_STATE_S  astUpnpPort[NETDEV_LEN_16];      /* 协议信息  Protocol info */
}NETDEV_UPNP_NAT_STATE_S, *LPNETDEV_UPNP_NAT_STATE_S;


/**
 * @brief 设备发现的设备信息  Info of discovered device
 * @attention 无 None
 */
typedef struct tagNetDEVDiscoveryDevInfo
{
    CHAR    szDevAddr[NETDEV_LEN_64];                            /* 设备地址  Device address */
    CHAR    szDevModule[NETDEV_LEN_64];                          /* 设备型号  Device model */
    CHAR    szDevSerailNum[NETDEV_LEN_64];                       /* 设备序列号  Device serial number */
    CHAR    szDevMac[NETDEV_LEN_64];                             /* 设备MAC地址  Device MAC address */
    CHAR    szDevName[NETDEV_LEN_64];                            /* 设备名称  Device name */
    CHAR    szDevVersion[NETDEV_LEN_64];                         /* 设备版本  Device version */
    NETDEV_DEVICE_TYPE_E  enDevType;                              /* 设备类型  Device type */
    INT32   dwDevPort;                                           /* 设备端口号  Device port number */
    CHAR    szManuFacturer[NETDEV_LEN_64];                       /* 生产商 Device manufacture */
    CHAR    szActiveCode[NETDEV_LEN_64];                         /* 激活码 activeCode */
    CHAR    szCloudUserName[NETDEV_LEN_64];                       /* 云用户名称 cloudUserName */
    BYTE    byRes[68];                                              /* 保留字段  Reserved */
}NETDEV_DISCOVERY_DEVINFO_S, *LPNETDEV_DISCOVERY_DEVINFO_S;

/**
* @brief 时间参数 结构体定义 Time parameter Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVTime
{
    INT32   dwYear;                       /* 年  Year */
    INT32   dwMonth;                      /* 月  Month */
    INT32   dwDay;                        /* 日  Day */
    INT32   dwHour;                       /* 时  Hour */
    INT32   dwMinute;                     /* 分  Minute */
    INT32   dwSecond;                     /* 秒  Second */
}NETDEV_TIME_S, *LPNETDEV_TIME_S;

/**
* @brief 时间配置 结构体定义 Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeDST
{
    INT32 dwMonth;              /* 月(1~12)  Month(1~12)*/
    INT32 dwWeekInMonth;        /* 每月的第N周（1~5）  1 for the first week and 5 for the last week in the month */
    INT32 dwDayInWeek;          /* 每周的星期几 参见#NETDEV_DAY_IN_WEEK_E  0 for Sunday and 6 for Saturday see enumeration NETDEV_DAY_IN_WEEK_E */
    INT32 dwHour;               /* 时  Hour */
}NETDEV_TIME_DST_S, *LPNETDEV_TIME_DST_S;

/**
* @brief 时间配置 结构体定义 Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeDSTCfg
{
    NETDEV_TIME_DST_S   stBeginTime;        /* 夏令时开始时间 参见枚举#NETDEV_TIME_DST_S  DST begin time see enumeration NETDEV_TIME_DST_S */
    NETDEV_TIME_DST_S   stEndTime;          /* 夏令时结束时间 参见枚举#NETDEV_TIME_DST_S  DST end time see enumeration NETDEV_TIME_DST_S */
    INT32               dwOffsetTime;       /* 夏令时节约时间 参见枚举# NETDEV_DST_OFFSET_TIME  DST saving time see enumeration NETDEV_DST_OFFSET_TIME */
}NETDEV_TIME_DST_CFG_S, *LPNETDEV_TIME_DST_CFG_S;

/**
* @brief 时间配置 结构体定义 Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeInfo
{
    NETDEV_TIME_ZONE_E      dwTimeZone;             /* 时区 参见枚举#NETDEV_TIME_ZONE_E  Time zone, see enumeration #NETDEV_TIME_ZONE_E */
    NETDEV_TIME_S           stTime;                 /* 时间  Time */
    BOOL                    bEnableDST;             /* 夏令时使能 DST enable */
    NETDEV_TIME_DST_CFG_S   stTimeDSTCfg;           /* 夏令时配置 DST time config*/
    UINT32                  udwDateFormat;          /* 日期格式 0：YYYY-MM-DD 年月日 1：MM-DD-YYYY 月日年 2：DD-MM-YYYY 日月年*/
    UINT32                  udwHourFormat;          /* 时间格式 0 ：12小时制  1:24 小时制*/
    BYTE                    byRes[212];             /* 保留字段  Reserved */
}NETDEV_TIME_CFG_S, *LPNETDEV_TIME_CFG_S;

/**
* @brief 夏令时配置信息 结构体定义 DST configuration structure definition
* @attention
*/
typedef struct tagNETDEVDSTCfgInfo
{
    BOOL                    bEnableDST;             /* 夏令时使能 DST enable */
    NETDEV_TIME_DST_CFG_S   stTimeDSTCfg;           /* 夏令时配置 DST time config*/
    BYTE                    byRes[128];             /* 保留字段  Reserved */
}NETDEV_DST_CFG_S, *LPNETDEV_DST_CFG_S;

/**
* @brief 超时时间 结构体定义  Timeout structure definition
* @attention
*/
typedef struct tagNETDEVRevTimeout
{
    INT32   dwRevTimeOut;                 /* 设置接收超时时间 Set timeout for receiving */
    INT32   dwFileReportTimeOut;          /* 设置文件操作超时时间 Set timeout for file operation */
    BYTE    byRes[128];                   /* 保留字段  Reserved */
}NETDEV_REV_TIMEOUT_S, *LPNETDEV_REV_TIMEOUT_S;




/**
 * @brief 硬盘详细信息 Disk info
 * @attention 无 None
 */
typedef struct tagNETDEVDiskInfo
{
    INT32 dwDiskCabinetIndex;
    INT32 dwSlotIndex;                          /* 硬盘所在槽位索引 Slot Index */
    INT32 dwTotalCapacity;                      /* 硬盘总容量 Total Capacity */
    INT32 dwUsedCapacity;                       /* 已经使用量 Used Capacity */
    NETDEV_DISK_WORK_STATUS_E enStatus;         /* 运行状态 Status */
    CHAR szManufacturer[NETDEV_LEN_32];         /* 厂商 Manufacturer */
}NETDEV_DISK_INFO_S,*LPNETDEV_DISK_INFO_S;

/**
 * @brief 硬盘信息列表 Disk info list
 * @attention 无 None
 */
typedef struct tagNETDEVDiskInfoList
{
    INT32 dwSize;                                       /* 硬盘个数 Disk number */
    NETDEV_DISK_INFO_S astDisksInfo[NETDEV_DISK_MAX_NUM];     /* 硬盘信息 Disk info */
}NETDEV_DISK_INFO_LIST_S,*LPNETDEV_DISK_INFO_LIST_S;

/**
* @brief 透雾信息 Defogging info
* @attention
*/
typedef struct tagNETDEVDefoggingInfo
{
    NETDEV_DEFOGGING_MODE_E  enDefoggingMode;           /* 除雾模式 Defogging mode */
    FLOAT                    fDefoggingLevel;           /* 除雾等级 Defogging level (0.0, 1.0) */
    BYTE                     bRes[64];                  /* 保留字段 Reserved */
}NETDEV_DEFOGGING_INFO_S, *LPNETDEV_DEFOGGING_INFO_S;

/**
* @brief 聚焦信息 Focus Info
* @attention
*/
typedef struct tagNETDEVFocusInfo
{
    NETDEV_FOCUS_MODE_E     enFocusMode;                /* 聚焦模式 Defogging mode */
    BYTE                    bRes[16];                   /* 保留字段 Reserved */
}NETDEV_FOCUS_INFO_S, *LPNETDEV_FOCUS_INFO_S;


/**
* @brief 昼夜模式信息 IrCut filter info
* @attention
*/
typedef struct tagNETDEVIrFilterInfo
{
    NETDEV_IR_CUT_FILTER_MODE_E enIrCutFilterMode;      /* 昼夜模式 IrCut Filter mode */
    BYTE                        bRes[16];               /* 保留字段 Reserved */
}NETDEV_IRCUT_FILTER_INFO_S, *LPNETDEV_IRCUT_FILTER_INFO_S;

/**
* @brief 手动录像 结构体定义 Manual Record structure definition
* @attention
*/
typedef struct tagNETDEVManualRecordcfg
{
    INT32                   dwChannelID;        /* 通道号  ChannelID */
    NETDEV_RECORD_TYPE_E    enRecordType;       /* 录像类型 Record type 参考#NETDEV_RECORD_TYPE_E */
    BYTE                    byRes[64];          /* 保留字段  Reserved */
}NETDEV_MANUAL_RECORD_CFG_S, *LPNETDEV_MANUAL_RECORD_CFG_S;


/**
 * @brief 按月查询录像分布信息配置 结构体定义 get video by Month Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVMonthInfo
{
    UINT32  udwYear;        /* 年份  year*/
    UINT32  udwMonth;       /* 月份  month */
    UINT32  udwPosition;    /* 录像查询位置 NETDEV_VIDEO_POSITION_E video query location */
}NETDEV_MONTH_INFO_S, *LPNETDEV_MONTH_INFO_S;

/**
 * @brief 录像分布状态 结构体定义 video status Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVMonthStatus
{
    UINT32  udwDayNumInMonth;                       /* 某月的实际天数 The number of a month's days */
    UINT32  szVideoStatus[NETDEV_MONTH_DAY_MAX];    /* 录像状态列表 video status list, see in NETDEV_VIDEO_STATUS_E */
}NETDEV_MONTH_STATUS_S, *LPNETDEV_MONTH_STATUS_S;


/**
 * @brief 多通道 结构体定义 multichannel Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVChannels
{
    UINT32  udwSize;                            /* 通道个数 Channel size */
    INT32   dwChannelIDs[NETDEV_CHANNEL_MAX];   /* 需要查询的视频输入通道号列表 Channel ID list[1,2,3,4] */
}NETDEV_CHANNELS_S, *LPNETDEV_CHANNELS_S;


/**
* @brief 客流量统计命令 结构体定义 Command of Passenger flow statistic Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVTrafficStatisticsCond
{
    INT32       dwChannelID;            /* 通道号 Channel ID */
    INT32       dwStatisticsType;       /* 统计模式 参考# NETDEV_TRAFFIC_STATISTICS_TYPE_E Statistics type */
    INT32       dwFormType;             /* 统计报表 参考# NETDEV_FORM_TYPE_E Form type */
    INT64       tBeginTime;             /* 起始时间 Begin time */
    INT64       tEndTime;               /* 结束时间 End time */
}NETDEV_TRAFFIC_STATISTICS_COND_S, *LPNETDEV_TRAFFIC_STATISTICS_COND_S;

/**
* @brief 客流量统计 结构体定义 Passenger flow statistic Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVTrafficStatisticsData
{
    INT32  dwSize;                                          /* 报表长度 根据不同报表类型长度不同 */
    INT32  adwEnterCount[NETDEV_PEOPLE_CNT_MAX_NUM];        /* 进入人数计数值 */
    INT32  adwExitCount[NETDEV_PEOPLE_CNT_MAX_NUM];         /* 离开人数计数值 */
}NETDEV_TRAFFIC_STATISTICS_DATA_S, *LPNETDEV_TRAFFIC_STATISTICS_DATA_S;


/**
* @brief 定位信息 结构体定义 Geolocation info Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVGeolocationInfo 
{
    FLOAT fLongitude;       /* 经度 Longitude */
    FLOAT fLatitude;        /* 纬度 Latitude */
}NETDEV_GEOLACATION_INFO_S, *LPNETDEV_GEOLACATION_INFO_S;

/**
* @brief WIFISnifferMac信息 结构体定义  WIFISnifferMac info Structure definition 
* @attention 无 None
*/
typedef struct tagNETDEVWiFiSnifferMacInfo
{
    CHAR  aszMACInfo[NETDEV_WIFISNIFFER_MAC_MAX_NUM];     /* WiFi sniffer mac 地址 WiFi sniffer mac address*/
    INT16 wMaxSig;                                        /* Mac地址对应最大信号强度,单位dBm Mac address’ corresponding max signal strength (in dBm) */
    CHAR  aszMaxSigTime[NETDEV_MAX_DATE_STRING_LEN];      /* Mac地址对应最大信号强度获取时间 Time to obtain Mac address’ corresponding max signal strength*/
}NETDEV_WIFISNIFFER_MAC_INFO_S, *LPNETDEV_WIFISNIFFER_MAC_INFO_S;

/**
* @brief WIFISnifferMac数组信息 结构体定义 WIFISnifferMac array Structure definition  
* @attention 无 None
*/
typedef struct tagNETDEVWiFiSnifferMacList
{
    INT32 dwSize;
    NETDEV_WIFISNIFFER_MAC_INFO_S  astMACList[NETDEV_WIFISNIFFER_MAC_ARRY_MAX_NUM];
}NETDEV_WIFISNIFFER_MAC_LIST_S, *LPNETDEV_WIFISNIFFER_MAC_LIST_S;


typedef struct tagNETDEVAlarmSnapShotCond
{
    INT32                           dwChannelID;                                /* 通道号  Channel number 或者 开关量告警编号，参数为通道号*100+报警输出号，设备本身通道号为0*/
    INT64                           tAlarmTime;                                 /* 告警产生时间 */
    NETDEV_ALARM_SNAPSHOT_TYPE_E    enAlarmType;                                /* 告警类型 */
    BYTE                            byRes[244];                                 /* 保留字段  Reserved */
}NETDEV_ALARM_SNAPSHOT_COND_S,*LPNETDEV_ALARM_SNAPSHOT_COND_S;

typedef struct tagNETDEVAlarmSnapShotPicInfo
{
    CHAR    szURL[NETDEV_MAX_URL_LEN];  /* 图片URL */
    CHAR    szName[NETDEV_LEN_64];      /* 图片名称 */
    INT32   dwSize;                     /* 图片大小 */
    BYTE    byRes[256];                 /* 保留字段  Reserved */
}NETDEV_ALARM_SNAPSHOT_PIC_S,*LPNETDEV_ALARM_SNAPSHOT_PIC_S;

typedef struct tagNETDEVSnapShotFileInfo
{
    CHAR    szURL[NETDEV_MAX_URL_LEN];         /* 图片URL */
    BOOL    bSaveLocal;                        /* 是否保存在本地，TURE表示保存本地，FALSE表示写入缓存 */
    CHAR    szFileName[NETDEV_LEN_260];        /* 保存图片的本地路径及名称 */
    CHAR*   pcBuffer;                          /* 保存图片缓存,需客户申请内存，大小为dwSize缓存大小 */
    INT32   dwSize;                            /* 缓存大小 */
    INT32   dwCaptureMode;                     /* 保存图像格式,参见#NETDEV_PICTURE_FORMAT_E*/
    BYTE    byRes[252];                        /* 保留字段  Reserved */
}NETDEV_PIC_FILE_INFO_S, *LPNETDEV_PIC_FILE_INFO_S;

/************************************************************************/
/*                       NVR周计划配置                                  */
/************************************************************************/

/**
 * @brief 时间段配置 结构体定义 Time Sections Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoTimeSection
{
    CHAR    szBeginTime[NETDEV_LEN_64];              /* 开始时间  Begin time */
    CHAR    szEndTime[NETDEV_LEN_64];                /* 结束时间  End time */
    UINT32  udArmingType;                            /* 布防类型   ArmingType 参考NETDEV_ARMING_TYPE_E */
}NETDEV_VIDEO_TIME_SECTION_S, *LPNETDEV_VIDEO_TIME_SECTION_S;

/**
 * @brief 计划（天）配置 结构体定义 Play (Day) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoDayPlan
{
    UINT32                         udwIndex;                                                  /* 星期索引,参见：NETDEV_LAPI_WEEK_INFO_E  day index */
    UINT32                         udwSectionNum;                                             /* 每天时间段个数  Section Num NVR最大为8段,IPC最大为4段 */
    NETDEV_VIDEO_TIME_SECTION_S    astTimeSection[NETDEV_MAX_TIME_SECTION_NUM];   /* 布防时间段配置  Time Sections */
}NETDEV_VIDEO_DAY_PLAN_S, *LPNETDEV_VIDEO_DAY_PLAN_S;

/**
 * @brief  计划（周）配置 结构体定义  Plan (Week) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoPlanWeek
{
    BOOL                        bEnabled;                                            /* 布防计划是否使能,仅IPC支持该字段，默认使能;参考NETDEV_DEFENCE_PLAN_ENABLE_E */
    UINT32                      udwDayNum;                                           /* 计划天数,NVR最大为8(一周七天和假日);IPC最大为7(一周七天) */
    NETDEV_VIDEO_DAY_PLAN_S     astDayPlan[NETDEV_MAX_DAY_NUM];         /* 一周内每天的布防计划列表 */
    BYTE                        byRes[32];                                         /* 保留字段 */
}NETDEV_VIDEO_WEEK_PLAN_S, *LPNETDEV_VIDEO_WEEK_PLAN_S;

/**
 * @brief  录像计划规则 结构体定义   Record Rule Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVRecordRule
{
    UINT32                      udwPreRecordTime;                                  /* 警前预录时间,参考NETDEV_PRE_RECORD_TIME_E */
    UINT32                      udwPostRecordTime;                                 /* 警后录像时间,参考NETDEV_POST_RECORD_TIME_E */
    BYTE                        byRes[32];                                         /* 保留字段 */
}NETDEV_RECORD_RULE_S, *LPNETDEV_RECORD_RULE_S;

/**
 * @brief  录像计划配置信息 结构体定义   Record plan config info Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVRecordPlanCfgInfo
{
    BOOL                       bPlanEnable;                                        /* 计划使能 */
    BOOL                       bRedundantStorage;                                  /* 冗余录像使能 */
    NETDEV_RECORD_RULE_S       stRecordRule;                                       /* 录像计划规则 */
    NETDEV_VIDEO_WEEK_PLAN_S   stWeekPlan;                                         /* 计划配置 */
    BYTE                       byRes[128];                                         /* 保留字段 */
}NETDEV_RECORD_PLAN_CFG_INFO_S, *LPNETDEV_RECORD_PLAN_CFG_INFO_S;

/**
 * @brief  告警信息 结构体定义 Alarm infomation Sturcture definition
 * @attention 无 None
 note:
 1. dwAlarmSrcType为NETDEV_ALARM_SRC_LOCAL_HARD_DISK到NETDEV_ALARM_SRC_SD_STORAGE_DISK之间，dwChannelID代表存储盘索引；
 2. dwAlarmSrcType为8，dwChannelID代表视频通道号；
 3. dwAlarmSrcType为9，dwChannelID代表报警输入通道号，报警源见dwInputSwitchID字段。
 4. dwAlarmSrcType为10,dwChannelID默认为0,代表系统本身
 */
typedef struct tagNETDEVAlarmInfoEx
{ 
    INT32   dwAlarmType;                        /* 告警类型,参见枚举#NETDEV_ALARM_TYPE_E  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT64   tAlarmTime;                         /* 告警发生时间  Alarm time */
    INT32   dwChannelID;                        /* 通道号 */
    INT32   dwAlarmSrcType;                     /* 告警源类型 参见枚举#NETDEV_ALARM_SRC_TYPE_E */
    CHAR    szAlarmSrcName[NETDEV_LEN_132];     /* 告警源名称,当告警源类型无效NETDEV_ALARM_SRC_INVALID时有效 */
    UINT16  wIndex;                             /* 索引号  Index number, index number */
    INT32   dwTotalBandWidth;                   /* 当前带宽总量,单位为MBps  Current total bandwidth (in MBps) */
    INT32   dwUnusedBandwidth;                  /* 未使用的带宽,单位为MBps  Bandwidth left (in MBps)*/
    INT32   dwTotalStreamNum;                   /* 总路数 Total cameras*/
    INT32   dwFreeStreamNum;                    /* 未使用路数 Cameras left */
    INT32   dwMediaMode;                        /* 流类型,参见枚举#NETDEV_MEDIA_MODE_E Stream type. For enumerations, see#NETDEV_MEDIA_MODE_E*/
    INT32   dwAlarmLevel;                       /* 告警等级，1到5级，1级最严重 */
    INT32   dwAlarmSeq;                         /* 告警序号 */
    BYTE    byRes[248];                         /* 保留字段 */
}NETDEV_ALARM_INFO_EX_S, *LPNETDEV_ALARM_INFO_EX_S;


/**
* @enum tagNETDEVFGSubInfo
* @brief 人脸告警订阅信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonSubInfo
{
    UINT32 udwType;                         /* 订阅类型 
                                               按BIT位进行描述，每个BIT位，对应一种订阅类型，
                                               从右到左依次为第0位-第31位，相应的BIT为1代表订阅类型有效。
                                               Bit0：人脸采集
                                               Bit1：人脸比对 */
    UINT32 udwLibIDNum;                     /* 订阅的库ID数目 LibIDNum为0xffff时 表示订阅所有库 */
    UINT32 audwLibIDList[NETDEV_LEN_32];    /* 订阅的库ID列表 */
    UINT32 udwFileType;                     /* 响应携带的数据类型
                                               PicType|1:人脸大图
                                               PicType|(1<<1):人脸小图
                                               PicType|(1<<2):库图片 
                                               不携带默认返回有的图片类型 */
    BYTE   byRes[128];                      /* 保留字节 */
}NETDEV_PERSON_SUB_INFO_S,*LPNETDEV_PERSON_SUB_INFO_S;

/**
* @enum tagNETDEVFGSubSuccInfo
* @brief 速通门订阅信息成功返回信息
* @attention 无 None
*/
typedef struct tagNETDEVSubscribeSuccInfo
{
    UINT32 udwID;                   /* 订阅ID */
    UINT32 udwCurrrntTime;          /* 当前时间，UTC格式，从1970年1月1日0点开始的秒数 */
    UINT32 udwTerminationTime;      /* 结束时间，UTC格式，从1970年1月1日0点开始的秒数 */
    BYTE   byRes[128];              /* 保留字节 */
}NETDEV_SUBSCRIBE_SUCC_INFO_S,*LPNETDEV_SUBSCRIBE_SUCC_INFO_S;

/**
* @struct tagNETDEVResInfo
* @brief 资源数据变更信息 结构体定义
* @attention 无
*/
typedef struct tagNETDEVResInfo
{
    UINT32   udwResType;                              /* 资源类型, 请参考#NETDEV_RES_TYPE_E */
    UINT32   udwResID;                                /* 资源ID*/
    BYTE     byRes[256];                              /* 保留字段  Reserved */
}NETDEV_RES_CHANGE_INFO_S, *LPNETDEV_RES_CHANGE_INFO_S;

/**
* @struct tagNETDEVResChangeEventInfo
* @brief 资源变更事件 结构体定义
* @attention 无
*/
typedef struct tagNETDEVResChangeEventInfo
{
    CHAR     szReference[NETDEV_LEN_260];                           /* 用于客户端确认推送告警事件消息的url
                                                                    <SubscribersID>:便于同一IP和port用户多点登陆时区分不同的订阅客户端*/
    UINT32   udwAction;                                             /* 资源变更子事件类型, 请参考#NETDEV_RES_CHANGE_SUBEVENT_TYPE_E */
    UINT32   udwNum;                                                /* 变更的资源个数*/
    NETDEV_RES_CHANGE_INFO_S   audwResInfos[NETDEV_CHANNEL_MAX];    /* 资源数据变更信息*/
    BYTE     byRes[256];                                            /* 保留字段  Reserved */
}NETDEV_RES_CHANGE_EVENT_INFO_S, *LPNETDEV_RES_CHANGE_EVENT_INFO_S;


/**
 * @brief 云端设备登录信息    Cloud Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNetDEVCloudDevLoginInfo
{

    CHAR    szDeviceName[NETDEV_LEN_260];       /* 设备名称 Device name */
    CHAR    szDevicePassword[NETDEV_LEN_64];    /* 设备登录密码 (可选) Device login password (optional) */
    INT32   dwT2UTimeout;                       /* P2P超时时间, 默认为15s P2P timeout (default: 15s) */
    INT32   dwConnectMode;                      /* 连接模式 Connect Mode  参见枚举NETDEV_CLOUD_CONNECT_MODE  传NETDEV_CLOUD_CONNECT_MODE_ALL时无法准确获取最终登陆成的模式时打洞还是转发*/
    NETDEV_LOGIN_PROTO_E dwLoginProto;      	/* 登录协议, 参见NETDEV_LOGIN_PROTO_E */
    BYTE  byRes[252];                       	/* 保留字段 */
} NETDEV_CLOUD_DEV_LOGIN_INFO_S, *LPNETDEV_CLOUD_DEV_LOGIN_INFO_S;


/**登录速度优化
 * @brief 登录信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVLoginInfo
{
    UINT32 LoginType;                               /* 登录类型 参考枚举#NETDEV_LOGIN_TYPE_E */
    LPVOID lpUserID;                                /* 云端账户登录ID User login ID */
    LPNETDEV_CLOUD_DEV_LOGIN_INFO_S pstCloudInfo;   /* pstCloudInfo云端设备登录信息 */
    INT32 dwCloudFunVersion;                        /* 内部保留,云端接口版本, 参见NETDEV_CLOUD_FUN_VERSION_E */
    INT32 dwShareSrcType;                           /* 内部保留,共享源类型, 参见NETDEV_CLOUD_SHARE_SRC_TYPE_E */
    CHAR szDevIP[NETDEV_LEN_64];                    /* 设备IP Device IP */
    CHAR szUserName[NETDEV_LEN_64];                 /* 用户名 User Name */
    CHAR szPassword[NETDEV_LEN_64];                 /* 密码 Password */
    INT32 dwDevPort;                                /* 设备服务器端口 Device Server Port */
    INT32   dwDevType;                              /* 设备类型,参见枚举#NETDEV_DEVICETYPE_E  Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT32   dwChannelNum;                           /* 通道个数  Number of Channels */
    CHAR szRegisterCode[NETDEV_LEN_64];             /* 设备注册码 */
    CHAR szDeviceSN[NETDEV_LEN_64];                 /* 设备SN Device SN */
    UINT32 udwAccessType;                           /* 接入协议类型 参见NETDEV_ACCESS_PROTOCOL_E */ 
    UINT32 udwRemainLockTimes;                      /* 用户安全登录次数 */
    UINT32 udwRemainUnlockTime;                     /* 用户安全登录时间 */
    BYTE byRes[356];                                /* 保留字段  Reserved */
}NETDEV_LOGIN_INFO_S,*LPNETDEV_LOGIN_INFO_S;

/**
* @brief  设备、通道共享响应 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVResponse
{
    CHAR szUserName[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];                   /* 共享对象 */
    CHAR szDescription[NETDEV_CLOUD_SHARE_DESCRIBE_LEN];                   /* 失败原因描述 */
    BYTE byRes[128];                                                       /* 保留字段 */
}NETDEV_RESPONSE_S,*LPNETDEV_RESPONSE_S;

/**
* @brief  共享限制信息
* @attention 无 None
*/
typedef struct tagNETDEVLimitInfo
{
    INT64   tValidTimeSecond;                                             /* 共享有效时间 单位：秒 */
    CHAR    szPermission[NETDEV_CLOUD_DEV_USER_AUTH_LEN];                   /* 共享权限 */
    CHAR    szChannelNum[NETDEV_DEV_OTHER_LEN_MAX];                         /* 共享通道号 */
    CHAR    szChannelName[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];              /* 共享通道名 */
    CHAR    szDescription[NETDEV_CLOUD_SHARE_DESCRIBE_LEN];                 /* 共享描述 */
    BYTE    byRes[128];                                                     /* 保留字段 */
}NETDEV_LIMIT_INFO_S,*LPNETDEV_LIMIT_INFO_S;

/**
* @brief  设备、通道共享信息 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVChannelShareInfo
{
    CHAR                    szDevName[NETDEV_DEV_NAME_LEN_MAX];             /* 设备名 */
    CHAR                    szUserName[NETDEV_CLOUD_USER_NAME_LEN];         /* 共享对象用户名 */
    NETDEV_LIMIT_INFO_S     stLimitInfo;                                    /* 共享限制信息 */
    CHAR                    szEZPassword[NETDEV_DEV_PASSWORD_LEN_MAX];      /* EZCloud密码 */
    CHAR                    szEZUserName[NETDEV_CLOUD_USER_NAME_LEN];       /* EZCloud用户名 */
    BYTE                    byRes[128];                                     /* 保留字段 */
}NETDEV_CHANNEL_SHARE_INFO_S,*LPNETDEV_CHANNEL_SHARE_INFO_S;

/**
* @brief   共享限制信息 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVShareLimitInfo
{
    CHAR    szUserName[NETDEV_CLOUD_USER_NAME_LEN];             /* 共享对象用户名 */
    CHAR    szUserPhone[NETDEV_DEV_OTHER_LEN_MAX];              /* 共享对象手机号 */
    CHAR    szUserMail[NETDEV_DEV_OTHER_LEN_MAX];               /* 共享对象邮箱地址 */
    INT64   tValidTimeSecond;                                   /* 共享有效时间 单位：秒 */
    INT64   tVaildTimeSlot;                                     /* 共享有效时间段 单位：秒 */
    CHAR    szPermission[NETDEV_CLOUD_DEV_USER_AUTH_LEN];       /* 共享权限 */
    INT64   dwChannelNum;                                       /* 共享通道号 */
    CHAR    szDescription[NETDEV_CLOUD_SHARE_DESCRIBE_LEN];     /* 共享描述 */
    CHAR    szChannelName[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];  /* 通道名 */
    BYTE    byRes[64];                                          /* 保留字段 */
}NETDEV_SHARE_LIMIT_INFO_S,*LPNETDEV_SHARE_LIMIT_INFO_S;

/**
* @brief 云端共享设备信息 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVDevInfo
{
    CHAR    szDevName[NETDEV_DEV_NAME_LEN_MAX];     /* 设备名 */
    CHAR    szDevAlias[NETDEV_DEV_OTHER_LEN_MAX];   /* 设备别名 */
    INT32   dwSize;                                 /* 共享限制记录个数 */
    BYTE    byRes[128];                             /* 保留字段 */
}NETDEV_DEV_INFO_S,*LPNETDEV_DEV_INFO_S;

/**
* @brief 取消设备/通道共享 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVDeleteShareChannelInfo
{
    CHAR szDevOwner[NETDEV_DEV_OTHER_LEN_MAX];          /* 设备所有者标识位 */
    CHAR szDevName[NETDEV_DEV_NAME_LEN_MAX];            /* 设备名 */
    CHAR szChannelNum[NETDEV_DEV_OTHER_LEN_MAX];        /* 通道号 */
    CHAR szUserName[NETDEV_DEV_OTHER_LEN_MAX];          /* 取消共享对象标识位 */
    CHAR szEZPassword[NETDEV_DEV_PASSWORD_LEN_MAX];     /* EZCloud密码 */
    CHAR szEZUserName[NETDEV_CLOUD_USER_NAME_LEN];      /* EZCloud用户名 */
    BYTE byRes[128];                                    /* 保留字段 */
}NETDEV_DELETE_SHARE_CHANNEL_INFO_S,*LPNETDEV_DELETE_SHARE_CHANNEL_INFO_S;



/**
 * @brief 云端设备信息 结构体定义 Cloud Device information Structure definition
 * @attention 废弃,不建议使用
 */
typedef struct tagNETDEVCloudDevInfo
{
    CHAR    szIPAddr[NETDEV_IPADDR_STR_MAX_LEN];            /* 设备IP */
    CHAR    szDevUserName[NETDEV_LEN_260];                  /* 设备用户名 */
    CHAR    szDevName[NETDEV_LEN_260];                      /* 设备名称 */
    CHAR    szDevModel[NETDEV_LEN_64];                      /* 设备型号 */
    CHAR    szDevSerialNum[NETDEV_LEN_64];                  /* 设备序列号 */
    INT32   dwOrgID;                                        /* 所属组织ID */
    INT32   dwDevPort;                                      /* 设备端口 */
    BOOL    bIsOnline;                                      /* 设备是否在线 */
    INT32   dwConnectMode;                                  /* 连接模式 Connect Mode*/
    INT32   dwDisTributeCloud;                               /* 分发模式  参见枚举 NETDEV_DISTRIBUTE_CLOUD_SRV_E*/
    BYTE    byRes[256];
}NETDEV_CLOUD_DEV_INFO_S,*LPNETDEV_CLOUD_DEV_INFO_S;

/**
 * @brief 云端设备基本信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevUserAuthority
{
    CHAR    szDevUserAuth[NETDEV_CLOUD_DEV_USER_AUTH_LEN];            /* 设备用户权限 */
    BYTE    byRes[512];
}NETDEV_CLOUD_DEV_USER_AUTH_S, *LPNETDEV_CLOUD_DEV_USER_AUTH_S;

/**
 * @brief 云端设备共享信息 结构体定义 Cloud Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevShareInfo
{
    BOOL    bIsShareDev;                                    /* 共享设备标志位 */
    INT64   tValidTimeSecond;                               /* 共享有效期 单位：秒 */
    CHAR    szDevUserName[NETDEV_CLOUD_DEV_USER_NAME_LEN];  /* 设备ID */
    CHAR    szCloudUserName[NETDEV_CLOUD_USER_NAME_LEN];    /* 共享设备所有者云账号名称 */
    INT32   dwUserAuthSize;                                 /* 设备用户权限个数 */
    LPNETDEV_CLOUD_DEV_USER_AUTH_S pstUserAuth;             /* 设备用户权限列表 权限列表内存个数与dwUserAuthoritySize对应，建议至少分配128个 */
}NETDEV_CLOUD_DEV_SHARE_INFO_S,*LPNETDEV_CLOUD_DEV_SHARE_INFO_S;


 /**
 * @brief 云端设备共享对象名称 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevShareTarget
{
    CHAR    szName[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];     /* 共享对象名称 */
    INT32   dwResultCode;                                   /* 共享错误码 0:共享成功, 其他:共享失败(错误码见云端设备相关错误码 NETDEV_E_CLOUD_INVALID_REG_CODE) */
    BYTE    byRes[128];                                     /* 保留字段 */
}NETDEV_CLOUD_DEV_SHARE_TARGET_S, *LPNETDEV_CLOUD_DEV_SHARE_TARGET_S;

 /**
 * @brief 云端设备共享对象名称列表 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevShareTargetList
{
    INT32                               dwSize;         /* 共享对象个数 */
    LPNETDEV_CLOUD_DEV_SHARE_TARGET_S   pstTarget;      /* 共享对象 用户根据size分配内存 */
    BYTE                                byRes[128];
}NETDEV_CLOUD_DEV_SHARE_TARGET_LIST_S, *LPNETDEV_CLOUD_DEV_SHARE_TARGET_LIST_S;

 /**
 * @brief 云端共享设备信息
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevShareCfg
{
    INT64 tValidTimeSecond;                                /* 共享有效时间 单位：秒 */
    CHAR  szDevUserAuth[NETDEV_CLOUD_DEV_USER_AUTH_LEN];   /* 设备用户权限 */
    CHAR  szDescribe[NETDEV_CLOUD_SHARE_DESCRIBE_LEN];     /* 共享描述 */
    CHAR  szDevUserName[NETDEV_CLOUD_DEV_USER_NAME_LEN];   /* 设备ID */
    NETDEV_CLOUD_DEV_SHARE_TARGET_LIST_S  stTargetList;    /* 共享对象列表 */
}NETDEV_CLOUD_DEV_SHARE_CFG_S,*LPNETDEV_CLOUD_DEV_SHARE_CFG_S;

 /**
 * @brief 云端设备共享记录信息 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevShareRecord
{
    INT64 tValidTimeSecond;                                                /* 共享有效时间 单位：秒 */
    CHAR  szTargetUserName[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];            /* 共享对象用户名 */
    CHAR  szTargetPhoneNum[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];            /* 共享对象手机号 */
    CHAR  szTargetMailNum[NETDEV_CLOUD_SHARE_TARGET_NAME_LEN];             /* 共享对象邮箱号 */
    CHAR  szDevName[NETDEV_CLOUD_DEV_NAME_LEN];                            /* 设备名称 */
    CHAR  szDevUserName[NETDEV_CLOUD_DEV_USER_NAME_LEN];                   /* 设备用户名 */
    CHAR  szDevUserAuth[NETDEV_CLOUD_DEV_USER_AUTH_LEN];                   /* 设备用户权限 */
    CHAR  szDescribe[NETDEV_CLOUD_SHARE_DESCRIBE_LEN];                     /* 共享描述 */
}NETDEV_CLOUD_DEV_SHARE_RECORD_S, *LPNETDEV_CLOUD_DEV_SHARE_RECORD_S;

 /**
 * @brief 批量云端设备名称 
 * @attention 无 None
 */
typedef struct tagNETDEVBatchCloudDevInfo
{
    CHAR  szDevUserName[NETDEV_CLOUD_DEV_NAME_LEN];              /* 设备名称 */
    INT32 dwResultCode;                                       /* 共享错误码 0:共享成功, 其他:取消设备绑定失败(错误码见云端设备相关错误码 NETDEV_E_CLOUD_INVALID_REG_CODE) */
}NETDEV_BATCH_CLOUD_DEV_INFO_S, *LPNETDEV_BATCH_CLOUD_DEV_INFO_S;

/**
 * @brief 批量云端设备列表
 * @attention 无 None
 */
typedef struct tagNETDEVBatchCloudDevList
{
    UINT32                              udwSize;            /* 云端设备个数，最大64个 */
    LPNETDEV_BATCH_CLOUD_DEV_INFO_S     pstBatchDevInfo;    /* 云端设备名称指针，用户动态分配内存,内存大小与udwSize相对应 */
}NETDEV_BATCH_CLOUD_DEV_LIST_S, *LPNETDEV_BATCH_CLOUD_DEV_LIST_S;

 /**
 * @brief 批量关闭云端共享设备信息
 * @attention 无 None
 */
typedef struct tagNETDEVBatchDevShareInfo
{
    CHAR szDevUserName[NETDEV_CLOUD_DEV_NAME_LEN];                /* 云端设备ID */
    NETDEV_CLOUD_DEV_SHARE_TARGET_LIST_S  stTargetList;           /* 共享对象列表  */
 }NETDEV_BATCH_DEV_SHARE_INFO_S,*LPNETDEV_BATCH_DEV_SHARE_INFO_S;

 /**
 * @brief 批量关闭云端共享设备信息列表
 * @attention 无 None
 */
typedef struct tagNETDEVBatchDevShareList
{
    BOOL    bIsStopedByOwner;                                   /* 是否由设备所有者关闭共享 （当bIsStopedByOwner等于FALSE时传入一个共享对象pstTarget，共享对象名称为空） */
    UINT32  udwSize;                                            /* 共享设备个数 */
    LPNETDEV_BATCH_DEV_SHARE_INFO_S  pstBatchDevShareInfo;      /* 批量关闭云端共享设备信息 */
}NETDEV_BATCH_DEV_SHARE_LIST_S,*LPNETDEV_BATCH_DEV_SHARE_LIST_S;



/**
 * @brief 云端设备组织信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudOrgInfoEx
{
    INT32   dwOrgID;                        /* 所属组织ID */
    INT32   dwOrgParentID;                  /* 所在父设备ID */
    CHAR    szOrgName[NETDEV_LEN_260];      /* 组织名称 */
    BYTE    byRes[128];                     /* 保留字段 */
}NETDEV_CLOUD_ORG_INFO_S,*LPNETDEV_CLOUD_ORG_INFO_S;


/**
 * @brief 云端设备组织信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevBindInfo
{
    CHAR szDevRegisterCode[NETDEV_LEN_64];      /* 设备注册码 */
    CHAR szDevAlias[NETDEV_LEN_64];             /* 设备别名 */
    CHAR szDevCloudUsername[NETDEV_LEN_64];     /* 设备用户名 */
    CHAR szDevSerialNum[NETDEV_LEN_64];         /* 设备序列号 */
    CHAR szDevModel[NETDEV_LEN_64];             /* 设备型号 Device model */
    BYTE byRes[256];                            /* 保留字段 */
}NETDEV_CLOUD_DEV_BASE_INFO_S,*LPNETDEV_CLOUD_DEV_BASE_INFO_S;


/**
 * @brief 设备分发策略信息结构体
 * @attention 无None
 */
typedef struct tagNETDEVCloudDevDistributeInfo
{
    INT32   dwDistributeCloud;                          /* 支持的分发服务商，参考枚举NETDEV_DISTRIBUTE_CLOUD_SRV_E */
    INT32   dwBitrateLimit;                             /* 码率限制(单位：Kbps) */
    INT32   dwDistributeMode;                           /* 分发模式，参考枚举NETDEV_DISTRIBUTE_MODE_E */
    CHAR    szDevDistributeCap[NETDEV_LEN_64];          /* 设备分发能力 */
    BYTE    byRes[128];                                 /* 保留字段 Reserved */
}NETDEV_CLOUD_DEV_DISTRIBUTE_INFO_S,*LPNETDEV_CLOUD_DEV_DISTRIBUTE_INFO_S;

/**
 * @brief 通道视频流信息 结构体定义 Channel video stream information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVideoStreamInfo
{
    NETDEV_LIVE_STREAM_INDEX_E  enStreamType;       /* 码流索引  Stream index */
    INT32                       bEnableFlag;        /* 是否启用  Enable or not */
    INT32                       dwHeight;           /* 视频编码分辨率-Height  Video encoding resolution - Height */
    INT32                       dwWidth;            /* 视频编码分辨率-Width  Video encoding resolution - Width */
    INT32                       dwFrameRate;        /* 视频编码配置帧率  Video encoding configuration frame rate */
    INT32                       dwBitRate;          /* 码率  Bit rate */
    NETDEV_VIDEO_CODE_TYPE_E    enCodeType;         /* 视频编码格式  Video encoding format */
    NETDEV_VIDEO_QUALITY_E      enQuality;          /* 图像质量  Image quality */
    INT32                       dwGop;              /* I帧间隔  I-frame interval */
    BYTE                        byRes[32];          /* 保留字段  Reserved */
}NETDEV_VIDEO_STREAM_INFO_S, *LPNETDEV_VIDEO_STREAM_INFO_S;

/**
 * @brief 云端设备通道信息结构体定义
 * @attention 无None
 */
 typedef struct tagNETDEVCloudDevChlInfo
{
    INT32                          dwChannelID;                         /* 通道ID */
    CHAR                           szChannelSN[NETDEV_LEN_260];         /* 通道（IPC）序列号 */
    CHAR                           szChannelName[NETDEV_LEN_260];       /* 通道名 */
    NETDEV_VIDEO_STREAM_INFO_S     astStreamInfo[NETDEV_LEN_8];         /* 流信息列表 */
    BOOL                           bChannelStatus;                      /* 通道状态 */
    BYTE                           byRes[128];                          /* 保留字段 */
}NETDEV_CLOUD_DEV_CHL_INFO_S,*LPNETDEV_CLOUD_DEV_CHL_INFO_S;

/**
 * @brief 分页查询条件信息结构体
 * @attention 无None
 */
typedef struct tagNETDEVPageQueryCond
{
    INT32   dwQueryCond;        /* 查询条件0：设备状态；1：设备所在组织。 */
    INT32   dwSubQueryCond;     /* 当前查询条件的右值,用于补充说明查询条件中设备状态:0表示离线，1表示在线 */
    INT32   dwLogicalType;      /* 查询条件逻辑类型:参见枚举类型#NETDEV_QUERYCOND_LOGICTYPE_E */
    BYTE    byRes[128];         /* 保留字段 */
}NETDEV_PAGE_FIND_LOGIC_S,*LPNETDEV_PAGE_FIND_LOGIC_S;


/** 
 * @brief 分页查询信息结构体
 * @attention 无None
 */
typedef struct tagNETDEVPageQueryInfo
{
    INT32   dwLimitNum;                                          /* 单页查询设备数量，建议参考#NETDEV_PAGE_QUERY_CAP_INFO_S结构体中dwSuggestSinglePageQuantily值大小来设置*/
    INT32   dwStartID;                                           /* 单页查询设备的起始id,连续查询中可以用上次分页查询获取到的最后一个设备中的id字段+1，作为此次查询的开始id。*/
    INT32   dwCondNum;                                           /* 查询条件数量 */
    NETDEV_PAGE_FIND_LOGIC_S  astFindCond[NETDEV_LEN_16];        /* 查询条件信息列表,查询条件数量最多为16个,当查询数量为0时,此节点可选 */
    BYTE    byRes[128];                                          /* 保留字段*/
}NETDEV_PAGE_FIND_COND_S,*LPNETDEV_PAGE_FIND_COND_S;

/**
 * @brief 分页查询能力集信息结构体
 * @attention 无None
 */
typedef struct tagNETDEVCloudDevPopulationInfo
{
    INT32   dwDevTotalNum;          /* 当前云账号下所有的设备数量 */
    INT32   dwDevOfflineNum;        /* 当前云账号下离线设备总数 */
    BYTE    byRes[128];             /* 保留字段 */
}NETDEV_CLOUD_DEV_POPUL_INFO_S,*LPNETDEV_CLOUD_DEV_POPUL_INFO_S;

/**
 * @struct tagNETDEVCloudMobileInfo
 * @brief 终端信息
 * @attention 无 None
 */
typedef struct tagNETDEVCloudMobileInfo
{
    CHAR    szMobileModule[NETDEV_LEN_32];                      /* 终端信号 Module of Terminal */
    CHAR    szSystemType[NETDEV_LEN_16];                        /* 操作系统类型 System Type of Terminal */
    CHAR    szSystemVersion[NETDEV_LEN_16];                     /* 操作系统版本 System Version of Terminal */
    BOOL    bDonotDisturb;                                      /* 免打扰标志 Flag of Do Not Disturb */
    BOOL    bPushBuiltFlag;                                     /* 推送连接建立标识 Flag of push connected,Ture means Long Link*/
    CHAR    szAppName[NETDEV_LEN_32];                           /* App名称 App Name */
    CHAR    szAppLanguage[NETDEV_LEN_32];                       /* App语言环境 App Language. ex:en-us|zh-cn */
    CHAR    szAppVersion[NETDEV_LEN_16];                        /* App版本信息 App Version */
    BOOL    bIosEnvir;                                          /* IOS的环境标志 environment of IOS, True:Production False:Development*/
    BYTE    byRes[256];                                         /* 保留字段 Reserved */
}NETDEV_CLOUD_MOBILE_INFO_S,*LPNETDEV_CLOUD_MOBILE_INFO_S;

/**
 * @struct tagNETDEVCloudLimitInfo
 * @brief 终端限制信息
 * @attention 无 None
 */
typedef struct tagNETDEVCloudLimitInfo
{
    UINT32  udwMaxDeviceNum;                                    /* 设备最大接入数 Max Num of Online Device */
    UINT32  udwMaxAppTimeS;                                     /* App最大使用时间(秒) Max Time of App Cost */
    UINT32  udwMaxRTSNum;                                       /* 最大实况数量 Max Num of Real Time Stream */
    BYTE    byRes[256];                                         /* 保留字段 Reserved */
}NETDEV_CLOUD_LIMIT_INFO_S,*LPNETDEV_CLOUD_LIMIT_INFO_S;

/**
 * @struct tagNETDEVCloudNoAccountInfo
 * @brief 无账户信息
 * @attention szDeviceName is Not Required Using for Cancel Binding
 */
typedef struct tagNETDEVCloudNoAccountInfo
{
    CHAR    szDeviceSN[NETDEV_LEN_260];                         /* 设备序列号 SN of Device */
    CHAR    szDeviceName[NETDEV_LEN_260];                       /* 设备别名 Device Name Named By User */
    BYTE    byRes[256];                                         /* 保留字段 Reserved */
}NETDEV_CLOUD_NOACCOUNT_INFO_S, *LPNETDEV_CLOUD_NOACCOUNT_INFO_S;

/**
 * @struct tagNETDEVCloudFindVideoTimeCond
 * @brief 云存储时间信息查询条件
 * @attention 无 None
 */
typedef struct tagNETDEVCloudFindVideoTimeCond
{
    INT32    dwChannelID;                       /* 通道ID  ChannelID */
    DOUBLE   tBeginTime;                        /* 起始时间 Begin time */
    DOUBLE   tEndTime;                          /* 结束时间 End time */
    BYTE     byRes[256];                        /* 保留字段 */
}NETDEV_CLOUD_FIND_VIDEO_TIME_COND_S,*LPNETDEV_CLOUD_FIND_VIDEO_TIME_COND_S;

/**
 * @struct tagNETDEVCloudVideoTimeBlock
 * @brief 云端视频时间信息查询结果
 * @attention 无 None
 */
typedef struct tagNETDEVCloudVideoTimeBlock
{
    DOUBLE   tBeginTime;                         /* 起始时间 Begin time */
    DOUBLE   tEndTime;                           /* 结束时间 End time */
    BYTE    byRes[128];                          /* 保留字段 */
}NETDEV_CLOUD_VIDEO_TIME_BLOCK_S,*LPNETDEV_CLOUD_VIDEO_TIME_BLOCK_S;

/**
 * @struct tagNETDEVCloudVideoInfo
 * @brief 查找到的视频云存储信息
 * @attention 无 None
 */
typedef struct tagNETDEVCloudVideoInfo
{
    DOUBLE   tBeginTime;                         /* 起始时间 Begin time */
    DOUBLE   tEndTime;                           /* 结束时间 End time */
    DOUBLE   tExpireTime;                        /* 过期时间 Expiration time */
    UINT32   udwM3u8AvailSize;                   /* M3u8空间可用大小 */
    CHAR*    pszM3u8;                            /* M3u8信息,此内容较大，建议从堆上申请 */
    BYTE     byRes[256];                         /* 保留字段 */
}NETDEV_CLOUD_VIDEO_INFO_S,*LPNETDEV_CLOUD_VIDEO_INFO_S;

/**
*@enum tagNETDEVCloudStorageType
*@brief 云存储支持类型
*@attention 无
*/
typedef enum tagNETDEVCloudStorageType
{
    NETDEV_CLOUD_STORAGE_TYPE_PIC                 = 1,            /* 开启云存储图片告警 */
    NETDEV_CLOUD_STORAGE_TYPE_VIDEO               = 2,            /* 开启视频回放云存储 */
    NETDEV_CLOUD_STORAGE_TYPE_PIC_AND_VIDEO       = 3,            /* 开启云存储图片告警及视频回放云存储*/
    NETDEV_CLOUD_STORAGE_TYPE_INVALID
}NETDEV_CLOUD_STORAGE_TYPE_E;


/**
 * @brief 云端设备基本信息 结构体定义 Cloud Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCloudDevBasicInfo
{
    CHAR    szIPAddr[NETDEV_IPV4_LEN_MAX];              /* 设备IP Device IP */
    CHAR    szDevUserName[NETDEV_LEN_260];              /* 设备用户名 Device username */
    CHAR    szDevName[NETDEV_LEN_260];                  /* 设备名称 Device name */
    CHAR    szDevModel[NETDEV_LEN_64];                  /* 设备型号 Device model */
    CHAR    szDevSerialNum[NETDEV_LEN_64];              /* 设备序列号 Device serial number */
    INT32   dwOrgID;                                    /* 所属组织ID Home organization ID */
    INT32   dwDevPort;                                  /* 设备端口 Device port */
    INT32   dwDevID;                                    /* 设备ID此设备在设备列表中的序号 */
    CHAR    szDevSubName[NETDEV_LEN_260];               /* 设备别名：包括共享设备别名 */
    INT32   dwDevType;                                  /* 设备类型：参见枚举#NETDEV_CLOUD_DEVICE_TYPE  Device type, see enumeration #NETDEV_CLOUD_DEVICE_TYPE */
    BOOL    bKeepLiveStatus;                            /* 设备保活状态：在线返回true，不在线返回false */
    BOOL    bIsShareDev;                                /* 共享设备标志位，如果是共享设备，则为true，自己名下的设备为false */
    INT32   dwValidityShareTime;                        /* 共享有效期，单位秒。例如返回“3600.0000000”，客户端当前时间2014-2-27 9:22，就允许-2-27 10:22前发起连接。当共享设备标志位为true时有效。*/
    CHAR    szShareDevUserName[NETDEV_LEN_260];         /* 共享设备所有者用户名，当bIsShareDev为true时有效 */
    INT32   dwConnectMode;                              /* 连接模式 Connect Mode*/
    INT32   dwDisTributeCloud;                          /* 分发模式  参见枚举 NETDEV_DISTRIBUTE_CLOUD_SRV_E*/
    INT32   dwCloudStorageType;                         /* 设备云存储类型 参考枚举 NETDEV_CLOUD_STORAGE_TYPE_E*/
    BYTE    byRes[120];                                 /* 保留字段 */
}NETDEV_CLOUD_DEV_BASIC_INFO_S,*LPNETDEV_CLOUD_DEV_BASIC_INFO_S;


/**
 * @struct tagstNETDEVSELogInfo
 * @brief 安全登录信息
 * @attention
 */
typedef struct tagstNETDEVSELogInfo
{
    INT32  dwSELogCount;    /* 安全登录次数 */
    INT32  dwSELogTime;     /* 安全登录时间 */
    BYTE   byRes[64];       /* 保留字段 */
}NETDEV_SELOG_INFO_S, *LPNETDEV_SELOG_INFO_S;

/**
 * @struct tagstNETDEVLoginInfo
 * @brief 设备登录信息
 * @attention
 */
typedef struct tagstNETDEVDeviceLoginInfo
{    
    CHAR    szIPAddr[NETDEV_LEN_260];       /* IP地址/域名 */
    INT32   dwPort;                         /* 端口号 */
    CHAR    szUserName[NETDEV_LEN_132];     /* 用户名 */
    CHAR    szPassword[NETDEV_LEN_128];     /* 密码 */
    INT32   dwLoginProto;                   /* 登录协议, 参见NETDEV_LOGIN_PROTO_E */
    INT32   dwDeviceType;                   /* 设备类型, 参见NETDEV_DEVICE_TYPE_E */
    BYTE    byRes[256];                     /* 保留字段 */
}NETDEV_DEVICE_LOGIN_INFO_S, *LPNETDEV_DEVICE_LOGIN_INFO_S;


/**
 * @struct tagNETDEVAlarmInfo
 * @brief 告警信息 结构体定义 Alarm information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAlarmInfoV30
{
    INT32 dwAlarmType;                                  /* 告警类型，参见枚举#NETDEV_ALARM_TYPE_E  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT32 dwAlarmSubType;                               /* 告警子类型，参见NETDEV_ALARM_SUBTYPE_E */
    INT32 dwAlarmLevel;                                 /* 告警等级，1到5级，1级最严重 */
    INT64 tAlarmTimeStamp;                              /* 告警发生时间  Alarm occurrence time */
	INT32 dwChannelID;                                  /* 通道ID,非一体机设备使用  Channel ID */
	INT32 dwAlarmID;                                    /* 告警ID，一体机设备使用 */
    INT32 dwAlarmSrcID;                                 /* 告警源ID 参见枚举#NETDEV_ALARM_SRC_TYPE_E
                                                        note:
                                                        1. dwAlarmSrcType为NETDEV_ALARM_SRC_LOCAL_HARD_DISK到NETDEV_ALARM_SRC_SD_STORAGE_DISK之间，dwAlarmID代表存储盘索引；
                                                        2. dwAlarmSrcType为8，dwAlarmID代表视频通道号；
                                                        3. dwAlarmSrcType为9，dwAlarmID代表报警输入通道号，报警源见dwInputSwitchID字段。
                                                        4. dwAlarmSrcType为10,dwAlarmID默认为0,代表系统本身
                                                        */
    CHAR  szAlarmSrc[NETDEV_ALARM_SOURCE_MAX_LEN];      /* 告警源信息（名称） */
    BOOL IsAlarmSnapExisted;                            /* 告警是否有抓图 0没有抓图 1有抓图  vms使用*/
    UINT16  wIndex;                                     /* 索引号  Index number, index number */
    INT32   dwTotalBandWidth;                           /* 当前带宽总量,单位为MBps  Current total bandwidth (in MBps) */
    INT32   dwUnusedBandwidth;                          /* 未使用的带宽,单位为MBps  Bandwidth left (in MBps)*/
    INT32   dwTotalStreamNum;                           /* 总路数 Total cameras*/
    INT32   dwFreeStreamNum;                            /* 未使用路数 Cameras left */
    INT32   dwMediaMode;                                /* 流类型,参见枚举#NETDEV_MEDIA_MODE_E Stream type. For enumerations, see#NETDEV_MEDIA_MODE_E*/
    
    BYTE  byRes[512];                                   /* 保留字段 */
}NETDEV_ALARM_INFO_V30_S, *LPNETDEV_ALARM_INFO_V30_S;


/**
 * @struct tagNETDEVEventRes
 * @brief 事件资源信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVEventRes
{
    INT32   dwResType;                          /* 资源类型，参见枚举#NETDEV_EVENT_RES_TYPE_E */
    INT32   dwResID;                            /* 资源ID */
    INT32   dwFirstSubResID;                    /* 第一子资源ID */
    INT32   dwSecondSubResID;                   /* 第二子资源ID 不同资源类型对应意义不同。如：电视墙分屏资源的资源ID是电视墙ID，第一子资源ID是窗口ID，第二子资源ID就是分屏ID*/

    BYTE    byRes[16];                          /* 保留字段 */
}NETDEV_EVENT_RES_S, *LPNETDEV_EVENT_RES_S;


/**
 * @struct tagNETDEVEventInfo
 * @brief 事件信息 结构体定义 Alarm information Structure definition
 * @attention  事件个数超过NETDEV_MAX_EVENT_RES_SIZE个时，超过部分使用存放在指针pstEventRes中，该指针的内存进行动态申请
 */
typedef struct tagNETDEVEventInfo
{
    INT32                   dwSize;                                     /* 资源数量 */
    NETDEV_EVENT_RES_S      astEventRes[NETDEV_MAX_EVENT_RES_SIZE];     /* 事件资源信息 */
    INT32                   dwEventActionType;                          /* 事件类型，参见枚举#NETDEV_EVENT_ACTION_TYPE_E */
    LPNETDEV_EVENT_RES_S    pstEventRes;                                /* 超过NETDEV_MAX_EVENT_RES_SIZE的事件资源信息 需要动态申请*/
    BYTE                    byRes[28];                                  /* 保留字段 */
}NETDEV_EVENT_INFO_S, *LPNETDEV_EVENT_INFO_S;

/**
 * @struct tagNETDEVReportInfo
 * @brief 告警/事件上报信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVReportInfo
{
    INT32                       dwReportType;       /* 上报类型，参见枚举#NETDEV_REPORT_TYPE_E */
    NETDEV_ALARM_INFO_V30_S     stAlarmInfo;        /* 告警信息，当dwReportType为NETDEV_REPORT_TYPE_ALARM时有效 */
    NETDEV_EVENT_INFO_S         stEventInfo;        /* 事件信息，当dwReportType为NETDEV_REPORT_TYPE_EVENT时有效 */
}NETDEV_REPORT_INFO_S, *LPNETDEV_REPORT_INFO_S;

/**
 * @struct tagstNETDEVUserSimpleInfo
 * @brief 用户账号信息（用户名＋密码）
 * @attention
 */
typedef struct tagstNETDEVUserSimpleInfo
{    
    CHAR szUserName[NETDEV_USERNAME_LEN];       /* 用户名 */
    CHAR szPassword[NETDEV_PASSWORD_LEN];       /* 密码 */
    BYTE byRes[64];                             /* 保留字段 */
}NETDEV_USER_SIMPLE_INFO_S, *LPNETDEV_USER_SIMPLE_INFO_S;

/**
 * @struct tagstNETDEVIPAddrInfo
 * @brief IP地址信息
 * @attention
 */
typedef struct tagstNETDEVIPAddrInfo
{
    INT32   dwType;                            /* 地址类型，参见枚举NETDEV_IP_ADDRESS_TYPE_E */
    CHAR    szIPAddr[NETDEV_MAX_URL_LEN];      /* IP地址/域名 */
    INT32   dwPort;                            /* 端口号 */
    BYTE    byRes[60];                         /* 保留字段 */
}NETDEV_IPADDR_INFO_S, *LPNETDEV_IPADDR_INFO_S;

/**
* @brief Onvif信息
* @attention
*/
typedef struct tagstNETDEVOnvifInfo
{   
    UINT32   udwTransportMode;                          /* 传输模式，参见枚举NETDEV_TRANS_PROTOCOL_E */

    BYTE  byRes[128];                                   /* 保留字段  Reserved field*/
}NETDEV_ONVIF_INFO_S, *LPNETDEV_ONVIF_INFO_S;

/**
 * @struct tagNETDEVGBInfo
 * @brief 国标信息
 * @attention 无 None
 */
typedef struct tagNETDEVGBInfo
{
    CHAR     szUniCode[NETDEV_LEN_32];      /* 国标资源编码，范围[1, 32]*/
    UINT32   udwTransport;                  /* 传输模式 0: TCP 1: UDP*/
    BYTE   byRes[128];                      /* 保留字节 */
}NETDEV_GBINFO_S, *LPNETDEV_GBINFO_S;

/**
 * @struct tagstNETDEVDeviceBasicInfo
 * @brief 设备基本信息
 * @attention
 */
typedef struct tagstNETDEVDeviceBasicInfo
{
    NETDEV_IPADDR_INFO_S stDevAddr;                         /* 设备IP地址信息 */
    NETDEV_USER_SIMPLE_INFO_S stDevUserInfo;                /* 设备用户名、密码 */
    CHAR szDevName[NETDEV_NAME_MAX_LEN];                    /* 设备名称 */
    CHAR szDevDesc[NETDEV_DESCRIBE_MAX_LEN];                /* 设备描述 */
    CHAR szDevModel[NETDEV_CODE_STR_MAX_LEN];               /* 设备型号 */
    INT32 dwDevID;                                          /* 设备ID */
    INT32 dwDevStatus;                                      /* 设备状态, 参考# NETDEV_DEVICE_STATUS_E */
    INT32 dwDevType;                                        /* 设备类型，参考# NETDEV_DEVICE_MAIN_TYPE_E */
    INT32 dwDevSubType;                                     /* 设备子类型，参考# NETDEV_DEVICE_SUB_TYPE_E */
    INT32 dwOrgID;                                          /* 组织编号 */
    INT32 dwAccessProtocol;                                 /* 接入协议 */
    INT32 dwAccessMode;                                     /* 接入方式 参考# NETDEV_DEVICE_ACCESS_MODE_E*/
    INT32 dwServerID;                                       /* 所属服务器ID */
    INT32 dwAudioResID;                                     /* 音频通道ID */
    CHAR  szVIIDCode[NETDEV_VIID_CODE_LEN];                 /* 视图库编码,仅卡口设备时有效 */
    INT32 dwVIIDStatus;                                     /* 视图库状态，用来标识当前设备是否已通过视图库协议连接，0：离线 1：在线 */
    CHAR szSerialNum[NETDEV_LEN_64];                        /* 设备序列号*/
    CHAR szSoftVersion[NETDEV_LEN_128];                     /* 软件版本号*/
    CHAR szMacAddr[NETDEV_LEN_32];                          /* MAC地址*/
    INT32 dwStoreStatus;                                    /* 设备存储状态。0: 空闲 1: 未格式化 2: 格式化中3: 运行中*/
    NETDEV_ONVIF_INFO_S stOnvifInfo;                        /* onvif信息 */
    NETDEV_GBINFO_S stGBInfo;                               /* 国标信息 当AccessProtocol值为3时该节点必选，其他可选*/

    BYTE byRes[128];                                         /* 保留字段 */
}NETDEV_DEV_BASIC_INFO_S, *LPNETDEV_DEV_BASIC_INFO_S;


/**
 * @struct tagstNETDEVDeviceFirmwareInfo
 * @brief 设备固件信息
 * @attention
 */
typedef struct tagstNETDEVDeviceFirmwareInfo
{    
    CHAR szDevModel[NETDEV_CODE_STR_MAX_LEN];       /* 设备型号 */
    CHAR szFireVersion[NETDEV_CODE_STR_MAX_LEN];    /* 软件版本号 */
    CHAR szSerialNum[NETDEV_CODE_STR_MAX_LEN];      /* 设备序列号 */
    BYTE byRes[128];                                /* 保留字段 */
}NETDEV_DEV_FIREWARE_INFO_S, *LPNETDEV_DEV_FIREWARE_INFO_S;

/**
 * @struct tagstNETDEVDeviceDetailInfo
 * @brief 设备详细信息
 * @attention
 */
typedef struct tagstNETDEVDeviceDetailInfo
{    
    NETDEV_DEV_BASIC_INFO_S stDevBasicInfo;             /* 设备基本信息 */
    NETDEV_DEV_FIREWARE_INFO_S stDevFirewareInfo;       /* 设备固件信息 */
}NETDEV_DEV_INFO_V30_S, *LPNETDEV_DEV_INFO_V30_S;


/**
 * @struct tagstNETDEVEncodeChnProperty
 * @brief 编码通道属性
 * @attention
 */
typedef struct tagstNETDEVEncodeChnProperty
{
    INT32   dwMaxStream;        /* 支持的最大流个数 */
    BOOL    bSupportPTZ;        /* 是否支持云台 */
    INT32   dwAudioResID;       /* 音频资源ID */
    BYTE    byRes[64];          /* 保留字段 */
}NETDEV_ENCODE_CHN_PROPERTY_S, *LPNETDEV_ENCODE_CHN_PROPERTY_S;

/**
 * @struct tagstNETDEVDecodeChnProperty
 * @brief 解码通道属性
 * @attention
 */
typedef struct tagstNETDEVDecodeChnProperty
{
    INT32 dwVideoFmtCapSize;                                    /* 编码制式能力集选项数量 */
    INT32 adwVideoFormatCap[NETDEV_VIDEO_FORMAT_CAP_NUM];       /* 编码制式能力集 */
    INT32 dwLayoutCapSize;                                      /* 分屏能力集选项数量 */
    INT32 adwLayoutCap[NETDEV_LAYOUT_CAP_NUM];                  /* 分屏能力集 */
    BYTE  byRes[64];                                            /* 保留字段 */
}NETDEV_DECODE_CHN_PROPERTY_S, *LPNETDEV_DECODE_CHN_PROPERTY_S;

/**
 * @struct tagstNETDEVAlarmOutChnProperty
 * @brief 告警输出通道属性
 * @attention
 */
typedef struct tagstNETDEVAlarmOutChnProperty
{
    INT32 dwRunMode;        /* 运行模式（常开/常闭）参见#NETDEV_ALARM_STATUS_E */
    INT32 dwDuration;       /* 持续时间：(ms) */
    BYTE byRes[64];         /* 保留字段 */
}NETDEV_ALARMOUT_CHN_PROPERTY_S, *LPNETDEV_ALARMOUT_CHN_PROPERTY_S;

/**
 * @struct tagstNETDEVAlarmInChnProperty
 * @brief 告警输入通道属性
 * @attention
 */
typedef struct tagstNETDEVAlarmInChnProperty
{
    INT32 dwRunMode;        /* 运行模式（常开/常闭）参见#NETDEV_ALARM_STATUS_E */
    BOOL  bEnable;          /* 使能开关（使能开/使能关） */
    BYTE byRes[64];         /* 保留字段 */
}NETDEV_ALARMIN_CHN_PROPERTY_S, *LPNETDEV_ALARMIN_CHN_PROPERTY_S;


/**
 * @struct tagstNETDEVDAProperty
 * @brief 代理设备通道属性
 * @attention
 */
typedef struct tagstNETDEVDAProperty
{
    CHAR   szPointCode[NETDEV_DA_POINT_CODE_LEN];         /* 点位编码或门编码 */
    CHAR   szAreaCode[NETDEV_DA_AREA_CODE_LEN];           /* 区域编码 */
    UINT32 udwPointStatus;                                /* 告警点位状态请参考#NETDEV_ALARM_POINT_STATUS_TYPE_E 或门状态 请参考#NETDEV_DOOR_STATUS_TYPE_E */
    BYTE   byRes[64];                                     /* 保留字段 */
}NETDEV_DA_CHN_PROPERTY_S, *LPNETDEV_DA_CHN_PROPERTY_S;



/**
* @struct tagNETDEVTrafficStatisticsInfo
* @brief 客流量统计 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVTrafficStatisticsInfo
{
    BOOL    bIsSuccess;                                    /* 查询是否成功 */
    INT32   dwChannelID;                                   /* 通道号 */
    UINT32  udwSize;                                       /* 时间段个数 */
    UINT32  audwEnterCount[NETDEV_PEOPLE_CNT_MAX_NUM];     /* 进入人数统计 */
    UINT32  audwExitCount[NETDEV_PEOPLE_CNT_MAX_NUM];      /* 离开人数统计 */
    BYTE    byRes[6];                                      /* 保留字段   */
}NETDEV_TRAFFIC_STATISTICS_INFO_S, *LPNETDEV_TRAFFIC_STATISTICS_INFO_S;

/**
 * @struct tagstNETDEVOrgChnInfo
 * @brief 组织下通道信息
 * @attention
 */
typedef struct tagstNETDEVOrgChnInfo
{
    INT32 dwOrgID;                              /* 组织ID */
    INT32 dwChannelID;                          /* 通道ID */
    CHAR szChnName[NETDEV_NAME_MAX_LEN];        /* 通道名称 */
    INT32 dwChnIndex;                           /* 通道索引 */
    INT32 dwChnType;                            /* 通道类型 */
    INT32 dwChnStatus;                          /* 通道状态 */
    INT32 dwDevID;                              /* 设备ID */
    CHAR szDevName[NETDEV_NAME_MAX_LEN];        /* 设备名称 */
    BYTE  byRes[128];                           /* 保留字段   */
}NETDEV_ORG_CHN_INFO_S, *LPNETDEV_ORG_CHN_INFO_S;


/**
 * @struct tagstNETDEVOrgDetailInfo
 * @brief 组织详细信息
 * @attention
 */
typedef struct tagstNETDEVOrgDetailInfo
{    
    INT32 dwOrgID;                              /* 组织ID */
    INT32 dwParentID;                           /* 组织父节点ID */
    INT32 dwType;                               /* 类型 参见 NETDEV_ORG_TYPE_E */
    CHAR szNodeName[NETDEV_NAME_MAX_LEN];       /* 节点名称 */
    CHAR szDesc[NETDEV_DESCRIBE_MAX_LEN];       /* 备注 */
    BYTE  byRes[128];                           /* 保留字段   */
}NETDEV_ORG_INFO_S, *LPNETDEV_ORG_INFO_S;


/**
* @struct tagNETDEVMemSize
* @brief 虚拟内存信息。
* @attention 无
*/
typedef struct tagNETDEVMemSize
{
    UINT32 udwDecodePayload;        /* 解码格式 NETDEV_MEM_PAYLOAD_E */
    UINT32 udwResolution;           /* 解码分辨率 NETDEV_MEM_RESOLUTION_E  */
    UINT32 udwMemSize;              /* 需要的资源大小 */
}NETDEV_MEM_SIZE_S, *LPNETDEV_MEM_SIZE_S;

/**
* @struct tagMallocInfo
* @brief 虚拟内存信息。
* @attention 无
*/
typedef struct tagNETDEVMemTable
{
    UINT32 udwSize;                                                     /* 资源表元素个数*/
    NETDEV_MEM_SIZE_S szVirtualMem[NETDEV_VIRTUAL_MEM_TABLE_MAX];       /* 资源表内存信息 */
}NETDEV_MEM_TABLE_S, *LPNETDEV_MEM_TABLE_S;

/**
 * @struct tagNETDEVTMSStrutPicInfo
 * @brief 结构化报文图片解析信息
 * @attention
 */
typedef struct tagNETDEVTMSStrutPicInfo
{
    UINT32  udwPicSize;         /* 图片大小 */
    CHAR    *pcPicData;         /* 图片数据 */
    BYTE bRes[256];             /* 保留字段 Reserved */
}NETDEV_TMS_STRUT_PIC_INFO_S,*LPNETDEV_TMS_STRUT_PIC_INFO_S;

/**
 * @struct tagstNETDEVStructCommonInfo
 * @brief 结构化公共信息部分
 * @attention
 */
typedef struct tagstNETDEVStructCommonInfo
{
    CHAR szPlaceCode[NETDEV_LEN_32];            /* 地点编号 */
    CHAR szPlaceName[NETDEV_LEN_128];           /* 地点名称 */
    CHAR szLaneDirection[NETDEV_LEN_32];        /* 车道行驶方向 */
    CHAR szDirection[NETDEV_LEN_32];            /* 方向编号 */
    CHAR szDirectionName[NETDEV_LEN_32];        /* 方向名称 */
    CHAR szDevID[NETDEV_LEN_32];                /* 设备编号 */
    CHAR szLaneID[NETDEV_LEN_32];               /* 车道编号 */
    CHAR szLaneType[NETDEV_LEN_32];             /* 车道类型 */
    CHAR szLaneDescription[NETDEV_LEN_128];     /* 车道描述 */
    BYTE bRes[128];                             /* 保留字段 Reserved */
}NETDEV_STRUCT_COMMON_INFO_S,*LPNETDEV_STRUCT_COMMON_INFO_S;

/**
 * @struct tagstNETDEVStructVeh
 * @brief 结构化车辆信息
 * @attention
 */
typedef struct tagstNETDEVStructVehInfo
{
    CHAR szAppearTime[NETDEV_LEN_32];           /* 机动车出现时间 */
    CHAR szDisAppearTime[NETDEV_LEN_32];        /* 机动车消失时间 */
    CHAR szRedLightStartTime[NETDEV_LEN_32];    /* 红灯开始时间 */
    CHAR szRedLightEndTime[NETDEV_LEN_32];      /* 红灯结束时间 */
    CHAR szRedLightTime[NETDEV_LEN_32];         /* 红灯时间 */
    CHAR szIdentifyTime[NETDEV_LEN_32];         /* 识别时间 */
    CHAR szCorrectTime[NETDEV_LEN_32];          /* 校对时间 */
    CHAR szLimitedSpeed[NETDEV_LEN_32];         /* 执法限速 */
    CHAR szMarkedSpeed[NETDEV_LEN_32];          /* 标识限速 */
    CHAR szVehicleSpeed[NETDEV_LEN_32];         /* 车辆速度 */
    CHAR szVehicleType[NETDEV_LEN_32];          /* 车辆类型 */
    CHAR szLogoAreaPosition[NETDEV_LEN_32];     /* 车标定位 */
    CHAR szVehicleColor[NETDEV_LEN_32];         /* 车身颜色 */
    CHAR szDriSunVisStat[NETDEV_LEN_32];        /* 正驾驶遮阳板状态 */
    CHAR szCodriSunVisStat[NETDEV_LEN_32];      /* 副驾驶遮阳板状态 */
    CHAR szDriSeatBeltStat[NETDEV_LEN_32];      /* 正驾驶安全带状态 */
    CHAR szCodriSeatBeltStat[NETDEV_LEN_32];    /* 副驾驶安全带状态 */
    CHAR szDriMobileStat[NETDEV_LEN_32];        /* 正驾驶开车打电话状态 */
    CHAR szYlwPlateMarkStat[NETDEV_LEN_32];     /* 黄标车标志状态 */
    CHAR szPendantStatus[NETDEV_LEN_32];        /* 挂坠状态 */
    CHAR szAimStatus[NETDEV_LEN_32];            /* 年检标状态 */
    CHAR szDangerGoodsMarkStat[NETDEV_LEN_32];  /* 危险品标志状态 */
    CHAR szLaneQueueLength[NETDEV_LEN_32];      /* 车道排队长度 */
    BYTE bRes[128];                             /* 保留字段 Reserved */
}NETDEV_STRUCT_VEH_INFO_S,*LPNETDEV_STRUCT_VEH_INFO_S;

/**
 * @struct tagstNETDEVStructNonVeh
 * @brief 结构化非车辆信息
 * @attention
 */
typedef struct tagstNETDEVStructNonVehInfo
{
    CHAR szAppearTime[NETDEV_LEN_32];       /* 非机动车出现时间 */
    CHAR szDisAppearTime[NETDEV_LEN_32];    /* 非机动车消失时间 */
    CHAR szDirectionType[NETDEV_LEN_32];    /* 非机动车运动方向 */
    CHAR szSpeed[NETDEV_LEN_32];            /* 非机动车运动速度 */
    BYTE bRes[128];                         /* 保留字段 Reserved */
}NETDEV_STRUCT_NON_VEH_INFO_S,*LPNETDEV_STRUCT_NON_VEH_INFO_S;

/**
 * @struct tagstNETDEVStructPerson
 * @brief 结构化人员信息
 * @attention
 */
typedef struct tagstNETDEVStructPersonInfo
{
    CHAR szAppearTime[NETDEV_LEN_32];           /* 人员出现时间 */
    CHAR szDisAppearTime[NETDEV_LEN_32];        /* 人员消失时间 */
    CHAR szMovingDirection[NETDEV_LEN_32];      /* 人员运动方向 */
    BYTE bRes[128];                             /* 保留字段 Reserved */
}NETDEV_STRUCT_PERSON_INFO_S,*LPNETDEV_STRUCT_PERSON_INFO_S;

/**
 * @struct tagstNETDEVStructFace
 * @brief 结构化人脸信息
 * @attention
 */
typedef struct tagstNETDEVStructFaceInfo
{
    CHAR szAppearTime[NETDEV_LEN_32];       /* 人脸出现时间 */
    CHAR szDisAppearTime[NETDEV_LEN_32];    /* 人脸消失时间 */
    BYTE bRes[128];                         /* 保留字段 Reserved */
}NETDEV_STRUCT_FACE_INFO_S,*LPNETDEV_STRUCT_FACE_INFO_S;

/**
 * @struct tagstNETDEVStructInfo
 * @brief 结构化XML信息
 * @attention
 */
typedef struct tagstNETDEVStructInfo
{
    NETDEV_STRUCT_COMMON_INFO_S stCommonInfo;           /* 公共信息 */
    UINT32 udwVehicleNum;                               /* 机动车数目 */
    LPNETDEV_STRUCT_VEH_INFO_S pstVehInfo;              /* 机动车信息 */
    UINT32 udwNonVehicleNum;                            /* 非机动车数目 */
    LPNETDEV_STRUCT_NON_VEH_INFO_S pstNonVehInfo;       /* 非机动车信息 */
    UINT32 udwPersonNum;                                /* 人员数目 */
    LPNETDEV_STRUCT_PERSON_INFO_S pstPersonInfo;        /* 人员信息 */
    UINT32 udwFaceNum;                                  /* 人脸数目 */
    LPNETDEV_STRUCT_FACE_INFO_S pstFaceInfo;            /* 人脸信息 */
    BYTE bRes[128];                                     /* 保留字段 Reserved */
}NETDEV_STRUCT_INFO_S,*LPNETDEV_STRUCT_INFO_S;

/**
 * @struct tagNETDEVTMSStrutInfo
 * @brief 结构化报文数据消息
 * @attention
 */
typedef struct tagNETDEVTMSStrutInfo
{
    UINT32                             udwPicNum;                                   /* 图片个数 Picture Number */
    NETDEV_STRUCT_INFO_S               stTmsXmlInfo;                                /* XML信息 XML Information */
    NETDEV_TMS_STRUT_PIC_INFO_S        stTmsPicInfo[NETDEV_TMS_PIC_COMMON_NUM];     /* 图片信息 Picture Message */
    CHAR                               szIPAddr[NETDEV_IPV4_LEN_MAX];               /* 设备IP地址 */

}NETDEV_TMS_STRUT_INFO_S,*LPNETDEV_TMS_STRUT_INFO_S;

/**
 * @struct tagNETDEVTMSInterface 
 * @brief TMS信息（原始数据）
 * @attention
 */
typedef struct tagNETDEVTMSInterface
{
    NETDEV_TMS_CONNECT_INFO_S stTmsConnectInfo;         /* Socket缓存信息 */
    NETDEV_TMS_FACE_PARSE_INFO_S stTmsFaceParseInfo;    /* 人脸识别解析后信息 */
    NETDEV_TMS_HEAT_MAP_INFO_S stTmsHeatMapInfo;        /* 热度图信息 */
    NETDEV_TMS_CAR_PLATE_INFO_S stTmsCarPlateInfo;      /* 车牌识别 */
    NETDEV_TMS_STRUT_INFO_S     stTmsStrutInfo;         /* 结构化信息 */
    CHAR        szIPAddr[NETDEV_IPV4_LEN_MAX];          /* 设备IP地址 */
    BYTE     bRes[240];                                 /* 保留字段 Reserved */
}NETDEV_TMS_INTERFACE_S, *LPNETDEV_TMS_INTERFACE_S;

/**
* @struct tagNETDEVBaseFindCond
* @brief 查找录像基本信息 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVBaseFindCond
{
    INT32   dwChannelID;    /* 通道号  Channel number */
    INT64   tBeginTime;     /* 起始时间  Start time */
    INT64   tEndTime;       /* 结束时间  End time */
    INT32   dwStreamType;   /* 流类型 参见枚举#NETDEV_STREAM_TYPE_E*/
    BYTE    byRes[32];      /* 保留字段  Reserved */
}NETDEV_BASE_FIND_COND_S, *LPNETDEV_BASE_FIND_COND_S;

/**
* @struct tagNETDEVEventFindCond
* @brief 事件查找录像 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVEventFindCond
{
    INT32   dwFindLogic;                                        /* 查找录像类型逻辑 参见枚举#NETDEV_EVENT_FIND_LOGIC_E */
    INT32   dwEventFileTypeSize;                                /* 查找类型个数 */
    INT32   adwEventFileType[NETDEV_EVENT_STORE_TYPE_NUM];      /* 智能查找类型,参见枚举#NETDEV_EVENT_STORE_TYPE_E */
    NETDEV_BASE_FIND_COND_S stBaseCond;                         /* 查询需要基本信息 */
    INT32   dwStreamType;                                       /* 流类型 参见枚举#NETDEV_STREAM_TYPE_E*/
    BYTE    byRes[128];                                         /* 保留字段  Reserved */
}NETDEV_EVENT_FIND_COND_S, *LPNETDEV_EVENT_FIND_COND_S;

/**
* @struct tagNETDEVSmartFindCond
* @brief 智能查找录像 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVSmartFindCond
{
    INT32   dwSensitivity;                                                      /* 灵敏度,取值范围1-8 */
    NETDEV_BASE_FIND_COND_S stBaseCond;                                         /* 查询需要基本信息 */
    UCHAR   awSmartBlock[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];    /* 智能查找块属性,选中填1,不选填0  */
    BYTE    byRes[124];                                                         /* 保留字段  Reserved */
}NETDEV_SMART_FIND_COND_S, *LPNETDEV_SMART_FIND_COND_S;

/**
* @struct tagNETDEVSmartEventFindCond
* @brief 事件查找录像 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVSmartEventFindCond
{
    INT32   dwColumn;                                                           /* 行 */
    INT32   dwRow;                                                              /* 列 */
    INT32   dwSensitivity;                                                      /* 灵敏度  */
    UCHAR   awSmartBlock[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];    /* 智能查找块属性,选中填1,不选填0 */
    INT32   dwFindLogic;                                                        /* 查找录像类型逻辑 参见枚举#NETDEV_EVENT_FIND_LOGIC_E */
    INT32   dwEventFileTypeSize;                                                /* 查找类型个数 */
    INT32   adwEventFileType[NETDEV_EVENT_STORE_TYPE_NUM];                      /* 智能查找类型,参见枚举#NETDEV_EVENT_STORE_TYPE_E */
    NETDEV_BASE_FIND_COND_S stBaseCond;                                         /* 查询需要基本信息 */
    BYTE    byRes[128];                                                         /* 保留字段  Reserved */
}NETDEV_SMART_EVENT_FIND_COND_S, *LPNETDEV_SMART_EVENT_FIND_COND_S;

/**
 * @struct tagNETDEVEventFindData
 * @brief 事件查找数据 结构体定义 
 *        逐个获取查找到的文件信息 
 * @attention 无 None
 */
typedef struct tagNETDEVEventFindData
{
    INT32   dwEventFileTypeSize;                                /* 包含类型个数 */
    INT32   adwEventFileType[NETDEV_EVENT_STORE_TYPE_NUM];      /* 事件查找类型,参见枚举#NETDEV_EVENT_STORE_TYPE_E */
    INT64   tBeginTime;                                         /* 起始时间  Start time */
    INT64   tEndTime;                                           /* 结束时间  End time */
    CHAR    szFileName[NETDEV_LEN_64];                          /* 文件名称 */
    BYTE    byRes[128];                                         /* 保留字段  Reserved */
}NETDEV_EVENT_FIND_DATA_S,*LPNETDEV_EVENT_FIND_DATA_S;



/**
* @struct tagNETDEVQueryPageInfo
* @brief 分页请求信息 结构体定义
* @attention
* 分页查询中每页的条目数, 不能为0, 也不能大于#NETDEV_PAGE_QUERY_ROW_MAX_NUM
*/
typedef struct tagNETDEVQueryPageInfo
{
    INT32   dwPageRowNum;           /* 分页查询中每页的条目数 */
    INT32   dwPageCnt;              /* 表示第几页 */
}NETDEV_QUERY_PAGE_INFO_S;

/**
* @struct tagNETDEVQueryPageInfo
* @brief 分页响应信息 结构体定义
* @attention 无
*/
typedef struct tagNETDEVRspPageInfo
{
    INT32   dwRowNum;           /* 实际返回的条目数 */
    INT32   dwTotalRowNum;      /* 符合条件的总条目数 */
}NETDEV_RSP_PAGE_INFO_S;


/**
* @struct tagNETDEVPortMappingInfo
* @brief 映射端口信息 结构体定义
* @attention
* 保留字段,置为0
*/
typedef struct tagNETDEVPortMappingInfo
{
    INT32   dwHttpLocal;                /* 映射前的HTTP端口 */
    INT32   dwHttpNat;                  /* 映射后的HTTP端口 */
    INT32   dwSdkLocal;                 /* 映射前的SDK端口 */
    INT32   dwSdkNat;                   /* 映射后的SDK端口 */
    INT32   dwMediaLocal;               /* 映射前的Media端口 */
    INT32   dwMediaNat;                 /* 映射后的Media端口 */
    INT32   dwRTSPLocal;                /* 映射前的RTSP端口 */
    INT32   dwRTSPNat;                  /* 映射后的RTSP端口 */

    INT32   dwRes[8];                   /* 保留字段 */
}NETDEV_PORT_MAPPING_INFO_S, *LPNETDEV_PORT_MAPPING_INFO_S;

/**
* @struct tagNETDEVStreamInfo
* @brief 流ID信息 结构体定义
* @attention
* 流ID,置0
*/
typedef struct tagNETDEVStreamInfo
{
    INT32   dwChannelID;                    /* 关联的设备通道 */
    INT32   dwSize;                         /* 结构体大小 */
    BYTE    byID[NETDEV_STREAM_ID_LEN];     /* 流ID */
    BYTE    byRes[NETDEV_LEN_32];           /* 保留字段 */
}NETDEV_STREAM_INFO_S,*LPNETDEV_STREAM_INFO_S;

/**
* @struct tagNETDEVParseVideoData
* @brief 媒体流数据扩展信息 结构体定义
*        拼帧前媒体流扩展信息
* @attention 无
*/
typedef struct tagNETDEVSourceDataExInfo
{
    BYTE szDecoderTag[NETDEV_CODE_STR_MAX_LEN];         /* 解码器标签 */
    BYTE szReserved[64];                                /* 保留字段 */
}NETDEV_SOURCE_DATA_EX_INFO_S;

/**
* @struct tagNETDEVSdkAblity
* @brief 当前SDK的功能信息 结构体定义
* @attention
* 保留字段置为0.
*/
typedef struct tagNETDEVSdkAblity
{
    INT32   dwMaxLoginNum;              /* 最大注册用户数 */
    INT32   dwMaxRealPlayNum;           /* 最大实时预览的路数 */
    INT32   dwMaxPlayBackNum;           /* 最大回放或下载的路数 */
    INT32   dwMaxAlarmChanNum;          /* 最大建立报警通道的路数 */
    INT32   dwMaxFormatNum;             /* 最大硬盘格式化的路数 */
    INT32   dwMaxFileSearchNum;         /* 最大文件搜索的路数 */
    INT32   dwMaxLogSearchNum;          /* 最大日志搜索的路数 */
    INT32   dwMaxSerialNum;             /* 最大建立透明通道的路数 */
    INT32   dwMaxUpgradeNum;            /* 最大升级的路数 */
    INT32   dwMaxVoiceComNum;           /* 最大语音转发的路数 */
    INT32   dwMaxBroadCastNum;          /* 最大语音广播的路数 */
    INT32   dwRes[10];                  /* 保留字段 */
}NETDEV_SDKABILITY_S,*LPNETDEV_SDKABILITY_S;

/**
* @struct tagNETDEVSdkState
* @brief 当前SDK的状态信息 结构体定义
* @attention
* 保留字段置为0.
*/
typedef struct tagNETDEVSdkState
{
    INT32   dwTotalLoginNum;                /* 当前注册的用户数 */
    INT32   dwTotalRealPlayNum;             /* 当前实时预览的路数 */
    INT32   dwTotalPlayBackNum;             /* 当前回放或下载的路数 */
    INT32   dwTotalAlarmChanNum;            /* 当前建立报警通道的路数 */
    INT32   dwTotalFormatNum;               /* 当前硬盘格式化的路数 */
    INT32   dwTotalFileSearchNum;           /* 当前文件搜索的路数 */
    INT32   dwTotalLogSearchNum;            /* 当前日志搜索的路数 */
    INT32   dwTotalSerialNum;               /* 当前建立透明通道的路数 */
    INT32   dwTotalUpgradeNum;              /* 当前升级的路数 */
    INT32   dwTotalVoiceComNum;             /* 当前语音转发的路数 */
    INT32   dwTotalBroadCastNum;            /* 当前语音广播的路数 */
    INT32   dwRes[10];                      /* 保留字段 */
}NETDEV_SDKSTATE_S,*LPNETDEV_SDKSTATE_S;

/**
* @struct tagPrivacyMaskPara
* @brief 隐私遮能力集 Privacy mask capabilities
* @attention
*/
typedef struct tagPrivacyMaskAbility
{
    INT32 dwSupportCnt;             /* 支持的遮盖区域数量 Number of supported privacy mask areas */
}NETDEV_PRIVACY_MASK_ABILITY_S, *LPNETDEV_PRIVACY_MASK_ABILITY_S;


/* 通道OSD能力集 */
typedef struct tagNETDEVOsdAbilityInfo
{
    INT32   bIsSupportTimeOSD;          /* 是否支持时间 */
    INT32   bIsSupportNameOSD;          /* 是否支持名称 */
    UINT32  u32OSDMaxNum;               /* 支持的最大OSD个数 */
    UINT32  u32NameMLen;                /* 支持最大的字符长度 */
    UINT32  u32TimeOSDFormat;           /* 时间OSD格式 参见NETDEV_OSD_TIME_FORMAT_CAP_E */
    UINT32  u32DateOSDFormat;           /* 日期OSD格式 参见NETDEV_OSD_DATE_FORMAT_CAP_E */
    BYTE    byRes[32];                  /* 保留字段 */
}NETDEV_VIDEO_OSD_ABILITY_S, *LPNETDEV_VIDEO_OSD_ABILITY_S;

/**
* @struct tagNETDEVVideoOutChlprofiles
* @brief VideoOut单通道能力集
* @attention 无None
*/
typedef struct tagNETDEVVideoOutChlprofiles
{
    INT32   dwDefaultPane;                              /* 默认分屏数*/
    INT32   dwSupportedMaxPane;                         /* 最大分屏数*/
    INT32   adwSupportedPane[NETDEV_LEN_32];            /* 支持的分屏数,参见#NETDEV_PANE_NUM_E */
    INT32   dwDefaultVideoFormat;                       /* 默认分辨率*/
    INT32   dwSupportedPaneNum;                         /* 支持的分辨率个数 */
    INT32   adwSupportedVideoFormat[NETDEV_LEN_32];     /* 支持的分辨率,参见#NETDEV_VIDEO_FORMAT_E */
}NETDEV_VIDEOOUT_CHL_PROFILES_S, *LPNETDEV_VIDEOOUT_CHL_PROFILES_S;

/**
* @struct tagNETDEVVideoOutALLprofiles
* @brief VideoOut所有通道能力集
* @attention 无None
*/
typedef struct tagNETDEVVideoOutALLprofiles
{
    INT32 dwChlNum;                                     /* 通道数 */
    LPNETDEV_VIDEOOUT_CHL_PROFILES_S pstDCProfiles;     /* 通道能力集 */
}NETDEV_VIDEOOUT_ALL_PROFILES_S, *LPNETDEV_VIDEOOUT_ALL_PROFILES_S;

/**
* @struct tagNETDEVPriviewTVWallInfo
* @brief 实况解码上墙参数
* @attention 无 None
*/
typedef struct tagNETDEVPriviewTVWallInfo
{
    UINT16  dwChannelID;                /* 通道ID  Channel ID */
    UINT16  dwPaneIndex;                /* 窗口索引(从1开始) */
    INT32   dwStreamType;               /* 流类型,#参见NETDEV_STREAM_TYPE_E */
    CHAR    szUrl[NETDEV_LEN_260];      /* 实况Url */
    INT32   dwTransProto;               /* 传输协议,#参见NETDEV_TRANSPORT_PROTOCOL_E */
    BYTE    byRes[256];                 /* 保留字段  Reserved */
}NETDEV_PREVIEW_TVWALLINFO_S, *LPNETDEV_PREVIEW_TVWALLINFO_S;


/**
 * @struct tagNETDEVReceiverInfo
 * @brief 上墙业务信息
 * @attention 无
 */
typedef struct tagNETDEVReceiverInfo
{
    UINT16 dwPaneIndex;             /* receiver对应的分屏索引(从1开始) */
    INT32 dwReceiverMode;           /* receiver配置信息 */
    INT32 dwStreamType;             /* 流类型 */
    INT32 dwTransportProtocol;      /* 传输协议 */
    CHAR  szUrl[NETDEV_LEN_260];    /* 实况或回放url */
    BYTE  byRes[64];                /* 保留字段 */
}NETDEV_RECEIVER_INFO_S, *LPNETDEV_RECEIVER_INFO_S;

/**
 * @struct tagNETDEVReceiverInfoList
 * @brief 某一通道ID下所有业务信息
 * @attention 无
 */
typedef struct tagNETDEVReceiverInfoList
{
    INT32                   dwSize;                                         /* 业务信息数量 */
    NETDEV_RECEIVER_INFO_S  astReceiverInfoList[NETDEV_MAX_PANE_NUM];       /* 所有业务信息 */
}NETDEV_RECEIVER_INFO_LIST_S, *LPNETDEV_RECEIVER_INFO_LIST_S;


/**
 * @struct tagNETDEVDevLoginParamInfo
 * @brief 设备登陆成功后的基本信息 结构体定义 Device information Structure definition
 * @attention 无 None   用于获取设备登陆成功后一些基本参数，例如网络连接模式
 */
typedef struct tagNETDEVDevLoginParamInfo
{
    NETDEV_NETWORK_MODE_E   eNetWorkMode;   /* 网络模式,参见枚举#NETDEV_NETWORK_MODE_E */
    BYTE                    byRes[48];      /* 保留字段  Reserved */
}NETDEV_DEV_LOGIN_PARAM_INFO_S,*LPNETDEV_DEV_LOGIN_PARAM_INFO_S;


/**
 * @struct tagNETDEVChlOsdCfg
 * @brief 通道OSD配置
 * @attention
 */
typedef struct tagNETDEVChlOsdCfg
{
    INT32 dwOsdID;                                      /* OSD ID */
    NETDEV_OSD_TEXT_TYPE_E enOsdTextType;               /* OSD类型 */
    NETDEV_AREA_SCOPE_S stAreaScope;                    /* OSD坐标 */
    CHAR szTextInfo[NETDEV_OSD_TEXT_MAX_LEN];           /* OSD内容 */
}NETDEV_CHL_OSD_CFG_S, *LPNETDEV_CHL_OSD_CFG_S;

/**
 * @struct tagNETDEVChlOsdCfgList
 * @brief 通道OSD配置列表
 * @attention
 */
typedef struct tagNETDEVChlOsdCfgList
{
    INT32 dwSize;                                               /* OSD个数 */
    NETDEV_CHL_OSD_CFG_S stChlOsdCfg[NETDEV_OSD_MAX_NUM_EX];    /* OSD配置 */
}NETDEV_CHL_OSD_CFG_LIST_S, *LPNETDEV_CHL_OSD_CFG_LIST_S;

/**
 * @struct tagNETDEVNetworkInfo
 * @brief 网络信息
 * @attention 无 None
 */
typedef struct tagNETDEVNetworkInfo
{
    CHAR    szIPAddress[NETDEV_LEN_32];         /* IP地址  */
    INT32   dwHttpPort;                         /* Http端口 */
    INT32   dwRtspPort;                         /* Rtsp端口 */

}NETDEV_NETWORKINFO_S, *LPNETDEV_NETWORKINFO_S;

/**
 * @struct tagstNETDEVBandWith
 * @brief 网络带宽状态
 * @attention 
 */
typedef struct tagstNETDEVBandWith
{
    UINT32 udwTotal;                /*总带宽*/
    UINT32 udwLive;                 /*实况占用带宽*/
    UINT32 udwReplayAndDown;        /*回放/下载占用带宽*/
    UINT32 udwResidual;             /*剩余带宽*/
}NETDEV_NETWORK_BANDWIDTH_S, *LPNETDEV_NETWORK_BANDWIDTH_S;

/**
* @struct tagsNETDEVStreamNum
* @brief 流路数
* @attention
*/
typedef struct tagNETDEVStreamNum
{
    INT32   dwCurrent;              /* 实况流路数,即已用路数 */
    INT32   dwTotal;                /* 总路数 */
}NETDEV_STREAM_NUM_S, *LPNETDEV_STREAM_NUM_S;

/**
 * @struct tagstNETDEVBandWithInfo
 * @brief 网络带宽状态数据
 * @attention 
 */
typedef struct tagstNETDEVBandWithInfo
{
    NETDEV_NETWORK_BANDWIDTH_S stInputBandWidth;
    NETDEV_NETWORK_BANDWIDTH_S stOutputBandWidth;
    NETDEV_STREAM_NUM_S stStreamNum;
}NETDEV_NETWORK_BANDWIDTH_INFO_S, *LPNETDEV_NETWORK_BANDWIDTH_INFO_S;


/**
 * @struct tagstNETDEVOperateInfo
 * @brief 单个操作信息
 * @attention dwID为入参，dwReturnCode为出参
 */
typedef struct tagNETDEVOperateInfo
{
    INT32   dwID;                   /* ID */
    INT32   dwReturnCode;           /* 返回码*/
    BYTE    byRes[64];              /* 保留字段  Reserved field */
}NETDEV_OPERATE_INFO_S, *LPNETDEV_OPERATE_INFO_S;

/**
 * @struct tagstNETDEVOperateList
 * @brief 批量处理列表
 * @attention
 */
typedef struct tagNETDEVOperateList
{
    INT32   dwSize;                                 /* 批量处理数量 */
    LPNETDEV_OPERATE_INFO_S   pstOperateInfo;       /* 批量处理信息 */
}NETDEV_OPERATE_LIST_S, *LPNETDEV_OPERATE_LIST_S;


/**
* @struct tagNETDEVTrafficStatisticsCondEx
* @brief 多通道客流量统计命令 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVMultiTrafficStatisticsCond
{
    NETDEV_OPERATE_LIST_S   stChannelIDs;               /* 通道ID列表 */
    UINT32                  udwStatisticsType;          /* 参见 NETDEV_TRAFFIC_STATISTICS_TYPE_E */
    UINT32                  udwFormType;                /* 参见 NETDEV_TRAFFIC_STATIC_FORM_TYPE_E */
    INT64                   tBeginTime;                 /* 起始时间 */
    INT64                   tEndTime;                   /* 结束时间 */
    BYTE                    byRes[256];
}NETDEV_MULTI_TRAFFIC_STATISTICS_COND_S, *LPNETDEV_MULTI_TRAFFIC_STATISTICS_COND_S;

/**
* @struct tagNETDEVFaceDetectionCapInfo
* @brief 人脸检测能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVFaceDetectionCapInfo 
{
    BOOL bIsSupport;                                                    /* 是否支持Smart人脸检测 */
    BOOL bQualityAnalysisIsSupport;                                     /* 是否具有人脸质量优先（上报图片）能力 */
    INT32 dwFaceQualityAnalysisType;                                    /* 人脸质量优先类型, 参考枚举NETDEV_FACE_ANALYSIS_SKILL_E */
    BOOL bAttributeAnalysisIsSupport;                                   /* 设备具备是否具有人脸属性分析（上报）能力 */
    INT32 adwAttributeAnalysisSkills[NETDEV_FACE_ANALYSIS_SKILL_NUM];   /* 设备的人脸分析能力，参考枚举 当为“0”时，该对象可以不存在 */
    BOOL bFeatureIsSupport;                                             /* 设备是否具有人脸二进制特征提取（上报）能力 */
    BOOL bRecognitionIsSupport;                                         /* 设备是否具有人脸识别能力 */
    INT32 dwFaceRecognitionType;                                        /*人脸识别类型, 参考枚举NETDEV_FACE_RECOGNITION_TYPE_E */
}NETDEV_FACE_DETEC_CAP_S, *LPNETDEV_FACE_DETEC_CAP_S;

/**
* @struct tagNETDEVIntrusionDetectionCapInfo
* @brief 区域入侵能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVIntrusionDetectionCapInfo 
{
    BOOL bIsSupport;                        /* 是否支持区域入侵 */
    INT32 dwPecentMin;                      /* 区域入侵中，图形占比(Percentages)最小值, 不支持区域入侵时，该字段可选 */
    INT32 dwPecentMax;                      /* 区域入侵中，图形占比(Percentages)最大值, 不支持区域入侵时，该字段可选 */
    INT32 dwTimeThresholdMin;               /* 区域入侵中，时间阈值(TimeThreshold)最小值, 不支持区域入侵时，该字段可选 */
    INT32 dwTimeThresholdMax;               /* 区域入侵中，时间阈值(TimeThreshold)最大值, 不支持区域入侵时，该字段可选 */
    BYTE bRes[32];                          /* 保留字段 */
}NETDEV_INTRUSION_DETEC_CAP_S, *LPNETDEV_INTRUSION_DETEC_CAP_S;

/**
* @struct tagNETDEVCrossLineDetectionCapInfo
* @brief 越界检测能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVCrossLineDetectionCapInfo
{
    BOOL bIsSupport;                /* 是否支持越界检测 */
    BYTE bRes[32];                  /* 保留字段 */
}NETDEV_CROSS_LINE_DETEC_CAP_S, *LPNETDEV_CROSS_LINE_DETEC_CAP_S;

/**
* @struct tagNETDEVPassengerFlowCapInfo
* @brief 客流量检测能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVPassengerFlowCapInfo
{
    BOOL bIsSupport;                /* 是否支持客流量检测 */
    BYTE bRes[32];                  /* 保留字段 */
}NETDEV_PASSENGER_FLOW_CAP_S, *LPNETDEV_PASSENGER_FLOW_CAP_S;


/**
* @struct tagNETDEVAudioDetectionCapInfo
* @brief 音频检测能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVAudioDetectionCapInfo
{
    BOOL bIsSupport;    /* 是否支持音频检测 */
    INT32 dwDiffMin;    /* 音频检测中，差值/阈值的最小值, 不支持音频检测时，该字段可选 */
    INT32 dwDiffMax;    /* 音频检测中，差值/阈值的最大值, 不支持音频检测时，该字段可选  */
}NETDEV_AUDIO_DETEC_CAP_S, *LPNETDEV_AUDIO_DETEC_CAP_S;

/**
* @struct tagNETDEVObjTrackCapInfo
* @brief 智能跟踪能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVObjTrackCapInfo
{
    BOOL bIsSupport;                                /* 是否支持智能跟踪 */
    INT32 adwMode[NETDEV_OBJ_TRACK_MODE_NUM];       /* 跟踪模式,参考枚举NETDEV_OBJ_TRACK_MODE_E，支持智能跟踪时可选 */
    INT32 dwTrackTimeMin;                           /* 最小跟踪时间（单位：s），跟踪模式包含NETDEV_OBJ_TRACK_MODE_FULLVIEW时可选 */
    INT32 dwTrackTimeMax;                           /* 最大跟踪时间（单位：s），跟踪模式包含NETDEV_OBJ_TRACK_MODE_FULLVIEW时可选 */
}NETDEV_OBJ_TRACK_CAP_S, *LPNETDEV_OBJ_TRACK_CAP_S;

/**
* @struct tagNETDEVSmartCapInfo
* @brief smart智能能力 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVSmartCapInfo
{
    NETDEV_FACE_DETEC_CAP_S         stFaceDetecCap;                 /* 人脸检测能力 */
    NETDEV_INTRUSION_DETEC_CAP_S    stIntrusionDetecCap;            /* 区域入侵能力 */
    NETDEV_CROSS_LINE_DETEC_CAP_S   stCrossLineDetecCap;            /* 越界检测能力 */
    NETDEV_PASSENGER_FLOW_CAP_S     stPassengerFlowCap;             /* 客流量检测能力 */
    NETDEV_AUDIO_DETEC_CAP_S        stAudioDetecCap;                /* 音频检测能力 */
    NETDEV_OBJ_TRACK_CAP_S          stObjTrackCap;                  /* 智能跟踪能力 */
    BYTE byRes[512];                                                /* 保留字段 */
}NETDEV_SMART_CAP_S, *LPNETDEV_SMART_CAP_S;

/**
* @struct tagNETDEVTrafficStatisticsReportTime
* @brief 设置客流量上报时间间隔结构体
* @attention 无 None
*/
typedef struct tagNETDEVTrafficStatisticsReportTime
{
    UINT32  udwReportTimeInterval;      /*时间间隔 单位秒*/
    BOOL    bEnable;                    /*使能*/
}NETDEV_TRAFFIC_STATISTICS_REPORT_TIME_S, *LPNETDEV_TRAFFIC_STATISTICS_REPORT_TIME_S;

/**
 * @struct tagNETDEVChlDeviceInfo
 * @brief 设备通道基本信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVChlDeviceInfo
{
    INT32 dwChannelID;                                  /* 通道号 */
    CHAR szDevModel[NETDEV_LEN_64];                     /* 设备型号  Device model */
    CHAR szSerialNum[NETDEV_LEN_64];                    /* 硬件序列号  Hardware serial number */
    CHAR szFirmwareVersion[NETDEV_LEN_64];              /* 软件版本号  Software version */
    CHAR szHardewareID[NETDEV_LEN_64];                  /* 硬件标识 */
    CHAR szUbootVersion[NETDEV_LEN_64];                 /* UBOOT引导版本 */
    BYTE byRes[512];                                    /* 保留字  Reserved */
}NETDEV_DEVICE_CHL_INFO_S, *LPNETDEV_DEVICE_CHL_INFO_S;


/**
 * @struct tagNETDEVNewVersionDateInfo
 * @brief 新版本发布时间 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVNewVersionDateInfo
{
    UINT32 udwYear;         /* 年  Year */
    UINT32 udwMonth;        /* 月  Month */
    UINT32 udwDay;          /* 日  Day */
    UINT32 udwHour;         /* 时  Hour */
    UINT32 udwMinute;       /* 分  Minute */
    BYTE   byRes[64];       /* 保留字段 */
}NETDEV_NEW_VERSION_DATE_INFO_S, *LPNETDEV_NEW_VERSION_DATE_INFO_S;


/**
 * @struct tagNETDEVUpgradeInfo
 * @brief 设备升级版本信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVUpgradeInfo
{
    BOOL                            bHasNewVersion;                             /* 是否存在新版本 0:没有新版本 1:有新版本*/
    CHAR                            szNewFirmwareVersion[NETDEV_LEN_64];        /* 新的软件版本号 当bHasNewVersion为0时，该节点可选*/
    UINT32                          udwID;                                      /* ID为0，默认设备自身*/
    NETDEV_NEW_VERSION_DATE_INFO_S  stNewVersionDateInfo;                       /* 新版本的发布时间，当HasNewVersion为0时，该节点可选（NVR需要）具体见#NETDEV_NEW_VERSION_DATE_INFO_S*/
    CHAR                            szVersionDescription[NETDEV_LEN_1024];      /* 版本描述*/
    BYTE                            byRes[256];                                 /* 保留字段 */
}NETDEV_UPGRADE_INFO_S, *LPNETDEV_UPGRADE_INFO_S;

/**
 * @struct tagNETDEVUpgradeDevice
 * @brief 升级设备所需信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVUpgradeDevice
{
    INT32 dwUpgradeType;                    /* 升级类型 参考枚举#NETDEV_UPGRADE_TYPE_E */
    INT32 dwSize;                           /* 需升级通道个数 ,为0时默认给NVR自身升级 */
    INT32 adwChannelID[NETDEV_LEN_64];      /* 需升级的通道 */
    CHAR  szPath[NETDEV_PATH_LEN];          /* 升级文件所在路径 */
    BYTE  byRes[256];                       /* 保留字  Reserved */
}NETDEV_UPGRADE_DEVICE_S, *LPNETDEV_UPGRADE_DEVICE_S;

/**
 * @struct tagNETDEVUpgradeStatus
 * @brief 升级设备状态信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVUpgradeStatus
{
    INT32 dwStatus;             /* 升级状态,参考枚举#NETDEV_UPGRADE_STATUS_E */
    INT32 dwPercent;            /* 百分比 */
    INT32 dwChannelID;          /* 通道号 */
    BYTE  byRes[256];           /* 保留字段 */
}NETDEV_UPGRADE_STATUS_S, *LPNETDEV_UPGRADE_STATUS_S;

/**
 * @struct tagNETDEVChannelsBasicInfo
 * @brief 通道基本信息
 * @attention 无 None
 */
typedef struct tagNETDEVChannelsBasicInfo
{
    UINT32                      udwAddType;                                     /* 添加类型：0：IP；1:即插即用； 2：EZDDNS；3：通用域名；*/
    UINT32                      udwAddressType;                                 /* IP地址类型0: IPv4,1: IPv6,: 域名.当AddType为2或3时，此处必填2。*/
    CHAR                        szAddress[NETDEV_IPADDR_STR_MAX_LEN];           /* IP地址,字符串范围[0,64]*/
    CHAR                        szDDNSAdress[NETDEV_DOMAIN_LEN];                /* DDNS服务器地址，范围[0,64]，当AddType为2时，该选项必选。*/
    UINT32                      udwPort;                                        /* 端口号,范围[1, 65535]当AddType为0和3时，该选项必选*/ 
    CHAR                        szLoginName[NETDEV_NAME_MAX_LEN];               /* 接入设备的登录用户名，范围[0,20]*/
    CHAR                        szPIN[NETDEV_LEN_256];                          /* 接入设备的登录密码,范围[0,256],POST时必选。修改密码时用户下发的为RSA加密后再进行base64编码的密文，公私钥对由NVR生成。如果在配置时，该密码没有修改，可以不下发该字段；如果配置时，该密码为空，则下发空字段*/
    NETDEV_RSA_PUBLIC_KEY_S     stRSAPublicKey;                                 /* 不修改接入登录密码时不必携带，修改接入登录密码时必携带，获取时默认不携带该字段；具体请见：#NETDEV_RSA_PUBLIC_KEY_S*/
    UINT32                      udwAccessProtocol;                              /* 接入协议*/
    UINT16                      udwNum;                                         /* 接入设备的通道号数，范围[0, 16]*/
    UINT32                      audwRemoteIndexList[NETDEV_CHANNEL_MAX];        /* 多通道接入设备的通道号列表,Num为0时此节点可选*/
    UINT32                      udwRemoteIndex;                                 /* 多通道接入设备的通道号(修改信息时使用)*/ 
    NETDEV_GBINFO_S             stGBInfo;                                       /* 国标信息 当AccessProtocol值为3时该节点必选，其他可选*/
    UINT32                      udwIsPTZNeeded;                                 /* 是否需要云台：0: 自适应；1: 不需要；2: 需要。（添加通道时使用）*/
    BOOL                        bLongHaulEnabled;                               /* 长距离传输使能：0: 不使能；1: 使能；当AddType值为1时，此节点必选（修改时使用）*/
    BYTE                        byRes[128];                                     /* 保留字节 */
}NETDEV_CHANNEL_BASIC_INFO_S, *LPNETDEV_CHANNEL_BASIC_INFO_S;

/**
 * @struct tagNETDEVChannelsInfos
 * @brief 通道信息
 * @attention 无 None
 */
typedef struct tagNETDEVChannelsInfos
{
    UINT32   udwNum;                                    /* 接入设备的通道号数，不为0*/
    UINT32   audwChannelList[NETDEV_CHANNEL_MAX];       /* 通道号列表*/
    BYTE     byRes[128];                                /* 保留字节 */
}NETDEV_CHANNEL_LIST_S, *LPNETDEV_CHANNEL_LIST_S;

/**
 * @struct tagNETDEVAudioDecodeStatus
 * @brief 随路音频状态信息
 * @attention 无 None
 */
typedef struct tagNETDEVAudioDecodeStatus
{
    INT32 dwStreamID;       /* 视频流索引号 */
    BOOL  bDecodeAudio;     /* 是否开启随路音频解码 */
}NETDEV_AUDIO_DECODE_STATUS_S, *LPNETDEV_AUDIO_DECODE_STATUS_S;

/**
 * @struct tagNETDEVAudioDecodeStatusList
 * @brief 随路音频状态信息列表
 * @attention 无 None
 */
typedef struct tagNETDEVAudioDecodeStatusList
{
    INT32 dwSize;   /* 数量 */
    NETDEV_AUDIO_DECODE_STATUS_S astAudioDecStatus[NETDEV_STREAM_MAX_NUM];  /* 随路音频状态信息 */
}NETDEV_AUDIO_DECODE_STATUS_LIST_S, *LPNETDEV_AUDIO_DECODE_STATUS_LIST_S;


/**
* @struct tagNETDEVAudioInputEncodeFormatInfo
* @brief 音频编码格式信息
* attention None
*/
typedef struct tagNETDEVAudioInputEncodeFormatInfo
{
    UINT32 udwType;                                                         /* 音频编码格式类型，参见枚举#NETDEV_AUDIO_ENCODE_FORMAT_TYPE_E */
    UINT32 udwSamplingRateNum;                                              /* 支持的采样率数目 */
    UINT32 audwSamplingRateList[NETDEV_AUDIO_SAMPLING_RATE_MAX_NUM];        /* 支持的采样率列表 参见枚举#NETDEV_AUDIO_SAMPLING_RATE_E */
    BYTE   byRes[128];                                                      /* 保留字节 */
}NETDEV_AUDIO_IN_ENCODE_FORMAT_INFO_S, *LPNETDEV_AUDIO_IN_ENCODE_FORMAT_INFO_S;

/**
* @struct tagNETDEVAudioInputModeInfo
* @brief 音频输入模式信息
* attention None
*/
typedef struct tagNETDEVAudioInputModeInfo
{
    INT32  dwChannelID;                                         /* 音频通道号 */
    UINT32 udwModeNum;                                          /* 音频模式数量 */
    UINT32 audwModeList[NETDEV_AUDIO_IN_CHL_MODE_MAX_NUM];      /* 支持的音频输入通道模式列表 参见枚举#NETDEV_AUDIO_CHL_MODE_E */
    BYTE   byRes[128];                                          /* 保留字节 */
}NETDEV_AUDIO_IN_MODE_INFO_S, *LPNETDEV_AUDIO_IN_MODE_INFO_S;

/**
 * @struct tagNETDEVAudioCapInfo
 * @brief 视频输入通道音频能力集信息
 * @attention 无 None
 */
typedef struct tagNETDEVAudioCapInfo
{
    INT32                                   dwAudioInNum;                                                   /* 支持的音频口输入的数目 */
    NETDEV_AUDIO_IN_MODE_INFO_S             astAudioInModeList[NETDEV_AUDIO_IN_MAX_NUM];                    /* 音频口输入模式列表 */
    INT32                                   dwAudioInEncFmtNum;                                             /* 支持的音频输入编码格式数量 */
    NETDEV_AUDIO_IN_ENCODE_FORMAT_INFO_S    astAudioInEncFmtList[NETDEV_AUDIO_IN_ENCODE_FORMAT_MAX_NUM];    /* 支持的音频输入编码格式列表 */
    INT32                                   dwSerialInNum;                                                  /* 支持的串口输入的数目，用于外接数字拾音器 */
    NETDEV_AUDIO_IN_MODE_INFO_S             astSerialInModeList[NETDEV_SERIAL_IN_MAX_NUM];                  /* 串口输入模式列表 */
    INT32                                   dwSerialInEncFmtNum;                                      /* 串口输入支持的编码格式数量 */
    NETDEV_AUDIO_IN_ENCODE_FORMAT_INFO_S    astSerialInEncFmtList[NETDEV_SERIAL_IN_ENCODE_FORMAT_MAX_NUM];  /* 串口输入支持的编码格式列表 */
    BYTE                                    byRes[256];                                                     /* 保留字段 */
}NETDEV_AUDIO_CAP_S, *LPNETDEV_AUDIO_CAP_S;

/**
* @struct tagNETDEVAudioInputInfo
* @brief 音频输入通道信息
* attention None
*/
typedef struct tagNETDEVAudioInputInfo
{
    INT32  dwChannelID;     /* 音频通道号 */
    UINT32 udwEnabled;      /* 音频输入通道是否启动 */
    UINT32 udwMode;         /* 音频输入通道模式 参见枚举#NETDEV_AUDIO_CHL_MODE_E */
    BYTE   byRes[128];      /* 保留字节 */
}NETDEV_AUDIO_INPUT_INFO_S, *LPNETDEV_AUDIO_INPUT_INFO_S;

/**
 * @struct tagNETDEVAudioInputCfgInfo
 * @brief 音频输入参数配置信息
 * @attention 无 None
 */
typedef struct tagNETDEVAudioInputCfgInfo
{
    BOOL bIsMute;                                                                   /* 是否静音 0：不静音，1 静音 */
    UINT32 udwType;                                                                 /* 采集口类型 参见枚举#NETDEV_AUDIO_COLLECTION_PORT_TYPE_E */
    UINT32 udwEncodeFormat;                                                         /* 音频编码格式 参见枚举#NETDEV_AUDIO_ENCODE_FORMAT_TYPE_E */
    UINT32 udwSampleRate;                                                           /* 音频采样率 参见枚举#NETDEV_AUDIO_SAMPLING_RATE_E */
    UINT32 udwInputGain;                                                            /* 音频增益，范围[0,255] */
    BOOL bNoiseReductionEnabled;                                                    /* 是否启用降噪 0不启用，1启用 */
    INT32 dwAudioInNum;                                                             /* 音频输入数量 */
    NETDEV_AUDIO_INPUT_INFO_S astAudioInputInfoList[NETDEV_AUDIO_IN_MAX_NUM];       /* 音频输入采集信息列表，当采集口类型为NETDEV_AUDIO_COLLECTION_PORT_TYPE_AUDIO_IN时有效 */
    INT32 dwSerialInNum;                                                            /* 串口输入数量 */
    NETDEV_AUDIO_INPUT_INFO_S astSerialInputInfoList[NETDEV_SERIAL_IN_MAX_NUM];     /* 串口音频采集信息列表 */
    BYTE  byRes[256];                                                               /* 保留字段 */
}NETDEV_AUDIO_INPUT_CFG_INFO_S, *LPNETDEV_AUDIO_INPUT_CFG_INFO_S;


/**
 * @struct tagNETDEVTimeSection
 * @brief 时间段配置 结构体定义 Time Sections Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVTimeSection
{
    CHAR    szBeginTime[NETDEV_LEN_64];              /* 开始时间  Begin time */
    CHAR    szEndTime[NETDEV_LEN_64];                /* 结束时间  End time */
}NETDEV_TIME_SECTION_S, *LPNETDEV_TIME_SECTION_S;

/**
 * @struct tagNETDEVDayPlan
 * @brief 计划（天）配置 结构体定义 Play (Day) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDayPlan
{
    UINT32                       udwIndex;                                                  /* 索引  day index */
    UINT32                       udwSectionNum;                                             /* 时间段个数  Section Num */
    NETDEV_TIME_SECTION_S        astTimeSection[NETDEV_PLAN_TIME_SECTION_NUM_ADAY];         /* 时间段配置  Time Sections */
}NETDEV_DAY_PLAN_S, *LPNETDEV_DAY_PLAN_S;

/**
 * @struct tagNETDEVPlanWeek
 * @brief 计划（周）配置 结构体定义 Play (Week) Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVPlanWeek
{
    UINT32              udwDayNum;                                  /* 天数  day num*/
    NETDEV_DAY_PLAN_S   astDayPlan[NETDEV_PLAN_DAY_NUM_AWEEK];      /* 天数配置  days */
}NETDEV_WEEK_PLAN_S, *LPNETDEV_WEEK_PLAN_S;


/**
 * @struct tagNETDEVPointS
 * @brief 点坐标
 * @attention
 */
typedef struct tagNETDEVPointS
{
    INT32 dwPointX;     /* 横坐标,万分比 */
    INT32 dwPointY;     /* 纵坐标,万分比 */
}NETDEV_POINT_S, *LPNETDEV_POINT_S;

/**
 * @struct tagNETDEVCustomFileInfo
 * @brief 设备定制配置所需信息 结构体定义 Basic device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCustomFileInfo
{
    CHAR  szCustomFilePath[NETDEV_PATH_LEN];              /* 定制文件所在路径 */
    CHAR  szMd5Data[NETDEV_LEN_64];                       /* 定制文件的Md5值 */
    BYTE  byRes[256];                                     /* 保留字  Reserved */
}NETDEV_CUSTOM_FILE_INFO_S, *LPNETDEV_CUSTOM_FILE_INFO_S;

typedef struct tagNETDEVLogMainTypes
{
    INT32 dwMainType;                          /* 日志主类型, 请参考#NETDEV_LOG_MAIN_TYPE_E */
    CHAR  *pcDescription;                      /* 对应的字符串 */
}NETDEV_LOG_MAIN_TYPE_S;

/**
 * @struct tagNETDEVNetworkDiagnosis
 * @brief 网络诊断消息 Network Diagnosis
 * @attention 无 None
 */  
typedef struct tagNETDEVNetworkDiagnosis
{
    UINT32    dwPacketSize;             /* 报文大小(单位:byte) */
    UINT32    dwPacketNum;              /* 报文数量 */
    UINT32    dwDuration;               /* 检测持续时间(单位:s) */
    CHAR      szUrl[NETDEV_LEN_260];    /* 诊断报文发送URL */
} NETDEV_NETWORK_DIAGNOSIS_S, *LPNETDEV_NETWORK_DIAGNOSIS_S;

/**
* @struct tagNETDEVAlarmFindConds
* @brief 告警信息查找条件 结构体定义
* @attention 无
*/
typedef struct tagNETDEVAlarmFindConds
{
    INT32   dwChannelID;      /* 通道ID */
    INT64   tBeginTime;       /* 开始时间 */
    INT64   tEndTime;         /* 结束时间 */
    BYTE    byRes[128];       /* 保留字段  Reserved */
}NETDEV_FIND_ALARM_COND_S, *LPNETDEV_FIND_ALARM_COND_S;

/**
* @struct tagNETDEVFindAlarmInfo
* @brief 告警信息 结构体定义
* @attention 无
*/
typedef struct tagNETDEVFindAlarmInfo
{
    INT64    tAlarmTime;        /* 告警时间 */
    INT32    dwAlarmType;       /* 告警类型, 请参考#NETDEV_FIND_ALARM_TYPE_E */
    BYTE     byRes[256];        /* 保留字段  Reserved */
}NETDEV_FIND_ALARM_INFO_S, *LPNETDEV_FIND_ALARM_INFO_S;


/**
 * @struct tagNETDEVSDKInfo
 * @brief SDK信息
 * @attention 无 None
 */
typedef struct tagNETDEVSDKInfo
{
    CHAR szSDKType[NETDEV_LEN_64];                   /* SDK类型 */
    CHAR szSDKVersion[NETDEV_LEN_64];                /* SDK版本号 */
}NETDEV_SDK_INFO_S, *LPNETDEV_SDK_INFO_S;

/**
 * @struct tagNETDEVSplitScreenInfo
 * @brief 分屏信息
 * @attention 无 None
 */
typedef struct tagNETDEVSplitScreenInfo
{
    INT32 dwOperatedMode;           /* 操作模式, NETDEV_OPERATED_MODE_E*/
    INT32 dwSplitScreenIndex;       /* 分屏序号 */

}NETDEV_SPLIT_SCREEN_INFO_S, *LPNETDEV_SPLIT_SCREEN_INFO_S;

/**
 * @struct tagNETDEVAlarmDeviceInfo
 * @brief 告警设备信息 结构体定义 Alarm device information Structure definition
 * @attention 无  
 1.通道号仅在告警源类型是视频通道类型和报警输入通道时,其他情况下dwChannelID默认为0,
 2.告警源类型参见NETDEV_ALARM_SRC_TYPE_E 要获取具体信息可参见NETDEV_ALARM_LISTEN_INFO_S类型中的dwAlarmSrcID字段。
 */
typedef struct tagNETDEVAlarmDeviceInfo
{
    CHAR    pszIP[16];      /* 设备IP device IP */
    INT32   dwChannelID;    /* 通道号 */
    BYTE    byRes[128];     /* 保留字段  Reserved */

}NETDEV_ALARM_DEVICE_INFO_S, *LPNETDEV_ALARM_DEVICE_INFO_S;

/**
 * @struct tagNETDEVAlarmListenInfo
 * @brief 告警信息 结构体定义 Alarm device information Structure definition
 * @attention 无 
 告警资源ID 使用规则：
 1. AlarmSrcType为0-7，AlarmSrcID代表存储盘索引。
 2. AlarmSrcType为8，AlarmSrcID代表视频通道号。
 3. AlarmSrcType为9，AlarmSrcID代表报警输入通道号。
 4.AlarmSrcType为10,AlarmSrcID默认为0,代表系统本身。 
 */
typedef struct tagNETDEVAlarmListenInfo
{
    INT32   dwAlarmType;                /*告警类型 参见枚举#NETDEV_ALARM_TYPE_E */
    INT32   dwAlarmSrcType;             /*告警源类型 参见枚举#NETDEV_ALARM_SRC_TYPE_E*/
    INT64   tAlarmTime;                 /* 告警发生时间  Alarm time */
    INT32   dwAlarmSrcID;               /* 告警资源ID */
    CHAR    szAlarmSrcName[128];        /*告警源名称 VMS使用*/
    INT32   dwAlarmSeq;                 /*告警序号 IPC & VMS使用*/
    BYTE    byRes[128];                 /* 保留字段  Reserved */
}NETDEV_ALARM_LISTEN_INFO_S,*LPNETDEV_ALARM_LISTEN_INFO_S;

/**
 * @struct tagNETDEVDiagnosisInfoURL
 * @brief 诊断信息URL
 * @attention
 */
typedef struct tagNETDEVDiagnosisInfoURL
{
    CHAR   szURL[NETDEV_LEN_256];      /* 诊断信息URL */
}NETDEV_DIAGNOSIS_INFO_URL_S, *LPNETDEV_DIAGNOSIS_INFO_URL_S;


/**
 * @struct tagNETDEVDiagnosisInfo
 * @brief 诊断信息
 * @attention
 */
typedef struct tagNETDEVDiagnosisInfo
{
    INT32    dwTime;                          /* 文件创建时间 */
    CHAR     szFileName[NETDEV_LEN_64];       /* 文件名 */
    INT32    dwSize;                          /* 文件大小 */
}NETDEV_DIAGNOSIS_INFO_S, *LPNETDEV_DIAGNOSIS_INFO_S;
/**
 * @struct tagNETDEVDownDiagnosisFileInfo
 * @brief 下载诊断文件的信息
 * @attention
 */
typedef struct tagNETDEVDownDiagnosisFileInfo
{
    CHAR    szURL[NETDEV_MAX_URL_LEN];         /* 诊断信息URL */
    BOOL    bSaveLocal;                        /* 是否保存在本地，TURE表示保存本地，FALSE表示写入缓存*/
    CHAR    szFileName[NETDEV_LEN_260];        /* 保存诊断信息的本地路径及名称*/
    CHAR*   pcBuffer;                          /* 保存诊断信息缓存,需客户申请内存，大小为dwSize缓存大小*/
    INT32   dwSize;                            /* 缓存大小*/
    BYTE    byRes[256];                        /* 保留字段 Reserved */
}NETDEV_DIAGNOSIS_FILE_INFO_S, *LPNETDEV_DIAGNOSIS_FILE_INFO_S;


/**
* @struct tagNETDEVFaceGalleyInfo
* @brief 人脸特征库信息
* @attention
*/
typedef struct tagNETDEVFaceGalleyInfo
{
    CHAR    szGalleyID[NETDEV_FACE_FEATURE_GALLEY_ID_LEN];          /* 人脸特征库ID */
    UINT32  udwGalleyType;                                          /* 人脸特征库类型 参见枚举 NETDEV_FACE_DB_TYPE_E*/
    UINT32  udwFeatureDataLen;                                      /* 人脸特征库净荷总长度 单位字节*/
    CHAR    szFeatureVersion[NETDEV_FACE_FEATURE_VERSION_LEN];      /* 人脸特征模型版本号 长度为char[40]*/
    CHAR    szFeatureFileMD5[NETDEV_FACE_FEATURE_FILE_MD5_LEN];     /* 人脸特征库净荷的MD5值 128比特*/
    BYTE    byRes[128];                                             /* 保留字段  Reserved */
}NETDEV_FACE_GALLEY_INFO_S, *LPNETDEV_FACE_GALLEY_INFO_S;

/**
* @struct tagNETDEVFaceDBImportNumInfo
* @brief 系统人脸库导入数量信息
* @attention
*/
typedef struct tagNETDEVFaceDBImportNumInfo
{
    UINT32  udwMaxNum;      /* 系统人脸库成员最大个数*/
    UINT32  udwImportSum;   /* 已导入人脸成员总数量*/
    UINT32  udwFaceDBNum;   /* 人脸库数量*/

    BYTE    byRes[128];     /* 保留字段  Reserved */
}NETDEV_FACE_DB_IMPORT_NUM_INFO_S, *LPNETDEV_FACE_DB_IMPORT_NUM_INFO_S;

/**
* @struct tagNETDEVFaceDBMemberImportInfo
* @brief 人脸库成员导入信息
* @attention
*/
typedef struct tagNETDEVFaceDBMemberImportInfo
{
    UINT32  udwFaceDBID;            /* 人脸库ID*/
    UINT32  udwFaceDBMemberNum;     /* 已导入成员数量*/

    BYTE    byRes[128];             /* 保留字段  Reserved */
}NETDEV_FACEDB_MEMBER_IMPORT_INFO_S, *LPNETDEV_FACEDB_MEMBER_IMPORT_INFO_S;

/**
 * @struct tagNETDEVModifyPasswordInfo
 * @brief用户密码
 * @attention 
 */
typedef struct tagNETDEVModifyPasswordInfo
{
    CHAR szUserName[NETDEV_LEN_260];    /* 用户名 */
    CHAR szNewPIN[NETDEV_LEN_256];      /* 用户新密码 */
    CHAR szCurrentPIN[NETDEV_LEN_256];  /* 用户原密码 */
    BYTE byRes[128];                    /* 保留字段 */
}NETDEV_MODIFY_PASSWORD_INFO_S,*LPNETDEV_MODIFY_PASSWORD_INFO_S;

/**
 * @enum tagNETDEVDevManageInfo
 * @brief 设备管理信息
 * @attention 无 None
 */
typedef struct tagNETDEVDevManageInfo
{
    CHAR    szSerailNum[NETDEV_LEN_64];     /* 序列号 */
    CHAR    szActiveCode[NETDEV_LEN_64];    /* 激活码 */
}NETDEV_DEV_MANAGE_INFO_S, *LPNETDEV_DEV_MANAGE_INFO_S;

/**
 * @struct tagNETDEVImagingEnhance
 * @brief 指定通道的图像增强参数 结构体定义    Device image settings Structure definition
 * @attention udwBrightness,udwContrast,udwSaturation,udwSharpness,udw2DNoiseReduce 参数取值范围：0-255    
              udwBrightness,udwContrast,udwSaturation,udwSharpness,udw2DNoiseReduce parameter range: 0-255
 */
typedef struct tagNETDEVImagingEnhance
{
    UINT32 udwBrightness;                 /* 亮度  Brightness */
    UINT32 udwContrast;                   /* 对比度  Contrast */
    UINT32 udwSaturation;                 /* 饱和度  Saturation */
    UINT32 udwSharpness;                  /* 锐度  Sharpness */
    UINT32 udwImageRotation;              /* 图像镜像模式 */
    UINT32 udw2DNoiseReduce;              /* 2D降噪 */
    UINT32 udw3DNoiseReduce;              /* 3D降噪 */
    BYTE  byRes[252];                     /* 保留字段  Reserved */
}NETDEV_IMAGE_ENHANCE_S, *LPNETDEV_IMAGE_ENHANCE_S;


/**
 * @struct tagNETDEVEnhanceCapabilitiesInfo
 * @brief 图像增强能力参数 结构体定义
 * @attention
 */
typedef struct tagNETDEVEnhanceCapabilitiesInfo
{
    UINT32 udwImageRotationModeNum;                                          /* 支持的图像镜像模式个数 */
    UINT32 udwImageRotationModeList[NETDEV_IMAGE_ROTATION_MODE_MAX_NUM];     /* 支持的图像镜像模式列表,参见枚举#NETDEV_IMAGE_ROTATION_MODE_E*/
    BOOL bSupportSharpness;                                                  /* 设备是否支持锐度，0,不支持，1,支持*/
    BOOL bSupport2DNoiseReduce;                                              /* 设备是否支持2D降噪，0,不支持，1,支持 */
    BOOL bSupport3DNoiseReduce;                                              /* 设备是否支持3D降噪，0,不支持，1,支持 */
    BYTE  byRes[512];                                                        /* 保留字段  Reserved */
}NETDEV_IMAGE_ENHANCE_CAP_INFO_S, *LPNETDEV_IMAGE_ENHANCE_CAP_INFO_S;

/**
 * @struct tagNETDEVFocusCapabilitiesInfo
 * @brief 对焦能力参数 （仅IPC支持） 结构体定义
 * @attention
 */
typedef struct tagNETDEVFocusCapabilitiesInfo 
{
    BOOL bSupportFocusCfg;                                                   /* 是否支持对焦参数的配置：0,不支持，1,支持*/
    UINT32 udwFocusModeNum;                                                  /* 支持的对焦模式个数*/
    UINT32 udwFocusModeList[NETDEV_FOCUS_MODE_MAX_NUM];                      /* 支持的对焦模式列表,参见枚举#NETDEV_FOCUS_MODEL_E*/
    UINT32 udwFocusSceneNum;                                                 /* 支持的对焦场景个数*/
    UINT32 udwFocusSceneList[NETDEV_FOCUS_SCENE_MAX_NUM];                    /* 支持的对焦场景列表,参见枚举#NETDEV_FOCUS_SCENE_E*/
    BYTE  byRes[512];                                                        /* 保留字段  Reserved */
}NETDEV_FOCUS_CAP_INFO_S, *LPNETDEV_FOCUS_CAP_INFO_S;

/**
 * @struct tagNETDEVWhiteBalanceCapabilitiesInfo
 * @brief 白平衡能力参数 （仅IPC支持） 结构体定义
 * @attention
 */
typedef struct tagNETDEVWhiteBalanceCapabilitiesInfo 
{
    UINT32 udwWhiteBalanceModeNum;                                           /* 支持的白平衡模式个数*/
    UINT32 audwWhiteBalanceModeList[NETDEV_WHITE_BALANCE_MODE_MAX_NUM];       /* 支持的白平衡模式信息列表,参见枚举#NETDEV_WHITE_BALANCE_MODE_E*/
    BYTE  byRes[512];                                                        /* 保留字段  Reserved */
}NETDEV_WHITE_BALANCE_CAP_INFO_S, *LPNETDEV_WHITE_BALANCE_CAP_INFO_S;

/**
 * @struct tagNETDEVLampInfo
 * @brief 补光灯信息 结构体定义
 * @attention
 */
typedef struct tagNETDEVLampInfo
{
    UINT32 udwLampType;                                             /* 补光灯类型 参加枚举NETDEV_LAMP_TYPE_E*/
    UINT32 udwLampCtrlModeListNum;                                  /* 补光灯支持的控制模式个数。*/
    UINT32 audwLampCtrlModeList[NETDEV_LAMP_CTRL_MODE_MAX_NUM];     /* 补光灯支持的控制模式。参见枚举#NETDEV_LAMP_CTRL_MODE_E*/
    BOOL   bSupportNearLampCfg;                                     /* 是否支持近光灯级别可配置：0：不支持 1：支持*/
    BOOL   bSupportMiddleLampCfg;                                   /* 是否支持中光灯级别可配置：0：不支持 1：支持*/
    BOOL   bSupportFarLampCfg;                                      /* 是否支持远光灯级别可配置：0：不支持 1：支持*/
    BOOL   bSupportSuperFarLampCfg;                                 /* 是否支持超远远灯级别可配置：0：不支持 1：支持*/
    BOOL   bSupportLaserAngleCfg;                                   /* 是否支持激光角度可配置：0：不支持 1：支持*/
    UINT32 udwLaserAngleMin;                                        /* 激光角度最小值，bSupportLaserAngleCfg为0时，此节点可选。。*/
    UINT32 udwLaserAngleMax;                                        /* 激光角度最大值，bSupportLaserAngleCfg为0时，此节点可选。*/
    BYTE   byRes[512];                                              /* 保留字段  Reserved */
}NETDEV_LAMP_INFO_S, *LPNETDEV_LAMP_INFO_S;

/**
 * @struct tagNETDEVLampCtrlCapabilitiesInfo
 * @brief 补光灯能力参数 （仅IPC支持） 结构体定义
 * @attention
 */
typedef struct tagNETDEVLampCtrlCapabilitiesInfo
{
    UINT32              udwLampNum;                                     /* 支持的补光灯类型个数，为0时表示设备不支持补光灯。*/
    NETDEV_LAMP_INFO_S  astLampInfos[NETDEV_LAMP_CTRL_TYPE_MAX_NUM];    /* 补光灯信息列表,补光灯信息列表，当LampNum为0时，该节点可选。*/
    BYTE                byRes[512];                                     /* 保留字段  Reserved */
}NETDEV_LAMPCTRL_CAP_INFO_S, *LPNETDEV_LAMPCTRL_CAP_INFO_S;

/**
 * @struct tagNETDEVShutterCapabilitiesInfo
 * @brief 快门能力集 结构体定义
 * @attention
 */
typedef struct tagNETDEVShutterCapabilitiesInfo
{
    BOOL   bSupportShutterTimeCfg;                                                  /* 是否支持快门时间配置：0：不支持 1：支持*/
    UINT32 udwShutterTimeUnit;                                                      /* 快门时间单位  0：微秒 1：秒*/
    UINT32 udwShutterTimeRangeNum;                                                  /* 支持的快门时间的取值的个数*/
    UINT32 audwShutterTimeRangeList[NETDEV_SHUTTER_TIME_RANGE_MAX_NUM];             /* 快门时间支持的取值列表 枚举参见#NETDEV_SHUTTER_TIME_RANGE_E*/
    BOOL   bSupportSlowShutterCfg;                                                  /* 是否支持慢快门可配置：0：不支持 1：支持*/
    UINT32 udwSlowShutterTimeRangeNum;                                              /* 支持的慢快门时间的取值的个数*/
    UINT32 audwSlowShutterTimeRangeList[NETDEV_SLOW_SHUTTER_TIME_RANGE_MAX_NUM];    /* 慢快门时间支持的取值列表 枚举参见#NETDEV_SHUTTER_TIME_RANGE_E。注意，慢快门时间支持的取值最快仅1/25*/
    BYTE   byRes[512];                                                              /* 保留字段  Reserved */
}NETDEV_SHUTTER_CAP_INFO_S, *LPNETDEV_SHUTTER_CAP_INFO_S;

/**
 * @struct tagNETDEVWideDynamicCapabilitiesInfo
 * @brief 宽动态能力集 结构体定义
 * @attention
 */
typedef struct tagNETDEVWideDynamicCapabilitiesInfo
{
    BOOL   bSupportWideDynamicCfg;                                              /* 是否支持宽动态可配置：0：不支持 1：支持*/
    UINT32 udwWideDynamicModeNum;                                               /* 支持的宽动态模式个数*/
    UINT32 audwWideDynamicModeList[NETDEV_SHUTTER_TIME_RANGE_MAX_NUM];          /* 宽动态模式列表 枚举参见#NETDEV_WIDE_DYNAMIC_MODE_E*/
    BYTE   byRes[512];                                                          /* 保留字段  Reserved */
}NETDEV_WIDE_DYNAMIC_CAP_INFO_S, *LPNETDEV_WIDE_DYNAMIC_CAP_INFO_S;

/**
 * @struct tagNETDEVDayNightCapabilitiesInfo
 * @brief 昼夜模式能力集 结构体定义
 * @attention
 */
typedef struct tagNETDEVDayNightCapabilitiesInfo
{
    BOOL   bSupportDayNightCfg;                                              /* 是否支持昼夜模式可配置：0：不支持 1：支持*/
    UINT32 udwDayNightModeNum;                                               /* 支持昼夜模式类型个数*/
    UINT32 audwDayNightModeList[NETDEV_DAY_NIGHT_MODE_MAX_NUM];              /* 昼夜模式类型列表 枚举参见#NETDEV_DAY_NIGHT_MODE_E*/
    BOOL   bSupportSensibilityCfg;                                           /* 是否支持昼夜模式灵敏度可配置：0：不支持 1：支持*/
    BOOL   bSupportSwitchingCfg;                                             /* 是否支持昼夜模式切换时间可配置：0：不支持 1：支持*/
    BYTE   byRes[512];                                                       /* 保留字段  Reserved */
}NETDEV_DAY_NIGHT_CAP_INFO_S, *LPNETDEV_DAY_NIGHT_CAP_INFO_S;


/**
 * @struct tagNETDEVExposureCapabilitiesInfo
 * @brief 曝光能力参数（仅IPC支持） 结构体定义
 * @attention
 */
typedef struct tagNETDEVExposureCapabilitiesInfo
{
    BOOL   bSupportCompensationCfg;                                          /* 是否支持曝光补偿可配置。0：不支持 1：支持*/
    UINT32 udwExposureModeNum;                                               /* 支持的曝光模式个数。*/
    UINT32 audwExposureModeList[NETDEV_EXPOSURE_MODE_MAX_NUM];               /* 支持的曝光模式。参见枚举#NETDEV_EXPOSURE_MODE_E*/
    BOOL   bSupportIrisCfg;                                                  /* 是否支持光圈可配置。0：不支持 1：支持*/
    UINT32 udwIrisRangeNum;                                                  /* 支持的光圈取值个数。*/
    UINT32 audwIrisRangeList[NETDEV_IRIS_RANGE_MAX_NUM];                     /* 光圈支持的取值:160，200，240，280，340，400，480，560，680，800，960，1100，1400,1600,2200 当IrisRangeNum为0时，该节点可选。*/
    UINT32 udwMinGain;                                                       /* 支持的增益最小值。*/
    UINT32 udwMaxGain;                                                       /* 支持的增益最大值。*/
    BOOL   bSupportHLCCfg;                                                   /* 是否支持强光抑制灵敏度可配置：0：不支持 1：支持*/
    BOOL   bSupportMeteringCfg;                                              /* 是否支持测光控制可配置：0：不支持 1：支持*/
    BOOL   bSupportSuperFarLampCfg;                                          /* 是否支持超远远灯级别可配置：0：不支持 1：支持*/
    UINT32 udwMeteringModeNum;                                               /* 支持的测光控制模式个数。*/
    UINT32 audwMeteringModeList[NETDEV_METERING_MODE_MAX_NUM];               /* 测光控制模式 参见枚举#NETDEV_METERING_MODE_E*/
    NETDEV_SHUTTER_CAP_INFO_S  stShutterCapInfo;                             /* 快门能力信息*/
    NETDEV_WIDE_DYNAMIC_CAP_INFO_S  stWideDynamicCapInfo;                    /* 宽动态能力信息*/
    NETDEV_DAY_NIGHT_CAP_INFO_S  stDayNightCapInfo;                          /* 昼夜模式能力信息*/
    BYTE  byRes[512];                                                        /* 保留字段  Reserved */
}NETDEV_EXPOSURE_CAP_INFO_S, *LPNETDEV_EXPOSURE_CAP_INFO_S;

/**
 * @struct tagNETDEVImageCapabilities
 * @brief 指定通道的图像参数能力集 结构体定义    Device image Capabilities Structure definition
 * @attention
 */
typedef struct tagNETDEVImageCapabilities
{
    BOOL bSupportCfg;                                                       /* 设备是否支持图像参数配置 0,不支持，1,支持 */
    INT32 udwImageRotationModeNum;                                          /* 支持的图像镜像模式个数 */
    INT32 udwImageRotationModeList[NETDEV_IMAGE_ROTATION_MODE_MAX_NUM];     /* 支持的图像镜像模式列表,参见枚举#NETDEV_IMAGE_ROTATION_MODE_E*/
    BOOL bSupportSharpness;                                                 /* 设备是否支持锐度，0,不支持，1,支持*/
    BOOL bSupport2DNoiseReduce;                                             /* 设备是否支持2D降噪，0,不支持，1,支持 */
    BOOL bSupport3DNoiseReduce;                                             /* 设备是否支持3D降噪，0,不支持，1,支持 */
    BOOL bSupportIlluminationCfg;                                           /* 设备是否支持获取相对照度等级值(仅IPC支持) 0,不支持，1,支持 */
    NETDEV_FOCUS_CAP_INFO_S stFocusCapInfo;                                 /* 对焦能力参数,仅IPC支持。*/
    NETDEV_LAMPCTRL_CAP_INFO_S stLampCtrlCapInfo;                           /* 补光灯能力参数,仅IPC支持。*/
    NETDEV_EXPOSURE_CAP_INFO_S stExposureCapInfo;                           /* 曝光能力参数,仅IPC支持。*/
    NETDEV_WHITE_BALANCE_CAP_INFO_S  stWhiteBalanceCapInfo;                 /* 白平衡能力信息,仅IPC支持*/
    BYTE  byRes[512];                                                       /* 保留字段  Reserved */
}NETDEV_IMAGE_CAP_S, *LPNETDEV_IMAGE_CAP_S;


/**
 * @struct tagNETDEVIrisInfo
 * @brief  光圈信息  结构体定义    IrisInfo
 * @attention
 */
typedef struct tagNETDEVIrisInfo
{
    UINT32 udwIris;         /* 光圈,在光圈优先、手动曝光模式下可选。光圈支持的取值:160， 200， 240， 280， 340， 400， 480， 560， 680， 800， 960， 1100，1400,  1600,  2200*/
    UINT32 udwMinIris;      /* 最小光圈值 自定义曝光模式下可用，枚举同 Iris能力集所描述，不得大于光圈最大值。图像能力集支持该功能，此字段必选。*/
    UINT32 udwMaxIris;      /* 最大光圈值 自定义曝光模式下可用，枚举同 Iris能力集所描述，不得小于光圈最小值。图像能力集支持该功能，此字段必选。*/
    BYTE  byRes[128];       /* 保留字段  Reserved */
}NETDEV_IRIS_INFO_S, *LPNETDEV_IRIS_INFO_S;


/**
 * @struct tagNETDEVShutterInfo
 * @brief  快门信息  结构体定义    ShutterInfo
 * @attention
 */
typedef struct tagNETDEVShutterInfo
{
    UINT32 udwShutterTime;                  /* 快门时间 枚举见#NETDEV_SHUTTER_TIME_RANGE_E,快门时间单位  0：微秒 1：秒*/
    UINT32 udwMinShutterTime;               /* 快门时间最小值 MinShutter 枚举见#NETDEV_SHUTTER_TIME_RANGE_E*/
    UINT32 udwMaxShutterTime;               /* 快门时间最大值 MaxShutter 枚举见#NETDEV_SHUTTER_TIME_RANGE_E*/
    UINT32 udwIsEnableSlowShutter;          /* 慢快门使能。非光圈优先模式下可用：0：不使能  1：使能*/
    UINT32 udwSlowestShutter;               /* 最慢慢快门,慢快门使能后可用。*/
    BYTE   byRes[128];                      /* 保留字段  Reserved */
}NETDEV_SHUTTER_INFO_S, *LPNETDEV_SHUTTER_INFO_S;

/**
 * @struct tagNETDEVGainInfo
 * @brief  增益信息  结构体定义    GainInfo
 * @attention
 */
typedef struct tagNETDEVGainInfo
{
    UINT32 udwGain;         /* 增益值（单位:db）手动曝光模式下可用。范围[1,100]*/
    UINT32 udwMinGain;      /* 增益最小值 ,自定义曝光模式下可用，不得大于增益最大值。最小值为1*/
    UINT32 udwMaxGain;      /* 增益最大值 , 自定义曝光模式下可用，不得小于增益最小值。最大值为100*/
    BYTE  byRes[128];       /* 保留字段  Reserved */
}NETDEV_GAIN_INFO_S, *LPNETDEV_GAIN_INFO_S;

/**
 * @struct tagNETDEVWideDynamicInfo
 * @brief  宽动态信息  结构体定义    WideDynamicInfo
 * @attention
 */
typedef struct tagNETDEVWideDynamicInfo
{
    UINT32 udwWideDynamicMode;              /* 宽动态模式 WideDynamicMode 枚举详见#NETDEV_WIDE_DYNAMIC_MODE_E*/
    UINT32 udwWideDynamicLevel;             /* 宽动态级别配置，宽动态开启且在曝光模式为自动模式、自定义、快门优先、室内50HZ、室内60HZ、低拖影下可用。范围[1, 9]。*/
    UINT32 udwOpenSensitivity;              /* 宽动态开启的灵敏度。宽动态模式为自动下可用。范围[1, 9]。*/
    UINT32 udwCloseSensitivity;             /* 宽动态关闭的灵敏度。宽动态模式为自动下可用。范围[1, 9]。*/
    UINT32 udwAntiFlicker;                    /* 宽动态条纹抑制：0：关闭 1：开启该功能开启后，可消除图像中的条纹效应。*/
    BYTE   byRes[128];                      /* 保留字段  Reserved */
}NETDEV_WIDE_DYNAMIC_INFO_S, *LPNETDEV_WIDE_DYNAMIC_INFO_S;

/**
 * @struct tagNETDEVAreaTopLeft
 * @brief  左上角区域  结构体定义    Upper left Area
 * @attention
 */
typedef struct tagNETDEVAreaTopLeft
{
    UINT32  dwTopLeftX;     /* 左上角横坐标(比例)：区域测光模式范围: [0, 100]。Upper left corner X [0, 100]  */
    UINT32  dwTopLeftY;     /* 左上角纵坐标(比例)：区域测光模式范围: [0, 100]。Upper left corner Y [0, 100]  */
    BYTE    byRes[128];     /* 保留字段  Reserved */
}NETDEV_AREA_TOP_LEFT_S, *LPNETDEV_AREA_TOP_LEFT_S;

/**
 * @struct tagNETDEVAreaBotRight
 * @brief  右下角区域  结构体定义    Lower right Area
 * @attention
 */
typedef struct tagNETDEVAreaBotRight
{
    UINT32  dwBottomRightX;     /* 左上角横坐标(比例)：区域测光模式范围: [0, 100]  Lower right corner x [0, 100] */
    UINT32  dwBottomRightY;     /* 左上角纵坐标(比例)：区域测光模式范围: [0, 100]  Lower right corner y [0, 100] */
    BYTE    byRes[128];         /* 保留字段  Reserved */
}NETDEV_AREA_BOT_RIGHT_S, *LPNETDEV_AREA_BOT_RIGHT_S;

/**
 * @struct tagNETDEVMeteringArea
 * @brief  测光区域  结构体定义   MeteringArea
 * @attention
 */
typedef struct tagNETDEVMeteringArea
{
    NETDEV_AREA_TOP_LEFT_S    stAreaTopLeft;           /* 左上角区域  结构体见#NETDEV_AREA_TOP_LEFT_S*/
    NETDEV_AREA_BOT_RIGHT_S   stAreaBotRight;          /* 右下角区域  结构体见#NETDEV_AREA_BOT_RIGHT_S*/
    BYTE  byRes[128];                                  /* 保留字段  Reserved */
}NETDEV_METERING_AREA_S, *LPNETDEV_METERING_AREA_S;

/**
 * @struct tagNETDEVMeteringInfo
 * @brief  测光信息  结构体定义    MeteringInfo
 * @attention
 */
typedef struct tagNETDEVMeteringInfo
{
    UINT32 udwMeteringMode;                 /* 测光控制模式,此字段在非手动曝光模式下可用。枚举详见#NETDEV_DAY_NIGHT_MODE_E*/
    UINT32 udwRefBrightness;                /* 人脸亮度。人脸测光模式下可用。范围：[0, 100]。*/
    UINT32 udwHoldTime;                     /* 最短持续时间。人脸测光模式下可用。单位：分钟。范围：[0, 60]。*/
    NETDEV_METERING_AREA_S stMeteringArea;  /* 测光区域 ,在测光模式为区域测光及点测光时，此字段可用*/
    BYTE  byRes[128];                       /* 保留字段  Reserved */
}NETDEV_METERING_INFO_S, *LPNETDEV_METERING_INFO_S;

/**
 * @struct tagNETDEVDayNightInfo
 * @brief  昼夜模式信息  结构体定义    MeteringInfo
 * @attention
 */
typedef struct tagNETDEVDayNightInfo
{
    UINT32 udwDayNightMode;                 /* 昼夜模式类型 DayNightMode 枚举参见#NETDEV_DAY_NIGHT_MODE_E*/
    UINT32 udwDayNightSensitivity;          /* 昼夜模式灵敏度 DayNightSensitivity 在昼夜模式为自动模式下可用，范围[0, 9]。若图像能力支持该功能，此字段必选。*/
    UINT32 udwDayNightTime;                 /* 昼夜模式切换时间，在昼夜模式为自动模式下可用。范围[3, 120]。单位秒。若图像能力支持该功能，此字段必选。*/
    BYTE  byRes[128];                       /* 保留字段  Reserved */
}NETDEV_DAY_NIGHT_INFO_S, *LPNETDEV_DAY_NIGHT_INFO_S;

/**
 * @struct tagNETDEVImagingExposure
 * @brief 图像曝光参数 结构体定义    Device image Exposure Structure definition
 * @attention
 */
typedef struct tagNETDEVImagingExposure
{
    UINT32                      udwMode;                /* 曝光模式  Exposure Mode 枚举详见#NETDEV_EXPOSURE_MODE_E*/
    INT32                       dwCompensationLevel;    /* 曝光补偿级别,曝光模式为非手动曝光模式时可用。范围[-100,100].图像能力集支持该功能，此字段必选 */
    UINT32                      udwHLCSensitivity;      /* 强光抑制灵敏度，当前场景为道路强光抑制及园区强光抑制时可用,范围[1,9]。 图像能力集支持该功能，此字段必选 */
    NETDEV_IRIS_INFO_S          stIrisInfo;             /* 光圈信息。图像能力集支持该功能，此字段必选。*/
    NETDEV_SHUTTER_INFO_S       stShutterInfo;          /* 快门信息。图像能力集支持该功能，此字段必选。*/
    NETDEV_GAIN_INFO_S          stGainInfo;             /* 增益信息。*/
    NETDEV_WIDE_DYNAMIC_INFO_S  stWideDynamicInfo;      /* 宽动态信息。图像能力集支持该功能，此字段必选。*/
    NETDEV_METERING_INFO_S      stMeteringInfo;         /* 测光信息。当前场景不是道路强光抑制及园区强光抑制时可用。图像能力集支持该功能，此字段必选。*/
    NETDEV_DAY_NIGHT_INFO_S     stDayNightInfo;         /* 昼夜模式信息。图像能力集支持该功能，此字段必选。*/
    BYTE                        byRes[256];             /* 保留字段  Reserved */
}NETDEV_IMAGE_EXPOSURE_S, *LPNETDEV_IMAGE_EXPOSURE_S;


/**
 * @struct tagNETDEVLampCtrlInfo
 * @brief  补光灯信息
 * @attention
 */
typedef struct tagNETDEVLampCtrlInfo
{
    UINT32 udwEnabled;          /* 补光灯使能开关：0：关闭 1：开启 */
    UINT32 udwType;             /* 补光灯类型 详见枚举类型 #NETDEV_LAMP_TYPE_E*/
    UINT32 udwMode;             /* 补光灯控制模式 详见枚举类型 #NETDEV_LAMP_CTRL_MODE_E*/
    UINT32 udwNearLevel;        /* 近光灯级别,在红外控制模式为手动控制及手动-强制开启模式下,此字段可用。补光灯能力集支持该功能，此字段必选。范围[0-1000]。级别越高，补光灯强度越大。*/
    UINT32 udwMiddleLevel;      /* 中光灯级别,在红外控制模式为手动控制及手动-强制开启模式下可用。补光灯能力集支持该功能，此字段必选。范围[0-1000]。级别越高，补光灯强度越大。*/
    UINT32 udwFarLevel;         /* 远光灯级别,在红外控制模式为手动控制及手动-强制开启模式下可用。补光灯能力集支持该功能，此字段必选。范围[0-1000]。级别越高，补光灯强度越大。*/
    UINT32 udwSuperFarLevel;    /* 超远光灯级别,在红外控制模式为手动控制及手动-强制开启模式下可用。补光灯能力集支持该功能，此字段必选。范围[0-1000]。级别越高，补光灯强度越大。*/
    UINT32 udwLaserAngle;       /* 激光角度，当补光灯类型为激光器且，在红外控制模式为手动控制及手动-强制开启模式下可用。补光灯能力集支持该功能，此字段必选。范围见补光灯能力集。激光角度越小能量越集中，角度越大能量越分散。*/
    BYTE  byRes[256];           /* 保留字段  Reserved */
}NETDEV_LAMP_CTRL_INFO_S, *LPNETDEV_LAMP_CTRL_INFO_S;

/**
 * @struct tagNETDEVWhiteBalanceInfo
 * @brief  白平衡信息
 * @attention
 */
typedef struct tagNETDEVWhiteBalanceInfo
{
    UINT32 udwMode;             /* 白平衡模式 详见枚举类型 #NETDEV_WHITE_BALANCE_MODE_E*/
    UINT32 udwRedOffset;        /* Red偏移值，只有在Mode为[1,5,8]微调模式下可配置*/
    UINT32 udwBlueOffset;       /* Blue偏移值，只有在Mode为[1,5,8]微调模式下可配置*/
    BYTE  byRes[256];           /* 保留字段  Reserved */
}NETDEV_WHITE_BALANCE_INFO_S, *LPNETDEV_WHITE_BALANCE_INFO_S;


/* 源端媒体流信息 */
typedef struct tagNETDEVXWSteamInfoSrc
{
    UINT32  udwVideoInChlID;                /* 视频源ID */
    UINT32  udwStreamID;                    /* 媒体流序号 */
    CHAR    szIPAddr[NETDEV_IPV4_LEN_MAX];  /* 视频源IP地址 */
    UINT32  udwPort;                        /* 端口号 */
    BYTE    byRes[64];                      /* 保留字段 */
}NETDEV_XW_STREAM_INFO_SRC_S, *LPNETDEV_XW_STREAM_INFO_SRC_S;

/* 目的端媒体流信息 */
typedef struct tagNETDEVXWSteamInfoDest
{
    UINT32  udwWndID;                       /* 窗口ID */
    UINT32  udwPaneID;                      /* 分屏序号 */
    CHAR    szIPAddr[NETDEV_IPV4_LEN_MAX];  /* 目的端IP地址 */
    UINT32  udwPort;                        /* 端口号 */
    BYTE    byRes[64];                      /* 保留字段 */
}NETDEV_XW_STREAM_INFO_DEST_S, *LPNETDEV_XW_STREAM_INFO_DEST_S;

/* 媒体流具体信息 */
typedef struct tagNETDEVXWStreamInfoMsg
{
    UINT32                  udwTransProtocol;           /* 传输协议 NETDEV_LAPI_TRANS_PROTOCOL_E */
    UINT32                  udwIsMulticast;             /* 单组播 NETDEV_STREAM_TYPE_E */
    NETDEV_XW_RESOLUTION_S  stResolution;               /* 分辨率 */
    UINT32                  udwFrame;                   /* 帧率 */
    UINT32                  udwEncodeFormat;            /* 编码格式 NETDEV_VIDEOENCODING_E */
    UINT32                  udwIsInvalidAfterReboot;    /* 是否需要恢复 0 "XW"设备不负责恢复，1 "XW"设备恢复*/
    BYTE                    byRes[64];                  /* 保留字段 */
}NETDEV_XW_STREAM_INFO_MSG_S, *LPNETDEV_XW_STREAM_INFO_MSG_S;

/* 流业务的详细信息 */
typedef struct tagNETDEVXWSteamInfo
{
    UINT32                          udwTaskNo;          /* 业务号 */
    UINT32                          udwType;            /* 业务类型 NETDEV_XW_VIDEO_TYPE_E */
    NETDEV_XW_STREAM_INFO_SRC_S     stStreamInfoSrc;    /* 源端媒体流信息 */
    NETDEV_XW_STREAM_INFO_DEST_S    stStreamInfoDest;   /* 目的端媒体流信息 */
    NETDEV_XW_STREAM_INFO_MSG_S     stStreamInfoMsg;    /* 媒体流具体信息 */
}NETDEV_XW_STREAM_INFO_S, *LPNETDEV_XW_STREAM_INFO_S;



/**
 * @enum tagNETDEVXWAudioOutInfoList
 * @brief 音频输出通道信息列表
 * @attention 无 None
 */
typedef struct tagNETDEVXWAudioOutInfoList
{
    UINT32                      udwAudioSize;                           /* 音频通道数量 */
    NETDEV_XW_AUDIO_OUT_INFO_S  stAudioIDList[NETDEV_XW_AUDIO_NUM];     /* 音频输出通道信息 */
    BYTE                        byRes[128];                             /* 预留字段 */
}NETDEV_XW_AUDIO_OUT_INFO_LIST_S, *LPNETDEV_XW_AUDIO_OUT_INFO_LIST_S;


typedef struct tagNETDEVPassiveDecodeCtrl
{
    UINT32    udwSize;
    UINT32    dwPlayCmd;        /* 播放命令 见文件播放命令 */
    UINT32    dwCmdParam;       /* 播放命令参数 */
    BYTE      byRes[16];        /* 保留字段 */
}NETDEV_PASSIVE_DECODE_CTRL_S,*LPNETDEV_PASSIVE_DECODE_CTRL_S;


/* 轮询状态列表信息 */
typedef struct tagNETDEVXWSequenceStatus
{
    UINT32  udwWndID;       /* 窗口ID */
    UINT32  udwStatus;      /* 轮巡状态 NETDEV_XW_SEQUENCE_STATUS_E */
    BYTE    byRes[64];      /* 保留字段 */
}NETDEV_XW_SEQUENCE_STATUS_S, *LPNETDEV_XW_SEQUENCE_STATUS_S;


/* 轮巡资源基本信息 */
typedef struct tagNETDEVXWSequenceResourceBaseInfo
{
    UINT32  udwID;                          /* 轮巡资源的唯一ID */
    CHAR    szName[NETDEV_LEN_64];          /* 轮巡资源名称 */
    CHAR    szDescription[NETDEV_LEN_256];  /* 轮巡资源描述信息 */
    BOOL    bEnabled;                       /* 轮巡资源是否启用 */
    BYTE    byRes[128];                      /* 保留字段 */
}NETDEV_XW_SEQUENCE_RES_BASE_INFO_S, *LPNETDEV_XW_SEQUENCE_RES_BASE_INFO_S;

/* 轮巡视频源信息 */
typedef struct tagNETDEVXWSeqVideoSrcInfo
{
    UINT32                              udwVideoSrcIndex;               /* 视频源的序号 */
    NETDEV_XW_VIDEO_SOURCE_BASE_S       stVideoSrcBaseInfo;             /* 视频源基本信息 */
    UINT32                              udwPresetIndex;                 /* 云台预置位序号，只有是轮巡时才需要配置 */
    BYTE                                byRes[64];                      /* 保留字段 */
}NETDEV_XW_SEQ_RES_VIDEO_SRC_INFO_S, *LPNETDEV_XW_SEQ_RES_VIDEO_SRC_INFO_S;

/* 轮巡资源详细信息
轮巡间隔时间，单位：秒，只有是轮巡时才需要配置当前只支持轮巡间隔配置成一样的，即只会取第一个摄像机的轮巡间隔做为整个巡的时间间隔
*/
typedef struct tagNETDEVXWSequenceResDeTailInfo
{
    NETDEV_XW_SEQUENCE_RES_BASE_INFO_S      stSeqResBaseInfo;   /* 轮巡资源基本信息 */
    UINT32                                  udwIntervalTime;    /* 轮巡间隔时间，单位：秒 */
    UINT32                                  udwVideoSrcNum;     /* 组轮巡视频源个数 */
    LPNETDEV_XW_SEQ_RES_VIDEO_SRC_INFO_S    pstVideoInList;     /* 组轮巡视频源列表信息,内存由调用者维护, 规格参照能力集接口获取 */
    UINT32                                  udwManageType;      /* 资源管理类型，参见枚举NETDEV_XW_MANAGE_TYPE_E  */
    BYTE                                    byRes[124];         /* 保留字段 */
}NETDEV_XW_SEQUENCE_RES_DETAIL_INFO_S, *LPNETDEV_XW_SEQUENCE_RES_DETAIL_INFO_S;

/* 轮巡播放控制信息 */
typedef struct tagNETDEVXWSequencePlayControlInfo
{
    UINT32  udwSequenceResBindID;   /* 轮巡资源绑定信息ID */
    UINT32  udwOperation;           /* 操作命令类型 参见枚举NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_E */
    BYTE    byRes[128];             /* 保留字段 */
}NETDEV_XW_SEQUENCE_PLAY_CTRL_INFO_S, *LPNETDEV_XW_SEQUENCE_PLAY_CTRL_INFO_S;

/* 轮巡播放间隔信息 */
typedef struct tagNETDEVXWSequenceIntervalInfo
{
    UINT32  udwSequenceResBindID;   /* 轮巡资源绑定信息ID */
    UINT32  udwIntervalTime;        /* 播放间隔 单位：秒 */
    BYTE    byRes[128];             /* 保留字段 */
}NETDEV_XW_SEQUENCE_INTERVAL_INFO_S, *LPNETDEV_XW_SEQUENCE_INTERVAL_INFO_S;


/* 场景计划定时切换模式信息 */
typedef struct tagNETDEVXWScenesPlanTimerInfo
{
    UINT32  udwIntervalTime;        /* 时间间隔 单位：秒 */
    UINT32  udwSceneNum;            /* 场景个数 */
    UINT32* pudwSceneIDList;        /* 场景ID列表，内存由用户维护 */
    BYTE    byRes[64];              /* 保留字段 */
}NETDEV_XW_SCENES_PLAN_TIMER_INFO_S, *LPNETDEV_XW_SCENES_PLAN_TIMER_INFO_S;

/* 24小时时间表配置信息 */
typedef struct tagNETDEVXWTimeTableInfo
{
    UINT32  udwSceneID;                     /* 场景ID */
    CHAR    szStartTime[NETDEV_LEN_16];     /* 启动时间 hh:mm:ss */
    BYTE    byRes[64];                      /* 保留字段 */
}NETDEV_XW_TIME_TABLE_INFO_S, *LPNETDEV_XW_TIME_TABLE_INFO_S;

/* 场景计划时间表模式信息,24小时计划表 */
typedef struct tagNETDEVXWScenesPlanTimeTableInfo
{
    UINT32                          udwTimePeriodNum;               /* 时间分段个数 */
    LPNETDEV_XW_TIME_TABLE_INFO_S   pstTimeTableList;               /* 计划时间表信息，内存由用户维护，大小由udwTimePeriodNum指定 */
    BYTE                            byRes[64];                      /* 保留字段 */
}NETDEV_XW_SCENES_PLAN_TIME_TABLE_INFO_S, *LPNETDEV_XW_SCENES_PLAN_TIME_TABLE_INFO_S;

/* 场景轮巡计划基本信息 */
typedef struct tagNETDEVXWScenesPlanInfo
{
    UINT32                                      udwID;                          /* 计划ID */
    CHAR                                        szName[NETDEV_LEN_64];          /* 计划名称 */
    CHAR                                        szDescription[NETDEV_LEN_256];  /* 计划描述信息 */
    UINT32                                      udwStatus;                      /* 计划状态 参见NETDEV_XW_SEQUENCE_RES_STATUS_E */
    UINT32                                      udwMode;                        /* 计划方式 参见NETDEV_XW_SCENES_PLAN_MODE_E */
    NETDEV_XW_SCENES_PLAN_TIMER_INFO_S          stTimerInfo;                    /* 定时切换模式信息 */
    NETDEV_XW_SCENES_PLAN_TIME_TABLE_INFO_S     stTimeTableInfo;                /* 时间表模式切换信息 */
    BYTE                                        byRes[128];                     /* 保留字段 */
}NETDEV_XW_SCENES_PLAN_INFO_S, *LPNETDEV_XW_SCENES_PLAN_INFO_S;

/* 场景轮巡计划播放控制信息 */
typedef struct tagNETDEVXWScenesSeqPlanPlayCtrlInfo
{
    UINT32  udwScenesSeqPlanID;     /* 场景轮巡计划ID */
    UINT32  udwOperation;           /* 操作命令类型 参见枚举NETDEV_XW_SEQUENCE_PLAY_CTRL_CMD_E */
    BYTE    byRes[128];             /* 保留字段 */
}NETDEV_XW_SCENES_PLAN_PLAY_CTRL_INFO_S, *LPNETDEV_XW_SCENES_PLAN_PLAY_CTRL_INFO_S;

/**
 * @struct tagNETDEVDevFaceCapInfo
 * @brief 人脸识别能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVDevFaceCapInfo
{
    BOOL   bIsFaceRecognitionSupported;     /* 是否支持人脸识别能力 0不支持 1支持 */
    BYTE   byRes[255];                      /* 保留字段 */
}NETDEV_DEV_FACE_CAP_INFO_S, *LPNETDEV_DEV_FACE_CAP_INFO_S;


/**
 * @struct tagNETDEVCIQuotaChannelInfoList
 * @brief 硬盘容量策略  
 * @attention 无None
 */
typedef struct tagNETDEVCIQuotaChannelInfoList
{
    UINT32 udwNums;                         /* 复制的视频输入通道数目*/
    UINT32 audwChannels[NETDEV_LEN_1024];      /*复制的视频输入通道ID列表*/

}NETDEV_QUOTA_CHANNE_INFO_S,*LPNETDEV_QUOTA_CHANNE_INFO_S;

/**
 * @struct tagNETDEVCISetQuotaInfo
 * @brief 硬盘容量策略    
 * @attention 无None
 */
typedef struct tagNETDEVCISetQuotaInfo
{
    UINT32 udwRecordQuota;                  /* 通道录像配额容量(GB)*/
    UINT32 udwPictureQuota;                 /*通道抓图配额容量(GB)*/
    UINT32 udwGroupID;                      /*盘组ID号*/
    NETDEV_QUOTA_CHANNE_INFO_S stCopyTo;    /*复制的视频通道列表*/
}NETDEV_SET_QUOTA_INFO_S,*LPNETDEV_SET_QUOTA_INFO_S;

/**
 * @struct tagNETDEVCIGetQuotainolist
 * @brief 硬盘容量策略  
 * @attention 无None
 */
typedef struct tagNETDEVCIGetQuotaInfo
{
    UINT32 udwChannelID;                    /* 通道ID*/  
    CHAR   szChannelName[NETDEV_LEN_64];    /* 通道名称 */
    CHAR   szDeviceName[NETDEV_LEN_64];     /* 设备名称 */
    UINT32 udwRecordQuota;                  /* 通道录像配额容量(GB)*/       
    UINT32 udwPictureQuota;                 /*通道抓图配额容量(GB)*/
    UINT32 udwGroupID;                      /*盘组ID号*/
    UINT32 udwOrgID;                        /*组织ID号*/
}NETDEV_QUOTA_INFO_S,*LPNETDEV_QUOTA_INFO_S;

/**
 * @struct tagNETDEVCIGetQuotainolist
 * @brief 硬盘容量策略    
 * @attention 无None
 */
typedef struct tagNETDEVCIGetQuotainolist
{
    UINT32                  udwNums;                        /* 配额信息总数*/
    NETDEV_QUOTA_INFO_S     astQuotas[NETDEV_LEN_1024];     /* 配额信息列表*/
}NETDEV_GET_QUOTA_INFOLIST_S,*LPNETDEV_GET_QUOTA_INFOLIST_S;

/**
* @enum tagNETDEVRAIDStatus
* @brief 阵列状态信息
* @attention 
*/
typedef struct tagNETDEVRAIDStatus
{
    BOOL    bEnabled;                   /* 阵列状态使能 */
    BYTE    byRes[128];                 /* 保留字节 */
}NETDEV_RAID_STATUS_S, *LPNETDEV_RAID_STATUS_S;

/**
 * @struct tagNETDEVHDDInfo
 * @brief 硬盘信息 HDD info
 * @attention 无 None
 */
typedef struct tagNETDEVHDDInfo
{
    UINT32  udwID;                          /* 磁盘编号 */
    UINT32  udwType;                        /* 磁盘类型 参见枚举#NETDEV_HDD_TYPE_E */
    UINT32  udwWorkMode;                    /* 磁盘工作模式 参见枚举#NETDEV_HDD_WORK_MODE_E */
    UINT32  udwTotalCapacity;               /* 硬盘总容量(MB) Total Capacity */
    CHAR    szRAIDName[NETDEV_LEN_64];      /* 阵列名称 */
    UINT32  udwStatus;                      /* 磁盘状态 参见枚举#NETDEV_HDD_STATUS_E */
    CHAR    szManufacturer[NETDEV_LEN_64];  /* 厂商名称 */
    BYTE    byRes[128];                     /* 保留字节 */
}NETDEV_HDD_INFO_S,*LPNETDEV_HDD_INFO_S;

/**
 * @struct tagNETDEVHDDInfoList
 * @brief 磁盘信息列表 Disk info list
 * @attention 无 None
 */
typedef struct tagNETDEVHDDInfoList
{
    INT32               dwSize;                             /* 硬盘个数 Disk number */
    NETDEV_HDD_INFO_S   astHDDInfo[NETDEV_LEN_32];          /* 硬盘信息 Disk info */
    BYTE                byRes[128];                         /* 保留字节 */
}NETDEV_HDD_INFO_LIST_S,*LPNETDEV_HDD_INFO_LIST_S;

/**
 * @struct tagNETDEVStorageContainerInfo
 * @brief 存储容器信息 Storage Container info
 * @attention 无 None
 */
typedef struct tagNETDEVStorageContainerInfo
{
    UINT32  udwID;                              /* 磁盘编号 */
    UINT32  udwRemainCapacity;                  /* 存储容器剩余容量(MB) */
    UINT32  udwTotalCapacity;                   /* 存储容器总容量(MB) */
    CHAR    szManufacturer[NETDEV_LEN_64];      /* 厂商名称 */
    UINT32  udwStatus;                          /* 存储容器状态 参见枚举#NETDEV_STORAGE_CONTAINER_STATUS_E */
    UINT32  udwProperty;                        /* 存储盘属性,当udwStatus为0时无效 参见枚举#NETDEV_STORAGE_CONTAINER_PROPERTY_E */
    UINT32  udwFormatProgress;                  /* 格式化进度，百分比 */
    UINT32  udwGroupID;                         /* 盘组序号 */
    BYTE    byRes[128];                         /* 保留字节 */
}NETDEV_STORAGE_CONTAINER_INFO_S,*LPNETDEV_STORAGE_CONTAINER_INFO_S;

/**
 * @struct tagNETDEVExtendStorageContainerInfo
 * @brief 扩展存储容器信息 extend Storage Container info
 * @attention 无 None
 */
typedef struct tagNETDEVExtendStorageContainerInfo
{
    UINT32  udwID;                              /* 磁盘编号 */
    UINT32  udwRemainCapacity;                  /* 存储容器剩余容量(MB) */
    UINT32  udwTotalCapacity;                   /* 存储容器总容量(MB) */
    UINT32  udwAddressType;                     /* IP地址类型,参见枚举#NETDEV_ADDR_TYPE_E */
    CHAR    szIPAddress[NETDEV_LEN_64];         /* 服务器IP地址 */
    CHAR    szPath[NETDEV_LEN_256];             /* NAS服务器存储路径 */
    UINT32  udwUsageType;                       /* 用途,参见枚举#NETDEV_STORAGE_CONTAINER_USAGE_TYPE_E */
    UINT32  udwStatus;                          /* 存储容器状态 参见枚举#NETDEV_STORAGE_CONTAINER_STATUS_E */
    UINT32  udwProperty;                        /* 存储盘属性,当udwStatus为0时无效 参见枚举#NETDEV_STORAGE_CONTAINER_PROPERTY_E */
    UINT32  udwFormatProgress;                  /* 格式化进度，百分比 */
    UINT32  udwGroupID;                         /* 盘组序号 */
    BYTE    byRes[128];                         /* 保留字节 */
}NETDEV_EXTEND_STORAGE_CONTAINER_INFO_S,*LPNETDEV_EXTEND_STORAGE_CONTAINER_INFO_S;

/**
 * @struct tagNETDEVStorageContainerInfoList
 * @brief 存储容器信息列表 Storage Container info List
 * @attention 无 None
 */
typedef struct tagNETDEVStorageContainerInfoList
{
    UINT32                                  udwLocalHDDNum;                                                 /* 本地硬盘数量 */
    NETDEV_STORAGE_CONTAINER_INFO_S         astLocalHDDList[NETDEV_LOCAL_DISK_MAX_NUM];                     /* 本地存储盘信息列表 */
    UINT32                                  udwSDNum;                                                       /* SD卡数量 */
    NETDEV_STORAGE_CONTAINER_INFO_S         astSDList[NETDEV_SD_CARD_DISK_MAX_NUM];                         /* SD卡信息列表 */
    UINT32                                  udwArrayNum;                                                    /* 阵列数量 */
    NETDEV_STORAGE_CONTAINER_INFO_S         astArrayList[NETDEV_ARRAY_MAX_NUM];                             /* 阵列信息列表 */
    UINT32                                  udwExtendCabinet1HDDNum;                                        /* 拓展柜-1存储盘数量 */
    NETDEV_STORAGE_CONTAINER_INFO_S         astExtendCabinet1HDDList[NETDEV_EXTEND_CABINET_DISK_MAX_NUM];   /* 拓展柜-1 信息列表 */
    UINT32                                  udwExtendCabinet2HDDNum;                                        /* 拓展柜-2存储盘数量 */
    NETDEV_STORAGE_CONTAINER_INFO_S         astExtendCabinet2HDDList[NETDEV_EXTEND_CABINET_DISK_MAX_NUM];   /* 拓展柜-2 信息列表 */
    UINT32                                  udwNASNum;                                                      /* NAS数量 */
    NETDEV_EXTEND_STORAGE_CONTAINER_INFO_S  astNASList[NETDEV_NAS_MAX_NUM];                                 /* NAS信息列表 */
    UINT32                                  udweSATANum;                                                    /* eSATA硬盘数量 */
    NETDEV_EXTEND_STORAGE_CONTAINER_INFO_S  asteSATAList[NETDEV_ESATA_MAX_NUM];                             /* eSATA信息列表 */
    BYTE                                    byRes[128];                                                     /* 保留字节 */
}NETDEV_STORAGE_CONTAINER_INFO_LIST_S,*LPNETDEV_STORAGE_CONTAINER_INFO_LIST_S;

/**
 * @struct tagNETDEVHDDSmartDetailsInfo
 * @brief 硬盘Smart详细信息
 * @attention 无 None
 */
typedef struct tagNETDEVHDDSmartDetailsInfo
{
    UINT32  udwAttributeID;                     /* 属性ID */
    CHAR    szAttributeName[NETDEV_LEN_64];     /* 属性名称 */
    UINT32  udwStatus;                          /* 状态 参见枚举#NETDEV_HDD_SMART_ASSESSMENT_STATUS_E */
    UINT32  udwHex;                             /* 显示为十六进制 */
    UINT32  udwThresh;                          /* 阈值 */
    UINT32  udwCurrentValue;                    /* 当前值 */
    UINT32  udwWorstValue;                      /* 最差值 */
    UINT32  udwActualValue;                     /* 实际值 */
    BYTE    byRes[128];                         /* 保留字节 */
}NETDEV_HDD_SMART_DETAILS_INFO_S,*LPNETDEV_HDD_SMART_DETAILS_INFO_S;

/**
 * @struct tagNETDEVHDDSmartCheckInfo
 * @brief 硬盘Smart检测信息
 * @attention 无 None
 */
typedef struct tagNETDEVHDDSmartCheckInfo
{
    UINT32                          udwID;                                  /* 存储容器编号 */
    UINT32                          udwType;                                /* 检测类型 参见枚举#NETDEV_HDD_SMART_CHECK_TYPE_E */
    BYTE                            byRes[128];                             /* 保留字节 */
}NETDEV_HDD_SMART_CHECK_INFO_S,*LPNETDEV_HDD_SMART_CHECK_INFO_S;

/**
 * @struct tagNETDEVHDDSmartInfo
 * @brief 硬盘Smart信息
 * @attention 无 None
 */
typedef struct tagNETDEVHDDSmartInfo
{
    UINT32                          udwID;                                  /* IN 存储容器编号 */
    CHAR                            szManufacturer[NETDEV_LEN_64];          /* 厂商名称 */
    UINT32                          udwTemperature;                         /* 温度(℃) */
    CHAR                            szDeviceModel[NETDEV_LEN_64];           /* 硬盘型号 */
    UINT32                          udwUsedDays;                            /* 使用天数 */
    UINT32                          udwHealthAssessment;                    /* 整体评估结果 参见枚举#NETDEV_HDD_HEALTH_ASSESSMENT_STATUS_E */
    CHAR                            szFirmware[NETDEV_LEN_64];              /* 硬盘固件版本 */
    UINT32                          udwSmartNum;                            /* Smart详情项数量 */
    NETDEV_HDD_SMART_DETAILS_INFO_S SmartDetailsInfoList[NETDEV_DISK_SMART_MAX_NUM];    /* Smart详情项列表 */
    BOOL                            bCheckResult;                           /* 自我评估结果, TRUE 通过，FALSE 未通过 */
    UINT32                          udwCheckPrograss;                       /* 检测进度 [0,100] */
    UINT32                          udwCheckStatus;                         /* 检测状态 参见枚举#NETDEV_HDD_SMART_CHECK_STATUS_E */
    UINT32                          udwCheckType;                           /* 检测类型 参见枚举#NETDEV_HDD_SMART_CHECK_TYPE_E */
    BYTE                            byRes[128];                             /* 保留字节 */
}NETDEV_HDD_SMART_INFO_S,*LPNETDEV_HDD_SMART_INFO_S;

/*
* @struct tagDNSAddress
* @brief DNS地址
* @attention 无 None
*/
typedef struct tagDNSAddress
{
    UINT32  udwAddressType;                 /*IP地址类型 0: IPv4  1: IPv6 3: IPv4和IPv6都需要 当前仅支持IPv4 */
    CHAR   szIPAddress[NETDEV_LEN_64];      /*IPv4地址*/
    CHAR   szIPv6Address[NETDEV_LEN_64];    /*IPv6地址*/
    BYTE   byRes[128];                      /* 保留字  Reserved */
}NETDEV_DNS_ADDRESS_S, *LPNETDEV_DNS_ADDRESS_S;


/*
* @struct tagNETDEVDNSInfo
* @brief 设备DNS信息 device DNS Info
* @attention 无 None
*/
typedef struct tagNETDEVDNSInfo
{
    UINT32                  udwNum;                             /*DNS地址数量*/
    NETDEV_DNS_ADDRESS_S    astDNSList[NETDEV_DNS_LIST_NUM];    /*DNS地址列表，第1个为首要地址，第2个为次选地址。当前只支持2个*/
    BYTE                    byRes[128];                         /* 保留字  Reserved */
}NETDEV_DNS_INFO_S, *LPNETDEV_DNS_INFO_S;

/*
* @struct tagIpv6Addressinfo
* @brief IPV6详细地址信息
* @attention 无 None
*/
typedef struct tagIpv6Addressinfo
{
    UINT32  udwPrefixLenth;             /*子网前缀长度，范围为[3,127]*/
    CHAR    szAddress[NETDEV_LEN_64];   /*IP地址*/
    CHAR    szGateway[NETDEV_LEN_64];   /*默认网关*/

}NETDEV_IPV6_ADDRESS_INFO_S, *LPNETDEV_IPV6_ADDRESS_INFO_S;
/*
* @struct tagNetWorkIpv6info
* @brief 网卡信息中IPV6信息
* @attention 无 None
*/
typedef struct tagNetWorkIpv6info
{
    UINT32                      udwIPGetType;                           /*IP获取方式*/
    UINT32                      udwAddressNum;                          /*IP地址个数*/
    NETDEV_IPV6_ADDRESS_INFO_S  astIPv6AddressInfo[NETDEV_LEN_8];       /*IPv6信息，如果不支持IPv6，则该节点可选*/

}NETDEV_NETWORK_IPV6_INFO_S, *LPNETDEV_NETWORK_IPV6_INFO_S;

/*
* @struct tagIpv4Addressinfo
* @brief IPV4详细地址信息
* @attention 无 None
*/
typedef struct tagIpv4Addressinfo
{
    CHAR   szAddress[NETDEV_LEN_64];                /*IP地址*/
    CHAR   szNetmask[NETDEV_LEN_64];                /*子网掩码*/
    CHAR   szGateway[NETDEV_LEN_64];                /*默认网关*/

}NETDEV_IPV4_ADDRESS_INFO_S, *LPNETDEV_IPV4_ADDRESS_INFO_S;
/*
* @struct tagIpv4info
* @brief 网卡信息中IPV4信息
* @attention 无 None
*/
typedef struct tagNetWorkIpv4info
{
    UINT32                      udwIPGetType;                       /*IP获取方式 0：for static 1：for PPPOE2：for DHCP*/
    CHAR                        szLoginName[NETDEV_LEN_64];         /*PPPoE账号*/
    CHAR                        szPIN[NETDEV_LEN_128];              /*PPPOE密码（MD5加密）*/
    UINT32                      udwAddressNum;                      /*IP地址个数*/
    NETDEV_IPV4_ADDRESS_INFO_S  astIPv4AddressInfo[NETDEV_LEN_8];   /*IPv4信息，如果不支持IPv4，则该节点可选*/

}NETDEV_NETWORK_IPV4_INFO_S, *LPNETDEV_NETWORK_IPV4_INFO_S;

/*
* @struct tagNETDEVNetworkInterfaceInfo
* @brief 网卡的详细信息
* @attention 无 None
*/
typedef struct tagNETDEVNetworkInterfaceInfo
{
    UINT32              udwID;                                             /*网卡编号对VMS、IPC从1开始 对NVR该字段是资源编码*/
    CHAR                szName[NETDEV_NAME_MAX_LEN];                       /*网卡名称，NVR、IPC支持*/
    UINT32              udwWorkMode;                                       /*网卡工作模式 0：多址设定 1：负载均衡  2：网络容错*/
    BOOL                bIsInnerNIC;                                       /*是否为内部网卡*/
    CHAR                szInnerNICIPAddress[NETDEV_IPADDR_STR_MAX_LEN];    /*内部网卡IP地址*/
    CHAR                szInnerNICNetmask[NETDEV_IPADDR_STR_MAX_LEN];      /*内部网卡网络掩码；该字段不可配置，仅供查询*/
    CHAR                szInnerNICName[NETDEV_NAME_MAX_LEN];               /*内部网卡名称；该字段不可配置，仅供查询*/
    UINT32              udwMTU;                                            /*MTU长度，范围[576,1500]*/
    CHAR                szMAC[NETDEV_NETWORK_MACNAME_LEN];                 /*MAC地址，只读属性，字符串长度范围[0, 48]*/
    UINT32              udwNegotiationMode;                                /*网口工作模式*/
    NETDEV_NETWORK_IPV4_INFO_S stIPV4Infos;                                /*IPv4信息，如果不支持IPv4，则该节点可选*/
    NETDEV_NETWORK_IPV6_INFO_S stIPV6Infos;                                /*IPv6信息，如果不支持IPv6，则该节点可选*/
    BYTE                byRes[128];                                        /* 保留字  Reserved */
}NETDEV_NETWORK_INTERFACE_INFO_S, *LPNETDEV_NETWORK_INTERFACE_INFO_S;

/*
* @struct tagNETDEVNetworkCardsInfo
* @brief 查询设备所有网卡的配置信息。
* @attention 无 None
*/
typedef struct tagNETDEVNetworkCardsInfo
{
    UINT32                              udwNum;                                     /*网卡个数*/
    UINT32                              udwDefaultRouteNIC;                         /*作默认路由的网卡ID，当存在多张网卡（不含内部网卡）时必选*/
    UINT32                              udwWorkMode;                                /*网卡工作模式 0：多址设定 1：负载均衡  2：网络容错*/
    NETDEV_NETWORK_INTERFACE_INFO_S     astNetworkInterfaceList[NETDEV_LEN_8];      /*网卡信息列表，当Num值为0时该节点可选*/
    BYTE                                byRes[128];                                 /* 保留字  Reserved */
}NETDEV_NETWORK_CARD_INFO_S, *LPNETDEV_NETWORK_CARD_INFO_S;



/**
* @struct tagNETDEVFGSubInfo
* @brief 速通门订阅信息
* @attention 无 None
*/
typedef struct tagNETDEVFGSubInfo
{
    UINT32 udwType;                         /* 订阅类型 详见枚举NETDEV_SUB_TYPE_E*/
    UINT32 udwLibIDNum;                     /* 订阅的库ID数目 LibIDNum为16时 表示订阅所有库 */
    UINT32 audwLibIDList[NETDEV_LEN_32];    /* 订阅的库ID列表 */
    BYTE   byRes[128];                      /* 保留字节 */
}NETDEV_FG_SUB_INFO_S,*LPNETDEV_FG_SUB_INFO_S;

/**
* @struct tagNETDEVFGSubSuccInfo
* @brief 速通门订阅信息成功返回信息
* @attention 无 None
*/
typedef struct tagNETDEVFGSubSuccInfo
{
    UINT32 udwID;                   /* 订阅ID */
    UINT32 udwCurrrntTime;          /* 当前时间，UTC格式，单位秒 */
    UINT32 udwTerminationTime;      /* 结束时间，UTC格式，单位秒 */
    BYTE   byRes[128];              /* 保留字节 */
}NETDEV_FG_SUB_SUCC_INFO_S,*LPNETDEV_FG_SUB_SUCC_INFO_S;

/**
* @struct tagNETDEVFileInfo
* @brief 文件信息
* @attention 无 None
*/
typedef struct tagNETDEVFileInfo
{
    CHAR   szName[NETDEV_LEN_64];   /* 文件名称 范围[1, 16]*/
    UINT32 udwSize;                 /* 文件大小 单位:字节 范围:[0, 1M(1048576)] */
    UINT32 dwFileType;              /* 文件类型，详见枚举值：NETDEV_FILE_TYPE_E */
    UINT32 udwLastChange;           /* 最后修改时间，UTC时间，单位为s */
    CHAR   *pcData;                 /* 文件数据 Base64 需根据udwSize 动态申请内存*/
    CHAR   szUrl[NETDEV_LEN_512];   /* 图片URL，长度范围[0,256] */
    BYTE   byRes[128];              /* 保留字节 */
}NETDEV_FILE_INFO_S,*LPNETDEV_FILE_INFO_S;

/**
* @struct tagNETDEVFeatureInfo
* @brief 半结构化特征信息
* @attention 无 None
*/
typedef struct tagNETDEVFeatureInfo
{
    CHAR    szFeatureVersion[NETDEV_LEN_32];        /* 人脸半结构化特征提取算法版本号 [0, 20] */
    CHAR    szFeature[NETDEV_FACE_FEATURE_SIZE];    /* 基于人脸提取出来的特征信息 目前加密前512B */
    BYTE    byRes[128];                             /* 保留字节 */
}NETDEV_FEATURE_INFO_S,*LPNETDEV_FEATURE_INFO_S;

/**
* @struct tagNETDEVRegionInfo
* @brief 成员地区信息
* @attention 无 None
*/
typedef struct tagNETDEVRegionInfo
{
    CHAR szNation[NETDEV_LEN_128];          /* 国籍，范围[1-63] */
    CHAR szProvince[NETDEV_LEN_128];        /* 省份，范围[1-63] */
    CHAR szCity[NETDEV_LEN_128];            /* 城市，范围[1-63] */
    BYTE byRes[256];

}NETDEV_REGION_INFO_S, *LPNETDEV_REGION_INFO_S;

/**
* @enum tagNETDEVPersonTimeTemplateInfo
* @brief 时间模板相关信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonTimeTemplateInfo
{
    UINT32 udwBeginTime;    /* 时间模板生效起始时间 若未配置，填写0 */
    UINT32 udwEndTime;      /* 时间模板生效结束时间 若未配置，填写4294967295(0xFFFFFFFF)*/
    UINT32 udwIndex;        /* 时间模板索引 */
    BYTE   byRes[128];      /* 保留字节 */
}NETDEV_PERSON_TIME_TEMPLATE_INFO_S,*LPNETDEV_PERSON_TIME_TEMPLATE_INFO_S;

/**
* @struct tagNETDEVIdentificationInfo
* @brief 成员证件信息
* @attention 无 None
*/
typedef struct tagNETDEVIdentificationInfo
{
    UINT32 udwType;                     /* 证件类型 详情参见枚举 NETDEV_ID_TYPE_E*/
    CHAR   szNumber[NETDEV_LEN_32];     /* 证件号，范围:[1, 20] */
    BYTE   byRes[128];                  /* 保留字节 */
}NETDEV_IDENTIFICATION_INFO_S,*LPNETDEV_IDENTIFICATION_INFO_S;

/**
* @struct tagNETDEVImageInfo
* @brief 人脸图片信息列表
* @attention 无 None
*/
typedef struct tagNETDEVImageInfo
{
    UINT32 udwFaceID;                   /* 人脸照片ID */
    NETDEV_FILE_INFO_S stFileInfo;      /* 照片信息 */
    BYTE   byRes[128];                  /* 保留字节 */
}NETDEV_IMAGE_INFO_S,*LPNETDEV_IMAGE_INFO_S;

/**
 * @struct tagNETDEVCustomValue
 * @brief 自定义属性信息
 * @attention 无 None
 */
typedef struct tagNETDEVCustomValue
{
    UINT32  udwID;                                         /* 自定义属性名称序号 从0开始*/
    CHAR    szValue[NETDEV_FACE_MEMBER_CUSTOM_LEN];        /* 自定义属性值 范围[1,63]*/

    BYTE    byRes[128];                                    /* 保留字段  Reserved */
}NETDEV_CUSTOM_VALUE_S,*LPNETDEV_CUSTOM_VALUE_S;

/**
* @struct tagNETDEVPersonInfo
* @brief 人员信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonInfo
{
    UINT32 udwPersonID;                                                      /* 人员ID */
    UINT32 udwLastChange;                                                    /* 人员信息最后修改时间 */
    CHAR   szPersonName[NETDEV_LEN_256];                                     /* 人员名字 范围:[1, 63] */
    UINT32 udwGender;                                                        /* 成员性别 详情参见枚举NETDEV_GENDER_TYPE_E*/
    CHAR   szBirthday[NETDEV_LEN_64];                                        /* 成员出生日期，格式YYYYMMDD，范围[1,31] */
    NETDEV_REGION_INFO_S stRegionInfo;                                       /* 成员地区信息 */
    NETDEV_PERSON_TIME_TEMPLATE_INFO_S stTimeTemplate;                       /* 时间模板相关信息 */
    UINT32 udwIdentificationNum;                                             /* 证件信息个数 范围:[0, 6]*/
    NETDEV_IDENTIFICATION_INFO_S stIdentificationInfo[NETDEV_LEN_8];         /* 成员证件信息 */
    UINT32 udwImageNum;                                                      /* 人脸图片个数 范围:[0, 6] */
    NETDEV_IMAGE_INFO_S stImageInfo[NETDEV_LEN_8];                           /* 人脸图片信息列表 */

    UINT32  udwReqSeq;                                                       /* 请求数据序列号，此字段会在返回结果中待会，仅在批量添加中携带该字段 */
    BOOL    bIsMonitored;                                                    /* 是否已布控，获取时必带，仅VMS支持 */
    UINT32  udwBelongLibNum;                                                 /* 所属人员库数量，仅VMS支持 */
    UINT32  *pudwBelongLibList;                                              /* 所属人员库ID列表，需动态分配内存，仅VMS支持 */
    UINT32  udwCustomNum;                                                    /* 自定义属性值数量，最多5个，仅VMS支持 */
    LPNETDEV_CUSTOM_VALUE_S              pstCustomValueList;                  /* 自定义属性值列表，需动态分配内存，当Num为0时可以不填 */
    BYTE   byRes[128];                                                       /* 保留字节 */
}NETDEV_PERSON_INFO_S,*LPNETDEV_PERSON_INFO_S;

/**
* @struct tagNETDEVCtrlFaceInfo
* @brief 人脸信息
* @attention 无 None
*/
typedef struct tagNETDEVCtrlFaceInfo
{
    UINT32 udwID;                                           /* 记录ID */
    UINT32 udwType;                                         /* 人脸通行记录类型 */
    UINT32 udwTimestamp;                                    /* 采集时间 UTC格式，单位秒 */
    UINT32 udwCapSrc;                                       /* 采集来源 */
    CHAR   szCapSrcName[NETDEV_LEN_128];                    /* 抓拍来源名称，范围1-63 */\
    UINT32 udwSimilarity;                                   /* 相似度 */
    NETDEV_PERSON_INFO_S stPersonInfo;                      /* 人脸库成员信息 */
    UINT32 udwFeatureNum;                                   /* 半结构化特征数目 范围：[0, 2] */
    NETDEV_FEATURE_INFO_S stFeatureInfo[NETDEV_LEN_4];      /* 半结构化特征列表 */
    NETDEV_FILE_INFO_S stPanoImage;                         /* 人脸全景图 */
    NETDEV_FILE_INFO_S stFaceImage;                         /* 人脸小图 */
    NETDEV_FACE_POSITION_INFO_S stFaceArea;                 /* 人脸全景图人脸区域坐标 */
    BYTE   byRes[128];                                      /* 保留字节 */
}NETDEV_CTRL_FACE_INFO_S,*LPNETDEV_CTRL_FACE_INFO_S;

/**
* @enum tagNETDEVCtrlGateInfo
* @brief 闸机信息
* @attention 无 None
*/
typedef struct tagNETDEVCtrlGateInfo
{
    UINT32 udwID;               /* 记录ID */
    UINT32 udwTimestamp;        /* 采集时间 */
    UINT32 udwCapSrc;           /* 采集来源 */
    UINT32 udwInPersonCnt;      /* 进入人员计数 */
    UINT32 udwOutPersonCnt;     /* 离开人员计数 */
    BYTE   byRes[128];          /* 保留字节 */
}NETDEV_CTRL_GATE_INFO_S,*LPNETDEV_CTRL_GATE_INFO_S;

/**
* @struct tafNETDEVCtrlCardInfo
* @brief 卡信息
* @attention 无 None
*/
typedef struct tafNETDEVCtrlCardInfo
{
    UINT32 udwID;                                       /* 记录ID */
    UINT32 udwTimestamp;                                /* 采集时间 UTC格式，单位秒 */
    UINT32 udwCapSrc;                                   /* 采集来源 1：人脸识别终端采集的人脸信息 2：读卡器采集的门禁卡信息 3：读卡器采集的身份证信息 4：闸机采集的闸机信息 */
    UINT32 udwCardType;                                 /* 0：身份证，1：门禁卡 */
    CHAR   szCardID[NETDEV_LEN_32];                     /* 门禁卡字段：物理卡号 */
    UINT32 udwCardStatus;                               /* 门禁卡字段：卡状态 */
    CHAR   szName[NETDEV_LEN_256];                      /* 身份证字段：姓名 范围[1,63] */
    UINT32 udwGender;                                   /* 身份证字段：性别 详情参见枚举NETDEV_DENDER_TYPE_E*/
    UINT32 udwEthnicity;                                /* 身份证字段：民族 01：汉族*/
    CHAR   szBirthday[NETDEV_LEN_16];                   /* 身份证字段：出生日期 YYYYMMDD */
    CHAR   szResidentialAddress[NETDEV_LEN_128];        /* 身份证字段：住址 */
    CHAR   szIdentityNo[NETDEV_LEN_32];                 /* 身份证字段：身份证号码 */
    CHAR   szIssuingAuthority[NETDEV_LEN_128];          /* 身份证字段：发证机关 */
    CHAR   szIssuingDate[NETDEV_LEN_16];                /* 身份证字段：发证日期 YYYYMMDD */
    CHAR   szValidDateStart[NETDEV_LEN_16];             /* 身份证字段：证件有效期开始时间 */
    CHAR   szValidDateEnd[NETDEV_LEN_16];               /* 身份证字段：证件有效期结束时间 */
    NETDEV_FILE_INFO_S stIDImage;                       /* 身份证照片 */
    BYTE   byRes[128];                                  /* 保留字节 */
}NETDEV_CTRL_CARD_INFO_S,*LPNETDEV_CTRL_CARD_INFO_S;

/**
* @struct tagNETDEVMatchPersonInfo
* @brief 匹配人员信息
* @attention 无 None
*/
typedef struct tagNETDEVMatchPersonInfo
{
    CHAR   szPersonName[NETDEV_LEN_256];        /* 成员名字 范围[1,63] */
    UINT32 udwGender;                           /* 成员性别 详情参见枚举NETDEV_DENDER_TYPE_E */
    CHAR   szCardID[NETDEV_LEN_32];             /* 门禁卡号 */
    CHAR   szIdentityNo[NETDEV_LEN_32];         /* 身份证卡号 */
    BYTE   byRes[128];                          /* 保留字节 */
}NETDEV_MATCH_PERSON_INFO_S,*LPNETDEV_MATCH_PERSON_INFO_S;

/**
* @struct tagNETDEVCtrlLibMatchInfo
* @brief 库比对信息
* @attention 无 None
*/
typedef struct tagNETDEVCtrlLibMatchInfo
{
    UINT32 udwID;                                   /* 记录ID */
    UINT32 udwLibID;                                /* 库ID */
    UINT32 udwLibType;                              /* 库类型 */
    UINT32 udwMatchStatus;                          /* 匹配状态 1:核验成功 2:核验失败（比对失败)3:核验失败(对比成功,不在布控时间)41:底图采集成功 42:底图采集失败 */
    UINT32 udwMatchPersonID;                        /* 匹配人员ID */
    UINT32 udwMatchFaceID;                          /* 匹配人脸ID */
    NETDEV_MATCH_PERSON_INFO_S stMatchPersonInfo;   /* 匹配人员信息 */
    BYTE   byRes[128];                              /* 保留字节 */
}NETDEV_CTRL_LIB_MATCH_INFO_S,*LPNETDEV_CTRL_LIB_MATCH_INFO_S;

/**
* @struct tagNETDEVNotification
* @brief 门禁通知信息
* @attention 无 None
*/
typedef struct tagNETDEVNotification
{
    UINT32 udwID;                                                            /* 通知记录ID */
    UINT32 udwTimestamp;                                                     /* 通知上报时间 UTC格式，单位秒*/
    UINT32 udwNotificationType;                                              /* 通知类型 0：实时通知1：历史通知 */
    UINT32 udwFaceInfoNum;                                                   /* 人脸信息数目 范围：[0, 1] */
    NETDEV_CTRL_FACE_INFO_S stCtrlFaceInfo[NETDEV_LEN_2];                    /* 人脸信息 */
    UINT32 udwCardInfoNum;                                                   /* 卡信息数目 范围：[0, 1] */
    NETDEV_CTRL_CARD_INFO_S stCtrlCardInfo[NETDEV_LEN_2];                    /* 卡信息 */
    UINT32 udwGateInfoNum;                                                   /* 闸机信息数目 范围：[0, 1] */
    NETDEV_CTRL_GATE_INFO_S stCtrlGateInfo[NETDEV_LEN_2];                    /* 闸机信息 */
    UINT32 udwLibMatInfoNum;                                                 /* 库比对信息数目 范围：[0, 16] */
    NETDEV_CTRL_LIB_MATCH_INFO_S stLibMatchInfo[NETDEV_LEN_32];              /* 库比对信息 */
    BYTE   byRes[128];                                                       /* 保留字节 */
}NETDEV_NOTIFICATION_S,*LPNETDEV_NOTIFICATION_S;

/**
* @struct tagNETDEVPersonCompareInfo
* @brief 人脸 比对信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonCompareInfo
{
    UINT32 udwSimilarity;                                   /* 相似度 */
    NETDEV_PERSON_INFO_S stPersonInfo;                      /* 人脸库成员信息 */
    NETDEV_FILE_INFO_S stPanoImage;                         /* 人脸大图  */
    NETDEV_FILE_INFO_S stFaceImage;                         /* 人脸小图 */
    NETDEV_FACE_POSITION_INFO_S stFaceArea;                 /* 人脸区域坐标 */
    UINT32 udwCapSrc;                                       /* 采集来源 */
    BYTE   byRes[NETDEV_LEN_256];                           /* 保留字段 */
}NETDEV_PERSON_COMPARE_INFO_S, *LPNETDEV_PERSON_COMPARE_INFO_S;

/**
* @struct tagNETDEVFacePassRecordInfo
* @brief 人脸 通过记录信息
* @attention 无 None
*/
typedef struct tagNETDEVFacePassRecordInfo
{
    UINT32                              udwRecordID;                        /* 人脸通行记录ID */
    UINT32                              udwType;                            /* 人脸通行类型，参见枚举NETDEV_FACE_PASS_RECORD_TYPE_E */
    INT64                               tPassingTime;                       /* 过人时间，UTC格式，单位秒 */
    UINT32                              udwChannelID;                       /* 通道ID */
    CHAR                                szChlName[NETDEV_LEN_128];          /* 抓拍通道名称，范围[1,63] */
    NETDEV_PERSON_COMPARE_INFO_S        stCompareInfo;                      /* 比对信息 */
    BYTE                                byRes[NETDEV_LEN_256];              /* 保留字段 */
}NETDEV_FACE_PASS_RECORD_INFO_S, *LPNETDEV_FACE_PASS_RECORD_INFO_S;

/**
* @struct tagNETDEVPersonEventInfo
* @brief 人员报警信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonEventInfo
{
    UINT32 udwID;                                                            /* 通知记录ID */
    UINT32 udwTimestamp;                                                     /* 通知上报时间 UTC格式，单位秒*/
    UINT32 udwNotificationType;                                              /* 通知类型 0：实时通知1：历史通知 */
    UINT32 udwFaceInfoNum;                                                   /* 人脸信息数目 范围：[0, 1] */
    NETDEV_FACE_PASS_RECORD_INFO_S  stCtrlFaceInfo[NETDEV_LEN_2];                          /* 人脸信息列表，当采集信息没有人脸时，可不带FaceInfo相关字段 */
    BYTE    byRes[NETDEV_LEN_256];                                           /* 保留字段 */
}NETDEV_PERSON_EVENT_INFO_S, *LPNETDEV_PERSON_EVENT_INFO_S;

/**
* @struct tagNETDEVUpdateInfo
* @brief 更新信息
* @attention 无 None
*/
typedef struct tagNETDEVUpdateInfo
{
    UINT32 udwID;               /* 时间模板ID */
    UINT32 udwLastChange;       /* 时间模板最后修改时间 */
    BYTE   byRes[128];          /* 保留字节 */
}NETDEV_UPDATE_INFO_S,*LPNETDEV_UPDATE_INFO_S;

/**
* @struct tagNETDEVTimeTemplateUdateInfo
* @brief 时间模板的更新信息
* @attention 无 None
*/
typedef struct tagNETDEVTimeTemplateUpdateInfo
{
    UINT32 udwNum;                                          /* 有效时间模板个数 [0, 32] */
    NETDEV_UPDATE_INFO_S stUpdateInfo[NETDEV_LEN_64];       /* 更新信息 */
    BYTE   byRes[128];                                      /* 保留字节 */
}NETDEV_TIME_TEMPLATE_UPDATE_INFO_S,*LPNETDEV_TIME_TEMPLATE_UPDATE_INFO_S;

/**
* @struct tagNETDEVExceptionDayInfo
* @brief 每天的布防计划具体信息
* @attention 无 None
*/
typedef struct tagNETDEVExceptionDayInfo
{
    UINT32 udwID;                                                            /* 例外日期索引 */
    BOOL   bEnabled;                                                         /* 例外日期是否使能 */
    CHAR   szDate[NETDEV_LEN_16];                                            /* 例外日期 year-month-day */
    UINT32 udwNum;                                                           /* 例外时间段个数 NVR最大为8段 IPC/PTS最大为4段*/
    NETDEV_TIME_SECTION_INFO_S stTimeSectionInfo[NETDEV_LEN_16];             /* 布防配置具体信息 */
    BYTE   byRes[128];                                                       /* 保留字节 */
}NETDEV_EXCEPTION_DAY_INFO_S,*LPNETDEV_EXCEPTION_DAY_INFO_S;

/**
* @struct tagNETDEVExceptionInfo
* @brief 布控任务例外计划
* @attention 无 None
*/
typedef struct tagNETDEVExceptionInfo
{
    BOOL   bEnabled;                                                         /* 例外日期是否使能 0:不使能 1：使能 */
    UINT32 udwNum;                                                           /* 例外日期个数 [0, 16] */
    NETDEV_EXCEPTION_DAY_INFO_S stExceptionDayInfo[NETDEV_LEN_32];           /* 每天的布防计划具体信息 */
    BYTE   byRes[128];                                                       /* 保留字节 */
}NETDEV_EXCEPTION_INFO_S,*LPNETDEV_EXCEPTION_INFO_S;

/**
* @struct tagNETDEVTimeTemplateInfo
* @brief 时间模板配置
* @attention 无 None
*/
typedef struct tagNETDEVTimeTemplateInfo
{
    UINT32 udwID;                                   /* 人员库时间模板布控任务序号 */
    CHAR   szName[NETDEV_LEN_256];                  /* 时间模板名称 [1, 63] */
    UINT32 udwLastChange;                           /* 时间模板最后修改时间 */
    NETDEV_WEEK_PLAN_INFO_S stWeekPlanInfo;         /* 布控任务布防计划 */
    NETDEV_EXCEPTION_INFO_S stExceptionInfo;        /* 布控任务例外计划 */
    BYTE   byRes[128];                              /* 保留字节 */
}NETDEV_TIME_TEMPLATE_INFO_S,*LPNETDEV_TIME_TEMPLATE_INFO_S;

/**
* @struct tagNETDEVSinglePersonUpdateInfo
* @brief 指定人员的更新信息
* @attention 无 None
*/
typedef struct tagNETDEVSinglePersonUpdateInfo
{
    BOOL   bPersonExisted;      /* 人员是否存在 */
    UINT32 udwLastChange;       /* 最后修改时间 */
    BYTE   byRes[128];          /* 保留字节 */
}NETDEV_SINGLE_PERSON_UPDATE_INFO_S,*LPNETDEV_SINGLE_PERSON_UPDATE_INFO_S;

/**
* @struct tagNETDEVPagedQueryInfo
* @brief 查询条件
* @attention 无 None
*/
typedef struct tagNETDEVPagedQueryInfo
{
    UINT32 udwLimit;        /* 每次查询的数量 */
    UINT32 udwOffset;       /* 从当前序号开始查询 */
    BYTE   byRes[128];      /* 保留字节 */
}NETDEV_PAGED_QUERY_INFO_S,*LPNETDEV_PAGED_QUERY_INFO_S;

/**
* @struct tagNETDEVPersonUpdateInfo
* @brief 名单成员信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonUpdateInfo
{
    UINT32 udwPersonID;         /* 人员ID */
    UINT32 udwLastChange;       /* 人员库名单查询结果列表 */
    BYTE   byRes[128];          /* 保留字节 */
}NETDEV_PERSON_UPDATE_INFO_S,*LPNETDEV_PERSON_UPDATE_INFO_S;

/**
* @struct tagNETDEVPersonUpdateInfoList
* @brief 人员库名单查询结果列表
* @attention 无 None
*/
typedef struct tagNETDEVPersonUpdateInfoList
{
    UINT32 udwTotal;                                                /* 人员库名单总数 */
    UINT32 udwOffset;                                               /* 人员库名单查询起始序号 */
    UINT32 udwNum;                                                  /* 人员库名单查询结果总数 单次最大1000条 */
    NETDEV_PERSON_UPDATE_INFO_S stPersonList[NETDEV_LEN_1024];      /* 人员库名单查询结果列表 */
    BYTE   byRes[128];                                              /* 保留字节 */
}NETDEV_PERSON_UPDATE_INFO_LIST_S,*LPNETDEV_PERSON_UPDATE_INFO_LIST_S;

/**
* @struct tagNETDEVPersonInfoList
* @brief 人员信息列表
* @attention 无 None
*/
typedef struct tagNETDEVPersonInfoList
{
    UINT32 udwNum;                                          /* 人员库人员个数 */
    LPNETDEV_PERSON_INFO_S              pstPersonInfo;      /* 人员信息列表,需动态分配内存 */
    BYTE   byRes[128];                                      /* 保留字节 */
}NETDEV_PERSON_INFO_LIST_S,*LPNETDEV_PERSON_INFO_LIST_S;

/**
* @struct tagNETDEVFaceInfo
* @brief 人脸信息结果
* @attention 无 None
*/
typedef struct tagNETDEVFaceInfo
{
    UINT32 udwFaceID;           /* 人员ID */
    UINT32 udwResultCode;       /* 处理结果状态码，详见#NETDEV_PERSON_RESULT_CODE_E */
    BYTE   byRes[128];          /* 保留字节 */
}NETDEV_FACE_INFO_S,*LPNETDEV_FACE_INFO_S;

/**
* @struct tagNETDEVPersonList
* @brief 人员信息列表
* @attention 无 None
*/
typedef struct tagNETDEVPersonList
{
    UINT32 udwPersonID;                                 /* 人员ID */
    UINT32 udwFaceNum;                                  /* 人脸个数 批量单次最多6个 */
    NETDEV_FACE_INFO_S stFaceInfo[NETDEV_LEN_8];        /* 人脸信息结果列表 */
    UINT32 udwReqseq;                                   /* 请求数据序号,仅VMS支持 */
    BYTE   byRes[128];                                  /* 保留字节 */
}NETDEV_PERSON_LIST_S,*LPNETDEV_PERSON_LIST_S;

/**
* @struct tagNETDEVPersonResultList
* @brief 人员信息结果列表
* @attention 无 None
*/
typedef struct tagNETDEVPersonResultList
{
    UINT32 udwNum;                                          /* 人员个数 */
    LPNETDEV_PERSON_LIST_S pstPersonList;                   /* 人员信息列表,需动态分配内存 */
    BYTE   byRes[128];                                      /* 保留字节 */
}NETDEV_PERSON_RESULT_LIST_S,*LPNETDEV_PERSON_RESULT_LIST_S;

/**
* @struct tagNETDEVLibInfo
* @brief 库信息
* @attention 无 None
*/
typedef struct tagNETDEVLibInfo
{
    UINT32 udwID;                           /* 库ID */
    CHAR   szName[NETDEV_LEN_256];          /* 库名称 范围[1,63] */
    UINT32 udwType;                         /* 人员库类型 详情参见枚举NETDEV_PEOPLE_LIB_TYPE_E*/
    UINT32 udwPersonNum;                    /* 库中人员信息的总数 */
    UINT32 udwFaceNum;                      /* 库中人脸照片总数 */
    UINT32 udwMemberNum;                    /* 库中人员成员的总数 */
    UINT32 udwLastChange;                   /* 库的信息的最后修改时间 */
    CHAR   szBelongIndex[NETDEV_LEN_256];   /* 库的唯一归属索引 */
    BOOL   bIsMonitored;                    /* 是否已布控，获取库信息时必带 */
    BYTE   byRes[128];                      /* 保留字节 */
}NETDEV_LIB_INFO_S,*LPNETDEV_LIB_INFO_S;

/**
* @struct tagNETDEVPersonLibList
* @brief 人员库信息
* @attention 无 None
*/
typedef struct tagNETDEVPersonLibList
{
    UINT32              udwNum;                     /* 设备中已创建的库数量 */
    LPNETDEV_LIB_INFO_S pstLibInfo;                 /* 库列表信息,需动态分配内存 */
    BYTE                byRes[128];                 /* 保留字节 */
}NETDEV_PERSON_LIB_LIST_S,*LPNETDEV_PERSON_LIB_LIST_S;


/**
 * @struct tagstNETDEVSmartInfo
 * @brief 智能事件信息
 * @attention
 */
typedef struct tagstNETDEVSmartInfo
{
    INT32      dwChannelID;         /* 通道ID */
    UINT32     udwSubscribeID;      /* 订阅ID */
    BYTE       byRes[128];          /* 保留字段  Reserved */
}NETDEV_SMART_INFO_S, *LPNETDEV_SMART_INFO_S;

/**
 * @struct tagstNETDEVSubscribeSmartInfo
 * @brief 订阅智能事件信息
 * @attention
 */
typedef struct tagstNETDEVSubscribeSmartInfo
{
    UINT32   udwNum;                /* 订阅智能告警数 */
    UINT32   *pudwSmartType;        /* 订阅的智能告警类型 参见枚举NETDEV_SMART_ALARM_TYPE_E，根据udwNum动态申请 */
    BYTE     byRes[128];            /* 保留字段  Reserved */
}NETDEV_SUBSCRIBE_SMART_INFO_S, *LPNETDEV_SUBSCRIBE_SMART_INFO_S;


/**
 * @struct tagstNETDEVAlarmLogCond
 * @brief 告警日志查询条件
 * @attention  查询“告警类型”时，携带的告警主类型或子类型数量均不能超过16个。
 */
typedef struct tagstNETDEVQueryInfo
{
    INT32   dwQueryType;                                /* 查询条件类型，参见#NETDEV_QUERYCOND_TYPE_E */
    INT32   dwLogicFlag;                                /* 查询条件逻辑类型，参见#NETDEV_QUERYCOND_LOGICTYPE_E */
    CHAR    szConditionData[NETDEV_CODE_STR_MAX_LEN];   /* 查询条件右值 */
}NETDEV_QUERY_INFO_S, *LPNETDEV_QUERY_INFO_S;

/**
 * @struct tagstNETDEVAlarmLogCondList
 * @brief 告警日志所有查询条件
 * @attention
 */
typedef struct tagstNETDEVAlarmLogCondList
{
    INT32   dwPageRow;                                                      /* 每页最大条数 */
    INT32   dwFirstRow;                                                     /* 分页查询中第一条数据的序号 */
    INT32   dwCondSize;                                                     /* 查询条件数量 */
    NETDEV_QUERY_INFO_S astCondition[NETDEV_LOG_QUERY_COND_NUM];            /* 查询条件右值 */
}NETDEV_ALARM_LOG_COND_LIST_S, *LPNETDEV_ALARM_LOG_COND_LIST_S;

/**
 * @struct tagstNETDEVAlarmLogInfo
 * @brief 告警日志信息
 * @attention
 */
typedef struct tagstNETDEVAlarmLogInfo
{
    INT32 dwAlarmID;                                            /* 告警ID */
    INT32 dwAlarmType;                                          /* 告警类型 参见# NETDEV_ALARM_TYPE_E*/
    INT32 dwAlarmSubType;                                       /* 告警子类型,参见#NETDEV_ALARM_SUBTYPE_E */
    INT32 dwAlarmLevel;                                         /* 告警级别 */
    INT32 dwServerID;                                           /* 所属服务器 */
    INT32 dwDevID;                                              /* 设备ID */
    INT32 dwChannelID;                                          /* 通道ID */
    CHAR szAlarmSrc[NETDEV_NAME_MAX_LEN];                       /* 告警源信息 */
    INT64 tAlarmTime;                                           /* 告警发生时间 */
    BOOL bAlarmChecked;                                         /* 告警是否被确认 */
    CHAR szAlarmCheckUser[NETDEV_USERNAME_LEN];                 /* 告警确认用户 */
    INT64 tAlarmCheckTime;                                      /* 告警确认时间 */
    CHAR szAlarmCheckDesc[NETDEV_DESCRIBE_MAX_LEN];             /* 告警确认描述 */
    INT32 dwAlarmLinkType;                                      /* 告警联动类型 */
    BOOL IsAlarmSnapExisted;                                    /* 告警是否有抓图 0没有抓图 1有抓图*/
    BYTE byRes[252];                                            /* 保留字段 */
}NETDEV_ALARM_LOG_INFO_S, *LPNETDEV_ALARM_LOG_INFO_S;

/**
 * @struct tagstNETDEVAlarmLogChecked
 * @brief 告警日志确认信息
 * @attention
 */
typedef struct tagstNETDEVAlarmLogChecked
{
    INT32  dwSize;                                               /* 告警源数量 */
    INT32* pdwAlarmID;                                           /* 告警ID，根据size动态分配内存  */
    CHAR   szAlarmDesc[NETDEV_DESCRIBE_MAX_LEN];                 /* 告警描述 */

    BYTE     byRes[128];                                        /* 保留字段  Reserved */
}NETDEV_ALARMLOG_CHECKED_S, *LPNETDEV_ALARMLOG_CHECKED_S;

/**
 * @struct tagstNETDEVAlarmLogCheckedList
 * @brief 告警日志确认信息列表
 * @attention
 */
typedef struct tagstNETDEVAlarmLogCheckedList
{
    INT32    dwSize;                                             /* 告警日志确认数量 */
    LPNETDEV_ALARMLOG_CHECKED_S pstAlarmLogChecked;              /* 告警日志确认信息，根据size动态分配内存 */

    BYTE     byRes[128];                                         /* 保留字段  Reserved */
}NETDEV_ALARMLOG_CHECKED_LIST_S, *LPNETDEV_ALARMLOG_CHECKED_LIST_S;


/* 告警上报类型转换 */
typedef struct tagAlarmReportInfo
{
    INT32 dwReportType;                 /* 告警类型，参见枚举NETDEV_ALARM_TYPE_E */
    CHAR* szDescribe;                   /* 告警类型描述 */
}NETDEV_ALARM_REPORT_INFO_S, *LPNETDEV_ALARM_REPORT_INFO_S;


/**
 * @struct tagNETDEVDatabaseInfo
 * @brief 库信息（人脸库和车辆） 结构体定义 face and Vehicle database information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVDatabaseInfo
{
    UINT32   udwFaceDBID;                               /* 库序号 */
    UINT32   udwFaceDBType;                             /* 库类型 参见枚举#NETDEV_FACE_DB_TYPE_E */
    CHAR     szFaceDBName[NETDEV_FACE_DB_NAME_LEN];     /* 库名称 */
    BOOL     bMonitored;                                /* 是否已布控*/
    UINT32   udwMemberNum;                              /* 人脸库中人脸成员总数*/
    BYTE     byRes[128];                                /* 保留字段  Reserved */

}NETDEV_DATABASE_INFO_S,*LPNETDEV_DATABASE_INFO_S;

/**
 * @struct tagstNETDEVAlarmPlanInfo
 * @brief 告警布防预案信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanInfo
{
    INT32   dwPlanType;                                         /* 告警布防预案类型，参见#NETDEV_ALARM_PLAN_TYPE_E */
    INT32   dwPlanID;                                           /* 预案ID */
    CHAR    szPlanName[NETDEV_NAME_MAX_LEN];                    /* 预案名称 */
    INT32   dwTimeTamplateID;                                   /* 时间模板ID */
    CHAR    szTimeTamplateName[NETDEV_NAME_MAX_LEN];            /* 时间模板名称 */
    CHAR    szDesc[NETDEV_DESCRIBE_MAX_LEN];                    /* 预案描述 */
    BOOL    bEnable;                                            /* 是否启用预案 */
}NETDEV_ALARM_PLANINFO_S, *LPNETDEV_ALARM_PLANINFO_S;

/**
 * @struct tagNETDEVCustomAttrInfo
 * @brief 自定义属性名称 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVCustomAttrInfo
{
    UINT32   udwID;                                         /* 自定义属性名称序号 */
    BOOL     bEnabled;                                      /* 自定义属性使能 0不使能、1使能*/
    CHAR     szName[NETDEV_FACE_DB_TITLE_NAME_LEN];    /* 自定义属性名称*/

    BYTE     byRes[128];                                    /* 保留字段  Reserved */

}NETDEV_CUSTOM_ATTR_INFO_S,*LPNETDEV_CUSTOM_ATTR_INFO_S;


/**
 * @struct tagNETDEVMemberInfo
 * @brief 人脸成员信息列表 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVMemberInfo
{
    UINT32 udwPersonID;                                             /* 人脸成员ID */
    CHAR szMemberName[NETDEV_LEN_260];                              /* 人脸成员名称，范围[1,63] */
    BYTE     byRes[128];                                            /* 保留字段  Reserved */
}NETDEV_MEMBER_INFO_S,*LPNETDEV_MEMBER_INFO_S;

/**
 * @struct tagNETDEVFaceMonitorRuleInfo
 * @brief 人脸布控任务配置信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMonitorRuleInfo
{
    BOOL                    bEnabled;                                              /* 人脸布控任务使能 */
    CHAR                    szName[NETDEV_FACE_MONITOR_RULE_NAME_LEN];             /* 人脸布控任务的布控名称 */
    CHAR                    szReason[NETDEV_FACE_MONITOR_RULE_REASON_LEN];         /* 人脸布控的布控原因 */
    UINT32                  udwLibNum;                                             /* 任务对应的人脸库数量,最大16个 */
    UINT32                  audwLibList[NETDEV_LEN_32];                            /* 库ID列表 */
    UINT32                  udwMonitorType;                                        /* 布控告警类型，0：匹配告警,1：不匹配告警 */
    UINT32                  udwMultipleValue;                                      /* 人脸1：N比较置信度阀值 */
    CHAR                    szMatchSucceedMsg[NETDEV_LEN_512];                     /* 比对成功提示语 */
    CHAR                    szMatchFailedMsg[NETDEV_LEN_512];                      /* 比对失败提示语 */
    UINT32                  udwPersonNum;                                          /* 人脸成员数量 [0-32] */
    NETDEV_MEMBER_INFO_S    stMemberInfo[NETDEV_LEN_64];                           /* 人脸成员信息列表 */
    UINT32                  udwDevNum;                                             /* 人脸布控任务的布控设备个数 最多四个 */
    UINT32                  audwMonitorDevIDList[NETDEV_LEN_16];                   /* 人脸布控任务的布控设备列表 根据DevNum动态确定*/
    BYTE                    byRes[256];                                            /* 保留字段  Reserved */
}NETDEV_FACE_MONITION_RULE_INFO_S,*LPNETDEV_FACE_MONITION_RULE_INFO_S;

/**
 * @struct tagNETDEVVideoLossRuleInfo
 * @brief视频丢失告警的配置信息
 * @attention 
 */
typedef struct tagNETDEVVideoLossRuleInfo
{
    BOOL         bEnabled;            /* 使能, 0:不使能 1:使能*/
    BYTE         byRes[256];          /* 保留字段 */
}NETDEV_VIDEO_LOSS_RULE_INFO_S, *LPNETDEV_VIDEO_LOSS_RULE_INFO_S;

/**
 * @struct tagNETDEVTamperDetectionRuleInfo
 * @brief遮挡检测告警的配置信息
 * @attention 
 */
typedef struct tagNETDEVTamperDetectionRuleInfo
{
    BOOL         bEnabled;              /* 使能, 0:不使能 1:使能*/
    UINT32       udwSensitivity;        /* 灵敏度，范围[1,100] */
    UINT32       udwDuration;           /* 持续时间，单位秒。长度范围[0, 10]，IPC需要 */
    BYTE         byRes[256];            /* 保留字段 */
}NETDEV_TAMPER_DETECTION_RULE_INFO_S, *LPNETDEV_TAMPER_DETECTION_RULE_INFO_S;

/**
 * @struct tagNETDEVOutputSwitchActParamInfo
 * @brief 联动开关量输出
 * @attention
 */
typedef struct tagNETDEVOutputSwitchActParamInfo
{
    UINT32 udwNum;                                                                                 /* 联动的开关量输出个数*/
    NETDEV_OUTPUT_SWITCH_ALARM_STATUS_S astOutputAlarmStatusInfo[NETDEV_MAX_ALARM_OUT_NUM];        /* 联动的开关量输出列表*/
}NETDEV_OUTPUT_SWITCH_ACT_PARAM_INFO_S,*LPNETDEV_OUTPUT_SWITCH_ACT_PARAM_INFO_S;

/**
 * @struct tagNETDEVChannelActParamInfo
 * @brief 通道联动
 * @attention
 */
typedef struct tagNETDEVChannelActParamInfo
{
    UINT32 udwNum;                                 /* 通道个数*/
    INT32 adwChannelID[NETDEV_CHANNEL_MAX];        /* 通道ID列表*/
}NETDEV_CHANNEL_ACT_PARAM_INFO_S,*LPNETDEV_CHANNEL_ACT_PARAM_INFO_S;

/**
 * @struct tagNETDEVChannelPreset
 * @brief 联动云台预置位
 * @attention
 */
typedef struct tagNETDEVChannelPreset
{
    INT32 dwChannelID;                              /* 通道号*/
    INT32 dwPresetID;                               /* 预置位编号*/
    BYTE  byRes[128];                               /* 保留字段 */
}NETDEV_CHANNEL_PRESET_S,*LPNETDEV_CHANNEL_PRESET_S;

/**
 * @struct tagNETDEVPresetActParamInfo
 * @brief 联动云台预置位
 * @attention
 */
typedef struct tagNETDEVPresetActParamInfo
{
    UINT32 udwNum;                                                      /* 联动动作数量*/
    NETDEV_CHANNEL_PRESET_S stChannelPreset[NETDEV_CHANNEL_MAX];        /* 联动到预置位信息列表*/
}NETDEV_PRESET_ACT_PARAM_INFO_S,*LPNETDEV_PRESET_ACT_PARAM_INFO_S;

/**
 * @struct tagNETDEVEnabledActParamInfo
 * @brief 使能联动参数
 * @attention
 */
typedef struct tagNETDEVEnabledActParamInfo
{
    BOOL    bEnabled;       /* 使能标记 */
    BYTE    byRes[64];      /* 保留字段 */
}NETDEV_ENABLED_ACT_PARAM_INFO_S, *LPNETDEV_ENABLED_ACT_PARAM_INFO_S;

/**
 * @enum tagNETDEVAlarmActID
 * @brief 使能联动参数
 * @attention
 */
typedef enum tagNETDEVAlarmActID
{
    ALARM_ACTION_TYPE_NVR_PREVIEW                = 0,                    /* 联动NVR预览，ActParam见NETDEV_CHANNEL_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_BUZZER                     = 1,                    /* 联动蜂鸣器，IPC暂不支持,NVR ActParam见NETDEV_ENABLED_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_E_MAIL                     = 2,                    /* 联动E-Mail，IPC暂不支持，NVR ActParam见NETDEV_ENABLED_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_RECORD                     = 3,                    /* 联动存储，IPC暂不支持，NVR ActParam见NETDEV_CHANNEL_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_PRESET                     = 4,                    /* 联动云台预置位，ActParam见NETDEV_PRESET_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_OUTPUT_SWITCH              = 5,                    /* 联动开关量输出，ActParam见NETDEV_OUTPUT_SWITCH_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_SNAP                       = 6,                    /* 联动抓拍，IPC无需填写ActParam ，NVR ActParam见NETDEV_CHANNEL_ACT_PARAM_INFO_S*/
    ALARM_ACTION_TYPE_BOX                        = 7,                    /* 告警弹框，IPC暂不支持，NVR ActParam见NETDEV_ENABLED_ACT_PARAM_INFO_S */
    ALARM_ACTION_TYPE_CENTER_RECORD              = 8,                    /* 联动中心存储，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_START_LOCAL_RECORD         = 9,                    /* 联动启动本地存储，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_STOP_LOCAL_RECORD          = 10,                   /* 联动停止本地存储，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_SNAP_UP_FTP                = 11,                   /* 联动抓拍上传FTP，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_SNAP_UP_EMAIL              = 12,                   /* 联动抓拍上传EMail，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_SNAP_UP_FTP_AND_EMAIL      = 13,                   /* 联动抓拍上传FTP和EMail，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_SMART_SNAP_UP              = 14,                   /* 智能联动抓拍上传，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_FACE_PIC_SNAP_UP           = 15,                   /* 联动人脸小图抓拍上传，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_ALARM_REPORT               = 16,                   /* 联动告警上报，IPC无需填写ActParam，NVR不支持 */
    ALARM_ACTION_TYPE_PTZ_ZOOM                   = 17,                   /* 联动云台变倍， */
    ALARM_ACTION_TYPE_INVALID                    = 0xff                  /* 无效参数 */
}NETDEV_ALARM_ACT_ID_E;


/**
 * @struct tagNETDEVLinkageActionList
 * @brief 联动动作列表
 * @attention
 */
typedef struct tagNETDEVLinkageActionInfo 
{
    UINT32  udwActID;                                                   /* 联动动作ID，参见枚举值NETDEV_ALARM_ACT_ID_E */
    NETDEV_ENABLED_ACT_PARAM_INFO_S  stEnabledInfo;                     /* 联动参数使能标记，适用于联动蜂鸣器、联动EMail、联动告警弹窗、 */
    NETDEV_OUTPUT_SWITCH_ACT_PARAM_INFO_S stOutputSwitchActParamInfo;   /* 联动开关量输出*/
    NETDEV_CHANNEL_ACT_PARAM_INFO_S stChannelActParamInfo;              /* 联动NVR预览、联动存储、联动抓拍 */
    NETDEV_PRESET_ACT_PARAM_INFO_S  stPresetActParamInfo;               /* 联动云台预置位 */
    BYTE  byRes[512];                                                   /* 保留字段 */
}NETDEV_LINKAGE_ACTION_INFO_S,*LPNETDEV_LINKAGE_ACTION_INFO_S;

/**
 * @struct tagNETDEVLinkageActionList
 * @brief 布控任务联动动作列表 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVLinkageActionList
{
    UINT32          udwNum;
    NETDEV_LINKAGE_ACTION_INFO_S stActionInfo[NETDEV_LEN_4];
    BYTE            byRes[256];
}NETDEV_LINKAGE_ACTION_LIST_S,*LPNETDEV_LINKAGE_ACTION_LIST_S;

/**
 * @struct tagNETDEVSwitchLinkageAction
 * @brief 开关量布控任务联动动作 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVSwitchLinkageAction
{
    UINT32                          udwSwitchIndex; /* 开关量索引 */
    NETDEV_LINKAGE_ACTION_LIST_S    stLinkageActionList;
    BYTE                            byRes[256];
}NETDEV_SWITCH_LINKAGE_ACTION_S,*LPNETDEV_SWITCH_LINKAGE_ACTION_S;

/**
 * @struct tagLinkageStrategy
 * @brief 告警联动配置信息 结构体定义
 * @attention 无 None
 */
typedef enum tagPersonCompareResult
{
    NETDEV_TYPE_COMPARE_SUCCESS = 1,
    NETDEV_TYPE_COMPARE_FAILED = 2,
    NETDEV_TYPE_COMPARE_INVALID = 0xff
}NETDEV_PERSON_COMPARE_RESULT_TYPE_E;

/**
 * @struct tagLinkageStrategy
 * @brief 告警联动配置信息 结构体定义
 * @attention 无 None
 */
typedef struct tagLinkageStrategy
{
    UINT32                          udwType;                /* 告警类型,NETDEV_PERSON_COMPARE_RESULT_TYPE_E */
    NETDEV_LINKAGE_ACTION_LIST_S    stLintageActions;       /* 人脸布控任务联动动作 */
    BYTE                            byRes[512];             /* 保留字段 */
}NETDEV_LINKAGE_STRATEGY_S, *LPNETDEV_LINKAGE_STRATEGY_S;

/**
 * @struct tagNETDEVMonitorDefenceInfo
 * @brief 布防信息 结构体定义
 * @attention 仅PTS VMS使用
 */
typedef struct tagNETDEVMonitorDefenceInfo
{
    INT64      tBegin;                  /* 时间模板生效起始时间(unix时间戳) */
    INT64      tEnd;                    /* 时间模板生效结束时间(unix时间戳) */
    UINT32     udwTimeTemplateID;       /* 时间模板索引，若未配置，则填写0 */
    BYTE       byRes[128];              /* 保留字段 */
}NETDEV_MONITOR_DEFENCE_INFO_S, *LPNETDEV_MONITOR_DEFENCE_INFO_S;

/**
 * @struct tagNETDEVFaceMonitorInfo
 * @brief 人脸布控任务信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMonitorInfo
{
    UINT32                              udwID;                        /* 人脸布控任务序号 */
    NETDEV_FACE_MONITION_RULE_INFO_S    stMonitorRuleInfo;            /* 人脸布控任务配置信息 */
    UINT32                              udwLinkStrategyNum;           /* 告警联动策略数量 */
    LPNETDEV_LINKAGE_STRATEGY_S         pstLinkStrategyList;          /* 告警联动策略配置信息，需动态分配内存*/
    NETDEV_VIDEO_WEEK_PLAN_S            stWeekPlan;                   /* 人脸布控任务布防计划,仅NVR IPC使用 */
    NETDEV_MONITOR_DEFENCE_INFO_S       stMonitorDefenceInfo;         /* 布防信息，仅PTS VMS使用 */
    BYTE                                byRes[250];                   /* 保留字段  Reserved */
}NETDEV_FACE_MONITION_INFO_S,*LPNETDEV_FACE_MONITION_INFO_S;

/**
 * @struct tagNETDEVFaceMonitorList
 * @brief 人脸布控任务列表 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMonitorList
{
    UINT32 udwNum;                                                    /* 人脸布控任务数量 */
    LPNETDEV_FACE_MONITION_INFO_S pstMonitorList;                     /* 人脸布控任务列表 该指针所指向内存需调用者分配*/
}NETDEV_FACE_MONITOR_LIST_S,*LPNETDEV_FACE_MONITOR_LIST_S;

/**
 * @struct tagstNETDEVFaceAlarmImageArea
 * @brief 区域坐标
 * @attention
 */
typedef struct tagstNETDEVFaceAlarmImageArea
{
    UINT32   udwLeft;          /* 左坐标 */
    UINT32   udwTop;           /* 上坐标 */
    UINT32   udwRight;         /* 右坐标 */
    UINT32   udwButtom;        /* 下坐标 */

    BYTE     byRes[128];       /* 保留字段  Reserved */
}NETDEV_FACE_ALARM_IMAGE_AREA_S, *LPNETDEV_FACE_ALARM_IMAGE_AREA_S;

/**
 * @struct tagstNETDEVFaceAlarmLogSnapImage
 * @brief 抓拍图片信息
 * @attention
 */
typedef struct tagstNETDEVFaceAlarmSnapImage
{
    NETDEV_FILE_INFO_S   stBigImage;                /* 大图 */
    NETDEV_FILE_INFO_S   stSmallImage;              /* 小图 */
    NETDEV_FACE_ALARM_IMAGE_AREA_S   stArea;        /* 区域坐标 */
    BYTE    byRes[128];                             /* 保留字段  Reserved */
}NETDEV_FACE_ALARM_SNAP_IMAGE_S, *LPNETDEV_FACE_ALARM_SNAP_IMAGE_S;


/**
* @struct tagNETDEVVehicleMonitorRuleInfo
* @brief 车辆布控任务配置信息 结构体定义
* @attention 无 None
*/
typedef struct tagNETDEVVehicleMonitorRuleInfo
{
    CHAR                        szName[NETDEV_LEN_260];                              /* 车辆布控任务的布控名称 */
    BOOL                        bEnabled;                                            /* 车辆布控任务使能 */
    INT64                       tBegin;                                              /* 开始时间 */
    INT64                       tEnd;                                                /* 结束时间 */
    UINT32                      udwMonitorReason;                                    /* 布控类型 参见枚举 NETDEV_VEHICLE_MONITOR_TYPE_E */
    CHAR                        szDescription[NETDEV_FACE_MONITOR_RULE_REASON_LEN];  /* 车辆布控任务的布控描述 */
    UINT32                      udwMonitorAlarmType;                                 /* 布控告警类型 */
    UINT32                      udwDatabaseID;                                       /* 车辆库ID */
    UINT32                      udwMemberNum;                                        /* 车辆成员数量[0~32] */
    NETDEV_MEMBER_INFO_S        stMemberInfo[NETDEV_LEN_64];                         /* 车辆成员信息 */
    BYTE                        byRes[128];                                          /* 保留字段  Reserved */
}NETDEV_VEHICLE_MONITION_RULE_INFO_S, *LPNETDEV_VEHICLE_MONITION_RULE_INFO_S;

/**
* @struct tagNETDEVVehicleMonitorInfo
* @brief 车辆布控任务信息 结构体定义 Vehicle monitoring task information Structure definition
* @attention 无 None
*/
typedef struct tagNETDEVVehicleMonitorInfo
{
    UINT32   udwMonitorID;                                            /* 车辆布控任务序号 */
    NETDEV_VEHICLE_MONITION_RULE_INFO_S stMonitorRuleInfo;            /* 车辆布控任务配置信息 */

    BYTE    byRes[128];                                               /* 保留字段  Reserved */

}NETDEV_VEHICLE_MONITION_INFO_S, *LPNETDEV_VEHICLE_MONITION_INFO_S;

/**
* @struct tagstNETDEVPlateAttrInfo
* @brief 车牌信息
* @attention
*/
typedef struct tagstNETDEVPlateAttrInfo
{
    CHAR     szPlateNo[NETDEV_LEN_16];                        /* 车牌号 */
    UINT32   udwColor;                                        /* 车牌颜色 参见NETDEV_PLATE_COLOR_E */
    UINT32   udwType;                                         /* 车牌类型，参见NETDEV_PLATE_TYPE_E */
    BYTE     byRes[64];                                       /* 保留字段  Reserved */
}NETDEV_PLATE_ATTR_INFO_S, *LPNETDEV_PLATE_ATTR_INFO_S;

/**
* @struct tagstNETDEVVehicleAttrInfo
* @brief 车辆信息
* @attention
*/
typedef struct tagstNETDEVVehicleAttrInfo
{
    UINT32   udwColor;          /* 车辆颜色 参见NETDEV_VEHICLE_COLOR_E */
    UINT32   udwType;           /* 车辆类型，参见NETDEV_VEHICLE_TYPE_E */
    FLOAT   udwSpeedValue;      /* 车辆速度 double */
    UINT32   udwSpeedUnit;      /* 车辆速度单位 参见枚举 NETDEV_VEHICLE_SPEED_UNIT_E */

    BYTE     byRes[64];         /* 保留字段  Reserved */
}NETDEV_VEHICLE_ATTR_INFO_S, *LPNETDEV_VEHICLE_ATTR_INFO_S;

/**
* @struct tagstNETDEVVehicleDetailInfo
* @brief 车辆成员信息
* @attention
*/
typedef struct tagstNETDEVVehicleDetailInfo
{
    UINT32                     udwReqSeq;                         /* 请求数据序列号 */
    UINT32                     udwMemberID;                       /* 人脸成员ID */
    NETDEV_PLATE_ATTR_INFO_S   stPlateAttr;                       /* 车牌信息 */
    NETDEV_VEHICLE_ATTR_INFO_S stVehicleAttr;                     /* 车辆信息 */
    NETDEV_FILE_INFO_S         stVehicleImage;                    /* 车牌图片 */
    BOOL                       bIsMonitored;                      /* 是否已布控 0未布控 1已布控 */
    UINT32                     udwDBNum;                          /* 所属车辆库数量 */
    UINT32                     audwDBIDList[NETDEV_LEN_16];       /* 所属车辆库ID数组 */
    BYTE                       byRes[128];                        /* 保留字段  Reserved */
}NETDEV_VEHICLE_DETAIL_INFO_S, *LPNETDEV_VEHICLE_DETAIL_INFO_S;
/**
* @struct tagstNETDEVVehicleRcordInfo
* @brief 车辆识别记录信息
* @attention
*/
typedef struct tagstNETDEVVehicleRcordInfo
{
    UINT32   udwRecordID;                                      /* 车辆识别记录ID */
    UINT32   udwChannelID;                                     /* 通道ID，抓拍推送时有效 */
    UINT32   udwEventType;                                     /* 上报事件类型，抓拍推送时必带。按BIT位进行类型描述，相应BIT为1，表示属于该类型，为0表示不属于该类型；BIT0：车辆抓拍 BIT1：车辆告警 */
    UINT32   udwMemberID;                                      /* 车辆成员ID，事件类型为车辆匹配告警时携带此字段 */
    UINT32   udwPassingTime;                                   /* 过车时间，UTC格式，单位秒*/
    UINT32   udwMonitorTime;                                   /* 布控时间，UTC格式，单位秒*/
    CHAR     szChannelName[NETDEV_LEN_260];                    /* 卡口相机名称 */
    UINT32   udwMonitorReason;                                 /* 布控原因类型,该记录为布控抓拍记录才有布控原因类型 参见NETDEV_VEHICLE_MONITOR_TYPE_E */
    NETDEV_PLATE_ATTR_INFO_S   stPlateAttr;                    /* 车牌抓拍信息 */
    NETDEV_VEHICLE_ATTR_INFO_S stVehicleAttr;                  /* 车辆抓拍信息 */
    NETDEV_FILE_INFO_S         stPlateImage;                   /* 车牌抓拍图片 */
    BYTE     byRes[128];                                       /* 保留字段  Reserved */
}NETDEV_VEHICLE_RECORD_INFO_S, *LPNETDEV_VEHICLE_RECORD_INFO_S;

/**
 * @struct tagNETDEVFaceMemberRegionInfo
 * @brief 人脸库成员地区信息 
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMemberRegionInfo
{
    CHAR   szNation[NETDEV_FACE_MEMBER_REGION_LEN];                       /* 国籍 */
    CHAR   szProvince[NETDEV_FACE_MEMBER_REGION_LEN];                     /* 省份 */
    CHAR   szCity[NETDEV_FACE_MEMBER_REGION_LEN];                         /* 城市 */
    BYTE   byRes[256];                                                    /* 保留字段  Reserved */

}NETDEV_FACE_MEMBER_REGION_INFO_S,*LPNETDEV_FACE_MEMBER_REGION_INFO_S;
/**
 * @struct tagNETDEVFaceMemberIDInfo
 * @brief 成员证件信息 
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMemberIDInfo
{
    UINT32   udwType;                                       /*证件类型 参见枚举 NETDEV_FACE_MEMBER_ID_TYPE_E */
    CHAR     szNumber[NETDEV_FACE_IDNUMBER_LEN];            /* 证件号 */

    BYTE    byRes[128];                                     /* 保留字段  Reserved */
}NETDEV_FACE_MEMBER_ID_INFO_S,*LPNETDEV_FACE_MEMBER_ID_INFO_S;

/**
 * @struct tagNETDEVFaceMemberInfo
 * @brief 人脸库成员信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFaceMemberInfo
{
    UINT32   udwReqSeq;                                                   /* 请求数据序号 */
    UINT32   udwMemberID;                                                 /*人脸库成员ID   只读 post消息时不带*/
    CHAR     szMemberName[NETDEV_FACE_MEMBER_NAME_LEN];                   /* 成员名称 */
    UINT32   udwMemberGender;                                             /* 成员性别 参见枚举 NETDEV_GENDER_TYPE_E */
    CHAR     szMemberBirthday[NETDEV_FACE_MEMBER_BIRTHDAY_LEN];           /* 成员出生日期 */
    NETDEV_FACE_MEMBER_REGION_INFO_S   stMemberRegionInfo;                /* 成员地区信息 */
    NETDEV_FACE_MEMBER_ID_INFO_S       stMemberIDInfo;                    /* 成员证件信息 */
    NETDEV_FILE_INFO_S                 stMemberImageInfo;                 /* 人脸图片信息 */
    NETDEV_FILE_INFO_S                 stMemberSemiInfo;                  /* 人脸半结构化信息 */
    UINT32   udwCustomNum;                                                /* 自定义属性值数量 */
    NETDEV_CUSTOM_VALUE_S   stCustomValue[NETDEV_FACE_MEMBER_CUSTOM_NUM];        /* 自定义属性值列表 */    
    BOOL      bIsMonitored;                                               /* 是否已布控  0未布控，1已布控 */
    UINT32    udwDBNum;                                                   /* 所属人脸库数量 */
    UINT32    audwDBIDList[NETDEV_LEN_16];                                /* 人脸库ID列表 */
    BYTE      byRes[128];                                                 /* 保留字段  Reserved */

}NETDEV_FACE_MEMBER_INFO_S,*LPNETDEV_FACE_MEMBER_INFO_S;

/**
 * @struct tagstNETDEVFaceAlarmCmpInfo
 * @brief 人脸抓拍告警记录比对信息
 * @attention
 */
typedef struct tagstNETDEVFaceAlarmCmpInfo
{
    UINT32                           udwSimilarity;               /* 相似度 */
    NETDEV_FACE_MEMBER_INFO_S        stMemberInfo;                /* 人脸库成员信息 */
    NETDEV_FACE_ALARM_SNAP_IMAGE_S   stSnapshotImage;             /* 抓拍图片 */

    BYTE    byRes[128];                                           /* 保留字段  Reserved */
}NETDEV_FACE_ALARM_CMP_INFO_S, *LPNETDEV_FACE_ALARM_CMP_INFO_S;


/**
 * @struct tagstNETDEVFaceRecordSnapshotInfo
 * @brief 人脸识别记录
 * @attention
 */
typedef struct tagstNETDEVFaceRecordSnapshotInfo
{
    UINT32   udwRecordID;                                       /* 人脸识别记录ID */
    UINT32   udwPassTime;                                       /* 过人时间 UTC格式 */
    UINT32   udwEventType;                                      /* 事件类型 按BIT位进行类型描述，相应BIT为1，表示属于该类型，为0表示不属于该类型。BIT0:人脸抓拍BIT1:人脸匹配告警BIT2:人脸不匹配告警*/
    UINT32   udwChannelID;                                      /* 通道ID */
    UINT32   udwMonitorRuleID;                                  /* 告警对应的布控ID */
    CHAR     szChannelName[NETDEV_LEN_260];                     /* 抓拍通道名称 */
    NETDEV_FACE_ALARM_CMP_INFO_S  stCompareInfo;                /* 比对信息 */
    BYTE     byRes[128];                                        /* 保留字段  Reserved */
}NETDEV_FACE_RECORD_SNAPSHOT_INFO_S, *LPNETDEV_FACE_RECORD_SNAPSHOT_INFO_S;

/**
 * @struct tagstNETDEVFaceAlarmLogResultInfo
 * @brief 告警记录返回信息（人脸识别和车牌识别）
 * @attention
 */
typedef struct tagstNETDEVSmartAlarmLogResultInfo
{
    UINT32   udwTotal;                     /* 告警记录总数 */
    UINT32   udwOffset;                    /* 记录偏移量 */
    UINT32   udwNum;                       /* 此次返回告警记录个数 */
    BYTE     byRes[128];                   /* 保留字段  Reserved */
}NETDEV_SMART_ALARM_LOG_RESULT_INFO_S, *LPNETDEV_SMART_ALARM_LOG_RESULT_INFO_S;

/**
* struct tagNETDEVSmartRecordCond
* @brief 智能回放录像查询条件
* @attention 无
*/
typedef struct tagNETDEVSmartRecordCond
{
    INT32       dwChannelID;                              /* 通道号 */
    UINT32      udwPosition;                              /* 录像位置 参见枚举#NETDEV_RECORD_LOCATION_E */
    UINT32      udwGridEnable;                            /* 1表示是宏块，0表示不是 */
    BYTE        awGridAreas[NETDEV_GRID_AREAS_LEN];       /* 宏块值 */
    INT64       tBeginTime;                               /* 起始时间(unix时间戳) */
    INT64       tEndTime;                                 /* 结束时间(unix时间戳) */
    UINT32      udwSensitivity;                           /* 灵敏度，范围1~8 */
    UINT32      udwServerID;                              /* 录像所属服务器ID Video server ID */
    BYTE        byRes[128];                               /* 保留字段  Reserved */      
}NETDEV_SMART_RECORD_COND_S, *LPNETDEV_SMART_RECORD_COND_S;


/**
 * @struct tagstNETDEV_VoiceBroadcastChlInfo
 * @brief 语音广播通道信息
 * @attention
 */
typedef struct tagstNETDEV_VoiceBroadcastChlInfo
{
    UINT32  dwChannelID;               /* 音频通道ID */
    UINT32  dwResultCode;              /* 广播通道状态码 */
    UINT32  dwStatus;                  /* 广播通道声音开启状态 */
}NETDEV_VOICE_BROADCAST_CHL_INFO_S, *LPNETDEV_VOICE_BROADCAST_CHL_INFO_S;

/**
 * @struct tagstNETDEV_VoiceBroadcastGroupInfo
 * @brief 语音广播组信息
 * @attention
 */
typedef struct tagstNETDEV_VoiceBroadcastGroupInfo
{
    INT32                                  dwSize;                                                        /* 广播组通道个数 */
    NETDEV_VOICE_BROADCAST_CHL_INFO_S      astChlInfoList[NETDEV_VOICE_BROADCAST_CHANNEL_NUM_MAX];        /* 所有通道信息 */
}NETDEV_VOICE_BROADCAST_GROUP_INFO_S, *LPNETDEV_VOICE_BROADCAST_GROUP_INFO_S;

/**
 * @struct tagstNETDEV_ModifyVoiceBroadcastInfo
 * @brief 修改语音广播组信息
 * @attention
 */
typedef struct NETDEV_ModifyVoiceBroadcastInfo
{
    LPNETDEV_OPERATE_LIST_S     pstAddChannelList;      /* 新增通道列表 */
    LPNETDEV_OPERATE_LIST_S     pstDelChannelList;      /* 删除通道列表 */
}NETDEV_MODIFY_VOICE_BROADCAST_INFO_S, *LPNETDEV_MODIFY_VOICE_BROADCAST_INFO_S;

/**
 * @struct tagstNETDEV_VoiceBroadcastCtrlInfo
 * @brief 语音广播组控制信息
 * @attention
 */
typedef struct tagstNETDEV_VoiceBroadcastCtrlInfo
{
    INT32   dwChannelID;             /* 通道ID */
    UINT32  udwStatus;               /* 声音状态,开(1),关(0) */
}NETDEV_VOICE_BROADCAST_CTRL_INFO_S, *LPNETDEV_VOICE_BROADCAST_CTRL_INFO_S;


/**
 * @struct tagNETDEVRecordLabel
 * @brief 录像标签信息
 * @attention
 */
typedef struct tagNETDEVRecordLabel
{
    INT32   dwChannelID;                            /* 通道ID */
    UINT32  udwTime;                                /* 标签时间 */
    CHAR    szLabelID[NETDEV_LABEL_ID_MAX_LEN];     /* 标签ID */
    CHAR    szDesc[NETDEV_DESCRIBE_MAX_LEN];        /* 标签描述 */
    UINT32  udwServerID;                            /* 标签所属服务器ID */
    BYTE    byRes[256];                             /* 保留字段 Reserved */
}NETDEV_RECOED_LABEL_S, *LPNETDEV_RECOED_LABEL_S;

/**
 * @struct tagNETDEVLabelDelete
 * @brief 录像标签基本信息
 * @attention
 */
typedef struct tagNETDEVLabelBase
{
    INT32   dwChannelID;                            /* 通道ID */
    CHAR    szLabelID[NETDEV_LABEL_ID_MAX_LEN];     /* 标签ID */
    UINT32  udwResult;                              /* 设备返回结果 参见 NETDEV_RECODE_LABEL_RESULT_E */
    UINT32  udwServerID;                            /* 标签所属服务器ID */
    BYTE    byRes[256];                             /* 保留字段 Reserved */
}NETDEV_LABEL_BASE_S, *LPNETDEV_LABEL_BASE_S;

/**
 * @struct tagNETDEVLabelBase
 * @brief 录像标签基本信息
 * @attention
 */
typedef struct tagNETDEVLabelBaseList
{
    UINT32                  udwPosition;              /* 标签位置 参见 NETDEV_RECORD_LOCATION_E */
    UINT32                  udwSize;                  /* 标签数量 */
    LPNETDEV_LABEL_BASE_S   pstLabelBase;             /* 标签基本信息 */
    UINT32                  udwLabelFailNum;           /* 返回失败的标签数量 */
}NETDEV_LABEL_BASE_LIST_S, *LPNETDEV_LABEL_BASE_LIST_S;

 /**
 * @struct tagNETDEVLabelFindData
 * @brief 录像标签查询信息
 * @attention
 */
typedef struct tagNETDEVLabelFindData
{
    UINT32  udwPosition;               /* 标签位置 参见 NETDEV_RECORD_LOCATION_E */
    UINT32  udwChannelNum;             /* 查询通道数量 */
    INT32   *pdwChannelID;             /* 查询通道号 用户分配内存 */
    INT64   tBeginTime;               /* 起始时间  Start time */
    INT64   tEndTime;                 /* 结束时间  End time */
    CHAR    szDesc[NETDEV_DESCRIBE_MAX_LEN]; /* 标签关键字 */
}NETDEV_LABEL_FINDDATA_S, *LPNETDEV_LABEL_FINDDATA_S;

/**
 * @struct tagRecordSectionInfo
 * @brief 锁定录像段信息
 * @attention
 */
typedef struct tagRecordSectionInfo
{
    CHAR    szLockDecs[NETDEV_RECORD_LOCK_DESC_LEN];                 /* 锁定录像段的描述 */
    INT64   tBeginTime;                                              /* 起始时间  Start time */
    INT64   tEndTime;                                                /* 结束时间  End time */
    UINT32  udwServerID;                                             /* 标签所属服务器ID */
    BYTE    byRes[256];                                              /* 保留字段 */
}NETDEV_RECORD_SECTION_INFO_S,* LPNETDEV_RECORD_SECTION_INFO_S;

/**
 * @struct tagstNETDEVLockIDInfo
 * @brief 锁定ID
 * @attention
 */
typedef struct tagstNETDEVLockIDInfo
{
    CHAR    szLockIDInfo[NETDEV_RECORD_LOCK_ID_LEN];                  /* 锁定ID */
    UINT32  udwServerID;                                              /* 标签所属服务器ID */
    BYTE    byRes[256];                                               /* 保留字段 */
}NETDEV_LOCK_ID_INFO_S, *LPNETDEV_LOCK_ID_INFO_S;

/**
 * @struct tagstNETDEVLockIDList
 * @brief 锁定ID列表
 * @attention
 */
typedef struct tagstNETDEVLockIDList
{
    INT32                       dwSize;             /* 锁定ID个数 */
    LPNETDEV_LOCK_ID_INFO_S     pszLockIDInfo;      /* 锁定ID列表，动态申请dwsize内存*/
}NETDEV_LOCK_ID_LIST_S, *LPNETDEV_LOCK_ID_LIST_S;




/**
 * @struct tagRecordLockQryInfo
 * @brief 锁定录像查询信息
 * @attention
 */
typedef struct tagNETDEVRecordLockQryInfo
{
    UINT32              udwPosition;        /* 录像查询位置 */
    INT64               tBeginTime;         /* 起始时间  Start time */
    INT64               tEndTime;           /* 结束时间  End time */
    NETDEV_CHANNELS_S   stChannels;         /* 多通道ID */
    BYTE                byRes[256];         /* 保留字段 */
}NETDEV_RECORD_LOCK_FIND_COND_S,* LPNETDEV_RECORD_LOCK_FIND_COND_S;

/**
 * @struct tagRecordLockInfo
 * @brief 锁定录像信息
 * @attention
 */
typedef struct tagNETDEVRecordLockInfo
{
    NETDEV_LOCK_ID_INFO_S           stLockIDInfo;               /* 录像锁定ID */
    INT32                           dwChannelID;                /* 通道ID */
    NETDEV_RECORD_SECTION_INFO_S    stRecordSectionInfo;        /*录像段信息*/
    BYTE                            byRes[256];                 /* 保留字段 */
}NETDEV_RECORD_LOCK_INFO_S,* LPNETDEV_RECORD_LOCK_INFO_S;

/** 
 * @struct tagNETDEVAddress
 * @brief 地址 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVAddress
{
    UINT32  udwAddressType;                     /* 地址类型,参见枚举#NETDEV_ADDRESS_TYPE_E */
    CHAR    szAddress[NETDEV_IP_ADDRESS_LEN];   /* 地址 */
    BYTE    byRes[256];                         /* 保留字段  Reserved */
}NETDEV_ADDRESS_S,*LPNETDEV_ADDRESS_S;

/** 
 * @struct tagNETDEVHotStandbyParam
 * @brief 热备配置参数 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVHotStandbyParam
{
    UINT32              udwVirtualRouterID;                              /* 虚拟路由ID */
    CHAR                szVirtualNETMask[NETDEV_IP_ADDRESS_LEN];         /* 网络掩码 */
    UINT32              udwCleanupFlag;                                  /* 报警日志数据清除标志,参见枚举#NETDEV_ALARM_LOG_CLEANUP_FLAG_E */
    NETDEV_ADDRESS_S    stMasterAddress;                                 /* 主机地址 */
    NETDEV_ADDRESS_S    stBackupAddress;                                 /* 备机地址 */
    NETDEV_ADDRESS_S    stVirtualAddress;                                /* 虚拟地址 */
    BYTE                byRes[256];                                      /* 保留字段  Reserved */
}NETDEV_HOTSTANDBY_PARAM_S,*LPNETDEV_HOTSTANDBY_PARAM_S;

/**
 * @struct tagNETDEVMasterSlaveState
 * @brief 一体机主从状态 结构体定义 VMS Master_Slave State Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVMasterSlaveState
{
    UINT32                      udwMode;                             /* 主从模式,参见枚举#NETDEV_VMS_MODE_E */
    UINT32                      udwStatus;                           /* 主从服务器的状态,参见枚举#NETDEV_VMS_STATUS_E */
    NETDEV_ADDRESS_S            stVMSAddress;                        /* 一体机地址 */
    UINT32                      udwHotStandbyMode;                   /* 热备模式,参见枚举#NETDEV_VMS_HOTSTANDBYMODE_E */
    NETDEV_HOTSTANDBY_PARAM_S   stHotStandbyParam;                   /* 热备配置设置和获取的参数 */
    UINT32                      udwOldHotStandbyMode;                /* 原先配置文件中的主备模式,参见枚举#NETDEV_VMS_HOTSTANDBYMODE_E */
    BYTE                        byRes[256];                          /* 保留字段 */
}NETDEV_MASTER_SLAVE_STATE_S,*LPNETDEV_MASTER_SLAVE_STATE_S;




/**
 * @struct tagNETDEVVodFile
 * @brief 录像文件 结构体定义 Recording file Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVVodFile
{
    CHAR                    szFileName[NETDEV_NAME_MAX_LEN];        /* 录像文件名  Recording file name */
    NETDEV_STORE_TYPE_E     enType;                                 /* 录像存储类型  Recording storage type */
    INT64                   tBeginTime;                             /* 起始时间  Start time */
    INT64                   tEndTime;                               /* 结束时间  End time */
}NETDEV_VOD_FILE_S, *LPNETDEV_VOD_FILE_S;


/**
 * @struct tagNETDEVPictureDataEx
 * @brief 图像数据 结构体定义 Image data Structure definition
 *        存放解码后图像数据的指针和长度等信息 Storing pointer and length of decoded picture data
 * @attention 无 None
 */
typedef struct tagNETDEVPictureDataEx
{
    BYTE    *pucData[4];                /* pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针  pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32   dwLineSize[4];              /* ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距  ulLineSize[0]: Y line spacing, ulLineSize[1]: U line spacing, ulLineSize[2]: V line spacing */
    INT32   dwPicHeight;                /* 图片高度  Picture height */
    INT32   dwPicWidth;                 /* 图片宽度  Picture width */
    INT32   dwRenderTimeType;           /* 用于渲染的时间数据类型  Time data type for rendering */
    INT64   tRenderTime;                /* 用于渲染的时间数据  Time data for rendering */
    INT32   dwFrameRate;                /* 帧率 */
    BYTE    byRes[32];                  /* 保留字段 */
}NETDEV_PICTURE_DATA_EX_S, *LPNETDEV_PICTURE_DATA_EX_S;



/**
* @struct tagstNETDEVGpuAbleState
* @brief GPU使能状态结构体
* @attention 无
*/
typedef struct tagstNETDEVGpuAbleState
{
    BOOL bGpuAbleH264;            /* GPU使能-H.264标准*/
    BOOL bGpuAbleH265;            /* GPU使能-H.265标准 */
    BOOL bGpuAbleMJPEG;           /* GPU使能-MJEGP标准 */
    BOOL bGpuAbleMPEG2;           /* GPU使能-MPEG-2标准 */
    BOOL bGpuAbleMPEG4;           /* GPU使能-MPEG-4标准 */
    BOOL bReserved1;              /* 预留类型1 */
    BOOL bReserved2;              /* 预留类型2 */
    BOOL bReserved3;              /* 预留类型3 */
}NETDEV_GPU_ABLESTATE_S,*LPNETDEV_GPU_ABLESTATE_S;

/**
 * @struct tagstNETDEVXWEncodeChnProperty
 * @brief 本地编码通道通道属性
 * @attention
 */
typedef struct tagstNETDEVXWEncodeChnProperty
{
    INT32 dwVideoSrc;                                     /* 视频输入格式 NETDEV_VIDEO_SRC_TYPE_E */
    BYTE   byRes[512];
}NETDEV_XW_ENCODE_CHN_PROPERTY_S, *LPNETDEV_XW_ENCODE_CHN_PROPERTY_S;



/**
 * @struct tagNETDEVLogFindCondV30
 * @brief 日志查询条件 结构体定义 Log query condition Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVLogFindCondV30
{
    NETDEV_LOG_MAIN_TYPE_E  enMainType;         /* 主类型  Main type */
    NETDEV_LOG_SUB_TYPE_E   enSubType;          /* 次类型  Sub type */
    INT64                   tBeginTime;         /* 起始时间  Start time */
    INT64                   tEndTime;           /* 结束时间  End time */
}NETDEV_LOG_FIND_COND_V30_S, *LPNETDEV_LOG_FIND_V30_COND_S;


/**
 * @struct tagstNETDEVUserLogInfo
 * @brief 用户登录信息
 * @attention
 */
typedef struct tagstNETDEVUserLogInfo
{
    CHAR   szUserName[NETDEV_USERNAME_LEN];                     /* 用户名 */
    INT32  dwUserHandle;                                        /* 用户ID(登录句柄) */
    NETDEV_IPADDR_INFO_S   stUserIPAddr;                        /* 用户IP地址 */
}NETDEV_USER_LOG_INFO_S, *LPNETDEV_USER_LOG_INFO_S;

/**
 * @struct tagstNETDEVUserEventType
 * @brief 用户事件类型
 * @attention
 */
typedef struct tagstNETDEVUserEventType
{
    INT32 dwMajorType;                                  /* 主类型 */
    INT32 dwMinorType;                                  /* 子类型 */
}NETDEV_USER_EVENT_TYPE_S, *LPNETDEV_USER_EVENT_TYPE_S;

/**
 * @struct tagstNETDEVEventNotifyInfo
 * @brief 事件订阅信息
 * @attention
 */
typedef struct tagstNETDEVEventNotifyInfo
{    
    NETDEV_USER_EVENT_TYPE_S    stEventType;            /* 事件类型 */
    INT32 dwParamLen;                                   /* 参数长度 */
}NETDEV_EVENT_NOTIFY_TYPE_S, *LPNETDEV_EVENT_NOTIFY_TYPE_S;

/**
 * @struct tagstNETDEVDateInfo
 * @brief 时间信息
 * @attention
 */
typedef struct tagstNETDEVDateInfo
{
    INT32     dwYear;                               /* 所在年份 */
    INT32     dwMonth;                              /* 所在月份 */
    INT32     dwDay;                                /* 具体日期 */
    INT32     dwHour;                               /* 具体小时 */
    INT32     dwMinute;                             /* 具体分钟 */
    BYTE      byRes[32];                            /* 保留字段 */
}NETDEV_DATE_INFO_S, *LPNETDEV_DATE_INFO_S;

/**
 * @struct tagNETDEVDeviceBaseInfo
 * @brief 设备信息
 * @attention 无
 */
typedef struct tagNETDEVDeviceBaseInfo
{
    INT32 dwChlID;                                          /* 视频输入通道号  Video input channel ID */
    INT32 dwDeviceType;                                     /* 设备类型  Device Type */
    INT32 dwDevCode;                                        /* 设备编号  Device code */
    INT32 dwCurrentLang;                                    /* 设备当前语言 参见枚举#NETDEV_LANG_TYPE_E Current language NETDEV_LANG_TYPE_E*/
    NETDEV_DATE_INFO_S stBuildDate;                         /* 发布时间  Release time */
    CHAR szSerialNum[NETDEV_LEN_32];                        /* 设备序列号  Device serial number */
    CHAR szMacAddress[NETDEV_LEN_64];                       /* IPv4的Mac地址  MAC address of IPv4 */
    CHAR szDevName[NETDEV_CODE_STR_MAX_LEN];                /* 设备名称  Device name */
    CHAR szDevModel[NETDEV_CODE_STR_MAX_LEN];               /* 设备型号  Device model */
    CHAR szVIIDVersion[NETDEV_CODE_STR_MAX_LEN];            /* 视图库组件版本号  VIIDVersion version */
    CHAR szSoftwareVersion[NETDEV_CODE_STR_MAX_LEN];        /* 内部软件版本 Internal software version */
    CHAR szFirmwareVersion[NETDEV_CODE_STR_MAX_LEN];        /* 软件版本号  Software version */
    CHAR szHardewareID[NETDEV_CODE_STR_MAX_LEN];            /* 硬件标识  Hardware ID */
    CHAR szUbootVersion[NETDEV_CODE_STR_MAX_LEN];           /* UBOOT引导版本  UBOOT version */
    CHAR szManufacturer[NETDEV_LEN_64];                     /* 厂商名称，字符串长度[1,64]  Manufacturer */

    BYTE byRes[512];                                        /* 保留字段 Reserved */
}NETDEV_DEVICE_BASE_INFO_S, *LPNETDEV_DEVICE_BASE_INFO_S;

/************************************************************************/
/*                            组织 ORG                                 */
/************************************************************************/

/**
 * @struct tagstNETDEVOrgChnShortInfo
 * @brief 组织下通道数量信息
 * @attention
 */
typedef struct tagstNETDEVOrgChnShortInfo
{
    INT32 dwOrgID;              /* 组织ID */
    INT32 dwChannelsNum;        /* 通道个数 */
    INT32 *pdwChnIDs;           /* 通道ID 指针 根据通道个数动态申请内存 */

    BYTE  byRes[68];            /* 保留字段  Reserved field*/
}NETDEV_ORG_CHN_SHORT_INFO_S, *LPNETDEV_ORG_CHN_SHORT_INFO_S;


/**
 * @struct tagstNETDEVOrgDetailInfo
 * @brief 待删除组织详细信息
 * @attention
 */
typedef struct tagstNETDEVDelOrgDetailInfo
{    
    INT32 dwOrgNum;     /* 组织数量 */
    INT32 *pdwOrgIDs;   /* 需要删除的组织ID，根据dwOrgNum 动态申请 */
    BYTE  byRes[68];    /* 保留字段  Reserved field*/
}NETDEV_DEL_ORG_INFO_S, *LPNETDEV_DEL_ORG_INFO_S;

/**
 * @struct tagstNETDEVOrgDelDetailInfo
 * @brief 批量删除组织返回信息
 * @attention
 */
typedef struct tagstNETDEVOrgDelDetailInfo
{    
    INT32 dwStatus;                             /* 响应状态，类型 参见 NETDEV_ORG_RESPONSE_STAUTE_E */
    INT32 dwNum;                                /* 响应数量 */
    LPNETDEV_OPERATE_INFO_S pstResultInfo;      /*批量删除返回信息，根据删除数量动态申请*/

    BYTE  byRes[68];                            /* 保留字段  Reserved field*/
}NETDEV_ORG_BATCH_DEL_INFO_S, *LPNETDEV_ORG_BATCH_DEL_INFO_S;


/**
 * @struct tagNETDEVDCPlaybackCond
 * @brief DC录像回放参数 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVDCPlaybackCond
{
    INT32   dwChannelID;                    /* 通道ID  Channel ID */
    INT32   dwTVWallID;                     /* 电视墙ID */
    INT32   dwWinIndex;                     /* 窗口索引 */
    INT32   dwSubWinIndex;                  /* 子窗口索引 */
    INT32   dwStreamType;                   /* 流类型,#参见NETDEV_STREAM_TYPE_E */
    INT64   tBeginTime;                     /* 开始时间 */
    INT64   tEndTime;                       /* 结束时间 */
    INT32   dwTransProto;                   /* 传输协议,#参见NETDEV_TRANSPORT_PROTOCOL_E */
    INT32   dwRecordType;                   /* 录像类型,.参见#NETDEV_STORE_TYPE_E */
    INT32   dwRecordLocation;               /* 录像存储位置，参见#NETDEV_RECORD_LOCATION_E */
    BOOL    bRealtimeSync;                  /* 是否即时生效 */
    CHAR    szUrl[NETDEV_LEN_260];          /* 回放Url */
    BYTE    byRes[196];                     /* 保留字段  Reserved */
}NETDEV_DC_PLAYBACK_COND_S, *LPNETDEV_DC_PLAYBACK_COND_S;

/**
 * @struct tagNETDEVDCPlaybackCond
 * @brief DC录像回放转发回显参数 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVDCTransWinCond
{
    INT32   dwChannelID;                /* 被绑定的编码通道ID */
    UINT32  udwSessionID;               /* 回放的业务号 */
    INT64   tBeginTime;                 /* 回放开始时间 */
    INT64   tEndTime;                   /* 回放结束时间 */
    INT32   dwLinkMode;                 /* 传输协议，参见枚举#NETDEV_TRANS_PROTOCAL_E */
    LPVOID  hPlayWnd;                   /* 回显的窗格句柄 */
    INT32   dwTransType;                /* 传输类型，参见枚举#NETDEV_TRANS_TYPE_E */
    BYTE    byRes[124];                 /* 保留字段 */
}NETDEV_DC_TRANS_WIN_COND_S, *LPNETDEV_DC_TRANS_WIN_COND_S;




/**
 * @struct tagstNETDEVAlarmPlanAlarmSrcInfo
 * @brief 告警预案告警源信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanAlarmSrcInfo
{
    INT32 dwAlarmType;          /* 告警类型 */
    INT32 dwAlarmSubType;       /* 告警子类型 */
    INT32 dwAlarmSrcID;         /* 告警源ID */
}NETDEV_ALARM_PLAN_ALARMSRCINFO_S, *LPNETDEV_ALARM_PLAN_ALARMSRCINFO_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkPreset
 * @brief 告警预案联动预置位信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkPreset
{
    INT32 dwChnID;      /* 联动预置位通道ID */
    INT32 dwPresetID;   /* 联动预置位序号 */
}NETDEV_ALARM_PLAN_LINKPRESET_S, *LPNETDEV_ALARM_PLAN_LINKPRESET_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkSwitchOut
 * @brief 告警预案联动开关量输出信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkSwitchOut
{
    INT32   dwSwitchOutChnID; /* 联动开关量输出通道号ID */
    BYTE    byRes[256];
}NETDEV_ALARM_PLAN_LINKSWITCHOUT_S, *LPNETDEV_ALARM_PLAN_LINKSWITCHOUT_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkMonitor
 * @brief 告警预案联动实况信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkMonitor
{
    INT32 dwChnID;                          /* 联动实况通道号ID */
    INT32 dwMonitorDelay;                   /* 联动实况持续时间 单位s */
}NETDEV_ALARM_PLAN_LINKMONITOR_S, *LPNETDEV_ALARM_PLAN_LINKMONITOR_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkTvwall
 * @brief 联动报警上墙信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkTvwall
{
    INT32 dwTaskID;                          /* 报警上墙任务ID */
    INT32 dwTaskDelayTime;                   /* 持续时间 */
}NETDEV_ALARM_PLAN_LINKTVWALL_S, *LPNETDEV_ALARM_PLAN_LINKTVWALL_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkRuleInfo
 * @brief 告警预案联动规则信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkRuleInfo
{
    INT32 dwLinkType;                                                                   /* 联动类型(比特位操作)，参见#NETDEV_ALARM_LINK_TYPE_E */
    INT32 dwLinkPresetSize;                                                             /* 联动预置位数量*/
    NETDEV_ALARM_PLAN_LINKPRESET_S astLinkPreset[NETDEV_ALARM_LINK_PRESET_NUM];         /* 预置位详细信息*/
    INT32 dwSwitchOutSize;                                                              /* 联动告警输出通道数量*/
    NETDEV_ALARM_PLAN_LINKSWITCHOUT_S astSwitchOut[NETDEV_ALARM_LINK_SWITCHOUT_NUM];    /* 联动告警输出通道信息*/
    INT32 dwLinkMonitorSize;                                                            /* 联动实况数量*/
    NETDEV_ALARM_PLAN_LINKMONITOR_S astLinkMonitor[NETDEV_ALARM_LINK_MONITOR_NUM];      /* 联动实况信息*/
    INT32 dwLinkTVWallSize;                                                             /* 联动电视墙个数*/
    NETDEV_ALARM_PLAN_LINKTVWALL_S astLinkTVWall[NETDEV_ALARM_LINK_TVWALL_NUM];         /* 联动报警上墙信息*/
    CHAR szLinkSoundInfo[NETDEV_ALARM_LINK_SOUND_LEN];                                  /* 联动声音信息 */
}NETDEV_ALARM_PLAN_LINKRULEINFO_S, *LPNETDEV_ALARM_PLAN_LINKRULEINFO_S;

/**
 * @struct tagstNETDEVAlarmPlanLinkInfo
 * @brief 告警预案联动信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanLinkInfo
{
    INT32 dwLinkRuleID;                                                         /* 联动规则ID */
    INT32 dwAlarmSrcSize;                                                       /* 告警源数量 */
    NETDEV_ALARM_PLAN_ALARMSRCINFO_S astAlarmSrc[NETDEV_ALARM_SOURCE_NUM];      /* 告警源信息 */
    NETDEV_ALARM_PLAN_LINKRULEINFO_S stLinkRuleInfo;                            /* 联动规则信息 */
}NETDEV_ALARM_PLAN_LINKINFO_S, *LPNETDEV_ALARM_PLAN_LINKINFO_S;

/**
 * @struct tagstNETDEVAlarmPlanDetailInfo
 * @brief 告警预案详细信息
 * @attention
 */
typedef struct tagstNETDEVAlarmPlanDetailInfo
{
    INT32   dwPlanType;                                                 /* 告警布防预案类型 */
    INT32   dwPlanID;                                                   /* 预案ID */
    CHAR    szPlanName[NETDEV_NAME_MAX_LEN];                            /* 预案名称 */
    INT32   dwTimeTamplateID;                                           /* 时间模板ID */
    CHAR    szPlanDesc[NETDEV_DESCRIBE_MAX_LEN];                        /* 预案描述 */
    BOOL    bEnable;                                                    /* 是否启用预案 */
    INT32   dwLinkInfoSize;                                             /* 预案联动数量信息 */
    NETDEV_ALARM_PLAN_LINKINFO_S astLinkInfo[NETDEV_ALARM_LINK_NUM];    /* 预案联动信息 */
}NETDEV_ALARM_PLAN_DETAILINFO_S, *LPNETDEV_ALARM_PLAN_DETAILINFO_S;


/**
 * @struct tagstNETDEVTimeTemplate
 * @brief 时间模板信息
 * @attention
 */
typedef struct tagstNETDEVTimeTemplate
{
    CHAR    szTamplateName[NETDEV_NAME_MAX_LEN];        /* 模板名称 */
    CHAR    szTamplateDesc[NETDEV_DESCRIBE_MAX_LEN];    /* 模板描述 */
    INT32   dwTamplateID;                               /* 模板ID */
}NETDEV_TIME_TEMPLATE_S, *LPNETDEV_TIME_TEMPLATE_S;

/**
 * @struct tagstNETDEVTimeTemplateList
 * @brief 时间模板列表
 * @attention
 */
typedef struct tagstNETDEVTimeTemplateList
{
    INT32   dwSize;                                                         /* 模板大小 */
    NETDEV_TIME_TEMPLATE_S astTimeTemplate[NETDEV_TIME_TEMPLATE_NUM];       /* 时间模板信息 */
}NETDEV_TIME_TEMPLATE_LIST_S, *LPNETDEV_TIME_TEMPLATE_LIST_S;


/**
 * @struct tagstNETDEVViewBasicInfo
 * @brief 轮巡预案基本信息
 * @attention
 */
typedef struct tagstNETDEVViewBasicInfo
{
    INT32   dwPlanID;                                           /* 预案ID */
    CHAR    szPlanName[NETDEV_NAME_MAX_LEN];                    /* 预案名称 */
    CHAR    szPlanDesc[NETDEV_DESCRIBE_MAX_LEN];                /* 预案描述 */
    INT32   dwLayout;                                           /* 分屏模式, 参见#NETDEV_LAYOUT_TYPE_E */
    BYTE    byRes[128];                                         /* 保留字段  Reserved */
}NETDEV_VIEW_BASIC_INFO_S, *LPNETDEV_VIEW_BASIC_INFO_S;

/**
 * @struct tagstNETDEVScenesTimeTable
 * @brief 轮巡计划时间表模式信息
 * @attention
 */
typedef struct tagstNETDEVScenesTimeTable
{
    UINT32   udwScenseID;                             /* 场景ID */
    CHAR     szStartTime[NETDEV_LEN_16];              /* 开始时间 HH:MM     最大长度: 8*/
    BYTE     byRes[128];                              /* 保留字段  Reserved */
}NETDEV_SCENES_TIME_TABLE_INFO_S, *LPNETDEV_SCENES_TIME_TABLE_INFO_S;

/**
 * @struct tagstNETDEVScenesPlanInfo
 * @brief 轮巡计划信息
 * @attention
 */
typedef struct tagstNETDEVScenesPlanInfo
{
    NETDEV_VIEW_BASIC_INFO_S         stScenesBasicInfo;                  /* 轮巡预案基本信息 */
    UINT32   udwStatus;                                                  /* 计划状态 参见 NETDEV_DC_SEQ_STATUS_E */
    UINT32   udwPlanMode;                                                /* 计划方式  0：定时切换 1：24小时计划表 参见枚举NETDEV_PLANS_MODE_E */
    UINT32   udwInterval;                                                /* 时间间隔（属于定时切换模式信息）, 单位：秒， 当PlanMode为0时必选 */
    UINT32   udwSceneNum;                                                /* 场景个数（属于定时切换模式信息）   当PlanMode为0时必选*/
    UINT32   audwSceneID[NETDEV_LEN_1024];                               /* 场景ID列表（属于定时切换模式信息）  当PlanMode为0时必选*/
    UINT32   udwTimeTableNum;                                            /*时间表模式成员个数*/
    NETDEV_SCENES_TIME_TABLE_INFO_S   astTimeTable[NETDEV_LEN_1024];     /* 时间表模式信息列表  当PlanMode为1时必选*/
    BYTE     byRes[128];                                                 /* 保留字段  Reserved */
}NETDEV_SCENES_PLAN_INFO_S, *LPNETDEV_SCENES_PLAN_INFO_S;

/**
 * @struct tagstNETDEVResInfo
 * @brief 轮巡资源信息
 * @attention
 */
typedef struct tagstNETDEVResInfo
{
    INT32   dwWinIndex;                                                 /* 窗口索引 */
    INT32   dwResType;                                                  /* 资源类型 参考枚举#NETDEV_VIEW_TYPE_E*/
    INT32   dwResID;                                                    /* 资源ID */
    INT32   dwStreamIndex;                                              /* 码流索引 */
    INT32   dwPresetID;                                                 /* 预置位ID */
}NETDEV_RES_INFO_S, *LPNETDEV_RES_INFO_S;

/**
 * @struct tagstNETDEVViewDetailInfo
 * @brief 视图详细信息
 * @attention
 */
typedef struct tagstNETDEVViewDetailInfo
{
    NETDEV_VIEW_BASIC_INFO_S       stBasicInfo;                                      /* 基本信息 */
    INT32                          dwViewResSize;                                    /* 视图资源数量 */
    NETDEV_RES_INFO_S              astViewResInfo[NETDEV_VIEW_MAX_WIN_NUM];          /* 视图资源详细信息 */
}NETDEV_VIEW_DETAIL_INFO_S, *LPNETDEV_VIEW_DETAIL_INFO_S;


/**
 * @struct tagstNETDEVViewPlanModeInfo
 * @brief 视图计划模式详细信息
 * @attention
 */
typedef struct tagstNETDEVViewPlanModeInfo
{
    UINT32   udwViewID;                                                  /* 视图ID*/
    UINT32   udwInterval;                                                /* 时间间隔 模式为定时切换模式时必选，单位：秒*/
    CHAR     szStartTime[NETDEV_LEN_16];                                 /* 开始时间时 模式为时间表模式时必选，HH:MM， 长度范围：[1, 8]*/
    BYTE     byRes[128];                                                 /* 保留字段  Reserved */
}NETDEV_VIEW_PLAN_MODE_INFO_S, *LPNETDEV_VIEW_PLAN_MODE_INFO_S;

/**
 * @struct tagstNETDEVViewPlanInfo
 * @brief 视图计划信息
 * @attention
 */
typedef struct tagstNETDEVViewPlanInfo
{
    NETDEV_VIEW_BASIC_INFO_S         stScenesBasicInfo;                     /* 轮巡预案基本信息 */
    UINT32   udwStatus;                                                     /* 计划状态 参见 NETDEV_DC_SEQ_STATUS_E*/
    UINT32   udwPlanMode;                                                   /* 计划方式  0：定时切换 1：24小时计划表, 参见枚举NETDEV_PLANS_MODE_E*/
    NETDEV_VIEW_PLAN_MODE_INFO_S    astViewPlanInfoList[NETDEV_LEN_1024];                   /*计划信息列表 根据udwPlanMode 进行对应内容的填充*/
    UINT32   udwPlanNum;                                                    /* 计划信息列表中计划的个数*/
    BYTE     byRes[128];                                                    /* 保留字段  Reserved */
}NETDEV_VIEW_PLAN_INFO_S, *LPNETDEV_VIEW_PLAN_INFO_S;

/**
 * @struct tagstNETDEVEMapPicInfo
 * @brief 电子地图 图片信息
 * @attention 
 */
typedef struct tagstNETDEVEMapPicInfo
{
    INT32   dwPicID;                                /* 图片ID */
    CHAR    szPicName[NETDEV_NAME_MAX_LEN];         /* 图片名称 */
    CHAR    szFileName[NETDEV_NAME_MAX_LEN];        /* 图片文件名称 */
    INT32   dwInfo;                                 /* 标识信息 */
}NETDEV_EMAP_PIC_INFO_S, *LPNETDEV_EMAP_PIC_INFO_S;

/**
 * @struct tagstNETDEVEMapHotPotInfo
 * @brief 电子地图 热点/热区信息
 * @attention 
 */
typedef struct tagstNETDEVEMapHotPotInfo
{
    INT32   dwID;                                   /* 热点/热区ID */
    INT32   dwParentID;                             /* 父热区ID */
    INT32   dwType;                                 /* 热点 or 热区，参见#NETDEV_EMAP_HOTPOT_TYPE_E */
    INT32   dwLinkID;                               /* 热区时为地图ID，热点是为通道ID */
    INT32   dwStyle;                                /* 样式 */
    INT32   dwPosX;                                 /* 水平坐标 */
    INT32   dwPosY;                                 /* 垂直坐标 */
    CHAR    szName[NETDEV_NAME_MAX_LEN];            /* 热点/热区名称 */
}NETDEV_EMAP_HOTPOT_INFO_S, *LPNETDEV_EMAP_HOTPOT_INFO_S;

/**
 * @struct tagstNETDEVDCSchemeResInfo
 * @brief DC轮巡资源基本信息
 * @attention 
 */
typedef struct tagstNETDEVDCSchemeResInfo
{
    INT32   dwResID;                                    /* 资源ID 添加时不需要 */
    BOOL    bEnable;                                    /* 轮巡是否使能 */
    CHAR    szName[NETDEV_NAME_MAX_LEN];                /* 轮巡资源名称 */
    CHAR    szDesc[NETDEV_DESCRIBE_MAX_LEN];            /* 轮巡资源描述 */
}NETDEV_DC_SCHEME_RES_INFO_S, *LPNETDEV_DC_SCHEME_RES_INFO_S;

/**
 * @struct tagstNETDEVDCSchemeResChnInfo
 * @brief DC轮巡资源通道信息
 * @attention
 */
typedef struct tagstNETDEVDCSchemeResChnInfo
{
    INT32   dwIndex;                                            /* 索引 */
    INT32   dwChannelID;                                        /* 通道ID */
    INT32   dwStreamIndex;                                      /* 码流索引 */
    INT32   dwPresetID;                                         /* 预置位ID */
}NETDEV_DC_SCHEME_RES_CHN_INFO_S, *LPNETDEV_DC_SCHEME_RES_CHN_INFO_S;

/**
 * @struct tagstNETDEVDCSchemeRes
 * @brief DC轮巡资源信息
 * @attention 
 */
typedef struct tagstNETDEVDCSchemeResource
{
    NETDEV_DC_SCHEME_RES_INFO_S         stResInfo;                                          /* 轮巡资源基本信息 */
    INT32                               dwIntervalTime;                                     /* 轮巡时间间隔(s) */
    INT32                               dwSize;                                             /* 轮巡通道资源个数 */
    NETDEV_DC_SCHEME_RES_CHN_INFO_S     astChnInfo[NETDEV_DC_SCHEME_RES_CHN_MAX_NUM];       /* 轮巡通道资源信息 */
}NETDEV_DC_SCHEME_RESOURCE_S, *LPNETDEV_DC_SCHEME_RESOURCE_S;

/**
 * @struct tagstNETDEVRoleRight
 * @brief 用户角色权限信息
 * @attention 
 */

typedef struct tagstNETDEVRoleRight
{
    UINT32 udwMajorRight;
    UINT32 udwMinorRight;
}NETDEV_ROLE_RIGHT_S, *LPNETDEV_ROLE_RIGHT_S;

/**
 * @struct tagstNETDEVOrgTreeList
 * @brief 用户角色权限列表
 * @attention 
 */
typedef struct tagstNETDEVOrgTreeList
{
    INT32 dwSize;                                               /* 组织树数量 */
    INT32 adwOrgRootID[NETDEV_MAX_ORG_ROOT_ID_NUM];              /* 组织树根节点ID */
}NETDEV_ORG_TREE_S, *LPNETDEV_ORG_TREE_S;

/**
 * @struct tagstNETDEVRoleRightList
 * @brief 用户角色权限列表
 * @attention 
 */
typedef struct tagstNETDEVRoleRightList
{
    INT32 dwSize;                                                   /* 数量 */
    NETDEV_ROLE_RIGHT_S astRoleRight[NETDEV_MAX_ROLE_RIGHT_SIZE];        /* 用户权限信息 */
    NETDEV_ORG_TREE_S stOrgTreeInfo;                                 /* 组织树信息 */
}NETDEV_RIGHT_LIST_S, *LPNETDEV_RIGHT_LIST_S;



/**
 * @struct tagstNETDEVTimeDuration
 * @brief 每天的时间段信息
 */
typedef struct tagstNETDEVTimeDuration
{
    INT64    tBeginTime;                              /* 起始时间 */
    INT64    tEndTime;                                /* 结束时间 */
    INT32    dwPlanType;                              /* 参见 NETDEV_TIME_TEMPLATE_PLAN_TYPE */
}NETDEV_TIME_DURATION_S, *LPNETDEV_TIME_DURATION_S;

/**
 * @struct tagstNETDEVTimeDurationList
 * @brief 每天的时间段信息列表，一天最多24个时间段
 */
typedef struct tagstNETDEVTimeDurationList
{
    INT32                     dwSize;                                                      /* 时间段个数 */
    NETDEV_TIME_DURATION_S    astTimeDurationList[NETDEV_TIME_DURATION_NUM];               /* 时间段信息列表 */
}NETDEV_TIME_DURATION_LIST_S, *LPNETDEV_TIME_DURATION_LIST_S;

/**
 * @struct tagstNETDEVTimeRange
 * @brief 时间范围信息，一个时间模板最多可包含8个时间范围，周一到周日和假日
 * @attention
 */
typedef struct tagstNETDEVTimeRange
{
    INT32                            dwSize;                                         /* 时间范围个数 */
    NETDEV_TIME_DURATION_LIST_S      astTimeRangeList[NETDEV_TIME_RANGE_NUM];        /* 时间范围列表 */
}NETDEV_TIME_RANGE_S, *LPNETDEV_TIME_RANGE_S;

/**
 * @struct tagstNETDEVTimeTemplateInfo
 * @brief 时间模板详细信息
 * @attention
 */
typedef struct tagstNETDEVTimeTemplateInfoV30
{
    CHAR    szTamplateName[NETDEV_NAME_MAX_LEN];                            /* 模板名称 */
    CHAR    szTamplateDesc[NETDEV_DESCRIBE_MAX_LEN];                        /* 模板描述 */
    INT32   dwTemplateType;                                                 /* 时间模板类型 参见NETDEV_TIME_TEMPLATE_TYPE_E */
    NETDEV_TIME_RANGE_S    stTimeRange;                                     /* 共8个时间范围 */
}NETDEV_TIME_TEMPLATE_INFO_V30_S, *LPNETDEV_TIME_TEMPLATE_INFO_V30_S;

/**
 * @struct tagstNETDEVHolidayTimeInfo
 * @brief 假日时间信息
 * @attention
 */
typedef struct tagstNETDEVHolidayTimeInfo
{
    INT32     dwYear;                               /* 所在年份 */
    INT32     dwMonth;                              /* 所在月份 */
    INT32     dwDay;                                /* 具体日期 */
    INT32     dwWeekOfMonth;                        /* 当月的第几周 */
    INT32     dwWeekDay;                            /* 周几 */
}NETDEV_HOLIDAY_TIME_INFO_S, *LPNETDEV_HOLIDAY_TIME_INFO_S;

/**
 * @struct tagstNETDEVHolidayInfo
 * @brief 假日信息
 * @attention
 */
typedef struct tagstNETDEVHolidayInfo
{
    INT32      dwHolidayID;                            /* 假日信息索引 */
    CHAR       szHolidayName[NETDEV_NAME_MAX_LEN];           /* 假日名称 */
    INT32      dwStatus;                               /* 假日状态(0表示未启用，1表示启用) */
    INT32      dwRepeatType;                           /* 重复方式(0表示单年，1表示常年) */
    INT32      dwHolidayType;                          /* 节假日时间识别方式(0表示按日，1表示按周) */
    NETDEV_HOLIDAY_TIME_INFO_S    stBeginTime;         /* 假日开始时间 */
    NETDEV_HOLIDAY_TIME_INFO_S    stEndTime;           /* 假日结束时间 */
}NETDEV_HOLIDAY_INFO_S, *LPNETDEV_HOLIDAY_INFO_S;

/**
 * @struct tagstNETDEVHolidayInfoList
 * @brief 所有假日信息
 * @attention
 */
typedef struct tagstNETDEVHolidayInfoList
{
    INT32                        dwSize;                                        /* 假日配置数量 */
    NETDEV_HOLIDAY_INFO_S        astHolidayInfoList[NETDEV_HOLIDAY_INFO_NUM];      /* 所有假日信息 */
}NETDEV_HOLIDAY_INFO_LIST_S, *LPNETDEV_HOLIDAY_INFO_LIST_S;

/**
 * @struct tagNETDEVPaneBindInfo
 * @brief 分屏绑定业务信息
 * @attention
 */
typedef struct tagNETDEVPaneBindInfo
{
    UINT32  udwVideoInChannelID;              /* 视频源ID */
    UINT32  udwStreamID;                      /* 媒体流ID */
}NETDEV_PANE_BIND_INFO_S, *LPNETDEV_PANE_BIND_INFO_S;


/**
 * @struct tagNETDEVPaneBindService
 * @brief 分屏绑定业务
 * @attention
 */
typedef struct tagNETDEVPaneBindService
{
    UINT32                       udwTVWallID;                 /* 电视墙ID */
    UINT32                       udwWindowID;                 /* 窗口ID */
    UINT32                       udwPaneID;                   /* 分屏ID */
    UINT32                       udwPaneOperateType;          /* 分屏操作类型 参见NETDEV_PANE_OPERATE_TYPE_E*/
    NETDEV_PANE_BIND_INFO_S      udwPaneBindInfo;             /* 分屏绑定的业务信息 */
}NETDEV_PANE_BIND_SERVICE_S, *LPNETDEV_PANE_BIND_SERVICE_S;


/**
 * @struct tagNETDEVXWPaneInfo
 * @brief XW窗口分屏信息
 * @attention
 */
typedef struct tagNETDEVVideoInSource
{
    UINT32  udwPaneID;          /* 分屏序号 */
    INT32   dwChannelID;        /* 通道ID */
    UINT32  udwStreamIndex;     /* 流索引 */
    UINT32  udwTaskNo;          /* 业务号 */
    UINT32  udwTransProtocal;   /* 传输协议 参见 NETDEV_LAPI_TRANS_PROTOCAL_E */
    UINT32  udwSessionType;     /* 分屏业务类型 参见 NETDEV_SESSION_TYPE_E */
}NETDEV_VIDEO_IN_SOURCE_INFO_S, *LPNETDEV_VIDEO_IN_SOURCE_INFO_S;


/**
 * @struct tagNETDEVXWSceneWndInfo
 * @brief 场景窗口信息
 * @attention
 */
typedef struct tagNETDEVVideoInChnInfo
{
    UINT32                              udwWndID;                             /* 窗口ID */
    UINT32                              udwSeqResID;                          /* 轮巡资源ID */
    UINT32                              udwSeqStatus;                         /* 轮巡状态 参见 NETDEV_SEQ_STATUS_E */
    NETDEV_VIDEO_IN_SOURCE_INFO_S       stVideoInSourceInfo;                  /* 窗口分屏信息 */
}NETDEV_VIDEO_IN_CHN_INFO_S, *LPNETDEV_VIDEO_IN_CHN_INFO_S;


typedef struct tagNETDEVSceneWndInfo
{
    UINT32              udwWndID;                            /* 窗口ID */
    UINT32              udwDChlID;                           /* DC通道ID */
    CHAR                szName[NETDEV_WND_NAME_LEN];         /* 名称 */
    UINT32              udwWndType;                          /* 窗口类型 NETDEV_TVWALL_WND_TPYE */
    UINT32              udwStatus;                           /* 0表示不锁定，1表示锁定 */
    UINT32              udwPaneMod;                          /* 分屏模式 参见NETDEV_LAYOUT_TYPE_E */
    UINT32              udwZoomType;                         /* 放大类型 参见NETDEV_WINDOWS_ZOOM_TYPE_E zoom Type see NETDEV_WINDOWS_ZOOM_TYPE_E */
    UINT32              udwSplitIndex;                       /* 分屏序号  当ZoomType字段值1时必选*/
    UINT32              udwLayer;                            /* 图层 */
    UINT32              udwTransparency;                     /* 透明度 */
    NETDEV_XW_AREA_S    stArea;                              /* 区域范围 */
}NETDEV_SCENE_WND_INFO_S, *LPNETDEV_SCENE_WND_INFO_S;

/**
 * @struct tagstNETDEVResInfo
 * @brief 轮巡资源信息
 * @attention
 */
typedef struct tagstNETDEVGroupSeqInfo
{
    UINT32                      udwSeqID;           /* 组轮巡ID */
    BOOL                        bEnabled;           /* 组轮巡启用状态 */
    UINT32                      udwResourceID;      /* 轮巡资源ID */
    UINT32                      udwStatus;          /* 轮巡状态 参见 NETDEV_SEQ_STATUS_E */
    UINT32                      udwWndNum;          /* 组轮巡窗口数量 */
    LPNETDEV_SCENE_WND_INFO_S   audwWndIDList;      /* 窗口信息 */
}NETDEV_GROUP_SEQ_INFO_S, *LPNETDEV_GROUP_SEQ_INFO_S;

/**
 * @struct tagNETDEVXWSceneDetailInfo
 * @brief 场景详细信息
 * @attention
 */
typedef struct tagNETDEVXWSceneDetailInfoEx
{
    UINT32                              udwVirtualLedNum;       /* 虚拟LED数量 */
    LPNETDEV_XW_VIRTUAL_LED_INFO_S      pstVirtualLedInfo;      /* 虚拟LED信息 */
    UINT32                              udwWndNum;              /* 窗口数量 */
    LPNETDEV_SCENE_WND_INFO_S           pstWndInfo;             /* 窗口信息 */
    UINT32                              udwGroupSeqNums;        /* 组轮巡数量 */
    LPNETDEV_GROUP_SEQ_INFO_S           pstGroupSeqInfo;        /* 组轮巡信息 */
    UINT32                              udwVideoChnNums;        /* 绑定业务数量 */
    LPNETDEV_VIDEO_IN_CHN_INFO_S        pstVideoInChnInfo;      /* 绑定业务信息 */
}NETDEV_XW_SCENE_DETAIL_INFO_EX_S, *LPNETDEV_XW_SCENE_DETAIL_INFO_EX_S;


/**
 * @struct tagNETDEVXWWndIndex
 * @brief 窗口索引
 * @attention
 */
typedef struct tagNETDEVXWWndIndex
{
    UINT32  udwTVWallID;    /* 电视墙ID */
    UINT32  udwWndID;       /* 窗口ID */
}NETDEV_XW_WND_INDEX_S, *LPNETDEV_XW_WND_INDEX_S;

/**
 * @struct tagNETDEVXWLEDIndex
 * @brief 虚拟LED索引 
 * @attention
 */
typedef struct tagNETDEVXWLEDIndex
{
    UINT32  udwTVWallID;        /* 电视墙ID */
    UINT32  udwVirtualLEDID;    /* 虚拟LED ID */
}NETDEV_XW_LED_INDEX_S, *LPNETDEV_XW_LED_INDEX_S;

/**
 * @struct tagNETDEVXWBatchResuleInfo
 * @brief 批量添加返回信息
 * @attention
 */
typedef struct tagNETDEVXWBatchResuleInfo
{
    UINT32  udwReqSeq;          /*请求数据序号*/
    UINT32  udwResuleCode;      /*返回错误码*/
    UINT32  udwID;              /*窗口ID*/
}NETDEV_XW_BATCH_RESULT_INFO_S,*LPNETDEV_XW_BATCH_RESULT_INFO_S;

/**
 * @struct tagNETDEVXWAudioOutputInfo
 * @brief 音频输出信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVXWAudioOutputInfo
{
    UINT32  udwID;          /* 音频输出通道ID */
    UINT32  udwVolum;       /* 音量 */
    UINT32  udwIsMute;      /* 静音状态 */
    BYTE    byRes[64];      /* 保留字段 */
}NETDEV_XW_AUDIO_OUTPUT_INFO_S,*LPNETDEV_XW_AUDIO_OUTPUT_INFO_S;

/**
 * @struct tagNETDEVXWWinAudioOutputInfo
 * @brief 音频输出业务信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVXWWinAudioOutputInfo
{
    UINT32 udwWindowID;                                         /* 窗口ID */
    UINT32 udwPanelID;                                          /* 分屏序号 */
    NETDEV_XW_AUDIO_OUTPUT_INFO_S stXWAudioOutputInfo;          /* 音频输出信息结构体 */
    BYTE byRes[64];                                             /* 保留字段 */
}NETDEV_XW_WIN_AUDIO_OUTPUT_INFO_S,*LPNETDEV_XW_WIN_AUDIO_OUTPUT_INFO_S;

/**
 * @struct tagNETDEVXWWinAudioOutputList
 * @brief 音频输出业务列表信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVXWWinAudioOutputList
{
    UINT32 udwNum;                                                                          /* 窗口音频输出业务数量 */
    NETDEV_XW_WIN_AUDIO_OUTPUT_INFO_S stXWWinAudioOutputInfo[NETDEV_AUDIO_MAX_NUM];       /* 窗口音频输出业务列表 */
    BYTE byRes[64];                                                                         /* 保留字段 */
}NETDEV_XW_WIN_AUDIO_OUTPUT_LIST_S,*LPNETDEV_XW_WIN_AUDIO_OUTPUT_LIST_S;

/**
 * @struct tagNETDEVXWPriviewInfo
 * @brief 实况预览参数
 * @attention
 */
typedef struct tagNETDEVXWPriviewInfo
{
    UINT32  udwTVWallID;        /* 电视墙ID */
    UINT32  udwWndID;           /* 窗口ID */
    UINT32  udwPaneID;          /* 分屏ID */
    INT32   dwChannelID;        /* 通道ID */
    UINT32  udwStreamIndex;     /* 流类型 */
    UINT32  udwTransProtocal;   /* 传输协议 */
    UINT32  udwTransType;       /* 直连(0)或转发(1) */
}NETDEV_XW_PRIVIEW_INFO_S, *LPNETDEV_XW_PRIVIEW_INFO_S;

/**
 * @struct tagNETDEVXWPlayBackCond
 * @brief 回放参数
 * @attention
 */
typedef struct tagNETDEVXWPlayBackCond
{
    UINT32  udwTVWallID;            /* 电视墙ID */
    UINT32  udwWndID;               /* 窗口屏ID */
    UINT32  udwPaneID;              /* 分屏ID */
    INT32   dwChannelID;            /* 通道ID */
    UINT32  udwBeginTime;           /* 开始时间 */
    UINT32  udwEndTime;             /* 结束时间 */
    UINT32  udwStoreType;           /* 录像存储类型 参见 NETDEV_STORE_TYPE_E */
    UINT32  udwRecordLocation;      /* 录像位置 */
    UINT32  udwSessionID;           /* session id */
}NETDEV_XW_PLAY_BACK_COND_S, *LPNETDEV_XW_PLAY_BACK_COND_S;


/**
 * @struct tagNETDEVXWPlayBackCond
 * @brief 轮巡操作枚举
 * @attention
 */
typedef struct tagNETDEVXWSequenceCond
{
    UINT32  udwTVWallID;        /* 电视墙ID */
    UINT32  udwSeqID;           /* 轮巡ID */
    UINT32  udwResourceType;    /* 资源类型 参见NETDEV_XW_SEQ_RESOURCE_TYPE_E */
    UINT32  udwResourceID;      /* 资源ID */
    UINT32  udwSeqCmd;          /* 轮巡操作方法,参见NETDEV_XW_SEQ_CMD_E */
}NETDEV_XW_SEQUENCE_COND_S, *LPNETDEV_XW_SEQUENCE_COND_S;


/**
 * @struct tagstNETDEVAlarmTaskInfo
 * @brief 告警任务信息
 * @attention 
 */
typedef struct tagstNETDEVAlarmTaskInfo
{
    INT32   dwTaskID;                               /* 告警任务ID */
    CHAR    szTaskName[NETDEV_NAME_MAX_LEN];        /* 告警任务名称 */
    CHAR    szTaskDesc[NETDEV_DESCRIBE_MAX_LEN];    /* 告警任务描述 */
    INT32   dwTVWallID;                             /* 电视墙ID */
}NETDEV_ALARM_TASK_INFO_S, *LPNETDEV_ALARM_TASK_INFO_S;

/**
 * @struct tagstNETDEVAlarmTasksList
 * @brief 告警任务信息列表
 * @attention 
 */
typedef struct tagstNETDEVAlarmTasksList
{
    INT32                       dwSize;                                             /* 数量 */
    NETDEV_ALARM_TASK_INFO_S    astAlarmTaskInfo[NETDEV_MAX_ALARM_TASK_SIZE];       /* 告警任务信息 */
}NETDEV_ALARM_TASK_LIST_S, *LPNETDEV_ALARM_TASK_LIST_S;

/**
 * @struct tagstNETDEVWinLayoutInfo
 * @brief 窗口布局信息
 * @attention 
 */
typedef struct tagstNETDEVWinLayoutInfo
{
    INT32               dwWndID;            /* 窗口ID */
    INT32               dwDChlID;           /* 解码通道ID */
    INT32               dwStatus;           /* 窗口状态  0表示不锁定，1表示锁定 */
    INT32               dwLayer;            /* 图层  数字大的在最上层*/
    INT32               dwLayoutMode;       /* 分屏幕模式，参见#NETDEV_LAYOUT_TYPE_E */
    INT32               dwTransparency;     /* 透明度 */
    NETDEV_XW_AREA_S    stArea;             /* 区域范围 */
}NETDEV_WIN_LAYOUT_INFO_S, *LPNETDEV_WIN_LAYOUT_INFO_S;


/**
 * @struct tagstNETDEVVideoChnInfo
 * @brief 视频通道信息
 * @attention 
 */
typedef struct tagstNETDEVVideoChnInfo
{
    INT32 dwWndID;                                                  /* 所属窗口ID */
    INT32 dwPaneIdx;                                                /* 分屏索引 */
    INT32 dwChannelID;                                              /* 编码设备通道ID */
    INT32 dwStreamIdx;                                              /* 码流索引，参见#NETDEV_LIVE_STREAM_INDEX_E */
    INT32 dwTransProtocal;                                          /* 传输协议，参见#NETDEV_TRANS_PROTOCAL_E */
    INT32 dwPresetID;                                               /* 预置位ID */
}NETDEV_VIDEO_CHANNEL_INFO_S, *LPNETDEV_VIDEO_CHANNEL_INFO_S;

/**
 * @struct tagstNETDEVAlarmTaskDetailInfo
 * @brief 告警任务详细信息
 * @attention 
 */
typedef struct tagstNETDEVAlarmTaskDetailInfo
{
    NETDEV_ALARM_TASK_INFO_S        stAlarmInfo;            /* 告警任务基本信息 */
    INT32                           dwLayoutSize;           /* 窗口布局数量 */
    LPNETDEV_WIN_LAYOUT_INFO_S      pstWinLayoutInfo;       /* 窗口布局信息，根据dwLayoutSize动态申请内存 */
    INT32                           dwLEDSize;              /* 虚拟LED个数 */
    LPNETDEV_XW_VIRTUAL_LED_INFO_S  pstLEDList;             /* 虚拟LED列表 */
    INT32                           dwVideoChannelSize;     /* 视频通道个数 */
    LPNETDEV_VIDEO_CHANNEL_INFO_S   pstVideoChannelList;    /* 视频通道列表 */
}NETDEV_ALARM_TASK_DETAIL_INFO_S, *LPNETDEV_ALARM_TASK_DETAIL_INFO_S;


/**
 * @struct tagstNETDEVVersionInfo
 * @brief 一体机设备版本信息
 * @attention 
 */
typedef struct tagstNETDEVVersionInfo
{
    UINT32  udwDefaultLang;                         /* 默认语言 参加枚举 NETDEV_LANG_TYPE_E */
    UINT32  udwNum;                                 /* 支持的语言数量 */
    UINT32  audwLangType[NETDEV_LEN_16];            /* 支持的语言类型 参加枚举 NETDEV_LANG_TYPE_E ,目前最多支持两种*/
    UINT32  udwRegionType;                          /* 区域类型 参见枚举 NETDEV_REGION_TYPE_E */
    UINT32  udwCustomType;                          /* 定制类型 定制类型 参见枚举 NETDEV_CUSTOM_TYPE_E */
    CHAR    szWin32ClientVision[NETDEV_LEN_64];     /* 32位C/S客户端版本路径，范围[1,32]] */
    CHAR    szWin64ClientVision[NETDEV_LEN_64];     /* 64位C/S客户端版本路径，范围[1,32]] */
    CHAR    szAgentClientVision[NETDEV_LEN_64];     /* agent客户端版本路径，范围[1,32] */
    CHAR    szEztoolClientVision[NETDEV_LEN_64];    /* Eztool客户端版本，范围[1,32] */
    CHAR    szUNPClientVision[NETDEV_LEN_64];       /* UNP客户端版本，范围[1,32] */
    BYTE    byRes[256];                             /* 保留字段 */
}NETDEV_VERSION_INFO_S, *LPNETDEV_VERSION_INFO_S;



/**
 * @struct tagNETDEVXWDecodeInfo
 * @brief 窗口解码信息
 * @attention
 */
typedef struct tagNETDEVXWDecodeInfo
{
    UINT32         udwTvWallID;                               /* 电视墙ID*/
    UINT32         udwWndID;                                  /* 窗口ID*/
    UINT32         udwWndIndex;                               /* 窗口索引序号*/
    UINT32         udwPaneID;                                 /* 分屏序号*/
    UINT32         udwChnCode;                                /* 窗口所在通道编码，0x01000100表示这是一个视频输出通道，为第2个设备的第1个槽位的第1个视频输出通道*/
    UINT32         udwStreamStatus;                           /* 建流状态 参见枚举 NETDEV_XW_WND_STREAM_STATUS_E */
    CHAR           szCameraCode[NETDEV_LEN_64];               /* 摄像机编码*/
    CHAR           szCameraIP[NETDEV_LEN_64];                 /* 摄像机地址 [0,64]*/
    CHAR           szSourceAddress[NETDEV_LEN_64];            /* 源地址 [0,64]*/
    UINT32         udwSourcePort;                             /* 源端口*/
    CHAR           szDestAddress[NETDEV_LEN_64];              /* 目的地址（dsp地址）[0,64]*/
    UINT32         udwDestPort;                               /* 目的端口*/
    CHAR           szTransport[NETDEV_LEN_16];                /* 传输模式[0,16], 例如：TCP*/
    NETDEV_XW_RESOLUTION_S stResolution;                     /* 分辨率节点 */
    UINT32         udwFrameRate;                              /* 帧率*/
    CHAR           szVideoEncodeType[NETDEV_LEN_8];           /* 视屏格式[0,8], 例如：H.264*/
    CHAR           szAudioEncodeType[NETDEV_LEN_8];           /* 音频格式[0,8], 例如：G.711U*/
    CHAR           szFormatType[NETDEV_LEN_16];               /* 封装格式[0,16], 例如：RTP+PS、PS等*/
    FLOAT          fPacketDorpRate;                           /* 两分钟丢包率（相机丢包率）*/
    UINT32         udwPacketDropCnt;                          /* 丢包计数*/
    UINT32         udwTotalPacketNum;                         /* 总包数*/
    BYTE           bRes[128];                                 /* 预留字段 */
}NETDEV_XW_DECODE_INFO_S, *LPNETDEV_XW_DECODE_INFO_S;


/**
 * @enum tagNETDEVXWSerialCfgInfo
 * @brief XW串口ID信息
 * @attention 无 None
 */
typedef struct tagNETDEVXWSerialCfgInfo
{
    UINT32      udwSerialID;                       /* 串口ID */
    UINT32      udwSerialType;                     /* 串口类型 参见枚举 NETDEV_XW_SERIAL_TYPE_E*/
    UINT32      udwIndex;                          /* 串口序号 */
    UINT32      udwSerialMode;                     /* 串口模式 参见枚举NETDEV_XW_SERIAL_MODE_E*/
    UINT32      udwWorkMode;                       /* 工作模式 RS232串口不携带 参见枚举NETDEV_XW_SERIAL_MODE_E*/
    UINT32      udwBaudRate;                       /* 波特率 取值范围：1200、2400、4800、9600、19200、38400、57600、115200*/
    UINT32      udwDataBits;                       /* 数据位 取值范围：5、6、7、8*/
    UINT32      udwStopBits;                       /* 停止位 取值范围：1、2*/
    UINT32      udwParity;                         /* 校验位 参见枚举 NETDEV_XW_PARITY_TYPE_E*/
    UINT32      udwFlowCtrl;                       /* 流控位 参见枚举 NETDEV_XW_PARITY_TYPE_E*/
    BYTE        byRes[128];                        /* 预留字段 参见枚举 NETDEV_XW_FLOW_CTRL_E*/
}NETDEV_XW_SERIAL_CFG_INFO_S, *LPNETDEV_XW_SERIAL_CFG_INFO_S;

/**
 * @enum tagNETDEVXWSerialList
 * @brief XW串口ID列表
 * @attention 无 None
 */
typedef struct tagNETDEVXWSerialList
{
    UINT32                          udwNum;                                     /* 串口数量 */
    NETDEV_XW_SERIAL_CFG_INFO_S     stSerialCfgInfo[NETDEV_XW_SERIAL_NUM];      /* 串口类型 参见枚举 NETDEV_XW_COM_TYPE_E*/
    BYTE                            byRes[128];                                 /* 预留字段 */
}NETDEV_XW_DEVICE_SERIAL_LIST_S, *LPNETDEV_XW_DEVICE_SERIAL_LIST_S;

/*
* @struct tagNETDEVDiscoverCondInfo
* @brief 设备发现条件信息
* @attention 无 None
*/
typedef struct tagNETDEVDiscoverCondInfo
{
    CHAR                szBeginIP[NETDEV_LEN_128];    /* 起始IP地址,不指定时为0 */
    CHAR                szEndIP[NETDEV_LEN_128];      /* 结束IP地址,不指定时为0 */
    UINT32              udwServiceID;                 /* 服务器ID,范围[0-255],0表示主机，其它值从机设备 */
    UINT32              udwAccessMode;                /* 接入方式，参见枚举NETDEV_DEVICE_ACCESS_MODE_E */
    BYTE                byRes[128];                   /* 保留字  Reserved */
}NETDEV_DISCOVER_COND_INFO_S, *LPNETDEV_DISCOVER_COND_INFO_S;

/*
* @struct tagNETDEVDeviceFindCond
* @brief 获取设备查找条件信息
* @attention 无 None
*/
typedef struct tagNETDEVDeviceFindCond
{
    UINT32              udwDeviceType;                  /* 设备类型 参见枚举NETDEV_DEVICE_MAIN_TYPE_E */
    UINT32              udwServiceID;                   /* 服务器ID,范围[0-255],0表示主机，其它值从机设备 */
    BYTE                byRes[128];                     /* 保留字  Reserved */
}NETDEV_DEVICE_FIND_COND_S, *LPNETDEV_DEVICE_FIND_COND_S;

/*
* @struct tagNETDEVDiscoverDeviceInfo
* @brief 发现的设备信息
* @attention 无 None
*/
typedef struct tagNETDEVDiscoverDeviceInfo
{
    UINT32              udwDeviceType;                      /* 设备类型 参见枚举NETDEV_DEVICE_MAIN_TYPE_E */
    UINT32              udwDeviceSubType;                   /* 设备子类型 参见枚举NETDEV_DEVICE_SUB_TYPE_E */
    UINT32              udwPort;                            /* 端口 */
    BOOL                bIsAdded;                           /* 是否已添加,FALSE未添加，TRUE已添加 */
    CHAR                szIPAddress[NETDEV_LEN_64];         /* IP地址 */
    CHAR                szDevModel[NETDEV_LEN_64];          /* 设备型号 */
    CHAR                szSerialNumber[NETDEV_LEN_64];      /* 设备序列号 */
    CHAR                szFirmwareVersion[NETDEV_LEN_64];   /* 软件版本 */
    CHAR                szDevMac[NETDEV_LEN_64];            /* MAC地址 */
    CHAR                szManufacturer[NETDEV_LEN_64];      /* 设备制造商 */
    CHAR                szUniCode[NETDEV_LEN_64];           /* 设备国标编码 */
    UINT32              udwProtocolType;                    /* 协议类型，参见枚举NETDEV_ACCESS_PROTOCOL_E */
    BYTE                byRes[128];                         /* 保留字  Reserved */
}NETDEV_DISCOVER_DEV_INFO_S, *LPNETDEV_DISCOVER_DEV_INFO_S;

typedef struct tagstNETDEVDevChnCommonInfo
{    
    UINT32 udwDevID;                                          /* 设备ID */
    UINT32 udwOrgID;                                          /* 组织ID */
    UINT32 udwChnIndex;                                       /* 通道索引 */
    CHAR  szDevName[NETDEV_LEN_256];                        /* 设备名称 */
    UINT32 udwRight;                                        /* 通道权限 */
    BYTE   byRes[128];                                      /* 保留字段 */
}NETDEV_DEV_CHN_COMMON_INFO_S, *LPNETDEV_DEV_CHN_COMMON_INFO_S;

/**
 * @brief 通道信息
 * @attention
 */
typedef struct tagstNETDEVChnInfo
{    
    UINT32                          udwChannelID;               /* 通道ID */
    CHAR                            szChnName[NETDEV_LEN_256];  /* 通道名称 */

    BYTE                            byRes[128];                 /* 保留字段 */
}NETDEV_CHN_INFO_S, *LPNETDEV_CHN_INFO_S;

/**
 * @struct tagstNETDEVDevVideoChnInfo
 * @brief 设备视频通道信息
 * @attention
 */
typedef struct tagstNETDEVDevVideoChnInfo
{    
    UINT32                           udwChannelID;               /* 通道ID */
    CHAR                             szChnName[NETDEV_LEN_256];  /* 通道名称 */
    UINT32                           udwChnStatus;               /* 通道状态, 参见 NETDEV_CHN_STATUS_E */
    CHAR                             szGBID[NETDEV_LEN_32];      /* 国标资源编码 */
    NETDEV_DEV_CHN_COMMON_INFO_S  stCommonInfo;                  /* 通用信息 */
    UINT32                           udwMaxStream;               /* 支持的最大流个数 */
    BOOL                             bSupportPTZ;                /* 是否支持云台 */
    UINT32                           udwAudioResID;              /* 音频资源ID */
    BYTE                             byRes[128];                 /* 保留字段 */
}NETDEV_VIDEO_CHN_INFO_S, *LPNETDEV_VIDEO_CHN_INFO_S;

/**
 * @struct tagstNETDEVVideoChnFindCond
 * @brief 查找视频通道信息列表条件
 * @attention
 */
typedef struct tagstNETDEVVideoChnFindCond
{    
    UINT32                           udwDevID;                /* 设备ID */
    UINT32                           udwOrgID;                /* 组织ID */
    UINT32                           udwLimit;                /* 每次查询的数量，范围[1,500] */
    UINT32                           udwOffset;               /* 开始查询的序号，从0开始 */
    UINT32                           udwFindType;             /* 查找模式，参见NETDEV_VIDEO_CHN_FIND_TYPE_E */
    
    BYTE                            byRes[128];             /* 保留字段 */
}NETDEV_VIDEO_CHN_FIND_COND_S, *LPNETDEV_VIDEO_CHN_FIND_COND_S;

/**
 * @struct tagstNETDEVOrgFindCond
 * @brief 查找组织信息列表条件
 * @attention
 */
typedef struct tagstNETDEVOrgFindCond
{    
    UINT32                           udwOrgType;              /* 组织类型 参见NETDEV_ORG_TYPE_E */
    UINT32                           udwRootOrgID;            /* 根节点组织ID */
    UINT32                           udwFindType;             /* 查找模式，参见NETDEV_ORG_FIND_MODE_E */
    
    BYTE                            byRes[128];             /* 保留字段 */
}NETDEV_ORG_FIND_COND_S, *LPNETDEV_ORG_FIND_COND_S;

/**
* @struct tagstNETDEVModifyDevInfo
* @brief 修改设备信息
* @attention
*/
typedef struct tagstNETDEVModifyDevInfo
{
    UINT32                          udwID;                              /* 设备ID */
    CHAR                            szDevName[NETDEV_LEN_64];           /* 设备名称 */
    NETDEV_IPADDR_INFO_S            stDevIPAddress;                     /* IP地址 */
    CHAR                            szLoginName[NETDEV_LEN_64];         /* 登录用户名 */
    CHAR                            szPasswd[NETDEV_LEN_64];            /* 登录密码，不修改接入登录密码时为"" */
    UINT32                          udwAccessProtocol;                  /* 接入协议 参见枚举NETDEV_ACCESS_PROTOCOL_E */
    UINT32                          udwDevSubType;                      /* 设备子类型，参见枚举NETDEV_DEVICE_SUB_TYPE_E */
    UINT32                          udwServerID;                        /* 服务器ID，范围[0,255] */
    UINT32                          udwOrgID;                           /* 组织编码 */
    CHAR                            szDescription[NETDEV_LEN_256];      /* 设备描述 */
    NETDEV_ONVIF_INFO_S             stOnvifInfo;                        /* onvif信息 */
    NETDEV_GBINFO_S                 stGBInfo;                           /* 国标信息 */

    BYTE                            byRes[128];                         /* 保留字段  Reserved field*/
}NETDEV_MODIFY_DEV_INFO_S, *LPNETDEV_MODIFY_DEV_INFO_S;

/**
* @struct tagstNETDEVAddDevBasicInfo
* @brief 批量添加设备基本信息
* @attention
*/
typedef struct tagstNETDEVAddDevBasicInfo
{    
    UINT32                          udwReqSeq;                          /* 请求数据序号，范围[1, 50]，此字段会在返回结果中带回 */
    CHAR                            szDevName[NETDEV_LEN_64];           /* 设备名称 */
    NETDEV_IPADDR_INFO_S            stDevIPAddress;                     /* IP地址 */
    CHAR                            szLoginName[NETDEV_LEN_64];         /* 登录用户名 */
    CHAR                            szPasswd[NETDEV_LEN_64];            /* 登录密码，不修改接入登录密码时为"" */
    UINT32                          udwAccessProtocol;                  /* 接入协议 参见枚举NETDEV_ACCESS_PROTOCOL_E */
    UINT32                          udwDevType;                         /* 设备类型，参见枚举NETDEV_DEVICE_MAIN_TYPE_E */
    UINT32                          udwDevSubType;                      /* 设备子类型，参见枚举NETDEV_DEVICE_SUB_TYPE_E */
    UINT32                          udwServerID;                        /* 服务器ID，范围[0,255] */
    UINT32                          udwOrgID;                           /* 组织编码 */
    CHAR                            szDescription[NETDEV_LEN_256];      /* 设备描述 */
    NETDEV_ONVIF_INFO_S             stOnvifInfo;                        /* onvif信息 */
    NETDEV_GBINFO_S                 stGBInfo;                           /* 国标信息 */
    UINT32                          udwIsPTZNeeded;                     /* 是否需要云台 0:  不需要 1:  需要 255:  自适应 */

    BYTE                            byRes[128];                         /* 保留字段  Reserved field*/
}NETDEV_ADD_DEV_BASIC_INFO_S, *LPNETDEV_ADD_DEV_BASIC_INFO_S;

/**
 * @struct tagstNETDEVXWAddDevInfo
 * @brief 批量添加设备信息列表
 * @attention
 */
typedef struct tagstNETDEVXWAddDevInfo
{
    UINT32                              udwNum;                     /* 设备数量 */
    UINT32                              udwDevType;                 /* 设备类型，参见枚举NETDEV_DEVICE_MAIN_TYPE_E */
    LPNETDEV_ADD_DEV_BASIC_INFO_S       pstAddDevBasicInfoList;     /* 批量添加设备信息列表指针，根据待添加设备数量，内存由调用者维护 */

    BYTE                                byRes[128];                 /* 保留字段  Reserved field */
}NETDEV_ADD_DEV_INFO_S, *LPNETDEV_ADD_DEV_INFO_S;

/**
 * @struct tagNETDEVBatchOperatorInfo
 * @brief 批量操作信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVBatchOperatorInfo
{
    UINT32   udwReqSeq;                          /* 请求数据序号 */
    UINT32   udwResultCode;                      /* 返回错误码,人脸布控操作结果详见#NETDEV_PERSON_MONITOR_OPT_RES_CODE_E */
    UINT32   udwID;                              /* 编号 */
    CHAR     szName[NETDEV_LEN_260];             /* 成员名称，长度范围[1,63] */
    BYTE     byRes[128];                         /* 保留字段  Reserved */
}NETDEV_BATCH_OPERATOR_INFO_S,*LPNETDEV_BATCH_OPERATOR_INFO_S;

/**
 * @struct tagstNETDEVXWAddDevResultInfo
 * @brief 批量添加设备返回信息
 * @attention
 */
typedef struct tagstNETDEVXWAddDevResultInfo
{    
    UINT32 udwStatus;                                               /* 响应状态，类型参见 NETDEV_ORG_RESPONSE_STAUTE_E */
    UINT32 udwNum;                                                  /* 响应数量 */
    LPNETDEV_BATCH_OPERATOR_INFO_S pstResultInfoList;               /* 批量添加返回信息，根据添加设备数量动态申请 */

    BYTE  byRes[128];                                               /* 保留字段  Reserved field */
}NETDEV_ADD_DEV_RESULT_INFO_S, *LPNETDEV_ADD_DEV_RESULT_INFO_S;

/**
 * @struct tagstNETDEVDelDevInfo
 * @brief 待删除设备详细信息
 * @attention
 */
typedef struct tagstNETDEVDelDevInfo
{    
    UINT32 udwDevNum;                                         /* 设备数量 */
    UINT32 udwDevType;                                        /* 设备类型，参见枚举NETDEV_DEVICE_MAIN_TYPE_E */
    UINT32 *pudwIDs;                                          /* 需要删除的设备ID，根据dwDevNum 动态申请 */
    BYTE  byRes[128];                                         /* 保留字段  Reserved field*/
}NETDEV_DEL_DEV_INFO_S, *LPNETDEV_DEL_DEV_INFO_S;

/**
 * @struct tagstNETDEVDelDevResultInfo
 * @brief 批量删除设备返回信息
 * @attention
 */
typedef struct tagstNETDEVDelDevResultInfo
{
    UINT32 udwNum;                                              /* 响应数量 */
    LPNETDEV_OPERATE_INFO_S pstResultInfoList;                  /* 批量删除返回信息，根据删除设备数量动态申请 */

    BYTE  byRes[128];                                           /* 保留字段  Reserved field */
}NETDEV_DEL_DEV_RESULT_INFO_S, *LPNETDEV_DEL_DEV_RESULT_INFO_S;


/************************************************************************/
/*                           经济型鱼眼接入                        */
/************************************************************************/
/**
 * @struct tagNETDEVACSFaceImage
 * @brief 图片信息
 * @attention
 */
typedef struct tagNETDEVACSFaceImage
{
    UINT32               udwNum;                            /* 照片数 */
    NETDEV_FILE_INFO_S   stImageList[NETDEV_LEN_16];        /* 人脸照片列表 */
    UINT32               udwMajorImageIndex;                /* 主照片索引 */

    BYTE                 byRes[128];                        /* 保留字段 */
}NETDEV_ACS_FACE_IMAGE_S, *LPNETDEV_ACS_FACE_IMAGE_S;

/**
 * @struct tagNETDEVACSStaffInfo
 * @brief 员工信息
 * @attention
 */
typedef struct tagNETDEVACSStaffInfo
{
    CHAR     szNumber[NETDEV_LEN_16];                               /* 人员编号 */
    CHAR     szBirthday[NETDEV_FACE_MEMBER_BIRTHDAY_LEN];           /* 出生日期 */
    CHAR     szDeptName[NETDEV_LEN_260];                            /* 部门名称*/
    UINT32   udwDeptID;                                             /* 部门ID */

    BYTE     byRes[128];                                            /* 保留字段 */
}NETDEV_ACS_STAFF_INFO_S, *LPNETDEV_ACS_STAFF_INFO_S;

 /**
 * @struct tagACSTimeSection
 * @brief 时间信息
 * @attention
 */
typedef struct tagACSTimeSection
{
    INT64   tStartTime;                                      /* 起始时间 UTC时间 单位秒s */
    INT64   tEndTime;                                        /* 结束时间 UTC时间 单位秒s */

    BYTE    byRes[32];                                       /* 保留字段 */
}NETDEV_ACS_TIME_SECTION_S, *LPNETDEV_ACS_TIME_SECTION_S;

 /**
 * @struct tagNETDEVACSVisitorInfo
 * @brief 访客信息
 * @attention
 */
typedef struct tagNETDEVACSVisitorInfo
{
    CHAR   szVisitorCompany[NETDEV_LEN_260];       /* 访客公司 [1,64]字符 */
    UINT32 udwVisitorCount;                        /* 访客人数 */
    UINT32 udwIntervieweeID;                       /* 被访者ID */
    CHAR   szIntervieweeName[NETDEV_LEN_260];      /* 被访者姓名 [1,64]字符 */
    CHAR   szIntervieweeDept[NETDEV_LEN_260];      /* 被访者部门 [1,64]字符 */
    NETDEV_ACS_TIME_SECTION_S   tScheduleTime;     /* 预约访问时间 */
    NETDEV_ACS_TIME_SECTION_S   tRealTime;         /* 实际到访时间 */
    UINT32 udwStatus;                              /* 状态 参见枚举NETDEV_ACS_VISIT_STATUS_E */

    BYTE   byRes[128];                             /* 保留字段 */
}NETDEV_ACS_VISITOR_INFO_S, *LPNETDEV_ACS_VISITOR_INFO_S;

/**
 * @struct tagNETDEVACSPersonInfo
 * @brief 门禁人员信息
 * @attention
 */
typedef struct tagNETDEVACSPersonInfo
{
    UINT32                          udwReqSeq;                      /* 请求序号 */
    UINT32                          udwPersonID;                    /* 人员编号 */
    CHAR                            szName[NETDEV_LEN_260];         /* 姓名 */
    UINT32                          udwGender;                      /* 性别 参见枚举 NETDEV_GENDER_TYPE_E*/
    NETDEV_FACE_MEMBER_ID_INFO_S    stMemberIDInfo;                 /* 证件信息 */
    CHAR                            szTelephone[NETDEV_LEN_64];     /* 联系电话 */
    CHAR                            szAddress[NETDEV_LEN_260];      /* 地址 */
    CHAR                            szDesc[NETDEV_LEN_480];         /* 备注 */
    UINT32                          udwCardID;                      /* 卡片编号 */
    CHAR                            szCardNo[NETDEV_LEN_16];        /* 卡片号码*/
    NETDEV_ACS_FACE_IMAGE_S         stFaceImage;                    /* 人脸图片 */
    UINT32                          udwType;                        /* 人员类型  参见NETDEV_ACS_PERSON_TYPE_E*/
    NETDEV_ACS_STAFF_INFO_S         stStaffInfo;                    /* 员工信息 */
    NETDEV_ACS_VISITOR_INFO_S       stVisitor;                      /* 访客信息 */
    BYTE                            byRes[256];                     /* 保留字段 */
}NETDEV_ACS_PERSON_INFO_S, *LPNETDEV_ACS_PERSON_INFO_S;

/**
 * @struct tagNETDEVACSPersonList
 * @brief 人员列表
 * @attention
 */
typedef struct tagNETDEVACSPersonList
{
    UINT32                      udwNum;                 /* 人员数量 */
    LPNETDEV_ACS_PERSON_INFO_S  pstPersonInfoList;      /* 员工信息列表 根据udwNum动态申请*/
    BYTE                        byRes[128];             /* 保留字段 */
}NETDEV_ACS_PERSON_LIST_S, *LPNETDEV_ACS_PERSON_LIST_S;

/**
 * @struct tagNETDEVFaceBatchInfo
 * @brief 人脸识别模块批量操作信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFaceBatchInfo
{
    UINT32   udwReqSeq;         /* 请求数据序号 */
    UINT32   udwResultCode;     /* 返回错误码 */
    UINT32   udwID;             /* 编号 */
    BYTE    byRes[128];         /* 保留字段  Reserved */
}NETDEV_FACE_BATCH_INFO_S,*LPNETDEV_FACE_BATCH_INFO_S;

/**
 * @struct tagNETDEVFaceBatchList
 * @brief 人脸识别模块批量操作列表 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVFaceBatchList
{
    UINT32                      udwNum;         /* 批量操作数量 */
    LPNETDEV_FACE_BATCH_INFO_S  pstBatchList;   /* 批量操作信息 根据udwNum进行动态申请 */
    BYTE                        byRes[128];     /* 保留字段  Reserved */
}NETDEV_FACE_BATCH_LIST_S,*LPNETDEV_FACE_BATCH_LIST_S;

/**
 * @struct tagNETDEVACSPersonBaseInfo
 * @brief 门禁人员基本信息
 * @attention
 */
typedef struct tagNETDEVACSPersonBaseInfo
{
    UINT32                          udwPersonID;                    /* 人员编号 */
    CHAR                            szName[NETDEV_LEN_260];         /* 姓名 */
    UINT32                          udwGender;                      /* 性别 参见枚举 NETDEV_GENDER_TYPE_E*/
    NETDEV_FACE_MEMBER_ID_INFO_S    stMemberIDInfo;                 /* 证件信息 */
    CHAR                            szTelephone[NETDEV_LEN_64];     /* 联系电话 */
    UINT32                          udwCardID;                      /* 卡片编号 */
    CHAR                            szCardNo[NETDEV_LEN_16];        /* 卡片号码*/
    UINT32                          udwType;                        /* 人员类型  0员工  1访客*/
    NETDEV_ACS_STAFF_INFO_S         stStaffInfo;                    /* 员工信息 */
    NETDEV_ACS_VISITOR_INFO_S       stVisitor;                      /* 访客信息 */
    BYTE                            byRes[256];                     /* 保留字段 */
}NETDEV_ACS_PERSON_BASE_INFO_S, *LPNETDEV_ACS_PERSON_BASE_INFO_S;

/**
 * @struct tagNETDEVACSPersonQueryCond
 * @brief 门禁人员基本信息查询条件
 * @attention
 */
typedef struct tagNETDEVACSPersonQueryCond
{
    CHAR     szName[NETDEV_LEN_260];                         /* 姓名 */
    CHAR     szNumber[NETDEV_FACE_IDNUMBER_LEN];             /* 证件号 */
    UINT32   udwType;                                        /* 人员类型  0员工  1访客*/
    UINT32   udwOffset;                                      /* 从当前序号开始查询 序号从0开始*/
    UINT32   udwLimit;                                       /* 每次查询的数量，最大为200 */

    BYTE     byRes[128];                                     /* 保留字段 */
}NETDEV_ACS_PERSON_QUERY_COND_S, *LPNETDEV_ACS_PERSON_QUERY_COND_S;

/**
 * @struct tagNETDEVBatchOperateBasicInfo
 * @brief 批量查询返回的基本信息 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVBatchOperateBasicInfo
{
    UINT32   udwTotal;      /* 数量 */
    UINT32   udwOffset;     /* 查询起始序号 */
    UINT32   udwNum;        /*查询结果总数 */
    BYTE    byRes[128];     /* 保留字段  Reserved */
}NETDEV_BATCH_OPERATE_BASIC_S,*LPNETDEV_BATCH_OPERATE_BASIC_S;

/**
 * @struct tagACSPersonCard
 * @brief 人员所持门禁卡信息
 * @attention
 */
typedef struct tagACSPersonCard
{
    UINT32                      udwCardID;                      /* 绑定ID */
    UINT32                      udwCardType;                    /* 卡片类型 */
    UINT32                      udwCardStatus;                  /* 卡片状态 */
    CHAR                        szCardNo[NETDEV_LEN_64];        /* 卡号 */
    NETDEV_ACS_TIME_SECTION_S   stValidTime;                    /* 有效时间 */

    BYTE                        byRes[256];                     /* 保留字段 */
}NETDEV_ACS_PERSON_CARD_INFO_S,* LPNETDEV_ACS_PERSON_CARD_INFO_S;

/**
 * @struct tagNETDEVACSPersonPermissionInfo
 * @brief 人员授权信息
 * @attention
 */
typedef struct tagNETDEVACSPersonPermissionInfo
{
    NETDEV_OPERATE_LIST_S        stPersonList;                    /* 授权人员ID列表 */
    UINT32                       udwTemplateID;                   /* 时间模板ID  员工授权时携带*/
    NETDEV_ACS_TIME_SECTION_S    stValidTime;                     /* 有效时间，访客授权时携带 */
    NETDEV_OPERATE_LIST_S        stDoorList;                      /* 授权门通道列表，对门通道授权时携带 */
    NETDEV_OPERATE_LIST_S        stDoorGroupList;                 /* 授权门组列表，对门组授权时携带 */
    BYTE                         byRes[256];                      /* 保留字段 */
}NETDEV_ACS_PERSON_PERMISSION_INFO_S, *LPNETDEV_ACS_PERSON_PERMISSION_INFO_S;

/**
 * @struct tagNETDEVACSPersonPermissionBasicInfo
 * @brief 人员授权信息
 * @attention
 */
typedef struct tagNETDEVACSPersonPermissionBasicInfo
{
    UINT32   udwPermissionID;                    /* 权限编号 */
    UINT32   udwPersonID;                        /* 人员编号 */
    CHAR     szPersonName[NETDEV_LEN_260];       /* 人员名称 */
    CHAR     szPersonNumber[NETDEV_LEN_16];      /* 人员编号 */
    UINT32   udwDeptID;                          /* 部门编号 */
    CHAR     szDeptName[NETDEV_LEN_260];         /* 部门名称 */
    UINT32   udwTemplateID;                      /* 模板ID */
    CHAR     szTemplateName[NETDEV_LEN_260];     /* 模板名称 */
    UINT32   udwCardID;                          /* 卡编号 已绑定卡时会携带*/
    CHAR     szCardNo[NETDEV_LEN_64];            /* 卡号 */
    UINT32   udwCardStatus;                      /* 卡状态*/
    UINT32   udwAuthStatus;                      /* 授权状态 0未授权  1已授权*/
    BYTE     byRes[256];                         /* 保留字段 */
}NETDEV_ACS_PERSON_PERMISSION_BASIC_INFO_S, *LPNETDEV_ACS_PERSON_PERMISSION_BASIC_INFO_S;

/**
 * @struct tagNETDEVACSDoorPermissionInfo
 * @brief 门授权信息
 * @attention
 */
typedef struct tagNETDEVACSDoorPermissionInfo
{
    UINT32                       udwTemplateID;                   /* 时间模板ID  员工授权时携带*/
    CHAR                         szTemplateName[NETDEV_LEN_260];  /* 模板名称 */
    NETDEV_ACS_TIME_SECTION_S    stValidTime;                     /* 有效时间 */
    NETDEV_OPERATE_LIST_S        stDoorList;                      /* 授权门通道列表，对门通道授权时携带 */
    NETDEV_OPERATE_LIST_S        stDoorGroupList;                 /* 授权门组列表，对门组授权时携带 */
    BYTE                         byRes[256];                      /* 保留字段 */
}NETDEV_ACS_DOOR_PERMISSION_INFO_S, *LPNNETDEV_ACS_DOOR_PERMISSION_INFO_S;

/**
 * @struct tagNETDEVCompareInfo
 * @brief 人脸对比信息
 * @attention
 */
typedef struct tagNETDEVCompareInfo
{
    NETDEV_FILE_INFO_S  stPersonImage;                    /* 人员图片 */
    NETDEV_FILE_INFO_S  stSnapshotImage;                  /* 抓拍图片 */
    BYTE                byRes[128];                       /* 保留字段 */
}NETDEV_COMPARE_INFO_S, *LPNETDEV_COMPARE_INFO_S;

/**
 * @struct tagNETDEVACSAttendanceLogInfo
 * @brief 出入记录信息
 * @attention
 */
typedef struct tagNETDEVACSAttendanceLogInfo
{
    UINT32 udwAlarmType;                    /* 告警类型 */
    INT64  tTimeStamp;                      /* 告警时间 */
    CHAR   szDoorName[NETDEV_LEN_260];      /* 门名称 */
    CHAR   szDoorNo[NETDEV_LEN_64];         /* 门编号 */
    UINT32 udwDoorDirect;                   /* 进出方向 0:进,1:出 */
    CHAR   szCardNo[NETDEV_LEN_64];         /* 刷卡卡号*/
    CHAR   szPersonName[NETDEV_LEN_260];    /* 刷卡人姓名 */
    UINT32 udwPersonType;                   /* 人员类型  参见NETDEV_ACS_PERSON_TYPE_E*/
    CHAR   szPersonPhone[NETDEV_LEN_64];    /* 刷卡人电话 */
    CHAR   szPersonDept[NETDEV_LEN_260];    /* 刷卡人部门 */
    NETDEV_COMPARE_INFO_S stCompareInfo;    /* 脸对比信息，速通门会携带此信息 */

    BYTE   byRes[256];                      /* 保留字段 */
}NETDEV_ACS_ATTENDANCE_LOG_INFO_S, *LPNETDEV_ACS_ATTENDANCE_LOG_INFO_S;

 /**
 * @struct tagACSVisitLogInfo
 * @brief 访客记录信息
 * @attention
 */
typedef struct tagACSVisitLogInfo
{
    UINT32 udwLogID;                                /* 日子ID */
    UINT32 udwVisitorID;                            /* 访客ID */
    CHAR   szVisitorName[NETDEV_LEN_260];           /* 访客姓名 [1,64]字符 */
    CHAR   szVisitorCompany[NETDEV_LEN_260];        /* 访客公司 [1,64]字符 */
    CHAR   szVisitorPhone[NETDEV_LEN_64];           /* 访客电话 */
    CHAR   szCardNo[NETDEV_LEN_16];                 /* 访客卡号 */
    UINT32 udwIntervieweeID;                        /* 被访者ID */
    CHAR   szIntervieweeName[NETDEV_LEN_260];       /* 被访者姓名 [1,64]字符 */
    CHAR   szIntervieweeDept[NETDEV_LEN_260];       /* 被访者部门 [1,64]字符 */
    INT64  tScheduleStartTime;                      /* 预约来访时间 UTC时间 单位秒s */
    INT64  tRealStartTime;                          /* 实际来访时间 UTC时间 单位秒s */
    UINT32 udwStatus;                               /* 状态 参见枚举NETDEV_ACS_VISIT_STATUS_E */
    BYTE   byRes[256];                              /* 保留字段 */
}NETDEV_ACS_VISIT_LOG_INFO_S, *LPNETDEV_ACS_VISIT_LOG_INFO_S;


/**
 * @enum tagNETDEVAlarmActionType
 * @brief 输出开关量的报警状态
 * @attention
 */
typedef struct tagNETDEVSwitchOutputAlarmStatus
{
    UINT32 udwID;               /* 输出开关量编号 */
    INT32  dwAlarmStatus;       /* 开关量输出告警状态 */
    BYTE   bRes[32];            /* 保留字段 */
}NETDEV_ALARM_STATUS_S,* LPNETDEV_ALARM_STATUS_S;

/*************************************************************************************************************
************************************获取通道列表Begin******************************************************
***************************************************************************************************************/
/**
 * @struct tagstNETDEVDevChnBaseInfo
 * @brief 设备通道基本信息
 * @attention
 */
typedef struct tagstNETDEVDevChnBaseInfo
{    
    INT32 dwChannelID;                                      /* 通道ID */
    INT32 dwDevID;                                          /* 设备ID */
    INT32 dwOrgID;                                          /* 组织ID */
    INT32 dwChnType;                                        /* 通道类型，参见 NETDEV_CHN_TYPE_E */
    INT32 dwChnStatus;                                      /* 通道状态, 参见 NETDEV_CHN_STATUS_E */
    INT32 dwChnIndex;                                       /* 通道索引 */
    CHAR szChnName[NETDEV_NAME_MAX_LEN];                    /* 通道名称 */
    UINT32 udwRight;                                        /* 通道权限 */
    BYTE   byRes[128];                                      /* 保留字段 */
}NETDEV_DEV_CHN_BASE_INFO_S, *LPNETDEV_DEV_CHN_BASE_INFO_S;

/**
 * @struct tagstNETDEVDevChnEncodeInfo
 * @brief 设备编码通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnEncodeInfo
{
    NETDEV_DEV_CHN_BASE_INFO_S  stChnBaseInfo;  /* 通道基本信息 */
    INT32                       dwMaxStream;    /* 支持的最大流个数 */
    BOOL                        bSupportPTZ;    /* 是否支持云台 */
    INT32                       dwAudioResID;   /* 音频资源ID */
    BYTE                        byRes[260];     /* 保留字段 */
}NETDEV_DEV_CHN_ENCODE_INFO_S, *LPNETDEV_DEV_CHN_ENCODE_INFO_S;

/**
 * @struct tagstNETDEVDevChnDecodeInfo
 * @brief 设备解码通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnDecodeInfo
{    
    NETDEV_DEV_CHN_BASE_INFO_S      stChnBaseInfo;              /* 通道基本信息 */
    INT32 dwVideoFmtCapSize;                                    /* 编码制式能力集选项数量 */
    INT32 adwVideoFormatCap[NETDEV_VIDEO_FORMAT_CAP_NUM];       /* 编码制式能力集 参见枚举NETDEV_DC_VIDEOFORMAT_E*/
    INT32 dwLayoutCapSize;                                      /* 分屏能力集选项数量 */
    INT32 adwLayoutCap[NETDEV_LAYOUT_CAP_NUM];                  /* 分屏能力集 */
    INT32 dwResolutionDefault;                                  /* 默认分辨率制式 参见枚举NETDEV_DC_VIDEOFORMAT_E */

    BYTE   byRes[260];                                          /* 保留字段 */
}NETDEV_DEV_CHN_DECODE_INFO_S, *LPNETDEV_DEV_CHN_DECODE_INFO_S;

/**
 * @struct tagstNETDEVDevChnAlarmOutInfo
 * @brief 告警输出通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnAlarmOutInfo
{
    NETDEV_DEV_CHN_BASE_INFO_S  stChnBaseInfo;  /* 通道基本信息 */
    INT32                       dwRunMode;      /* 运行模式（常开/常闭）参见#NETDEV_ALARM_STATUS_E */
    INT32                       dwDuration;     /* 持续时间：(ms) */
    BYTE                        byRes[260];     /* 保留字段 */
}NETDEV_DEV_CHN_ALARMOUT_INFO_S, *LPNETDEV_DEV_CHN_ALARMOUT_INFO_S;

/**
 * @struct tagstNETDEVDevChnAlarmInInfo
 * @brief 告警输入通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnAlarmInInfo
{
    NETDEV_DEV_CHN_BASE_INFO_S  stChnBaseInfo;  /* 通道基本信息 */
    INT32                       dwRunMode;      /* 运行模式（常开/常闭）参见#NETDEV_ALARM_STATUS_E */
    BOOL                        bEnable;        /* 使能开关（使能开/使能关） */
    BYTE                        byRes[260];     /* 保留字段 */
}NETDEV_DEV_CHN_ALARMIN_INFO_S, *LPNETDEV_DEV_CHN_ALARMIN_INFO_S;

/**
 * @struct tagstNETDEVDevChnAudioInfo
 * @brief 音频通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnAudioInfo
{
    NETDEV_DEV_CHN_BASE_INFO_S      stChnBaseInfo;         /* 通道基本信息 */
    INT32                           dwAssociatedResID;     /* 音频通道的关联资源ID */

    BYTE   byRes[256];                                      /* 保留字段 */
}NETDEV_DEV_CHN_AUDIO_INFO_S, *LPNETDEV_DEV_CHN_AUDIO_INFO_S;

/**
 * @struct tagstNETDEVDevChnDaInfo
 * @brief 代理设备通道信息(门禁、报警点)
 * @attention
 */
typedef struct tagstNETDEVDevChnDaInfo
{    
    NETDEV_DEV_CHN_BASE_INFO_S  stChnBaseInfo;                          /* 通道基本信息 */
    CHAR                        szPointCode[NETDEV_DA_POINT_CODE_LEN];  /* 点位编码或门编码 */
    CHAR                        szAreaCode[NETDEV_DA_AREA_CODE_LEN];    /* 区域编码 */
    UINT32                      udwPointStatus;                         /* 告警点位状态请参考#NETDEV_ALARM_POINT_STATUS_TYPE_E 或门状态 请参考#NETDEV_DOOR_STATUS_TYPE_E */

    BYTE                        byRes[260];                             /* 保留字段 */
}NETDEV_DEV_CHN_DA_INFO_S, *LPNETDEV_DEV_CHN_DA_INFO_S;

/**
 * @struct tagstNETDEVDevChnXWEncodeInfo
 * @brief 设备XW本地信号源通道信息
 * @attention
 */
typedef struct tagstNETDEVDevChnXWEncodeInfo
{
    NETDEV_DEV_CHN_BASE_INFO_S  stChnBaseInfo;  /* 通道基本信息 */
    INT32                       dwVideoSrc;     /* 视频输入格式 NETDEV_VIDEO_SRC_TYPE_E */
    BYTE                        byRes[260];     /* 保留字段 */
}NETDEV_DEV_CHN_XW_ENCODE_INFO_S, *LPNETDEV_DEV_CHN_XW_ENCODE_INFO_S;


/**
 * @struct tagNETDEVEmergencyBellInfo
 * @brief 紧急铃信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVEmergencyBellInfo
{
    UINT32   udwID;                                            /* 紧急铃序号 */
    BOOL     bEnable;                                          /* 紧急铃使能标记*/
    CHAR     szName[NETDEV_EMERGENCY_BRLL_NAME_LEN];           /* 紧急铃名称 支持中文 */
    UINT32   udwRegionCode;                                    /* 紧急铃地区码 */
    UINT32   udwDistrictCode;                                  /* 紧急铃区域码 */
    UINT32   udwAddressCode;                                   /* 紧急铃地址码 */
    BYTE     byRes[108];                                       /* 保留字段 */
}NETDEV_EMERGENCY_BELL_INFO_S, *LPNETDEV_EMERGENCY_BELL_INFO_S;

/**
 * @struct tagNETDEVEmergencyBellInfoList
 * @brief 紧急铃列表信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVEmergencyBellInfoList
{
    UINT32   udwNum;                                           /* 紧急铃个数 用户输入申请的紧急铃个数，现阶段固定是NETDEV_EMERGENCY_BRLL_MAX_NUM*/
    LPNETDEV_EMERGENCY_BELL_INFO_S pstEmergencyBellList;       /*紧急铃信息 动态申请，一次申请NETDEV_EMERGENCY_BRLL_MAX_NUM个，*/

    BYTE     byRes[16];                                       /* 保留字段 */
}NETDEV_EMERGENCY_BELL_INFO_LIST_S, *LPNETDEV_EMERGENCY_BELL_INFO_LIST_S;


/**
 * @struct tagNETDEVPtzCapabilityInfo
 * @brief 视频通道云台能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVPtzCapabilityInfo
{
    BOOL   bIsSupportPtz;       /* 是否支持云台 0不支持 1支持 */
    BOOL   bIsSupportTrack;     /* 是否支持录制巡航 0不支持 1支持 */

    BYTE   byRes[128];          /* 保留字段 */
}NETDEV_PTZ_CAPABILITY_INFO_S, *LPNETDEV_PTZ_CAPABILITY_INFO_S;

/**
 * @struct tagNETDEVVideoCapabilityInfo
 * @brief 视频通道实况能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVVideoCapabilityInfo
{
    BOOL   bIsSupportImageSettings;     /* 是否支持画面调节 0不支持 1支持 */

    BYTE   byRes[128];                  /* 保留字段 */
}NETDEV_VIDEO_CAPABILITY_INFO_S, *LPNETDEV_VIDEO_CAPABILITY_INFO_S;

/**
 * @struct tagNETDEVPlayBackCapabilityInfo
 * @brief 视频通道回放能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVPlayBackCapabilityInfo
{
    BOOL   bIsSupportStep;      /* 是否支持单帧 0不支持 1支持 */
    BOOL   bIsSupportIntgVod;   /* 是否支持智能回放 0不支持 1支持 */

    BYTE   byRes[128];          /* 保留字段 */
}NETDEV_PLAYBACK_CAPABILITY_INFO_S, *LPNETDEV_PLAYBACK_CAPABILITY_INFO_S;

/**
 * @struct tagNETDEVSmartCapabilityInfo
 * @brief 视频通道实况能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVSmartCapabilityInfo
{
    BOOL   bIsSupportPassengerFlow;     /* 是否支持客流量统计 0不支持 1支持 */
    BOOL   bIsVehicleDetection;         /* 是否支持车辆检测 0：不支持 1：支持 */
    BYTE   byRes[251];                  /* 保留字段 */
}NETDEV_SMART_CAPABILITY_INFO_S, *LPNETDEV_SMART_CAPABILITY_INFO_S;


/**
 * @struct tagNETDEVVideoDetailCapabilityInfo
 * @brief 视频通道能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVVideoDetailCapabilityInfo
{
    INT32                             dwChannelID;                     /* 通道ID  */
    NETDEV_PTZ_CAPABILITY_INFO_S      stPtzCapabilityInfo;             /* 云台能力集 */
    NETDEV_VIDEO_CAPABILITY_INFO_S    stVideoCapabilityInfo;           /* 实况能力 */
    NETDEV_PLAYBACK_CAPABILITY_INFO_S stPlayBackCapabilityInfo;        /* 回放能力 */
    NETDEV_SMART_CAPABILITY_INFO_S    stSmartCapabilityInfo;           /* 智能能力集 */

    BYTE                              byRes[128];                      /* 保留字段 */
}NETDEV_VIDEO_DETAIL_CAPABILITY_INFO_S, *LPNETDEV_VIDEO_DETAIL_CAPABILITY_INFO_S;

/**
 * @struct tagNETDEVDevSmartCapabilityInfo
 * @brief 设备智能能力集 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVDevSmartCapabilityInfo
{
    BOOL   bIsFaceRecognitionSupported;     /* 是否支持人脸识别能力 0不支持 1支持 */
    BOOL   bIsFaceDetectionSupported;       /* 是否支持人脸检测功能 0不支持 1支持 */
    BOOL   bIsVehicleRecognitionSupported;  /* 是否支持车辆识别功能 0不支持 1支持 */

    BYTE   byRes[255];                      /* 保留字段 */
}NETDEV_DEV_SMART_CAPABILITY_INFO_S, *LPNETDEV_DEV_SMART_CAPABILITY_INFO_S;

 /**
 * @struct tagNETDEVDevCapabilityInfo
 * @brief 设备能力集信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVDevCapabilityInfo
{
    UINT32                              udwDevID;                          /* 设备ID  */
    NETDEV_DEV_SMART_CAPABILITY_INFO_S  stSmartCapabilityInfo;          /* 智能能力集 */
    BYTE                                byRes[256];                         /* 保留字段 */
}NETDEV_DEV_CAPABILITY_INFO_S, *LPNETDEV_DEV_CAPABILITY_INFO_S;


 /**
 * @struct tagNETDEVSystemCapabilityInfo
 * @brief 系统能力集信息 结构体定义
 * @attention 无 None
 */
typedef struct tagNETDEVSystemCapabilityInfo
{
    UINT32  udwSize;                             /* 文件大小 */
    CHAR    *pcData;                             /* 文件数据 根据Size动态申请*/
    BYTE    byRes[256];                         /* 保留字段 */
}NETDEV_SYSTEM_CAPABILITY_INFO_S, *LPNETDEV_SYSTEM_CAPABILITY_INFO_S;

/**
 * @struct tagNETDEVVideoSnapCapInfo
 * @brief 视频输入通道的抓图参数能力 Snap parameter capability
 * @attention
 */
typedef struct tagNETDEVVideoSnapCapInfo
{
    BOOL bIsSupportSnapshotCfg;                                                  /* 设备是否支持抓图可配置,0: 不支持, 1: 支持 Support configuration or not. 0-No, 1-Yes*/
    UINT32 udwPictureMaxSize;                                                    /* 抓图支持的图片大小的最大值 */
    UINT32 udwResolutionNum;                                                     /* 支持的分辨率个数 */
    NETDEV_VIDEO_RESOLUTION_S astResolutionCapList[NETDEV_LEN_16];               /* 支持的抓图分辨率信息列表 */

    BYTE   byRes[255];                                                           /* 保留字段 */
 
}NETDEV_VIDEO_SNAP_CAP_S,*LPNETDEV_VIDEO_SNAP_CAP_S;

/**
 * @struct tagNETDEVVideoSnapshotInfo
 * @brief 视频输入通道的抓图信息 Snap parameter info
 * @attention
 */
typedef struct tagNETDEVVideoSnapshotInfo
{
    BOOL bIsEnabled;                                                             /* 抓图使能,0: 关闭, 1: 开启 Support configuration or not. 0-close, 1-open*/
    UINT32 udwPictureMaxSize;                                                    /* 最大图片大小 */
    UINT32 udwSnapshotInterval;                                                  /* 抓图间隔，范围[1, 60],单位:秒。仅在抓图数量SnapshotNum设置为2或3时有效 */
    UINT32 udwSnapshotNum;                                                       /* 抓图数量，范围[1,3] */
    NETDEV_VIDEO_RESOLUTION_S stResolution;                                      /* 抓图分辨率 */

    BYTE   byRes[255];                                                           /* 保留字段 */
}NETDEV_VIDEO_SNAPSHOT_S,*LPNETDEV_VIDEO_SNAPSHOT_S;


/**
 * @struct tagstNETDEVAlarmLevelInfo
 * @brief 告警级别信息
 * @attention 
 */
typedef struct tagstNETDEVAlarmLevelInfo
{
    INT32   dwAlarmType;                    /* 告警类型 参见NETDEV_ALARM_TYPE_E*/
    INT32   dwAlarmSubType;                 /* 告警子类型 参见NETDEV_ALARM_SUBTYPE_E*/
    INT32   dwAlarmLevel;                   /* 告警级别 */
}NETDEV_ALARM_LEVEL_INFO_S, *LPNETDEV_ALARM_LEVEL_INFO_S;

/**
 * @struct tagstNETDEVAlarmLevelInfoList
 * @brief 告警级别信息列表
 * @attention
 */
typedef struct tagstNETDEVAlarmLevelInfoList
{
    INT32                           dwSize;                 /* 告警级别信息数量 */
    LPNETDEV_ALARM_LEVEL_INFO_S     pstAlarmLevelInfo;      /* 告警级别信息列表*/
}NETDEV_ALARM_LEVEL_INFO_LIST_S, *LPNETDEV_ALARM_LEVEL_INFO_LIST_S;

/**
 * @struct tagNETDEVBatchOperateList
 * @brief 批量操作列表 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVBatchOperateList
{
    UINT32                          udwNum;         /* 批量操作数量 */
    UINT32                          udwStatus;      /* 结果状态 */
    LPNETDEV_BATCH_OPERATOR_INFO_S  pstBatchList;   /* 批量操作信息 最大是2000个,需动态申请 */
    BYTE                            byRes[128];     /* 保留字段  Reserved */

}NETDEV_BATCH_OPERATOR_LIST_S,*LPNETDEV_BATCH_OPERATOR_LIST_S;

/**
 * @struct tagNETDEVMonitorDevResultInfo
 * @brief 设备布控结果信息 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVMonitorDevResultInfo
{
    UINT32                          udwDevID;           /* 布控设备ID */
    NETDEV_BATCH_OPERATOR_LIST_S    stMonitorResult;    /* 设备布控结果信息 */
    BYTE                            byRes[128];         /* 保留字段  Reserved */
}NETDEV_MONITOR_DEV_RESULT_INFO_S,*LPNETDEV_MONITOR_DEV_RESULT_INFO_S;

/**
 * @struct tagNETDEVMonitorDevResultList
 * @brief 设备布控结果列表 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVMonitorDevResultList
{
    UINT32                              udwDevNum;                                  /* 布控设备数量 */
    NETDEV_MONITOR_DEV_RESULT_INFO_S    astMonitorDevResultInfo[NETDEV_LEN_16];     /* 布控设备结果信息列表 目前最大量是5台设备*/
    BYTE                                byRes[128];                                 /* 保留字段  Reserved */
}NETDEV_MONITOR_DEV_RESULT_LIST_S,*LPNETDEV_MONITOR_DEV_RESULT_LIST_S;

/**
 * @struct tagNETDEVBatchOperateMemberList
 * @brief 批量操作成员列表 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVBatchOperateMemberList
{
    UINT32  udwTaskNo;             /* 操作任务号，仅NVR支持 */
    UINT32  udwMemberNum;          /* 成员数量 */
    UINT32* pstMemberIDList;       /* 成员列表 根据udwNum进行动态申请 */
    BYTE    byRes[128];             /* 保留字段  Reserved */

}NETDEV_BATCH_OPERATE_MEMBER_LIST_S,*LPNETDEV_BATCH_OPERATE_MEMBER_LIST_S;

/**
* @struct tagNETDEVMonitorCapacityInfo
* @brief 容量布控信息结构体定义
* @attention 无None
*/
typedef struct tagNETDEVMonitorCapacityInfo
{
    UINT32  udwMonitorType;         /* 布控类型 0：人脸布控   1：车辆布控 */
    UINT32  udwNum;                 /* 设备数量 */
    UINT32  *pudwDevIDList;         /* 设备ID列表 根据udwNum动态申请*/
    BYTE    byRes[128];             /* 保留字段  Reserved */
}NETDEV_MONITOR_CAPACITY_INFO_S, *LPNETDEV_MONITOR_CAPACITY_INFO_S;

/**
* @struct tagNETDEVDevCapacityInfo
* @brief 设备容量信息结构体定义
* @attention 无None
*/
typedef struct tagNETDEVDevCapacityInfo
{
    UINT32  udwDevID;               /* 设备ID */
    UINT32  udwCapacity;            /* 设备布控人脸总数量 */
    UINT32  udwMonitoredNum;        /* 已布控人脸数量 */
    BYTE    byRes[128];             /* 保留字段  Reserved */
}NETDEV_DEV_CAPACITY_INFO_S, *LPNETDEV_DEV_CAPACITY_INFO_S;

/**
* @struct tagNETDEVMonitorCapacityList
* @brief 容量布控操作列表结构体定义
* @attention 无None
*/
typedef struct tagNETDEVMonitorCapacityList
{
    UINT32                          udwDevNum;              /* 设备数量 */
    LPNETDEV_DEV_CAPACITY_INFO_S    pstDevCapacityList;     /* 容量列表 根据DevNum动态申请 */
    BYTE                            byRes[64];              /* 保留字段  Reserved */
}NETDEV_MONITOR_CAPACITY_LIST_S, *LPNETDEV_MONITOR_CAPACITY_LIST_S;



/**
* @struct tagNETDEVDevMonitorInfo
* @brief 成员布控设备信息结构体定义
* @attention 无None
*/
typedef struct tagNETDEVDevMonitorInfo
{
    UINT32  udwDevID;               /* 设备ID */
    UINT32  udwMonitorStatus;       /* 设备布控状态 */
    BYTE    byRes[64];              /* 保留字节 */
}NETDEV_DEV_MONITOR_INFO_S,*LPNETDEV_DEV_MONITOR_INFO_S;

/**
* @struct tagNETDEVMonitorMemberInfo
* @brief 成员布控状态信息结构体定义
* @attention 无None
*/
typedef struct tagNETDEVMonitorMemberInfo
{
    UINT32                      udwMemberID;                        /* 成员ID */
    CHAR                        szName[NETDEV_LEN_260];             /* 成员名称 */
    UINT32                      udwDevNum;                          /* 布控设备数量 */
    UINT32                      udwMonitorStatus;                   /* 布控状态 0:布控失败   1:布控成功*/
    NETDEV_DEV_MONITOR_INFO_S   stDevMonitorInfo[NETDEV_LEN_16];    /* 成员布控设备信息列表 目前设备数量最大为5*/
    BYTE                        byRes[64];                          /* 保留字段  Reserved */
}NETDEV_MONITOR_MEMBER_INFO_S,*LPNETDEV_MONITOR_MEMBER_INFO_S;

/**
* @struct tagNETDEVMonitorFaceVehicle
* @brief 布控任务下车辆/人脸成员
* @attention 无None
*/
typedef struct tagNETDEVMonitorFaceVehicle
{
    UINT32                          udwMemberNum;                           /* 成员数量 */
    NETDEV_MONITOR_MEMBER_INFO_S    stMonitorMemberInfo[NETDEV_LEN_32];     /* 成员布控状态信息 */
    BYTE                            byRes[64];                              /* 保留字段  Reserved */
}NETDEV_MONITOR_FACE_VEHICLE_S,*LPNETDEV_MONITOR_FACE_VEHICLE_S;


/**
 * @struct tagNETDEVDeleteDBFlagInfo
 * @brief 删除库信息标志位
 * @attention 无 None
 */
typedef struct tagNETDEVDeleteDBFlagInfo
{
    BOOL     bIsDeleteMember;       /* 是否删除库下里面的成员信息：0:不删除 1:删除 */
    BYTE     byRes[128];            /* 保留字段  Reserved */

}NETDEV_DELETE_DB_FLAG_INFO_S,*LPNETDEV_DELETE_DB_FLAG_INFO_S;

/**
 * @struct tagNETDEVFaceDBMemberCond
 * @brief 人脸库成员查询条件 结构体定义 
 * @attention 无 None
 */
typedef struct tagNETDEVFaceDBMemberCond
{
    UINT32   udwOffset;     /* 分页查询中第一条数据的序号 */
    UINT32   udwLimit;      /* 每页最大条数 */
    BYTE    byRes[128];     /* 保留字段  Reserved */
}NETDEV_FACE_DB_MEMBER_COND_S,*LPNETDEV_FACE_DB_MEMBER_COND_S;


/**
 * @struct tagNETDEVFaceAddMemberList
 * @brief 批量新增人脸成员列表 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVFaceAddMemberList
{
    UINT32                      udwTaskNo;              /* 操作任务号，仅NVR支持 */
    UINT32                      udwNum;                 /* 人脸成员数量 */
    LPNETDEV_FACE_MEMBER_INFO_S pstMemberInfoList;      /* 人脸列表成员 根据udwNum进行动态申请 */
    BYTE                        byRes[128];             /* 保留字段  Reserved */

}NETDEV_FACE_ADD_MEMBER_LIST_S,*LPNETDEV_FACE_ADD_MEMBER_LIST_S;



/**
 * @struct tagstNETDEVFaceSnapFeature
 * @brief 人脸识别抓拍特征
 * @attention
 */
typedef struct tagstNETDEVFaceSnapFeature
{
    UINT32   udwAge;                            /* 年龄 */
    UINT32   udwGender;                         /* 性别 参见枚举NETDEV_FACE_MEMBER_GENDER_TYPE_E*/
    BOOL     bWithGlasses;                     /* 是否带眼镜 */
    BOOL     bWithSmile;                       /* 是否微笑 */
    UINT32   udwHappyIndex;                     /* 开心指数 */

    BYTE     byRes[128];                        /* 保留字段  Reserved */
}NETDEV_FACE_SNAP_FEATURE_INFO_S, *LPNETDEV_FACE_SNAP_FEATURE_INFO_S;

/**
 * @struct tagstNETDEVFaceSnapLog
 * @brief 人脸识别抓拍事件
 * @attention
 */
typedef struct tagstNETDEVFaceSnapLog
{
    UINT32                          udwID;                                  /* 抓拍记录ID */
    UINT32                          udwTimestamp;                           /* 时间 */
    CHAR                            szAlarmSrc[NETDEV_FACE_ALARM_SRC_LEN];  /* 抓拍相机 */
    NETDEV_FACE_SNAP_FEATURE_INFO_S stSnapFeature;                          /* 抓拍特征 */
    NETDEV_FACE_ALARM_SNAP_IMAGE_S  stSnapImage;                            /* 抓拍图片信息 */

    BYTE                            byRes[128];                             /* 保留字段  Reserved */
}NETDEV_FACE_SNAP_LOG_INFO_S, *LPNETDEV_FACE_SNAP_LOG_INFO_S;


/**
 * @struct tagNETDEVAddVehicleMemberList
 * @brief 批量新增成员列表 结构体定义 Device information Structure definition
 * @attention 无 None
 */
typedef struct tagNETDEVAddVehicleMemberList
{
    UINT32                          udwTaskNo;              /* 操作任务号，仅NVR支持 */
    UINT32                          udwVehicleNum;          /* 车辆成员数量 */
    LPNETDEV_VEHICLE_DETAIL_INFO_S  pstMemberInfoList;      /* 车辆成员列表 根据udwNum进行动态申请 */
    BYTE                            byRes[128];             /* 保留字段  Reserved */
}NETDEV_ADD_VEHICLE_MEMBER_LIST_S,*LPNETDEV_ADD_VEHICLE_MEMBER_LIST_S;

/**
 * @struct tagDSTCfgTimeInfo
 * @brief 夏令时时间
 * @attention
 */
typedef struct tagDSTCfgTimeInfo
{
    UINT32    udwMonth;                   /* 开始的月份 1:一月  2:二月.....12:十二月*/
    UINT32    udwWeekNum;                 /* 开始这个月的第几周 1:第一周 2:第二周 1:第一周 3:第三周 4:第四周 5:最后一周 */
    UINT32    udwWeekDay;                 /* 开始这个月第X周的周几 1:周一  2:周二  3:周三  4:周四  5:周五  6:周六  7:周日*/
    UINT32    udwHour;                    /* 开始时间，单位小时（24小时制）0：00:00     1：01:00     2：02:00   3：03:00     22：22:00      23：23:00 */
    BYTE      byRes[256];                 /* 保留字段 */
}NETDEV_DST_CFG_TIME_INFO_S,* LPNETDEV_DST_CFG_TIME_INFO_S;


/**
* @brief 通道权限信息 结构体定义
* @attention 无
*/
typedef struct tagNETDEVChnPermissionInfo
{
    INT32    dwChannelID;               /* 通道号 */
    INT32    dwPermission;              /* 通道权限, 请参考#NETDEV_CHN_PERMISSION_TYPE_E */
    BYTE     byRes[256];                /* 保留字段  Reserved */
}NETDEV_CHN_PERMISSION_INFO_S, *LPNETDEV_CHN_PERMISSION_INFO_S;


/**
 * @brief用户详细信息
 * @attention 
 */
typedef struct tagNETDEVUserDetailInfo
{
    UINT32                         udwLevel;                                          /* 用户等级  参见枚举 NETDEV_USER_LEVEL_E*/
    CHAR                           szUserName[NETDEV_LEN_64];                         /* 用户名 不支持修改，获取单个信息时作为入参 范围1~18*/
    CHAR                           szPassword[NETDEV_LEN_256];                        /* 密码 添加使用 范围0~256 获取时不返回该字段*/
    UINT32                         udwBasePermission;                                 /* 基本权限，参见枚举NETDEV_USER_BASE_PERMISSION_E 按BIT位进行权限描述，相应BIT为1，表示该权限生效，为0表示该权限不生效*/
    UINT32                         udwNum;                                            /* 视频输入通道数量 */
    NETDEV_CHN_PERMISSION_INFO_S   astChnPermission[NETDEV_CHANNEL_MAX];              /* 通道权限列表 */
    BYTE                           byRes[256];                                        /* 保留字段 */
}NETDEV_USER_DETAIL_INFO_S, *LPNETDEV_USER_DETAIL_INFO_S;

/**
 * @brief修改用户详细信息
 * @attention 
 */
typedef struct tagNETDEVUserModifyDetailInfo
{
    NETDEV_USER_DETAIL_INFO_S      stUserInfo;
    BOOL                           bIsModifyPassword;                       /* 是否修改密码, 修改时赋值 */
    BOOL                           bIsModifyOther;                          /* 是否管理员修改其他用户, 修改时赋值 */
    CHAR                           szNewPassword[NETDEV_LEN_256];           /* 新密码(修改密码时使用)，范围0~256 不涉及密码的修改 那么该字段可不下发，如果配置时，密码为空，则下发空字段*/
    CHAR                           szCurrentPassword[NETDEV_LEN_256];       /* /当前使用的密码 修改密码时携带 范围0~256 管理员修改其他用户密码只需要新密码则可，如果配置时，密码为空，则下发空字段*/
    BYTE                           byRes[256];                              /* 保留字段 */
}NETDEV_USER_MODIFY_DETAIL_INFO_S, *LPNETDEV_USER_MODIFY_DETAIL_INFO_S;

/**
 * @brief用户信息列表
 * @attention 
 */
typedef struct tagNETDEVUserDetailList
{
    UINT32                      udwNum;                          /* 用户数量 */
    NETDEV_USER_DETAIL_INFO_S   astUserInfo[NETDEV_LEN_64];     /* 用户列表 */
    BYTE                        byRes[128];                      /* 保留字段 */
}NETDEV_USER_DETAIL_LIST_S, *LPNETDEV_USER_DETAIL_LIST_S;

/**
 * @struct tagNetWorkCloudInfo
 * @brief MyCloud信息
 * @attention
 */
typedef struct tagNetWorkCloudInfo
{
    BOOL        bEnable;                                  /* 云是否使能 0 不使能 1使能 */
    UINT32      udwType;                                  /* 类型，暂时为0 */
    UINT32      udwConStatus;                             /* 连接状态 0未连接 1已连接 */
    CHAR        szDomainAddress[NETDEV_DOMAIN_LEN];       /* 域名 */
    CHAR        szDevName[NETDEV_LEN_64];                 /* 设备名称  Device name */
    CHAR        szUserName[NETDEV_LEN_64];                /* 用户名称  User name */
    CHAR        szPassWord[NETDEV_LEN_64];                /* 密码 */
    UINT32      udwOffLineErrCode;                        /* 下线原因 参见枚举NETDEV_MYCLOUD_OFF_ERR_E */
    CHAR        szRegisterCode[NETDEV_LEN_64];            /* 注册码 */
    BYTE        byRes[256];                               /* 保留字段 */
}NETDEV_NETWORK_CLOUD_INFO_S,* LPNETDEV_NETWORK_CLOUD_INFO_S;


/**
 * @brief 配置视频分发服务器信息
 * @attention
 */
typedef struct tagstNETDEVCDNSrvInfo
{
    UINT32  udwState;                           /* 流分发功能状态:0：不可用1：可用 */
    FLOAT   fSurplusFlux;                       /* 剩余流量(单位：GB) */
    CHAR    szServerDomain[NETDEV_LEN_256];     /* 服务器域名 */
    BYTE    byRes[256];
}NETDEV_CDN_SRV_INFO_S, *LPNETDEV_CDN_SRV_INFO_S;

/**
 * @brief 视频分发配置
 * @attention
 */
typedef struct tagstNETDEVCDNRule
{
    BOOL    bEnable;        /* 分发功能是否开启 */
    UINT32  ProtocolType;   /* 分发协议类型, 参见NETDEV_CDN_PROT_E */
    BYTE    byRes[256];
}NETDEV_CDN_RULE_S, *LPNETDEV_CDN_RULE_S;

/**
 * @brief 视频分发通道信息信息
 * @attention
 */
typedef struct tagstNETDEVCDNChnInfo
{
    UINT32  udwChannelID;                   /* 通道号 */
    UINT32  udwStreamType;                  /* 码流类型 */
    CHAR    szStreamUrl[NETDEV_LEN_260];    /* 推流地址 */
    BYTE    byRes[256];
}NETDEV_CDN_CHL_INFO_S, *LPNETDEV_CDN_CHL_INFO_S;

/**
* @struct tagNETDEVLoginNatInfo
* @brief 云设备登录信息
* @attention 无 None
*/
typedef struct tagNETDEVLoginNatInfo
{
    CHAR szDeviceUsername[NETDEV_LEN_260];      /* 设备登录用户名 */
    BYTE byRes[256];                        /* 保留字段 Reserved */
} NETDEV_CLOUD_NAT_LOGIN_INFO_S, *LPNETDEV_CLOUD_NAT_LOGIN_INFO_S;

/**
 * @struct tagNETDEVPersonLibCapInfo
 * @brief 人脸库容量信息
 * @attention 无 None
 */
typedef struct tagNETDEVPersonLibCapInfo
{
    UINT32          udwLibID;            /* 库ID */
    UINT32          udwCapacity;         /* 库容量信息，单位：人 */
    BYTE            byRes[128];          /* 保留字段 */
}NETDEV_PERSON_LIB_CAP_INFO_S, *LPNETDEV_PERSON_LIB_CAP_INFO_S;

/**
 * @struct tagNETDEVPersonLibCapList
 * @brief 所有人员库的容量信息
 * @attention 无 None
 */
typedef struct tagNETDEVPersonLibCapList
{
    UINT32                      udwMaxPerpleMun;                         /* 总库容量，单位：K人 */
    UINT32                      udwFreePerpleNum;                        /* 剩余容量，单位：人 */
    UINT32                      udwMaxLibNum;                            /* 最大可建库容量 */
    UINT32                      udwFreeLibNum;                           /* 剩余可建库容量 */
    UINT32                      udwNum;                                  /* 已建库个数 库个数范围:[0, 16] */
    NETDEV_PERSON_LIB_CAP_INFO_S  stLibCapInfoList[NETDEV_LEN_16];         /* 单库容量信息 */
    BYTE                        byRes[256];                              /* 保留字段 */
}NETDEV_PERSON_LIB_CAP_LIST_S, *LPNETDEV_PERSON_LIB_CAP_LIST_S;

/**
 * @struct tagNETDEVPersonQueryInfo
 * @brief 人员信息查询条件
 * @attention 无 None
 */
typedef struct tagNETDEVPersonQueryInfo
{
    UINT32                      udwNum;             /* 查询条件数量 */
    LPNETDEV_QUERY_INFO_S       pstQueryInfos;      /* 查询条件列表，Num为0时，不带此字段*/
    UINT32                      udwLimit;           /* 每次查询的数量，最大20 */
    UINT32                      udwOffset;          /* 从当前序号开始查询，序号从0开始 */
    BYTE                        byRes[256];         /* 保留字段 */
}NETDEV_PERSON_QUERY_INFO_S, *LPNETDEV_PERSON_QUERY_INFO_S;

/**
 * @struct tagNETDEVMonitorQueryInfo
 * @brief 布控信息查询条件
 * @attention 无 None
 */
typedef struct tagNETDEVMonitorQueryInfo
{
    UINT32                      udwLimit;           /* 每次查询的数量，最大20 */
    UINT32                      udwOffset;          /* 从当前序号开始查询，序号从0开始 */
    BOOL                        bIsQueryAll;        /* 是否查询所有，是:TRUE,否:FALSE */
    BYTE                        byRes[128];         /* 保留字段 */
}NETDEV_MONITOR_QUERY_INFO_S, *LPNETDEV_MONITOR_QUERY_INFO_S;

/**
 * @struct tagNETDEVPersonQueryResultInfo
 * @brief 布控信息查询结果信息
 * @attention 无 None
 */
typedef struct tagNETDEVPersonQueryResultInfo
{
    UINT32                          udwTotal;           /* 符合查询条件的总数 */
    UINT32                          udwOffset;          /* 当前序号，序号从0开始 */
    NETDEV_PERSON_INFO_LIST_S       stPersonInfoList;   /* 符合条件的人脸信息列表 */
    BYTE                            byRes[256];         /* 保留字段 */
}NETDEV_PERSON_QUERY_RESULT_INFO_S, *LPNETDEV_PERSON_QUERY_RESULT_INFO_S;

////////////////////////////分割线/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                          函数                                  */
/************************************************************************/
/**
* SDK 初始化  SDK initialization
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 线程不安全 Thread not safe
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

/**
* SDK 清理  SDK cleaning
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

/**
* 获取SDK的版本信息 Get SDK version information 
* @return SDK版本信息 SDK version information
* @note
* - 在两个高字节中高8位表示主版本,低八位表示次版本.两个低字节表示附加版本号如0x01080000：表示版本为1.8.0.0.
* - The two high bytes,The high-8-bit indicate the major version, and the low-8-bytes indicate the minor version.Two low bytes for additional version numbers For example, 0x01080000 means version 1.8.0.0
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);

/**
* 获取错误码  Get error codes
* @return 错误码 Error codes
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetLastError();

/**
* 设置日志路径业务 Set log path
* @param [IN]   pszLogPath  日志路径(不包含文件名)  Log path (file name not included)
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetLogPath(IN CHAR *pszLogPath);

/**
* 设置日志文件大小和数量 Set log file size and number
* @param [IN] dwLogFileSize     单个日志文件大小(单位字节) The size of single log file
* @param [IN] dwLogFileNum      日志文件个数  Log file number
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ConfigLogFile(IN INT32 dwLogFileSize,
                                                          IN INT32 dwLogFileNum);

/**
* 设置写入日志的标记 Set write log flag
* @param [IN]   bWriteLogFlag  写入日志的标记  TRUE:写入日志,FALSE：不写入日志
* @return VOID
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetWriteLogFlag(IN BOOL bWriteLogFlag);

/**
* 设置超时时间 Set timeout
* @param [IN]  pstRevTimeout         超时时间指针 Pointer to timeout
* @return TRUE表示成功,其他表示失败    TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRevTimeOut(IN LPNETDEV_REV_TIMEOUT_S pstRevTimeout);

/**
* 设置保活参数 Set keep-alive parameters
* @param [IN]  dwWaitTime            间隔等待时间  Waiting time
* @param [IN]  dwTrytimes            尝试连接次数  Connecting attempts
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetConnectTime(IN INT32 dwWaitTime,
                                                           IN INT32 dwTrytimes);

/**
* 设置客户端唯一标识
* @param [IN] pszClientID                              客户端ID 
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetClientID(IN CHAR *pszClientID);


/**
* 设置最大解码路数
* @param [IN]  dwMaxdecNum        最大解码通道数
* @return TRUE表示成功，其他表示失败
* @note 
*    1、该接口调用失败，表示解码路数为128路
*    2、解码路数包括：实况路数、回放路数、录像下载路数的总和
*    3、该接口调用必须在SDK初始化之前
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetMaxDecChlNum(IN UINT32 dwMaxdecNum);

/**
* 设备发现回调函数 Device discovery callback function
* @param [IN] pstDevInfo                设备信息 Device info
* @param [IN] lpUserData                用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_DISCOVERY_CALLBACK_PF)(IN LPNETDEV_DISCOVERY_DEVINFO_S pstDevInfo,
                                                    IN LPVOID lpUserData);

/**
* 注册设备发现回调函数 Registered device discovery callback function
* @param [IN] cbDiscoveryCallBack   回调函数 Callback function
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDiscoveryCallBack(IN NETDEV_DISCOVERY_CALLBACK_PF cbDiscoveryCallBack,
                                                                 IN LPVOID lpUserData);

/**
* 设备发现 先注册设备发现相关的回调,再调用此接口发现设备,发现的设备信息在回调中反映
* This interface is used for device discovery. Please first register callback functions related to device discovery and use this interface for device discovery. Discovered device info will be included in the callback function.
* @param [IN]   pszBeginIP                 起始IP地址
* @param [IN]   pszEndIP                   结束IP地址
* @return TRUE表示成功,其他表示失败
* @note 若pszBeginIP和pszEndIP都是"0.0.0.0",则搜索本网段设备
*/
NETDEV_API NEWINTERFACE BOOL  STDCALL NETDEV_Discovery(IN CHAR *pszBeginIP,
                                                       IN CHAR *pszEndIP);


/**
* 用户登录  User login
* @param [IN]  pszDevIP         设备IP Device IP
* @param [IN]  wDevPort         设备服务器端口 Device server port
* @param [IN]  pszUserName      用户名 Username
* @param [IN]  pszPassword      密码 Password
* @param [OUT] pstDevInfo       设备信息结构体指针 Pointer to device information structure
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
                                                    IN INT16 wDevPort,
                                                    IN char *pszUserName,
                                                    IN char *pszPassword,
                                                    OUT LPNETDEV_DEVICE_INFO_S pstDevInfo);

/**
* 登陆速度优化 用户登录  User login
* @param  [INOUT]  pstLoginInfo         登录信息 Login Info
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginV2(INOUT LPNETDEV_LOGIN_INFO_S pstLoginInfo);

/**
* 设备登录
* @param [IN]  pstDevLoginInfo  设备登录信息
* @param [OUT] pstSELogInfo     安全登录信息，包含登录失败次数及下次登录时间
* @return 返回值为用户ID。
* @note 安全登录信息此字段仅适用于使用LAPI协议登录的设备
* -
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login_V30(IN LPNETDEV_DEVICE_LOGIN_INFO_S pstDevLoginInfo, 
                                                        OUT LPNETDEV_SELOG_INFO_S pstSELogInfo);

/**
* 用户注销  User logout
* @param [IN] lpUserID    用户登录句柄 User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

/**
* 接收告警消息的回调函数  Callback function to receive alarm information
* @param [IN] lpUserID              用户登录句柄 User login ID
* @param [IN] dwChannelID           通道号 Channel ID
* @param [IN] LPNETDEV_ALARM_INFO_S 告警信息 Alarm information
* @param [IN] lpBuf                 缓冲区指针 Pointer to buffer
* @param [IN] dwBufLen              告警信息对应结构体的长度 Length of structure for alarm information
* @param [IN] lpUserData            用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBack_PF)(IN LPVOID lpUserID,
                                                   IN INT32 dwChannelID,
                                                   IN NETDEV_ALARM_INFO_S stAlarmInfo,
                                                   IN LPVOID lpBuf,
                                                   IN INT32 dwBufLen,
                                                   IN LPVOID lpUserData);

/**
* 注册回调函数,接收报警消息等（同时回调登录ID,用以区分不同设备） Register callback function and receive alarm information, etc. (Call back login ID at the same time to distinguish different devices)
* @param [IN] lpUserID              用户登录句柄 User login ID
* @param [IN] cbAlarmMessCallBack   回调函数 Callback function
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBack(IN LPVOID lpUserID,
                                                             IN NETDEV_AlarmMessCallBack_PF cbAlarmMessCallBack,
                                                             IN LPVOID lpUserData);

/**
* 接收告警消息的回调函数  Callback function to receive alarm information
* @param [IN] lpUserID                   用户登录句柄 User login ID
* @param [IN] LPNETDEV_ALARM_INFO_V2_S   告警信息 Alarm information
* @param [IN] lpUserData                 用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBackV2_PF)(IN LPVOID lpUserID,
                                                     IN NETDEV_ALARM_INFO_EX_S stAlarmInfo,
                                                     IN LPVOID lpUserData);

/**
* 注册回调函数,接收报警消息等（同时回调登录ID,用以区分不同设备）
* @param [IN] lpUserID              用户登录句柄
* @param [IN] cbAlarmMessCallBack   回调函数
* @param [IN] pstSubscribeInfo      告警订阅信息
* @param [IN] lpUserData            用户数据
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBackV2(IN LPVOID lpUserID, 
                                                               IN NETDEV_AlarmMessCallBackV2_PF cbAlarmMessCallBack,
                                                               IN LPNETDEV_ALARM_SUB_INFO_S pstSubscribeInfo, 
                                                               IN LPVOID lpUserData);

/**
* 接收告警消息的回调函数 Callback function to receive alarm information
* @param [IN] lpUserID              用户登录ID
* @param [IN] pstReportInfo         上报信息 Alarm information
* @param [IN] lpBuf                 缓冲区指针 Pointer to buffer
* @param [IN] dwBufLen              告警信息对应结构体的长度 Length of structure for alarm information
* @param [IN] dwBufLen              用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBack_PF_V30)(IN LPVOID lpUserID,
                                                       IN LPNETDEV_REPORT_INFO_S pstReportInfo,
                                                       IN LPVOID    lpBuf,
                                                       IN INT32     dwBufLen,
                                                       IN LPVOID    lpUserData);


/**
* 注册回调函数，接收报警消息等
* Register callback function and receive alarm information, etc.
* @param [IN] lpUserID              用户登录ID User login ID
* @param [IN] cbAlarmMessCallBack   回调函数 Callback function
* @param [IN] lpUserData            用户数据 User data
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBack_V30(IN LPVOID lpUserID,
                                                                 IN NETDEV_AlarmMessCallBack_PF_V30 cbAlarmMessCallBack,
                                                                 IN LPVOID lpUserData);

/**
 * @struct tagstNETDEVExceptionOutputInfo
 * @brief 异常输出信息
 * @attention
 */
typedef struct tagstNETDEVExceptionOutputInfo
{
    INT32    dwEventCode;                                      /* 事件码（ND上报异常使用） */
    INT64    tPlayBackTime;                                   /* 回放绝对时间(ND上报异常使用 N+M特性使用) */
    BYTE     byRes[128];                                       /* 保留字段 */
}NETDEV_EXCEPTION_OUTPUT_INFO_S, *LPNETDEV_EXCEPTION_OUTPUT_INFO_S;

/**
* 接收异常.重连等消息的回调函数  Callback function to receive exception and reconnection messages
* @param [IN] lpUserID     用户登录句柄 User login ID
* @param [IN] dwType       异常或重连等消息的类型:NETDEV_EXCEPTION_TYPE_E Type of exception or reconnection message: NETDEV_EXCEPTION_TYPE_E
* @param [IN] lpExpHandle  出现异常的相应类型的句柄 Exception type handle
* @param [IN] lpUserData   用户数据 User data
* @param [OUT] pstExceptionOutputInfo   异常输出信息 Exception output information
* @note
*/
typedef void(STDCALL *NETDEV_ExceptionCallBack_PF)(IN LPVOID lpUserID,
                                                   IN INT32 dwType,
                                                   IN LPVOID lpExpHandle,
                                                   IN LPVOID lpUserData,
                                                   OUT LPNETDEV_EXCEPTION_OUTPUT_INFO_S pstExceptionOutputInfo
                                                   );

/**
* 注册sdk接收异常.重连等消息的回调函数  Callback function to register SDK, receive exception and reconnection messages, etc.
* @param [IN] cbExceptionCallBack       接收异常消息的回调函数,回调当前异常的相关信息 Callback function to receive exception messages, used to call back information about current exceptions
* @param [IN] lpUserData                用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetExceptionCallBack(IN NETDEV_ExceptionCallBack_PF cbExceptionCallBack,
                                                                 IN LPVOID lpUserData);

/**
* 订阅推送消息
* @param [IN] lpUserID          用户登录ID
* @param [IN] dwAlarmType   订阅告警的类型 参见NETDEV_SUBSCRIBE_ALARM_TYPE_E，多个类型使用或运算
* @return TRUE表示成功，其他表示失败
* @note   订阅前需要先调用NETDEV_SetAlarmCallBack接口注册回调函数
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Subscribe(IN LPVOID lpUserID,
                                                      IN INT32 dwAlarmType);

/**
* 取消订阅推送消息
* @param [IN] lpUserID          用户登录ID
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Unsubscribe(IN LPVOID lpUserID);


/**
* 获取设备信息        GetDeviceInfos
* @param [IN] lpUserID          用户登录句柄 User login handle
* @param [OUT] pstDevInfo       设备信息结构体指针 Pointer to device information structure
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDeviceInfo(IN LPVOID lpUserID ,
                                                          OUT LPNETDEV_DEVICE_INFO_S pstDevInfo);

/**
* 获取设备信息
* @param [IN] lpUserID                 用户登录ID
* @param [OUT] pstDeviceInfo         设备信息
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDeviceBaseInfo(IN LPVOID lpUserID, 
                                                              OUT LPNETDEV_DEVICE_BASE_INFO_S pstDeviceInfo);

/**
* 查询设备详细信息
* @param [IN] lpUserID              用户登录ID
* @param [IN] dwDevID               设备ID
* @param [OUT]  pstDevDetailInfo    设备详细信息
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDeviceInfo_V30(IN LPVOID lpUserID,
                                                              IN INT32 dwDevID,
                                                              OUT LPNETDEV_DEV_INFO_V30_S pstDevDetailInfo);

/***********************************显控独立客户端Start**************************************************/

/**
* 设备发现
* @param [IN] lpUserID                  用户登录句柄
* @param [IN]   stDiscoverCondInfo                    设备发现条件信息 Discover Device Condition Info
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DiscoverDevice(IN LPVOID lpUserID,
                                                           IN LPNETDEV_DISCOVER_COND_INFO_S pstDiscoverCondInfo);

/**
* 获取设备发现信息列表
* @param [IN] lpUserID                  用户登录句柄
* @param [IN] pstFindCond               获取设备查找条件
* @return 若返回值为NULL则表示失败。其他值为查询任务号，作为NETDEV_FindNextDiscoverDeviceInfo、NETDEV_FindCloseDiscoverDeviceInfoList入参。
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindDiscoverDeviceInfoList(IN LPVOID lpUserID,
                                                                         IN LPNETDEV_DEVICE_FIND_COND_S pstFindCond);

/**
* 获取一条设备发现信息
* @param [IN]  lpFindHandle                    查找句柄   Search handle
* @param [OUT] pstDiscoverDeviceInfo           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败
* @note 返回失败说明查询结束
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextDiscoverDeviceInfo(IN LPVOID lpFindHandle,
                                                                       OUT LPNETDEV_DISCOVER_DEV_INFO_S pstDiscoverDeviceInfo);

/*
* 关闭查找设备发现信息，释放资源
* @param [IN] lpFindHandle  查找句柄 File search handle
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseDiscoverDeviceInfoList(IN LPVOID lpFindHandle);

/**
* 获取视频通道信息列表
* @param [IN] lpUserID          用户登录ID
* @param [IN] pstFindCond           查询条件
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextVideoChn、NETDEV_FindCloseVideoChnList等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindVideoChnList(IN LPVOID lpUserID,
                                                               IN LPNETDEV_VIDEO_CHN_FIND_COND_S pstFindCond);

/**
* 逐个获取查找到的 设备通道 信息
* @param [IN]  lpFindHandle         查找句柄 
* @param [OUT] pstVideoChannelInfo  视频通道信息
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextVideoChn(IN LPVOID lpFindHandle, 
                                                             OUT LPNETDEV_VIDEO_CHN_INFO_S pstVideoChannelInfo);

/**
* 关闭查找 设备通道信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseVideoChnList(IN LPVOID lpFindHandle);


/**
* 获取单个通道详细信息
* @param [IN] lpUserID              用户登录ID
* @param [INOUT] pstDevChnDetailInfo        设备通道信息
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetChnDetailInfo(IN LPVOID lpUserID, 
                                                             INOUT LPNETDEV_VIDEO_CHN_INFO_S pstDevChnDetailInfo);

/**
* 修改通道信息
* @param [IN] lpUserID              用户登录ID
* @param [INOUT] pstChnInfo         通道信息
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyChnInfo(IN LPVOID lpUserID, 
                                                          IN LPNETDEV_CHN_INFO_S pstChnInfo);

/**
* 获取指定组织信息
* @param [IN] lpUserID              用户登录ID
* @param [IN] pstOrgInfo            组织信息指针
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetOrgInfo(IN LPVOID lpUserID,
                                                          INOUT LPNETDEV_ORG_INFO_S pstOrgInfo);


/**
* 批量添加设备
* @param [IN] lpUserID             用户登录ID
* @param [IN] pstAddDevInfo        待添加设备信息指针
* @param [OUT] pstAddResultInfo    添加设备响应信息指针
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_BatchAddDevice(IN LPVOID lpUserID,
                                                           IN LPNETDEV_ADD_DEV_INFO_S pstAddDevInfo, 
                                                           OUT LPNETDEV_ADD_DEV_RESULT_INFO_S pstAddResultInfo);

/**
* 批量删除设备
* @param [IN] lpUserID             用户登录ID
* @param [IN] pstDelDevInfo        待删除设备信息指针
* @param [OUT] pstDelResultInfo    删除设备响应信息指针
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_BatchDelDevice(IN LPVOID lpUserID,
                                                           IN LPNETDEV_DEL_DEV_INFO_S pstDelDevInfo, 
                                                           OUT LPNETDEV_DEL_DEV_RESULT_INFO_S pstDelResultInfo);

/**
* 修改接入设备信息
* @param [IN] lpUserID             用户登录ID
* @param [OUT] pstDeviceInfo    接入设备信息指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyDeviceInfo(IN LPVOID lpUserID,
                                                                IN LPNETDEV_MODIFY_DEV_INFO_S pstDeviceInfo);


/**
* 获取单个接入设备信息
* @param [IN] lpUserID             用户登录ID
* @param [INOUT] pstDeviceInfo    接入设备信息指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetDeviceInfo(IN LPVOID lpUserID,
                                                             INOUT LPNETDEV_DEV_BASIC_INFO_S pstDeviceInfo);

/**
* 删除单个接入设备
* @param [IN] lpUserID             用户登录ID
* @param [IN] dwDevID    设备ID
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteDeviceInfo(IN LPVOID lpUserID,
                                                                IN INT32 dwDevID);

/***********************************显控独立客户端End*******************************************************/

/**
* 查询视频通道信息列表  Query channel info list
* @param [IN]    lpUserID           用户登录句柄 User login ID
* @param [INOUT] pdwChlCount        通道数 Number of channels
* @param [OUT]   pstVideoChlList    通道能力集列表 List of channel info list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlDetailList(IN LPVOID lpUserID, 
                                                                    INOUT INT32 *pdwChlCount, 
                                                                    OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlList);

/**
* 查询视频通道信息列表  Query channel info list
* @param [IN]    lpUserID           用户登录句柄 User login ID
* @param [INOUT] pdwChlCount        通道数 Number of channels
* @param [OUT]   pstVideoChlList    通道能力集列表 List of channel info list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlDetailListEx(IN LPVOID lpUserID,
                                                                      INOUT INT32 *pdwChlCount,
                                                                      OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_EX_S pstVideoChlList);

/**
* 查询视频通道信息  Query video channel info
* @param [IN]   lpUserID           用户登录句柄 User login ID
* @param [IN]   dwChannelID        通道号 Channel ID
* @param [OUT]  pstVideoChlInfo    视频通道信息 video channel info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlInfo(IN LPVOID lpUserID,
                                                              IN INT32 dwChannelID,
                                                              OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlInfo);

/**
* 通过 设备类型 查询 设备列表
* @param [IN] lpUserID              用户登录ID
* @param [IN] dwDevType             设备类型 参见#NETDEV_DEVICE_MAIN_TYPE_E
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextOrgInfo、NETDEV_FindCloseOrgInfo等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindDevList(IN LPVOID lpUserID, 
                                                          IN INT32 dwDevType);

/**
* 逐个获取查找到的 设备信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstDevBasicInfo              保存 设备详细信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextDevInfo(IN LPVOID lpFindHandle, 
                                                            OUT LPNETDEV_DEV_BASIC_INFO_S pstDevBasicInfo);

/**
* 关闭查找 设备信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseDevInfo(IN LPVOID lpFindHandle);


/**
* 获取通道设备基本信息列表
* @param [IN]   lpUserID                用户登录ID User login ID
* @return 业务号,返回0表示失败,其他值作为NETDEV_FindNextChlDeviceInfo等函数的参数.
* @note 此函数返回值为通道设备基本信息列表业务号,若返回值为非0,则查询通道设备基本信息列表成功：
*         一.将上述业务号作为NETDEV_FindNextDeviceChlInfo函数的入参lpFindHandle,多次调用NETDEV_FindNextDeviceChlInfo函数,以逐个获取详细通道设备基本信息.
*         二.查询结束后,必须以上述业务号作为NETDEV_FindCloseDeviceChlList函数的入参lpFindHandle,调用NETDEV_FindCloseDeviceChlList函数,以释放资源,关闭查找.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindDevChlBasicInfoList(IN LPVOID lpUserID);

/**
* 逐个获取通道设备基本信息
* @param [IN]   lpFindHandle                查询Handle
* @param [OUT]  pstDeviceInfo               设备信息结构体指针
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextDevChlBasicInfo(IN LPVOID lpFindHandle,
                                                                    OUT LPNETDEV_DEVICE_CHL_INFO_S pstDeviceInfo);

/**
* 关闭获取通道设备基本信息
* @param [IN]   lpFindHandle                查询Handle
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseDevChlBasicInfo(IN LPVOID lpFindHandle);

/**
* 通过设备ID或通道类型 查询通道信息列表
* @param [IN] lpUserID          用户登录ID
* @param [IN] dwDevID           设备ID
* @param [IN] dwChnType         通道类型，参见# NETDEV_CHN_TYPE_E
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextDevChn、NETDEV_FindCloseDevChn等函数的参数。
* @note     1、只根据通道类型查询时，将设备ID设置为0.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindDevChnList(IN LPVOID lpUserID,
                                                             IN INT32 dwDevID,
                                                             IN INT32 dwChnType);

/**
* 逐个获取查找到的 设备通道 信息
* @param [IN]  lpFindHandle         查找句柄 
* @param [OUT] lpOutBuffer          接收数据的缓冲指针
* @param [IN] dwOutBufferSize       接收数据的缓冲长度(以字节为单位)，不能为0
* @param [OUT] pdwBytesReturned     实际收到的数据长度指针，不能为NUL
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextDevChn(IN LPVOID lpFindHandle, 
                                                           OUT LPVOID lpOutBuffer, 
                                                           IN INT32  dwOutBufferSize,
                                                           OUT INT32  *pdwBytesReturned);

/**
* 关闭查找 设备通道信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseDevChn(IN LPVOID lpFindHandle);

/**
* 获取通道设备基本信息
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   dwChannelID             通道ID 
* @param [OUT]  pstDeviceChlInfo        设备基本信息请参见结构体#NETDEV_DEVICE_CHL_INFO_S
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevChlBasicInfo(IN LPVOID lpUserID, 
                                                               IN INT32 dwChannelID,
                                                               OUT LPNETDEV_DEVICE_CHL_INFO_S pstDeviceChlInfo);

/**
* 获取通道类型
* @param [IN] lpUserID              用户登录ID
* @param [IN] dwChnID               通道ID
* @param [OUT] pdwChnType           设备通道类型 参见# NETDEV_CHN_TYPE_E
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetChnType(IN LPVOID lpUserID,
                                                       IN INT32 dwChnID,
                                                       OUT INT32 *pdwChnType);

/**
* 主动获取设备告警信息  Get alarm information from the device
* @param [IN]  lpUserID        用户登录句柄 User login ID
* @param [IN]  dwPullWaitTime  告警等待时间,单位s Alarm wait time (s)
* @param [INOUT] pdwListCnt     告警最大数量,入参数时表示告警信息列表大小,出参时表示实际告警数量Maximum number of alarms. When working as an input parameter, it indicates the length of alarm information list; when working as an output parameter, it indicates the actual number of alarms.
* @param [OUT]   pstPullAlarmList   告警信息列表,此内存需预先分配 List of alarm information. The memory should be allocated in advance.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* note: 函数调用会阻塞login,logout, 不建议长时间等待 Calling the function will block login and logout. It is not recommended to wait for a long time.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PullAlarm(IN LPVOID lpUserID, 
                                                      IN INT32 dwPullWaitTime, 
                                                      INOUT INT32 *pdwListCnt, 
                                                      OUT LPNETDEV_PULLALARM_INFO_S pstPullAlarmList);

/**
* 非预览下抓拍  Snapshot without preview
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  dwStreamType;        码流类型,参见枚举#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E 
* @param [IN]  pszFileName          保存图像的文件路径（包括文件名） File path to save images (including file name)
* @param [IN]  dwCaptureMode        保存图像格式,参见#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
        仅支持JPG格式.
        Only JPG format is supported.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CaptureNoPreview(IN LPVOID lpUserID,
                                                             IN INT32 dwChannelID,
                                                             IN INT32 dwStreamType,
                                                             IN CHAR *pszFileName,
                                                             IN INT32 dwCaptureMode);

/**
* 动态产生一个关键帧 Dynamically create an I frame 
* @param [IN] lpUserID       用户登录句柄  User login ID
* @param [IN] dwChannelID    通道号  Channel ID
* @param [IN] dwStreamType   参考枚举NETDEV_LIVE_STREAM_INDEX_E  See enumeration NETDEV_LIVE_STREAM_INDEX_E
* @return NETDEV_E_SUCCEED   表示成功,其他表示失败  NETDEV_E_SUCCEED means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MakeKeyFrame(IN LPVOID lpUserID,
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType);

/**
* 查询指定月份的录像分布信息 Query video distribution information by month 
* @param [IN]   lpUserID            用户登录句柄 User login ID
* @param [IN]   dwChannelID         通道号  Channel ID
* @param [IN]   pstMonthInfo        月份信息  Month information
* @param [OUT]   pstMonthStatus     月录像分布状态  Video status in the month
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QuickSearch(IN LPVOID lpUserID, 
                                                        IN INT32 dwChannelID, 
                                                        IN LPNETDEV_MONTH_INFO_S pstMonthInfo,
                                                        OUT LPNETDEV_MONTH_STATUS_S pstMonthStatus);

/**
* 查询多个通道指定月份的录像分布信息   Query video distribution information by month with multichannel
* @param [IN]   lpUserID            用户登录句柄 User login ID
* @param [IN]   pstChannels         多个通道信息  Multichannel information
* @param [IN]   pstMonthInfo        月份信息  Month information
* @param [OUT]  pstMonthStatus     月录像分布状态  Video status in the month
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QuickSearchMultiChl(IN LPVOID lpUserID, 
                                                                IN LPNETDEV_CHANNELS_S pstChannels, 
                                                                IN LPNETDEV_MONTH_INFO_S pstMonthInfo,
                                                                OUT LPNETDEV_MONTH_STATUS_S pstMonthStatus);

/**
* 获取实况码流URL Obtain Live view stream url
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwStreamType         码流类型 参见#NETDEV_LIVE_STREAM_INDEX_E   Stream type see enumeration#NETDEV_LIVE_STREAM_INDEX_E
* @param [OUT] pszStreamUrl         码流URL Stream URL,内存长度要求大于等于NETDEV_LEN_260 The length must exceed NETDEV_LEN_260
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetStreamUrl(IN LPVOID lpUserID, 
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType,
                                                         OUT CHAR *pszStreamUrl);

/**
* 获取回放URL Obtain replay url
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  dwStreamType         码流类型 参见#NETDEV_LIVE_STREAM_INDEX_E   Stream type see enumeration#NETDEV_LIVE_STREAM_INDEX_E
* @param [OUT] pszReplayUrl  码流URL,内存长度要求大于等于NETDEV_LEN_260 The length must exceed NETDEV_LEN_260
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetReplayUrl(IN LPVOID lpUserID, 
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType, 
                                                         OUT CHAR *pszReplayUrl);

/**
* 根据文件类型.时间查找设备录像文件  Query recording files according to file type and time
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @param [IN]  pstFindCond    录像查询条件 Search condition
* @return 录像查询业务号,返回0表示失败,其他值作为NETDEV_FindClose等函数的参数.
Recording search service number. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_FindClose.
* @note 此函数返回值为录像查询业务号,若返回值为非0,则查询录像文件成功：
*         一.将上述业务号作为NETDEV_FindNextFile函数的入参lpFindHandle,多次调用NETDEV_FindNextFile函数,以逐个获取详细录像文件信息.
*         二.查询结束后,必须以上述业务号作为NETDEV_FindClose函数的入参lpFindHandle,调用NETDEV_FindClose函数,以释放资源,关闭查找.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindFile(IN LPVOID lpUserID,
                                                       IN LPNETDEV_FILECOND_S pstFindCond);

/**
* 逐个获取查找到的文件信息  Obtain the information of found files one by one.
* @param [IN]  lpFindHandle     文件查找句柄 File search handle
* @param [OUT] pstFindData       保存文件信息的指针 Pointer to save file information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextFile(IN LPVOID lpFindHandle,
                                                         OUT LPNETDEV_FINDDATA_S pstFindData);

/**
* 关闭文件查找,释放资源  Close file search and release resources
* @param [IN] lpFindHandle  文件查找句柄 File search handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindClose(IN LPVOID lpFindHandle);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_MEDIA
/************************************************************************/
/*                  包含媒体模块                                   */
/************************************************************************/

/**
* 拼帧前媒体流数据回调函数的指针类型  Type of pointer to media stream data callback function before being framed 
* @param [IN] lpPlayHandle      当前的实况播放句柄 Current live playing handle
* @param [IN] pucBuffer         存放拼帧前媒体流数据缓冲区指针 Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize         缓冲区大小 Buffer size
* @param [IN] dwMediaDataType   媒体数据类型,参见媒体类型枚举定义#NETDEV_MEDIA_DATA_FORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       用户设置参数,即用户在调用#NDPlayer_SetSourceMediaDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return 无. None.
* @note  用户应及时处理输出的媒体流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpPlayHandle,
                                                       IN const BYTE    *pucBuffer,
                                                       IN INT32         dwBufSize,
                                                       IN INT32         dwMediaDataType,
                                                       IN LPVOID        lpUserParam);

/**
* 注册码流回调函数:原始码流  Callback function to register streams (original stream)
* @param [IN]  lpPlayHandle               实时预览句柄 Live preview handle
* @param [IN]  cbSourceDataCallBack       码流数据回调函数 Callback function for stream data
* @param [IN]  bContinue                  是否继续进行后面的拼帧.解码和显示操作 Whether to continue to following framing, decoding and displaying operations.
* @param [IN]  lpUser                     用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE  BOOL STDCALL NETDEV_SetPlayDataCallBack(IN LPVOID lpPlayHandle,
                                                                 IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUser);

/**
* 拼帧后视频流数据回调函数的指针类型  Type of pointer to callback function for framed stream data 
* @param [IN] lpPlayHandle          当前的实况播放句柄 Current live playing handle
* @param [IN] pstParseVideoData     存放拼帧后视频流数据信息缓冲区指针 Pointer to buffer that stores framed video stream data
* @param [IN] lUserParam            用户设置参数,即用户在调用#NDPlayer_SetParseVideoDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetParseVideoDataCB function
* @return 无. None.
* @note
* -     用户应及时处理输出的数据,确保函数尽快返回,否则会影响播放器内的媒体流处理. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                            IN const NETDEV_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                            IN LPVOID lpUserParam);

/**
* 注册实况码流回调函数:拼帧后码流数据  Callback function to register live stream (framed stream data)
* @param [IN]  lpPlayHandle              预览\回放句柄 Preview\playback handle
* @param [IN]  cbParsePlayDataCallBack   数据回调函数 Data callback function
* @param [IN]  bContinue                 是否继续进行后面的解码和显示操作 Whether to continue to following decoding and displaying operations.
* @param [IN]  lpUserData                用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseCB(IN LPVOID lpPlayHandle, 
                                                           IN NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF cbParsePlayDataCallBack,
                                                           IN INT32 bContinue, 
                                                           IN LPVOID lpUserData);

/**
* 注册实时码流回调函数：解码后视频媒体流数据  Callback function to register live stream (decoded media stream data)
* @param [IN]  lpPlayHandle                 预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDecodeVideoCALLBACK    数据回调函数 Data callback function
* @param [IN]  bContinue                    是否继续进行后面的显示操作 Whether to continue to following displaying operations.
* @param [IN]  lpUserData                   用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeVideoCB(IN LPVOID  lpPlayHandle,
                                                                 IN NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF cbPlayDecodeVideoCALLBACK,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUserData);

/**
* 拼帧后音频流数据回调函数的指针类型  Type of pointer to callback function for framed stream data 
* @param [IN] lpPlayHandle   当前的实况播放句柄 Current live playing handle
* @param [IN] pstWaveData    存放解码后音频流数据信息缓冲区指针 Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NDPlayer_SetDecodeAudioDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return 无. None.
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_PARSE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                            IN const NETDEV_PARSE_AUDIO_DATA_S *pstParseAudioData,
                                                            IN LPVOID lpUserParam);

/**
* 注册码流回调函数：拼帧后音频媒体流数据 Callback function to register audio stream (framed stream data)
* @param [IN]  lpPlayHandle                预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayParseAudioCallBack    数据回调函数 Data callback function
* @param [IN]  bContinue                   是否继续进行播放操作 Whether to continue to playing operations.
* @param [IN]  lpUserData                  用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseAudioCB(IN LPVOID lpPlayHandle, 
                                                                IN NETDEV_PARSE_AUDIO_DATA_CALLBACK_PF cbPlayParseAudioCallBack,
                                                                IN INT32 bContinue, 
                                                                IN LPVOID lpUserData);

/**
* 解码后音频流数据回调函数的指针类型  Type of pointer to callback function for decoded audio stream data 
* @param [IN] lpPlayHandle   当前的实况播放句柄 Current live playing handle
* @param [IN] pstWaveData    存放解码后音频流数据信息缓冲区指针 Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NDPlayer_SetDecodeAudioDataCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return 无. None.
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                             IN const NETDEV_WAVE_DATA_S *pstWaveData,
                                                             IN LPVOID lpUserParam);

/**
* 注册码流回调函数：解码后音频媒体流数据 Callback function to register audio stream (decoded media stream data)
* @param [IN]  lpPlayHandle                 预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDecodeAudioCallBack    数据回调函数 Data callback function
* @param [IN]  bContinue                    是否继续进行播放操作 Whether to continue to playing operations.
* @param [IN]  lpUserData                   用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeAudioCB(IN LPVOID lpPlayHandle, 
                                                                 IN NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF cbPlayDecodeAudioCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUserData);

/**
* 显示数据回调函数的指针类型 Type of pointer to display data callback function
* @param [IN] lpHandle       当前的实况播放句柄 Current live playing handle
* @param [IN] hdc            显示表面的hdc,用户可以用这个hdc 作图 Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    用户设置参数,即用户在调用#NETDEV_SetPlayDisplayCB函数时指定的用户参数 User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return 无.
* @note
* -     用户应及时处理输出的音频流数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
                                                   IN LPVOID hdc,
                                                   IN LPVOID lpUserParam);

/**
* 设置显示后数据回调  Modify displayed data callback
* @param [IN]  lpPlayHandle             预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDisplayCallBack    数据回调函数 Data callback function
* @param [IN]  lpUserData               用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDisplayCB(IN LPVOID lpPlayHandle,
                                                             IN NETDEV_DISPLAY_CALLBACK_PF cbPlayDisplayCallBack,
                                                             IN LPVOID lpUserData);


/**
* 启动实时预览  Start live preview
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pstPreviewInfo       预览参数,参考枚举：NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E. Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbRealDataCallBack   码流数据回调函数指针 Pointer to callback function of stream data
* @param [IN]  lpUserData           用户数据 User data
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
                                                       IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                       IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                       IN LPVOID lpUserData);


/**
* 按照url启动实时预览
* @param [IN]  lpUserID             用户登录ID
* @param [IN]  pszUrl...............码流URL
* @param [IN]  pstPreviewInfo       预览参数,参考枚举：NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbRealDataCallBack   码流数据回调函数指针
* @param [IN]  lpUserData           用户数据
* @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FastRealPlayByUrl(IN LPVOID lpUserID, 
                                                                IN CHAR *pszUrl,
                                                                IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                                IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                IN LPVOID lpUserData);

/**
* 按照Url启动实时预览
* Start live preview
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszUrl               码流URL
* @param [IN]  pszUserName          用户名
* @param [IN]  pszPassword          密  码
* @param [IN]  pstPreviewInfo       预览参数，参考枚举：NETDEV_PROTOCAL_E，NETDEV_LIVE_STREAM_INDEX_E。 Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbPlayDataCallBack   码流数据回调函数指针 Pointer to callback function of stream data
* @param [IN]  lpUserData           用户数据 User data
* @return 返回 0 表示失败，其他值表示返回的预览句柄。作为NETDEV_StopRealPlay等函数的句柄参数  Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FastRealPlayByUrl_V30(IN LPVOID lpUserID,
                                                                    IN CHAR* pszUrl,
                                                                    IN CHAR*pszUserName,
                                                                    IN CHAR*pszPassword,
                                                                    IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                                    IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                    IN LPVOID lpUserData
                                                                    );

/**
* 通过URL拉取云端设备视频流
* @param [IN]  pszUrl...............码流URL
* @param [IN]  cbRealDataCallBack   码流数据回调函数指针
* @param [IN]  lpUserData           用户数据
* @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetCloudLiveByUrl(IN CHAR *pszUrl,
                                                                IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                IN LPVOID lpUserData);

/**
* 停止实时预览  Stop live preview
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 对应关闭NETDEV_RealPlay开启的实况 Stop the live view started by NETDEV_RealPlay
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpPlayHandle);

/**
* 本地录像  Local recording
* @param [IN]  lpPlayHandle         预览句柄 Preview handle
* @param [IN]  pszSaveFileName      保存的文件名 Name of saved file
* @param [IN]  dwFormat             Format of saved file, see #NETDEV_MEDIA_FILE_FORMAT_E 
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SaveRealData(IN LPVOID lpPlayHandle, 
                                                         IN CHAR *pszSaveFileName,
                                                         IN INT32   dwFormat);

/**
* 停止本地录像 Stop local recording
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopSaveRealData(IN LPVOID lpPlayHandle);


/**
* 获取窗口码率  Get window bit rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwBitRate       获取的码率指针 Pointer to obtained bit rate
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetBitRate(IN LPVOID lpPlayHandle,
                                                       OUT INT32 *pdwBitRate);

/*
* 获取窗口帧率  Get window frame rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwFrameRate     获取的帧率指针 Pointer to obtained frame rate
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetFrameRate(IN LPVOID lpPlayHandle,
                                                         OUT INT32 *pdwFrameRate);

/**
* 获取窗口编码格式  Get window encoding format
* @param [IN]  lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [OUT] pdwVideoEncFmt       获取的视频编码格式指针,参见NETDEV_VIDEO_CODE_TYPE_E  Pointer to obtained encoding format, see NETDEV_VIDEO_CODE_TYPE_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEncodeFmt(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pdwVideoEncFmt);


/**
* 获取视频分辨率  Get video resolution
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pdwWidth         获取的分辨率-宽度指针 Pointer to obtained resolution – width
* @param [OUT] pdwHeight        获取的分辨率-高度指针 Pointer to obtained resolution – height
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetResolution(IN LPVOID lpPlayHandle,
                                                          OUT INT32 *pdwWidth,
                                                          OUT INT32 *pdwHeight);

/**
* 获取窗口丢包率  Get window packet loss rate
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [OUT] pulRecvPktNum    接收的数据包数量指针 Pointer to number of received packets
* @param [OUT] pulLostPktNum    丢失的数据包数量指针 Pointer to number of lost packets
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetLostPacketRate(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pulRecvPktNum,
                                                              OUT INT32 *pulLostPktNum);

/**
* 重置窗口丢包率  Reset window packet loss rate
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetLostPacketRate(IN LPVOID lpPlayHandle);

/**
* 实况抓拍  Live view snapshot
* @param [IN]  lpPlayHandle     预览\回放句柄 Preview\playback handle
* @param [IN]  pszFileName      保存图像的文件路径（包括文件名） File path to save images (including file name)
* @param [IN]  dwCaptureMode    保存图像格式,参见#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 文件名中可以不携带抓拍格式的后缀名 File format suffix is not required in the file name
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CapturePicture(IN LPVOID lpPlayHandle, 
                                                           IN char *pszFileName, 
                                                           IN INT32 dwCaptureMode);

/**
* 设置视频图像显示比例  Modify image display ratio
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  enRenderScale  视频图像的显示比例 Image display ratio
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRenderScale(IN LPVOID lpPlayHandle,
                                                           IN NETDEV_RENDER_SCALE_E enRenderScale);

/**
* 影像参数获取,只获取当前画面参数  Get the current image info
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  pstImageInfo   图像信息列表 Image information list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           OUT LPNETDEV_VIDEO_EFFECT_S pstImageInfo);

/**
* 影像调节,只改变当前画面  Adjust the current image
* @param [IN]  lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN]  pstImageInfo   图像信息列表 Image information list
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           IN LPNETDEV_VIDEO_EFFECT_S pstImageInfo);

/**
* 设置数字放大  Set Digital zoom
* @param [IN] lpPlayHandle   预览\回放句柄 Preview\playback handle
* @param [IN] hWnd           窗口句柄  window handle 
* @param [IN] pstRect        矩形区域 Rectangle Area
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note pstRect为空时,显示全部画面,即退出数字放大 All images will be displayed with digital zoom disabled when pstRect is null
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDigitalZoom(IN LPVOID lpPlayHandle, 
                                                           IN LPVOID hWnd,
                                                           IN LPNETDEV_RECT_S pstRect);

/**
* 设置流畅性优先 Set pictuer fluency
* @param [IN] lpPlayHandle         预览\回放句柄 Preview\playback handle
* @param [IN] dwFluency           图像播放流畅性优先类型,参见枚举#NETDEV_PICTURE_FLUENCY_E
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPictureFluency(IN LPVOID lpPlayHandle,
                                                              IN INT32 dwFluency);


/**
* 开启语音对讲 Start two-way audio
* @param [IN]  lpUserID                 用户登录句柄  User ID
* @param [IN]  dwChannelID              通道号  Channel ID
* @param [IN]  cbRealDataCallBack       码流数据回调函数指针  Pointer to callback function of the stream data 
* @param [IN]  lpUserData               用户数据   User data
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值 Returned user ID. 0 means failure, and any other value is a user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_StartVoiceCom(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                            IN LPVOID lpUserData);

/**
* 关闭语音对讲 Stop two-way audio
* @param [IN]  lpPlayHandle   对讲句柄 Two-way audio handle
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopVoiceCom(IN LPVOID lpPlayHandle);

/**
* 开启麦克风 Turn on microphone
* @param [IN]  lpPlayHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenMic(IN LPVOID lpPlayHandle);

/**
* 关闭麦克风 Turn off microphone
* @param [IN]  lpPlayHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseMic(IN LPVOID lpPlayHandle);

/**
* 调节麦克风音量  Adjust sound volume of microphone
* @param [IN]  lpPlayHandle     预览句柄 Preview handle 
* @param [IN]  dwVolume             音量 Sound volume
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MicVolumeControl(IN LPVOID lpPlayHandle,
                                                             IN INT32 dwVolume);

/**
* 获取麦克风音量 Get mic volume
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @param [IN]  pdwVolume        音量 Volume
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMicVolume(IN LPVOID lpPlayHandle, 
                                                         OUT INT32* pdwVolume);

/**
* 获取静音状态 Get mute status
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @param [OUT]  pbMute           静音状态 Mute status
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMuteStatus(IN LPVOID lpPlayHandle, 
                                                          OUT BOOL* pbMute);

/**
* 设置静音状态 Set mute status
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @param [IN]  bMute            静音状态 Mute status
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetMuteStatus(IN LPVOID lpPlayHandle, 
                                                          IN BOOL bMute);


/**
* 开启声音  Enable sound
* @param [IN]  lpPlayHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenSound(IN LPVOID lpPlayHandle);

/**
* 调节扬声器音量 Control sound volume
* @param [IN]  lpPlayHandle   预览句柄 Preview handle
* @param [IN]  dwVolume       音量 Volume
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SoundVolumeControl(IN LPVOID lpPlayHandle, 
                                                               IN INT32 dwVolume);

/**
* 获取扬声器音量 Get sound volume
* @param [IN]  lpPlayHandle     预览句柄 Preview handle
* @param [IN]  pdwVolume        音量 Volume
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSoundVolume(IN LPVOID lpPlayHandle, 
                                                           OUT INT32* pdwVolume);

/**
* 关闭声音 Mute
* @param [IN]  lpPlayHandle   预览句柄 Preview handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseSound(IN LPVOID lpPlayHandle);

/**
* 开启输入语音数据服务
* @param [IN]  lpUserID                 用户ID
* @param [IN]  dwChannelID              通道号
* @param [IN]  cbRealDataCallBack       码流数据回调函数指针
* @param [IN]  lpUserData               用户数据
* @return 返回的语音对讲句柄,返回 0 表示失败
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_StartInputVoiceSrv(IN LPVOID lpUserID,
                                                                 IN INT32 dwChannelID);

/**
* 关闭输入语音数据服务
* @param [IN]  lpVoiceComHandle   对讲句柄
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopInputVoiceSrv(IN LPVOID lpVoiceComHandle);

/**
* 输入语音数据
* @param [IN]  lpVoiceComHandle         对讲句柄
* @param [IN] lpDataBuf                 语音数据地址
* @param [IN] dwDataLen                 语音数据长度
* @param [IN] pstVoiceParam             语音参数
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_InputVoiceData(IN LPVOID lpVoiceComHandle,
                                                           IN LPVOID lpDataBuf,
                                                           IN INT32 dwDataLen,
                                                           IN LPNETDEV_AUDIO_SAMPLE_PARAM_S pstVoiceParam);

/**
* 用于语音对讲解析后的语音数据回调函数的指针类型.
* @param [IN] lpVoiceComHandle      对讲句柄
* @param [IN] lpWaveData            存放解析后语音数据信息缓冲区指针
* @param [IN] lpUserParam           用户设置参数
* @param [IN] dwReserved            音频数据大小
* @return 无.
* @note
* -     用户应及时处理输出的数据,确保函数尽快返回,否则会影响播放器内的媒体流处理.
*/
typedef VOID (STDCALL *NETDEV_PARSE_VOICE_DATA_CALLBACK_PF)(IN LPVOID lpVoiceComHandle,
                                                            IN const LPNETDEV_WAVE_DATA_S lpWaveData,
                                                            IN LPVOID lpUserParam,
                                                            IN INT32 dwReserved);

/**
* 设置解析后语音数据回调函数
* @param [IN]  lpPlayHandle                 预览\回放句柄 Preview\playback handle
* @param [IN]  cbPlayDecodeVideoCALLBACK    数据回调函数 Data callback function
* @param [IN]  bContinue                    是否继续 Continue or not
* @param [IN]  lpUserData                   用户数据 User data
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 若关闭回调函数,将第二个参数置为NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetParseVoiceDataCB(IN LPVOID  lpPlayHandle,
                                                                IN NETDEV_PARSE_VOICE_DATA_CALLBACK_PF cbDecodeVideoCB,
                                                                IN INT32 bContinue,
                                                                IN LPVOID lpUserParam);

/**
* 按名称回放录像文件  Play back recording files by name
* @param [IN] lpUserID          用户登录句柄 User login ID
* @param [IN] pstPlayBackInfo   录像回放结构体指针,参考 LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByName(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo);

/**
* 按时间回放录像文件  Play back recording by time. 
* @param [IN] lpUserID          用户登录句柄 User login ID
* @param [IN] pstPlayBackCond   按时间录像回放结构体指针  参考 LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByTime(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKCOND_S pstPlayBackInfo);


/**
* 使用URL启动回放
* @param [IN]  lpUserID             用户登录句柄
* @param [IN]  pszUrl               码流URL
* @param [IN]  pstPlayBackCond      录像回放结构体指针,参考 LPNETDEV_PLAYBACKCOND_S
* @return 返回0表示失败,其他值作为NETDEV_StopPlayBack等函数的句柄参数
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByUrl(IN LPVOID lpUserID, 
                                                            IN CHAR *pszUrl, 
                                                            IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond
                                                            );

/**
* 按照url快速回放录像 Play back recording by url. 
* @param [IN] lpUserID          用户登录句柄 User login ID
* @param [IN]  pszUrl...........码流URL
* @param [IN] pstPlayBackParam   按url录像回放结构体指针  参考 LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @return 返回的用户登录ID,返回 0 表示失败,其他值表示返回的用户ID值.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FastPlayBackByUrl(IN LPVOID lpUserID,
                                                                IN CHAR *pszUrl,
                                                                IN LPNETDEV_PLAYBACKCOND_S pstPlayBackParam);

/**
* 停止回放业务  Stop playback service
* @param [IN] lpPlayHandle  回放句柄 Playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPlayBack(IN LPVOID lpPlayHandle);

/**
* 按文件名下载录像文件 Download recordings by file name
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pstPlayBackInfo      录像回放结构体指针,参考 LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @param [IN]  *pszSaveFileName     下载后保存到PC机的文件路径,需为绝对路径（包括文件名） Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat             录像文件保存格式 Recording file saving format
* @return 下载句柄, 返回0表示失败,其他值作为NETDEV_StopGetFile等函数的参数. Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByName(IN LPVOID  lpUserID,
                                                            IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo,
                                                            IN CHAR *pszSaveFileName,
                                                            IN INT32 dwFormat);

/**
* 按时间下载录像文件 Download recordings by time
* @param [IN]  lpUserID                用户登录句柄 User login ID
* @param [IN]  pstPlayBackCond   按时间录像回放结构体指针,参考 LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @param [IN]  *pszSaveFileName        下载后保存到PC机的文件路径,需为绝对路径（包括文件名） Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat                录像文件保存格式 Recording file saving format
* @return 下载句柄, 返回0表示失败,其他值作为NETDEV_StopGetFile等函数的参数. Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByTime(IN LPVOID lpUserID, 
                                                            IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond, 
                                                            IN CHAR *pszSaveFileName,
                                                            IN INT32 dwFormat);

/**
* 停止下载录像文件 Stop downloading recording files
* @param [IN]  lpPlayHandle  回放句柄 Playback handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopGetFile(IN LPVOID lpPlayHandle);


/**
* 控制录像回放的状态  Control recording playback status.
* @param [IN]  lpPlayHandle     回放或下载句柄 Playback or download handle
* @param [IN]  dwControlCode    控制录像回放状态命令 参考枚举：NETDEV_VOD_PLAY_CTRL_E Command for controlling recording playback status, see NETDEV_VOD_PLAY_CTRL_E
* @param [INOUT]  lpBuffer     指向输入/输出参数的指针, 播放速度参考枚举：NETDEV_VOD_PLAY_STATUS_E,播放时间参数类型为：INT64 Pointer to input/output parameters. For playing speed, see NETDEV_VOD_PLAY_STATUS_E. The type of playing time: INT64.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 开始.暂停.恢复播放时,lpBuffer置为NULL When playing, pause or resume videos, set IpBuffer as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PlayBackControl(IN LPVOID lpPlayHandle, 
                                                            IN INT32 dwControlCode, 
                                                            INOUT LPVOID lpBuffer);

/**
* 设置特定时间点单帧回放
* @param [IN]  lpPlayHandle    回放句柄
* @param [IN]  IN INT64 dwPlayTime 特定时间点
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetOneFramePlayWithTime(IN LPVOID lpPlayHandle, IN INT64 dwPlayTime);


/**
* 获取语音广播组通道的状态
* @param [IN] lpPlayHandle           语音广播句柄
* @param [OUT] pstGroupInfo          通道状态列表
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVoiceBroadcastChlStatus(IN LPVOID lpPlayHandle,
                                                                       OUT LPNETDEV_VOICE_BROADCAST_GROUP_INFO_S pstGroupInfo);

/**
* 新建语音广播组
* @parma [IN] lpUserID              用户登录ID
* @param [IN] pstChnList            通道列表
* @return 返回语音广播句柄，NULL表示失败
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_CreateVoiceBroadcastGroup(IN LPVOID lpUserID,
                                                                        IN LPNETDEV_OPERATE_LIST_S pstChnList);


/**
* 修改语音广播组
* @param [IN] lpPlayHandle          语音广播句柄
* @param [IN] pstModifyInfo         修改语音广播组信息
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyVoiceBroadcastGroup(IN LPVOID lpPlayHandle,
                                                                      IN LPNETDEV_MODIFY_VOICE_BROADCAST_INFO_S pstModifyInfo);

/**
* 开启语音广播 Start voice broadcast
* @param [IN]  lpUserID         用户登录句柄 User login ID
* @param [IN]  dwChannelID      通道号  Channel ID
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值 Returned user ID. 0 means failure, and any other value is a user ID.
* @note 不仅实现启动语音广播功能,并且启用一路语音对讲功能 Voice broadcast and two-way audio for one channel are available.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_StartVoiceBroadcast(IN LPVOID lpUserID, 
                                                                  IN INT32 dwChannelID);

/**
* 关闭语音广播 Stop voice broadcast
* @param [IN]  lpPlayHandle   语音广播 voice broadcast handle
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopVoiceBroadcast(IN LPVOID lpPlayHandle);

/**
* 开启/关闭某个广播通道声音
* @param [IN] lpPlayHandle          语音广播句柄
* @param [IN] pstCtrlInfo           控制信息
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyVoiceBroadcastStatus(IN LPVOID lpPlayHandle,
                                                                       IN LPNETDEV_VOICE_BROADCAST_CTRL_INFO_S pstCtrlInfo);


/**
* 打开本地文件
* @param [IN] pszFilename           播放文件名
* @return 返回0表示失败,其他值作为NETDEV_PlayMediaFile.NETDEV_StopPlayMediaFile等函数的句柄参数
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_OpenMediaFile(IN CHAR *pszFilename);

/**
* 播放本地文件
* @param [IN] lpPlayHandle       文件句柄,调用NETDEV_OpenMediaFile的返回值
* @param [IN] dwPlayWnd          播放窗口句柄
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartPlayMediaFile(IN LPVOID lpPlayHandle,
                                                               IN LPVOID lpPlayWnd);

/**
* 停止播放本地文件业务
* @param [IN] lpPlayHandle  回放句柄
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPlayMediaFile(IN LPVOID lpPlayHandle);

/**
* 获取媒体文件时间总长度
* @param [IN] lpPlayHandle  回放句柄
* @param [IN] pdwTotalTime  媒体文件时间总长度（s）
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMediaFileTime(IN LPVOID lpPlayHandle,
                                                             OUT INT32* pdwTotalTime);


/**
* 元数据处理
* @param [IN] lpPlayHandle              播放句柄
* @param [IN] bEnableIVA                是否添加元数据
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetIVAEnable(IN LPVOID lpPlayHandle,
                                                         IN BOOL bEnableIVA);

/**
* 设置元数据绘图显示类型参数
* @param [IN] dwShowParam              元数据显示类型参数
* @return TRUE表示成功,其他表示失败
* @note
* -    1.该接口函数仅支持Windows.
* -    2.请将规则进行组合,比如显示规则线框和触发规则目标框,下发的ulShowParam = NETDEV_IVA_SHOW_RULE|NETDEV_IVA_SHOW_RESULT_TOUTH_RULE；以此类推
* -    3.已最后一次设置的显示类型为准,之前设置的显示操作取消
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetIVAShowParam(IN INT32 dwShowParam);

/*                   媒体模块结束行                               */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_CLOUD
/************************************************************************/
/*                  包含云服务模块                                */
/************************************************************************/
/**
* 设置T2U最大负载
* @param [IN]   dwT2UPayload         T2U最大负载,MTU设置范围:101-1500 ，默认值是1500。
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetT2UPayLoad(IN INT32 dwT2UPayload);

/**
* 用户登录云端账户 User login to cloud account
* @param [IN]  pszCloudSrvUrl       云端服务器URL  Cloud server URL 
* @param [IN]  pszUserName          云端账户名 Cloud account name
* @param [IN]  pszPassWord          云端账户密码  Cloud account password 
* @return 返回的用户登陆ID,-1表示失败,其他值表示返回的用户登录句柄值  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloud(IN CHAR *pszCloudSrvUrl,
                                                         IN CHAR *pszUserName,
                                                         IN CHAR *pszPassWord);

/**
* 用户登录云端预置账户 User login to cloud account
* @param [IN]  pszCloudSrvUrl       云端服务器URL  Cloud server URL 
* @param [IN]  pszUserName          云端账户名 Cloud account name
* @param [IN]  pszPassWord          云端账户密码  Cloud account password 
* @param [IN]  bPresetAccountFlag   预置账号标记 
* @return 返回的用户登录句柄,返回 0 表示失败,其他值表示返回的用户登录句柄值. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloudEx(IN CHAR *pszCloudSrvUrl,
                                                           IN CHAR *pszUserName,
                                                           IN CHAR *pszPassWord,
                                                           IN BOOL bPresetAccountFlag);


/* 终端信息上报
* @param [IN]   lpUserID                     用户登录句柄 User login ID
* @param [IN]   pstMobileInfo                终端信息 Mobile Info
* @param [IN]   pstCloudLimitInfo            限制（阈值）信息 Limit Info
* @return TRUE表示成功,其他表示失败   TRUE means success, any other value indicates failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ReportMobileInfo(IN  LPVOID lpUserID, 
                                                             IN  LPNETDEV_CLOUD_MOBILE_INFO_S pstMobileInfo,
                                                             OUT LPNETDEV_CLOUD_LIMIT_INFO_S  pstCloudLimitInfo);

/**
* 无账号信息登录（设备绑定）
* @param [IN]   lpUserID                     用户登录句柄 User login ID
* @param [IN]   pstNoAccountInfo             无账户信息 No Account Info
* @return TRUE表示成功,其他表示失败   TRUE means success, any other value indicates failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_NoAccountBinding(IN LPVOID lpUserID, 
                                                             IN LPNETDEV_CLOUD_NOACCOUNT_INFO_S pstNoAccountInfo);

/**
* 无账号信息解除绑定
* @param [IN]   lpUserID                     用户登录句柄 User login ID
* @param [IN]   pstNoAccountInfo             无账户信息 No Account Info
* @return TRUE表示成功,其他表示失败   TRUE means success, any other value indicates failure.
* @note pstNoAccountInfo->szDeviceName is Not Required Using for Cancel Binding
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_NoAccountCancel(IN LPVOID lpUserID, 
                                                            IN LPNETDEV_CLOUD_NOACCOUNT_INFO_S pstNoAccountInfo);

/**
* 查询云端账户设备列表   Query device list under a cloud account
* @param [IN]  lpUserID            用户登录句柄 User login ID
* @return 查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevInfo.NETDEV_FindCloseDevList等函数的参数.
Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevInfo and NETDEV_FindCloseDevList.
* @note 此函数返回值为云端设备列表查询业务号,若返回值为非0,则查询云端设备列表成功：
*         一.将上述业务号作为NETDEV_FindNextCloudDevInfo函数的入参lpFindHandle,多次调用NETDEV_FindNextCloudDevInfo函数,以逐个获取已查询到的云端设备信息.
*         二.查询结束后,必须以上述业务号作为NETDEV_FindCloseCloudDevList函数的入参lpFindHandle,调用NETDEV_FindCloseCloudDevList函数,以释放资源,关闭查找.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevListEx(IN LPVOID lpUserID);

/**
* 逐个获取查找到的设备信息   Obtain info about detected devices one by one
* @param [IN]  lpFindHandle         查找句柄   Search handle
* @param [OUT] pstDevInfo           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevInfoEx(IN LPVOID lpFindHandle,
                                                                   OUT LPNETDEV_CLOUD_DEV_BASIC_INFO_S pstDevInfo
                                                                   );

/**
* 关闭查找,释放资源 Stop search and release resource 
* @param [IN] lpFindHandle  查找句柄 File search handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevListEx(IN LPVOID lpFindHandle);

/**
* 查询云端账户设备列表   Query device list under a cloud account
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pstPageFindCond      查询条件 Search condition
* @return 查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevInfoV3.NETDEV_FindCloseCloudDevListEx等函数的参数.
Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevInfoV3 and NETDEV_FindCloseCloudDevListEx.
* @note 此函数返回值为云端设备列表查询业务号,若返回值为非0,则查询云端设备列表成功：
*         一.将上述业务号作为NETDEV_FindNextCloudDevInfoEx函数的入参lpFindHandle,多次调用NETDEV_FindNextCloudDevInfoV3函数,以逐个获取已查询到的云端设备信息.
*         二.查询结束后,必须以上述业务号作为NETDEV_FindNextCloudDevInfoV3函数的入参lpFindHandle,调用NETDEV_FindCloseCloudDevListEx函数,以释放资源,关闭查找.
*         三.因
*/ 
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevList_V30(IN LPVOID lpUserID,
                                                                   IN LPNETDEV_PAGE_FIND_COND_S pstPageFindCond);

/**
* 逐个获取查找到的设备信息   Obtain info about detected devices one by one
* @param [IN]  lpFindHandle         查找句柄   Search handle
* @param [OUT] pstDevInfo           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevInfo_V30(IN LPVOID lpFindHandle,
                                                                     OUT LPNETDEV_CLOUD_DEV_BASIC_INFO_S pstDevInfo);

/**
* 逐个获取查找到的设备信息   Obtain info about detected devices one by one
* @param [IN]  lpFindHandle         查找句柄   Search handle
* @param [OUT] pstDevInfo           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevInfo_V30(IN LPVOID lpFindHandle);

/**
* 根据注册码获取云端设备信息 Obtain cloud device info by register code
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pszRegisterCode      注册码 Register code
* @param [IN]  pstDevInfo           云端设备信息  Cloud device info
* @return TRUE表示成功,其他表示失败   TRUE means success, any other value indicates failure.
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevByRegCode_V30(IN LPVOID lpUserID,
                                                                     IN CHAR *pszRegisterCode,
                                                                     OUT LPNETDEV_CLOUD_DEV_BASIC_INFO_S pstDevInfo);

/**
* 根据设备名称获取云端设备信息  Obtain cloud device info by device name
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pszDevName           设备名 Device name
* @param [IN]  pstDevInfo           云端设备信息  Cloud device info
* @return TRUE表示成功,其他表示失败   TRUE means success, any other value indicates failure.
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevByName_V30(IN LPVOID lpUserID,
                                                                  IN CHAR *pszDevName,
                                                                  OUT LPNETDEV_CLOUD_DEV_BASIC_INFO_S pstDevInfo);

/**
* 向云端账户中添加云端设备.
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszDevRegisterCode    设备注册码
* @param [IN]  pszDevName           设备名称
* @param [OUT] pstDevBase           云端设备基本信息
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddCloudDevice(IN LPVOID lpUserID,
                                                           IN CHAR *pszDevRegisterCode,
                                                           IN CHAR *pszDevName,
                                                           OUT LPNETDEV_CLOUD_DEV_BASE_INFO_S pstDevBase);

/**
* 修改云端账户中设备名称.
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszDevName           设备名称
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyCloudDevName(IN LPVOID lpUserID,
                                                               IN CHAR *pszDevUserName,
                                                               IN CHAR *pszDevName);

/**
* 修改云端账户中共享设备的设备名称..
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszDevUserName       云端设备ID
* @param [IN]  pszDevName           设备名称
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyCloudShareDevName(IN LPVOID lpUserID,
                                                                    IN CHAR *pszDevUserName,
                                                                    IN CHAR *pszDevName);

/**
* 删除云端账户下单个设备.
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszDevUserName       云端设备ID
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteCloudDevice(IN LPVOID lpUserID,
                                                              IN CHAR *pszDevUserName);

/**
* 批量删除云端账户设备.
* @param [IN]     lpUserID             用户登录ID User login ID
* @param [INOUT]  pstBatchDevList      批量云端设备列表
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteBatchCloudDevice(IN LPVOID lpUserID,
                                                                   INOUT LPNETDEV_BATCH_CLOUD_DEV_LIST_S pstBatchDevList);


/** 暂未实现，待新登录接口实现后开发
* 云端设备动态密码登录   Cloud device login with dynamic password
* @param [IN]  lpUserID             云端账户登录ID Cloud account login ID
* @param [IN]  pstCloudInfo         云端设备登录信息  Cloud device login info
* @param [OUT]  pstSELogInfo        设备安全登录信息   Device Security Logon Information
* @return 返回的用户登陆ID,0表示失败,其他值表示返回的用户登录句柄值  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
    1.pCloudInfo 中szDevicePassword字段不需填写.The szDevicePassword field in pCloudInfo needs not to be filled in.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloudDevice_V30(IN LPVOID lpUserID, 
                                                                   IN LPNETDEV_CLOUD_DEV_LOGIN_INFO_S pstCloudInfo);

/**
* 查询云端账户共享记录.
* @param [IN]  lpUserID             用户登录ID User login ID
* @return TRUE表示成功,其他表示失败
* @note  查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevShareRecordInfo.NETDEV_FindCloseCloudDevShareRecordList等函数的参数.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindShareRecordList(IN LPVOID lpUserID);

/**
* 逐个查询云端账户共享记录.
* @param [IN]  lpFindHandle             记录查找句柄
* @param [OUT] pstShareRecord           云端设备共享记录信息
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextShareRecordInfo(IN LPVOID lpFindHandle,
                                                                    OUT LPNETDEV_CLOUD_DEV_SHARE_RECORD_S pstShareRecord);

/**
* 关闭共享记录查找.
* @param [IN]  lpFindHandle             记录查找句柄
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseShareRecordList(IN LPVOID lpFindHandle);

/**
* 查询云端账户设备共享信息   Query device list under a cloud account
* @param [IN]  lpUserID            用户登录句柄 User login ID
* @return 查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevInfo.NETDEV_FindCloseDevList等函数的参数.
Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevInfo and NETDEV_FindCloseDevList.
* @note 此函数返回值为云端设备列表查询业务号,若返回值为非0,则查询云端设备列表成功：
*         一.将上述业务号作为NETDEV_FindNextCloudDevShareInfo函数的入参lpFindHandle,多次调用NETDEV_FindNextCloudDevShareInfo函数,以逐个获取已查询到的云端设备信息.
*         二.查询结束后,必须以上述业务号作为NETDEV_FindCloseCloudDevShareInfoList函数的入参lpFindHandle,调用NETDEV_FindCloseCloudDevShareInfoList函数,以释放资源,关闭查找.
*/

NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevShareList(IN LPVOID lpUserID);

/**
* 逐个获取查找到的查询云端设备共享信息   Obtain info about detected devices one by one
* @param [IN]  lpFindHandle         查找句柄   Search handle
* @param [OUT] pstDevShare           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevShareInfo(IN LPVOID lpFindHandle,
                                                                      OUT LPNETDEV_CLOUD_DEV_SHARE_INFO_S pstDevShare);

/**
* 关闭查找,释放资源 Stop search and release resource 
* @param [IN] lpFindHandle  查找句柄 File search handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevShareList(IN LPVOID lpFindHandle);

/**
* 根据设备名称获取云端设备共享信息
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pszDevUserName       云端设备ID
* @param [IN]  pstDevShare           云端设备信息
* @return
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetShareDevInfoByName(IN LPVOID lpUserID, 
                                                                  IN CHAR *pszDevUserName, 
                                                                  OUT LPNETDEV_CLOUD_DEV_SHARE_INFO_S pstDevShare);

/**
* 开启云端设备共享.
* @param [IN]     lpUserID             用户登录ID User login ID
* @param [INOUT]  pstDevShareCfg       云端设备共享配置
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartCloudDevShare(IN LPVOID lpUserID,
                                                               INOUT LPNETDEV_CLOUD_DEV_SHARE_CFG_S pstDevShareCfg);

/**
* 关闭云端设备共享.
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pszDevUserName       云端设备ID
* @param [IN]  bIsStopedByOwner     是否由设备所有者关闭共享
* @param [IN]  pszTarget            共享对象（当bIsStopedByOwner等于FALSE时可传入空字符串）
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopCloudDevShare(IN LPVOID lpUserID,
                                                              IN CHAR *pszDevUserName,
                                                              IN BOOL bIsStopedByOwner,
                                                              IN CHAR *pszTarget);

/**
* 批量关闭云端设备共享.
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  pstBatchDevShareList 批量关闭云端共享设备信息列表
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopBatchCloudDevShare(IN LPVOID lpUserID,
                                                                   INOUT LPNETDEV_BATCH_DEV_SHARE_LIST_S pstBatchDevShareList);

/**
* 根据设备名称获取云账号下单个设备共享记录信息 Get shared record information under cloud account based on device name
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  pszDevUserName       设备名 Device name
* @param [OUT] pstDevInfo           云端共享设备信息 Cloud sharing device information
* @return                           查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevShareRecoredInfo.NETDEV_FindCloseCloudDevShareRecoredList等函数的参数.
                                    Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevShareRecoredInfo and NETDEV_FindCloseCloudDevShareRecoredList.
* @note                             此函数返回值为云账号下获取单个设备所有共享记录业务号,若返回值为非0,则获取云账号下单个设备共享记录列表成功：
*                                   一.将上述业务号作为NETDEV_FindNextCloudDevShareRecoredInfo函数的入参lpFindHandle,多次调用NETDEV_FindNextCloudDevShareRecoredInfo函数,以逐个获取已查询到的共享记录信息.
*                                   二.查询结束后,必须以上述业务号作为NETDEV_FindCloseCloudDevShareRecoredList函数的入参lpFindHandle,调用NETDEV_FindCloseCloudDevShareRecoredList函数,以释放资源,关闭查找.
*
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevShareRecordList(IN LPVOID lpUserID,
                                                                          IN CHAR *pszDevUserName,
                                                                          OUT LPNETDEV_DEV_INFO_S pstDevInfo);

/**
* 根据云账号动态密码获取云账号下共享记录列表                     Get shared record information list under cloud account based by cloud count dynamic
* @param [IN]  pszCloudSrvUrl       云端服务器URL                Cloud server URL 
* @param [IN]  pszUserName          云账号                       Cloud count 
* @param [IN]  pszPasswd            云账号动态密码               Cloud count dynamic password
* @param [IN]  pszDevUserName       设备名                       Device name
* @param [OUT] pstDevInfo           云端共享设备信息             Cloud sharing device information
* @return                           查询业务号,返回0表示失败,其他值作为NETDEV_FindNextCloudDevShareRecoredInfo.NETDEV_FindCloseCloudDevShareRecoredList等函数的参数.
                                    Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevShareRecoredInfo and NETDEV_FindCloseCloudDevShareRecoredList.
* @note                             此函数返回值为云账号下获取单个设备所有共享记录业务号,若返回值为非0,则获取云账号下单个设备共享记录列表成功：
*                                   一.将上述业务号作为NETDEV_FindNextCloudDevShareRecoredInfo函数的入参lpFindHandle,多次调用NETDEV_FindNextCloudDevShareRecoredInfo函数,以逐个获取已查询到的共享记录信息.
*                                   二.查询结束后,必须以上述业务号作为NETDEV_FindCloseCloudDevShareRecoredList函数的入参lpFindHandle,调用NETDEV_FindCloseCloudDevShareRecoredList函数,以释放资源,关闭查找.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevShareRecordListByDynamic(IN CHAR *pszCloudSrvUrl,
                                                                                   IN CHAR *pszUserName, 
                                                                                   IN CHAR *pszPasswd,
                                                                                   IN CHAR *pszDevUserName,
                                                                                   OUT LPNETDEV_DEV_INFO_S pstDevInfo);


/**
* 逐个获取查找到的云账号下单个设备共享记录信息                                             Obtain information about share record one by one
* @param [IN]  lpFindHandle                        查找句柄                                Search handle
* @param [OUT] pstShareLimitInfo                   保存单个设备共享记录信息的指针          Pointer to saved signle share record information
* @return                                          TRUE表示成功,其他表示失败               TRUE means success, and any other value means failure.
* @note                                            返回失败说明查询结束                    A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevShareRecordInfo(IN LPVOID lpFindHandle,
                                                                            OUT LPNETDEV_SHARE_LIMIT_INFO_S pstShareLimitInfo);

/**
* 关闭查找,释放资源                                                      Stop search and release resource 
* @param [IN] lpFindHandle            查找句柄                           File search handle
* @return                             TRUE表示成功,其他表示失败          TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevShareRecordList(IN LPVOID lpFindHandle);

/**
* 设置设备通道共享 Setup device and channel sharing
* @param [IN]  lpUserID 用户登录句柄 User login ID
* @param [IN]  pstDevChannelShareInfo   设备、通道共享信息 Device and channel share information
* @param [OUT]  pstResponse 设备、通道共享响应信息 Device and channel share response
* @return
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevChannelShare(IN LPVOID lpUserID,
                                                               IN LPNETDEV_CHANNEL_SHARE_INFO_S pstDevChannelShareInfo,
                                                               OUT LPNETDEV_RESPONSE_S pstResponse);

/**
* 通过云账号动态密码设置设备通道共享 Setup device and channel sharing by cloud count dynamic password
* @param [IN]  pszCloudSrvUrl 云端服务器URL Cloud server URL
* @param [IN]  pstDevChannelShareInfo   设备、通道共享信息 Device and channel share information
* @param [OUT]  pstResponse 设备、通道共享响应信息 Device and channel share response
* @return
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevChannelShareByDynamic(IN CHAR *pszCloudSrvUrl,
                                                                        IN LPNETDEV_CHANNEL_SHARE_INFO_S pstDevChannelShareInfo,
                                                                        OUT LPNETDEV_RESPONSE_S pstResponse);

/**
* 删除设备通道共享 Delete device and channel sharing
* @param [IN]  lpUserID 用户登录句柄 User login ID
* @param [IN]  pstDevChannelShareInfo   设备、通道共享信息 Device and channel share information
* @return
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteDevChannelShare(IN LPVOID lpUserID,
                                                                  IN LPNETDEV_DELETE_SHARE_CHANNEL_INFO_S pstDevChannelShareInfo);

/**
* 添加云端组织
* @param [IN] lpUserID                  云端账户登录ID
* @param [IN] dwParentOrgID             父组织ID
* @param [IN] pszOrgName                要添加的组织名
* @param [OUT] pdwOrgID                 生成的新组织ID
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddCloudOrg(IN LPVOID lpUserID,
                                                        IN INT32 dwParentOrgID,
                                                        IN CHAR* pszOrgName,
                                                        OUT INT32 *pdwOrgID);

/**
* 修改云端组织名称
* @param [IN] lpUserID                  云端账户登录ID
* @param [IN] dwOrgID                   组织ID
* @param [IN] pszOrgName                要修改的组织名称
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyCloudOrg(IN LPVOID lpUserID,
                                                           IN INT32 dwOrgID,
                                                           IN CHAR* pszOrgName);

/**
* 删除云端组织
* @param [IN] lpUserID              云端账户登录ID
* @param [IN] dwOrgID               待删除组织ID
* @param [IN] dwDeleteMode          删除模式，参加枚举
* @return TRUE表示成功，其他表示失败
* @note 根据组织ID删除组织，删除模式说明：
*        模式1，删除该组织下的所有子组织，如果这些组织下有设备，统一划归到根节点root下；
*        模式2，如果该组织下有其它子组织或者有设备，就不允许删除（需要先删除子组织或先调用设备划归，把设备划归到别处）
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteCloudOrg(IN LPVOID lpUserID,
                                                           IN INT32 dwOrgID,
                                                           IN INT32 dwDeleteMode);

/**
<<<<<<< .mine
* 查询云端账户组织列表.
=======
* 通过云账号动态密码删除设备、通道共享                               Delete device and channel sharing by cloud count dynamic password
* @param [IN]  pszCloudSrvUrl           云端服务器URL                Cloud server URL
* @param [IN]  pstDevChannelShareInfo   设备、通道共享信息           Device and channel share information
* @return
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteDevChannelShareByDynamic(IN CHAR *pszCloudSrvUrl,
                                                                           IN LPNETDEV_DELETE_SHARE_CHANNEL_INFO_S pstDevChannelShareInfo);

/**
* 查询云端账户组织列表.\n
* @param [IN]  lpUserID             云端账户登录ID
* @param [OUT] pstOrgList           设备信息结构体指针
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudOrgList(IN LPVOID lpUserID);

/**
* 逐个获取查找到的查询云端设备共享信息   Obtain info about detected devices one by one
* @param [IN]  lpFindHandle         查找句柄   Search handle
* @param [OUT] pstDevShare           保存设备信息的指针   Pointer to saved device info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudOrgInfo(IN LPVOID lpFindHandle,
                                                                 OUT LPNETDEV_CLOUD_ORG_INFO_S pstOrgInfo);

/**
* 关闭查找,释放资源 Stop search and release resource 
* @param [IN] lpFindHandle  查找句柄 File search handle
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudOrgList(IN LPVOID lpFindHandle);

/**
* 添加设备到组织
* @param [IN] lpUserID                  云端账户登录ID
* @param [IN] pstCloudDevBindInfo        组织云端设备绑定信息
* @param [IN] dwOrgID                   组织ID
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddDevice2Org(IN LPVOID lpUserID,
                                                          IN LPNETDEV_CLOUD_DEV_BASE_INFO_S pstCloudDevBindInfo,
                                                          IN INT32 dwOrgID);

/**
* 获取云端设备通道信息列表
* @param [IN] lpUserID                      云端账户登录ID
* @param [IN] pszDeviceSN                   云端设备序列号
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextCloudDevChlList、NETDEV_FindCloseCloudDevChlList等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevChlList(IN LPVOID lpUserID,
                                                                  IN CHAR* pszDeviceSN);

/**
* 逐个获取查找到的云端设备通道信息
* @param [IN]  lpFindHandle             查找句柄 
* @param [OUT] pstCloudDevChlInfo       保存云端设备通道信息的指针
* @return TRUE表示成功，其他表示失败 
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevChlInfo(IN LPVOID lpFindHandle,
                                                                    OUT LPNETDEV_CLOUD_DEV_CHL_INFO_S pstCloudDevChlInfo);

/**
* 关闭查找云端设备通道信息，释放资源
* @param [IN] lpFindHandle                              查找句柄 
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevChlList(IN LPVOID lpFindHandle);

/**
* 获取云账户设备统计信息
* @param [IN]  lpUserID                         云端账户登录ID
* @param [OUT] pstCloudDevPopulInfo             云端设备统计信息
* @return TRUE表示成功,其他表示失败
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevPopulation(IN LPVOID lpUserID,
                                                                  OUT LPNETDEV_CLOUD_DEV_POPUL_INFO_S pstCloudDevPopulInfo);


/**
* 获取云设备远程URL
* @parm [IN]    LPVOID lpUserID 云账号登录句柄
* @parm [IN]    CHAR* pszDevUserName, 云设备用户名
* @parm [INOUT]    INT32* pdwUrlLen,     pszJumpUrl长度
* @parm [OUT]   CHAR*  pszRemoteUrl，云设备URL,由使用者分配内存
* @return 返回TRUE表示成功，其它表示失败
* note 如果pszRemoteUrl的内存分配不够，将调用失败，pdwUrlLen会返回实际需要的字节数
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevRemoteUrl(IN LPVOID lpUserID,
                                                                 IN CHAR* pszDevUserName,
                                                                 INOUT INT32* pdwUrlLen,
                                                                 OUT CHAR* pszRemoteUrl);

/**
* 获取NAT类型
* @param [IN]  pszDomain                    域名
* @param [IN]  pdwNatType                   NAT类型  参考#NETDEV_NAT_TYPE_E
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetNATType(IN CHAR* pszDomain, 
                                                       OUT INT32 *pdwNatType);

/**
* 获取云端设备登陆信息(云端登录成功后调用)
* @param [IN]   lpUserID                       用户登录ID User login ID
* @param OUT pstCloudDevNatInfo                云设备登陆信息
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevLoginInfo(IN LPVOID lpUserID, 
                                                                 OUT LPNETDEV_CLOUD_NAT_LOGIN_INFO_S pstCloudDevNatInfo);

/**
* 获取云端登录设备URL(云端登录成功后调用)
* @param [IN]   lpUserID              用户登录ID User login ID
* @param [IN]   dwSize                字符串长度
* @param [OUT]  pszUrl                云端登录成功后URL
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevUrl(IN LPVOID lpUserID, IN INT32 dwSize, OUT CHAR* pszUrl);



/*                   云服务模块结束行                              */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_PTZ
/************************************************************************/
/*                  包含云台模块                                 */
/************************************************************************/
/**
* 云台控制操作(不启动实况预览)  PTZ control operation (preview not required)
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  dwPTZCommand         云台控制命令,参见#NETDEV_PTZ_E
PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              云台控制的速度,用户按不同解码器的速度控制值设置.取值范围[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZCommand, IN INT32 dwSpeed);

/**
* 获取云台预置位列表
* @param [IN]  lpUserID             用户登录ID User login ID
* @param [IN]  dwChannelID          通道号 Channel number
* @param [IN]  pstPresetList        预置位列表
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetPTZPresetList(IN LPVOID lpUserID, IN INT32  dwChannelID, OUT LPNETDEV_PTZ_ALLPRESETS_S pstPresetList);

/**
* 云台预置位操作(不需要启动预览)  PTZ preset operation (preview not required)
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  dwPTZPresetCmd       操作云台预置位命令,参考枚举NETDEV_PTZ_PRESETCMD_E PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        预置位的名称 Preset name
* @param [IN]  dwPresetID           预置位的序号（从1开始）,最多支持255个预置位. Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZPresetCmd, IN CHAR *pszPresetName, IN INT32 dwPresetID);

/**
* 获取云台预置位巡航路径  Get PTZ preset patrol route
* @param [IN]   lpUserID            用户登录句柄 User login ID
* @param [IN]   dwChannelID         通道号 Channel ID
* @param [OUT]  pstCruiseList        巡航路径列表 Patrol route list
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetCruise(IN LPVOID lpUserID, IN INT32 dwChannelID, OUT LPNETDEV_CRUISE_LIST_S pstCruiseList);

/**
* 云台预置位巡航操作(不需要启动预览)  PTZ preset patrol operation (preview not required)
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  dwPTZCruiseCmd       操作云台巡航命令,参考#NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see #NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         云台巡航路径信息,参考#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1.巡航路径,最多支持16条路径（序号从1开始） Patrol route. Up to 16 routes are supported (starting from 1).
* - 2.巡航点,最多支持32个点（序号从1开始） Patrol point. Up to 32 points are supported (starting from 1).
* - 3.预置位(最大255).时间(最大255).速度(最大40)  Preset (max 255), time (max 255) and speed (max 40).
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZCruiseCmd, IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo);


/**
* 获取云台轨迹巡航路径  Get PTZ patrol route
* @param [IN]   lpUserID            用户登录句柄 User login ID
* @param [IN]   dwChannelID         通道号 Channel ID
* @param [OUT]  pstTrackCruiseInfo        巡航路径列表,参考#LPNETDEV_PTZ_TRACK_INFO_S  Patrol route list, see #LPNETDEV_PTZ_TRACK_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackCruise(IN LPVOID lpUserID, IN INT32 dwChannelID, OUT LPNETDEV_PTZ_TRACK_INFO_S pstTrackCruiseInfo);


/**
* 获取云台轨迹巡航路径
* Get PTZ patrol route
* @param [IN]   lpUserID                  用户登录ID User login ID
* @param [IN]   dwChannelID               通道号 Channel number
* @param [OUT]  pstTrackCruiseList        巡航路径列表,参考#LPNETDEV_PTZ_TRACK_LIST_V30_S
Patrol route list, see #LPNETDEV_PTZ_TRACK_LIST_V30_S
* @return  TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackCruise_V30(IN LPVOID lpUserID, IN INT32 dwChannelID, OUT LPNETDEV_PTZ_TRACK_LIST_V30_S pstTrackCruiseList);

/**
* 云台轨迹巡航操作(不需要启动预览)   PTZ route patrol operation (preview not required)
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  dwPTZCruiseCmd       操作云台轨迹巡航命令,参考#NETDEV_PTZ_TRACKCMD_E  PTZ route patrol operation commands, see #NETDEV_PTZ_TRACKCMD_E
* @param [INOUT]  pszTrackCruiseName         轨迹巡航名称,建议长度#NETDEV_LEN_64  Route patrol name, suggested length #NETDEV_LEN_64
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1.巡航轨迹路径,最多支持1条路径  Only one patrol route allowed.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZTrackCruise(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZTrackCruiseCmd, INOUT CHAR *pszTrackCruiseName);

/**
* 云台轨迹巡航操作(不需要启动预览)
* PTZ route patrol operation (preview not required) 
* @param [IN]  lpUserID                  用户登录ID User login ID
* @param [IN]  dwChannelID               通道号 Channel number
* @param [IN]  dwPTZTrackCruiseCmd       操作云台轨迹巡航命令,参考#NETDEV_PTZ_TRACKCMD_E
* @param [IN]  pstTrackCruiseInfo        云台轨迹巡航路径信息
PTZ route patrol operation commands, see #NETDEV_PTZ_TRACKCMD_E
Route patrol name, suggested length #NETDEV_LEN_64
* @return  TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1、巡航轨迹路径，最多支持1条路径
* - 1 Only one patrol route allowed.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZTrackCruise_V30(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZTrackCruiseCmd, IN LPNETDEV_PTZ_TRACK_INFO_V30_S pstTrackCruiseInfo);


/**
* 拉框放大.缩小(不需要启动预览)   Drag to zoom in and out(preview not required)
* @param lpUserID                   用户登录句柄 User login ID
* @param [IN]  dwChannelID          通道号 Channel ID
* @param [IN]  pstPtzOperateArea    拉框放大结构体信息 Drag-to-zoom structure information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 在我司NVR下,需通过私有协议连接我司IPC才支持该接口  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea);


/**
* 云台3D定位(不需要启动预览)
* @param [IN] lpUserID               用户登录ID User login ID
* @param [IN] dwChannelID            通道号
* @param [IN] pstZoomAreaInfo        拉框缩放结构体
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZ3DPosition_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);


/**
* 云台拉框放大(不需要启动预览)
* @param [IN] lpUserID                用户登录ID
* @param [IN] dwChannelID             通道ID
* @param [IN] pstZoomAreaInfo         拉框缩放结构体
* @return TRUE表示成功，其他表示失败 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAreaZoomIn_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);

/**
* 云台拉框缩小(不需要启动预览)
* @param [IN] lpUserID                    用户登录ID
* @param [IN] dwChannelID                 通道ID
* @param [IN] pstZoomAreaInfo             拉框缩放结构体
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAreaZoomOut_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);

/**
* 获取指定通道的巡航状态
* @param [IN] lpUserID                   用户登录ID
* @param [IN] dwChannelID                通道ID
* @param [OUT] pstTrackStatus            巡航状态信息结构体,参考#LPNETDEV_PTZ_TRACK_STATUS_INFO
* @return  TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackStatus(IN LPVOID lpUserID, IN INT32 dwChannelID, OUT LPNETDEV_PTZ_TRACK_STATUS_INFO_S pstTrackStatus);


/**
* 云台看守位操作(不需要启动预览)  PTZ Home position (preview not required)
* @param [IN]  lpUserID                   用户登录句柄 User login ID
* @param [IN]  dwChannelID                通道号 Channel ID
* @param [IN]  dwPTZHomePositionCmd       操作云台看守位命令,参考#NETDEV_PTZ_HOMEPOSITIONCMD_E PTZ home position control commond
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZHomePosition_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZHomePositionCmd);


/**
* 云台绝对坐标转动 PTZ absolute move
* @param [IN]  lpUserID         用户登录句柄 User login ID
* @param [IN]  dwChannelID      通道号 Channel ID
* @param [IN]  pstAbsoluteMove  云台绝对坐标转动结构体信息 PTZ absolute move info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAbsoluteMove(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_ABSOLUTE_MOVE_S pstAbsoluteMove);

/**
* 获取云台状态 
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @param [IN]  dwChannelID  通道号 Channel ID
* @param [IN]  pstPTZStaus  云台状态
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetStatus(IN LPVOID lpUserID, IN INT32 dwChannelID, IN LPNETDEV_PTZ_STATUS_S pstPTZStaus);


/**
* 获取、设置指定通道的云台守望信息(不需要启动预览)
* @param [IN] lpUserID                    用户登录ID
* @param [IN] dwChannelID                 通道ID
* @param [IN] dwPTZGuardCmd               操作云台守望命令，参考#NETDEV_PTZ_GUARDCMD_E
* @param [OUT] pstPTZGuardInfo            拉框缩放结构体
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetGuard_Other(IN LPVOID lpUserID, IN INT32 dwChannelID, IN INT32 dwPTZGuardCmd, OUT LPNETDEV_PTZ_GUARD_INFO_S pstPTZGuardInfo);



/*                   以下为云台模块需要开始实况的业务             */
#ifdef NETDEV_WITH_MEDIA

/**
* 云台预置位操作(需先启动预览)  PTZ preset operation (preview required)
* @param [IN]  lpPlayHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZPresetCmd       操作云台预置位命令,参考枚举NETDEV_PTZ_PRESETCMD_E  PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        预置位的名称 Preset name
* @param [IN]  dwPresetID           预置位的序号（从1开始）,最多支持255个预置位 Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset(IN LPVOID lpPlayHandle, IN INT32  dwPTZPresetCmd, IN CHAR   *pszPresetName, IN INT32  dwPresetID);

/**
* 云台控制操作(需先启动实况预览)  PTZ control operation (preview required)
* @param [IN]  lpPlayHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZCommand         云台控制命令,参见#NETDEV_PTZ_E PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              云台控制的速度,用户按不同解码器的速度控制值设置.取值范围[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl(IN LPVOID lpPlayHandle, IN INT32 dwPTZCommand, IN INT32 dwSpeed);

/**
* 云台预置位巡航操作(需先启动预览)  PTZ preset patrol operation (preview required)
* @param [IN]  lpPlayHandle         实时预览句柄 Live preview handle
* @param [IN]  dwPTZCruiseCmd       操作云台巡航命令,参考枚举：NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         云台巡航路径信息,参考#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1.巡航路径ID不可修改. Patrol route ID cannot be modified.
* - 2.新增巡航路径时,默认按顺序新增.  New routes are added one after another.
* - 3.删除.开始.停止巡航路径时,pstCruiseInfo中只需要填写巡航路径ID即可.  When deleting, starting or stopping patrol, enter patrol route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise(IN LPVOID lpPlayHandle, IN INT32 dwPTZCruiseCmd, IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo);

/**
* 拉框放大.缩小(需先启动预览)   Drag to zoom in and out (preview required)
* @param [IN]  lpPlayHandle         实时预览句柄 Live preview handle
* @param [IN]  pstPtzOperateArea    拉框放大结构体信息 Drag-to-zoom structure information
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 在我司NVR下,需通过私有协议连接我司IPC才支持该接口  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn(IN LPVOID lpPlayHandle, IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea);

/**
* 云台3D定位
* @param [IN] lpPlayHandle          实时预览句柄
* @param [IN] pstZoomAreaInfo       拉框放大结构体提
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZ3DPosition(IN LPVOID lpPlayHandle, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);

/**
* 云台拉框放大
* @param [IN] lpPlayHandle             实时预览句柄
* @param [IN] pstZoomAreaInfo          拉框缩放结构体
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAreaZoomIn(IN LPVOID lpPlayHandle, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);


/**
* 云台拉框缩小
* @param [IN] lpPlayHandle              实时预览句柄
* @param [IN] pstZoomAreaInfo           拉框缩放结构体
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAreaZoomOut(IN LPVOID lpPlayHandle, IN LPNETDEV_PTZ_ZOOM_AREA_INFO_S pstZoomAreaInfo);

/**
* 云台看守位操作(需要启动预览)  PTZ Home position (preview required)
* @param [IN]  lpRealHandle             实时预览句柄 Live preview handle
* @param [IN]  dwPTZHomePositionCmd     操作云台看守位命令,参考枚举NETDEV_PTZ_HOMEPOSITIONCMD_E PTZ home position control commond
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZHomePosition(IN LPVOID lpRealHandle, IN INT32 dwPTZHomePositionCmd);


/**
* 云台标定 PTZ Calibrate
* @param [IN]  lpUserID                   用户登录句柄 User login ID
* @param [IN]  dwChannelID                通道号 Channel ID
* @param [IN]  pstOrientationInfo            云台方位信息 PTZ Orientation info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCalibrate(IN LPVOID lpUserID,
                                                         IN INT32 dwChannelID,
                                                         IN LPNETDEV_PTZ_ORIENTATION_INFO_S pstOrientationInfo
                                                         );

#endif


/*                   云台模块结束行                              */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif













////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_CONFIG
/************************************************************************/
/*                  包含配置业务模块                              */
/************************************************************************/
/**
* 获取设备能力集 Obtain device capability
* @param [IN]   lpUserID                用户登录句柄 User login ID
* @param [IN]  dwChannelID              通道号 Channel ID
* @param [IN]   dwCommand               设备能力类型指令 NETDEV_CAPABILITY_COMMOND_E
* @param [OUT]  lpOutBuffer             接收数据的缓冲指针 Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         接收数据的缓冲长度(以字节为单位)，不能为0 Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned        实际收到的数据长度指针，不能为NULL  Pointer to length of received data, cannot be NULL.
* @return TRUE表示成功，其他表示失败      TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDeviceCapability(IN LPVOID lpUserID,
                                                                IN INT32 dwChannelID,
                                                                IN INT32 dwCommand,
                                                                OUT LPVOID lpOutBuffer,
                                                                OUT INT32  dwOutBufferSize,
                                                                OUT INT32  *pdwBytesReturned);

/**
* 获取设备的配置信息  Get configuration information of device
* @param [IN]   lpUserID                用户登录句柄 User login ID
* @param [IN]   dwChannelID             通道号 Channel ID
* @param [IN]   dwCommand               设备配置命令,参见# NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [OUT]  lpOutBuffer             接收数据的缓冲指针 Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         接收数据的缓冲长度(以字节为单位),不能为0 Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned        实际收到的数据长度指针,不能为NULL  Pointer to length of received data, cannot be NULL.
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
* - 1.巡航路径ID不可修改.  Route ID cannot be modified.
* - 2.新增巡航路径时,默认按顺序新增.  New routes are added one after another.
* - 3.删除.开始.停止巡航路径时,pstCruiseInfo中只需要填写巡航路径ID即可.  When deleting, starting or stoping a patrol route, enter route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         OUT LPVOID lpOutBuffer,
                                                         OUT INT32  dwOutBufferSize,
                                                         OUT INT32  *pdwBytesReturned);

/**
* 设置设备的配置信息  Modify device configuration information
* @param [IN]   lpUserID            用户登录句柄 User login ID
* @param [IN]   dwChannelID         通道号 Channel ID
* @param [IN]   dwCommand           设备配置命令,参见#NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [IN]   lpInBuffer          输入数据的缓冲指针 Pointer to buffer of input data
* @param [IN]   dwInBufferSize      输入数据的缓冲长度(以字节为单位) Length of input data buffer (byte)
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         IN LPVOID  lpInBuffer,
                                                         IN INT32   dwInBufferSize);


/**
* 重启设备
* Restart device
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Reboot(IN LPVOID lpUserID);


/**
* 恢复出厂设置  Restore to factory default settings
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note 保留网络配置和用户配置,其他参数恢复到出厂设置. Restore all parameters to factory settings, except network settings and user settings.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_RestoreConfig(IN LPVOID lpUserID);

/**
* 开启/关闭Telnet
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   bEnable                     telnet状态
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_EnableTelnet(IN LPVOID lpUserID,
                                                         IN BOOL bEnable);

/**
* 修改设备名称 Set device name
* @param [IN] lpUserID         用户登录句柄 User login ID
* @param [IN] pszDeviceName    设备名称  Device name
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyDeviceName(IN LPVOID lpUserID,
                                                             IN CHAR *pszDeviceName);


/**
* 获取映射端口 Get UPnP net state info
* @param [IN]   lpUserID     用户登录句柄 User login ID
* @param [IN]   pstNatState  网络端口号状态信息 UPnP nat state info
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUpnpNatState(IN LPVOID lpUserID,
                                                            OUT LPNETDEV_UPNP_NAT_STATE_S pstNatState);

/**
* 设置映射端口 Set UPnP net state info
* @param [IN]   lpUserID                  用户登录句柄 User login ID
* @param [IN]   pstNatState               网络端口号状态信息 UPnP nat state info
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetUpnpNatState(IN LPVOID lpUserID,
                                                            IN LPNETDEV_UPNP_NAT_STATE_S pstNatState);

/**
* 获取设备系统时间配置 Get device System time configuration
* @param [IN]  pstSystemTimeInfo    时间配置结构体指针  Pointer to time configuration structure
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSystemTimeCfg(IN LPVOID lpUserID,
                                                             OUT LPNETDEV_TIME_CFG_S pstSystemTimeInfo);

/**
* 设置设备系统时间配置 Set device system time configuration
* @param [IN]  pstSystemTimeInfo    时间配置结构体指针  Pointer to time configuration structure
* @return TRUE表示成功,其他表示失败  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetSystemTimeCfg(IN LPVOID lpUserID,
                                                             IN LPNETDEV_TIME_CFG_S pstSystemTimeInfo);

/**
* 获取手动录像状态
* @param [IN]  lpUserID       设备句柄
* @param [IN]  pstManualRecordCfg    手动录像参数信息
* @param [OUT]  & udwRecodeStatus    手动录像状态   参见枚举NETDEV_MANUAL_RECORD_STATUS_E
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetManualRecordStatus(IN LPVOID lpUserID,
                                                                  IN LPNETDEV_MANUAL_RECORD_CFG_S pstManualRecordCfg,
                                                                  OUT UINT32 *pudwRecodeStatus);


/**
* 开启手动录像 Start manual record
* @param [IN]   lpUserID                用户登录句柄 User login ID
* @param [IN]   pstManualRecordCfg      手动录像参数信息 Manual record config
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartManualRecord(IN LPVOID lpUserID,
                                                              IN LPNETDEV_MANUAL_RECORD_CFG_S pstManualRecordCfg);

/**
* 停止手动录像 Stop manual record
* @param [IN]   lpUserID                用户登录句柄 User login ID
* @param [IN]   pstManualRecordCfg      手动录像参数信息 Manual record config
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopManualRecord(IN LPVOID lpUserID,
                                                             IN LPNETDEV_MANUAL_RECORD_CFG_S pstManualRecordCfg);

/**
* 查询指定通道录像的天数                    Get daynums of Specify Channel
* @param [IN]   lpUserID                    用户登录句柄 User login ID
* @param [IN]   dwChannelID                 通道号  Channel ID
* @param [OUT]   dwDayNums                  录像天数  Video daynums
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoDayNums(IN LPVOID lpUserID, 
                                                            IN INT32 dwChannelID,
                                                            OUT UINT32 *dwDayNums);

/**
* 根据日志类型、时间查找日志信息 Search NVR log by log type and time
* @param [IN]  lpUserID              用户登录 ID User login ID
* @param [IN]  pstLogFindCond        日志查询条件 Log search condition
* @return 日志查询业务号,返回NETDEV_E_FAILED表示失败，其他值作为NETDEV_CloseFindLog等函数的参数。
Log search service number. NETDEV_E_FAILED means failure, and any other value is used as the parameter of functions like NETDEV_CloseFindLog.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindLogInfoList(IN LPVOID lpUserID,
                                                              IN LPNETDEV_FIND_LOG_COND_S pstLogFindCond);

/**
* 逐个获取查找到的日志信息 Obtain logone by one
* @param [IN]  lFindHandle           日志查找句柄 Log search handle
* @param [OUT] pstFindData           保存日志信息的指针 Pointer to saved log info
* @return NETDEV_E_SUCCEED表示成功，其他表示失败 NETDEV_E_SUCCEED means success, and any other value means failure
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextLogInfo(IN LPVOID lpFindHandle,
                                                            OUT LPNETDEV_LOG_INFO_S pstLogInfo);

/**
* 关闭日志查找，释放资源 Close log search and release resource
* @param [IN]  lFindHandle           文件查找句柄 File search handle
* @return NETDEV_E_SUCCEED表示成功，其他表示失败 NETDEV_E_SUCCEED means success, and any other value means failure
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseLogInfo(IN LPVOID lpFindHandle);


/**
* 根据时间查询设备告警
* @param [IN]  lpUserID             用户登录ID
* @param [IN]  pstAlarmFindCond     告警查询条件
* @return 告警查询业务号,返回NETDEV_E_FAILED表示失败，其他值作为NETDEV_CloseFindAlarm等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindAlarmInfoList(IN LPVOID lpUserID, 
                                                                IN LPNETDEV_FIND_ALARM_COND_S pstAlarmFindCond);

/**
* 逐个获取查找到的告警信息
* @param [IN]  lFindHandle    日志查找句柄
* @param [OUT] pstAlarmInfo   保存告警信息
* @return NETDEV_E_SUCCEED表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextAlarmInfo(IN LPVOID lpFindHandle,
                                                              OUT LPNETDEV_FIND_ALARM_INFO_S pstAlarmInfo);

/**
* 关闭告警查询，释放资源
* @param [IN]  lFindHandle  文件查找句柄
* @return NETDEV_E_SUCCEED表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseAlarmInfo(IN LPVOID lpFindHandle);



/**
* 获取所有用户全部信息
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [OUT]   pstUserDetailList             用户信息 请参见结构体#LPNETDEV_USER_DETAIL_LIST_S
* @return TRUE表示成功,其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUserDetailList(IN LPVOID lpUserID,
                                                              OUT LPNETDEV_USER_DETAIL_LIST_S pstUserDetailList);

/**
* 获取指定用户全部信息
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [INOUT]   pstUserDetailInfo             用户信息 请参见结构体#NETDEV_USER_DETAIL_INFO_S
* @return TRUE表示成功,其他表示失败
* @note   pstUserDetailInfo中的szUsername为入参
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUserDetailInfo(IN LPVOID lpUserID,
                                                              INOUT LPNETDEV_USER_DETAIL_INFO_S pstUserDetailInfo);

/**
* 创建用户信息
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   pstUserDetailInfo             用户信息请参见结构体#NETDEV_USER_DETAIL_INFO_S
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CreateUser(IN LPVOID lpUserID,
                                                       IN LPNETDEV_USER_DETAIL_INFO_S pstUserDetailInfo);

/**
* 修改用户信息
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   pstUserInfo             用户信息请参见结构体#NETDEV_USER_INFO_S
* @return TRUE表示成功,其他表示失败
* @note
    1、仅管理员用户支持修改权限，管理员用户修改其他用户信息不需要携带旧密码
    2、操作员及普通用户只能修改自己的密码
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyUser(IN LPVOID lpUserID,
                                                       IN LPNETDEV_USER_MODIFY_DETAIL_INFO_S pstUserInfo);

/**
* 删除用户信息
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   pszUserName             用户名
* @return TRUE表示成功,其他表示失败
* @note 无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteUser(IN LPVOID lpUserID,
                                                       IN CHAR *pszUserName);

/**
* 修改指定用户密码
* @param [IN]   lpUserID                用户登录ID 
* @param [IN]   IN LPNETDEV_MODIFY_PASSWORD_INFO_S pstModifyPasswordInfo 用户密码
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyPassword(IN LPVOID lpUserID,
                                                           IN LPNETDEV_MODIFY_PASSWORD_INFO_S pstModifyPasswordInfo);

/**
* 获取设备当前密码
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [OUT]  pszPassword             密码 内存长度要求大于等于NETDEV_LEN_64
* @return TRUE表示成功,其他表示失败
* @note 无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevPassword(IN LPVOID lpUserID,
                                                           OUT CHAR *pszPassword);


/**
* 修改当前用户密码
* @param [IN] lpUserID          用户登录ID
* @param [IN] pszNewPasswd      新密码
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ChangePassword(IN LPVOID lpUserID,
                                                           IN CHAR* pszNewPasswd);

/**
* 获取当前用户权限
* @param [IN] lpUserID              用户登录ID
* @param [OUT] pstRoleRightList     用户权限信息列表
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCurrentUserRightList(IN LPVOID lpUserID, 
                                                                 OUT LPNETDEV_RIGHT_LIST_S pstRoleRightList);

/**
* 设置设备云功能
* @param [IN]   lpUserID                    用户登录ID
* @param [IN]   bEnableCloud                Cloud使能
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_EnableCloudState(IN LPVOID lpUserID,
                                                             IN BOOL bEnableCloud);


/**
* 获取Cloud信息
* @param [IN]  lpUserID               用户登录ID
* @param [OUT]  pstCloudInfo        Cloud信息
* @return TRUE表示成功,其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetNetWorkCloudInfo(IN LPVOID lpUserID,
                                                                OUT LPNETDEV_NETWORK_CLOUD_INFO_S pstCloudInfo);

/**
* 设置Cloud状态
* @param [IN]  lpUserID               用户登录ID
* @param [IN]  pstCloudInfo          Cloud信息 输入使能字段
* @return TRUE表示成功,其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetNetWorkCloudInfo(IN LPVOID lpUserID, 
                                                                IN LPNETDEV_NETWORK_CLOUD_INFO_S pstCloudInfo);

/**
* 获取视频分发服务器信息
* @param [IN]  lpUserID         用户登录
* @param [OUT]  pstCDNSrvInfo   CDN服务器信息
* @return TRUE表示成功,其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCDNSrvInfo(IN LPVOID lpUserID, 
                                                          OUT LPNETDEV_CDN_SRV_INFO_S pstCDNSrvInfo);

/**
* 获取视频分发服务器配置信息
* @param [IN]   lpUserID    用户登录
* @param [OUT]  pstCDNRule  CDN配置信息
* @return TRUE表示成功,其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCDNRule(IN LPVOID lpUserID, 
                                                       OUT LPNETDEV_CDN_RULE_S pstCDNRule);

/**
* 查询视频分发通道列表信息
* @param [IN]  lpUserID             用户登录ID
* @param [IN]  pstAlarmFindCond     告警查询条件
* @return 告警查询业务号,返回NETDEV_E_FAILED表示失败，其他值作为NETDEV_CloseFindAlarm等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCDNChlList(IN LPVOID lpUserID);

/**
* 逐个获取查找到的分发通道信息
* @param [IN]  lFindHandle      日志查找句柄
* @param [OUT] pstCDNChlInfo    保存分发通道信息
* @return NETDEV_E_SUCCEED表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCDNChlInfo(IN LPVOID lpFindHandle,
                                                               OUT LPNETDEV_CDN_CHL_INFO_S pstCDNChlInfo);

/**
* 关闭分发通道信息查询，释放资源
* @param [IN]  lFindHandle  文件查找句柄
* @return NETDEV_E_SUCCEED表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCDNChlInfo(IN LPVOID lpFindHandle);


/*                   配置模块结束行                              */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif











////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_BASIC
/************************************************************************/
/*                  包含基础管理业务模块                         */
/************************************************************************/

/**
* 获取告警联动抓图URL
* @param [IN]  lpUserID                     用户登录
* @param [IN]  pstAlarmSnapShotCond         告警抓图获取条件
* @return  查询句柄,返回NULL表示失败，其他值作为NETDEV_GetNextAlarmSnapShotURL、NETDEV_CloseGetAlarmSnapShotURL等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindAlarmSnapShotURL(IN LPVOID lpUserID,
                                                                   IN LPNETDEV_ALARM_SNAPSHOT_COND_S pstAlarmSnapShotCond);

/**
* 获取下一张图片信息
* @param [IN]  lpFindHandle                     查询句柄
* @param [OUT]  pstAlarmPicInfo         告警抓图图片信息
* @return  TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextAlarmSnapShotURL(IN LPVOID lpFindHandle,
                                                                     OUT LPNETDEV_ALARM_SNAPSHOT_PIC_S pstAlarmPicInfo);

/**
* 关闭告警联动抓图FindHandle
* @param [IN]  lpFindHandle                     查询句柄
* @return  TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseAlarmSnapShotURL(IN LPVOID lpFindHandle);

/**
* 保存告警抓图
* @param [IN]  lpUserID                     用户登录
* @param [IN]  pstPicFileInfo           告警图片信息
* @return  TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SaveSnapShotFile(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PIC_FILE_INFO_S pstPicFileInfo);

/**
* 查询组织信息列表
* @param [IN] lpUserID          用户登录ID
* @param [IN] pstFindCond       查找组织信息列表条件
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextOrgInfo、NETDEV_FindCloseOrgInfo等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindOrgInfoList(IN LPVOID lpUserID, 
                                                              IN LPNETDEV_ORG_FIND_COND_S pstFindCond);

/**
* 逐个获取查找到的组织信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstOrgInfo                   保存组织信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextOrgInfo(IN LPVOID lpFindHandle, 
                                                            OUT LPNETDEV_ORG_INFO_S pstOrgInfo);

/**
* 关闭查找 组织信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseOrgInfo(IN LPVOID lpFindHandle);


/**
* 添加组织
* @param [IN] lpUserID              用户登录ID
* @param [IN] pstOrgInfo            组织信息指针
* @param [OUT] dwOrgID             组织ID
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddOrgInfo(IN LPVOID lpUserID, 
                                                       IN LPNETDEV_ORG_INFO_S pstOrgInfo, 
                                                       OUT INT32 *dwOrgID);
/**
* 修改组织
* @param [IN] lpUserID              用户登录ID
* @param [IN] dwOrgID              组织ID
* @param [IN] pstOrgInfo            组织信息指针
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyOrgInfo(IN LPVOID lpUserID,
                                                          IN LPNETDEV_ORG_INFO_S pstOrgInfo);

/**
* 批量删除组织
* @param [IN] lpUserID             用户登录ID
* @param [IN] pstOrgDelInfo       待删除组织信息指针
* @param [OUT] pstOrgDelResultInfo  删除组织响应信息指针
* @return TRUE           表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_BatchDeleteOrgInfo(IN LPVOID lpUserID,
                                                               IN LPNETDEV_DEL_ORG_INFO_S pstOrgDelInfo, 
                                                               OUT LPNETDEV_ORG_BATCH_DEL_INFO_S pstOrgDelResultInfo);

/**
* 通过组织ID查询通道信息列表
* @param [IN] lpUserID          用户登录ID
* @param [IN] dwOrgID           组织ID
* @param [IN] dwChnType         通道类型，参见#NETDEV_CHN_TYPE_E
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextOrgChn、NETDEV_FindCloseOrgChn等函数的参数。
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindOrgChnList(IN LPVOID lpUserID, 
                                                             IN INT32 dwOrgID,
                                                             IN INT32 dwChnType
                                                             );

/**
* 逐个获取查找到的 组织通道 信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstOrgChnInfo                保存 组织通道 信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextOrgChn(IN LPVOID lpFindHandle, 
                                                           OUT LPNETDEV_ORG_CHN_INFO_S pstOrgChnInfo);

/**
* 关闭查找 组织通道信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseOrgChn(IN LPVOID lpFindHandle);

/**
* 根据组织ID获取通道
* @param [IN] lpUserID             用户登录ID
* @param [IN] dwOrgID              组织ID
* @param [OUT] pstOrgChnShortInfo  组织下通道信息指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 该接口需要调用两次
*       第一次获取通道数量 并返回NETDEV_E_NEED_MORE_MEMORY错误码
*       第二次根据数量进行动态内存分配后，再次调用获取通道ID
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetOrgChnInfo(IN LPVOID lpUserID, 
                                                          IN INT32 dwOrgID,
                                                          OUT LPNETDEV_ORG_CHN_SHORT_INFO_S pstOrgChnShortInfo);
/**
* 根据组织ID修改通道
* @param [IN] lpUserID              用户登录ID
* @param [IN] pstOrgChnShortInfo      组织下通道信息指针
* @return TRUE              表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyOrgChnInfo(IN LPVOID lpUserID,
                                                             IN LPNETDEV_ORG_CHN_SHORT_INFO_S pstOrgChnShortInfo);


/*                   基础管理模块结束行                           */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif












////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_VMS
/************************************************************************/
/*                  包含一体机业务模块                            */
/************************************************************************/

/**
* 根据通道类型和通道ID获取通道详细信息
* @param [IN] lpUserID              用户登录ID
* @param [IN] dwChnID               通道ID
* @param [IN] dwChnType             通道类型,参见# NETDEV_CHN_TYPE_E
* @param [OUT] lpOutBuffer          接收数据的缓冲指针
* @param [IN] dwOutBufferSize       接收数据的缓冲长度(以字节为单位)，不能为0
* @param [OUT] pdwBytesReturned     实际收到的数据长度指针，不能为NULL
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetChnDetailByChnType(IN LPVOID lpUserID, 
                                                                  IN INT32 dwChnID,
                                                                  IN INT32 dwChnType,
                                                                  OUT LPVOID lpOutBuffer, 
                                                                  IN INT32  dwOutBufferSize,
                                                                  OUT INT32  *pdwBytesReturned);

/*                   一体机模块结束行                           */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_SMART
/************************************************************************/
/*                  包含智能业务模块                              */
/************************************************************************/

/************************************************************************/
/*                     客流量统计                                 */
/************************************************************************/

/**
* 订阅智能事件
* @param [IN] lpUserID              用户登录ID
* @param [IN] pstSubscribeInfo      订阅信息
* @param [INOUT] pstSmartInfo       智能事件信息，成功返回订阅ID
* @return TRUE表示成功，其他表示失败
* @note   订阅前需要先调用NETDEV_SetAlarmCallBack接口注册回调函数
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SubscribeSmart(IN LPVOID lpUserID, 
                                                           IN LPNETDEV_SUBSCRIBE_SMART_INFO_S pstSubscribeInfo,
                                                           INOUT LPNETDEV_SMART_INFO_S pstSmartInfo);

/**
* 取消订阅智能事件
* @param [IN] lpUserID            用户登录ID
* @param [IN] pstSmartInfo         智能事件
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_UnsubscribeSmart(IN LPVOID lpUserID,
                                                             IN LPNETDEV_SMART_INFO_S pstSmartInfo);

/**
 * 客流量统计消息回调函数  Callback function for passenger flow statistic message
 * @param [IN] lpUserID                用户登录句柄 User login ID
 * @param [IN] pstPassengerFlowData    客流量数据 Passenger flow data
 * @param [IN] lpUserData              用户数据   User data
 * @note 无 None
 */
typedef void (STDCALL *NETDEV_PassengerFlowStatisticCallBack_PF)(IN LPVOID lpUserID,
                                                                 IN LPNETDEV_PASSENGER_FLOW_STATISTIC_DATA_S pstPassengerFlowData,
                                                                 IN LPVOID lpUserData);

/**
 * 注册客流量统计上报回调函数 Register callback function that used for count passenger flow
 * @param [IN] lpUserID                 用户登录句柄  User login ID
 * @param [IN] cbPassengerFlowStatisticCallBack    需要注册的回调函数  Callback function which will be registered
 * @param [IN] lpUserData                用户数据  User data
 */
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPassengerFlowStatisticCallBack(IN LPVOID lpUserID, 
                                                                              IN NETDEV_PassengerFlowStatisticCallBack_PF cbPassengerFlowStatisticCallBack, 
                                                                              IN LPVOID lpUserData);


/**
* 获取客流量统计 Obtain traffic statistic
* @param [IN]   lpUserID                用户登录句柄 User login ID
* @param [OUT]  pstPeopleCounter        客流量统计列表 People counting list
* @return TRUE表示成功,其他表示失败 TRUE means success, any other value indicates failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetTrafficStatistic(IN LPVOID lpUserID,
                                                                IN LPNETDEV_TRAFFIC_STATISTICS_COND_S pstStatisticCond,
                                                                OUT LPNETDEV_TRAFFIC_STATISTICS_DATA_S pstTrafficStatistic);

/**
* 清零客流量人数统计 eset people counting
* @param [IN]   lpUserID             用户登录句柄 User login ID
* @param [IN]   dwChannelID          通道号 Channel ID
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetPassengerFlow(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID);


/**
* 获取客流量上报时间间隔
* @param [IN] lpUserID
* @param [IN] dwChannelID               通道号
* @param [OUT] pstReportTimeValue           客流量上报时间
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetTrafficStatisticReportTime(IN LPVOID lpUserID, 
                                                                          IN INT32 dwChannelID,
                                                                          OUT LPNETDEV_TRAFFIC_STATISTICS_REPORT_TIME_S pstReportTimeValue);

/**
* 开始客流量统计查询 
* @param [IN]  lpUserID                用户登录ID
* @param [IN]  pstStatisticCond        客流量统计结构体
* @param [OUT] pudwSearchID            客流量查询ID
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartTrafficStatistic(IN LPVOID lpUserID,
                                                                  IN LPNETDEV_TRAFFIC_STATISTICS_COND_S pstStatisticCond,
                                                                  OUT UINT32* pudwSearchID);

/**
* 获取客流量统计信息列表
* @param [IN] lpUserID                用户登录ID
* @param [IN] udwSearchID             客流量查询ID
* @return 查询句柄(作为NETDEV_FindNextTrafficStatisticInfo, NETDEV_FindCloseTrafficStatisticInfo)，NULL表示失败
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindTrafficStatisticInfoList(IN LPVOID lpUserID,
                                                                           IN UINT32 udwSearchID);

/**
* 逐个查询获取到的客流量信息
* @param [IN] lpFindHandle                查找句柄
* @param [OUT] pstStatisticInfo           客流量查询信息
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextTrafficStatisticInfo(IN LPVOID lpFindHandle,
                                                                         OUT LPNETDEV_TRAFFIC_STATISTICS_INFO_S pstStatisticInfo);

/**
* 关闭查找，释放资源
* @param [IN] lpFindHandle
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseTrafficStatisticInfo(IN LPVOID lpFindHandle);

/**
* 获取客流量统计进度
* @param [IN]  lpUserID               用户登录ID
* @param [IN]  udwSearchID            客流量查询ID
* @param [OUT] pudwProgress           客流量统计进度
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetTrafficStatisticProgress(IN LPVOID lpUserID,
                                                                        IN UINT32 udwSearchID,
                                                                        OUT UINT32* pudwProgress);

/**
* 多通道开始客流量统计查询 
* @param [IN] lpUserID                用户登录ID
* @param [IN] pstStatisticCond        客流量统计结构体
* @param [OUT] pudwSearchID           客流量查询ID
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartMultiTrafficStatistic(IN LPVOID lpUserID,
                                                                       IN LPNETDEV_MULTI_TRAFFIC_STATISTICS_COND_S pstStatisticCond,
                                                                       OUT UINT32* pudwSearchID);

/**
* 停止客流量查询
* @param [IN] lpUserID                        用户登录ID
* @param [IN] udwSearchID                     客流量查询ID
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopTrafficStatistic(IN LPVOID lpUserID, 
                                                                 IN UINT32 udwSearchID);



/************************************************************************/
/*                     人脸抓拍                                   */
/************************************************************************/

typedef enum tagNETDEVListenType
{
    NETDEV_FACE_SNAPSHOT_TYPE       = 1,
    NETDEV_PASSENGER_FLOW_TYPE      = 2,

    NETDEV_LISTEN_TYPE_INVALID      = 0xffff
}NETDEV_LISTEN_TYPE_E;
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetListenPort(IN INT32 dwListenType,
                                                          IN INT32 dwPort);


/**
 * 人脸抓拍消息回调函数
 * @param [IN] lpUserID                用户登录句柄 User login ID
 * @param [IN] pstFaceSnapShotData     人脸抓拍数据
 * @param [IN] lpUserData              用户数据   User data
 * @note 无 None
 */
typedef void (STDCALL *NETDEV_FaceSnapshotCallBack_PF)(IN LPVOID lpUserID,
                                                       IN LPNETDEV_TMS_FACE_SNAPSHOT_PIC_INFO_S pstFaceSnapShotData,
                                                       IN LPVOID lpUserData);

/**
 * 注册人脸抓拍上报回调函数
 * @param [IN] lpUserID                 用户登录句柄  User login ID
 * @param [IN] cbFaceSnapshotCallBack    需要注册的回调函数  Callback function which will be registered
 * @param [IN] lpUserData                用户数据  User data
 */
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetFaceSnapshotCallBack(IN LPVOID lpUserID, 
                                                                    IN NETDEV_FaceSnapshotCallBack_PF cbFaceSnapshotCallBack, 
                                                                    IN LPVOID lpUserData);

/************************************************************************/
/*                     热度图                                     */
/************************************************************************/
/**
 * 热度图消息回调函数
 * @param [IN] lpUserID                用户登录句柄 User login ID
 * @param [IN] pstHeatMapData          热度图数据
 * @param [IN] lpUserData              用户数据   User data
 * @note 无 None
 */

typedef void (STDCALL *NETDEV_HeatMapCallBack_PF)(IN LPVOID lpUserID,
                                                  IN LPNETDEV_TMS_HEAT_MAP_INFO_S pstHeatMapData,
                                                  IN LPVOID lpUserData);

/**
 * 注册热度图上报回调函数
 * @param [IN] lpUserID                  用户登录句柄  User login ID
 * @param [IN] cbHeatMapCallBack         需要注册的回调函数  Callback function which will be registered
 * @param [IN] lpUserData                用户数据  User data
 */
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetHeatMapCallBack (IN LPVOID lpUserID, 
                                                                IN NETDEV_HeatMapCallBack_PF cbHeatMapCallBack, 
                                                                IN LPVOID lpUserData);


/************************************************************************/
/*                     车牌识别                                   */
/************************************************************************/
/**
* 车牌识别消息回调函数
* @param [IN] lpUserID                用户登录句柄 User login ID
* @param [IN] pstHeatMapData          车牌识别数据
* @param [IN] lpUserData              用户数据   User data
* @note 无 None
*/
typedef void (STDCALL *NETDEV_CarPlateCallBack_PF)(IN LPVOID lpUserID,
                                                   IN LPNETDEV_TMS_CAR_PLATE_INFO_S pstCarPlateData,
                                                   IN LPVOID lpUserData);

 /**
 * 注册车牌识别上报回调函数
 * @param [IN] lpUserID                  用户登录句柄  User login ID
 * @param [IN] cbCarPlateCallBack         需要注册的回调函数  Callback function which will be registered
 * @param [IN] lpUserData                用户数据  User data
 */
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetCarPlateCallBack(IN LPVOID lpUserID, 
                                                                IN NETDEV_CarPlateCallBack_PF cbCarPlateCallBack, 
                                                                IN LPVOID lpUserData
                                                                );


/************************************************************************/
/*                      超感信息                                  */
/************************************************************************/
/**
* 获取设备定位信息 Obtain geolocation info
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   dwChannelID             通道号  Channel ID
* @param [OUT]  pstGPSInfo              定位信息 Geolocation info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetGeolocationInfo(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID,
                                                               OUT LPNETDEV_GEOLACATION_INFO_S pstGPSInfo);

/**
* 获取wifi sniffer MAC地址信息 Obtain wifi sniffer mac list
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   dwChannelID             通道号  Channel ID
* @param [OUT]  pstMACList              Wifi sniffer Mac地址数组 Wifi sniffer Mac address array
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetWifiSnifferMacList(IN LPVOID lpUserID,
                                                                  IN INT32 dwChannelID,
                                                                  OUT LPNETDEV_WIFISNIFFER_MAC_LIST_S pstMACList);

/**
* 获取设备电子罗盘信息 Obtain compass info
* @param [IN]   lpUserID                用户登录ID User login ID
* @param [IN]   dwChannelID             通道号  Channel ID
* @param [OUT]  pfCompassInfo           电子罗盘信息（与正北的夹角）Electronic compass info
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCompassInfo(IN LPVOID lpUserID,
                                                           IN INT32 dwChannelID,
                                                           OUT FLOAT *pfCompassInfo);


/************************************************************************/
/*                     人脸识别                                   */
/************************************************************************/
/**
* 接收人脸识别告警消息的回调函数 Callback function to receive alarm information
* @param [IN] lpUserID                用户登录ID
* @param [IN] pstFaceAlarmReportInfo  上报信息 Alarm information
* @param [IN] lpBuf                   缓冲区指针 Pointer to buffer
* @param [IN] dwBufLen                告警信息对应结构体的长度 Length of structure for alarm information
* @param [IN] dwBufLen                用户数据 User data
* @note   在回调函数中只能做拷贝数据动作，否则若耗时过长，容易造成告警上报阻塞、内存消耗过大等问题
*/
typedef void(STDCALL *NETDEV_FaceAlarmMessCallBack_PF)(IN LPVOID lpUserID,
                                                       IN LPNETDEV_FACE_RECORD_SNAPSHOT_INFO_S pstFaceAlarmReportInfo,
                                                       IN LPVOID    lpBuf,
                                                       IN INT32     dwBufLen,
                                                       IN LPVOID    lpUserData
                                                       );

/**
* 注册人脸识别报警消息回调函数
* Register callback function and receive alarm information, etc.
* @param [IN] lpUserID                  用户登录ID User login ID
* @param [IN] cbFaceAlarmMessCallBack   回调函数 Callback function
* @param [IN] lpUserData                用户数据 User data
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetFaceAlarmCallBack(IN LPVOID lpUserID,
                                                                 IN NETDEV_FaceAlarmMessCallBack_PF cbFaceAlarmMessCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );


/**
* 创建人员库信息                                Create Person libraries information
* @param [IN]  lpUserID                         用户登录句柄 User login ID
* @param [IN]  pstLibraryList                   人员库信息 Person library information
* @param [OUT]  *pudwID                         创建库生成的库ID create library generated libry ID
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CreatePersonLibInfo(IN LPVOID lpUserID, 
                                                                IN LPNETDEV_LIB_INFO_S pstPersonLibInfo, 
                                                                OUT UINT32 *pudwID);

/**
* 修改人员库信息  Modify Person libraries information
* @param [IN]  lpUserID         用户登录句柄 User login ID
* @param [IN]  pstLibraryList   人员库信息 Person library information
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyPersonLibInfo(IN LPVOID lpUserID, 
                                                                IN LPNETDEV_PERSON_LIB_LIST_S pstPersonLibList);


/**
* 删除指定的人员库    Delete designated Person libraries information
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @param [IN]  udwPersonLibID   人员库ID Person library ID
* @param [IN]  pstFlagInfo   人员库删除标志
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeletePersonLibInfo(IN LPVOID lpUserID, 
                                                                IN UINT32 udwPersonLibID,
                                                                IN LPNETDEV_DELETE_DB_FLAG_INFO_S pstFlagInfo);

/**
* 新增指定的人员信息 Add designated Person information
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  udwPersonLibID       人员库ID Person library ID
* @param [IN]  pstPersonInfoList    人员信息列表 Person information list
* @param [OUT]  pstPersonResultList 人员信息结果列表 Person information result list
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddPersonInfo(IN LPVOID lpUserID, 
                                                          IN UINT32 udwPersonLibID, 
                                                          IN LPNETDEV_PERSON_INFO_LIST_S pstPersonInfoList, 
                                                          OUT LPNETDEV_PERSON_RESULT_LIST_S pstPersonResultList);

/**
* 修改指定的人员信息 Modify designated Person information
* @param [IN]  lpUserID             用户登录句柄 User login ID
* @param [IN]  udwPersonLibID       人员库ID Person library ID
* @param [IN]  pstPersonInfoList    人员信息列表 Person information list
* @param [OUT]  pstPersonResultList 人员信息结果列表 Person information result list
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyPersonInfo(IN LPVOID lpUserID, 
                                                             IN UINT32 udwPersonLibID, 
                                                             IN LPNETDEV_PERSON_INFO_LIST_S pstPersonInfoList, 
                                                             OUT LPNETDEV_PERSON_RESULT_LIST_S pstPersonResultList);

/**
* 批量删除人员信息
* @param [IN] lpUserID             用户登录ID
* @param [IN] udwPersonLibID       人脸库ID
* @param [IN] pstIDList            人脸成员列表
* @param [OUT] pstBatchList        批量操作返回信息
* @return 查询句柄,返回0表示失败，
* @note 仅VMS支持
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeletePersonInfoList(IN LPVOID lpUserID, 
                                                                 IN UINT32 udwPersonLibID, 
                                                                 IN LPNETDEV_BATCH_OPERATE_MEMBER_LIST_S pstIDList, 
                                                                 OUT LPNETDEV_BATCH_OPERATOR_LIST_S pstResutList);


/**
* 删除指定的人员信息 Delete designated Person information
* @param [IN]  lpUserID         用户登录句柄 User login ID
* @param [IN]  udwPersonLibID   人员库ID Person library ID
* @param [IN]  udwPersonID      人员ID Person ID
* @param [IN]  udwLastChange    最后修改时间 Last modify time
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeletePersonInfo(IN LPVOID lpUserID, 
                                                             IN UINT32 udwPersonLibID, 
                                                             IN UINT32 udwPersonID, 
                                                             IN UINT32 udwLastChange);

/**
* 查询所有布控任务
* @param [IN]  lpUserID              用户登录ID
* @param [IN]  udwChannelID          通道ID，仅NVR查询通道布控信息时使用
* @param [IN]  pstQueryInfo          查询条件，仅NVR支持
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextMonitorInfo、NETDEV_FindCloseMonitorInfo等函数的参数。
* @note    
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindMonitorList(IN LPVOID lpUserID, 
                                                              IN UINT32 udwChannelID, 
                                                              IN LPNETDEV_MONITOR_QUERY_INFO_S pstQueryInfo);

/**
* 逐个获取查找到的 布控任务 信息
* @param [IN]  lpFindHandle            查找句柄 
* @param [OUT] pstMonitorInfo          保存 布控任务 信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextMonitorInfo(IN LPVOID lpFindHandle, 
                                                                OUT LPNETDEV_FACE_MONITION_INFO_S pstMonitorInfo);

/**
* 关闭查找 布控任务，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseMonitorList(IN LPVOID lpFindHandle);


/**
* 新增单个布控任务 
* @param [IN]  lpUserID                      用户登录ID 
* @param [INOUT] pstMonitorInfo              保存 布控任务 信息的指针  成功返回布控任务序号
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_AddMonitorInfo(IN LPVOID lpUserID, 
                                                           INOUT LPNETDEV_FACE_MONITION_INFO_S pstMonitorInfo);

/**
* 删除单个布控任务 
* @param [IN]  lpUserID                      用户登录ID 
* @param [IN] udwID                          布控ID
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_DeleteMonitorInfo(IN LPVOID lpUserID, IN UINT32 udwID);

/**
* 查询单个布控任务配置信息
* @param [IN]  lpUserID                    用户登录ID 
* @param [INOUT] pstMonitorInfo            保存 布控任务 信息的指针，输入布控ID，成功返回配置信息
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMonitorRuleInfo(IN LPVOID lpUserID, 
                                                               INOUT LPNETDEV_FACE_MONITION_INFO_S pstMonitorInfo);


/**
* 设置单个布控任务配置信息
* @param [IN]  lpUserID                    用户登录ID 
* @param [IN] pstMonitorInfo               保存 布控任务 信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetMonitorRuleInfo(IN LPVOID lpUserID, 
                                                               IN LPNETDEV_FACE_MONITION_INFO_S pstMonitorInfo);


/**
* 查询所有人员库的容量信息
* @param [IN]  lpUserID     用户登录句柄 User login ID
* @param [IN]   dwTimeOut              连接超时时间
* @param [OUT]  pstCapacityList   所有人员库的容量信息
* @return TRUE表示成功,其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetPersonLibCapacity(IN LPVOID lpUserID,
                                                                 IN INT32 dwTimeOut,
                                                                 OUT LPNETDEV_PERSON_LIB_CAP_LIST_S pstCapacityList);

/**
* 条件查询人员信息
* @param [IN] lpUserID 用户登录句柄
* @param [IN] udwPersonLibID 人员库ID
* @param [IN] pstQueryInfo 人脸信息查询条件
* @param [OUT] pstQueryResultInfo 人脸信息查询返回结果
* @return 查询句柄,返回0表示失败，其他值作为NETDEV_FindNextPersonInfo、NETDEV_FindClosePersonInfoList等函数的参数
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindPersonInfoList(IN LPVOID lpUserID, 
                                                                 IN UINT32 udwPersonLibID,
                                                                 IN LPNETDEV_PERSON_QUERY_INFO_S pstQueryInfo, 
                                                                 OUT LPNETDEV_BATCH_OPERATE_BASIC_S pstQueryResultInfo);

/**
* 逐个获取查找到的 人员 信息
* @param [IN]  lpFindHandle            查找句柄 
* @param [OUT] pstPersonInfo          保存 人员信息的指针
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note 返回失败说明查询结束 A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextPersonInfo(IN LPVOID lpFindHandle, 
                                                               OUT LPNETDEV_PERSON_INFO_S pstPersonInfo);

/**
* 关闭查找 人员信息，释放资源
* @param [IN] lpFindHandle  文件查找句柄 
* @return TRUE表示成功，其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindClosePersonInfoList(IN LPVOID lpFindHandle);

/**
* 接收人脸告警消息的回调函数          Callback function to receive alarm information
* @param [IN] lpUserID                用户登录句柄 User login ID
* @param [IN] pstAlarmData            告警信息 Alarm information
* @param [IN] lpUserData              用户数据 User data
* @note
*/
typedef void(STDCALL *NETDEV_PersonAlarmMessCallBack_PF)(IN LPVOID lpUserID,
                                                         IN LPNETDEV_ALARM_INFO_EX_S pstAlarmInfo,
                                                         IN LPNETDEV_PERSON_EVENT_INFO_S pstAlarmData,
                                                         IN LPVOID    lpUserData
                                                         );

/**
* 注册速人脸报警消息回调函数（同时回调登录ID,用以区分不同设备） Register callback function and receive alarm information, etc. (Call back login ID at the same time to distinguish different devices)
* @param [IN] lpUserID                   用户登录句柄 User login ID
* @param [IN] cbAlarmMessCallBack        回调函数 Callback function
* @param [IN] lpUserData                 用户数据 User data
* @param [IN] pstFGSubInfo               速通门订阅信息 Speed door subscription information
* @param [OUT] pstFGSubSuccInfo          速通门订阅信息成功返回信息 Subscription succ return information 
* @return TRUE表示成功,其他表示失败 TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPersonAlarmCallBack(IN LPVOID lpUserID,
                                                                   IN NETDEV_PersonAlarmMessCallBack_PF cbAlarmMessCallBack,
                                                                   IN LPVOID lpUserData
                                                                   );

/**
* 订阅人脸告警
* @param [IN] lpUserID                                      用户登录句柄
* @param IN LPNETDEV_PERSON_SUB_INFO_S pstSubInfo           人脸告警订阅信息
* @param OUT LPNETDEV_SUBSCRIBE_SUCC_INFO_S pstSubSuccInfo  订阅成功返回信息
* @return TRUE表示成功,其他表示失败 
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SubPersonAlarm(IN LPVOID lpUserID,
                                                           IN LPNETDEV_PERSON_SUB_INFO_S pstSubInfo,
                                                           OUT LPNETDEV_SUBSCRIBE_SUCC_INFO_S pstSubSuccInfo
                                                           );

/**
* 取消订阅人脸告警
* @param [IN] lpUserID               用户登录句柄
* @param [IN] UINT32 udwID           人脸告警订阅ID
* @return TRUE表示成功,其他表示失败 
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_UnSubPersonAlarm(IN LPVOID lpUserID, IN UINT32 udwID);

/*                   智能业务模块结束行                        */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NETDEV_WITH_XW
/************************************************************************/
/*                  包含电视墙、拼接模块                          */
/************************************************************************/

/**
* 获取能力集
* @param [IN]  lpUserID                     用户登录ID
* @param [OUT] pstCapInfo                   电视墙信息结构体指针
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetCapability(IN LPVOID lpUserID, 
                                                             OUT LPNETDEV_XW_CAP_INFO_S pstCapInfo);

/**
* 获取视频通道信息列表
* @param [IN]  lpUserID                     用户登录ID
* @param [INOUT] pstChannelsList            编码通道信息，通道数量为输入信息，通道信息为输出信息，内存由调用者分配
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetChannelsInfoList(IN LPVOID lpUserID,
                                                                   INOUT LPNETDEV_XW_CHANNELS_LIST_S pstChannelsList);


/**
* 获取最新摘要字
* @param [IN]  lpUserID                     用户登录ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetLastChange(IN LPVOID lpUserID, 
                                                             OUT UINT32 *pudwLastChange);


/**
* 获取本地编码通道数量
* @param [IN]  lpUserID                     用户登录ID
* @param [OUT] pstChannels                    通道数量
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetChannelsNum(IN LPVOID lpUserID, 
                                                              OUT LPNETDEV_XW_CHANNELS_NUM_S pstChannels);

/**
* 清空所有配置
* @param [IN]  lpUserID                     用户登录ID
* @return TRUE表示成功，其他表示失败
* @note（所有配置包括电视墙、场景、窗口、虚拟LED、底图绑定关系、业务绑定关系）
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteAllCfg(IN LPVOID lpUserID);

/**
* 获取电视墙配置列表
* @param [IN] lpUserID                      用户登录ID
* @return 查询句柄,返回NULL表示失败，其他值作为NETDEV_XW_FindNextTVWallCfg、NETDEV_XW_FindCloseTVWallCfg等函数的参数。
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_XW_FindTVWallCfgList(IN LPVOID lpUserID);

/**
* 逐个获取查找到的电视墙配置信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstTVWallCfg                 保存电视墙配置信息的指针 
* @return TRUE表示成功，其他表示失败
* @note 返回失败说明查询结束
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindNextTVWallCfg(IN LPVOID lpFindHandle,
                                                                 OUT LPNETDEV_XW_TVWALL_CFG_S pstTVWallCfg);

/**
* 关闭查找 窗口视频源信息，释放资源
* @param [IN] lpFindHandle                  文件查找句柄 File search handle
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindCloseTVWallCfg(IN LPVOID lpFindHandle);

/**
* 获取单个电视墙布局配置信息
* @param [IN]    lpUserID        用户登录ID
* @param [IN]    udwTVWallID      电视墙ID
* @param [OUT]   pstTVWallCfg    电视墙信息结构体指针
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetTVWallCfg(IN LPVOID lpUserID,
                                                            IN UINT32 udwTVWallID,
                                                            OUT LPNETDEV_XW_TVWALL_CFG_S pstTVWallCfg);

/**
* 创建电视墙配置
* @param [IN]  lpUserID                     用户登录ID
* @param [INOUT] pstTVWallCfg               电视墙信息结构体指针,设备端创建成功后返回电视墙ID
* @param [OUT]   pudwLastChange             摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_CreateTVWallCfg(IN LPVOID lpUserID, 
                                                               INOUT LPNETDEV_XW_TVWALL_CFG_S pstTVWallCfg,
                                                               OUT UINT32 *pudwLastChange);

/**
* 修改电视墙配置
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  pstTVWallCfg                 电视墙信息结构体指针，结构体中需要输入电视墙ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ModifyTVWallCfg(IN LPVOID lpUserID,
                                                               IN LPNETDEV_XW_TVWALL_CFG_S pstTVWallCfg,
                                                               OUT UINT32 *pudwLastChange);

/**
* 删除电视墙配置
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteTVWallCfg(IN LPVOID lpUserID, 
                                                               IN UINT32 udwTvWallID,
                                                               OUT UINT32 *pudwLastChange);

/**
* 获取场景配置列表
* @param [IN] lpUserID                      用户登录ID
* @param [IN] udwTvWallID                   电视墙ID
* @return 查询句柄,返回NULL表示失败，其他值作为NETDEV_XW_FindNextSceneCfg、NETDEV_XW_FindCloseSceneCfg等函数的参数。
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_XW_FindSceneCfgList(IN LPVOID lpUserID,
                                                                  IN UINT32 udwTvWallID);

/**
* 逐个获取查找到的场景配置信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstSceneShortInfo            保存简要场景信息的指针 
* @return TRUE表示成功，其他表示失败
* @note 返回失败说明查询结束
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindNextSceneCfg(IN LPVOID lpFindHandle,
                                                                OUT LPNETDEV_XW_SCENE_INFO_BASIC_S pstSceneShortInfo);

/**
* 关闭查找场景，释放资源
* @param [IN] lpFindHandle                  文件查找句柄
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindCloseSceneCfg(IN LPVOID lpFindHandle);

/**
* 获取场景信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwSceneID                   场景ID
* @param [INOUT] pstSceneDetailInfo           场景详细信息结构体指针
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetSceneInfo(IN LPVOID lpUserID, 
                                                            IN UINT32 udwSceneID,
                                                            INOUT LPNETDEV_XW_SCENE_INFO_DETAIL_S pstSceneDetailInfo);


/**
* 创建单个场景信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [INOUT] pstSceneBase               输入场景名称，输出场景ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note   输入场景名称新建场景，场景的其他数据为当前场景的数据
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_CreateSceneInfo(IN LPVOID lpUserID, 
                                                               IN UINT32 udwTvWallID,
                                                               INOUT LPNETDEV_XW_SCENE_INFO_BASE_S pstSceneBase,
                                                               OUT UINT32 *pudwLastChange);

/**
* 修改场景信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [INOUT]  pstSceneModifyInfo           修改信息
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ModifySceneInfo(IN LPVOID lpUserID,
                                                               IN UINT32 udwTvWallID,
                                                               INOUT LPNETDEV_XW_SCENE_MODIFY_INFO_S pstSceneModifyInfo,
															   OUT UINT32 *pudwLastChange);

/**
* 删除场景信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [IN]  udwSceneID                   场景ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteSceneInfo(IN LPVOID lpUserID, 
                                                               IN UINT32 udwTvWallID, 
                                                               IN UINT32 udwSceneID, 
                                                               OUT UINT32 *pudwLastChange);

/**
* 获取当前场景的关联场景
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [OUT] pudwSceneID                  场景ID
* @return TRUE表示成功，其他表示失败
* @note 获取时，返回当前场景所关联的场景ID；
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetCurrentSceneID(IN LPVOID lpUserID, 
                                                                 IN UINT32 udwTvWallID,
                                                                 OUT UINT32 *pudwSceneID);

/**
* 切换为当前场景
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [IN]  udwSceneID                   场景ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note 设置时，表明把该场景ID设置为当前关联场景ID，并用该场景的配置覆盖当前场景的配置；
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_SetCurrentSceneID(IN LPVOID lpUserID, 
                                                                 IN UINT32 udwTvWallID,
                                                                 IN UINT32 udwSceneID,
                                                                 OUT UINT32 *pudwLastChange);

/**
* 获取当前场景配置内容
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [OUT] pstSceneDetailInfo           场景信息
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetCurrentSceneInfo(IN LPVOID lpUserID, 
                                                                   IN UINT32 udwTvWallID, 
                                                                   OUT LPNETDEV_XW_SCENE_INFO_DETAIL_S pstSceneDetailInfo);

/**
* 删除当前场景配置内容
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  dwTimeOut                    超时时间(秒)  范围10s~60s
* @param [IN]  udwTvWallID                  电视墙ID
* @return TRUE表示成功，其他表示失败
* @note 删除当前场景下的窗口、窗口下的当前业务/业务绑定关系、虚拟LED、底图的绑定
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteCurrentSceneInfo(IN LPVOID lpUserID,
                                                                      IN INT32 dwTimeOut,
                                                                      IN UINT32 udwTvWallID); 

/**
* 获取场景计划
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [OUT] pstScenePlan                 场景计划结构体指针
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetScenePlan(IN LPVOID lpUserID, 
                                                            IN UINT32 udwTvWallID,
                                                            OUT LPNETDEV_XW_SCENE_PLAN_S pstScenePlan);

/**
* 设置场景计划
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [IN]  pstScenePlan                 场景计划结构体指针
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_SetScenePlan(IN LPVOID lpUserID, 
                                                            IN UINT32 udwTvWallID, 
                                                            IN LPNETDEV_XW_SCENE_PLAN_S pstScenePlan,
                                                            OUT UINT32 *pudwLastChange);

/**
* 获取场景下所有窗口配置信息
* @param [IN] lpUserID                      用户登录ID
* @param [IN] udwTvWallID                   电视墙ID
* @return 查询句柄,返回NULL表示失败，其他值作为NETDEV_XW_FindNextWndInfo、NETDEV_XW_FindCloseWndInfo等函数的参数。
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_XW_FindWndList(IN LPVOID lpUserID, 
                                                             IN UINT32 udwTvWallID);

/**
* 逐个获取查找到的窗口配置信息
* @param [IN]  lpFindHandle                 查找句柄 
* @param [OUT] pstWndInfo                   保存窗口配置信息的指针 
* @return TRUE表示成功，其他表示失败
* @note 返回失败说明查询结束
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindNextWnd(IN LPVOID lpFindHandle, 
                                                           OUT LPNETDEV_XW_SCENE_WND_INFO_S pstWndInfo);

/**
* 关闭查找窗口配置，释放资源
* @param [IN] lpFindHandle                  文件查找句柄
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindCloseWnd(IN LPVOID lpFindHandle);


/**
* 获取单个窗口配置信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [INOUT]  pstWndInfo                窗口信息结构体指针,需要输入窗口ID
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetWnd(IN LPVOID lpUserID,
                                                      IN UINT32 udwTvWallID, 
                                                      INOUT LPNETDEV_XW_SCENE_WND_INFO_S pstWndInfo);

/**
* 创建单个窗口配置信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [INOUT]  pstWndInfo                窗口信息结构体指针,窗口ID由设备端分配并输出
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_CreateWnd(IN LPVOID lpUserID,
                                                         IN UINT32 udwTvWallID, 
                                                         INOUT LPNETDEV_XW_SCENE_WND_INFO_S pstWndInfo,
                                                         OUT UINT32 *pudwLastChange);


/**
* 修改单个窗口配置信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [INOUT]  pstWndInfo                窗口信息结构体指针,需要输入窗口ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ModifyWnd(IN LPVOID lpUserID, 
                                                         IN UINT32 udwTvWallID, 
                                                         INOUT LPNETDEV_XW_SCENE_WND_INFO_S pstWndInfo, 
                                                         OUT UINT32 *pudwLastChange);

/**
* 删除单个窗口配置信息
* @param [IN]  lpUserID                     用户登录ID
* @param [IN]  udwTvWallID                  电视墙ID
* @param [IN]  udwWndID                     窗口ID
* @param [OUT] pudwLastChange               摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteWnd(IN LPVOID lpUserID,
                                                         IN UINT32 udwTvWallID,
                                                         IN UINT32 udwWndID,
                                                         OUT UINT32 *pudwLastChange);


/**
* 建立实况
* @param [IN]  lpUserID                      用户登录ID
* @param [IN]  pstDisplayerID                电视墙ID、窗口ID、分屏序号
* @param [IN]  pstVideoSource                视频源的信息
* @param [OUT]  *pudwTaskNo                  本次实况业务号,停止实况时需要使用
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StartRealPlay(IN LPVOID lpUserID, 
                                                             IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                             IN LPNETDEV_XW_VIDEO_SOURCE_S pstVideoSource,
                                                             OUT UINT32 *pudwTaskNo);

/** 
* 电视墙开启实况
* @param [IN] lpUserID                                     用户登录ID
* @param [IN] pstPriviewInfo                               实况预览参数
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StartRealPlay_V30(IN LPVOID lpUserID,
                                                                 IN LPNETDEV_XW_PRIVIEW_INFO_S pstPriviewInfo);


/**
* 停止实况
* @param [IN]  lpUserID                      用户登录ID 
* @param [IN]  pstDisplayerID                电视墙ID、窗口ID、分屏序号
* @param [IN]  udwTaskNo                     实况业务号
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StopRealPlay(IN LPVOID lpUserID,
                                                            IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                            IN UINT32 udwTaskNo);

/**
* 停止实况（不需要传入TaskNo）
* @param [IN]  lpUserID                      用户登录ID 
* @param [IN]  pstDisplayerID                电视墙ID、窗口ID、分屏序号
* @return TRUE表示成功，其他表示失败
* @note 仅供一体机内部使用，
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StopRealPlayWithoutTaskNo(IN LPVOID lpUserID,
                                                                         IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID);

/**
* 开启 DC 回放上墙
* @param [IN] lpUserID                  用户登录ID
* @param [IN] pstDCPlaybackCond         电视墙回放参数
* @param [OUT] pudwSessionID            回放业务号
* @return TRUE表示成功，其他表示失败
* @note
* -
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PlayBackToTVWall(IN LPVOID lpUserID,
                                                             IN LPNETDEV_DC_PLAYBACK_COND_S pstDCPlaybackCond,
                                                             OUT UINT32 *pudwSessionID);



/**
* 建立回放
* @param [IN]  lpUserID                      用户登录ID 
* @param [IN]  pstDisplayerID                电视墙ID、窗口ID、分屏序号
* @param [IN]  pstChannels                   多个通道信息  
* @param [OUT]  *pudwTaskNo                  本次回放业务号,停止回放时需要使用
* @return TRUE表示成功，其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StartPlayback(IN LPVOID lpUserID, 
                                                             IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                             IN LPNETDEV_XW_CHANNELS_S pstChannels,
                                                             OUT UINT32 *pudwTaskNo);

/**
* 停止回放
* @param [IN]  lpUserID                     回放句柄
* @param [IN]  pstDisplayerID               电视墙ID、窗口ID、分屏序号
* @param [IN]  udwTaskNo                    回放业务号
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_StopPlayback(IN LPVOID lpUserID,
                                                            IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                            IN UINT32 udwTaskNo);

/**
* 控制回放
* @param [IN]  lpUserID                     回放句柄
* @param [IN]  pstDisplayerID               电视墙ID、窗口ID、分屏序号
* @param [IN]  pstPlaybackParam             回放控制信息
* @return TRUE表示成功，其他表示失败
* @note 
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ControlPlayback(IN LPVOID lpUserID,
                                                               IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                               IN LPNETDEV_XW_PLAYBACK_PARAM_S pstPlaybackParam);

/**
* 开始被动解码  Start passive decode
* @param [IN]   lpUserID                    用户登录ID User login ID
* @para, [IN]   pstDisplayerID              设备ID信息
* @param [IN]   pstVideoSource              视频源信息
* @param [OUT]  pudwTaskNo             ·    业务号，用于控制被动解码
* @return 返回FALSE表示失败，TRUE为成功
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartPassiveDecode(IN LPVOID lpUserID,
                                                               IN LPNETDEV_XW_DISPLAYER_ID_S pstDisplayerID,
                                                               IN LPNETDEV_XW_VIDEO_SOURCE_S pstVideoSource,
                                                               OUT UINT32 *pudwTaskNo);

/**
* 向被动解码通道发送数据  Send data to passive decode channel
* @param [IN]   lpUserID                 用户登录ID User login ID
* @param [IN]   udwTaskNO              · 业务号，用于控制被动解码
* @param [IN]   pstSendData              待发送数据内容
* @return 返回FALSE表示失败，TRUE为成功
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SendPassiveData(IN LPVOID lpUserID,
                                                            IN UINT32 udwTaskNo,
                                                            IN LPNETDEV_PASSIVE_SEND_S pstSendData);

/**
* 停止被动解码 Stop passive decode
* @param [IN]   lpUserID                 用户登录ID User login ID
* @param [IN]   udwTaskNO              · 业务号，用于控制被动解码
* @return 返回FALSE表示失败，TRUE为成功
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPassiveDecode(IN LPVOID lpUserID,
                                                              IN UINT32 udwTaskNO);

/**
* 批量开窗
* @param [IN] lpUserID               用户登录ID
* @param [IN] dwTimeOut              超时时间(秒)    范围10s~60s
* @param [IN] udwTVWallID            电视墙ID
* @param [IN] pstWndInfo             窗口信息结构体，创建成功后返回窗口ID
* @param [OUT] pstResultWndInfo      开窗返回信息结构体
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_CreateBatchWnd(IN LPVOID lpUserID,
                                                              IN INT32 dwTimeOut,
                                                              IN UINT32 udwTVWallID,
                                                              IN LPNETDEV_XW_WND_INFO_LIST_S pstWndInfo,
                                                              OUT LPNETDEV_XW_BATCH_RESULT_LIST_S pstResultWndInfo);

/**
* 批量关窗
* @param [IN] lpUserID                  用户登录ID
* @param [IN] dwTimeOut                 超时时间(秒)    范围10s~60s
* @param [IN] udwTVWallID               电视墙ID
* @param [INOUT] pstDeleteWndInfo       窗口信息结构体
* @return TRUE表示成功，其他表示失败
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteBatchWnd(IN LPVOID lpUserID,
                                                              IN INT32 dwTimeOut,
                                                              IN UINT32 udwTVWallID,
                                                              INOUT LPNETDEV_XW_BATCH_RESULT_LIST_S pstDeleteWndInfo);
  
/**
* 电视墙窗口放大/还原
* @param [IN]  lpUserID             用户登录ID
* @param [IN]  udwTvWallID          电视墙ID
* @param [IN]  udwWndID             窗口ID
* @param [IN]  pstScreenZoomInfo    屏幕放大信息
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ZoomScreen(IN LPVOID lpUserID,
                                                          IN UINT32 udwTvWallID,
                                                          IN UINT32 udwWndID,
                                                          IN LPNETDEV_XW_SCREEN_ZOOM_INFO_S pstScreenZoomInfo);


/**
* 获取电视墙拼接屏控制参数信息
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [OUT] pstScreenCtrlParamInfo   拼接屏控制参数信息
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetSceenCtrlParam(IN LPVOID lpUserID,
                                                                 IN UINT32 udwTvWallID,
                                                                 OUT LPNETDEV_XW_SCREEN_CTRL_PARAM_INFO_S pstScreenCtrlParamInfo);

/**
* 设置电视墙拼接屏控制参数信息
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [IN]  pstScreenCtrlParamInfo   拼接屏控制参数信息
* @param [OUT] pudwLastChange           摘要字 每次配置改动修改需要修改这个摘要字，摘要字由终端生成
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_SetSceenCtrlParam(IN LPVOID lpUserID,
                                                                 IN UINT32 udwTvWallID,
                                                                 IN LPNETDEV_XW_SCREEN_CTRL_PARAM_INFO_S pstScreenCtrlParamInfo,
                                                                 OUT UINT32* pudwLastChange);

/**
* 手动开关机
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [IN]  pstManualSwitchPower   手动开关机参数
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_ManualSwitchPower(IN LPVOID lpUserID,
                                                                 IN UINT32 udwTvWallID,
                                                                 IN LPNETDEV_XW_MANUAL_SWITCH_POWER_S pstManualSwitchPower);

/**
* 延迟开关机
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [IN]  pstDelaySwitchPower   延迟开关机参数
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DelaySwitchPower(IN LPVOID lpUserID,
                                                                IN UINT32 udwTvWallID,
                                                                IN LPNETDEV_XW_DELAY_SWITCH_POWER_S pstDelaySwitchPower);

/**
* 取消延迟开关机
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DelDelaySwitchPower(IN LPVOID lpUserID,
                                                                   IN UINT32 udwTvWallID);


/**
* 获取定时开关机信息
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [OUT] pstTimingSwitchPower     定时开关机信息
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetTimingSwitchPower(IN LPVOID lpUserID,
                                                                    IN UINT32 udwTvWallID,
                                                                    OUT LPNETDEV_XW_TIMING_SWITCH_POWER_S pstTimingSwitchPower);

/**
* 配置定时开关机信息
* @param [IN]  lpUserID                 用户登录ID
* @param [IN]  udwTvWallID              电视墙ID
* @param [IN] pstTimingSwitchPower      定时开关机信息
* @param [OUT] pudwLastChange           摘要字 每次配置改动修改需要修改这个摘要字，摘要字由终端生成
* @return TRUE表示成功,其他表示失败
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_SetTimingSwitchPower(IN LPVOID lpUserID,
                                                                    IN UINT32 udwTvWallID,
                                                                    IN LPNETDEV_XW_TIMING_SWITCH_POWER_S pstTimingSwitchPower,
                                                                    OUT UINT32 *pudwLastChange);

/**
* 获取虚拟LED列表
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @return 业务号,返回NULL表示失败,其他值作为NETDEV_XW_FindNextVirtualLED,NETDEV_XW_FindCloseVirtualLED等函数的参数。
* @note无
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_XW_FindVirtualLEDList(IN LPVOID lpUserID,
                                                                    IN UINT32 udwTvWallID);


/**
* 逐个虚拟LED
* @param [IN]   lpFindHandle                 查询Handle
* @param [OUT]  pstVirtualLEDInfo            虚拟LED信息
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindNextVirtualLED(IN LPVOID lpFindHandle,
                                                                  OUT LPNETDEV_XW_VIRTUAL_LED_INFO_S pstVirtualLEDInfo);

/**
* 关闭虚拟LED列表FindHandle
* @param [IN]   lpFindHandle                查询Handle
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_FindCloseVirtualLED(IN LPVOID lpFindHandle);

/**
* 创建单个虚拟LED
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @param [INOUT]  pstVirtualLEDInfo         虚拟LED信息,LEDID由设备返回
* @param [OUT]  pudwLastChange              摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_CreateVirtualLED(IN LPVOID lpUserID, 
                                                                IN UINT32 udwTvWallID, 
                                                                INOUT LPNETDEV_XW_VIRTUAL_LED_INFO_S pstVirtualLEDInfo, 
                                                                OUT UINT32 *pudwLastChange);

/**
* 删除单个场景下所有虚拟LED
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @param [OUT]  pudwLastChange              摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteAllVirtualLED(IN LPVOID lpUserID, 
                                                                   IN UINT32 udwTvWallID,
                                                                   OUT UINT32 *pudwLastChange);

/**
* 获取单个虚拟LED
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @param [INOUT]  pstVirtualLEDInfo         虚拟LED信息,需要输入LED ID
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_GetVirtualLED(IN LPVOID lpUserID, 
                                                             IN UINT32 udwTvWallID, 
                                                             INOUT LPNETDEV_XW_VIRTUAL_LED_INFO_S pstVirtualLEDInfo);

/**
* 配置单个虚拟LED
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @param [OUT]  pstVirtualLEDInfo           虚拟LED信息
* @param [OUT]  pudwLastChange              摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_SetVirtualLED(IN LPVOID lpUserID,
                                                             IN UINT32 udwTvWallID,
                                                             IN LPNETDEV_XW_VIRTUAL_LED_INFO_S pstVirtualLEDInfo,
                                                             OUT UINT32 *pudwLastChange);

/**
* 删除单个虚拟LED
* @param [IN]   lpUserID                    用户登录ID User login ID
* @param [IN]   udwTvWallID                 电视墙ID
* @param [IN]   udwLedlID                   虚拟LED的ID
* @param [OUT]  pudwLastChange              摘要字，配置改动会更新摘要字，由设备端生成
* @return TRUE表示成功，其他表示失败
* @note无
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_XW_DeleteOneVirtualLED(IN LPVOID lpUserID,
                                                                   IN UINT32 udwTvWallID,
                                                                   IN UINT32 udwLedlID,
                                                                   OUT UINT32 *pudwLastChange);

/*                   电视墙、拼接业务模块结束行                   */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif




#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */

