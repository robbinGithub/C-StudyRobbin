#include "iostream"
using namespace std;

class  Complex
{
private:
	int a;
	int b;
	friend ostream& operator<<(ostream &out, Complex &c1);

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
	Complex operator+(Complex &c2)
	{
		Complex tmp;
		tmp.a = this->a + c2.a;
		tmp.b = b + c2.b;
		return tmp;
	}

	// ǰ��--
	Complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;
	}

	// ǰ��++
	Complex& operator++()
	{
		this->a++;
		this->b++;
		return *this;
	}

	//����--
	Complex operator--(int)
	{
		Complex tmp = *this;
		this->a --;
		this->b --;
		return tmp;
	}

	//����++
	Complex operator++(int)
	{
		Complex tmp = *this;
		this->a ++;
		this->b ++;
		return tmp;
	}
};




//1���������أ�������ͨ������ʵ�ֵġ�
void main61()
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

	++c2; 
	c2.printCom();

	//ȫ�ֺ���ԭ���Ƶ�
	//Complex& operator++(Complex &c2);
	--c2; //c2.operator--();
	c2.printCom();


	//����ȫ�ֺ���ʵ�ֺ���++
	c2++;
	c2.printCom();

	//���������Ա����ʵ�ֺ���--
	c2--;
	c2.printCom();

	system("pause");
}



ostream& operator<<(ostream &out, Complex &c1)
{
	cout<<"12345,��ɽ���ϻ�"<<endl;
	cout<<c1.a<<"+"<<c1.b<<"i"<<endl;
	return out;
}

//1���������أ�������ͨ������ʵ�ֵġ�
void main0600()
{
	Complex c1(1, 2), c2(3, 4);

	int a = 10;
	char *p = "abc";
	cout<<a<<endl;
	cout<<p<<endl;


	cout<<c1<<"��ʽ��̲���"<<endl;
	operator<<(cout, c1);

	//��������ֵ����ֵ��ʱ����Ҫ����һ�����������
	//cout<<c1   <<"aaa";
	//û�з���ȥ��cout��������Ӻ���operator<<��ֻ��ͨ��ȫ�ֺ���ʵ�֡�
	//cout.operator<<( c1);
	//void operator<<(ostream &out, Complex &c1)


	system("pause");
}