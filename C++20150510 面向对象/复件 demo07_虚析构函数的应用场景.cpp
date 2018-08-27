#include "iostream"
using namespace std;
class AA2
{
public:
	AA2(int a = 0)
	{   
		cout << "父类构造函数" << endl;
		this->a = a;
		print(); //在构造函数里面能实现多态吗？ 不能实现
	}
	virtual ~AA2()
	{
		cout<<"父类析构函数do"<<endl;
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

class BB2 : public AA2
{
public:
	BB2(int a= 0, int b = 0)
	{ 

		cout << "子类构造函数" << endl;
		this->a = a;
		this->b = b;
	}

	~BB2()
	{
		cout<<"子类析构函数do"<<endl;
	}
	virtual void print()
	{
		cout<<"子类的"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToDelete(AA2 *pBase)
{
	delete pBase; 
}
void main_071()
{
	BB2 *b1 = new BB2(1, 2);
	
	b1->print();

	howToDelete(b1);
	//delete b1;
	system("pause");
}