#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
    char *pipe = "group11";
    int open_id = open(pipe, O_RDWR);

    char *msg;
    char input[100];
    int n,c;
    msg="Insert a number :";
    write(STDOUT_FILENO,msg,strlen(msg)+1);
    n=read(STDOUT_FILENO,&input,sizeof(input));
    input[n]='\0';
    //write(STDOUT_FILENO,buffer,strlen(buffer));


    //char *msg = "hello arif. how are you";
    write(open_id, input, strlen(input));

    char buffer[100];
    int read_after_write = read(open_id, &buffer, sizeof(buffer));
    buffer[read_after_write] = '\0';

    printf("write into pipe is:%s\n", buffer);

    close(open_id);
}