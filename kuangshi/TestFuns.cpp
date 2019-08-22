#include "TestFuns.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

int ToFile(const char *pFileName, const void *pData, int nLenght)
{
	FILE* fp = fopen(pFileName, "wb");
	if (fp != 0)
	{
		fwrite((const char *)pData, 1, nLenght, fp);
		fclose(fp);
		return 0;
	}
	return -1;
}
