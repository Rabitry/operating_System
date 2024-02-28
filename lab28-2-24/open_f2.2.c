#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    int fileDescriptor =
        open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }
    char *dataToWrite = "Hello, this is some data.\n";
    ssize_t bytesWritten =
        write(fileDescriptor, dataToWrite, strlen(dataToWrite));

    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fileDescriptor);  
        return 1;
    }
    close(fileDescriptor);
    return 0;
}