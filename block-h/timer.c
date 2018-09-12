#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
void handler(int s)
{
    printf("time out %d\n",s);
}
int main(void)
{
    signal(SIGALRM,handler);
    struct itimerval it;
    memset(&it,0x00,sizeof it);
    it.it_value.tv_usec=1;
    it.it_interval.tv_sec=1;
    setitimer(ITIMER_REAL,&it,NULL);
    for(;;)
    {
        printf(".");
        fflush(stdout);
        sleep(60);
    }
}
