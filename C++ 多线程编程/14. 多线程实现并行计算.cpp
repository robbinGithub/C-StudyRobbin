#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cstdlib>

using namespace std;

#define COUNT 100000000

// http://www.cnblogs.com/si-lei/p/9508541.html

//�̺߳�����
int add(vector<int> *arr, int start, int count)
{
	static mutex m;    //��̬�ֲ�������ֻ���ʼ��һ��
	int sum(0);//������

	for (int i = 0; i < count; i++)
	{
		sum += (*arr)[start + i];//ʵ���ۼ�
	}

	{    //�˴������Ǽ�������е���ʾ��������鿴
		lock_guard<mutex> lckg(m);//����,���������̸߳���

		cout << "thread" << this_thread::get_id() << ",count=" << count << ",sum=" << sum << endl;
	}

	return sum;
}

void main_14()
{
	vector<int> data(COUNT);    //���飬100��Ĵ�С
	for (int i = 0; i < COUNT; i++)
	{
		data[i] = i % 10000;    //0-999
	}

	vector< future<int> > result;//�������

	int cpus = thread::hardware_concurrency();//CPU���ĵĸ���

	for (int i = 0; i < cpus * 2; i++)
	{
		//1000 10= 100 * 10
		//1000 9 = 1000 - 111*8
		int batch_each = COUNT / (cpus * 2);

		if (i == (cpus * 2) - 1)
		{
			batch_each = COUNT - COUNT / (cpus * 2)*i;//���һ���е��Ķ�һ��
		}

		//����ѹ����
		result.push_back(async(add, &data, i*batch_each, batch_each));//asyncֱ�ӷ��ؽ��

	}

	//����
	int lastresult(0);
	for (int i = 0; i < cpus * 2; i++)
	{
		lastresult += result[i].get();//���ܽ�����ۼ�
	}
	cout << "lastresule=" << lastresult << endl;

	cin.get();
}