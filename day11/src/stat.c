#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(void)
{
    struct stat sbuf;
    if(stat("../day11.txt",&sbuf)==-1)
	perror("stat"),exit(1);
    printf("size : %d\n",sbuf.st_size);
}
