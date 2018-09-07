#include "bank.h"
#include <iostream>
#include <clocale>
#include <chrono>
#include <cstdlib>

/*
#include <algorithm>
std::sort(_work_queue, _work_queue + _queue_number,
	  [](const std::queue<QueueNode> &q1,
		const std::queue<QueueNode> &q2) -> bool
	  {return q1.size() < q2.size();});
*/

Bank::Bank(int window, int close_time)
	:_queue_number(window), _close_time(close_time),
	_total_time(0), _customer_number(0)
{
	_work_queue = new std::queue<QueueNode>[window];

	srand(std::chrono::system_clock
		::to_time_t(std::chrono::system_clock::now()));
}

Bank::~Bank()
{
	delete[] _work_queue;
}

void Bank::OpenForDay()
{
	// ��һ���ͻ�����
	_event_list.push_back({ 0, 0 });
}

// �ͻ������¼�
// �ͻ�����ʱ������������Ҫ����
// ����Ϊ��ʱ�̵���Ŀͻ��������һ������������Ҫʱ��
// �������������һ�ͻ������ʱ����
// �����ѵ���Ŀͻ�����һ����̵Ĺ�������
void Bank::CustomerArrived(Event *event)
{
	++_customer_number;

	int duration_time, inter_time;

	// ��ʱ�̵���ͻ�����������Ҫʱ��
	duration_time = rand() % 1800 + 1; //һ���ͻ����Ҫ30����  [0-32767)
	// ��һ���ͻ��ڴ�event->_occur_time+inter_timeʱ�̵���
	inter_time = rand() % 600 + 1; // ���10������һ���ͻ�

	// ��һ���ͻ�����ʱ��
	int t = event->_occur_time + inter_time;

	// ���л�û�й���
	if (t < _close_time) {
		_event_list.push_back({ t, 0 });
		// ������ʱ�������¼�����ǰ���
		SortEventList();
	}
	// ѡһ����̶����Ŷ�
	int i;
	i = FindShortestQueue();

	_work_queue[i].push({ event->_occur_time, duration_time });

	if (_work_queue[i].size() == 1) {
		// ���i���е�һ���ͻ������������뿪�¼�
		_event_list.push_back(
			{ event->_occur_time + duration_time, i + 1 });
		SortEventList();
	}
}

void Bank::CustomerDeparture(Event *event)
{
	int i = event->_type - 1;

	QueueNode customer;

	// �ͻ���������ϣ��뿪
	customer = _work_queue[i].front();
	_work_queue[i].pop();

	_total_time
		+= event->_occur_time - customer._arrival_time;

	// ��i�����е�һ���뿪�¼�
	if (!_work_queue[i].empty()) {
		customer = _work_queue[i].front();
		_event_list.push_back(
			{ customer._duration_time + event->_occur_time, i + 1 });
		SortEventList();
	}
}

int Bank::FindShortestQueue()
{
	int result = 0;
	for (int i = 0; i < _queue_number; ++i) {
		if (_work_queue[result].size() > _work_queue[i].size())
			result = i;
	}
	return result;
}

void Bank::SortEventList()
{
	// ����һ��Lambda���ʽ��
	_event_list.sort(
		[](const Event &e1, const Event &e2) -> bool
	{return e1._occur_time < e2._occur_time; });

	// ��������
	// ��֪����ôдһ���������Ƚ�����event��
	// ��ʵ���ǰ�Lambda���ʽд��һ����������
	// ���������Ϊsort�Ĳ����Ϳ����ˡ�

	// ��������ʹ�� struct Event::operator< ��
	_event_list.sort();

	// ע�⣺����ķ���һ�ͷ���������ע�͵��κ�һ����
	// д������ֻ��Ϊ����ʾ��
}

void Bank::Simulation()
{
	OpenForDay();
	Event event;
	while (!_event_list.empty()) {
		event = _event_list.front(); // front����������һ����ʱ���󣬸�ֵ��Event��ɾ����ʱ����
		_event_list.pop_front();
		if (event._type == 0) // �����¼�
			CustomerArrived(&event);
		else
			CustomerDeparture(&event);

		// std::chrono::milliseconds dura(20000);
	}
	// ���㲢���ƽ������ʱ��
	std::wcout << L"�ͻ�����" << _customer_number << std::endl
		<< L"�ܶ���ʱ�䣨Сʱ����" << (double)_total_time / 3600.0
		<< std::endl
		<< L"ƽ������ʱ�䣨���ӣ���"
		<< (double)_total_time / (double)(_customer_number * 60)
		<< std::endl;
}

int wmain(int argc, wchar_t *argv[], wchar_t *env[])
{
	_wsetlocale(LC_ALL, L"");

	Bank bank;
	bank.Simulation();
	return 0;
}