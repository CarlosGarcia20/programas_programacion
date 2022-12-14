#include <iostream>
#include <iterator> // std::size

int main()
{
    char myString[]{ "String" };
    const int lenght{static_cast<int>(std::size(myString)) };
    std::cout << myString << "tiene" << lenght << " caracteres.\n";

    for (int index{ 0 }; index < lenght; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';

    std::cout << '\n';

    return 0;
}