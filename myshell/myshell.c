#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<ctype.h>
#define MAXLINE 1024
int argc = 0;
char *argv[8];
int main()
{
    char buf[MAXLINE+1];
    while(1)
    {
        //打印提示信息，获取用户输入命令
        printf("my shell->");
        memset(buf,0x00,sizeof(buf));
        if(fgets(buf,MAXLINE,stdin)==NULL)break;
        buf[strlen(buf)-1]='\0';
        int flag=0;
        argc=0;
        //for循环解析命令，状态机思想
        for(int i=0;buf[i]!='\0';i++)
        {
            if(!isspace(buf[i])&&flag==0)
            {
                flag=1;
                argv[argc++]=buf+i;

            }
            else if(isspace(buf[i]))
            {
                flag=0;
                buf[i]='\0';
            }
        }
        argv[argc]=NULL;
       // for(int i=0;i<argc;i++)
       // {
         //   printf("argv[%d]=%s\n",i,argv[i]);
       // }
        //创建子进程
        if(fork()==0)
        {
            //用新输入的程序，替换子程序的进程空间
            //执行输入命令
            execvp(argv[0],argv);
            exit(1);
        }
        else
        {
            //父进程等待子进程死亡
            wait(NULL);
        }
    }
    printf("\n谢谢使用\n");
}

