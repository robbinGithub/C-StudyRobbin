#include <stdio.h>
#include <stdio.h>

typedef struct _Teacher
{
	char name[62];
	char * job;
	char ** pStuArray; // 老师带的学生
	int age;

}Teacher;

/*在堆上创建结构体数组(被调函数分配内存）通过二级指针传出去*/
int  createArray4(Teacher * * p, int num)
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
	// 创建老师带的学生
	for (int i = 0; i < num; i++){
		// 创建一个临时变量 
		char ** ptemp = (char**)malloc(3 * sizeof(char*));
		for (int j = 0; j < 3; j++)
		{
			ptemp[i] = (char*)malloc(120);
		}
		tArray[i].pStuArray = ptemp;
	}
	*p = tArray;
	return 0;
}


int main04()
{  
	int ret;
	Teacher *pArray = NULL;
	ret = createArray4(&pArray, 3);
	if (ret != 0)
	{
		return;
	}
	return 0;
}