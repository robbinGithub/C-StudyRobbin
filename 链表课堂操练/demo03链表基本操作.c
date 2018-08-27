#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;

}SLST;
//创建列表
SLST * Create_SList();
//在结点数值为x的前面插入y
int SList_NodeInsert(SLST *pHead, int x, int y);
//删除结点为y的链表结点
int SList_NodeDel(SLST *pHead, int y);
int SList_Destroy(SLST *pHead);
//打印链表
int SList_Print(SLST* pHead);

void main(){
	//创建链表
	SLST *p =Create_SList();
	SList_Print(p);
	//插入操作
	SList_NodeInsert(p, 20, 19);
	SList_Print(p);
	//逆置链表
	printf("正在逆转链表...");
	SList_reverse(p);
	SList_Print(p);
	system("pause");
}

int SList_Destroy(SLST *pHead){
	if (pHead == NULL){
		return -1;
	}
	SLST *p = NULL;
	SLST *pTmp = NULL;
	p = pHead;
	while (p){
		pTmp = p->next;
		free(p);
		p = pTmp;
	}
	return 0;
}


//在结点数值为x的前面插入y
int SList_NodeInsert(SLST *pHead, int x, int y){
	if (pHead == NULL){
		return -1;
	}
	//环境初始化
	SLST *pPre = pHead;   //上一个节点
	SLST *p = pPre->next; //当前节点
	SLST *pM = (SLST*)malloc(sizeof(SLST));
	pM->data = y;
	pM->next = NULL;
	while (p){
		if (p->data == x){
			break;
		}
		pPre = p;
		p = p->next;
	}
	pM->next = pPre->next;
	pPre->next = pM;
	return  0;
}

int Create_SList2(SLST **Head){
	//初始化表头
	int data = 0;
	int ret = 0;
	SLST*p = NULL,*pTmp=NULL;
	SLST *pHead = (SLST*)malloc(sizeof(SLST));
	if (pHead == NULL){
		ret = -1;
		printf("func Creat_SList() err:%d", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;
	p = pHead;
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);
	while (data != -1){
		pTmp = (SLST*)malloc(sizeof(SLST));
		if (pTmp = NULL){
			ret = -2;
			SList_Destroy(pHead);
		}
		pTmp->data = data;
		pTmp->next = NULL;
		p->next = pTmp;
		p = pTmp;
		printf("\nPlease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}
	*Head = pHead;
}
//创建链表
SLST * Create_SList(){
	//创建头结点并初始化
	int data = 0;
	SLST *pHead = NULL, *pM = NULL, *p;
	pHead = (SLST*)malloc(sizeof(SLST));
	if (pHead == NULL){
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	p = pHead;
	//循环创建结点
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);
	while (data != -1){
		//创建新结点
		pM = (SLST*)malloc(sizeof(SLST));
		if (pM == NULL){
			SList_Destroy(pHead); 
			return NULL;  
		}
		pM->data = data;
		pM->next = NULL;
		//连接至当前结点
		p->next = pM;
	    //更改一下结点为新建结点
		p = pM;
		printf("Please enter the data of noede(-1:quit)");
		scanf("%d", &data);
	}
	return pHead;
}

//删除结点为y的链表结点
int SList_NodeDel(SLST *pHead, int y){
	if (pHead == NULL){
		return -1;
	}
	SLST *pPre = pHead, *pNext = NULL;
	SLST *p = pHead->next;
	while (p){
		if (p->data == y){
			break;
		}
		pPre = p;
		p = p->next;
	}
	if (p == NULL){
		printf("没有找到节点y:%d", y);
		return -2;
	}
	pPre->next = p->next;
	free(p);
	return 0;



}

int SList_Print(SLST* pHead){
	if (pHead == NULL){
		return -1;
	}
	//准备环境
	SLST* p = NULL;
	p = pHead->next;
	printf("\nBegin");
	while (p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("End");
	return 0;
}
//链表逆置操作和辅助指针变量之间的关系
int SList_reverse(SLST *pHead){
	int ret = 0;
	SLST* p = NULL, *q = NULL,*t = NULL;
	if (pHead == NULL){
		ret = -1;
		return ret;
	}
	if (pHead->next == NULL || pHead->next->next == NULL){
		ret = -2;
		return ret;
	}
	//准备环境
	p = pHead->next;
    q = pHead->next->next;
	while (q != NULL){
		//缓存q下一个结点地址
		t = q->next;
		//q下一结点设置为p
		q->next = p;
		p = q;
		q = t;
	}
	pHead->next->next = NULL;
	pHead->next = p;
	ret = 0;
	return ret;
	
}
