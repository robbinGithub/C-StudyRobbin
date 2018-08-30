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
	AA a(1);      // 创建对象a
	AA b = AA(2); // 创建对象b
	a = AA(3);    // 创建临时对象，调用赋值运算,临时对象析构 【构造->赋值->析构】
	
	cout << "=====test_01 End========" << endl;
}

void test_02()
{
	AA a(0);
	for (int i = 1; i < 5; i++)
	{
		a = AA(i); // AA(i)是临时对象，使用结束后释放
	}

	cout << "=====test_01 End========" << endl;
}


int main()
{

	test_01();

	system("pause");
	return 0;
}