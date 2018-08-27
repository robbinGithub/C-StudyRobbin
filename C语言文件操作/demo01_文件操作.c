#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 文件基本操作

 文本文件:
 "r"             打开，只读(文件必须存在，否则报错,返回NULL)
 "w"             打开，文件指针指到头，只写 (不存在则新建一个文件,存在则删除后重建文件)
 "a"             打开，指向文件尾，在已存在文件中追加 (文件存不存在,新建一个文件)

 二进制文件:
 "rb"            打开一个二进制文件，只读
 "wb"            打开一个二进制文件，只写
 "ab"            打开一个二进制文件，进行追加

 "r+"            以读/写方式打开一个已存在的文件
 "w+"            以读/写方式建立一个新的文本文件 
 "a+"            以读/写方式打开一个文件文件进行追加

 "rb+"           以读/写方式打开一个二进制文件
 "wb+"           以读/写方式建立一个新的二进制文件
 "ab+"           以读/写方式打开一个二进制文件进行追加


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
		printf("写入字符:%c\n", a[i]);
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