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



// ��̬����

//== != [] =
//(vector<int>ģ������  
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
	//����һ�����飨���ԣ�
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
 Vector �ڴ�����Ա��������Ϊ�y��
 */
void test_mem3()
{

	vector<int> iVec;
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //1��Ԫ�أ� ��������Ϊ1

	iVec.push_back(1);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //2��Ԫ�أ� ��������Ϊ2

	iVec.push_back(2);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //3��Ԫ�أ� ��������Ϊ4

	iVec.push_back(3);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //4��Ԫ�أ� ��������Ϊ4


	printfArray(iVec);

	iVec.push_back(4);
	iVec.push_back(5);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //5��Ԫ�أ� ��������Ϊ8


	

	iVec.push_back(6);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //6��Ԫ�أ� ��������Ϊ8

	iVec.push_back(7);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //7��Ԫ�أ� ��������Ϊ8

	iVec.push_back(8);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //8��Ԫ�أ� ��������Ϊ8

	iVec.push_back(9);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //9��Ԫ�أ� ��������Ϊ16
	/* vs2005/8 �����������Ƿ����ģ���
	9��Ԫ��   ����9
	10��Ԫ�� ����13 */

	/* �y��effective stl�е�����Ľ��� swap() */
	cout << "��ǰvector �Ĵ�СΪ: " << iVec.size() << endl;
	cout << "��ǰvector ������Ϊ: " << iVec.capacity() << endl;
	vector<int>(iVec).swap(iVec);

	cout << "��ʱ��vector<int>���� �Ĵ�СΪ: " << (vector<int>(iVec)).size() << endl;
	cout << "��ʱ��vector<int>���� ������Ϊ: " << (vector<int>(iVec)).capacity() << endl;
	cout << "�����󣬵�ǰvector �Ĵ�СΪ: " << iVec.size() << endl;
	cout << "�����󣬵�ǰvector ������Ϊ: " << iVec.capacity() << endl;
}

/*
 * vector��size��capacity��resize��reserve������
 *
 * @date 2018/08/31 10:49
 * @see https://blog.csdn.net/q_l_s/article/details/52946769
 */
void test_101()
{
	vector<int> iVec;
	iVec.push_back(1);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //1��Ԫ�أ� ��������Ϊ1
	
	/*
	   reserver����������vectorԤ����洢����С����capacity��ֵ ������û�и�����ڴ���г�ʼ����
	   reserve �Ĳ���n���Ƽ�Ԥ�����ڴ�Ĵ�С��ʵ�ʷ���Ŀ��ܵ��ڻ�������ֵ����n����capacity��ֵ���ͻ�reallocate�ڴ� capacity��ֵ����ڻ��ߵ���n ��
	   ��������ector����push_back����ʹ��size ����ԭ����Ĭ�Ϸ����capacityֵʱ �������ڴ��ط��俪����
	 */

	// void reserve (size_type n);
	iVec.reserve(16);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //1��Ԫ�أ� ��������Ϊ16
	// cout << "���� ֵ[15]: " << iVec[15] << endl;
	/*
	  resize�������·����С���ı������Ĵ�С�����Ҵ�������
	  ��nС�ڵ�ǰsize()ֵʱ��vector���Ȼ����size()ֵ ����ǰn��Ԫ�أ�Ȼ�󽫳���n��Ԫ��ɾ��(remove and destroy)
	  ��n���ڵ�ǰsize()ֵʱ��vector�������Ӧ������Ԫ�� ʹ��size()ֵ�ﵽn��������ЩԪ�ؽ��г�ʼ���������������ĵڶ���resize������ָ��val��vector����val����ʼ����Щ�²����Ԫ��
	  ��n����capacity()ֵ��ʱ�򣬻��Զ��������·����ڴ�洢�ռ䡣
	*/
	// void resize (size_type n, value_type val);
	iVec.resize(100);
	// iVec.resize(100, 10); 

	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //32��Ԫ�أ� ��������Ϊ32
	cout << "���� ֵ[90]: " << iVec[90] << endl;

	iVec.resize(2);
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //2��Ԫ�أ� ��������Ϊ100

	cout << "================= vector clear =================" << endl;
	iVec.clear();
	cout << "���� ��СΪ: " << iVec.size() << endl;
	cout << "���� ����Ϊ: " << iVec.capacity() << endl; //0��Ԫ�أ� ��������Ϊ100
}

/*
 * vector swap����
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
 * vector���ڴ��ͷ�
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

	// ��ʱ����ڴ���� ռ��54M

	v.clear();
	cin >> ch;

	// ��ʱ�ٴμ�飬 ��Ȼռ��54M

	cout << "Vector �� ����Ϊ" << v.capacity() << endl;

	// ��ʱ����Ϊ 1048576

	vector<string>().swap(v);

	cout << "Vector �� ����Ϊ" << v.capacity() << endl;

	// ��ʱ����Ϊ0
	cin >> ch;

	// ����ڴ棬�ͷ��� 10M+ ��Ϊ�����ڴ�
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

	// ջ�ϴ���vector
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


	// ���ϴ���vector
	vector<int> * v = new std::vector<int>(20);
	v->push_back(100);
	v->push_back(200);
	printfArray(*v);

	system("pause");
}


