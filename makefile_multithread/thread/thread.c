#include "thread.h"

pthread_mutex_t now_t= PTHREAD_MUTEX_INITIALIZER;

extern int end,now,start,sum; //在这个文件中引用其他源文件的外部变量

void *add(void* arg){
    while(1){
       pthread_mutex_lock(&now_t);
       if(now>end){
          pthread_mutex_unlock(&now_t);
          pthread_exit(NULL);//到达临界条件后返回
          //return ((void*)0);
       }
        sum+=now;
        now++;
        pthread_mutex_unlock(&now_t);
    }
}