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
	//thread th1([]() {cout << this_thread::get_id() << endl; });    //��ȡ��ǰ�̵߳�id
	//thread th2([]() {cout << this_thread::get_id() << endl; });

	thread th1([]() {
		this_thread::sleep_for(chrono::seconds(3));    //�ȴ�3��
		this_thread::yield();        //��CPU��ִ�������̣߳���������ִ����
		cout << this_thread::get_id() << endl;        //��ȡ��ǰ�̵߳�id
		//this_thread::sleep_until();    //ĳ��ʱ�̵���֮ǰһֱ�ȴ�
	});
	thread th2([]() {
		this_thread::sleep_for(chrono::seconds(10));    //�ȴ�10��
		cout << this_thread::get_id() << endl;
	});

	cin.get();
}