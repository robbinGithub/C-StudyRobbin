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

		MyTest(a, b, 100);//��������(û�н���)����֮������������
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
	int getC() const { return c; } // ��C++�У���һ����������Ϊconst���ͣ�����ͼ�޸ĸñ�����ֵ�Ĳ��������ӱ������
	void setC(int val) { c = val; }
};

int main_15()
{
	MyTest t1(1, 2); 
	printf("c:%d", t1.getC()); //����c��ֵ�ǣ�  c:-858993460
	system("pause");
	return 0;
}