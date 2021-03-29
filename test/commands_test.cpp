#include "../include/commands.h"
#include <iostream>
#include <string>

#define IS_TRUE(x) {if(!x) std::cout << __FUNCTION__ << "failed on line" <<__LINE__ <<std::endl;}


int main() {
    //std::cout << Commands::CommandsCore().tCmd.at("help") << std::endl;
    std::cout << Commands::CommandsCore().commandControll("help");


    return 0;
}