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
				//交换的是数组元素 数组元素是指针
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
		printf("第%d个元素:%s \n", i + 1, p[i]);
	}
}


int main_02()
{
	int i = 0;
	// 二级指针第一种内存模型
	// 数组,指针数组,[只是每个元素是指针]
	// [] 优先级高
	// 打印数组 排序数组 指针做函数参数
	char * myArray[] = { "bbbb", "aaaa", "dddd", "cccc" };


	/* OK */
	*myArray = "eeee";

	/*
	 * 无法修改全局区常量池中字符串
	 * 0x00B31664 处的第一机会异常(在 C语言提高-指针.exe 中):  0xC0000005:  写入位置 0x00B36924 时发生访问冲突。
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

		 别名myArray 常量值:0x0024fce0 
		 指针步长：16

	 */
	sortArray(myArray, 4);
	printArray(myArray, 4);

	// 求数组元素个数
	int num = sizeof(myArray) / sizeof(myArray[0]);
	// int num = sizeof(myArray) / sizeof(*myArray);
	printf("数组元素个数%d \n", num);

	system("pause");

	return 0;

}