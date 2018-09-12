#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
void handler(int s)
{
    printf("%d recv\n",s);
}
void handler_quit(int s)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_UNBLOCK,&set,NULL);
}
int main(void)
{
    signal(SIGINT,handler);
    signal(SIGQUIT,handler_quit);
    sigset_t set,pset;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set,NULL);
    for(;;)
    {
        sleep(1);
        sigemptyset(&pset);
        sigpending(&pset);
        for(int i=0;i<NSIG;i++)
        {
            if(sigismember(&pset,i))printf("1");
            else printf("0");
        }
        printf("\n");
    }
}
