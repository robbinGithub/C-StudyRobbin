#include "iostream"
using namespace std;
class DD
{
public:

	DD() //DD中定义了有参构造函数
	{
		cout << "调用DD默认构造函数" << endl;
	}

	DD(int d) //DD中定义了有参构造函数
	{
		cout<<d<<endl;
		m_d = d;
	}

	DD( const DD& d ) 
	{
		m_d = d.m_d;
		cout << "调用DD【拷贝】构造函数" << endl;
	}

	~DD() //DD中定义了有参构造函数
	{
		cout << "调用DD析构函数" << endl;
	}

private:
	int m_d;
};

class EE
{
public:
	//构造函数的初始化列表
	//EE(int _a):d1(1),d2(2)
	/*EE(int _a):d2(1),d1(2)
	{
		a = _a;
		cout<<_a<<endl;
	}*/

	// 不使用初始化列表 （报错，没有合适的默认构造函数可用）
	EE(int _a, DD d)	{
		cout<< "执行EE构造函数" << endl;   // 优先执行成员函数的初始化
		a = _a;
		d1 = d;
		d2 = d;
		cout << _a << endl;
	}

protected:
private:
	int a;
	DD d1;   //按照变量定义的顺序
	DD d2;
};

void test_01()
{
	DD d;
	DD d2;
	// DD d3 = d2; 
	d = d2;
	// EE e1(3, d );
}
void main_12()
{
	test_01();
	system("pause");
}