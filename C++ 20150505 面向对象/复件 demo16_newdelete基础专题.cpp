#include "iostream"
using namespace std;

//1 new/delete（操作符）作用手工分配内存（heap上）  malloc/free（函数）
//2 new/delete int 基础类型
//3 new/delete 数组
//4 new/delete类

//new/delete int 基础类型
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

//分配数组
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

//指针做函数参数
class Test1
{
public:
	Test1(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"构造执行"<<endl;
	}
	~Test1()
	{
		cout<<"析构执行"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};

//c++中的new能自动的调用类的构造函数，delete能调用类的析构函数
//malloc不会调用类的构造函数 free也不会调用类的析构函数
// new/delete类
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
	//p是实参的地址 *（实参的地址）去间接修改实参的值	
	*p = tmp;
	return 0;
}


int CreateTest2(Test1 * &myp)
{
	myp = new Test1(5, 6);
	//p是实参的地址 *（实参的地址）去间接修改实参的值
	
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