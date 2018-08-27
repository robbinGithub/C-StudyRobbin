#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "socketclientdll.h"

//typedef int (*EncData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);
int myEncData(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen)
{
	//IP POrt
	memcpy(outData, "111111111111111111111111111111111", 10);
	*outDataLen = 10;
	return 0;
}

typedef struct EnvDevInfo
{
	char ip[32];
	int port;
	//
}EnvDevInfo;

int main()
{
	int				rv = 0;
	void			*handle = NULL; //socket处理句柄
	unsigned char	buf[2048];
	int				buflen = 0;

	unsigned char	buf2[2048] = {0};
	int				buflen2 = 0;

    //设备环境结构体清空内存及赋值
	EnvDevInfo		myEnvDevInfo;
	memset(&myEnvDevInfo, 0, sizeof(EnvDevInfo));

	strcpy(myEnvDevInfo.ip, "192.168.1.22");
	myEnvDevInfo.port = 99;

	strcpy(buf, "aaaaaaaaaaaaaaaaaaaaaaaaafffffffffffffffffffffff");


	buflen = 10;
	rv = cltSocketInit(&handle);
	if (rv != 0)
	{
		printf("func cltSocketInit():%d", rv);
		return rv;
	}

	rv = clitSocket_SetEncFunc(handle, myEncData, &myEnvDevInfo, sizeof(myEnvDevInfo));
	if (rv != 0)
	{
		printf("func cltSocketInit():%d", rv);
		goto End;
	}

	/*
	rv = cltSocketSend(handle, buf,  buflen);
	if (rv != 0)
	{
		printf("func cltSocketSend():%d", rv);
		goto End;
	}
	*/

	
	rv = cltSocketSend_enc(handle, buf,  buflen, myEncData, NULL, 0);
	if (rv != 0)
	{
		printf("func cltSocketSend_enc():%d", rv);
		goto End;
	}
	
	rv = cltSocketRev(handle, buf2 , &buflen2);
	if (rv != 0)
	{
		printf("func cltSocketRev():%d", rv);
		goto End;
	}
	printf("\n%s", buf2);

End:

	rv = cltSocketDestory(handle);
	if (rv != 0)
	{
		printf("func cltSocketDestory():%d", rv);
		return rv;
	}

	printf("hello....\n");
	
	system("pause");

	return 0;
}

