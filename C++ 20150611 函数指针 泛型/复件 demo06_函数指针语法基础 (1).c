#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int array2[10];
//定义一个数组类型
typedef int (ArrayType)[10];

//定义一个指向数组的 数组指针类型 
typedef int (*PArrayType)[10];  // int *

void main_数组类型复习()
// void main()
{
	//由数组类型定义变量
	ArrayType array; //int array2[10];
	array[0] = 1;

	printf("array:%p\n", array);
	printf("&array:%p\n", &array);

	{
		//用数组指针类型  去定义一个指针 
		PArrayType arrayp; //定义一个指向数组类型的指针
		arrayp = &array;

		printf("&arrayp:%p\n", arrayp);
		printf("(*arrayp):%p\n", (*arrayp));
		printf("(*arrayp)[0]:%p\n", (*arrayp)[0]);
		printf("*((*arrayp)+ 0):%p\n", (*arrayp)[0]);

		(*arrayp)[0] = 2;
	}

	{
		//直接定义一个指向数组类型的指针
		int (*myParray)[10] =  &array;
			(*myParray)[0] = 3;
	}

	printf("hello...\n");
	system("pause");
}

//定义一个函数类型 
typedef int Func(int); //int类型参数及int类型返回值

//函数名称就代表函数的入口地址 函数名称本身就是一个指针
int test(int a)
{
	return a*a;
}

void main12()
{
	//用函数类型 定义一个函数指针
	Func *myfun = NULL;
	myfun = test;

	//通过函数指针（函数的入口地址）可以指向函数体。（言外之意可以进行函数调用）
	//printf("%d \n", myfun(2));

	//对函数名取多少地址 都是一样
	myfun = &test;
	printf("%d \n", myfun(2));

	//通过通过函数指针可以执行一个函数调用

	//(*(*(test)));

	system("pause");
}

void f()
{
	printf("执行了f\n");
}
void main_061()
{
	//直接定义一个函数指针，并且赋值 
	void (*myf1)() = f;
	void (*myf2)() = &f;

	myf2();
	myf1();

	system("pause");
}