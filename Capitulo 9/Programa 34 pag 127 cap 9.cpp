#include <iostream>
#include <cstddef> // NULL

void print(int x);   
{
    std::cout << "Imprime(int): " << x << '\n';
}

void print(int *x)
{
    if (!x)
        std::cout << "Imprime(int*): null'\n'";
    else
        std::cout << "Imprime(int*): " << *x << '\n';
}

int main()
{

    int *x { NULL };
    print(x); // Llama a print (int*) porque x tiene tipo int
    print(0); // Llama a print (int*) porque 0 es un literal extremo
    print(NULL); // Probablemente llame a print (int), aunque probablemente qusieramos print (int*)

    return 0;
}