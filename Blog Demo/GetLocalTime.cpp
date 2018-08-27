#include <stdio.h>
#include "windows.h"
int main()
{
	SYSTEMTIME sys;
	for (int i = 0; i<10; i++)
	{
		Sleep(50);
		GetLocalTime(&sys);
		printf("%4d-%02d-%02d %02d:%02d:%02d.%03d\t%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, i);
	}
	system("pause");
	return 0;
}