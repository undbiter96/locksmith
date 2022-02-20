#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock[3];
int shared;

void* run(void*);

int main() {
  pthread_t t[3];

  int i;
  for (i = 0; i < 3; i++)
  {
	int *a = &i;
	pthread_mutex_init(&lock[i], NULL);
  	pthread_create(&t[i], NULL, run, a);
  }
  return 1;
}

int rec_sum(int num)
{
	if(num <= 0)	return num;
	return num + rec_sum(num - 1);
}

void *run(void *arg) {
  int i = *arg;
  pthread_mutex_lock(&lock[i]);
  shared++;
  pthread_mutex_unlock(&lock[i]);
  int sum = rec_sum(shared);
  return &sum;
}

