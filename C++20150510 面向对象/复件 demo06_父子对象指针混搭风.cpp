#include "iostream"
using namespace std;

//ָ��Ҳ��һ���������ͣ�ָ�����ݵ�����������ָ������ָ���ڴ�ռ����������
//���һ������ ָ��Ĳ��� ������c++

class Parent01
{
protected:
	int i;
	int		j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};


class Child01 : public Parent01
{	
public:
	int k;
public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		printf("Child01::f()...do\n");
	}
};

void howToF(Parent01 *pBase)
{
	pBase->f();
}

//ָ��Ĳ��� ��c++������Ȼ��Ч������ָ��Ĳ���������ָ��Ĳ�����һ��
//��̬�ǿ��ٰ�ʵ�ֵģ�vptr+����ָ��ʵ�֣�
int main06()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;

	//��Ҫ�Ѹ���������������ͬ�·���һ����������
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};

	//��Ҫ�ø���ָ������ֵָ�������ȥ����һ����������顣

	p = ca;
	c = ca;

	p->f();
	c->f(); //�ж�̬����

// 	p++;
// 	c++;
// 
// 	p->f();//�ж�̬����
// 	c->f();

	for (i=0; i<3; i++)
	{
		howToF(&(ca[i]));
	}

	
	system("pause");
	return 0;
}

