#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main_03()
{
	time_t start_t, end_t;
	double diff_t;

	printf("��������...\n");
	time(&start_t);

	printf("���� 5 ��...\n");
	Sleep(5);

	time(&end_t);
	diff_t = difftime(end_t, start_t);

	printf("ִ��ʱ�� = %f\n", diff_t);
	printf("�����˳�...\n");

	system("pause");

	return(0);
}