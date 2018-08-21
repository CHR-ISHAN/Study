#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
    int fd=open("abc",O_CREAT|O_RDWR|O_EXCL,0666);
    if(fd==-1)
        perror("open"),exit(1);
    printf("create ok\n");
    close(fd);
}
