#include<stdio.h>
#include"add.h"
#include"sub.h"
#include"mul.h"
int main(void)
{
    int a=19;
    int b=3;
    printf("%d+%d=%d\n",a,b,add(a,b));
    printf("%d-%d=%d\n",a,b,sub(a,b));
    printf("%d*%d=%d\n",a,b,mul(a,b));
}
