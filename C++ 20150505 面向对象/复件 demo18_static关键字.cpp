#include "iostream"
using namespace std;

//c�����е�static

//״̬����
//��static���α���
void GetStatic()
{
	int a = 10;
	//bֻ��ʼ��һ��
	static int b = 10;
	
	printf("a:%d b:%d \n", a, b);
	a++;
	b++;
}

//�������myprintfֻ�������c�б�ʹ��
static void myprintf()
{
	printf("�����յ��磬�������ǿ�");
	printf("����c���ԣ����������壨c++��");
}



//ָ������������
class Test3
{
public:
	Test3(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<m_a<<endl;
		count ++;
		cout<<"����ִ��"<<endl;
	}
	~Test3()
	{
		cout<<"����ִ��"<<endl;
	}
	

	static int getCount()
	{
		return count;
		
	}
protected:
private:
	int m_a; //���ھ���Ķ���
	int m_b;
	//static���εı������ߺ�������������࣬�����ھ���Ķ���
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