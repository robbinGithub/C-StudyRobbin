#include "iostream"
using namespace std;

class Test1
{
public:
	//Test1(this, int a, int b)
	Test1(int a=0, int b=0)
	{
		this->a = a;
		this->b = b;
	}
public:
	int a;
	int b;
public:
	//��Ա����
	Test1& T_add(Test1 &t2)
	{
// 		Test1 t3;
// 		t3.a = t1.a + t2.a;
// 		t3.b = t1.b + t2.b;
// 		return t3;
		a = a + t2.a;
		this->b = this->b + t2.b;
		return *this;
	}
};


// Test1(Test1 *pThis, int a=0, int b=0)
// {
// 	this->a = a;
// 	this->b = b;
// }
//ȫ�ֺ���
Test1 T_add(Test1 &t1, Test1 &t2) 
{
	Test1 t3;
	t3.a = t1.a + t2.a;
	t3.b = t1.b + t2.b;
	return t3;
}

//�ӳ�Ա����ת��Ϊȫ�ֺ��� ֻ��Ҫ��һ�� thisָ�루ָ�������ָ�룩
//��ȫ�ֺ���ת��Ϊ��ĳ�Ա�����ǣ���Ҫ��һ���������������
void main010()
{
	Test1  t1(1, 2), t2(3, 4);
	Test1 t3;
	//t1 = T_add(t1 ,t2);

	//t1.add(t2); ====>add(this &t1, t2);
	t1.T_add(t2);


	system("pause");
}