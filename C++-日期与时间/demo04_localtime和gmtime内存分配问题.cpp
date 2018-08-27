#include <stdio.h>
#include <time.h>

#pragma warning(disable:4996);

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/*
 * localtime/gmtime 静态分配内存
 *
 * @author:robbin.zhang
 * @date 2018/03/12 20:39
 */
int main_04()
{   

	time_t tNow = time(NULL);
	time_t tEnd = tNow + 1800;

	//注意下面两行的区别
	struct tm* ptm = localtime(&tNow);
	struct tm* ptmEnd = localtime(&tEnd);

	//  ptm和ptmEnd会指向同一内存,建议使用 localtime_r 除非只使用一次，可以方便才使用 localtime
	//  asctime 和 gtime 应该也会有这种问题

	printf("year:%d\n", ptm->tm_year);
	ptm->tm_year++;
	printf("year2:%d\n", ptmEnd->tm_year);

	// 这个问题涉及到 谁分配内存，是来释放的问题，如果没有解决这个问题就是内存泄漏了。
	// 为了避免内存泄漏，有时候我们会使用 static 在函数内部，作为一个静态变量。

	system("pause");

	return 0;

}