#include "../include/server.h"
#include "../include/commands.h"
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>


int Server::Server::runServer(int port)
{   
    Commands::CommandsCore().setupTriggers();
    // socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        perror("Error on binding socket address");
        return -1;
    }

    if (listen(sock, SOMAXCONN) == -1)
    {
        perror("Error on listening");
        return -1;
    }

    std::cout << "Server listening on port :" << port << std::endl;

    //memset(&remote_address, 0, sizeof(remote_address));
    socklen_t remote_addrlen = sizeof(address);
    int client_sock = accept(sock, (struct sockaddr *)&remote_address, &remote_addrlen);
    if (client_sock == -1)
    {
        perror("Error on accepting connection from client");
        return 1;
    }

    std::string client_ip = inet_ntoa(remote_address.sin_addr);
    int client_port = ntohs(remote_address.sin_port);

    std::cout << "Client " << client_ip << " connected on port " << port << std::endl;

    int bufflen = 1024;
    char buffer[bufflen];

    while (true)
    {
        memset(buffer, 0, bufflen);

        int recv_buffer = recv(client_sock, buffer, bufflen - 1, 0);
        if (recv_buffer == -1)
        {
            perror("Error on recv msg from client");
            continue;
        }

        else if (recv_buffer == 0)
        {
            std::cout << "Client " << client_ip << " disconnected." << std::endl;
            continue;
        }

        if (buffer[recv_buffer - 1] == '\n')
        {
            buffer[recv_buffer - 1] = 0;
        }

        // system log
        std::cout << client_ip << " -> " << buffer << std::endl;

        std::string client_msg = static_cast<std::string>(buffer);

        // client response
        // Command exec
        std::string response = Commands::CommandsCore().commandControll(client_msg);

        int send_buffer = send(client_sock, response.c_str(), response.length(), 0);
        if (send_buffer == -1)
        {
            perror("Error on sending message to client");
            return 1;
        }
    }
    shutdown(client_sock, SHUT_RDWR);
    return 0;
}