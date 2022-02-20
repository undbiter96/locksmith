#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;
int *arr1, *arr2;
int arr3[15];
struct example {
	int f1;
	float f2;
	char f3;
} ex, ex2, tmp;

void simple_func()
{
	arr1 = malloc(5 * sizeof(int));
	ex.f1 = 3;
	ex.f2 = 2.4;
	ex2.f2 = 6.2;
	ex2.f3 = 'r';
}

void *allocate_mem()
{
	pthread_mutex_lock(&lock);
	tmp = ex;
	ex = ex2;
	ex.f1 = 5;
	pthread_mutex_unlock(&lock);
	//ex = tmp;
	//ex2 = ex;
	arr2 = malloc(10 * sizeof(int));
	arr3[4] = 5;
	arr3[7] = 10;
	return arr2;
}

int main()
{
	pthread_t t, t2;
	simple_func();
	pthread_mutex_init(&lock, NULL);
        pthread_create(&t, NULL, allocate_mem, NULL);
	pthread_create(&t2, NULL, allocate_mem, NULL);
	arr1[0] = 4;
	arr2[0] = 5;
	return 0;
}
