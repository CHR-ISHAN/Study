#include<stdio.h>
#include<unistd.h>
int main(void)
{
    printf("hahahha\n");
    char *argv[]={
	"ls",
	    NULL
    };
    execvp("pwd",argv);
    printf("heheheh\n");
}
