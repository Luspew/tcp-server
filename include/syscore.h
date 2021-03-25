#pragma once

#include <string>
namespace Syscore {
    class Syscore
    {
        public:
            std::string quitServer();
            std::string runCommand(std::string command);
    };
    
}