#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "seqqueue.h"

void main()
{
	int i = 0, a[10], tmp = 0;
	SeqQueue*  queue = NULL;
	//��������
	queue = SeqQueue_Create(10);

	for (i=0; i<5; i++)
	{
		a[i] = i+1;
		//�������Ԫ��
		SeqQueue_Append(queue, (void *)&a[i]);
	}
	//��ȡ��Ԫ��
	tmp = *((int *)SeqQueue_Header(queue));
	printf("���е�ͷԪ��:%d \n", tmp);
	printf("���е�length:%d \n", SeqQueue_Length(queue)); //��ȡ����
	printf("���е�cap:%d \n", SeqQueue_Capacity(queue));  //��ȡ����

	//��������
	while (SeqQueue_Length(queue) > 0)
	{   //��ȡ����Ԫ��
		tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}
	//���ٶ���
	SeqQueue_Destroy(queue);
	system("pause");
}