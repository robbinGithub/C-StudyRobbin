#include "iostream"
#include "Array.h"
using namespace std;

int main_000()
{
    Array a1(10);
    
    for(int i=0; i<a1.length(); i++)
    {
        //a1.setData(i, i);  
		a1[i] = i+100;
		//a1.operator[](i) = i;
		//�������Ԫ�ظ�ֵ ��Ҫ������Ԫ�ر�������س�������
		//0 = i;
    }
    
    for(int i=0; i<a1.length(); i++)
    {
		//printf("array %d: %d\n", i, a1.getData(i));
		// printf("array %d: %d\n", i, a1[i]) ;
    }
    
    Array a2 = a1;
    
    for(int i=0; i<a2.length(); i++)
    {
        //printf("array %d: %d\n", i, a2.getData(i));
		//printf("array %d: %d\n", i, a2[i]);
    }


// 	
	Array a3(100);
	a3 = a2; //ִ��=����
// 	1)���a3�Ѿ������ڴ���Ҫ�ͷ�
//	2������a2�����ڴ�ռ� ��a2��ֵcopy��a3�С�

	printf("a3:len %d", a3.length());
	for(int i=0; i<a3.length(); i++)
	{
		printf("array %d: %d\n", i, a3[i]);
	}

	a1 = a3 = a2; //ִ��=����
	
	// a1.operator=(a3.operator=(a2));
	 // a1.operator=(void)
	
	//a2.operator==(a1);
	
	if (a2==a1)
	{
		printf("���");
	}
	else
	{
		printf("�����");
	}

	
	if (a2 != a1)
	{
		printf("�����");
	}
	else
	{
		printf("���");
	}


    system("pause");
    return 0;
}
