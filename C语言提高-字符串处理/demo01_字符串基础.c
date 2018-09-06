#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
字符串操作

C语言中没有字符串这种类型，通过字符数组来模拟字符串，C网络字符串是以0结尾的字符串。

@author robbin.zhang
@date 2018/01/25 23:43
*/

/*
 * 字符串初始化
 */
void str_init()
{

	// 不指定长度
	char buf1[100] = { 'a', 'b', 'c', 'd' };

	// 指定长字符串
	char buf2[] = { 'a', 'b', 'c', 'd' };
	char buf3[] = { 'a', 'b', 'c', 'd', '\0' };

	// 通过字符串初始化字符数组
	char buf4[] = "abcd";

	printf("buf1:%s\n", buf1); // abcd
	printf("buf2:%s\n", buf2); // abcd烫烫烫烫abcd
	printf("buf3:%s\n", buf3); // abcd
	printf("buf4:%s\n", buf4); // abcd

}

/*
 * 字符数组的访问 
 */
void strvisit()
{
	int i = 0;
	char *p = NULL;
	//通过字符串初始化字符数组 并且追加\0
	char buf4[] = "abcd";

	for (i = 0; i<strlen(buf4); i++)
	{
		printf("%c", buf4[i]); //p[]
	}

	//[] *的本质到底是什么？
	//*p 是我们程序员手工的（显示）去利用间接赋值
	//【】 只不过是，c/c++ 编译器帮我们做了一个*p的操作。。。。。。
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
 * 字符串拷贝
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
 * 测试strtok 分解字符串为一组字符串
 * 只能接收数组参数
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

	// 循环获取每一个元素
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
* 在str1中查找str2出现的次数
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
	printf("请输入要待查找的字符串:\n");
	//scanf("%[^\n]", buf);
	//gets(buf);
	fgets(buf, 100, stdin);

	printf("请输入要查找的字符串:\n");
	//scanf("%[^\n]", search);
	//gets(search);
	fgets(search, 100, stdin);
	ncount = strstrctn(buf, search);
	printf("共查找到%d处\n", ncount);

}

/*测试char*指针边界*/
void test_str_pointer_bound()
{
	char *p = "abcd";
	p = p + 14;
	printf("%s", p);
}

/*测试char数组边界*/
void test_strarr_pointer_bound()
{
	char arr[5] = { 'a', 'b', 'c', 'd', 'e' };
	char * p = arr;
	p = p + 5;
	printf("%s", p);

}

/*
 * 字符串trim(两头堵模型)
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
 * 挑选奇偶字符串
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
 * 键值对key=value字符串
 * 1.根据key获取value
 * 2.键值对中可能有n多个空格，去除空格   abcefg|key   =    value
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
		printf("func getKeybyValue() err:%d 没有查找到关键字pKey \n", rv);
		return rv;
	}

	// ab=c=efg|key   =   value
	//           /\
		//           |
	//           p

	p = p + strlen(pKey); //为下一次检索做准备
	p = strstr(p, "=");
	if (p == NULL)
	{
		rv = -2;
		printf("func getKeybyValue() err:%d 查找没有= \n", rv);
		return rv;
	}
	p = p + 1; //为下一次检索做准备

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
 *字符串反转
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

	C 库函数 int isspace(int c) 检查所传的字符是否是空白字符。

	' '     (0x20)    space (SPC) 空格符
	'\t'    (0x09)    horizontal tab (TAB) 水平制表符
	'\n'    (0x0a)    newline (LF) 换行符
	'\v'    (0x0b)    vertical tab (VT) 垂直制表符
	'\f'    (0x0c)    feed (FF) 换页符
	'\r'    (0x0d)    carriage return (CR) 回车符
	*/
void test_isspace()
{

	int var1 = 't';
	int var2 = '1';
	int var3 = ' ';
	int var4 = '\0';

	if (isspace(var1))
	{
		printf("var1 = |%c| 是空白字符\n", var1);
	}
	else
	{
		printf("var1 = |%c| 不是空白字符\n", var1);
	}
	if (isspace(var2))
	{
		printf("var2 = |%c| 是空白字符\n", var2);
	}
	else
	{
		printf("var2 = |%c| 不是空白字符\n", var2);
	}
	if (isspace(var3))
	{
		printf("var3 = |%c| 是空白字符\n", var3);
	}
	else
	{
		printf("var3 = |%c| 不是空白字符\n", var3);
	}

	if (isspace(var4))
	{
		printf("var4 = |%c| 是空白字符\n", var4);
	}
	else
	{
		printf("var4 = |%c| 不是空白字符\n", var4);

	}

}

void test_truefalseValue()
{

	int var1 = '\0'; // 真
	int var2 = ' ';
	int var3 = 0;  // 假
	int var4 = '\n';

	if (var1)
	{
		printf("var1 = |%c| 是真值\n", var1);
	}
	else
	{
		printf("var1 = |%c| 不是真值\n", var1);
	}
	if (var2)
	{
		printf("var2 = |%c| 是真值\n", var2);
	}
	else
	{
		printf("var2 = |%c| 不是真值\n", var2);
	}
	if (var3)
	{
		printf("var3 = |%c| 是真值\n", var3);
	}
	else
	{
		printf("var3 = |%c| 不是真值\n", var3);
	}

	if (var4)
	{
		printf("var4 = |%c| 是真值\n", var4);
	}
	else
	{
		printf("var4 = |%c| 不是真值\n", var4);

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