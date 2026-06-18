#include <stdio.h>

// *** TODO: counting functions

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *fin;

    // *** TODO: open file

    // count characters in file

    printf("%s contains %d characters\n", argv[1], countc(fin));

    fclose(fin);
    return 0;
}
