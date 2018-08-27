#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
   一、volatile 介绍
    表示一个变量也许会被后台程序改变，关键字 volatile 是与 const 绝对对立的。它指示一个变量也许会被某种方式修改，

	二、为什么使用 volatile(volatile的作用)
 
	1.作为指令关键字,确保本条指令不会被编译器的优化，发生指令重排序；
	2.每次重新从它所在的内存读取数据；
	3.写数据保证其他线程的可见性。


	@see http://blog.csdn.net/qq_29350001/article/details/54024070
  */

static int i = 0; //i 为非自动变量  

int main_023()
{  
	
	volatile int i = 10;
	int a = i; //优化
	int b = i;

	printf("i = %d\n", b);
	system("pause");

	return 0;
}


/*
   2、一个中断服务子程序中会访问到的非自动变量（Non-automatic variables)
   程序的本意是希望 ISR_2 中断产生时，在main函数中调用 dosomething 函数，
   但是，由于编译器判断在 main 函数里面没有修改过 i，因此可能只执行一次对从i到某寄存器的读操作，
   然后每次if判断都只使用这个寄存器里面的“i副本”，导致 dosomething 永远也不会被调用。
   如果将变量加上 volatile 修饰，则编译器保证对此变量的读写操作都不会被优化（肯定执行）。
 */
void dosomething2();

int main_02(void)
{

	while (1){
		if (i) dosomething2();
	}
}

void dosomething2()
{
	printf("dosomething");
}

/* Interrupt service routine. */
void ISR_2(void)
{
	i = 1;
}


/*

3、多线程应用中被几个任务共享的变量

	当两个线程都要用到某一个变量且该变量的值会被改变时，应该用 volatile 声明，
	该关键字的作用是防止优化编译器把变量从内存装入CPU寄存器中。
	如果变量被装入寄存器，那么两个线程有可能一个使用内存中的变量，一个使用寄存器中的变量，
	这会造成程序的错误执行。volatile的意思是让编译器每次操作该变量时一定要从内存中真正取出，
	而不是使用已经存在寄存器中的值，如下
*/

/*
 volatile  BOOL  bStop  =  FALSE;  //bStop  为共享全局变量  
(1) 在一个线程中：    
  while(  !bStop  )  {  ...  }    
  bStop  =  FALSE;    
  return;      
  
(2) 在另外一个线程中，要终止上面的线程循环：    
  bStop  =  TRUE;    
  while(  bStop  )

*/