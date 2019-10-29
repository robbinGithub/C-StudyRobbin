
#ifndef WORKER_H
#define WORKER_H  

#include "Person.h"
using namespace std;

class Worker :public Person{
public:
	Worker(string name, int age);
	~Worker();
	//virtual void work() = 0;
	virtual void printinfo();
private:
		int m_iAge;
};

#endif