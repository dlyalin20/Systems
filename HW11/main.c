#include "random.h"

int main() {

    int *data = generate_random(NUM);
    int counter;
    printf("Original Array: \n");
    for (counter = 0; counter < NUM; counter++){
        printf("%d: %d\n", counter, data[counter]);
    }
    printf("\n");

    int file = open("f1.txt", O_CREAT | O_WRONLY, 0777);
    printf("Error Code for f1: %d\n", file);
    write(file, data, NUM * sizeof(int));

    int *cpy = calloc(NUM, sizeof(int));
    file = open("f1.txt", O_RDONLY, 0777);
    printf("Second Error Code for f1: %d\n", file);
    read(file, cpy, 10 * sizeof(int));
    printf("Copy of Array: \n");
    for (counter = 0; counter < NUM; counter ++){
        printf("%d: %d\n", counter, cpy[counter]);
    }

    return 0;
}