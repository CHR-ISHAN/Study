#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	printf("before fork\n");
	pid_t pid =fork();
	
	if(pid==0){
	while(1)
		printf("child\n");
	}
	else if(pid>0){while(1)
		printf("parent\n");}
}

