#include"my_thread.h"
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


//the max num add to the sum
#ifndef UPPER_BOUNDARY
#define UPPER_BOUNDARY 100
#endif

#ifndef THREAD_NUM
#define THREAD_NUM 10
#endif


int main(){
  pthread_t threads[THREAD_NUM];
  struct Task tasks[THREAD_NUM];
  int sum=0;
  pthread_mutex_t mtx;
  int i;

  void *status;

  pthread_mutex_init(&mtx,NULL);

  printf("thread num is %d\n",THREAD_NUM);
  
  if (THREAD_NUM>UPPER_BOUNDARY){
    printf("the thread num is to big");
  }
  
  for(i=0;i<THREAD_NUM;i++){
    tasks[i].pmtx=&mtx;
    tasks[i].psum=&sum;
    tasks[i].min=i*((int)(UPPER_BOUNDARY/THREAD_NUM));
    tasks[i].max=(i==THREAD_NUM-1)?UPPER_BOUNDARY:(tasks[i].min+(int)(UPPER_BOUNDARY/THREAD_NUM));
    if (pthread_create(threads+i,NULL,add_thread,tasks+i)){
      printf("pthread_create error");
    }else
      printf("thread create. min:%d max:%d \n",tasks[i].min,tasks[i].max);
  }

  
  for(i=0;i<THREAD_NUM;i++)pthread_join(threads[i],&status);
  printf("sum is %d\n",sum);
  return 0;
}
