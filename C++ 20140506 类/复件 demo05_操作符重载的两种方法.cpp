#include "iostream"
using namespace std;

//a+bi
class  Complex
{
private:
	int a;
	int b;
	//ͨ����Ԫ����ʵ��+����
	friend Complex operator+(Complex &c1, Complex &c2);
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
	//ͨ����ĳ�Ա����ʵ��-����
	Complex operator-(Complex &c2)
	{
		Complex tmp;
		tmp.a = this->a -c2.a;
		tmp.b = b -c2.b;
		return tmp;
	}
};

Complex operator+(Complex &c1, Complex &c2) //����c1��c2˽�г�Ա��������
{
	Complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

//1���������أ�������ͨ������ʵ�ֵġ�
void main050()
{
	Complex c1(1, 2), c2(3, 4);

	//Complex c3 = ComAdd(c1, c2);
	//Complex c3 = operator+(c1, c2);
	//2  +���������������� ������� �� �Ҳ�����
	//3 
	Complex c3 = c1 + c2;
	c3.printCom();

	Complex c4 = c1.operator-(c2);
	c4.printCom();

	Complex c5 = c1 - c2 ;
	c5.printCom();
	//Ŀ�� ͨ����ĳ�Ա��������ɲ���������
	//1 Ҫ���ϲ�����������һ��������Ҫд����ԭ��
	//2 д�������������� c1.operator-(c2)
	//3 ���ƺ���ԭ�� 
		
	
	

	system("pause");
}