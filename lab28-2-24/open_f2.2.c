#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int n;
    char *msg = "Hello Everyone";
    //int fopenn = open("input.txt", O_RDONLY, 0644);
    int fopenn = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fopenn == -1) {
        printf("Error opening file");
        exit(-1);
    }
    else {
        n = write(fopenn, msg, strlen(msg));
        if (n == -1) {
            printf("Error writing into file\n");
            exit(-1);
        }
        printf("Write into file successfully\n");
        write(STDOUT_FILENO,msg,strlen(msg)+1);
        printf("\n");

        close(fopenn);
    }

    return 0;
}

// #include <fcntl.h>
// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// int main() {
//     int n;
//     char buffer[100];
//     int fopenn = open("input.txt", O_RDONLY);
//     if (fopenn == -1) {
//         printf("Error opening file");
//         exit(-1);
//     }
//     n = read(fopenn, buffer, sizeof(buffer));
//     //buffer[n]='\0';
//     if (n == -1) {
//         printf("Error reading from file\n");
//         exit(-1);
//     }
//     close(fopenn);
//     write(STDOUT_FILENO, buffer, n);

//     return 0;
// }
