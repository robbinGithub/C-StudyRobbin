#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int add(int a, int b);
//�ڶ������� �Ǻ���ָ�� ���������� 
//������������棬�Ϳ���ͨ���������ָ�룬ȥ�����ⲿ�ĺ������γ�һ���ص�
int libfun(  int (*pDis)(int a, int b)  );

int main_07(void)
{
	//ֱ�Ӷ�����һ������ָ��
	int (*pfun)(int a, int b);
	//��������������ָ�룬��������ڵ�ַ������pfunc
	pfun = add;
	libfun(pfun);

}
int add(int a, int b)
{
	return a + b;
}

//pDis��add����ڵ�ַ
int libfun(int (*pDis)(int a, int b))
{
	int a, b;
	a = 1;
	b = 2;
	printf("%d", pDis(a, b)); //ִ����add��������
}
