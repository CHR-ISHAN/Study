#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)

{
	printf("before fork:%d\n",getpid());
	pid_t pid =fork();
	if(pid==0){
		printf("child,pid=%d,my parent=%d\n",getpid(),getppid());}
	else{
		printf("parent pid =%d,mychild=%d\n",getpid(),pid);
	pid_t pid2=fork();
		if(pid2==0){
			printf("child2,pid=%d,my parent=%d\n",getpid(),getppid());}
	else{
		printf("parent create 2 pid =%d,mychild =%d\n",getpid(),pid2);
		sleep(1);}
	}
	printf("haha");
}
