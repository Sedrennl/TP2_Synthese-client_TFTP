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

}
