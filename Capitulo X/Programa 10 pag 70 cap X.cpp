#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inf{ "Sample.dat" };
    if (!inf)
    {
        std::cerr << "Uh, oh Sample.dat no se puede abrir para escritura!" << std::endl;
        return 1;
    }
    while (inf)
    {
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    return 0;
}