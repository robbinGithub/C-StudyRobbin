#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//����ָ���һ���ڴ�ģ��
void main01()
{
	int i = 0, j = 0;
	char *tmp = NULL;

	char *ArrayStr[] = { "ccccc", "aaaa", "bbbb", "11111" };  // ָ������

	for (i = 0; i<4; i++)
	{
		printf("%s \n", ArrayStr[i]);
	}

	//����

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
	//��С���������

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

//����ָ���һ���ڴ�ģ��
void main1232()
{
	char *ArrayStr[] = { "ccccc", "aaaa", "bbbb", "11111" }; // ָ������  ArrayStrָ��ָ�������׵�ַ�ĵ�ַ   *ArrayStrָ�������׵�ַ
	//p2      P     ccccc
	//	            aaaa
	//	            bbbb
	//	            11111
	printf("����֮ǰ\n");
	printfArr(ArrayStr, 4);
	sortArrayStr(ArrayStr, 4);

	printf("����֮��\n");
	printfArr(ArrayStr, 4);

	system("pause");
}