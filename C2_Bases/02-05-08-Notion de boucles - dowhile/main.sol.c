#include <stdio.h>

int main() {
    int age;
    do {
        printf("Entrez votre âge: ");
        scanf("%d", &age);
    } while (age < 18);
    printf("Accès accordé.\n");
    return 0;
}
