#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
  指针数组用法
 */

#define DIM(a) (sizeof(a) /sizeof(*a))

/*
 * 在table中查找key对应的索引
 */
int searchKeyTable(const char * table[], const int size, const char * key, int *pos)
{   
	int rv = 0;
	int index = -1;
	int i = 0;
	int inum = 0;
	if (table == NULL || key == NULL || size <= 0 || pos == NULL)
	{
		rv = -1;
		printf("func searchKeyTable:%d", rv);
		return rv;
	}

	/*
	 *  P2: table:0x0025fb90 (存储P1的地址)
	 *	P1:	0x00087ad4 (存储P0的地址)
	 *  P0: 字符数组:"while"
	 */
	inum = sizeof(table) / sizeof(*table); 
	printf("inum:%d\n", inum);

	for (int i = 0; i < size; i++)
	{
		if (strcmp(table[i], key) == 0)
		{ 
			index = i;
			break;
		}
	}

	*pos = index;

	return rv;

}

int main_66()
{  
	int inum = 0;
	int pos = 0;

	char * c_keyword[] =
	{
		"while",
		"case",
		"static",
		"do"
	};

	inum = sizeof(c_keyword) / sizeof(c_keyword[0]);
	searchKeyTable(c_keyword, inum, "while", &pos);
	printf("pos:%d \n", pos);

	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
	printf("pos:%d \n", pos);

	system("pause");
}

// int main()
// int main(int argc)
int main_668(int argc, char* argv[], char* env[])
{
	int i = 0;
	printf("************************* Begin argv *************************\n");
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d]:%s\n", i, argv[i]);
	}
	printf("************************* End argv *************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("************************* Begin env *************************\n");
	for (i = 0; env[i] != NULL; i++) // ?
	{
		printf("env[%d]:%s\n", i, env[i]);
	}
	
	printf("************************* End env *************************\n");

	system("pause");

}