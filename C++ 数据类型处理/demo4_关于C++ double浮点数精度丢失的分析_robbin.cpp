#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include<iomanip>
// #include<decimal>

void con_float(float n);

using namespace std;

/*
 * ���������ڴ��еı�ʾ

 *  ����(float)�� @see https://www.zhihu.com/question/46432979
    
	8bits��ָ��λ�� 
    23bits��β��λ�����������8388607   11111111111111111111111  838.8607��
	������ָһ����λ����123456.7

  
 *   
 *
 *  ����ת�����ߣ�          http://tool.oschina.net/hexconvert/
 *  �����ȸ������ڴ��б��룺https://www.h-schmidt.net/FloatConverter/IEEE754.html
 *
 * @see https://www.cnblogs.com/c-primer/p/5992696.html
 *      https://blog.csdn.net/cai870808/article/details/24907853
 *      http://blog.chinaunix.net/uid-26748719-id-3316174.html
 */

void test_401()
{


	// @see https://www.zhihu.com/question/46432979

	// ������ת����
	// ʮ���ƣ�  12344.567
	// �����ƣ�  11000000111000.10010001001001101110100101111000110101

	// ����ѧ������
	// 1.10000001110001001000100 1001101110100101111000110101 * 2^13 
	// ����:  0
	// ָ���� 13  13+127 = 140 =>10001100
    // β���� 10000001110001001000100 ȡβ��23λ������23λ��0������23λ��1���λ������������)

	// ���ڴ��б�ʾ��
	// �ڴ��д洢�����ƣ�0 10001100 10000001110001001000101 

	// ��C++�����б�ʾ��
	// f5:12344.567383, address:0042F974
	// 1.10000001110001001000101 * 2^13
    // = 11000000111000.1001000101 = 12344.5673828125

	float f1 = 12344.567;
	printf("f1��%f, address:%p\n", f1, &f1);
	
	float f7 = 2.5; //  2.2
	printf("f7:%f, address:%p\n", f7, &f7);
	con_float(f7);

	float f8 = 105.207;
	printf("f8:%f, address:%p\n", f8, &f8);
	cout << "cout f8:" << f8 << endl;
	con_float(f8);

	// https://www.cnblogs.com/SugarLSG/p/3534248.html
	float f9 = 198903.19; // 00110000101000111101100
	printf("f9:%f, address:%p\n", f9, &f9);
	con_float(f9);
}

/*
 * ��������ת��ΪС��
 * @see https://www.cnblogs.com/xiehongfeng100/p/4851201.html 
        http://zhan.renren.com/programming4idiots?gid=3602888498026486936&checked=true
 */
void test_041()
{
	float input;
	unsigned long long nMem;
	while (1)
	{
		cout << "������Ҫת����С����" << endl;
		cin >> input;
		nMem = *(unsigned long long *)&input;
		bitset<32> myBit(nMem);
		cout << myBit << endl;
	}
}

// ����������ת��ΪС��
void test_042()
{
	float rst;
	bitset<32> input;
	cout << "��������Խ��û�����Ķ������밴��IEEE-754��׼ת��ΪС����" << endl;
	cout << endl;
	//while (1)
	//{
		cout << "������Ҫת���Ķ������룺" << endl;
		cin >> input;
		rst = *(float *)&input;             // ��ȡ�ڴ��б����input��ֵ������������ʽ���
		cout << "ת�����Ϊ��" << endl;
		cout << rst << endl;
		cout << endl;
	//}
}

/*
 * �������Ƚϣ�

 * �Ӹ����ӿ��Կ���������ͬһ��С�������ò�ͬ���ȱ�ʾʱ������ǲ�һ���ģ�����ֱ���õȺűȽϴ�С
 * @see https://www.cnblogs.com/xiehongfeng100/p/4851201.html
 */
void test_403()
{
	float a = (float)0.1;
	float b = (float)0.1;
	if (a == b)
		cout << "a == b" << endl;
	else
		cout << "a == b" << endl;

	float c = (float)0.1;
	double d = (double)0.1;
	if (c == d)
		cout << "c == d" << endl;
	else
		cout << "c != d" << endl;

	float e = (float)0.1;
	float f = (double)0.1;
	if (abs(e - f) < 0.0001)
		cout << "e == f" << endl;
	else
		cout << "e != f" << endl;

}

// printf��������������� 
// cout ������ȿ���
// @see http://blog.sina.com.cn/s/blog_73428e9a0102xlev.html
void test_404()
{

	float f1 = 0.3;
	printf("%f\n", f1);

	f1 = 0.3;
	printf("%.8f\n", f1);

	f1 = 0.3;
	printf("%.8lf\n", f1);

	f1 = 0.3;
	printf("%.18lf\n", f1);

	//0.3�Ķ����ƽ��Ϊ��0.0100110011001100110011001100110011001100110011001101
	//��ȻԶ��ֹ��ô��λ��׼ȷ�Ľ�Ӧ����һ������С����

	double f = 3.1415926535;
	cout << "Enter the huashi temperature:" << endl;
	//-----------------����һ-------------------
	/*	cout.precision(3);		//����cout��precision()�������û򷵻ص�ǰҪ����ʾ�ĸ��������λ�����������������ָ�����
	cout << fixed;		//fixed���С���������λ��Ч����
	cout << "The Celsius temperature is: ";
	cout << f << endl;		//���С����ǰ����λ��Ч����
	cout << f << endl;
	*/
	//----------------������--------------------
	//ʹ��setprecision()����������������iomanipͷ�ļ���
	cout << f << endl;				//Ĭ�������λ
	cout << setprecision(3);		//����setprecision��������ʾ����Ч����λ����
	cout << setprecision(0) << f << endl;
	cout << setprecision(1) << f << endl;
	cout << setprecision(2) << f << endl;
	cout << setprecision(3) << f << endl;
	cout << setprecision(4) << f << endl;
	cout << "---------------------------------" << endl;
	cout << setiosflags(ios::fixed);	//���setprecision��������С������(С��������Чλ��)
	//cout << fixed;				//��Ϊcout��һ��������setiosflags(ios::fixed)�ļ�д��ʽ����Ч����һ��
	cout << setprecision(0) << f << endl;
	cout << setprecision(1) << f << endl;
	cout << setprecision(2) << f << endl;
	cout << setprecision(3) << f << endl;
	cout << setprecision(4) << f << endl;

}

/*
 * C++ С�����㾫������
 */

void test_405()
{

	float a = 1.123;
	float b = 1.234;
	float c = a + b;

	cout << c;

	// ��ʱ c = 2.3569999
}

int main()
{
	test_404();
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