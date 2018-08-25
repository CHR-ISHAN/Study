#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
void v(int id)
{
    struct sembuf sb[1]={0,1,0};
    semop(id,sb,1);
}
union semun{int val;};
int main(void)
{
    int shmid=shmget(1234,sizeof(int),IPC_CREAT|0600);
    if(shmid==-1)perror("shmget");exit(1);
    int semid=semget(1234,1,IPC_CREAT|0600);
    if(semid==-1)perror("shmget"),exit(1);
    //初始化
    union semun su={1};
    semctl(semid,0,SETVAL,su);
    int *p=shmat(shmid,NULL,0);
    int num=0;
    while(1){
    sleep(1);
    *p=num++;
    printf("put ok:%d\n",num-1);
    v(semid);
}
}

