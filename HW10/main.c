#include "structs.h"

int main() {
    srand( time(NULL) );

    // char s[] = TEST_NAME;

    // List Generation Test
    struct grades *front = NULL;
    front = insert_front(front, "Daniel", rand());
    front = insert_front(front, "Dexter", rand());
    front = insert_front(front, "D", 5);

    // List Printint Test
    printf("Printing list: \n");
    print_list(front);
    printf("\n");

    // Test removing from list
    front = remove_node(front, 5);
    printf("Having removed D from list: \n");
    print_list(front);
    printf("\n");

    // List Freeing Test
    front = free_list(front);
    printf("Empty List: \n");
    print_list(front);
    printf("\n");

    // Struct printing test
    // print_grade(test);

    // free(test);

}