#include <iostream>

int main()
{
    int v{5};   
    int *ptr (&v); // Inicializar ptr con la dirección de la variable v

    std::cout << &v << '\n'; // Imprime la dirección de la variable v
    std::cout << ptr << '\n'; // Imprime la dirección que tiene ptr
    
    return 0;
}