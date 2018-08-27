#include <stdlib.h>
#include <stdio.h>

int main_01()
{
	int i = 0;
	int *p = &i;
	printf("p value:%p  \n", p);

	/*
	 * 0x010B144A 处的第一机会异常(在 C语言提高-指针.exe 中):  0xC0000005:  写入位置 0x010B5868 时发生访问冲突。
	 * "robbin"在全局区，不可以修改
     */
	char *p2 = "robbin";
	//*p2 = 's';
	
	/*
		0x0046FCCC  01 00 00 00  ....  a+0           &a
		0x0046FCD0  02 00 00 00  ....  a+1 
		0x0046FCD4  03 00 00 00  ....  a+2
		0x0046FCD8  04 00 00 00  ....  a+3
		0x0046FCDC  05 00 00 00        a+4
		0x0046FCE0  cc cc cc cc                      &a+1

	   intArr 值：0x0046FCCC
	   intArr 地址：0x________
	*/

	/* 
	   a代表数组首元素的地址，是一个指向数组元素的指针常量
	   &a代表数组的地址,指向由m个元素组成的一维数组的指针变量
	   a与&a值相同，但是类型不同，步长不同
	 */
	int a[5] = { 1, 2, 3, 4, 5 };
	printf("数组元素指针:%p \n", a);  
	printf("数组元素指针+1:%p \n", a + 1);
	printf("数组指针:%p \n", &a);
	printf("数组指针+1:%p \n", &a + 1);


	// sizeof
	printf("sizeof(a[10]):%d\n", sizeof(a)); // 20
	printf("sizeof(&a):%d\n", sizeof(&a));   // 4 二级指针&a+1等于向后跳20个字节
	printf("sizeof(*a):%d\n", sizeof(*a));   // 4
	printf("sizeof(a[0]):%d\n", sizeof(a[0]));// 4

	system("pause");

}