#include "parse.h"

int main() {
    
    char line[] = "ls -l -a";

    char **args = parse_args(line);

    int status = execvp(args[0], args);
    if (status == -1) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}