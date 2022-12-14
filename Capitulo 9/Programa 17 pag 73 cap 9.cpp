#include <iostream>
#include <iterator> // std::size

int main()
{
    char name[255]; // declarar una matriz lo suficientemente grande para contener 255 caracteres
    std::cout << "Ingrese su nombre: ";
    std::cin.getline(name, std::size(name));
    std::cout << "Ingresaste: " << name << '\n';
    
    return 0;
}