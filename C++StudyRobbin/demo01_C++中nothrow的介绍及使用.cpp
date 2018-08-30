
/*
��C�У�ʹ��malloc�ȷ����ڴ�ĺ���ʱ��һ��Ҫ����䷵��ֵ�Ƿ�Ϊ����ָ�롱�����Դ���Ϊ����ڴ�����Ƿ�ɹ������ݣ�����Test-for-NULL������ʽ��һ�����õı��ϰ�ߣ�Ҳ�Ǳ�д�ɿ�����������ġ�

��C++��new�������ڴ�ʧ��ʱĬ�ϻ��׳�һ��std::bad_alloc �쳣�������������쳣���Ǿ���ζ���ڴ�ľ�������������ԭ�����ڴ����ʧ�ܡ����ԣ�����C++��׼���������new�Ƿ�ɹ�����Ӧ��ͨ��try catch��׽�쳣������Щ��������֧��try catch��C++��׼��ίԱ�᲻��������ЩTest-for-NULL�Ĵ��룬���������ṩ��operator new����һ�ֿ�ѡ��ʽ---- nothrow�������ṩ��ͳ��Failure-yields-NULL��Ϊ��

��ʹ��new����һ���ڴ�ʧ��ʱ���׳��쳣std::bad_alloc��C++��׼�й涨�ı�׼��Ϊ������ʹ��try { p = new int[size];} catch(std::bad_alloc) { �� } �Ĵ���ʽ��

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
