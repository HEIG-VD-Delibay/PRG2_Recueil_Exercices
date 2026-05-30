#include <stdio.h>

int main() {
    int nombre, max;

    printf("Entrez des nombres pour trouver le maximum (-1 pour terminer): \n");
    scanf("%d", &nombre);

    max = nombre;
    while (nombre != -1) {
        if (nombre > max) {
            max = nombre;
        }
        scanf("%d", &nombre);
    }

    printf("Le plus grand nombre est: %d\n", max);

    return 0;
}
