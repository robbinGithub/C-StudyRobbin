#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
    0x00000000 ----> "aaaaaa"
	0x00000004 ----> "bbbbbb"
	0x00000008 ----> "cccccc"
	0x0000000C ----> "dddddd"

	p3 = 0x000023f8 (0x00000000的地址)
 
 */
void getArray3_Free(char **p3, int p3num)
{
	int i = 0;
	if (p3 == NULL)
	{
		return -1;
	}
	for (i = 0; i < p3num; i++)
	{
		if (p3[i] != NULL)
		{
			free(p3[i]);
		}
	}
	free(p3);

}

void getArray3_Free_02(char ***p3, int p3num)
{
	int i = 0;
	char **tmp = NULL;
	tmp = *p3;
	if (tmp == NULL)
	{
		return -1;
	}
	for (i = 0; i < p3num; i++)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
		}
	}
	free(tmp);

	// temp = NULL 是错误的
	*p3 = NULL;

}


// D7A2
int getArray3_02(char **p1, int num1, char(*p2)[30], int num2, int *num3, char ***p3)
{  
	int ret = 0;
	int tmpNum3 = NULL;
	int i,j;
	char ** tmpp3 = NULL;
	char * temp = NULL;
	if (p1 == NULL || p2 == NULL || num3 == NULL)
	{    
		ret = -1;
		return ret;
	}

	// 分配第一维内存
	tmpNum3 = num1 + num2;
	tmpp3 = (char **)malloc(tmpNum3 * sizeof(char *));

	if (tmpp3 == NULL)
	{
		ret = -1;
		return ret;
	}

	// 分配第二维内存
	for (i = 0; i < num1; i++)
	{
		tmpp3[i] = (char *)malloc(sizeof(char) * (strlen(p1[i]) + 1));
		strcpy(tmpp3[i], p1[i]);
	}

	for (j = 0; j < num2; j++,i++)
	{
		tmpp3[i] = (char *)malloc(sizeof(char) * (strlen(p2[j]) + 1));
		strcpy(tmpp3[i], p2[j]);
	}
	

	for (i = 0; i < tmpNum3; i++)
	{
		for (j = i+1 ; j < tmpNum3; j++)
		{
			if (strcmp(tmpp3[i] , tmpp3[j]) > 0)
			{
				temp = tmpp3[i];
				tmpp3[i] = tmpp3[j];
				tmpp3[j] = temp;
			}
		}
	}
	*p3 = tmpp3;
	*num3 = tmpNum3;

	return ret;
}

// D7A2
char **getArray3(char **p1, int num1, char(*p2)[30], int num2, int *num3)
{
	int ret = 0;
	int tmpNum3 = NULL;
	int i, j;
	char ** tmpp3 = NULL;
	char * temp = NULL;
	if (p1 == NULL || p2 == NULL || num3 == NULL)
	{
		return NULL;
	}

	// 分配第一维内存
	tmpNum3 = num1 + num2;
	tmpp3 = (char **)malloc(tmpNum3 * sizeof(char *));

	if (tmpp3 == NULL)
	{
		return NULL;
	}

	// 分配第二维内存
	for (i = 0; i < num1; i++)
	{
		tmpp3[i] = (char *)malloc(sizeof(char) * (strlen(p1[i]) + 1));
		strcpy(tmpp3[i], p1[i]);
	}
	for (j = 0; j < num2; j++)
	{
		tmpp3[num1 + j] = (char *)malloc(sizeof(char) * (strlen(p2[j]) + 1));
		strcpy(tmpp3[num1 + j], p2[j]);
	}
	*num3 = tmpNum3;

	for (i = 0; i < tmpNum3; i++)
	{
		for (j = i + 1; j < tmpNum3; j++)
		{
			if (strcmp(tmpp3[i], tmpp3[j]) > 0)
			{
				temp = tmpp3[i];
				tmpp3[i] = tmpp3[j];
				tmpp3[j] = temp;
			}
		}
	}



	return tmpp3;
}

int main()
{
	if (NULL == 0)
	{
		printf("NULL == 0\n");
	}
	
	int ret = 0;
	int num3 = 0, i = 0;
	char *p1[] = { "222222", "111111", "333333" };
	char p2[4][30] = { "bbbbbb", "aaaaaa", "cccccc", "dddddd" };
	char **p3 = NULL;

	//p3 = getArray3(p1, 3, p2, 4, &num3);
	ret = getArray3_02(p1, 3, p2, 4, &num3, &p3);
	if (ret != 0)
	{
		return;
	}

	for (i = 0; i < num3; i++)
	{
		printf("%s:\n", p3[i]);
	}
	
	// getArray3_Free(p3, num3);
	getArray3_Free_02(&p3, num3);
	p3 = NULL;

	system("pause");
	return 0;
}