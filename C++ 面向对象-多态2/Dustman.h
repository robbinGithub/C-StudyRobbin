#ifndef DUSTMAN_H
#define DUSTMAN_H

#include "Worker.h"
class Dustman:public Worker {
public:
	Dustman(string name,int age);
	~Dustman();
	virtual void work();
	virtual void printinfo();
};

#endif