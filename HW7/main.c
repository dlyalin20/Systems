#include "arrays.h"
#define LEN 10

int main() {

    int ray1[10];
    int ray2[10];
    int i;
    srand( time(NULL) );
    for (i  = 0; i < LEN; i++) {
        ray1[i] = rand();
        ray2[i] = rand();
    }
    print_array(ray1, LEN);
    print_array(ray2, LEN);
    printf("Average of Array: %f \n\n", avg(ray1, LEN));
    copy(ray1, ray2, LEN);
    print_array(ray2, LEN);
}