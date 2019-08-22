#include "XNetSDKTest.h"

int TestDevAlarmCallback()
{
	printf("%s\r\n", __FUNCTION__);
	char c = 0;
	do
	{
		switch(c)
		{
		case 's':
			{
				XSDK_DevSetAlarmListener(g_hDevice, true);
			}
			break;
		case 't':
			{
				XSDK_DevSetAlarmListener(g_hDevice, false);
			}
			break;
		}
	}while((c = getchar()) != 'q');
	return 0;
}

void OnDevAlarmCallback(XSDK_HANDLE hDevice, const char *szAlarm)
{
	printf("OnDevAlarmCallback[Dev:%ld][%s]\r\n", hDevice, szAlarm);
}