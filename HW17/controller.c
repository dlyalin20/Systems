#include "controller.h"

void error_handler(int val) {
    if (val == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(errno);
    }
}

int create() {
    // creating file
        int fd = open("lines.txt", O_CREAT);
        error_handler(fd);
        printf("File created successfully!\n");

        // creating semaphore
        int semd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
        error_handler(semd);
        union semun us;
        us.val = 1;
        int r = semctl(semd, 0, SETVAL, us);
        error_handler(r);
        printf("Semaphore successfully created!\n");

        // creating shared memory
        int shmd = shmget(KEY, sizeof(int), IPC_CREAT | 0600);
        error_handler(shmd);
        int *data = shmat(shmd, 0, 0);
        error_handler(*data);
        (*data) = 0;
        printf("Created shared memory segment!\n");

        return 0;
}

int delete() {
        // deleting semaphore
        int semd = semget(KEY, 1, 0);
        error_handler(semd);
        int r = semctl(semd, IPC_RMID, 0);
        error_handler(r);
        printf("Semaphore deleted\n");

        // deleting shared memory segment
        int shmd = shmget(KEY, 0, 0);
        error_handler(shmd);
        r = shmctl(shmd, IPC_RMID, 0);
        error_handler(r);
        printf("Shared memory segment deleted\n");

        // printing and deleting file
        FILE *fd = fopen("lines.txt", "r");
        char *buffer = calloc(maxlen, sizeof(char));
        printf("Story: \n");
        while (fgets(buffer, maxlen, fd)) {
            printf("%s\n", buffer);
        }
        remove("lines.txt");
        printf("File removed\n");

        return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Program takes one of two arguments: -c to create, -r to remove\n");
        return -1;
    }
    if (!strcmp(argv[1], "-c")) {
        return create();
    }
    else if (!strcmp(argv[1], "-r")) {
        return delete();
    }
    else {
        printf("Program takes one of two arguments: -c to create, -r to remove\n");
        return -1;
    }
}