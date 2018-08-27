#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int add(int a, int b);
//第二个函数 是函数指针 做函数参数 
//在这个函数里面，就可以通过这个函数指针，去调用外部的函数，形成一个回调
int libfun(  int (*pDis)(int a, int b)  );

int main_07(void)
{
	//直接定义了一个函数指针
	int (*pfun)(int a, int b);
	//函数名赋给函数指针，函数的入口地址付给了pfunc
	pfun = add;
	libfun(pfun);

}
int add(int a, int b)
{
	return a + b;
}

//pDis是add的入口地址
int libfun(int (*pDis)(int a, int b))
{
	int a, b;
	a = 1;
	b = 2;
	printf("%d", pDis(a, b)); //执行了add函数调用
}
