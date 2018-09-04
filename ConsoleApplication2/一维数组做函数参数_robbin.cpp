#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    【一维数组做函数参数】

	数组的两个特殊性质对我们定义和使用作用在数组上的函数有影响，这两个性质分别是：
	不允许拷贝数组以及使用数组时通常会将其转换成指针。因为不能拷贝数组，所以我们无法以值传递的方式使用数组参数。因为数组会被转换成指针，所以当我们为函数传递一个数组时，实际上传递的是指向数组首元素的指针。

	尽管不能以值传递的形式传递数组，但是我们可以把形参写成类似数组的形式：

	//尽管形式不同，但这三个print函数是等价的
	//每个函数都有一个const int*类型的形参
	void print(const int*);
	void print(const int[]);
	void print(const int[10])//这里的维度表示我们期望数组含有多少元素，实际不一定
	@see https://www.cnblogs.com/larryking/p/5734417.html
*/


void print1(int arr[10])
{
	for (size_t i = 0; i < 10; ++i)
	{
		printf("arr[%d]:%d\n", i, arr[i]);
	}
}

void print2(int arr[])
{
	for (size_t i = 0; i < 10; ++i)
	{
		printf("arr[%d]:%d\n", i, arr[i]);
	}
}

void print3(int* arr)
{
	for (size_t i = 0; i < 10; ++i)
	{
		//printf("arr[%d]:%d\n", i, arr[i]); 或者
		printf("arr[%d]:%d\n", i, *(arr+i));
	}
}

/*
 * 关于数组长度
 */

// 1、使用标记指定数组长度
void print4(const char *cp)
{
	if (cp) {     //若cp不是空指针
		while (*cp) {     //只要指针所指字符不是空字符
			// std::cout << *cp++;    //输出当前字符并将指针前移
		}
	}
}

// 2、显示传递一个表示数组大小的形参
void print5(int* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		//printf("arr[%d]:%d\n", i, arr[i]); 或者
		printf("arr[%d]:%d\n", i, *(arr + i));
	}
}


int main_x1()
{
	int pc[] = { 0,1,2,3,4,5,6,7,8,9 };
	print5(pc, 10);
	system("pause");

	return 0;
}
