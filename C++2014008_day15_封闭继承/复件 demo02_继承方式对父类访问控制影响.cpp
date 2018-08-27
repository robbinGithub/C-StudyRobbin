#include <cstdlib>
#include <iostream>

using namespace std;

class A
{
private:
	int a;
protected:
	int b;
public:
	int c;

	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
};
//继承用：符号
class B : public A    //public继承 可以继承protected，不能继承private
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err
		cout<<"b = "<<b;
		cout<<"c = "<<endl;
	}
};

class C : protected A  //proteced继承 
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err
		cout<<"b = "<<b;
		cout<<"c = "<<endl;
	}
};

class D : private A
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err
		cout<<"b = "<<b<<endl; 
		cout<<"c = "<<c<<endl; 
	}
};

int main020(int argc, char *argv[])
{
	A aa;
	B bb;
	C cc;
	D dd;

	aa.c = 100; //ok
	bb.c = 100; //ok
	//cc.c = 100;  //err 类的外部是什么含义 protected继承A的属性c(public)->protected，无法在类外部使用
	//dd.c = 100;  //err private继承A的属性c(public)->private，无法在类外部使用

	aa.set(1, 2, 3);
	bb.set(10, 20, 30);
	//cc.set(40, 50, 60); //ee
	//dd.set(70, 80, 90); //ee

	bb.print();
	cc.print();
	dd.print();

	system("pause");
	return 0;
}

//1 看访问父类属性（函数）这句话是写在了子类的内部、外部
//2 看子类如何从父类继承 （public、protected、private）
//3 看父类中的访问级别（public、protected、private）