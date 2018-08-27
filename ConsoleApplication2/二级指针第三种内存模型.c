#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int printArray03(char ** pArray, int num)
{
	int i = 0;

	if (pArray == NULL)
	{
		return -1;
	}

	for (i = 0; i < num; i++)
	{
	 // printf("第%d个元素:%s \n", pArray[i]);
		printf("第%d个元素:%s \n", i, *(pArray + i));
	}

	return 0;
}

int sortArray03(char ** pArray, int num)
{
	int i = 0, j = 0;
	char * temp = NULL;

	if (pArray == NULL)
	{
		return -1;
	}

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(pArray[i], pArray[j]) > 0)
			{
				temp = pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = temp;
			}

		}
	}

	return 0;

}


int main_033()
{
	char ** pArray = NULL;
	pArray = (char **)malloc(sizeof(char *) * 100);

	pArray[0] = (char *)malloc(12 * sizeof(char)); //char buf[12];
	pArray[1] = (char *)malloc(200 * sizeof(char)); //char buf[200];
	pArray[2] = (char *)malloc(200 * sizeof(char)); //char buf[200];
	pArray[3] = (char *)malloc(200 * sizeof(char)); //char buf[200];

	strcpy(pArray[0], "cccccc");
	strcpy(pArray[1], "aaaa");
	strcpy(pArray[2], "bbbb");
	strcpy(pArray[3], "11111");

	printArray03(pArray, 4);
	sortArray03(pArray, 4);
	printf("第三种内存排序之后\n");
	printArray03(pArray, 4);

	system("pause");

}