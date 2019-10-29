#include<iostream>
#include<boost/thread/thread.hpp>

/*
 * WIN7œ¬£¨VS2013≈‰÷√boostø‚

 *@see   https://blog.csdn.net/zengraoli/article/details/51322484
 *            https://blog.csdn.net/xiao_lxl/article/details/53035026
*/
void hello()
{
	std::cout << "Hello world, I'm a thread!" << std::endl;
}

int main()
{
	boost::thread thrd(&hello);
	thrd.join();
}
