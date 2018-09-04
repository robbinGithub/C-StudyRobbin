#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <array>
#include <vector>

using namespace std;

static mutex m;
static condition_variable isfull, isempty;//�����������
static bool flag = true;//��־,�������˾��˳�
static vector<int> myint(10);//����10��Ԫ�أ���ʼ����10��Ĭ��ֵΪ0��Ԫ��

void produce(int num)    //����
{
	for (int i = 0; i < num; i++)
	{
		unique_lock<mutex> lk(m);    // ����
		while (myint.size() >= 10)   // ��̬����
		{
			isempty.wait(lk);    //����һֱ�ȴ�  �ȴ�����isempty��<10
		}

		myint.push_back(i);//����
		cout << "����" << i << endl;
		isfull.notify_all();//֪ͨ������

	}

	this_thread::sleep_for(chrono::seconds(5));//����5��

	flag = false;  

	cout << "�����߳�ִ�н���" << endl;

	// ���һ��������ϣ�֪ͨ�����߳�,�����߳����ѽ����� => wait()
	// 5S�����״̬��ǣ������̻߳���һֱ������wait������
	// ���ȴ�5S��ֱ�Ӹ�ֵflag = false, �ᵼ�������߳�δ���ѣ�ֱ�ӽ�����
}

void consume()    //����
{
	while (flag)
	{
		unique_lock<mutex> lk(m);    //����
		// while (myint.size() == 0)
		while (myint.empty())   // // ���һ��������(flag = false)����ǰ��������0 wait
		{  
			// ��������� @added by robbin
			if (!flag)
			{
				break;
			}

			cout << "�����߳�wait......................." << this_thread::get_id() << endl;
			isfull.wait(lk);//�ȴ�  �ȴ����� isfull size >0
		}

		if (flag)
		{
			cout << "����" << myint[myint.size() - 1] << " " << this_thread::get_id() << endl;
			myint.pop_back();//�޳����һ��

			isempty.notify_all();//֪ͨ�����߼�������
		}
	}
    
	cout << "�����߳�ִ�н���"<<endl;
}

int main_E8()
{

	myint.resize(0);
	thread t1(consume);    //������
	thread t2(consume);
	thread t3(consume);

	//produce(100);
	thread s1(produce, 15);//������
	thread s2(produce, 15);

	t1.join();
	t2.join();
	t3.join();

	cin.get();

	return 0;
}