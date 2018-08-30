
/*
在C中，使用malloc等分配内存的函数时，一定要检查其返回值是否为”空指针”，并以此作为检查内存操作是否成功的依据，这种Test-for-NULL代码形式是一种良好的编程习惯，也是编写可靠程序所必需的。

在C++中new在申请内存失败时默认会抛出一个std::bad_alloc 异常。如果出现这个异常，那就意味着内存耗尽，或者有其它原因导致内存分配失败。所以，按照C++标准，如果想检查new是否成功，则应该通过try catch捕捉异常。但有些编译器不支持try catch。C++标准化委员会不想遗弃这些Test-for-NULL的代码，所以他们提供了operator new的另一种可选形式---- nothrow，用以提供传统的Failure-yields-NULL行为。

当使用new申请一块内存失败时，抛出异常std::bad_alloc是C++标准中规定的标准行为，所以使用try { p = new int[size];} catch(std::bad_alloc) { … } 的处理方式。

  @see https://blog.csdn.net/fengbingchun/article/details/63686673
 */
#include <iostream>
#include <new> // std::nothrow

// reference: http://www.cplusplus.com/reference/new/nothrow/
int test_nothrow1()
{
	std::cout << "Attempting to allocate 1 MiB...";
	char* p = new (std::nothrow) char[1048576];
	if (p == 0)
		std::cout << "Failed!\n";
	else {
		std::cout << "Succeeded!\n";
		delete[] p;
	}

	return 0;
}

// reference: http://en.cppreference.com/w/cpp/memory/new/nothrow
int test_nothrow2()
{
	try {
		while (true) {
			new int[100000000ul];   // throwing overload
		}
	}
	catch (const std::bad_alloc& e) {
		std::cout << e.what() << '\n';
	}

	while (true) {
		int* p = new(std::nothrow) int[100000000ul]; // non-throwing overload
		if (p == nullptr) {
			std::cout << "Allocation returned nullptr\n";
			break;
		}
	}

	return 0;
}
