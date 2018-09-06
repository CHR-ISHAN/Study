#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid = fork();
    if(pid==-1)
    {
	perror("fork"),exit(EXIT_FAILURE);
    }
    if(pid==0)
    {
	sleep(20);
	printf("哈哈，我死了 pid =%d\n",getpid());
	exit(125);
    }else
    {
	int s;
	pid_t r=wait(&s);
	printf("r=%d\n",r);
	if(WIFEXITED(s)){
	printf("code=%d",WEXITSTATUS(s));	
	}
    }
}
