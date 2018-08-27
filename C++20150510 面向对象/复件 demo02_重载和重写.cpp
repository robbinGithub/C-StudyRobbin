#include <cstdlib>
#include <iostream>

using namespace std;

//重载只放在在一个类里面 ，在编译期间就确定
class Parent01
{
public:
	Parent01()
	{
		cout<<"Parent01:printf()..do"<<endl;
	}
public:
	void aaaaa()
	{
		;
	}
	void func()
	{
		cout<<"Parent01:void func()"<<endl;
	}

	 void func(int i)
	{
		cout<<"Parent:void func(int i)"<<endl;
	}

	 // 错误：无法重载仅按返回类型区分的函数
	 /*
	 int func(int i)
	 {
		 cout << "Parent:void func(int i)" << endl;
		 return 0;
	 }*/

	 virtual void func(int i, int j)//
	{
		cout<<"Parent:void func(int i, int j)"<<endl;
	}
};

//重写 父子类之间，函数三要素（函数名、函数参数、函数返回类型）完全一样 
//重写又分为两种
//如果父类中有virtual关键字，这种父子之间的关系叫做虚函数重写，这种情况下发生多态 （动态链编 迟绑定）
//如果父类中没有virtual关键字，这种父子之间的关系 重定义  （静态链编）
class Child01 : public Parent01
{

public:

	//此处2个参数，和子类func函数是什么关系
	void func(int i, int j)
	{
		cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
	}

	//我想在子类中重载父类的func函数  ====》
	//此处3个参数的，和子类func函数是什么关系
	void func(int i, int j, int k)
	{
		cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
	}
};

void run01(Parent01* p)
{
	p->func(1, 2);
}

int main_0101()
{
	Parent01 p;

	p.func();
	p.func(1);
	p.func(1, 2);

	

	Child01 c;
	//c.func(); //注意1
	c.Parent01::func();
	//c.aaaaa();
	//c.func(1, 2);
	
	run01(&p);
	run01(&c);
	
	system("pause");
	
	return 0;
}

//问题1：child对象继承父类对象的func，请问这句话能运行吗？why
//c.func(); 

//1子类里面的func无法重载父类里面的func 
//2当父类和子类有相同的函数名、变量名出现，发生名称覆盖
//3//c.Parent::func();
//问题2 子类的两个func和父类里的三个func函数是什么关系？

