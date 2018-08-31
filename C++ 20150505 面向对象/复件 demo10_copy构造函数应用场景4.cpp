#include "iostream"
using namespace std;

class Location
{
public:
	Location( int xx = 0 , int yy = 0 )
	{
		X = xx ;  Y = yy ;  cout << X << "," << Y  << "Constructor Object.\n" ;
	}
	Location( const Location & p ) 	    //复制构造函数
	{
		X = p.X ;  Y = p.Y ;   cout << X << "," << Y << "Copy_constructor called." << endl ;  }

	Location& operator =(const Location & p)
	{
		X = p.X;
		Y = p.Y;
		cout << X << "," << Y << "赋值运算符号函数 called." << endl;
		return *this;
	}

	~Location() { cout << X << "," << Y << " Object destroyed." << endl ; }
	int  GetX () { return X ; }		int GetY () { return Y ; }
private :   int  X , Y ;
} ;

void f1 ( Location  p )
{
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}
// void playobjmain()
// {
// 	Location A ( 1, 2 ) ;
// 	f ( A ) ;
// }
Location g1()
{
	Location A(3, 4); //调用构造函数,函数结束后析构
	return A;         //调用拷贝构造函数（返回对象）
}
void main1010()
{
	Location B(1, 2); //调用默认构造器，函数结束后析构
	B = g1();   //调用拷贝构造函数 （参数传递对象)

	cout << "======== End ========" << endl;


	// 构造B对象
    // 构造A对象 
	// return A 拷贝构造对象，返回一个匿名对象
	// return A 结束后 调用A析构函数
	// 执行 = 操作
	// 析构匿名对象
	// 析构B对象

}

void main1011()
{
	Location B  = g1();

}

/*
 拷贝构造与赋值运算符区别
 @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
*/
void main1012()
{
	Location B1(1, 2);
	Location B2 = B1;  // 调用拷贝构造
	Location B3(5, 6);
	B3 = B1;

}


 int main()
// int main()
{
	 main1010();
	system("pause");
	return 0;
}

