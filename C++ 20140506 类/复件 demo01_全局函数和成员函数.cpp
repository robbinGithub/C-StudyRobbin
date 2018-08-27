#include "iostream"
using namespace std;

class Test1
{
public:
	//Test1(this, int a, int b)
	Test1(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
public:
	//成员函数
	Test1& T_add(Test1 &t2)
	{
// 		Test1 t3;
// 		t3.a = t1.a + t2.a;
// 		t3.b = t1.b + t2.b;
// 		return t3;
		a = a + t2.a;
		this->b = this->b + t2.b;
		return *this;
	}
};


// Test1(Test1 *pThis, int a=0, int b=0)
// {
// 	this->a = a;
// 	this->b = b;
// }
//全局函数
Test1 T_add(Test1 &t1, Test1 &t2) 
{
	Test1 t3;
	t3.a = t1.a + t2.a;
	t3.b = t1.b + t2.b;
	return t3;
}

//从成员函数转化为全局函数 只需要加一个 this指针（指向本类的类指针）
//从全局函数转化为类的成员函数是，需要减一个做左操作数参数
void main010()
{
	Test1  t1(1, 2), t2(3, 4);
	Test1 t3;
	//t1 = T_add(t1 ,t2);

	//t1.add(t2); ====>add(this &t1, t2);
	t1.T_add(t2);


	system("pause");
}