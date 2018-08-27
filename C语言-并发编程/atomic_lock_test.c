#include "atomic_lock.h"

app_atomic_lock_t lock;
volatile int value;

void* th_fun(void *arg)
{
	int i;
	for (i = 0; i < 10000; i++){

		app_atomic_lock(&lock, 100);
		value++;
		app_atomic_unlock(&lock, 100);
	}
	return NULL;
}

int main_01()
{
	/*lock.lock = 0;

	pthread_t th1, th2;

	pthread_create(&th1, null, th_fun, null);
	pthread_create(&th2, null, th_fun, null);

	pthread_join(th1, null);
	pthread_join(th2, null);

	printf("%d\n", value);*/
	system("pause");

	return 0;
}