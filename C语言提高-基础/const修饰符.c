#include <stdio.h>
#include <stdlib.h>

int getStr(const char *p)
{
	// p[0] = 'a';
	p = 0x1;
	p = 0x2;

	return 0;
}

int getStr2(char * const p)
{
    p[0] = 'a';
	// p = 0x1;
	// p = 0x2;
	return 0;
}

int getStr3(const char * const p)
{
	// p[0] = 'a';
	// p = 0x1;
	// p = 0x2;
	return 0;
}


int main()
{
	const int a;
	int const b;  // const 修饰 a、b意义相同

	// 常量的指针 c所指向的内存空间不能修改
	const char *c1;
	char const *c2;

	// 指针常量   指针不可指向其他内存空间
	char * const d1;  // 写法1
	char const * d2;  // 写法2

	const char * const e1;  // 指针和指向的内容都不能修改
	const char const * e2;  // 指针和指向的内容都不能修改

	printf("OK! \n");
	system("pause");

	return 0;

}