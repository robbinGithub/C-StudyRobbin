#include "iostream"
using namespace std;

//a+bi

/*class  Complex
{
public:
	int a;
	int b;
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
};

void main01()
{
	Complex c1(1, 2), c2(3, 4);

	int a = 10, b = 20; 
	a = a + b; //int �ǻ������ͣ��������Ѿ�Ϊ��Щ�����ṩ+�����ˡ�
	//c1 = c1 + c2; 
	//c1�������� Complex���������ͣ����Զ������͡� ������������֪����μӣ�
	//����c++������������ṩһ�����ƣ�����ʵ���Զ������ͼ�
	system("pause");
}

Complex ComAdd(Complex &c1, Complex &c2)
{
	Complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

Complex operator+(Complex &c1, Complex &c2)
{
	Complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

void main()
{
	Complex c1(1, 2), c2(3, 4);

	//Complex c3 = ComAdd(c1, c2);
	//Complex c3 = operator+(c1, c2);
	Complex c3 = c1 + c2;
	
	c3.printCom();
	


	system("pause");
}*/