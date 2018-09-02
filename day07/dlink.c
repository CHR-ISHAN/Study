#include<stdio.h>
#include<stdlib.h>
#include"dlink.h"
//初始化
void dlink_init(dlink_t **phead)
{
    dlink_t *p=  malloc (sizeof(dlink_t));
    p->next=p;
    p->prev=p;
    *phead=p;
}
//插入
void dlink_insert(dlink_t *head,void *data)
{

    dlink_t *p=malloc(sizeof(dlink_t));
    menset(p,0x00,sizeof(dlink_t));
    p->data=data;
    p->prev=head->prev;
    p->next=head;
    head->prev->next=p;
    head->prev=p;
}
//显示
void dlink_show(dlink_t *head)
{
    dlink_t *cur=head->next;
    while(cur!=head){
        p
    }
}
//删除
void dlink_erase(dlink_t *head,void *data)
{

}
//销毁
void dlink_destory(dlink_t **head)
{

}
