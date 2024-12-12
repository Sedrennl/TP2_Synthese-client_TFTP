#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netdb.h>
#include<sys/socket.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s  <Server ip address> <Port> <File_name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *server_ip = argv[1];
    char *server_port = argv[2];
    char *file_name = argv[3];



    struct addrinfo hints; //sert à restreindre la recherche
    memset(&hints, 0, sizeof(hints)); // On met nul : pas de restriction;
    struct addrinfo *res; // Résultats de la recherche,  permet les listes chaînées

    //paramètrage du hints
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int addrinfo = getaddrinfo(argv[1], NULL, &hints, &res);

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
}
