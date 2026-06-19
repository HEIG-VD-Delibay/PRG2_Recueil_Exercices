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

    if (argc != 3) {
        printf("Usage: %s importfile dbfile\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("[e] could not open %s\n", argv[1]);
        return 1;
    }

    // start importing

    struct stockItem stock[MAXSTOCK] = {0};
    int i = 0;
    while (fscanf(fin, "%s %s %f %d %f", stock[i].brand, stock[i].item, &(stock[i].unit), &(stock[i].qty), &(stock[i].total)) != EOF) {
        printf("importing %s,%s,%.2f,%d,%.2f\n", stock[i].brand, stock[i].item, stock[i].unit, stock[i].qty, stock[i].total);
        i++;
    }

    fclose(fin);

    // create/overwrite DB file

    FILE *fout = fopen(argv[2], "wb");
    if (!fout) {
        printf("[e] could not open %s\n", argv[2]);
        return 1;
    }

    // DB size as header

    if (fwrite(&i, sizeof i, 1, fout) != 1) {
        printf("[e] could not write size of stock to %s\n", argv[2]);
        return 1;
    }

    // DB rows

    if (fwrite(stock, sizeof stock[0], i, fout) != i) {
        printf("[e] could not write stock to %s\n", argv[2]);
        return 1;
    }

    fclose(fout);
    return 0;
}
