#ifndef MY_STRUCT
#define MY_STRUCT "defined"
#define TEST_NAME "Daniel"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Struct declarations
struct grades {char *name; int grade; };

// Function declarations
struct grades * enter_grade(char *n, int g);
void print_grade(struct grades *student);

#endif