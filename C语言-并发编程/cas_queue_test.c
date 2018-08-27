#include <stdlib.h>
#include <stdio.h>
#include "cas_queue.h"

/*
 * CASª∑–ŒŒﬁÀ¯Queue≤‚ ‘
 */
#define QUEUE_SIZE_TEST 100

int main_cas_queue()
{
	char *str1 = "robbin";
	char *p2 = NULL;
	cas_queue_init(QUEUE_SIZE_TEST);
	cas_queue_try_enqueue(str1);
	cas_queue_try_dequeue(&p2);
	printf("value:%s", p2);
	system("pause");

}