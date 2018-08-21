#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd=open("open.c",O_RDONLY);
    if(fd==-1){

    }
    while(1){
        char buf[10+1]={};
        int r=read(fd,buf,10);
        if(r==-1)perror("read"),exit(1);
        if(r==0){
            printf("读结束\n");
            break;
        }else{
            printf("%s",buf);
            fflush(stdout);
        }
        sleep(1);
    }    
    close(fd);
}
