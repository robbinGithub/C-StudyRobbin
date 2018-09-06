#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>    //条件变量

using namespace std;

//线程通信，结合mutex
//一个线程，多个线程处于等待，通知一个或通知多个

mutex m;                  //线程互相排斥
condition_variable cv;    //线程通信

void main_011()
{
	// [线程1指针 ，线程2指针， 线程3指针...]  th为首元素的地址(线程1指针的地址)
	thread **th = new thread *[10];//开辟线程的指针数组

	for (int i = 0; i < 10; i++)
	{
		th[i] = new thread([](int index)
		{
			unique_lock<mutex> lck(m);    //锁定
			cv.wait_for(lck, chrono::hours(1000));    //一直等待
			cout << index << endl;        //打印编号
		}, i);    //传递参数

		this_thread::sleep_for(chrono::milliseconds(100));    //错开
	}

	// 所有的线程都等待在条件变量cv上
	for (int i = 0; i < 10; i++)
	{
		lock_guard<mutex> lckg(m);//解锁向导
	    // cin.get();
		// getchar();
		system("pause");
		cout << "通知第" << i << "个线程" << endl;
		cv.notify_one();    //挨个通知
	}

	cout << "解锁通知结束" << endl;

	for (int i = 0; i < 10; i++)
	{
		th[i]->join();
		delete th[i];
	}

	delete[]th;    //释放指针数组

	cin.get();
}