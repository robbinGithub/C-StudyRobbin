#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//�ṹ������ڴ�,ע��ÿ�ĸ��ֽڷ���
typedef struct _Teacher
{
	char name[62];
	int age;
	//char title[128];

}Teacher;


void main01() 
{   
	//���߱����������ڴ�
	 Teacher t1;
	 printf("sizeof(t1):%d\n", sizeof(t1));

	 system("pause");

}