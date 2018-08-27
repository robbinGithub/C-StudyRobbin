#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "seqqueue.h"

void main()
{
	int i = 0, a[10], tmp = 0;
	SeqQueue*  queue = NULL;
	//创建队列
	queue = SeqQueue_Create(10);

	for (i=0; i<5; i++)
	{
		a[i] = i+1;
		//队列添加元素
		SeqQueue_Append(queue, (void *)&a[i]);
	}
	//获取首元素
	tmp = *((int *)SeqQueue_Header(queue));
	printf("队列的头元素:%d \n", tmp);
	printf("队列的length:%d \n", SeqQueue_Length(queue)); //获取长度
	printf("队列的cap:%d \n", SeqQueue_Capacity(queue));  //获取容量

	//遍历队列
	while (SeqQueue_Length(queue) > 0)
	{   //获取队列元素
		tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d \n", tmp);
	}
	//销毁队列
	SeqQueue_Destroy(queue);
	system("pause");
}