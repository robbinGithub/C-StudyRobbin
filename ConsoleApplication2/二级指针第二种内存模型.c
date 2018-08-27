#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
  ����ָ��ڶ����ڴ�ģ��
  @author robbin.zhang
  @date 2018/01/27 14:58

  */

// һά����ָ���˻�
//void printfArray(int a[10]);
//void printfArray(int a[]);
//void printfArray(int *a);


// ��ά����ָ���˻�
// int printfArray2(char pArray[10][30], int num)//  OK
// int printfArray2(char pArray[][30], int num)//  OK
 int printfArray2(char(*pArray)[30], int num) // OK ����ָ�� 
{
	int rv = 0;
	int i = 0;
	if (pArray == NULL)
	{
		return -1;
	}
	for (i = 0; i < num; i++)
	{
		printf("��%d��Ԫ��:%s \n",i, pArray[i]);
	}

	return rv;

}

//int sortArray2(char pArray[10][30], int num)
int sortArray2(char pArray[][30], int num)
{
	int rv = 0;
	int i = 0, j = 0;
	char tmpBuf[30];

	if (pArray == NULL)
	{
		return -1;
	}
	
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(pArray[i], pArray[j]) > 0)
			{
				strcpy(tmpBuf, pArray[i]);
				strcpy(pArray[i], pArray[j]);
				strcpy(pArray[j], tmpBuf);
			}
		}
		
	}

	return rv;

}


int main_024()
{
	
	char bufArray[10][30] = { "cccc", "aaaa", "bbbb", "dddd" };
	bufArray[0][1] = 'e';

	printf("����ǰ���飺\n");
	printfArray2(bufArray, 4);
	sortArray2(bufArray, 4);
	printf("��������飺\n");
	printfArray2(bufArray, 4);

	system("pause");
	
	return 0;
}