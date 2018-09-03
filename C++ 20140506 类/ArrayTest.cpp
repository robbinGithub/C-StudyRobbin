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
		//给数组的元素赋值 需要把数组元素本身给返回出来（）
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
	a3 = a2; //执行=操作
// 	1)如果a3已经分配内存需要释放
//	2）根据a2开辟内存空间 把a2的值copy到a3中。

	printf("a3:len %d", a3.length());
	for(int i=0; i<a3.length(); i++)
	{
		printf("array %d: %d\n", i, a3[i]);
	}

	a1 = a3 = a2; //执行=操作
	
	// a1.operator=(a3.operator=(a2));
	 // a1.operator=(void)
	
	//a2.operator==(a1);
	
	if (a2==a1)
	{
		printf("相等");
	}
	else
	{
		printf("不相等");
	}

	
	if (a2 != a1)
	{
		printf("不相等");
	}
	else
	{
		printf("相等");
	}


    system("pause");
    return 0;
}
