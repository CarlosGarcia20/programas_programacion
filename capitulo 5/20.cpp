#include <iostream>

int main ()
{
		std :: cout << "Ingresa un numero: ";
		int value {};
		std :: cin >> value;
		
		if (value == 0 || value == 1)
			std :: cout << "Ingresaste 0 o 1\n";
		else
			std :: cout << "No ingresaste 0 o 1\n";
		return 0;
}