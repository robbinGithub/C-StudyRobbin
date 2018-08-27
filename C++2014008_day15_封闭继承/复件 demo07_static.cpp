#include<iostream>
using std::cout;
using namespace std;

class A
{
public:
	A()
	{
		//cout<<&(A::c)<<endl;  构造函数使用静态变量时，应该先初始化
	}
	int a;
	static int c;

	static void mm()
	{
		cout<<&(A::c)<<endl;
	}
protected:
	int b;
private:

};

class B : public A
{
public:
	B()
	{
		//cout<<&B::c;
	}
	//static int c;

	int a;
protected:
	int b;
private:

};

void main070()
{ 
	//cout<<sizeof(A)<<endl;
	//cout<<sizeof(B);
	B b;

	system("pause");
}

