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

void copyObj01(Teacher from,Teacher to)
{
	memcpy(&to, &from, sizeof(Teacher));
}

void copyObj02(Teacher *from, Teacher *to)
{
	memcpy(to,from, sizeof(Teacher));
}



void main02()
{
	Teacher t1 = { "robbin", 28 };
	Teacher t2 = { "tony", 30 };
	Teacher *p = NULL;
	//copyObj01(t1, t2);
	copyObj02(&t1, &t2);
	p = &t2;
	printf("%s:\n", t2.name);
	printf("%s:\n", p->name);
	system("pause");
}





void main01()
{
	Teacher t1 = { "robbin", 28 };
	Teacher t2;
	Teacher *p = NULL;
	//t2 = t1;
	p = &t2;
	memcpy(&t2, &t1, sizeof(Teacher));
	printf("%s:\n", t2.name);
	printf("%s:\n", p->name);
	system("pause");
}



