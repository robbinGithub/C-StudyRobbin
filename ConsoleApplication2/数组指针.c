#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 C�����е��������Լ��ض������ͣ��������������ͺ������С����
 @author robbin.zhang 
 @date 2018/01/28 22:44
 */

// ����һ����������
typedef int(MYINT5)[5];
typedef float(MYFLOAT5)[5];

// ����һ������ָ������
typedef  int(*MyPArrType)[5];


typedef struct _Teacher
{
	char name[20];
	int age;

} Teacher;


/*
 * ��ά����ı���
 */
int main_099()
{
	int i = 0, j = 0, tmp = 0;

	int a[3][5] = {0};

	

	int b[5]; // b����������Ԫ�صĵ�ַ�� &b�����������ĵ�ַ &b+1�൱��ָ�����40���ֽ�
	
	printf("a:%d, a+1:%d \n", a, a + 1); // 20

	// a�ı�����һ������ָ��,ָ���ά�����ָ��
	{
		int(*p)[5];
		p = a;

	}

	for (i = 0; i<5; i++)
	{
		b[i] = i + 1;
	}

	
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<5; j++)
		{
			a[i][j] = ++tmp;
		}
	}
	
	
	system("pause");

}

int main_07()
{  

	int i = 0;

	// ����һ������
	MYINT5 myArray;

	for (i = 0; i < 5; i++)
	{
		myArray[i] = i;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", myArray[i]);
	}

	// ����һ���������͵�ָ��
	MYINT5 * pArray = NULL;

	int a[5];
	{
		int a = 1;
		int *p1 = NULL;
		p1 = &a;
		printf("%d \n", p1[1]); // -858993460
	}

	pArray = &a;

	printf("ͨ������ָ�뷽ʽ����a[5]����ڴ�\n");

    // ͨ��ָ�뷽ʽ����a[5]����ڴ�
	for (i = 0; i < 5; i++)
	{
		(*pArray)[i] = i + 1;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d \n", (*pArray)[i]);
	}


	printf("ͨ������ָ�����a[5]����ڴ�\n");

	// ͨ������ָ�����a[5]����ڴ�
	MyPArrType myPoint = &a;
	for (i = 0; i < 5; i++)
	{
		printf("%d \n", (*myPoint)[i]);
	}


	// �ܽ᣺����ָ������ָ��һ������

	{
		// ����һ���������� int[5]
		typedef int MyArrayType[5];
		// ����һ���������͵�ָ��
		MyArrayType *pArray = NULL;
	}
	{
		// ֱ�Ӷ���һ��ָ�������ָ������ int(* p)[5]
		typedef int(*MyPArrType)[5];
		MyPArrType myPoint;
	}
	{
		// ����һ��ָ�����
		int(*myArrayPoint)[5]; //���߱����������ĸ��ֽ��ڴ棬�����������ǰ��

	}

	// ����һ��ָ������
	// char *[] pp

	Teacher t;

	system("pause");

}