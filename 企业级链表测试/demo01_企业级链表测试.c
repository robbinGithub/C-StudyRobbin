#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Mylinklist.h"
typedef struct _Teacher
{
	LinkListNode*node;
	char name[32];
	int age;

}Teacher;
void main()
{
	Teacher t1, t2, t3, t4;
	LinkList * list = NULL;
	int linklen = 0, i = 0;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;
	list = LinkList_Create();
	linklen =LinkList_Length(list);
	LinkList_Insert(list, (LinkListNode*)&t1, linklen);
	LinkList_Insert(list, (LinkListNode*)&t2, linklen);
	LinkList_Insert(list, (LinkListNode*)&t3, linklen);
	LinkList_Insert(list, (LinkListNode*)&t4, linklen);
	//遍历链表
	for (i = 0; i<LinkList_Length(list); i++){
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp != NULL){
			printf("1_tmp->age:%d\n", tmp->age);
		}
	}
	//从链表删除元素
	while (LinkList_Length(list)>0){
		Teacher* tmp = (Teacher*)LinkList_Delete(list,0);
		if (tmp != NULL){
			printf("2_tmp->age:%d\n", tmp->age);
		}
	}
	//销毁链表
	LinkList_Destroy(list);
	system("pause");

}