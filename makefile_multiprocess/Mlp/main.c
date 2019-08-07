#include "main.h"

int main(int argc, char*argv[])
{
    int status;
    pid_t pid;
    int sum=0;

    if(argc != 3)
    {
        printf("%s\n","Input Error!");
        return -1;
    }

    int num = atoi(argv[1]);
    int num_process = atoi(argv[2]);

    if(!(num_process))
    {
        printf("%s\n","Input Error!");
        return -1;
    }
    if(num%num_process)
    {
        printf("%s\n","Input Error!");
        return -1;
    }
    
    int **fd=NULL;
    int *child_sum=NULL;

    int a;
    int i;
    int j;

    if(!(fd = (int**)malloc(num_process*sizeof(int*))))
    {
        printf("%s\n","Malloc Error!");
        return -1;
    }

    for(a = 0; a < num_process; a++)
    {
        if(!(fd[a] = (int*)malloc(2*sizeof(int))))
        {
            printf("%s\n","Malloc Error!");
            return -1;
        }
    }
    
    if(!(child_sum = (int*)malloc(num_process*sizeof(int))))
    {
        printf("%s\n","Malloc Error!");
        return -1;
    }

    int subsum = num/num_process;

    //分配进程进行计算
    for(j = 0 ; j < num_process; j++)
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
            close(fd[j][1]);//关闭写端
            
            int a = read(fd[j][0],&child_sum[j],sizeof(int));
            
        }
        else
        {
            //child process
            close(fd[j][0]);//关闭读端
            sum = 0;
            for(i = subsum*j; i<subsum*(j+1); i++)
            {
                sum+=i;
            }
            write(fd[j][1],&sum,sizeof(int));
            exit(0); //这个很重要，子进程完成相应计算后就退出，否则最后输出Sum时会有很多sum输出
        }
    }
    
    int sumall = 0;
    for(j = 0; j < num_process; j++)
    {
        sumall += child_sum[j];
    }
    printf("Sum is %d\n", sumall);

    for(a = 0; a < num_process; a++)
    {
        free(fd[a]);
    }
    free(child_sum);
    free(fd);
    return 0;
}