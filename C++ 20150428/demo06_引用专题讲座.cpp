#include "iostream"
using namespace std;

void swap2(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c; 
}
void swap(int &a, int &b){
	int c = 0;
	c = a;
	a = b;
	b = c;
}
struct Teacher{

	int &a;
	int &b;
	//char &c;
	//char c[5];
	//char *p;
	
};

//引用本质是一个常量指针
int main05(){
	printf("size of (Teacher) %d\n", sizeof(Teacher));
	system("pause");
	return 0;
}

int main03(){
	int a = 10;
	int b = 20;
	swap2(&a, &b);
	printf("a:%d;b:%d", a, b);
	system("pause");
	return 0;
}

int main02(){
	int a = 10;
	int b = 20;
	swap(a, b);
	printf("a:%d;b:%d", a, b);
	system("pause");
	return 0;
}
void main01()
{
	int a = 10;
	//引用相当于变量的别名
	int &b = a;
	int &c = b;
	b = 11;
	printf("b:%d\n", b);
	printf("a:%d\n", a);
	printf("c:%d\n", c);
	system("pause");
}