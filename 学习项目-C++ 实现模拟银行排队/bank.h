#ifndef __BANK_H__
#define __BANK_H__

#include <queue>
#include <list>
#include <iostream>
using namespace std;

struct Event
{
	int _occur_time; // �¼�������ʱ��
	int _type; // �¼����ͣ�0��ʾ�����¼���1��
					 // 4 ��ʾ�ĸ����ڵ��뿪�¼�

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
	int _arrival_time; // �ͻ�����ʱ��
	int _duration_time;// �ͻ���Ҫ�ķ���Աʱ��
};

class Bank
{
public:
	explicit Bank(int window_number = 4,
		int close_time = 8 * 3600);
	~Bank();
	void Simulation();
private:
	int _queue_number;                 // ���и���
	int _close_time;                   // ����ʱ��
	int _total_time;                   // �ۼƿͻ�����ʱ��
	int _customer_number;              // �ͻ�����

	std::list<Event>      _event_list; // �¼�����
	std::queue<QueueNode> *_work_queue;// ��������

	void OpenForDay();
	void CustomerArrived(Event *event);
	void CustomerDeparture(Event *event);
	int FindShortestQueue();
	void SortEventList();
};

#endif