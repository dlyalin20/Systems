#include "worker.h"

int count_vowels(char *buffer) {
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
    return counter;
}

int main() {

    int mario = open("mario", O_RDONLY);
    int luigi = open("luigi", O_WRONLY);

    while (1) {

        char *buffer = calloc(maxlen, sizeof(char));
        read(mario, buffer, maxlen);

        int counter = count_vowels(buffer);
        write(luigi, &counter, sizeof(int));

    }

    return 0;

}