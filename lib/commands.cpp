#include "../include/commands.h"
#include "../include/syscore.h"
#include "../include/utils.h"

#include <map>
#include <string>

Commands::CommandsCore::CommandsCore() : SYSTEM_COMMANDS{
                                             {0, "help", "", false, false},
                                             {1, "listdir", "ls", true, false},
                                             {2, "currdir", "pwd", true, false},
                                             {3, "clear", "clear", true, false},
                                             {4, "frperm", "", false, true}}
{
    //triggerCommands["help"] = &CommandsCore::helpTrigger;
    triggerCommands.insert(std::pair<std::string, action>("help", &CommandsCore::helpTrigger));
}

std::string Commands::CommandsCore::commandControll(std::string command)
{
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
            return (this->*triggerCommands.find(SYSTEM_COMMANDS[i].ALIAS)->second)(command);
        }
    }
    return "not found \n";
}
