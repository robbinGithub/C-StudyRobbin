#include <iostream>
#include <thread>
#include <array>
#include <Windows.h>

using namespace std;

//join�õ�ǰ���̵߳ȴ��������߳�ִ����ɲ����˳�
//detach�������̵߳İ󶨣����߳��˳���ʱ�򣬲�Ӱ�����̡߳�
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
		cout << threads[i].joinable() << endl;    //�ж��Ƿ����join 
		threads[i].join();    //���̵߳ȴ����߳�ִ��������˳� 
	}

	auto n = thread::hardware_concurrency();    //��ȡCPU�Ǽ���
	cout << n << endl;

	cin.get();
}

int main_04()
{
	thread th(show);
    // th.join();
	th.detach();    //�������̣߳����̹߳��˲�����
	//detach�Ժ��߳��޷�ͨ��

	// th.joinable();

	cout << "���߳̽�����" << endl;

	return 0;
}