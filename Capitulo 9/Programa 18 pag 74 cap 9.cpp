#include <cstring>

int main()
{
    char source[]{ "Copia esta cadena!" };
    char dest[50];
    std::strcpy(dest, source);
    std::cout << dest << '\n';
    
    return 0;
}