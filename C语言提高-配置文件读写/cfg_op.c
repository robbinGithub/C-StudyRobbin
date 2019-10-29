#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/);
int WriteCfgItem(char *pFileName /*in*/, char *pItemName /*in*/, char *pItemValue/*in*/, int itemValueLen /*in*/);

//ʵ������
//���ļ�
//�����еķ�ʽ ѭ�����ļ�
//����ÿһ�У���ƥ��key�ؼ��֣��ڽ���valueֵ����ȡ
//��ȡvalueֵ��Ҫ 1ȥ��ǰ��ո� 1��ָ�����Ӧ��

#define  LineMaxLen 2048
#define  KeyMaxLen 64

int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/)
{
	int		rv = 0;               // ���巵��ֵ
	FILE	*fp = NULL;           // �����ļ�ָ��
	char	lineBuf[LineMaxLen];  // �����ַ�������
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL; // pTempָ��Ϊ�������ַ������ȡ��ʱָ��

	// �������
	if (pFileName==NULL || pKey==NULL || pValue==NULL || pValueLen==NULL) 
	{
		rv = -1;
		printf("GetCfgItem() err. param err \n");
		goto End;
	}

	// ���ļ�
	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	// ��ȡ�ļ�
	while (!feof(fp))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp =                                                                                                                                        (lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			break;
		}

		//����=, ������������
		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
		{
			continue;
		}
		//key�Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			continue;
		}
		
		//������=�ұߣ�ȡvalue׼��
		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + 1;

		//��ȡvalue ���
		while (1) 
		{  
		    // ���ֵ�ұ��ǿո���������ָ��+1
			if (*pTmp == ' ')
			{
				pTmp ++ ;
			} 
			else
			{
				pBegin = pTmp;
				if (*pBegin == '\n')
				{
					//û������value
					printf("������:%s û������value \n", pKey);
					goto End;
				}
				break;
			}
		}
		
		//��ȡvalude������  key =      value
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

		//��ֵ
		*pValueLen = pEnd-pBegin;
		memcpy(pValue, pBegin, pEnd-pBegin);
		break;
	}

// END�����ļ����ط���ֵ
End:
	if (fp != NULL)
	{
		fclose(fp); 
	}
	
	return rv;
}

//ʵ������
//ѭ����ÿһ�У����key�������Ƿ���� �������޸Ķ�Ӧvalueֵ
//�������ڣ����ļ�ĩβ ��� "key = value"
//�ѵ㣺����޸��ļ����е�ֵ

int SetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in*/, int ValueLen /*in*/)
{
	int		rv = 0, iTag = 0, length = 0;
	FILE	*fp = NULL;
	char	lineBuf[LineMaxLen];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024*8] = {0};

	// �������
	if (pFileName==NULL || pKey==NULL || pValue==NULL) 
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}
	// ���ļ� 
	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		//goto End;
	}
	// �ļ�ָ����
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
	// �ļ�ָ����ת���ײ��������ļ����ȣ��������ļ�ͷ��
	fseek(fp, 0L, SEEK_END); 
	//��ȡ�ļ�����;
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	// �ļ�����8M������
	if (length > 1024*8) 
	{
		rv = -3;
		printf("�ļ�����1024*8, nunsupport");
		goto End;
	}
	
	while (!feof(fp))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		// �ж϶�ȡ�������Ƿ�Ϊ��
		if (pTmp == NULL) 
		{
			break;
		}
	
		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else
		{    

			/*
			   �ڽ��������͵����ݹ�����ַ���ʱ��sprintf ��ǿ���ܺ��ٻ�����ʧ����
			   ����sprintf ��printf ���÷��ϼ���һ����ֻ�Ǵ�ӡ��Ŀ�ĵز�ͬ���ѣ�ǰ�ߴ�ӡ���ַ����У�������ֱ�����������������
			   ��Ҳ����sprintf ��printf ���õöࡣ
				sprintf �Ǹ���κ������������£�
				int sprintf(char *buffer, const char *format[, argument] ...);
			     ����ǰ�����������͹̶��⣬������Խ������������������ľ�������Ȼ���ڵڶ���������
				��ʽ���ַ����ϡ�  */

			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//������key
			iTag = 1; 
		}
	}

	//�������� ׷��
	if (iTag == 0) 
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else //������
	{
		if (fp != NULL) 
		{ 
			fclose(fp); 
			fp = NULL; //����Ұָ��
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
