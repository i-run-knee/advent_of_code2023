#include "utils.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

namespace utils
{
    void writeToFile(std::string filename, std::string content)
    {
        std::ofstream file;
        file.open(filename);
        file << content;
        file.close();
    }

    void readFromFile(std::string filename)
    {
        std::ifstream file;
        file.open(filename);
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }

    std::string intToString(int number)
    {
        std::stringstream ss;
        ss << number;
        return ss.str();
    }

    int stringToInt(std::string str)
    {
        std::stringstream ss(str);
        int number;
        ss >> number;
        return number;
    }

    int charToInt(char c)
    {
        return c - '0';
    }

    template<class UnaryFunction>
    UnaryFunction for_each_line(std::string filename, UnaryFunction f)
    {
        std::ifstream file;
        file.open(filename);
        std::string line;
        int r = 0;
        while (std::getline(file, line))
        {
            f(line);
        }
        file.close();
        return f;
    }
}
