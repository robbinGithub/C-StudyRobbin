#include <iostream>
#include <thread>
#include <array>
#include <Windows.h>

using namespace std;

//join让当前主线程等待所有子线程执行完成才能退出
//detach脱离主线程的绑定，主线程退出的时候，不影响子线程。
void show()
{
	MessageBoxA(0, "1", "1", 0);

	// Sleep(10000);
	// cout << "Show END !" << endl;
}

void main0401()
{
	array<thread, 3> threads{ thread(show),thread(show),thread(show) };

	for (int i = 0; i < 3; i++)
	{
		cout << threads[i].joinable() << endl;    //判断是否可以join 
		threads[i].join();    //主线程等待子线程执行完成再退出 
	}

	auto n = thread::hardware_concurrency();    //获取CPU是几核
	cout << n << endl;

	cin.get();
}

int main_04()
{
	thread th(show);
    // th.join();
	th.detach();    //脱离主线程，主线程挂了不报错
	//detach以后线程无法通信

	// th.joinable();

	cout << "主线程结束！" << endl;

	return 0;
}