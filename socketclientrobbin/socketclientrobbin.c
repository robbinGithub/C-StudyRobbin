#include "stdio.h"
#include "stdio.h"
#include "string.h"

/*
  HANDLE结构，句柄，函数执行函数
*/
typedef struct _SCK_HANDLE{
	char version[16];
	char serverip[16];
	int  serverport;
	unsigned char* buf;
	int buflen;
}SCK_HANDLE;



// 客户端初始化(获取Handle)

__declspec(dllexport) int cltSocketInit(void ** handle /*out*/)
{  
	int ret = 0;
	SCK_HANDLE * sh = (SCK_HANDLE*)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{   
		ret = -1;
		printf("func cltSocketInit() err:%d malloc error....", ret);
	}
	memset(sh, 0, sizeof(SCK_HANDLE));
	strcpy(sh->serverip, "127.0.0.1");
	sh->serverport = 8080;
	strcpy(sh->version, "1.0.1");
	sh->buflen = 1024;
	*handle = sh;
	return 0;
}


// 客户端发送报文

__declspec(dllexport) int cltSocketSend(void * handle/*in*/, unsigned char * buf /*in*/)
{   
	int ret = 0;
	SCK_HANDLE * sh;
	if (handle == NULL || buf == NULL)
	{
		ret = -1;
		printf("func cltSocketSend() err:%dhandle == NULL || buf == NUL....", ret);
		return ret;

	}
	sh =(SCK_HANDLE *) handle;
	strcpy(sh->buf, buf);
	return 0;
}


// 客户端接收报文
__declspec(dllexport) int cltSocketRev(void * handle/*in*/, unsigned char * buf/*in*/, int * bufferlen/*out*/)
{
	int ret = 0;
	SCK_HANDLE * sh = NULL;
	if (handle == NULL || buf == NULL){
		ret = -1;
		printf("func cltSocketRev() err:%dhandle == NULL || buf == NUL....", ret);
		return ret;
	}
	sh = handle;
	memset(buf, 0, bufferlen);
	strcpy(buf, sh->buf);
	*bufferlen = handle;
	return 0;
}


// 客户端释放资源
__declspec(dllexport) int cltSocketDestroy(void * handle/*in*/)
{   
	int ret = 0;
	SCK_HANDLE * sh = NULL;

	if (handle == NULL)
	{
		ret = -1;
		return ret;
	}
	sh = (SCK_HANDLE *)handle;
	if (sh != NULL)
	{
		free(sh->buf);
		sh->buf = NULL;
		sh->buflen = 0;
	}
	free(sh);

	return ret;
}