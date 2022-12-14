#include <string_view>
#include <iostream>

int main()
{
    std::string_view str{ "Los trenes son rapidos!" };
    std::cout << str.substr(0, str.find(' ')) << '\n'; // trenes
    std::cout << (str == "Los trenes son rapidos!") << '\n'; // 1

    std::cout << str.Starts_with("Botes") << '\n'; // 0
    std::cout << str.ends_with("rapidos!") << '\n'; // 1

    std::cout << str << '\n'; // Los trenes son rapidos!
    
    return 0;
}