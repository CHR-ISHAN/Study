
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
void p(int id)
{
    struct sembuf sb[1]={0,1,0};
    semop(id,sb,1);
}
int main(void)
{
    int shmid=shmget(1234,0,0);
    if(shmid==-1)perror("shmget"),exit(1);
    int semid=semget(1234,0,0);
    if(shmid==-1)perror("shmget"),exit(1);
    int *pv=shmat(shmid,NULL,0);
    while(1){
    p(semid);
    printf("p=%d\n",*pv);
}}

