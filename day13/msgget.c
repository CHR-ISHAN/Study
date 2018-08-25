#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int msgid=msgget(1234,IPC_CREAT|0644);
    if(msgid==-1)perror("msgget"),exit(1);
    printf("msgget create ok\n");
}
