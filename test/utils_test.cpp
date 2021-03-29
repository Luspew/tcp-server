#include "../include/utils.h"
#include <iostream>
#include <string>

#define IS_TRUE(x) {if(!x) std::cout << __FUNCTION__ << "failed on line" <<__LINE__ <<std::endl;}


int main() {
    /* std::string lin =  Utils::Utils().readbinf("me.jpg");
    Utils::Utils().writebinf("teste.jpg",lin); */

    //Utils::Utils().imageCopy("me.jpg", "out.jpg");
    std::string res = "frperm       dir    ";
    std::string *splitted = Utils::Utils().splitString(res, 2);

    std::cout << splitted[1];
    return 0;
}