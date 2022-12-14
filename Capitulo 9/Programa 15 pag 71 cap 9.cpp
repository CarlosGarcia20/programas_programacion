#include <iostream>

int main()
{
    char name[20]{ "Fernando" }; // solo usa 5 caracteres ( 4 letras + terminador nulo)
    std::cout << "My name is: " << name << '\n';
    
    return 0;
}