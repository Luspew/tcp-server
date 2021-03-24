#pragma once

#include <string>

namespace Commands {
    class CommandsCore
    {
        private:
            struct command;
        public:
            CommandsCore();
            std::string commandControll(std::string command);
    };   
}
