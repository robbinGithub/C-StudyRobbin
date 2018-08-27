#include <stdlib.h>
#include <stdio.h>


int main_066()
{

	int i = 0;

	// 指针数组
	char *p1[] = { "123", "456", "789" };

	// 二维数组
	char p2[3][4] = { "123", "456", "789" };

	// 手工二维内存
	char **p3 = (char **)malloc(3 * sizeof(char *));
	for (i = 0; i < 3; i++)
	{
		p3[i] = (char *)malloc(10 * sizeof(char));
		sprintf(p3[i], "%d%d%d", i, i, i);
	}

	system("pause");
}

int main_072()
{
	/*
	【指针数组】
	 p1 = 0x0020fbe8 {0x003e7884 "123", 0x003e789c "456", 0x003e78c0 "789"}
	 p1:指针数组首地址
	 p1的地址：0x0020FBE8
	 p1的值:0x003e7884 (数组首个元素的地址) 指针常量
	 &p1:0x003e7884 指针数组类型指针(指针数组指针)

	 0x0020FBE8  84 78 3e 00

	 0x003e7884
	 0x003e789c
	 0x003e78c0

	*/
	char * p1[] = { "123", "456", "789" }; // 数组 3*4 字节内存
	printf("p1 value:%p \n", p1);
	printf("&p1 value:%p \n", &p1);

	/*
	【数组指针】
	*/
	//  char(*p2)[5] = { "123", "456", "789" }; //Error 指向一个数组的指针(4个字节)，每次跳5 * sizeof(char) = 5个字节

	system("pause");
}
