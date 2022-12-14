#include <iostream>

int main()
{
	int count{ 0 };
	bool keepLopping { true };
	while (keepLopping)
	{
		std::cout << "Ingrese 's' para salir del ciclo, otro caracter para continuar: ";
		char ch{}:
		std::cin >> ch;

		if (ch == 's')
			keepLopping = false;
	}
	else
	{
		++count;
		std :: cout << "Hemos iterado" << count << " veces\n"
	}
	return 0;



}