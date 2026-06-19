#include <stdio.h>

#define MAXLEN 256

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("[e] could not open %s\n", argv[1]);
        return 1;
    }

    // start reading

    char brand[MAXLEN];
    char item[MAXLEN];
    float unit, total;
    int qty;

    while (fscanf(fin, "%s %s %f %d %f", brand, item, &unit, &qty, &total) != EOF)
        printf("reading %s,%s,%.2f,%d,%.2f\n", brand, item, unit, qty, total);

    fclose(fin);
    return 0;
}
