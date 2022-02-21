#include <pthread.h>

pthread_mutex_t lock1, lock2, lock[2];
float shared_var;
int partly_unprotected;
float non_linear;
int many_refs;
int completely_unprotected;

void *my_func(void *arg) {
  int local_var = 4, local_var2;
  pthread_mutex_lock(&lock1);
  shared_var++;
  many_refs += 5;
  pthread_mutex_unlock(&lock1);
  pthread_mutex_lock(&lock2);
  partly_unprotected = local_var;
  local_var += many_refs;
  pthread_mutex_unlock(&lock2);
  many_refs = 1;
  local_var = partly_unprotected;
  completely_unprotected--;
  pthread_mutex_lock(&lock[1]);
  non_linear = 4.2;
  pthread_mutex_unlock(&lock[1]);
  local_var2 = many_refs;
  return NULL;
}

int main() {
  pthread_t t1, t2, t[2];

  int i;
  for(i = 0; i < 2; i++)
  {
    pthread_mutex_init(&lock[i], NULL);
    pthread_create(&t[i], NULL, my_func, NULL);
  }

  pthread_mutex_init(&lock1, NULL);
  pthread_mutex_init(&lock2, NULL);

  pthread_create(&t1, NULL, my_func, NULL);
  pthread_create(&t2, NULL, my_func, NULL);

  return 1;
}


