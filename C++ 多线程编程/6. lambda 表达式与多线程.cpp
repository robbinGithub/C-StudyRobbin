#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>

using namespace std;

void main0701()
{
	//auto fun = []() {MessageBoxA(0, "1", "2", 0); };
	//thread th1(fun);
	//thread th2(fun);

	thread th1([]() {MessageBoxA(0, "11", "22", 0); });
	thread th2([]() {MessageBoxA(0, "11", "22", 0); });

	cin.get();
}

void main_06()
{
	//thread th1([]() {cout << this_thread::get_id() << endl; });    //获取当前线程的id
	//thread th2([]() {cout << this_thread::get_id() << endl; });

	thread th1([]() {
		this_thread::sleep_for(chrono::seconds(3));    //等待3秒
		this_thread::yield();        //让CPU先执行其他线程，空闲了再执行我
		cout << this_thread::get_id() << endl;        //获取当前线程的id
		//this_thread::sleep_until();    //某个时刻到来之前一直等待
	});
	thread th2([]() {
		this_thread::sleep_for(chrono::seconds(10));    //等待10秒
		cout << this_thread::get_id() << endl;
	});

	cin.get();
}