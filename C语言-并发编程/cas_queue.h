// .h

#pragma once

#ifndef _cas_queue
#define _cas_queue

#ifndef C_BOOL
#define C_BOOL

typedef int cbool;
#define false 0 
#define true  1

#endif

//
//typedef struct _cas_queue
//{
//  int size;
//} cas_queue;

#define QUEUE_SIZE 65536

/*
    CAS无锁Queue(环形队列)
	@see https://www.cnblogs.com/luconsole/p/4944304.html
  */


#ifdef __cplusplus
extern "C" {
#endif
	/*
	compare and swap： CAS(*ptr,outvalue,newvalue);
	return bool
	*/

	cbool compare_and_swap(void ** ptr, long outvalue, long newvalue);

	void cas_queue_init(int queue_size);

	void cas_queue_free();

	cbool  cas_queue_try_enqueue(void * p);

	cbool cas_queue_try_dequeue(void ** p);


#ifdef __cplusplus
}
#endif

#endif