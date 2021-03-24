#include "../include/commands.h"
#include "../include/syscore.h"
#include <string>


Commands::CommandsCore::CommandsCore(){
    struct command {
        int ID;
        std::string ALIAS;
    };
}

std::string Commands::CommandsCore::commandControll(std::string command)
{
    if (command == "quit")
    {
       return Syscore::Syscore().quitServer();
    }
    return command;
}
