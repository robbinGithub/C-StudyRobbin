#include <iostream>
using namespace std;

//������дprint
//��ֵ������ԭ�򣨰�������󸳸�����ָ��������ã�

//������д���ϸ�ֵ������ԭ��

//���������������������
//����������void howToPrintf(Parent *base)����ϣ����
//����������������ôӦ��ִ�и��ຯ��
//����������������ôִ�����ຯ��
//��̬
//c++�������������ṩ�Ķ�̬������ �麯��

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout<<"����a"<<a<<endl;
	}
protected:
private:
	 int a;
};

class Child : public Parent
{
public:
	Child(int b = 0)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout<<"����b"<<b<<endl;
	}
protected:
private:
	int b;
};


void howToPrintf(Parent *base)
{
	base->print(); //ͬ��һ�仰����ʵ�ֶ��ֹ��ܣ��ж�����̬
}


void howToPrintf2(Parent &base)
{
	base.print();
}
void main070()
{
	Parent  p1;
	//p1.print();

	Child	c1;
	//c1.print();

	//
	Parent *base = NULL;
	base = &p1;
	//base->print();

	base = &c1;
	//base->print(); //û�д�ӡ����ĺ���

	// p2 ��c1�ı��� ����c1����
	Parent &p2 = c1;
	//p2.print();

	//��������
	howToPrintf(&p1);
	howToPrintf(&c1);
	

	//howToPrintf2(p1);
	//howToPrintf2(c1);


	//Child *pC = &p1;

	system("pause");
}
