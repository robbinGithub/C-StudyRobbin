#include <stdio.h>
#include <stdlib.h>

int getStr(const char *p)
{
	// p[0] = 'a';
	p = 0x1;
	p = 0x2;

	return 0;
}

int getStr2(char * const p)
{
    p[0] = 'a';
	// p = 0x1;
	// p = 0x2;
	return 0;
}

int getStr3(const char * const p)
{
	// p[0] = 'a';
	// p = 0x1;
	// p = 0x2;
	return 0;
}


int main()
{
	const int a;
	int const b;  // const ���� a��b������ͬ

	// ������ָ�� c��ָ����ڴ�ռ䲻���޸�
	const char *c1;
	char const *c2;

	// ָ�볣��   ָ�벻��ָ�������ڴ�ռ�
	char * const d1;  // д��1
	char const * d2;  // д��2

	const char * const e1;  // ָ���ָ������ݶ������޸�
	const char const * e2;  // ָ���ָ������ݶ������޸�

	printf("OK! \n");
	system("pause");

	return 0;

}