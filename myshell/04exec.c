#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
    char *argv[]={"ls","-l",NULL};
   /* if(execv("/bin/ls",argv)==-1)
        perror("execv"),exit(1);*/
   /*execl("/bin/ls","ls","-l",NULL);*/
    execlp("ls","ls","-l",NULL);
    char *args[]={"th",NULL};
    char *env[]={"_1=shanghai","_2=xian"};
    execve("./th",args,env);
}
