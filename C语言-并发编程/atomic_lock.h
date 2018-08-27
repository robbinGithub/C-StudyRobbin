#pragma once
#ifndef _atomic_lock_h_include_
#define _atomic_lock_h_include_

#define spin_num (2048)

#ifdef _MSC_VER

#include <windows.h>

#define cpu_pause()  _mm_pause()
#define thread_yield()        SwitchToThread()

__forceinline int compare_and_swap(long volatile *des, long out, long set)
{
	InterlockedCompareExchange(des, set, out);
	return *des == set;
}

#endif

#ifdef __GNUC__

#include <sched.h>

#define cpu_pause()  __asm__ ("pause")
#define thread_yield()       sched_yield()

#if defined(__INTEL_COMPILER) || (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 1))
#define USE_BUILTINS
#endif

static inline int compare_and_swap(volatile long* x, long oldval, long newval) {
#ifdef USE_BUILTINS
	return    __sync_bool_compare_and_swap(x, oldval, newval);
#elif defined(__i386__)
	char result;
	asm volatile ("lock; cmpxchgl %3, %0; setz %1" : "=m"(*x), "=q" (result) : "m" (*x), "r" (newval), "a" (oldval) : "memory");
	return result;
#elif defined(__x86_64__)
	char result;
	asm volatile ("lock; cmpxchgq %3, %0; setz %1" : "=m"(*x), "=q" (result) : "m" (*x), "r" (newval), "a" (oldval) : "memory");
	return result;
#else
#error architecture not supported and gcc too old.
#endif
}

#endif

typedef struct {
	volatile long   lock;
} app_atomic_lock_t;


int app_atomic_trylock(app_atomic_lock_t* lt, long value);

void app_atomic_lock(app_atomic_lock_t* lt, long value);

void app_atomic_unlock(app_atomic_lock_t* lt, long value);
#endif