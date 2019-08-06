#include "my_thread.h"

void *add_thread(void* task){
  struct Task* pt=(struct Task*)task;
  int i;
  for(i=pt->min;i<pt->max;i++){
    pthread_mutex_lock(pt->pmtx);
    *(pt->psum)+=i;
    pthread_mutex_unlock(pt->pmtx);
  }
  pthread_exit(NULL);
}
