#include "interface.h"

int main() {

    mkfifo("mario", 0644);
    mkfifo("luigi", 0644);

    int mario = open("mario", O_WRONLY);
    int luigi = open("luigi", O_RDONLY);

    while (1) {
        char *buffer = calloc(maxlen, sizeof(char));
        printf("Input, max length %d: ", maxlen);
        fgets(buffer, maxlen, stdin);
        
        write(mario, buffer, maxlen);
        int counter;
        read(luigi, &counter, sizeof(int));
        printf("Number of vowels: %d\n", counter);
    }

    return 0;

}