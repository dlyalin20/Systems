#include "csv.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Too few arguments; Please use one or more of following: read_csv read_data add_data update_data\n");
        return -1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "read_csv") == 0) {
            read_csv();
        } 
        else if (strcmp(argv[i], "read_data") == 0) {
            read_data();
        }
        else if (strcmp(argv[i], "add_data") == 0) {
            add_data();
        }
        else if (strcmp(argv[i], "update_data") == 0) {
            update_data();
        }
        else {
            printf("No such argument. Please use one or more of following: read_csv read_data add_data update_data\n");
            return -1;
        }
    }
    
    return 0;

}