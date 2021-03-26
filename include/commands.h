#pragma once

#include <string>
#include <iostream>
#include <map>

#include "syscore.h"
#define SYSTEM_CMD_SIZE 5

namespace Commands
{
    struct Command
    {
        int ID;
        std::string ALIAS;
        std::string UNIXCMD;
        bool IS_OS_CMD;
        Command(int id, std::string alias, std::string unixcmd, bool is_os_cmd)
        {
            ID = id;
            ALIAS = alias;
            UNIXCMD = unixcmd;
            IS_OS_CMD = is_os_cmd;
        }
    };  

  

    class CommandsCore
    {

    private:
        int sys_cmd_size = SYSTEM_CMD_SIZE;
        Command SYSTEM_COMMANDS[SYSTEM_CMD_SIZE];

    public:
        typedef std::string (CommandsCore::*action)();
        action triggerCommands[SYSTEM_CMD_SIZE];
        CommandsCore();
        void setupTriggers();
        std::string helpTrigger();
        std::string frpermTrigger(std::string command);
        std::string commandControll(std::string command);
    };
}
