#include "structs.h"

int main() {
    srand( time(NULL) );

    char s[] = TEST_NAME;

    // Struct generation test
    struct grades *test = enter_grade(s, rand());

    // Struct printing test
    print_grade(test);

}