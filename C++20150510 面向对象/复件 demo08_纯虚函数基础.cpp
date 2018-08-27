#include "iostream"
using namespace std;


//定义一个抽象类，还有纯虚函数类叫做抽象类


//1、如果子类继承抽象类，只有把所有的纯虚函数都实现了，才能实例化
//2  抽象类可以定义普通的函数 变量 。。。。
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
// 		cout<<"三角形面积:"<<x*y*0.5<<endl;
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
		 cout<<"三角形面积:"<<x*y*0.5<<endl;
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
		cout<<"四边形面积:"<<x*y<<endl;
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
		cout<<"圆的面积:"<<3.14*x*x<<endl;
	}
protected:
private:
};

//通过抽象类的 纯虚函数 接口约定 （公共界面的约定）来实现具体的业务模型的填充
//（比继承代码复用更好一个级别的，属于框架的设计）
void objShow(figure *pBase)
{
	pBase->show_area();
}
//纯虚函数
void main_08()
{
	//figure f1; //直接用抽象类定义具体的对象，error
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