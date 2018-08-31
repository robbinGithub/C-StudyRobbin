#include "iostream"
using namespace std;

class MyTest
{
public:
	MyTest(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	MyTest(int a, int b)
	{
		this->a = a;
		this->b = b;

		MyTest(a, b, 100);//匿名对象(没有接收)创建之后立即析构，
	}
	~MyTest()
	{
		printf("MyTest~:%d, %d, %d\n", a, b, c);
	}

protected:
private:
	int a;
	int b;
	int c;

public:
	int getC() const { return c; } // 在C++中，若一个变量声明为const类型，则试图修改该变量的值的操作都被视编译错误
	void setC(int val) { c = val; }
};

int main_15()
{
	MyTest t1(1, 2); 
	printf("c:%d", t1.getC()); //请问c的值是？  c:-858993460
	system("pause");
	return 0;
}