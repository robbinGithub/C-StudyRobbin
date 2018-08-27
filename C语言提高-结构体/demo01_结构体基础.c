#include <stdio.h>
#include <stdio.h>
#include <string.h>

/*结结构体起一个别名 Teacher 可替换 struct Teacher*/
typedef struct _Teacher
{
	char name[62];
	int age;
}Teacher;


/*第二种和第三种定义结构体变量忘记，用的比较少(忘掉)*/


// 定义结构体变量第二种方法(匿名)
struct 
{
   char name[62];
   int age;
} t2,t3;

// 定义结构体变量第三种方法
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
  结构体拷贝
*/
void copyStruct(Teacher *from,Teacher *to ){
	*to =  *from;
}
/*
  值传递，有问题
*/
void copyStruct2(Teacher from, Teacher to){
	to = from;
}


void main(){

	/*struct Teacher t1;
	struct Teacher *p = (struct Teacher *) malloc(sizeof(struct Teacher));*/

	// 定义结构体变量第一种方法
	Teacher t1;
	Teacher t2;
	t1.age = 10;
	Teacher * p = NULL;

	// 对结构体变量引用两种方法 
	t1.age = 26;   // 通过点的方法操作结构体的成员域

	p = &t1;
	p->age = 27;   // 通过指针操作结构体的成员域  本质寻址，成员域相对于结构体内存偏移量
	p->age;        // 这样写没有问题
	strcpy(t1.name, "robbin");
	t2 = t1;       // 编译器作了什么 
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