#include <cstdlib>
#include <iostream>

using namespace std;

//����ֻ������һ�������� ���ڱ����ڼ��ȷ��
class Parent01
{
public:
	Parent01()
	{
		cout<<"Parent01:printf()..do"<<endl;
	}
public:
	void aaaaa()
	{
		;
	}
	void func()
	{
		cout<<"Parent01:void func()"<<endl;
	}

	 void func(int i)
	{
		cout<<"Parent:void func(int i)"<<endl;
	}

	 // �����޷����ؽ��������������ֵĺ���
	 /*
	 int func(int i)
	 {
		 cout << "Parent:void func(int i)" << endl;
		 return 0;
	 }*/

	 virtual void func(int i, int j)//
	{
		cout<<"Parent:void func(int i, int j)"<<endl;
	}
};

//��д ������֮�䣬������Ҫ�أ������������������������������ͣ���ȫһ�� 
//��д�ַ�Ϊ����
//�����������virtual�ؼ��֣����ָ���֮��Ĺ�ϵ�����麯����д����������·�����̬ ����̬���� �ٰ󶨣�
//���������û��virtual�ؼ��֣����ָ���֮��Ĺ�ϵ �ض���  ����̬���ࣩ
class Child01 : public Parent01
{

public:

	//�˴�2��������������func������ʲô��ϵ
	void func(int i, int j)
	{
		cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
	}

	//���������������ظ����func����  ====��
	//�˴�3�������ģ�������func������ʲô��ϵ
	void func(int i, int j, int k)
	{
		cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
	}
};

void run01(Parent01* p)
{
	p->func(1, 2);
}

int main_0101()
{
	Parent01 p;

	p.func();
	p.func(1);
	p.func(1, 2);

	

	Child01 c;
	//c.func(); //ע��1
	c.Parent01::func();
	//c.aaaaa();
	//c.func(1, 2);
	
	run01(&p);
	run01(&c);
	
	system("pause");
	
	return 0;
}

//����1��child����̳и�������func��������仰��������why
//c.func(); 

//1���������func�޷����ظ��������func 
//2���������������ͬ�ĺ����������������֣��������Ƹ���
//3//c.Parent::func();
//����2 ���������func�͸����������func������ʲô��ϵ��

