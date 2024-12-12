#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    struct addrinfo hints; //sert à réstreindre la recherche
    memset(&hints, 0, sizeof(hints)); // On met nul : pas de restriction;
    struct addrinfo *res; // Pour pas que ça prenne trop de place, et parce que on ne peut pas faire &&res, alors que la fonction veut un **res
    hints.ai_protocol = IPPROTO_TCP;
    getaddrinfo(argv[1], NULL, &hints, &res);
}