#include <stdio.h>

todo init_packet;
todo print_packet;
todo set_packet_typerint_packet;
todo set_packet_status;

int main() {
    struct Packet my_packet;

    init_packet(&my_packet, 1234, 3, 1, 512);

    printf("Informations du paquet initial :\n");
    print_packet(my_packet);

    set_packet_type(&my_packet, 2);
    printf("\nType modifié :\n");

    print_packet(my_packet);

    set_packet_status(&my_packet, 0);
    printf("\nStatut modifié :\n");

    print_packet(my_packet);

    printf("\nTaille du paquet : %zu octets\n", sizeof(my_packet));

    return 0;
}
