#include "iostream"
using namespace std;

//指针也是一种数据类型，指针数据的数据类型是指，它所指的内存空间的数据类型
//最后一点引申 指针的步长 。。。c++

class Parent01
{
protected:
	int i;
	int		j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};


class Child01 : public Parent01
{	
public:
	int k;
public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		printf("Child01::f()...do\n");
	}
};

void howToF(Parent01 *pBase)
{
	pBase->f();
}

//指针的步长 在c++领域仍然有效，父类指针的步长和子类指针的步长不一样
//多态是靠迟绑定实现的（vptr+函数指针实现）
int main06()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;

	//不要把父类对象还有子类对象同事放在一个数组里面
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};

	//不要用父类指针做赋值指针变量，去遍历一个子类的数组。

	p = ca;
	c = ca;

	p->f();
	c->f(); //有多态发生

// 	p++;
// 	c++;
// 
// 	p->f();//有多态发生
// 	c->f();

	for (i=0; i<3; i++)
	{
		howToF(&(ca[i]));
	}

	
	system("pause");
	return 0;
}

