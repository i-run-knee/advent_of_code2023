#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "../utils/utils.cpp"

#define FILENAME "input2.txt"
#define RED 12
#define GREEN 13
#define BLUE 14

std::unordered_map<char, std::string> color_map = 
{
    {'r', "red"},
    {'g', "green"},
    {'b', "blue"},
};

int game_num(const std::string& line)
{
    bool possible = true;
    int col_id = line.find(":");
    int game = utils::stringToInt(line.substr(5, col_id));
    for(int i = col_id+2; i < line.size();)
    {
       int num_cubes = 0;
       if(line[i+1] != ' ')
       {
        num_cubes = utils::charToInt(line[i]) * 10 + utils::charToInt(line[i+1]);
        i += 3;
       }
       else
       {
        num_cubes = utils::charToInt(line[i]);
        i += 2;
       }
       std::string color = color_map.find(line[i])->second;
       switch (line[i])
       {
        case 'r':
        if (num_cubes > RED)
        {
            return 0;
        }
        case 'g':
        if (num_cubes > GREEN)
        {
            return 0;
        }
        case 'b':
        if (num_cubes > BLUE)
        {
            return 0;
        }
       default:
        break;
       }
       i = i + color.size() + 2;
    }
    return game;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int power_cubes(std::string& line)
{
    int col_id = line.find(":");
    line = line.substr(col_id +2);
    int max_red = 0;
    int max_green = 0;
    int max_blue = 0;
    int semi_col = line.find(";");
    while(semi_col != std::string::npos)
    {
        semi_col = line.find(";");
        int end = semi_col == std::string::npos ? line.size() : semi_col;
        for(int i = 0; i < end;)
        {
            int num_cubes = 0;
            if(line[i+1] != ' ')
            {
                num_cubes = utils::charToInt(line[i]) * 10 + utils::charToInt(line[i+1]);
                i += 3;
            }
            else
            {
                num_cubes = utils::charToInt(line[i]);
                i += 2;
            }
            std::string color = color_map.find(line[i])->second;
            switch (line[i])
            {
                case 'r':
                max_red = max(max_red, num_cubes);
                break;
                case 'g':
                max_green = max(max_green, num_cubes);
                break;
                case 'b':
                max_blue = max(max_blue, num_cubes);
                break;
            default:
                break;
            }
            i = i + color.size() + 2;
        }
        if(semi_col != std::string::npos)
        {
            line = line.substr(end+2);
        }
    }
    return max_red * max_green * max_blue;
}

int p2()
{
    int sum = 0;
    utils::for_each_line(FILENAME, [&sum](std::string& line)
    {
        sum += power_cubes(line);
    });
    return sum;

}

int p1()
{
    int sum = 0;
    utils::for_each_line(FILENAME, [&sum](std::string& line)
    {
        sum += game_num(line);
    });
    return sum;
}

int main()
{
    std::cout << "Solving Day 2, AoC 2023..."<< std::endl;
    std::cout << p2() << std::endl;
    return 0;
}