#include "iostream"
using namespace std;

//1 new/delete���������������ֹ������ڴ棨heap�ϣ�  malloc/free��������
//2 new/delete int ��������
//3 new/delete ����
//4 new/delete��

//new/delete int ��������
void main01()
{

	//int *p = (int *)malloc(sizeof(int));
// 	int *p1 = new int;
// 	*p1 = 1;
// 	printf("%d\n", *p1);
// 	delete p1;

	int *p2 = new int(10);
	printf("%d\n", *p2);
	delete p2;
	system("pause");
}

//��������
void main02()
{

	//int *p = (int *)malloc(10*sizeof(int));
	int *p1 = new int[10];

	for (int i=0; i<10; i++)
	{
		p1[i] = i+1;
		printf("%d\n", p1[i]);
	}

	//delete[] p1;
	delete[] p1;

// 	int *p2 = new int(10);
// 	printf("%d\n", *p2);
// 	delete p2;
	system("pause");
}

//ָ������������
class Test1
{
public:
	Test1(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"����ִ��"<<endl;
	}
	~Test1()
	{
		cout<<"����ִ��"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

//c++�е�new���Զ��ĵ�����Ĺ��캯����delete�ܵ��������������
//malloc���������Ĺ��캯�� freeҲ������������������
// new/delete��
void mainobjplay()
{
	//Test1 t1(1, 2);
	Test1 *p2 = (Test1 *)malloc(sizeof(Test1));
	free(p2);


	Test1 *p1 = new Test1(3, 4);
	delete p1;
}

int CreateTest1(Test1 **p)
{
	Test1 *tmp = new Test1(5, 6);
	//p��ʵ�εĵ�ַ *��ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ	
	*p = tmp;
	return 0;
}


int CreateTest2(Test1 * &myp)
{
	myp = new Test1(5, 6);
	//p��ʵ�εĵ�ַ *��ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ
	
	return 0;
}
void main161()
{
	Test1 *p3 = NULL;
	//mainobjplay();
	//CreateTest1(&p3);

	CreateTest2(p3);

	delete p3;
	system("pause");

}