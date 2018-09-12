//使用select实现单线程多客户端聊天机器人服务端程序
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/select.h>
int main(int argc,char *argv[])
{
    int lst_fd,cli_fd;
    int i,ret,max_fd;
    struct timeval tv;
    
    socklen_t len;
    struct sockaddr_in lst_addr;
    struct sockaddr_in cli_addr;
    fd_set readfds;
    int fd_list[1024];
    if(argc!=3)
    {
        printf("USAGE:./tcp_select.c ip prot\n");
        return -1;
    }
    lst_fd=socket(AF_INET,SOCK_STREAM,0);
    if(lst_fd<0)
    {
        perror("socket error");
        return -1;
    }
    lst_addr.sin_family=AF_INET;
    lst_addr.sin_port=htons(atoi(argv[2]));
    lst_addr.sin_addr.s_addr=inet_addr(argv[1]);
    len=sizeof(struct sockaddr_in);
    ret=bind(lst_fd,(struct sockaddr*)&lst_addr,len);
    if(ret<0)
    {
        perror("bind error");
        return -1;
    }
    if(listen(lst_fd,5)<0)
    {
        perror("listen error");
        return -1;
    }
    for(i=0;i<1024;i++)
    {
        fd_list[i]=-1;

    }
    fd_list[0]=lst_fd;
    while(1)
    {
        tv.tv_sec=3;
        tv.tv_usec=0;
    max_fd=lst_fd;
    for(i=0;i<1024;i++)
    {
        //循环将所有已经存在的描述符添加到监控集合中
        if(fd_list[i]!=-1)
        {
            FD_SET(fd_list[i],&readfds);
        }
        //从数组中选出最大的描述符
        if(max_fd<fd_list[i])
        {
            max_fd=fd_list[i];
        }
    }
    ret=select(max_fd+1,&readfds,NULL,NULL,&tv);
    if(ret<0)
    {
        perror("select error");
        continue;
    }
    if(ret==0)
    {
        printf("timeout\n");
        continue;
    }
    for(i=0;i<1024;i++)
    {
        if(fd_list[i]==-1)
        {
            continue;
        }
        if(FD_ISSET(fd_list[i],&readfds))
        {
            //当就绪描述符是监听描述符时，则代表有新连接到来
            if(fd_list[i]==lst_fd)
            {
                cli_fd=accept(lst_fd,(struct sockaddr*)&cli_addr,&len);
                
                for(int j=0;j<1024;j++)
                {
                    if(fd_list[j]==-1)
                    {
                        fd_list[j]=cli_fd;
                        break;
                    }
                }
            }
            else
            {
                char buff[1024]={0};
                ret=recv(fd_list[i],buff,1023,0);
                if(ret<=0)
                {
                    close(fd_list[i]);
                    fd_list[i]=-1;
                }
                printf("client say:%s\n",buff);
                send(fd_list[i],"what????",10,0);
            }
        }
    }

    }
}
