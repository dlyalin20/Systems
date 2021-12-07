#include "user.h"

void error_handler(int val) {
    if (val == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(errno);
    }
}

int main() {
    // asking semaphore for access
    int semd = semget(KEY, 1, 0);
    error_handler(semd);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1;
    semop(semd, &sb, 1);

    // getting line length
    int shmd = shmget(KEY, 0, 0);
    error_handler(shmd);
    int *data = shmat(shmd, 0, 0);
    error_handler(*data);

    // opening file
    int fd = open("lines.txt", O_RDWR | O_APPEND);
    error_handler(fd);
    lseek(fd, -(*data), SEEK_END);
    char *buffer = calloc(maxlen, sizeof(char));
    read(fd, buffer, maxlen);
    printf("Current line: %s\n", buffer);
    printf("Input new line, max length %d chars: ", maxlen);
    fgets(buffer, maxlen, stdin);
    lseek(fd, 0, SEEK_END);
    write(fd, buffer, strlen(buffer));
    *data = strlen(buffer);
    printf("Wrote to file!\n");

    // detaching data
    shmdt(data);
    sb.sem_op = 1;
    semop(semd, &sb, 1);

    return 0;
}