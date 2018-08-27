#include <cstdlib>
#include <iostream>
using namespace std;

/*
1、父类的属性，应该有父类的构造函数去初始化
2子类新增加的属性，应该有子类的构造函数完成；
	==父子分工，很明确
	*/


//在子类对象构造的时，需要调用父类构造函数对其继承得来的成员进行初始化
//在子类对象析构的时，需要调用父类析构函数对其继承得来的成员进行清理

class Parent04
{
public:
	Parent04(const char* s)
	{
		cout<<"Parent04()"<<" "<<s<<endl;
	}

	~Parent04()
	{
		cout<<"~Parent04()"<<endl;
	}
};

class Child04 : public Parent04
{
public:
	Child04() : Parent04("Parameter from Child!")
	{
		cout<<"Child04()"<<endl;
	}

	~Child04()
	{
		cout<<"~Child04()"<<endl;
	}
};

void run04()
{
	Child04 child;
}

int main050(int argc, char *argv[])
{
	run04();

	system("pause");
	return 0;
}
