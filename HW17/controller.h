// std includes
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>

// key def
#define KEY ftok("controller.c", 17)
#define maxlen 1024

// function declarations
int create();
int delete();
int main(int argc, char *argv[]);