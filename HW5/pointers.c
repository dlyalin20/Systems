#include<stdio.h>

int main() {

    char c = 'c';
    int i = 65;
    long l = 18;

    printf("Char Hexadecimal Address: %p \t Char Decimal Address: %lu \n", &c, &c);
    printf("Int Hexadecimal Address: %p \t Int Decimal Address: %lu \n", &i, &i);
    printf("Long Hexadecimal Address: %p \t Long Decimal Address: %lu \n", &l, &l);
    
    char *pc = &c;
    int *pi = &i;
    long *pl = &l;

    printf("Char Pointer: %p \t Int Pointer: %p \t Long Pointer: %p \n", pc, pi, pl);

    *pc = 'd';
    *pi += 1;
    *pl += 1;

    printf("New Char: %c \t New Int: %i \t New Long: %lu \n", c, i, l);

    unsigned int ui = 102;
    unsigned int *pui = &ui;
    char *cpui = &ui;

    printf("pui: %p \t pui points to: %u \n", pui, *pui);
    printf("cpui: %p \t cpui points to: %u \n", cpui, *cpui);

    printf("Unsigned Int in Decimal: %u \t Unsigned Int in Hexadecimal: %x \n", ui, ui);

    int counter;
    for (counter = 0; counter < sizeof(ui); counter++) {
        cpui = *( ((char *) pui) + counter);
        printf("Byte %i: %hhu \n", counter, cpui);
    }

    for (counter = 0; counter < sizeof(ui); counter++) {
        *( ((char *) pui) + counter) += 1;
        printf("Unsigned Int: %u \t Unsigned Int Hexadecimal: %x \n", ui, ui);
    }
    for (counter = 0; counter < sizeof(ui); counter++) {
        cpui = *( ((char *) pui) + counter);
        printf("Byte %d: %hhu \n", counter, cpui);
    }

    ui = 102;
    pui = &ui;
    for (counter = 0; counter < sizeof(ui); counter++) {
        *( ((char *) pui) + counter) += 16;
        printf("Unsigned Int: %u \t Unsigned Int Hexadecimal: %x \n", ui, ui);
    }
    for (counter = 0; counter < sizeof(ui); counter++) {
        cpui = *( ((char *) pui) + counter);
        printf("Byte %d: %hhu \n", counter, cpui);
    }
}