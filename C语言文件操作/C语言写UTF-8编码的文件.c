#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>  
#include <Windows.h> 

void writeUTF8();
void writeUTF82();
void writeGBK();

/*
   用C语言写UTF-8编码的文件
   @see http://blog.csdn.net/zaffix/article/details/7217701

 */
int main_05()
{
	writeUTF82();
	system("pause");
}

/*
   为实现用C语言写UTF-8编码的文件，测试了以下两种情况。
   第一种情况，为 fopen 指定一个编码，然后写入 wchar_t 字符串，最终写入的文件就是UTF-8编码的了，原理不清楚，
   估计是 fwrite 时对 wchar_t 做了编码转换（如果写入 char 的话就会乱码）。
 */
void writeUTF8()
{
	unsigned int i = 0;
	FILE *fp = NULL;
	char *fname = "d:/cutf8.txt";
	
	wchar_t* s = _T("hello, 你好！");

	printf("sizeof(wchar_t):%d\n", sizeof(wchar_t));  //  wchar_t 2个字节
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
 第二种情况，先将字符串编码转换为UTF-8格式的，然后再写入。
  使用CP_ACP代码页就实现了ANSI与Unicode之间的转换。
  使用CP_UTF8代码页就实现了UTF-8与Unicode之间的转换。
 */
void writeUTF82()
{
	FILE* fp = fopen("D:\cutf82.txt", "wb+");

	// 写入UTF-8的BOM文件头  
	char header[3] = { (char)0xEF, (char)0xBB, (char)0xBF };
	fwrite(header, sizeof(char), 3, fp);

	char* s = "hello, 你好！";
	wchar_t wc[256];
	// 将ANSI编码的多字节字符串转换成宽字符字符串  
	int n = MultiByteToWideChar(CP_ACP, 0, s, strlen(s), wc, 256);
	if (n > 0)
	{
		wc[n] = 0;

		char mb[1024];
		// 将宽字符字符串转换成UTF-8编码的多字节字符串  
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
	char a[100] = "中国";//"ab\rcd\n";
	char buf[100];
	char *p = NULL;
	char *fname = "d:/1.txt";
	fp = fopen(fname, "w+");

	printf("strlen:%d\n", strlen(a));  // 4个字节

	// fp = fopen(fname, "w+");
	if (fp == NULL)
	{
		printf("func fopen () err: \n");
		return;
	}

	/*
	* 成功返回0, 否则返回非0值
	* int fput(char *str, FILE *fp);
	*
	*/
	fputs(a, fp);
}

