#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cstdlib>

using namespace std;

#define COUNT 100000000

// http://www.cnblogs.com/si-lei/p/9508541.html

//线程函数：
int add(vector<int> *arr, int start, int count)
{
	static mutex m;    //静态局部变量，只会初始化一次
	int sum(0);//保存结果

	for (int i = 0; i < count; i++)
	{
		sum += (*arr)[start + i];//实现累加
	}

	{    //此处仅仅是计算过程中的显示，更清楚查看
		lock_guard<mutex> lckg(m);//加锁,不让其他线程干涉

		cout << "thread" << this_thread::get_id() << ",count=" << count << ",sum=" << sum << endl;
	}

	return sum;
}

void main_14()
{
	vector<int> data(COUNT);    //数组，100万的大小
	for (int i = 0; i < COUNT; i++)
	{
		data[i] = i % 10000;    //0-999
	}

	vector< future<int> > result;//结果数组

	int cpus = thread::hardware_concurrency();//CPU核心的个数

	for (int i = 0; i < cpus * 2; i++)
	{
		//1000 10= 100 * 10
		//1000 9 = 1000 - 111*8
		int batch_each = COUNT / (cpus * 2);

		if (i == (cpus * 2) - 1)
		{
			batch_each = COUNT - COUNT / (cpus * 2)*i;//最后一个承担的多一点
		}

		//不断压入结果
		result.push_back(async(add, &data, i*batch_each, batch_each));//async直接返回结果

	}

	//汇总
	int lastresult(0);
	for (int i = 0; i < cpus * 2; i++)
	{
		lastresult += result[i].get();//汇总结果，累加
	}
	cout << "lastresule=" << lastresult << endl;

	cin.get();
}