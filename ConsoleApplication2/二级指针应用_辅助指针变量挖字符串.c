#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";��,Ҫ��дһ���������ӿڣ���������½��
1��	�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ��������
2��	�Ѷ�ά��������������Ҳ������
strchr(��aa,aa��,��,�� );
���Լ�����һ���ӿڣ���������
Ҫ��1������ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڣ���������30�֣���
Ҫ��2����ȷʵ�ֽӿڣ�����������ʵ�ֹ��ܣ�40�֣���
Ҫ��3����д��ȷ�Ĳ�����������30�֣���
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

	// ��abcdef,acccd,eeee,aaaa,e3eeeee,sssss,"
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

	// ��abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx,"

	do{

		p = strchr(p, delim);
		if (p == NULL) //û���ҵ���������
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
		
		
	} while (*p != '\0');  // ƥ�����ַ�������

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

	// ��abcdef,acccd,eeee,aaaa,e3eeeee,sssss,xx,"

	do{

		p = strchr(p, delim);
		if (p == NULL) //û���ҵ���������
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


	} while (*p != '\0');  // ƥ�����ַ�������

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
		printf("δ�ڴ��в��Ҹ����ַ�\n");
	}
	else
	{
		printf("|%c| ֮����ַ����� - |%s|\n", ch, ret);
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

