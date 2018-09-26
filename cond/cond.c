#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int noddle=0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *thr_product(void *arg)
{
    while(1)
    {
    if(noddle==0)
    {
        printf("onsale\n");
        noddle=1;
        pthread_cond_signal(&cond);
    }
    }
    return NULL;
}
void *thr_consumer(void *arg)
{
    while(1)
    {
    if(noddle==0)
    {
    pthread_cond_wait(&cond,&mutex) ;
    }
    printf("very good\n");
    noddle=0;
    }
    return NULL;
}
int main()
{
    pthread_t tid1,tid2;
    int ret;
    pthread_cond_init(&cond,NULL);
    ret =pthread_create(&tid1,NULL,thr_product,NULL);
    if(ret!=0)
    {   printf("pthread_create error!\n");
    return -1;
    

}
ret =pthread_create(&tid2,NULL,thr_consumer,NULL);
if(ret!=0){
    printf("pthread_create error\n");
    return -1;
}
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
pthread_cond_destroy(&cond);
pthread_mutex_destroy(&mutex);
return 0;
}
