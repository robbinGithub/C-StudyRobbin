#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myString.h"

//ʵ�ֿ⺯��strlen():
int mystrlen(const char *p)
{
	if (p == NULL)
		return -1;        //ʧ��
	int len = 0;
	while (*p != '\0')    //�ַ�����ֹ����
	{
		len++;            //��������
		p++;              //ָ�벻����ǰ
	}
	return len;
}

//ʵ�ֿ⺯��strcpy():
char *mystrcpy(char *strDest, const char *strSrc)    //const�޶����������޸�
{
	if (strDest == NULL || strSrc == NULL)           //�쳣����
		return NULL;

	char *destbak = strDest;    //destbak����strDest�ĳ�ʼλ�ã���Ϊѭ��������strDestָ����ĩβ
	while (*strSrc != '\0')
	{
		*strDest = *strSrc;     //��ֵ�ַ�
		strSrc++;
		strDest++;              //ָ�벻����ǰ���ַ�������ֵ
	}
	*strDest = '\0';            //ע�⣺�˴���Ҫ���'\0'��Ϊ����
	return destbak;             //���ص���strDest����ʼλ�ã�������destbak
}

//��ʼ���ṹ���ַ���
void init(myString *string)
{
	string->p = NULL;
	string->realLen = 0;
}

void initWithLen(myString *string, int len)
{
	//string->p = (char *)malloc(sizeof(char *)*len);    //�����ڴ棬���Ƿ�����ڴ治Ϊ��0��������ʹ��calloc����
	string->p = (char *)calloc(len, sizeof(char *));     //�����ڴ沢��0���������������ݵ�Ӱ��
	string->realLen = len;                               //����
}

void initWithString(myString *string, char *copyString)
{
	int length = mystrlen(copyString);                      //��ȡ�ַ�������,��ʵ��strlen()�⺯��
	string->p = (char *)calloc(length + 1, sizeof(char));   //�����ڴ�
	mystrcpy(string->p, copyString);                        //�����ַ�������ʵ��strcpy()�⺯��
	string->realLen = length + 1;                           //���ó���
}

//��ӡ�ַ���
void printString(myString *string)
{
	printf("%s\n", string->p);
}

void run(myString *string)
{
	system(string->p);        //ִ��ָ��
}

//-----------------------------------��[β������]���ַ�/�ַ���)-------------------------------------------------
//ʵ�ֿ⺯��strcat():
char *mystrcat(char *strDest, const char *strSrc)
{
	if (strDest == NULL || strSrc == NULL)
		return NULL;          //ʧ��

	char *destbak = strDest;
	while (*strDest != '\0')
	{
		strDest++;            //strDestָ����ǰ�ƶ���һֱ�����һ���ַ�'\0'��λ��
	}
	while (*strSrc != '\0')   //��strDestβ����ʼ����
	{
		*strDest = *strSrc;
		strSrc++;
		strDest++;
	}
	*strDest = '\0';
	return destbak;
}

//β�������ַ�
void backAddChar(myString *string, char ch)
{
	if (mystrlen(string->p) + 1 == string->realLen)    //��ζ������
	{
		//���·����ڴ棬����һ���ַ���λ��
		string->p = realloc(string->p, string->realLen + 1);
		string->realLen += 1;        //ע�⣺������ string->realLen++; ����++�����ֵ�ڼĴ����ж���û�и�ֵ

		string->p[string->realLen - 2] = ch;
		string->p[string->realLen - 1] = '\0';
	}
	else
	{
		int nowLen = mystrlen(string->p);    //�����ǰ����
		string->p[nowLen] = ch;
		string->p[nowLen + 1] = '\0';        //�ַ�����
	}
}

//β�������ַ���
void backAddStr(myString *string, char *str)
{
	int nowStrLen = mystrlen(string->p); //��ȡ��ǰ�ַ�������
	int addStrLen = mystrlen(str); //Ҫ���ӵ��ַ����ĳ���
	if (nowStrLen + addStrLen + 1 > string->realLen)    //�ж��Ƿ�Խ��
	{
		int needAddLen = nowStrLen + addStrLen + 1 - string->realLen;            //��Ҫ��չ�ĳ���
		string->p = (char *)realloc(string->p, string->realLen + needAddLen);    //�����ַ�������

		mystrcat(string->p, str);            //�����ַ���,��Ҫ�Լ�ʵ�ֿ⺯��strcat()
		string->realLen += needAddLen;       //���ӳ���
	}
	else
	{
		mystrcat(string->p, str);            //�����ַ���
	}
}

//-----------------------------------�飨�ַ�/�ַ�����-------------------------------------------------
//���ַ���string�в��ҵ�һ�����ֵ��ַ�ch�����ص�һ���ҵ����ַ�
//ʵ�ֿ⺯��strchr():���ַ���string�в��ҵ�һ�����ֵ��ַ�ch
//����ԭ�ͣ�  char *strchr(char *str,char c);
char *mystrchr(const char *str, const char c)
{
	if (str == NULL)        //�쳣���
		return NULL;

	while (*str != '\0')
	{
		if (*str == c)
		{
			return str;     //�ҵ����ص�ַ
		}
		str++;
	}
	return NULL;            //û���ҵ�����NULL
}
char *findFirstChar(myString *string, char ch)
{
	char *p = mystrchr(string->p, ch);
	return p;
}
//���ַ���string�в��ҵ�һ���Ӵ�str�����ص�һ���ҵ����Ӵ��ĵ�ַ
//ʵ�ֿ⺯��strstr():���ַ���str1�в���ָ���Ӵ�str2�����ص�һ���ҵ����Ӵ��ĵ�ַ
//����ԭ�ͣ�  char *strstr(char *str1,char *str2);
char *mystrstr(const char * const str1, const char * const str2)    //ע������ڶ���const��ʹ�ã�������str1ָ�����
{
	if (str1 == NULL || str2 == NULL)  //�쳣
		return NULL;

	char *p = NULL;                    //�����ҵ��ĵ�ַ
	char *strbak1 = str1;              //��str1����ʼλ��������

	while (*strbak1 != '\0')
	{
		int flag = 1;                //��ʶ����һ��ʼ�ٶ�����ȵ�
		char *strbak2 = str2;        //��������ѭ���У�ÿ��ѭ������Ҫ���¸�ֵ
		char *nowstrbak1 = strbak1;

		while (*strbak2 != '\0')
		{
			if (*nowstrbak1 != '\0')        //û�е�str1��ĩβ
			{
				if (*strbak2 != *nowstrbak1)//��һ������
				{
					flag = 0;    //��ֵΪ0��������
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
			p = strbak1;    //��ǰλ��
			return p;
		}
		strbak1++;
	}

	return NULL;
}
char *findFirstStr(myString *string, char *str)
{
	char *pres = mystrstr(string->p, str);
	return pres;        //���ص�ַ
}

//-----------------------------------ɾ���ַ�/�ַ�����-------------------------------------------------
//ɾ����һ���ҵ����ַ�
int delFirstChar(myString *string, const char ch)    //�ɹ�����0��ʧ�ܷ���-1�������ڲ��Һ���
{
	char *p = mystrchr(string->p, ch);        //����

	if (p == NULL)
		return 0;
	else
	{
		char *pnext = p + 1;
		while (*pnext != '\0')
		{
			*p = *pnext;     //ɾ��һ���ַ���������ǰ�ƶ�
			p++;
			pnext++;
		}
		*p = '\0';            //�ַ���һ��Ҫ�н�β

		return 1;
	}
}

//ɾ����һ���ҵ����ַ���
int delFirstStr(myString *string, char * const str)
{
	char *p = mystrstr(string->p, str);    //����

	if (p == NULL)
		return 0;
	else
	{
		int length = mystrlen(str);        //���Ӵ��ĳ���
		char *pnext = p + length;
		while (*pnext != '\0')
		{
			*p = *pnext;    //ɾ��һ���ַ���������ǰ�ƶ�
			p++;
			pnext++;
		}
		*p = '\0';

		return 1;
	}
}

//-----------------------------------��[����λ������]���ַ�/�ַ���)-------------------------------------------------
//����λ�������ַ�
void addChar(myString *string, char ch, char *pos)
{
	if (pos == NULL || string == NULL)    //�쳣���
		return;

	if (mystrlen(string->p) + 1 == string->realLen)    //��ζ������
	{
		//���·����ڴ棬����һ���ַ���λ��
		string->p = realloc(string->p, string->realLen + 1);
		string->realLen += 1;        //ע�⣺������ string->realLen++; ����++�����ֵ�ڼĴ����ж���û�и�ֵ

		int nowLen = mystrlen(string->p);       //�����ǰ����
		int moveLen = mystrlen(pos);            //�������Ҫ�ƶ��ĳ���
		for (int i = nowLen - 1; i > (nowLen - moveLen); i--)
		{
			string->p[i] = string->p[i - 1];    //��ѯ�ƶ�
		}
		string->p[nowLen - moveLen] = ch;       //���ƶ����ٲ���

		string->p[nowLen + 1] = '\0';           //ע���β
	}
	else
	{
		int nowLen = mystrlen(string->p);       //�����ǰ����
		int moveLen = mystrlen(pos);            //�������Ҫ�ƶ��ĳ���
		for (int i = nowLen - 1; i > (nowLen - moveLen); i--)
		{
			string->p[i] = string->p[i - 1];    //��ѯ�ƶ�
		}
		string->p[nowLen - moveLen] = ch;       //���ƶ����ٲ���

		string->p[nowLen + 1] = '\0';           //ע���β
	}
}

//����λ�������ַ���
void addStr(myString *string, char *str, char *pos)
{
	if (pos == NULL || string == NULL)      //�쳣���
		return;

	int nowStrLen = mystrlen(string->p);    //��ȡ��ǰ�ַ�������
	int addStrLen = mystrlen(str);          //Ҫ���ӵ��ַ����ĳ���
	if (nowStrLen + addStrLen + 1 > string->realLen)    //�ж��Ƿ�Խ��
	{
		int needAddLen = nowStrLen + addStrLen + 1 - string->realLen;            //��Ҫ��չ�ĳ���
		string->p = (char *)realloc(string->p, string->realLen + needAddLen);    //�����ַ�������
		string->realLen += needAddLen;                 //���ӳ���

		//�ƶ�������
		int nowStrLen = mystrlen(string->p);     //��ȡ��ǰ�ַ�������
		int moveStrLen = mystrlen(pos);          //�������Ҫ�ƶ��ĳ���
		int insertStrLen = mystrlen(str);        //Ҫ����ĳ���

		for (int i = nowStrLen; i >= nowStrLen - moveStrLen; i--)
		{
			string->p[i + insertStrLen] = string->p[i];        //�ַ��ƶ�
		}
		for (int j = 0; j < insertStrLen; j++)
		{
			string->p[nowStrLen - moveStrLen + j] = str[j];    //��ֵ����
		}
	}
	else
	{
		mystrcat(string->p, str);            //�����ַ���
	}
}

//-----------------------------------//�ģ��ַ�/�ַ�����-------------------------------------------------
//�޸��ַ�
void changeFirstChar(myString *string, const char oldChar, const char newChar)
{
	char *pstr = string->p;
	while (*pstr != '\0')
	{
		if (*pstr == oldChar)   //����
		{
			*pstr = newChar;    //��ֵ
			return;
		}
		pstr++;
	}
}

//�޸��ַ���
void changeFirstStr(myString *string, char * const oldStr, char * const newStr)
{
	char *pfind = findFirstStr(string, oldStr); //�ҵ�λ��
	if (pfind != NULL)
	{
		delFirstStr(string, oldStr);            //ɾ��
		addStr(string, newStr, pfind);          //����
	}
}


void main()
{
	myString str1;
	initWithString(&str1, "note");

	printString(&str1);                            //note

	/* ����һ��****************************************************************/
	//backAddChar(&str1, 'd');
	//printString(&str1);                        //noted
	//run(&str1);

	//backAddStr(&str1, "pad");
	//printString(&str1);                        //notepad
	//run(&str1);

	/* ���Զ���****************************************************************/
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
	//printString(&str1);                        //notepad����û�иı䣬û���ҵ���Ӧ�Ӵ���

	/* ��������****************************************************************/
	//backAddStr(&str1, "pad");                    
	//printString(&str1);                        //notepad
	//delFirstChar(&str1,'e');
	//printString(&str1);                        //notpad

	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//delFirstStr(&str1, "pad");
	//printString(&str1);                        //notenotepad

	/* �����ģ�****************************************************************/
	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//char *p = findFirstChar(&str1, 't');//���ҵ�һ��t��λ��
	//if (p != NULL)
	//{
	//    addChar(&str1, 'A', p);            //��p��ǰ��λ�ò���'A'
	//}
	//printString(&str1);                        //noAtenotepa

	//backAddStr(&str1, "padnotepad");
	//printString(&str1);                        //notepadnotepad
	//char *p = findFirstChar(&str1, 't');//���ҵ�һ��t��λ��
	//if (p != NULL)
	//{
	//    addStr(&str1, "12345", p);            //��p��ǰ��λ�ò���'A'
	//}
	//printString(&str1);                        //no12345tepadnotepad

	/* �����壺****************************************************************/
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