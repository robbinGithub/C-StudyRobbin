#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdbool>

using namespace std;

int _LOOP = 10;    // 循环次数
int _flag = 0;     // 标识符 012012012012 标记下一个执行的线程

mutex _m;
condition_variable _cv;


//2. 迅雷面试题：
//
//编写一个程序，开启3个线程，这3个线程的ID分别为A、B、C，每个线程将自己的ID在屏幕上打印10遍，
//
//要求输出结果必须按ABC的顺序显示。如：ABCABC...，依次递推。


// T1  T2  T3 |   T1  T2  T3    |    T1   T2   T3

// #Flag 

// A   B   C  |   A   B   Ｃ　  |    A    B    C 
// -  A
// 0   1   2      0   1    2         0    1    2  

// @see https://www.cnblogs.com/si-lei/p/9515012.html

void _func(int id)
{
	for (int i = 0; i < _LOOP; i++)
	{
		unique_lock<mutex> ulk(_m);

		while (id - 'A' != _flag)
		{
			_cv.wait(ulk);
		}
		_flag = (_flag + 1) % 3;
		cout << (char)id;                //转换id
		_cv.notify_all();                //通知全部

	}
}


// ###################### C1 #######################

// T1: 输出robbin
// T2: 输出ldd
// T3: 输出yelis

int shouldExeThreadId = 65; // 当前应该执行的线程
void _func2(int id)
{
	string content;
	if (id == 65) {
		content = "robbin";
	}
	else if (id == 66) {
		content = "ldd";
	}
	else
	{
		content = "yelis";
	}
	for (int i = 0; i < _LOOP; i++)
	{
		unique_lock<mutex> ulk(_m);
		while (id != shouldExeThreadId)
		{
			_cv.wait(ulk);
		}
		cout << content.c_str() << endl;
		shouldExeThreadId++;
		if (shouldExeThreadId == 68) shouldExeThreadId = 65;
		_cv.notify_all();
	}
}

// ###################### C2 #######################
/*
 *  3. 思考：上题中若变为开启5个线程，ID分别为1，2，3，4，5，
 *  每个线程将自己的ID在屏幕上打印10遍，要求输出结果为：12345,54321,12345,54321，...依此类推。
 */

bool _forward = true;     // 方向，用于辅助计算下一线应该执行的线程
int nextExeThreadId = 1;  // 下一个应该执行的线程

void _func3(int id)
{  
	// 1 1 1 1 1 1 1 1 1 1 1
	// 2 2 2 2 2 2 2 2 2 2 2

	// 执行顺序
	// T1 T2 T3 T4 T5
	// T5 T4 T3 T2 T1
	// T1 T2 T3 T4 T5
	// T5 T4 T3 T2 T1

    // 12345543211234554321

	for (int i = 0; i < _LOOP; i++)
	{
		unique_lock<mutex> ulk(_m);
		while (id != nextExeThreadId)
		{
			_cv.wait(ulk);
		}
		cout <<id;

		if(_forward)
		{
			nextExeThreadId++;
			if (nextExeThreadId == 6)
			{
				nextExeThreadId = 5;
				_forward = false;
			}
		}
		else
		{
			nextExeThreadId--;
			if (nextExeThreadId == 0)
			{
				nextExeThreadId = 1;
				_forward = true;
			}
		}
		_cv.notify_all();
	}
}


int main_E2()
{
  /*
    thread *pthread1(new thread(_func, 65));
	thread *pthread2(new thread(_func, 66));
	thread *pthread3(new thread(_func, 67));

	pthread1->join();
	pthread2->join();
	pthread3->join();

	delete pthread1;
	delete pthread2;
	delete pthread3;*/

	//thread t1(_func2, 65);
	//thread t2(_func2, 66);
	//thread t3(_func2, 67);

	//t1.join();
	//t2.join();
	//t3.join();

	thread t1(_func3, 1);
	thread t2(_func3, 2);
	thread t3(_func3, 3);
	thread t4(_func3, 4);
	thread t5(_func3, 5);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	system("pause");

	return 0;
}