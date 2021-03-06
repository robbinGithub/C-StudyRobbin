// C++ 智能指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <memory>
#include <iostream>

struct Foo {
	Foo() { std::cout << "Foo...\n"; }
	~Foo() { std::cout << "~Foo...\n"; }
};

struct D {
	//删除p所指向的Foo对象
	void operator()(Foo* p) const {
		std::cout << "Call delete for Foo object...\n";
		delete p;
	}
};

void main_01()
{
	// constructor with no managed object
	std::shared_ptr<Foo> sh1;

	// constructor with object
	std::shared_ptr<Foo> sh2(new Foo);
	std::shared_ptr<Foo> sh3(sh2);  // 拷贝构造函数
	std::shared_ptr<Foo> sh4 = sh3; // 拷贝构造函数
	sh1 = sh4;

	std::cout << sh1.use_count() << '\n';
	std::cout << sh2.use_count() << '\n';
	std::cout << sh3.use_count() << '\n';
	std::cout << sh4.use_count() << '\n';

	//constructor with object and deleter
	std::shared_ptr<Foo> sh5(new Foo, D());
}
