#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <cstdlib>

using namespace std;

void main_0401()
{
	string str1("12345");
	string str2("678910");
	string str3(str1 + str2);    //C++风格的字符串
	cout << str3 << endl;

	cin.get();
}

promise<string>val;    //全局通信变量

void main_09()
{
	thread th1([]()
	{
		future<string> fu = val.get_future();//获取未来的状态
		cout << "等待中..." << endl;
		cout << fu.get() << endl;
	});


	thread th2([]()
	{
		system("pause");
		val.set_value("I love CPP");
		system("pause");
	});

	th1.join();
	th2.join();

}