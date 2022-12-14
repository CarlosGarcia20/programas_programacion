#include <string_view>
#include <iostream>
#include <string>

void print(std::string s)
{ 
   std::cout << s << '\n';
}

int main()
{
    std::string_view sv { "Pelota" };
    
    sv.remove_suffix(3);

    std::string str{ sv }; //ok

    print(str); //ok

    print(static_cast<std::string(sv)); // ok
    
    return 0;
