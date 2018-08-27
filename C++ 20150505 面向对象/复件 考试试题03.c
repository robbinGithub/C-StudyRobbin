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
//�ڽ����ֵΪx��ǰ�����y
int SList_NodeInsert(SLIST *pHead, int x, int y);
//ɾ�����Ϊy��������
int SList_NodeDel(SLIST *pHead, int y);
int SList_Destory(SLIST *pHead);
int SList_revse(SLIST *pHead);

//�������� д���ȶ��ġ��Ƚ����� 1�깤������
SLIST *Creat_SList()
{
	//1 ����ͷ��㲢��ʼ�� 
	int data = 0;
	SLIST *pHead = NULL, *pM = NULL, *pCur;
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2ѭ��������㣬����������е���ֵ�Ӽ������룬
	//��-1��Ϊ���������־
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//׼������ ��pCurָ��pHead
	pCur = pHead;
	while(data != -1)
	{
		//���ϵ�malloc�½ڵ� ���������� ��ֵ
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			SList_Destory(pHead);
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//1�½ڵ�������
		pCur->next = pM;

		//2 ��ǰ������ƣ��½���ɵ�ǰ��㣩
		pCur = pM; // (pCur = pCur->next)

		printf("\nPlease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}
	return pHead;
}


//�������� д���ȶ��ġ��Ƚ����� 2�깤������
int Creat_SList2(SLIST **Head)
{
	int ret = 0;
	//1 ����ͷ��㲢��ʼ�� 
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

	//2ѭ��������㣬����������е���ֵ�Ӽ������룬
	//��-1��Ϊ���������־
	printf("\nPlease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//׼������ ��pCurָ��pHead
	pCur = pHead;
	while(data != -1)
	{
		//���ϵ�malloc�½ڵ� ���������� ��ֵ
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

		//1�½ڵ�������
		pCur->next = pM;

		//2 ��ǰ������ƣ��½���ɵ�ǰ��㣩
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
	//׼������
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

//�ڽ����ֵΪx��ǰ�����y
int SList_NodeInsert(SLIST *pHead, int x, int y)
{
	SLIST *pCur = NULL, *pPre = NULL, *pM= NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//����׼��
	pPre = pHead;
	pCur = pHead->next;

	//���ϵ�malloc�½ڵ� ���������� ��ֵ
	pM = (SLIST *)malloc(sizeof(SLIST));
	pM->data = y;
	pM->next = NULL;

	while(pCur)
	{
		if (pCur->data == x)
		{
			break;
		}
		//��pPre����
		pPre = pCur;
		//�õ�ǰ�ڵ�����
		pCur = pCur->next;
	}

	//���½ڵ����Ӻ�̽��
	pM->next = pPre->next; //(pCur)
	//��ǰ���������pM
	pPre->next = pM;

	return 0;
}

//ɾ�����Ϊy��������
int SList_NodeDel(SLIST *pHead, int y)
{
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//����׼��
	pPre = pHead;
	pCur = pHead->next;

	while(pCur)
	{
		if (pCur->data == y)
		{
			break;
		}
		//��pPre����
		pPre = pCur;
		//�õ�ǰ�ڵ�����
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		printf("û���ҵ��ڵ� y:%d", y);
		return -2;
	}
	//ִ�в���
	pPre->next = pCur->next;
	free(pCur);
	return 0;
}

//ɾ�����Ϊy��������
int SList_DelSpeicalNode(SLIST *pHead)
{
	SLIST *pCur = NULL, *pPre = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	//����׼��
	pPre = pHead;
	pCur = pHead->next;

	while(pCur)
	{
		if (pCur->data %2 == 0) 
		{
			break;
		}
		//��pPre����
		pPre = pCur;
		//�õ�ǰ�ڵ�����
		pCur = pCur->next;
	}
	if (pCur == NULL)
	{
		printf("û���ҵ��ڵ� ");
		return 0;
	}
	//ִ�в���
	pPre->next = pCur->next;
	free(pCur);
	return 0;
}


//ѭ������ɾ��ҵ��ڵ�
int SList_DelSpeical_OP(SLIST *pHead)
{

	SLIST *p = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	//׼������
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
	//1��ɾ����ǰ���ǰ����Ҫ�Ѻ�̽��λ�û���

	SLIST *pTmp = NULL;
	SLIST *pCur = pHead;
	if (pHead == NULL)
	{
		return -1;
	}

	while(pCur)
	{
		//�����̽��λ��
		pTmp = pCur->next;
		//ɾ����ǰ���
		free(pCur);
		//��ǰ�������
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
	//׼������
	p = pHead->next;
	q = pHead->next->next;

	while(q != NULL)
	{
		//1��������֮ǰ��Ҫ��һ������
		t = q->next;

		//2����ʼ����
		q->next = p;

		//3����p����
		p = q;
		//4��q����
		q = t; 
	}

	//�õ�һ��ҵ���㸳ֵnull
	pHead->next->next = NULL;
	//������ͷָ�����һ���ڵ�
	pHead->next = p;

	return 0;
}


void main0003()
{
	int ret = 0;
	SLIST *pHead = NULL;
	//���� ����ӡ 
	pHead = Creat_SList();
	ret = SList_Print(pHead);

	
	ret = SList_DelSpeical_OP(pHead);
	ret = SList_Print(pHead);

	/*
	//�������
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