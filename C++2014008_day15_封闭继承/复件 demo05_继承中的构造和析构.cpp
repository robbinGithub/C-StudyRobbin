#include <cstdlib>
#include <iostream>
using namespace std;

/*
1����������ԣ�Ӧ���и���Ĺ��캯��ȥ��ʼ��
2���������ӵ����ԣ�Ӧ��������Ĺ��캯����ɣ�
	==���ӷֹ�������ȷ
	*/


//������������ʱ����Ҫ���ø��๹�캯������̳е����ĳ�Ա���г�ʼ��
//���������������ʱ����Ҫ���ø���������������̳е����ĳ�Ա��������

class Parent04
{
public:
	Parent04(const char* s)
	{
		cout<<"Parent04()"<<" "<<s<<endl;
	}

	~Parent04()
	{
		cout<<"~Parent04()"<<endl;
	}
};

class Child04 : public Parent04
{
public:
	Child04() : Parent04("Parameter from Child!")
	{
		cout<<"Child04()"<<endl;
	}

	~Child04()
	{
		cout<<"~Child04()"<<endl;
	}
};

void run04()
{
	Child04 child;
}

int main050(int argc, char *argv[])
{
	run04();

	system("pause");
	return 0;
}
