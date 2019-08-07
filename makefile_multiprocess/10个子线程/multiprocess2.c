#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int status;
  pid_t pid;
  int sum=0;
  int fd[10][2];
  int child_sum[10];

  int j;
  for(j = 0 ; j < 10; j++)
  {
    if(pipe(fd[j])<0)
    {
      printf("create pipe Error!");
    }
    if((pid=fork())<0)
    {
        printf("create process Error!");
    }
    else if(pid>0)
    {
        //while(wait(&status) != pid);
        //father process
        int i;
        close(fd[j][1]);//关闭写端
        
        int a = read(fd[j][0],&child_sum[j],sizeof(int));
        
    }
    else
    {
        //child process
        int i;
        close(fd[j][0]);//关闭读端
        sum = 0;
        for(i = 10*j; i<10*(j+1); i++)
        {
            sum+=i;
        }
        write(fd[j][1],&sum,sizeof(int));
        exit(0); //这个很重要，子进程完成相应计算后就退出，否则最后输出Sum时会有很多sum输出
    }
  }
  int sumall = 0;
  for(j = 0; j < 10; j++)
  {
    sumall+=child_sum[j];
  }
  printf("Sum is %d\n", sumall);
  return 0;
}