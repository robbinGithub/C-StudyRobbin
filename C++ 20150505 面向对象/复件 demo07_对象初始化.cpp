#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "iostream"
using namespace std;

class ABC 
{
	public:
		ABC(int a, int b, int c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			printf("构造函数执行a:%d;b:%d;c:%d\n", this->a, this->b, this->c);
		}
		~ABC()
		{
			printf("析构函数执行a:%d;b:%d;c:%d\n", a, b, c);
		}

	protected:
	private:
		int a;
		int b;
		int c;

};
void initObj()
{  
	// ABC a; // 类ABC不存在默认构造函数
	ABC(1, 2, 3);

}

int main_071()
{    
	initObj();
	system("pause");
	return 0;
}