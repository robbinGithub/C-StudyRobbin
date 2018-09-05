#include <stdio.h>
#include <stdlib.h>

void con_float(float n);

/*
 * 
 *  ����(float)�� @see https://www.zhihu.com/question/46432979
    
	8bits��ָ��λ�� 
    23bits��β��λ�����������8388607   11111111111111111111111  838.8607��

    78.375   
    1001110.011
    
    8388607   23λ
	4194303   22λ
    2097151   21λ
 *   
 *
 * @����ת������ http://tool.oschina.net/hexconvert/
 *
 * @see https://www.cnblogs.com/c-primer/p/5992696.html
 *      https://blog.csdn.net/cai870808/article/details/24907853
 *      http://blog.chinaunix.net/uid-26748719-id-3316174.html
 */


int main()
{
	long a = 123456; //assign any long number here
	double db = a;
	long b = db;
	printf("%s\n", a == b ? "true" : "false");

	float f1 = -1.2;
	float f2 = 8388608.12;
	float f3 = 838860.12;
	float f4 = 83.8860812;
	float f5 = 12344.567; // 2097151.25  2097151.375  12344.567

	// @see https://www.zhihu.com/question/46432979

	// ������ת����
	// ʮ���ƣ�  12344.567
	// �����ƣ�  11000000111000.10010001001001101110100101111000110101

	// ����ѧ������
	// 1.100000011100010010001001001101110100101111000110101
	// ����:  0
	// ָ���� 13  13+127 = 140 =>10001100
    // β���� 10000001110001001000100 �����Ƴ���1001101110100101111000110101,β������23λ,���һλ1���λ

	// ���ڴ��б�ʾ��
	// �ڴ��д洢�����ƣ�0 10001100 10000001110001001000101

	// ��C++�����б�ʾ��
	// f5:12344.567383, address:0042F974
	// 1.10000001110001001000101 * 2^13
    // = 11000000111000.1001000101 = 12344.5673828125

	printf("f1 address:%p\n", &f1);
	printf("f2 + 1:%f \n", f2 + 1); // 8388609.000000
	printf("f3 + 1:%f \n", f3 + 1); // 838861.125000
	printf("f4 address:%p\n", &f4);

	printf("f5:%f, address:%p\n",f5, &f5); 

	con_float(f5);

	// f4: acc5a742
	// 1bit������λ�� 8bits��ָ��λ��   23bits��β��λ��
    // 1              01011001          10001011010011101000010

	// f1
	// 1 00110101 00110011001100100111111

	system("pause");
}

void con_float(float n)
{
	for (unsigned int i = 0, j = 0x80000000; i < 32; i++)
	{
		printf("%d", (*(unsigned int*)&n)&j >> i ? 1 : 0);
		if ((i + 1) % 4 == 0 && i < 31)
			printf(".");
		if (i == 31)
			printf("\n");
	}
}