#include "iostream"
using namespace std;


//����һ�������࣬���д��麯�������������


//1���������̳г����ֻ࣬�а����еĴ��麯����ʵ���ˣ�����ʵ����
//2  ��������Զ�����ͨ�ĺ��� ���� ��������
class figure
{
public:
	virtual void show_area() = 0 ;

	//virtual void show_area1() = 0 ;

	//virtual void show_area2() = 0 ;

	void printf()
	{
		cout<<"test"<<endl;
	}

protected:
	double x;
	double y;
};



class test : public figure
{
public:
	test(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}

// 	void show_area()
// 	{
// 		cout<<"���������:"<<x*y*0.5<<endl;
// 	}
protected:
private:
};

class tri : public figure
{
public:
	tri(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	
	 void show_area()
	 {
		 cout<<"���������:"<<x*y*0.5<<endl;
	 }
protected:
private:
};

class square  : public figure
{
public:
	square(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"�ı������:"<<x*y<<endl;
	}
protected:
private:
};

class circle  : public figure
{
public:
	circle(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"Բ�����:"<<3.14*x*x<<endl;
	}
protected:
private:
};

//ͨ��������� ���麯�� �ӿ�Լ�� �����������Լ������ʵ�־����ҵ��ģ�͵����
//���ȼ̳д��븴�ø���һ������ģ����ڿ�ܵ���ƣ�
void objShow(figure *pBase)
{
	pBase->show_area();
}
//���麯��
void main_08()
{
	//figure f1; //ֱ���ó����ඨ�����Ķ���error
	figure *pBase = NULL;
// 
	tri t1;
	square s1;
	circle c1;
	objShow(&t1);
	objShow(&s1);
	objShow(&c1);

	//test t1;
	system("pause");
}