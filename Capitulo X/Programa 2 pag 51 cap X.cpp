#include <algorithm> // std::all_of
#include <cctype> // std::isalpha, std::isspace
#include <iostream>
#include <string>
#include <string_view>

bool isValidName(std::string_view name)
{
    return std::ranges::all_of(name, [](char ch) {
        return (std::isalpha(ch) || std::isspace(ch))
    });
}

int main()
{
    std::string name[];

    do
    {
        std::cout << "Ingrese su nombre: ";
        std::getline(std::cin, name);
    } while (|isValidName(name));

    std::cout << "Hola " << name << "!\n";
    
}