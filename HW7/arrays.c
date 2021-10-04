#include "arrays.h"

// Solution to 1

int print_array(int arr[], int size) {
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        if (i == size-1) {
            printf("%d]\n\n", arr[i]);
        }
        else {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

// Solution to 2
float avg(int arr[], int size) {
    int i;
    long sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Solution to 3
int copy(int arr1[], int arr2[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
    return 0;
}