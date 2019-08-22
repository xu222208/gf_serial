
#ifndef GENERALDEF_H
#define GENERALDEF_H

#include "HCNetSDK.h"
#include "LinuxPlayM4.h"



#define MAX_CHANS      24              //�豸֧�ֵ����ͨ����
#define MAX_DEVICE     10             //����豸��
#define MAX_OUTPUTS	   16	//16���Ĵ�����
#define MAX_PREVIEWS		512	//��Ԥ���������

//�豸��������
#define TREE_ALL_T	 0        //������ڵ�
#define DEVICETYPE 	 1		  //�����豸
#define CHANNELTYPE	 2	      //����ͨ��


#define DEMO_FULL_WIDTH 1024	//demoĬ�ϵĿ��
#define DEMO_FULL_HEIGHT 768	//demoĬ�ϵĸ߶�
#define OUTPUT_INTERVAL 4		//ÿ������ļ����С


//��ʱ��ʱ��
#define CYCLE_PREVIEW_TIMER        2    //ѭ��Ԥ����ʱ��
#define REMOTE_PLAY_STATE_TIMER	   8		//Զ�̻ط��ļ�����״̬ʱ��
#define DOWNSTATE_TIMER		       9	 //�����ļ�ʱ��
#define LOCAL_PLAY_STATE_TIMER     10
#define PLAYBYTIME_TIMER	       12		// ��ʱ��ط�
#define DOWNBYTIME_TIMER		   13		//��ʱ������

//Զ���ļ����ҷ���ֵ
#define NET_DVR_FILE_SUCCESS    1000
#define NET_DVR_FILE_NOFIND     1001
#define NET_DVR_ISFINDING       1002
#define NET_DVR_NOMOREFILE      1003
#define NET_DVR_FILE_EXCEPTION  1004

typedef struct STRU_CHANNEL_INFO
{
	int		iDeviceIndex;			//��Ӧ���豸�������±�
	int		iChanIndex;			//���ͨ����
	char	chChanName[100];	//����ͨ���������

	int		iPicResolution;				//ͼƬ�ֱ���
	int		iPicQuality;				//ͼƬ����
	LONG	lRealHandle;          //ʵʱԤ�����

	int     iWinowIndex;           //Ԥ��ʱ��ͨ�������Ĵ�������
	BOOL    isRecording;           //����¼��
    BOOL    bEnable;               //ͨ���Ƿ�ʹ��
	char	chAccessChanIP[16];//ip����ͨ����ip��ַ

	STRU_CHANNEL_INFO *pNext;

	STRU_CHANNEL_INFO()
	{
		iDeviceIndex        = -1;
		iChanIndex          = -1;
		chChanName[0]       = '\0';
		iPicResolution		= 0;
		iPicQuality			= 2;
		lRealHandle         = -1;
		chAccessChanIP[0]	= '\0';	
		iWinowIndex         = -1;
		isRecording         = FALSE;
		bEnable             = FALSE;
		pNext				= NULL;
	}
}CHANNEL_INFO,*pCHANNEL_INFO;

typedef struct STRU_DEVICE_INFO
{
	int		iDeviceIndex;			//�豸�����±�
	LONG	lLoginID;				//ע��ID
	char	chLocalNodeName[100];	//�����豸�ڵ�����
	char	chDeviceName[100];		//�豸����
	char	chDeviceIP[33];			//����ֱ�����ӵ��豸IP
	UINT	lDevicePort;			//�豸���˿ں�
	char	chLoginUserName[30];	//��½�豸���û��������û������ʱ���õ�
	char	chLoginPwd[30];	//��½�豸������
	//char	chDeviceMultiIP[20];	//�ಥ���ַ
	char	chSerialNumber[50];		//���к�
	int		iDeviceChanNum;		    //�豸��ͨ����
	int		iStartChan;				//�豸��ʼͨ����
	int		iDeviceType;			//�豸����
	int 	iIPChanNum;				//�������ͨ������
    BOOL    bIPRet;                 //�Ƿ�IP����
//	BOOL	bCycle;					//���豸�Ƿ���ѭ������
	BOOL	bPlayDevice;			//���豸�ǲ�������ͨ�����ڲ���
	BOOL    bIsLogin;               //�Ƿ���ע����豸
	int		iEnableChanNum;			//��Чͨ����
	CHANNEL_INFO struChanInfo[MAX_CHANNUM_V30];
    STRU_DEVICE_INFO *pNext;

	STRU_DEVICE_INFO()
	{
       //  iDeviceIndex  = -1;
         lLoginID            = -1;
		 chLocalNodeName[0]  = '\0';
		 chDeviceName[0]     = '\0';
		 chDeviceIP[0]       = '\0';
         lDevicePort         = 8000;
         chLoginUserName[0]  = '\0';
         chLoginPwd[0]       ='\0';
         //chDeviceMultiIP[0]   ='\0';
		 chSerialNumber[0]   = '\0';
		 iDeviceChanNum      =  -1;
		 iStartChan          = 0;
		 iDeviceType         = 0;
		 iIPChanNum          = 0;
		 bIPRet              = 0;
		 bIsLogin            = FALSE;
//		 bCycle              = FALSE;
		 bPlayDevice         = FALSE;
		 iEnableChanNum      = -1;
		 pNext=NULL;
	}	 
}LOCAL_DEVICE_INFO,*pLOCAL_DEVICE_INFO;


//ȫ�����ź���Ѳ��ʱ�򲥷��豸��Ӧ�����к�
typedef struct STRU_PLAY_INFO{
	
	int		iDeviceIndex;		//��Ӧ���豸�������±�
	int		iChanIndex;			//���ͨ����
	
	STRU_PLAY_INFO()
	{
		iDeviceIndex = -1;
		iChanIndex   = -1;
	}
}PLAY_INFO,*PPLAY_INFO;


// typedef struct STRU_LOCAL_FILE_INFO{
// 	char chName[100];             //�ļ���
// 	DWORD FileSize;               //��С
// 	CTime StartTime;              //��ʼʱ��
// 	CTime StopTime;               //����ʱ��
// 	int iType;                    //�ļ�����
// 
// 	STRU_LOCAL_FILE_INFO()
// 	{
//         chName[0] = '\0';
// 		FileSize = 0;
//         iType = -1;
// 	}
// }LOCAL_FILE_INFO,*PLOCAL_FILE_INFO;

#define  XML_BUF 3*1024*1024
#endif