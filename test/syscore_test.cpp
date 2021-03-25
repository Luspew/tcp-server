#include "../include/syscore.h"
#include <iostream>
#include <string>

#define IS_TRUE(x) {if(!x) std::cout << __FUNCTION__ << "failed on line" <<__LINE__ <<std::endl;}


void test_runCommand(){
    
}

int main() {
    std::string command_result = Syscore::Syscore().runCommand("ls");

    std::cout<<command_result<<std::endl;
    return 0;
}