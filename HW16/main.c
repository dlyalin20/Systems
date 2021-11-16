#include "headers.h"

int main() {
    
    printf("Forking first time\n");

    int f = fork();

    // parent process
    if (f) {
        printf("Forking second time\n");
        int f2 = fork();
        // parent
        if (f2) {
            int status;
            wait(&status);
            int return_val = WEXITSTATUS(status);
            printf("Completed Child PID: %d\tAsleep for %d seconds\n", status, return_val);
            printf("Parent Completed \n");
            exit(0);
        }
        // child
        else {
            printf("pid: %d\n", getpid());
            srand( time(NULL) );
            int r = rand() % (5 + 1 - 2) + 2;
            sleep(r);
            printf("Finished sleeping\n");
            return r;
        }
    }
    // child process
    else {
        printf("pid: %d\n", getpid());
        srand( time(NULL) );
        int r = rand() % (5 + 1 - 2) + 2;
        sleep(r);
        printf("Finished sleeping\n");
        return r;
    }
 

}