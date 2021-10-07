#include "strings.h"

// Solution to returning the size of a string
int mystrlen( char *s ) {
    int counter = 0;
    while (*s) {
        counter++;
        s++;
    }
    return counter;
}

// Solution to copying one string into another
char * mystrcpy( char *dest, char *source ) {
    int counter = 0;
    while (*source) {
        *dest = *source;
        source++;
        dest++;
        counter++;
    }
    *dest = '\0';
    dest -= counter;
    return dest;
}

// Solution to concatenating variable part of a string into another string // FIX
char * mystrncat( char *dest, char *source, int n) {
    int counter = 0;
    while (*dest) {
        dest++;
        counter++;
    }
    while (n && *source) {
        *dest = *source;
        source++;
        counter++;
        dest++;
        n--;
    }
    dest -= counter;
    return dest;
}

// Solution to comparing two strings
int mystrcmp( char *s1, char *s2 ) {

    while (*s1 || *s2) {
        if (*s1 == '\0') {
            return -1;
        }
        if (*s2 == '\0') {
            return 1;
        }
        if (*s1 != *s2) {
            if (*s1 < *s2) {
                return -1;
            }
            else {
                return 1;
            }
        }
        s1++;
        s2++;
    }
    return 0;

}

// Solution to finding character in a string
char * mystrchr( char *s, char c ) {
    while (*(s++)) {
        if (*s == c) {
            return s;
        }
    }
    return NULL;
}