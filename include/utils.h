#pragma once

#include <string>

namespace Utils
{
    class Utils
    {
    public:
        std::string *splitString(std::string str, size_t size_res);
        void writebinf(std::string filename, std::string fileinfo);
        std::string readbinf(std::string filename);
        void imageCopy(std::string imagename, std::string copyimagename);
    };

}