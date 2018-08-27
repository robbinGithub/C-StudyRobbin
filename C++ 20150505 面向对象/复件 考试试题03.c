#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;

SLIST *Creat_SList();
int SList_Print(SLIST *pHead);
//在结点数值为x的前面插入y
int SList_NodeInsert(SLIST *pHead, int x, int y);
//删除结点为y的链表结点
int SList_NodeDel(SLIST *pHead, int y);
int SList_Destory(SLIST *pHead);
int SList_revse(SLIST *pHead);

//能熟练的 写出稳定的、稳健程序 1年工作经验
SLIST *Creat_SList()
{
	//1 创建头结点并初始化 
	int data = 0;
	SLIST *pHead = NULL, *pM = NULL, *pCur;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2循环创建结点，结点数据域中的数值从键盘输入，
	//以-1作为输入结束标志
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//准备环境 让pCur指向pHead
	pCur = pHead;
	while(data != -1)
	{
		//不断的malloc新节点 并且数据域 赋值
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			SList_Destory(pHead);
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//1新节点入链表
		pCur->next = pM;

		//2 当前结点下移（新结点变成当前结点）
		pCur = pM; // (pCur = pCur->next)

		printf("\nPlease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}
	return pHead;
}


//能熟练的 写出稳定的、稳健程序 2年工作经验
int Creat_SList2(SLIST **Head)
{
	int ret = 0;
	//1 创建头结点并初始化 
	int data = 0;
	SLIST *pHead = NULL, *pM = NULL, *pCur = NULL;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		ret = -1;
		printf("func Creat_SList() err:%d", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2循环创建结点，结点数据域中的数值从键盘输入，
	//以-1作为输入结束标志
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//准备环境 让pCur指向pHead
	pCur = pHead;
	while(data != -1)
	{
		//不断的malloc新节点 并且数据域 赋值
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			SList_Destory(pHead);
			ret = -2;
			printf("func Creat_SList() err:%d malloc err", ret);
			return ret;
		}
		pM->data = data;
		pM->next = NULL;

		//1新节点入链表
		pCur->next = pM;

		//2 当前结点下移（新结点变成当前结点）
		pCur = pM; // (pCur = pCur->next)

		printf("\nPlease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}
	*Head = pHead;
	return ret;
}

int SList_Print(SLIST *pHead)
{
	SLIST *p = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	//准备环境
	p = pHead->next;
	printf("\nBegin ");
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("End ");
	return 0;
}

//在结点数值为x的前面插入y
int SList_NodeInsert(SLIST *pHead, int x, int y)
{
	SLIST *pCur = NULL, *pPre = NULL, *pM= NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//环境准备
	pPre = pHead;
	pCur = pHead->next;

	//不断的malloc新节点 并且数据域 赋值
	pM = (SLIST *)malloc(sizeof(SLIST));
	pM->data = y;
	pM->next = NULL;

	while(pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		//让pPre下移
		pPre = pCur;
		//让当前节点下移
		pCur = pCur->next;
	}

	//让新节点链接后继结点
	pM->next = pPre->next; //(pCur)
	//让前驱结点连接pM
	pPre->next = pM;

	return 0;
}

//删除结点为y的链表结点
int SList_NodeDel(SLIST *pHead, int y)
{
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//环境准备
	pPre = pHead;
	pCur = pHead->next;

	while(pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		//让pPre下移
		pPre = pCur;
		//让当前节点下移
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		printf("没有找到节点 y:%d", y);
		return -2;
	}
	//执行操作
	pPre->next = pCur->next;
	free(pCur);
	return 0;
}

//删除结点为y的链表结点
int SList_DelSpeicalNode(SLIST *pHead)
{
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//环境准备
	pPre = pHead;
	pCur = pHead->next;

	while(pCur)
	{
		if (pCur->data %2 == 0) 
		{
			break;
		}
		//让pPre下移
		pPre = pCur;
		//让当前节点下移
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		printf("没有找到节点 ");
		return 0;
	}
	//执行操作
	pPre->next = pCur->next;
	free(pCur);
	return 0;
}


//循环控制删除业务节点
int SList_DelSpeical_OP(SLIST *pHead)
{

	SLIST *p = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	//准备环境
	p = pHead->next;
	while(p)
	{
		SList_DelSpeicalNode(p);
		p = p->next;
	}
	
	return 0;
}


int SList_Destory(SLIST *pHead)
{
	//1、删除当前结点前，需要把后继结点位置缓存

	SLIST *pTmp = NULL;
	SLIST *pCur = pHead;
	if (pHead == NULL)
	{
		return -1;
	}

	while(pCur)
	{
		//缓存后继结点位置
		pTmp = pCur->next;
		//删除当前结点
		free(pCur);
		//当前结点下移
		pCur = pTmp;
	}
	return 0;
}

int SList_revse(SLIST *pHead)
{

	SLIST *p = NULL, *q = NULL, *t = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	if (pHead->next == NULL || pHead->next->next == NULL)
	{
		return 0;
	}
	//准备环境
	p = pHead->next;
	q = pHead->next->next;

	while(q != NULL)
	{
		//1、在逆置之前需要做一个缓存
		t = q->next;

		//2、开始逆置
		q->next = p;

		//3、让p后移
		p = q;
		//4、q后移
		q = t; 
	}

	//让第一个业务结点赋值null
	pHead->next->next = NULL;
	//让链表头指向最后一个节点
	pHead->next = p;

	return 0;
}


void main0003()
{
	int ret = 0;
	SLIST *pHead = NULL;
	//创建 并打印 
	pHead = Creat_SList();
	ret = SList_Print(pHead);

	
	ret = SList_DelSpeical_OP(pHead);
	ret = SList_Print(pHead);

	/*
	//插入操作
	ret = SList_NodeInsert(pHead, 20, 19);
	ret = SList_Print(pHead);

	ret = SList_NodeDel(pHead, 19);
	ret = SList_Print(pHead);

	ret = SList_revse(pHead);
	ret = SList_Print(pHead);
	*/
	ret = SList_Destory(pHead);
	system("pause");
}