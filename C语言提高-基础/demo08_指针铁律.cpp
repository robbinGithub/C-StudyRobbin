/*
* 指针铁律

  铁律1:指针也是一种数据类型

* @author:robbin.zhang
* @date:2018/01/25 10:57
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>‘

int main_08(void)
{   
	// 字符串拷贝
	char buf1[100] = { 0 };
	char buf2[100];// = { 0 };
	memset(buf2, 0, 100);
	char *p1 = buf1;
	char *p2 = buf2;

	strcpy(buf1, "abcdefg");
	while (*p1 != '\0')
	{ 
		*p2 = *p1;
		p2++;
		p1++;
	}
	printf("buf2:%s\n", buf2);

	
	int a = 10;
	int *p = NULL; // int *********p = NULL;
	p =  &a;
	*p = 20;

	printf("a:%d\n", a);

	system("pause");
	return 0;
}

