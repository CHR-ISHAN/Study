#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>
struct stu{
    int id;
    char name[20];
};
int main(void)
{
    int shmid=shmget(1234,sizeof(struct stu),0);
    if(shmid==-1)perror("shmget"),exit(1);
    struct stu *p=(struct stu *) shmat(shmid,NULL,0);
    assert(p!=NULL);
    p->id=1;
    strcpy(p->name,"哈哈哈哈");
    sleep(10);
    shmdt(p);
}

