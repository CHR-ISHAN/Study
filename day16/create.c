#include<stdio.h>
#include<pthread.h>
void loop1()
{
    while(1)
    {
        printf("hahaha");
        sleep(1);
    }
}
void *thr_start(void *arg)
{
    return NULL;
}
int main()
{   int ret;
    pthread_t tid;
   ret= pthread_create(&tid,NULL,thr_start,NULL);
   if(ret!=0)
   {
       printf("create error:%s\n",strerror(ret));
   }
}
