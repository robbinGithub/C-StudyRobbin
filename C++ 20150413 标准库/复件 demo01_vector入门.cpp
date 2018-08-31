#include "iostream"
#include "vector"
using namespace std;


class Point
{
public:
	Point()
	{
		cout << "construction" << endl;
	}
	Point(const Point& p)
	{
		cout << "copy construction" << endl;
	}
	~Point()
	{
		cout << "destruction" << endl;
	}
};



// 动态数组

//== != [] =
//(vector<int>模板类型  
void printfArray(vector<int> &v)
{
	
	int size = v.size();
	for (int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<endl;
	}
}
void main_x02()
{
	//定义一个数组（弹性）
	vector<int> v1(5); //int v[5]

	for (int i=0; i<5; i++)
	{
		v1[i] = i+1;
	}

	vector<int> v2(10);
	v2 = v1;

	for (int i=0; i<5; i++)
	{
		cout<<v2[i]<<endl;
	}
	v2.resize(0);
	cout<<v2.size()<<endl;

	vector<int> v3(10);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);



	printfArray(v3);
	system("pause");
}

void main131()
{
	vector<int> v3(10);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);

	printfArray(v3);
	system("pause");
}

struct Teacher
{
	int age ;
	char name[10];
};

void main321()
{
	struct Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> v3(0);
	v3.push_back(t1);
	v3.push_back(t2);
	v3.push_back(t3);

	for (int i=0; i<3; i++)
	{
		 cout<<v3[i].age<<endl;
	}


	
	system("pause");
}

/*
=====================test_v
construction
construction
============1==========
copy construction
============2==========
copy construction
destruction
copy construction
============3==========
2
destruction
destruction
destruction
destruction
=====================
 */
void test_vector_mem(){

	vector<Point> pointVec(2);
	printf("============0==========\n");
	Point a;
    Point b;
	printf("============1==========\n");
	pointVec.push_back(a);
	printf("============2==========\n");
	pointVec.push_back(b);
	printf("============3==========\n");

	cout << pointVec.size() << std::endl;

}

void test_vector_mem2(){

	vector<Point*> pointVec;
	Point a;
	Point b;
	pointVec.push_back(&a);
	pointVec.push_back(&b);

	cout << pointVec.size() << std::endl;

}

/*
 Vector 内存管理成员函数的行为測试
 */
void test_mem3()
{

	vector<int> iVec;
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //1个元素， 容器容量为1

	iVec.push_back(1);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //2个元素， 容器容量为2

	iVec.push_back(2);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //3个元素， 容器容量为4

	iVec.push_back(3);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //4个元素， 容器容量为4


	printfArray(iVec);

	iVec.push_back(4);
	iVec.push_back(5);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //5个元素， 容器容量为8


	

	iVec.push_back(6);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //6个元素， 容器容量为8

	iVec.push_back(7);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //7个元素， 容器容量为8

	iVec.push_back(8);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //8个元素， 容器容量为8

	iVec.push_back(9);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //9个元素， 容器容量为16
	/* vs2005/8 容量增长不是翻倍的，如
	9个元素   容量9
	10个元素 容量13 */

	/* 測试effective stl中的特殊的交换 swap() */
	cout << "当前vector 的大小为: " << iVec.size() << endl;
	cout << "当前vector 的容量为: " << iVec.capacity() << endl;
	vector<int>(iVec).swap(iVec);

	cout << "暂时的vector<int>对象 的大小为: " << (vector<int>(iVec)).size() << endl;
	cout << "暂时的vector<int>对象 的容量为: " << (vector<int>(iVec)).capacity() << endl;
	cout << "交换后，当前vector 的大小为: " << iVec.size() << endl;
	cout << "交换后，当前vector 的容量为: " << iVec.capacity() << endl;
}

/*
 * vector的size和capacity、resize和reserve的区别
 *
 * @date 2018/08/31 10:49
 * @see https://blog.csdn.net/q_l_s/article/details/52946769
 */
void test_101()
{
	vector<int> iVec;
	iVec.push_back(1);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //1个元素， 容器容量为1
	
	/*
	   reserver函数用来给vector预分配存储区大小，即capacity的值 ，但是没有给这段内存进行初始化。
	   reserve 的参数n是推荐预分配内存的大小，实际分配的可能等于或大于这个值，即n大于capacity的值，就会reallocate内存 capacity的值会大于或者等于n 。
	   这样，当ector调用push_back函数使得size 超过原来的默认分配的capacity值时 避免了内存重分配开销。
	 */

	// void reserve (size_type n);
	iVec.reserve(16);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //1个元素， 容器容量为16
	// cout << "容器 值[15]: " << iVec[15] << endl;
	/*
	  resize函数重新分配大小，改变容器的大小，并且创建对象
	  当n小于当前size()值时候，vector首先会减少size()值 保存前n个元素，然后将超出n的元素删除(remove and destroy)
	  当n大于当前size()值时候，vector会插入相应数量的元素 使得size()值达到n，并对这些元素进行初始化，如果调用上面的第二个resize函数，指定val，vector会用val来初始化这些新插入的元素
	  当n大于capacity()值的时候，会自动分配重新分配内存存储空间。
	*/
	// void resize (size_type n, value_type val);
	iVec.resize(100);
	// iVec.resize(100, 10); 

	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //32个元素， 容器容量为32
	cout << "容器 值[90]: " << iVec[90] << endl;

	iVec.resize(2);
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //2个元素， 容器容量为100

	cout << "================= vector clear =================" << endl;
	iVec.clear();
	cout << "容器 大小为: " << iVec.size() << endl;
	cout << "容器 容量为: " << iVec.capacity() << endl; //0个元素， 容器容量为100
}

/*
 * vector swap函数
 */
void test_102()
{

	std::vector<int> foo;
	foo.push_back(1);
	foo.push_back(2);
	foo.push_back(3);
	foo.push_back(4);
	foo.push_back(5);

	std::vector<int> bar;
	bar.push_back(6);
	bar.push_back(7);


	std::cout << "foo size:" << foo.size() << std::endl;
	std::cout << "foo capacity:" << foo.capacity() << std::endl;

	std::cout << "bar size:" << bar.size() << std::endl;
	std::cout << "bar capacity:" << bar.capacity() << std::endl;
	foo.swap(bar);

	std::cout << "after swap foo size:" << foo.size() << std::endl;
	std::cout << "after swap foo capacity:" << foo.capacity() << std::endl;

	std::cout << "after swap bar size:" << bar.size() << std::endl;
	std::cout << "after swap bar capacity:" << bar.capacity() << std::endl;
}



/*
 * vector的内存释放
 */

template <class T> void swap(T& a, T& b)
{
	T c(a); a = b; b = c;
}

void test_103()
{

	vector <string> v;
	char ch;

	for (int i = 0; i < 1000000; i++)
		v.push_back("hello vector");
	cin >> ch;

	// 此时检查内存情况 占用54M

	v.clear();
	cin >> ch;

	// 此时再次检查， 仍然占用54M

	cout << "Vector 的 容量为" << v.capacity() << endl;

	// 此时容量为 1048576

	vector<string>().swap(v);

	cout << "Vector 的 容量为" << v.capacity() << endl;

	// 此时容量为0
	cin >> ch;

	// 检查内存，释放了 10M+ 即为数据内存
}

void main(){

	test_102();
	system("pause");
}

void main_0111111()
{
	struct Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	// 栈上创建vector
	vector<Teacher *> v3(0);
	v3.push_back(&t1);
	v3.push_back(&t2);
	v3.push_back(&t3);

	// v3.pop_back();
	Teacher * t = v3.front();

	cout << t->age << endl;

	for (int i=0; i<3; i++)
	{
		//struct Teacher *tmp = (struct Teacher *)v3[i];
		struct Teacher *tmp = v3[i];
		cout<<tmp->age<<endl;

	}

	printf("=====================test_vector_mem:\n");
	test_vector_mem();
	printf("=====================\n");
	//test_vector_mem2();


	// 堆上创建vector
	vector<int> * v = new std::vector<int>(20);
	v->push_back(100);
	v->push_back(200);
	printfArray(*v);

	system("pause");
}


