#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

struct sockaddr_in address;
struct sockaddr_in remote_address;

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        cout << "Please, set the port number..." << endl;
        return 0;
    }

    int port = atoi(argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    int bind_val = bind(sock, (struct sockaddr *)&address, sizeof(address));
    if (bind_val == -1)
    {
        perror("Error on binding socket address");
        return 1;
    }

    int listen_val = listen(sock, 1);
    if (listen_val == -1)
    {
        perror("Error on listening");
        return 1;
    }

    memset(&remote_address, 0, sizeof(remote_address));
    socklen_t remote_addrlen = sizeof(address);

    cout << "Server listening on port :" << port << endl;

    int client_sock = accept(sock, (struct sockaddr *)&remote_address, &remote_addrlen);
    if (client_sock == -1)
    {
        perror("Error on accepting connection from client");
        return 1;
    }

    string client_ip = inet_ntoa(remote_address.sin_addr);
    int client_port = ntohs(remote_address.sin_port);

    cout << "Client " << client_ip << " connected on port " << port << endl;

    int bufflen = 1024;
    char buffer[bufflen];

    while (true)
    {
        memset(buffer, 0, bufflen);

        int recv_buffer = recv(client_sock, buffer, bufflen - 1, 0);

        if (recv_buffer < 0)
        {
            perror("Error on recv msg from client");
            continue;
        }
        else if (recv_buffer == 0)
        {
            cout << "Client " << client_ip << " disconnected." << endl;
            break;
        }

        if (buffer[recv_buffer - 1] == '\n')
        {
            buffer[recv_buffer - 1] = 0;
        }

        // system log
        cout << client_ip << " -> " << buffer << endl;

        // client response
        string response = "You said: " + static_cast<string>(buffer) + '\n';

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