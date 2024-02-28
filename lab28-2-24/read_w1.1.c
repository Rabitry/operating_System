#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char *msg;
    char buffer[100];
    int n,c;
    msg="Insert a number :";
    write(STDOUT_FILENO,msg,strlen(msg)+1);
    n=read(STDOUT_FILENO,&buffer,sizeof(buffer));
    buffer[n]='\0';
    write(STDOUT_FILENO,buffer,strlen(buffer));

    return 0;

}