#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>
// #include<decimal>

void con_float(float n);

using namespace std;

/*
 * 浮点数在内存中的表示

 *  举例(float)： @see https://www.zhihu.com/question/46432979
    
	8bits（指数位） 
    23bits（尾数位），最大整数8388607   11111111111111111111111  838.8607万
	精度是指一共七位比如123456.7

  
 *   
 *
 *  进制转换工具：          http://tool.oschina.net/hexconvert/
 *  单精度浮点数内存中编码：https://www.h-schmidt.net/FloatConverter/IEEE754.html
 *
 * @see https://www.cnblogs.com/c-primer/p/5992696.html
 *      https://blog.csdn.net/cai870808/article/details/24907853
 *      http://blog.chinaunix.net/uid-26748719-id-3316174.html
 */

void test_401()
{


	// @see https://www.zhihu.com/question/46432979

	// 【进制转换】
	// 十进制：  12344.567
	// 二进制：  11000000111000.10010001001001101110100101111000110101

	// 【科学计数】
	// 1.10000001110001001000100 1001101110100101111000110101 * 2^13 
	// 符号:  0
	// 指数： 13  13+127 = 140 =>10001100
    // 尾数： 10000001110001001000100 取尾数23位，不足23位补0，超过23位，1则进位。（精度问题)

	// 【内存中表示】
	// 内存中存储二进制：0 10001100 10000001110001001000101 

	// 【C++语言中表示】
	// f5:12344.567383, address:0042F974
	// 1.10000001110001001000101 * 2^13
    // = 11000000111000.1001000101 = 12344.5673828125

	float f1 = 12344.567;
	printf("f1：%f, address:%p\n", f1, &f1);
	
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
 * 二进制码转换为小数
 * @see https://www.cnblogs.com/xiehongfeng100/p/4851201.html 
        http://zhan.renren.com/programming4idiots?gid=3602888498026486936&checked=true
 */
void test_041()
{
	float input;
	unsigned long long nMem;
	while (1)
	{
		cout << "请输入要转换的小数：" << endl;
		cin >> input;
		nMem = *(unsigned long long *)&input;
		bitset<32> myBit(nMem);
		cout << myBit << endl;
	}
}

// 将二进制码转换为小数
void test_042()
{
	float rst;
	bitset<32> input;
	cout << "本程序可以将用户输入的二进制码按照IEEE-754标准转换为小数。" << endl;
	cout << endl;
	//while (1)
	//{
		cout << "请输入要转换的二进制码：" << endl;
		cin >> input;
		rst = *(float *)&input;             // 获取内存中保存的input的值并按浮点数格式表达
		cout << "转换结果为：" << endl;
		cout << rst << endl;
		cout << endl;
	//}
}

/*
 * 符点数比较：

 * 从该例子可以看出，对于同一个小数，当用不同精度表示时，结果是不一样的，不能直接用等号比较大小
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

// printf输出浮点数的问题 
// @see http://blog.sina.com.cn/s/blog_73428e9a0102xlev.html
void test_404()
{

	float f = 0.3;
	printf("%f\n", f);

	f = 0.3;
	printf("%.8f\n", f);

	f = 0.3;
	printf("%.8lf\n", f);

	f = 0.3;
	printf("%.18lf\n", f);

	//0.3的二进制结果为：0.0100110011001100110011001100110011001100110011001101
	//当然远不止这么多位，准确的讲应该是一个无限小数。

}

/*
 * C++ 小数运算精度问题
 */

void test_405()
{

	float a = 1.123;
	float b = 1.234;
	float c = a + b;

	cout << c;

	// 此时 c = 2.3569999
}

int main()
{
	test_405();
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