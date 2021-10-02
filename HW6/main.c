#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int ray1[10];
    ray1[0] = 0;
    printf("0 Value of Ray1: %i \n", 0);
    srand( time(NULL) );
    int counter;
    for (counter = 1; counter < 10; counter++) {
        ray1[counter] = (int) rand();
        printf("%i Value of Ray1: %i \n", counter, ray1[counter]);
    }
    printf("\n");

    int ray2[10];

    int *p1 = ray1;
    int *p2 = ray2;

    // Works perfectly except for first element of ray1, which is transformed to 1 in ray2
    for (counter = 9; counter > 0; counter--) {
       *(p2 + (9 - counter)) = *(p1 + counter);
    }
    for (counter = 0; counter < 10; counter++) {
        printf("%i Value of Ray2 Using Pointers: %i \n", counter, ray2[counter]);
        ray2[counter] = 0;
        ray2[counter] = ray1[9 - counter];
    }
    printf("\n");

    // Works without transforming 0 to 1
    for (counter = 0; counter < 10; counter++) {
        printf("%i Value of Ray2 Using Brackets: %i \n", counter, ray2[counter]);
    }

    return 0;

}