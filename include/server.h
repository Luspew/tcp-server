#pragma once
#include <netinet/in.h>

namespace Server
{
    class Server
    {
    private:
        struct sockaddr_in address;
        struct sockaddr_in remote_address;

    public:
        int runServer(int port);
    };

}