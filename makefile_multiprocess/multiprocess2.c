#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int status;
  pid_t pid;
  int sum=0;
  int fd[2];
  if(pipe(fd)<0){
    printf("create pipe Error!");
  }
  int j;
  for(j = 0 ; j < 10; j++)
  {
    if((pid=fork())<0)
    {
        printf("create process Error!");
    }
    else if(pid>0)
    {
        while(wait(&status) != pid);
        //father process
        int i;
        close(fd[1]);//关闭写端
        
        int child_sum=0;
        int a = read(fd[0],&child_sum,sizeof(int));
        printf("child sum is %d\n",child_sum);
        sum+=child_sum;
        
        printf("sum is %d\n",sum);
    }
    else
    {
        //child process
        int i;
        close(fd[0]);//关闭读端
        for(i = 10*j; i<10*(j+1); i++)
        {
            sum+=i;
        }
        write(fd[1],&sum,sizeof(int));
        exit(0);
    }
  }
  return 0;
}