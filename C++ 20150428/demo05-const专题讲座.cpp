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
	printf("�޸ĺ��a:%d\n", a);
	system("pause");
	return 0;
}



int getTeacher01(Teacher const *pT) //����ָ�룬ֻ��ָ���ڴ����򣬲���ָ�������ڴ�����
{   
	//pT = NULL;
	//pT->age = 11;
	return 0;
}

int getTeacher02(const Teacher  *pT) //����ָ�룬ֻ��ָ���ڴ����򣬲���ָ�������ڴ�����
{
	//pT->age = 11;
	return 0;
}




int main()
{
	int a = 10;
	int b = 20;
	//const int *p = &a; //ָ��ָ���ڴ�ռ䲻���޸�
	//int * const p = &b; //����ָ�룬ָ�벻����ָ�������ռ�
	system("pause");
	return 0;
}
