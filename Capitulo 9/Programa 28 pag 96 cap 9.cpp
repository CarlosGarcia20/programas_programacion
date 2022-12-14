#include <string_view>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view sv { "Pelota" };
    
    sv.remove_suffix(3);

    std::string str{ sv }; //ok

    auto szNullTerminated{ str.c_str() };

    std::cout << str << " tiene " << std:strlen(szNullTerminated) << " letra(s)\n";    
    
    return 0;
}