#include <iostream>
#include <thread>
#include <Windows.h>

using namespace std;

/*
 * @see http://www.cnblogs.com/si-lei/p/9508541.html
 */
void run()
{
	MessageBoxA(0, "hello world", "hello china", 0);

}

void main0101()
{
	//同步（阻塞）
	run();
	run();
	run();

	cin.get();
}

void main0102()
{
	//并行，异步，非阻塞
	thread t1(run);        //根据函数初始化并执行,t1在栈上
	thread t2(run);
	thread t3(run);
	thread t4(run);

	cin.get();
}

void main0103()
{   
	//栈上
	//并行，异步，非阻塞
	//thread t[5]{ run,run,run,run,run };    //error C2440: “初始化”: 无法从“void (__cdecl *)(void)”转换为“std::thread”
	thread t[5]{ thread(run),thread(run), thread(run), thread(run), thread(run) };    //初始化线程数组（线程池）

	cin.get();
}

void main0104()
{
	//堆上
	thread *pthread1(new thread(run));
	thread *pthread2(new thread(run));
	thread *pthread3(new thread(run));

	cin.get();
}

void main_01()
{
	//堆上开辟了线程数组
	thread *pthread1(new thread[5]{ thread(run),thread(run), thread(run), thread(run), thread(run) });

	int *p1 = new int(1);
	int *p2(new int(1));

	cin.get();
}