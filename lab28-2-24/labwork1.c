#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
    char *pipe = "group11";
    int open_id = open(pipe, O_RDWR);

    char *msg = "Me : " ;
    char *msg2 = "MyFriend : " ;
    int global_counter = 0;
    while(1) {
            if(global_counter == 0) {
                char *msg = "User1 : " ;
                write(STDOUT_FILENO, msg, strlen(msg));
                char buffer[100];
                int n = read(STDOUT_FILENO, &buffer, sizeof(buffer));
                buffer[n]='\0';
                for(int i = 0; i < 100000; i++) {}

                write(open_id, buffer, strlen(buffer));
                for(int i = 0; i < 100000; i++) {}
            } else {
                char buffer[100];

                int read_after_write = read(open_id, &buffer, sizeof(buffer));
                buffer[read_after_write] = '\0';
                for(int i = 0; i < 100000; i++) {}
                
                write(STDOUT_FILENO, msg2, strlen(msg2));
                write(STDOUT_FILENO, buffer, strlen(buffer));
                for(int i = 0; i < 100000; i++) {}
                write(STDOUT_FILENO, msg, strlen(msg));
                int n = read(STDOUT_FILENO, &buffer, sizeof(buffer));
                buffer[n]='\0';
                for(int i = 0; i < 100000; i++) {}
                write(open_id, buffer, strlen(buffer));
                for(int i = 0; i < 100000; i++) {}
            }
            global_counter++ ;
    }

    close(open_id);
}