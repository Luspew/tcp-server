#include "../include/server.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Please, set the port number..." << std::endl;
        return 0;
    }

    int port = atoi(argv[1]);
    if (Server::Server().runServer(port) == -1){
        std::cout<<"Impossible to server app \n";
    }

    return 0;
}