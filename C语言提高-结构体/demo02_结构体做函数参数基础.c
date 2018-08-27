#include <stdio.h>
#include <stdio.h>

typedef struct _Teacher
{
	char name[62];
	char * job;
	int age;

}Teacher;


/*打印结构体数组*/
int printArray(Teacher* p, int num){
	for (int i = 0; i < num; i++)
	{

		// 通过数组[ ]的方式访问结构体 

		// printf("name:%s\n", p[i].name);
		// printf("age:%d\n", p[i].age);

		// 通过指针的方式访问结构体
		printf("name:%s", p->name);
		printf("age:%d", p->age);
		printf("job:%s\n", p->job);
		p++;

	}
	return 0;
}

/*排序数组*/
int sortArray(Teacher* p, int num){
	Teacher  temp;
	for (int i = 0; i < num; i++){
		for (int j = i + 1; j < num; j++){
			if (p[i].age> p[j].age)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	return 0;
}


/*在堆上创建结构体数组(被调函数分配内存)通过返回值返回地址*/
Teacher *  createArray(int num)
{   
	Teacher * tArray = NULL;
	tArray = (Teacher*)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < num; i++){
		tArray[i].job = (char*)malloc(50);
	}
	return tArray;

}

/*在堆上创建结构体数组(被调函数分配内存）通过二级指针传出去*/
int  createArray2(Teacher * * p, int num)
{  
	if (p == NULL)
	{
		return -1;
	}
	Teacher * tArray = (Teacher*)malloc(3 * sizeof(Teacher));
	if (tArray == NULL){
		return  -1;
	}
	for (int i = 0; i < num; i++){
		tArray[i].job = (char*)malloc(50);
	}
	* p = tArray;
	return 0;
}



int main_0222(){

	// 定义一个结构体数组，给结构体元素赋值，排序，打印
    int i = 0;
	int ret = 0;

	/*Teacher  tArray[3];

	for (int i = 0; i < 3; i++){

		printf("请输入第%d个老师姓名", i + 1);
		scanf("%s", tArray[i].name);
		printf("请输入第%d个老师年龄", i + 1);
		scanf("%d", &tArray[i].age);
	
	}
	printf("排序之前。。。。\n");
	printArray(tArray, 3);
	sortArray(tArray, 3);
	printf("排序之后。。。。\n");
	printArray(tArray, 3); */

	// 在堆上分配内存
	Teacher *pArray = NULL;
	ret  = createArray2(&pArray, 3);
	for (int i = 0; i < 3; i++)
	{
		printf("请输入第%d个老师姓名", i + 1);
		scanf("%s", pArray[i].name);
		printf("请输入第%d个老师年龄", i + 1);
		scanf("%d", &pArray[i].age);
		printf("请输入第%d个老师工作", i + 1);
		scanf("%s",pArray[i].job);  // 没有内存块

	}
	printArray(pArray, 3);
	if (ret != 0){
		return;
	}
	system("pause");
	return 0;
}