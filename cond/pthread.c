#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
int ticket =100;
void *get_ticket(void *arg)
{
    int id =(int)arg;
    while(1)
        {
        if(ticket>0)
        {  
            usleep(100);
            ticket--;
            printf("thread :%d get a ticket :%d\n",id,ticket);

        }
        else
        {
            pthread_exit(NULL);
        }
    }
}
int main()
{
    pthread_t tid[4];
    int i=0,ret;
    for(i=0;i<4;i++)
    {
        ret=pthread_create(&tid[i],NULL,get_ticket,(void*)i);
    }
    pthread_join(tid[0],NULL);     
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    pthread_join(tid[3],NULL);
}
