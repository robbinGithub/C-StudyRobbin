#include <iostream>
#include <thread>
#include <mutex>    //互斥量
#include <atomic>    //原子变量

using namespace std;

//线程安全，多线程访问不冲突就是线程安全，冲突则不安全
//int num = 0;

//mutex m;            //互斥，加锁解锁浪费时间

atomic_int num(0);    //原子变量不会发生线程冲突，属于线程安全

 void static run()
{
	for (int i = 0; i < 10000000; i++)
	{
		//m.lock();
		num++;
		//m.unlock();
	}
}

void main_05()
{
	clock_t start = clock();

	thread th1(run);
	thread th2(run);
	th1.join();
	th2.join();

	clock_t end = clock();
	cout << num << endl;
	cout << end - start << "ms" << endl;

	cin.get();
}
//全局变量，会发生冲突，结果不正确，速度快
//mutex，结果正确，速度慢
//atomic，结果正确，速度比mutex快