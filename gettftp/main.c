#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netdb.h>
#include<sys/socket.h>
#include"fonctions.h"
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

    int addrinfo = getaddrinfo(server_ip, server_port, &hints, &res);

    char request[BUFFSIZE];
    int lenght_read_request = build_request(file_name,request);
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    sendto(sock, request, lenght_read_request, 0, res->ai_addr, res->ai_addrlen);
}