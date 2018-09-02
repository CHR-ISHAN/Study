#include "dlink.h"
typedef struct dlink dlink_t;
struct link {
    dlink_t *prev;
    dlink_t *next;
    void *data;
}dlink;
//初始化
void dlink_init(dlink_t **phead)
{
    dlink_t *p=  malloc (sizeof(dlink_t));
    p->next=p;
    p->prev=p;
    *phead=p;
}
//插入
void dlink_insert(dlink_t *head,void *data);
//显示
void dlink_show(dlink_t *head);
//删除
void dlink_erase(dlink_t *head,void *data);
//销毁
void dlink_destory(dlink_t **head);
