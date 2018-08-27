#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 @see http://c.biancheng.net/cpp/html/107.html
 */

typedef struct _Student
{
	char name[10];
	int num;
	int age;
	char addr[15];
}Student;

#define SIZE 5 

void save();
void load();

int main_03()
{  
	
	save();

	load();

	system("pause");

	return 0;
}


void save()
{
	FILE *fp = NULL;
	int i = 0;
	char *filename = "D:\student.data";

	Student student[5];

	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("cannot open file\n");
		return;
	}

	for (i = 0; i < 5; i++)
	{
		memset(&student[i], 0, sizeof(Student));
		sprintf(student[i].name, "name%d", i);
		student[i].age = i;
	}

	for (i = 0; i < 5; i++)
	{
		if (fwrite(&student[i], sizeof(Student), 1, fp) != 1)
		{

			printf("file write error\n");
		}
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void load()
{
	FILE *fp = NULL;
	int i = 0;
	char *filename = "D:\student.data";

	Student student[SIZE];
	for (i = 0; i<SIZE; i++)
	{
		memset(&student[i], 0, sizeof(Student));
		//sprintf(student[i].name, "name%d", i+1);
	}

	// fread
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("func fopen err\n");
		return;
	}

	for (i = 0; i<SIZE; i++)
	{
		fread(&student[i], sizeof(Student), 1, fp);
		printf("%-10s %4d %4d %-15s\n", student[i].name,
			student[i].num, student[i].age, student[i].addr);
	}


	// feof会有问题(不知道原因)

	//i = 0;
	//while (!feof(fp))
	//{
	//	fread(&buf, sizeof(Student), 1, fp);
	//	printf("student%d:name:%s,age:%d \n", i++, buf.name, buf.age);
	//}

	if (fp)
	{
		fclose(fp);
	}


}