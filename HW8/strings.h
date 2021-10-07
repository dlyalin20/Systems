#ifndef MY_STRINGS
#define MY_STRINGS "defined"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int string_test();
int mystrlen( char *s );
char * mystrcpy( char *dest, char *source );
char * mystrncat( char *dest, char *source, int n);
int mystrcmp( char *s1, char *s2 );
char * mystrchr( char *s, char c );

#endif
