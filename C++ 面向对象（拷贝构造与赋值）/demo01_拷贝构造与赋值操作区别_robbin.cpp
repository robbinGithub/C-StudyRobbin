#include "AA.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// _CRT_SECURE_NO_DEPRECATE

/*
  ����VSGit
  @see https://www.cnblogs.com/wangguchangqing/p/6141743.html
 */

void test_01()
{  
	// ���캯��
	AA a(1);      // ��������a
	AA b = AA(2); // ��������b

	// �������캯��
	AA c(b);    

	// ��ֵ����
	a = AA(3);    // ������ʱ���󣬵��ø�ֵ����,��ʱ�������� ������->��ֵ->������
	
	//����AA���캯��1
	//����AA���캯��2
	//����AA���캯��3
	//����AA��ֵ����3
	//����AA��������3
	//=====test_01 End========
	//����AA��������2
	//����AA��������3

	cout << "=====test_01 End========" << endl;
}

void test_02()
{
	AA a(0); // ����AA���캯��0
	for (int i = 1; i <= 5; i++)
	{
		a = AA(i); // AA(i)����ʱ����ʹ�ý������ͷ�
		
		//����AA���캯��1
		//����AA��ֵ����1
		//����AA��������1
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