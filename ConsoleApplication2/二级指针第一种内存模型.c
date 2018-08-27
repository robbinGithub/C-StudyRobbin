#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* CHARP;


//1.void sortArray(char *arr[4], int len)  void sortArray(CHARP p[4], int len) 
//2.void sortArray(char *arr[], int len)   void sortArray(CHARP p[], int len) 
//3.void sortArray(char **arr, int len)    void sortArray(CHARP *p, int len) 

void sortArray(char **arr, int len)   
{
	int i = 0, j = 0;
	char * temp = NULL;

	for (i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{ 
			if (strcmp(arr[i], arr[j]) > 0)
			{  
				//������������Ԫ�� ����Ԫ����ָ��
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			
		}
	}
}

// void printArray(char *p[4], int len)
// void printArray(char *p[], int len)
// void printArray(char **arr, int len)

   void printArray(char **p, int len)
{  
	int i;
	for (i = 0; i < len; i++)
	{
		printf("��%d��Ԫ��:%s \n", i + 1, p[i]);
	}
}


int main_02()
{
	int i = 0;
	// ����ָ���һ���ڴ�ģ��
	// ����,ָ������,[ֻ��ÿ��Ԫ����ָ��]
	// [] ���ȼ���
	// ��ӡ���� �������� ָ������������
	char * myArray[] = { "bbbb", "aaaa", "dddd", "cccc" };


	/* OK */
	*myArray = "eeee";

	/*
	 * �޷��޸�ȫ�������������ַ���
	 * 0x00B31664 ���ĵ�һ�����쳣(�� C�������-ָ��.exe ��):  0xC0000005:  д��λ�� 0x00B36924 ʱ�������ʳ�ͻ��
	 */
	// (*myArray)[0] = "5";

    /*
	    char * myArray[4] =
		{
				0x0024fce0->  0x00b658a8  ->"aaaa"
				0x0024fce4->  0x00b658b0  ->"bbbb"
				0x0024fce8->  0x00b65918  ->"cccc"
				0x0024fcec->  0x00b65920  ->"dddd"
		 }

		 ����myArray ����ֵ:0x0024fce0 
		 ָ�벽����16

	 */
	sortArray(myArray, 4);
	printArray(myArray, 4);

	// ������Ԫ�ظ���
	int num = sizeof(myArray) / sizeof(myArray[0]);
	// int num = sizeof(myArray) / sizeof(*myArray);
	printf("����Ԫ�ظ���%d \n", num);

	system("pause");

	return 0;

}