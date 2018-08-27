#include "iostream"
using namespace std;


class Parent
{
public:
	static int a;
	int b;
	Parent()
	{
		;
	}

	static void add()
	{
		a = a + 10;
	}
	void print()
	{
		cout<<"a"<<a<<"b"<<b<<endl;
	}

private:
};
int Parent::a = 10;

class Child : private Parent
{
public:
	
protected:
private:

};

void main040()
{
	Child c1;
	//c1.add();
	system("pause");
}