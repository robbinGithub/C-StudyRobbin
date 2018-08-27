
#include <iostream>
using namespace std;

template<class T>
class Complex
{ 
public:
	//������
	Complex( T r =0, T i =0 );
	Complex(T a) { Real = a ;  Image = 0 ; } 
	 void print() const;
	 //��Ա������+������
	 friend Complex<T>operator+(Complex<T>&c1,Complex<T>&c2)
	{
		T r = c1.Real + c2.Real ;     T i = c1.Image+c2.Image ;
		return Complex<T>( r, i ) ;
	}

	 // ��Ԫ��������-
	 friend Complex<T> operator-(Complex<T>&c1, Complex<T>&c2)
	 {
		T r = c1.Real - c2.Real;     T i = c1.Image - c2.Image;
		return Complex<T>(r, i);
	 }

	 // ��������-
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
"class Complex<int> __cdecl operator+(class Complex<int> &,class Complex<int> &)" (??H@YA?AV?$Complex@H@@AAV0@0@Z)���÷����ں��� _main �б�����
	1>E:\01-work\09-��ҵ��0415\day16\���ͱ��\Debug\���ͱ��.exe : fatal error LNK1120: 1 ���޷��������ⲿ����
	========== ����: �ɹ� 0 ����ʧ�� 1 �������� 0 �������� 0 �� ==========
	*/


/*
  ����Ԫ����ʵ��-���ᱨ��ֱ��д��.h�ļ��С�
  error C2248: ��Complex<int>::Real��: �޷����� private ��Ա(�ڡ�Complex<int>����������)	
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
  ���ຯ��ʵ��-��
 */
 /*template<class T>
 Complex<T> Complex<T>::operator-(Complex<T>&c)
 {
	 T r = this->Real - c.Real;     T i = this->Image - c.Image;
	 return Complex<T>(r, i);
 }*/


// ģ�庯��
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