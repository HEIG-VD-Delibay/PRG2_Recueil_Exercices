
#include <stdio.h>

int main() {
    char op;
    float num1, num2, resultat = 0.0f;

    /* Saisir les données d'entrée */
    printf("Saisir une operation [Num 1] [+ - * /] [Num 2]\n");
    scanf("%f %c %f", &num1, &op, &num2);

    switch (op) {
        case '+':
            resultat = num1 + num2;
            break;

        case '-':
            resultat = num1 - num2;
            break;

        case '*':
            resultat = num1 * num2;
            break;

        case '/':
            resultat = num1 / num2;
            break;

        default:
            printf("Operation mal formee ou inconnue!");
            return -1;
    }

    /* afficher le résultat */
    printf("%.2f %c %.2f = %.2f", num1, op, num2, resultat);

    return 0;
}
