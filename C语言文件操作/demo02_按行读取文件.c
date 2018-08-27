#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * 特殊字符读取\r\n
 *
 * 测试文本内容:61 62 OA 64 0D 61
 *               a  b  \n d  \r a
 *
 * 【windows下用文本方式写文件时】
 *
 *  缓冲区里的\n或者\r都会被自动替换为\r\n写入文件，即使是连着的\r\n，也会被替换成\r\n\r\n
 * （但是msdn上面只说\r被替换为\r\n）
 *  
 *
 * 【windows下用文本方式读文件时】
 *  文件中的\r\n自动替换为\n存放到缓冲区里\r不会被替换
 * 
 *
 * 如果是fgets文本模式读文件，碰到第一个\n（这里的\r和\n都是指经过转换后读入缓冲区的，即\r\n被替换为\n）后停止读取，
 *  缓存区里存放的是\n之前的字符串（包括这个\n以及之前所有的\r)
 *
 * @see http://blog.csdn.net/u011061503/article/details/34084857
 *
 */
int main_022()
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

	// read
	rewind(fp);
	while (!feof(fp))
	{   
		/*
		 * 按行读取文件,读取_MaxCount-1个字符,并在末尾加上结束标志\0, 参数_MaxCount防止数组越界
		 * 读取过程中遇到换行符号或文件结束标志, 读取操作结束.
		 * 读成功返回地址str,失败则返回NULL(空指针)
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