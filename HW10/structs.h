#ifndef MY_STRUCT
#define MY_STRUCT "defined"
#define TEST_NAME "Daniel"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Struct declarations
struct grades {char *name; int grade; struct grades *next; };

// Function declarations
struct grades * insert_front(struct grades *front, char *n, int g);
struct grades * remove_node(struct grades *front, int data);
struct grades * free_list(struct grades *node);
struct grades * enter_grade(char *n, int g);
void print_grade(struct grades *student);
void print_list(struct grades *node);

#endif