#include <iostream>
#include <thread>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void test()
{
	int i = 0;
	while (1)
	{
		cout << ++i << endl;
		Sleep(1000);
	}
}

void main_02()
{
	thread *p(new thread(test));    //¶ÑÉÏ

	system("pause");

	system("pause");

	system("pause");

	system("pause");

	cin.get();
}