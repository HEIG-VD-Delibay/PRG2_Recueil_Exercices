#include <stdio.h>

int main() {
    int nb;

    /* Fournir les données d'entrée */
    printf("Saisir un nombre: ");
    scanf("%d", &nb);

    if ((nb % 3 == 0) && (nb % 13 == 0)) {
        printf("%d est divisible par 3 et 13", nb);
    } else {
        printf("%d n'est pas divisible par 3 et 13", nb);
    }

    return 0;
}
