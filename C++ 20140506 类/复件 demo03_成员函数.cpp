#include "iostream"
using namespace std;

//class 
//const c 冒牌货 
//register cpu身边的小太监
//typedef //混号王
class Test2
{
public:
	//友元函数的特点是：有一个参数是友元类的指针或引用
	friend int OpMem(Test2 *p, int a); //友元函数
	Test2(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return this->a;
	}
protected:

private:
	int a ;
	int b;
};


int OpMem(Test2 *p, int a)
{
	p->a = a;
	return 0;
}

void main111()
{
	Test2 t1(1, 2);
	t1.getA();
	OpMem(&t1, 10);
	system("pause");
}


class A
{ 
	friend class B ; //B是A类的友员类，B类所有的函数都是A类的友员函数
public :
	void  Display() { cout << x << endl ; } ;
private :
	int  x ;
} ;

class  B          //B类没有数据成员，只有对A类操作（组合A)
{ 
public :
	void Set ( int i ) { Aobject . x = i ; } 
	void Display ()  { Aobject . Display () ; } 
private :
	A  Aobject ;
} ;
void main03000()
{
	B  Bobject ;
	Bobject . Set ( 100 ) ;
	Bobject . Display () ;
	system("pause");
}
