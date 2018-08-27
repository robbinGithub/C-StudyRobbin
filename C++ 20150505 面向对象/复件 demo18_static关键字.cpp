#include "iostream"
using namespace std;

//c语言中的static

//状态保留
//用static修饰变量
void GetStatic()
{
	int a = 10;
	//b只初始化一次
	static int b = 10;
	
	printf("a:%d b:%d \n", a, b);
	a++;
	b++;
}

//这个函数myprintf只能在这个c中被使用
static void myprintf()
{
	printf("锄禾日当午，生活真是苦");
	printf("送走c语言，来了它大叔（c++）");
}



//指针做函数参数
class Test3
{
public:
	Test3(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<m_a<<endl;
		count ++;
		cout<<"构造执行"<<endl;
	}
	~Test3()
	{
		cout<<"析构执行"<<endl;
	}
	

	static int getCount()
	{
		return count;
		
	}
protected:
private:
	int m_a; //属于具体的对象
	int m_b;
	//static修饰的变量或者函数，属于这个类，不属于具体的对象
	static int count;
};
 int Test3::count  = 0;
void main180()
{
	///GetStatic();
	//GetStatic();
	Test3 t1(1, 3), t2(3, 4), t3(5, 65);

	cout<<Test3::getCount()<<endl;;
	cout<<t3.getCount()<<endl;;

	system("pause");
}