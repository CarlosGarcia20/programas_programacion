#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outf{ "Sample.dat" };

    if (!outf) //Verdadero si no se pudo abrir o crear el archivo
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.dat no puede ser abierto en modo escritura!" << std::endl;
        return 1;
    }

    outf << "Esta es la linea 1" << '\n';
    outf << "Esta es la linea 2" << '\n';

    return 0;
}