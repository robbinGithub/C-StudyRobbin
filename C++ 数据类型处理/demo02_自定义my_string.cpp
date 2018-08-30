#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>
#include <cstring>
#include <cstdlib>



using namespace std;

// #include "stdafx.h"


/*
* 实现C++的赋值函数
* @see https://blog.csdn.net/Vivid_110/article/details/49999003
*/
class my_string
{
private:
	char *str_ptr;
public:
	my_string();
	my_string(char *str_ptr);
	my_string(const my_string &str);
	my_string &operator = (const my_string &str);
	void print();
	~my_string();
};
void my_string::print()
{
	cout << str_ptr << endl;
}

// 构造函数，不释放传入字符串指针内存，重新分配内存拷贝字符串
my_string::my_string(char *str_ptr)
{
	if (str_ptr == NULL) {
		cerr << "argument is error" << endl;
	}
	this->str_ptr = new(nothrow)char[strlen(str_ptr) + 1];
	if (this->str_ptr == NULL) {
		cerr << "merrory is full" << endl;
		exit(1);
	}
	strcpy(this->str_ptr, str_ptr);
}

// 拷贝构造，不释放原来的内存空间
my_string::my_string(const my_string &str)
{
	if (str.str_ptr) {
		this->str_ptr = new(nothrow)char[strlen(str.str_ptr) + 1];
		if (this->str_ptr == NULL) {
			cerr << "merrory is full" << endl;
			exit(1);
		}

		strcpy(this->str_ptr, str.str_ptr);
	}
}
my_string::~my_string()
{
	delete[]str_ptr;
	this->str_ptr = NULL;
}
/******************************************************
*********************高级解法*************************
*****************************************************/
//使用临时变量的优势：
//1.将new的判错交给拷贝构造函数
//2.将this->str_ptr指向的原有单元的释放交给temp的析构函数
//3.从而简化了代码
my_string &my_string::operator = (const my_string &str)
{
	if (&str != this && str.str_ptr != NULL) {
		my_string temp(str);         // 用临时对象拷贝对象，析构原来对象内存
		char *temp_ptr = this->str_ptr; 
		this->str_ptr = temp.str_ptr; // 
		temp.str_ptr = temp_ptr;
	}

	return *this;
}
my_string::my_string()
{
	str_ptr = NULL;
}

int main(int argc, char* argv[])
{
	char str[100] = { 0 };
	my_string *obj_ptr = NULL;
	my_string obj1, obj2;

	cout << "Please input a string:" << endl;
	cin >> str;
	obj_ptr = new(nothrow)my_string(str);

	if (obj_ptr == NULL) {
		cerr << "memory is full" << endl;
		exit(1);
	}

	obj1 = obj2 = *obj_ptr;
	obj1.print();
	obj2.print();
	obj_ptr->print();

	delete obj_ptr;
	obj_ptr = NULL;
}
