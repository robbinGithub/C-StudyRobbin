#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int array2[10];
//����һ����������
typedef int (ArrayType)[10];

//����һ��ָ������� ����ָ������ 
typedef int (*PArrayType)[10];  // int *

void main_�������͸�ϰ()
// void main()
{
	//���������Ͷ������
	ArrayType array; //int array2[10];
	array[0] = 1;

	printf("array:%p\n", array);
	printf("&array:%p\n", &array);

	{
		//������ָ������  ȥ����һ��ָ�� 
		PArrayType arrayp; //����һ��ָ���������͵�ָ��
		arrayp = &array;

		printf("&arrayp:%p\n", arrayp);
		printf("(*arrayp):%p\n", (*arrayp));
		printf("(*arrayp)[0]:%p\n", (*arrayp)[0]);
		printf("*((*arrayp)+ 0):%p\n", (*arrayp)[0]);

		(*arrayp)[0] = 2;
	}

	{
		//ֱ�Ӷ���һ��ָ���������͵�ָ��
		int (*myParray)[10] =  &array;
			(*myParray)[0] = 3;
	}

	printf("hello...\n");
	system("pause");
}

//����һ���������� 
typedef int Func(int); //int���Ͳ�����int���ͷ���ֵ

//�������ƾʹ���������ڵ�ַ �������Ʊ������һ��ָ��
int test(int a)
{
	return a*a;
}

void main12()
{
	//�ú������� ����һ������ָ��
	Func *myfun = NULL;
	myfun = test;

	//ͨ������ָ�루��������ڵ�ַ������ָ�����塣������֮����Խ��к������ã�
	//printf("%d \n", myfun(2));

	//�Ժ�����ȡ���ٵ�ַ ����һ��
	myfun = &test;
	printf("%d \n", myfun(2));

	//ͨ��ͨ������ָ�����ִ��һ����������

	//(*(*(test)));

	system("pause");
}

void f()
{
	printf("ִ����f\n");
}
void main_061()
{
	//ֱ�Ӷ���һ������ָ�룬���Ҹ�ֵ 
	void (*myf1)() = f;
	void (*myf2)() = &f;

	myf2();
	myf1();

	system("pause");
}