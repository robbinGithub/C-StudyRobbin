#include "xstring.h"

/*
测试string的拷贝构造和赋值运算
@see https://blog.csdn.net/xld_hung/article/details/76397668
*/
void test_03()
{
	string s1 = "robbin";
	string s2 = s1;     // string赋值运算，深度拷贝
	string s3(s2);      // string拷贝构造，深度拷贝
	string s4 = s1 + s2; // string加号运算，深度拷贝
	s4.insert(0, "CC");
	s4.append("CC");

	s2[0] = 'A';
	cout << "s1:" << s1.c_str() << endl;
	cout << "s2:" << s2.c_str() << endl;
	cout << "s3:" << s3.c_str() << endl;
	cout << "s4:" << s4.c_str() << endl;
}



void test_04()
{
	String s1("hello");
	s1.primsg();
	String s2 = s1;
	s2.primsg();
	String s3(" world");
	s3.primsg();
	String s4 = s1 + s3;
	s4.primsg();
}