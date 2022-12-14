#include <iostream>

int main()
{
    char name[255]; // declarar una matriz lo suficientemente grande para contener 255 caracteres
    std::cout << "Ingrese su nombre: ";
    std::cin >> name;
    std::cout << "Ingresaste: " << name << '\n';
    
    return 0;
}