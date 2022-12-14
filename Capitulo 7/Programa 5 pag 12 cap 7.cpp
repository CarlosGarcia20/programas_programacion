#include <string>
#include <iostream>

int main()
{
	std :: cout << "Seleccione 1 o 2: ";
	int choice{};
	std :: cin >> choice;
	std :: cin.ignore(32767, '\n');
	std :: cout << "Ahora ingresa tu nombre: ";
	std :: string name{};
	std :: getline(std :: cin, name);
	
	std :: cout << "Hola, " << name << ", seleccionaste: " << choice << '\n';
	
	return 0;
}