#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//�ַ�����װ����Ҫ�⺯��
//����Ҫ�⺯��
struct CString
{
	char *p;        //�����ַ����׵�ַ
	int realLen;    //�ַ���ʵ�ʳ���
};

typedef struct CString myString;    //�൱��myString����struct CString�ļ�д

//�ַ�����װ��Ҫʵ�֣���ʼ������ӡ����[β������/����λ������]���ַ�/�ַ�������ɾ���ַ�/�ַ��������飨�ַ�/�ַ��������ģ��ַ�/�ַ�����

void init(myString *string);                                //ԭ�ⲻ����ʼ��
void initWithLen(myString *string, int len);                //���ٳ���,�ڴ�����
void initWithString(myString *string, char *copyString);    //��ʼ���������ַ���
void printString(myString *string);                         //��ӡ�ַ���

void run(myString *string);                                 //���ַ���string����ָ����ִ��

//��[β������]���ַ�/�ַ���):
void backAddChar(myString *string, char ch);                 //β�������ַ�
void backAddStr(myString *string, char *str);                //β�������ַ���

//�飨�ַ�/�ַ�����:
char *findFirstChar(myString *string, char ch);    //���ַ���string�в��ҵ�һ�����ֵ��ַ�ch�����ص�һ���ҵ����ַ�
char *findFirstStr(myString *string, char *str);   //���ַ���string�в��ҵ�һ���Ӵ�str�����ص�һ���ҵ����Ӵ��ĵ�ַ

//ɾ���ַ�/�ַ�����
int delFirstChar(myString *string, const char ch);          //�ɹ�����0��ʧ�ܷ���-1�������ڲ��Һ���;ɾ����һ���ҵ����ַ�
int delFirstStr(myString *string, char * const str);        //ɾ����һ���ҵ����ַ���

//��[����λ������]���ַ�/�ַ���):
void addChar(myString *string, char ch, char *pos);     //����λ�������ַ�
void addStr(myString *string, char *str, char *pos);    //����λ�������ַ���

//�ģ��ַ�/�ַ�����
void changeFirstChar(myString *string, const char oldChar, const char newChar);     //�޸��ַ�
void changeFirstStr(myString *string, char * const oldStr, char * const newStr);    //�޸��ַ���