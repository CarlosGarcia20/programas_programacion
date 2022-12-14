#include <cstring>

int main()
{
    char source[]{ "Copia esta cadena!" };
    char dest[5]; // tenga en cuenta que la longitud de dest es de solo 5 caracteres.
    std::strcpy(dest, source); //overflow
    std::cout << dest << '\n';
    

    return 0;
}