#include <iostream>
#include <memory>
using namespace std;

void Func1(shared_ptr<int> a)
{
	cout << "Enter Func1" << endl;
	cout << "Ref count: " << a.use_count() << endl;
	cout << "Leave Func1" << endl;
}

shared_ptr<int> Func2(shared_ptr<int>& a)
{
	cout << "Enter Func2" << endl;
	cout << "Ref count: " << a.use_count() << endl;
	cout << "Leave Func2" << endl;
	return a;
}

int main()
{
	//构造一个指向int类型对象的指针aObj1,引用计数+1
	shared_ptr<int> aObj1(new int(10));
	cout << "Ref count: " << aObj1.use_count() << endl;

	{
		//同aObj1,不过由于生存周期在括号内,所以aObj2会被销毁
		shared_ptr<int> aObj2 = aObj1;
		cout << "Ref count: " << aObj2.use_count() << endl;//引用计数-1
	}

	//在调用函数时,参数为shared_ptr类型,参数为传值类型,智能指针引用计数+1
	Func1(aObj1);

	//在调用函数时,参数为shared_ptr类型,参数为传引用类型,智能指针引用计数不变
	Func2(aObj1);

	shared_ptr<int> aObj3 = Func2(aObj1);//引用计数+1
	cout << "Ref count:" << aObj3.use_count() << endl;

	return 0;
}