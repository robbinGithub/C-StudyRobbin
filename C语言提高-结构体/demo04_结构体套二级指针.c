#include <stdio.h>
#include <stdio.h>

typedef struct _Teacher
{
	char name[62];
	char * job;
	char ** pStuArray; // ��ʦ����ѧ��
	int age;

}Teacher;

/*�ڶ��ϴ����ṹ������(�������������ڴ棩ͨ������ָ�봫��ȥ*/
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
	// ������ʦ����ѧ��
	for (int i = 0; i < num; i++){
		// ����һ����ʱ���� 
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