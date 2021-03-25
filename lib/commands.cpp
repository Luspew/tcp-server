#include "../include/commands.h"
#include "../include/syscore.h"
#include <string>

Commands::CommandsCore::CommandsCore() : SYSTEM_COMMANDS{{1, "listdir", "ls", true}, {0, "help", "", false}} {}

void Commands::CommandsCore::setupTriggers()
{
    triggerCommands[0] = &CommandsCore::helpTrigger;
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
            return (this->*triggerCommands[0])();
        }
    }
    return "not found";
}
