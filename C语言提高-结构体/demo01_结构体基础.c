#include <stdio.h>
#include <stdio.h>
#include <string.h>

/*��ṹ����һ������ Teacher ���滻 struct Teacher*/
typedef struct _Teacher
{
	char name[62];
	int age;
}Teacher;


/*�ڶ��ֺ͵����ֶ���ṹ��������ǣ��õıȽ���(����)*/


// ����ṹ������ڶ��ַ���(����)
struct 
{
   char name[62];
   int age;
} t2,t3;

// ����ṹ����������ַ���
struct _Teacher3
{
	char name[62];
	int age;
} t4;


/*struct Teacher
{
	char name[62];
	int age;
};*/

/*
  �ṹ�忽��
*/
void copyStruct(Teacher *from,Teacher *to ){
	*to =  *from;
}
/*
  ֵ���ݣ�������
*/
void copyStruct2(Teacher from, Teacher to){
	to = from;
}


void main(){

	/*struct Teacher t1;
	struct Teacher *p = (struct Teacher *) malloc(sizeof(struct Teacher));*/

	// ����ṹ�������һ�ַ���
	Teacher t1;
	Teacher t2;
	t1.age = 10;
	Teacher * p = NULL;

	// �Խṹ������������ַ��� 
	t1.age = 26;   // ͨ����ķ��������ṹ��ĳ�Ա��

	p = &t1;
	p->age = 27;   // ͨ��ָ������ṹ��ĳ�Ա��  ����Ѱַ����Ա������ڽṹ���ڴ�ƫ����
	p->age;        // ����дû������
	strcpy(t1.name, "robbin");
	t2 = t1;       // ����������ʲô 
	printf("t2.age:%d\n", t2.age);
	
	{
		Teacher t3;
		memset(&t3, 0, sizeof(Teacher));
		// t3.age = 100;
		// copyStruct(&t1, &t3);
	    copyStruct2(t1, t3);
		printf("t3.age:%d\n", t3.age);
	}


	// Teacher *p = (Teacher *)malloc(sizeof(Teacher));

	system("pause");
	return 0;

}