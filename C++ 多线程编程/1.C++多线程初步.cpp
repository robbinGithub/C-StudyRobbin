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
	//ͬ����������
	run();
	run();
	run();

	cin.get();
}

void main0102()
{
	//���У��첽��������
	thread t1(run);        //���ݺ�����ʼ����ִ��,t1��ջ��
	thread t2(run);
	thread t3(run);
	thread t4(run);

	cin.get();
}

void main0103()
{   
	//ջ��
	//���У��첽��������
	//thread t[5]{ run,run,run,run,run };    //error C2440: ����ʼ����: �޷��ӡ�void (__cdecl *)(void)��ת��Ϊ��std::thread��
	thread t[5]{ thread(run),thread(run), thread(run), thread(run), thread(run) };    //��ʼ���߳����飨�̳߳أ�

	cin.get();
}

void main0104()
{
	//����
	thread *pthread1(new thread(run));
	thread *pthread2(new thread(run));
	thread *pthread3(new thread(run));

	cin.get();
}

void main_01()
{
	//���Ͽ������߳�����
	thread *pthread1(new thread[5]{ thread(run),thread(run), thread(run), thread(run), thread(run) });

	int *p1 = new int(1);
	int *p2(new int(1));

	cin.get();
}