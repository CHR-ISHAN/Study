#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char yy[50];
    char hy[50];
    char cx[6];
} DICT_T;
DICT_T word [8000];
int cunt = 0;
void load_file(void)
{
    FILE *fp = fopen("dictionary.txt","r");
    if(fp==NULL) perror("fopen"),exit(1);
    while(!feof(fp)){
        fscanf(fp,"%s\t%s\t%s",word[cunt].yy,word[cunt].hy,
                word[cunt].cx);
        cunt++;
    }
    fclose(fp);
}
int bin_search(const char *buf)
{
    int l=0;
    int r=cunt-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(strcmp(word[m].yy,buf)<0){
        l=m+1;
        }
        else if(strcmp(word[m].yy,buf)==0){
            return m;
        }
        else{
            r=m-1;
        }
    }
    return -1;
}
int main(void)
{
    load_file();
    int r;
    char buf[100];
    do{
        printf("请输入单词:");
        memset(buf,0x00,sizeof buf);
        scanf("%s",buf);
        if((r=bin_search(buf))==-1){
            printf("没有这个单词\n");
        }else {
            printf("%s:%s %s\n",word[r].yy,word[r].hy,word[r].cx);
        }
    }while(1);
}
