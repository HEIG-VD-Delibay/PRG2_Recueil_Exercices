#include <stdio.h>

int main() {
    // Initialisation de la structure Value avec différents types de données
    struct Value int_val = make_value(10);
    struct Value float_val = make_value(3.14f);
    struct Value string_val = make_value("Hello, world!");

    show_value(&int_val);
    show_value(&float_val);
    show_value(&string_val);

    return 0;
}
