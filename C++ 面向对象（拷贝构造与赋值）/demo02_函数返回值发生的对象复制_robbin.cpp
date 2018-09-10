/*
  C++函数返回值发生的对象复制
  @see https://www.cnblogs.com/AuroraMini/p/7398300.html
 */

// 1.当函数返回值不是引用类型是，会发生复制，且接收函数返回值的变量不能是引用类型
// 2.当函数返回值是引用类型，接收函数返回值的变量不是引用时，仍然发生复制
// 3.函数返回值是引用类型，接收函数返回值的变量是引用类型，不会发生复制

#include <iostream>
using namespace std;

class C1
{
public:
	int a;
	C1(int a) {
		this->a = a;
	}
	/*复制构造函数，不修改被拷贝的对象，所以参数为const；参数是引用，
	是因为如果不是引用，在传递参数的时候就会被调用复制构造函数，而这
	个函数本身就是复制构造函数，会造成无穷的递归调用
	*/
	C1(const C1 &c) {
		this->a = c.a;
		cout << "copy constructor called" << endl;
	}
};
class C2
{
public:
	C1 c1;
	C2() :c1(10) {
	}
	// 返回引用
	C1 &getC_Ref() {
		return c1;
	}
	// 返回不是引用
	C1 getC1() {
		return c1;
	}
};
int main_02() {

	C2 c2;

	printf("== 返回非引用，会发生复制，调用拷贝构造函数\n");
	C1 c11 = c2.getC1();     
	printf("== 返回引用，接收的也是引用，不会发生复制\n");
	C1 &c12 = c2.getC_Ref(); 
	printf("== 返回引用，接收的不是引用，会发生复制==\n");
	C1 _c13 = c2.getC_Ref(); 
	
	cout << (int)(&c11) << endl << (int)(&c2.c1) << endl;
	return 0;
}