#include <iostream>

int main ()
{
		std :: cout << "Ingrese un numero: ";
		int value {};
		std :: cin >> value;
		
		if (value > 10 && value < 20)
			std :: cout << "El valor está entre 10 y 20\n";
		else
			std :: cout << "El valor no está entre 10 y 20\n";
		return 0;
}