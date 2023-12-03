#include <iostream>
#include <string>

#include "../utils/utils.cpp"

#define FILENAME "input3.txt"

int f1(std::string& line)
{
    return 0;
}

int f2(std::string& line)
{
    return 0;
}

int p1()
{
    int sum = 0;
    utils::for_each_line(FILENAME, [&sum](std::string line)
    {
        sum += f1(line);
    });
    return sum;   
}

int p2()
{
    int sum = 0;
    utils::for_each_line(FILENAME, [&sum](std::string line)
    {
        sum += f2(line);
    });
    return sum;
}

int main()
{
    std::cout << "Solving day 3 of AoC 2023... " << std::endl;
}