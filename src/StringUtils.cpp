#include "StringUtils.h"
#include <cctype>
#include <cmath>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    std::string Temp = str;
    if (end == 0){
        end = Temp.length();
    }
    if (start < 0){
        start = start + Temp.length();
        if (start < 0){
            start = 0;
        }
    }
    if (end < 0){
        end = end + Temp.length();
        if (end < 0){
            end = 0;
        }
    }
    if (end > Temp.length()){
        end = Temp.length();
    }
    if (start >= end){
        return "";
    }
    return Temp.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept{
    std::string Temp = str;
    Temp[0] = toupper(Temp[0]);
    return Temp;
}

std::string Upper(const std::string &str) noexcept{
    std::string Temp = str;
    int i;
    for (i = 0; i < Temp.length(); i++){
        Temp[i] = toupper(Temp[i]);
    }
    return Temp;
}

std::string Lower(const std::string &str) noexcept{
    std::string Temp = str;
    int i;
    for (i = 0; i < Temp.length(); i++){
        Temp[i] = tolower(Temp[i]);
    }
    return Temp;
}

std::string LStrip(const std::string &str) noexcept{
    std::string Temp = str;
    size_t len = Temp.length();
    size_t firstChar = Temp.find_first_not_of(" \n\t");
    if (firstChar == std::string::npos){
        return "";
    }
    return Temp.substr(firstChar, len - firstChar);
}

std::string RStrip(const std::string &str) noexcept{
    std::string Temp = str;
    size_t lastChar = Temp.find_last_not_of(" \n\t");
    if (lastChar == std::string::npos){
        return "";
    }
    return Temp.substr(0,lastChar + 1);
}

std::string Strip(const std::string &str) noexcept{
    std::string Temp = str;
    size_t firstChar = Temp.find_first_not_of(" \n\t");
    if (firstChar == std::string::npos){
        return "";
    }
    size_t lastChar = Temp.find_last_not_of(" \n\t");
    return Temp.substr(firstChar, lastChar - firstChar + 1);
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;
    size_t len = Temp.length();
    size_t fillRight, fillLeft;
    if (width < len){
        return Temp;
    }
    size_t toFill = width - len;
    if (toFill % 2 == 0){
        fillRight = toFill/2;
        fillLeft = toFill/2;
    }
    else {
        fillLeft = toFill/2;
        fillRight = toFill - fillLeft;

    }
    Temp.insert(len, fillRight, fill);
    Temp.insert(0, fillLeft, fill);
    return Temp;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;
    size_t len = Temp.length();
    size_t toFill = width - len;
    if (width < len){
        return Temp;
    }
    Temp.insert(len, toFill, fill);
    return Temp;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;
    size_t len = Temp.length();
    size_t toFill = width - len;
    if (width < len){
        return Temp;
    }
    Temp.insert(0, toFill, fill);
    return Temp;
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};