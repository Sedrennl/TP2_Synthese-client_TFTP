//TP Synthese Client TFTP
//Question 2
//Blaret julien and LABROUSSE Sédrenn on 12/12/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netdb.h>
#include<sys/socket.h>

int main(int argc, char *argv[]){
    
    // Error handling: Check if the program receives the correct number of arguments.
    if (argc != 4){
        fprintf(stderr, "Usage: %s  <Server ip address> <Port> <File_name> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Store command-line arguments for later use.
    char *server_ip = argv[1];   
    char *server_port = argv[2]; 
    char *file_name = argv[3];   

    // Define a struct to hold address configuration hints.
    struct addrinfo hints; // Helps narrow down address lookup results.
    memset(&hints, 0, sizeof(hints)); // Initialize the struct to zero (no restrictions).
    struct addrinfo *res; // Pointer to the results list returned by getaddrinfo.

    // Configure the hints structure for a UDP connection using IPv4.
    hints.ai_protocol = IPPROTO_UDP; // Use UDP protocol.
    hints.ai_family = AF_INET;       // Use IPv4 addresses only.
    hints.ai_socktype = SOCK_DGRAM;  // Specify datagram sockets (UDP).

    // Perform address resolution for the provided server IP.
    // `res` will contain the resolved address information.
    int addrinfo = getaddrinfo(argv[1], NULL, &hints, &res);

    // Create a socket using the address information from the `res` structure.
    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    
}
