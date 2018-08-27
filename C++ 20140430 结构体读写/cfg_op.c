#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//ʵ������
//���ļ�
//�����еķ�ʽ ѭ�����ļ�
//����ÿһ�У���ƥ��key�ؼ��֣��ڽ���valueֵ����ȡ
//��ȡvalueֵ��Ҫ 1ȥ��ǰ��ո� 1��ָ�����Ӧ��

#define  LineMaxLen 2048
#define  KeyMaxLen 64

int GetCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char * pValue/*in out*/, int * pValueLen /*out*/)
{
	int		rv = 0;
	FILE	*fp = NULL;
	char	lineBuf[LineMaxLen];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;

	if (pFileName==NULL || pKey==NULL || pValue==NULL || pValueLen==NULL) 
	{
		rv = -1;
		printf("GetCfgItem() err. param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		goto End;
	}
	while (!feof(fp))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, LineMaxLen, fp);
		if (pTmp == NULL) 
		{
			break;
		}

		//����=, ��������
		pTmp = strchr(lineBuf, '='); //�ҳ����ַ���str�е�һ�γ����ַ�ch��λ��,���ظ��ַ����ַ����еĵ�ַ��λ��
		if (pTmp == NULL)
		{
			continue;
		}
		//key�Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);//�����ַ���str2���ַ���str1�еĵ�ַ��λ��,�Ҳ����ͷ��ؿ�ָ��(���� null)
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
		
		//��ȡvalue������
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
	char	lineBuf[LineMaxLen];  //�л���
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024*8] = {0};
	
	if (pFileName==NULL || pKey==NULL || pValue==NULL) 
	{
		rv = -1;
		printf("SetCfgItem() err. param err \n");
		goto End;
	}
	
	fp = fopen(pFileName, "r+");//r+ �򿪿ɶ�д���ļ������ļ�������ڡ� 
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err. \n");
		//goto End;
	}

	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t"); //w+ �򿪿ɶ�д�ļ������ļ��������������ļ�
		if (fp == NULL)
		{
			rv = -3;
			printf("fopen() err. \n");
			goto End;
		}
	}
	
	fseek(fp, 0L, SEEK_END); /* ��λ���ļ�ĩβ */ 
	//��ȡ�ļ�����;
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET); //�ļ�ָ��ָ���ļ��Ŀ�ͷ
	
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
		pTmp = fgets(lineBuf, LineMaxLen, fp);//�� fp ָ����ļ��� ��ȡ ���ַ��ŵ� buf �ַ�������,����lineBuf��ָ��
		
		/*fgets�������ļ���ȡ'\n'���洢����'\n'��������һ��'\0'�����ַ�����
		  ��fgets������Ҫָ��������ַ��������ָ����n�������ֻ�ܶ�ȡn - 1����
		  fgets�ڶ�ȡ��n - 1���ַ���������'\n'��������EOF�������֮һʱ��������ȡ��*/	

		if (pTmp == NULL)
		{
			break;
		}
	
		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey); //�ҳ�str2�ַ�����str1�ַ����е�һ�γ��ֵ�λ��,���ظ�λ�õ�ָ��
		if (pTmp == NULL)
		{
			strcat(filebuf, lineBuf);//��src��ָ�ַ�����ӵ�dest��β��(����dest��β����'\0')�����'\0'
			continue;
		}
		else
		{
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);//��ӡ���ַ�����
			strcat(filebuf, lineBuf); 
			//������key
			iTag = 1; 
		}
	}

	//�������� ׷��
	if (iTag == 0) 
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);//д���ļ�
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
