#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    ��һά����������������

	����������������ʶ����Ƕ����ʹ�������������ϵĺ�����Ӱ�죬���������ʷֱ��ǣ�
	�������������Լ�ʹ������ʱͨ���Ὣ��ת����ָ�롣��Ϊ���ܿ������飬���������޷���ֵ���ݵķ�ʽʹ�������������Ϊ����ᱻת����ָ�룬���Ե�����Ϊ��������һ������ʱ��ʵ���ϴ��ݵ���ָ��������Ԫ�ص�ָ�롣

	���ܲ�����ֵ���ݵ���ʽ�������飬�������ǿ��԰��β�д�������������ʽ��

	//������ʽ��ͬ����������print�����ǵȼ۵�
	//ÿ����������һ��const int*���͵��β�
	void print(const int*);
	void print(const int[]);
	void print(const int[10])//�����ά�ȱ�ʾ�����������麬�ж���Ԫ�أ�ʵ�ʲ�һ��
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
		//printf("arr[%d]:%d\n", i, arr[i]); ����
		printf("arr[%d]:%d\n", i, *(arr+i));
	}
}

/*
 * �������鳤��
 */

// 1��ʹ�ñ��ָ�����鳤��
void print4(const char *cp)
{
	if (cp) {     //��cp���ǿ�ָ��
		while (*cp) {     //ֻҪָ����ָ�ַ����ǿ��ַ�
			// std::cout << *cp++;    //�����ǰ�ַ�����ָ��ǰ��
		}
	}
}

// 2����ʾ����һ����ʾ�����С���β�
void print5(int* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		//printf("arr[%d]:%d\n", i, arr[i]); ����
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
