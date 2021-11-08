#ifndef MY_CSV
#define MY_CSV "defined"

// std includes
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

// custom functions
void add_data();
void read_csv();
void read_data();
void update_data();

// custom structs
struct pop_entry {
  int year;
  int population;
  char boro[15];
};

#endif