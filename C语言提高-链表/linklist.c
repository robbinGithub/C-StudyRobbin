#include "linklist.h"
#include "stdlib.h"

// ͷ���
typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

// ��������
LinkList * LinkList_Create( )
{  
	TLinkList * tlist = malloc(sizeof(TLinkList));
	if (tlist == NULL)
	{
		return NULL;
	}
	tlist ->length = 0;
	tlist->header.next = NULL;

}
// ��������
void LinkList_Destroy(LinkList * list)
{
	if (list != NULL)
	{
		free(list);
	}
	return;
}
// �������
void LinkList_Clear(LinkList * list)
{   
	TLinkList *tlist = list;
	if (tlist == NULL)
	{
		return;
	}
	tlist->header.next = NULL;
	tlist->length = 0;
	return;
}

// ������
int LinkList_Length(LinkList* list)
{
	TLinkList *tlist = list;
	if (tlist == NULL)
	{
		return -1;
	}
	return tlist->length;

}

int LinkList_Insert(LinkList * list, LinkListNode* node, int pos)
{  
	int i = 0;
	TLinkList  *tList = (TLinkList *)list;
	LinkListNode  * current = NULL;
	LinkListNode  * temp = NULL;
	if (tList == NULL || node == NULL || pos<0)
	{
		return -1;
	}
	current = &tList->header;   
	if (current == NULL)
	{
		return  -2;
	}

	for (i = 0; i < pos&&(current!=NULL); i++)  
	{
		current = current->next;
	}

	node->next = current->next;
	current->next = node; 
	tList->length++;
	return 0;

}
LinkListNode * LinkList_Get(LinkList * list, int pos)
{   
	int i = 0;
	TLinkList  *tList = (TLinkList *)list;
	LinkListNode  * current = NULL;
	LinkListNode  * ret = NULL;
	if (tList == NULL)
	{
		return NULL;
	}
	current = &tList->header;
	for (i = 0; i < pos && (current != NULL); i++)
	{
		current = current->next;
	}
	ret = current->next;
	return  ret;
	
}
LinkListNode * LinkList_Delete(LinkList * list,int pos)
{
	int i = 0;
	TLinkList  *tList = (TLinkList *)list;
	LinkListNode  * current = NULL;
	LinkListNode  * ret = NULL;
	if (tList == NULL)
	{
		return NULL;
	}
	current = &tList->header;
	for (i = 0; i < (pos-1) && (current != NULL); i++)
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tList->length--;
	return  ret;
}

