#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netdb.h>
#include<sys/socket.h>
#include <fcntl.h>
#include"fonctions.h"
#include <unistd.h>
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

    struct sockaddr server;

    struct addrinfo hints; //sert à restreindre la recherche
    memset(&hints, 0, sizeof(hints)); // On met nul : pas de restriction;
    struct addrinfo *res; // Résultats de la recherche,  permet les listes chaînées


    //paramètrage du hints
    hints.ai_protocol = IPPROTO_UDP;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int addrinfo = getaddrinfo(server_ip, server_port, &hints, &res);

    creat("./recv.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH); //Pour écrire le fichier
    int fd_recv = open("./recv.txt",O_RDWR);

    creat("./recv_temp.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);//Pour traiter le fichier (ACK, fichiers suivants...)
    int fd_temp= open("./recv_temp.txt",O_RDWR);

    char request[BUFFSIZE];
    char response[DATASIZE];
    char ACK[4] = "\0\4\0\0";
    int lenght_read_request = build_request(file_name,request);
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    sendto(sock, request, lenght_read_request, 0, res->ai_addr, res->ai_addrlen);
    do
    {
        if (recvfrom(sock, response, BUFFSIZE, 0,&server, &res->ai_addrlen ) !=-1)
        {
            int status1 = write(fd_recv, response+4,DATASIZE);
            int status2 = write(fd_temp,response, BUFFSIZE);
            ACK[2] = response[2];
            ACK[3] = response[3];
            sendto(sock, ACK, 4, 0, &server, res->ai_addrlen); //A chaque fois que l'on envoie une réponse c'est sur le nouveau socket
        }
    }while (read(fd_temp,response,BUFFSIZE)==BUFFSIZE);
}