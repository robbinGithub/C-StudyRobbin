#include "iostream"
using namespace std;

class Location
{
public:
	Location( int xx = 0 , int yy = 0 )
	{
		X = xx ;  Y = yy ;  cout << X << "," << Y  << "Constructor Object.\n" ;
	}
	Location( const Location & p ) 	    //���ƹ��캯��
	{
		X = p.X ;  Y = p.Y ;   cout << X << "," << Y << "Copy_constructor called." << endl ;  }

	Location& operator =(const Location & p)
	{
		X = p.X;
		Y = p.Y;
		cout << X << "," << Y << "��ֵ������ź��� called." << endl;
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
	Location A(3, 4); //���ù��캯��,��������������
	return A;         //���ÿ������캯�������ض���
}
void main1010()
{
	Location B(1, 2); //����Ĭ�Ϲ���������������������
	B = g1();   //���ÿ������캯�� ���������ݶ���)

	cout << "======== End ========" << endl;


	// ����B����
    // ����A���� 
	// return A ����������󣬷���һ����������
	// return A ������ ����A��������
	// ִ�� = ����
	// ������������
	// ����B����

}

void main1011()
{
	Location B  = g1();

}

/*
 ���������븳ֵ���������
 @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
*/
void main1012()
{
	Location B1(1, 2);
	Location B2 = B1;  // ���ÿ�������
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

