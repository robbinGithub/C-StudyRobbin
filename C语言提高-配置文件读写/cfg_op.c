#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/);
int WriteCfgItem(char *pFileName /*in*/, char *pItemName /*in*/, char *pItemValue/*in*/, int itemValueLen /*in*/);

//实现流程
//打开文件
//按照行的方式 循环读文件
//解析每一行，若匹配key关键字，在进行value值的提取
//提取value值需要 1去除前后空格 1级指针典型应用

#define  LineMaxLen 2048
#define  KeyMaxLen 64

int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/)
{
	int		rv = 0;               // 定义返回值
	FILE	*fp = NULL;           // 定义文件指针
	char	lineBuf[LineMaxLen];  // 定义字符缓冲区
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL; // pTemp指针为配置项字符数组读取临时指针

	// 参数检查
	if (pFileName==NULL || pKey==NULL || pValue==NULL || pValueLen==NULL) 
	{
		rv = -1;
		printf("GetCfgItem() err. param err \n");
		goto End;
	}

	// 打开文件
	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	// 读取文件
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp =                                                                                                                                        (lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			break;
		}

		//不含=, 非配置项跳过
		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
		{
			continue;
		}
		//key是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			continue;
		}
		
		//调整到=右边，取value准备
		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + 1;

		//获取value 起点
		while (1) 
		{  
		    // 如果值右边是空格则跳过，指针+1
			if (*pTmp == ' ')
			{
				pTmp ++ ;
			} 
			else
			{
				pBegin = pTmp;
				if (*pBegin == '\n')
				{
					//没有配置value
					printf("配置项:%s 没有配置value \n", pKey);
					goto End;
				}
				break;
			}
		}
		
		//获取valude结束点  key =      value
		while (1) 
		{
			if ((*pTmp == ' ' || *pTmp == '\n'))
			{
				break;
			}
			else 
			{
				pTmp ++;
			}
		}
		pEnd = pTmp;

		//赋值
		*pValueLen = pEnd-pBegin;
		memcpy(pValue, pBegin, pEnd-pBegin);
		break;
	}

// END结束文件返回返回值
End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	
	return rv;
}

//实现流程
//循环读每一行，检查key配置项是否存在 若存在修改对应value值
//若不存在，在文件末尾 添加 "key = value"
//难点：如何修改文件流中的值

int SetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in*/, int ValueLen /*in*/)
{
	int		rv = 0, iTag = 0, length = 0;
	FILE	*fp = NULL;
	char	lineBuf[LineMaxLen];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024*8] = {0};

	// 参数检查
	if (pFileName==NULL || pKey==NULL || pValue==NULL) 
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}
	// 打开文件 
	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		//goto End;
	}
	// 文件指针检查
	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t");
		if (fp == NULL)
		{
			rv = -3;
			printf("fopen() err. \n");
			goto End;
		}
	}
	// 文件指针跳转至底部，计算文件长度，再跳回文件头部
	fseek(fp, 0L, SEEK_END); 
	//获取文件长度;
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	// 文件大于8M不处理
	if (length > 1024*8) 
	{
		rv = -3;
		printf("文件超过1024*8, nunsupport");
		goto End;
	}
	
	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		// 判断读取的内容是否为空
		if (pTmp == NULL) 
		{
			break;
		}
	
		//key关键字是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else
		{    

			/*
			   在将各种类型的数据构造成字符串时，sprintf 的强大功能很少会让你失望。
			   由于sprintf 跟printf 在用法上几乎一样，只是打印的目的地不同而已，前者打印到字符串中，后者则直接在命令行上输出。
			   这也导致sprintf 比printf 有用得多。
				sprintf 是个变参函数，定义如下：
				int sprintf(char *buffer, const char *format[, argument] ...);
			     除了前两个参数类型固定外，后面可以接任意多个参数。而它的精华，显然就在第二个参数：
				格式化字符串上。  */

			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在key
			iTag = 1; 
		}
	}

	//若不存在 追加
	if (iTag == 0) 
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else //若存在
	{
		if (fp != NULL) 
		{ 
			fclose(fp); 
			fp = NULL; //避免野指针
		}

		fp = fopen(pFileName, "w+t");

		if (fp == NULL)
		{
			rv = -4;
			printf("fopen() err. \n");
			goto End;
		}
		fputs(filebuf, fp);
		//fwrite(filebuf, sizeof(char), strlen(filebuf), fp);
	}
	
End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	return rv;
}
