#include <stdio.h>
#include <time.h>

#pragma warning(disable:4996);

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*
 * localtime/gmtime ��̬�����ڴ�
 *
 * @author:robbin.zhang
 * @date 2018/03/12 20:39
 */
int main_04()
{   

	time_t tNow = time(NULL);
	time_t tEnd = tNow + 1800;

	//ע���������е�����
	struct tm* ptm = localtime(&tNow);
	struct tm* ptmEnd = localtime(&tEnd);

	//  ptm��ptmEnd��ָ��ͬһ�ڴ�,����ʹ�� localtime_r ����ֻʹ��һ�Σ����Է����ʹ�� localtime
	//  asctime �� gtime Ӧ��Ҳ������������

	printf("year:%d\n", ptm->tm_year);
	ptm->tm_year++;
	printf("year2:%d\n", ptmEnd->tm_year);

	// ��������漰�� ˭�����ڴ棬�����ͷŵ����⣬���û�н�������������ڴ�й©�ˡ�
	// Ϊ�˱����ڴ�й©����ʱ�����ǻ�ʹ�� static �ں����ڲ�����Ϊһ����̬������

	system("pause");

	return 0;

}