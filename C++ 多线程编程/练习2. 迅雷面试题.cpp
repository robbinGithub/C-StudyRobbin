#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdbool>

using namespace std;

int _LOOP = 10;    // ѭ������
int _flag = 0;     // ��ʶ�� 012012012012 �����һ��ִ�е��߳�

mutex _m;
condition_variable _cv;


//2. Ѹ�������⣺
//
//��дһ�����򣬿���3���̣߳���3���̵߳�ID�ֱ�ΪA��B��C��ÿ���߳̽��Լ���ID����Ļ�ϴ�ӡ10�飬
//
//Ҫ�����������밴ABC��˳����ʾ���磺ABCABC...�����ε��ơ�


// T1  T2  T3 |   T1  T2  T3    |    T1   T2   T3

// #Flag 

// A   B   C  |   A   B   �á�  |    A    B    C 
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
		cout << (char)id;                //ת��id
		_cv.notify_all();                //֪ͨȫ��

	}
}


// ###################### C1 #######################

// T1: ���robbin
// T2: ���ldd
// T3: ���yelis

int shouldExeThreadId = 65; // ��ǰӦ��ִ�е��߳�
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
 *  3. ˼��������������Ϊ����5���̣߳�ID�ֱ�Ϊ1��2��3��4��5��
 *  ÿ���߳̽��Լ���ID����Ļ�ϴ�ӡ10�飬Ҫ��������Ϊ��12345,54321,12345,54321��...�������ơ�
 */

bool _forward = true;     // �������ڸ���������һ��Ӧ��ִ�е��߳�
int nextExeThreadId = 1;  // ��һ��Ӧ��ִ�е��߳�

void _func3(int id)
{  
	// 1 1 1 1 1 1 1 1 1 1 1
	// 2 2 2 2 2 2 2 2 2 2 2

	// ִ��˳��
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