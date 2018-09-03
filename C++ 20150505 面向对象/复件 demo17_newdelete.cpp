#include "iostream"
using namespace std;


//new/delete int 基础类型
void main171()
{

	//int *p = (int *)malloc(sizeof(int));
	// 	int *p1 = new int;
	// 	*p1 = 1;
	// 	printf("%d\n", *p1);
	// 	delete p1;

	int *p2 = new int(10);
	printf("%d\n", *p2);
	//delete p2;
	free(p2);
	system("pause");
}

//分配数组
void main173()
{

	//int *p1 = (int *)malloc(10*sizeof(int));
	int *p1 = new int[10];

	for (int i=0; i<10; i++)
	{
		p1[i] = i+1;
		printf("%d\n", p1[i]);
	}

	delete[] (p1+1);
	//delete[] p1;
	//free(p1);

	// 	int *p2 = new int(10);
	// 	printf("%d\n", *p2);
	// 	delete p2;
	system("pause");
}


//指针做函数参数
class Test2
{
public:
	Test2(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"构造执行"<<endl;
	}
	~Test2()
	{
		cout<<"析构执行"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

void main174()
{
	Test2 *tmp = new Test2(5, 6);
	//p是实参的地址 *（实参的地址）去间接修改实参的值
	free(tmp);
	system("pause");
}

void main176()
{
	Test2 *tmp = (Test2 *)malloc(sizeof(Test2));
	//p是实参的地址 *（实参的地址）去间接修改实参的值
	//free(tmp);
	delete(tmp);
	system("pause");
}


void main4444()
{

	//int *p1 = (int *)malloc(10*sizeof(int));
	int *p1 = new int[10];

	for (int i=0; i<10; i++)
	{
		p1[i] = i+1;
		printf("%d\n", p1[i]);
	}

	delete[] (p1+1);
	//delete[] p1;
	//free(p1);

	// 	int *p2 = new int(10);
	// 	printf("%d\n", *p2);
	// 	delete p2;
}


void main170()
{
main4444();
	system("pause");
}
