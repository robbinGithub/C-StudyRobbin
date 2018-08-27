#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node ; // unsigned int nodeAarry[100]
}TSeqList;

//typdef的意思 把void 重新命名成SeqList
/*
void * SeqList_Create2(int capacity)
{
	TSeqList *ret = NULL;
	ret = (TSeqList *)malloc(sizeof(TSeqList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)malloc(sizeof(unsigned int ) * capacity);
	if (ret->node == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	return ret;
}
*/
//根据容量创建队列
void * SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;

	if (capacity <= 0)
	{
		return NULL;
	}
	//初始所有内存空间
	ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(unsigned int ) * capacity );
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)(ret + 1);// ？
	
	ret->length = 0;
	return ret;
}

void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TSeqList *)list;   //这里为什么要换，不直接使用呢

	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0;
	TSeqList *tlist = list;

	if (list == NULL || node== NULL )
	{
		return -1;
	}
	if (pos<0 || pos>=tlist->capacity )
	{
		return -2;
	}
	//判断是否已经man
	if (tlist->length >= tlist->capacity)
	{
		return -3;
	}
	//容错
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}
	
	//插入算法 有两步
	//从插入的位置 后移元素 
	//注意length能表示出现在数组的最后元素位置
	//最后元素的下标为 tlist->node[length-1];
	for (i=tlist->length; i>pos; i--)
	{
		tlist->node[i] = tlist->node[i-1]; //数组从后移动 如第4元素移动   第4个元素赋予第5个元素
	}
	//在pos位置插入元素
	tlist->node[pos] = (unsigned int )node; //20140514这个地方不能加 (unsigned int *)
	//如果你加*，说明你对	unsigned int *node ; // unsigned int nodeAarry[100]还没有理解 
	tlist->length ++;

// 	{
// 		char *p = (char *)malloc(1000);
// 		p[1] = (char *)'a'; //err
// 		p[2] = (char)'b'; //0k
// 	}

	return 0;
}

//pos是数组的下标 我们约定从0开始
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	//int i = 0;
	TSeqList *tlist = list;
	if (list== NULL || pos<0 || pos>=tlist->length)  //node wangbaoming modify
	//if (list== NULL || pos<0 || pos>tlist->length)
	{
		return NULL;
	}
	return (SeqListNode*)tlist->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	TSeqList *tlist = list;
	SeqListNode* ret = NULL;
	if (list == NULL || pos<0 || pos>=tlist->length) //node wangbaoming modify
	{
		return NULL;
	}
	//缓存要删除的结点
	ret = (SeqListNode*)tlist->node[pos];
	//对链表进行移动
	for (i=pos+1; i<tlist->length; i++)   // 4 5 6 7 8 9
	{
		tlist->node[i-1] = tlist->node[i]; //向左移动   最后一个元素还在
 	}
	/*for (i = pos; i < (tlist->length-1); i++){
		tlist->node[i] = tlist->node[i + 1];
	}*/
	tlist->length --;
	return ret;
}
