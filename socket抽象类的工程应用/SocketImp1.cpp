#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SocketImp1.h"


SocketImp1::SocketImp1(void)
{
}


SocketImp1::~SocketImp1(void)
{
}

int SocketImp1::cltSocketInit()
{
	return 0;
}

//�ͻ��˷�����
int SocketImp1::cltSocketSend( unsigned char *buf ,  int buflen )
{
	pcommon = (char *)malloc((buflen+1)*sizeof(char));
	//pcommon[len-1] = 0;
	len = buflen;
	memcpy(pcommon,buf,buflen);
	return 0;
}

//�ͻ����ձ���
int SocketImp1::cltSocketRev( unsigned char *buf , int *buflen )
{
	memcpy(buf,pcommon,len);
	*buflen = len;
	return 0;
}

//�ͻ����ͷ���Դ
int SocketImp1::cltSocketDestory()
{
	if (pcommon != NULL)
	{
		delete[] pcommon;
	}
	return 0;
}
