#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(void){
    int fds[2];
    if(pipe(fds)==-1)
	perror("pipe"),exit(1);
    pid_t pid=fork();
    if(pid==-1) perror("fork"),exit(1);

    if(pid==0){//子进程，往管道中写数据
	close(fds[0]);//关闭读端
	sleep(1);
	write(fds[1],"abc",3);
	close(fds[1]);
	exit(0);
    }else{//父进程，读取管道数据
	close(fds[1]);//关闭写端
	char buf[100]={};
	int r=read(fds[0],buf,100);
	if(r==0)printf("read EOF\n");
	else if(r==-1)perror("read"),exit(1);
	else if(r>0)printf("buf=[%s]\n",buf);
	close(fds[0]);
	exit(0);}
}
