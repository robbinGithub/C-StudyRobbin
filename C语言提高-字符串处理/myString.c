#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myString.h"

//实现库函数strlen():
int mystrlen(const char *p)
{
	if (p == NULL)
		return -1;        //失败
	int len = 0;
	while (*p != '\0')    //字符串终止条件
	{
		len++;            //长度自增
		p++;              //指针不断向前
	}
	return len;
}

//实现库函数strcpy():
char *mystrcpy(char *strDest, const char *strSrc)    //const限定不被意外修改
{
	if (strDest == NULL || strSrc == NULL)           //异常处理
		return NULL;

	char *destbak = strDest;    //destbak保留strDest的初始位置，因为循环结束后strDest指向了末尾
	while (*strSrc != '\0')
	{
		*strDest = *strSrc;     //赋值字符
		strSrc++;
		strDest++;              //指针不断向前，字符挨个赋值
	}
	*strDest = '\0';            //注意：此处需要添加'\0'作为结束
	return destbak;             //返回的是strDest的起始位置，所以用destbak
}

//初始化结构体字符串
void init(myString *string)
{
	string->p = NULL;
	string->realLen = 0;
}

void initWithLen(myString *string, int len)
{
	//string->p = (char *)malloc(sizeof(char *)*len);    //分配内存，但是分配的内存不为‘0’，可以使用calloc函数
	string->p = (char *)calloc(len, sizeof(char *));     //分配内存并清0，避免了垃圾数据的影响
	string->realLen = len;                               //长度
}

void initWithString(myString *string, char *copyString)
{
	int length = mystrlen(copyString);                      //获取字符串长度,需实现strlen()库函数
	string->p = (char *)calloc(length + 1, sizeof(char));   //分配内存
	mystrcpy(string->p, copyString);                        //拷贝字符串，需实现strcpy()库函数
	string->realLen = length + 1;                           //设置长度
}

//打印字符串
void printString(myString *string)
{
	printf("%s\n", string->p);
}

void run(myString *string)
{
	system(string->p);        //执行指令
}

//-----------------------------------增[尾部增加]（字符/字符串)-------------------------------------------------
//实现库函数strcat():
char *mystrcat(char *strDest, const char *strSrc)
{
	if (strDest == NULL || strSrc == NULL)
		return NULL;          //失败

	char *destbak = strDest;
	while (*strDest != '\0')
	{
		strDest++;            //strDest指针向前移动，一直到最后一个字符'\0'的位置
	}
	while (*strSrc != '\0')   //从strDest尾部开始拷贝
	{
		*strDest = *strSrc;
		strSrc++;
		strDest++;
	}
	*strDest = '\0';
	return destbak;
}

//尾部增加字符
void backAddChar(myString *string, char ch)
{
	if (mystrlen(string->p) + 1 == string->realLen)    //意味着满了
	{
		//重新分配内存，增加一个字符的位置
		string->p = realloc(string->p, string->realLen + 1);
		string->realLen += 1;        //注意：不能用 string->realLen++; 若用++，这个值在寄存器中而并没有赋值

		string->p[string->realLen - 2] = ch;
		string->p[string->realLen - 1] = '\0';
	}
	else
	{
		int nowLen = mystrlen(string->p);    //求出当前长度
		string->p[nowLen] = ch;
		string->p[nowLen + 1] = '\0';        //字符增加
	}
}

//尾部增加字符串
void backAddStr(myString *string, char *str)
{
	int nowStrLen = mystrlen(string->p); //获取当前字符串长度
	int addStrLen = mystrlen(str); //要增加的字符串的长度
	if (nowStrLen + addStrLen + 1 > string->realLen)    //判定是否越界
	{
		int needAddLen = nowStrLen + addStrLen + 1 - string->realLen;            //需要扩展的长度
		string->p = (char *)realloc(string->p, string->realLen + needAddLen);    //增加字符串长度

		mystrcat(string->p, str);            //拷贝字符串,需要自己实现库函数strcat()
		string->realLen += needAddLen;       //增加长度
	}
	else
	{
		mystrcat(string->p, str);            //拷贝字符串
	}
}

//-----------------------------------查（字符/字符串）-------------------------------------------------
//在字符串string中查找第一个出现的字符ch，返回第一个找到的字符
//实现库函数strchr():在字符串string中查找第一个出现的字符ch
//函数原型：  char *strchr(char *str,char c);
char *mystrchr(const char *str, const char c)
{
	if (str == NULL)        //异常情况
		return NULL;

	while (*str != '\0')
	{
		if (*str == c)
		{
			return str;     //找到返回地址
		}
		str++;
	}
	return NULL;            //没有找到返回NULL
}
char *findFirstChar(myString *string, char ch)
{
	char *p = mystrchr(string->p, ch);
	return p;
}
//在字符串string中查找第一个子串str，返回第一个找到的子串的地址
//实现库函数strstr():在字符串str1中查找指定子串str2，返回第一个找到的子串的地址
//函数原型：  char *strstr(char *str1,char *str2);
char *mystrstr(const char * const str1, const char * const str2)    //注意这里第二个const的使用，不允许str1指针后移
{
	if (str1 == NULL || str2 == NULL)  //异常
		return NULL;

	char *p = NULL;                    //保存找到的地址
	char *strbak1 = str1;              //对str1的起始位置作备份

	while (*strbak1 != '\0')
	{
		int flag = 1;                //标识符，一开始假定是相等的
		char *strbak2 = str2;        //此语句放在循环中，每次循环都需要重新赋值
		char *nowstrbak1 = strbak1;

		while (*strbak2 != '\0')
		{
			if (*nowstrbak1 != '\0')        //没有到str1的末尾
			{
				if (*strbak2 != *nowstrbak1)//有一个不等
				{
					flag = 0;    //赋值为0，代表不等
				}
				nowstrbak1++;
				strbak2++;
			}
			else
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)
		{
			p = strbak1;    //当前位置
			return p;
		}
		strbak1++;
	}

	return NULL;
}
char *findFirstStr(myString *string, char *str)
{
	char *pres = mystrstr(string->p, str);
	return pres;        //返回地址
}

//-----------------------------------删（字符/字符串）-------------------------------------------------
//删除第一个找到的字符
int delFirstChar(myString *string, const char ch)    //成功返回0，失败返回-1；依赖于查找函数
{
	char *p = mystrchr(string->p, ch);        //查找

	if (p == NULL)
		return 0;
	else
	{
		char *pnext = p + 1;
		while (*pnext != '\0')
		{
			*p = *pnext;     //删除一个字符，整体向前移动
			p++;
			pnext++;
		}
		*p = '\0';            //字符串一定要有结尾

		return 1;
	}
}

//删除第一个找到的字符串
int delFirstStr(myString *string, char * const str)
{
	char *p = mystrstr(string->p, str);    //查找

	if (p == NULL)
		return 0;
	else
	{
		int length = mystrlen(str);        //求子串的长度
		char *pnext = p + length;
		while (*pnext != '\0')
		{
			*p = *pnext;    //删除一个字符，整体向前移动
			p++;
			pnext++;
		}
		*p = '\0';

		return 1;
	}
}

//-----------------------------------增[任意位置增加]（字符/字符串)-------------------------------------------------
//任意位置增加字符
void addChar(myString *string, char ch, char *pos)
{
	if (pos == NULL || string == NULL)    //异常情况
		return;

	if (mystrlen(string->p) + 1 == string->realLen)    //意味着满了
	{
		//重新分配内存，增加一个字符的位置
		string->p = realloc(string->p, string->realLen + 1);
		string->realLen += 1;        //注意：不能用 string->realLen++; 若用++，这个值在寄存器中而并没有赋值

		int nowLen = mystrlen(string->p);       //求出当前长度
		int moveLen = mystrlen(pos);            //求出现在要移动的长度
		for (int i = nowLen - 1; i > (nowLen - moveLen); i--)
		{
			string->p[i] = string->p[i - 1];    //轮询移动
		}
		string->p[nowLen - moveLen] = ch;       //先移动，再插入

		string->p[nowLen + 1] = '\0';           //注意结尾
	}
	else
	{
		int nowLen = mystrlen(string->p);       //求出当前长度
		int moveLen = mystrlen(pos);            //求出现在要移动的长度
		for (int i = nowLen - 1; i > (nowLen - moveLen); i--)
		{
			string->p[i] = string->p[i - 1];    //轮询移动
		}
		string->p[nowLen - moveLen] = ch;       //先移动，再插入

		string->p[nowLen + 1] = '\0';           //注意结尾
	}
}

//任意位置增加字符串
void addStr(myString *string, char *str, char *pos)
{
	if (pos == NULL || string == NULL)      //异常情况
		return;

	int nowStrLen = mystrlen(string->p);    //获取当前字符串长度
	int addStrLen = mystrlen(str);          //要增加的字符串的长度
	if (nowStrLen + addStrLen + 1 > string->realLen)    //判定是否越界
	{
		int needAddLen = nowStrLen + addStrLen + 1 - string->realLen;            //需要扩展的长度
		string->p = (char *)realloc(string->p, string->realLen + needAddLen);    //增加字符串长度
		string->realLen += needAddLen;                 //增加长度

		//移动，拷贝
		int nowStrLen = mystrlen(string->p);     //获取当前字符串长度
		int moveStrLen = mystrlen(pos);          //求出现在要移动的长度
		int insertStrLen = mystrlen(str);        //要插入的长度

		for (int i = nowStrLen; i >= nowStrLen - moveStrLen; i--)
		{
			string->p[i + insertStrLen] = string->p[i];        //字符移动
		}
		for (int j = 0; j < insertStrLen; j++)
		{
			string->p[nowStrLen - moveStrLen + j] = str[j];    //赋值拷贝
		}
	}
	else
	{
		mystrcat(string->p, str);            //拷贝字符串
	}
}

//-----------------------------------//改（字符/字符串）-------------------------------------------------
//修改字符
void changeFirstChar(myString *string, const char oldChar, const char newChar)
{
	char *pstr = string->p;
	while (*pstr != '\0')
	{
		if (*pstr == oldChar)   //查找
		{
			*pstr = newChar;    //赋值
			return;
		}
		pstr++;
	}
}

//修改字符串
void changeFirstStr(myString *string, char * const oldStr, char * const newStr)
{
	char *pfind = findFirstStr(string, oldStr); //找到位置
	if (pfind != NULL)
	{
		delFirstStr(string, oldStr);            //删除
		addStr(string, newStr, pfind);          //插入
	}
}


void main()
{
	myString str1;
	initWithString(&str1, "note");

	printString(&str1);                            //note

	/* 测试一：****************************************************************/
	//backAddChar(&str1, 'd');
	//printString(&str1);                        //noted
	//run(&str1);

	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//run(&str1);

	/* 测试二：****************************************************************/
	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//char *strp = findFirstChar(&str1, 'a');
	//*strp = 'A';
	//printString(&str1);                        //notepAd

	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//char *strp = findFirstStr(&str1, "te");
	//*strp = 'X';
	//printString(&str1);                        //noXepad

	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//char *strp = findFirstStr(&str1, "ad");
	//*strp = 'X';
	//printString(&str1);                        //notepXd

	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//char *strp = findFirstStr(&str1, "ada");
	//if (strp != NULL)
	//{
	//    *strp = 'X';
	//}
	//printString(&str1);                        //notepad（并没有改变，没有找到相应子串）

	/* 测试三：****************************************************************/
	//backAddStr(&str1, "pad");                    
	//printString(&str1);                        //notepad
	//delFirstChar(&str1,'e');
	//printString(&str1);                        //notpad

	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//delFirstStr(&str1, "pad");
	//printString(&str1);                        //notenotepad

	/* 测试四：****************************************************************/
	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//char *p = findFirstChar(&str1, 't');//查找第一个t的位置
	//if (p != NULL)
	//{
	//    addChar(&str1, 'A', p);            //在p的前面位置插入'A'
	//}
	//printString(&str1);                        //noAtenotepa

	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//char *p = findFirstChar(&str1, 't');//查找第一个t的位置
	//if (p != NULL)
	//{
	//    addStr(&str1, "12345", p);            //在p的前面位置插入'A'
	//}
	//printString(&str1);                        //no12345tepadnotepad

	/* 测试五：****************************************************************/
	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//changeFirstChar(&str1, 'a', 'i');
	//printString(&str1);                        //notepidnotepad

	backAddStr(&str1, "padnotepad");
	printString(&str1);                        //notepadnotepad
	changeFirstStr(&str1, "notepad", "123456789");
	printString(&str1);                        //123456789notepad

	system("pause");
	return;
}