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

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("[e] could not open %s\n", argv[1]);
        return 1;
    }

    struct stockItem stock[MAXSTOCK] = {0};

    // TODO

    fclose(fin);
    return 0;
}
