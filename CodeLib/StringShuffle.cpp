#include "StringShuffle.h"

std::string shuffle(const std::string& source) {
    std::string str1 = source;
    std::string strResult = "";
    int n = 0;
    while (strResult.length() != source.length())
    {
        n = rand() % str1.length();
        strResult += str1.at(n);
        str1.erase(n, 1);
    }
    return strResult;
}