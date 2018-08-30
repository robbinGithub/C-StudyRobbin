#include <iostream>
using namespace std;
class String
{
private:
	char * m_data; //用于保存字符串
	int length;     //字符数组的大小
public:
	// 无参构造函数
	String()
	{
		m_data = 0;
		length = 0;
	}
	// 拷贝构造函数
	String(const String &s);
	//定义初始化构造函数
	String(const char *s);

	// 析构函数
	~String()
	{
		delete[] m_data;
	}
	//打印字符串
	void primsg()
	{
		cout << "字符串为：" << this->m_data << endl;
	}
	// 赋值函数
	void operator = (const String &s);

	//连接函数实现字符串相加
	friend String operator + (const String &s1, const String &s2);

};