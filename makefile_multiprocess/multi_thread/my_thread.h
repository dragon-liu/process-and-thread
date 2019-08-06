#ifndef __MY_THREAD
#define __MY_THREAD

#include<pthread.h>

struct Task{
  int* psum;
  int min;
  int max;
  pthread_mutex_t* pmtx;
};

void *add_thread(void* task);

#endif
