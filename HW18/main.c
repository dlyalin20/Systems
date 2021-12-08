#include "main.h"

int main() {

    int parent_read[2];
    int child_read[2];
    int p;

    p = pipe(parent_read);
    if (p) {
        printf("Error: %s\n", strerror(errno));
        return errno;
    }
    p = pipe(child_read);
    if (p) {
        printf("Error: %s\n", strerror(errno));
        return errno;
    }

    int f = fork();
    while (1) {
        // child process
        if (f) {
            close(parent_read[READ]);
            close(child_read[WRITE]);
            char *buffer = calloc(maxlen, sizeof(char));
            read(child_read[READ], buffer, maxlen);
            int counter = 0, i; 
            for (i = 0; i < strlen(buffer); i++) {
                if (tolower(buffer[i]) == 'a' ||
                    tolower(buffer[i]) == 'e' ||
                    tolower(buffer[i]) == 'i' ||
                    tolower(buffer[i]) == 'o' ||
                    tolower(buffer[i]) == 'u') {
                        counter++;
                    }
            }
            write(parent_read[WRITE], &counter, sizeof(int));
        }
        // parent process
        else {
            close(parent_read[WRITE]);
            close(child_read[READ]);
            char *buffer = calloc(maxlen, sizeof(char));
            printf("Please input string to process, max length %d: ", maxlen);
            fgets(buffer, maxlen, stdin);
            write(child_read[WRITE], buffer, maxlen);
            int counter;
            read(parent_read[READ], &counter, sizeof(int));
            printf("Number Vowels: %d\n", counter);
        }
    }
    

}