#include <boost/shared_ptr.hpp>   
#include <vector>

/*
  https://blog.csdn.net/mo4776/article/details/79387847
 */
int main()
{
	std::vector<boost::shared_ptr<int> > v;
	v.push_back(boost::shared_ptr<int>(new int(1)));
	v.push_back(boost::shared_ptr<int>(new int(2)));
}