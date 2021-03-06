#include <boost/shared_ptr.hpp>   
#include <vector>
#include <iostream>
#include <boost/ptr_container/ptr_container.hpp>
#define _crtdbg_map_alloc

class CTest
{
public:
	CTest(int i) :i(i)
	{
		std::cout << "construct" << std::endl;
	}
	~CTest()
	{
		std::cout << "construct" << std::endl;
	}

	int i;
};

/*
  https://blog.csdn.net/mo4776/article/details/79387847
 */
int test_01()
{
	std::vector<boost::shared_ptr<int> > v;
	v.push_back(boost::shared_ptr<int>(new int(1)));
	v.push_back(boost::shared_ptr<int>(new int(2)));
}


// 使用方法
int test_02()
{
	//以ptr_vector为例
	boost::ptr_vector<int> ints;
	//插入元素
	ints.push_back(new int(18));
	ints.push_back(new int(118));

	//以下标取元素
	std::cout << ints[0] << std::endl;
	//通过迭代器取元素
	std::cout << (*(ints.begin())) << std::endl;
	std::system("pause");
}

// 指针容器的内存释放
int test_03()
{

	{
		boost::ptr_vector<CTest> Tests;
		Tests.push_back(new CTest(1));
		Tests.push_back(new CTest(2));
	}

	//system("pause");  
	_CrtDumpMemoryLeaks();
	return 0;
}

// 容器成员的所有权
int test_04()
{
	CTest *p = NULL;

	{ 
		boost::ptr_vector<CTest> Tests;

		Tests.push_back(new CTest(1));
		p = &Tests.front(); // 返回当前vector容器中起始元素的引用。  
	}
	// 重复释放了p指针所指的内存
	delete p;
	p = NULL;
	system("pause");
	return 0;
}

// 通过release方法来获取元素的所有权
int test_05()
{
	CTest *p1 = NULL;
	{

		boost::ptr_vector<CTest> Tests;
		Tests.push_back(new CTest(1));
		Tests.push_back(new CTest(2));

		// You can think of auto_type as a non-copyable form of std::auto_ptr
		// 我们知道std::auto_ptr是通过复制，赋值来实现的转移语义，这里的auto_type是没有复制语义的，但它有转移语义，也是通过release方法。
		// 这跟std::unique_ptr很像也是只有转移语义，也只可通过release方法来转移。见如下代码:
		boost::ptr_vector<CTest>::auto_type p = Tests.release(Tests.begin());

		p1 = p.release();
		if (!p)
		{
			std::cout << "no ownership" << std::endl;
		}
	}

	delete p1;
	p1 = NULL;

	//system("pause");
	_CrtDumpMemoryLeaks();

	return 0;
}

//  auto_type所有权的转移
void test_06()
{
	boost::ptr_vector<CTest> Tests;
	Tests.push_back(new CTest(1));
	Tests.push_back(new CTest(2));
	boost::ptr_vector<CTest>::auto_type p = Tests.pop_back();
    boost::ptr_vector<CTest>::auto_type p1;

	// 上面的代码是无法编译通过的，应该通过ptr_container提供的move函数来进行所有权转移
	// p1 = p;
	p1 = boost::ptr_container::move(p);

	return 0;
}



