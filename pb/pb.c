#include<stdio.h>
#include <unistd.h>
#include<string.h>
int main()
{   char buf[52];
    char zhan[]="-/|\\";
    memset(buf,0x00,sizeof(buf));
    printf("\033[?25l");
    for(int i=0;i<50;i++)
    {
        buf[i]='#';
    printf("\r[%-50s][%d%%][%c]",buf,(i+1)*2,zhan[i%4]);
    fflush(stdout);
    usleep(100000);
    }

    printf("\n");
    printf("\033[?25h\n");
}
