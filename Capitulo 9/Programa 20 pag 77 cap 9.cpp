#include <cstring>
#include <iterator> // para std::size
#include <iostream>

int main()
{
    char name[20]{ "Fernando" }; // 
    std::cout << "Mi nombre es: " << name << '\n';
    std::cout << name << " tiene " << std::size(name) << " caracteres en el arreglo.'\n";
    
    return 0;
}