#include "../include/commands.h"
#include "../include/syscore.h"

#include <string>

Commands::CommandsCore::CommandsCore() : SYSTEM_COMMANDS{
                                             {0, "help", "", false},
                                             {1, "listdir", "ls", true},
                                             {2, "currdir", "pwd", true},
                                             {3, "clear", "clear", true},
                                             {4, "frperm", "", false}} {}

void Commands::CommandsCore::setupTriggers()
{
    triggerCommands[0] = &CommandsCore::helpTrigger;
}

std::string Commands::CommandsCore::commandControll(std::string command)
{
    if (command.find("frperm") != std::string::npos)
    {
       return frpermTrigger(command);
    }
    if (command == "quit")
    {
        return Syscore::Syscore().quitServer();
    }

    for (int i = 0; i < sys_cmd_size; i++)
    {
        if (SYSTEM_COMMANDS[i].ALIAS == command)
        {
            if (SYSTEM_COMMANDS[i].IS_OS_CMD)
            {
                return Syscore::Syscore().runCommand(SYSTEM_COMMANDS[i].UNIXCMD);
            }
            return (this->*triggerCommands[SYSTEM_COMMANDS[i].ID])();
        }
    }
    return "not found \n";
}
