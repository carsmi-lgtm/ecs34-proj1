#include "StringUtils.h"
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string Temp = str;
    std::string Old = old;
    std::string New = rep;
    size_t pos = 0;

    if (Old == ""){
        return Temp;
    }

    while ((pos = Temp.find(Old, pos)) != std::string::npos){
        Temp.replace(pos, Old.length(), New);
        pos += New.length();
    }
    return Temp;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> Result;
    std::string Temp = str;
    std::string Splt = splt;
    
    if (Temp == "") return Result;

    if (Splt == "") {
        size_t strt = 0;
        while (strt < Temp.length()){
            size_t s = Temp.find_first_not_of(" \n\t", strt);
            if (s == std::string::npos) break;

            size_t e = Temp.find(' ', s);
            if (e == std::string::npos) e = Temp.length();
            
            Result.push_back(Temp.substr(s, e-s));
            strt = e + 1;
        }
        return Result;
    }

    size_t strt = 0;
    while (strt <= Temp.length()) {
        size_t pos = Temp.find(Splt, strt);
        if (pos == std::string::npos) {
            Result.push_back(Temp.substr(strt));
            break;
        }
        Result.push_back(Temp.substr(strt, pos-strt));
        strt = pos + Splt.length();
        
    }

    return Result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::vector<std::string> Vect = vect;
    std::string Delim = str;
    std::string Temp;

    for (size_t i = 0; i < Vect.size(); i++){
        if (i > 0) Temp += Delim;
        Temp += Vect[i];
    }

    return Temp;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string Temp = str;
    size_t pos = 0;
    while ((pos = Temp.find('\t', pos)) != std::string::npos){
        Temp.replace(pos, 1, std::string(tabsize, ' '));
        pos += tabsize;
    } 
    return Temp;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    int count = 0;
    std::string Left = left;
    std::string Right = right;
    int l = Left.length();
    int r = Right.length();

    if (ignorecase == true) {
        Left = Lower(Left);
        Right = Lower(Right);
    }

    if (l == 0) return r;
    if (r == 0) return l;

    std::vector<std::vector<int>> dp(l+1, std::vector<int>(r+1));

    for (int i = 0; i <= l; i++) dp[i][0] = i;
    for (int j = 0; j <= r; j++) dp[0][j] = j;

    for (int i = 1; i <= l; i++){
        for (int j = 1; j <= r; j++){
            if (Left[i-1] == Right[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + std::min({
                dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1]});
        }
    }
    return dp[l][r];
}

};