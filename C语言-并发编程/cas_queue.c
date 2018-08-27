
//.c
#include "cas_queue.h"

#ifdef _MSC_VER
#include <windows.h>
#else

#endif


volatile unsigned long read_index = 0;
volatile unsigned long write_index = 0;

long* read_index_p = &read_index;
long* write_index_p = &write_index;

void** ring_queue_buffer_head;

int ring_queue_size = QUEUE_SIZE;

cbool is_load = 0;

cbool compare_and_swap(void * ptr, long outvalue, long newvalue)
{
#ifdef _MSC_VER  // vs
	long return_outvalue = InterlockedCompareExchange(ptr, newvalue, outvalue);
	return return_outvalue == outvalue;
	/*InterlockedCompareExchange64 No success£¡£¡*/
	//#ifndef _WIN64
	//  //32 bit
	//  long return_outvalue = InterlockedCompareExchange(ptr, newvalue, outvalue);
	//  return return_outvalue == outvalue;
	//#else
	//  //64 bit
	//  long return_outvalue = InterlockedCompareExchange64(ptr, newvalue, outvalue);
	//  return return_outvalue == outvalue;
	//#endif
#else
	//linux
#endif

}

void cas_queue_init(int queue_size)
{
	if (queue_size > 0)
		ring_queue_size = queue_size;
	int size = sizeof(void**)*ring_queue_size;
	ring_queue_buffer_head = malloc(size);
	memset(ring_queue_buffer_head, 0, size);
	is_load = 1;
	read_index = 0;
	write_index = 0;
}

void cas_queue_free()
{
	is_load = 0;
	free(ring_queue_buffer_head);
}

cbool cas_queue_try_enqueue(void * p)
{
	if (!is_load)
		return false;
	unsigned long index;
	do
	{
		//queue full
		if (read_index != write_index && read_index%ring_queue_size == write_index%ring_queue_size)
			return false;
		index = write_index;
	} while (compare_and_swap(&write_index, index, index + 1) != true);
	ring_queue_buffer_head[index%ring_queue_size] = p;

	return true;
}
cbool cas_queue_try_dequeue(void ** p)
{
	if (!is_load)
		return false;
	unsigned long index;
	do
	{
		//queue empty
		if (read_index == write_index)
			return false;
		index = read_index;
	} while (compare_and_swap(read_index_p, index, index + 1) != true);
	*p = ring_queue_buffer_head[index%ring_queue_size];
	return true;
}