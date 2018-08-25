#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
void p(int id)
{
    struct sembuf sb[1];
    sb[0].sem_num=0;
    sb[0].sem_op=0;
    sb[0].sem_flg=0;
    semop(id,sb,1);
}
int main(void)
{
    int id=semget(1234,0,0);
    if(id==-1)perror("semget"),exit(1);
    p(id);
}
