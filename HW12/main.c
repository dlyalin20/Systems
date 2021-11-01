#include "headers.h"

int main() {

    DIR *d;
    struct dirent *dent;
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

}