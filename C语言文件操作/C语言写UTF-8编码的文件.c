#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>  
#include <Windows.h> 

void writeUTF8();
void writeUTF82();
void writeGBK();

/*
   ��C����дUTF-8������ļ�
   @see http://blog.csdn.net/zaffix/article/details/7217701

 */
int main_05()
{
	writeUTF82();
	system("pause");
}

/*
   Ϊʵ����C����дUTF-8������ļ����������������������
   ��һ�������Ϊ fopen ָ��һ�����룬Ȼ��д�� wchar_t �ַ���������д����ļ�����UTF-8������ˣ�ԭ�������
   ������ fwrite ʱ�� wchar_t ���˱���ת�������д�� char �Ļ��ͻ����룩��
 */
void writeUTF8()
{
	unsigned int i = 0;
	FILE *fp = NULL;
	char *fname = "d:/cutf8.txt";
	
	wchar_t* s = _T("hello, ��ã�");

	printf("sizeof(wchar_t):%d\n", sizeof(wchar_t));  //  wchar_t 2���ֽ�
	printf("wcslen(s):%d\n", wcslen(s));  //  wchar_t 10
	

	fp = fopen(fname, "wt+,ccs=UTF-8");
	if (fp == NULL)
	{
		printf("func fopen () err: \n");
		return;
	}

	fwrite(s, sizeof(wchar_t), wcslen(s), fp);
}

/*
 �ڶ���������Ƚ��ַ�������ת��ΪUTF-8��ʽ�ģ�Ȼ����д�롣
  ʹ��CP_ACP����ҳ��ʵ����ANSI��Unicode֮���ת����
  ʹ��CP_UTF8����ҳ��ʵ����UTF-8��Unicode֮���ת����
 */
void writeUTF82()
{
	FILE* fp = fopen("D:\cutf82.txt", "wb+");

	// д��UTF-8��BOM�ļ�ͷ  
	char header[3] = { (char)0xEF, (char)0xBB, (char)0xBF };
	fwrite(header, sizeof(char), 3, fp);

	char* s = "hello, ��ã�";
	wchar_t wc[256];
	// ��ANSI����Ķ��ֽ��ַ���ת���ɿ��ַ��ַ���  
	int n = MultiByteToWideChar(CP_ACP, 0, s, strlen(s), wc, 256);
	if (n > 0)
	{
		wc[n] = 0;

		char mb[1024];
		// �����ַ��ַ���ת����UTF-8����Ķ��ֽ��ַ���  
		n = WideCharToMultiByte(CP_UTF8, 0, wc, wcslen(wc), mb, 1024, NULL, NULL);
		if (n > 0)
		{
			mb[n] = 0;
			fwrite(mb, sizeof(char), strlen(mb), fp);
		}
	}

	fclose(fp);

}

void writeGBK()
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
}

