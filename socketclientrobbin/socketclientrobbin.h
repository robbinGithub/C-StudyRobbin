#include "stdio.h"
#include "stdio.h"
#include "string.h"

//------------------��һ��api�ӿ�---Begin--------------------------------//

//�ͻ��˳�ʼ�� ��ȡhandle����
int cltSocketInit(void **handle /*out*/);

//�ͻ��˷�����
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/);

//�ͻ����ձ���
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);

//�ͻ����ͷ���Դ
int cltSocketDestory(void *handle/*in*/);

//------------------��һ��api�ӿ�---End-----------------------------------//

