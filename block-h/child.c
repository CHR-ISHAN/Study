#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void handler(int s)
{
    wait(NULL);
    }
int main(void)
{
    signal(SIGCHLD,handler);//SIGCHLD缺省是忽略但不会
    pid_t pid =fork();
    if(pid==0)
    {
        for(int i=0;i<5;i++)
        {
            printf("i am a child\n");
            sleep(1);
        }
    }
    else{
        while(1)
        {
            printf("i am parents\n");
            sleep(1);
        }
    }
}
