#include <cstring>
#include <iterator> // para std::size
#include <iostream>

int main()
{
    char buffer[255];
    std::cout << "Ingrese una cadena: ";
    std::cin.getline(buffer, std::size(buffer));

    int spacesFound{ 0 };
    int bufferLenght{ static_cast<int>(std::strlen(buffer)) };
    for (int index{ 0 }; index < bufferLenght; ++index)
    {
        if (buffer[index] == ' ')
            ++spacesFound;
    }

    std::cout << "Ingresaste " << spacesFound << " espacios!\n";
    
    return 0;
}