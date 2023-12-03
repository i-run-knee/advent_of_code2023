#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <string>
#include <sstream>

namespace utils
{
    void writeToFile(std::string filename, std::string content);
    void readFromFile(std::string filename);
    std::string intToString(int number);
    int stringToInt(std::string str);
    int charToInt(char c);
    template<class UnaryFunction>
    UnaryFunction for_each_line(std::string filename, UnaryFunction f);
}

#endif // UTILS_H