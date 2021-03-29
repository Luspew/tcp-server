#include "../include/commands.h"
#include "../include/utils.h"
#include "../include/syscore.h"

#include <string>


std::string Commands::CommandsCore::helpTrigger(std::string command)
{
    return "System commands list";
}

std::string Commands::CommandsCore::frpermTrigger(std::string command)
{
    Utils::Utils utils;
    Syscore::Syscore syscore;

    std::string *command_split = utils.splitString(command + " ", 2);

    return syscore.runCommand("ls -l " + command_split[1]);
}