#include "headers.h"

static void sighandler(int sig) {
    if (sig == SIGINT) {
        int file = open("log.txt", O_CREAT | O_WRONLY | O_APPEND);
        if (file == -1) {
            printf("Error: %s\n", strerror(errno));
        }
        char *message = "program exited due to SIGINT\n";
        int i;
        for (i = 0; message[i] != '\n'; i++) {
            ;
        }
        i++;
        write(file, message, i);
        exit(0);
    }
    else if (sig == SIGUSR1) {
        printf("ppid: %d\n", getppid());
    }
}

int main() {

    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while(1) {
        printf("%d\n", getpid());
        sleep(1);
    }

}