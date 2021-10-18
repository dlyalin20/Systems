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
    student->next = NULL;

    return student;
}

void print_list(struct grades *node) {
    while (node != NULL) {
        print_grade(node);
        node = node->next;
    }
}

struct grades * insert_front(struct grades *front, char *n, int g) {
    struct grades *node = enter_grade(n, g);
    node->next = front;
    return node;
}

struct grades * free_list(struct grades *node) {
    struct grades *tmp;

    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }

    return node;
}

struct grades * remove_node(struct grades *front, int data) {
    if (front->grade == data) {
        return front->next;
    }
    struct grades *tmp = front;
    while (tmp->next) {
        if (tmp->next->grade == data) {
            tmp->next = tmp->next->next;
            return front;
        }
        else {
            tmp = tmp->next;
        }
    }
    return front;
}
