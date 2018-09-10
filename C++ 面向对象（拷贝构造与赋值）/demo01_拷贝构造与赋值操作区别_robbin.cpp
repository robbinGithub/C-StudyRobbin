#include "AA.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// _CRT_SECURE_NO_DEPRECATE

/*
  测试VSGit
  @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
 */

void test_01()
{  
	// 构造函数
	AA a(1);      // 创建对象a
	AA b = AA(2); // 创建对象b

	// 拷贝构造函数
	AA c(b);    

	// 赋值操作
	a = AA(3);    // 创建临时对象，调用赋值运算,临时对象析构 【构造->赋值->析构】
	
	//调用AA构造函数1
	//调用AA构造函数2
	//调用AA构造函数3
	//调用AA赋值函数3
	//调用AA析构函数3
	//=====test_01 End========
	//调用AA析构函数2
	//调用AA析构函数3

	cout << "=====test_01 End========" << endl;
}

void test_02()
{
	AA a(0); // 调用AA构造函数0
	for (int i = 1; i <= 5; i++)
	{
		a = AA(i); // AA(i)是临时对象，使用结束后释放
		
		//调用AA构造函数1
		//调用AA赋值函数1
		//调用AA析构函数1
	}

	cout << "===== seporator ========" << endl;

	AA * p_a;
	for (int i = 1; i <= 5; i++)
	{
		p_a = new AA(i); 
		delete p_a;
	}
	cout << "=====test_01 End========" << endl;
}

int main_01()
{

	test_01();

	system("pause");
	return 0;
}