/*这是一个基于epoll的TCP服务端高并发多客户端聊天程序
 * 1、TCP服务端程序
 * 2、创建epoll--------epoll_create
 * 3、开始向epoll监控集合中添加事件节点 epoll_ctl
 * 4、开始监控等待epoll_wait
 * epoll的事件节点是一个结构体
 *  struct epoll_event{
 *  _unit32_t events;
 *  epoll_data_t data;
 *  }
 */
#include "network.h"
int main(int  argc,char *argv[])
{
    if(argc!=3)
    {
        printf("USAGE:./tcp_epoll.c ip port\n");
        return -1;
    }
        int lst_fd,new_fd;
        int ret,i;
        socklen_t len;
        struct sockaddr_in lst_addr;
        struct sockaddr_in cli_addr;
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
        ret=bind(lst_fd,(struct sockaddr *)&lst_addr,len);
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
        int epfd=epoll_create(1024);
        if(epfd<0)
        {
            perror("epoll_create error");
            return -1;
        }
        //定义事件，向epoll监控集合添加事件节点
        //evs事件数组用于接收就绪的事件
        struct epoll_event ev ,evs[1024];
        ev.events=EPOLLIN;
        ev.data.fd=lst_fd;
        epoll_ctl(epfd,EPOLL_CTL_ADD,lst_fd,&ev);
        while(1)
        {
            
            int nfds=epoll_wait(epfd,evs,1024,3000);
            if(nfds<0)
            {
                perror("epoll_wait error");
                continue;
            }
            else if(nfds==0)
            {
                printf("timeout!!!!!!\n");
                continue;
            }
            for(i=0;i<nfds;i++)
            {
                if(evs[i].data.fd==lst_fd)
                {
                    new_fd=accept(lst_fd,(struct sockaddr*)&cli_addr,&len);
                    if(new_fd<0)
                    {
                        perror("accept error");
                        continue;
                    }
                    printf("new connect,add to epoll!!\n");
                    ev.data.fd=new_fd;
                    ev.events=EPOLLIN;
                    epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&ev);
                }
                else if(evs[i].events & EPOLLIN){
                 char buff[1024] ={0} ;
                 ret=recv(evs[i].data.fd,buff,1023,0);
                 if(ret<=0)
                 {
                     epoll_ctl(epfd,EPOLL_CTL_ADD,evs[i].data.fd,&ev);
                     close(evs[i].data.fd);
                 }
                 printf("client say:%s\n",buff);
                 send(evs[i].data.fd,"what????",6,0);
                }
            }
        }
}
 
