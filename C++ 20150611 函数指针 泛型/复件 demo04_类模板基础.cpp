
#include <iostream>
using namespace std;

//����һ����ģ��

template<typename T>
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	T getA()
	{
		return this->a
	}
protected:
private:
	T a;
};

class BB : public AA<int>
{
public:
	//BB(int a, int b) : AA(a) 
	BB(int a, int b) : AA<int>(a) 
	{
		this->b = b;
	}

private:
	int b;
};

void main_04()
{
	//Ҫ����ģ���������ͺ󣬲��ܶ������
	AA<int> a(10);

	BB b1(1, 2);
	system("pause");
}