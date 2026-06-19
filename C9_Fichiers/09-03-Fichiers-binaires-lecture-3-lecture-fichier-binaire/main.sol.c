#include <stdio.h>

#define MAXLEN 256
#define MAXSTOCK 80

struct stockItem {
    char brand[MAXLEN];
    char item[MAXLEN];
    int qty;
    float unit, total;
};

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s dbfile\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (!fin) {
        printf("[e] could not open %s\n", argv[1]);
        return 1;
    }

    // load DB into memory

    struct stockItem stock[MAXSTOCK] = {0};
    int n = 0;

    // get DB size (number of rows)

    if (fread(&n, sizeof n, 1, fin) != 1) {
        printf("[e] error trying to read db size\n");
        return 1;
    }

    // get DB rows

    if (fread(stock, sizeof stock[0], n, fin) != n) {
        printf("[e] error trying to read %d db contents\n", n);
        return 1;
    }

    // display DB contents

    printf("[i] The stock contains %d products:\n", n);
    for (int i = 0; i < n; i++) {
        printf("[i] - row %d: ", i);
        printf("[%s],[%s],", stock[i].brand, stock[i].item);
        printf("[%.2f],[%d],[%.2f]\n", stock[i].unit, stock[i].qty, stock[i].total);
    }

    fclose(fin);
    return 0;
}
