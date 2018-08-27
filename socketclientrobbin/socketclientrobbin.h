#include "stdio.h"
#include "stdio.h"
#include "string.h"

//------------------第一套api接口---Begin--------------------------------//

//客户端初始化 获取handle上下
int cltSocketInit(void **handle /*out*/);

//客户端发报文
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);

//客户端收报文
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);

//客户端释放资源
int cltSocketDestory(void *handle/*in*/);

//------------------第一套api接口---End-----------------------------------//

