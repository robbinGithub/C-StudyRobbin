#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linklist.h"

typedef struct _Teacher
{
	LinkListNode*node;
	char name[32];
	int age;

}Teacher;



int main()
{  

	LinkList * list = LinkList_Create(&list);

}