#include <iostream>
#include <ctime>

#pragma warning(disable:4996)

using namespace std;

/*

 C �⺯�� clock_t clock(void) ���س���ִ���𣬴�����ʱ����ʹ�õ�ʱ�䡣
 Ϊ�˻�ȡ CPU ��ʹ�õ�����������Ҫ���� CLOCKS_PER_SEC��

 �� 32 λϵͳ�У�CLOCKS_PER_SEC ���� 1000000���ú�����Լÿ 72 ���ӻ᷵����ͬ��ֵ��

 ������ֵ��
 �ú��������Գ��������𣬴�����ʱ����ʹ�õ�ʱ�䡣���ʧ�ܣ��򷵻� -1 ֵ��

 */
int main_02()
{  

	clock_t start_t, end_t;
	double total_t;
	int i;

	start_t = clock();
	printf("����������start_t = %ld\n", start_t);

	printf("��ʼһ����ѭ����start_t = %ld\n", start_t);
	for (i = 0; i< 10000000; i++)
	{
	}
	end_t = clock();
	printf("��ѭ��������end_t = %ld\n", end_t);

	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("CPU ռ�õ���ʱ�䣺%f\n", total_t);
	printf("�����˳�...\n");

	system("pause");

	return(0);

}