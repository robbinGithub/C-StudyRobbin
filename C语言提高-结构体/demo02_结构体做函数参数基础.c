#include <stdio.h>
#include <stdio.h>

typedef struct _Teacher
{
	char name[62];
	char * job;
	int age;

}Teacher;


/*��ӡ�ṹ������*/
int printArray(Teacher* p, int num){
	for (int i = 0; i < num; i++)
	{

		// ͨ������[ ]�ķ�ʽ���ʽṹ�� 

		// printf("name:%s\n", p[i].name);
		// printf("age:%d\n", p[i].age);

		// ͨ��ָ��ķ�ʽ���ʽṹ��
		printf("name:%s", p->name);
		printf("age:%d", p->age);
		printf("job:%s\n", p->job);
		p++;

	}
	return 0;
}

/*��������*/
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


/*�ڶ��ϴ����ṹ������(�������������ڴ�)ͨ������ֵ���ص�ַ*/
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

/*�ڶ��ϴ����ṹ������(�������������ڴ棩ͨ������ָ�봫��ȥ*/
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

	// ����һ���ṹ�����飬���ṹ��Ԫ�ظ�ֵ�����򣬴�ӡ
    int i = 0;
	int ret = 0;

	/*Teacher  tArray[3];

	for (int i = 0; i < 3; i++){

		printf("�������%d����ʦ����", i + 1);
		scanf("%s", tArray[i].name);
		printf("�������%d����ʦ����", i + 1);
		scanf("%d", &tArray[i].age);
	
	}
	printf("����֮ǰ��������\n");
	printArray(tArray, 3);
	sortArray(tArray, 3);
	printf("����֮�󡣡�����\n");
	printArray(tArray, 3); */

	// �ڶ��Ϸ����ڴ�
	Teacher *pArray = NULL;
	ret  = createArray2(&pArray, 3);
	for (int i = 0; i < 3; i++)
	{
		printf("�������%d����ʦ����", i + 1);
		scanf("%s", pArray[i].name);
		printf("�������%d����ʦ����", i + 1);
		scanf("%d", &pArray[i].age);
		printf("�������%d����ʦ����", i + 1);
		scanf("%s",pArray[i].job);  // û���ڴ��

	}
	printArray(pArray, 3);
	if (ret != 0){
		return;
	}
	system("pause");
	return 0;
}