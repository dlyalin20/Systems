#include "structs.h"

// Prints struct
void print_grade(struct grades *student) {
    printf("%s's Grade: %d\n", student->name, student->grade);
}

// Creates struct
struct grades * enter_grade(char *n, int g) {
    struct grades *student = calloc(1, sizeof(struct grades));

    student->name = strdup(n);
    student->grade = g;

    return student;
}