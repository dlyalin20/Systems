#include "random.h"

int * generate_random(int num) {
    int file = open("/dev/urandom", O_RDONLY);
    printf("Error Code for /dev/random: %d\n", file);
    int *data = calloc(num, sizeof(int));
    read(file, data, sizeof(int) *num);
    return data;
}