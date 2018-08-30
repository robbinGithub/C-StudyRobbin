#include "AA.h"
#include <iostream>
using namespace std;

AA::AA(int v)
{
   a = v;
   cout << "调用AA构造函数" <<a<< endl;
}


AA& AA::operator = (const  AA &aa)
{  
	a = aa.a;
	cout << "调用AA赋值函数" << a << endl;
	return *this;
}

AA::~AA()
{
	cout << "调用AA析构函数" << a << endl;
}
