#ifndef HEADERS
#define HEADERS "defined"

// std includes
#include <ctype.h>
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

//
#define maxlen 100

// function declarations
int main();
int count_vowels(char *buffer);

#endif