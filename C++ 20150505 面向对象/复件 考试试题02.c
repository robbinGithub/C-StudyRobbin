/*
2 ��дһ��ҵ������ʵ�ְ��ж�ȡ�ļ��������ݰ��յ������ڴ�ģ�ʹ�����ݴ�����������ͨ����������������
	����ԭ��������������ѡ����һ
	Ҫ��1�����Լ�����ѡ��һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
	Ҫ��2����д����������30��
	Ҫ��3���Լ���д�ڴ��ͷź���
*/


#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define  LineMaxLen 1024*2
//��Ҫ��������У������з����ڴ� 
//�ڰ��ж��ļ����ڶ��η����ڴ棬�ѽ��copy���ڶ��η�����ڴ���

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
	//��һ�����������
	while (!feof(fp))
	{
		//��ÿһ��
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

	//�ڶ��������
	//׼������
	tmplineNum  = 0;
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		//��ÿһ��
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
	//��һ�����������
	while (!feof(fp))
	{
		//��ÿһ��
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

	//�ڶ��������
	//׼������
	tmplineNum  = 0;
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		//��ÿһ��
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

