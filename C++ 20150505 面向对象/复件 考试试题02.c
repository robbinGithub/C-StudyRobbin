/*
2 编写一个业务函数，实现按行读取文件。把内容按照第三种内存模型打包数据传出，把行数通过函数参数传出。
	函数原型有两个，任意选择其一
	要求1：请自己任意选择一个接口（函数），并实现功能；70分
	要求2：编写测试用例。30分
	要求3：自己编写内存释放函数
*/


#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define  LineMaxLen 1024*2
//需要求出多少行，按照行分配内存 
//在按行读文件，第二次分配内存，把结果copy到第二次分配的内存中

char **readFile1(const char *pfilename/*in*/, int *lineNum/*in out*/)
{
	int		rv = 0, tmplineNum = 0;
	FILE	*fp = NULL;
	char	lineBuf[LineMaxLen];
	char	*pTmp = NULL;
	char	**tmpFile = NULL;
	if (pfilename==NULL || lineNum==NULL ) 
	{
		rv = -1;
		printf("readFile1() err. param err \n");
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	//第一遍读出多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			continue;
		}
		else
		{
			tmplineNum ++;
		}
	}

	tmpFile = (char **)malloc((tmplineNum +1)*sizeof(char *) );
	if (tmpFile == NULL)
	{
		goto End;
	}

	//第二遍读内容
	//准备环境
	tmplineNum  = 0;
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			continue;
		}
		else
		{
			int tmplen = strlen(lineBuf);
			tmpFile[tmplineNum] = (char *)malloc( (tmplen+1)*sizeof(char));
			if (tmpFile[tmplineNum] == NULL)
			{
				goto End;
			}
			strcpy(tmpFile[tmplineNum], lineBuf );
			printf("%s", lineBuf);
			tmplineNum ++;
		}
	}

End:

	if (fp != NULL)
	{
		fclose(fp); 
	}
	*lineNum = tmplineNum;
	return tmpFile;
}

int readFile2(const char *pfilename/*in*/, char ***p/*out*/, int *lineNum/*int out*/)
{
	int		rv = 0, tmplineNum = 0;
	FILE	*fp = NULL;
	char	lineBuf[LineMaxLen];
	char	*pTmp = NULL;
	char	**tmpFile = NULL;
	if (pfilename==NULL || lineNum==NULL ) 
	{
		rv = -1;
		printf("readFile1() err. param err \n");
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	//第一遍读出多少行
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			continue;
		}
		else
		{
			tmplineNum ++;
		}
	}

	tmpFile = (char **)malloc((tmplineNum +1)*sizeof(char *) );
	if (tmpFile == NULL)
	{
		goto End;
	}

	//第二遍读内容
	//准备环境
	tmplineNum  = 0;
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			continue;
		}
		else
		{
			int tmplen = strlen(lineBuf);
			tmpFile[tmplineNum] = (char *)malloc( (tmplen+1)*sizeof(char));
			if (tmpFile[tmplineNum] == NULL)
			{
				goto End;
			}
			strcpy(tmpFile[tmplineNum], lineBuf );
			printf("%s", lineBuf);
			tmplineNum ++;
		}
	}

End:

	if (fp != NULL)
	{
		fclose(fp); 
	}
	*lineNum = tmplineNum;
	*p = tmpFile;
	return 0;

}

void readFile2_Free(char **p, int lineNUm)
{
	int i = 0;
	if (p==NULL)
	{
		return ;
	}
	for (i=0; i<lineNUm; i++)
	{
		free(p[i]);
	}
	free(p);
}

void main21()
{
	char **p = NULL;
	const char *pfilename = "c:/1.txt";
	int lineNum = 0, i = 0;


	p = readFile1(pfilename/*in*/,  &lineNum/*in out*/);
	if (p == NULL)
	{
		return ;
	}

	for (i=0; i<lineNum; i++)
	{
		printf("%s", p[i]);
	}

	readFile2_Free(p, lineNum);
	
	system("pause");
}

void main0002()
{
	int ret = 0;
	char **p = NULL;
	const char *pfilename = "c:/1.txt";
	int lineNum = 0, i = 0;

	ret = readFile2(pfilename/*in*/, &p,  &lineNum/*in out*/);
	if (ret != 0)
	{

		return ;
	}

	for (i=0; i<lineNum; i++)
	{
		printf("%s", p[i]);
	}

	readFile2_Free(p, lineNum);

	system("pause");
}

