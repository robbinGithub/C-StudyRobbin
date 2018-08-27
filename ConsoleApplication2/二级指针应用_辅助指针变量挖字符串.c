#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
有一个字符串符合以下特征（”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";）,要求写一个函数（接口），输出以下结果
1）	以逗号分割字符串，形成二维数组，并把结果传出；
2）	把二维数组行数运算结果也传出。
strchr(“aa,aa”,’,’ );
请自己定义一个接口（函数）。
要求1：能正确表达功能的要求，定义出接口（函数）（30分）；
要求2：正确实现接口（函数），并实现功能（40分）；
要求3：编写正确的测试用例。（30分）。
*/


int splitString( char *str, char delim, char buf[10][30], int *count)
{
	int rv = 0;
	int ncount = 0;
	char *p = NULL;
	char *p2 = NULL;
	if (str == NULL || buf == NULL)
	{
		return -1;
	}
	p2 = str;
	p = str;

	// ”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,"
    /*
	p = strchr(str, delim);
	while(p != NULL){

		int len = (p - p2);
		strncpy(buf[ncount], p2, len);
		buf[ncount][len] = '\0';
		ncount++;
		p2 = p = p+1;
		p = strchr(p, delim);
	}*/

	while (*p != '\0'){

		p = strchr(p, delim);
		int len = (p - p2);
		strncpy(buf[ncount], p2, len);
		buf[ncount][len] = '\0';
		ncount++;
		p2 = p = p + 1;

	}

	*count = ncount;

	return rv;
}


int splitString_02(char *str, char delim, char buf[10][30], int *count) 
{
	int rv = 0;
	int ncount = 0;
	char *p = NULL;
	char *pTmp = NULL;
	if (str == NULL || buf == NULL)
	{
		return -1;
	}
	pTmp = str;
	p = str;

	// ”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx,"

	do{

		p = strchr(p, delim);
		if (p == NULL) //没有找到则跳出来
		{
			strcpy(buf[ncount], pTmp);
			ncount = ncount + 1;
			break;
		}
		else
		{
			int len = (p - pTmp);
			strncpy(buf[ncount], pTmp, len);
			buf[ncount][len] = '\0';
			ncount++;
			pTmp = p = p + 1;
		}
		
		
	} while (*p != '\0');  // 匹配至字符串结束

	*count = ncount;

	return rv;
}

int splitString_03(char *str, char delim, char **buf, int *count)
{
	int rv = 0;
	int ncount = 0;
	char *p = NULL;
	char *pTmp = NULL;
	if (str == NULL || buf == NULL)
	{
		return -1;
	}
	pTmp = str;
	p = str;

	// ”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx,"

	do{

		p = strchr(p, delim);
		if (p == NULL) //没有找到则跳出来
		{
			strcpy(buf[ncount], pTmp);
			ncount = ncount + 1;
			break;
		}
		else
		{
			int len = (p - pTmp);
			strncpy(buf[ncount], pTmp, len);
			buf[ncount][len] = '\0';
			ncount++;
			pTmp = p = p + 1;
		}


	} while (*p != '\0');  // 匹配至字符串结束

	*count = ncount;

	return rv;
}

void test_splitString()
{

	int ret = 0, i = 0;
	char *str = " abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx";
	int count = 0;
	char delim = ',';
	char buf[10][30];
	ret = splitString_02(str, delim, buf, &count);
	if (ret != 0)
	{
		printf("func spitString() err:%d\n", ret);
		return;
	}
	for (i = 0; i<count; i++)
	{
		printf("%s\n", buf[i]);
	}

}

void test_splitString_03()
{

	int ret = 0, i = 0;
	char *str = " abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx";
	int count = 0;
	char delim = ',';

	// char buf[10][30];

	char ** buf = malloc(10 * sizeof(char *));
	if (buf == NULL)
	{
		printf("malloc err:");
		goto End;
	}

	for (i = 0; i < 10; i++)
	{
		*(buf + i) = (char*)malloc(100);
		if (*(buf + i) == NULL)
		{
			printf("malloc err:");
			goto End;
		}
	}

	ret = splitString_03(str, delim, buf, &count);
	if (ret != 0)
	{
		printf("func spitString() err:%d\n", ret);
		goto End;
	}
	for (i = 0; i < count; i++)
	{
		printf("%s\n", buf[i]);
	}

	
End:
	// free
	if (buf != NULL)
	{
		for (i = 0; i < 10; i++)
		{
			free(buf[i]);
		}

		free(buf);
		buf = NULL;
	}
}

int test_strchr()
{
	const char str[] = "http://www.runoob.com";
	const char ch = '&';
	char *ret;

	ret = strchr(str, ch);

	// if (ret == NULL)
	if (ret == '\0')
	{
		printf("未在串中查找给定字符\n");
	}
	else
	{
		printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);
	}

	return(0);

}

int main_06()
{
	//test_splitString();
	test_splitString_03();
	//test_strchr();

	system("pause");
}

