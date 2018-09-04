#include <stdio.h>
#include <stdlib.h>
/*
 *
 * @see https://www.cnblogs.com/c-primer/p/5992696.html
 *      https://blog.csdn.net/cai870808/article/details/24907853
 */
int main()
{
	long a = 123456; //assign any long number here
	double db = a;
	long b = db;
	printf("%s\n", a == b ? "true" : "false");

	float f = 1.2;

	system("pause");
}