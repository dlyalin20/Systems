#include "csv.h"

// reads csv file into data file
void read_csv() {
    int csv = open("./nyc_pop.csv", O_RDONLY);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    struct stat mystat;
    stat("./nyc_pop.csv", &mystat);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    
    char *buffer = calloc(1, mystat.st_size);
    read(csv, buffer, mystat.st_size);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    char *cp = buffer;
    
    char *target = strchr(cp, '\n');
    
    int counter = 0;
    int lines = 0;
    for (counter = 0; buffer[counter] != '\0'; counter++) {
        if (buffer[counter] == '\n') {
            lines++;
        }
    }
    struct pop_entry data[lines * 5];
    
    lines = 0;
    int year;
    struct pop_entry m;
    strcpy(m.boro, "Manhattan");
    struct pop_entry bk;
    strcpy(bk.boro, "Brooklyn");
    struct pop_entry q;
    strcpy(q.boro, "Queens");
    struct pop_entry bx;
    strcpy(bx.boro, "Bronx");
    struct pop_entry si;
    strcpy(si.boro, "Staten Island");
    while (target != NULL && *target != '\0') {
        lines++;
        *target = '\0';
        if (lines > 1) {
            sscanf(cp, "%d,%d,%d,%d,%d,%d", &year, &m.population, &bk.population, &q.population, &bx.population, &si.population);
            m.year = year;
            bk.year = year;
            q.year = year;
            bx.year = year;
            si.year = year;
            data[(lines - 2) * 5] = m;
            data[((lines - 2) * 5) + 1] = bk;
            data[((lines - 2) * 5) + 2] = q;
            data[((lines - 2) * 5) + 3] = bx;
            data[((lines - 2) * 5) + 4] = si;
        }
        cp = target + 1;
        target = strchr(cp, '\n');
    }
    lines++;
    sscanf(cp, "%d,%d,%d,%d,%d,%d\n", &year, &m.population, &bk.population, &q.population, &bx.population, &si.population);
    m.year = year;
    bk.year = year;
    q.year = year;
    bx.year = year;
    si.year = year;
    data[(lines - 2) * 5] = m;
    data[((lines - 2) * 5) + 1] = bk;
    data[((lines - 2) * 5) + 2] = q;
    data[((lines - 2) * 5) + 3] = bx;
    data[((lines - 2) * 5) + 4] = si;
    
    int file = open("./nyc_pop.data", O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    write(file, data, sizeof(data));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    printf("Wrote %lu bytes to datafile\n", sizeof(data));
}

// Reads and prints out the datafile
void read_data() {
    int file = open("./nyc_pop.data", O_RDONLY);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    struct stat mystat;
    stat("./nyc_pop.data", &mystat);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    
    struct pop_entry *data = calloc(1, mystat.st_size);
    
    read(file, data, mystat.st_size);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    int i;
    for (i = 0; i * sizeof(struct pop_entry) < mystat.st_size; i++) {
        printf("%d: Year: %d\tBorough: %s\tPopulation: %d\n", i, data[i].year, data[i].boro, data[i].population);
    }
}

void add_data() {
    char buffer[100];
    printf("Enter data to add in format: year,population,Borough\n");
    read(STDIN_FILENO, buffer, sizeof(buffer));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    struct pop_entry data;
    sscanf(buffer, "%d,%d,%s\n", &data.year, &data.population, data.boro);
    int file = open("./nyc_pop.data", O_WRONLY | O_APPEND);
    
    write(file, &data, sizeof(data));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
    }
    printf("Appended %lu bytes of data to file: year: %d\tboro: %s\tpop: %d\n", sizeof(data), data.year, data.boro, data.population);
}

// Updates data
void update_data() {
    read_data();
    
    int file = open("./nyc_pop.data", O_RDWR);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    struct stat mystat;
    stat("./nyc_pop.data", &mystat);
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    
    char buffer[100];
    printf("Entry number to update: \n");
    read(STDIN_FILENO, buffer, sizeof(buffer));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
    }
    int target = atoi(buffer) + 5;
    printf("Enter data in format: year,population,Borough: \n");
    read(STDIN_FILENO, buffer, sizeof(buffer));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
    }
    struct pop_entry data;
    sscanf(buffer, "%d,%d,%s\n", &data.year, &data.population, data.boro);
    lseek(file, target * sizeof(struct pop_entry), SEEK_SET);
    write(file, &data, sizeof(data));
    if (errno != 0) {
        printf("Error: %s\n", strerror(errno));
        return;
    }
}