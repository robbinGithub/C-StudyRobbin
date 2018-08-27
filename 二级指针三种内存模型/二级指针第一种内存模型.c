#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//二级指针第一种内存模型
void main01()
{
	int i = 0, j = 0;
	char *tmp = NULL;

	char *ArrayStr[] = { "ccccc", "aaaa", "bbbb", "11111" };  // 指针数组

	for (i = 0; i<4; i++)
	{
		printf("%s \n", ArrayStr[i]);
	}

	//排序

	for (i = 0; i<4; i++)
	{
		for (j = i + 1; j<4; j++)
		{
			if (strcmp(ArrayStr[i], ArrayStr[j]) > 0)
			{
				tmp = ArrayStr[i];
				ArrayStr[i] = ArrayStr[j];
				ArrayStr[j] = tmp;
			}
		}
	}

	for (i = 0; i<4; i++)
	{
		printf("%s \n", ArrayStr[i]);
	}

	system("pause");
}

int	printfArr(char **ArrayStr, int iNum)
{
	int i = 0;
	for (i = 0; i<iNum; i++)
	{
		printf("%s \n", ArrayStr[i]);
	}
	return 0;
}

int sortArrayStr(char **ArrayStr, int iNum)
{
	int i = 0, j = 0;
	char *tmp = NULL;
	//从小到大从排序

	for (i = 0; i<iNum; i++)
	{
		for (j = i + 1; j<iNum; j++)
		{
			if (strcmp(ArrayStr[i], ArrayStr[j]) > 0)
			{
				tmp = ArrayStr[i];
				ArrayStr[i] = ArrayStr[j];
				ArrayStr[j] = tmp;
			}
		}
	}
	return 0;
}

//二级指针第一种内存模型
void main1232()
{
	char *ArrayStr[] = { "ccccc", "aaaa", "bbbb", "11111" }; // 指针数组  ArrayStr指向指针数组首地址的地址   *ArrayStr指针数组首地址
	//p2      P     ccccc
	//	            aaaa
	//	            bbbb
	//	            11111
	printf("排序之前\n");
	printfArr(ArrayStr, 4);
	sortArrayStr(ArrayStr, 4);

	printf("排序之后\n");
	printfArr(ArrayStr, 4);

	system("pause");
}