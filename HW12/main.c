#include "headers.h"

int main(int argc, char *argv[]) {

    DIR *d;
    struct dirent *dent;

    if (argc > 1) {
        d = opendir(argv[1]);
        if (errno != 0) {
            printf("Error: %s\n", strerror(errno));
            return 0;
        }
    }
    else {
        char buffer[100];
        printf("Please input directory path: \n");
        read(STDIN_FILENO, buffer, sizeof(buffer));
        d = opendir(argv[1]);
        if (errno != 0) {
            printf("Error: %s]\n", strerror(errno));
            return 0;
        }
    }

    d = opendir("./");
    unsigned long size = 0;

    printf("Statistics for directory: ./\n");
    while ((dent = readdir(d)) != NULL) {
        struct stat sb;
        stat(dent, &sb);
        if (dent->d_type == DT_DIR) {
            printf("%s (directory)\n", dent->d_name);
        }
        else {
            printf("%s\n", dent->d_name);
        }
        size += sb.st_size;
    }
    printf("Total Directory Size: %lu Bytes\n", size);

    return 0;
}