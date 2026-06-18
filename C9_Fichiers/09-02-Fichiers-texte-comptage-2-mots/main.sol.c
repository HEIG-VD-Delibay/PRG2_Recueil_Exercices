#include <stdbool.h>
#include <stdio.h>

int countc(FILE *f) {
    int cpt = 0;

    while (fgetc(f) != EOF)
        cpt++;

    return cpt;
}

int countm(FILE *f) {
    int c;
    int cpt = 0;
    int curw = false;

    while ((c = fgetc(f)) != EOF)
        if (c == ' ' || c == '\n')
            curw = false;
        else if (!curw) {
            curw = true;
            cpt++;
        }

    return cpt;
}


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

    // count characters in file
    printf("%s contains %d characters\n", argv[1], countc(fin));

    // reopen file
    fin = freopen(argv[1], "r", fin);
    printf("%s contains %d words\n", argv[1], countm(fin));

    fclose(fin);
    return 0;
}
