#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * �����ַ���ȡ\r\n
 *
 * �����ı�����:61 62 OA 64 0D 61
 *               a  b  \n d  \r a
 *
 * ��windows�����ı���ʽд�ļ�ʱ��
 *
 *  ���������\n����\r���ᱻ�Զ��滻Ϊ\r\nд���ļ�����ʹ�����ŵ�\r\n��Ҳ�ᱻ�滻��\r\n\r\n
 * ������msdn����ֻ˵\r���滻Ϊ\r\n��
 *  
 *
 * ��windows�����ı���ʽ���ļ�ʱ��
 *  �ļ��е�\r\n�Զ��滻Ϊ\n��ŵ���������\r���ᱻ�滻
 * 
 *
 * �����fgets�ı�ģʽ���ļ���������һ��\n�������\r��\n����ָ����ת������뻺�����ģ���\r\n���滻Ϊ\n����ֹͣ��ȡ��
 *  ���������ŵ���\n֮ǰ���ַ������������\n�Լ�֮ǰ���е�\r)
 *
 * @see http://blog.csdn.net/u011061503/article/details/34084857
 *
 */
int main_022()
{
	unsigned int i = 0;
	FILE *fp = NULL;
	char a[100] = "�й�";//"ab\rcd\n";
	char buf[100];
	char *p = NULL;
	char *fname = "d:/1.txt";
	fp = fopen(fname, "w+");

	printf("strlen:%d\n", strlen(a));  // 4���ֽ�

	// fp = fopen(fname, "w+");
	if (fp == NULL)
	{
		printf("func fopen () err: \n");
		return;
	}

	/*
	 * �ɹ�����0, ���򷵻ط�0ֵ 
	 * int fput(char *str, FILE *fp);
	 *
	 */
	 fputs(a, fp);

	// read
	rewind(fp);
	while (!feof(fp))
	{   
		/*
		 * ���ж�ȡ�ļ�,��ȡ_MaxCount-1���ַ�,����ĩβ���Ͻ�����־\0, ����_MaxCount��ֹ����Խ��
		 * ��ȡ�������������з��Ż��ļ�������־, ��ȡ��������.
		 * ���ɹ����ص�ַstr,ʧ���򷵻�NULL(��ָ��)
		 *
		 * char * fgets( char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File)
		 * char * fgets( char * str, _In_ int n, FILE * fpln)
		 */
		p = fgets(buf, 100, fp);
		if (p == NULL)
		{
			printf("func fgets() err....\n");
		}
		printf("%s", buf);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
	system("pause");

	return 0;

}