#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n'; // Imprime el valor de la variable x
    std::cout << &x << '\n'; // Imprime la dirección de memoria de la variable x
    
    return 0;
}