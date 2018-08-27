
/*
1 编写一个业务函数，实现字符串（前后各有三个空格，单词前后也均有空格）
"   i am student, you are teacher   " ，
各个单词首字符大写，结果如下"   I Am Student, You Are Teacher   " ，
要求1：实现所有接口  70
要求2：写出测试程序  30
*/

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int GetString(const char *str1 /*in*/, char *str2 /*in*/);

int GetString_Adv(const char *str1/*in*/, char **str2 /*out*/);
int GetString_Adv_Free1(char *str2);
int GetString_Adv_Free2(char **str2);

int GetString(const char *str1 /*in*/, char *str2 /*in*/)
{
	char *p1 = NULL, *p2 = NULL;
	int len = 0, i = 0;

	if (str1 == NULL || str2 == NULL)
	{
		return -1;
	}
	len = strlen(str1);
	strcpy(str2, str1);
	if (len <1 )
	{
		return -1;
	}
	p1 = str2 +1;
	p2 = str2;
	for (i=0; i<len; i++)
	{
		if (isalpha(*p1) && isspace(*p2))
		{
			*p1 = *p1 - 32 ;
		}
		p1++;
		p2++;
	}
	return 0;
}

void main0101()
{
	int ret = 0;
	char *p = "   i am student, you are teacher   ";
	char str2[1024*10] = {0};
	//char *str3 = (char *)malloc(1024*10*sizeof(char ));
	ret = GetString(p /*in*/,str2 /*in*/);
	if (ret != 0)
	{
		return;
	}
	printf("%s ", str2);

	system("pause");
}
int GetString_Adv(const char *str1/*in*/, char **pp2 /*out*/)
{
	char *p1 = NULL, *p2 = NULL;
	int len = 0, i = 0;
	char *tmp = NULL;

	if (str1 == NULL || pp2 == NULL)
	{
		return -1;
	}
	len = strlen(str1);

	tmp = (char *)malloc((len+1) *sizeof(char));
	if (tmp == NULL)
	{
		return -2;
	}
	strcpy(tmp, str1);

	if (len <1 )
	{
		return -1;
	}
	//准备循环条件
	p1 = tmp +1;
	p2 = tmp;
	for (i=0; i<len; i++)
	{
		if (isalpha(*p1) && isspace(*p2))
		{
			*p1 = *p1 - 32 ;
		}
		//准备循环条件
		p1++;
		p2++;
	}
	//赋值
	*pp2 = tmp;
	return 0;

}
//直接释放形参执向的内存空间，没有修改实参的值，不能有效的避免野指针
int GetString_Adv_Free1(char *str2)
{
	if (str2 != NULL)
	{
		free(str2);
	}
}

//直接释放形参执向的内存空间，间接去修改实参的值，有效的避免野指针
int GetString_Adv_Free2(char **str2)
{
	char *tmp = *str2;
	if (str2 == NULL)
	{
		return 0;
	}
	if (tmp != NULL)
	{
		free(tmp);
		*str2 = NULL;
	}
}

void main0001()
{
	int ret = 0;
	char *p = "   i am student, you are teacher   ";
	//char str2[1024*10] = {0};
	//str2 = 0x11;
	//char *str3 = (char *)malloc(1024*10*sizeof(char ));
	char *str2 = NULL;
	ret = GetString_Adv(p /*in*/,&str2 /*out*/);
	if (ret != 0)
	{
		return;
	}
	printf("%s ", str2);

	if (str2 != NULL) 
	{
		free(str2);
		str2 = NULL;
	}

	GetString_Adv_Free1(str2);
	system("pause");
}