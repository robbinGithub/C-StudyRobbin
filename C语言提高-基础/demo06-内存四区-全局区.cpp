/*

 * 内存四区：堆区、栈区、代码区、全局区
 * @author:robbin.zhang
 * @date:2018/01/24 21:12
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *getStr1(){
	char *p = "abcd";
	return p;

}
char *getStr2()
{

	char *p = "abcd";
	return p;
}
char *getStr3()
{
	char buf[100];
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "abcd1");
	return buf;
}

int main_06(void){

	int a = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	char *p4 = NULL;

	char *p5 = NULL;
	char *p6 = NULL;

	// 栈区
	p1 = getStr1();
	p2 = getStr2();

	// 全局区
	p3 = "robbin";
	p4 = "robbi2";

	// 堆区
	p5 = (char *)malloc(5);
	p6 = (char *)malloc(5);

	printf("p1:%d\n", p1);
	printf("p2:%d\n", p2);
	printf("p3:%d\n", p3);
	printf("p4:%d\n", p4);

	printf("p5:%d\n", p5);
	printf("p6:%d\n", p6);

	printf("getStr3():%s\n", getStr3());

	system("pause");

	return 0;

}
