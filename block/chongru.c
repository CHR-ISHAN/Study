#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
struct T {int a;int b;int c;};
struct T g_data;
void unsafe(void){
    printf("g_data.a=%d, g_data.b=%d, g_data.c=%d\n",g_data.a,g_data.b,g_data.c);
}
void handler(int s)
{
    alarm(1);
    unsafe();
}
int main(void)
{
    signal(SIGALRM,handler);
    alarm(1);
    struct T one ={1,1,1};
    struct T zero ={2,2,2};

    for(;;)
    {
        g_data=one;
        g_data=zero;
    }
}
