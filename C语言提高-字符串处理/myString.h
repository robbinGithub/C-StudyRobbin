#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//字符串封装，需要库函数
//不需要库函数
struct CString
{
	char *p;        //保存字符串首地址
	int realLen;    //字符串实际长度
};

typedef struct CString myString;    //相当于myString就是struct CString的简写

//字符串封装需要实现：初始化、打印、增[尾部增加/任意位置增加]（字符/字符串）、删（字符/字符串）、查（字符/字符串）、改（字符/字符串）

void init(myString *string);                                //原封不动初始化
void initWithLen(myString *string, int len);                //开辟长度,内存清零
void initWithString(myString *string, char *copyString);    //初始化并拷贝字符串
void printString(myString *string);                         //打印字符串

void run(myString *string);                                 //将字符串string按照指令来执行

//增[尾部增加]（字符/字符串):
void backAddChar(myString *string, char ch);                 //尾部增加字符
void backAddStr(myString *string, char *str);                //尾部增加字符串

//查（字符/字符串）:
char *findFirstChar(myString *string, char ch);    //在字符串string中查找第一个出现的字符ch，返回第一个找到的字符
char *findFirstStr(myString *string, char *str);   //在字符串string中查找第一个子串str，返回第一个找到的子串的地址

//删（字符/字符串）
int delFirstChar(myString *string, const char ch);          //成功返回0，失败返回-1；依赖于查找函数;删除第一个找到的字符
int delFirstStr(myString *string, char * const str);        //删除第一个找到的字符串

//增[任意位置增加]（字符/字符串):
void addChar(myString *string, char ch, char *pos);     //任意位置增加字符
void addStr(myString *string, char *str, char *pos);    //任意位置增加字符串

//改（字符/字符串）
void changeFirstChar(myString *string, const char oldChar, const char newChar);     //修改字符
void changeFirstStr(myString *string, char * const oldStr, char * const newStr);    //修改字符串