#include <iostream>
#include <ctime>

#pragma warning(disable:4996)

using namespace std;

/*

    C++ 日期 & 时间
	
	@author:robbin.zhang
	@date:2018/03/11 12:51
	@see http://www.runoob.com/cplusplus/cpp-date-time.html
	@see http://blog.csdn.net/educast/article/details/17239735
	
 */

time_t StringToDatetime(char *str);


int main_01()
{   

	// 当前日期和时间

	// time 基于当前系统的当前日期/时间
	time_t now = time(0);
	printf("自 1970-01-01 起的小时数 = %ld\n", now / 3600);

	// ctime 把 now 转换为字符串形式
	time_t curtime;
	time(&curtime);
    printf("本地日期和时间：%s", ctime(&curtime)); // const time_t *timer

	// gmtime/localtime 返回指向tm 结构的指针(本地时区)
	time_t rawtime;
	time(&rawtime);

	// gmtime 把now 转换为 tm 结构(格林威治时间) （静态分配,不是线程安全的）
	tm *gmtm = gmtime(&now);
	char* dt = asctime(gmtm);
	cout << "UTC 日期和时间：" << dt << endl;

	// localtime 把now 转换为 tm 结构
	struct tm* info;
	info = localtime(&rawtime);
	// asctime 返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。
	printf("当前的本地时间和日期：%s", asctime(info));


	// 1、时间转字符串函数
	// size_t strftime( char *strDest, size_t maxsize, const char *format, const struct tm *timeptr );


	// 2、字符串转时间函数
	// char *strptime(const char *s, const char *format, struct tm *tm);

	tm tm_;
	time_t t_;
	char buf[128] = { 0 };
	strcpy(buf, "2012-01-01 14:00:00");

	// strptime(buf, "%Y-%m-%d %H:%M:%S", &tm_); //将字符串转换为tm时间 
	// 由于windows下没有strptime函数，所以可以使用scanf来格式化  

	t_ = StringToDatetime(buf);
	tm_  =  *localtime(&t_);

	tm_.tm_isdst = -1;
	t_ = mktime(&tm_); //将tm时间转换为秒时间  
	t_ += 3600;  //秒数加3600  

	tm_ = *localtime(&t_);//输出时间  
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", &tm_);
	std::cout << buf << std::endl;

	system("pause");

	return 0;
}

time_t StringToDatetime(char *str)
{
	tm tm_;
	int year, month, day, hour, minute, second;
	sscanf(str, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
	tm_.tm_year = year - 1900;
	tm_.tm_mon = month - 1;
	tm_.tm_mday = day;
	tm_.tm_hour = hour;
	tm_.tm_min = minute;
	tm_.tm_sec = second;
	tm_.tm_isdst = 0;

	time_t t_ = mktime(&tm_); //已经减了8个时区  
	return t_; //秒时间  
}