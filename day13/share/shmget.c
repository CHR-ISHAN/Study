#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
struct stu{
    int id;
    char name[20];
};
int main(void)
{
    int shmid = shmget(1234,sizeof(struct stu),IPC_CREAT|0644);
    if(shmid==-1)perror("shmid create"),exit(1);
    printf("create ok\n");
}

