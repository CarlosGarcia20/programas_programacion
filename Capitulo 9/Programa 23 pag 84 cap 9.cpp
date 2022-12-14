#include <string_view>
#include <iostream>

int main()
{
    std::string_view text{ "hola" };
    std::string str{ text };
    std::string more{ str };

    std::cout << text << ' ' << str << ' ' << more << '\n';

    return 0;
}