#include  "iostream"
using namespace std;

struct Teacher
{
	char name[32];
	int age;
};

int mainxx()
{
	int a = 10;
	int *p = NULL;
	p = (int *)&a;
	*p = 11;
	printf("修改后的a:%d\n", a);
	system("pause");
	return 0;
}



int getTeacher01(Teacher const *pT) //常量指针，只能指向内存区域，不可指向其他内存区域
{   
	//pT = NULL;
	//pT->age = 11;
	return 0;
}

int getTeacher02(const Teacher  *pT) //常量指针，只能指向内存区域，不可指向其他内存区域
{
	//pT->age = 11;
	return 0;
}




int main()
{
	int a = 10;
	int b = 20;
	//const int *p = &a; //指针指向内存空间不可修改
	//int * const p = &b; //常量指针，指针不可以指向其他空间
	system("pause");
	return 0;
}
