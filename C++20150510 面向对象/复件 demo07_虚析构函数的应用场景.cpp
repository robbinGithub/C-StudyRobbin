#include "iostream"
using namespace std;
class AA2
{
public:
	AA2(int a = 0)
	{   
		cout << "���๹�캯��" << endl;
		this->a = a;
		print(); //�ڹ��캯��������ʵ�ֶ�̬�� ����ʵ��
	}
	virtual ~AA2()
	{
		cout<<"������������do"<<endl;
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

class BB2 : public AA2
{
public:
	BB2(int a= 0, int b = 0)
	{ 

		cout << "���๹�캯��" << endl;
		this->a = a;
		this->b = b;
	}

	~BB2()
	{
		cout<<"������������do"<<endl;
	}
	virtual void print()
	{
		cout<<"�����"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToDelete(AA2 *pBase)
{
	delete pBase; 
}
void main_071()
{
	BB2 *b1 = new BB2(1, 2);
	
	b1->print();

	howToDelete(b1);
	//delete b1;
	system("pause");
}