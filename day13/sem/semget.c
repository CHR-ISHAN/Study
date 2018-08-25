#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
int main(void)
{
    int id=semget(1234,1,IPC_CREAT|0664);
    if(id==-1)perror("semget"),exit(1);
    printf("semget ok\n");
}
