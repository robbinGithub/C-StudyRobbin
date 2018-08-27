#pragma once
#include "MyPoint.h"
class MyCircle
{
public:
	void setCir(double x, double y, double r);

public:
	char * judge(double x, double y);
	char * judge(MyPoint &p);

private:
	double x1, y1; //Ô²ÐÄ×ø±ê
	double r1;  //Ô²°ë¾¶
};

