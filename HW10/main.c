#include "structs.h"

int main() {
    srand( time(NULL) );

    // char s[] = TEST_NAME;

    // List Generation Test
    struct grades *front = enter_grade("Daniel", rand());
    struct grades *f2 = insert_front(front, "Dexter", rand());
    struct grades *f3 = insert_front(f2, "D", rand());

    // List Printint Test
    print_list(f3);

    // List Freeing Test
    print_list(free_list(f3));

    // Struct printing test
    // print_grade(test);

    // free(test);

}