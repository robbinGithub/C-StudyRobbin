#include "iostream"

using namespace std;

class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); //在构造函数里面能实现多态吗？  调用父类的方法，并不会调用子类print
	}

	//分析一下要想实现多态，c++编译器应该动什么手脚
	//第一个需要动手脚的地方  起码这个函数print 我应该特殊处理
	virtual void print()
	{
		cout<<"父类的"<<"a"<<a<<endl;
	}
protected:
	int a ;
};

class BB : public AA
{
public:
	BB(int a= 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	
	}
	virtual void print()
	{
		cout<<"子类的"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};


void howToPrintf(AA *pBase)
{
	//pBase 我怎么知道是父类对象还是子类对象
	//动手脚2：:区分是父类对象还是子类对象，提前布局
	pBase->print();  //
}
void main050()
{
	//AA a1;
	BB b1;
	//howToPrintf(&a1);
	howToPrintf(&b1);
	system("pause");
}