#include <cstring>
#include <iostream>

int main()
{
    char text[]{ "hola" };
    std::string str{ text };
    std::string more{ str };

    std::cout << text << ' ' << more << '\n';

    return 0;
}