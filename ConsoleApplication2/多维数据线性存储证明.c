#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * 多维数组线性存储证明
 * author robbin.zhang
 * date 2018/01/29 22:28
 */
void printArrayLine(int *p, int num)
{
	int i = 0;
	for (int i = 0; i < num; i++)
	{
		printf("第%d个元素:%d", i, *(p + i));
	}
}

int main_d01()
{

	int a[3][5];
	int i = 0, j = 0;
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = tmp++;
		}
	}
	printArrayLine((int *) a, 15);
	system("pause");
}