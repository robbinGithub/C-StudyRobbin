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

	float f = 1.2;
	float f2 = 8388608.12;
	float f3 = 838860.12;

	system("pause");
}