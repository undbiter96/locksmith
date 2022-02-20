#include <pthread.h>

pthread_mutex_t lock1, lock2;
int shared_var;
int completely_unprotected;
int partly_unprotected;

void *my_func(void *arg) {
  int local_var = 4;
  pthread_mutex_lock(&lock1);
  shared_var++;
  pthread_mutex_unlock(&lock1);
  pthread_mutex_lock(&lock2);
  partly_unprotected = local_var;
  pthread_mutex_unlock(&lock2);
  partly_unprotected++;
  completely_unprotected = local_var;
  return NULL;
}

int main() {
  pthread_t t1, t2;

  pthread_mutex_init(&lock1, NULL);
  pthread_mutex_init(&lock2, NULL);

  pthread_create(&t1, NULL, my_func, NULL);
  pthread_create(&t2, NULL, my_func, NULL);
  return 1;
}


