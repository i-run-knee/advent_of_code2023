#include <iostream>
#include <string>
#include <vector>

#include "../utils/utils.cpp"

#define FILENAME "input3.txt"

std::vector<std::pair<int,int>>dirs = 
{
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
    {1,1},
    {-1,-1},
    {1,-1},
    {-1,1}
};

bool is_digit(char c)
{
    return c - '0' >= 0 && c - '0' <= 9;
}

int find_number(const std::vector<std::vector<char>>&data, int x, int y, std::vector<std::vector<bool>>&visited)
{
    int num = 0;
    if(visited[x][y])
    {
        return 0;
    }
    int start = y;
    int end = y;
    while(start >=0 && is_digit(data[x][start]))
    {
        start--;
    }
    while(end < data[0].size() && is_digit(data[x][end]))
    {
        end++;
    }
    for(int i = start+1; i < end; i++)
    {
        num *= 10;
        num += data[x][i] - '0';
        visited[x][i] = true;
    }
    return num;
}

std::vector<std::vector<char>>create_data_map()
{
    std::vector<std::vector<char>>data;
    utils::for_each_line(FILENAME, [&data](std::string line)
    {
        std::vector<char> row;
        for(char c : line)
        {
            row.push_back(c);
        }
        data.push_back(row);
    });
    return data;
}

int p1()
{
    std::vector<std::vector<char>>data = create_data_map();
    std::vector<std::vector<bool>>visited = std::vector<std::vector<bool>>(data.size(), std::vector<bool>(data[0].size(), false));
    int sum = 0;
    for(size_t i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < data[0].size(); j++)
        {
            if(data[i][j] != '.' && !is_digit(data[i][j]))
            {
                // special symbol found
                for(auto dir : dirs)
                {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if(x >= 0 && x < data.size() && y >= 0 && y < data[0].size())
                    {
                        if(is_digit(data[x][y]))
                        {
                            sum+= find_number(data, x, y, visited);
                        }
                    }
                }

            }
        }
    }
    return sum;
}

int gear_ratio(const std::vector<std::vector<char>>&data, std::vector<std::pair<int,int>>&adjs)
{
    int ratio = 1;
    for(int i = 0; i < adjs.size(); i++)
    {
        int num = 0;
        int start = adjs[i].second;
        int end = adjs[i].second;
        while(start >=0 && is_digit(data[adjs[i].first][start]))
        {
            start--;
        }
        while(end < data[0].size() && is_digit(data[adjs[i].first][end]))
        {
            end++;
        }
        for(int j = start+1; j < end; j++)
        {
            num *= 10;
            num += data[adjs[i].first][j] - '0';
        }
        ratio *= num;
    }
    return ratio;
}

int p2()
{
   std::vector<std::vector<char>>data = create_data_map();
   std::vector<std::vector<bool>>visited = std::vector<std::vector<bool>>(data.size(), std::vector<bool>(data[0].size(), false));
   int sum = 0;
   for(size_t i = 0; i < data.size(); i++)
   {
    for(size_t j = 0; j < data[0].size(); j++)
    {
        if(data[i][j] == '*')
        {
            std::vector<std::pair<int,int>>adjs;
            for(auto dir:dirs)
            {
                int x = i + dir.first;
                int y = j + dir.second;
                if(x >= 0 && x < data.size() && y >= 0 && y < data[0].size() && !visited[x][y] && is_digit(data[x][y]))
                {
                    adjs.push_back(std::make_pair(x,y));
                    visited[x][y] = true;
                    if(y-1 >= 0 && is_digit(data[x][y-1]))
                    {
                        visited[x][y-1] = true;
                    }
                    if(y+1 < data[0].size() && is_digit(data[x][y+1]))
                    {
                        visited[x][y+1] = true;
                    }
                }
               
            }
            if(adjs.size() == 2)
            {
                sum += gear_ratio(data, adjs);
            }
            for(auto dir:dirs)
            {
                int x = i + dir.first;
                int y = j + dir.second;
                if(x >= 0 && x < data.size() && y >= 0 && y < data[0].size())
                {
                    visited[x][y] = false;
                }
            }
        }
    }
   }
    return sum;
}

int main()
{
    std::cout << "Solving day 3 of AoC 2023... " << std::endl;
    std::cout << p2() << std::endl;
}