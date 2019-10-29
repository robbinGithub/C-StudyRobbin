#include "iostream"
#include <string>
using namespace std;

class Location2
{
public:
	Location2( int xx = 0 , int yy = 0 )
	{
		flag = "【普通构造对象】";
		X = xx ;  Y = yy ;  cout << X << "," << Y  << "Constructor Object.\n" ;
	}
	Location2( const Location2 & p ) 	    //复制构造函数
	{
		flag = "【拷贝构造对象】";
		X = p.X ;  Y = p.Y ;   
		cout << X << "," << Y << "Copy_constructor called." << endl ;  
	}

	Location2& operator =(const Location2 & p)
	{  
		flag = "【赋值运算对象】";
		X = p.X;
		Y = p.Y;	
		cout << X << "," << Y << "赋值运算符号函数 called." << endl;
		return *this;
	}

	~Location2() { cout << X << "," << Y << "," << flag <<" Object destroyed." << endl ; }
	int  GetX () { return X ; }		int GetY () { return Y ; }
private :   int  X , Y ;
			std::string flag = "init";
} ;

void f1 ( Location2  p )
{
	cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}
// void playobjmain()
// {
// 	Location2 A ( 1, 2 ) ;
// 	f ( A ) ;
// }
Location2 g1()
{
	Location2 A(3, 4); //调用构造函数,函数结束后析构
	return A;         //调用拷贝构造函数（返回对象）
}
void main1010()
{
	Location2 B(1, 2); //调用默认构造器，函数结束后析构
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

/*
 4、拷贝构造函数的第四种应用场景
   当函数返回类型时，通过复制构造函数建立临时对象
   @see http://blog.sina.com.cn/s/blog_8eac84090102w7h8.html
 */
void app_04()
{
	// 4-1
	// g1();
	/*
	3,4Constructor Object.
    3,4Copy_constructor called.
    3,4 Object destroyed.
    3,4 Object destroyed.
	*/

	// 4-2 (同上)
	//Location2 B = g1();
	
	// 4-3
	Location2 B;
	B = g1();
	cout << "===============" << endl;

}

void main()
{
	app_04();
	system("pause");
}

/*
 拷贝构造与赋值运算符区别
 @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
*/
void main1012()
{
	Location2 B1(1, 2);
	Location2 B2 = B1;  // 调用拷贝构造
	Location2 B3(5, 6);
	B3 = B1;

}


 int main_1001()
// int main()
{
	 main1010();
	system("pause");
	return 0;
}

