#include "iostream"
#include <string>
using namespace std;

class Location2
{
public:
	Location2( int xx = 0 , int yy = 0 )
	{
		flag = "����ͨ�������";
		X = xx ;  Y = yy ;  cout << X << "," << Y  << "Constructor Object.\n" ;
	}
	Location2( const Location2 & p ) 	    //���ƹ��캯��
	{
		flag = "�������������";
		X = p.X ;  Y = p.Y ;   
		cout << X << "," << Y << "Copy_constructor called." << endl ;  
	}

	Location2& operator =(const Location2 & p)
	{  
		flag = "����ֵ�������";
		X = p.X;
		Y = p.Y;	
		cout << X << "," << Y << "��ֵ������ź��� called." << endl;
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
	Location2 A(3, 4); //���ù��캯��,��������������
	return A;         //���ÿ������캯�������ض���
}
void main1010()
{
	Location2 B(1, 2); //����Ĭ�Ϲ���������������������
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

/*
 4���������캯���ĵ�����Ӧ�ó���
   ��������������ʱ��ͨ�����ƹ��캯��������ʱ����
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

	// 4-2 (ͬ��)
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
 ���������븳ֵ���������
 @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
*/
void main1012()
{
	Location2 B1(1, 2);
	Location2 B2 = B1;  // ���ÿ�������
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

