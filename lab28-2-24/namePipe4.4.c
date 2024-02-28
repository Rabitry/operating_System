#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
    char *pipePath;
    int pipeFlag,fd;
    pipePath="/home/rabitry/op_s/group11";
    if(access(pipePath,F_OK)==0){
         printf("%s is already created, so new pipe will not be created\n",pipePath);
    }
    else{
        pipeFlag=mkfifo(pipePath,0666);
        if(pipeFlag<0){
            printf("Error in created a named pipe\n");
            exit(-1);
        }
        else{
            printf("pipe has been created successfully\n");
        }
    }

    

}