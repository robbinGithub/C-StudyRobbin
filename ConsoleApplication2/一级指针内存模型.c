#include <stdlib.h>
#include <stdio.h>

int main_01()
{
	int i = 0;
	int *p = &i;
	printf("p value:%p  \n", p);

	/*
	 * 0x010B144A ���ĵ�һ�����쳣(�� C�������-ָ��.exe ��):  0xC0000005:  д��λ�� 0x010B5868 ʱ�������ʳ�ͻ��
	 * "robbin"��ȫ�������������޸�
     */
	char *p2 = "robbin";
	//*p2 = 's';
	
	/*
		0x0046FCCC  01 00 00 00  ....  a+0           &a
		0x0046FCD0  02 00 00 00  ....  a+1 
		0x0046FCD4  03 00 00 00  ....  a+2
		0x0046FCD8  04 00 00 00  ....  a+3
		0x0046FCDC  05 00 00 00        a+4
		0x0046FCE0  cc cc cc cc                      &a+1

	   intArr ֵ��0x0046FCCC
	   intArr ��ַ��0x________
	*/

	/* 
	   a����������Ԫ�صĵ�ַ����һ��ָ������Ԫ�ص�ָ�볣��
	   &a��������ĵ�ַ,ָ����m��Ԫ����ɵ�һά�����ָ�����
	   a��&aֵ��ͬ���������Ͳ�ͬ��������ͬ
	 */
	int a[5] = { 1, 2, 3, 4, 5 };
	printf("����Ԫ��ָ��:%p \n", a);  
	printf("����Ԫ��ָ��+1:%p \n", a + 1);
	printf("����ָ��:%p \n", &a);
	printf("����ָ��+1:%p \n", &a + 1);


	// sizeof
	printf("sizeof(a[10]):%d\n", sizeof(a)); // 20
	printf("sizeof(&a):%d\n", sizeof(&a));   // 4 ����ָ��&a+1���������20���ֽ�
	printf("sizeof(*a):%d\n", sizeof(*a));   // 4
	printf("sizeof(a[0]):%d\n", sizeof(a[0]));// 4

	system("pause");

}