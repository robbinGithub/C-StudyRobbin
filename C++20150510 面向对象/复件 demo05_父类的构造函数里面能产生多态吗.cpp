#include "iostream"

using namespace std;

class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); //�ڹ��캯��������ʵ�ֶ�̬��  ���ø���ķ������������������print
	}

	//����һ��Ҫ��ʵ�ֶ�̬��c++������Ӧ�ö�ʲô�ֽ�
	//��һ����Ҫ���ֽŵĵط�  �����������print ��Ӧ�����⴦��
	virtual void print()
	{
		cout<<"�����"<<"a"<<a<<endl;
	}
protected:
	int a ;
};

class BB : public AA
{
public:
	BB(int a= 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	
	}
	virtual void print()
	{
		cout<<"�����"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};


void howToPrintf(AA *pBase)
{
	//pBase ����ô֪���Ǹ���������������
	//���ֽ�2��:�����Ǹ�����������������ǰ����
	pBase->print();  //
}
void main050()
{
	//AA a1;
	BB b1;
	//howToPrintf(&a1);
	howToPrintf(&b1);
	system("pause");
}