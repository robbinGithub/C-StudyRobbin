#include "iostream"
using namespace std;
class DD
{
public:

	DD() //DD�ж������вι��캯��
	{
		cout << "����DDĬ�Ϲ��캯��" << endl;
	}

	DD(int d) //DD�ж������вι��캯��
	{
		cout<<d<<endl;
		m_d = d;
	}

	DD( const DD& d ) 
	{
		m_d = d.m_d;
		cout << "����DD�����������캯��" << endl;
	}

	~DD() //DD�ж������вι��캯��
	{
		cout << "����DD��������" << endl;
	}

private:
	int m_d;
};

class EE
{
public:
	//���캯���ĳ�ʼ���б�
	//EE(int _a):d1(1),d2(2)
	/*EE(int _a):d2(1),d1(2)
	{
		a = _a;
		cout<<_a<<endl;
	}*/

	// ��ʹ�ó�ʼ���б� ������û�к��ʵ�Ĭ�Ϲ��캯�����ã�
	EE(int _a, DD d)	{
		cout<< "ִ��EE���캯��" << endl;   // ����ִ�г�Ա�����ĳ�ʼ��
		a = _a;
		d1 = d;
		d2 = d;
		cout << _a << endl;
	}

protected:
private:
	int a;
	DD d1;   //���ձ��������˳��
	DD d2;
};

void test_01()
{
	DD d;
	DD d2;
	// DD d3 = d2; 
	d = d2;
	// EE e1(3, d );
}
void main_12()
{
	test_01();
	system("pause");
}