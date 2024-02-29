#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
    char *pipe = "group11";
    int open_id = open(pipe, O_RDWR);

    char *input_txt = "Hello arif. how are you";
    write(open_id, input_txt, strlen(input_txt));

    char buffer[100];
    int read_after_write = read(open_id, &buffer, sizeof(buffer));
    buffer[read_after_write] = '\0';

    //printf("%s\n", buffer);
    write(STDOUT_FILENO,buffer,strlen(buffer)+1);
    printf("\n");

    close(open_id);
}