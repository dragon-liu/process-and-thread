#include "thread.h"
#include<stdlib.h>
#include<stdio.h>
#include<inttypes.h>
#include<errno.h>
int end,now,start,sum;

int main(int argc,char *argv[]){
    sum=0;
    now=0;
    int i;

    int num_of_thread=0;
    num_of_thread=atoi(argv[2]);
    end=atoi(argv[1]);

    pthread_t *tid;
    if(!(tid = (pthread_t *)malloc(num_of_thread*sizeof(pthread_t))))
    {
       printf("%s\n","Malloc Error!");
       exit(1);
    }

    for(i = 0;i < num_of_thread;i++)
    {
       pthread_create(&tid[i],NULL,add,NULL);
    }
    for(i=0;i<num_of_thread;i++)
    {
       pthread_join(tid[i],NULL);//等待线程结束
    }
    printf("sum = %lld\n",sum);
    free(tid);
    return 0;
}