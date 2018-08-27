#include "iostream"
using namespace std;

#include "MyCircle.h"
#include "MyPoint.h"

void mainc()
{
	MyCircle c1;
	MyPoint  p1;

	c1.setCir(2, 2, 3);
	p1.setPoint(1, 1);
	cout << c1.judge(p1.getX0(), p1.getY0()) << endl;
	cout << c1.judge(p1) << endl;
	system("pause");

}