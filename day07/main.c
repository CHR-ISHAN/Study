#include "dlink.h"
typedef struct stu{
    int id;
    char name[32];
}stu_t;
void myprint(void *data)
{
    stu_t *p =data;
    printf("id=%d,name=%s",p->id,p->name);
}
int main()
{
    dlink_t *head =NULL;
    dlink_init(&head);
    stu_t s1={1,"1"};
    stu_t s2={2,"2"};
    stu_t s3={3,"3"};
    dlink_insert(head,(void * )&s1); 
    dlink_insert(head,(void * )&s2);
    dlink_insert(head,(void * )&s3);
    return 0;
}
