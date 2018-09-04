#include <iostream>
#include <thread>
#include <mutex>    //������
#include <atomic>    //ԭ�ӱ���

using namespace std;

//�̰߳�ȫ�����̷߳��ʲ���ͻ�����̰߳�ȫ����ͻ�򲻰�ȫ
//int num = 0;

//mutex m;            //���⣬���������˷�ʱ��

atomic_int num(0);    //ԭ�ӱ������ᷢ���̳߳�ͻ�������̰߳�ȫ

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
//ȫ�ֱ������ᷢ����ͻ���������ȷ���ٶȿ�
//mutex�������ȷ���ٶ���
//atomic�������ȷ���ٶȱ�mutex��