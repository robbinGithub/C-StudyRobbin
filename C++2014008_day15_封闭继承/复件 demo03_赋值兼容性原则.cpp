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
	//��дadd����
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

//������һ������ĸ��� ������Ե�����ʹ�� 
//��ֵ������ԭ�� 
void main31()
{
	A a;
	B b;
	b.b = 3;
	b.A::b = 4;
	/*
	a.print();

	
	b.print();

	//�����˸���p
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