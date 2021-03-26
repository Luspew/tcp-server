#include "../include/utils.h"
#include <string>

std::string *Utils::Utils::splitString(std::string str, size_t size_res)
{
    std::string *result = new std::string[size_res];

    std::string delim = " ";
    size_t pos = 0;
    int arrPos = 0;
    std::string sub;

    while ((pos = str.find(delim)) != std::string::npos)
    {
        sub = str.substr(0, pos);
        str.erase(0, pos + delim.length());
        result[arrPos] = sub;
        arrPos++;
    }

    return result;
}