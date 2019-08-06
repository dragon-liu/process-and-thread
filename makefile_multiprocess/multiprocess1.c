#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  pid_t pid;
  int sum=0;
  int fd[2];
  if(pipe(fd)<0){
    printf("create pipe Error!");
  }
  if((pid=fork())<0){
    printf("create process Error!");
  }
  else if(pid>0){
    //father process
    int i;
    close(fd[1]);//关闭写端
    for(i=1;i<51;i++)
    {
      sum+=i;
    }
    {
      int child_sum=0;
      int a = read(fd[0],&child_sum,sizeof(int));
      printf("child sum is %d\n",child_sum);
      sum+=child_sum;
    }
    printf("sum is %d\n",sum);
  }
  else
  {
    //child process
    int i;
    close(fd[0]);//关闭读端
    for(i=51;i<101;i++)
    {
      sum+=i;
    }
    write(fd[1],&sum,sizeof(int));
    printf("child real sum is %d\n",sum);
  }
  return 0;
}