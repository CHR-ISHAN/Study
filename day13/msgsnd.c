#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msgbuf{
    long mtype;
    char mtext[1000];
};
int main(int argc,char *argv[])
{
    if(argc!=2){
        fprintf(stderr,"usage:%s type\n",argv[0]);
        exit(1);
    }
    int id=msgget(1234,0);
    if(id==-1)perror("msgget"),exit(1);
    struct msgbuf mb;
    memset(&mb,0x00,sizeof(mb));
    mb.mtype=atoi(argv[1]);
    printf("msg:");
    fgets(mb.mtext,999,stdin);
    int r=msgsnd(id,&mb,strlen(mb.mtext),0);
    if(r==-1)perror("msgsnd"),exit(1);
}
