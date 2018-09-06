#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>    //��������

using namespace std;

//�߳�ͨ�ţ����mutex
//һ���̣߳�����̴߳��ڵȴ���֪ͨһ����֪ͨ���

mutex m;                  //�̻߳����ų�
condition_variable cv;    //�߳�ͨ��

void main_011()
{
	// [�߳�1ָ�� ���߳�2ָ�룬 �߳�3ָ��...]  thΪ��Ԫ�صĵ�ַ(�߳�1ָ��ĵ�ַ)
	thread **th = new thread *[10];//�����̵߳�ָ������

	for (int i = 0; i < 10; i++)
	{
		th[i] = new thread([](int index)
		{
			unique_lock<mutex> lck(m);    //����
			cv.wait_for(lck, chrono::hours(1000));    //һֱ�ȴ�
			cout << index << endl;        //��ӡ���
		}, i);    //���ݲ���

		this_thread::sleep_for(chrono::milliseconds(100));    //��
	}

	// ���е��̶߳��ȴ�����������cv��
	for (int i = 0; i < 10; i++)
	{
		lock_guard<mutex> lckg(m);//������
	    // cin.get();
		// getchar();
		system("pause");
		cout << "֪ͨ��" << i << "���߳�" << endl;
		cv.notify_one();    //����֪ͨ
	}

	cout << "����֪ͨ����" << endl;

	for (int i = 0; i < 10; i++)
	{
		th[i]->join();
		delete th[i];
	}

	delete[]th;    //�ͷ�ָ������

	cin.get();
}