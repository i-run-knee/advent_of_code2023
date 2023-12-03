#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "../utils/utils.cpp"

std::unordered_map<char, std::vector<std::string>>char_to_string_map = 
{
    {'z', {"zero"}},
    {'o', {"one"}},
    {'t', {"two", "three"}},
    {'f', {"four", "five"}},
    {'s', {"six", "seven"}},
    {'e', {"eight"}},
    {'n', {"nine"}},
};

std::unordered_map<std::string, int> string_num_map =
{
    // add numbers till 9
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three",3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

int find_num1(std::string line)
{
    int tens = 10;
    int ones = 1;
    for (int i = 0; i < line.size(); i++)
    {
        if(line[i] - '0' >= 0 && line[i] - '0' <= 9)
        {
            tens *= utils::charToInt(line[i]);
            break;
        }
    }
    for(int i = line.size()-1; i >= 0; i--)
    {
        if(line[i] - '0' >= 0 && line[i] - '0' <= 9)
        {
            ones *= utils::charToInt(line[i]);
            break;
        }
    }
    return tens + ones;
}


int find_num2(std::string line)
{
    int tens = 10;
    int ones = 1;
    bool done = false;
    for (int i = 0; i < line.size(); i++)
    {
        if(line[i] - '0' >= 0 && line[i] - '0' <= 9)
        {
            tens *= utils::charToInt(line[i]);
            break;
        }

        else if(char_to_string_map.find(line[i]) != char_to_string_map.end())
        {
            for(std::string str : char_to_string_map[line[i]])
            {
                if(line.substr(i, str.size()) == str)
                {
                    tens *= string_num_map[str];
                    done = true;
                }
            }
        }
        if(done)
        {
            break;
        }
    }
    done = false;
    for(int i = line.size()-1; i >= 0; i--)
    {
        if(line[i] - '0' >= 0 && line[i] - '0' <= 9)
        {
            ones *= utils::charToInt(line[i]);
            break;
        }
        else if(char_to_string_map.find(line[i]) != char_to_string_map.end())
        {
            for(std::string str : char_to_string_map[line[i]])
            {
                if(line.substr(i, str.size()) == str)
                {
                    ones *= string_num_map[str];
                    done = true;
                }
            }
        }
        if(done)
        {
            break;
        }
    }
    return tens + ones;
}

int p1()
{
    int sum = 0;
    utils::for_each_line("input1.txt", [&sum](std::string line)
    {
        sum += find_num1(line);
    });
    return sum;
}

int p2()
{
    int sum = 0;
    utils::for_each_line("input1.txt", [&sum](std::string line)
    {
        sum += find_num2(line);
    });
    return sum;
}

int main()
{
    std::cout << "Solving the first puzzle..." << std::endl;
    std::cout << p2() << std::endl;
}