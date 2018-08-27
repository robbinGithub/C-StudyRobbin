#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//结构体分配内存,注意每四个字节分配
typedef struct _Teacher
{
	char name[62];
	int age;
	//char title[128];

}Teacher;


void main01() 
{   
	//告诉编译器分配内存
	 Teacher t1;
	 printf("sizeof(t1):%d\n", sizeof(t1));

	 system("pause");

}