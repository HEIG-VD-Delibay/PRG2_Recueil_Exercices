#include <stdio.h>

int main() {
    int nombre, somme = 0;

    printf("Entrez des nombres pour additionner (0 pour terminer): \n");
    scanf("%d", &nombre);

    while (nombre != 0) {
        somme += nombre;
        scanf("%d", &nombre);
    }

    printf("La somme des nombres est: %d\n", somme);

    return 0;
}
