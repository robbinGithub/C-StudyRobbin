#include <iostream>
#include "unique_ptr.h"
//#include <cassert>//异常处理
//#include <assert.h> 

/*
  @see https://www.cnblogs.com/ywy2090/p/5808266.html
*/
struct Obj
{
	int m_nMyMem;
	Obj()
	{
		std::cout << "[NEWOBJ][Obj] this =" << this << std::endl;
	}
	~Obj()
	{
		std::cout << "[DELOBJ][~Obj] this =" << this << std::endl;
	}
};

int main_07(int argc, char *argv[])
{
	unique_ptr<Obj> uptr(new Obj);
	//assert(uptr);
	uptr->m_nMyMem = 100;
	std::cout << "nMyMem= " << (*uptr).m_nMyMem << std::endl;
	auto p = uptr.release();
	if (p)
	{
		delete p;
		p = NULL;
	}
	system("pause");
	return 0;
}

/*
输出结果 == >>

[NEWOBJ][Obj] this = 00000000002C7D20
nMyMem = 100
[DELOBJ][~Obj] this = 00000000002C7D20 */