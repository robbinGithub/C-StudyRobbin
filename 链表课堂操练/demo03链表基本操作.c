#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;

}SLST;
//�����б�
SLST * Create_SList();
//�ڽ����ֵΪx��ǰ�����y
int SList_NodeInsert(SLST *pHead, int x, int y);
//ɾ�����Ϊy��������
int SList_NodeDel(SLST *pHead, int y);
int SList_Destroy(SLST *pHead);
//��ӡ����
int SList_Print(SLST* pHead);

void main(){
	//��������
	SLST *p =Create_SList();
	SList_Print(p);
	//�������
	SList_NodeInsert(p, 20, 19);
	SList_Print(p);
	//��������
	printf("������ת����...");
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


//�ڽ����ֵΪx��ǰ�����y
int SList_NodeInsert(SLST *pHead, int x, int y){
	if (pHead == NULL){
		return -1;
	}
	//������ʼ��
	SLST *pPre = pHead;   //��һ���ڵ�
	SLST *p = pPre->next; //��ǰ�ڵ�
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
	//��ʼ����ͷ
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
//��������
SLST * Create_SList(){
	//����ͷ��㲢��ʼ��
	int data = 0;
	SLST *pHead = NULL, *pM = NULL, *p;
	pHead = (SLST*)malloc(sizeof(SLST));
	if (pHead == NULL){
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	p = pHead;
	//ѭ���������
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);
	while (data != -1){
		//�����½��
		pM = (SLST*)malloc(sizeof(SLST));
		if (pM == NULL){
			SList_Destroy(pHead); 
			return NULL;  
		}
		pM->data = data;
		pM->next = NULL;
		//��������ǰ���
		p->next = pM;
	    //����һ�½��Ϊ�½����
		p = pM;
		printf("Please enter the data of noede(-1:quit)");
		scanf("%d", &data);
	}
	return pHead;
}

//ɾ�����Ϊy��������
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
		printf("û���ҵ��ڵ�y:%d", y);
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
	//׼������
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
//�������ò����͸���ָ�����֮��Ĺ�ϵ
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
	//׼������
	p = pHead->next;
    q = pHead->next->next;
	while (q != NULL){
		//����q��һ������ַ
		t = q->next;
		//q��һ�������Ϊp
		q->next = p;
		p = q;
		q = t;
	}
	pHead->next->next = NULL;
	pHead->next = p;
	ret = 0;
	return ret;
	
}
