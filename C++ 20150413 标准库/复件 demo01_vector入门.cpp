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


void main_0102(){

	test_mem3();
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

