#include <stdio.h>
#include <stdlib.h>
/*
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

	float f = -1.2;
	float f2 = 8388608.12;
	float f3 = 838860.12;
	float f4 = 83.8860812;

	printf("f2 + 1:%f \n", f2 + 1); // 8388609.000000
	printf("f3 + 1:%f \n", f3 + 1); // 838861.125000

	printf("f1 address:%p\n", &f);
	printf("f4 address:%p\n", &f4);

	// f4: acc5a742
	// 1bit（符号位） 8bits（指数位）   23bits（尾数位）
    // 1              01011001          10001011010011101000010

	// f1
	// 1 00110101 00110011001100100111111

	system("pause");
}