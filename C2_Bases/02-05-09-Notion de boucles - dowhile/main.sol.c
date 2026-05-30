#include <stdio.h>

int main() {
    int nombre, inverse = 0;

    printf("Entrez un nombre pour inverser ses chiffres: ");
    scanf("%d", &nombre);
    do {
        inverse = inverse * 10 + nombre % 10;
        nombre /= 10;
    } while (nombre > 0);

    printf("Le nombre inversé est: %d\n", inverse);

    return 0;
}
