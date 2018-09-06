#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
�ַ�������

C������û���ַ����������ͣ�ͨ���ַ�������ģ���ַ�����C�����ַ�������0��β���ַ�����

@author robbin.zhang
@date 2018/01/25 23:43
*/

/*
 * �ַ�����ʼ��
 */
void str_init()
{

	// ��ָ������
	char buf1[100] = { 'a', 'b', 'c', 'd' };

	// ָ�����ַ���
	char buf2[] = { 'a', 'b', 'c', 'd' };
	char buf3[] = { 'a', 'b', 'c', 'd', '\0' };

	// ͨ���ַ�����ʼ���ַ�����
	char buf4[] = "abcd";

	printf("buf1:%s\n", buf1); // abcd
	printf("buf2:%s\n", buf2); // abcd��������abcd
	printf("buf3:%s\n", buf3); // abcd
	printf("buf4:%s\n", buf4); // abcd

}

/*
 * �ַ�����ķ��� 
 */
void strvisit()
{
	int i = 0;
	char *p = NULL;
	//ͨ���ַ�����ʼ���ַ����� ����׷��\0
	char buf4[] = "abcd";

	for (i = 0; i<strlen(buf4); i++)
	{
		printf("%c", buf4[i]); //p[]
	}

	//[] *�ı��ʵ�����ʲô��
	//*p �����ǳ���Ա�ֹ��ģ���ʾ��ȥ���ü�Ӹ�ֵ
	//���� ֻ�����ǣ�c/c++ ����������������һ��*p�Ĳ���������������
	// buf4[i]======> buf4[0+i] ====>  *(buf4+i)
	//===*(buf4+i)   --> bu4[i];

	printf("\n");

	p = buf4;
	for (i = 0; i<strlen(buf4); i++)
	{
		printf("%c", *(p + i)); //*p 
	}

}


/*
 * �ַ�������
 */
void _strcpy(char *from, char *to){

	while (*to++ = *from++)
	{
		;
	}
}

void test_strcpy()
{
	char buf[100];
	char *from = "robbin";
	_strcpy(from, buf);
	printf("buf:%s\n", buf);
}

/*
 * ����strtok �ֽ��ַ���Ϊһ���ַ���
 * ֻ�ܽ����������
 */

void test_strtok()
{

	char input[16] = "abc,d";
	char *p;

	/* strtok places a NULL terminator
	in front of the token, if found */
	p = strtok(input, ",");
	if (p)   printf("%s\n", p);

	/* A second call to strtok using a NULL
	as the first parameter returns a pointer
	to the character following the token  */
	p = strtok(NULL, ",");
	if (p)   printf("%s\n", p);

	// ѭ����ȡÿһ��Ԫ��
	char input2[] = "a,b,c,d,e,f,g";
	char *sep = ",";
	char *p2 = NULL;
	p2 = strtok(input2, sep);
	while (p2 != NULL)
	{
		printf("%s\n", p2);
		p2 = strtok(NULL, sep);
	}
}

/**
* ��str1�в���str2���ֵĴ���
*/
int strstrctn(char *str1, char* str2)
{

	int ncount = 0;
	char *p = NULL;
	p = str1;
	do
	{

		p = strstr(p, str2);
		if (p == NULL)
		{
			break;
		}
		else
		{
			ncount += 1;
			p = p + strlen(str2);
		}
	} while (p != '\0');

	return ncount;
}

int getCount(char *str, char* substr, int* count)
{
	int rv = 0;
	char *p = str;
	int ncount = 0;
	if (p == NULL || substr == NULL || count == NULL)
	{
		rv = -1;
		printf("func getCount() check (p == NULL || substr == NULL || count == NULL) err:%d", rv);
		return rv;
	}

	do
	{

		p = strstr(p, substr);
		if (p == NULL)
		{
			break;
		}
		else
		{
			ncount += 1;
			p = p + strlen(substr);
		}
	} while (p != '\0');

	*count = ncount;
	printf("count:%d \n", ncount);

	return rv;
}

void test_getCount()
{
	int ret = 0;
	char *str = NULL;
	char *substr = NULL;
	int ncount = 0;
	str = "abcd232safdabcd321";
	substr = "abcd";
	ret = getCount(str, substr, &ncount);
	if (ret != 0){
		printf("func getCount() err:%d", ret);
		return;
	}
	printf("countn:%d \n", ncount);
}

void test_strstrctn()
{

	char buf[100];
	char search[100];
	memset(buf, 0, 100);
	memset(search, 0, 100);
	int ncount = 0;
	printf("������Ҫ�����ҵ��ַ���:\n");
	//scanf("%[^\n]", buf);
	//gets(buf);
	fgets(buf, 100, stdin);

	printf("������Ҫ���ҵ��ַ���:\n");
	//scanf("%[^\n]", search);
	//gets(search);
	fgets(search, 100, stdin);
	ncount = strstrctn(buf, search);
	printf("�����ҵ�%d��\n", ncount);

}

/*����char*ָ��߽�*/
void test_str_pointer_bound()
{
	char *p = "abcd";
	p = p + 14;
	printf("%s", p);
}

/*����char����߽�*/
void test_strarr_pointer_bound()
{
	char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
	char * p = arr;
	p = p + 5;
	printf("%s", p);

}

/*
 * �ַ���trim(��ͷ��ģ��)
 */
static int trimSpace(const char *inbuf, char *outbuf)
{
	int rv = 0;

	if (inbuf == NULL || outbuf == NULL)
	{
		rv = -1;
		printf("func trimSpace err:%d inbuf == NULL || outbuf == NULL", rv);
		return rv;
	}

	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(inbuf) - 1;
	while (isspace(inbuf[i]) && inbuf[i] != '\0')
	{
		i++;
	}
	while (isspace(inbuf[j]) && j > 0)
	{
		j--;
	}
	ncount = j - i + 1;
	strncpy(outbuf, inbuf + i, ncount);
	outbuf[ncount] = '\0';
	return rv;
}

void getstrCount(char *inbuf, int* count)
{

	int ncount = 0;
	int i, j;
	i = 0;
	j = strlen(inbuf) - 1;
	while (isspace(inbuf[i]))
	{
		i++;
	}
	while (isspace(inbuf[j]))
	{
		j--;
	}
	ncount = j - i + 1;
	*count = ncount;
}

/*
 * ��ѡ��ż�ַ���
 */
void getStr1Str2(char *source, char *buf1, char *buf2)
{
	int len = strlen(source);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < len; i++)
	{
		if (i % 2 == 0)
		{
			buf1[j++] = source[i];
		}
		else
		{
			buf2[k++] = source[i];
		}
	}

	buf1[j] = '\0';
	buf2[k] = '\0';

}

/*
 * ��ֵ��key=value�ַ���
 * 1.����key��ȡvalue
 * 2.��ֵ���п�����n����ո�ȥ���ո�   abcefg|key   =    value
 */
int getKeyByValue(char *pKeyValude, char *pKey, char *pValude, int* valuebuflen)
{
	int rv = 0;
	if (pKeyValude == NULL)
	{
		rv = -1;
		printf("func getKeybyValue() err:%d pKeyValude \n", rv);
		return rv;
	}
	if (pKey == NULL)
	{
		rv = -1;
		printf("func getKeybyValue() err:%d pKey=NULL \n", rv);
		return rv;
	}
	if (pValude == NULL)
	{
		rv = -1;
		printf("func getKeybyValue() err:%d pValude \n", rv);
		return rv;
	}
	char *p = strstr(pKeyValude, pKey);
	if (p == NULL)
	{
		rv = -1;
		printf("func getKeybyValue() err:%d û�в��ҵ��ؼ���pKey \n", rv);
		return rv;
	}

	// ab=c=efg|key   =   value
	//           /\
		//           |
	//           p

	p = p + strlen(pKey); //Ϊ��һ�μ�����׼��
	p = strstr(p, "=");
	if (p == NULL)
	{
		rv = -2;
		printf("func getKeybyValue() err:%d ����û��= \n", rv);
		return rv;
	}
	p = p + 1; //Ϊ��һ�μ�����׼��

	rv = trimSpace(p, pValude);
	if (rv != 0)
	{
		printf("func trimSpace() err:%d \n", rv);
		return rv;
	}

	return rv;
}

void test_getKeyByValue()
{
	int ret = 0;
	char *p = "abcdefgadsafd=||name      =     robbin    ";
	char *key = "name";
	int len = 0;
	char value[100];
	ret = getKeyByValue(p, key, value, &len);
	if (ret != 0)
	{
		printf("func getKeybyValue() err:%d \n", ret);
		return;
	}
	printf("%s=%s \n", key, value);

}

/*
 *�ַ�����ת
 */
void strreverse(char *str)
{
	char *p = str;
	char *q = p + strlen(str) - 1;
	char c;
	while (p < q)
	{
		c = *p;
		*p = *q;
		*q = c;
		p++;
		q--;
	}

}
void test_strreverse()
{
	char buf[100] = "abcd";
	strreverse(buf);
	printf("reverse:%s \n", buf);
}

/*

	C �⺯�� int isspace(int c) ����������ַ��Ƿ��ǿհ��ַ���

	' '     (0x20)    space (SPC) �ո��
	'\t'    (0x09)    horizontal tab (TAB) ˮƽ�Ʊ��
	'\n'    (0x0a)    newline (LF) ���з�
	'\v'    (0x0b)    vertical tab (VT) ��ֱ�Ʊ��
	'\f'    (0x0c)    feed (FF) ��ҳ��
	'\r'    (0x0d)    carriage return (CR) �س���
	*/
void test_isspace()
{

	int var1 = 't';
	int var2 = '1';
	int var3 = ' ';
	int var4 = '\0';

	if (isspace(var1))
	{
		printf("var1 = |%c| �ǿհ��ַ�\n", var1);
	}
	else
	{
		printf("var1 = |%c| ���ǿհ��ַ�\n", var1);
	}
	if (isspace(var2))
	{
		printf("var2 = |%c| �ǿհ��ַ�\n", var2);
	}
	else
	{
		printf("var2 = |%c| ���ǿհ��ַ�\n", var2);
	}
	if (isspace(var3))
	{
		printf("var3 = |%c| �ǿհ��ַ�\n", var3);
	}
	else
	{
		printf("var3 = |%c| ���ǿհ��ַ�\n", var3);
	}

	if (isspace(var4))
	{
		printf("var4 = |%c| �ǿհ��ַ�\n", var4);
	}
	else
	{
		printf("var4 = |%c| ���ǿհ��ַ�\n", var4);

	}

}

void test_truefalseValue()
{

	int var1 = '\0'; // ��
	int var2 = ' ';
	int var3 = 0;  // ��
	int var4 = '\n';

	if (var1)
	{
		printf("var1 = |%c| ����ֵ\n", var1);
	}
	else
	{
		printf("var1 = |%c| ������ֵ\n", var1);
	}
	if (var2)
	{
		printf("var2 = |%c| ����ֵ\n", var2);
	}
	else
	{
		printf("var2 = |%c| ������ֵ\n", var2);
	}
	if (var3)
	{
		printf("var3 = |%c| ����ֵ\n", var3);
	}
	else
	{
		printf("var3 = |%c| ������ֵ\n", var3);
	}

	if (var4)
	{
		printf("var4 = |%c| ����ֵ\n", var4);
	}
	else
	{
		printf("var4 = |%c| ������ֵ\n", var4);

	}
}

int main_01()
{

	// test_strcpy();
	// test_strtok();

	// test_str_pointer_bound();
	// test_strarr_pointer_bound();

	// test_getCount();
	// test_getKeyByValue();
	// test_isspace();

	// test_strreverse();

	test_truefalseValue();

	system("pause");
	return 0;
}