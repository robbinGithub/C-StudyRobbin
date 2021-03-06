#include <stdlib.h>
#include <stdio.h>

/*
   free函数释放动态申请的内存时只需要把内存块的首地址传过去就行了，
   显然仅仅依靠首地址是无法确定要释放多少内存的，猜想应该在某处存放着这个内存块的大小，
   网上搜了搜发现在Linux里面glibc在分配内存的时候会在内存块的地址前面的4个字节出存放内存块的大小，
   就猜想Windows里面应该也是这样。写了一个小程序测试了下：

   1000000000
   二进制：    00111011 10011010 11001010 00000000
   十六进制：  3b9aca00
   -------------------------------------------------------------->内存增长方向(小->大)
   大端：3b9aca00
   小端 :  00ca9a3b

   小端低低：低位内存放低位字节
   0x0048BB20     00
   0x0048BB21     ca
   0x0048BB22     9a
   0x0048BB23    3b

   @author robbin.zhang
   @date 2018/01/25 22:21
*/
int main_0x01()
{
	int *p = (int *)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		// *(p + i) = 1000000000 + i;
		*(p + i) =  i;
	}

	free(p);

	return 0;
}