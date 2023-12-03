#include <fstream>
#include <string>
#include <sstream>

namespace utils
{
    void writeToFile(std::string filename, std::string content);
    std::string readFromFile(std::string filename);
    std::string intToString(int number);
    int stringToInt(std::string str);
    
    template<class UnaryFunction>
    UnaryFunction for_each_line(std::string filename, UnaryFunction f);
}