#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[],char *envp [])
{
     char *val=getenv("SHELL"); 
     if(val !=NULL)
         printf("val=%s\n",val);

}

