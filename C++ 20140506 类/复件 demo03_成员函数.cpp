#include "iostream"
using namespace std;

//class 
//const c ð�ƻ� 
//register cpu��ߵ�С̫��
//typedef //�����
class Test2
{
public:
	//��Ԫ�������ص��ǣ���һ����������Ԫ���ָ�������
	friend int OpMem(Test2 *p, int a); //��Ԫ����
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
	friend class B ; //B��A�����Ա�࣬B�����еĺ�������A�����Ա����
public :
	void  Display() { cout << x << endl ; } ;
private :
	int  x ;
} ;

class  B          //B��û�����ݳ�Ա��ֻ�ж�A����������A)
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
