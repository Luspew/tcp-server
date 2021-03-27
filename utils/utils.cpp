#include "../include/utils.h"
#include <string>
#include <fstream>
#include <iostream>

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

void Utils::Utils::writebinf(std::string filename, std::string fileinfo)
{
    std::ofstream OutFile;
    OutFile.open(filename, std::ios::out | std::ios::binary);
    OutFile.write(fileinfo.c_str(), fileinfo.length());
    OutFile.close();
}

std::string Utils::Utils::readbinf(std::string filename)
{
    std::ifstream File(filename);
    std::string lines;

    getline(File, lines);

    return lines;
}

void Utils::Utils::imageCopy(std::string imagename, std::string copyimagename)
{
    std::ofstream(copyimagename, std::ios::binary) << std::ifstream(imagename, std::ios::binary).rdbuf();
}