
#include "iostream"
using namespace std;

void swap(int &a, int &b)
{
	int c ;
	c = a;
	a = b;
	b = c;
}

void swap(float &a, float &b)
{
	float c ;
	c = a;
	a = b;
	b = c;
}
void main11()
{
	int a = 1, b = 2;
	swap(a, b);
	float a1 = 1, b1 = 2;
	swap(a1, b1);
	system("pause");
}


//template关键字告诉c++编译器，现在开始泛型编程
//typename 告诉c++编译器，T为类型（T为类型，可以参数化，int float），你不要乱报错
//类型参数化。。。。。。。

// template<typename T> 和 template<class T> 完全相同

template<typename T>
void swap2(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

void main_01()
{
	//泛型编程的调用方式有两种
	//自动类型推导
	int x =1, y =2;
	swap2(x, y);
	printf("x:%d y:%d \n", x, y);

	float x1= 1.0, y1 = 2.0;

	//具体类型调用
	swap2<float>(x1, y1);
	printf("x1:%f y1:%f \n", x1, y1);
	system("pause");
}

