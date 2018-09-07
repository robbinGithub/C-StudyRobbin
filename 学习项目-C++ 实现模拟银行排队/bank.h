#ifndef __BANK_H__
#define __BANK_H__

#include <queue>
#include <list>
#include <iostream>
using namespace std;

struct Event
{
	int _occur_time; // 事件发生的时刻
	int _type; // 事件类型，0表示到达事件，1到
					 // 4 表示四个窗口的离开事件

	Event()
	{
		std::cout << "Event Construct" << std::endl;
	}

	Event(int _occur_time, int _type):_occur_time(_occur_time), _type(_type)
	{
		std::cout << "Event Construct2" << std::endl;
	}

	~Event()
	{
		std::cout << "Event DeConstruct" << std::endl;
	}

	Event(const Event & event)
	{
		std::cout << "Event Copy Construct" << std::endl;
		_occur_time = event._occur_time;
		_type = event._type;
	}

	Event& operator=(const Event & event)
	{
		std::cout << "Event operator= " << std::endl;
		_occur_time = event._occur_time;
		_type = event._type;
		return *this;
	}

	bool operator<(const Event &rhs)
	{
		return _occur_time < rhs._occur_time;
	}
};

struct QueueNode
{
	int _arrival_time; // 客户到达时间
	int _duration_time;// 客户需要的服务员时间
};

class Bank
{
public:
	explicit Bank(int window_number = 4,
		int close_time = 8 * 3600);
	~Bank();
	void Simulation();
private:
	int _queue_number;                 // 队列个数
	int _close_time;                   // 关门时间
	int _total_time;                   // 累计客户逗留时间
	int _customer_number;              // 客户总数

	std::list<Event>      _event_list; // 事件链表
	std::queue<QueueNode> *_work_queue;// 工作队列

	void OpenForDay();
	void CustomerArrived(Event *event);
	void CustomerDeparture(Event *event);
	int FindShortestQueue();
	void SortEventList();
};

#endif