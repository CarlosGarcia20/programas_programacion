#include <iostream>

int main()
{
    std :: cout << "Ingrese un numero: "
    int x{};
    std :: cin >> x

    if (x > 10)
    {
         std :: cout << "Ingresaste: " << x << '\n';
        std :: cout << x << " es mayor que 10\n";
    }           
    else
         std :: cout << "Ingresaste: " << x << '\n';
        std :: cout << x << " no es mayor que 10\n";
        
        
    return 0;   
}