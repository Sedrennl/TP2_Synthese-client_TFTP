//
// Created by julien on 19/12/24.
//

#include "fonctions.h"
int build_request(char* filename,char* request){
    memset(request, 0, BUFFSIZE);
    int offset = 0; //permet de parcourir le buffer
    int rrq_length;

    // Ajouter l'opcode (2 octets)
    request[offset++] = 0x00;
    request[offset++] = 0x01; // Opcode pour RRQ

    // Ajouter le nom du fichier
    strcpy(&request[offset], filename);
    offset += strlen(filename) + 1; // Inclut l'octet nul

    // Ajouter le mode de transfert
    strcpy(&request[offset], "octet");
    offset += strlen("octet") + 1; // Inclut l'octet nul
    return offset;
  }