#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 C语言中的数组有自己特定的类型，数组类型由类型和数组大小决定
 @author robbin.zhang 
 @date 2018/01/28 22:44
 */

// 定义一个数组类型
typedef int(MYINT5)[5];
typedef float(MYFLOAT5)[5];

// 定义一个数组指针类型
typedef  int(*MyPArrType)[5];


typedef struct _Teacher
{
	char name[20];
	int age;

} Teacher;


/*
 * 多维数组的本质
 */
int main_099()
{
	int i = 0, j = 0, tmp = 0;

	int a[3][5] = {0};

	

	int b[5]; // b代表数组首元素的地址， &b代表这个数组的地址 &b+1相当于指针后移40个字节
	
	printf("a:%d, a+1:%d \n", a, a + 1); // 20

	// a的本质是一个数组指针,指向低维数组的指针
	{
		int(*p)[5];
		p = a;

	}

	for (i = 0; i<5; i++)
	{
		b[i] = i + 1;
	}

	
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			a[i][j] = ++tmp;
		}
	}
	
	
	system("pause");

}

int main_07()
{  

	int i = 0;

	// 定义一个数组
	MYINT5 myArray;

	for (i = 0; i < 5; i++)
	{
		myArray[i] = i;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", myArray[i]);
	}

	// 定义一个数组类型的指针
	MYINT5 * pArray = NULL;

	int a[5];
	{
		int a = 1;
		int *p1 = NULL;
		p1 = &a;
		printf("%d \n", p1[1]); // -858993460
	}

	pArray = &a;

	printf("通过数组指针方式操作a[5]这块内存\n");

    // 通过指针方式操作a[5]这块内存
	for (i = 0; i < 5; i++)
	{
		(*pArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", (*pArray)[i]);
	}


	printf("通过数组指针操作a[5]这块内存\n");

	// 通过数组指针操作a[5]这块内存
	MyPArrType myPoint = &a;
	for (i = 0; i < 5; i++)
	{
		printf("%d \n", (*myPoint)[i]);
	}


	// 总结：数组指针用于指向一个数组

	{
		// 定义一个数组类型 int[5]
		typedef int MyArrayType[5];
		// 定义一个数组类型的指针
		MyArrayType *pArray = NULL;
	}
	{
		// 直接定义一个指向数组的指针类型 int(* p)[5]
		typedef int(*MyPArrType)[5];
		MyPArrType myPoint;
	}
	{
		// 定义一个指针变量
		int(*myArrayPoint)[5]; //告诉编译器开辟四个字节内存，定义变量放在前面

	}

	// 定义一个指针数组
	// char *[] pp

	Teacher t;

	system("pause");

}