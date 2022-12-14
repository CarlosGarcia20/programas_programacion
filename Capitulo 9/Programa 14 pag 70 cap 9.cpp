#include <iostream>

int main()
{
    char myString[]{ "String" };
    myString[1] = 'p';
    std::cout << myString << '\n';
    
    return 0;
}