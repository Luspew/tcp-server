#include "../include/syscore.h"
#include <iostream>
#include <string>

#define BUFFSIZE 1024

std::string Syscore::Syscore::quitServer()
{
    // ToDo
    // Disconnect from server
    return "quited server";
};

std::string Syscore::Syscore::runCommand(std::string command)
{
    char buffer[BUFFSIZE];

    std::string result = "";
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        perror("Error on popen");
        return result;
    }

    while (!feof(pipe))
    {
        if (fgets(buffer, BUFFSIZE, pipe) != NULL)
        {
            result += buffer;
        }
    }

    pclose(pipe);

    return result;
}