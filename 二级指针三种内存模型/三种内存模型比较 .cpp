#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//   注释： 先CTRL+K，然后CTRL+C  取消注释： 先CTRL+K，然后CTRL+U

//三种内存模型比较
//第一种模型是指针数组，数组元素完全在栈空间分配内存，但字符串常量是在全局数据区分配空间；
//第二种是二维数组，先是全局数据区有字符串常量，再拷贝到栈空间的数组元素，注意结尾有’\0’，以及数组是线性存储。
//但是需要注意：显示使用二维数组作为函数参数，可以指定指针步长，与直接使用二级指针不一样；
//第三种是手工打造二维内存，总指针在栈空间，各数组元素指针在堆空间，堆空间指向的内存也在堆空间。

/*
 * @see https://blog.csdn.net/saizo123/article/details/77141554
 */
void main_003()
{
	int i = 0;

	//1、第一种内存模型：指针数组
	char *   p1[] = { "123", "456", "789" };
	char *   _p1[] = { "123", "456", "789" };

	//2、第二种内存模型：二维数组
	char p2[3][4] = { "123", "456", "789" };

	//3、第三种内存模型：手工二维内存
	char **p3 = (char **)malloc(3 * sizeof(char *)); //int array[3];

	for (i = 0; i < 3; i++)
	{
		p3[i] = (char *)malloc(10 * sizeof(char)); //char buf[10]

		sprintf(p3[i], "%d%d%d", i, i, i);
	}
}
