#include <iostream>
#include <ctime>

#pragma warning(disable:4996)

using namespace std;

/*

    C++ ���� & ʱ��
	
	@author:robbin.zhang
	@date:2018/03/11 12:51
	@see http://www.runoob.com/cplusplus/cpp-date-time.html
	@see http://blog.csdn.net/educast/article/details/17239735
	
 */

time_t StringToDatetime(char *str);


int main_01()
{   

	// ��ǰ���ں�ʱ��

	// time ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);
	printf("�� 1970-01-01 ���Сʱ�� = %ld\n", now / 3600);

	// ctime �� now ת��Ϊ�ַ�����ʽ
	time_t curtime;
	time(&curtime);
    printf("�������ں�ʱ�䣺%s", ctime(&curtime)); // const time_t *timer

	// gmtime/localtime ����ָ��tm �ṹ��ָ��(����ʱ��)
	time_t rawtime;
	time(&rawtime);

	// gmtime ��now ת��Ϊ tm �ṹ(��������ʱ��) ����̬����,�����̰߳�ȫ�ģ�
	tm *gmtm = gmtime(&now);
	char* dt = asctime(gmtm);
	cout << "UTC ���ں�ʱ�䣺" << dt << endl;

	// localtime ��now ת��Ϊ tm �ṹ
	struct tm* info;
	info = localtime(&rawtime);
	// asctime ����һ��ָ���ַ�����ָ�룬�ַ��������� time ��ָ��ṹ�д洢����Ϣ��������ʽΪ��day month date hours:minutes:seconds year\n\0��
	printf("��ǰ�ı���ʱ������ڣ�%s", asctime(info));


	// 1��ʱ��ת�ַ�������
	// size_t strftime( char *strDest, size_t maxsize, const char *format, const struct tm *timeptr );


	// 2���ַ���תʱ�亯��
	// char *strptime(const char *s, const char *format, struct tm *tm);

	tm tm_;
	time_t t_;
	char buf[128] = { 0 };
	strcpy(buf, "2012-01-01 14:00:00");

	// strptime(buf, "%Y-%m-%d %H:%M:%S", &tm_); //���ַ���ת��Ϊtmʱ�� 
	// ����windows��û��strptime���������Կ���ʹ��scanf����ʽ��  

	t_ = StringToDatetime(buf);
	tm_  =  *localtime(&t_);

	tm_.tm_isdst = -1;
	t_ = mktime(&tm_); //��tmʱ��ת��Ϊ��ʱ��  
	t_ += 3600;  //������3600  

	tm_ = *localtime(&t_);//���ʱ��  
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

	time_t t_ = mktime(&tm_); //�Ѿ�����8��ʱ��  
	return t_; //��ʱ��  
}