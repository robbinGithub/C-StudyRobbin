#include "iostream"
using namespace std;

class  Complex
{
private:
	int a;
	int b;
	friend ostream& operator<<(ostream &out, Complex &c1);

public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<"+"<<b<<"i"<<endl;
	}
public:
	//通过类的成员函数实现-操作
	Complex operator-(Complex &c2)
	{
		Complex tmp;
		tmp.a = this->a -c2.a;
		tmp.b = b -c2.b;
		return tmp;
	}
	Complex operator+(Complex &c2)
	{
		Complex tmp;
		tmp.a = this->a + c2.a;
		tmp.b = b + c2.b;
		return tmp;
	}

	// 前置--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}

	// 前置++
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}

	//后置--
	Complex operator--(int)
	{
		Complex tmp = *this;
		this->a --;
		this->b --;
		return tmp;
	}

	//后置++
	Complex operator++(int)
	{
		Complex tmp = *this;
		this->a ++;
		this->b ++;
		return tmp;
	}
};




//1操作符重载，首先是通过函数实现的。
void main61()
{
	Complex c1(1, 2), c2(3, 4);

	//Complex c3 = ComAdd(c1, c2);
	//Complex c3 = operator+(c1, c2);
	//2  +操作符有两个参数 左操作数 和 右操作数
	//3 
	Complex c3 = c1 + c2;
	c3.printCom();

	Complex c4 = c1.operator-(c2);
	c4.printCom();

	Complex c5 = c1 - c2 ;
	c5.printCom();
	//目标 通过类的成员函数，完成操作符重载
	//1 要承认操作符重载是一个函数，要写函数原型
	//2 写出函数调用语言 c1.operator-(c2)
	//3 完善函数原型 

	++c2; 
	c2.printCom();

	//全局函数原型推导
	//Complex& operator++(Complex &c2);
	--c2; //c2.operator--();
	c2.printCom();


	//测试全局函数实现后置++
	c2++;
	c2.printCom();

	//测试用类成员函数实现后置--
	c2--;
	c2.printCom();

	system("pause");
}



ostream& operator<<(ostream &out, Complex &c1)
{
	cout<<"12345,上山打老虎"<<endl;
	cout<<c1.a<<"+"<<c1.b<<"i"<<endl;
	return out;
}

//1操作符重载，首先是通过函数实现的。
void main0600()
{
	Complex c1(1, 2), c2(3, 4);

	int a = 10;
	char *p = "abc";
	cout<<a<<endl;
	cout<<p<<endl;


	cout<<c1<<"链式编程测试"<<endl;
	operator<<(cout, c1);

	//函数返回值当左值的时候，需要返回一个对象的引用
	//cout<<c1   <<"aaa";
	//没有方法去在cout类里面添加函数operator<<，只能通过全局函数实现。
	//cout.operator<<( c1);
	//void operator<<(ostream &out, Complex &c1)


	system("pause");
}