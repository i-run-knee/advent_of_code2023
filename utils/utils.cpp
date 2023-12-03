#include "utils.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

void utils::writeToFile(std::string filename, std::string content)
{
    std::ofstream file;
    file.open(filename);
    file << content;
    file.close();
}

std::string utils::readFromFile(std::string filename)
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

std::string utils::intToString(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

int utils::stringToInt(std::string str)
{
    std::stringstream ss(str);
    int number;
    ss >> number;
    return number;
}
