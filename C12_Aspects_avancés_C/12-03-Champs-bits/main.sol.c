#include <stdio.h>

struct Packet {
    unsigned int sequence_number : 16;
    unsigned int packet_type : 4;
    unsigned int packet_status : 2;
    unsigned int data_length : 10;
};

void init_packet(struct Packet *packet, unsigned int seq_num, unsigned int type, unsigned int status, unsigned int length) {
    packet->sequence_number = seq_num;
    packet->packet_type = type;
    packet->packet_status = status;
    packet->data_length = length;
}

void print_packet(struct Packet packet) {
    printf("Numéro de séquence : %u\n", packet.sequence_number);
    printf("Type de paquet : %u\n", packet.packet_type);
    printf("Statut du paquet : %u\n", packet.packet_status);
    printf("Longueur des données : %u\n", packet.data_length);
}

void set_packet_type(struct Packet *packet, unsigned int type) {
    packet->packet_type = type;
}

void set_packet_status(struct Packet *packet, unsigned int status) {
    packet->packet_status = status;
}

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
