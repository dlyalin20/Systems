#include "parse.h"


char **parse_args( char *line ) {

    int i;
    int counter = 2;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == ' ') {
            counter++;
        }
    }
    
    char **arr = calloc(counter, sizeof(char *));

    char *tmp;

    counter = 0;

    while ((tmp = strsep(&line, " "))) {
        if (errno != 0) {
            printf("Error: %s\n", strerror(errno));
            exit(-1);
        }
        arr[counter] = tmp;
        counter++;
    }
    
    return arr;

}   
