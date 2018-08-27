
#include <iostream>
using namespace std;

template<class T>
class Complex
{ 
public:
	//构造器
	Complex( T r =0, T i =0 );
	Complex(T a) { Real = a ;  Image = 0 ; } 
	 void print() const;
	 //友员类重载+操作符
	 friend Complex<T>operator+(Complex<T>&c1,Complex<T>&c2)
	{
		T r = c1.Real + c2.Real ;     T i = c1.Image+c2.Image ;
		return Complex<T>( r, i ) ;
	}

	 // 友元函数声明-
	 friend Complex<T> operator-(Complex<T>&c1, Complex<T>&c2)
	 {
		T r = c1.Real - c2.Real;     T i = c1.Image - c2.Image;
		return Complex<T>(r, i);
	 }

	 // 函数声明-
	// Complex<T> operator-(const Complex<T>&c);

private:  
	T  Real, Image ;
};

template<class T>
Complex<T>::Complex( T r, T i )
{ 
	Real = r ;  Image = i ; 
}

/*
"class Complex<int> __cdecl operator+(class Complex<int> &,class Complex<int> &)" (??H@YA?AV?$Complex@H@@AAV0@0@Z)，该符号在函数 _main 中被引用
	1>E:\01-work\09-就业班0415\day16\泛型编程\Debug\泛型编程.exe : fatal error LNK1120: 1 个无法解析的外部命令
	========== 生成: 成功 0 个，失败 1 个，最新 0 个，跳过 0 个 ==========
	*/


/*
  【友元函数实现-】会报错，直接写在.h文件中。
  error C2248: “Complex<int>::Real”: 无法访问 private 成员(在“Complex<int>”类中声明)	
 */

/*
 template<class T> 
 Complex<T> operator-(Complex<T>&c1, Complex<T>&c2)
 { 
 	T r = c1.Real - c2.Real ;     T i = c1.Image-c2.Image ; 
 	return Complex<T>( r, i ) ;
 }
 */

/*
  【类函数实现-】
 */
 /*template<class T>
 Complex<T> Complex<T>::operator-(Complex<T>&c)
 {
	 T r = this->Real - c.Real;     T i = this->Image - c.Image;
	 return Complex<T>(r, i);
 }*/


// 模板函数
template<typename T> 
void Complex<T>::print()const
{ 
	cout << '(' << Real << " , " << Image << ')' << endl; 
}


void main_0601()
{
	Complex<int>c1(1, 2);
	Complex<int>c2(3, 4);

	Complex<int>c3 = c1 + c2;
	Complex<int>c4 = c1 - c2;
	c3.print();
	c4.print();

	system("pause");
}