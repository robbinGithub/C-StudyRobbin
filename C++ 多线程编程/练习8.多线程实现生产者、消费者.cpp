#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <array>
#include <vector>

using namespace std;

static mutex m;
static condition_variable isfull, isempty;//处理两种情况
static bool flag = true;//标志,消费完了就退出
static vector<int> myint(10);//开辟10个元素，初始化了10个默认值为0的元素

void produce(int num)    //生产
{
	for (int i = 0; i < num; i++)
	{
		unique_lock<mutex> lk(m);    // 锁定
		while (myint.size() >= 10)   // 竞态条件
		{
			isempty.wait(lk);    //满了一直等待  等待条件isempty：<10
		}

		myint.push_back(i);//插入
		cout << "生产" << i << endl;
		isfull.notify_all();//通知消费者

	}

	this_thread::sleep_for(chrono::seconds(5));//休眠5秒

	flag = false;  

	cout << "生产线程执行结束" << endl;

	// 最后一轮生产完毕，通知消费线程,消费线程消费结束后 => wait()
	// 5S后更新状态标记，消费线程还会一直阻塞在wait函数中
	// 不等待5S，直接赋值flag = false, 会导致消费线程未消费，直接结束掉
}

void consume()    //消费
{
	while (flag)
	{
		unique_lock<mutex> lk(m);    //锁定
		// while (myint.size() == 0)
		while (myint.empty())   // // 最后一批生产中(flag = false)，当前容器数量0 wait
		{  
			// 生产完毕了 @added by robbin
			if (!flag)
			{
				break;
			}

			cout << "消费线程wait......................." << this_thread::get_id() << endl;
			isfull.wait(lk);//等待  等待条件 isfull size >0
		}

		if (flag)
		{
			cout << "消费" << myint[myint.size() - 1] << " " << this_thread::get_id() << endl;
			myint.pop_back();//剔除最后一个

			isempty.notify_all();//通知生产者继续生产
		}
	}
    
	cout << "消费线程执行结束"<<endl;
}

int main_E8()
{

	myint.resize(0);
	thread t1(consume);    //消费者
	thread t2(consume);
	thread t3(consume);

	//produce(100);
	thread s1(produce, 15);//消费者
	thread s2(produce, 15);

	t1.join();
	t2.join();
	t3.join();

	cin.get();

	return 0;
}