#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

struct fun
{
	void run1()
	{
		MessageBoxA(0, "12345", "ABCDE", 0);
		cout << "hello china" << endl;
	}

	void run2(const char *str)
	{
		MessageBoxA(0, str, str, 0);
		cout << "hello china" << endl;
	}
};

void main_08()
{
	//fun *p(nullptr);
	//p->run1();            //空类指针可以引用没有调用内部变量的成员函数

	fun fun1;
	//&fun::run引用成员函数
	thread th1(&fun::run1, fun1);
	thread th2(&fun::run1, fun1);

	thread th3(&fun::run2, fun1, "run2-1");
	thread th4(&fun::run2, fun1, "run2-2");

	cin.get();
}