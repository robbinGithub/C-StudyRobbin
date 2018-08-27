#include "iostream"
using namespace std;


class A
{
public:
	int a;
	int b;
	A(int a = 0, int b =0)
	{
		this->a = a;
		this->b = b;
	}

	void add()
	{
		a = a + 10;
	}
	void print()
	{
		cout<<"a"<<a<<"b"<<b<<endl;
	}

private:
};

class B : public A
{
public:
	//重写add方法
	void add()
	{
		a++;
	}
		int b;
protected:
private:

};

void howToCall(A *pA)
{
	pA->print();
}

//子类是一中特殊的父类 子类可以当父类使用 
//赋值兼容性原则 
void main31()
{
	A a;
	B b;
	b.b = 3;
	b.A::b = 4;
	/*
	a.print();

	
	b.print();

	//定义了父类p
	A *pA = NULL;
	pA = &b;
	pA->print();

	//
	A &myb= b;
	myb.print();
	*/
	howToCall(&a);
	b.add();
	howToCall(&b);

	system("pause");
}

void main030()
{
	B b1;
	b1.add();
	b1.A::add();
	system("pause");
}