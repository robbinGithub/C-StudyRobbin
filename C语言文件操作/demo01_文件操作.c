#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 �ļ���������

 �ı��ļ�:
 "r"             �򿪣�ֻ��(�ļ�������ڣ����򱨴�,����NULL)
 "w"             �򿪣��ļ�ָ��ָ��ͷ��ֻд (���������½�һ���ļ�,������ɾ�����ؽ��ļ�)
 "a"             �򿪣�ָ���ļ�β�����Ѵ����ļ���׷�� (�ļ��治����,�½�һ���ļ�)

 �������ļ�:
 "rb"            ��һ���������ļ���ֻ��
 "wb"            ��һ���������ļ���ֻд
 "ab"            ��һ���������ļ�������׷��

 "r+"            �Զ�/д��ʽ��һ���Ѵ��ڵ��ļ�
 "w+"            �Զ�/д��ʽ����һ���µ��ı��ļ� 
 "a+"            �Զ�/д��ʽ��һ���ļ��ļ�����׷��

 "rb+"           �Զ�/д��ʽ��һ���������ļ�
 "wb+"           �Զ�/д��ʽ����һ���µĶ������ļ�
 "ab+"           �Զ�/д��ʽ��һ���������ļ�����׷��


 author robbin.zhang
 date 2018/01/31 23:22
 @see https://www.cnblogs.com/likebeta/archive/2012/06/16/2551780.html
 */
int main_01()
{
	unsigned int i = 0;
	FILE *fp = NULL;
	char a[100] = "abcdefg";
	char *fname = "d:/2.txt";
	fp = fopen(fname, "r+");
	// fp = fopen(fname, "w+");
	if (fp == NULL)
	{
		printf("func fopen () err: \n");
		return;
	}

	// write
	for (i = 0; i < strlen(a); i++)
	{
		fputc(a[i], fp);
		printf("д���ַ�:%c\n", a[i]);
	}

	// read
	rewind(fp);
	while (!feof(fp))
	{
		printf("%c\n", fgetc(fp));
	}
	
	if (fp != NULL)
	{
		fclose(fp);
	}
	system("pause");

	return 0;
}