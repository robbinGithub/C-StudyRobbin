#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main21()
{
	int i = 0, j = 0;

	char buf[30];
	char myArray[10][30] = { "ccccc", "aaaa", "bbbb", "11111" };


	//��ӡ�ڶ����ڴ�ģ��
	for (i = 0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	//����
	for (i = 0; i<4; i++)
	{
		for (j = i + 1; j<4; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(buf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], buf);
			}
		}
	}

	// ��ӡ�ڶ����ڴ�ģ��
	for (i = 0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}
	system("pause");
}

//ָ�����Ͳ�һ����=====���ڴ�ģ�Ͳ�һ���ɡ�������
//û���ڴ�������ָ�밡��������
int	printfArr22(char **ArrayStr, int iNum)
{
	int i = 0;
	for (i = 0; i<iNum; i++)
	{
		printf("%s \n", ArrayStr[i]);
	}
	return 0;
}

//int array[10]===>int *array===>
//	int	printfArr22(char array[10], int iNum);
int	printfArr23(char myArray[10][30], int iNum)
{
	int i = 0;
	for (i = 0; i<iNum; i++)
	{
		printf("%s \n", myArray[i]);
	}
	return 0;
}

//	int	printfArr22(char array[10], int iNum);
int	sortArr23(char myArray[10][30], int iNum)
{
	int i = 0, j = 0;
	char buf[30]; //buf����������������Ԫ�صĵ�ַ
	//����
	for (i = 0; i<iNum; i++)
	{
		for (j = i + 1; j<iNum; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(buf, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], buf);
			}
		}
	}
}

void main()
{
	int i = 0;
	char myArray[10][30] = { "ccccc", "aaaa", "bbbb", "11111" }; //myArray����������ʲô����ש

	//��ӡ�ڶ����ڴ�ģ��
	for (i = 0; i<4; i++)
	{
		printf("%s \n", myArray[i]);
	}

	printf("�ڶ����ڴ�ģ�ͣ�����֮ǰ\n");
	printfArr23(myArray, 4);
	//printfArr23(myArray[10][30], 4);

	sortArr23(myArray, 4);

	printf("�ڶ����ڴ�ģ�ͣ�����֮��\n");
	printfArr23(myArray, 4);
	system("pause");
}