#include "MyCircle.h"

void MyCircle::setCir(double x, double y, double r)
{
	//这里面也是类的内部
	x1 = x; y1 = y; r1 = r;
}
char* MyCircle::judge(double x, double y)
{
	double s = (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) - r1*r1;
	if (s > 0)
	{
		return "在圆外";
	}
	else
	{
		return "在圆内";
	}
}
char* MyCircle::judge(MyPoint &p)
{
	double s = (x1 - p.getX0())*(x1 - p.getX0()) + (y1 - p.getY0())*(y1 - p.getY0()) - r1*r1;
	if (s > 0)
	{
		return "在圆外";
	}
	else
	{
		return "在圆内";
	}
}