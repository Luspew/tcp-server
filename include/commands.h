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
        bool HAS_ARGS;
        Command(int id, std::string alias, std::string unixcmd, bool is_os_cmd, bool has_args)
        {
            ID = id;
            ALIAS = alias;
            UNIXCMD = unixcmd;
            IS_OS_CMD = is_os_cmd;
            HAS_ARGS = has_args;
        }
    };

    class CommandsCore
    {

    private:
        int sys_cmd_size = SYSTEM_CMD_SIZE;
        Command SYSTEM_COMMANDS[SYSTEM_CMD_SIZE];

    public:
        typedef std::string (CommandsCore::*action)(std::string);
        std::map<std::string,action> triggerCommands;
        CommandsCore();
        void setupTriggers();
        std::string helpTrigger(std::string command);
        std::string frpermTrigger(std::string command);
        std::string commandControll(std::string command);
    };
}
